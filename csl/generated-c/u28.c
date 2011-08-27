
/* $destdir\u28.c        Machine generated C code */

/* Signature: 00000000 27-Aug-2011 */

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


/* Code for collectphysops_reversed */

static Lisp_Object CC_collectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphysops_reversed");
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
    v10 = stack[-1];
    if (!consp(v10)) goto v12;
    v10 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    if (v10 == nil) goto v14;
    stack[-2] = stack[-1];
    v10 = stack[-1];
    fn = elt(env, 3); /* collectindices */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    fn = elt(env, 4); /* removeindices */
    v11 = (*qfn2(fn))(qenv(fn), stack[-2], v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v10 = stack[0];
    popv(4);
    return cons(v11, v10);

v14:
    v10 = stack[-1];
    if (!consp(v10)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v10 = stack[-1];
    v11 = qcar(v10);
    v10 = stack[0];
    v10 = CC_collectphysops_reversed(env, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[0] = v10;
    v10 = stack[-1];
    v10 = qcdr(v10);
    stack[-1] = v10;
    goto v14;

v12:
    v10 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v11 = stack[-1];
    v10 = stack[0];
    popv(4);
    return cons(v11, v10);
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzero");
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
    goto v22;

v22:
    v21 = stack[0];
    v20 = (Lisp_Object)1; /* 0 */
    if (v21 == v20) goto v23;
    v21 = (Lisp_Object)1; /* 0 */
    v20 = stack[-1];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[-1] = v20;
    v20 = stack[0];
    v20 = sub1(v20);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[0] = v20;
    goto v22;

v23:
    v20 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for fs!:onep!: */

static Lisp_Object CC_fsTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:onep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v25 = qcdr(v25);
    {
        fn = elt(env, 1); /* fs!:onep */
        return (*qfn1(fn))(qenv(fn), v25);
    }
}



/* Code for pst_subpst */

static Lisp_Object CC_pst_subpst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_subpst");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v28 = v1;
    v27 = v0;
/* end of prologue */
    stack[0] = qcdr(v27);
    v27 = v28;
    v27 = sub1(v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v27 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v27/(16/CELL)));
    { popv(1); return onevalue(v27); }
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v53 = stack[-3];
    if (!consp(v53)) goto v22;
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = (consp(v53) ? nil : lisp_true);
    goto v26;

v26:
    if (v53 == nil) goto v9;
    v53 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v53); }

v9:
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v54 = qcar(v53);
    v53 = stack[-1];
    if (equal(v54, v53)) goto v56;
    v53 = stack[-3];
    v53 = qcar(v53);
    stack[-4] = qcar(v53);
    v53 = stack[-3];
    v53 = qcar(v53);
    v55 = qcdr(v53);
    v54 = stack[-2];
    v53 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v55, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-3];
    v55 = qcdr(v53);
    v54 = stack[-2];
    v53 = stack[-1];
    v53 = CC_diffKoverKkKmodKp(env, 3, v55, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    {
        Lisp_Object v58 = stack[-4];
        Lisp_Object v59 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v58, v59, v53);
    }

v56:
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v54 = qcdr(v53);
    v53 = (Lisp_Object)17; /* 1 */
    if (v54 == v53) goto v60;
    v53 = stack[-1];
    fn = elt(env, 4); /* fkern */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v53 = (Lisp_Object)((int32_t)(v53) - 0x10);
    fn = elt(env, 5); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v54 = Lmodular_number(nil, v53);
    env = stack[-5];
    v53 = stack[-3];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    fn = elt(env, 6); /* times!-mod!-p */
    v54 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-2];
    v53 = Lmodular_number(nil, v53);
    env = stack[-5];
    fn = elt(env, 7); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-3];
    v55 = qcdr(v53);
    v54 = stack[-2];
    v53 = stack[-1];
    v53 = CC_diffKoverKkKmodKp(env, 3, v55, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    {
        Lisp_Object v61 = stack[-4];
        Lisp_Object v62 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v61, v62, v53);
    }

v60:
    v53 = stack[-3];
    v53 = qcar(v53);
    v54 = qcdr(v53);
    v53 = stack[-2];
    v53 = Lmodular_number(nil, v53);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 7); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v54, v53);
    }

v22:
    v53 = qvalue(elt(env, 1)); /* t */
    goto v26;
/* error exit handlers */
v57:
    popv(6);
    return nil;
}



/* Code for ext_mult */

static Lisp_Object CC_ext_mult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v13, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ext_mult");
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
    v71 = v1;
    v13 = v0;
/* end of prologue */
    v13 = qcdr(v13);
    v71 = qcdr(v71);
    fn = elt(env, 3); /* merge_lists */
    v71 = (*qfn2(fn))(qenv(fn), v13, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    stack[0] = v71;
    v71 = stack[0];
    if (v71 == nil) goto v74;
    v71 = stack[0];
    v71 = qcdr(v71);
    if (v71 == nil) goto v21;
    v13 = elt(env, 2); /* ext */
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = cons(v13, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    fn = elt(env, 4); /* !*a2k */
    v72 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v13 = (Lisp_Object)17; /* 1 */
    v71 = stack[0];
    v71 = qcar(v71);
    v13 = acons(v72, v13, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v72 = qvalue(elt(env, 1)); /* nil */
    v71 = (Lisp_Object)17; /* 1 */
    popv(2);
    return acons(v13, v72, v71);

v21:
    v13 = (Lisp_Object)17; /* 1 */
    v71 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v13, v71);

v74:
    v13 = qvalue(elt(env, 1)); /* nil */
    v71 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v13, v71);
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for fctrf1 */

static Lisp_Object CC_fctrf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctrf1");
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
    stack[-1] = nil;
    v113 = stack[-3];
    if (!consp(v113)) goto v27;
    v113 = stack[-3];
    v113 = qcar(v113);
    v113 = (consp(v113) ? nil : lisp_true);
    goto v70;

v70:
    if (v113 == nil) goto v116;
    v113 = stack[-3];
    popv(6);
    return ncons(v113);

v116:
    v114 = qvalue(elt(env, 2)); /* dmode!* */
    v113 = elt(env, 3); /* field */
    v113 = Lflagp(nil, v114, v113);
    env = stack[-5];
    if (v113 == nil) goto v14;
    v113 = stack[-3];
    fn = elt(env, 6); /* lnc */
    v114 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-1] = v114;
    v113 = (Lisp_Object)17; /* 1 */
    v113 = Lneq(nil, v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    goto v118;

v118:
    if (v113 == nil) goto v15;
    v113 = stack[-1];
    fn = elt(env, 7); /* !:recip */
    v114 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-3];
    fn = elt(env, 8); /* multd */
    v113 = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-3] = v113;
    goto v69;

v69:
    v113 = stack[-3];
    fn = elt(env, 9); /* comfac */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-4] = v113;
    stack[0] = stack[-3];
    v113 = stack[-4];
    v113 = qcar(v113);
    if (v113 == nil) goto v119;
    v113 = stack[-4];
    v113 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    goto v120;

v120:
    fn = elt(env, 10); /* quotf */
    v113 = (*qfn2(fn))(qenv(fn), stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-3] = v113;
    v113 = stack[-4];
    v113 = qcdr(v113);
    v113 = CC_fctrf1(env, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-2] = v113;
    v113 = stack[-4];
    v113 = qcar(v113);
    if (v113 == nil) goto v121;
    v113 = stack[-2];
    stack[0] = qcar(v113);
    v113 = stack[-4];
    v113 = qcar(v113);
    v115 = qcar(v113);
    v114 = (Lisp_Object)17; /* 1 */
    v113 = (Lisp_Object)17; /* 1 */
    v113 = acons(v115, v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v114 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-4];
    v113 = qcar(v113);
    v113 = qcdr(v113);
    v114 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-2];
    v113 = qcdr(v113);
    v113 = list2star(stack[0], v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-2] = v113;
    goto v121;

v121:
    v113 = stack[-1];
    if (v113 == nil) goto v62;
    v114 = stack[-1];
    v113 = (Lisp_Object)17; /* 1 */
    if (v114 == v113) goto v62;
    v114 = stack[-1];
    v113 = stack[-2];
    v113 = qcar(v113);
    fn = elt(env, 8); /* multd */
    v114 = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-2];
    v113 = qcdr(v113);
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-2] = v113;
    goto v62;

v62:
    v113 = stack[-3];
    if (!consp(v113)) goto v122;
    v113 = stack[-3];
    v113 = qcar(v113);
    v113 = (consp(v113) ? nil : lisp_true);
    goto v123;

v123:
    if (v113 == nil) goto v124;
    v114 = stack[-3];
    v113 = stack[-2];
    v113 = qcar(v113);
    fn = elt(env, 11); /* multf */
    v114 = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v113 = stack[-2];
    v113 = qcdr(v113);
    popv(6);
    return cons(v114, v113);

v124:
    v113 = stack[-3];
    fn = elt(env, 12); /* minusf */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    if (v113 == nil) goto v125;
    v113 = stack[-3];
    fn = elt(env, 13); /* negf */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-3] = v113;
    v113 = stack[-2];
    v113 = qcar(v113);
    fn = elt(env, 13); /* negf */
    v114 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-2];
    v113 = qcdr(v113);
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-2] = v113;
    goto v125;

v125:
    v113 = stack[-3];
    fn = elt(env, 14); /* factor!-prim!-f */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-1] = v113;
    v113 = stack[-1];
    v114 = qcar(v113);
    v113 = stack[-2];
    v113 = qcar(v113);
    fn = elt(env, 11); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-1];
    v114 = qcdr(v113);
    v113 = stack[-2];
    v113 = qcdr(v113);
    v113 = Lappend(nil, v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    {
        Lisp_Object v126 = stack[0];
        popv(6);
        return cons(v126, v113);
    }

v122:
    v113 = qvalue(elt(env, 1)); /* t */
    goto v123;

v119:
    v113 = stack[-4];
    v113 = qcdr(v113);
    goto v120;

v15:
    v113 = qvalue(elt(env, 2)); /* dmode!* */
    if (v113 == nil) goto v69;
    v114 = qvalue(elt(env, 2)); /* dmode!* */
    v113 = elt(env, 5); /* unitsfn */
    v113 = get(v114, v113);
    env = stack[-5];
    stack[-2] = v113;
    if (v113 == nil) goto v69;
    stack[-1] = stack[-2];
    v114 = (Lisp_Object)17; /* 1 */
    v113 = stack[-3];
    stack[0] = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = stack[-3];
    fn = elt(env, 6); /* lnc */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v113 = Lapply2(nil, 3, stack[-1], stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-4] = v113;
    v113 = stack[-4];
    v113 = qcdr(v113);
    stack[-3] = v113;
    v113 = stack[-4];
    v113 = qcar(v113);
    fn = elt(env, 7); /* !:recip */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-1] = v113;
    goto v69;

v14:
    v113 = qvalue(elt(env, 4)); /* nil */
    goto v118;

