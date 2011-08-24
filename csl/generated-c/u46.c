
/* $destdir\u46.c        Machine generated C code */

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


/* Code for pa_part2list */

static Lisp_Object CC_pa_part2list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_part2list");
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
    stack[-6] = v0;
/* end of prologue */
    v24 = stack[-6];
    v24 = qcdr(v24);
    fn = elt(env, 2); /* upbve */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[0] = v24;
    v24 = stack[0];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = Lmkvect(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-7] = v24;
    v24 = stack[0];
    stack[-4] = v24;
    goto v26;

v26:
    v24 = stack[-4];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = Lminusp(nil, v24);
    env = stack[-8];
    if (v24 == nil) goto v27;
    v24 = stack[-6];
    v24 = qcar(v24);
    stack[-4] = v24;
    goto v28;

v28:
    v24 = stack[-4];
    if (v24 == nil) goto v29;
    v24 = stack[-4];
    v24 = qcar(v24);
    stack[0] = stack[-7];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-3] = v24;
    v24 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-2] = v24;
    v24 = stack[-4];
    v24 = qcdr(v24);
    stack[-4] = v24;
    v24 = stack[-2];
    if (!consp(v24)) goto v28;
    else goto v30;

v30:
    v24 = stack[-4];
    if (v24 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v24 = stack[-4];
    v24 = qcar(v24);
    stack[0] = stack[-7];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = Lrplacd(nil, stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-2] = v24;
    v24 = stack[-4];
    v24 = qcdr(v24);
    stack[-4] = v24;
    goto v30;

v29:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v24); }

v27:
    v24 = stack[-6];
    stack[0] = qcdr(v24);
    v24 = stack[-4];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    stack[-5] = v24;
    stack[-3] = stack[-7];
    v24 = stack[-5];
    stack[-2] = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v24 = stack[-5];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    v24 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    v24 = cons(stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v24;
    v24 = stack[-4];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-8];
    stack[-4] = v24;
    goto v26;
/* error exit handlers */
v25:
    popv(9);
    return nil;
}



/* Code for get_first_kernel */

static Lisp_Object CC_get_first_kernel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v13, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_first_kernel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v31;
    v13 = v0;
/* end of prologue */
    v36 = v13;
    v13 = v35;
    v35 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* gfk */
        return (*qfnn(fn))(qenv(fn), 3, v36, v13, v35);
    }
}



/* Code for rl_simpatom */

static Lisp_Object CC_rl_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpatom");
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
    v58 = stack[0];
    if (!(v58 == nil)) goto v61;
    v59 = elt(env, 1); /* "nil" */
    v58 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v61;

v61:
    v58 = stack[0];
    if (!(is_number(v58))) goto v63;
    v59 = elt(env, 3); /* "number" */
    v58 = stack[0];
    v59 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v58 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v63;

v63:
    v58 = stack[0];
    v58 = Lstringp(nil, v58);
    env = stack[-1];
    if (v58 == nil) goto v64;
    v59 = elt(env, 4); /* "string" */
    v58 = stack[0];
    v59 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v58 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v64;

v64:
    v58 = stack[0];
    fn = elt(env, 12); /* rl_gettype */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v60 = v58;
    if (v58 == nil) goto v65;
    v59 = v60;
    v58 = elt(env, 5); /* (logical equation scalar slprog) */
    v58 = Lmemq(nil, v59, v58);
    if (v58 == nil) goto v66;
    v59 = stack[0];
    v58 = elt(env, 6); /* avalue */
    v58 = get(v59, v58);
    env = stack[-1];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v66:
    v59 = v60;
    v58 = stack[0];
    v59 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v58 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v65;

v65:
    v59 = stack[0];
    v58 = elt(env, 7); /* true */
    if (v59 == v58) goto v67;
    v59 = stack[0];
    v58 = elt(env, 9); /* false */
    v58 = (v59 == v58 ? lisp_true : nil);
    goto v68;

v68:
    if (!(v58 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v58 = stack[0];
    v58 = Lboundp(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    if (v58 == nil) goto v69;
    v58 = stack[0];
    fn = elt(env, 14); /* eval */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v69:
    v59 = elt(env, 10); /* "unbound id" */
    v58 = stack[0];
    v59 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v58 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v58 = nil;
    { popv(2); return onevalue(v58); }

v67:
    v58 = qvalue(elt(env, 8)); /* t */
    goto v68;
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for deleteq */

static Lisp_Object CC_deleteq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v77, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteq");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v15 = nil;
    goto v61;

v61:
    v16 = stack[-1];
    if (v16 == nil) goto v78;
    v16 = stack[-1];
    v77 = qcar(v16);
    v16 = stack[0];
    if (v77 == v16) goto v79;
    v16 = stack[-1];
    v16 = qcar(v16);
    v77 = v15;
    v16 = cons(v16, v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v15 = v16;
    v16 = stack[-1];
    v16 = qcdr(v16);
    stack[-1] = v16;
    goto v61;

v79:
    v77 = v15;
    v16 = stack[-1];
    v16 = qcdr(v16);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v77, v16);
    }

v78:
    v16 = v15;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for ioto_tprin2 */

static Lisp_Object CC_ioto_tprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v57, v26, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ioto_tprin2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v63 = v36;
    v26 = qvalue(elt(env, 1)); /* t */
    v57 = qvalue(elt(env, 2)); /* nil */
    v36 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* ioto_prin21 */
        return (*qfnn(fn))(qenv(fn), 4, v63, v26, v57, v36);
    }
}



/* Code for qqe_length!-graph!-neighbors */

static Lisp_Object CC_qqe_lengthKgraphKneighbors(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v32 = elt(env, 1); /* neighbors */
    return get(v82, v32);
}



/* Code for iv_cutn */

static Lisp_Object CC_iv_cutn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutn");
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
    v83 = v0;
/* end of prologue */
    v76 = v83;
    v76 = qcdr(v76);
    if (v76 == nil) goto v63;
    v76 = v83;
    stack[0] = qcar(v76);
    v76 = v83;
    v76 = qcdr(v76);
    v76 = CC_iv_cutn(env, v76);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    {
        Lisp_Object v85 = stack[0];
        popv(2);
        fn = elt(env, 1); /* iv_cut */
        return (*qfn2(fn))(qenv(fn), v85, v76);
    }

v63:
    v76 = v83;
    v76 = qcar(v76);
    { popv(2); return onevalue(v76); }
/* error exit handlers */
v84:
    popv(2);
    return nil;
}



/* Code for bc_dcont */

static Lisp_Object CC_bc_dcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_dcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v86 = v0;
/* end of prologue */
    v86 = qcar(v86);
    {
        fn = elt(env, 1); /* sfto_dcontentf */
        return (*qfn1(fn))(qenv(fn), v86);
    }
}



/* Code for subeval */

static Lisp_Object CC_subeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval");
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
    stack[-2] = qvalue(elt(env, 1)); /* sublist!* */
    qvalue(elt(env, 1)) = nil; /* sublist!* */
    v89 = elt(env, 2); /* sub */
    v88 = elt(env, 3); /* psopfn */
    v87 = elt(env, 4); /* subeval0 */
    v87 = Lputprop(nil, 3, v89, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[0] = elt(env, 4); /* subeval0 */
    v87 = stack[-1];
    v87 = Lmkquote(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v87 = list2(stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[0] = v87;
    v89 = elt(env, 2); /* sub */
    v88 = elt(env, 3); /* psopfn */
    v87 = elt(env, 0); /* subeval */
    v87 = Lputprop(nil, 3, v89, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v87 = stack[0];
    if (!consp(v87)) goto v91;
    v87 = stack[0];
    v87 = qcdr(v87);
    goto v71;

v71:
    if (v87 == nil) goto v64;
    v87 = qvalue(elt(env, 6)); /* errmsg!* */
    if (v87 == nil) goto v8;
    v87 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v87 == nil)) goto v19;
    v87 = qvalue(elt(env, 6)); /* errmsg!* */
    fn = elt(env, 9); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    goto v19;

v19:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    goto v64;

v64:
    v87 = stack[0];
    v87 = qcar(v87);
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    { popv(4); return onevalue(v87); }

v8:
    v87 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v87 == nil)) goto v28;
    v87 = elt(env, 2); /* sub */
    fn = elt(env, 9); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    goto v28;

v28:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    goto v64;

v91:
    v87 = qvalue(elt(env, 5)); /* t */
    goto v71;
/* error exit handlers */
v90:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    popv(4);
    return nil;
}



/* Code for nestminusp!: */

static Lisp_Object CC_nestminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v91, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestminusp:");
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
    v14 = v0;
/* end of prologue */
    v71 = v14;
    v71 = integerp(v71);
    if (v71 == nil) goto v26;
    v71 = (Lisp_Object)1; /* 0 */
    v91 = v71;
    goto v81;

v81:
    v71 = (Lisp_Object)1; /* 0 */
    if (v91 == v71) goto v21;
    v71 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v71); }

v21:
    v71 = v14;
    v71 = integerp(v71);
    if (v71 == nil) goto v92;
    v71 = v14;
    fn = elt(env, 2); /* simp */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[0];
    goto v84;

v84:
    v71 = qcar(v71);
    {
        popv(1);
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v71);
    }

v92:
    v71 = v14;
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    goto v84;

v26:
    v71 = v14;
    v71 = qcdr(v71);
    v71 = qcar(v71);
    v91 = v71;
    goto v81;
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for groebmakepair */

