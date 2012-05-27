
/* $destdir\u38.c        Machine generated C code */

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


/* Code for gd_gcasesimpl */

static Lisp_Object CC_gd_gcasesimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_gcasesimpl");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v4 = stack[0];
    stack[-1] = qcar(v4);
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = qcar(v4);
    fn = elt(env, 1); /* gd_simpl */
    v5 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v6;
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = qcdr(v4);
    v4 = qcar(v4);
    {
        Lisp_Object v7 = stack[-1];
        popv(2);
        return list3(v7, v5, v4);
    }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for taymindegreel */

static Lisp_Object CC_taymindegreel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taymindegreel");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v20;

v20:
    v18 = stack[-2];
    if (v18 == nil) goto v21;
    v18 = stack[-2];
    v18 = qcar(v18);
    stack[0] = v18;
    v18 = (Lisp_Object)1; /* 0 */
    v19 = v18;
    goto v22;

v22:
    v18 = stack[0];
    if (v18 == nil) goto v23;
    v18 = stack[0];
    v18 = qcar(v18);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v18 = (*qfn2(fn))(qenv(fn), v18, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v19 = v18;
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[0] = v18;
    goto v22;

v23:
    v18 = v19;
    v19 = v18;
    v18 = stack[-1];
    v18 = qcar(v18);
    fn = elt(env, 2); /* tayexp!-min2 */
    v19 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v18 = stack[-3];
    v18 = cons(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    stack[-3] = v18;
    v18 = stack[-2];
    v18 = qcdr(v18);
    stack[-2] = v18;
    v18 = stack[-1];
    v18 = qcdr(v18);
    stack[-1] = v18;
    goto v20;

v21:
    v18 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v24:
    popv(5);
    return nil;
}



/* Code for pasf_lnegrel */

static Lisp_Object CC_pasf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v37 = v0;
/* end of prologue */
    v36 = v37;
    v35 = elt(env, 1); /* equal */
    if (v36 == v35) goto v38;
    v36 = v37;
    v35 = elt(env, 2); /* neq */
    if (v36 == v35) goto v39;
    v36 = v37;
    v35 = elt(env, 3); /* leq */
    if (v36 == v35) goto v6;
    v36 = v37;
    v35 = elt(env, 5); /* lessp */
    if (v36 == v35) goto v40;
    v36 = v37;
    v35 = elt(env, 6); /* geq */
    if (v36 == v35) goto v41;
    v36 = v37;
    v35 = elt(env, 4); /* greaterp */
    if (v36 == v35) goto v42;
    v36 = v37;
    v35 = elt(env, 7); /* cong */
    if (v36 == v35) goto v43;
    v36 = v37;
    v35 = elt(env, 8); /* ncong */
    if (v36 == v35) goto v44;
    v35 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v35 == nil)) goto v45;
    v35 = elt(env, 10); /* "pasf_lnegrel: unknown operator" */
    v36 = v37;
    v35 = list2(v35, v36);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[0];
    goto v45;

v45:
    v35 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v35 = nil;
    { popv(1); return onevalue(v35); }

v44:
    v35 = elt(env, 7); /* cong */
    { popv(1); return onevalue(v35); }

v43:
    v35 = elt(env, 8); /* ncong */
    { popv(1); return onevalue(v35); }

v42:
    v35 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v35); }

v41:
    v35 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v35); }

v40:
    v35 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v35); }

v6:
    v35 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v35); }

v39:
    v35 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v35); }

v38:
    v35 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v35); }
/* error exit handlers */
v46:
    popv(1);
    return nil;
}



/* Code for dvfsf_smcpknowl */

static Lisp_Object CC_dvfsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v47 == nil) goto v21;
    v47 = v39;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v47);
    }

v21:
    v47 = v39;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v47);
    }
}



/* Code for cnml */

static Lisp_Object MS_CDECL CC_cnml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnml");
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
    v72 = qvalue(elt(env, 2)); /* atts */
    v71 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 12); /* search_att */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-2] = v71;
    fn = elt(env, 13); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = qvalue(elt(env, 4)); /* char */
    stack[0] = v71;
    fn = elt(env, 13); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v72 = stack[-2];
    v71 = elt(env, 5); /* (c o n s t a n t) */
    if (!(equal(v72, v71))) goto v5;
    v71 = stack[0];
    v71 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v72 = Lintern(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = qvalue(elt(env, 6)); /* rdci!* */
    v72 = Lassoc(nil, v72, v71);
    v71 = v72;
    if (v72 == nil) goto v5;
    v72 = v71;
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    {
        popv(4);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v5:
    v71 = stack[0];
    v71 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    if (!(symbolp(v71))) goto v74;
    v71 = stack[0];
    v72 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = (Lisp_Object)257; /* 16 */
    fn = elt(env, 15); /* errorml */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    goto v74;

v74:
    v71 = stack[-2];
    if (v71 == nil) goto v44;
    v72 = stack[-2];
    v71 = elt(env, 7); /* ((r e a l) (i n t e g e r)) */
    v71 = Lmember(nil, v72, v71);
    if (v71 == nil) goto v75;
    v71 = stack[0];
        popv(4);
        return Lcompress(nil, v71);

v75:
    v72 = stack[-2];
    v71 = elt(env, 8); /* ((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r)) 
*/
    v71 = Lmember(nil, v72, v71);
    if (v71 == nil) goto v76;
    fn = elt(env, 16); /* seprd */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-1] = v71;
    v72 = stack[-2];
    v71 = elt(env, 9); /* (r a t i o n a l) */
    if (equal(v72, v71)) goto v77;
    v72 = stack[-2];
    v71 = elt(env, 10); /* (c o m p l e x !- c a r t e s i a n) */
    if (equal(v72, v71)) goto v78;
    v72 = stack[-2];
    v71 = elt(env, 11); /* (c o m p l e x !- p o l a r) */
    if (!(equal(v72, v71))) goto v76;
    v71 = stack[0];
    v72 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[-1];
    fn = elt(env, 17); /* po2ca */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-1] = v71;
    fn = elt(env, 13); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = stack[-1];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v76:
    v71 = nil;
    { popv(4); return onevalue(v71); }

v78:
    fn = elt(env, 13); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[0];
    v72 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[-1];
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v77:
    fn = elt(env, 13); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[0];
    v72 = Lcompress(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v71 = stack[-1];
    {
        popv(4);
        fn = elt(env, 19); /* alg_quotient */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v44:
    v71 = stack[0];
        popv(4);
        return Lcompress(nil, v71);
/* error exit handlers */
v73:
    popv(4);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v87 = qvalue(elt(env, 2)); /* maxvar */
    v42 = stack[0];
    v42 = plus2(v87, v42);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v87 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    v42 = (Lisp_Object)81; /* 5 */
    v42 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    if (v42 == nil) goto v88;
    v42 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v42); }

v88:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v87 = qvalue(elt(env, 2)); /* maxvar */
    v42 = stack[0];
    v42 = plus2(v87, v42);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v87 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    v42 = (Lisp_Object)49; /* 3 */
    v42 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    v42 = (is_number(v42) ? lisp_true : nil);
    { popv(3); return onevalue(v42); }
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for termorder1 */

static Lisp_Object CC_termorder1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder1");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v89:
    v19 = stack[-1];
    if (v19 == nil) goto v90;
    v19 = stack[-1];
    v19 = (Lisp_Object)zerop(v19);
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v47;
    v19 = stack[0];
    v19 = (Lisp_Object)zerop(v19);
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v47;
    v19 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v19); }

v47:
    v19 = stack[-1];
    v19 = (Lisp_Object)zerop(v19);
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v9;
    v19 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v19); }

v9:
    v19 = stack[0];
    v19 = (Lisp_Object)zerop(v19);
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v40;
    v19 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v19); }

v40:
    v19 = stack[-1];
    v43 = qcar(v19);
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = (Lisp_Object)lessp2(v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v80;
    v19 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v19); }

v80:
    v19 = stack[-1];
    v43 = qcar(v19);
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = (Lisp_Object)greaterp2(v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v10;
    v19 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v19); }

v10:
    v19 = stack[-1];
    v19 = qcdr(v19);
    stack[-1] = v19;
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    goto v89;

v90:
    v19 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v19); }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for xexptpf */

static Lisp_Object CC_xexptpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xexptpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v39;

v39:
    v94 = stack[0];
    v93 = (Lisp_Object)17; /* 1 */
    if (v94 == v93) goto v90;
    v94 = stack[-1];
    v93 = stack[-2];
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    stack[-2] = v93;
    v93 = stack[0];
    v93 = sub1(v93);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    stack[0] = v93;
    goto v39;

v90:
    v93 = stack[-1];
    v94 = v93;
    goto v21;

v21:
    v93 = stack[-2];
    if (v93 == nil) { popv(4); return onevalue(v94); }
    v93 = stack[-2];
    v93 = qcar(v93);
    fn = elt(env, 1); /* wedgepf */
    v93 = (*qfn2(fn))(qenv(fn), v93, v94);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    v94 = v93;
    v93 = stack[-2];
    v93 = qcdr(v93);
    stack[-2] = v93;
    goto v21;
/* error exit handlers */
v42:
    popv(4);
    return nil;
}



/* Code for adjp */

static Lisp_Object CC_adjp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjp");
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
    v26 = stack[-1];
    v25 = elt(env, 1); /* unit */
    if (v26 == v25) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v25 = stack[-1];
    if (!consp(v25)) goto v98;
    v25 = stack[-1];
    v26 = qcar(v25);
    v25 = elt(env, 3); /* comm */
    if (v26 == v25) goto v99;
    v25 = stack[-1];
    v26 = qcar(v25);
    v25 = elt(env, 4); /* anticomm */
    if (v26 == v25) goto v43;
    v25 = stack[-1];
    v26 = qcar(v25);
    v25 = elt(env, 2); /* adjoint */
    v26 = get(v26, v25);
    v25 = stack[-1];
    v25 = qcdr(v25);
    popv(4);
    return cons(v26, v25);

