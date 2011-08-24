
/* $destdir\u39.c        Machine generated C code */

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


/* Code for r2speclist */

static Lisp_Object CC_r2speclist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist");
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
    v10 = v0;
/* end of prologue */
    v11 = v10;
    v9 = elt(env, 1); /* plus */
    if (!consp(v11)) goto v12;
    v11 = qcar(v11);
    if (!(v11 == v9)) goto v12;
    v9 = v10;
    v9 = qcdr(v9);
    goto v13;

v13:
    v10 = v9;
    v9 = v10;
    stack[-3] = v9;
    v9 = stack[-3];
    if (v9 == nil) goto v14;
    v9 = stack[-3];
    v9 = qcar(v9);
    fn = elt(env, 3); /* r2speclist1 */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    stack[-1] = v9;
    stack[-2] = v9;
    goto v16;

v16:
    v9 = stack[-3];
    v9 = qcdr(v9);
    stack[-3] = v9;
    v9 = stack[-3];
    if (v9 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v9 = stack[-3];
    v9 = qcar(v9);
    fn = elt(env, 3); /* r2speclist1 */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    v9 = Lrplacd(nil, stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    goto v16;

v14:
    v9 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v9); }

v12:
    v9 = v10;
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    goto v13;
/* error exit handlers */
v15:
    popv(5);
    return nil;
}



/* Code for bassoc */

static Lisp_Object CC_bassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v25, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v17;
    v26 = v0;
/* end of prologue */

v27:
    v23 = v25;
    if (v23 == nil) goto v28;
    v24 = v26;
    v23 = v25;
    v23 = qcar(v23);
    v23 = qcar(v23);
    if (v24 == v23) goto v12;
    v24 = v26;
    v23 = v25;
    v23 = qcar(v23);
    v23 = qcdr(v23);
    v23 = (v24 == v23 ? lisp_true : nil);
    goto v29;

v29:
    if (v23 == nil) goto v30;
    v23 = v25;
    v23 = qcar(v23);
    return onevalue(v23);

v30:
    v23 = v25;
    v23 = qcdr(v23);
    v25 = v23;
    goto v27;

v12:
    v23 = qvalue(elt(env, 2)); /* t */
    goto v29;

v28:
    v23 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v23);
}



/* Code for subs2chkex */

static Lisp_Object CC_subs2chkex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2chkex");
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

v37:
    v34 = stack[0];
    if (v34 == nil) goto v38;
    v34 = stack[0];
    v34 = qcar(v34);
    v34 = qcdr(v34);
    fn = elt(env, 2); /* subs2chk */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v35 = v34;
    if (v35 == nil) goto v40;
    v35 = stack[0];
    v35 = qcar(v35);
    v36 = qcar(v35);
    v35 = v34;
    v34 = stack[0];
    v34 = qcdr(v34);
    popv(2);
    return acons(v36, v35, v34);

v40:
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[0] = v34;
    goto v37;

v38:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v34); }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepcadr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v21 = v41;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    if (v21 == nil) goto v38;
    v21 = v41;
    v21 = qcdr(v21);
    v41 = qcar(v21);
    v21 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v41, v21);
    }

v38:
    v21 = (Lisp_Object)1; /* 0 */
    return onevalue(v21);
}



/* Code for mo_from_ei */

static Lisp_Object CC_mo_from_ei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v14, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_from_ei");
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
    v32 = v0;
/* end of prologue */
    v14 = v32;
    v44 = (Lisp_Object)1; /* 0 */
    if (v14 == v44) goto v38;
    v44 = v32;
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    stack[0] = v44;
    fn = elt(env, 1); /* mo!=deglist */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v45;
    {
        Lisp_Object v33 = stack[0];
        popv(2);
        return cons(v33, v44);
    }

v38:
    {
        popv(2);
        fn = elt(env, 2); /* mo_zero */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v45:
    popv(2);
    return nil;
}



/* Code for !*v2j */

static Lisp_Object CC_Hv2j(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *v2j");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v34 = qvalue(elt(env, 1)); /* ordering */
    v20 = elt(env, 2); /* lex */
    if (v34 == v20) goto v18;
    stack[0] = (Lisp_Object)17; /* 1 */
    v34 = v35;
    v20 = qvalue(elt(env, 3)); /* varlist */
    fn = elt(env, 4); /* sub01 */
    v20 = (*qfn2(fn))(qenv(fn), v34, v20);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v39 = stack[0];
        popv(1);
        return cons(v39, v20);
    }

v18:
    v34 = v35;
    v20 = qvalue(elt(env, 3)); /* varlist */
    {
        popv(1);
        fn = elt(env, 4); /* sub01 */
        return (*qfn2(fn))(qenv(fn), v34, v20);
    }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for general!-difference!-mod!-p */

static Lisp_Object CC_generalKdifferenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-difference-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v8 = v17;
    v7 = v0;
/* end of prologue */
    stack[0] = v7;
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    {
        Lisp_Object v12 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v12, v8);
    }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for max!-degree */

static Lisp_Object CC_maxKdegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v55, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for max-degree");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v54 = v17;
    v55 = v0;
/* end of prologue */

v56:
    v53 = v55;
    if (!consp(v53)) goto v7;
    v53 = v55;
    v53 = qcar(v53);
    v53 = (consp(v53) ? nil : lisp_true);
    goto v8;

v8:
    if (!(v53 == nil)) { popv(2); return onevalue(v54); }
    v15 = v54;
    v53 = v55;
    v53 = qcar(v53);
    v53 = qcar(v53);
    v53 = qcdr(v53);
    if (((int32_t)(v15)) > ((int32_t)(v53))) goto v21;
    v53 = v55;
    v53 = qcdr(v53);
    stack[0] = v53;
    v53 = v55;
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v54 = v55;
    v54 = qcar(v54);
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v53 = CC_maxKdegree(env, v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v54 = v53;
    v53 = stack[0];
    v55 = v53;
    goto v56;

v21:
    v53 = v55;
    v53 = qcdr(v53);
    stack[0] = v53;
    v53 = v55;
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v53 = CC_maxKdegree(env, v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v54 = v53;
    v53 = stack[0];
    v55 = v53;
    goto v56;

v7:
    v53 = qvalue(elt(env, 1)); /* t */
    goto v8;
/* error exit handlers */
v57:
    popv(2);
    return nil;
}



/* Code for list_assoc */

static Lisp_Object CC_list_assoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v14, v32, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list_assoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v17;
    v32 = v0;
/* end of prologue */

v27:
    v44 = v14;
    if (v44 == nil) return onevalue(v14);
    v44 = v14;
    v44 = qcar(v44);
    v31 = qcar(v44);
    v44 = v32;
    if (equal(v31, v44)) return onevalue(v14);
    v44 = v14;
    v44 = qcdr(v44);
    v14 = v44;
    goto v27;
}



/* Code for girationalize!: */

static Lisp_Object CC_girationalizeT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for girationalize:");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-3] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v71 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v71; /* !*gcd */
    stack[-1] = stack[-5];
    v71 = stack[-4];
    v71 = qcdr(v71);
    stack[-5] = v71;
    fn = elt(env, 4); /* conjgd */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[0] = v71;
    if (equal(stack[-1], v71)) goto v50;
    stack[-2] = stack[0];
    v72 = stack[-5];
    v71 = stack[0];
    fn = elt(env, 5); /* addf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = stack[-5];
    fn = elt(env, 6); /* negf */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v73 = elt(env, 3); /* !:gi!: */
    v72 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v73, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 7); /* multf */
    v71 = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 8); /* gcdf */
    v72 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* quotf */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v71 = (*qfn2(fn))(qenv(fn), stack[-2], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[0] = v71;
    v71 = stack[-4];
    v72 = qcar(v71);
    v71 = stack[0];
    fn = elt(env, 7); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v72 = stack[-5];
    v71 = stack[0];
    fn = elt(env, 7); /* multf */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 10); /* gigcdsq */
    v71 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    goto v56;

v56:
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    { popv(7); return onevalue(v71); }

v50:
    v71 = stack[-4];
    goto v56;
/* error exit handlers */
v74:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    popv(7);
    return nil;
}



/* Code for ciom */

static Lisp_Object CC_ciom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciom");
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
    v10 = elt(env, 1); /* "<OMATTR>" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 3); /* "<OMATP>" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 4); /* "<OMS cd=""typmml"" name=""type"">" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 5); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v10 = qcar(v10);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v11 = Lintern(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 6)); /* mmltypes!* */
    v10 = Lassoc(nil, v11, v10);
    v10 = Lprinc(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v10 = qcar(v10);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v11 = Lintern(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 6)); /* mmltypes!* */
    v10 = Lassoc(nil, v11, v10);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v10 = Lprinc(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 7); /* """>" */
    v10 = Lprinc(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 9); /* "</OMATP>" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    fn = elt(env, 13); /* objectom */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v10 = elt(env, 10); /* "</OMATTR>" */
    fn = elt(env, 11); /* printout */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v10 = nil;
    { popv(2); return onevalue(v10); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0;
/* end of prologue */
    stack[-3] = nil;
    v110 = qvalue(elt(env, 1)); /* subfg!* */
    if (v110 == nil) goto v5;
    v110 = stack[-5];
    v110 = qcdr(v110);
    stack[-6] = v110;
    v110 = stack[-5];
    v110 = qcar(v110);
    fn = elt(env, 11); /* simp!* */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-5] = v110;
    goto v28;

v28:
    v110 = stack[-6];
    if (v110 == nil) goto v35;
    v110 = stack[-5];
    v110 = qcar(v110);
    v110 = (v110 == nil ? lisp_true : nil);
    goto v34;

