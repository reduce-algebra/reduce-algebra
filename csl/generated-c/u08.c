
/* $destdir\u08.c        Machine generated C code */

/* Signature: 00000000 23-Oct-2012 */

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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
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


/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0130, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "scan");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scan");
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
    v0130 = qvalue(elt(env, 1)); /* cursym!* */
    v0129 = elt(env, 2); /* !*semicol!* */
    if (!(v0130 == v0129)) goto v0132;

v0133:
    fn = elt(env, 38); /* token1 */
    v0129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    goto v0132;

v0132:
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v0129)) goto v0135;
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0131 = v0129;
    v0129 = v0131;
    v0129 = (is_number(v0129) ? lisp_true : nil);
    if (!(v0129 == nil)) goto v0136;
    v0130 = v0131;
    v0129 = elt(env, 4); /* !:dn!: */
    if (!consp(v0130)) goto v0137;
    v0130 = qcar(v0130);
    if (!(v0130 == v0129)) goto v0137;
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0136;

v0136:
    v0129 = (v0129 == nil ? lisp_true : nil);
    goto v0138;

v0138:
    if (v0129 == nil) goto v0139;
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0130 = qcar(v0129);
    v0129 = elt(env, 36); /* string */
    if (!(v0130 == v0129)) goto v0140;
    v0130 = elt(env, 37); /* " " */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = Lmkquote(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    v0129 = qcdr(v0129);
    v0130 = qcar(v0129);
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    goto v0140;

v0140:
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v0129; /* cursym!* */
    fn = elt(env, 38); /* token1 */
    v0129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v0130 == v0129) goto v0141;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0142;

v0142:
    if (v0129 == nil) goto v0143;
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0143:
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (is_number(v0129)) goto v0144;
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v0129)) goto v0145;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0146;

v0146:
    if (!(v0129 == nil)) goto v0144;

v0147:
    v0129 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v0129; /* cursym!* */
    { popv(4); return onevalue(v0129); }

v0144:
    v0130 = elt(env, 37); /* " " */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    goto v0147;

v0145:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 30); /* switch!* */
    v0129 = get(v0130, v0129);
    env = stack[-3];
    v0129 = (v0129 == nil ? lisp_true : nil);
    goto v0146;

v0141:
    v0130 = qvalue(elt(env, 14)); /* ttype!* */
    v0129 = (Lisp_Object)49; /* 3 */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0142;

v0139:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 8); /* else */
    if (v0130 == v0129) goto v0148;
    v0130 = qvalue(elt(env, 1)); /* cursym!* */
    v0129 = elt(env, 2); /* !*semicol!* */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0149;

v0149:
    if (v0129 == nil) goto v0150;
    v0129 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    goto v0150;

v0150:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    goto v0151;

v0151:
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(symbolp(v0129))) goto v0140;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 10); /* newnam */
    v0129 = get(v0130, v0129);
    env = stack[-3];
    stack[-1] = v0129;
    if (v0129 == nil) goto v0152;
    v0130 = stack[-1];
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (equal(v0130, v0129)) goto v0152;
    v0129 = stack[-1];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    v0129 = stack[-1];
    v0129 = Lstringp(nil, v0129);
    env = stack[-3];
    if (!(v0129 == nil)) goto v0140;
    v0129 = stack[-1];
    if (!consp(v0129)) goto v0151;
    else goto v0140;

v0152:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 11); /* comment */
    if (v0130 == v0129) goto v0153;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 13); /* !% */
    if (v0130 == v0129) goto v0154;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0155;

v0155:
    if (v0129 == nil) goto v0156;
    v0129 = elt(env, 15); /* percent_comment */
    fn = elt(env, 40); /* read!-comment1 */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-1] = v0129;
    v0129 = qvalue(elt(env, 12)); /* !*comment */
    if (v0129 == nil) goto v0133;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0156:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 16); /* !#if */
    if (v0130 == v0129) goto v0157;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 17); /* !#else */
    if (v0130 == v0129) goto v0158;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 18); /* !#elif */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0159;

v0159:
    if (v0129 == nil) goto v0160;
    v0129 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v0129;
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    goto v0161;

v0161:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 19); /* !#endif */
    if (v0130 == v0129) goto v0162;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 16); /* !#if */
    if (v0130 == v0129) goto v0163;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 17); /* !#else */
    if (v0130 == v0129) goto v0164;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0165;

v0165:
    if (!(v0129 == nil)) goto v0133;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 18); /* !#elif */
    if (v0130 == v0129) goto v0166;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0167;

v0167:
    if (!(v0129 == nil)) goto v0157;

v0168:
    fn = elt(env, 38); /* token1 */
    v0129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    v0130 = qvalue(elt(env, 14)); /* ttype!* */
    v0129 = (Lisp_Object)49; /* 3 */
    if (v0130 == v0129) goto v0169;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0170;

v0170:
    if (v0129 == nil) goto v0161;
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0169:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 24)); /* !$eof!$ */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0170;

v0157:
    v0130 = elt(env, 21); /* " '" */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    v0130 = qvalue(elt(env, 22)); /* !*backtrace */
    v0129 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-1] = v0129;
    v0129 = stack[-1];
    if (!consp(v0129)) goto v0171;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    goto v0172;

v0172:
    if (v0129 == nil) goto v0173;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0174;

v0174:
    if (!(v0129 == nil)) goto v0133;
    v0129 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v0129;
    goto v0161;

v0173:
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    goto v0174;

v0171:
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0172;

v0166:
    v0129 = stack[-1];
    v0129 = (v0129 == nil ? lisp_true : nil);
    goto v0167;

v0164:
    v0129 = stack[-1];
    v0129 = (v0129 == nil ? lisp_true : nil);
    goto v0165;

v0163:
    v0130 = qvalue(elt(env, 7)); /* nil */
    v0129 = stack[-1];
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-1] = v0129;
    goto v0168;

v0162:
    v0129 = stack[-1];
    if (v0129 == nil) goto v0133;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    stack[-1] = v0129;
    goto v0168;

v0160:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 19); /* !#endif */
    if (v0130 == v0129) goto v0133;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 20); /* !#eval */
    if (v0130 == v0129) goto v0175;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 23); /* !#define */
    if (v0130 == v0129) goto v0176;
    v0130 = qvalue(elt(env, 14)); /* ttype!* */
    v0129 = (Lisp_Object)49; /* 3 */
    if (!(v0130 == v0129)) goto v0140;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v0130 == v0129) goto v0177;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 25); /* !' */
    if (v0130 == v0129) goto v0178;
    v0129 = qvalue(elt(env, 28)); /* !*eoldelimp */
    if (v0129 == nil) goto v0179;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 29)); /* !$eol!$ */
    if (!(v0130 == v0129)) goto v0179;

v0180:
    v0129 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 35)) = v0129; /* semic!* */
    v0129 = elt(env, 2); /* !*semicol!* */
    qvalue(elt(env, 1)) = v0129; /* cursym!* */
    { popv(4); return onevalue(v0129); }

v0179:
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = elt(env, 30); /* switch!* */
    v0129 = get(v0130, v0129);
    env = stack[-3];
    stack[-1] = v0129;
    if (v0129 == nil) goto v0140;
    v0129 = stack[-1];
    v0130 = qcdr(v0129);
    v0129 = elt(env, 2); /* !*semicol!* */
    if (!consp(v0130)) goto v0181;
    v0130 = qcar(v0130);
    if (v0130 == v0129) goto v0180;
    else goto v0181;

v0181:
    v0129 = qvalue(elt(env, 31)); /* crchar!* */
    v0129 = Lwhitespace_char_p(nil, v0129);
    env = stack[-3];
    stack[-2] = v0129;
    goto v0182;

v0182:
    fn = elt(env, 38); /* token1 */
    v0129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0129; /* nxtsym!* */
    v0130 = qvalue(elt(env, 14)); /* ttype!* */
    v0129 = (Lisp_Object)49; /* 3 */
    if (!(v0130 == v0129)) goto v0183;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v0130 == v0129) goto v0184;
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    if (v0129 == nil) goto v0183;
    v0129 = stack[-2];
    if (!(v0129 == nil)) goto v0183;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    v0129 = Latsoc(nil, v0130, v0129);
    stack[0] = v0129;
    if (v0129 == nil) goto v0183;
    v0130 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    stack[-1] = v0129;
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    if (v0129 == nil) goto v0185;
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0186;

v0186:
    if (v0129 == nil) goto v0182;
    fn = elt(env, 43); /* read!-comment */
    v0129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 34)) = v0129; /* comment!* */
    goto v0133;

v0185:
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0130 = qcar(v0129);
    v0129 = elt(env, 33); /* !*comment!* */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0186;

v0183:
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    qvalue(elt(env, 1)) = v0129; /* cursym!* */
    v0130 = qvalue(elt(env, 1)); /* cursym!* */
    v0129 = elt(env, 32); /* !*rpar!* */
    if (v0130 == v0129) goto v0143;
    v0129 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v0129; /* cursym!* */
    { popv(4); return onevalue(v0129); }

v0184:
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0178:
    v0129 = qvalue(elt(env, 26)); /* !*protfg */
    if (!(v0129 == nil)) goto v0187;
    v0129 = elt(env, 27); /* "Invalid QUOTE" */
    fn = elt(env, 44); /* lprie */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    goto v0187;

v0187:
    v0129 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    goto v0181;

v0177:
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0176:
    v0130 = elt(env, 21); /* " '" */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    v0130 = qvalue(elt(env, 22)); /* !*backtrace */
    v0129 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-1] = v0129;
    v0129 = stack[-1];
    if (!consp(v0129)) goto v0188;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    goto v0189;

v0189:
    if (!(v0129 == nil)) goto v0133;
    v0130 = elt(env, 21); /* " '" */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    v0130 = qvalue(elt(env, 22)); /* !*backtrace */
    v0129 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[0] = v0129;
    v0129 = stack[0];
    if (!consp(v0129)) goto v0190;
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    goto v0191;