v43:
    stack[-2] = elt(env, 4); /* anticomm */
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcar(v25);
    stack[0] = CC_adjp(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v25 = qcar(v25);
    v25 = CC_adjp(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v37;
    {
        Lisp_Object v46 = stack[-2];
        Lisp_Object v100 = stack[0];
        popv(4);
        return list3(v46, v100, v25);
    }

v99:
    stack[-2] = elt(env, 3); /* comm */
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v25 = qcar(v25);
    stack[0] = CC_adjp(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcar(v25);
    v25 = CC_adjp(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v37;
    {
        Lisp_Object v77 = stack[-2];
        Lisp_Object v101 = stack[0];
        popv(4);
        return list3(v77, v101, v25);
    }

v98:
    v25 = stack[-1];
    v26 = elt(env, 2); /* adjoint */
    popv(4);
    return get(v25, v26);
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v23 = stack[0];
    v81 = Llength(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v23 = (Lisp_Object)49; /* 3 */
    if (!(v81 == v23)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v23 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v81 = v23;
    if (v81 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v81 = stack[0];
    v23 = qcar(v23);
    fn = elt(env, 2); /* mk_edge_parents */
    v23 = (*qfn2(fn))(qenv(fn), v81, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for simp!-prop */

static Lisp_Object CC_simpKprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* propvars!* */
    qvalue(elt(env, 1)) = nil; /* propvars!* */
    v131 = stack[-2];
    v131 = qcdr(v131);
    stack[-4] = v131;
    v131 = stack[-4];
    if (v131 == nil) goto v85;
    v131 = stack[-4];
    v131 = qcar(v131);
    fn = elt(env, 14); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    stack[-1] = v131;
    stack[-3] = v131;
    goto v1;

v1:
    v131 = stack[-4];
    v131 = qcdr(v131);
    stack[-4] = v131;
    v131 = stack[-4];
    if (v131 == nil) goto v34;
    stack[0] = stack[-1];
    v131 = stack[-4];
    v131 = qcar(v131);
    fn = elt(env, 14); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = Lrplacd(nil, stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = stack[-1];
    v131 = qcdr(v131);
    stack[-1] = v131;
    goto v1;

v34:
    v131 = stack[-3];
    goto v2;

v2:
    stack[-5] = v131;
    v132 = elt(env, 3); /* and */
    v131 = stack[-5];
    v131 = Lmember(nil, v132, v131);
    if (v131 == nil) goto v91;
    v131 = elt(env, 4); /* or */
    qvalue(elt(env, 5)) = v131; /* !'and */
    v131 = elt(env, 3); /* and */
    qvalue(elt(env, 6)) = v131; /* !'or */
    v131 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v131; /* !'true */
    v131 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 8)) = v131; /* !'false */
    goto v135;

v135:
    v131 = stack[-2];
    v132 = qcar(v131);
    v131 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    v132 = v133;
    v131 = (Lisp_Object)1; /* 0 */
    if (v132 == v131) goto v136;
    v131 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-4] = v131;
    goto v26;

v26:
    v131 = stack[-4];
    if (v131 == nil) goto v25;
    v131 = stack[-4];
    v131 = qcar(v131);
    stack[-3] = elt(env, 10); /* times */
    stack[-2] = v133;
    stack[-1] = qvalue(elt(env, 6)); /* !'or */
    stack[0] = v131;
    v132 = elt(env, 11); /* not */
    v131 = list2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v132 = list3(stack[-1], stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = list3(stack[-3], stack[-2], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    v131 = stack[-4];
    v131 = qcdr(v131);
    stack[-4] = v131;
    goto v26;

v25:
    v131 = v133;
    fn = elt(env, 17); /* simp!-prop!-dist */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    v132 = elt(env, 12); /* full */
    v131 = stack[-5];
    v131 = Lmember(nil, v132, v131);
    if (!(v131 == nil)) goto v54;
    v131 = v133;
    fn = elt(env, 18); /* simp!-prop2 */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    goto v54;

v54:
    v131 = v133;
    fn = elt(env, 19); /* simp!-prop!-form */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    v131 = v133;
    if (is_number(v131)) goto v49;
    v131 = v133;
    if (!consp(v131)) goto v137;
    v131 = elt(env, 13); /* boolean */
    v132 = v133;
    v131 = list2(v131, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v133 = v131;
    goto v137;

v137:
    v132 = (Lisp_Object)17; /* 1 */
    v131 = (Lisp_Object)17; /* 1 */
    v133 = acons(v133, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v132 = qvalue(elt(env, 2)); /* nil */
    v131 = (Lisp_Object)17; /* 1 */
    v131 = acons(v133, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    goto v20;

v20:
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    { popv(8); return onevalue(v131); }

v49:
    v132 = v133;
    v131 = (Lisp_Object)17; /* 1 */
    v131 = cons(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    goto v20;

v136:
    v131 = qvalue(elt(env, 8)); /* !'false */
    fn = elt(env, 20); /* simp */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    goto v20;

v91:
    v131 = elt(env, 3); /* and */
    qvalue(elt(env, 5)) = v131; /* !'and */
    v131 = elt(env, 4); /* or */
    qvalue(elt(env, 6)) = v131; /* !'or */
    v131 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v131; /* !'true */
    v131 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v131; /* !'false */
    goto v135;

v85:
    v131 = qvalue(elt(env, 2)); /* nil */
    goto v2;
/* error exit handlers */
v134:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    popv(8);
    return nil;
}



/* Code for njets */

static Lisp_Object CC_njets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for njets");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v3 = v8;
    v4 = v0;
/* end of prologue */
    stack[-1] = v3;
    stack[0] = v3;
    v3 = v4;
    v3 = sub1(v3);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v3 = plus2(stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    {
        Lisp_Object v6 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* combin */
        return (*qfn2(fn))(qenv(fn), v6, v3);
    }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v154 = stack[-1];
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v89;
    v154 = stack[0];
    v153 = (Lisp_Object)33; /* 2 */
    if (v154 == v153) goto v88;
    v153 = qvalue(elt(env, 3)); /* nil */
    goto v3;

v3:
    if (v153 == nil) goto v19;
    v153 = elt(env, 4); /* i */
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v153);
    }

v19:
    v154 = stack[-1];
    v153 = elt(env, 5); /* expt */
    if (!consp(v154)) goto v126;
    v154 = qcar(v154);
    if (!(v154 == v153)) goto v126;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = integerp(v153);
    if (v153 == nil) goto v29;
    v153 = qvalue(elt(env, 6)); /* !*precise_complex */
    v153 = (v153 == nil ? lisp_true : nil);
    goto v127;

v127:
    if (v153 == nil) goto v100;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v154 = qcar(v153);
    v153 = stack[0];
    v154 = CC_mkrootsq(env, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    {
        popv(4);
        fn = elt(env, 11); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v100:
    stack[-2] = nil;
    v153 = stack[-1];
    v153 = integerp(v153);
    if (v153 == nil) goto v157;
    v153 = stack[-1];
    v153 = Lminusp(nil, v153);
    env = stack[-3];
    if (v153 == nil) goto v119;
    v153 = qvalue(elt(env, 3)); /* nil */
    goto v112;

v112:
    if (v153 == nil) goto v157;
    v154 = stack[-2];
    v153 = stack[0];
    {
        popv(4);
        fn = elt(env, 12); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v157:
    v154 = stack[0];
    v153 = (Lisp_Object)33; /* 2 */
    if (v154 == v153) goto v110;
    stack[-2] = elt(env, 5); /* expt */
    v155 = elt(env, 9); /* quotient */
    v154 = (Lisp_Object)17; /* 1 */
    v153 = stack[0];
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    v153 = list3(stack[-2], stack[-1], v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    goto v158;

v158:
    stack[-2] = v153;
    v153 = stack[-2];
    fn = elt(env, 13); /* opmtch */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    v154 = v153;
    if (v153 == nil) goto v159;
    v153 = v154;
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v153);
    }

v159:
    v154 = stack[-2];
    v153 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 14); /* mksq */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v110:
    v153 = stack[-1];
    fn = elt(env, 15); /* mksqrt */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    goto v158;

v119:
    stack[-2] = stack[-1];
    v154 = stack[-1];
    v153 = qvalue(elt(env, 7)); /* factorbound!* */
    v153 = (Lisp_Object)lessp2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v153 = v153 ? lisp_true : nil;
    env = stack[-3];
    if (!(v153 == nil)) goto v160;
    v153 = qvalue(elt(env, 8)); /* !*ifactor */
    goto v160;

v160:
    fn = elt(env, 16); /* zfactor1 */
    v153 = (*qfn2(fn))(qenv(fn), stack[-2], v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    stack[-2] = v153;
    v154 = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    v153 = (Lisp_Object)greaterp2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v153 = v153 ? lisp_true : nil;
    env = stack[-3];
    if (!(v153 == nil)) goto v112;
    v153 = stack[-2];
    v153 = qcar(v153);
    v154 = qcdr(v153);
    v153 = (Lisp_Object)17; /* 1 */
    v153 = (Lisp_Object)greaterp2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v153 = v153 ? lisp_true : nil;
    env = stack[-3];
    goto v112;

v29:
    v153 = qvalue(elt(env, 3)); /* nil */
    goto v127;

v126:
    v153 = qvalue(elt(env, 3)); /* nil */
    goto v127;

v88:
    v154 = stack[-1];
    v153 = (Lisp_Object)-15; /* -1 */
    if (v154 == v153) goto v34;
    v154 = stack[-1];
    v153 = elt(env, 2); /* (minus 1) */
    v153 = (equal(v154, v153) ? lisp_true : nil);
    goto v3;

v34:
    v153 = qvalue(elt(env, 1)); /* t */
    goto v3;

v89:
    v153 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 17); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v153);
    }
/* error exit handlers */
v156:
    popv(4);
    return nil;
}



/* Code for update_components */

static Lisp_Object MS_CDECL CC_update_components(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v87, v13, v10;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update_components");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update_components");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v13 = v50;
    stack[0] = v8;
    v42 = v0;
/* end of prologue */
    stack[-1] = v42;
    goto v129;

v129:
    v42 = stack[-1];
    if (v42 == nil) { popv(3); return onevalue(v13); }
    v42 = stack[-1];
    v42 = qcar(v42);
    v87 = v42;
    v10 = v87;
    v42 = stack[0];
    v42 = Lassoc(nil, v10, v42);
    v10 = v42;
    if (v42 == nil) goto v9;
    v42 = v13;
    v42 = Lassoc(nil, v87, v42);
    if (!(v42 == nil)) goto v9;
    v42 = v10;
    v87 = v13;
    v42 = cons(v42, v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v13 = v42;
    goto v9;

v9:
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    goto v129;
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for !*multsq */

static Lisp_Object CC_Hmultsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v8;
    stack[-3] = v0;
/* end of prologue */
    v137 = stack[-3];
    v137 = qcar(v137);
    if (v137 == nil) goto v21;
    v137 = stack[-2];
    v137 = qcar(v137);
    v137 = (v137 == nil ? lisp_true : nil);
    goto v90;

v90:
    if (v137 == nil) goto v88;
    v174 = qvalue(elt(env, 2)); /* nil */
    v137 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v174, v137);

v88:
    v137 = stack[-3];
    v174 = qcdr(v137);
    v137 = (Lisp_Object)17; /* 1 */
    if (v174 == v137) goto v33;
    v137 = qvalue(elt(env, 2)); /* nil */
    goto v12;

v12:
    if (v137 == nil) goto v175;
    v137 = stack[-3];
    v174 = qcar(v137);
    v137 = stack[-2];
    v137 = qcar(v137);
    fn = elt(env, 3); /* !*multf */
    v174 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v137 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v174, v137);

v175:
    v137 = stack[-3];
    v174 = qcar(v137);
    v137 = stack[-2];
    v137 = qcdr(v137);
    fn = elt(env, 4); /* gcdf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v137;
    v137 = stack[-2];
    v174 = qcar(v137);
    v137 = stack[-3];
    v137 = qcdr(v137);
    fn = elt(env, 4); /* gcdf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-1] = v137;
    v137 = stack[-3];
    v174 = qcar(v137);
    v137 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v137 = stack[-2];
    v174 = qcar(v137);
    v137 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v137 = (*qfn2(fn))(qenv(fn), stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[0] = v137;
    v137 = stack[-3];
    v174 = qcdr(v137);
    v137 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v137 = stack[-2];
    v174 = qcdr(v137);
    v137 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v137 = (*qfn2(fn))(qenv(fn), stack[-1], v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v137;
    v137 = stack[-4];
    fn = elt(env, 6); /* minusf */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    if (v137 == nil) goto v149;
    v137 = stack[0];
    fn = elt(env, 7); /* negf */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[0] = v137;
    v137 = stack[-4];
    fn = elt(env, 7); /* negf */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v137;
    goto v149;

v149:
    v174 = stack[0];
    v137 = stack[-4];
    fn = elt(env, 4); /* gcdf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-1] = v137;
    v174 = stack[-1];
    v137 = (Lisp_Object)17; /* 1 */
    if (v174 == v137) goto v49;
    v174 = stack[0];
    v137 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v174 = stack[-4];
    v137 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v137 = (*qfn2(fn))(qenv(fn), v174, v137);
    nil = C_nil;
    if (exception_pending()) goto v106;
    {
        Lisp_Object v102 = stack[0];
        popv(6);
        return cons(v102, v137);
    }

v49:
    v174 = stack[0];
    v137 = stack[-4];
    popv(6);
    return cons(v174, v137);

v33:
    v137 = stack[-2];
    v174 = qcdr(v137);
    v137 = (Lisp_Object)17; /* 1 */
    v137 = (v174 == v137 ? lisp_true : nil);
    goto v12;

v21:
    v137 = qvalue(elt(env, 1)); /* t */
    goto v90;
/* error exit handlers */
v106:
    popv(6);
    return nil;
}



/* Code for ratpoly_red */

static Lisp_Object CC_ratpoly_red(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_red");
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
    stack[0] = v0;
/* end of prologue */
    v47 = stack[0];
    v47 = qcar(v47);
    fn = elt(env, 1); /* numpoly_red */
    v39 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v47 = stack[0];
    v47 = qcdr(v47);
    popv(1);
    return cons(v39, v47);
/* error exit handlers */
v70:
    popv(1);
    return nil;
}



/* Code for bc_2a */

static Lisp_Object CC_bc_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* prepf */
        return (*qfn1(fn))(qenv(fn), v38);
    }
}



/* Code for pdiffvars */

static Lisp_Object CC_pdiffvars(Lisp_Object env,
                         Lisp_Object v8, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdiffvars");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v8);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v8,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v50;
    v67 = v8;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* ind */
    qvalue(elt(env, 1)) = nil; /* ind */
    qvalue(elt(env, 1)) = v67; /* ind */
    v67 = qvalue(elt(env, 1)); /* ind */
    if (v67 == nil) goto v47;
    v33 = stack[-1];
    v67 = qvalue(elt(env, 1)); /* ind */
    v67 = qcar(v67);
    fn = elt(env, 2); /* pnth */
    v67 = (*qfn2(fn))(qenv(fn), v33, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    stack[0] = qcar(v67);
    v67 = qvalue(elt(env, 1)); /* ind */
    v33 = qcdr(v67);
    v67 = stack[-1];
    v67 = CC_pdiffvars(env, v33, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v67 = cons(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    goto v20;

v20:
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    { popv(4); return onevalue(v67); }

v47:
    v67 = nil;
    goto v20;
/* error exit handlers */
v82:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    popv(4);
    return nil;
}



/* Code for ldf!-sep!-var */

static Lisp_Object CC_ldfKsepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-sep-var");
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
    v4 = stack[0];
    fn = elt(env, 1); /* ldf!-pow!-var */
    stack[-1] = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v4 = stack[0];
    fn = elt(env, 2); /* ldf!-dep!-var */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    fn = elt(env, 3); /* compl */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v4);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v4 = stack[0];
    fn = elt(env, 4); /* ldf!-spf!-var */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    {
        Lisp_Object v6 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* compl */
        return (*qfn2(fn))(qenv(fn), v6, v4);
    }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for addns */

static Lisp_Object CC_addns(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v100, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addns");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v20;

v20:
    v46 = stack[0];
    if (v46 == nil) goto v47;
    v46 = stack[-1];
    v100 = qcdr(v46);
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = qcdr(v46);
    if (equal(v100, v46)) goto v33;
    v46 = stack[-1];
    v100 = qcdr(v46);
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = qcdr(v46);
    fn = elt(env, 1); /* ordp */
    v46 = (*qfn2(fn))(qenv(fn), v100, v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    if (v46 == nil) goto v96;
    v100 = stack[-1];
    v46 = stack[0];
    v46 = cons(v100, v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    {
        Lisp_Object v179 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v179, v46);
    }

v96:
    v46 = stack[0];
    v100 = qcar(v46);
    v46 = stack[-2];
    v46 = cons(v100, v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[-2] = v46;
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v20;

v33:
    v46 = stack[-1];
    v100 = qcar(v46);
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = qcar(v46);
    fn = elt(env, 3); /* addsq */
    v46 = (*qfn2(fn))(qenv(fn), v100, v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v77 = v46;
    v46 = stack[-1];
    v100 = qcdr(v46);
    v46 = stack[0];
    v46 = qcdr(v46);
    v46 = acons(v77, v100, v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    {
        Lisp_Object v180 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v180, v46);
    }

v47:
    stack[0] = stack[-2];
    v46 = stack[-1];
    v46 = ncons(v46);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    {
        Lisp_Object v61 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v61, v46);
    }
/* error exit handlers */
v169:
    popv(4);
    return nil;
}



/* Code for mkprec */

static Lisp_Object MS_CDECL CC_mkprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v183;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprec");
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
    v62 = qvalue(elt(env, 1)); /* fixedpreclis!* */
    v61 = qvalue(elt(env, 2)); /* preclis!* */
    v61 = Lappend(nil, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-3] = v61;
    v61 = (Lisp_Object)17; /* 1 */
    stack[-2] = v61;
    goto v20;

v20:
    v61 = stack[-3];
    if (v61 == nil) goto v98;
    v61 = stack[-3];
    v183 = qcar(v61);
    v62 = elt(env, 4); /* infix */
    v61 = stack[-2];
    v61 = Lputprop(nil, 3, v183, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v61 = stack[-3];
    stack[-1] = qcar(v61);
    stack[0] = elt(env, 5); /* op */
    v62 = stack[-2];
    v61 = stack[-2];
    v61 = list2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v61 = Lputprop(nil, 3, stack[-1], stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v61 = stack[-3];
    v62 = qcar(v61);
    v61 = elt(env, 6); /* unary */
    v61 = get(v62, v61);
    env = stack[-4];
    stack[0] = v61;
    if (v61 == nil) goto v87;
    v183 = stack[0];
    v62 = elt(env, 4); /* infix */
    v61 = stack[-2];
    v61 = Lputprop(nil, 3, v183, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    goto v87;

v87:
    v61 = stack[0];
    if (v61 == nil) goto v184;
    v62 = stack[0];
    v61 = elt(env, 7); /* nary */
    v61 = Lflagp(nil, v62, v61);
    env = stack[-4];
    if (!(v61 == nil)) goto v184;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* op */
    v62 = qvalue(elt(env, 3)); /* nil */
    v61 = stack[-2];
    v61 = list2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v61 = Lputprop(nil, 3, stack[-1], stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    goto v184;

v184:
    v61 = stack[-3];
    v61 = qcdr(v61);
    stack[-3] = v61;
    v61 = stack[-2];
    v61 = add1(v61);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-2] = v61;
    goto v20;

v98:
    v61 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v61); }
/* error exit handlers */
v112:
    popv(5);
    return nil;
}



/* Code for xquotient!-mod!-p */

static Lisp_Object MS_CDECL CC_xquotientKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v137, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xquotient-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xquotient-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    v164 = stack[-2];
    if (v164 == nil) goto v20;
    v164 = stack[-2];
    if (!consp(v164)) goto v98;
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = (consp(v164) ? nil : lisp_true);
    goto v85;

v85:
    if (v164 == nil) goto v40;
    v164 = qvalue(elt(env, 2)); /* t */
    goto v47;

v47:
    if (v164 == nil) goto v43;
    v164 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v164; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v164); }

v43:
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v137 = qcdr(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcdr(v164);
    if (equal(v137, v164)) goto v28;
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcar(v164);
    fn = elt(env, 4); /* fkern */
    v174 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v137 = qcdr(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcdr(v164);
    v164 = (Lisp_Object)(int32_t)((int32_t)v137 - (int32_t)v164 + TAG_FIXNUM);
    fn = elt(env, 5); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v174, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v164 = stack[-2];
    v164 = qcar(v164);
    v137 = qcdr(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcdr(v164);
    fn = elt(env, 6); /* quotient!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), v137, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v164 = cons(stack[-3], v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[-3] = v164;
    v164 = stack[-2];
    stack[-2] = qcdr(v164);
    v164 = stack[-3];
    fn = elt(env, 7); /* negate!-term */
    v137 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v164 = stack[-1];
    v164 = qcdr(v164);
    fn = elt(env, 8); /* times!-term!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), v137, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    fn = elt(env, 9); /* plus!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), stack[-2], v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[-2] = v164;
    v174 = stack[-2];
    v137 = stack[-1];
    v164 = stack[0];
    v164 = CC_xquotientKmodKp(env, 3, v174, v137, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v106 = stack[-3];
        popv(5);
        return cons(v106, v164);
    }

v28:
    v164 = stack[-2];
    v164 = qcar(v164);
    v137 = qcdr(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcdr(v164);
    fn = elt(env, 6); /* quotient!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), v137, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[0] = v164;
    v164 = stack[0];
    if (v164 == nil) goto v123;
    v137 = stack[0];
    v164 = stack[-1];
    fn = elt(env, 10); /* times!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), v137, v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    fn = elt(env, 11); /* difference!-mod!-p */
    v164 = (*qfn2(fn))(qenv(fn), stack[-2], v164);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    goto v75;

v75:
    if (v164 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v164 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v164; /* exact!-quotient!-flag */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v123:
    v164 = qvalue(elt(env, 2)); /* t */
    goto v75;

v40:
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v137 = qcar(v164);
    v164 = stack[0];
    if (equal(v137, v164)) goto v80;
    v164 = qvalue(elt(env, 2)); /* t */
    goto v47;

v80:
    v164 = stack[-2];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v137 = qcdr(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcdr(v164);
    v164 = ((intptr_t)v137 < (intptr_t)v164) ? lisp_true : nil;
    goto v47;

v98:
    v164 = qvalue(elt(env, 2)); /* t */
    goto v85;

v20:
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v164); }
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for lto_alunion */

static Lisp_Object CC_lto_alunion(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_alunion");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v0;
/* end of prologue */
    v2 = v129;
    v129 = elt(env, 1); /* union */
    {
        fn = elt(env, 2); /* lto_almerge */
        return (*qfn2(fn))(qenv(fn), v2, v129);
    }
}



/* Code for texexplode */

static Lisp_Object CC_texexplode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v28, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texexplode");
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
    v28 = v0;
/* end of prologue */
    v194 = v28;
    if (v194 == nil) goto v90;
    v194 = v28;
    if (!(!consp(v194))) goto v90;
    v27 = v28;
    v194 = elt(env, 1); /* texname */
    v194 = get(v27, v194);
    env = stack[0];
    if (!(v194 == nil)) goto v85;
    v27 = v28;
    v194 = elt(env, 2); /* class */
    v194 = get(v27, v194);
    env = stack[0];
    if (v194 == nil) goto v16;
    v194 = v28;
    goto v85;

v85:
    if (!(v194 == nil)) goto v20;
    v194 = v28;
    if (is_number(v194)) goto v82;
    v194 = v28;
    v194 = Lstringp(nil, v194);
    env = stack[0];
    if (v194 == nil) goto v74;
    v194 = v28;
    v194 = Lexplodec(nil, v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    fn = elt(env, 5); /* strcollect */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    goto v20;

v20:
    v28 = v194;
    v194 = v28;
    if (v194 == nil) goto v173;
    v194 = v28;
    if (!(!consp(v194))) { popv(1); return onevalue(v28); }
    v194 = v28;
    popv(1);
    return ncons(v194);

v173:
    v194 = elt(env, 4); /* !  */
    popv(1);
    return ncons(v194);

v74:
    v194 = v28;
    v194 = Lexplodec(nil, v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    fn = elt(env, 7); /* texexplist */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    goto v20;

v82:
    v194 = v28;
    v194 = Lexplode(nil, v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    goto v20;

v16:
    v194 = qvalue(elt(env, 3)); /* nil */
    goto v85;

v90:
    v194 = nil;
    goto v20;
/* error exit handlers */
v125:
    popv(1);
    return nil;
}



/* Code for cl_smsimpl!-junct1 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v50, Lisp_Object v11,
                         Lisp_Object v38, Lisp_Object v89,
                         Lisp_Object v20, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v238, v239, v240, v241, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct1");
#endif
    if (stack >= stacklimit)
    {
        push6(v20,v89,v38,v11,v50,v8);
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v8,v50,v11,v38,v89);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v20;
    stack[-4] = v89;
    stack[-5] = v38;
    stack[-6] = v11;
    stack[-7] = v50;
    v237 = v8;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v98;

v98:
    v237 = stack[-7];
    if (v237 == nil) goto v243;
    v237 = stack[-7];
    v237 = qcar(v237);
    stack[-9] = v237;
    v237 = stack[-7];
    v237 = qcdr(v237);
    stack[-7] = v237;
    stack[-10] = stack[-9];
    stack[0] = stack[-5];
    v237 = stack[-4];
    v238 = sub1(v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    v237 = stack[-8];
    fn = elt(env, 17); /* cl_simpl1 */
    v237 = (*qfnn(fn))(qenv(fn), 4, stack[-10], stack[0], v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-10] = v237;
    v237 = stack[-10];
    if (!consp(v237)) goto v83;
    v237 = stack[-10];
    v237 = qcar(v237);
    goto v82;

v82:
    v239 = v237;
    v238 = v239;
    v237 = stack[-3];
    if (v238 == v237) goto v13;
    v238 = v239;
    v237 = stack[-8];
    if (v238 == v237) goto v91;
    v238 = v239;
    v237 = elt(env, 3); /* true */
    if (v238 == v237) goto v119;
    v238 = v239;
    v237 = elt(env, 5); /* false */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v245;

v245:
    if (v237 == nil) goto v72;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v246;

v246:
    if (v237 == nil) goto v247;
    stack[0] = v239;
    v237 = stack[-3];
    fn = elt(env, 18); /* cl_flip */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    if (equal(stack[0], v237)) goto v87;
    v238 = stack[-10];
    v237 = stack[-2];
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-2] = v237;
    goto v87;

v87:
    v237 = stack[-1];
    if (v237 == nil) goto v98;
    v240 = stack[-8];
    v239 = stack[-1];
    v238 = stack[-5];
    v237 = stack[-4];
    fn = elt(env, 19); /* rl_smupdknowl */
    v237 = (*qfnn(fn))(qenv(fn), 4, v240, v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-5] = v237;
    v238 = stack[-5];
    v237 = elt(env, 5); /* false */
    if (!(v238 == v237)) goto v248;
    v237 = stack[-3];
    stack[-9] = v237;
    v237 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v237;
    goto v248;

v248:
    v237 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v237;
    goto v98;

v247:
    v237 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v237 == nil) goto v249;
    v237 = stack[-2];
    v238 = Lnreverse(nil, v237);
    env = stack[-11];
    v237 = stack[-7];
    v237 = Lnconc(nil, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-7] = v237;
    v237 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v237;
    goto v249;

v249:
    v237 = stack[-10];
    v237 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-1] = v237;
    goto v87;

v72:
    v238 = v239;
    v237 = elt(env, 6); /* or */
    if (v238 == v237) goto v49;
    v238 = v239;
    v237 = elt(env, 7); /* and */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v250;

v250:
    if (v237 == nil) goto v161;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v251;

v251:
    if (v237 == nil) goto v106;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v147;

v147:
    if (v237 == nil) goto v252;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v246;

v252:
    v238 = v239;
    v237 = elt(env, 12); /* ex */
    if (v238 == v237) goto v253;
    v238 = v239;
    v237 = elt(env, 13); /* all */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v254;

v254:
    if (v237 == nil) goto v255;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v246;

v255:
    v238 = v239;
    v237 = elt(env, 14); /* bex */
    if (v238 == v237) goto v256;
    v238 = v239;
    v237 = elt(env, 15); /* ball */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v257;

v257:
    if (v237 == nil) goto v258;
    v237 = qvalue(elt(env, 4)); /* t */
    goto v246;

v258:
    v238 = v239;
    v237 = elt(env, 16); /* rl_external */
    v237 = get(v238, v237);
    env = stack[-11];
    goto v246;

v256:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v257;

v253:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v254;

v106:
    v238 = v239;
    v237 = elt(env, 9); /* impl */
    if (v238 == v237) goto v107;
    v238 = v239;
    v237 = elt(env, 10); /* repl */
    if (v238 == v237) goto v159;
    v238 = v239;
    v237 = elt(env, 11); /* equiv */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v147;

v159:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v147;

v107:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v147;

v161:
    v238 = v239;
    v237 = elt(env, 8); /* not */
    v237 = (v238 == v237 ? lisp_true : nil);
    goto v251;

v49:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v250;

v119:
    v237 = qvalue(elt(env, 4)); /* t */
    goto v245;

v91:
    v237 = stack[-10];
    v237 = qcdr(v237);
    stack[0] = v237;
    goto v194;

v194:
    v237 = stack[0];
    if (v237 == nil) goto v184;
    v237 = stack[0];
    v237 = qcar(v237);
    fn = elt(env, 20); /* cl_atfp */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    if (v237 == nil) goto v184;
    v237 = stack[0];
    v238 = qcar(v237);
    v237 = stack[-1];
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-1] = v237;
    v237 = stack[0];
    v237 = qcdr(v237);
    stack[0] = v237;
    goto v194;

v184:
    v237 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v237 == nil) goto v59;
    v237 = stack[-1];
    if (v237 == nil) goto v59;
    v237 = stack[-2];
    v238 = Lnreverse(nil, v237);
    env = stack[-11];
    v237 = stack[-7];
    v237 = Lnconc(nil, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-7] = v237;
    v237 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v237;
    goto v59;

v59:
    v237 = stack[0];
    v237 = Lreverse(nil, v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    v237 = Lnconc(nil, stack[-2], v237);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-11];
    stack[-2] = v237;
    goto v87;

v13:
    v237 = stack[-3];
    stack[-9] = v237;
    v237 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v237;
    goto v87;

v83:
    v237 = stack[-10];
    goto v82;

v243:
    v238 = stack[-9];
    v237 = stack[-3];
    if (v238 == v237) goto v259;
    v242 = stack[-8];
    v241 = stack[-2];
    v240 = stack[-6];
    v239 = stack[-5];
    v238 = stack[-4];
    v237 = stack[-3];
    {
        popv(12);
        fn = elt(env, 21); /* cl_smsimpl!-junct2 */
        return (*qfnn(fn))(qenv(fn), 6, v242, v241, v240, v239, v238, v237);
    }

v259:
    v237 = stack[-3];
    popv(12);
    return ncons(v237);
/* error exit handlers */
v244:
    popv(12);
    return nil;
}



/* Code for lowupperlimitml */

static Lisp_Object CC_lowupperlimitml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
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
    v16 = elt(env, 1); /* "<lowlimit>" */
    fn = elt(env, 7); /* printout */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 9); /* expression */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = elt(env, 4); /* "</lowlimit>" */
    fn = elt(env, 7); /* printout */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = elt(env, 5); /* "<uplimit>" */
    fn = elt(env, 7); /* printout */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 9); /* expression */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v16 = elt(env, 6); /* "</uplimit>" */
    fn = elt(env, 7); /* printout */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v16 = nil;
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for sprow_dim */

static Lisp_Object CC_sprow_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sprow_dim");
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
    v260 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v260 == nil) goto v2;
    v260 = qvalue(elt(env, 2)); /* nil */
    goto v129;

v129:
    if (v260 == nil) goto v20;
    v260 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v260 == nil)) goto v86;
    v260 = elt(env, 4); /* "Error in sprow_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    goto v86;

v86:
    v260 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    goto v20;

v20:
    v260 = stack[0];
    fn = elt(env, 6); /* spmatlength */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v260 = qcdr(v260);
    v260 = qcar(v260);
    { popv(2); return onevalue(v260); }