v34:
    if (!(v110 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v110 = stack[-3];
    if (v110 == nil) goto v113;
    v111 = stack[-3];
    v110 = (Lisp_Object)1; /* 0 */
    v110 = (v111 == v110 ? lisp_true : nil);
    goto v65;

v65:
    if (v110 == nil) goto v66;
    v110 = stack[-6];
    v110 = qcar(v110);
    fn = elt(env, 11); /* simp!* */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    goto v114;

v114:
    stack[-4] = v110;
    v110 = stack[-4];
    v111 = qcdr(v110);
    v110 = (Lisp_Object)17; /* 1 */
    if (v111 == v110) goto v115;
    v110 = qvalue(elt(env, 3)); /* t */
    goto v116;

v116:
    if (v110 == nil) goto v117;
    v110 = stack[-4];
    v110 = qcar(v110);
    if (v110 == nil) goto v118;
    v111 = stack[-4];
    v110 = elt(env, 4); /* prepf */
    fn = elt(env, 12); /* sqform */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v111 = v110;
    goto v73;

v73:
    v110 = elt(env, 5); /* "kernel or integer" */
    fn = elt(env, 13); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    goto v119;

v119:
    v110 = stack[-6];
    v110 = qcdr(v110);
    stack[-6] = v110;
    v110 = stack[-6];
    if (v110 == nil) goto v120;
    v110 = stack[-6];
    v110 = qcar(v110);
    fn = elt(env, 11); /* simp!* */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-3] = v110;
    v110 = stack[-3];
    v110 = qcar(v110);
    if (v110 == nil) goto v121;
    v110 = stack[-3];
    fn = elt(env, 14); /* d2int */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[0] = v110;
    if (v110 == nil) goto v122;
    v110 = stack[-6];
    v110 = qcdr(v110);
    stack[-6] = v110;
    v110 = (Lisp_Object)17; /* 1 */
    stack[-1] = v110;
    goto v123;

v123:
    v111 = stack[0];
    v110 = stack[-1];
    v110 = difference2(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = Lminusp(nil, v110);
    env = stack[-7];
    if (v110 == nil) goto v124;
    v110 = qvalue(elt(env, 9)); /* nil */
    stack[-3] = v110;
    goto v28;

v124:
    v111 = stack[-5];
    v110 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-5] = v110;
    v110 = stack[-1];
    v110 = add1(v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-1] = v110;
    goto v123;

v122:
    v111 = stack[-5];
    v110 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-5] = v110;
    goto v28;

v121:
    v110 = stack[-6];
    v110 = qcdr(v110);
    stack[-6] = v110;
    v110 = qvalue(elt(env, 9)); /* nil */
    stack[-3] = v110;
    goto v28;

v120:
    v111 = stack[-5];
    v110 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-5] = v110;
    goto v28;

v118:
    v110 = (Lisp_Object)1; /* 0 */
    v111 = v110;
    goto v73;

v117:
    v110 = stack[-4];
    v110 = qcar(v110);
    stack[-2] = v110;
    v110 = stack[-2];
    if (!consp(v110)) goto v125;
    v110 = stack[-2];
    v110 = qcar(v110);
    v110 = (consp(v110) ? nil : lisp_true);
    goto v126;

v126:
    if (v110 == nil) goto v127;
    v110 = stack[-2];
    v111 = qcar(v110);
    v110 = elt(env, 6); /* domain!-diff!-fn */
    v110 = get(v111, v110);
    env = stack[-7];
    if (v110 == nil) goto v128;
    stack[-1] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 8)); /* alglist!* */
    qvalue(elt(env, 8)) = nil; /* alglist!* */
    v110 = qvalue(elt(env, 9)); /* nil */
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-7];
    qvalue(elt(env, 8)) = v110; /* alglist!* */
    v110 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-7];
    stack[-4] = v110;
    v110 = stack[-4];
    fn = elt(env, 16); /* prekernp */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-7];
    if (!(v110 == nil)) goto v130;
    v111 = stack[-4];
    v110 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-7];
    goto v130;

v130:
    qvalue(elt(env, 8)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 7)) = stack[-1]; /* dmode!* */
    goto v119;

v128:
    v110 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v111 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    goto v119;

v127:
    v110 = stack[-2];
    v110 = qcdr(v110);
    if (v110 == nil) goto v131;
    v110 = qvalue(elt(env, 9)); /* nil */
    goto v132;

v132:
    if (v110 == nil) goto v133;
    v110 = stack[-2];
    v110 = qcar(v110);
    v110 = qcar(v110);
    v110 = qcar(v110);
    stack[-4] = v110;
    goto v119;

v133:
    v110 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v111 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    goto v119;

v131:
    v110 = stack[-2];
    v110 = qcar(v110);
    v111 = qcdr(v110);
    v110 = (Lisp_Object)17; /* 1 */
    if (v111 == v110) goto v134;
    v110 = qvalue(elt(env, 9)); /* nil */
    goto v132;

v134:
    v110 = stack[-2];
    v110 = qcar(v110);
    v110 = qcar(v110);
    v111 = qcdr(v110);
    v110 = (Lisp_Object)17; /* 1 */
    v110 = (v111 == v110 ? lisp_true : nil);
    goto v132;

v125:
    v110 = qvalue(elt(env, 3)); /* t */
    goto v126;

v115:
    v110 = stack[-4];
    v110 = qcar(v110);
    v110 = (consp(v110) ? nil : lisp_true);
    goto v116;

v66:
    v110 = stack[-3];
    goto v114;

v113:
    v110 = qvalue(elt(env, 3)); /* t */
    goto v65;

v35:
    v110 = qvalue(elt(env, 3)); /* t */
    goto v34;

v5:
    v111 = elt(env, 2); /* df */
    v110 = stack[-5];
    v111 = cons(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v111, v110);
    }
/* error exit handlers */
v129:
    env = stack[-7];
    qvalue(elt(env, 8)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 7)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v112:
    popv(8);
    return nil;
}



/* Code for findoptrow */

static Lisp_Object MS_CDECL CC_findoptrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v153, v154, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findoptrow");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v6;
    stack[0] = v17;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v153 = qvalue(elt(env, 2)); /* maxvar */
    v95 = stack[-6];
    v95 = plus2(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    v153 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    v95 = (Lisp_Object)65; /* 4 */
    v95 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    fn = elt(env, 8); /* pnthxzz */
    v95 = (*qfn2(fn))(qenv(fn), stack[-2], v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    v95 = qcar(v95);
    v95 = qcdr(v95);
    v95 = qcar(v95);
    stack[-3] = v95;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v153 = qvalue(elt(env, 2)); /* maxvar */
    v95 = stack[0];
    v95 = plus2(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    v153 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    v95 = (Lisp_Object)65; /* 4 */
    v95 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    stack[-2] = v95;
    goto v23;

v23:
    v95 = stack[-2];
    if (v95 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v95 = stack[-2];
    v95 = qcar(v95);
    stack[-1] = v95;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v153 = qvalue(elt(env, 2)); /* maxvar */
    v95 = stack[-1];
    v95 = qcar(v95);
    stack[-4] = v95;
    v95 = plus2(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    v153 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    v95 = (Lisp_Object)1; /* 0 */
    v95 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    if (v95 == nil) goto v156;
    v88 = stack[-4];
    v154 = stack[-6];
    v95 = stack[-1];
    v95 = qcdr(v95);
    v153 = qcar(v95);
    v95 = stack[-3];
    fn = elt(env, 9); /* testpr */
    v95 = (*qfnn(fn))(qenv(fn), 4, v88, v154, v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    stack[0] = v95;
    v95 = qcdr(v95);
    if (v95 == nil) goto v157;
    v95 = stack[0];
    v153 = Llength(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    stack[-1] = v153;
    v95 = stack[-5];
    v95 = (Lisp_Object)greaterp2(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v95 = v95 ? lisp_true : nil;
    env = stack[-8];
    if (v95 == nil) goto v100;
    v95 = stack[-1];
    stack[-5] = v95;
    qvalue(elt(env, 5)) = v95; /* newnjsi */
    v95 = stack[-4];
    stack[-7] = v95;
    v95 = stack[0];
    qvalue(elt(env, 6)) = v95; /* newjsi */
    goto v100;

v100:
    v153 = stack[-4];
    v95 = qvalue(elt(env, 7)); /* roccup2 */
    v95 = cons(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    qvalue(elt(env, 7)) = v95; /* roccup2 */
    goto v158;

v158:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v153 = qvalue(elt(env, 2)); /* maxvar */
    v95 = stack[-4];
    v95 = plus2(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    v154 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v95/(16/CELL)));
    v153 = (Lisp_Object)1; /* 0 */
    v95 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v154 + (CELL-TAG_VECTOR) + ((int32_t)v153/(16/CELL))) = v95;
    goto v156;

v156:
    v95 = stack[-2];
    v95 = qcdr(v95);
    stack[-2] = v95;
    goto v23;

v157:
    v153 = stack[-4];
    v95 = qvalue(elt(env, 4)); /* roccup1 */
    v95 = cons(v153, v95);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-8];
    qvalue(elt(env, 4)) = v95; /* roccup1 */
    goto v158;
/* error exit handlers */
v155:
    popv(9);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v40, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v27;

v27:
    v33 = stack[0];
    if (v33 == nil) goto v28;
    v33 = stack[0];
    v33 = qcar(v33);
    v33 = qcar(v33);
    v19 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v33 = stack[0];
    v33 = qcar(v33);
    v40 = qcdr(v33);
    v33 = stack[-1];
    v33 = acons(v19, v40, v33);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v27;

v28:
    v33 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v33);
    }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for all_defined_map_ */

static Lisp_Object CC_all_defined_map_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v29, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v17;
    v29 = v0;
/* end of prologue */
    v12 = v29;
    v29 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_map_ */
        return (*qfnn(fn))(qenv(fn), 3, v12, v29, v18);
    }
}



/* Code for groeb!=testb */

static Lisp_Object CC_groebMtestb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testb");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v162 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    v163 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = stack[0];
    v162 = qcar(v162);
    if (equal(v163, v162)) goto v5;
    v162 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v162); }