v27:
    v113 = qvalue(elt(env, 1)); /* t */
    goto v70;
/* error exit handlers */
v117:
    popv(6);
    return nil;
}



/* Code for aex_0 */

static Lisp_Object MS_CDECL CC_aex_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "aex_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_0");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 1); /* ratpoly_0 */
    v79 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aex_fromrp */
        return (*qfn1(fn))(qenv(fn), v79);
    }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for ev_2a */

static Lisp_Object CC_ev_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v112 = v22;
    v22 = qvalue(elt(env, 1)); /* dip_vars!* */
    {
        fn = elt(env, 2); /* ev_2a1 */
        return (*qfn2(fn))(qenv(fn), v112, v22);
    }
}



/* Code for bvarrd */

static Lisp_Object MS_CDECL CC_bvarrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "bvarrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarrd");
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
    fn = elt(env, 8); /* lex */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v130 = qvalue(elt(env, 1)); /* char */
    v46 = elt(env, 2); /* (d e g r e e) */
    if (!(equal(v130, v46))) goto v12;
    v130 = elt(env, 3); /* "<bvar>" */
    v46 = (Lisp_Object)241; /* 15 */
    fn = elt(env, 9); /* errorml */
    v46 = (*qfn2(fn))(qenv(fn), v130, v46);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    goto v12;

v12:
    fn = elt(env, 10); /* mathml2 */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    stack[-1] = v46;
    fn = elt(env, 8); /* lex */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v130 = qvalue(elt(env, 1)); /* char */
    v46 = elt(env, 2); /* (d e g r e e) */
    if (equal(v130, v46)) goto v118;
    v46 = (Lisp_Object)17; /* 1 */
    stack[0] = v46;
    goto v38;

v38:
    v130 = qvalue(elt(env, 1)); /* char */
    v46 = elt(env, 6); /* (!/ b v a r) */
    if (equal(v130, v46)) goto v132;
    v130 = elt(env, 7); /* "</bvar>" */
    v46 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* errorml */
    v46 = (*qfn2(fn))(qenv(fn), v130, v46);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v46 = nil;
    { popv(3); return onevalue(v46); }

v132:
    v130 = stack[-1];
    v46 = stack[0];
    popv(3);
    return list2(v130, v46);

v118:
    fn = elt(env, 11); /* mathml */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    stack[0] = v46;
    fn = elt(env, 8); /* lex */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v130 = qvalue(elt(env, 1)); /* char */
    v46 = elt(env, 4); /* (!/ d e g r e e) */
    if (equal(v130, v46)) goto v133;
    v130 = elt(env, 5); /* "</degree>" */
    v46 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 12); /* error */
    v46 = (*qfn2(fn))(qenv(fn), v130, v46);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    goto v133;

v133:
    fn = elt(env, 8); /* lex */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    goto v38;
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for groebcplistsortin1 */

static Lisp_Object CC_groebcplistsortin1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin1");
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

v112:
    v137 = stack[0];
    v138 = qcar(v137);
    v137 = stack[-1];
    fn = elt(env, 1); /* groebcpcompless!? */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    if (v137 == nil) goto v74;
    v137 = stack[0];
    v137 = qcdr(v137);
    if (v137 == nil) goto v139;
    v137 = stack[0];
    v137 = qcdr(v137);
    stack[0] = v137;
    goto v112;

v139:
    v137 = stack[-1];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    {
        Lisp_Object v38 = stack[0];
        popv(4);
        return Lrplacd(nil, v38, v137);
    }

v74:
    stack[-2] = stack[0];
    v137 = stack[0];
    v138 = qcar(v137);
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = cons(v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v137 = Lrplacd(nil, stack[-2], v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v138 = stack[0];
    v137 = stack[-1];
        popv(4);
        return Lrplaca(nil, v138, v137);
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for contr!-strand */

static Lisp_Object CC_contrKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr-strand");
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
    stack[0] = v1;
    v69 = v0;
/* end of prologue */

v25:
    v68 = stack[0];
    if (v68 == nil) { popv(2); return onevalue(v69); }
    v68 = v69;
    v69 = stack[0];
    v69 = qcar(v69);
    fn = elt(env, 1); /* contr1!-strand */
    v69 = (*qfn2(fn))(qenv(fn), v68, v69);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v68 = stack[0];
    v68 = qcdr(v68);
    stack[0] = v68;
    goto v25;
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for vecsimp!* */

static Lisp_Object CC_vecsimpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecsimp*");
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
    v27 = stack[0];
    fn = elt(env, 1); /* vecp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    if (v27 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v27 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* vecsm!* */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for arminusp!: */

static Lisp_Object CC_arminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arminusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v25 = qcdr(v25);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v25);
    }
}



/* Code for ofsf_facequal!* */

static Lisp_Object CC_ofsf_facequalH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v111, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v1;
    v141 = v0;
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* !*rlsifac */
    if (v67 == nil) goto v16;
    v67 = qvalue(elt(env, 2)); /* !*rlsiexpla */
    if (!(v67 == nil)) goto v25;
    v67 = qvalue(elt(env, 3)); /* !*rlsiexpl */
    if (v67 == nil) goto v16;
    v67 = elt(env, 4); /* or */
    if (!(v111 == v67)) goto v16;

v25:
    v67 = v141;
    {
        fn = elt(env, 7); /* ofsf_facequal */
        return (*qfn1(fn))(qenv(fn), v67);
    }

v16:
    v67 = elt(env, 5); /* equal */
    v111 = v141;
    v141 = qvalue(elt(env, 6)); /* nil */
    return list3(v67, v111, v141);
}



/* Code for sortedpolynomlistinsert */

static Lisp_Object CC_sortedpolynomlistinsert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortedpolynomlistinsert");
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
    stack[-1] = v1;
    v137 = v0;
/* end of prologue */
    stack[-2] = v137;
    goto v26;

v26:
    v137 = stack[-2];
    v137 = qcar(v137);
    if (v137 == nil) goto v7;
    v137 = stack[-2];
    v138 = qcar(v137);
    v137 = stack[-1];
    fn = elt(env, 2); /* polynomcompare */
    v138 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v137 = (Lisp_Object)-15; /* -1 */
    if (v138 == v137) goto v7;
    v137 = stack[-2];
    v137 = qcdr(v137);
    stack[-2] = v137;
    goto v26;

v7:
    stack[0] = stack[-2];
    v137 = stack[-2];
    v138 = qcar(v137);
    v137 = stack[-2];
    v137 = qcdr(v137);
    v137 = cons(v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v138 = Lrplacd(nil, stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v137 = stack[-1];
    v137 = Lrplaca(nil, v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v137 = nil;
    { popv(4); return onevalue(v137); }
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for homogp */

static Lisp_Object CC_homogp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for homogp");
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
    v106 = stack[0];
    if (!consp(v106)) goto v70;
    v106 = stack[0];
    v106 = qcar(v106);
    v106 = (consp(v106) ? nil : lisp_true);
    goto v112;

v112:
    if (v106 == nil) goto v9;
    v106 = qvalue(elt(env, 1)); /* t */
    goto v12;

v12:
    if (v106 == nil) goto v25;
    v106 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v106); }

v25:
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v106 = qcdr(v106);
    if (v106 == nil) goto v67;
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 3); /* lastnondomain */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v106 = qcdr(v106);
    v107 = v106;
    v106 = v107;
    if (!consp(v106)) goto v50;
    v106 = v107;
    v106 = qcar(v106);
    v106 = (consp(v106) ? nil : lisp_true);
    goto v49;

v49:
    if (v106 == nil) goto v38;
    v106 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v106); }

v38:
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v106 = qcar(v106);
    v106 = qcar(v106);
    fn = elt(env, 4); /* listsum */
    stack[-1] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 3); /* lastnondomain */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v106 = qcar(v106);
    v106 = qcar(v106);
    fn = elt(env, 4); /* listsum */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    if (equal(stack[-1], v106)) goto v147;
    v106 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v106); }

v147:
    v106 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v106); }

v50:
    v106 = qvalue(elt(env, 1)); /* t */
    goto v49;

v67:
    v106 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v106); }

v9:
    v106 = stack[0];
    v106 = qcar(v106);
    if (!consp(v106)) goto v68;
    v106 = stack[0];
    v106 = qcar(v106);
    v106 = qcar(v106);
    v106 = (consp(v106) ? nil : lisp_true);
    goto v12;

v68:
    v106 = qvalue(elt(env, 1)); /* t */
    goto v12;

v70:
    v106 = qvalue(elt(env, 1)); /* t */
    goto v112;
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for ratpoly_0 */

static Lisp_Object MS_CDECL CC_ratpoly_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_0");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v79 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v79);
    }
}



/* Code for getargsrd */

static Lisp_Object MS_CDECL CC_getargsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getargsrd");
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
    v68 = qvalue(elt(env, 1)); /* char */
    v69 = elt(env, 2); /* (b v a r) */
    if (equal(v68, v69)) goto v146;
    v69 = nil;
    { popv(2); return onevalue(v69); }

v146:
    fn = elt(env, 3); /* bvarrd */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    stack[0] = v69;
    fn = elt(env, 4); /* lex */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v69 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    {
        Lisp_Object v118 = stack[0];
        popv(2);
        return cons(v118, v69);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for findnthroot */

static Lisp_Object CC_findnthroot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v79;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnthroot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */
    v79 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v79);
}



/* Code for insertocc */

static Lisp_Object CC_insertocc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v144, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertocc");
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
    v49 = v1;
    stack[-1] = v0;