v2:
    v260 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v260 = (v260 == nil ? lisp_true : nil);
    goto v129;
/* error exit handlers */
v193:
    popv(2);
    return nil;
}



/* Code for dipreplus */

static Lisp_Object CC_dipreplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipreplus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v6 = v7;
    if (!consp(v6)) return onevalue(v7);
    v6 = v7;
    v6 = qcdr(v6);
    if (v6 == nil) goto v90;
    v6 = elt(env, 1); /* plus */
    return cons(v6, v7);

v90:
    v6 = v7;
    v6 = qcar(v6);
    return onevalue(v6);
}



/* Code for vevzero!?1 */

static Lisp_Object CC_vevzeroW1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v87, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevzero?1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */

v261:
    v42 = v87;
    if (v42 == nil) goto v38;
    v42 = v87;
    v13 = qcar(v42);
    v42 = (Lisp_Object)1; /* 0 */
    if (v13 == v42) goto v1;
    v42 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v42);

v1:
    v42 = v87;
    v42 = qcdr(v42);
    if (v42 == nil) goto v6;
    v42 = v87;
    v42 = qcdr(v42);
    v13 = qcar(v42);
    v42 = (Lisp_Object)1; /* 0 */
    if (v13 == v42) goto v88;
    v42 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v42);