v0191:
    if (!(v0129 == nil)) goto v0133;
    v0131 = stack[-1];
    v0130 = elt(env, 10); /* newnam */
    v0129 = stack[0];
    v0129 = Lputprop(nil, 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    goto v0133;

v0190:
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0191;

v0188:
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0189;

v0175:
    v0130 = elt(env, 21); /* " '" */
    v0129 = qvalue(elt(env, 9)); /* outl!* */
    v0129 = cons(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    qvalue(elt(env, 9)) = v0129; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    v0130 = qvalue(elt(env, 22)); /* !*backtrace */
    v0129 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    goto v0133;

v0158:
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0159;

v0154:
    v0130 = qvalue(elt(env, 14)); /* ttype!* */
    v0129 = (Lisp_Object)49; /* 3 */
    v0129 = (v0130 == v0129 ? lisp_true : nil);
    goto v0155;

v0153:
    v0129 = elt(env, 11); /* comment */
    fn = elt(env, 40); /* read!-comment1 */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-1] = v0129;
    v0129 = qvalue(elt(env, 12)); /* !*comment */
    if (v0129 == nil) goto v0133;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0148:
    v0129 = qvalue(elt(env, 5)); /* t */
    goto v0149;

v0137:
    v0130 = v0131;
    v0129 = elt(env, 6); /* !:int!: */
    v0129 = Leqcar(nil, v0130, v0129);
    env = stack[-3];
    goto v0136;

v0135:
    v0129 = qvalue(elt(env, 7)); /* nil */
    goto v0138;
/* error exit handlers */
v0134:
    popv(4);
    return nil;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0119;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactfmatch2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    v0195 = stack[0];
    if (!consp(v0195)) goto v0196;
    v0195 = stack[0];
    v0119 = qcar(v0195);
    v0195 = elt(env, 2); /* !~ */
    if (v0119 == v0195) goto v0151;
    v0195 = stack[0];
    v0195 = qcar(v0195);
    stack[-1] = CC_compactfmatch2(env, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    v0195 = CC_compactfmatch2(env, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    {
        Lisp_Object v0198 = stack[-1];
        popv(3);
        return Lappend(nil, v0198, v0195);
    }

v0151:
    v0195 = stack[0];
    popv(3);
    return ncons(v0195);

v0196:
    v0195 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0195); }
/* error exit handlers */
v0197:
    popv(3);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[0];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    stack[-2] = times2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0205 = qcdr(v0204);
    v0204 = stack[0];
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = times2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0205 = qcdr(v0204);
    v0204 = stack[0];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = times2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    {
        Lisp_Object v0126 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0126, v0204);
    }
/* error exit handlers */
v0206:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0209, v0210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    stack[-1] = nil;
    goto v0133;

v0133:
    v0209 = stack[0];
    if (v0209 == nil) goto v0132;
    v0209 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v0210 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    v0209 = stack[-1];
    v0209 = cons(v0210, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    stack[-1] = v0209;
    v0209 = stack[0];
    v0209 = qcdr(v0209);
    stack[0] = v0209;
    goto v0133;

v0132:
    v0209 = (Lisp_Object)1; /* 0 */
    v0210 = v0209;
    goto v0151;

v0151:
    v0209 = stack[-1];
    if (v0209 == nil) { popv(3); return onevalue(v0210); }
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = Lmax2(nil, v0209, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    v0210 = v0209;
    v0209 = stack[-1];
    v0209 = qcdr(v0209);
    stack[-1] = v0209;
    goto v0151;
/* error exit handlers */
v0211:
    popv(3);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0201, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0127 = v0192;
/* end of prologue */
    v0201 = qvalue(elt(env, 1)); /* ordering */
    v0203 = elt(env, 2); /* lex */
    if (v0201 == v0203) goto v0200;
    v0203 = v0127;
    v0203 = qcar(v0203);
    { popv(1); return onevalue(v0203); }

v0200:
    v0203 = elt(env, 3); /* plus */
    v0201 = v0127;
    v0203 = cons(v0203, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v0203);
    }
/* error exit handlers */
v0128:
    popv(1);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0220, v0221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    stack[-1] = nil;
    goto v0222;

v0222:
    v0221 = stack[0];
    v0220 = (Lisp_Object)1; /* 0 */
    v0220 = (Lisp_Object)greaterp2(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0220 = v0220 ? lisp_true : nil;
    env = stack[-4];
    if (v0220 == nil) goto v0133;
    v0221 = stack[0];
    v0220 = stack[-1];
    v0220 = cons(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    stack[-1] = v0220;
    v0220 = stack[0];
    v0220 = sub1(v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    stack[0] = v0220;
    goto v0222;

v0133:
    v0220 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    stack[-3] = v0220;
    v0220 = stack[-3];
    if (v0220 == nil) goto v0124;
    v0220 = stack[-3];
    v0220 = qcar(v0220);
    fn = elt(env, 3); /* pkp */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0220 = ncons(v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    stack[-1] = v0220;
    stack[-2] = v0220;
    goto v0138;

v0138:
    v0220 = stack[-3];
    v0220 = qcdr(v0220);
    stack[-3] = v0220;
    v0220 = stack[-3];
    if (v0220 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0220 = stack[-3];
    v0220 = qcar(v0220);
    fn = elt(env, 3); /* pkp */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0220 = ncons(v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0220 = Lrplacd(nil, stack[0], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0220 = stack[-1];
    v0220 = qcdr(v0220);
    stack[-1] = v0220;
    goto v0138;

v0124:
    v0220 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0220); }
/* error exit handlers */
v0139:
    popv(5);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0192;
/* end of prologue */
    v0224 = stack[-1];
    if (v0224 == nil) goto v0196;
    v0224 = stack[-1];
    if (!consp(v0224)) goto v0213;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0214;

v0214:
    if (v0224 == nil) goto v0226;
    v0224 = stack[-1];
    v0224 = Lmodular_number(nil, v0224);
    env = stack[-3];
    v0225 = v0224;
    v0224 = v0225;
    v0224 = (Lisp_Object)zerop(v0224);
    v0224 = v0224 ? lisp_true : nil;
    env = stack[-3];
    if (v0224 == nil) { popv(4); return onevalue(v0225); }
    v0224 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0224); }

v0226:
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    stack[-2] = qcar(v0224);
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = qcdr(v0224);
    stack[0] = CC_reduceKmodKp(env, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    v0224 = CC_reduceKmodKp(env, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    {
        Lisp_Object v0228 = stack[-2];
        Lisp_Object v0229 = stack[0];
        popv(4);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0228, v0229, v0224);
    }

v0213:
    v0224 = qvalue(elt(env, 2)); /* t */
    goto v0214;

v0196:
    v0224 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0224); }
/* error exit handlers */
v0227:
    popv(4);
    return nil;
}



/* Code for efface1 */

static Lisp_Object CC_efface1(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0207, v0124, v0120;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for efface1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0124 = v0049;
    v0120 = v0192;
/* end of prologue */
    v0198 = v0124;
    if (v0198 == nil) goto v0231;
    v0207 = v0120;
    v0198 = v0124;
    v0198 = qcar(v0198);
    if (v0207 == v0198) goto v0182;
    stack[0] = v0124;
    v0198 = v0120;
    v0207 = v0124;
    v0207 = qcdr(v0207);
    v0198 = CC_efface1(env, v0198, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    {
        Lisp_Object v0210 = stack[0];
        popv(1);
        return Lrplacd(nil, v0210, v0198);
    }

v0182:
    v0198 = v0124;
    v0198 = qcdr(v0198);
    { popv(1); return onevalue(v0198); }

v0231:
    v0198 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0198); }
/* error exit handlers */
v0209:
    popv(1);
    return nil;
}



/* Code for cdarx */

static Lisp_Object CC_cdarx(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0214, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdarx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0214 = v0192;
/* end of prologue */
    v0213 = v0214;
    v0214 = elt(env, 1); /* cdar */
    fn = elt(env, 2); /* carx */
    v0214 = (*qfn2(fn))(qenv(fn), v0213, v0214);
    errexit();
    v0214 = qcdr(v0214);
    return onevalue(v0214);
}



/* Code for ofsf_smwmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0192, Lisp_Object v0049,
                         Lisp_Object v0016, Lisp_Object v0046, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0124, v0120, v0136, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0124 = v0046;
    v0120 = v0016;
    v0136 = v0049;
    v0209 = v0192;
/* end of prologue */
    v0207 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0207 == nil) goto v0201;
    v0207 = v0209;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0207, v0136, v0120, v0124);
    }

v0201:
    v0207 = v0209;
    {
        fn = elt(env, 3); /* ofsf_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0207, v0136, v0120, v0124);
    }
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0215, v0216, v0237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0215 = v0049;
    v0216 = v0192;
/* end of prologue */
    v0237 = v0216;
    v0236 = v0215;
    if (equal(v0237, v0236)) goto v0231;
    v0237 = qvalue(elt(env, 1)); /* dmode!* */
    v0236 = elt(env, 2); /* field */
    v0236 = Lflagp(nil, v0237, v0236);
    env = stack[0];
    if (v0236 == nil) goto v0194;
    v0236 = v0216;
    {
        popv(1);
        fn = elt(env, 4); /* divd */
        return (*qfn2(fn))(qenv(fn), v0236, v0215);
    }

v0194:
    v0236 = v0216;
    if (!consp(v0236)) goto v0226;
    v0236 = v0216;
    v0236 = qcar(v0236);
    v0236 = (consp(v0236) ? nil : lisp_true);
    goto v0138;

v0138:
    if (v0236 == nil) goto v0126;
    v0236 = v0216;
    {
        popv(1);
        fn = elt(env, 5); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v0236, v0215);
    }

v0126:
    v0236 = v0216;
    {
        popv(1);
        fn = elt(env, 6); /* quotk */
        return (*qfn2(fn))(qenv(fn), v0236, v0215);
    }

v0226:
    v0236 = qvalue(elt(env, 3)); /* t */
    goto v0138;