/* end of prologue */
    v144 = v49;
    v145 = stack[-1];
    v145 = Lassoc(nil, v144, v145);
    stack[-2] = v145;
    if (v145 == nil) goto v6;
    stack[0] = v49;
    v145 = stack[-2];
    v145 = qcdr(v145);
    v145 = add1(v145);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v49 = cons(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v144 = stack[-2];
    v145 = stack[-1];
    v145 = Lsubst(nil, 3, v49, v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v108;
    stack[-1] = v145;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v6:
    v144 = (Lisp_Object)17; /* 1 */
    v145 = stack[-1];
    v145 = acons(v49, v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v108;
    stack[-1] = v145;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs,
                         Lisp_Object v79, Lisp_Object v94,
                         Lisp_Object v25, Lisp_Object v146,
                         Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v165, v166, v167, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unify");
#endif
    if (stack >= stacklimit)
    {
        push5(v12,v146,v25,v94,v79);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v79,v94,v25,v146,v12);
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
    stack[-13] = v12;
    stack[-14] = v146;
    v165 = v25;
    v166 = v94;
    v85 = v79;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v85; /* op */
    v85 = v166;
    qvalue(elt(env, 2)) = v85; /* r */
    v85 = v165;
    qvalue(elt(env, 3)) = v85; /* p */
    v85 = qvalue(elt(env, 2)); /* r */
    if (v85 == nil) goto v8;
    v85 = qvalue(elt(env, 4)); /* nil */
    goto v9;

v9:
    if (v85 == nil) goto v74;
    v165 = stack[-14];
    v85 = stack[-13];
    fn = elt(env, 14); /* resume */
    v85 = (*qfn2(fn))(qenv(fn), v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-16];
    goto v27;

v27:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v85); }

v74:
    v85 = qvalue(elt(env, 2)); /* r */
    if (v85 == nil) goto v111;
    v85 = qvalue(elt(env, 3)); /* p */
    if (v85 == nil) goto v139;
    v85 = qvalue(elt(env, 4)); /* nil */
    goto v128;

v128:
    if (v85 == nil) goto v38;
    v85 = qvalue(elt(env, 4)); /* nil */
    goto v27;

v38:
    stack[0] = nil;
    stack[-9] = nil;
    stack[-8] = qvalue(elt(env, 6)); /* symm */
    qvalue(elt(env, 6)) = nil; /* symm */
    stack[-7] = qvalue(elt(env, 7)); /* comb */
    qvalue(elt(env, 7)) = nil; /* comb */
    stack[-6] = qvalue(elt(env, 8)); /* identity */
    qvalue(elt(env, 8)) = nil; /* identity */
    stack[-5] = qvalue(elt(env, 9)); /* mcontract */
    qvalue(elt(env, 9)) = nil; /* mcontract */
    stack[-4] = qvalue(elt(env, 10)); /* acontract */
    qvalue(elt(env, 10)) = nil; /* acontract */
    stack[-3] = qvalue(elt(env, 11)); /* expand */
    qvalue(elt(env, 11)) = nil; /* expand */
    stack[-2] = qvalue(elt(env, 12)); /* i */
    qvalue(elt(env, 12)) = nil; /* i */
    stack[-1] = qvalue(elt(env, 13)); /* upb */
    qvalue(elt(env, 13)) = nil; /* upb */
    v85 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v85; /* i */
    v85 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v85; /* upb */
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    fn = elt(env, 15); /* pm!:free */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    if (v85 == nil) goto v171;
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    fn = elt(env, 16); /* genp */
    v165 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    v85 = stack[-14];
    v85 = cons(v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[-14] = v85;
    goto v171;

v171:
    v85 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 17); /* initarg */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    goto v172;

v172:
    v85 = stack[0];
    if (v85 == nil) goto v41;
    v85 = qvalue(elt(env, 4)); /* nil */
    goto v43;

v43:
    if (v85 == nil) goto v120;
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    if (!consp(v85)) goto v29;
    v168 = qvalue(elt(env, 1)); /* op */
    v167 = qvalue(elt(env, 2)); /* r */
    v166 = stack[-9];
    v165 = stack[-14];
    v85 = stack[-13];
    fn = elt(env, 18); /* suspend */
    v85 = (*qfnn(fn))(qenv(fn), 5, v168, v167, v166, v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[0] = v85;
    goto v172;

v29:
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    fn = elt(env, 15); /* pm!:free */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    if (v85 == nil) goto v125;
    v85 = qvalue(elt(env, 2)); /* r */
    v165 = qcar(v85);
    v85 = stack[-9];
    v85 = qcar(v85);
    fn = elt(env, 19); /* bind */
    v85 = (*qfn2(fn))(qenv(fn), v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    v85 = stack[-14];
    fn = elt(env, 20); /* chk */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[-10] = v85;
    if (v85 == nil) goto v62;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcdr(v85);
    fn = elt(env, 21); /* mval */
    v167 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    v85 = stack[-9];
    v166 = qcdr(v85);
    v165 = stack[-10];
    v85 = stack[-13];
    v85 = CC_unify(env, 5, stack[0], v167, v166, v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[0] = v85;
    goto v62;

v62:
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    fn = elt(env, 22); /* unbind */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    goto v172;

v125:
    v85 = qvalue(elt(env, 2)); /* r */
    v165 = qcar(v85);
    v85 = stack[-9];
    v85 = qcar(v85);
    fn = elt(env, 23); /* meq */
    v85 = (*qfn2(fn))(qenv(fn), v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    if (v85 == nil) goto v172;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcdr(v85);
    fn = elt(env, 21); /* mval */
    v167 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    v85 = stack[-9];
    v166 = qcdr(v85);
    v165 = stack[-14];
    v85 = stack[-13];
    v85 = CC_unify(env, 5, stack[0], v167, v166, v165, v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[0] = v85;
    goto v172;

v120:
    v85 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v27;

v41:
    v85 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 24); /* nextarg */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-16];
    stack[-9] = v85;
    goto v43;

v139:
    v85 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 25); /* ident */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-16];
    if (!(v85 == nil)) goto v50;
    v85 = qvalue(elt(env, 2)); /* r */
    v85 = qcar(v85);
    fn = elt(env, 26); /* mgenp */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-16];
    goto v50;

v50:
    v85 = (v85 == nil ? lisp_true : nil);
    goto v128;

v111:
    v85 = elt(env, 5); /* "UNIFY:pattern over-run for function " */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-16];
    v85 = qvalue(elt(env, 1)); /* op */
    v85 = Lprint(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-16];
    v85 = qvalue(elt(env, 4)); /* nil */
    goto v27;

v8:
    v85 = qvalue(elt(env, 3)); /* p */
    v85 = (v85 == nil ? lisp_true : nil);
    goto v9;
/* error exit handlers */
v170:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
v169:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for noncomexpf */

static Lisp_Object CC_noncomexpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomexpf");
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

v173:
    v4 = stack[0];
    if (!consp(v4)) goto v23;
    v4 = stack[0];
    v4 = qcar(v4);
    v4 = (consp(v4) ? nil : lisp_true);
    goto v12;

v12:
    if (v4 == nil) goto v94;
    v4 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v4); }

v94:
    v4 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v4 == nil) goto v9;
    v4 = stack[0];
    v4 = qcar(v4);
    v4 = qcar(v4);
    v4 = qcar(v4);
    fn = elt(env, 4); /* noncomp1 */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    goto v140;

v140:
    if (!(v4 == nil)) { popv(2); return onevalue(v4); }
    v4 = stack[0];
    v4 = qcar(v4);
    v4 = qcdr(v4);
    v4 = CC_noncomexpf(env, v4);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    if (!(v4 == nil)) { popv(2); return onevalue(v4); }
    v4 = stack[0];
    v4 = qcdr(v4);
    stack[0] = v4;
    goto v173;

v9:
    v4 = qvalue(elt(env, 3)); /* nil */
    goto v140;

v23:
    v4 = qvalue(elt(env, 1)); /* t */
    goto v12;
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for simpunion */

static Lisp_Object CC_simpunion(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v148, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpunion");
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
    v73 = v0;
/* end of prologue */
    v148 = elt(env, 1); /* union */
    fn = elt(env, 3); /* applysetop */
    v73 = (*qfn2(fn))(qenv(fn), v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v143 = v73;
    v73 = v143;
    v148 = qcar(v73);
    v73 = elt(env, 1); /* union */
    if (v148 == v73) goto v110;
    v73 = v143;
    goto v21;

v21:
    fn = elt(env, 4); /* fkern */
    v148 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v73 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* getpower */
    v148 = (*qfn2(fn))(qenv(fn), v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v73 = (Lisp_Object)17; /* 1 */
    v73 = cons(v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v148 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v73 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v148, v73);

v110:
    v73 = qvalue(elt(env, 2)); /* empty_set */
    v148 = v143;
    v148 = qcdr(v148);
    v73 = Ldelete(nil, v73, v148);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v143 = v73;
    v73 = qcdr(v73);
    if (v73 == nil) goto v66;
    stack[0] = elt(env, 1); /* union */
    v73 = v143;
    fn = elt(env, 6); /* ordn */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v73 = cons(stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    goto v21;

v66:
    v73 = v143;
    v73 = qcar(v73);
    goto v21;
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for gftimesn */

static Lisp_Object CC_gftimesn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gftimesn");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v188 = v1;
    v189 = v0;
/* end of prologue */
    v90 = v189;
    v90 = qcar(v90);
    if (!consp(v90)) goto v22;
    v90 = v189;
    v90 = qcar(v90);
    stack[-5] = v90;
    v90 = v189;
    v90 = qcdr(v90);
    stack[-4] = v90;
    v90 = v188;
    v90 = qcar(v90);
    stack[-3] = v90;
    v90 = v188;
    v90 = qcdr(v90);
    stack[-2] = v90;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v90 = stack[-5];
    v90 = qcdr(v90);
    v188 = qcar(v90);
    v90 = stack[-3];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    stack[0] = times2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = stack[-5];
    v90 = qcdr(v90);
    v188 = qcdr(v90);
    v90 = stack[-3];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = plus2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    stack[-6] = list2star(stack[-1], stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v90 = stack[-4];
    v90 = qcdr(v90);
    v188 = qcar(v90);
    v90 = stack[-2];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    stack[0] = times2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = stack[-4];
    v90 = qcdr(v90);
    v188 = qcdr(v90);
    v90 = stack[-2];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = plus2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = list2star(stack[-1], stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    fn = elt(env, 2); /* difference!: */
    stack[-6] = (*qfn2(fn))(qenv(fn), stack[-6], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v90 = stack[-5];
    v90 = qcdr(v90);
    v188 = qcar(v90);
    v90 = stack[-2];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    stack[0] = times2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = stack[-5];
    v90 = qcdr(v90);
    v188 = qcdr(v90);
    v90 = stack[-2];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = plus2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    stack[-2] = list2star(stack[-1], stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v90 = stack[-4];
    v90 = qcdr(v90);
    v188 = qcar(v90);
    v90 = stack[-3];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    stack[0] = times2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = stack[-4];
    v90 = qcdr(v90);
    v188 = qcdr(v90);
    v90 = stack[-3];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = plus2(v188, v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    v90 = list2star(stack[-1], stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-7];
    fn = elt(env, 3); /* plus!: */
    v90 = (*qfn2(fn))(qenv(fn), stack[-2], v90);
    nil = C_nil;
    if (exception_pending()) goto v91;
    {
        Lisp_Object v190 = stack[-6];
        popv(8);
        return cons(v190, v90);
    }

v22:
    v90 = v189;
    {
        popv(8);
        fn = elt(env, 4); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v90, v188);
    }
/* error exit handlers */
v91:
    popv(8);
    return nil;
}



/* Code for dummyp */

static Lisp_Object CC_dummyp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v46, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummyp");
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
    v104 = (Lisp_Object)1; /* 0 */
    stack[-2] = v104;
    v104 = stack[-3];
    if (symbolp(v104)) goto v22;
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v104); }

v22:
    v104 = (Lisp_Object)17; /* 1 */
    stack[-4] = v104;
    goto v129;

v129:
    stack[0] = stack[-4];
    v104 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v104 = (Lisp_Object)lesseq2(stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v104 = v104 ? lisp_true : nil;
    env = stack[-5];
    if (v104 == nil) goto v147;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* g_dvnames */
    v104 = stack[-4];
    v104 = sub1(v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v104 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v104/(16/CELL)));
    if (equal(stack[-1], v104)) goto v24;
    v104 = stack[-4];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    stack[-4] = v104;
    goto v129;

v24:
    v104 = stack[-4];
    stack[-2] = v104;
    v104 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    stack[-4] = v104;
    goto v129;

v147:
    v46 = stack[-2];
    v104 = (Lisp_Object)1; /* 0 */
    if (!(v46 == v104)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v104 = stack[-3];
    fn = elt(env, 5); /* ad_splitname */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v46 = v104;
    v104 = v46;
    v104 = qcar(v104);
    v130 = qvalue(elt(env, 3)); /* g_dvbase */
    if (v104 == v130) goto v73;
    v104 = nil;
    { popv(6); return onevalue(v104); }

v73:
    v104 = v46;
    v104 = qcdr(v104);
    { popv(6); return onevalue(v104); }
/* error exit handlers */
v47:
    popv(6);
    return nil;
}



/* Code for general!-ordered!-gcd!-mod!-p */

static Lisp_Object CC_generalKorderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-ordered-gcd-mod-p");
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
    v39 = (Lisp_Object)1; /* 0 */
    stack[-2] = v39;
    goto v26;

v26:
    v127 = stack[-1];
    v39 = stack[0];
    fn = elt(env, 3); /* general!-reduce!-degree!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), v127, v39);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    stack[-1] = v39;
    v39 = stack[-1];
    if (v39 == nil) goto v136;
    v39 = stack[-2];
    v39 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    stack[-2] = v39;
    v39 = stack[-1];
    if (!consp(v39)) goto v20;
    v39 = stack[-1];
    v39 = qcar(v39);
    v39 = (consp(v39) ? nil : lisp_true);
    goto v52;

v52:
    if (v39 == nil) goto v145;
    v127 = qvalue(elt(env, 2)); /* reduction!-count */
    v39 = stack[-2];
    v39 = plus2(v127, v39);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    qvalue(elt(env, 2)) = v39; /* reduction!-count */
    v39 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v39); }

v145:
    v39 = stack[-1];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v127 = qcdr(v39);
    v39 = stack[0];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcdr(v39);
    v39 = (Lisp_Object)lessp2(v127, v39);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v39 = v39 ? lisp_true : nil;
    env = stack[-3];
    if (v39 == nil) goto v26;
    v127 = qvalue(elt(env, 2)); /* reduction!-count */
    v39 = stack[-2];
    v39 = plus2(v127, v39);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    qvalue(elt(env, 2)) = v39; /* reduction!-count */
    v39 = (Lisp_Object)1; /* 0 */
    stack[-2] = v39;
    v39 = stack[-1];
    v127 = v39;
    v39 = stack[0];
    stack[-1] = v39;
    v39 = v127;
    stack[0] = v39;
    goto v26;

v20:
    v39 = qvalue(elt(env, 1)); /* t */
    goto v52;

v136:
    v39 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* general!-monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v39);
    }
/* error exit handlers */
v171:
    popv(4);
    return nil;
}