v5:
    stack[-2] = stack[-1];
    v163 = stack[0];
    v162 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = qcar(v162);
    fn = elt(env, 4); /* mo_divides!? */
    v162 = (*qfn2(fn))(qenv(fn), stack[-2], v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    if (v162 == nil) goto v42;
    v163 = stack[0];
    v162 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 3); /* pnth */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = qcar(v162);
    fn = elt(env, 5); /* bas_dpoly */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v163 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v163 = stack[0];
    v162 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = qcar(v162);
    fn = elt(env, 8); /* mo_equal!? */
    v162 = (*qfn2(fn))(qenv(fn), stack[-2], v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    if (v162 == nil) goto v59;
    v162 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v162); }

v59:
    v163 = stack[0];
    v162 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 3); /* pnth */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = qcar(v162);
    fn = elt(env, 5); /* bas_dpoly */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v163 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-1] = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v163 = stack[0];
    v162 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v162 = qcar(v162);
    fn = elt(env, 8); /* mo_equal!? */
    v162 = (*qfn2(fn))(qenv(fn), stack[-1], v162);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v162 = (v162 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v162); }

v42:
    v162 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v162); }
/* error exit handlers */
v104:
    popv(4);
    return nil;
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v8 = v0;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v7 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    v8 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v8 = (*qfn2(fn))(qenv(fn), v7, v8);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    qvalue(elt(env, 2)) = v8; /* g_dvnames */
    v8 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v8); }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+product");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-3] = v0;
/* end of prologue */
    v165 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v165 = stack[-1];
    fn = elt(env, 7); /* get!+vec!+dim */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    if (equal(stack[0], v165)) goto v45;
    v165 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v165 == nil)) goto v41;
    v165 = elt(env, 2); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 8); /* lprie */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    goto v41;

v41:
    v165 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    goto v45;

v45:
    v118 = qvalue(elt(env, 3)); /* nil */
    v165 = (Lisp_Object)17; /* 1 */
    v165 = cons(v118, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = qvalue(elt(env, 4)); /* !*complex */
    if (v165 == nil) goto v23;
    v165 = stack[-1];
    fn = elt(env, 9); /* mk!+conjugate!+vec */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[-4] = v165;
    goto v35;

v35:
    v165 = (Lisp_Object)17; /* 1 */
    stack[-2] = v165;
    goto v51;

v51:
    v165 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    v118 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v165 = stack[-2];
    v165 = difference2(v118, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v165 = Lminusp(nil, v165);
    env = stack[-5];
    if (v165 == nil) goto v167;
    v165 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v165; /* !*sub2 */
    v165 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[0] = v165;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v167:
    stack[-1] = stack[0];
    v118 = stack[-3];
    v165 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v118, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v118 = stack[-4];
    v165 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    v165 = (*qfn2(fn))(qenv(fn), v118, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    fn = elt(env, 12); /* multsq */
    v165 = (*qfn2(fn))(qenv(fn), stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    fn = elt(env, 13); /* addsq */
    v165 = (*qfn2(fn))(qenv(fn), stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = stack[-2];
    v165 = add1(v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[-2] = v165;
    goto v51;

v23:
    v165 = stack[-1];
    stack[-4] = v165;
    goto v35;
/* error exit handlers */
v168:
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v166:
    popv(6);
    return nil;
}



/* Code for freeof!-df */

static Lisp_Object CC_freeofKdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-df");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v151 = stack[-1];
    if (!consp(v151)) goto v27;
    v151 = stack[-1];
    v169 = qcar(v151);
    v151 = elt(env, 2); /* df */
    if (v169 == v151) goto v41;
    v151 = stack[-1];
    v169 = qcdr(v151);
    v151 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeof!-dfl */
        return (*qfn2(fn))(qenv(fn), v169, v151);
    }

v41:
    v151 = stack[-1];
    v151 = qcdr(v151);
    v169 = qcar(v151);
    v151 = stack[0];
    v151 = CC_freeofKdf(env, v169, v151);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (v151 == nil) goto v5;
    v169 = stack[0];
    v151 = stack[-1];
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    fn = elt(env, 5); /* smember */
    v151 = (*qfn2(fn))(qenv(fn), v169, v151);
    nil = C_nil;
    if (exception_pending()) goto v9;
    v151 = (v151 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v151); }

v5:
    v151 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v151); }

v27:
    v151 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v151); }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for mri_irsplit1 */

static Lisp_Object CC_mri_irsplit1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_irsplit1");
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
    v175 = stack[0];
    if (!consp(v175)) goto v29;
    v175 = stack[0];
    v175 = qcar(v175);
    v175 = (consp(v175) ? nil : lisp_true);
    goto v18;

v18:
    if (v175 == nil) goto v50;
    v175 = stack[0];
    popv(5);
    return ncons(v175);

v50:
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = CC_mri_irsplit1(env, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[-2] = v175;
    v175 = stack[0];
    v175 = qcar(v175);
    v175 = qcar(v175);
    v175 = qcdr(v175);
    stack[-1] = v175;
    v175 = stack[0];
    v175 = qcar(v175);
    v175 = qcar(v175);
    v177 = qcar(v175);
    v176 = (Lisp_Object)17; /* 1 */
    v175 = (Lisp_Object)17; /* 1 */
    v175 = acons(v177, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v176 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-1];
    fn = elt(env, 2); /* exptf */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[-1] = v175;
    v175 = stack[-1];
    v175 = qcar(v175);
    v175 = qcar(v175);
    v175 = qcar(v175);
    fn = elt(env, 3); /* mri_realvarp */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (v175 == nil) goto v113;
    v175 = stack[-2];
    stack[-3] = qcar(v175);
    v175 = stack[0];
    v175 = qcar(v175);
    v176 = qcdr(v175);
    v175 = stack[-1];
    fn = elt(env, 4); /* multf */
    v176 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 5); /* addf */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    {
        Lisp_Object v179 = stack[-3];
        popv(5);
        return cons(v179, v175);
    }

v113:
    v175 = stack[0];
    v175 = qcar(v175);
    v175 = qcdr(v175);
    v175 = CC_mri_irsplit1(env, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[-3] = v175;
    v175 = stack[-3];
    v176 = qcar(v175);
    v175 = stack[-1];
    fn = elt(env, 4); /* multf */
    v176 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-2];
    v175 = qcar(v175);
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-3];
    v176 = qcdr(v175);
    v175 = stack[-1];
    fn = elt(env, 4); /* multf */
    v176 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 5); /* addf */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    {
        Lisp_Object v180 = stack[0];
        popv(5);
        return cons(v180, v175);
    }

v29:
    v175 = qvalue(elt(env, 1)); /* t */
    goto v18;
/* error exit handlers */
v178:
    popv(5);
    return nil;
}



/* Code for pasf_cein */