v0231:
    v0236 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0236); }
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0251;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comfac");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0192;
/* end of prologue */
    stack[-3] = nil;
    v0251 = qvalue(elt(env, 1)); /* dmode!* */
    v0250 = elt(env, 2); /* field */
    v0250 = Lflagp(nil, v0251, v0250);
    env = stack[-4];
    if (v0250 == nil) goto v0218;
    v0250 = stack[-2];
    fn = elt(env, 6); /* lnc */
    v0251 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[-3] = v0251;
    v0250 = (Lisp_Object)17; /* 1 */
    v0250 = Lneq(nil, v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0213;

v0213:
    if (v0250 == nil) goto v0151;
    v0250 = stack[-3];
    fn = elt(env, 7); /* !:recip */
    v0251 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0250 = stack[-2];
    fn = elt(env, 8); /* multd */
    v0250 = (*qfn2(fn))(qenv(fn), v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[-2] = v0250;
    goto v0151;

v0151:
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    if (v0250 == nil) goto v0223;
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0250 = qcdr(v0250);
    stack[-3] = v0250;
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0250 = qcar(v0250);
    v0250 = qcar(v0250);
    stack[-1] = v0250;
    goto v0133;

v0133:
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    stack[-2] = v0250;
    v0251 = stack[-2];
    v0250 = stack[-1];
    fn = elt(env, 9); /* degr */
    v0251 = (*qfn2(fn))(qenv(fn), v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0250 = (Lisp_Object)1; /* 0 */
    if (v0251 == v0250) goto v0139;
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    if (v0250 == nil) goto v0252;
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0251 = qcdr(v0250);
    v0250 = stack[-3];
    fn = elt(env, 10); /* gcdf */
    v0250 = (*qfn2(fn))(qenv(fn), v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[-3] = v0250;
    goto v0133;

v0252:
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    stack[0] = qcar(v0250);
    v0251 = stack[-3];
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0250 = qcdr(v0250);
    fn = elt(env, 10); /* gcdf */
    v0250 = (*qfn2(fn))(qenv(fn), v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    {
        Lisp_Object v0253 = stack[0];
        popv(5);
        return cons(v0253, v0250);
    }

v0139:
    stack[0] = qvalue(elt(env, 3)); /* nil */
    v0250 = stack[-2];
    if (!consp(v0250)) goto v0116;
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0250 = (consp(v0250) ? nil : lisp_true);
    goto v0115;

v0115:
    if (v0250 == nil) goto v0113;
    v0250 = qvalue(elt(env, 4)); /* t */
    goto v0254;

v0254:
    if (v0250 == nil) goto v0255;
    v0251 = stack[-3];
    v0250 = stack[-2];
    fn = elt(env, 10); /* gcdf */
    v0250 = (*qfn2(fn))(qenv(fn), v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    goto v0256;

v0256:
    {
        Lisp_Object v0257 = stack[0];
        popv(5);
        return cons(v0257, v0250);
    }

v0255:
    v0250 = (Lisp_Object)17; /* 1 */
    goto v0256;

v0113:
    v0250 = qvalue(elt(env, 5)); /* !*ncmp */
    if (v0250 == nil) goto v0258;
    v0250 = stack[-1];
    fn = elt(env, 11); /* noncomp1 */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    if (v0250 == nil) goto v0258;
    v0250 = qvalue(elt(env, 5)); /* !*ncmp */
    if (v0250 == nil) goto v0111;
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    v0250 = qcar(v0250);
    v0250 = qcar(v0250);
    fn = elt(env, 11); /* noncomp1 */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0259;

v0259:
    v0250 = (v0250 == nil ? lisp_true : nil);
    goto v0254;

v0111:
    v0250 = qvalue(elt(env, 3)); /* nil */
    goto v0259;

v0258:
    v0250 = qvalue(elt(env, 3)); /* nil */
    goto v0259;

v0116:
    v0250 = qvalue(elt(env, 4)); /* t */
    goto v0115;

v0223:
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    { popv(5); return onevalue(v0250); }

v0218:
    v0250 = qvalue(elt(env, 3)); /* nil */
    goto v0213;
/* error exit handlers */
v0156:
    popv(5);
    return nil;
}



/* Code for exceeds!-order */

static Lisp_Object CC_exceedsKorder(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */

v0261:
    v0137 = stack[-1];
    if (v0137 == nil) goto v0231;
    v0137 = stack[0];
    v0137 = qcar(v0137);
    stack[-2] = v0137;
    v0137 = (Lisp_Object)1; /* 0 */
    v0236 = v0137;
    goto v0262;

v0262:
    v0137 = stack[-2];
    if (v0137 == nil) goto v0193;
    v0137 = stack[-2];
    v0137 = qcar(v0137);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0137 = (*qfn2(fn))(qenv(fn), v0137, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0236 = v0137;
    v0137 = stack[-2];
    v0137 = qcdr(v0137);
    stack[-2] = v0137;
    goto v0262;

v0193:
    v0137 = v0236;
    v0236 = v0137;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    fn = elt(env, 4); /* tayexp!-lessp */
    v0137 = (*qfn2(fn))(qenv(fn), v0236, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    if (v0137 == nil) goto v0222;
    v0137 = stack[-1];
    v0236 = qcdr(v0137);
    v0137 = stack[0];
    v0137 = qcdr(v0137);
    stack[-1] = v0236;
    stack[0] = v0137;
    goto v0261;

v0222:
    v0137 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0137); }

v0231:
    v0137 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0137); }
/* error exit handlers */
v0122:
    popv(4);
    return nil;
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0230, v0193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */

v0196:
    v0230 = stack[0];
    if (!consp(v0230)) goto v0132;
    v0230 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0193 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-1];
    v0230 = elt(env, 1); /* (ladd radd) */
    v0230 = Lmemq(nil, v0193, v0230);
    if (v0230 == nil) goto v0235;
    v0230 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0230 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-1];
    stack[0] = v0230;
    goto v0196;

v0235:
    v0230 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0230 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-1];
    v0230 = CC_qqe_numberKofKtailsKinKqterm(env, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    popv(2);
    return add1(v0230);

v0132:
    v0230 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0230); }
/* error exit handlers */
v0217:
    popv(2);
    return nil;
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susibin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0143 = v0049;
    v0219 = v0192;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v0143 = list2(v0219, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-1];
    {
        Lisp_Object v0232 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0232, v0143);
    }
/* error exit handlers */
v0212:
    popv(2);
    return nil;
}



/* Code for ratpoly_idl */

static Lisp_Object CC_ratpoly_idl(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0231 = v0192;
/* end of prologue */
    v0231 = qcar(v0231);
    {
        fn = elt(env, 1); /* sf_idl */
        return (*qfn1(fn))(qenv(fn), v0231);
    }
}



/* Code for objectom */

static Lisp_Object CC_objectom(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0223, v0121, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for objectom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0121 = v0192;
/* end of prologue */
    v0223 = v0121;
    v0223 = Lconsp(nil, v0223);
    env = stack[-1];
    if (v0223 == nil) goto v0120;
    v0223 = v0121;
    v0211 = qcar(v0223);
    v0223 = qvalue(elt(env, 1)); /* ir2mml!* */
    v0223 = Lassoc(nil, v0211, v0223);
    v0211 = v0223;
    if (v0223 == nil) goto v0226;
    v0223 = v0211;
    v0223 = qcdr(v0223);
    v0223 = qcdr(v0223);
    v0223 = qcdr(v0223);
    stack[0] = qcar(v0223);
    v0223 = v0121;
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-1];
    fn = elt(env, 3); /* apply */
    v0223 = (*qfn2(fn))(qenv(fn), stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0133;

v0133:
    v0223 = nil;
    { popv(2); return onevalue(v0223); }

v0226:
    v0223 = v0121;
    fn = elt(env, 4); /* fnom */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0133;

v0120:
    v0223 = v0121;
    fn = elt(env, 5); /* basicom */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0133;
/* error exit handlers */
v0199:
    popv(2);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0260, v0199, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0199 = v0192;
/* end of prologue */
    v0260 = v0199;
    if (!consp(v0260)) goto v0151;
    v0260 = v0199;
    v0204 = qcar(v0260);
    v0260 = elt(env, 2); /* !:ps!: */
    if (v0204 == v0260) goto v0119;
    v0260 = v0199;
    v0204 = qcar(v0260);
    v0260 = elt(env, 3); /* dname */
    v0260 = get(v0204, v0260);
    env = stack[0];
    goto v0132;

v0132:
    if (!(v0260 == nil)) { popv(1); return onevalue(v0199); }
    v0260 = (Lisp_Object)97; /* 6 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0199, v0260);
    }

v0119:
    v0260 = qvalue(elt(env, 4)); /* nil */
    goto v0132;

v0151:
    v0260 = qvalue(elt(env, 1)); /* t */
    goto v0132;
}



/* Code for rd!:prep */

static Lisp_Object CC_rdTprep(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    v0224 = qvalue(elt(env, 1)); /* !*noconvert */
    if (v0224 == nil) goto v0231;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    if (!consp(v0224)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0225 = stack[0];
    v0224 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(2);
        fn = elt(env, 3); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0225, v0224);
    }

v0231:
    v0224 = stack[0];
    fn = elt(env, 4); /* rd!:onep */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    if (v0224 == nil) goto v0262;
    v0224 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0224); }

v0262:
    v0224 = stack[0];
    fn = elt(env, 5); /* rd!:minus */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    fn = elt(env, 4); /* rd!:onep */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    if (v0224 == nil) goto v0119;
    v0224 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v0224); }

v0119:
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    if (!consp(v0224)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0225 = stack[0];
    v0224 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(2);
        fn = elt(env, 3); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0225, v0224);
    }
/* error exit handlers */
v0126:
    popv(2);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0192, Lisp_Object v0049,
                         Lisp_Object v0016, Lisp_Object v0046, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0056, v0305, v0306, v0307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0046,v0016,v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0192,v0049,v0016,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0016;
    stack[-2] = v0049;
    stack[-3] = v0192;
/* end of prologue */
    stack[-4] = nil;
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0127;
    v0056 = stack[-1];
    v0057 = elt(env, 1); /* sparsemat */
    if (!consp(v0056)) goto v0308;
    v0056 = qcar(v0056);
    if (!(v0056 == v0057)) goto v0308;
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    fn = elt(env, 12); /* revlis */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    stack[-4] = v0057;
    fn = elt(env, 13); /* numlis */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    if (v0057 == nil) goto v0310;
    v0057 = stack[-4];
    v0056 = Llength(nil, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0057 = (Lisp_Object)33; /* 2 */
    v0057 = Lneq(nil, v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    goto v0311;

v0311:
    if (v0057 == nil) goto v0312;
    v0307 = elt(env, 7); /* "Syntax error:" */
    v0306 = stack[-3];
    v0305 = elt(env, 8); /* "invalid" */
    v0056 = qvalue(elt(env, 9)); /* nil */
    v0057 = elt(env, 10); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0307, v0306, v0305, v0056, v0057);
    }