/* Code for assoc2 */

static Lisp_Object CC_assoc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v52, v20, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assoc2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v1;
    v21 = v0;
/* end of prologue */

v25:
    v118 = v20;
    if (v118 == nil) goto v23;
    v52 = v21;
    v118 = v20;
    v118 = qcar(v118);
    v118 = qcdr(v118);
    if (equal(v52, v118)) goto v70;
    v118 = v20;
    v118 = qcdr(v118);
    v20 = v118;
    goto v25;

v70:
    v118 = v20;
    v118 = qcar(v118);
    return onevalue(v118);

v23:
    v118 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v118);
}



/* Code for prepsq!*0 */

static Lisp_Object CC_prepsqH0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v72, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*0");
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
    v13 = stack[-2];
    v13 = qcar(v13);
    if (v13 == nil) goto v23;
    v13 = stack[-2];
    v72 = qcar(v13);
    v13 = stack[-2];
    v13 = qcdr(v13);
    fn = elt(env, 2); /* gcdf */
    v72 = (*qfn2(fn))(qenv(fn), v72, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v72;
    v13 = (Lisp_Object)17; /* 1 */
    if (v72 == v13) goto v137;
    v13 = stack[-2];
    v72 = qcar(v13);
    v13 = stack[-3];
    fn = elt(env, 3); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v72, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v13 = stack[-2];
    v72 = qcdr(v13);
    v13 = stack[-3];
    fn = elt(env, 3); /* quotf */
    v72 = (*qfn2(fn))(qenv(fn), v72, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v13 = stack[-1];
    {
        Lisp_Object v127 = stack[0];
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v127, v72, v13);
    }

v137:
    v13 = stack[-2];
    v132 = qcar(v13);
    v13 = stack[-2];
    v72 = qcdr(v13);
    v13 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v132, v72, v13);
    }

v23:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v13); }
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for sfto_updecf */

static Lisp_Object CC_sfto_updecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_updecf");
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
    v16 = v0;
/* end of prologue */
    v15 = qvalue(elt(env, 1)); /* !*sfto_yun */
    if (v15 == nil) goto v25;
    v15 = v16;
    {
        popv(1);
        fn = elt(env, 5); /* sfto_yun!-updecf */
        return (*qfn1(fn))(qenv(fn), v15);
    }

v25:
    v15 = qvalue(elt(env, 2)); /* !*sfto_musser */
    if (v15 == nil) goto v28;
    v15 = v16;
    {
        popv(1);
        fn = elt(env, 6); /* sfto_musser!-updecf */
        return (*qfn1(fn))(qenv(fn), v15);
    }

v28:
    v15 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v15 == nil)) goto v183;
    v15 = elt(env, 4); /* "sfto_updecf: select a decomposition method" 
*/
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[0];
    fn = elt(env, 7); /* lprie */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[0];
    goto v183;

v183:
    v15 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v15 = nil;
    { popv(1); return onevalue(v15); }
/* error exit handlers */
v118:
    popv(1);
    return nil;
}



/* Code for ctx_idl */

static Lisp_Object CC_ctx_idl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_idl");
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
    v51 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ctx_ial */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    stack[-3] = v51;
    v51 = stack[-3];
    if (v51 == nil) goto v70;
    v51 = stack[-3];
    v51 = qcar(v51);
    v51 = qcar(v51);
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    stack[-1] = v51;
    stack[-2] = v51;
    goto v12;

v12:
    v51 = stack[-3];
    v51 = qcdr(v51);
    stack[-3] = v51;
    v51 = stack[-3];
    if (v51 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v51 = stack[-3];
    v51 = qcar(v51);
    v51 = qcar(v51);
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v51 = Lrplacd(nil, stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-1] = v51;
    goto v12;

v70:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v51); }
/* error exit handlers */
v128:
    popv(5);
    return nil;
}



/* Code for sets */

static Lisp_Object CC_sets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sets");
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
    v116 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v116 = elt(env, 2); /* "<" */
    v116 = Lprinc(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v116 = stack[0];
    v116 = Lprinc(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v116 = elt(env, 3); /* "/>" */
    v116 = Lprinc(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v193 = qvalue(elt(env, 4)); /* indent */
    v116 = (Lisp_Object)49; /* 3 */
    v116 = plus2(v193, v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    qvalue(elt(env, 4)) = v116; /* indent */
    v116 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v193 = qvalue(elt(env, 4)); /* indent */
    v116 = (Lisp_Object)49; /* 3 */
    v116 = difference2(v193, v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    qvalue(elt(env, 4)) = v116; /* indent */
    v116 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v116 = nil;
    { popv(3); return onevalue(v116); }
/* error exit handlers */
v5:
    popv(3);
    return nil;
}



/* Code for plusrd */

static Lisp_Object MS_CDECL CC_plusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "plusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plusrd");
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
    fn = elt(env, 2); /* mathml */
    v9 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    v8 = v9;
    v9 = v8;
    if (v9 == nil) goto v23;
    stack[0] = v8;
    v9 = CC_plusrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    {
        Lisp_Object v68 = stack[0];
        popv(2);
        fn = elt(env, 3); /* alg_plus */
        return (*qfn2(fn))(qenv(fn), v68, v9);
    }

v23:
    v9 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v9); }
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multerm");
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
    v116 = stack[-1];
    v193 = qcdr(v116);
    v116 = stack[0];
    v116 = qcdr(v116);
    fn = elt(env, 1); /* !*multsq */
    v116 = (*qfn2(fn))(qenv(fn), v193, v116);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    stack[-2] = v116;
    v116 = stack[-1];
    v193 = qcar(v116);
    v116 = stack[0];
    v116 = qcar(v116);
    fn = elt(env, 2); /* mulpower */
    v116 = (*qfn2(fn))(qenv(fn), v193, v116);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    {
        Lisp_Object v111 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v111, v116);
    }
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for rowdel */

static Lisp_Object CC_rowdel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v148, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rowdel");
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
    v73 = stack[0];
    fn = elt(env, 4); /* delhisto */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v148 = qvalue(elt(env, 2)); /* maxvar */
    v73 = stack[0];
    v73 = plus2(v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v143 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL)));
    v148 = (Lisp_Object)1; /* 0 */
    v73 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v143 + (CELL-TAG_VECTOR) + ((int32_t)v148/(16/CELL))) = v73;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v148 = qvalue(elt(env, 2)); /* maxvar */
    v73 = stack[0];
    v73 = plus2(v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v148 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL)));
    v73 = (Lisp_Object)65; /* 4 */
    v73 = *(Lisp_Object *)((char *)v148 + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL)));
    stack[0] = v73;
    goto v20;

v20:
    v73 = stack[0];
    if (v73 == nil) goto v192;
    v73 = stack[0];
    v73 = qcar(v73);
    v148 = v73;
    v148 = qcar(v148);
    v73 = qcdr(v73);
    v73 = qcar(v73);
    fn = elt(env, 5); /* downwght */
    v73 = (*qfn2(fn))(qenv(fn), v148, v73);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v73 = stack[0];
    v73 = qcdr(v73);
    stack[0] = v73;
    goto v20;

v192:
    v73 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v73); }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for amatch */

static Lisp_Object MS_CDECL CC_amatch(Lisp_Object env, int nargs,
                         Lisp_Object v17, Lisp_Object v79,
                         Lisp_Object v94, Lisp_Object v25, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v184, v197, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "amatch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for amatch");