static Lisp_Object CC_pasf_cein(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_cein");
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
    stack[-3] = v0;
/* end of prologue */
    v198 = stack[-3];
    v197 = elt(env, 1); /* true */
    if (v198 == v197) goto v12;
    v198 = stack[-3];
    v197 = elt(env, 3); /* false */
    v197 = (v198 == v197 ? lisp_true : nil);
    goto v29;

v29:
    if (v197 == nil) goto v174;
    v197 = qvalue(elt(env, 2)); /* t */
    goto v43;

v43:
    if (!(v197 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v197 = stack[-3];
    v197 = qcdr(v197);
    v197 = qcar(v197);
    fn = elt(env, 10); /* pasf_deci */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    stack[-2] = v197;
    v197 = stack[-2];
    v197 = qcar(v197);
    fn = elt(env, 11); /* sfto_dcontentf */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    stack[-4] = v197;
    v197 = stack[-3];
    stack[-1] = qcar(v197);
    v197 = stack[-4];
    fn = elt(env, 12); /* simp */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v197 = qcar(v197);
    v198 = qvalue(elt(env, 5)); /* !*exp */
    if (v198 == nil) goto v106;
    v198 = qvalue(elt(env, 6)); /* !*mcd */
    v198 = (v198 == nil ? lisp_true : nil);
    goto v105;

v105:
    if (v198 == nil) goto v200;
    v198 = stack[-2];
    v198 = qcar(v198);
    fn = elt(env, 13); /* quotf */
    v197 = (*qfn2(fn))(qenv(fn), v198, v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    stack[0] = v197;
    goto v201;

v201:
    v198 = stack[-3];
    v197 = elt(env, 1); /* true */
    if (v198 == v197) goto v202;
    v198 = stack[-3];
    v197 = elt(env, 3); /* false */
    v197 = (v198 == v197 ? lisp_true : nil);
    goto v203;

v203:
    if (v197 == nil) goto v204;
    v197 = stack[-3];
    v198 = v197;
    goto v101;

v101:
    v197 = elt(env, 7); /* (leq greaterp) */
    v197 = Lmemq(nil, v198, v197);
    if (v197 == nil) goto v205;
    v197 = stack[-2];
    v197 = qcdr(v197);
    v198 = negate(v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v197 = stack[-4];
    fn = elt(env, 14); /* pasf_floor */
    v197 = (*qfn2(fn))(qenv(fn), v198, v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    goto v74;

v74:
    fn = elt(env, 16); /* addf */
    v197 = (*qfn2(fn))(qenv(fn), stack[0], v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v198 = qvalue(elt(env, 9)); /* nil */
    {
        Lisp_Object v206 = stack[-1];
        popv(6);
        return list3(v206, v197, v198);
    }

v205:
    v198 = stack[-3];
    v197 = elt(env, 1); /* true */
    if (v198 == v197) goto v207;
    v198 = stack[-3];
    v197 = elt(env, 3); /* false */
    v197 = (v198 == v197 ? lisp_true : nil);
    goto v208;

v208:
    if (v197 == nil) goto v209;
    v197 = stack[-3];
    v198 = v197;
    goto v210;

v210:
    v197 = elt(env, 8); /* (geq lessp) */
    v197 = Lmemq(nil, v198, v197);
    if (v197 == nil) goto v211;
    v197 = stack[-2];
    v197 = qcdr(v197);
    v198 = negate(v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v197 = stack[-4];
    fn = elt(env, 17); /* pasf_ceil */
    v197 = (*qfn2(fn))(qenv(fn), v198, v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    goto v74;

v211:
    v197 = nil;
    goto v74;

v209:
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = Lconsp(nil, v197);
    env = stack[-5];
    if (v197 == nil) goto v212;
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = qcar(v197);
    v198 = v197;
    goto v210;

v212:
    v197 = stack[-3];
    v197 = qcar(v197);
    v198 = v197;
    goto v210;

v207:
    v197 = qvalue(elt(env, 2)); /* t */
    goto v208;

v204:
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = Lconsp(nil, v197);
    env = stack[-5];
    if (v197 == nil) goto v213;
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = qcar(v197);
    v198 = v197;
    goto v101;

v213:
    v197 = stack[-3];
    v197 = qcar(v197);
    v198 = v197;
    goto v101;

v202:
    v197 = qvalue(elt(env, 2)); /* t */
    goto v203;

v200:
    v198 = stack[-2];
    v198 = qcar(v198);
    fn = elt(env, 18); /* quotfx1 */
    v197 = (*qfn2(fn))(qenv(fn), v198, v197);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    stack[0] = v197;
    goto v201;

v106:
    v198 = qvalue(elt(env, 2)); /* t */
    goto v105;

v174:
    v198 = stack[-3];
    v197 = elt(env, 1); /* true */
    if (v198 == v197) goto v108;
    v198 = stack[-3];
    v197 = elt(env, 3); /* false */
    v197 = (v198 == v197 ? lisp_true : nil);
    goto v26;

v26:
    if (v197 == nil) goto v24;
    v197 = stack[-3];
    v198 = v197;
    goto v36;

v36:
    v197 = elt(env, 4); /* (leq greaterp geq lessp) */
    v197 = Lmemq(nil, v198, v197);
    v197 = (v197 == nil ? lisp_true : nil);
    goto v43;

v24:
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = Lconsp(nil, v197);
    env = stack[-5];
    if (v197 == nil) goto v156;
    v197 = stack[-3];
    v197 = qcar(v197);
    v197 = qcar(v197);
    v198 = v197;
    goto v36;

v156:
    v197 = stack[-3];
    v197 = qcar(v197);
    v198 = v197;
    goto v36;

v108:
    v197 = qvalue(elt(env, 2)); /* t */
    goto v26;

v12:
    v197 = qvalue(elt(env, 2)); /* t */
    goto v29;
/* error exit handlers */
v199:
    popv(6);
    return nil;
}



/* Code for ctx_union */

static Lisp_Object CC_ctx_union(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_union");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v17;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v175 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setkorder */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    stack[0] = v175;
    v175 = stack[0];
    fn = elt(env, 3); /* setkorder */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    v175 = stack[-3];
    fn = elt(env, 4); /* ctx_ial */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    stack[-3] = v175;
    v175 = stack[-2];
    fn = elt(env, 4); /* ctx_ial */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    stack[-2] = v175;
    v175 = stack[0];
    stack[-1] = v175;
    goto v42;

v42:
    v175 = stack[-1];
    if (v175 == nil) goto v70;
    v175 = stack[-1];
    v175 = qcar(v175);
    stack[0] = v175;
    v175 = stack[-3];
    if (v175 == nil) goto v25;
    v175 = stack[-3];
    v175 = qcar(v175);
    v176 = qcar(v175);
    v175 = stack[0];
    v175 = (v176 == v175 ? lisp_true : nil);
    goto v40;

v40:
    if (v175 == nil) goto v45;
    v175 = stack[-3];
    v176 = qcar(v175);
    v175 = stack[-4];
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    stack[-4] = v175;
    v175 = stack[-3];
    v175 = qcdr(v175);
    stack[-3] = v175;
    v175 = stack[-2];
    if (v175 == nil) goto v32;
    v175 = stack[-2];
    v175 = qcar(v175);
    v176 = qcar(v175);
    v175 = stack[0];
    if (!(v176 == v175)) goto v32;
    v175 = stack[-2];
    v175 = qcdr(v175);
    stack[-2] = v175;
    goto v32;

v32:
    v175 = stack[-1];
    v175 = qcdr(v175);
    stack[-1] = v175;
    goto v42;

v45:
    v175 = stack[-2];
    if (v175 == nil) goto v72;
    v175 = stack[-2];
    v175 = qcar(v175);
    v176 = qcar(v175);
    v175 = stack[0];
    v175 = (v176 == v175 ? lisp_true : nil);
    goto v172;

v172:
    if (v175 == nil) goto v32;
    v175 = stack[-2];
    v176 = qcar(v175);
    v175 = stack[-4];
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    stack[-4] = v175;
    v175 = stack[-2];
    v175 = qcdr(v175);
    stack[-2] = v175;
    goto v32;

v72:
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v172;

v25:
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v40;

v70:
    v175 = stack[-3];
    if (!(v175 == nil)) goto v105;
    v175 = stack[-2];
    if (!(v175 == nil)) goto v105;

v195:
    v175 = stack[-4];
    v175 = Lnreverse(nil, v175);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v175);
    }

v105:
    v175 = elt(env, 2); /* "***** ctx_union: idorder not complete" */
    v175 = Lprinc(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    v175 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-5];
    goto v195;
/* error exit handlers */
v178:
    popv(6);
    return nil;
}



/* Code for matrixir */

static Lisp_Object MS_CDECL CC_matrixir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v51, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixir");
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
    fn = elt(env, 5); /* lex */
    v169 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    fn = elt(env, 6); /* omobjs */
    v169 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v69 = v169;
    v169 = v69;
    v169 = qcdr(v169);
    v169 = qcar(v169);
    v169 = qcdr(v169);
    v169 = qcar(v169);
    v51 = qcar(v169);
    v169 = elt(env, 1); /* matrixcolumn */
    if (v51 == v169) goto v21;
    stack[0] = elt(env, 3); /* matrixrow */
    v169 = v69;
    fn = elt(env, 7); /* matrixelems */
    v51 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v169 = qvalue(elt(env, 2)); /* nil */
    v169 = list2star(stack[0], v51, v169);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v69 = v169;
    goto v26;

v26:
    v169 = elt(env, 4); /* matrix */
    v51 = qvalue(elt(env, 2)); /* nil */
    popv(2);
    return list2star(v169, v51, v69);

v21:
    stack[0] = elt(env, 1); /* matrixcolumn */
    v169 = v69;
    fn = elt(env, 7); /* matrixelems */
    v51 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v169 = qvalue(elt(env, 2)); /* nil */
    v169 = list2star(stack[0], v51, v169);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v69 = v169;
    goto v26;
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for i2crn!* */

static Lisp_Object CC_i2crnH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2crn*");
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
    v109 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:crn!: */
    v44 = v109;
    v109 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v44, v109);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v44 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)17; /* 1 */
    v109 = cons(v44, v109);
    nil = C_nil;
    if (exception_pending()) goto v31;
    {
        Lisp_Object v45 = stack[-1];
        Lisp_Object v33 = stack[0];
        popv(3);
        return list2star(v45, v33, v109);
    }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for solvealgtrig01 */

static Lisp_Object CC_solvealgtrig01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgtrig01");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */

v56:
    v51 = stack[-1];
    if (!consp(v51)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v51 = stack[-1];
    v69 = qcar(v51);
    v51 = elt(env, 1); /* (sin cos tan cot sinh cosh tanh coth) */
    v51 = Lmemq(nil, v69, v51);
    if (v51 == nil) goto v23;
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcar(v51);
    fn = elt(env, 2); /* constant_exprp */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    if (!(v51 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v69 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v51 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v69, v51);
    }

v23:
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-2] = v51;
    v51 = stack[-1];
    v69 = qcar(v51);
    v51 = stack[0];
    v51 = CC_solvealgtrig01(env, v69, v51);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    stack[0] = v51;
    v51 = stack[-2];
    stack[-1] = v51;
    goto v56;
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_item");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */

v27:
    v69 = stack[0];
    v69 = qcdr(v69);
    if (v69 == nil) goto v7;
    v69 = stack[0];
    v69 = qcar(v69);
    v9 = qcar(v69);
    v69 = stack[-1];
    v69 = qcar(v69);
    fn = elt(env, 3); /* monordp */
    v69 = (*qfn2(fn))(qenv(fn), v9, v69);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (v69 == nil) goto v113;
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcar(v69);
    stack[0] = v69;
    goto v27;

v113:
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v27;

v7:
    v9 = stack[0];
    v69 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v69 = (*qfn2(fn))(qenv(fn), v9, v69);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v69 = elt(env, 1); /* !*xset!* */
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v69 = acons(stack[-1], stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v69 = (*qfn2(fn))(qenv(fn), stack[-2], v69);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v69 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v69); }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for gbftimes */

static Lisp_Object CC_gbftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbftimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v55 = v17;
    v15 = v0;
/* end of prologue */
    v54 = v15;
    v54 = qcar(v54);
    stack[-4] = v54;
    v54 = v15;
    v54 = qcdr(v54);
    stack[-3] = v54;
    v54 = v55;
    v54 = qcar(v54);
    stack[-2] = v54;
    v54 = v55;
    v54 = qcdr(v54);
    stack[-1] = v54;
    v55 = stack[-4];
    v54 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    v55 = stack[-3];
    v54 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    fn = elt(env, 2); /* difbf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    v55 = stack[-4];
    v54 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    v55 = stack[-3];
    v54 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    fn = elt(env, 3); /* plubf */
    v54 = (*qfn2(fn))(qenv(fn), stack[-1], v54);
    nil = C_nil;
    if (exception_pending()) goto v64;
    {
        Lisp_Object v164 = stack[0];
        popv(6);
        return cons(v164, v54);
    }
/* error exit handlers */
v64:
    popv(6);
    return nil;
}



/* Code for kernelp */

static Lisp_Object CC_kernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernelp");
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
    v75 = stack[0];
    if (v75 == nil) goto v28;
    v75 = stack[0];
    fn = elt(env, 4); /* domain!*p */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    goto v141;

v141:
    if (v75 == nil) goto v27;
    v75 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v75); }