v0312:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0057 = stack[-4];
    v0057 = qcar(v0057);
    v0057 = *(Lisp_Object *)((char *)v0056 + (CELL-TAG_VECTOR) + ((int32_t)v0057/(16/CELL)));
    v0306 = v0057;
    v0057 = v0306;
    if (v0057 == nil) goto v0095;
    v0057 = stack[-4];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0057 = v0306;
    v0057 = Latsoc(nil, v0056, v0057);
    v0305 = v0057;
    v0057 = v0305;
    if (v0057 == nil) goto v0313;
    v0056 = stack[-2];
    v0057 = (Lisp_Object)1; /* 0 */
    if (v0056 == v0057) goto v0314;
    v0057 = qvalue(elt(env, 9)); /* nil */
    goto v0315;

v0315:
    if (v0057 == nil) goto v0059;
    v0057 = v0306;
    v0057 = qcdr(v0057);
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0316;
    stack[0] = v0306;
    v0057 = v0305;
    v0056 = v0306;
    v0057 = Ldelete(nil, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0057 = qcdr(v0057);
    v0057 = Lrplacd(nil, stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    goto v0140;

v0140:
    v0057 = nil;
    { popv(6); return onevalue(v0057); }

v0316:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0057 = stack[-4];
    v0057 = qcar(v0057);
    v0305 = qvalue(elt(env, 9)); /* nil */
    *(Lisp_Object *)((char *)v0056 + (CELL-TAG_VECTOR) + ((int32_t)v0057/(16/CELL))) = v0305;
    goto v0140;

v0059:
    v0056 = v0305;
    v0057 = stack[-2];
    v0057 = Lrplacd(nil, v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    goto v0140;

v0314:
    v0056 = stack[0];
    v0057 = elt(env, 11); /* cx */
    v0057 = (v0056 == v0057 ? lisp_true : nil);
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0315;

v0313:
    v0056 = stack[-2];
    v0057 = (Lisp_Object)1; /* 0 */
    if (v0056 == v0057) goto v0317;
    v0057 = qvalue(elt(env, 9)); /* nil */
    goto v0188;

v0188:
    if (!(v0057 == nil)) goto v0140;
    v0057 = stack[-4];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0305 = v0306;
    v0057 = stack[-2];
    fn = elt(env, 15); /* sortcolelem */
    v0057 = (*qfnn(fn))(qenv(fn), 3, v0056, v0305, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    goto v0140;

v0317:
    v0056 = stack[0];
    v0057 = elt(env, 11); /* cx */
    v0057 = (v0056 == v0057 ? lisp_true : nil);
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0188;

v0095:
    v0056 = stack[-2];
    v0057 = (Lisp_Object)1; /* 0 */
    if (v0056 == v0057) goto v0318;
    v0057 = qvalue(elt(env, 9)); /* nil */
    goto v0319;

v0319:
    if (!(v0057 == nil)) goto v0140;
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-3] = qcar(v0057);
    v0057 = stack[-4];
    stack[-1] = qcar(v0057);
    v0057 = qvalue(elt(env, 9)); /* nil */
    stack[0] = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0057 = stack[-4];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0057 = stack[-2];
    v0057 = cons(v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0057 = list2(stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0057;
    goto v0140;

v0318:
    v0056 = stack[0];
    v0057 = elt(env, 11); /* cx */
    v0057 = (v0056 == v0057 ? lisp_true : nil);
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0319;

v0310:
    v0057 = qvalue(elt(env, 6)); /* t */
    goto v0311;

v0308:
    v0305 = elt(env, 2); /* "Matrix" */
    v0057 = stack[-3];
    v0056 = qcar(v0057);
    v0057 = elt(env, 3); /* "not set" */
    v0057 = list3(v0305, v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0056 = v0057;
    v0057 = v0056;
    qvalue(elt(env, 4)) = v0057; /* errmsg!* */
    v0057 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0057 == nil)) goto v0320;
    v0057 = v0056;
    fn = elt(env, 16); /* lprie */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    goto v0320;

v0320:
    v0057 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    goto v0312;

v0127:
    v0056 = stack[-1];
    v0057 = elt(env, 1); /* sparsemat */
    if (!consp(v0056)) goto v0138;
    v0056 = qcar(v0056);
    if (!(v0056 == v0057)) goto v0138;
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    fn = elt(env, 12); /* revlis */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    stack[-4] = v0057;
    fn = elt(env, 13); /* numlis */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    if (v0057 == nil) goto v0137;
    v0057 = stack[-4];
    v0056 = Llength(nil, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0057 = (Lisp_Object)17; /* 1 */
    v0057 = Lneq(nil, v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    goto v0233;

v0233:
    if (v0057 == nil) goto v0321;
    v0307 = elt(env, 7); /* "Syntax error:" */
    v0306 = stack[-3];
    v0305 = elt(env, 8); /* "invalid" */
    v0056 = qvalue(elt(env, 9)); /* nil */
    v0057 = elt(env, 10); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0307, v0306, v0305, v0056, v0057);
    }

v0321:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    v0305 = qcar(v0057);
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    v0056 = qcar(v0057);
    v0057 = stack[-2];
    *(Lisp_Object *)((char *)v0305 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL))) = v0057;
    goto v0140;

v0137:
    v0057 = qvalue(elt(env, 6)); /* t */
    goto v0233;

v0138:
    v0305 = elt(env, 2); /* "Matrix" */
    v0057 = stack[-3];
    v0056 = qcar(v0057);
    v0057 = elt(env, 3); /* "not set" */
    v0057 = list3(v0305, v0056, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    v0056 = v0057;
    v0057 = v0056;
    qvalue(elt(env, 4)) = v0057; /* errmsg!* */
    v0057 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0057 == nil)) goto v0205;
    v0057 = v0056;
    fn = elt(env, 16); /* lprie */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-5];
    goto v0205;

v0205:
    v0057 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    goto v0321;
/* error exit handlers */
v0309:
    popv(6);
    return nil;
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypesf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */

v0261:
    v0193 = stack[0];
    if (v0193 == nil) goto v0151;
    v0193 = stack[0];
    fn = elt(env, 3); /* domain!*p */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-1];
    goto v0132;

v0132:
    if (v0193 == nil) goto v0140;
    v0193 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0193); }

v0140:
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    fn = elt(env, 4); /* getphystype */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-1];
    if (!(v0193 == nil)) { popv(2); return onevalue(v0193); }
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = qcdr(v0193);
    stack[0] = v0193;
    goto v0261;

v0151:
    v0193 = qvalue(elt(env, 1)); /* t */
    goto v0132;
/* error exit handlers */
v0217:
    popv(2);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0327, v0328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0049;
    stack[-2] = v0192;
/* end of prologue */
    stack[-3] = nil;
    goto v0133;

v0133:
    v0327 = stack[-1];
    if (v0327 == nil) goto v0182;
    v0327 = stack[-2];
    if (v0327 == nil) goto v0227;
    v0327 = stack[-2];
    if (!consp(v0327)) goto v0122;
    v0327 = stack[-2];
    v0327 = qcar(v0327);
    v0327 = (consp(v0327) ? nil : lisp_true);
    goto v0237;

v0237:
    if (v0327 == nil) goto v0115;
    stack[0] = stack[-3];
    v0328 = stack[-2];
    v0327 = stack[-1];
    fn = elt(env, 6); /* divdm */
    v0327 = (*qfn2(fn))(qenv(fn), v0328, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    {
        Lisp_Object v0300 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0300, v0327);
    }

v0115:
    v0327 = stack[-2];
    v0327 = qcar(v0327);
    stack[0] = qcar(v0327);
    v0327 = stack[-2];
    v0327 = qcar(v0327);
    v0328 = qcdr(v0327);
    v0327 = stack[-1];
    v0328 = CC_divd(env, v0328, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    v0327 = stack[-3];
    v0327 = acons(stack[0], v0328, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    stack[-3] = v0327;
    v0327 = stack[-2];
    v0327 = qcdr(v0327);
    stack[-2] = v0327;
    goto v0133;

v0122:
    v0327 = qvalue(elt(env, 5)); /* t */
    goto v0237;

v0227:
    v0327 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0327);
    }

v0182:
    v0327 = stack[-2];
    if (v0327 == nil) goto v0143;
    stack[0] = stack[-3];
    v0327 = elt(env, 4); /* "Zero divisor" */
    v0328 = v0327;
    v0327 = v0328;
    qvalue(elt(env, 2)) = v0327; /* errmsg!* */
    v0327 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0327 == nil)) goto v0205;
    v0327 = v0328;
    fn = elt(env, 8); /* lprie */
    v0327 = (*qfn1(fn))(qenv(fn), v0327);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    goto v0205;

v0205:
    v0327 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    v0327 = nil;
    {
        Lisp_Object v0299 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0299, v0327);
    }

v0143:
    stack[0] = stack[-3];
    v0327 = elt(env, 1); /* "0/0 formed" */
    v0328 = v0327;
    v0327 = v0328;
    qvalue(elt(env, 2)) = v0327; /* errmsg!* */
    v0327 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0327 == nil)) goto v0230;
    v0327 = v0328;
    fn = elt(env, 8); /* lprie */
    v0327 = (*qfn1(fn))(qenv(fn), v0327);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    goto v0230;

v0230:
    v0327 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-4];
    v0327 = nil;
    {
        Lisp_Object v0330 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0330, v0327);
    }
/* error exit handlers */
v0329:
    popv(5);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0106, v0244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_sum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */

v0261:
    v0107 = stack[-1];
    if (v0107 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0107 = stack[0];
    if (v0107 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0107 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    v0107 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v0107 = (*qfn2(fn))(qenv(fn), stack[-2], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    v0244 = v0107;
    v0106 = v0244;
    v0107 = (Lisp_Object)17; /* 1 */
    if (v0106 == v0107) goto v0124;
    v0106 = v0244;
    v0107 = (Lisp_Object)-15; /* -1 */
    if (v0106 == v0107) goto v0123;
    v0107 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    v0107 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v0107 = (*qfn2(fn))(qenv(fn), stack[-2], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    stack[-2] = v0107;
    v0107 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    if (v0107 == nil) goto v0111;
    v0107 = stack[-1];
    v0106 = qcdr(v0107);
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    stack[-1] = v0106;
    stack[0] = v0107;
    goto v0261;

v0111:
    v0107 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-3];
    v0107 = stack[-1];
    v0106 = qcdr(v0107);
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    v0107 = CC_dp_sum(env, v0106, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    {
        Lisp_Object v0332 = stack[-2];
        popv(4);
        return cons(v0332, v0107);
    }

v0123:
    v0107 = stack[0];
    stack[-2] = qcar(v0107);
    v0106 = stack[-1];
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    v0107 = CC_dp_sum(env, v0106, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    {
        Lisp_Object v0333 = stack[-2];
        popv(4);
        return cons(v0333, v0107);
    }

v0124:
    v0107 = stack[-1];
    stack[-2] = qcar(v0107);
    v0107 = stack[-1];
    v0106 = qcdr(v0107);
    v0107 = stack[0];
    v0107 = CC_dp_sum(env, v0106, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    {
        Lisp_Object v0334 = stack[-2];
        popv(4);
        return cons(v0334, v0107);
    }
/* error exit handlers */
v0320:
    popv(4);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0114 = v0049;
    stack[-4] = v0192;
/* end of prologue */
    stack[-5] = v0114;
    v0114 = stack[-5];
    if (v0114 == nil) goto v0222;
    v0114 = stack[-5];
    v0114 = qcar(v0114);
    v0149 = v0114;
    stack[0] = qcar(v0149);
    v0149 = stack[-4];
    v0114 = qcdr(v0114);
    fn = elt(env, 2); /* pappl0 */
    v0114 = (*qfn2(fn))(qenv(fn), v0149, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    stack[-2] = v0114;
    stack[-3] = v0114;
    goto v0182;

v0182:
    v0114 = stack[-5];
    v0114 = qcdr(v0114);
    stack[-5] = v0114;
    v0114 = stack[-5];
    if (v0114 == nil) goto v0120;
    stack[-1] = stack[-2];
    v0114 = stack[-5];
    v0114 = qcar(v0114);
    v0149 = v0114;
    stack[0] = qcar(v0149);
    v0149 = stack[-4];
    v0114 = qcdr(v0114);
    fn = elt(env, 2); /* pappl0 */
    v0114 = (*qfn2(fn))(qenv(fn), v0149, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = Lrplacd(nil, stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-6];
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-2] = v0114;
    goto v0182;

v0120:
    v0114 = stack[-3];
    goto v0151;

v0151:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0114);
    }

v0222:
    v0114 = qvalue(elt(env, 1)); /* nil */
    goto v0151;
/* error exit handlers */
v0326:
    popv(7);
    return nil;
}



/* Code for raiseind!: */

static Lisp_Object CC_raiseindT(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0222, v0180;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raiseind:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0222 = v0192;
/* end of prologue */
    v0180 = v0222;
    if (!consp(v0180)) return onevalue(v0222);
    v0222 = qcdr(v0222);
    v0222 = qcar(v0222);
    return onevalue(v0222);
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0350, v0351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0049;
    stack[-3] = v0192;
/* end of prologue */
    stack[0] = nil;
    goto v0133;

v0133:
    v0350 = stack[-3];
    if (v0350 == nil) goto v0222;
    v0350 = stack[-2];
    if (v0350 == nil) goto v0235;
    v0350 = stack[-3];
    if (!consp(v0350)) goto v0119;
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0350 = (consp(v0350) ? nil : lisp_true);
    goto v0195;

v0195:
    if (v0350 == nil) goto v0218;
    v0350 = stack[-2];
    if (!consp(v0350)) goto v0199;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = (consp(v0350) ? nil : lisp_true);
    goto v0260;

v0260:
    if (v0350 == nil) goto v0352;
    v0351 = stack[-3];
    v0350 = stack[-2];
    fn = elt(env, 3); /* general!-modular!-plus */
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0351 = v0350;
    v0350 = v0351;
    v0350 = (Lisp_Object)zerop(v0350);
    v0350 = v0350 ? lisp_true : nil;
    env = stack[-5];
    if (v0350 == nil) goto v0331;
    v0350 = qvalue(elt(env, 2)); /* nil */
    goto v0137;

v0137:
    {
        Lisp_Object v0082 = stack[0];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0082, v0350);
    }

v0331:
    v0350 = v0351;
    goto v0137;

v0352:
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = stack[0];
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    stack[0] = v0350;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    stack[-2] = v0350;
    goto v0133;

v0199:
    v0350 = qvalue(elt(env, 1)); /* t */
    goto v0260;

v0218:
    v0350 = stack[-2];
    if (!consp(v0350)) goto v0353;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = (consp(v0350) ? nil : lisp_true);
    goto v0354;

v0354:
    if (v0350 == nil) goto v0329;
    v0350 = stack[-3];
    v0351 = qcar(v0350);
    v0350 = stack[0];
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    stack[0] = v0350;
    v0350 = stack[-3];
    v0350 = qcdr(v0350);
    stack[-3] = v0350;
    goto v0133;

v0329:
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0351 = qcar(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    if (equal(v0351, v0350)) goto v0355;
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0351 = qcar(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    if (equal(v0351, v0350)) goto v0094;
    v0350 = qvalue(elt(env, 2)); /* nil */
    goto v0239;

v0239:
    if (!(v0350 == nil)) goto v0284;
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0351 = qcar(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    if (equal(v0351, v0350)) goto v0356;
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0351 = qcar(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    fn = elt(env, 5); /* ordop */
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    goto v0095;

v0095:
    if (!(v0350 == nil)) goto v0284;
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = stack[0];
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    stack[0] = v0350;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    stack[-2] = v0350;
    goto v0133;

v0284:
    v0350 = stack[-3];
    v0351 = qcar(v0350);
    v0350 = stack[0];
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    stack[0] = v0350;
    v0350 = stack[-3];
    v0350 = qcdr(v0350);
    stack[-3] = v0350;
    goto v0133;

v0356:
    v0350 = qvalue(elt(env, 2)); /* nil */
    goto v0095;

v0094:
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0351 = qcdr(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcar(v0350);
    v0350 = qcdr(v0350);
    v0350 = ((intptr_t)v0351 > (intptr_t)v0350) ? lisp_true : nil;
    goto v0239;

v0355:
    stack[-4] = stack[0];
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    stack[-1] = qcar(v0350);
    v0350 = stack[-3];
    v0350 = qcar(v0350);
    v0351 = qcdr(v0350);
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0350 = qcdr(v0350);
    stack[0] = CC_generalKplusKmodKp(env, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0350 = stack[-3];
    v0351 = qcdr(v0350);
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = CC_generalKplusKmodKp(env, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    fn = elt(env, 6); /* adjoin!-term */
    v0350 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0350);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    {
        Lisp_Object v0080 = stack[-4];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0080, v0350);
    }

v0353:
    v0350 = qvalue(elt(env, 1)); /* t */
    goto v0354;

v0119:
    v0350 = qvalue(elt(env, 1)); /* t */
    goto v0195;

v0235:
    v0351 = stack[0];
    v0350 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0351, v0350);
    }

v0222:
    v0351 = stack[0];
    v0350 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0351, v0350);
    }
/* error exit handlers */
v0081:
    popv(6);
    return nil;
}



/* Code for chknewnam */

static Lisp_Object CC_chknewnam(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0120, v0136, v0209;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chknewnam");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0136 = v0192;
/* end of prologue */

v0180:
    v0120 = v0136;
    v0124 = elt(env, 1); /* newnam */
    v0124 = get(v0120, v0124);
    env = stack[0];
    v0209 = v0124;
    if (v0124 == nil) goto v0214;
    v0120 = v0209;
    v0124 = v0136;
    v0124 = (v0120 == v0124 ? lisp_true : nil);
    goto v0183;

v0183:
    if (!(v0124 == nil)) { popv(1); return onevalue(v0136); }
    v0124 = v0209;
    if (!(symbolp(v0124))) { popv(1); return onevalue(v0209); }
    v0124 = v0209;
    v0136 = v0124;
    goto v0180;

v0214:
    v0124 = qvalue(elt(env, 2)); /* t */
    goto v0183;
}



/* Code for processcarpartitie1 */

static Lisp_Object MS_CDECL CC_processcarpartitie1(Lisp_Object env, int nargs,
                         Lisp_Object v0192, Lisp_Object v0049,
                         Lisp_Object v0016, Lisp_Object v0046,
                         Lisp_Object v0196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205, v0234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "processcarpartitie1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processcarpartitie1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0196,v0046,v0016,v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0192,v0049,v0016,v0046,v0196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0196;
    stack[-4] = v0046;
    stack[-5] = v0016;
    v0204 = v0049;
    stack[-6] = v0192;
/* end of prologue */

v0182:
    v0205 = v0204;
    if (v0205 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v0205 = v0204;
    v0205 = qcdr(v0205);
    stack[-7] = v0205;
    stack[-2] = stack[-5];
    stack[-1] = stack[-6];
    stack[0] = v0204;
    v0205 = stack[-4];
    v0234 = qcar(v0205);
    v0205 = qcar(v0204);
    v0204 = stack[-4];
    v0204 = qcdr(v0204);
    v0205 = list2star(v0234, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-8];
    v0204 = stack[-3];
    fn = elt(env, 1); /* processpartitie1 */
    v0204 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-8];
    stack[-3] = v0204;
    v0204 = stack[-7];
    goto v0182;
/* error exit handlers */
v0233:
    popv(9);
    return nil;
}



/* Code for totallessp */

static Lisp_Object CC_totallessp(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totallessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0143 = v0049;
    v0219 = v0192;
/* end of prologue */
    fn = elt(env, 2); /* totalcompare */
    v0143 = (*qfn2(fn))(qenv(fn), v0219, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[0];
    v0219 = elt(env, 1); /* less */
    v0143 = (v0143 == v0219 ? lisp_true : nil);
    { popv(1); return onevalue(v0143); }
/* error exit handlers */
v0208:
    popv(1);
    return nil;
}



/* Code for pasf_deci */

static Lisp_Object CC_pasf_deci(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0201, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_deci");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0203 = v0192;
/* end of prologue */
    fn = elt(env, 1); /* pasf_dec */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    errexit();
    v0127 = v0203;
    v0203 = v0127;
    v0201 = qcar(v0203);
    v0203 = v0127;
    v0203 = qcdr(v0203);
    if (v0203 == nil) goto v0140;
    v0203 = v0127;
    v0203 = qcdr(v0203);
    goto v0214;

v0214:
    return cons(v0201, v0203);

v0140:
    v0203 = (Lisp_Object)1; /* 0 */
    goto v0214;
}



/* Code for ibalp_litp */

static Lisp_Object CC_ibalp_litp(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    v0195 = stack[0];
    fn = elt(env, 3); /* ibalp_atomp */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-1];
    if (!(v0195 == nil)) { popv(2); return onevalue(v0195); }
    v0195 = stack[0];
    if (!consp(v0195)) goto v0143;
    v0195 = stack[0];
    v0195 = qcar(v0195);
    v0119 = v0195;
    goto v0222;

v0222:
    v0195 = elt(env, 1); /* not */
    if (v0119 == v0195) goto v0182;
    v0195 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0195); }

v0182:
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    {
        popv(2);
        fn = elt(env, 3); /* ibalp_atomp */
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0143:
    v0195 = stack[0];
    v0119 = v0195;
    goto v0222;
/* error exit handlers */
v0226:
    popv(2);
    return nil;
}



/* Code for dfn_prop */

static Lisp_Object CC_dfn_prop(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0211, v0260, v0199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfn_prop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0211 = v0192;
/* end of prologue */
    v0211 = qcdr(v0211);
    v0211 = Llength(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[0];
    v0199 = v0211;
    v0260 = v0199;
    v0211 = (Lisp_Object)17; /* 1 */
    if (v0260 == v0211) goto v0151;
    v0260 = v0199;
    v0211 = (Lisp_Object)33; /* 2 */
    if (v0260 == v0211) goto v0143;
    v0260 = v0199;
    v0211 = (Lisp_Object)49; /* 3 */
    if (v0260 == v0211) goto v0127;
    v0211 = elt(env, 1); /* dfn */
    v0260 = v0199;
    {
        popv(1);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v0211, v0260);
    }

v0127:
    v0211 = elt(env, 3); /* dfn3 */
    { popv(1); return onevalue(v0211); }

v0143:
    v0211 = elt(env, 2); /* dfn2 */
    { popv(1); return onevalue(v0211); }

v0151:
    v0211 = elt(env, 1); /* dfn */
    { popv(1); return onevalue(v0211); }
/* error exit handlers */
v0204:
    popv(1);
    return nil;
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0325, v0322, v0358, v0359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcpcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */
    v0325 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0325 == nil) goto v0112;
    v0325 = stack[-1];
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0322 = qcar(v0325);
    v0325 = stack[0];
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0325 = qcar(v0325);
    stack[-2] = difference2(v0322, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0325 = stack[-1];
    v0322 = qcar(v0325);
    v0325 = stack[0];
    v0325 = qcar(v0325);
    fn = elt(env, 3); /* vevcomp */
    v0325 = (*qfn2(fn))(qenv(fn), v0322, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0359 = stack[-2];
    v0358 = v0325;
    v0322 = v0359;
    v0325 = (Lisp_Object)1; /* 0 */
    if (v0322 == v0325) goto v0126;
    v0322 = v0359;
    v0325 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0322, v0325);

v0126:
    v0322 = v0358;
    v0325 = (Lisp_Object)1; /* 0 */
    if (v0322 == v0325) goto v0360;
    v0322 = v0358;
    v0325 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0322, v0325);

v0360:
    v0325 = stack[-1];
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0322 = qcar(v0325);
    v0325 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0322, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0325 = stack[0];
    v0325 = qcdr(v0325);
    v0325 = qcdr(v0325);
    v0322 = qcar(v0325);
    v0325 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v0325 = (*qfn2(fn))(qenv(fn), v0322, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        Lisp_Object v0111 = stack[-1];
        popv(4);
        return Llessp(nil, v0111, v0325);
    }

v0112:
    v0325 = stack[-1];
    v0322 = qcar(v0325);
    v0325 = stack[0];
    v0325 = qcar(v0325);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v0322, v0325);
    }
/* error exit handlers */
v0110:
    popv(4);
    return nil;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*farg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0136 = v0192;
/* end of prologue */
    v0120 = v0136;
    v0120 = qcdr(v0120);
    if (v0120 == nil) goto v0196;
    stack[-1] = nil;
    v0120 = v0136;
    stack[0] = v0120;
    goto v0219;

v0219:
    v0120 = stack[0];
    if (v0120 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0120 = stack[0];
    v0120 = qcar(v0120);
    fn = elt(env, 2); /* deg!*form */
    v0136 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0120 = stack[-1];
    fn = elt(env, 3); /* addf */
    v0120 = (*qfn2(fn))(qenv(fn), v0136, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    stack[-1] = v0120;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    stack[0] = v0120;
    goto v0219;

v0196:
    v0120 = v0136;
    v0120 = qcar(v0120);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v0120);
    }
/* error exit handlers */
v0223:
    popv(3);
    return nil;
}