#endif
    if (stack >= stacklimit)
    {
        push4(v25,v94,v79,v17);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v17,v79,v94,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v25;
    stack[-4] = v94;
    v184 = v79;
    v196 = v17;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* r */
    qvalue(elt(env, 1)) = nil; /* r */
    stack[-2] = qvalue(elt(env, 2)); /* p */
    qvalue(elt(env, 2)) = nil; /* p */
    qvalue(elt(env, 1)) = v196; /* r */
    v196 = v184;
    qvalue(elt(env, 2)) = v196; /* p */
    goto v19;

v19:
    v196 = qvalue(elt(env, 1)); /* r */
    if (!consp(v196)) goto v8;
    v196 = qvalue(elt(env, 2)); /* p */
    if (!consp(v196)) goto v4;
    v196 = qvalue(elt(env, 1)); /* r */
    v184 = qcar(v196);
    v196 = qvalue(elt(env, 2)); /* p */
    v196 = qcar(v196);
    v196 = Lneq(nil, v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    goto v51;

v51:
    if (v196 == nil) goto v2;
    v196 = qvalue(elt(env, 1)); /* r */
    fn = elt(env, 7); /* suchp */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    if (v196 == nil) goto v191;
    v196 = qvalue(elt(env, 1)); /* r */
    v196 = qcdr(v196);
    v196 = qcar(v196);
    stack[0] = v196;
    v196 = qvalue(elt(env, 1)); /* r */
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    v184 = qcar(v196);
    v196 = stack[-4];
    v196 = cons(v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    stack[-4] = v196;
    v196 = stack[0];
    qvalue(elt(env, 1)) = v196; /* r */
    goto v19;

v191:
    v196 = qvalue(elt(env, 5)); /* !*semantic */
    if (v196 == nil) goto v199;
    v197 = elt(env, 6); /* equal */
    v184 = qvalue(elt(env, 1)); /* r */
    v196 = qvalue(elt(env, 2)); /* p */
    v184 = list3(v197, v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v196 = stack[-4];
    v184 = cons(v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v196 = stack[-3];
    fn = elt(env, 8); /* resume */
    v196 = (*qfn2(fn))(qenv(fn), v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    goto v22;

v22:
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    { popv(7); return onevalue(v196); }

v199:
    v196 = qvalue(elt(env, 3)); /* nil */
    goto v22;

v2:
    v196 = qvalue(elt(env, 1)); /* r */
    stack[0] = qcar(v196);
    v196 = qvalue(elt(env, 1)); /* r */
    v196 = qcdr(v196);
    fn = elt(env, 9); /* mval */
    v198 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v196 = qvalue(elt(env, 2)); /* p */
    v197 = qcdr(v196);
    v184 = stack[-4];
    v196 = stack[-3];
    fn = elt(env, 10); /* unify */
    v196 = (*qfnn(fn))(qenv(fn), 5, stack[0], v198, v197, v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    goto v22;

v4:
    v196 = qvalue(elt(env, 4)); /* t */
    goto v51;

v8:
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v196 = qvalue(elt(env, 1)); /* r */
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 9); /* mval */
    stack[0] = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v196 = qvalue(elt(env, 2)); /* p */
    v197 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v184 = stack[-4];
    v196 = stack[-3];
    fn = elt(env, 10); /* unify */
    v196 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], v197, v184, v196);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    goto v22;
/* error exit handlers */
v160:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    popv(7);
    return nil;
}



/* Code for contposp */

static Lisp_Object CC_contposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */

v173:
    v8 = v9;
    if (v8 == nil) goto v94;
    v8 = v9;
    v8 = qcar(v8);
    if (!consp(v8)) goto v70;
    v9 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v9);

v70:
    v9 = qcdr(v9);
    goto v173;

v94:
    v9 = qvalue(elt(env, 1)); /* t */
    return onevalue(v9);
}



/* Code for !:log10 */

static Lisp_Object CC_Tlog10(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log10");
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
    v6 = elt(env, 0); /* !:log10 */
    v134 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    stack[-1] = v134;
    v6 = stack[-1];
    v134 = elt(env, 1); /* not_found */
    if (!(v6 == v134)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v6 = qvalue(elt(env, 2)); /* bften!* */
    v134 = stack[0];
    fn = elt(env, 4); /* log!: */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    stack[-1] = v134;
    v6 = elt(env, 0); /* !:log10 */
    v134 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for evaluate */

static Lisp_Object MS_CDECL CC_evaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v72, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v72 = v17;
    v132 = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*evaluateerror */
    qvalue(elt(env, 1)) = nil; /* !*evaluateerror */
    v13 = qvalue(elt(env, 2)); /* !*protfg */
    v13 = (v13 == nil ? lisp_true : nil);
    stack[-3] = v13;
    v13 = v132;
    fn = elt(env, 8); /* pair */
    v13 = (*qfn2(fn))(qenv(fn), v13, v72);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-7];
    stack[-6] = v13;
    v72 = qvalue(elt(env, 3)); /* nil */
    v13 = qvalue(elt(env, 4)); /* t */
    stack[-2] = qvalue(elt(env, 5)); /* !*msg */
    qvalue(elt(env, 5)) = v72; /* !*msg */
    stack[-1] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = v13; /* !*protfg */
    stack[0] = elt(env, 6); /* evaluate0 */
    v13 = stack[-5];
    stack[-5] = Lmkquote(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-7];
    v13 = stack[-6];
    v13 = Lmkquote(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-7];
    v132 = list3(stack[0], stack[-5], v13);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-7];
    v72 = stack[-3];
    v13 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 9); /* errorset */
    v13 = (*qfnn(fn))(qenv(fn), 3, v132, v72, v13);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-7];
    stack[0] = v13;
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    v13 = stack[0];
    if (!consp(v13)) goto v144;
    v13 = stack[0];
    v13 = qcdr(v13);
    goto v145;

v145:
    if (v13 == nil) goto v110;
    v13 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v13 == nil)) goto v3;
    v13 = elt(env, 7); /* "error during function evaluation (e.g. singularity)" 
*/
    fn = elt(env, 10); /* lprie */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-7];
    goto v3;

v3:
    v13 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-7];
    goto v110;

v110:
    v13 = stack[0];
    v13 = qcar(v13);
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    { popv(8); return onevalue(v13); }

v144:
    v13 = qvalue(elt(env, 4)); /* t */
    goto v145;
/* error exit handlers */
v191:
    env = stack[-7];
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
v103:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
}



/* Code for simppartdf */

static Lisp_Object CC_simppartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simppartdf");
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
    fn = elt(env, 1); /* partitpartdf */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v146:
    popv(1);
    return nil;
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_den_tar");
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
    v16 = v1;
    v118 = v0;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v16 = (*qfn2(fn))(qenv(fn), v118, v16);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[0];
    v118 = v16;
    v16 = v118;
    if (v16 == nil) goto v28;
    v16 = v118;
    v16 = qcdr(v16);
    if (v16 == nil) goto v136;
    v16 = v118;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v16);
    }

v136:
    v16 = v118;
    v16 = qcar(v16);
    { popv(1); return onevalue(v16); }

v28:
    v16 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v16); }
/* error exit handlers */
v52:
    popv(1);
    return nil;
}



/* Code for groeb!=rf1 */

static Lisp_Object CC_groebMrf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=rf1");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v136 = v0;
/* end of prologue */
    v183 = stack[0];
    fn = elt(env, 1); /* red_totalred */
    v183 = (*qfn2(fn))(qenv(fn), v183, v136);
    nil = C_nil;
    if (exception_pending()) goto v140;
    v136 = stack[0];
    popv(1);
    return list2(v183, v136);
/* error exit handlers */
v140:
    popv(1);
    return nil;
}



/* Code for derivative!-mod!-p!-1 */

static Lisp_Object CC_derivativeKmodKpK1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p-1");
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
    v130 = stack[-2];
    if (!consp(v130)) goto v26;
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = (consp(v130) ? nil : lisp_true);
    goto v23;

v23:
    if (v130 == nil) goto v140;
    v130 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v130); }

v140:
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = qcar(v130);
    v200 = qcar(v130);
    v130 = stack[-1];
    if (equal(v200, v130)) goto v193;
    v130 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v130); }

v193:
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = qcar(v130);
    v200 = qcdr(v130);
    v130 = (Lisp_Object)17; /* 1 */
    if (v200 == v130) goto v21;
    v130 = stack[-1];
    fn = elt(env, 3); /* fkern */
    v200 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = qcar(v130);
    v130 = qcdr(v130);
    v130 = (Lisp_Object)((int32_t)(v130) - 0x10);
    fn = elt(env, 4); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v200, v130);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v130 = stack[-2];
    v130 = qcar(v130);
    v200 = qcdr(v130);
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = qcar(v130);
    v130 = qcdr(v130);
    v130 = Lmodular_number(nil, v130);
    env = stack[-4];
    fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v200, v130);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v130 = stack[-2];
    v200 = qcdr(v130);
    v130 = stack[-1];
    v130 = CC_derivativeKmodKpK1(env, v200, v130);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    {
        Lisp_Object v45 = stack[-3];
        Lisp_Object v201 = stack[0];
        popv(5);
        fn = elt(env, 6); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v45, v201, v130);
    }

v21:
    v130 = stack[-2];
    v130 = qcar(v130);
    v130 = qcdr(v130);
    { popv(5); return onevalue(v130); }

v26:
    v130 = qvalue(elt(env, 1)); /* t */
    goto v23;
/* error exit handlers */
v47:
    popv(5);
    return nil;
}



/* Code for listeval0 */

static Lisp_Object CC_listeval0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v127, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval0");
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
    v39 = qvalue(elt(env, 1)); /* simpcount!* */
    v127 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    qvalue(elt(env, 1)) = v127; /* simpcount!* */
    v39 = qvalue(elt(env, 2)); /* simplimit!* */
    v39 = (Lisp_Object)greaterp2(v127, v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v39 = v39 ? lisp_true : nil;
    env = stack[-1];
    if (v39 == nil) goto v146;
    v39 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v39; /* simpcount!* */
    v39 = elt(env, 3); /* "Simplification recursion too deep" */
    v127 = v39;
    v39 = v127;
    qvalue(elt(env, 4)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v39 == nil)) goto v69;
    v39 = v127;
    fn = elt(env, 8); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    goto v69;

v69:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    goto v146;

v146:
    v39 = stack[0];
    if (!(symbolp(v39))) goto v116;
    v127 = stack[0];
    v39 = elt(env, 6); /* share */
    v39 = Lflagp(nil, v127, v39);
    env = stack[-1];
    if (v39 == nil) goto v192;
    v39 = stack[0];
    fn = elt(env, 9); /* eval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    v39 = CC_listeval0(env, v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    stack[0] = v39;
    goto v116;

v116:
    v39 = qvalue(elt(env, 1)); /* simpcount!* */
    v39 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    qvalue(elt(env, 1)) = v39; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v192:
    v127 = stack[0];
    v39 = elt(env, 7); /* avalue */
    v39 = get(v127, v39);
    env = stack[-1];
    v105 = v39;
    if (v39 == nil) goto v116;
    v39 = v105;
    v39 = qcdr(v39);
    v127 = qcar(v39);
    v39 = stack[0];
    if (equal(v127, v39)) goto v116;
    v39 = v105;
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = CC_listeval0(env, v39);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    stack[0] = v39;
    goto v116;