v27:
    v75 = stack[0];
    if (symbolp(v75)) goto v70;
    v75 = stack[0];
    fn = elt(env, 5); /* listp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    if (v75 == nil) goto v36;
    v75 = stack[0];
    v75 = qcar(v75);
    if (!(symbolp(v75))) goto v36;
    v75 = stack[0];
    v52 = qcar(v75);
    v75 = elt(env, 3); /* (!*sq set setq plus minus difference times quotient) 
*/
    v75 = Lmemq(nil, v52, v75);
    if (!(v75 == nil)) goto v36;
    v75 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v75); }

v36:
    v75 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v75); }

v70:
    v75 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v75); }

v28:
    v75 = qvalue(elt(env, 1)); /* t */
    goto v141;
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for diff_vertex */

static Lisp_Object CC_diff_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff_vertex");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v65 = nil;
    goto v56;

v56:
    v1 = stack[-1];
    if (v1 == nil) goto v49;
    v1 = stack[-1];
    v1 = qcar(v1);
    v2 = qcar(v1);
    v1 = stack[0];
    v1 = Lassoc(nil, v2, v1);
    if (v1 == nil) goto v39;
    v1 = stack[-1];
    v1 = qcar(v1);
    v2 = qcar(v1);
    v1 = qvalue(elt(env, 1)); /* !_0edge */
    v1 = qcar(v1);
    if (v2 == v1) goto v39;
    v1 = stack[-1];
    v1 = qcdr(v1);
    stack[-1] = v1;
    goto v56;

v39:
    v1 = stack[-1];
    v1 = qcar(v1);
    v2 = v65;
    v1 = cons(v1, v2);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v65 = v1;
    v1 = stack[-1];
    v1 = qcdr(v1);
    stack[-1] = v1;
    goto v56;

v49:
    v1 = v65;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v89, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatelem");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    v222 = stack[-2];
    v89 = Llength(nil, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v222 = (Lisp_Object)49; /* 3 */
    if (v89 == v222) goto v44;
    v89 = stack[-2];
    v222 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v222 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v44;

v44:
    v222 = stack[-2];
    v89 = qcar(v222);
    v222 = elt(env, 2); /* avalue */
    v222 = get(v89, v222);
    env = stack[-4];
    stack[-3] = v222;
    v222 = stack[-3];
    if (v222 == nil) goto v30;
    v222 = stack[-3];
    v89 = qcar(v222);
    v222 = elt(env, 4); /* matrix */
    v222 = (v89 == v222 ? lisp_true : nil);
    v222 = (v222 == nil ? lisp_true : nil);
    goto v36;

v36:
    if (v222 == nil) goto v167;
    v222 = stack[-2];
    v89 = qcar(v222);
    v222 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v222 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v47;

v47:
    v222 = stack[-2];
    v222 = qcdr(v222);
    v222 = qcar(v222);
    fn = elt(env, 13); /* reval_without_mod */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[0] = v222;
    v222 = stack[0];
    v222 = integerp(v222);
    if (v222 == nil) goto v168;
    v89 = stack[0];
    v222 = (Lisp_Object)1; /* 0 */
    v222 = (Lisp_Object)lesseq2(v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = v222 ? lisp_true : nil;
    env = stack[-4];
    goto v166;

v166:
    if (v222 == nil) goto v225;
    v89 = stack[0];
    v222 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v222 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v225;

v225:
    v222 = stack[-3];
    v89 = qcdr(v222);
    v222 = stack[0];
    fn = elt(env, 14); /* pnth */
    v222 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v222 = qcar(v222);
    stack[-3] = v222;
    v222 = stack[-2];
    v222 = qcdr(v222);
    v222 = qcdr(v222);
    v222 = qcar(v222);
    fn = elt(env, 13); /* reval_without_mod */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[0] = v222;
    v222 = stack[0];
    v222 = integerp(v222);
    if (v222 == nil) goto v190;
    v89 = stack[0];
    v222 = (Lisp_Object)1; /* 0 */
    v222 = (Lisp_Object)lesseq2(v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = v222 ? lisp_true : nil;
    env = stack[-4];
    goto v97;

v97:
    if (v222 == nil) goto v95;
    v89 = stack[0];
    v222 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v222 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v95;

v95:
    v89 = stack[-3];
    v222 = stack[0];
    fn = elt(env, 14); /* pnth */
    v89 = (*qfn2(fn))(qenv(fn), v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = stack[-1];
        popv(5);
        return Lrplaca(nil, v89, v222);

v190:
    v222 = qvalue(elt(env, 3)); /* t */
    goto v97;

v168:
    v222 = qvalue(elt(env, 3)); /* t */
    goto v166;

v167:
    v222 = stack[-3];
    v222 = qcdr(v222);
    v89 = qcar(v222);
    stack[-3] = v89;
    v222 = elt(env, 6); /* mat */
    if (!consp(v89)) goto v107;
    v89 = qcar(v89);
    if (v89 == v222) goto v47;
    else goto v107;

v107:
    v223 = elt(env, 7); /* "Matrix" */
    v222 = stack[-2];
    v89 = qcar(v222);
    v222 = elt(env, 8); /* "not set" */
    v222 = list3(v223, v89, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v89 = v222;
    v222 = v89;
    qvalue(elt(env, 9)) = v222; /* errmsg!* */
    v222 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v222 == nil)) goto v161;
    v222 = v89;
    fn = elt(env, 15); /* lprie */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v161;

v161:
    v222 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v47;

v30:
    v222 = qvalue(elt(env, 3)); /* t */
    goto v36;
/* error exit handlers */
v224:
    popv(5);
    return nil;
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v64, v164, v119, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rfirst");
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
    v67 = stack[0];
    v67 = qcar(v67);
    stack[0] = v67;
    v67 = stack[0];
    fn = elt(env, 7); /* listeval0 */
    v64 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    stack[-1] = v64;
    v67 = elt(env, 1); /* list */
    if (!consp(v64)) goto v16;
    v64 = qcar(v64);
    if (!(v64 == v67)) goto v16;
    v67 = qvalue(elt(env, 2)); /* nil */
    goto v8;

v8:
    if (v67 == nil) goto v28;
    v64 = stack[0];
    v67 = elt(env, 3); /* "list" */
    fn = elt(env, 8); /* typerr */
    v67 = (*qfn2(fn))(qenv(fn), v64, v67);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    goto v28;

v28:
    v67 = stack[-1];
    v67 = qcdr(v67);
    if (v67 == nil) goto v174;
    v67 = stack[-1];
    v67 = qcdr(v67);
    v67 = qcar(v67);
    {
        popv(3);
        fn = elt(env, 9); /* reval */
        return (*qfn1(fn))(qenv(fn), v67);
    }

v174:
    v171 = elt(env, 4); /* "Expression" */
    v119 = stack[0];
    v164 = elt(env, 5); /* "does not have part" */
    v64 = (Lisp_Object)17; /* 1 */
    v67 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 10); /* msgpri */
    v67 = (*qfnn(fn))(qenv(fn), 5, v171, v119, v164, v64, v67);
    nil = C_nil;
    if (exception_pending()) goto v116;
    v67 = nil;
    { popv(3); return onevalue(v67); }

v16:
    v67 = stack[0];
    fn = elt(env, 11); /* aeval */
    v64 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    stack[-1] = v64;
    v67 = elt(env, 1); /* list */
    v67 = Leqcar(nil, v64, v67);
    env = stack[-2];
    v67 = (v67 == nil ? lisp_true : nil);
    goto v8;
/* error exit handlers */
v116:
    popv(3);
    return nil;
}



/* Code for bc_from_a */

static Lisp_Object CC_bc_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_from_a");
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
    v56 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[0];
    v56 = qcar(v56);
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v141:
    popv(1);
    return nil;
}



/* Code for st_sorttree1 */