v88:
    v42 = v87;
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    v87 = v42;
    goto v261;

v6:
    v42 = qvalue(elt(env, 1)); /* t */
    return onevalue(v42);

v38:
    v42 = qvalue(elt(env, 1)); /* t */
    return onevalue(v42);
}



/* Code for ndepends */

static Lisp_Object CC_ndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ndepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v250 = stack[-1];
    if (v250 == nil) goto v21;
    v250 = stack[-1];
    v250 = (is_number(v250) ? lisp_true : nil);
    if (!(v250 == nil)) goto v90;
    v250 = stack[0];
    v250 = (is_number(v250) ? lisp_true : nil);
    goto v90;

v90:
    if (v250 == nil) goto v7;
    v250 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v250); }

v7:
    v49 = stack[-1];
    v250 = stack[0];
    if (equal(v49, v250)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v250 = stack[-1];
    if (!consp(v250)) goto v67;
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v99;

v99:
    if (v250 == nil) goto v42;
    v250 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v250); }

v42:
    v49 = stack[-1];
    v250 = qvalue(elt(env, 4)); /* depl!* */
    v250 = Lassoc(nil, v49, v250);
    v49 = v250;
    v250 = v49;
    if (v250 == nil) goto v182;
    v250 = v49;
    v49 = qcdr(v250);
    v250 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v250 = (*qfn2(fn))(qenv(fn), v49, v250);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    goto v43;