/* error exit handlers */
v191:
    popv(2);
    return nil;
}



/* Code for mksp!* */

static Lisp_Object CC_mkspH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksp*");
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
    v66 = stack[-1];
    if (v66 == nil) goto v70;
    v66 = stack[-1];
    fn = elt(env, 2); /* kernlp */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    goto v112;

v112:
    if (v66 == nil) goto v26;
    v38 = stack[-1];
    v66 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* exptf */
        return (*qfn2(fn))(qenv(fn), v38, v66);
    }

v26:
    v66 = stack[-1];
    fn = elt(env, 4); /* minusf */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    if (v66 == nil) goto v6;
    v66 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v66;
    v66 = stack[-1];
    fn = elt(env, 5); /* negf */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    stack[-1] = v66;
    goto v6;

v6:
    v66 = stack[-1];
    fn = elt(env, 6); /* fkern */
    v38 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    v66 = stack[0];
    fn = elt(env, 7); /* getpower */
    v38 = (*qfn2(fn))(qenv(fn), v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    v66 = (Lisp_Object)17; /* 1 */
    v66 = cons(v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    stack[-1] = v66;
    v66 = stack[-2];
    if (v66 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v66 = stack[0];
    v66 = Levenp(nil, v66);
    env = stack[-3];
    if (!(v66 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v66 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* negf */
        return (*qfn1(fn))(qenv(fn), v66);
    }

v70:
    v66 = qvalue(elt(env, 1)); /* t */
    goto v112;
/* error exit handlers */
v64:
    popv(4);
    return nil;
}



/* Code for aex_xtothen */

static Lisp_Object CC_aex_xtothen(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_xtothen");
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
    v129 = v1;
    v69 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ratpoly_xtothen */
    stack[0] = (*qfn2(fn))(qenv(fn), v69, v129);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    fn = elt(env, 3); /* ctx_new */
    v68 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v69 = qvalue(elt(env, 1)); /* t */
    v129 = qvalue(elt(env, 1)); /* t */
    {
        Lisp_Object v118 = stack[0];
        popv(2);
        fn = elt(env, 4); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v118, v68, v69, v129);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for bc_mkat */

static Lisp_Object CC_bc_mkat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_mkat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v1;
    v19 = v0;
/* end of prologue */
    v18 = qcar(v18);
    v135 = qvalue(elt(env, 1)); /* nil */
    return list3(v19, v18, v135);
}



/* Code for vectorml */

static Lisp_Object CC_vectorml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectorml");
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
    v15 = elt(env, 1); /* "<vector>" */
    fn = elt(env, 4); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* indent */
    v15 = (Lisp_Object)49; /* 3 */
    v15 = plus2(v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    qvalue(elt(env, 2)) = v15; /* indent */
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 5); /* multi_elem */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* indent */
    v15 = (Lisp_Object)49; /* 3 */
    v15 = difference2(v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    qvalue(elt(env, 2)) = v15; /* indent */
    v15 = elt(env, 3); /* "</vector>" */
    fn = elt(env, 4); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v15 = nil;
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for prlist */

static Lisp_Object CC_prlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prlist");
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
    v193 = nil;
    goto v25;

v25:
    v116 = stack[0];
    if (v116 == nil) goto v23;
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = Lconsp(nil, v116);
    env = stack[-1];
    if (v116 == nil) goto v118;
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = cons(v116, v193);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    v193 = v116;
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v25;

v118:
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v25;

v23:
    v116 = v193;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v116);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for a2bc */

static Lisp_Object CC_a2bc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2bc");
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
    v60 = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v110 == nil) goto v6;
    v110 = v60;
    if (!consp(v110)) goto v27;
    v110 = v60;
    v110 = qcar(v110);
    v110 = (consp(v110) ? nil : lisp_true);
    goto v70;

v70:
    if (v110 == nil) goto v26;
    {
        popv(1);
        fn = elt(env, 5); /* bcfd */
        return (*qfn1(fn))(qenv(fn), v60);
    }

v26:
    v110 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v110 == nil)) goto v69;
    v110 = elt(env, 4); /* " Invalid coefficient " */
    v60 = list2(v110, v60);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    fn = elt(env, 6); /* lprie */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    goto v69;

v69:
    v60 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v60 = nil;
    { popv(1); return onevalue(v60); }

v27:
    v110 = qvalue(elt(env, 2)); /* t */
    goto v70;

v6:
    {
        popv(1);
        fn = elt(env, 7); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for exdfprn */

static Lisp_Object CC_exdfprn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdfprn");
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
    v23 = elt(env, 1); /* "d" */
    fn = elt(env, 2); /* prin2!* */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v23 = stack[0];
    v23 = qcdr(v23);
    v23 = qcar(v23);
    {
        popv(2);
        fn = elt(env, 3); /* rembras */
        return (*qfn1(fn))(qenv(fn), v23);
    }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for !:log2 */

static Lisp_Object CC_Tlog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log2");
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
    v6 = elt(env, 0); /* !:log2 */
    v134 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    stack[-1] = v134;
    v6 = stack[-1];
    v134 = elt(env, 1); /* not_found */
    if (!(v6 == v134)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v6 = qvalue(elt(env, 2)); /* bftwo!* */
    v134 = stack[0];
    fn = elt(env, 4); /* log!: */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    stack[-1] = v134;
    v6 = elt(env, 0); /* !:log2 */
    v134 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v134 = (*qfn2(fn))(qenv(fn), v6, v134);
    nil = C_nil;
    if (exception_pending()) goto v4;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for unplus */

static Lisp_Object CC_unplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v171, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unplus");
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
    v44 = nil;
    goto v25;

v25:
    v191 = stack[-1];
    if (!consp(v191)) goto v70;
    v191 = stack[-1];
    v171 = qcar(v191);
    v191 = elt(env, 1); /* plus */
    if (v171 == v191) goto v183;
    v191 = stack[-1];
    v191 = qcar(v191);
    if (!consp(v191)) goto v24;
    v191 = stack[-1];
    v171 = qcar(v191);
    v191 = elt(env, 1); /* plus */
    v191 = Leqcar(nil, v171, v191);
    env = stack[-3];
    v191 = (v191 == nil ? lisp_true : nil);
    goto v193;

v193:
    if (v191 == nil) goto v66;
    v191 = stack[-1];
    v191 = qcar(v191);
    v171 = v44;
    v191 = cons(v191, v171);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    v44 = v191;
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v25;

v66:
    stack[-2] = v44;
    v191 = stack[-1];
    v191 = qcar(v191);
    stack[0] = qcdr(v191);
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = CC_unplus(env, v191);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    v191 = Lappend(nil, stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    {
        Lisp_Object v104 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v104, v191);
    }

v24:
    v191 = qvalue(elt(env, 2)); /* t */
    goto v193;

v183:
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v25;

v70:
    v171 = v44;
    v191 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v171, v191);
    }
/* error exit handlers */
v107:
    popv(4);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v108, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-numr");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v70;

v70:
    v108 = stack[-1];
    v65 = stack[0];
    if (equal(v108, v65)) goto v22;
    v108 = stack[-1];
    v65 = (Lisp_Object)1; /* 0 */
    if (v108 == v65) goto v20;
    v142 = elt(env, 1); /* difference */
    v108 = stack[-2];
    v65 = stack[-1];
    v65 = list3(v142, v108, v65);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    v108 = v65;
    goto v68;

v68:
    v65 = stack[-3];
    v65 = cons(v108, v65);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    stack[-3] = v65;
    v65 = stack[-1];
    v65 = add1(v65);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    stack[-1] = v65;
    goto v70;

v20:
    v65 = stack[-2];
    v108 = v65;
    goto v68;

v22:
    v65 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v65);
    }
/* error exit handlers */
v3:
    popv(5);
    return nil;
}



/* Code for fs!:prepfn!: */

static Lisp_Object CC_fsTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v79;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */
    return onevalue(v79);
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgdepends");
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

v112:
    v171 = stack[-1];
    v191 = stack[0];
    if (equal(v171, v191)) goto v26;
    v191 = stack[-1];
    if (!consp(v191)) goto v183;
    v171 = stack[-1];
    v191 = elt(env, 3); /* root_of */
    if (!consp(v171)) goto v109;
    v171 = qcar(v171);
    if (!(v171 == v191)) goto v109;
    v171 = stack[0];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    if (equal(v171, v191)) goto v24;
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcar(v191);
    stack[-1] = v191;
    goto v112;

v24:
    v191 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v191); }

v109:
    v191 = stack[-1];
    v171 = qcar(v191);
    v191 = stack[0];
    v191 = CC_solvealgdepends(env, v171, v191);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    v171 = v191;
    if (!(v191 == nil)) { popv(3); return onevalue(v171); }
    v191 = stack[-1];
    v171 = qcdr(v191);
    v191 = stack[0];
    v191 = CC_solvealgdepends(env, v171, v191);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    v171 = v191;
    if (!(v191 == nil)) { popv(3); return onevalue(v171); }
    v191 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v191); }

v183:
    v191 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v191); }

v26:
    v191 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v191); }
/* error exit handlers */
v202:
    popv(3);
    return nil;
}



/* Code for polynomcompare */

static Lisp_Object CC_polynomcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v202, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomcompare");
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
    v202 = v1;
    v185 = v0;
/* end of prologue */
    stack[-1] = v185;
    v185 = v202;
    stack[0] = v185;
    goto v27;

v27:
    v185 = stack[-1];
    v185 = qcar(v185);
    if (v185 == nil) goto v70;
    v185 = stack[0];
    v185 = qcar(v185);
    if (v185 == nil) goto v70;
    v185 = stack[-1];
    v202 = qcar(v185);
    v185 = stack[0];
    v185 = qcar(v185);
    fn = elt(env, 2); /* monomcompare */
    v185 = (*qfn2(fn))(qenv(fn), v202, v185);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v106 = v185;
    v202 = v106;
    v185 = (Lisp_Object)17; /* 1 */
    if (v202 == v185) goto v5;
    v202 = v106;
    v185 = (Lisp_Object)-15; /* -1 */
    if (v202 == v185) goto v14;
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    v185 = stack[0];
    v185 = qcdr(v185);
    stack[0] = v185;
    goto v27;

v14:
    v185 = qvalue(elt(env, 1)); /* nil */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v185;
    goto v27;

v5:
    v185 = qvalue(elt(env, 1)); /* nil */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[0] = v185;
    goto v27;

v70:
    v185 = stack[-1];
    v185 = qcar(v185);
    if (v185 == nil) goto v71;
    v185 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v185); }

v71:
    v185 = stack[0];
    v185 = qcar(v185);
    if (v185 == nil) goto v103;
    v185 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v185); }

v103:
    v185 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v185); }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for tayfkern */

static Lisp_Object CC_tayfkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayfkern");
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
    v63 = v0;