static Lisp_Object CC_groebmakepair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebmakepair");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v96 = stack[-3];
    v96 = qcdr(v96);
    v97 = qcar(v96);
    v96 = stack[-2];
    v96 = qcdr(v96);
    v96 = qcar(v96);
    fn = elt(env, 2); /* vevlcm */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-4] = v96;
    v96 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v96 == nil) goto v90;
    v96 = stack[-3];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v97 = stack[-4];
    v96 = stack[-3];
    v96 = qcdr(v96);
    v96 = qcar(v96);
    fn = elt(env, 4); /* vevdif */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v96 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v96 - TAG_FIXNUM);
    stack[-1] = v96;
    v96 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v97 = stack[-4];
    v96 = stack[-2];
    v96 = qcdr(v96);
    v96 = qcar(v96);
    fn = elt(env, 4); /* vevdif */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v96 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v96 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v97 = stack[-1];
    fn = elt(env, 6); /* max */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    {
        Lisp_Object v100 = stack[0];
        Lisp_Object v41 = stack[-3];
        Lisp_Object v68 = stack[-2];
        popv(6);
        return list4(v100, v41, v68, v96);
    }

v90:
    v98 = stack[-4];
    v97 = stack[-3];
    v96 = stack[-2];
    popv(6);
    return list3(v98, v97, v96);
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for idealp */

static Lisp_Object CC_idealp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v84, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idealp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v85 = v0;
/* end of prologue */
    v84 = v85;
    v79 = elt(env, 1); /* i */
    if (!consp(v84)) goto v26;
    v84 = qcar(v84);
    if (!(v84 == v79)) goto v26;
    v79 = qvalue(elt(env, 2)); /* t */
    return onevalue(v79);

v26:
    v79 = v85;
    v84 = elt(env, 3); /* list */
        return Leqcar(nil, v79, v84);
}



/* Code for mkuniquewedge */

static Lisp_Object CC_mkuniquewedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuniquewedge");
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
    goto v61;

v61:
    v17 = stack[0];
    if (v17 == nil) goto v103;
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = qcar(v17);
    fn = elt(env, 2); /* mkuniquewedge1 */
    v102 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = qcdr(v17);
    fn = elt(env, 3); /* multpfsq */
    v102 = (*qfn2(fn))(qenv(fn), v102, v17);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v17 = stack[-1];
    v17 = cons(v102, v17);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    stack[-1] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v61;

v103:
    v17 = qvalue(elt(env, 1)); /* nil */
    v102 = v17;
    goto v81;

v81:
    v17 = stack[-1];
    if (v17 == nil) { popv(3); return onevalue(v102); }
    v17 = stack[-1];
    v17 = qcar(v17);
    fn = elt(env, 4); /* addpf */
    v17 = (*qfn2(fn))(qenv(fn), v17, v102);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v102 = v17;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v81;
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for contain_edge */

static Lisp_Object CC_contain_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v22, v23, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contain_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v31;
    v23 = v0;
/* end of prologue */

v104:
    v92 = v22;
    if (v92 == nil) goto v86;
    v92 = v23;
    v56 = qcar(v92);
    v92 = v22;
    v92 = qcar(v92);
    v92 = Lassoc(nil, v56, v92);
    if (!(v92 == nil)) return onevalue(v92);
    v92 = v22;
    v92 = qcdr(v92);
    v22 = v92;
    goto v104;

v86:
    v92 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v92);
}



/* Code for dfppri */

static Lisp_Object CC_dfppri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfppri");
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
    v108 = qvalue(elt(env, 1)); /* !*nat */
    if (v108 == nil) goto v33;
    v108 = qvalue(elt(env, 3)); /* !*fort */
    goto v32;

v32:
    if (v108 == nil) goto v103;
    v108 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v108); }

v103:
    v108 = stack[-1];
    v108 = qcdr(v108);
    v108 = qcar(v108);
    stack[-2] = v108;
    v108 = stack[-1];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v108 = qcar(v108);
    stack[0] = v108;
    v108 = stack[-2];
    if (!consp(v108)) goto v92;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 5); /* generic_function */
    v108 = get(v109, v108);
    env = stack[-3];
    v108 = (v108 == nil ? lisp_true : nil);
    goto v74;

v74:
    if (v108 == nil) goto v27;
    v108 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v108); }

v27:
    v108 = stack[-2];
    v108 = qcar(v108);
    fn = elt(env, 12); /* prin2!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v108 = qvalue(elt(env, 6)); /* ycoord!* */
    v108 = sub1(v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    qvalue(elt(env, 6)) = v108; /* ycoord!* */
    v109 = qvalue(elt(env, 6)); /* ycoord!* */
    v108 = qvalue(elt(env, 7)); /* ymin!* */
    v108 = (Lisp_Object)lessp2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    v108 = v108 ? lisp_true : nil;
    env = stack[-3];
    if (v108 == nil) goto v52;
    v108 = qvalue(elt(env, 6)); /* ycoord!* */
    qvalue(elt(env, 7)) = v108; /* ymin!* */
    goto v52;

v52:
    v108 = stack[0];
    v108 = qcdr(v108);
    stack[0] = v108;
    goto v111;

v111:
    v108 = stack[0];
    if (v108 == nil) goto v112;
    v108 = stack[0];
    v108 = qcar(v108);
    fn = elt(env, 12); /* prin2!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v108 = stack[0];
    v108 = qcdr(v108);
    stack[0] = v108;
    goto v111;

v112:
    v108 = qvalue(elt(env, 6)); /* ycoord!* */
    v108 = add1(v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    qvalue(elt(env, 6)) = v108; /* ycoord!* */
    v108 = stack[-2];
    v108 = qcdr(v108);
    if (v108 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v108 = elt(env, 9); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v110 = elt(env, 10); /* !*comma!* */
    v109 = (Lisp_Object)1; /* 0 */
    v108 = stack[-2];
    v108 = qcdr(v108);
    fn = elt(env, 13); /* inprint */
    v108 = (*qfnn(fn))(qenv(fn), 3, v110, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v108 = elt(env, 11); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v6;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v92:
    v108 = qvalue(elt(env, 2)); /* t */
    goto v74;

v33:
    v108 = qvalue(elt(env, 2)); /* t */
    goto v32;
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for !*sq2fourier */

static Lisp_Object CC_Hsq2fourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v28, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sq2fourier");
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
    stack[0] = v0;
/* end of prologue */
    v111 = stack[0];
    v111 = qcar(v111);
    if (v111 == nil) goto v21;
    v111 = (Lisp_Object)49; /* 3 */
    v111 = Lmkvect(nil, v111);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[-2] = v111;
    v30 = stack[-2];
    v28 = (Lisp_Object)1; /* 0 */
    v111 = stack[0];
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v28/(16/CELL))) = v111;
    v30 = stack[-2];
    v28 = (Lisp_Object)17; /* 1 */
    v111 = elt(env, 2); /* cos */
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v28/(16/CELL))) = v111;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* fs!:make!-nullangle */
    v111 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v111;
    v30 = stack[-2];
    v28 = (Lisp_Object)49; /* 3 */
    v111 = qvalue(elt(env, 1)); /* nil */
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v28/(16/CELL))) = v111;
    v28 = elt(env, 3); /* fourier */
    v111 = elt(env, 4); /* tag */
    v28 = get(v28, v111);
    v111 = stack[-2];
    popv(4);
    return cons(v28, v111);

v21:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v111); }
/* error exit handlers */
v115:
    popv(4);
    return nil;
}



/* Code for square!-free!-mod!-p */

static Lisp_Object CC_squareKfreeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for square-free-mod-p");
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
    v70 = v0;
/* end of prologue */
    v116 = v70;
    if (!consp(v116)) goto v81;
    v116 = v70;
    v116 = qcar(v116);
    v116 = (consp(v116) ? nil : lisp_true);
    goto v103;

v103:
    if (v116 == nil) goto v117;
    v116 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v116); }

v117:
    stack[0] = v70;
    v116 = v70;
    fn = elt(env, 2); /* derivative!-mod!-p */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    fn = elt(env, 3); /* gcd!-mod!-p */
    v116 = (*qfn2(fn))(qenv(fn), stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    v70 = v116;
    v116 = v70;
    if (!consp(v116)) goto v74;
    v116 = v70;
    v116 = qcar(v116);
    v116 = (consp(v116) ? nil : lisp_true);
    { popv(2); return onevalue(v116); }

v74:
    v116 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v116); }

v81:
    v116 = qvalue(elt(env, 1)); /* t */
    goto v103;
/* error exit handlers */
v91:
    popv(2);
    return nil;
}



/* Code for legendre!-symbol */

static Lisp_Object CC_legendreKsymbol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for legendre-symbol");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v63 = v31;
    v101 = v0;
/* end of prologue */
    stack[0] = v101;
    v101 = sub1(v63);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v63 = (Lisp_Object)33; /* 2 */
    v63 = quot2(v101, v63);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    {
        Lisp_Object v76 = stack[0];
        popv(2);
        fn = elt(env, 1); /* general!-modular!-expt */
        return (*qfn2(fn))(qenv(fn), v76, v63);
    }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for flatten */

static Lisp_Object CC_flatten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatten");
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
    v113 = nil;
    goto v86;

v86:
    v20 = stack[-1];
    if (v20 == nil) goto v81;
    v20 = stack[-1];
    if (!consp(v20)) goto v57;
    v20 = stack[-1];
    v20 = qcar(v20);
    if (!consp(v20)) goto v73;
    stack[-2] = v113;
    v20 = stack[-1];
    v20 = qcar(v20);
    stack[0] = CC_flatten(env, v20);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v20 = stack[-1];
    v20 = qcdr(v20);
    v20 = CC_flatten(env, v20);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v20 = Lnconc(nil, stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    {
        Lisp_Object v8 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v8, v20);
    }