/* Code for fortranop */

static Lisp_Object CC_fortranop(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0200, v0194;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0194 = v0192;
/* end of prologue */
    v0200 = v0194;
    v0180 = elt(env, 1); /* !*fortranop!* */
    v0180 = get(v0200, v0180);
    if (v0180 == nil) return onevalue(v0194);
    else return onevalue(v0180);
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0198, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0207 = qcar(v0197);
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0197 = qcdr(v0197);
    v0198 = qcar(v0197);
    v0197 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v0197 = (*qfnn(fn))(qenv(fn), 3, v0207, v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-2];
    if (!(v0197 == nil)) { popv(3); return onevalue(v0197); }
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0197 = qcdr(v0197);
    v0207 = qcar(v0197);
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0198 = qcar(v0197);
    v0197 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v0207, v0198, v0197);
    }
/* error exit handlers */
v0136:
    popv(3);
    return nil;
}



/* Code for red!-weight!-less!-p */

static Lisp_Object CC_redKweightKlessKp(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0198, v0207, v0124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0198 = v0049;
    v0207 = v0192;
/* end of prologue */
    v0197 = v0207;
    v0124 = qcar(v0197);
    v0197 = v0198;
    v0197 = qcar(v0197);
    if (equal(v0124, v0197)) goto v0140;
    v0197 = v0207;
    v0197 = qcar(v0197);
    v0198 = qcar(v0198);
        return Llessp(nil, v0197, v0198);

v0140:
    v0197 = v0207;
    v0197 = qcdr(v0197);
    v0198 = qcdr(v0198);
        return Llessp(nil, v0197, v0198);
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnquotient:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0195 = qcar(v0217);
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    stack[-2] = times2(v0195, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0195 = qcdr(v0217);
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    v0217 = qcar(v0217);
    v0217 = times2(v0195, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    {
        Lisp_Object v0198 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0198, v0217);
    }
/* error exit handlers */
v0197:
    popv(4);
    return nil;
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v0049, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0189, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0049);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0049,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0077 = v0016;
    stack[-3] = v0049;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v0077; /* p!*!* */
    stack[0] = nil;
    v0077 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v0077;
    v0077 = stack[-3];
    if (v0077 == nil) goto v0194;
    v0077 = stack[-3];
    if (!consp(v0077)) goto v0208;
    v0077 = stack[-3];
    v0077 = qcar(v0077);
    if (!consp(v0077)) goto v0113;
    v0077 = stack[-3];
    v0189 = qcar(v0077);
    v0077 = stack[-2];
    v0077 = CC_maprint(env, v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0200;

v0200:
    v0077 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 13)) = v0077; /* obrkp!* */
    v0077 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v0077;
    v0189 = qvalue(elt(env, 12)); /* posn!* */
    v0077 = (Lisp_Object)289; /* 18 */
    v0077 = (Lisp_Object)lessp2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-5];
    if (v0077 == nil) goto v0373;
    v0077 = qvalue(elt(env, 12)); /* posn!* */
    goto v0374;

v0374:
    qvalue(elt(env, 11)) = v0077; /* orig!* */
    v0077 = stack[-3];
    v0077 = qcdr(v0077);
    if (v0077 == nil) goto v0288;
    v0188 = elt(env, 14); /* !*comma!* */
    v0189 = (Lisp_Object)1; /* 0 */
    v0077 = stack[-3];
    v0077 = qcdr(v0077);
    fn = elt(env, 16); /* inprint */
    v0077 = (*qfnn(fn))(qenv(fn), 3, v0188, v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0288;

v0288:
    v0077 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 13)) = v0077; /* obrkp!* */
    v0077 = stack[0];
    qvalue(elt(env, 11)) = v0077; /* orig!* */
    v0077 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = stack[-3];
    goto v0133;

v0133:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v0077); }

v0373:
    v0189 = qvalue(elt(env, 11)); /* orig!* */
    v0077 = (Lisp_Object)49; /* 3 */
    v0077 = plus2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0374;

v0113:
    v0077 = stack[-3];
    v0189 = qcar(v0077);
    v0077 = elt(env, 8); /* pprifn */
    v0077 = get(v0189, v0077);
    env = stack[-5];
    stack[-1] = v0077;
    if (v0077 == nil) goto v0298;
    v0188 = stack[-1];
    v0189 = stack[-3];
    v0077 = stack[-2];
    v0189 = Lapply2(nil, 3, v0188, v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = elt(env, 9); /* failed */
    if (!(v0189 == v0077)) goto v0354;

v0298:
    v0077 = stack[-3];
    v0189 = qcar(v0077);
    v0077 = elt(env, 10); /* prifn */
    v0077 = get(v0189, v0077);
    env = stack[-5];
    stack[-1] = v0077;
    if (v0077 == nil) goto v0104;
    v0189 = stack[-1];
    v0077 = stack[-3];
    v0189 = Lapply1(nil, v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = elt(env, 9); /* failed */
    if (!(v0189 == v0077)) goto v0354;

v0104:
    v0077 = stack[-3];
    v0189 = qcar(v0077);
    v0077 = elt(env, 5); /* infix */
    v0077 = get(v0189, v0077);
    env = stack[-5];
    stack[-1] = v0077;
    if (v0077 == nil) goto v0375;
    v0189 = stack[-1];
    v0077 = stack[-2];
    v0077 = (Lisp_Object)greaterp2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-5];
    v0077 = (v0077 == nil ? lisp_true : nil);
    stack[-2] = v0077;
    v0077 = stack[-2];
    if (v0077 == nil) goto v0319;
    v0077 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v0077;
    v0077 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0189 = qvalue(elt(env, 12)); /* posn!* */
    v0077 = (Lisp_Object)289; /* 18 */
    v0077 = (Lisp_Object)lessp2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-5];
    if (v0077 == nil) goto v0343;
    v0077 = qvalue(elt(env, 12)); /* posn!* */
    goto v0257;

v0257:
    qvalue(elt(env, 11)) = v0077; /* orig!* */
    goto v0319;