v43:
    if (v250 == nil) goto v66;
    v250 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v250); }

v66:
    v250 = stack[-1];
    if (!consp(v250)) goto v46;
    v250 = stack[-1];
    v250 = qcar(v250);
    if (symbolp(v250)) goto v123;
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v126;

v126:
    if (v250 == nil) goto v27;
    v250 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v250); }

v27:
    v250 = stack[-1];
    fn = elt(env, 7); /* atomf */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    if (v250 == nil) goto v112;
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v179;

v179:
    if (v250 == nil) goto v122;
    v250 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v250); }

v122:
    v250 = stack[0];
    fn = elt(env, 7); /* atomf */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    if (!(v250 == nil)) goto v55;
    v250 = stack[0];
    v250 = qcar(v250);
    if (!(symbolp(v250))) goto v147;
    v250 = stack[0];
    v49 = qcar(v250);
    v250 = elt(env, 5); /* dname */
    v250 = get(v49, v250);
    env = stack[-2];
    if (!(v250 == nil)) goto v55;

v147:
    v49 = stack[-1];
    v250 = stack[0];
    v250 = qcdr(v250);
    {
        popv(3);
        fn = elt(env, 8); /* ndependsl */
        return (*qfn2(fn))(qenv(fn), v49, v250);
    }

v55:
    v250 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v250); }

v112:
    v250 = stack[-1];
    v49 = qcdr(v250);
    v250 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v250 = (*qfn2(fn))(qenv(fn), v49, v250);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    if (!(v250 == nil)) goto v179;
    v250 = stack[-1];
    v49 = qcar(v250);
    v250 = stack[0];
    v250 = CC_ndepends(env, v49, v250);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    goto v179;

v123:
    v250 = stack[-1];
    v49 = qcar(v250);
    v250 = elt(env, 5); /* dname */
    v250 = get(v49, v250);
    env = stack[-2];
    goto v126;

v46:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v126;

v182:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v43;

v67:
    v49 = stack[-1];
    v250 = qvalue(elt(env, 3)); /* frlis!* */
    v250 = Lmemq(nil, v49, v250);
    goto v99;

v21:
    v250 = qvalue(elt(env, 1)); /* t */
    goto v90;
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



/* Code for mkupf */

static Lisp_Object CC_mkupf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v115, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkupf");
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
    v264 = v0;
/* end of prologue */
    v115 = v264;
    v264 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* mksq */
    v264 = (*qfn2(fn))(qenv(fn), v115, v264);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[0];
    v265 = v264;
    v264 = v265;
    v264 = qcar(v264);
    if (v264 == nil) goto v69;
    v264 = v265;
    v264 = qcar(v264);
    if (!consp(v264)) goto v6;
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = (consp(v264) ? nil : lisp_true);
    goto v86;

v86:
    if (v264 == nil) goto v94;
    v264 = (Lisp_Object)17; /* 1 */
    v115 = v265;
    v264 = cons(v264, v115);
    nil = C_nil;
    if (exception_pending()) goto v187;
    popv(1);
    return ncons(v264);

v94:
    v264 = v265;
    v115 = qcdr(v264);
    v264 = (Lisp_Object)17; /* 1 */
    if (v115 == v264) goto v18;
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v80;

v80:
    if (v264 == nil) goto v266;
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    v265 = qcar(v264);
    v115 = (Lisp_Object)17; /* 1 */
    v264 = (Lisp_Object)17; /* 1 */
    v264 = list2star(v265, v115, v264);
    nil = C_nil;
    if (exception_pending()) goto v187;
    popv(1);
    return ncons(v264);

v266:
    v264 = v265;
    {
        popv(1);
        fn = elt(env, 4); /* partitsq!* */
        return (*qfn1(fn))(qenv(fn), v264);
    }

v18:
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcar(v264);
    v115 = qcdr(v264);
    v264 = (Lisp_Object)17; /* 1 */
    if (v115 == v264) goto v128;
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v80;

v128:
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcdr(v264);
    if (v264 == nil) goto v44;
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v80;

v44:
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    if (!consp(v264)) goto v96;
    v264 = v265;
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = qcar(v264);
    v264 = (consp(v264) ? nil : lisp_true);
    v264 = (v264 == nil ? lisp_true : nil);
    goto v194;