/* end of prologue */
    v11 = qvalue(elt(env, 1)); /* !*tayinternal!* */
    if (!(v11 == nil)) { popv(3); return onevalue(v63); }
    v64 = elt(env, 2); /* taylor!* */
    v11 = elt(env, 3); /* klist */
    v11 = get(v64, v11);
    env = stack[-2];
    stack[0] = v11;
    v64 = v63;
    v11 = stack[0];
    v11 = Lassoc(nil, v64, v11);
    stack[-1] = v11;
    v11 = stack[-1];
    if (!(v11 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v11 = qvalue(elt(env, 4)); /* nil */
    v11 = list2(v63, v11);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    stack[-1] = v11;
    v63 = stack[-1];
    v11 = stack[0];
    fn = elt(env, 7); /* ordad */
    v11 = (*qfn2(fn))(qenv(fn), v63, v11);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    stack[0] = v11;
    v63 = elt(env, 5); /* (taylor!*) */
    v11 = qvalue(elt(env, 6)); /* kprops!* */
    fn = elt(env, 8); /* union */
    v11 = (*qfn2(fn))(qenv(fn), v63, v11);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    qvalue(elt(env, 6)) = v11; /* kprops!* */
    v64 = elt(env, 2); /* taylor!* */
    v63 = elt(env, 3); /* klist */
    v11 = stack[0];
    v11 = Lputprop(nil, 3, v64, v63, v11);
    nil = C_nil;
    if (exception_pending()) goto v72;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for get_char_group */

static Lisp_Object CC_get_char_group(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v146;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_group");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v146 = v0;
/* end of prologue */
    v146 = qcar(v146);
    return onevalue(v146);
}



/* Code for applyfnrd */

static Lisp_Object MS_CDECL CC_applyfnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyfnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyfnrd");
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
    v9 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    stack[0] = v9;
    fn = elt(env, 3); /* stats_getargs */
    v9 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    v8 = stack[0];
    v9 = cons(v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v9);
    }
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for findelem2 */

static Lisp_Object MS_CDECL CC_findelem2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v109, v137, v138, v2;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findelem2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findelem2");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v142 = v17;
    v109 = v1;
    v137 = v0;
/* end of prologue */
    v138 = v137;
    v138 = Lconsp(nil, v138);
    env = stack[0];
    if (v138 == nil) goto v24;
    v138 = v137;
    v138 = qcar(v138);
    v2 = elt(env, 1); /* sparsemat */
    if (!(v138 == v2)) goto v24;
    v137 = qcdr(v137);
    v137 = qcar(v137);
    goto v24;

v24:
    v109 = *(Lisp_Object *)((char *)v137 + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL)));
    v142 = Latsoc(nil, v142, v109);
    v109 = v142;
    v142 = v109;
    if (v142 == nil) goto v128;
    v142 = v109;
    v142 = qcdr(v142);
    { popv(1); return onevalue(v142); }

v128:
    v142 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v142); }
}



/* Code for inszzz */

static Lisp_Object CC_inszzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzz");
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
    goto v146;

v146:
    v204 = stack[-1];
    if (v204 == nil) goto v27;
    v204 = stack[-1];
    v204 = qcar(v204);
    v205 = qcar(v204);
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = (Lisp_Object)lessp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v204 = v204 ? lisp_true : nil;
    env = stack[-4];
    goto v70;

v70:
    if (v204 == nil) goto v60;
    stack[0] = stack[-3];
    v205 = stack[-2];
    v204 = stack[-1];
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    {
        Lisp_Object v30 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v30, v204);
    }

v60:
    v204 = stack[-1];
    v204 = qcar(v204);
    v205 = qcar(v204);
    v204 = stack[-2];
    v204 = qcar(v204);
    if (equal(v205, v204)) goto v108;
    v204 = stack[-1];
    v205 = qcar(v204);
    v204 = stack[-3];
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    stack[-3] = v204;
    v204 = stack[-1];
    v204 = qcdr(v204);
    stack[-1] = v204;
    goto v146;

v108:
    v204 = stack[-1];
    v204 = qcar(v204);
    stack[0] = qcdr(v204);
    v204 = stack[-1];
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v205 = qcar(v204);
    v204 = stack[-2];
    v204 = qcdr(v204);
    v204 = qcar(v204);
    fn = elt(env, 3); /* dm!-plus */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v204 = Lrplaca(nil, stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v204 = stack[-1];
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    fn = elt(env, 4); /* zeropp */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    if (v204 == nil) goto v45;
    v205 = stack[-3];
    v204 = stack[-1];
    v204 = qcdr(v204);
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }

v45:
    v205 = stack[-3];
    v204 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }

v27:
    v204 = qvalue(elt(env, 1)); /* t */
    goto v70;
/* error exit handlers */
v29:
    popv(5);
    return nil;
}



/* Code for pterpri */

static Lisp_Object MS_CDECL CC_pterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v66, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pterpri");
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
    v147 = qvalue(elt(env, 1)); /* nil */
    v147 = Lwrs(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v147;
    v147 = qvalue(elt(env, 2)); /* !*pprinbuf!* */
    v147 = Lnreverse(nil, v147);
    env = stack[-4];
    stack[-2] = v147;
    v147 = qvalue(elt(env, 3)); /* !*outchanl!* */
    stack[-1] = v147;
    goto v70;

v70:
    v147 = stack[-1];
    if (v147 == nil) goto v112;
    v147 = stack[-1];
    v147 = qcar(v147);
    v147 = Lwrs(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v147 = stack[-2];
    stack[0] = v147;
    goto v16;

v16:
    v147 = stack[0];
    if (v147 == nil) goto v15;
    v147 = stack[0];
    v147 = qcar(v147);
    v38 = v147;
    v66 = qvalue(elt(env, 4)); /* gentranlang!* */
    v147 = elt(env, 5); /* fortran */
    if (v66 == v147) goto v133;
    v147 = v38;
    v147 = Lprinc(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    goto v141;

v141:
    v147 = stack[0];
    v147 = qcdr(v147);
    stack[0] = v147;
    goto v16;

v133:
    v147 = v38;
    fn = elt(env, 7); /* fprin2 */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    goto v141;

v15:
    v147 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v147 = stack[-1];
    v147 = qcdr(v147);
    stack[-1] = v147;
    goto v70;

v112:
    v147 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v147; /* !*posn!* */
    v147 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v147; /* !*pprinbuf!* */
    v147 = stack[-3];
    v147 = Lwrs(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v147 = nil;
    { popv(5); return onevalue(v147); }
/* error exit handlers */
v71:
    popv(5);
    return nil;
}



/* Code for getphystypeexpt */

static Lisp_Object CC_getphystypeexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeexpt");
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
    v16 = stack[0];
    fn = elt(env, 3); /* getphystypecar */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    v118 = v16;
    v16 = v118;
    if (v16 == nil) goto v26;
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    if (!(is_number(v16))) { popv(2); return onevalue(v118); }
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    v16 = Levenp(nil, v16);
    env = stack[-1];
    if (v16 == nil) { popv(2); return onevalue(v118); }
    v16 = elt(env, 2); /* scalar */
    { popv(2); return onevalue(v16); }

v26:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for contr2 */

static Lisp_Object MS_CDECL CC_contr2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contr2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v12;

v12:
    v66 = stack[-1];
    if (v66 == nil) goto v28;
    v66 = stack[0];
    if (v66 == nil) goto v21;
    v38 = stack[-2];
    v66 = stack[-1];
    v66 = qcar(v66);
    fn = elt(env, 1); /* split!-road */
    v38 = (*qfn2(fn))(qenv(fn), v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v66 = stack[-3];
    v66 = cons(v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v66;
    v66 = stack[-1];
    v66 = qcdr(v66);
    stack[-1] = v66;
    goto v12;

v21:
    stack[0] = stack[-3];
    v38 = stack[-2];
    v66 = stack[-1];
    fn = elt(env, 2); /* contr */
    v66 = (*qfn2(fn))(qenv(fn), v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    {
        Lisp_Object v13 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v13, v66);
    }

v28:
    stack[-1] = stack[-3];
    v38 = stack[-2];
    v66 = stack[0];
    fn = elt(env, 2); /* contr */
    v66 = (*qfn2(fn))(qenv(fn), v38, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    {
        Lisp_Object v72 = stack[-1];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v72, v66);
    }
/* error exit handlers */
v71:
    popv(5);
    return nil;
}



/* Code for clogsq!* */

static Lisp_Object CC_clogsqH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogsq*");
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
    v116 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*div */
    qvalue(elt(env, 1)) = nil; /* !*div */
    stack[-2] = qvalue(elt(env, 2)); /* !*combinelogs */
    qvalue(elt(env, 2)) = nil; /* !*combinelogs */
    stack[-1] = qvalue(elt(env, 3)); /* !*expandlogs */
    qvalue(elt(env, 3)) = nil; /* !*expandlogs */
    v193 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v193; /* !*expandlogs */
    qvalue(elt(env, 1)) = v193; /* !*div */
    v193 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*uncached */
    qvalue(elt(env, 5)) = v193; /* !*uncached */
    v193 = v116;
    v193 = qcar(v193);
    if (v193 == nil) goto v27;
    v193 = v116;
    v116 = elt(env, 6); /* prepf */
    fn = elt(env, 8); /* sqform */
    v116 = (*qfn2(fn))(qenv(fn), v193, v116);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    goto v70;

v70:
    fn = elt(env, 9); /* simp */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* !*uncached */
    v193 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 3)) = v193; /* !*expandlogs */
    fn = elt(env, 10); /* prepsq!* */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    fn = elt(env, 11); /* comblog */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    fn = elt(env, 12); /* simp!* */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    { popv(5); return onevalue(v116); }

v27:
    v116 = (Lisp_Object)1; /* 0 */
    goto v70;
/* error exit handlers */
v141:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    popv(5);
    return nil;
v111:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* !*uncached */
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    popv(5);
    return nil;
}



/* Code for remchkf1 */

static Lisp_Object CC_remchkf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf1");
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
    v144 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[-2] = v144;
    v50 = stack[-1];
    v49 = stack[0];
    v144 = stack[-2];
    fn = elt(env, 5); /* xremf */
    v144 = (*qfnn(fn))(qenv(fn), 3, v50, v49, v144);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[0] = v144;
    v144 = stack[0];
    if (v144 == nil) goto v68;
    v144 = stack[0];
    v144 = qcar(v144);
    stack[0] = v144;
    fn = elt(env, 4); /* termsf */
    v49 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    v144 = stack[-2];
    v144 = (Lisp_Object)geq2(v49, v144);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v144 = v144 ? lisp_true : nil;
    env = stack[-3];
    goto v69;

v69:
    if (!(v144 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v144 = qvalue(elt(env, 2)); /* !*trcompact */
    if (v144 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v144 = elt(env, 3); /* "*** Remainder smaller" */
    v144 = Lprinc(nil, v144);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    v144 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v142;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v68:
    v144 = qvalue(elt(env, 1)); /* t */
    goto v69;
/* error exit handlers */
v142:
    popv(4);
    return nil;
}



/* Code for mo!=zero */

static Lisp_Object CC_moMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v118, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v118 = v0;
/* end of prologue */

v173:
    v16 = v118;
    if (v16 == nil) goto v94;
    v16 = v118;
    v52 = qcar(v16);
    v16 = (Lisp_Object)1; /* 0 */
    if (v52 == v16) goto v70;
    v16 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v16);

v70:
    v16 = v118;
    v16 = qcdr(v16);
    v118 = v16;
    goto v173;

v94:
    v16 = qvalue(elt(env, 1)); /* t */
    return onevalue(v16);
}



/* Code for num_signsort */

static Lisp_Object CC_num_signsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num_signsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v112 = v22;
    v22 = elt(env, 1); /* lambda_lqlbvd_7 */
    {
        fn = elt(env, 2); /* ad_signsort */
        return (*qfn2(fn))(qenv(fn), v112, v22);
    }
}