v0319:
    v0077 = stack[-3];
    v0188 = qcar(v0077);
    v0189 = stack[-1];
    v0077 = stack[-3];
    v0077 = qcdr(v0077);
    fn = elt(env, 16); /* inprint */
    v0077 = (*qfnn(fn))(qenv(fn), 3, v0188, v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = stack[-2];
    if (v0077 == nil) goto v0376;
    v0077 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = stack[0];
    qvalue(elt(env, 11)) = v0077; /* orig!* */
    goto v0376;

v0376:
    v0077 = stack[-3];
    goto v0133;

v0343:
    v0189 = qvalue(elt(env, 11)); /* orig!* */
    v0077 = (Lisp_Object)49; /* 3 */
    v0077 = plus2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0257;

v0375:
    v0077 = stack[-3];
    v0077 = qcar(v0077);
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0200;

v0354:
    v0077 = stack[-3];
    goto v0133;

v0208:
    v0077 = stack[-3];
    v0077 = Lsimple_vectorp(nil, v0077);
    env = stack[-5];
    if (v0077 == nil) goto v0203;
    v0189 = stack[-3];
    v0077 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 17); /* vec!-maprin */
    v0077 = (*qfn2(fn))(qenv(fn), v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0235;

v0235:
    v0077 = stack[-3];
    goto v0133;

v0203:
    v0077 = stack[-3];
    if (is_number(v0077)) goto v0205;
    v0077 = qvalue(elt(env, 3)); /* t */
    goto v0207;

v0207:
    if (v0077 == nil) goto v0377;
    v0077 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0235;

v0377:
    v0077 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    v0077 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-5];
    goto v0235;

v0205:
    v0189 = stack[-3];
    v0077 = (Lisp_Object)1; /* 0 */
    v0077 = (Lisp_Object)lessp2(v0189, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-5];
    if (v0077 == nil) goto v0260;
    v0188 = stack[-2];
    v0189 = elt(env, 4); /* minus */
    v0077 = elt(env, 5); /* infix */
    v0077 = get(v0189, v0077);
    env = stack[-5];
    v0077 = (Lisp_Object)lesseq2(v0188, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-5];
    goto v0207;

v0260:
    v0077 = qvalue(elt(env, 3)); /* t */
    goto v0207;

v0194:
    v0077 = qvalue(elt(env, 2)); /* nil */
    goto v0133;
/* error exit handlers */
v0372:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for flatsizec */

static Lisp_Object CC_flatsizec(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatsizec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0192;
/* end of prologue */
    v0127 = stack[0];
    if (v0127 == nil) goto v0196;
    v0127 = stack[0];
    if (!consp(v0127)) goto v0151;
    v0127 = stack[0];
    v0127 = qcar(v0127);
    stack[-1] = CC_flatsizec(env, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-2];
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    v0127 = CC_flatsizec(env, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-2];
    v0127 = add1(v0127);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    {
        Lisp_Object v0218 = stack[-1];
        popv(3);
        return plus2(v0218, v0127);
    }

v0151:
    v0127 = stack[0];
        popv(3);
        return Llengthc(nil, v0127);

v0196:
    v0127 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0127); }
/* error exit handlers */
v0193:
    popv(3);
    return nil;
}



/* Code for !*sqprint */

static Lisp_Object CC_Hsqprint(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sqprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0133 = v0192;
/* end of prologue */
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    {
        fn = elt(env, 1); /* sqprint */
        return (*qfn1(fn))(qenv(fn), v0133);
    }
}



/* Code for wulessp!* */

static Lisp_Object CC_wulesspH(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0226, v0197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0192;
/* end of prologue */
    v0197 = stack[-1];
    v0226 = stack[0];
    fn = elt(env, 3); /* wulessp */
    v0226 = (*qfn2(fn))(qenv(fn), v0197, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    if (v0226 == nil) goto v0219;
    v0226 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0226); }

v0219:
    v0197 = stack[0];
    v0226 = stack[-1];
    fn = elt(env, 3); /* wulessp */
    v0226 = (*qfn2(fn))(qenv(fn), v0197, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    if (v0226 == nil) goto v0230;
    v0226 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0226); }

v0230:
    v0197 = stack[-1];
    v0226 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* totallessp */
        return (*qfn2(fn))(qenv(fn), v0197, v0226);
    }
/* error exit handlers */
v0124:
    popv(3);
    return nil;
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0391, v0084, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0192;
/* end of prologue */
    v0391 = stack[-2];
    v0084 = qcdr(v0391);
    v0391 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0391) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0391 = stack[-2];
    v0391 = qcar(v0391);
    if (v0391 == nil) goto v0208;
    stack[-1] = nil;
    v0391 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v0391 == nil) goto v0195;
    v0391 = stack[-2];
    v0084 = qcar(v0391);
    v0391 = stack[-2];
    v0391 = qcdr(v0391);
    fn = elt(env, 10); /* gcdf */
    v0084 = (*qfn2(fn))(qenv(fn), v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-3] = v0084;
    v0391 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0391) goto v0195;
    v0391 = stack[-2];
    v0084 = qcar(v0391);
    v0391 = stack[-3];
    fn = elt(env, 11); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = stack[-2];
    v0084 = qcdr(v0391);
    v0391 = stack[-3];
    fn = elt(env, 11); /* quotf */
    v0391 = (*qfn2(fn))(qenv(fn), v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = cons(stack[0], v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-2] = v0391;
    goto v0195;

v0195:
    v0391 = stack[-2];
    v0391 = qcdr(v0391);
    fn = elt(env, 12); /* lnc */
    v0391 = (*qfn1(fn))(qenv(fn), v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-3] = v0391;
    v0084 = stack[-3];
    v0391 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0391) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0391 = stack[-3];
    if (!consp(v0391)) goto v0115;
    v0391 = stack[-3];
    v0084 = qcar(v0391);
    v0391 = elt(env, 3); /* minusp */
    v0084 = get(v0084, v0391);
    env = stack[-4];
    v0391 = stack[-3];
    v0391 = Lapply1(nil, v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    if (v0391 == nil) goto v0326;
    v0391 = stack[-2];
    v0391 = qcar(v0391);
    fn = elt(env, 13); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = stack[-2];
    v0391 = qcdr(v0391);
    fn = elt(env, 13); /* negf */
    v0391 = (*qfn1(fn))(qenv(fn), v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = cons(stack[0], v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-2] = v0391;
    v0391 = stack[-3];
    v0084 = qcar(v0391);
    v0391 = elt(env, 4); /* difference */
    stack[0] = get(v0084, v0391);
    env = stack[-4];
    v0391 = stack[-3];
    v0084 = qcar(v0391);
    v0391 = elt(env, 5); /* i2d */
    v0084 = get(v0084, v0391);
    env = stack[-4];
    v0391 = (Lisp_Object)1; /* 0 */
    v0084 = Lapply1(nil, v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = stack[-3];
    v0391 = Lapply2(nil, 3, stack[0], v0084, v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-3] = v0391;
    goto v0326;

v0326:
    v0391 = stack[-3];
    if (is_number(v0391)) goto v0392;
    v0084 = qvalue(elt(env, 6)); /* dmode!* */
    v0391 = elt(env, 7); /* unitsfn */
    v0391 = get(v0084, v0391);
    env = stack[-4];
    stack[-1] = v0391;
    goto v0312;

v0312:
    if (v0391 == nil) goto v0393;
    v0083 = stack[-1];
    v0084 = stack[-2];
    v0391 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v0083, v0084, v0391);

v0393:
    v0084 = qvalue(elt(env, 6)); /* dmode!* */
    v0391 = elt(env, 8); /* field */
    v0391 = Lflagp(nil, v0084, v0391);
    env = stack[-4];
    if (v0391 == nil) goto v0394;
    v0391 = qvalue(elt(env, 9)); /* t */
    goto v0291;

v0291:
    if (v0391 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0084 = stack[-3];
    v0391 = stack[-2];
    {
        popv(5);
        fn = elt(env, 14); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v0084, v0391);
    }

v0394:
    v0391 = stack[-3];
    if (!consp(v0391)) goto v0285;
    v0391 = stack[-3];
    v0084 = qcar(v0391);
    v0391 = elt(env, 8); /* field */
    v0391 = Lflagp(nil, v0084, v0391);
    env = stack[-4];
    goto v0291;

v0285:
    v0391 = qvalue(elt(env, 1)); /* nil */
    goto v0291;

v0392:
    v0391 = qvalue(elt(env, 1)); /* nil */
    goto v0312;

v0115:
    v0391 = stack[-3];
    v0391 = Lminusp(nil, v0391);
    env = stack[-4];
    if (v0391 == nil) goto v0326;
    v0391 = stack[-2];
    v0391 = qcar(v0391);
    fn = elt(env, 13); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = stack[-2];
    v0391 = qcdr(v0391);
    fn = elt(env, 13); /* negf */
    v0391 = (*qfn1(fn))(qenv(fn), v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    v0391 = cons(stack[0], v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-2] = v0391;
    v0391 = stack[-3];
    v0391 = negate(v0391);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-4];
    stack[-3] = v0391;
    goto v0326;

v0208:
    v0084 = qvalue(elt(env, 1)); /* nil */
    v0391 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0084, v0391);
/* error exit handlers */
v0337:
    popv(5);
    return nil;
}



/* Code for ratpoly_ldeg */

static Lisp_Object CC_ratpoly_ldeg(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ldeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0231 = v0192;
/* end of prologue */
    v0231 = qcar(v0231);
    {
        fn = elt(env, 1); /* numpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v0231);
    }
}



/* Code for rl_sacatlp */

static Lisp_Object CC_rl_sacatlp(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacatlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0143 = v0049;
    v0219 = v0192;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacatlp!* */
    v0143 = list2(v0219, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-1];
    {
        Lisp_Object v0232 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0232, v0143);
    }
/* error exit handlers */
v0212:
    popv(2);
    return nil;
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0218, v0217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omair");
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
    push2(nil, nil);
/* end of prologue */
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v0218 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v0218 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    stack[-1] = v0218;
    v0218 = stack[-1];
    v0217 = qcar(v0218);
    v0218 = elt(env, 1); /* matrix */
    if (v0217 == v0218) goto v0262;
    fn = elt(env, 4); /* lex */
    v0218 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v0218 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    stack[0] = v0218;
    v0218 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    goto v0262;

v0262:
    v0217 = stack[-1];
    v0218 = stack[0];
        popv(3);
        return Lappend(nil, v0217, v0218);
/* error exit handlers */
v0138:
    popv(3);
    return nil;
}



/* Code for on */

static Lisp_Object CC_on(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0203 = v0192;
/* end of prologue */
    stack[0] = v0203;
    goto v0231;

v0231:
    v0203 = stack[0];
    if (v0203 == nil) goto v0182;
    v0203 = stack[0];
    v0203 = qcar(v0203);
    v0201 = v0203;
    v0203 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 3); /* onoff */
    v0203 = (*qfn2(fn))(qenv(fn), v0201, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-1];
    v0203 = stack[0];
    v0203 = qcdr(v0203);
    stack[0] = v0203;
    goto v0231;

v0182:
    v0203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0203); }