v194:
    v264 = (v264 == nil ? lisp_true : nil);
    goto v80;

v96:
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v194;

v6:
    v264 = qvalue(elt(env, 2)); /* t */
    goto v86;

v69:
    v264 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v264); }
/* error exit handlers */
v187:
    popv(1);
    return nil;
}



/* Code for gfdiffer */

static Lisp_Object CC_gfdiffer(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfdiffer");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v19 = stack[-1];
    v19 = qcar(v19);
    if (!consp(v19)) goto v70;
    v19 = stack[-1];
    v43 = qcar(v19);
    v19 = stack[0];
    v19 = qcar(v19);
    fn = elt(env, 1); /* difbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v19 = stack[-1];
    v43 = qcdr(v19);
    v19 = stack[0];
    v19 = qcdr(v19);
    fn = elt(env, 1); /* difbf */
    v19 = (*qfn2(fn))(qenv(fn), v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    {
        Lisp_Object v65 = stack[-2];
        popv(4);
        return cons(v65, v19);
    }

v70:
    v19 = stack[-1];
    v43 = qcar(v19);
    v19 = stack[0];
    v19 = qcar(v19);
    stack[-2] = difference2(v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v19 = stack[-1];
    v43 = qcdr(v19);
    v19 = stack[0];
    v19 = qcdr(v19);
    v19 = difference2(v43, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    {
        Lisp_Object v152 = stack[-2];
        popv(4);
        return cons(v152, v19);
    }
/* error exit handlers */
v24:
    popv(4);
    return nil;
}



/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v362, v363, v364, v365;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*1");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v50;
    stack[-5] = v8;
    stack[-6] = v0;
/* end of prologue */
    v362 = stack[-6];
    if (!consp(v362)) goto v3;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = (consp(v362) ? nil : lisp_true);
    goto v98;

v98:
    if (v362 == nil) goto v34;
    v362 = qvalue(elt(env, 3)); /* nil */
    goto v39;

v39:
    if (v362 == nil) goto v129;
    v363 = stack[-5];
    v362 = (Lisp_Object)17; /* 1 */
    if (v363 == v362) goto v178;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcdr(v362);
    stack[-2] = v362;
    v362 = stack[-5];
    stack[-1] = v362;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v364 = qcar(v362);
    v363 = (Lisp_Object)17; /* 1 */
    v362 = (Lisp_Object)17; /* 1 */
    v362 = acons(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    goto v120;

v120:
    v363 = stack[-1];
    v362 = stack[0];
    fn = elt(env, 14); /* quotfm */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-7] = v362;
    if (v362 == nil) goto v367;
    v362 = stack[-7];
    stack[-1] = v362;
    v362 = stack[-2];
    v362 = sub1(v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-2] = v362;
    goto v120;

v367:
    v362 = stack[-6];
    v362 = qcar(v362);
    v363 = qcdr(v362);
    v362 = stack[-1];
    stack[0] = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v363 = stack[-2];
    v362 = (Lisp_Object)1; /* 0 */
    v362 = (Lisp_Object)greaterp2(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v362 = v362 ? lisp_true : nil;
    env = stack[-8];
    if (v362 == nil) goto v142;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v364 = qcar(v362);
    v363 = stack[-2];
    v362 = stack[-4];
    v362 = acons(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v51;

v51:
    fn = elt(env, 15); /* prepsq!*0 */
    v362 = (*qfn2(fn))(qenv(fn), stack[0], v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    goto v215;

v215:
    v362 = stack[-6];
    v363 = qcdr(v362);
    v362 = stack[-5];
    v363 = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-4];
    fn = elt(env, 15); /* prepsq!*0 */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    {
        Lisp_Object v368 = stack[0];
        popv(9);
        return Lnconc(nil, v368, v362);
    }

v142:
    v363 = stack[-2];
    v362 = (Lisp_Object)1; /* 0 */
    v362 = (Lisp_Object)lessp2(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v362 = v362 ? lisp_true : nil;
    env = stack[-8];
    if (v362 == nil) goto v156;
    v364 = elt(env, 4); /* expt */
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v363 = qcar(v362);
    v362 = stack[-2];
    v362 = list3(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 16); /* fkern */
    v363 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* getpower */
    v363 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-4];
    v362 = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v51;

v156:
    v362 = stack[-4];
    goto v51;

v178:
    v362 = stack[-6];
    v362 = qcar(v362);
    v363 = qcdr(v362);
    v362 = stack[-5];
    stack[0] = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-6];
    v362 = qcar(v362);
    v363 = qcar(v362);
    v362 = stack[-4];
    v362 = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!*0 */
    v362 = (*qfn2(fn))(qenv(fn), stack[0], v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    goto v215;

v129:
    v362 = stack[-5];
    if (!consp(v362)) goto v369;
    v362 = stack[-5];
    v362 = qcar(v362);
    v362 = (consp(v362) ? nil : lisp_true);
    goto v228;

v228:
    if (!(v362 == nil)) goto v370;
    v362 = qvalue(elt(env, 5)); /* kord!* */
    stack[-3] = v362;
    goto v371;

v371:
    v362 = stack[-3];
    if (v362 == nil) goto v370;
    v362 = stack[-3];
    v362 = qcar(v362);
    stack[-2] = v362;
    v362 = (Lisp_Object)1; /* 0 */
    stack[-1] = v362;
    v364 = stack[-2];
    v363 = (Lisp_Object)17; /* 1 */
    v362 = (Lisp_Object)17; /* 1 */
    v362 = acons(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    goto v217;

v217:
    v363 = stack[-5];
    v362 = stack[0];
    fn = elt(env, 14); /* quotfm */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-7] = v362;
    if (v362 == nil) goto v372;
    v362 = stack[-1];
    v362 = sub1(v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-1] = v362;
    v362 = stack[-7];
    stack[-5] = v362;
    goto v217;

v372:
    v363 = stack[-1];
    v362 = (Lisp_Object)1; /* 0 */
    v362 = (Lisp_Object)lessp2(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v362 = v362 ? lisp_true : nil;
    env = stack[-8];
    if (v362 == nil) goto v373;
    v364 = elt(env, 4); /* expt */
    v363 = stack[-2];
    v362 = stack[-1];
    v362 = list3(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 16); /* fkern */
    v363 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* getpower */
    v363 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-4];
    v362 = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-4] = v362;
    goto v373;

v373:
    v362 = stack[-3];
    v362 = qcdr(v362);
    stack[-3] = v362;
    goto v371;

v370:
    v362 = stack[-6];
    fn = elt(env, 18); /* kernlp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    if (v362 == nil) goto v374;
    v363 = stack[-4];
    v362 = stack[-6];
    fn = elt(env, 19); /* mkkl */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v362 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v362;
    goto v374;

v374:
    v362 = qvalue(elt(env, 6)); /* dnl!* */
    if (v362 == nil) goto v375;
    v362 = qvalue(elt(env, 7)); /* !*allfac */
    if (v362 == nil) goto v376;
    v362 = stack[-6];
    fn = elt(env, 20); /* ckrn */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v377;

v377:
    stack[-1] = v362;
    v363 = stack[-1];
    v362 = qvalue(elt(env, 6)); /* dnl!* */
    fn = elt(env, 21); /* ckrn!* */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-7] = v362;
    v363 = stack[-1];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v363 = stack[-6];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v363 = stack[-5];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-5] = v362;
    goto v375;

v375:
    v362 = qvalue(elt(env, 8)); /* upl!* */
    if (v362 == nil) goto v378;
    v362 = stack[-5];
    fn = elt(env, 20); /* ckrn */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    v363 = stack[0];
    v362 = qvalue(elt(env, 8)); /* upl!* */
    fn = elt(env, 21); /* ckrn!* */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-7] = v362;
    v363 = stack[0];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    v363 = stack[-6];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v363 = stack[-5];
    v362 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-5] = v362;
    goto v379;

v379:
    stack[-1] = stack[-6];
    v363 = stack[-5];
    v362 = stack[0];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = cons(stack[-1], v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 23); /* canonsq */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v362 = stack[-6];
    v363 = qcar(v362);
    v362 = stack[0];
    fn = elt(env, 22); /* quotof */
    v363 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-6];
    v362 = qcdr(v362);
    v362 = cons(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v362 = qvalue(elt(env, 7)); /* !*allfac */
    if (v362 == nil) goto v380;
    v362 = stack[-6];
    v362 = qcar(v362);
    fn = elt(env, 20); /* ckrn */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-1] = v362;
    v362 = stack[-6];
    v362 = qcdr(v362);
    fn = elt(env, 20); /* ckrn */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    v363 = stack[-1];
    v362 = (Lisp_Object)17; /* 1 */
    if (v363 == v362) goto v381;
    v362 = qvalue(elt(env, 1)); /* t */
    goto v382;

v382:
    if (v362 == nil) goto v383;
    v363 = stack[-1];
    v362 = stack[-6];
    v362 = qcar(v362);
    if (equal(v363, v362)) goto v384;
    v362 = qvalue(elt(env, 1)); /* t */
    goto v385;