static Lisp_Object MS_CDECL CC_st_sorttree1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v278, v279, v280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v6;
    stack[-9] = v17;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v278 = (Lisp_Object)17; /* 1 */
    stack[-6] = v278;
    v278 = stack[-10];
    v278 = qcdr(v278);
    v278 = qcar(v278);
    if (is_number(v278)) goto v21;
    v278 = stack[-10];
    v279 = qcar(v278);
    v278 = elt(env, 1); /* !* */
    if (v279 == v278) goto v98;
    v278 = stack[-10];
    v278 = qcdr(v278);
    stack[0] = v278;
    goto v281;

v281:
    v278 = stack[0];
    if (v278 == nil) goto v282;
    v278 = stack[0];
    v278 = qcar(v278);
    v280 = v278;
    v279 = stack[-6];
    v278 = (Lisp_Object)1; /* 0 */
    if (v279 == v278) goto v283;
    v279 = stack[-9];
    v278 = stack[-8];
    v278 = CC_st_sorttree1(env, 3, v280, v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v278;
    v279 = stack[-6];
    v278 = stack[-2];
    v278 = qcdr(v278);
    v278 = qcar(v278);
    v278 = times2(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v278;
    v278 = stack[-2];
    v278 = qcdr(v278);
    v280 = qcdr(v278);
    v278 = stack[-2];
    v279 = qcar(v278);
    v278 = stack[-1];
    v278 = acons(v280, v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v278;
    goto v283;

v283:
    v278 = stack[0];
    v278 = qcdr(v278);
    stack[0] = v278;
    goto v281;

v282:
    v279 = stack[-6];
    v278 = (Lisp_Object)1; /* 0 */
    if (v279 == v278) goto v285;
    v278 = stack[-10];
    v279 = qcar(v278);
    v278 = elt(env, 3); /* !+ */
    if (v279 == v278) goto v286;
    v279 = stack[-1];
    v278 = stack[-8];
    fn = elt(env, 4); /* cdr_signsort */
    v278 = (*qfn2(fn))(qenv(fn), v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v278;
    v278 = stack[-1];
    v279 = qcar(v278);
    v278 = (Lisp_Object)1; /* 0 */
    if (v279 == v278) goto v287;
    v279 = stack[-6];
    v278 = stack[-1];
    v278 = qcar(v278);
    v278 = times2(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v278;
    v278 = stack[-1];
    v278 = qcdr(v278);
    stack[-1] = v278;
    goto v288;

v288:
    v278 = stack[-1];
    if (v278 == nil) goto v289;
    v278 = stack[-1];
    v278 = qcar(v278);
    v279 = qcar(v278);
    v278 = stack[-7];
    v278 = cons(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v278;
    v278 = stack[-1];
    v278 = qcar(v278);
    v279 = qcdr(v278);
    v278 = stack[-11];
    v278 = cons(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v278;
    v278 = stack[-1];
    v278 = qcdr(v278);
    stack[-1] = v278;
    goto v288;

v289:
    v278 = stack[-10];
    stack[0] = qcar(v278);
    v278 = stack[-7];
    v278 = Lreverse(nil, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = cons(stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v278;
    v278 = stack[-11];
    v278 = Lreverse(nil, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    stack[-11] = v278;
    v280 = stack[-11];
    v279 = stack[-6];
    v278 = stack[-7];
    popv(13);
    return list2star(v280, v279, v278);

v287:
    v279 = qvalue(elt(env, 2)); /* nil */
    v278 = (Lisp_Object)1; /* 0 */
    v280 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v279, v278, v280);

v286:
    v279 = stack[-1];
    v278 = stack[-8];
    fn = elt(env, 5); /* cdr_sort */
    v278 = (*qfn2(fn))(qenv(fn), v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v278;
    goto v288;

v285:
    v279 = qvalue(elt(env, 2)); /* nil */
    v278 = (Lisp_Object)1; /* 0 */
    v280 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v279, v278, v280);

v98:
    v278 = stack[-10];
    v278 = qcdr(v278);
    stack[0] = v278;
    goto v153;

v153:
    v278 = stack[0];
    if (v278 == nil) goto v290;
    v278 = stack[0];
    v278 = qcar(v278);
    v280 = v278;
    v279 = stack[-6];
    v278 = (Lisp_Object)1; /* 0 */
    if (v279 == v278) goto v291;
    v279 = stack[-9];
    v278 = stack[-8];
    v278 = CC_st_sorttree1(env, 3, v280, v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v278;
    v279 = stack[-6];
    v278 = stack[-2];
    v278 = qcdr(v278);
    v278 = qcar(v278);
    v278 = times2(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v278;
    v278 = stack[-2];
    v279 = qcar(v278);
    v278 = stack[-11];
    v278 = cons(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v278;
    v278 = stack[-2];
    v278 = qcdr(v278);
    v279 = qcdr(v278);
    v278 = stack[-7];
    v278 = cons(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v278;
    goto v291;

v291:
    v278 = stack[0];
    v278 = qcdr(v278);
    stack[0] = v278;
    goto v153;

v290:
    v279 = stack[-6];
    v278 = (Lisp_Object)1; /* 0 */
    if (v279 == v278) goto v292;
    v278 = stack[-7];
    v278 = Lreverse(nil, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v278;
    v278 = stack[-11];
    v278 = Lreverse(nil, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v278;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v279 = elt(env, 1); /* !* */
    v278 = stack[-7];
    v278 = cons(v279, v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    {
        Lisp_Object v293 = stack[0];
        Lisp_Object v294 = stack[-1];
        popv(13);
        return list2star(v293, v294, v278);
    }

v292:
    v279 = qvalue(elt(env, 2)); /* nil */
    v278 = (Lisp_Object)1; /* 0 */
    v280 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v279, v278, v280);

v21:
    v278 = stack[-10];
    v279 = qcar(v278);
    v278 = elt(env, 1); /* !* */
    if (v279 == v278) goto v5;
    v278 = stack[-10];
    v278 = qcdr(v278);
    stack[-5] = v278;
    v278 = stack[-5];
    if (v278 == nil) goto v295;
    v278 = stack[-5];
    v278 = qcar(v278);
    stack[-1] = v278;
    stack[0] = stack[-9];
    v278 = sub1(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL)));
    v278 = cons(stack[-1], v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-3] = v278;
    stack[-4] = v278;
    goto v103;

v103:
    v278 = stack[-5];
    v278 = qcdr(v278);
    stack[-5] = v278;
    v278 = stack[-5];
    if (v278 == nil) goto v225;
    stack[-2] = stack[-3];
    v278 = stack[-5];
    v278 = qcar(v278);
    stack[-1] = v278;
    stack[0] = stack[-9];
    v278 = sub1(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL)));
    v278 = cons(stack[-1], v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = Lrplacd(nil, stack[-2], v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = stack[-3];
    v278 = qcdr(v278);
    stack[-3] = v278;
    goto v103;

v225:
    v278 = stack[-4];
    goto v148;

v148:
    stack[-1] = v278;
    goto v282;

v295:
    v278 = qvalue(elt(env, 2)); /* nil */
    goto v148;

v5:
    v278 = stack[-10];
    v278 = qcdr(v278);
    stack[-4] = v278;
    v278 = stack[-4];
    if (v278 == nil) goto v36;
    v278 = stack[-4];
    v278 = qcar(v278);
    stack[0] = stack[-9];
    v278 = sub1(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL)));
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v278;
    stack[-3] = v278;
    goto v46;

v46:
    v278 = stack[-4];
    v278 = qcdr(v278);
    stack[-4] = v278;
    v278 = stack[-4];
    if (v278 == nil) goto v9;
    stack[-1] = stack[-2];
    v278 = stack[-4];
    v278 = qcar(v278);
    stack[0] = stack[-9];
    v278 = sub1(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL)));
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = Lrplacd(nil, stack[-1], v278);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v278 = stack[-2];
    v278 = qcdr(v278);
    stack[-2] = v278;
    goto v46;

v9:
    v278 = stack[-3];
    goto v19;

v19:
    stack[-11] = v278;
    v280 = stack[-11];
    v279 = (Lisp_Object)17; /* 1 */
    v278 = stack[-10];
    popv(13);
    return list2star(v280, v279, v278);

v36:
    v278 = qvalue(elt(env, 2)); /* nil */
    goto v19;
/* error exit handlers */
v284:
    popv(13);
    return nil;
}



/* Code for ofsf_bestgaussp */

static Lisp_Object CC_ofsf_bestgaussp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v172, v173;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_bestgaussp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v173 = v0;
/* end of prologue */
    v216 = v173;
    v172 = qcar(v216);
    v216 = elt(env, 1); /* failed */
    if (v172 == v216) goto v58;
    v216 = v173;
    v172 = qcar(v216);
    v216 = elt(env, 2); /* gignore */
    if (v172 == v216) goto v156;
    v216 = v173;
    v216 = qcar(v216);
    v216 = qcdr(v216);
    v172 = qcar(v216);
    v216 = elt(env, 3); /* lin */
    if (v172 == v216) goto v75;
    v216 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v216);

v75:
    v216 = v173;
    v216 = qcar(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v172 = qcar(v216);
    v216 = elt(env, 4); /* con */
    if (v172 == v216) goto v30;
    v216 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v216);

v30:
    v216 = v173;
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = qcdr(v216);
    if (v216 == nil) goto v150;
    v216 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v216);

v150:
    v216 = v173;
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = (v216 == nil ? lisp_true : nil);
    return onevalue(v216);

v156:
    v216 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v216);

v58:
    v216 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v216);
}



/* Code for merge_lists */

static Lisp_Object CC_merge_lists(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge_lists");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v17;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v218 = (Lisp_Object)17; /* 1 */
    stack[0] = v218;
    v218 = stack[-5];
    v218 = Lreverse(nil, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-5] = v218;
    v218 = stack[-5];
    if (v218 == nil) goto v8;
    v218 = stack[-5];
    v218 = qcar(v218);
    stack[-6] = v218;
    goto v43;

v43:
    v218 = stack[-4];
    if (v218 == nil) goto v8;
    v218 = stack[-4];
    v218 = qcar(v218);
    stack[-2] = v218;
    v95 = stack[-6];
    v218 = stack[-2];
    v218 = (Lisp_Object)lessp2(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v218 = v218 ? lisp_true : nil;
    env = stack[-7];
    if (!(v218 == nil)) goto v8;
    v95 = stack[-2];
    v218 = stack[-3];
    v218 = cons(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-3] = v218;
    v218 = stack[-1];
    v218 = (v218 == nil ? lisp_true : nil);
    stack[-1] = v218;
    v218 = stack[-4];
    v218 = qcdr(v218);
    stack[-4] = v218;
    goto v43;

v8:
    v218 = stack[-5];
    if (v218 == nil) goto v68;
    v218 = stack[-3];
    if (v218 == nil) goto v149;
    v218 = stack[-3];
    v218 = qcar(v218);
    stack[-2] = v218;
    v95 = stack[-6];
    v218 = stack[-2];
    if (equal(v95, v218)) goto v163;
    v218 = qvalue(elt(env, 1)); /* nil */
    goto v118;

v118:
    if (v218 == nil) goto v125;
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v218); }

v125:
    v95 = stack[-6];
    v218 = stack[-2];
    v218 = (Lisp_Object)greaterp2(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v218 = v218 ? lisp_true : nil;
    env = stack[-7];
    if (v218 == nil) goto v178;
    v95 = stack[-6];
    v218 = stack[-4];
    v218 = cons(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-4] = v218;
    v218 = stack[-5];
    v218 = qcdr(v218);
    stack[-5] = v218;
    v218 = stack[-1];
    if (v218 == nil) goto v202;
    v95 = stack[-6];
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)greaterp2(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v218 = v218 ? lisp_true : nil;
    env = stack[-7];
    if (v218 == nil) goto v202;
    v218 = stack[0];
    v218 = negate(v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[0] = v218;
    goto v202;

v202:
    v218 = stack[-5];
    if (v218 == nil) goto v8;
    v218 = stack[-5];
    v218 = qcar(v218);
    stack[-6] = v218;
    goto v8;

v178:
    v95 = stack[-2];
    v218 = stack[-4];
    v218 = cons(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-4] = v218;
    v218 = stack[-3];
    v218 = qcdr(v218);
    stack[-3] = v218;
    v218 = stack[-1];
    v218 = (v218 == nil ? lisp_true : nil);
    stack[-1] = v218;
    goto v8;

v163:
    v95 = stack[-6];
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)greaterp2(v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v218 = v218 ? lisp_true : nil;
    env = stack[-7];
    goto v118;

v149:
    v95 = stack[-5];
    v218 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v218 = (*qfn2(fn))(qenv(fn), v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    {
        Lisp_Object v89 = stack[0];
        popv(8);
        return cons(v89, v218);
    }

v68:
    v95 = stack[-3];
    v218 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v218 = (*qfn2(fn))(qenv(fn), v95, v218);
    nil = C_nil;
    if (exception_pending()) goto v222;
    {
        Lisp_Object v223 = stack[0];
        popv(8);
        return cons(v223, v218);
    }
/* error exit handlers */
v222:
    popv(8);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v8;

v8:
    v114 = stack[-1];
    v108 = (Lisp_Object)17; /* 1 */
    if (v114 == v108) goto v3;
    v108 = stack[-2];
    v114 = qcar(v108);
    v108 = stack[-3];
    v108 = cons(v114, v108);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-2];
    v108 = qcdr(v108);
    stack[-2] = v108;
    v108 = stack[-1];
    v108 = sub1(v108);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[-1] = v108;
    goto v8;

v3:
    stack[-1] = stack[-3];
    v114 = stack[0];
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = cons(v114, v108);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    {
        Lisp_Object v150 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v150, v108);
    }
/* error exit handlers */
v113:
    popv(5);
    return nil;
}



/* Code for get!*nr!*real!*irred!*reps */

static Lisp_Object CC_getHnrHrealHirredHreps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v7 = elt(env, 1); /* realrepnumber */
    return get(v8, v7);
}



/* Code for mri_ofsf2mriat */

static Lisp_Object CC_mri_ofsf2mriat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v42, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v17;
    v42 = v0;
/* end of prologue */
    v48 = v42;
    v48 = qcar(v48);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v48, v42, v70);
    }
}