/* Code for lambda_lqlbvd_7 */

static Lisp_Object CC_lambda_lqlbvd_7(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvd_7");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v1;
    v70 = v0;
/* end of prologue */
        return Lleq(nil, v70, v112);
}



/* Code for fd2q */

static Lisp_Object CC_fd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fd2q");
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

v94:
    v127 = stack[0];
    if (!consp(v127)) goto v112;
    v127 = stack[0];
    v105 = qcar(v127);
    v127 = elt(env, 1); /* !:ar!: */
    if (v105 == v127) goto v136;
    v127 = stack[0];
    v105 = qcar(v127);
    v127 = elt(env, 2); /* !:rn!: */
    if (v105 == v127) goto v52;
    v127 = stack[0];
    v127 = qcar(v127);
    v105 = qcar(v127);
    v127 = (Lisp_Object)17; /* 1 */
    v127 = cons(v105, v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v105 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v127 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v105, v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v127 = stack[0];
    v127 = qcar(v127);
    v127 = qcdr(v127);
    v127 = CC_fd2q(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v127 = stack[0];
    v127 = qcdr(v127);
    v127 = CC_fd2q(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    {
        Lisp_Object v44 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v44, v127);
    }

v52:
    v127 = stack[0];
    v127 = qcdr(v127);
    { popv(3); return onevalue(v127); }

v136:
    v127 = stack[0];
    v127 = qcdr(v127);
    stack[0] = v127;
    goto v94;

v112:
    v105 = stack[0];
    v127 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v105, v127);
/* error exit handlers */
v171:
    popv(3);
    return nil;
}



/* Code for polynomread */

static Lisp_Object CC_polynomread(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v210, v181;
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
    v121 = stack[0];
    if (v121 == nil) goto v94;
    v121 = stack[0];
    if (!consp(v121)) goto v27;
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = (consp(v121) ? nil : lisp_true);
    goto v70;

v70:
    if (v121 == nil) goto v108;
    v210 = stack[0];
    v121 = (Lisp_Object)33; /* 2 */
    v210 = Cremainder(v210, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = Leqn(nil, v210, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    if (v121 == nil) goto v145;
    fn = elt(env, 5); /* createmonomunit */
    v210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = qvalue(elt(env, 1)); /* nil */
    v181 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2star(v210, v121, v181);

v145:
    v121 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return ncons(v121);

v108:
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v210 = qcar(v121);
    v121 = qvalue(elt(env, 3)); /* fluidbibasisvariables */
    v121 = Lmember(nil, v210, v121);
    if (v121 == nil) goto v119;
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v181 = CC_polynomread(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v210 = qcar(v121);
    v121 = qvalue(elt(env, 4)); /* fluidbibasissinglevariablemonomialsa 
*/
    v121 = Lassoc(nil, v210, v121);
    v121 = qcdr(v121);
    fn = elt(env, 6); /* polynommultiplybymonom */
    stack[-1] = (*qfn2(fn))(qenv(fn), v181, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = stack[0];
    v121 = qcdr(v121);
    v121 = CC_polynomread(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    {
        Lisp_Object v194 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* polynomadd */
        return (*qfn2(fn))(qenv(fn), v194, v121);
    }

v119:
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    stack[-1] = CC_polynomread(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    fn = elt(env, 5); /* createmonomunit */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    fn = elt(env, 6); /* polynommultiplybymonom */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = stack[0];
    v121 = qcdr(v121);
    v121 = CC_polynomread(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    fn = elt(env, 7); /* polynomadd */
    v121 = (*qfn2(fn))(qenv(fn), stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v121); }

v27:
    v121 = qvalue(elt(env, 2)); /* t */
    goto v70;

v94:
    v121 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return ncons(v121);
/* error exit handlers */
v195:
    popv(3);
    return nil;
}



/* Code for giintgcd */

static Lisp_Object CC_giintgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v48, v39, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giintgcd");
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
    v48 = v1;
    v39 = v0;
/* end of prologue */

v112:
    v127 = v48;
    v143 = (Lisp_Object)17; /* 1 */
    if (v127 == v143) goto v26;
    v143 = v39;
    if (v143 == nil) { popv(2); return onevalue(v48); }
    v143 = v39;
    if (!consp(v143)) goto v15;
    v127 = v39;
    v143 = elt(env, 1); /* !:gi!: */
    if (!consp(v127)) goto v2;
    v127 = qcar(v127);
    if (!(v127 == v143)) goto v2;
    v143 = v39;
    v143 = qcdr(v143);
    stack[0] = qcar(v143);
    v143 = v39;
    v143 = qcdr(v143);
    v143 = qcdr(v143);
    v143 = Lgcd(nil, v143, v48);
    nil = C_nil;
    if (exception_pending()) goto v103;
    {
        Lisp_Object v191 = stack[0];
        popv(2);
        return Lgcd(nil, v191, v143);
    }

v2:
    v143 = v39;
    v143 = qcar(v143);
    v143 = qcdr(v143);
    stack[0] = v143;
    v143 = v39;
    v143 = qcdr(v143);
    v143 = CC_giintgcd(env, v143, v48);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v48 = v143;
    v143 = stack[0];
    v39 = v143;
    goto v112;

v15:
    v143 = v39;
        popv(2);
        return Lgcd(nil, v143, v48);

v26:
    v143 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v143); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



setup_type const u28_setup[] =
{
    {"collectphysops_reversed", too_few_2,      CC_collectphysops_reversed,wrong_no_2},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"fs:onep:",                CC_fsTonepT,    too_many_1,    wrong_no_1},
    {"pst_subpst",              too_few_2,      CC_pst_subpst, wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"ext_mult",                too_few_2,      CC_ext_mult,   wrong_no_2},
    {"fctrf1",                  CC_fctrf1,      too_many_1,    wrong_no_1},
    {"aex_0",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_0},
    {"ev_2a",                   CC_ev_2a,       too_many_1,    wrong_no_1},
    {"bvarrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bvarrd},
    {"groebcplistsortin1",      too_few_2,      CC_groebcplistsortin1,wrong_no_2},
    {"contr-strand",            too_few_2,      CC_contrKstrand,wrong_no_2},
    {"vecsimp*",                CC_vecsimpH,    too_many_1,    wrong_no_1},
    {"arminusp:",               CC_arminuspT,   too_many_1,    wrong_no_1},
    {"ofsf_facequal*",          too_few_2,      CC_ofsf_facequalH,wrong_no_2},
    {"sortedpolynomlistinsert", too_few_2,      CC_sortedpolynomlistinsert,wrong_no_2},
    {"homogp",                  CC_homogp,      too_many_1,    wrong_no_1},
    {"ratpoly_0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_0},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"findnthroot",             CC_findnthroot, too_many_1,    wrong_no_1},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"gftimesn",                too_few_2,      CC_gftimesn,   wrong_no_2},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"general-ordered-gcd-mod-p",too_few_2,     CC_generalKorderedKgcdKmodKp,wrong_no_2},
    {"assoc2",                  too_few_2,      CC_assoc2,     wrong_no_2},
    {"prepsq*0",                too_few_2,      CC_prepsqH0,   wrong_no_2},
    {"sfto_updecf",             CC_sfto_updecf, too_many_1,    wrong_no_1},
    {"ctx_idl",                 CC_ctx_idl,     too_many_1,    wrong_no_1},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {"plusrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_plusrd},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"rowdel",                  CC_rowdel,      too_many_1,    wrong_no_1},
    {"amatch",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_amatch},
    {"contposp",                CC_contposp,    too_many_1,    wrong_no_1},
    {":log10",                  CC_Tlog10,      too_many_1,    wrong_no_1},
    {"evaluate",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluate},
    {"simppartdf",              CC_simppartdf,  too_many_1,    wrong_no_1},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {"groeb=rf1",               too_few_2,      CC_groebMrf1,  wrong_no_2},
    {"derivative-mod-p-1",      too_few_2,      CC_derivativeKmodKpK1,wrong_no_2},
    {"listeval0",               CC_listeval0,   too_many_1,    wrong_no_1},
    {"mksp*",                   too_few_2,      CC_mkspH,      wrong_no_2},
    {"aex_xtothen",             too_few_2,      CC_aex_xtothen,wrong_no_2},
    {"bc_mkat",                 too_few_2,      CC_bc_mkat,    wrong_no_2},
    {"vectorml",                CC_vectorml,    too_many_1,    wrong_no_1},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"a2bc",                    CC_a2bc,        too_many_1,    wrong_no_1},
    {"exdfprn",                 CC_exdfprn,     too_many_1,    wrong_no_1},
    {":log2",                   CC_Tlog2,       too_many_1,    wrong_no_1},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"fs:prepfn:",              CC_fsTprepfnT,  too_many_1,    wrong_no_1},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"polynomcompare",          too_few_2,      CC_polynomcompare,wrong_no_2},
    {"tayfkern",                CC_tayfkern,    too_many_1,    wrong_no_1},
    {"get_char_group",          CC_get_char_group,too_many_1,  wrong_no_1},
    {"applyfnrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyfnrd},
    {"findelem2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_findelem2},
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"pterpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pterpri},
    {"getphystypeexpt",         CC_getphystypeexpt,too_many_1, wrong_no_1},
    {"contr2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2},
    {"clogsq*",                 CC_clogsqH,     too_many_1,    wrong_no_1},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"mo=zero",                 CC_moMzero,     too_many_1,    wrong_no_1},
    {"num_signsort",            CC_num_signsort,too_many_1,    wrong_no_1},
    {"lambda_lqlbvd_7",         too_few_2,      CC_lambda_lqlbvd_7,wrong_no_2},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"polynomread",             CC_polynomread, too_many_1,    wrong_no_1},
    {"giintgcd",                too_few_2,      CC_giintgcd,   wrong_no_2},
    {NULL, (one_args *)"u28", (two_args *)"19487 953273 9511730", 0}
};

/* end of generated code */