v73:
    v20 = stack[-1];
    v20 = qcar(v20);
    v20 = cons(v20, v113);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v113 = v20;
    v20 = stack[-1];
    v20 = qcdr(v20);
    stack[-1] = v20;
    goto v86;

v57:
    stack[0] = v113;
    v20 = stack[-1];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    {
        Lisp_Object v9 = stack[0];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v9, v20);
    }

v81:
    v20 = v113;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for getsetvarlis */

static Lisp_Object CC_getsetvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvarlis");
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
    goto v86;

v86:
    v65 = stack[0];
    if (v65 == nil) goto v81;
    v65 = stack[0];
    if (!consp(v65)) goto v79;
    v65 = stack[0];
    v65 = qcar(v65);
    if (!consp(v65)) goto v55;
    v65 = stack[0];
    v65 = qcar(v65);
    v119 = qcar(v65);
    v65 = elt(env, 2); /* (setel setk) */
    v65 = Lmemq(nil, v119, v65);
    if (v65 == nil) goto v49;
    v65 = stack[0];
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v119 = CC_getsetvarlis(env, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v65 = stack[-1];
    v65 = cons(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v65;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v86;

v49:
    v65 = stack[0];
    v65 = qcar(v65);
    v119 = qcar(v65);
    v65 = elt(env, 3); /* setq */
    if (v119 == v65) goto v47;
    v65 = stack[0];
    v119 = qcar(v65);
    v65 = stack[-1];
    v65 = cons(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v65;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v86;

v47:
    v65 = stack[0];
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v119 = Lmkquote(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v65 = stack[-1];
    v65 = cons(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v65;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v86;

v55:
    v65 = stack[0];
    v119 = qcar(v65);
    v65 = stack[-1];
    v65 = cons(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v65;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v86;

v79:
    v119 = elt(env, 1); /* "getsetvarlis" */
    v65 = stack[0];
    v65 = list2(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    fn = elt(env, 4); /* errach */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    {
        Lisp_Object v1 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v1, v65);
    }

v81:
    v65 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v65);
    }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for simpx1 */

static Lisp_Object MS_CDECL CC_simpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v265, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpx1");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v7;
    stack[-1] = v31;
    stack[-4] = v0;
/* end of prologue */
    stack[-6] = nil;
    v265 = stack[-4];
    v264 = elt(env, 1); /* !*minus!* */
    if (!consp(v265)) goto v33;
    v265 = qcar(v265);
    if (!(v265 == v264)) goto v33;
    v265 = stack[-1];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v73;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v54;

v54:
    if (!(v264 == nil)) goto v267;
    v265 = stack[-3];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v89;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v9:
    if (!(v264 == nil)) goto v267;
    v265 = stack[-1];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v268;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v269;

v269:
    if (v264 == nil) goto v33;
    v264 = stack[-4];
    v264 = qcdr(v264);
    stack[0] = qcar(v264);
    v266 = elt(env, 3); /* quotient */
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = list2(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 20); /* simpexpt */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[0] = v264;
    v264 = stack[0];
    v264 = qcar(v264);
    fn = elt(env, 21); /* negf */
    v265 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v264 = stack[0];
    v264 = qcdr(v264);
    popv(8);
    return cons(v265, v264);

v33:
    v264 = stack[-1];
    if (!(is_number(v264))) goto v271;
    v264 = stack[-3];
    if (!(is_number(v264))) goto v271;

v78:
    v264 = stack[-1];
    if (is_number(v264)) goto v272;
    v264 = stack[-1];
    if (!consp(v264)) goto v273;
    v264 = stack[-1];
    v265 = qcar(v264);
    v264 = elt(env, 12); /* minus */
    if (v265 == v264) goto v274;
    v264 = stack[-1];
    v265 = qcar(v264);
    v264 = elt(env, 13); /* plus */
    if (v265 == v264) goto v275;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v276;

v276:
    if (v264 == nil) goto v277;
    v265 = (Lisp_Object)17; /* 1 */
    v264 = (Lisp_Object)17; /* 1 */
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    v264 = stack[-1];
    v264 = qcdr(v264);
    stack[-2] = v264;
    goto v278;

v278:
    v264 = stack[-2];
    if (v264 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v264 = stack[-2];
    v264 = qcar(v264);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 3); /* quotient */
    v265 = stack[-6];
    if (v265 == nil) goto v279;
    v265 = elt(env, 12); /* minus */
    v264 = list2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v265 = v264;
    goto v280;

v280:
    v264 = stack[-3];
    v264 = list3(stack[0], v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = list2(stack[-1], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 20); /* simpexpt */
    v265 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = stack[-5];
    fn = elt(env, 22); /* multsq */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-2] = v264;
    goto v278;

v279:
    v265 = v264;
    goto v280;

v277:
    v264 = stack[-1];
    v265 = qcar(v264);
    v264 = elt(env, 15); /* times */
    if (v265 == v264) goto v281;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v282;

v282:
    if (v264 == nil) goto v283;
    v264 = stack[-3];
    if (is_number(v264)) goto v284;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-5] = v264;
    goto v285;

v285:
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    if (v264 == nil) goto v286;
    v265 = elt(env, 15); /* times */
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    goto v287;

v287:
    stack[-1] = v264;
    goto v288;

v288:
    v264 = stack[-4];
    if (!(symbolp(v264))) goto v289;
    v265 = stack[-4];
    v264 = elt(env, 16); /* used!* */
    v264 = Lflagp(nil, v265, v264);
    env = stack[-7];
    if (!(v264 == nil)) goto v289;
    v264 = stack[-4];
    v265 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = elt(env, 16); /* used!* */
    v264 = Lflag(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    goto v289;

v289:
    v265 = stack[-4];
    v264 = elt(env, 17); /* (minus 1) */
    if (equal(v265, v264)) goto v290;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v291;

v291:
    if (v264 == nil) goto v292;
    v264 = elt(env, 5); /* i */
    fn = elt(env, 23); /* simp */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-4] = v264;
    v264 = stack[-6];
    if (v264 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v264 = stack[-4];
    v264 = qcar(v264);
    fn = elt(env, 21); /* negf */
    v265 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v264 = stack[-4];
    v264 = qcdr(v264);
    popv(8);
    return cons(v265, v264);

v292:
    stack[0] = elt(env, 4); /* expt */
    stack[-2] = stack[-4];
    v265 = stack[-3];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v293;
    v266 = elt(env, 3); /* quotient */
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    goto v294;

v294:
    v264 = list3(stack[0], stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-4] = v264;
    stack[0] = stack[-4];
    v264 = stack[-6];
    if (v264 == nil) goto v295;
    v264 = stack[-5];
    v264 = negate(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    goto v296;

v296:
    {
        Lisp_Object v297 = stack[0];
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v297, v264);
    }

v295:
    v264 = stack[-5];
    goto v296;

v293:
    v264 = stack[-1];
    goto v294;

v290:
    v265 = stack[-3];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v298;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v291;

v298:
    v266 = elt(env, 18); /* difference */
    v265 = stack[-1];
    v264 = elt(env, 19); /* (quotient 1 2) */
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 23); /* simp */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = qcar(v264);
    v264 = (v264 == nil ? lisp_true : nil);
    goto v291;

v286:
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    goto v287;

v284:
    v265 = stack[-3];
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lgcd(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    v265 = stack[-3];
    v264 = stack[-5];
    v264 = quot2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-3] = v264;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = stack[-5];
    v264 = quot2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    goto v285;

v283:
    v264 = stack[-1];
    v265 = qcar(v264);
    v264 = elt(env, 3); /* quotient */
    if (v265 == v264) goto v299;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v300:
    if (v264 == nil) goto v301;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-3] = v264;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-1] = v264;
    goto v78;

v301:
    v264 = (Lisp_Object)17; /* 1 */
    stack[-5] = v264;
    goto v288;

v299:
    v265 = stack[-3];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v302;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v302:
    v264 = qvalue(elt(env, 14)); /* !*expandexpt */
    goto v300;

v281:
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = integerp(v264);
    goto v282;

v275:
    v264 = qvalue(elt(env, 14)); /* !*expandexpt */
    goto v276;

v274:
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-1] = v264;
    goto v82;

v82:
    v264 = qvalue(elt(env, 7)); /* !*mcd */
    if (v264 == nil) goto v303;
    v266 = stack[-4];
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = CC_simpx1(env, 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 25); /* invsq */
        return (*qfn1(fn))(qenv(fn), v264);
    }

v303:
    v264 = stack[-6];
    v264 = (v264 == nil ? lisp_true : nil);
    stack[-6] = v264;
    goto v78;

v273:
    v264 = (Lisp_Object)17; /* 1 */
    stack[-5] = v264;
    goto v288;

v272:
    v264 = stack[-1];
    v264 = Lminusp(nil, v264);
    env = stack[-7];
    if (v264 == nil) goto v304;
    v264 = stack[-1];
    v264 = negate(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-1] = v264;
    goto v82;

v304:
    v264 = stack[-1];
    v264 = integerp(v264);
    if (v264 == nil) goto v305;
    v264 = stack[-3];
    v264 = integerp(v264);
    if (v264 == nil) goto v306;
    v264 = stack[-6];
    if (v264 == nil) goto v307;
    v264 = stack[-1];
    v264 = negate(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-1] = v264;
    goto v307;