/* Code for aex_red */

static Lisp_Object CC_aex_red(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_red");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v19 = v17;
    stack[0] = v0;
/* end of prologue */
    v46 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v19 = (*qfn2(fn))(qenv(fn), v46, v19);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (v19 == nil) goto v45;
    v19 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_red */
    stack[-1] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    v19 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v47 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    v46 = qvalue(elt(env, 1)); /* nil */
    v19 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v36 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v36, v47, v46, v19);
    }

v45:
    {
        popv(3);
        fn = elt(env, 7); /* aex_0 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for seprd */

static Lisp_Object MS_CDECL CC_seprd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "seprd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for seprd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v31 = qvalue(elt(env, 2)); /* char */
    v32 = elt(env, 3); /* (s e p !/) */
    if (equal(v31, v32)) goto v28;
    v31 = elt(env, 4); /* "<sep/>" */
    v32 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* errorml */
    v32 = (*qfn2(fn))(qenv(fn), v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[0];
    goto v28;

v28:
    fn = elt(env, 6); /* lex */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[0];
    v32 = qvalue(elt(env, 2)); /* char */
        popv(1);
        return Lcompress(nil, v32);
/* error exit handlers */
v45:
    popv(1);
    return nil;
}



/* Code for mkratnum */

static Lisp_Object CC_mkratnum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v9, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkratnum");
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
    v10 = v0;
/* end of prologue */
    v69 = v10;
    if (!consp(v69)) goto v28;
    v69 = v10;
    v9 = qcar(v69);
    v69 = elt(env, 2); /* !:gi!: */
    if (v9 == v69) goto v19;
    v69 = v10;
    v9 = qcar(v69);
    v69 = elt(env, 1); /* !:rn!: */
    v69 = get(v9, v69);
    v9 = v10;
        return Lapply1(nil, v69, v9);

v19:
    v9 = elt(env, 2); /* !:gi!: */
    v69 = elt(env, 3); /* !:crn!: */
    v69 = get(v9, v69);
    v9 = v10;
        return Lapply1(nil, v69, v9);

v28:
    v9 = elt(env, 1); /* !:rn!: */
    v69 = (Lisp_Object)17; /* 1 */
    return list2star(v9, v10, v69);
}



/* Code for tp */

static Lisp_Object CC_tp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp");
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
    v27 = v0;
/* end of prologue */
    fn = elt(env, 1); /* matsm */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* tp1 */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v56:
    popv(1);
    return nil;
}



/* Code for fs!:subang */

static Lisp_Object MS_CDECL CC_fsTsubang(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v218, v95, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:subang");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v6;
    stack[-6] = v17;
    stack[-7] = v0;
/* end of prologue */
    v94 = stack[-7];
    if (v94 == nil) goto v56;
    v94 = (Lisp_Object)113; /* 7 */
    v94 = Lmkvect(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    stack[-8] = v94;
    v218 = stack[-7];
    v94 = (Lisp_Object)33; /* 2 */
    v218 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v94 = stack[-6];
    v94 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    stack[-4] = v94;
    v94 = (Lisp_Object)1; /* 0 */
    stack[-3] = v94;
    goto v75;

v75:
    v218 = (Lisp_Object)113; /* 7 */
    v94 = stack[-3];
    v94 = difference2(v218, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    v94 = Lminusp(nil, v94);
    env = stack[-9];
    if (v94 == nil) goto v113;
    v218 = stack[-7];
    v94 = (Lisp_Object)49; /* 3 */
    v95 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v218 = stack[-6];
    v94 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v95, v218, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    v218 = stack[-7];
    v94 = (Lisp_Object)17; /* 1 */
    v153 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v95 = stack[-8];
    v218 = stack[-7];
    v94 = (Lisp_Object)1; /* 0 */
    v94 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    fn = elt(env, 2); /* make!-term */
    v94 = (*qfnn(fn))(qenv(fn), 3, v153, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    {
        Lisp_Object v155 = stack[0];
        popv(10);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v155, v94);
    }

v113:
    v218 = stack[-3];
    v94 = stack[-6];
    if (equal(v218, v94)) goto v10;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v218 = stack[-7];
    v94 = (Lisp_Object)33; /* 2 */
    v218 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v94 = stack[-3];
    stack[0] = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v95 = stack[-4];
    v218 = stack[-5];
    v94 = stack[-3];
    v94 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v94 = times2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    v94 = plus2(stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v94;
    goto v1;

v1:
    v94 = stack[-3];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    stack[-3] = v94;
    goto v75;

v10:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v95 = stack[-4];
    v218 = stack[-5];
    v94 = stack[-3];
    v94 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL)));
    v94 = times2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v94;
    goto v1;

v56:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v94); }
/* error exit handlers */
v302:
    popv(10);
    return nil;
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v308, v309, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-further");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v17;
    stack[-3] = v0;