v385:
    if (v362 == nil) goto v380;
    v362 = stack[-6];
    v363 = qcdr(v362);
    v362 = stack[0];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-5] = v362;
    v362 = stack[-6];
    v363 = qcar(v362);
    v362 = stack[-1];
    fn = elt(env, 22); /* quotof */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v363 = stack[-4];
    v362 = stack[-1];
    fn = elt(env, 19); /* mkkl */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 13); /* prepf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-4] = v362;
    v362 = stack[0];
    fn = elt(env, 13); /* prepf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-1] = v362;
    v363 = stack[-4];
    v362 = stack[-6];
    fn = elt(env, 24); /* addfactors */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-6] = v362;
    v363 = stack[-1];
    v362 = stack[-5];
    fn = elt(env, 24); /* addfactors */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[-5] = v362;
    v363 = stack[-5];
    v362 = (Lisp_Object)17; /* 1 */
    if (v363 == v362) goto v386;
    v363 = stack[-6];
    v362 = elt(env, 11); /* minus */
    if (!consp(v363)) goto v387;
    v363 = qcar(v363);
    if (!(v363 == v362)) goto v387;
    stack[0] = elt(env, 11); /* minus */
    v364 = elt(env, 12); /* quotient */
    v362 = stack[-6];
    v362 = qcdr(v362);
    v363 = qcar(v362);
    v362 = stack[-5];
    v362 = list3(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = list2(stack[0], v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    goto v388;

v388:
    popv(9);
    return ncons(v362);

v387:
    v364 = elt(env, 12); /* quotient */
    v363 = stack[-6];
    v362 = stack[-5];
    v362 = list3(v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    goto v388;

v386:
    v362 = stack[-6];
    v363 = elt(env, 10); /* plus */
    if (!consp(v362)) goto v389;
    v362 = qcar(v362);
    if (!(v362 == v363)) goto v389;
    v362 = stack[-6];
    v362 = qcdr(v362);
    { popv(9); return onevalue(v362); }

v389:
    v362 = stack[-6];
    popv(9);
    return ncons(v362);

v380:
    v362 = stack[-4];
    if (v362 == nil) goto v390;
    v365 = stack[-4];
    v364 = qvalue(elt(env, 3)); /* nil */
    v363 = qvalue(elt(env, 3)); /* nil */
    v362 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 25); /* exchk1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 4, v365, v364, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = stack[-6];
    v362 = qcar(v362);
    if (v362 == nil) goto v391;
    v363 = stack[-6];
    v362 = elt(env, 13); /* prepf */
    fn = elt(env, 26); /* sqform */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v392;

v392:
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    v362 = Lnconc(nil, stack[0], v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    fn = elt(env, 27); /* retimes */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    popv(9);
    return ncons(v362);

v391:
    v362 = (Lisp_Object)1; /* 0 */
    goto v392;

v390:
    v362 = stack[-6];
    v362 = qcar(v362);
    if (v362 == nil) goto v393;
    v363 = stack[-6];
    v362 = elt(env, 13); /* prepf */
    fn = elt(env, 26); /* sqform */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v394;

v394:
    v363 = v362;
    v362 = v363;
    v364 = elt(env, 10); /* plus */
    if (!consp(v362)) goto v395;
    v362 = qcar(v362);
    if (!(v362 == v364)) goto v395;
    v362 = v363;
    v362 = qcdr(v362);
    { popv(9); return onevalue(v362); }

v395:
    v362 = v363;
    popv(9);
    return ncons(v362);

v393:
    v362 = (Lisp_Object)1; /* 0 */
    goto v394;

v384:
    v363 = stack[0];
    v362 = stack[-6];
    v362 = qcdr(v362);
    v362 = Lneq(nil, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v385;

v383:
    v362 = qvalue(elt(env, 3)); /* nil */
    goto v385;

v381:
    v363 = stack[0];
    v362 = (Lisp_Object)17; /* 1 */
    v362 = Lneq(nil, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    goto v382;

v378:
    v362 = qvalue(elt(env, 9)); /* !*div */
    if (v362 == nil) goto v396;
    v362 = stack[-5];
    fn = elt(env, 20); /* ckrn */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-8];
    stack[0] = v362;
    goto v379;

v396:
    v362 = (Lisp_Object)17; /* 1 */
    stack[0] = v362;
    goto v379;

v376:
    v362 = (Lisp_Object)17; /* 1 */
    goto v377;

v369:
    v362 = qvalue(elt(env, 1)); /* t */
    goto v228;

v34:
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v363 = qcar(v362);
    v362 = qvalue(elt(env, 2)); /* factors!* */
    v362 = Lmember(nil, v363, v362);
    if (!(v362 == nil)) goto v39;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    if (!consp(v362)) goto v18;
    v362 = stack[-6];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    v363 = qcar(v362);
    v362 = qvalue(elt(env, 2)); /* factors!* */
    v362 = Lmember(nil, v363, v362);
    goto v39;

v18:
    v362 = qvalue(elt(env, 3)); /* nil */
    goto v39;

v3:
    v362 = qvalue(elt(env, 1)); /* t */
    goto v98;
/* error exit handlers */
v366:
    popv(9);
    return nil;
}



/* Code for equiv!-coeffs */

static Lisp_Object CC_equivKcoeffs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v20;

v20:
    v27 = stack[-1];
    if (v27 == nil) goto v47;
    v27 = stack[0];
    if (v27 == nil) goto v9;
    v27 = stack[-1];
    v27 = qcar(v27);
    v125 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = qcar(v27);
    if (equal(v125, v27)) goto v33;
    v27 = stack[-1];
    v27 = qcar(v27);
    v125 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = qcar(v27);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v27 = (*qfn2(fn))(qenv(fn), v125, v27);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    if (v27 == nil) goto v165;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v20;

v165:
    v125 = (Lisp_Object)1; /* 0 */
    v27 = stack[-2];
    v27 = cons(v125, v27);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    stack[-2] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v20;

v33:
    v27 = stack[-1];
    v27 = qcar(v27);
    v125 = qcdr(v27);
    v27 = stack[-2];
    v27 = cons(v125, v27);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    stack[-2] = v27;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v20;

v9:
    v27 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v27);
    }

v47:
    stack[-1] = stack[-2];
    v27 = stack[0];
    v27 = Llength(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    fn = elt(env, 3); /* nzeros */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    {
        Lisp_Object v64 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v64, v27);
    }
/* error exit handlers */
v136:
    popv(4);
    return nil;
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v67 = stack[-1];
    if (v67 == nil) goto v89;
    v33 = stack[-1];
    v67 = (Lisp_Object)49; /* 3 */
    v33 = *(Lisp_Object *)((char *)v33 + (CELL-TAG_VECTOR) + ((int32_t)v67/(16/CELL)));
    v67 = stack[0];
    stack[-2] = CC_hdiff(env, v33, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v33 = stack[-1];
    v67 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v67 = (*qfn2(fn))(qenv(fn), v33, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    {
        Lisp_Object v83 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v83, v67);
    }

v89:
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v67); }
/* error exit handlers */
v82:
    popv(4);
    return nil;
}



/* Code for difbf */

static Lisp_Object CC_difbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v256, v412;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difbf");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v8;
    stack[-7] = v0;