v307:
    v264 = stack[-1];
    stack[-5] = v264;
    v264 = qvalue(elt(env, 7)); /* !*mcd */
    if (v264 == nil) goto v308;
    v264 = stack[-4];
    v264 = integerp(v264);
    if (!(v264 == nil)) goto v309;
    v264 = qvalue(elt(env, 8)); /* !*notseparate */
    if (!(v264 == nil)) goto v308;

v309:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = quot2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-1] = v264;
    v264 = times2(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = difference2(stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    v265 = stack[-5];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (Lisp_Object)lessp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (v264 == nil) goto v310;
    v264 = stack[-1];
    v264 = sub1(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-1] = v264;
    v265 = stack[-5];
    v264 = stack[-3];
    v264 = plus2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    goto v310;

v310:
    v265 = stack[-4];
    v264 = stack[-1];
    v264 = list2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 20); /* simpexpt */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[0] = v264;
    v265 = stack[-5];
    v264 = (Lisp_Object)1; /* 0 */
    if (v265 == v264) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v265 = stack[-3];
    v264 = (Lisp_Object)33; /* 2 */
    if (v265 == v264) goto v311;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v312;

v312:
    if (v264 == nil) goto v313;
    stack[-1] = stack[0];
    v265 = elt(env, 10); /* sqrt */
    v264 = elt(env, 11); /* simpfn */
    stack[0] = get(v265, v264);
    env = stack[-7];
    v264 = stack[-4];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = Lapply1(nil, stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v264 = (*qfn2(fn))(qenv(fn), stack[-1], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[0] = v264;
    v265 = stack[-5];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (Lisp_Object)lessp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (v264 == nil) goto v314;
    v264 = stack[0];
    fn = elt(env, 25); /* invsq */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[0] = v264;
    v264 = stack[-5];
    v264 = negate(v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    stack[-5] = v264;
    goto v314;

v314:
    v265 = stack[0];
    v264 = stack[-5];
    {
        popv(8);
        fn = elt(env, 26); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v265, v264);
    }

v313:
    v264 = stack[-4];
    fn = elt(env, 27); /* simp!* */
    v265 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = stack[-3];
    fn = elt(env, 28); /* simprad */
    v265 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = stack[-5];
    fn = elt(env, 26); /* exptsq */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    {
        Lisp_Object v315 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v315, v264);
    }

v311:
    v264 = qvalue(elt(env, 9)); /* !*keepsqrts */
    goto v312;

v308:
    v264 = (Lisp_Object)1; /* 0 */
    stack[-1] = v264;
    goto v310;

v306:
    v264 = stack[-1];
    stack[-5] = v264;
    v264 = (Lisp_Object)17; /* 1 */
    stack[-1] = v264;
    goto v288;

v305:
    v264 = (Lisp_Object)17; /* 1 */
    stack[-5] = v264;
    goto v288;

v271:
    v265 = qvalue(elt(env, 6)); /* frlis!* */
    v264 = stack[-1];
    fn = elt(env, 29); /* smemqlp */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    if (!(v264 == nil)) goto v316;
    v265 = qvalue(elt(env, 6)); /* frlis!* */
    v264 = stack[-3];
    fn = elt(env, 29); /* smemqlp */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    if (v264 == nil) goto v78;
    else goto v316;

v316:
    stack[0] = elt(env, 4); /* expt */
    stack[-2] = stack[-4];
    v265 = stack[-3];
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v317;
    v266 = elt(env, 3); /* quotient */
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    goto v318;

v318:
    v265 = list3(stack[0], stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v265, v264);
    }

v317:
    v264 = stack[-1];
    goto v318;

v268:
    v264 = stack[-3];
    v264 = integerp(v264);
    goto v269;

v267:
    stack[-6] = elt(env, 4); /* expt */
    stack[-5] = elt(env, 5); /* i */
    stack[-2] = elt(env, 3); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v265 = stack[-3];
    v264 = (Lisp_Object)33; /* 2 */
    v264 = quot2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = list3(stack[-2], stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = list3(stack[-6], stack[-5], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 23); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = stack[-4];
    v264 = qcdr(v264);
    stack[-2] = qcar(v264);
    v266 = elt(env, 3); /* quotient */
    v265 = stack[-1];
    v264 = stack[-3];
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = list2(stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    fn = elt(env, 20); /* simpexpt */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    {
        Lisp_Object v319 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v319, v264);
    }

v89:
    v265 = stack[-1];
    v264 = elt(env, 3); /* quotient */
    if (!consp(v265)) goto v320;
    v265 = qcar(v265);
    if (!(v265 == v264)) goto v320;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = (Lisp_Object)17; /* 1 */
    if (v265 == v264) goto v11;
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v11:
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = integerp(v264);
    if (v264 == nil) goto v99;
    v264 = stack[-1];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = (Lisp_Object)33; /* 2 */
    v265 = Cremainder(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (v265 == v264 ? lisp_true : nil);
    goto v9;

v99:
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v320:
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v73:
    v264 = stack[-3];
    v264 = integerp(v264);
    if (v264 == nil) goto v116;
    v265 = stack[-3];
    v264 = (Lisp_Object)33; /* 2 */
    v265 = Cremainder(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-7];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (v265 == v264 ? lisp_true : nil);
    goto v54;

v116:
    v264 = qvalue(elt(env, 2)); /* nil */
    goto v54;
/* error exit handlers */
v270:
    popv(8);
    return nil;
}



/* Code for make!-var!-coefflist */

static Lisp_Object MS_CDECL CC_makeKvarKcoefflist(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v7, Lisp_Object v72,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v22, v23, v56, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "make-var-coefflist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-var-coefflist");
#endif
    if (stack >= stacklimit)
    {
        push5(v21,v72,v7,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v31,v7,v72,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v21;
    v22 = v72;
    v23 = v7;
    v56 = v31;
    v55 = v0;
/* end of prologue */
    fn = elt(env, 1); /* make!-var!-powerlist */
    v23 = (*qfnn(fn))(qenv(fn), 5, v55, v56, v23, v22, v92);
    errexit();
    v22 = (Lisp_Object)17; /* 1 */
    v92 = (Lisp_Object)17; /* 1 */
    return list2star(v23, v22, v92);
}



/* Code for get_nr_irred_reps */

static Lisp_Object CC_get_nr_irred_reps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_nr_irred_reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v13 = qvalue(elt(env, 1)); /* !*complex */
    if (v13 == nil) goto v32;
    v13 = v36;
    {
        fn = elt(env, 2); /* get!*nr!*complex!*irred!*reps */
        return (*qfn1(fn))(qenv(fn), v13);
    }

v32:
    v13 = v36;
    {
        fn = elt(env, 3); /* get!*nr!*real!*irred!*reps */
        return (*qfn1(fn))(qenv(fn), v13);
    }
}



/* Code for iscale */

static Lisp_Object CC_iscale(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76, v83;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iscale");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v76 = v31;
    v83 = v0;
/* end of prologue */
    v75 = v76;
    v75 = qcdr(v75);
    stack[0] = qcar(v75);
    v75 = v83;
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v75 = plus2(v75, v76);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v85 = stack[0];
        popv(1);
        return Lash1(nil, v85, v75);
    }
/* error exit handlers */
v84:
    popv(1);
    return nil;
}



/* Code for rand!-comb */

static Lisp_Object CC_randKcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v330, v331, v332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-comb");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v31;
    stack[-1] = v0;
/* end of prologue */
    v331 = stack[-3];
    v330 = stack[-1];
    if (equal(v331, v330)) goto v86;
    stack[-2] = nil;
    v331 = stack[-1];
    v330 = stack[-3];
    v331 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[-3];
    v330 = (Lisp_Object)lessp2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    v330 = v330 ? lisp_true : nil;
    env = stack[-5];
    if (v330 == nil) goto v267;
    stack[0] = stack[-1];
    v331 = stack[-1];
    v330 = stack[-3];
    v330 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = CC_randKcomb(env, stack[0], v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[-3] = v330;
    v330 = (Lisp_Object)1; /* 0 */
    stack[0] = v330;
    goto v6;

v6:
    v330 = stack[-1];
    v331 = sub1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[0];
    v330 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = Lminusp(nil, v330);
    env = stack[-5];
    if (!(v330 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v331 = stack[0];
    v330 = stack[-3];
    v330 = Lmember(nil, v331, v330);
    if (!(v330 == nil)) goto v258;
    v331 = stack[0];
    v330 = stack[-2];
    v330 = cons(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[-2] = v330;
    goto v258;

v258:
    v330 = stack[0];
    v330 = add1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[0] = v330;
    goto v6;

v267:
    v330 = (Lisp_Object)1; /* 0 */
    stack[0] = v330;
    goto v334;

v334:
    v330 = stack[-3];
    v331 = sub1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[0];
    v330 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = Lminusp(nil, v330);
    env = stack[-5];
    if (!(v330 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v335:
    v330 = stack[-1];
    fn = elt(env, 2); /* random */
    v331 = (*qfn1(fn))(qenv(fn), v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v332 = v331;
    v330 = stack[-2];
    v330 = Lmember(nil, v331, v330);
    if (!(v330 == nil)) goto v335;
    v331 = v332;
    v330 = stack[-2];
    v330 = cons(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[-2] = v330;
    v330 = stack[0];
    v330 = add1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[0] = v330;
    goto v334;

v86:
    v330 = (Lisp_Object)1; /* 0 */
    stack[-4] = v330;
    v330 = stack[-3];
    v331 = sub1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[-4];
    v330 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = Lminusp(nil, v330);
    env = stack[-5];
    if (v330 == nil) goto v75;
    v330 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v330); }

v75:
    v330 = stack[-4];
    v330 = ncons(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[-1] = v330;
    stack[-2] = v330;
    goto v63;

v63:
    v330 = stack[-4];
    v330 = add1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    stack[-4] = v330;
    v330 = stack[-3];
    v331 = sub1(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[-4];
    v330 = difference2(v331, v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = Lminusp(nil, v330);
    env = stack[-5];
    if (!(v330 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v330 = stack[-4];
    v330 = ncons(v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = Lrplacd(nil, stack[0], v330);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-5];
    v330 = stack[-1];
    v330 = qcdr(v330);
    stack[-1] = v330;
    goto v63;
/* error exit handlers */
v333:
    popv(6);
    return nil;
}



/* Code for lispcondp */

static Lisp_Object CC_lispcondp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispcondp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v32 = elt(env, 1); /* cond */
        return Leqcar(nil, v82, v32);
}



/* Code for asymmetrize!-inds */

static Lisp_Object CC_asymmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v307, v358;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for asymmetrize-inds");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v31;
    stack[-9] = v0;
/* end of prologue */
    v307 = (Lisp_Object)1; /* 0 */
    stack[-10] = v307;
    v307 = stack[-9];
    stack[-7] = v307;
    v307 = stack[-7];
    if (v307 == nil) goto v117;
    v307 = stack[-7];
    v307 = qcar(v307);
    v358 = v307;
    if (!consp(v358)) goto v23;
    stack[-3] = v307;
    v307 = stack[-3];
    if (v307 == nil) goto v17;
    v307 = stack[-3];
    v307 = qcar(v307);
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-1] = v307;
    stack[-2] = v307;
    goto v50;

v50:
    v307 = stack[-3];
    v307 = qcdr(v307);
    stack[-3] = v307;
    v307 = stack[-3];
    if (v307 == nil) goto v49;
    stack[0] = stack[-1];
    v307 = stack[-3];
    v307 = qcar(v307);
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = Lrplacd(nil, stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = stack[-1];
    v307 = qcdr(v307);
    stack[-1] = v307;
    goto v50;

v49:
    v307 = stack[-2];
    goto v73;

v73:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-5] = v307;
    stack[-6] = v307;
    goto v57;

v57:
    v307 = stack[-7];
    v307 = qcdr(v307);
    stack[-7] = v307;
    v307 = stack[-7];
    if (v307 == nil) goto v99;
    stack[-4] = stack[-5];
    v307 = stack[-7];
    v307 = qcar(v307);
    v358 = v307;
    if (!consp(v358)) goto v4;
    stack[-3] = v307;
    v307 = stack[-3];
    if (v307 == nil) goto v37;
    v307 = stack[-3];
    v307 = qcar(v307);
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-1] = v307;
    stack[-2] = v307;
    goto v360;

v360:
    v307 = stack[-3];
    v307 = qcdr(v307);
    stack[-3] = v307;
    v307 = stack[-3];
    if (v307 == nil) goto v361;
    stack[0] = stack[-1];
    v307 = stack[-3];
    v307 = qcar(v307);
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = Lrplacd(nil, stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = stack[-1];
    v307 = qcdr(v307);
    stack[-1] = v307;
    goto v360;

v361:
    v307 = stack[-2];
    goto v362;

v362:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = Lrplacd(nil, stack[-4], v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = stack[-5];
    v307 = qcdr(v307);
    stack[-5] = v307;
    goto v57;

v37:
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v362;

v4:
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    goto v362;

v99:
    v307 = stack[-6];
    goto v36;

v36:
    stack[0] = v307;
    v307 = stack[0];
    fn = elt(env, 3); /* repeats */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    if (v307 == nil) goto v332;
    v307 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v307); }

v332:
    v307 = stack[0];
    v307 = qcar(v307);
    if (!consp(v307)) goto v363;
    v307 = stack[0];
    fn = elt(env, 4); /* indordln */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v358 = v307;
    goto v333;

v333:
    stack[-5] = v358;
    v307 = stack[0];
    fn = elt(env, 5); /* permp */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    if (v307 == nil) goto v234;
    v307 = (Lisp_Object)17; /* 1 */
    goto v268;

v268:
    stack[0] = v307;
    v307 = stack[-9];
    v307 = qcar(v307);
    if (!consp(v307)) goto v364;
    v307 = stack[-9];
    fn = elt(env, 6); /* flatindl */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-9] = v307;
    v307 = stack[-5];
    fn = elt(env, 6); /* flatindl */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-5] = v307;
    goto v364;

v364:
    v358 = stack[-9];
    v307 = stack[-5];
    fn = elt(env, 7); /* pair */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-5] = v307;
    stack[-6] = stack[0];
    v307 = stack[-8];
    stack[-7] = v307;
    v307 = stack[-7];
    if (v307 == nil) goto v365;
    v307 = stack[-7];
    v307 = qcar(v307);
    stack[-1] = v307;
    v307 = stack[-5];
    if (v307 == nil) goto v220;
    v307 = stack[-5];
    v307 = qcar(v307);
    stack[0] = qcar(v307);
    v307 = stack[-10];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-10] = v307;
    if (!(equal(stack[0], v307))) goto v220;
    v307 = stack[-5];
    v307 = qcar(v307);
    v307 = qcdr(v307);
    v358 = v307;
    v307 = stack[-5];
    v307 = qcdr(v307);
    stack[-5] = v307;
    v307 = v358;
    goto v366;

v366:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-3] = v307;
    stack[-4] = v307;
    goto v367;

v367:
    v307 = stack[-7];
    v307 = qcdr(v307);
    stack[-7] = v307;
    v307 = stack[-7];
    if (v307 == nil) goto v368;
    stack[-2] = stack[-3];
    v307 = stack[-7];
    v307 = qcar(v307);
    stack[-1] = v307;
    v307 = stack[-5];
    if (v307 == nil) goto v369;
    v307 = stack[-5];
    v307 = qcar(v307);
    stack[0] = qcar(v307);
    v307 = stack[-10];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    stack[-10] = v307;
    if (!(equal(stack[0], v307))) goto v369;
    v307 = stack[-5];
    v307 = qcar(v307);
    v307 = qcdr(v307);
    v358 = v307;
    v307 = stack[-5];
    v307 = qcdr(v307);
    stack[-5] = v307;
    v307 = v358;
    goto v222;

v222:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = Lrplacd(nil, stack[-2], v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = stack[-3];
    v307 = qcdr(v307);
    stack[-3] = v307;
    goto v367;

v369:
    v307 = stack[-1];
    goto v222;

v368:
    v307 = stack[-4];
    goto v370;

v370:
    {
        Lisp_Object v371 = stack[-6];
        popv(12);
        return cons(v371, v307);
    }

v220:
    v307 = stack[-1];
    goto v366;

v365:
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v370;

v234:
    v307 = (Lisp_Object)-15; /* -1 */
    goto v268;

v363:
    v307 = stack[0];
    fn = elt(env, 8); /* indordn */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v358 = v307;
    goto v333;

v17:
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v73;

v23:
    v358 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v307 = (*qfn2(fn))(qenv(fn), v358, v307);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-11];
    v307 = qcar(v307);
    goto v73;

v117:
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v36;
/* error exit handlers */
v359:
    popv(12);
    return nil;
}



/* Code for requote1 */

static Lisp_Object CC_requote1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for requote1");
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
    goto v61;

v61:
    v45 = stack[-1];
    if (v45 == nil) goto v78;
    v45 = stack[-1];
    v45 = qcar(v45);
    if (is_number(v45)) goto v73;
    v45 = stack[-1];
    v46 = qcar(v45);
    v45 = elt(env, 1); /* (nil t) */
    v45 = Lmemq(nil, v46, v45);
    if (!(v45 == nil)) goto v73;
    v45 = stack[-1];
    v45 = qcar(v45);
    if (!consp(v45)) goto v263;
    v45 = stack[-1];
    v45 = qcar(v45);
    v46 = qcar(v45);
    v45 = elt(env, 3); /* quote */
    if (v46 == v45) goto v102;
    v45 = stack[-1];
    v45 = qcar(v45);
    v46 = qcar(v45);
    v45 = elt(env, 4); /* list */
    if (v46 == v45) goto v3;
    v45 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v9:
    if (v45 == nil) goto v66;
    v46 = stack[0];
    v45 = stack[-2];
    v45 = cons(v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v45;
    goto v81;

v81:
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v61;

v66:
    v45 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v45); }

v3:
    v45 = stack[-1];
    v45 = qcar(v45);
    v45 = qcdr(v45);
    v45 = CC_requote1(env, v45);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[0] = v45;
    goto v9;

v102:
    v45 = stack[-1];
    v45 = qcar(v45);
    v45 = qcdr(v45);
    v46 = qcar(v45);
    v45 = stack[-2];
    v45 = cons(v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v45;
    goto v81;

v263:
    v45 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v45); }