/* end of prologue */
    v210 = stack[-3];
    if (v210 == nil) goto v56;
    v210 = stack[-3];
    v309 = qcdr(v210);
    v308 = stack[-2];
    v210 = stack[-1];
    v210 = CC_splitKfurther(env, 3, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[-4] = v210;
    v210 = stack[-4];
    v210 = qcdr(v210);
    stack[0] = v210;
    v210 = stack[-4];
    v210 = qcar(v210);
    stack[-4] = v210;
    v308 = qvalue(elt(env, 2)); /* number!-needed */
    v210 = (Lisp_Object)1; /* 0 */
    if (v308 == v210) goto v224;
    v309 = stack[-2];
    v308 = stack[-1];
    v210 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 8); /* copy!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    qvalue(elt(env, 4)) = v210; /* dwork1 */
    v210 = stack[-3];
    v210 = qcar(v210);
    v309 = qcar(v210);
    v210 = stack[-3];
    v210 = qcar(v210);
    v308 = qcdr(v210);
    v210 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    qvalue(elt(env, 6)) = v210; /* dwork2 */
    v184 = qvalue(elt(env, 3)); /* work!-vector1 */
    v309 = qvalue(elt(env, 4)); /* dwork1 */
    v308 = qvalue(elt(env, 5)); /* work!-vector2 */
    v210 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 9); /* gcd!-in!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 4, v184, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    qvalue(elt(env, 4)) = v210; /* dwork1 */
    v308 = qvalue(elt(env, 4)); /* dwork1 */
    v210 = (Lisp_Object)1; /* 0 */
    if (v308 == v210) goto v115;
    v308 = qvalue(elt(env, 4)); /* dwork1 */
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = (equal(v308, v210) ? lisp_true : nil);
    goto v149;

v149:
    if (!(v210 == nil)) goto v224;
    v210 = stack[-3];
    v210 = qcar(v210);
    v309 = qcar(v210);
    v210 = stack[-3];
    v210 = qcar(v210);
    v308 = qcdr(v210);
    v210 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    qvalue(elt(env, 6)) = v210; /* dwork2 */
    v184 = qvalue(elt(env, 5)); /* work!-vector2 */
    v309 = qvalue(elt(env, 6)); /* dwork2 */
    v308 = qvalue(elt(env, 3)); /* work!-vector1 */
    v210 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 10); /* quotfail!-in!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 4, v184, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    qvalue(elt(env, 6)) = v210; /* dwork2 */
    v210 = qvalue(elt(env, 4)); /* dwork1 */
    v210 = Lmkvect(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[-1] = v210;
    v309 = qvalue(elt(env, 3)); /* work!-vector1 */
    v308 = qvalue(elt(env, 4)); /* dwork1 */
    v210 = stack[-1];
    fn = elt(env, 8); /* copy!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v309 = stack[-1];
    v308 = qvalue(elt(env, 4)); /* dwork1 */
    v210 = stack[-4];
    v210 = acons(v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[-4] = v210;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v210 = qvalue(elt(env, 6)); /* dwork2 */
    v210 = Lmkvect(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[-3] = v210;
    fn = elt(env, 8); /* copy!-vector */
    v210 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v309 = stack[-3];
    v308 = qvalue(elt(env, 6)); /* dwork2 */
    v210 = stack[0];
    v210 = acons(v309, v308, v210);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[0] = v210;
    v210 = qvalue(elt(env, 2)); /* number!-needed */
    v210 = (Lisp_Object)((int32_t)(v210) - 0x10);
    qvalue(elt(env, 2)) = v210; /* number!-needed */
    v308 = stack[-4];
    v210 = stack[0];
    popv(6);
    return cons(v308, v210);

v224:
    v309 = stack[-4];
    v210 = stack[-3];
    v308 = qcar(v210);
    v210 = stack[0];
    popv(6);
    return list2star(v309, v308, v210);

v115:
    v210 = qvalue(elt(env, 7)); /* t */
    goto v149;

v56:
    v210 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v210);
/* error exit handlers */
v207:
    popv(6);
    return nil;
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v291, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor1");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v17;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v8;

v8:
    v291 = stack[-4];
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)lessp2(v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-6];
    if (v131 == nil) goto v19;
    v224 = (Lisp_Object)-15; /* -1 */
    v291 = (Lisp_Object)17; /* 1 */
    v131 = stack[0];
    v131 = acons(v224, v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[0] = v131;
    v131 = stack[-4];
    v131 = negate(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[-4] = v131;
    goto v8;

v19:
    v291 = stack[-4];
    v131 = (Lisp_Object)65; /* 4 */
    v131 = (Lisp_Object)lessp2(v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-6];
    if (v131 == nil) goto v69;
    v291 = stack[-4];
    v131 = (Lisp_Object)17; /* 1 */
    v131 = cons(v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    {
        Lisp_Object v211 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v131);
    }

v69:
    stack[-5] = stack[0];
    v131 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v131;
    v131 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v131;
    goto v119;

v119:
    v131 = stack[-2];
    if (v131 == nil) goto v312;
    v131 = stack[-2];
    v131 = qcar(v131);
    stack[0] = v131;
    v131 = stack[-2];
    v131 = qcdr(v131);
    stack[-2] = v131;
    goto v73;

v73:
    v291 = stack[-4];
    v131 = stack[0];
    v131 = Ldivide(nil, v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v224 = v131;
    v291 = qcdr(v131);
    v131 = (Lisp_Object)1; /* 0 */
    if (v291 == v131) goto v149;
    v291 = stack[-4];
    v131 = (Lisp_Object)17; /* 1 */
    if (v291 == v131) goto v276;
    v291 = stack[0];
    v131 = stack[0];
    v291 = times2(v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = stack[-4];
    v131 = (Lisp_Object)greaterp2(v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-6];
    goto v87;

v87:
    if (v131 == nil) goto v119;
    v131 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v131;
    v291 = stack[-4];
    v131 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v131 = (*qfn2(fn))(qenv(fn), v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[-1] = v131;
    v131 = (Lisp_Object)17; /* 1 */
    stack[-4] = v131;
    goto v119;

v276:
    v131 = qvalue(elt(env, 2)); /* nil */
    goto v87;

v149:
    v131 = v224;
    v131 = qcar(v131);
    stack[-4] = v131;
    v291 = stack[0];
    v131 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v131 = (*qfn2(fn))(qenv(fn), v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[-1] = v131;
    goto v73;

v312:
    v291 = stack[-4];
    v131 = (Lisp_Object)17; /* 1 */
    if (v291 == v131) goto v306;
    v131 = stack[-3];
    if (v131 == nil) goto v128;
    v291 = stack[-4];
    v131 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v131 = (*qfn2(fn))(qenv(fn), v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    goto v11;

v11:
    {
        Lisp_Object v303 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v303, v131);
    }

v128:
    v224 = stack[-4];
    v291 = (Lisp_Object)17; /* 1 */
    v131 = stack[-1];
    v131 = acons(v224, v291, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    goto v11;

v306:
    v131 = stack[-1];
    goto v11;
/* error exit handlers */
v134:
    popv(7);
    return nil;
}



setup_type const u39_setup[] =
{
    {"r2speclist",              CC_r2speclist,  too_many_1,    wrong_no_1},
    {"bassoc",                  too_few_2,      CC_bassoc,     wrong_no_2},
    {"subs2chkex",              CC_subs2chkex,  too_many_1,    wrong_no_1},
    {"prepcadr",                CC_prepcadr,    too_many_1,    wrong_no_1},
    {"mo_from_ei",              CC_mo_from_ei,  too_many_1,    wrong_no_1},
    {"*v2j",                    CC_Hv2j,        too_many_1,    wrong_no_1},
    {"general-difference-mod-p",too_few_2,      CC_generalKdifferenceKmodKp,wrong_no_2},
    {"max-degree",              too_few_2,      CC_maxKdegree, wrong_no_2},
    {"list_assoc",              too_few_2,      CC_list_assoc, wrong_no_2},
    {"girationalize:",          CC_girationalizeT,too_many_1,  wrong_no_1},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"all_defined_map_",        too_few_2,      CC_all_defined_map_,wrong_no_2},
    {"groeb=testb",             too_few_2,      CC_groebMtestb,wrong_no_2},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"freeof-df",               too_few_2,      CC_freeofKdf,  wrong_no_2},
    {"mri_irsplit1",            CC_mri_irsplit1,too_many_1,    wrong_no_1},
    {"pasf_cein",               CC_pasf_cein,   too_many_1,    wrong_no_1},
    {"ctx_union",               too_few_2,      CC_ctx_union,  wrong_no_2},
    {"matrixir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixir},
    {"i2crn*",                  CC_i2crnH,      too_many_1,    wrong_no_1},
    {"solvealgtrig01",          too_few_2,      CC_solvealgtrig01,wrong_no_2},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"diff_vertex",             too_few_2,      CC_diff_vertex,wrong_no_2},
    {"setmatelem",              too_few_2,      CC_setmatelem, wrong_no_2},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"bc_from_a",               CC_bc_from_a,   too_many_1,    wrong_no_1},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"ofsf_bestgaussp",         CC_ofsf_bestgaussp,too_many_1, wrong_no_1},
    {"merge_lists",             too_few_2,      CC_merge_lists,wrong_no_2},
    {"replace-nth",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_replaceKnth},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"aex_red",                 too_few_2,      CC_aex_red,    wrong_no_2},
    {"seprd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_seprd},
    {"mkratnum",                CC_mkratnum,    too_many_1,    wrong_no_1},
    {"tp",                      CC_tp,          too_many_1,    wrong_no_1},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {NULL, (one_args *)"u39", (two_args *)"10544 5870776 5929831", 0}
};

/* end of generated code */