/* end of prologue */
    v257 = stack[-7];
    v257 = qcdr(v257);
    v256 = qcar(v257);
    stack[-8] = v256;
    v257 = (Lisp_Object)1; /* 0 */
    if (v256 == v257) goto v84;
    v257 = stack[-6];
    v257 = qcdr(v257);
    v256 = qcar(v257);
    stack[-5] = v256;
    v257 = (Lisp_Object)1; /* 0 */
    if (v256 == v257) goto v68;
    v257 = stack[-7];
    v257 = qcdr(v257);
    v256 = qcdr(v257);
    stack[-4] = v256;
    v257 = stack[-6];
    v257 = qcdr(v257);
    v257 = qcdr(v257);
    stack[-3] = v257;
    v256 = difference2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    stack[-2] = v256;
    v257 = (Lisp_Object)1; /* 0 */
    if (v256 == v257) goto v175;
    stack[-1] = stack[-2];
    v257 = stack[-8];
    v257 = Labsval(nil, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-5];
    v257 = Labsval(nil, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = difference2(stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = plus2(stack[-1], v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    stack[-1] = v257;
    v257 = qvalue(elt(env, 2)); /* !:bprec!: */
    v257 = add1(v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    stack[0] = v257;
    v256 = stack[-1];
    v257 = stack[0];
    v257 = (Lisp_Object)greaterp2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v257 = v257 ? lisp_true : nil;
    env = stack[-9];
    if (v257 == nil) goto v148;
    v257 = stack[-7];
    goto v2;

v2:
    stack[-2] = v257;
    v257 = stack[-2];
    v257 = qcdr(v257);
    v257 = qcar(v257);
    v412 = v257;
    v256 = v412;
    v257 = (Lisp_Object)1; /* 0 */
    if (v256 == v257) goto v231;
    v256 = v412;
    v257 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v257 = (*qfn2(fn))(qenv(fn), v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v412 = v257;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v257 = v412;
    stack[0] = qcar(v257);
    v257 = v412;
    v256 = qcdr(v257);
    v257 = stack[-2];
    v257 = qcdr(v257);
    v257 = qcdr(v257);
    v257 = plus2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    {
        Lisp_Object v414 = stack[-1];
        Lisp_Object v415 = stack[0];
        popv(10);
        return list2star(v414, v415, v257);
    }

v231:
    v412 = elt(env, 1); /* !:rd!: */
    v256 = (Lisp_Object)1; /* 0 */
    v257 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v412, v256, v257);

v148:
    v257 = stack[0];
    v257 = negate(v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = (Lisp_Object)lessp2(stack[-1], v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v257 = v257 ? lisp_true : nil;
    env = stack[-9];
    if (v257 == nil) goto v52;
    stack[0] = elt(env, 1); /* !:rd!: */
    v257 = stack[-6];
    v257 = qcdr(v257);
    v257 = qcar(v257);
    v256 = negate(v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-6];
    v257 = qcdr(v257);
    v257 = qcdr(v257);
    v257 = list2star(stack[0], v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    goto v2;

v52:
    v256 = stack[-2];
    v257 = (Lisp_Object)1; /* 0 */
    v257 = (Lisp_Object)greaterp2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v257 = v257 ? lisp_true : nil;
    env = stack[-9];
    if (v257 == nil) goto v161;
    stack[0] = elt(env, 1); /* !:rd!: */
    v256 = stack[-8];
    v257 = stack[-2];
    v256 = Lash1(nil, v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-5];
    v256 = difference2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-3];
    v257 = list2star(stack[0], v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    goto v2;

v161:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v257 = stack[-2];
    v257 = negate(v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = Lash1(nil, stack[-3], v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v256 = difference2(stack[-1], v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-4];
    v257 = list2star(stack[0], v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    goto v2;

v175:
    stack[0] = elt(env, 1); /* !:rd!: */
    v256 = stack[-8];
    v257 = stack[-5];
    v256 = difference2(v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-4];
    v257 = list2star(stack[0], v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    goto v2;

v68:
    v257 = stack[-7];
    goto v2;

v84:
    stack[0] = elt(env, 1); /* !:rd!: */
    v257 = stack[-6];
    v257 = qcdr(v257);
    v257 = qcar(v257);
    v256 = negate(v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    v257 = stack[-6];
    v257 = qcdr(v257);
    v257 = qcdr(v257);
    v257 = list2star(stack[0], v256, v257);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-9];
    goto v2;
/* error exit handlers */
v413:
    popv(10);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v264;
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
    v264 = elt(env, 1); /* i */
    v236 = qvalue(elt(env, 2)); /* kord!* */
    v236 = cons(v264, v236);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v236; /* kord!* */
    v236 = stack[0];
    fn = elt(env, 6); /* reorder */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    stack[-2] = v236;
    v236 = stack[-2];
    if (!consp(v236)) goto v4;
    v236 = stack[-2];
    v236 = qcar(v236);
    v236 = (consp(v236) ? nil : lisp_true);
    goto v3;

v3:
    if (v236 == nil) goto v125;
    v236 = stack[-2];
    if (!consp(v236)) goto v34;
    v236 = stack[-2];
    v264 = qcar(v236);
    v236 = elt(env, 4); /* cmpxfn */
    v236 = get(v264, v236);
    env = stack[-4];
    if (v236 == nil) goto v175;
    v236 = stack[-2];
    stack[-1] = qcar(v236);
    v236 = stack[-2];
    v236 = qcdr(v236);
    stack[0] = qcar(v236);
    v236 = stack[-2];
    v264 = qcar(v236);
    v236 = elt(env, 5); /* i2d */
    v264 = get(v264, v236);
    env = stack[-4];
    v236 = (Lisp_Object)1; /* 0 */
    v236 = Lapply1(nil, v264, v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = list2star(stack[-1], stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    fn = elt(env, 7); /* int!-equiv!-chk */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    goto v69;

v69:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v236); }

v175:
    v236 = stack[-2];
    goto v69;

v34:
    v236 = stack[-2];
    goto v69;

v125:
    v236 = stack[-2];
    v236 = qcar(v236);
    v236 = qcar(v236);
    v264 = qcar(v236);
    v236 = elt(env, 1); /* i */
    if (v264 == v236) goto v28;
    v236 = stack[-2];
    v236 = qcar(v236);
    v264 = qcar(v236);
    v236 = (Lisp_Object)17; /* 1 */
    v236 = cons(v264, v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    stack[0] = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v236 = stack[-2];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = CC_repartf(env, v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    fn = elt(env, 8); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v236 = stack[-2];
    v236 = qcdr(v236);
    v236 = CC_repartf(env, v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    fn = elt(env, 9); /* addf */
    v236 = (*qfn2(fn))(qenv(fn), stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    goto v69;

v28:
    v236 = stack[-2];
    v236 = qcdr(v236);
    v236 = CC_repartf(env, v236);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    goto v69;

v4:
    v236 = qvalue(elt(env, 3)); /* t */
    goto v3;
/* error exit handlers */
v58:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v57:
    popv(5);
    return nil;
}



/* Code for ev_mtest!? */

static Lisp_Object CC_ev_mtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v33, v32, v68, v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v8;
    v68 = v0;
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* t */
    v41 = v67;
    goto v21;

v21:
    v67 = v68;
    if (v67 == nil) return onevalue(v41);
    v67 = v41;
    if (v67 == nil) return onevalue(v41);
    v67 = v68;
    v33 = qcar(v67);
    v67 = v32;
    v67 = qcar(v67);
    if (((int32_t)(v33)) < ((int32_t)(v67))) goto v5;
    v67 = v68;
    v67 = qcdr(v67);
    v68 = v67;
    v67 = v32;
    v67 = qcdr(v67);
    v32 = v67;
    goto v21;

v5:
    v67 = qvalue(elt(env, 2)); /* nil */
    v41 = v67;
    v68 = v67;
    goto v21;
}



/* Code for quotientml */

static Lisp_Object CC_quotientml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v91;
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
    v173 = stack[0];
    v173 = qcar(v173);
    if (!(is_number(v173))) goto v193;
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcar(v173);
    if (!(is_number(v173))) goto v193;
    v173 = qvalue(elt(env, 1)); /* !*web */
    if (v173 == nil) goto v85;
    v173 = elt(env, 3); /* "<cn type=&quot;rational&quot;> " */
    fn = elt(env, 9); /* printout */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v70;

v70:
    v173 = stack[0];
    v173 = qcar(v173);
    v173 = Lprinc(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v173 = elt(env, 4); /* " <sep/> " */
    v173 = Lprinc(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcar(v173);
    v173 = Lprinc(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v173 = elt(env, 5); /* " </cn>" */
    v173 = Lprinc(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    goto v89;

v89:
    v173 = nil;
    { popv(2); return onevalue(v173); }

v85:
    v173 = elt(env, 2); /* "<cn type=""rational""> " */
    fn = elt(env, 9); /* printout */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v70;

v193:
    v173 = elt(env, 6); /* "<apply><divide/>" */
    fn = elt(env, 9); /* printout */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v91 = qvalue(elt(env, 7)); /* indent */
    v173 = (Lisp_Object)49; /* 3 */
    v173 = plus2(v91, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    qvalue(elt(env, 7)) = v173; /* indent */
    v173 = stack[0];
    v173 = qcar(v173);
    fn = elt(env, 10); /* expression */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcar(v173);
    fn = elt(env, 10); /* expression */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v91 = qvalue(elt(env, 7)); /* indent */
    v173 = (Lisp_Object)49; /* 3 */
    v173 = difference2(v91, v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    qvalue(elt(env, 7)) = v173; /* indent */
    v173 = elt(env, 8); /* "</apply>" */
    fn = elt(env, 9); /* printout */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v65;
    goto v89;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for varsinsf */

static Lisp_Object CC_varsinsf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for varsinsf");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v173 = v8;
    stack[-1] = v0;
/* end of prologue */
    v91 = stack[-1];
    if (!consp(v91)) goto v21;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = (consp(v91) ? nil : lisp_true);
    goto v90;

v90:
    if (!(v91 == nil)) { popv(4); return onevalue(v173); }

v7:
    v91 = stack[-1];
    if (!consp(v91)) goto v22;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = (consp(v91) ? nil : lisp_true);
    goto v34;

v34:
    if (!(v91 == nil)) { popv(4); return onevalue(v173); }
    v91 = stack[-1];
    v91 = qcar(v91);
    stack[-2] = qcdr(v91);
    stack[0] = v173;
    v173 = stack[-1];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    v173 = (*qfn2(fn))(qenv(fn), stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v173 = CC_varsinsf(env, stack[-2], v173);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-1] = v91;
    goto v7;

v22:
    v91 = qvalue(elt(env, 1)); /* t */
    goto v34;

v21:
    v91 = qvalue(elt(env, 1)); /* t */
    goto v90;
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for column_dim */

static Lisp_Object CC_column_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88;
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
    v88 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v88 == nil) goto v129;
    v88 = qvalue(elt(env, 2)); /* nil */
    goto v21;

v21:
    if (v88 == nil) goto v89;
    v88 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v88 == nil)) goto v9;
    v88 = elt(env, 4); /* "Error in column_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-1];
    goto v9;

v9:
    v88 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-1];
    goto v89;

v89:
    v88 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v260;
    v88 = qcdr(v88);
    v88 = qcar(v88);
    { popv(2); return onevalue(v88); }

v129:
    v88 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-1];
    v88 = (v88 == nil ? lisp_true : nil);
    goto v21;
/* error exit handlers */
v260:
    popv(2);
    return nil;
}



setup_type const u38_setup[] =
{
    {"gd_gcasesimpl",           CC_gd_gcasesimpl,too_many_1,   wrong_no_1},
    {"taymindegreel",           too_few_2,      CC_taymindegreel,wrong_no_2},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"cnml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnml},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"xexptpf",                 too_few_2,      CC_xexptpf,    wrong_no_2},
    {"adjp",                    CC_adjp,        too_many_1,    wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"simp-prop",               CC_simpKprop,   too_many_1,    wrong_no_1},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"update_components",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_update_components},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"ratpoly_red",             CC_ratpoly_red, too_many_1,    wrong_no_1},
    {"bc_2a",                   CC_bc_2a,       too_many_1,    wrong_no_1},
    {"pdiffvars",               too_few_2,      CC_pdiffvars,  wrong_no_2},
    {"ldf-sep-var",             CC_ldfKsepKvar, too_many_1,    wrong_no_1},
    {"addns",                   too_few_2,      CC_addns,      wrong_no_2},
    {"mkprec",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkprec},
    {"xquotient-mod-p",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_xquotientKmodKp},
    {"lto_alunion",             CC_lto_alunion, too_many_1,    wrong_no_1},
    {"texexplode",              CC_texexplode,  too_many_1,    wrong_no_1},
    {"cl_smsimpl-junct1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct1},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"dipreplus",               CC_dipreplus,   too_many_1,    wrong_no_1},
    {"vevzero?1",               CC_vevzeroW1,   too_many_1,    wrong_no_1},
    {"ndepends",                too_few_2,      CC_ndepends,   wrong_no_2},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"gfdiffer",                too_few_2,      CC_gfdiffer,   wrong_no_2},
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"quotientml",              CC_quotientml,  too_many_1,    wrong_no_1},
    {"varsinsf",                too_few_2,      CC_varsinsf,   wrong_no_2},
    {"column_dim",              CC_column_dim,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u38", (two_args *)"4999 5357310 6941156", 0}
};

/* end of generated code */