v73:
    v45 = stack[-1];
    v46 = qcar(v45);
    v45 = stack[-2];
    v45 = cons(v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v45;
    goto v81;

v78:
    v45 = stack[-2];
        popv(4);
        return Lnreverse(nil, v45);
/* error exit handlers */
v99:
    popv(4);
    return nil;
}



/* Code for actual_world */

static Lisp_Object CC_actual_world(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v117, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_world");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v117 = v31;
    v75 = v0;
/* end of prologue */
    v101 = v75;
    stack[0] = qcar(v101);
    v101 = v117;
    v117 = v75;
    v117 = qcdr(v117);
    fn = elt(env, 1); /* exclude_edges */
    v101 = (*qfn2(fn))(qenv(fn), v101, v117);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-1];
    {
        Lisp_Object v79 = stack[0];
        popv(2);
        fn = elt(env, 2); /* union_edges */
        return (*qfn2(fn))(qenv(fn), v79, v101);
    }
/* error exit handlers */
v83:
    popv(2);
    return nil;
}



/* Code for normmat */

static Lisp_Object CC_normmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v326;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for normmat");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v326 = v0;
/* end of prologue */
    stack[-6] = nil;
    v69 = (Lisp_Object)17; /* 1 */
    stack[-8] = v69;
    v69 = v326;
    stack[-5] = v69;
    goto v32;