/* error exit handlers */
v0128:
    popv(2);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0123, v0249, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0249 = v0049;
    v0135 = v0192;
/* end of prologue */
    v0122 = v0135;
    if (v0122 == nil) goto v0231;
    v0123 = v0135;
    v0122 = elt(env, 2); /* vdp */
    if (!consp(v0123)) goto v0208;
    v0123 = qcar(v0123);
    if (!(v0123 == v0122)) goto v0208;
    v0122 = v0249;
    v0123 = v0135;
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    v0122 = Lassoc(nil, v0122, v0123);
    v0123 = v0122;
    v0122 = v0123;
    if (v0122 == nil) goto v0215;
    v0122 = v0123;
    v0122 = qcdr(v0122);
    { popv(1); return onevalue(v0122); }

v0215:
    v0122 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0122); }

v0208:
    v0122 = elt(env, 3); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v0123 = v0135;
    v0122 = list3(v0122, v0123, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[0];
    v0123 = v0122;
    v0122 = v0123;
    qvalue(elt(env, 4)) = v0122; /* errmsg!* */
    v0122 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0122 == nil)) goto v0119;
    v0122 = v0123;
    fn = elt(env, 6); /* lprie */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[0];
    goto v0119;

v0119:
    v0122 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    v0122 = nil;
    { popv(1); return onevalue(v0122); }

v0231:
    v0122 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0122); }
/* error exit handlers */
v0349:
    popv(1);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0257, v0294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0049;
    stack[-2] = v0192;
/* end of prologue */
    stack[0] = nil;
    goto v0133;

v0133:
    v0253 = stack[-2];
    if (v0253 == nil) goto v0222;
    v0253 = stack[-1];
    if (v0253 == nil) goto v0235;
    v0253 = stack[-2];
    v0253 = qcar(v0253);
    v0257 = qcar(v0253);
    v0253 = (Lisp_Object)17; /* 1 */
    if (v0257 == v0253) goto v0199;
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0257 = qcar(v0253);
    v0253 = (Lisp_Object)17; /* 1 */
    if (v0257 == v0253) goto v0114;
    v0253 = stack[-2];
    v0253 = qcar(v0253);
    v0257 = qcar(v0253);
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = qcar(v0253);
    if (equal(v0257, v0253)) goto v0304;
    v0253 = stack[-2];
    v0253 = qcar(v0253);
    v0257 = qcar(v0253);
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = qcar(v0253);
    fn = elt(env, 1); /* ordop */
    v0253 = (*qfn2(fn))(qenv(fn), v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    if (v0253 == nil) goto v0367;
    v0253 = stack[-2];
    v0257 = qcar(v0253);
    v0253 = stack[0];
    v0253 = cons(v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    stack[0] = v0253;
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    stack[-2] = v0253;
    goto v0133;

v0367:
    v0253 = stack[-1];
    v0257 = qcar(v0253);
    v0253 = stack[0];
    v0253 = cons(v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    stack[0] = v0253;
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0133;

v0304:
    stack[-3] = stack[0];
    v0253 = stack[-2];
    v0253 = qcar(v0253);
    v0257 = qcdr(v0253);
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = qcdr(v0253);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    v0253 = stack[-2];
    v0257 = qcdr(v0253);
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    v0253 = CC_addpf(env, v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    v0257 = stack[0];
    v0294 = v0257;
    v0294 = qcar(v0294);
    if (v0294 == nil) goto v0150;
    v0294 = stack[-2];
    v0294 = qcar(v0294);
    v0294 = qcar(v0294);
    v0253 = acons(v0294, v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    goto v0150;

v0150:
    {
        Lisp_Object v0094 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0094, v0253);
    }

v0114:
    v0257 = stack[-1];
    v0253 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0253 = (*qfn2(fn))(qenv(fn), v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    {
        Lisp_Object v0159 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0159, v0253);
    }

v0199:
    v0257 = stack[-2];
    v0253 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0253 = (*qfn2(fn))(qenv(fn), v0257, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-4];
    {
        Lisp_Object v0158 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0158, v0253);
    }

v0235:
    v0257 = stack[0];
    v0253 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0257, v0253);
    }

v0222:
    v0257 = stack[0];
    v0253 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0257, v0253);
    }
/* error exit handlers */
v0345:
    popv(5);
    return nil;
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0230, v0193, v0218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0230 = v0192;
/* end of prologue */
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0218 = v0230;
    v0230 = v0218;
    v0193 = qcar(v0230);
    v0230 = elt(env, 1); /* !? */
    if (v0193 == v0230) goto v0201;
    v0230 = v0218;
    v0230 = qcdr(v0230);
    v0193 = elt(env, 1); /* !? */
        return Lneq(nil, v0230, v0193);

v0201:
    v0230 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0230);
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0124, v0120, v0136;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprogn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0120 = v0049;
    v0136 = v0192;
/* end of prologue */
    v0124 = v0120;
    v0207 = elt(env, 1); /* progn */
    if (!consp(v0124)) goto v0230;
    v0124 = qcar(v0124);
    if (!(v0124 == v0207)) goto v0230;
    v0207 = elt(env, 1); /* progn */
    v0124 = v0136;
    v0120 = qcdr(v0120);
    return list2star(v0207, v0124, v0120);

v0230:
    v0207 = elt(env, 1); /* progn */
    v0124 = v0136;
    return list3(v0207, v0124, v0120);
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0192)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0236, v0215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0192);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0192;
/* end of prologue */
    v0137 = stack[-1];
    v0236 = qcar(v0137);
    v0137 = elt(env, 1); /* dimension */
    v0137 = get(v0236, v0137);
    env = stack[-3];
    stack[-2] = v0137;
    v0137 = stack[-2];
    stack[0] = Llength(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0137 = stack[-1];
    v0137 = qcdr(v0137);
    v0137 = Llength(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    if (equal(stack[0], v0137)) goto v0199;
    v0137 = elt(env, 2); /* "Incorrect array reference" */
    v0236 = v0137;
    v0137 = v0236;
    qvalue(elt(env, 3)) = v0137; /* errmsg!* */
    v0137 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0137 == nil)) goto v0218;
    v0137 = v0236;
    fn = elt(env, 6); /* lprie */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0218;

v0218:
    v0137 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    v0137 = nil;
    { popv(4); return onevalue(v0137); }

v0199:
    v0137 = stack[-1];
    v0236 = qcar(v0137);
    v0137 = elt(env, 5); /* avalue */
    v0137 = get(v0236, v0137);
    env = stack[-3];
    v0137 = qcdr(v0137);
    v0215 = qcar(v0137);
    v0137 = stack[-1];
    v0236 = qcdr(v0137);
    v0137 = stack[-2];
    {
        popv(4);
        fn = elt(env, 7); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v0215, v0236, v0137);
    }
/* error exit handlers */
v0123:
    popv(4);
    return nil;
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0192, Lisp_Object v0049,
                         Lisp_Object v0016, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0016,v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0192,v0049,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0016;
    stack[-3] = v0049;
    v0201 = v0192;
/* end of prologue */
    stack[-4] = v0201;
    stack[-1] = stack[-3];
    v0201 = stack[-3];
    stack[0] = Llength(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0201 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v0127 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0201 = stack[-2];
    v0201 = list2(v0127, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    {
        Lisp_Object v0119 = stack[-4];
        Lisp_Object v0138 = stack[-1];
        Lisp_Object v0226 = stack[0];
        popv(6);
        return list3star(v0119, v0138, v0226, v0201);
    }
/* error exit handlers */
v0195:
    popv(6);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0192, Lisp_Object v0049)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0125;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcons");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0192);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0192,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0049;
    v0126 = v0192;
/* end of prologue */
    stack[-4] = v0126;
    v0126 = stack[-4];
    if (v0126 == nil) goto v0213;
    v0126 = stack[-4];
    v0126 = qcar(v0126);
    v0125 = stack[-3];
    v0126 = cons(v0125, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0126 = ncons(v0126);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-1] = v0126;
    stack[-2] = v0126;
    goto v0151;

v0151:
    v0126 = stack[-4];
    v0126 = qcdr(v0126);
    stack[-4] = v0126;
    v0126 = stack[-4];
    if (v0126 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0126 = stack[-4];
    v0126 = qcar(v0126);
    v0125 = stack[-3];
    v0126 = cons(v0125, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0126 = ncons(v0126);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0126 = Lrplacd(nil, stack[0], v0126);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    stack[-1] = v0126;
    goto v0151;

v0213:
    v0126 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0126); }
/* error exit handlers */
v0236:
    popv(6);
    return nil;
}



setup_type const u08_setup[] =
{
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"efface1",                 too_few_2,      CC_efface1,    wrong_no_2},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"ratpoly_idl",             CC_ratpoly_idl, too_many_1,    wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"rd:prep",                 CC_rdTprep,     too_many_1,    wrong_no_1},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"raiseind:",               CC_raiseindT,   too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"processcarpartitie1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_processcarpartitie1},
    {"totallessp",              too_few_2,      CC_totallessp, wrong_no_2},
    {"pasf_deci",               CC_pasf_deci,   too_many_1,    wrong_no_1},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"dfn_prop",                CC_dfn_prop,    too_many_1,    wrong_no_1},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"fortranop",               CC_fortranop,   too_many_1,    wrong_no_1},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"flatsizec",               CC_flatsizec,   too_many_1,    wrong_no_1},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"ratpoly_ldeg",            CC_ratpoly_ldeg,too_many_1,    wrong_no_1},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {NULL, (one_args *)"u08", (two_args *)"19799 6138495 8670951", 0}
};

/* end of generated code */