v32:
    v69 = stack[-5];
    if (v69 == nil) goto v328;
    v69 = stack[-5];
    v69 = qcar(v69);
    stack[-1] = v69;
    v69 = (Lisp_Object)17; /* 1 */
    stack[-7] = v69;
    v69 = stack[-1];
    stack[0] = v69;
    goto v84;

v84:
    v69 = stack[0];
    if (v69 == nil) goto v95;
    v69 = stack[0];
    v69 = qcar(v69);
    v326 = stack[-7];
    v69 = qcdr(v69);
    fn = elt(env, 2); /* lcm */
    v69 = (*qfn2(fn))(qenv(fn), v326, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[-7] = v69;
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v84;

v95:
    v69 = stack[-1];
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) goto v18;
    v69 = stack[-4];
    v69 = qcar(v69);
    v326 = v69;
    stack[0] = qcar(v326);
    v326 = stack[-7];
    v69 = qcdr(v69);
    fn = elt(env, 3); /* quotf */
    v69 = (*qfn2(fn))(qenv(fn), v326, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[-2] = v69;
    stack[-3] = v69;
    goto v262;

v262:
    v69 = stack[-4];
    v69 = qcdr(v69);
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) goto v11;
    stack[-1] = stack[-2];
    v69 = stack[-4];
    v69 = qcar(v69);
    v326 = v69;
    stack[0] = qcar(v326);
    v326 = stack[-7];
    v69 = qcdr(v69);
    fn = elt(env, 3); /* quotf */
    v69 = (*qfn2(fn))(qenv(fn), v326, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v69 = Lrplacd(nil, stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v262;

v11:
    v69 = stack[-3];
    v326 = v69;
    goto v80;

v80:
    v69 = stack[-6];
    v69 = cons(v326, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[-6] = v69;
    v326 = stack[-7];
    v69 = stack[-8];
    fn = elt(env, 4); /* multf */
    v69 = (*qfn2(fn))(qenv(fn), v326, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[-8] = v69;
    v69 = stack[-5];
    v69 = qcdr(v69);
    stack[-5] = v69;
    goto v32;

v18:
    v69 = qvalue(elt(env, 1)); /* nil */
    v326 = v69;
    goto v80;

v328:
    v69 = stack[-6];
    v326 = Lreverse(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v250;
    v69 = stack[-8];
    popv(10);
    return cons(v326, v69);
/* error exit handlers */
v250:
    popv(10);
    return nil;
}



/* Code for small!-primep */

static Lisp_Object CC_smallKprimep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v381, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for small-primep");
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
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    v381 = stack[-8];
    v381 = Levenp(nil, v381);
    env = stack[-10];
    if (!(v381 == nil)) goto v117;
    v241 = stack[-8];
    v381 = (Lisp_Object)49; /* 3 */
    v241 = Cremainder(v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    v381 = (Lisp_Object)1; /* 0 */
    if (v241 == v381) goto v117;
    v381 = stack[-8];
    v381 = sub1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-6] = v381;
    v381 = stack[-8];
    v381 = Lset_small_modulus(nil, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-3] = v381;
    v381 = (Lisp_Object)1; /* 0 */
    stack[-7] = v381;
    goto v95;

v95:
    v381 = stack[-6];
    v381 = Levenp(nil, v381);
    env = stack[-10];
    if (v381 == nil) goto v15;
    v241 = stack[-6];
    v381 = (Lisp_Object)33; /* 2 */
    v381 = quot2(v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-6] = v381;
    v381 = stack[-7];
    v381 = add1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-7] = v381;
    goto v95;

v15:
    v381 = (Lisp_Object)17; /* 1 */
    stack[-9] = v381;
    v381 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v381;
    goto v111;

v111:
    v381 = stack[-2];
    if (v381 == nil) goto v112;
    v241 = stack[-9];
    v381 = qvalue(elt(env, 3)); /* !*confidence!* */
    v381 = (Lisp_Object)lesseq2(v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    v381 = v381 ? lisp_true : nil;
    env = stack[-10];
    if (v381 == nil) goto v112;
    v241 = stack[-8];
    v381 = (Lisp_Object)33; /* 2 */
    v381 = difference2(v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    fn = elt(env, 4); /* random */
    v381 = (*qfn1(fn))(qenv(fn), v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    v381 = add1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    v241 = v381;
    v381 = stack[-6];
    v381 = Lmodular_expt(nil, v241, v381);
    env = stack[-10];
    stack[-5] = v381;
    v241 = stack[-5];
    v381 = (Lisp_Object)17; /* 1 */
    if (v241 == v381) goto v41;
    v381 = (Lisp_Object)17; /* 1 */
    stack[-1] = v381;
    goto v383;

v383:
    v241 = stack[-7];
    v381 = stack[-1];
    v381 = difference2(v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    v381 = Lminusp(nil, v381);
    env = stack[-10];
    if (v381 == nil) goto v327;
    v241 = stack[-5];
    v381 = (Lisp_Object)17; /* 1 */
    if (v241 == v381) goto v41;
    v381 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v381;
    goto v41;

v41:
    v381 = stack[-9];
    v381 = add1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-9] = v381;
    goto v111;

v327:
    v241 = stack[-5];
    v381 = stack[-5];
    v381 = Lmodular_times(nil, v241, v381);
    env = stack[-10];
    stack[-4] = v381;
    v241 = stack[-4];
    v381 = (Lisp_Object)17; /* 1 */
    if (v241 == v381) goto v334;
    v381 = qvalue(elt(env, 1)); /* nil */
    goto v384;

v384:
    if (v381 == nil) goto v244;
    v381 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v381;
    goto v37;

v37:
    v381 = stack[-1];
    v381 = add1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    stack[-1] = v381;
    goto v383;

v244:
    v381 = stack[-4];
    stack[-5] = v381;
    goto v37;

v334:
    stack[0] = stack[-5];
    v381 = stack[-8];
    v381 = sub1(v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    if (equal(stack[0], v381)) goto v385;
    v241 = stack[-5];
    v381 = (Lisp_Object)17; /* 1 */
    v381 = Lneq(nil, v241, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-10];
    goto v384;

v385:
    v381 = qvalue(elt(env, 1)); /* nil */
    goto v384;

v112:
    v381 = stack[-3];
    v381 = Lset_small_modulus(nil, v381);
    nil = C_nil;
    if (exception_pending()) goto v382;
    { Lisp_Object res = stack[-2]; popv(11); return onevalue(res); }

v117:
    v381 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v381); }
/* error exit handlers */
v382:
    popv(11);
    return nil;
}



/* Code for basic!-kern1 */

static Lisp_Object CC_basicKkern1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern1");
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
    v9 = stack[-3];
    if (!consp(v9)) goto v103;
    v9 = stack[-3];
    v9 = qcar(v9);
    fn = elt(env, 2); /* algebraic!-function */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    if (v9 == nil) goto v374;
    v9 = stack[-3];
    v9 = qcdr(v9);
    stack[-4] = v9;
    v9 = stack[-4];
    if (v9 == nil) goto v73;
    v9 = stack[-4];
    v9 = qcar(v9);
    fn = elt(env, 3); /* simp */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    stack[-1] = v9;
    stack[-2] = v9;
    goto v79;

v79:
    v9 = stack[-4];
    v9 = qcdr(v9);
    stack[-4] = v9;
    v9 = stack[-4];
    if (v9 == nil) goto v91;
    stack[0] = stack[-1];
    v9 = stack[-4];
    v9 = qcar(v9);
    fn = elt(env, 3); /* simp */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v9 = Lrplacd(nil, stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    goto v79;

v91:
    v9 = stack[-2];
    goto v83;

v83:
    fn = elt(env, 4); /* allbkern */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v3 = v9;
    if (!(v9 == nil)) { popv(6); return onevalue(v3); }

v374:
    v9 = stack[-3];
    popv(6);
    return ncons(v9);

v73:
    v9 = qvalue(elt(env, 1)); /* nil */
    goto v83;

v103:
    v9 = stack[-3];
    popv(6);
    return ncons(v9);
/* error exit handlers */
v49:
    popv(6);
    return nil;
}



/* Code for allbkern */

static Lisp_Object CC_allbkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v375, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for allbkern");
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
    goto v61;

v61:
    v375 = stack[0];
    if (v375 == nil) goto v103;
    v375 = stack[0];
    v375 = qcar(v375);
    v114 = qcar(v375);
    v375 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* kernels1 */
    v375 = (*qfn2(fn))(qenv(fn), v114, v375);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    fn = elt(env, 3); /* basic!-kern */
    v114 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v375 = stack[-1];
    v375 = cons(v114, v375);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[-1] = v375;
    v375 = stack[0];
    v375 = qcdr(v375);
    stack[0] = v375;
    goto v61;

v103:
    v375 = qvalue(elt(env, 1)); /* nil */
    v114 = v375;
    goto v81;

v81:
    v375 = stack[-1];
    if (v375 == nil) { popv(3); return onevalue(v114); }
    v375 = stack[-1];
    v375 = qcar(v375);
    fn = elt(env, 4); /* union */
    v375 = (*qfn2(fn))(qenv(fn), v375, v114);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v114 = v375;
    v375 = stack[-1];
    v375 = qcdr(v375);
    stack[-1] = v375;
    goto v81;
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for ofsf_facequal */

static Lisp_Object CC_ofsf_facequal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v41, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal");
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
    v100 = v0;
/* end of prologue */
    fn = elt(env, 7); /* fctrf */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v100 = qcdr(v100);
    stack[-3] = v100;
    v100 = stack[-3];
    if (v100 == nil) goto v34;
    v100 = stack[-3];
    v100 = qcar(v100);
    v68 = elt(env, 2); /* equal */
    v41 = qcar(v100);
    v100 = qvalue(elt(env, 1)); /* nil */
    v100 = list3(v68, v41, v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-1] = v100;
    stack[-2] = v100;
    goto v103;

v103:
    v100 = stack[-3];
    v100 = qcdr(v100);
    stack[-3] = v100;
    v100 = stack[-3];
    if (v100 == nil) goto v55;
    stack[0] = stack[-1];
    v100 = stack[-3];
    v100 = qcar(v100);
    v68 = elt(env, 2); /* equal */
    v41 = qcar(v100);
    v100 = qvalue(elt(env, 1)); /* nil */
    v100 = list3(v68, v41, v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v100 = Lrplacd(nil, stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v100 = stack[-1];
    v100 = qcdr(v100);
    stack[-1] = v100;
    goto v103;

v55:
    v100 = stack[-2];
    goto v61;

v61:
    v41 = v100;
    v100 = v41;
    if (v100 == nil) goto v112;
    v100 = v41;
    v100 = qcdr(v100);
    if (v100 == nil) goto v112;
    v100 = elt(env, 3); /* or */
    popv(5);
    return cons(v100, v41);

v112:
    v100 = v41;
    if (v100 == nil) goto v10;
    v100 = v41;
    v100 = qcar(v100);
    { popv(5); return onevalue(v100); }

v10:
    v41 = elt(env, 3); /* or */
    v100 = elt(env, 4); /* and */
    if (v41 == v100) goto v260;
    v100 = elt(env, 6); /* false */
    { popv(5); return onevalue(v100); }

v260:
    v100 = elt(env, 5); /* true */
    { popv(5); return onevalue(v100); }

v34:
    v100 = qvalue(elt(env, 1)); /* nil */
    goto v61;
/* error exit handlers */
v108:
    popv(5);
    return nil;
}



/* Code for monomispommaretdivisibleby */

static Lisp_Object CC_monomispommaretdivisibleby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v119, v108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomispommaretdivisibleby");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v108 = v31;
    v65 = v0;
/* end of prologue */
    stack[0] = nil;
    v119 = v65;
    v65 = (Lisp_Object)17; /* 1 */
    v65 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    stack[-2] = v65;
    v119 = v108;
    v65 = (Lisp_Object)17; /* 1 */
    v65 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    stack[-1] = v65;
    goto v84;

v84:
    v65 = stack[-2];
    v65 = qcar(v65);
    if (v65 == nil) goto v80;
    v65 = stack[-2];
    v119 = qcar(v65);
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = (Lisp_Object)greaterp2(v119, v65);
    nil = C_nil;
    if (exception_pending()) goto v42;
    v65 = v65 ? lisp_true : nil;
    env = stack[-3];
    if (v65 == nil) goto v80;
    v65 = stack[-2];
    v65 = qcdr(v65);
    stack[-2] = v65;
    goto v84;

v80:
    v65 = stack[0];
    if (v65 == nil) goto v51;
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v53;

v53:
    if (v65 == nil) goto v50;
    v65 = stack[-2];
    v119 = qcar(v65);
    v65 = stack[-1];
    v65 = qcar(v65);
    if (equal(v119, v65)) goto v10;
    v65 = qvalue(elt(env, 2)); /* t */
    stack[0] = v65;
    goto v80;

v10:
    v65 = stack[-2];
    v65 = qcdr(v65);
    stack[-2] = v65;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v80;

v50:
    v65 = stack[-2];
    v65 = qcar(v65);
    if (v65 == nil) goto v46;
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v65); }

v46:
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = (v65 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v65); }

v51:
    v65 = stack[-2];
    v65 = qcar(v65);
    if (v65 == nil) goto v18;
    v65 = stack[-1];
    v65 = qcar(v65);
    goto v53;

v18:
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v53;
/* error exit handlers */
v42:
    popv(4);
    return nil;
}



/* Code for put!-kvalue */

static Lisp_Object MS_CDECL CC_putKkvalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v7, Lisp_Object v72, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v44, v256, v380, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "put-kvalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-kvalue");
#endif
    if (stack >= stacklimit)
    {
        push4(v72,v7,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v31,v7,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v72;
    stack[-2] = v7;
    stack[-3] = v31;
    stack[0] = v0;
/* end of prologue */
    v44 = stack[-1];
    v46 = elt(env, 1); /* !*sq */
    if (!consp(v44)) goto v95;
    v44 = qcar(v44);
    if (!(v44 == v46)) goto v95;
    v44 = stack[-2];
    v46 = stack[-1];
    v46 = qcdr(v46);
    v46 = qcar(v46);
    v46 = qcar(v46);
    fn = elt(env, 6); /* sf_member */
    v46 = (*qfn2(fn))(qenv(fn), v44, v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    if (!(v46 == nil)) goto v82;
    v44 = stack[-2];
    v46 = stack[-1];
    v46 = qcdr(v46);
    v46 = qcar(v46);
    v46 = qcdr(v46);
    fn = elt(env, 6); /* sf_member */
    v46 = (*qfn2(fn))(qenv(fn), v44, v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    goto v82;

v82:
    if (v46 == nil) goto v94;
    v99 = qvalue(elt(env, 2)); /* nil */
    v380 = stack[-2];
    v256 = elt(env, 3); /* "improperly defined in terms of itself" */
    v44 = qvalue(elt(env, 2)); /* nil */
    v46 = qvalue(elt(env, 4)); /* t */
    {
        popv(6);
        fn = elt(env, 7); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v99, v380, v256, v44, v46);
    }

v94:
    stack[-4] = stack[0];
    stack[0] = elt(env, 5); /* kvalue */
    v44 = stack[-2];
    v46 = stack[-1];
    v46 = list2(v44, v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v46 = ncons(v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v46 = Lnconc(nil, stack[-3], v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v119 = stack[-4];
        Lisp_Object v108 = stack[0];
        popv(6);
        return Lputprop(nil, 3, v119, v108, v46);
    }

v95:
    v44 = stack[-2];
    v46 = stack[-1];
    fn = elt(env, 8); /* smember */
    v46 = (*qfn2(fn))(qenv(fn), v44, v46);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    goto v82;
/* error exit handlers */
v65:
    popv(6);
    return nil;
}



/* Code for ofsf_sminsert1 */

static Lisp_Object MS_CDECL CC_ofsf_sminsert1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v7, Lisp_Object v72,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v387, v321, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "ofsf_sminsert1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sminsert1");
#endif
    if (stack >= stacklimit)
    {
        push5(v21,v72,v7,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v31,v7,v72,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v72;
    stack[-2] = v7;
    stack[-3] = v31;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = stack[-3];
    v387 = stack[-1];
    v387 = qcar(v387);
    fn = elt(env, 4); /* negf */
    v321 = (*qfn1(fn))(qenv(fn), v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    v387 = stack[-1];
    v387 = qcdr(v387);
    v387 = cons(v321, v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    fn = elt(env, 5); /* addsq */
    v387 = (*qfn2(fn))(qenv(fn), stack[-5], v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    v387 = qcar(v387);
    v321 = v387;
    v387 = v321;
    if (v387 == nil) goto v23;
    v387 = v321;
    fn = elt(env, 6); /* minusf */
    v387 = (*qfn1(fn))(qenv(fn), v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    if (v387 == nil) goto v360;
    v321 = stack[-4];
    v387 = stack[-2];
    fn = elt(env, 7); /* ofsf_smordtable */
    v387 = (*qfn2(fn))(qenv(fn), v321, v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    v239 = v387;
    v387 = v239;
    if (!consp(v387)) { popv(7); return onevalue(v239); }
    v321 = v239;
    v387 = stack[-4];
    if (!consp(v321)) goto v110;
    v321 = qcar(v321);
    if (!(v321 == v387)) goto v110;
    v387 = v239;
    v387 = qcdr(v387);
    goto v44;

v44:
    if (v387 == nil) goto v2;
    v387 = elt(env, 2); /* true */
    { popv(7); return onevalue(v387); }

v2:
    v321 = stack[0];
    v387 = v239;
    v387 = qcar(v387);
    v239 = qcdr(v239);
    if (v239 == nil) goto v327;
    v239 = stack[-3];
    goto v389;

v389:
    popv(7);
    return list2star(v321, v387, v239);

v327:
    v239 = stack[-1];
    goto v389;

v110:
    v387 = qvalue(elt(env, 3)); /* nil */
    goto v44;

v360:
    v321 = stack[-2];
    v387 = stack[-4];
    fn = elt(env, 7); /* ofsf_smordtable */
    v387 = (*qfn2(fn))(qenv(fn), v321, v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    v239 = v387;
    v387 = v239;
    if (!consp(v387)) { popv(7); return onevalue(v239); }
    v321 = v239;
    v387 = stack[-4];
    if (!consp(v321)) goto v390;
    v321 = qcar(v321);
    if (!(v321 == v387)) goto v390;
    v387 = v239;
    v387 = qcdr(v387);
    v387 = (v387 == nil ? lisp_true : nil);
    goto v249;

v249:
    if (v387 == nil) goto v378;
    v387 = elt(env, 2); /* true */
    { popv(7); return onevalue(v387); }

v378:
    v321 = stack[0];
    v387 = v239;
    v387 = qcar(v387);
    v239 = qcdr(v239);
    if (v239 == nil) goto v248;
    v239 = stack[-1];
    goto v335;

v335:
    popv(7);
    return list2star(v321, v387, v239);

v248:
    v239 = stack[-3];
    goto v335;

v390:
    v387 = qvalue(elt(env, 3)); /* nil */
    goto v249;

v23:
    v321 = stack[-4];
    v387 = stack[-2];
    fn = elt(env, 8); /* ofsf_smeqtable */
    v387 = (*qfn2(fn))(qenv(fn), v321, v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-6];
    v239 = v387;
    v321 = v239;
    v387 = elt(env, 1); /* false */
    if (v321 == v387) goto v91;
    v321 = stack[-4];
    v387 = v239;
    if (v321 == v387) goto v52;
    v321 = stack[0];
    v387 = stack[-3];
    popv(7);
    return list2star(v321, v239, v387);

v52:
    v387 = elt(env, 2); /* true */
    { popv(7); return onevalue(v387); }

v91:
    v387 = elt(env, 1); /* false */
    { popv(7); return onevalue(v387); }
/* error exit handlers */
v388:
    popv(7);
    return nil;
}



/* Code for qqe_length!-graph!-marked */

static Lisp_Object CC_qqe_lengthKgraphKmarked(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v32 = elt(env, 1); /* blockmark */
    return get(v82, v32);
}



/* Code for lto_cartprod */

static Lisp_Object CC_lto_cartprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_cartprod");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v76 = v0;
/* end of prologue */
    v75 = v76;
    if (v75 == nil) goto v81;
    v75 = v76;
    v75 = qcdr(v75);
    v75 = (v75 == nil ? lisp_true : nil);
    goto v103;

v103:
    if (!(v75 == nil)) return onevalue(v76);
    v75 = v76;
    {
        fn = elt(env, 2); /* lto_cartprod1 */
        return (*qfn1(fn))(qenv(fn), v75);
    }

v81:
    v75 = qvalue(elt(env, 1)); /* t */
    goto v103;
}



/* Code for aex_add */

static Lisp_Object CC_aex_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_add");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v14 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v14 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_add */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v14 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v14 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v14 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    if (v14 == nil) goto v56;
    v14 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    goto v32;

v32:
    {
        Lisp_Object v375 = stack[-4];
        Lisp_Object v114 = stack[-1];
        Lisp_Object v17 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v375, v114, v17, v14);
    }

v56:
    v14 = qvalue(elt(env, 1)); /* nil */
    goto v32;
/* error exit handlers */
v80:
    popv(6);
    return nil;
}



/* Code for dipbcprod */

static Lisp_Object CC_dipbcprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipbcprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v79 = stack[0];
    fn = elt(env, 2); /* bczero!? */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (v79 == nil) goto v61;
    v79 = qvalue(elt(env, 1)); /* dipzero */
    { popv(3); return onevalue(v79); }

v61:
    v79 = stack[0];
    fn = elt(env, 3); /* bcone!? */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (!(v79 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v84 = stack[-1];
    v79 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* dipbcprodin */
        return (*qfn2(fn))(qenv(fn), v84, v79);
    }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for setequal */

static Lisp_Object CC_setequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v85 = stack[-1];
    v84 = stack[0];
    fn = elt(env, 2); /* subsetp */
    v84 = (*qfn2(fn))(qenv(fn), v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    if (v84 == nil) goto v86;
    v85 = stack[0];
    v84 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* subsetp */
        return (*qfn2(fn))(qenv(fn), v85, v84);
    }

v86:
    v84 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v84); }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for acmemb */

static Lisp_Object CC_acmemb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acmemb");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */

v86:
    v54 = stack[0];
    if (v54 == nil) goto v81;
    v73 = stack[-1];
    v54 = stack[0];
    v54 = qcar(v54);
    fn = elt(env, 2); /* aceq */
    v54 = (*qfn2(fn))(qenv(fn), v73, v54);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    if (v54 == nil) goto v79;
    v54 = stack[0];
    v54 = qcar(v54);
    { popv(3); return onevalue(v54); }

v79:
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v86;

v81:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v92:
    popv(3);
    return nil;
}



/* Code for gi */

static Lisp_Object CC_gi(Lisp_Object env,
                         Lisp_Object v31, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gi");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v31);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v31,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v7;
    v95 = v31;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v95; /* gg */
    stack[-2] = nil;
    v95 = qvalue(elt(env, 1)); /* gg */
    stack[-1] = v95;
    goto v35;

v35:
    v95 = stack[-1];
    if (v95 == nil) goto v34;
    v95 = stack[-1];
    v95 = qcar(v95);
    stack[0] = v95;
    v95 = stack[0];
    v95 = qcdr(v95);
    fn = elt(env, 3); /* class */
    v50 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v95 = stack[-3];
    if (!(equal(v50, v95))) goto v84;
    v50 = stack[0];
    v95 = stack[-2];
    v95 = cons(v50, v95);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    stack[-2] = v95;
    goto v84;

v84:
    v95 = stack[-1];
    v95 = qcdr(v95);
    stack[-1] = v95;
    goto v35;

v34:
    v95 = stack[-2];
    qvalue(elt(env, 1)) = stack[-4]; /* gg */
    { popv(6); return onevalue(v95); }
/* error exit handlers */
v52:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* gg */
    popv(6);
    return nil;
}



setup_type const u46_setup[] =
{
    {"pa_part2list",            CC_pa_part2list,too_many_1,    wrong_no_1},
    {"get_first_kernel",        too_few_2,      CC_get_first_kernel,wrong_no_2},
    {"rl_simpatom",             CC_rl_simpatom, too_many_1,    wrong_no_1},
    {"deleteq",                 too_few_2,      CC_deleteq,    wrong_no_2},
    {"ioto_tprin2",             CC_ioto_tprin2, too_many_1,    wrong_no_1},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"iv_cutn",                 CC_iv_cutn,     too_many_1,    wrong_no_1},
    {"bc_dcont",                CC_bc_dcont,    too_many_1,    wrong_no_1},
    {"subeval",                 CC_subeval,     too_many_1,    wrong_no_1},
    {"nestminusp:",             CC_nestminuspT, too_many_1,    wrong_no_1},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {"idealp",                  CC_idealp,      too_many_1,    wrong_no_1},
    {"mkuniquewedge",           CC_mkuniquewedge,too_many_1,   wrong_no_1},
    {"contain_edge",            too_few_2,      CC_contain_edge,wrong_no_2},
    {"dfppri",                  CC_dfppri,      too_many_1,    wrong_no_1},
    {"*sq2fourier",             CC_Hsq2fourier, too_many_1,    wrong_no_1},
    {"square-free-mod-p",       CC_squareKfreeKmodKp,too_many_1,wrong_no_1},
    {"legendre-symbol",         too_few_2,      CC_legendreKsymbol,wrong_no_2},
    {"flatten",                 CC_flatten,     too_many_1,    wrong_no_1},
    {"getsetvarlis",            CC_getsetvarlis,too_many_1,    wrong_no_1},
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {"make-var-coefflist",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKvarKcoefflist},
    {"get_nr_irred_reps",       CC_get_nr_irred_reps,too_many_1,wrong_no_1},
    {"iscale",                  too_few_2,      CC_iscale,     wrong_no_2},
    {"rand-comb",               too_few_2,      CC_randKcomb,  wrong_no_2},
    {"lispcondp",               CC_lispcondp,   too_many_1,    wrong_no_1},
    {"asymmetrize-inds",        too_few_2,      CC_asymmetrizeKinds,wrong_no_2},
    {"requote1",                CC_requote1,    too_many_1,    wrong_no_1},
    {"actual_world",            too_few_2,      CC_actual_world,wrong_no_2},
    {"normmat",                 CC_normmat,     too_many_1,    wrong_no_1},
    {"small-primep",            CC_smallKprimep,too_many_1,    wrong_no_1},
    {"basic-kern1",             CC_basicKkern1, too_many_1,    wrong_no_1},
    {"allbkern",                CC_allbkern,    too_many_1,    wrong_no_1},
    {"ofsf_facequal",           CC_ofsf_facequal,too_many_1,   wrong_no_1},
    {"monomispommaretdivisibleby",too_few_2,    CC_monomispommaretdivisibleby,wrong_no_2},
    {"put-kvalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKkvalue},
    {"ofsf_sminsert1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sminsert1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"lto_cartprod",            CC_lto_cartprod,too_many_1,    wrong_no_1},
    {"aex_add",                 too_few_2,      CC_aex_add,    wrong_no_2},
    {"dipbcprod",               too_few_2,      CC_dipbcprod,  wrong_no_2},
    {"setequal",                too_few_2,      CC_setequal,   wrong_no_2},
    {"acmemb",                  too_few_2,      CC_acmemb,     wrong_no_2},
    {"gi",                      too_few_2,      CC_gi,         wrong_no_2},
    {NULL, (one_args *)"u46", (two_args *)"2429 8246785 7684174", 0}
};

/* end of generated code */
