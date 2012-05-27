
/* $destdir\u39.c        Machine generated C code */

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


/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v10 = stack[-1];
    v10 = qcdr(v10);
    v10 = qcdr(v10);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    stack[0] = v10;
    v10 = stack[0];
    if (v10 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v10 = stack[0];
    fn = elt(env, 3); /* dipsimpcont */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[-2] = v10;
    v10 = stack[-2];
    v10 = qcdr(v10);
    fn = elt(env, 4); /* dip2vdp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[-1] = v10;
    v10 = stack[-2];
    v10 = qcar(v10);
    stack[-2] = v10;
    v10 = stack[-2];
    fn = elt(env, 5); /* evzero!? */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    if (v10 == nil) goto v14;
    v10 = qvalue(elt(env, 1)); /* nil */
    goto v15;

v15:
    if (v10 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v12 = stack[-1];
    v11 = elt(env, 2); /* monfac */
    v10 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v10 = (*qfnn(fn))(qenv(fn), 3, v12, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v14:
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcdr(v10);
    if (!(v10 == nil)) goto v15;
    v10 = stack[-2];
    fn = elt(env, 7); /* evtdeg */
    v11 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v10 = (Lisp_Object)17; /* 1 */
    v10 = (Lisp_Object)greaterp2(v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v10 = v10 ? lisp_true : nil;
    env = stack[-3];
    goto v15;
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for dim!<!=deg */

static Lisp_Object CC_dimRMdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v21 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*form */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v21 = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v22 = v21;
    v21 = v22;
    if (v21 == nil) goto v24;
    v21 = v22;
    v21 = integerp(v21);
    if (v21 == nil) goto v25;
    v21 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Lleq(nil, v22, v21);

v25:
    v21 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v21); }

v24:
    v21 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v21); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for rassoc */

static Lisp_Object CC_rassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v14, v29, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v26;
    v30 = v0;
/* end of prologue */

v31:
    v15 = v29;
    if (!consp(v15)) goto v19;
    v14 = v30;
    v15 = v29;
    v15 = qcar(v15);
    v15 = qcdr(v15);
    if (equal(v14, v15)) goto v18;
    v15 = v29;
    v15 = qcdr(v15);
    v29 = v15;
    goto v31;

v18:
    v15 = v29;
    v15 = qcar(v15);
    return onevalue(v15);

v19:
    v15 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v15);
}



/* Code for strand!-alg!-top */

static Lisp_Object MS_CDECL CC_strandKalgKtop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v7, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "strand-alg-top");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for strand-alg-top");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v26;
    stack[-2] = v0;
/* end of prologue */
    v7 = stack[-2];
    v41 = stack[0];
    fn = elt(env, 2); /* deletez1 */
    v41 = (*qfn2(fn))(qenv(fn), v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    stack[-2] = v41;
    v42 = stack[0];
    v7 = stack[-1];
    v41 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* color!-strand */
    v41 = (*qfnn(fn))(qenv(fn), 3, v42, v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    stack[0] = v41;
    v7 = stack[-2];
    v41 = stack[0];
    fn = elt(env, 4); /* contract!-strand */
    v41 = (*qfn2(fn))(qenv(fn), v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    stack[-2] = v41;
    v42 = stack[-2];
    v7 = stack[0];
    v41 = qvalue(elt(env, 1)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* dstr!-to!-alg */
        return (*qfnn(fn))(qenv(fn), 3, v42, v7, v41);
    }
/* error exit handlers */
v43:
    popv(4);
    return nil;
}



/* Code for reduce!-weights */

static Lisp_Object MS_CDECL CC_reduceKweights(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-weights");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-weights");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v4;
    stack[-4] = v26;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v56 = stack[-5];
    v55 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    stack[-2] = v55;
    goto v58;

v58:
    v56 = stack[-5];
    v55 = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!+ */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    stack[-1] = v55;
    v56 = stack[-1];
    v55 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    stack[0] = v55;
    v56 = stack[0];
    v55 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    if (v55 == nil) goto v16;
    v55 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v55;
    v55 = stack[-1];
    stack[-5] = v55;
    v55 = stack[0];
    stack[-2] = v55;
    goto v58;

v16:
    v55 = stack[-6];
    if (!(v55 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v59:
    v56 = stack[-5];
    v55 = stack[-4];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    stack[-1] = v55;
    v56 = stack[-1];
    v55 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    stack[0] = v55;
    v56 = stack[0];
    v55 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-7];
    if (v55 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v55 = stack[-1];
    stack[-5] = v55;
    v55 = stack[0];
    stack[-2] = v55;
    goto v59;
/* error exit handlers */
v57:
    popv(8);
    return nil;
}



/* Code for fs!:timescoeff */

static Lisp_Object CC_fsTtimescoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86, v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timescoeff");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v26;
    stack[-3] = v0;
/* end of prologue */

v89:
    v85 = stack[-2];
    if (v85 == nil) goto v31;
    v87 = stack[-3];
    v86 = stack[-2];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL)));
    fn = elt(env, 4); /* multsq */
    v85 = (*qfn2(fn))(qenv(fn), v87, v85);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    stack[0] = v85;
    v86 = stack[0];
    v85 = elt(env, 2); /* (nil . 1) */
    if (equal(v86, v85)) goto v30;
    v85 = (Lisp_Object)49; /* 3 */
    v85 = Lmkvect(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    stack[-4] = v85;
    v87 = stack[-4];
    v86 = (Lisp_Object)1; /* 0 */
    v85 = stack[0];
    *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v86/(16/CELL))) = v85;
    v88 = stack[-4];
    v87 = (Lisp_Object)17; /* 1 */
    v86 = stack[-2];
    v85 = (Lisp_Object)17; /* 1 */
    v85 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL)));
    *(Lisp_Object *)((char *)v88 + (CELL-TAG_VECTOR) + ((int32_t)v87/(16/CELL))) = v85;
    v88 = stack[-4];
    v87 = (Lisp_Object)33; /* 2 */
    v86 = stack[-2];
    v85 = (Lisp_Object)33; /* 2 */
    v85 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL)));
    *(Lisp_Object *)((char *)v88 + (CELL-TAG_VECTOR) + ((int32_t)v87/(16/CELL))) = v85;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)49; /* 3 */
    v87 = stack[-3];
    v86 = stack[-2];
    v85 = (Lisp_Object)49; /* 3 */
    v85 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL)));
    v85 = CC_fsTtimescoeff(env, v87, v85);
    nil = C_nil;
    if (exception_pending()) goto v90;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v85;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v30:
    v85 = elt(env, 3); /* "zero in times" */
    v85 = Lprint(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v87 = stack[-3];
    v86 = stack[-2];
    v85 = (Lisp_Object)49; /* 3 */
    v85 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL)));
    stack[-3] = v87;
    stack[-2] = v85;
    goto v89;

v31:
    v85 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v85); }
/* error exit handlers */
v90:
    popv(6);
    return nil;
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v82, v91, v43, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addnew");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v43 = v26;
    v92 = v0;
/* end of prologue */
    v91 = qvalue(elt(env, 1)); /* gv */
    v82 = v43;
    v8 = v92;
    *(Lisp_Object *)((char *)v91 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL))) = v8;
    v91 = qvalue(elt(env, 2)); /* bv */
    v82 = v43;
    v8 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v91 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL))) = v8;
    v8 = v92;
    if (v8 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v43;
    v8 = v92;
    fn = elt(env, 4); /* ljet */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    v82 = cons(stack[-1], v8);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    v8 = stack[0];
    fn = elt(env, 5); /* insert */
    v8 = (*qfn2(fn))(qenv(fn), v82, v8);
    nil = C_nil;
    if (exception_pending()) goto v83;
    { popv(3); return onevalue(v8); }
/* error exit handlers */
v83:
    popv(3);
    return nil;
}



/* Code for !*q2f */

static Lisp_Object CC_Hq2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *q2f");
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
    v34 = v0;
/* end of prologue */
    v32 = v34;
    v33 = qcdr(v32);
    v32 = (Lisp_Object)17; /* 1 */
    if (v33 == v32) goto v35;
    v32 = v34;
    v32 = qcar(v32);
    if (v32 == nil) goto v52;
    v33 = v34;
    v32 = elt(env, 1); /* prepf */
    fn = elt(env, 3); /* sqform */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    v33 = v32;
    goto v58;

v58:
    v32 = elt(env, 2); /* polynomial */
    {
        popv(1);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v33, v32);
    }

v52:
    v32 = (Lisp_Object)1; /* 0 */
    v33 = v32;
    goto v58;

v35:
    v32 = v34;
    v32 = qcar(v32);
    { popv(1); return onevalue(v32); }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for conjgd */

static Lisp_Object CC_conjgd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjgd");
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
    v105 = nil;
    v104 = stack[-1];
    if (!consp(v104)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v104 = stack[-1];
    if (!consp(v104)) goto v27;
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v54;

v54:
    if (v104 == nil) goto v16;
    v104 = stack[-1];
    v105 = qcar(v104);
    v104 = elt(env, 2); /* cmpxfn */
    v104 = get(v105, v104);
    env = stack[-3];
    v105 = v104;
    goto v40;

v40:
    if (v104 == nil) goto v18;
    stack[-2] = v105;
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[0] = qcar(v104);
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    if (is_number(v104)) goto v106;
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    if (!consp(v104)) goto v47;
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v13;

v13:
    if (v104 == nil) goto v107;
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    v104 = qcar(v104);
    v104 = (is_number(v104) ? lisp_true : nil);
    v104 = (v104 == nil ? lisp_true : nil);
    goto v12;

v12:
    if (v104 == nil) goto v108;
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    fn = elt(env, 5); /* !:minus */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    goto v7;

v7:
    {
        Lisp_Object v110 = stack[-2];
        Lisp_Object v111 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v110, v111, v104);
    }

v108:
    v104 = stack[-1];
    v105 = qcar(v104);
    v104 = elt(env, 4); /* realtype */
    v105 = get(v105, v104);
    env = stack[-3];
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    fn = elt(env, 5); /* !:minus */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v104 = qcdr(v104);
    goto v7;

v107:
    v104 = qvalue(elt(env, 3)); /* nil */
    goto v12;

v47:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v13;

v106:
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    v104 = negate(v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    goto v7;

v18:
    v104 = stack[-1];
    if (!consp(v104)) goto v112;
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v113;

v113:
    if (!(v104 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v104 = stack[-1];
    v104 = qcar(v104);
    v105 = qcar(v104);
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    stack[0] = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = CC_conjgd(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v104 = stack[-1];
    v104 = qcdr(v104);
    v104 = CC_conjgd(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    {
        Lisp_Object v114 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v114, v104);
    }

v112:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v113;

v16:
    v104 = qvalue(elt(env, 3)); /* nil */
    goto v40;

v27:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v54;
/* error exit handlers */
v109:
    popv(4);
    return nil;
}



/* Code for mri_opn */

static Lisp_Object CC_mri_opn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_opn");
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
    v24 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mri_op */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    errexit();
    v115 = v24;
    v24 = v115;
    if (!consp(v24)) return onevalue(v115);
    v24 = v115;
    v24 = qcar(v24);
    return onevalue(v24);
}



/* Code for pasf_anegateat */

static Lisp_Object CC_pasf_anegateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegateat");
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
    v129 = stack[-1];
    v128 = elt(env, 1); /* true */
    if (v129 == v128) goto v103;
    v129 = stack[-1];
    v128 = elt(env, 3); /* false */
    v128 = (v129 == v128 ? lisp_true : nil);
    goto v115;

v115:
    if (v128 == nil) goto v40;
    v128 = stack[-1];
    v129 = v128;
    goto v19;

v19:
    v128 = elt(env, 4); /* (cong ncong) */
    v128 = Lmemq(nil, v129, v128);
    if (v128 == nil) goto v130;
    v129 = stack[-1];
    v128 = elt(env, 1); /* true */
    if (v129 == v128) goto v131;
    v129 = stack[-1];
    v128 = elt(env, 3); /* false */
    v128 = (v129 == v128 ? lisp_true : nil);
    goto v48;

v48:
    if (v128 == nil) goto v13;
    v128 = stack[-1];
    goto v78;

v78:
    fn = elt(env, 5); /* pasf_anegrel */
    v129 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    fn = elt(env, 6); /* pasf_mkop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 7); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 7); /* negf */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v133 = stack[-2];
        Lisp_Object v134 = stack[0];
        popv(4);
        return list3(v133, v134, v128);
    }

v13:
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = Lconsp(nil, v128);
    env = stack[-3];
    if (v128 == nil) goto v72;
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcar(v128);
    goto v78;

v72:
    v128 = stack[-1];
    v128 = qcar(v128);
    goto v78;

v131:
    v128 = qvalue(elt(env, 2)); /* t */
    goto v48;

v130:
    v129 = stack[-1];
    v128 = elt(env, 1); /* true */
    if (v129 == v128) goto v135;
    v129 = stack[-1];
    v128 = elt(env, 3); /* false */
    v128 = (v129 == v128 ? lisp_true : nil);
    goto v136;

v136:
    if (v128 == nil) goto v88;
    v128 = stack[-1];
    goto v86;

v86:
    fn = elt(env, 5); /* pasf_anegrel */
    stack[-2] = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 7); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 7); /* negf */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v137 = stack[-2];
        Lisp_Object v138 = stack[0];
        popv(4);
        return list3(v137, v138, v128);
    }

v88:
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = Lconsp(nil, v128);
    env = stack[-3];
    if (v128 == nil) goto v139;
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcar(v128);
    goto v86;

v139:
    v128 = stack[-1];
    v128 = qcar(v128);
    goto v86;

v135:
    v128 = qvalue(elt(env, 2)); /* t */
    goto v136;

v40:
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = Lconsp(nil, v128);
    env = stack[-3];
    if (v128 == nil) goto v7;
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v129 = v128;
    goto v19;

v7:
    v128 = stack[-1];
    v128 = qcar(v128);
    v129 = v128;
    goto v19;

v103:
    v128 = qvalue(elt(env, 2)); /* t */
    goto v115;
/* error exit handlers */
v132:
    popv(4);
    return nil;
}



/* Code for bc_minus!? */

static Lisp_Object CC_bc_minusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v35);
    }
}



/* Code for vdp_getprop */

static Lisp_Object CC_vdp_getprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_getprop");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v25 = v26;
    v37 = v0;
/* end of prologue */
    stack[0] = v25;
    v25 = v37;
    fn = elt(env, 2); /* vdp_plist */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v25 = Latsoc(nil, stack[0], v25);
    v37 = v25;
    v25 = v37;
    if (v25 == nil) goto v140;
    v25 = v37;
    v25 = qcdr(v25);
    { popv(2); return onevalue(v25); }

v140:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v25); }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for csymbolrd */

static Lisp_Object MS_CDECL CC_csymbolrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v25, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "csymbolrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csymbolrd");
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
    v28 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    stack[0] = v28;
    fn = elt(env, 3); /* stats_getargs */
    v28 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v25 = v28;
    v28 = stack[0];
    v37 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list2star(v28, v37, v25);
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for ps!:term!-rthpow */

static Lisp_Object MS_CDECL CC_psTtermKrthpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:term-rthpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:term-rthpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v26;
    stack[-3] = v0;
/* end of prologue */
    v2 = stack[-3];
    v1 = stack[-2];
    fn = elt(env, 2); /* ps!:get!-term */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-4] = v1;
    v1 = stack[-4];
    if (!(v1 == nil)) goto v142;
    v1 = stack[-3];
    fn = elt(env, 3); /* ps!:last!-term */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v1 = add1(v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v1;
    goto v6;

v6:
    v2 = stack[-2];
    v1 = stack[0];
    v1 = difference2(v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v1 = Lminusp(nil, v1);
    env = stack[-5];
    if (!(v1 == nil)) goto v142;
    v2 = stack[-3];
    v1 = stack[0];
    fn = elt(env, 4); /* ps!:set!-rthpow */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-4] = v1;
    v1 = stack[0];
    v1 = add1(v1);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v1;
    goto v6;

v142:
    v2 = stack[-4];
    v1 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* ps!:evaluate */
        return (*qfn2(fn))(qenv(fn), v2, v1);
    }
/* error exit handlers */
v78:
    popv(6);
    return nil;
}



/* Code for greatertype */

static Lisp_Object CC_greatertype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greatertype");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v26;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v150 = qvalue(elt(env, 1)); /* optlang!* */
    if (v150 == nil) goto v37;
    v150 = qvalue(elt(env, 1)); /* optlang!* */
    v151 = v150;
    goto v24;

v24:
    v150 = elt(env, 3); /* conversion */
    v150 = get(v151, v150);
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-8];
    stack[-7] = v150;
    v150 = stack[-7];
    v151 = qcar(v150);
    v150 = stack[-5];
    if (equal(v151, v150)) goto v14;
    v150 = stack[-7];
    v151 = qcar(v150);
    v150 = stack[-6];
    if (!(equal(v151, v150))) goto v84;
    v150 = qvalue(elt(env, 5)); /* nil */
    stack[-1] = v150;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v84:
    v150 = stack[-7];
    v150 = qcdr(v150);
    stack[-7] = v150;
    if (v150 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v150 = stack[-4];
    if (!(v150 == nil)) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v150 = stack[-7];
    v150 = qcar(v150);
    v152 = v150;
    goto v47;

v47:
    v150 = v152;
    if (v150 == nil) goto v13;
    v150 = stack[-2];
    if (!(v150 == nil)) goto v13;
    v150 = v152;
    v151 = qcar(v150);
    v150 = stack[-6];
    if (!(equal(v151, v150))) goto v154;
    v150 = qvalue(elt(env, 4)); /* t */
    stack[-3] = v150;
    goto v154;

v154:
    v150 = v152;
    v151 = qcar(v150);
    v150 = stack[-5];
    if (equal(v151, v150)) goto v155;
    v150 = v152;
    v150 = qcdr(v150);
    v152 = v150;
    goto v47;

v155:
    v150 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v150;
    goto v47;

v13:
    v150 = stack[-2];
    if (v150 == nil) goto v62;
    v150 = v152;
    v150 = qcdr(v150);
    v152 = v150;
    goto v156;

v156:
    v150 = v152;
    if (v150 == nil) goto v62;
    v150 = stack[-1];
    if (!(v150 == nil)) goto v62;
    v150 = v152;
    v151 = qcar(v150);
    v150 = stack[-6];
    if (equal(v151, v150)) goto v88;
    v150 = v152;
    v150 = qcdr(v150);
    v152 = v150;
    goto v156;

v88:
    v150 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v150;
    stack[-3] = v150;
    goto v156;

v62:
    v150 = stack[-3];
    if (v150 == nil) goto v119;
    v150 = stack[-2];
    if (!(v150 == nil)) goto v119;

v116:
    stack[0] = (Lisp_Object)65; /* 4 */
    v151 = stack[-6];
    v150 = stack[-5];
    v150 = cons(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-8];
    fn = elt(env, 7); /* typerror */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-8];
    goto v84;

v119:
    v150 = stack[-3];
    if (v150 == nil) goto v157;
    v150 = qvalue(elt(env, 5)); /* nil */
    goto v158;

v158:
    if (!(v150 == nil)) goto v116;
    v150 = stack[-3];
    if (v150 == nil) goto v84;
    v150 = stack[-2];
    if (v150 == nil) goto v84;
    v150 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v150;
    goto v84;

v157:
    v150 = stack[-2];
    goto v158;

v14:
    v150 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v150;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v37:
    v150 = elt(env, 2); /* fortran */
    v151 = v150;
    goto v24;
/* error exit handlers */
v153:
    popv(9);
    return nil;
}



/* Code for sfpf */

static Lisp_Object CC_sfpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v21 = v22;
    if (!consp(v21)) goto v19;
    v21 = v22;
    v21 = qcar(v21);
    v21 = (consp(v21) ? nil : lisp_true);
    goto v46;

v46:
    if (v21 == nil) goto v35;
    v21 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v21);

v35:
    v21 = v22;
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    if (!consp(v21)) goto v30;
    v21 = v22;
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = (consp(v21) ? nil : lisp_true);
    v21 = (v21 == nil ? lisp_true : nil);
    return onevalue(v21);

v30:
    v21 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v21);

v19:
    v21 = qvalue(elt(env, 1)); /* t */
    goto v46;
}



/* Code for dipnumcontent */

static Lisp_Object CC_dipnumcontent(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipnumcontent");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */

v49:
    v36 = stack[0];
    fn = elt(env, 1); /* bcone!? */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    if (!(v36 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v36 = stack[-1];
    if (v36 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v36 = stack[-1];
    v36 = qcdr(v36);
    v36 = qcdr(v36);
    stack[-2] = v36;
    v6 = stack[0];
    v36 = stack[-1];
    v36 = qcdr(v36);
    v36 = qcar(v36);
    fn = elt(env, 2); /* vbcgcd */
    v36 = (*qfn2(fn))(qenv(fn), v6, v36);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[0] = v36;
    v36 = stack[-2];
    stack[-1] = v36;
    goto v49;
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for groebsaveltermbc */

static Lisp_Object CC_groebsaveltermbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsaveltermbc");
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
    v50 = stack[0];
    fn = elt(env, 3); /* vbc2a */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    stack[0] = v50;
    v50 = stack[0];
    if (is_number(v50)) goto v115;
    v50 = stack[0];
    fn = elt(env, 4); /* constant_exprp */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v50 = (v50 == nil ? lisp_true : nil);
    goto v20;

v20:
    if (v50 == nil) goto v46;
    v50 = stack[0];
    fn = elt(env, 5); /* simp */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v50 = qcar(v50);
    fn = elt(env, 6); /* fctrf */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v50 = qcdr(v50);
    stack[-1] = v50;
    goto v28;

v28:
    v50 = stack[-1];
    if (v50 == nil) goto v14;
    v50 = stack[-1];
    v50 = qcar(v50);
    v11 = v50;
    v50 = v11;
    v50 = qcar(v50);
    fn = elt(env, 7); /* prepf */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v11 = v50;
    v10 = v11;
    v50 = qvalue(elt(env, 2)); /* glterms */
    v50 = Lmember(nil, v10, v50);
    if (!(v50 == nil)) goto v23;
    stack[0] = qvalue(elt(env, 2)); /* glterms */
    v50 = v11;
    v50 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v50 = Lnconc(nil, stack[0], v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    goto v23;

v23:
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    goto v28;

v14:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v50); }

v46:
    v50 = nil;
    { popv(3); return onevalue(v50); }

v115:
    v50 = qvalue(elt(env, 1)); /* nil */
    goto v20;
/* error exit handlers */
v78:
    popv(3);
    return nil;
}



/* Code for xpartitk */

static Lisp_Object CC_xpartitk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v141, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitk");
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
    v141 = stack[0];
    v59 = elt(env, 1); /* (wedge partdf) */
    fn = elt(env, 2); /* memqcar */
    v59 = (*qfn2(fn))(qenv(fn), v141, v59);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    if (v59 == nil) goto v8;
    v59 = stack[0];
    fn = elt(env, 3); /* reval */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v3 = v59;
    v141 = v3;
    v59 = stack[0];
    if (equal(v141, v59)) goto v14;
    v59 = v3;
    {
        popv(2);
        fn = elt(env, 4); /* xpartitop */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v14:
    v3 = stack[0];
    v141 = (Lisp_Object)17; /* 1 */
    v59 = (Lisp_Object)17; /* 1 */
    v59 = list2star(v3, v141, v59);
    nil = C_nil;
    if (exception_pending()) goto v2;
    popv(2);
    return ncons(v59);

v8:
    v3 = stack[0];
    v141 = (Lisp_Object)17; /* 1 */
    v59 = (Lisp_Object)17; /* 1 */
    v59 = list2star(v3, v141, v59);
    nil = C_nil;
    if (exception_pending()) goto v2;
    popv(2);
    return ncons(v59);
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for delasc */

static Lisp_Object CC_delasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delasc");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v19;

v19:
    v43 = stack[0];
    if (v43 == nil) goto v46;
    v43 = stack[0];
    v43 = qcar(v43);
    if (!consp(v43)) goto v58;
    v92 = stack[-1];
    v43 = stack[0];
    v43 = qcar(v43);
    v43 = qcar(v43);
    v43 = Lneq(nil, v92, v43);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    goto v140;

v140:
    if (v43 == nil) goto v115;
    v43 = stack[0];
    v92 = qcar(v43);
    v43 = stack[-2];
    v43 = cons(v92, v43);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-2] = v43;
    goto v115;

v115:
    v43 = stack[0];
    v43 = qcdr(v43);
    stack[0] = v43;
    goto v19;

v58:
    v43 = qvalue(elt(env, 2)); /* t */
    goto v140;

v46:
    v43 = stack[-2];
        popv(4);
        return Lnreverse(nil, v43);
/* error exit handlers */
v84:
    popv(4);
    return nil;
}



/* Code for indordlp */

static Lisp_Object CC_indordlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v161, v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v161 = v26;
    v73 = v0;
/* end of prologue */

v31:
    v160 = v73;
    if (v160 == nil) goto v19;
    v160 = v161;
    if (v160 == nil) goto v18;
    v160 = v73;
    v74 = qcar(v160);
    v160 = v161;
    v160 = qcar(v160);
    if (equal(v74, v160)) goto v115;
    v160 = v73;
    v160 = qcar(v160);
    if (!consp(v160)) goto v29;
    v160 = v161;
    v160 = qcar(v160);
    if (!consp(v160)) goto v106;
    v160 = v73;
    v160 = qcar(v160);
    v160 = qcdr(v160);
    v160 = qcar(v160);
    v161 = qcar(v161);
    v161 = qcdr(v161);
    v161 = qcar(v161);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v160, v161);
    }

v106:
    v160 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v160);

v29:
    v160 = v161;
    v160 = qcar(v160);
    if (!consp(v160)) goto v32;
    v160 = qvalue(elt(env, 2)); /* t */
    return onevalue(v160);

v32:
    v160 = v73;
    v160 = qcar(v160);
    v161 = qcar(v161);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v160, v161);
    }

v115:
    v160 = v73;
    v160 = qcdr(v160);
    v73 = v160;
    v160 = v161;
    v160 = qcdr(v160);
    v161 = v160;
    goto v31;

v18:
    v160 = qvalue(elt(env, 2)); /* t */
    return onevalue(v160);

v19:
    v160 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v160);
}



/* Code for s_noparents */

static Lisp_Object CC_s_noparents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_noparents");
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
    goto v31;

v31:
    v36 = stack[0];
    if (v36 == nil) goto v19;
    v36 = stack[0];
    v36 = qcar(v36);
    fn = elt(env, 1); /* has_parents */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    if (v36 == nil) goto v25;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v31;

v25:
    v36 = stack[0];
    v6 = qcar(v36);
    v36 = stack[-1];
    v36 = cons(v6, v36);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    stack[-1] = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v31;

v19:
    v36 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for !*hfac */

static Lisp_Object CC_Hhfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *hfac");
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
    v59 = stack[0];
    v59 = integerp(v59);
    if (v59 == nil) goto v19;
    v141 = stack[0];
    v59 = (Lisp_Object)1; /* 0 */
    v59 = (Lisp_Object)lessp2(v141, v59);
    nil = C_nil;
    if (exception_pending()) goto v1;
    v59 = v59 ? lisp_true : nil;
    env = stack[-1];
    if (!(v59 == nil)) goto v46;
    v141 = stack[0];
    v59 = (Lisp_Object)33; /* 2 */
    v59 = (Lisp_Object)greaterp2(v141, v59);
    nil = C_nil;
    if (exception_pending()) goto v1;
    v59 = v59 ? lisp_true : nil;
    env = stack[-1];
    goto v46;

v46:
    if (v59 == nil) goto v82;
    v59 = elt(env, 2); /* "Invalid index" */
    v141 = v59;
    v59 = v141;
    qvalue(elt(env, 3)) = v59; /* errmsg!* */
    v59 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v59 == nil)) goto v80;
    v59 = v141;
    fn = elt(env, 6); /* lprie */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    goto v80;

v80:
    v59 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v1;
    v59 = nil;
    { popv(2); return onevalue(v59); }

v82:
    v59 = elt(env, 5); /* hfactors */
    fn = elt(env, 7); /* getavalue */
    v141 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v1;
    v59 = stack[0];
    v59 = *(Lisp_Object *)((char *)v141 + (CELL-TAG_VECTOR) + ((int32_t)v59/(16/CELL)));
    { popv(2); return onevalue(v59); }

v19:
    v59 = qvalue(elt(env, 1)); /* t */
    goto v46;
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for mod!/ */

static Lisp_Object CC_modV(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30, v36, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod/");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v29 = v26;
    v30 = v0;
/* end of prologue */
    stack[0] = v30;
    v6 = qvalue(elt(env, 1)); /* current!-modulus */
    v36 = v29;
    v30 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* general!-reciprocal!-by!-gcd */
    v29 = (*qfnn(fn))(qenv(fn), 4, v6, v36, v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v29 = times2(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v30 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return Cremainder(v29, v30);
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for cl_nnfnot */

static Lisp_Object CC_cl_nnfnot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_nnfnot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v162 = v0;
/* end of prologue */
    v60 = v162;
    v162 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_nnf1 */
        return (*qfn2(fn))(qenv(fn), v60, v162);
    }
}



/* Code for addfactors */

static Lisp_Object CC_addfactors(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v77, v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addfactors");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v78 = v26;
    v79 = v0;
/* end of prologue */
    v77 = v79;
    v12 = (Lisp_Object)17; /* 1 */
    if (v77 == v12) goto v31;
    v77 = v78;
    v12 = (Lisp_Object)17; /* 1 */
    if (v77 == v12) { popv(3); return onevalue(v79); }
    v77 = v79;
    v12 = elt(env, 1); /* times */
    if (!consp(v77)) goto v59;
    v77 = qcar(v77);
    if (!(v77 == v12)) goto v59;
    stack[-1] = elt(env, 1); /* times */
    v12 = v79;
    stack[0] = qcdr(v12);
    v12 = v78;
    fn = elt(env, 2); /* prepf */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v12 = Lnconc(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v48;
    {
        Lisp_Object v131 = stack[-1];
        popv(3);
        return cons(v131, v12);
    }

v59:
    stack[0] = v79;
    v12 = v78;
    fn = elt(env, 2); /* prepf */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v12 = list2(stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* retimes */
        return (*qfn1(fn))(qenv(fn), v12);
    }

v31:
    v12 = v78;
    {
        popv(3);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v12);
    }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for ofsf_simplequal */

static Lisp_Object CC_ofsf_simplequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v163, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simplequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v26;
    stack[-2] = v0;
/* end of prologue */
    v149 = stack[-2];
    fn = elt(env, 8); /* ofsf_posdefp */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    stack[-3] = v149;
    v163 = stack[-3];
    v149 = elt(env, 1); /* stsq */
    if (v163 == v149) goto v18;
    v149 = stack[-2];
    fn = elt(env, 9); /* sfto_sqfpartf */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    stack[0] = v149;
    v149 = stack[0];
    fn = elt(env, 8); /* ofsf_posdefp */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v68 = v149;
    v163 = v68;
    v149 = elt(env, 1); /* stsq */
    if (v163 == v149) goto v5;
    v149 = qvalue(elt(env, 3)); /* !*rlsitsqspl */
    if (v149 == nil) goto v76;
    v149 = qvalue(elt(env, 4)); /* !*rlsiexpla */
    if (!(v149 == nil)) goto v2;
    v149 = qvalue(elt(env, 5)); /* !*rlsiexpl */
    if (v149 == nil) goto v76;
    v163 = stack[-1];
    v149 = elt(env, 6); /* and */
    if (!(v163 == v149)) goto v76;

v2:
    v163 = v68;
    v149 = elt(env, 7); /* tsq */
    if (v163 == v149) goto v3;
    v163 = stack[-3];
    v149 = elt(env, 7); /* tsq */
    if (!(v163 == v149)) goto v76;
    v149 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v149);
    }

v76:
    v163 = stack[0];
    v149 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_facequal!* */
        return (*qfn2(fn))(qenv(fn), v163, v149);
    }

v3:
    v149 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v149);
    }

v5:
    v149 = elt(env, 2); /* false */
    { popv(5); return onevalue(v149); }

v18:
    v149 = elt(env, 2); /* false */
    { popv(5); return onevalue(v149); }
/* error exit handlers */
v164:
    popv(5);
    return nil;
}



/* Code for factorf */

static Lisp_Object CC_factorf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v183, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorf");
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
    stack[-3] = v0;
/* end of prologue */
    v182 = qvalue(elt(env, 1)); /* current!-modulus */
    stack[-7] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v182; /* current!-modulus */
    stack[-6] = qvalue(elt(env, 2)); /* m!-image!-variable */
    qvalue(elt(env, 2)) = nil; /* m!-image!-variable */
    stack[-4] = nil;
    v182 = stack[-3];
    if (!consp(v182)) goto v54;
    v182 = stack[-3];
    v182 = qcar(v182);
    v182 = (consp(v182) ? nil : lisp_true);
    goto v103;

v103:
    if (v182 == nil) goto v14;
    v182 = stack[-3];
    v182 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    goto v60;

v60:
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    { popv(9); return onevalue(v182); }

v14:
    v183 = stack[-3];
    v182 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* kernord */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v183 = v182;
    v182 = qvalue(elt(env, 5)); /* !*kernreverse */
    if (v182 == nil) goto v21;
    v182 = v183;
    v182 = Lreverse(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v183 = v182;
    goto v21;

v21:
    v182 = v183;
    fn = elt(env, 8); /* setkorder */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-5] = v182;
    v182 = stack[-3];
    fn = elt(env, 9); /* reorder */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    v182 = stack[-3];
    fn = elt(env, 10); /* minusf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    if (v182 == nil) goto v82;
    v182 = stack[-4];
    v182 = (v182 == nil ? lisp_true : nil);
    stack[-4] = v182;
    v182 = stack[-3];
    fn = elt(env, 11); /* negf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    goto v82;

v82:
    v182 = stack[-3];
    fn = elt(env, 12); /* comfac */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-2] = v182;
    v183 = stack[-3];
    v182 = stack[-2];
    v182 = qcdr(v182);
    fn = elt(env, 13); /* quotf1 */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    v182 = stack[-3];
    if (!consp(v182)) goto v160;
    v182 = stack[-3];
    v182 = qcar(v182);
    v182 = (consp(v182) ? nil : lisp_true);
    goto v159;

v159:
    if (v182 == nil) goto v13;
    v182 = elt(env, 6); /* "Improper factors in factorf" */
    v182 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    fn = elt(env, 14); /* errach */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    goto v13;

v13:
    v182 = stack[-2];
    v182 = qcar(v182);
    stack[-1] = v182;
    v182 = stack[-2];
    v182 = qcdr(v182);
    fn = elt(env, 15); /* fctrf1 */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-2] = v182;
    v182 = stack[-1];
    if (v182 == nil) goto v163;
    v182 = stack[-2];
    stack[0] = qcar(v182);
    v182 = stack[-1];
    v184 = qcar(v182);
    v183 = (Lisp_Object)17; /* 1 */
    v182 = (Lisp_Object)17; /* 1 */
    v182 = acons(v184, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v183 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-1];
    v182 = qcdr(v182);
    v183 = cons(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-2];
    v182 = qcdr(v182);
    v182 = list2star(stack[0], v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-2] = v182;
    goto v163;

v163:
    v182 = stack[-3];
    v182 = qcar(v182);
    v182 = qcar(v182);
    v182 = qcar(v182);
    qvalue(elt(env, 2)) = v182; /* m!-image!-variable */
    v182 = stack[-3];
    fn = elt(env, 16); /* factorize!-primitive!-polynomial */
    v183 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* distribute!.multiplicity */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    v182 = stack[-5];
    fn = elt(env, 8); /* setkorder */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-4];
    if (v182 == nil) goto v116;
    v182 = stack[-3];
    v182 = qcar(v182);
    v182 = qcar(v182);
    fn = elt(env, 11); /* negf */
    v184 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-3];
    v182 = qcar(v182);
    v183 = qcdr(v182);
    v182 = stack[-3];
    v182 = qcdr(v182);
    v182 = acons(v184, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    goto v116;

v116:
    v183 = (Lisp_Object)17; /* 1 */
    v182 = stack[-3];
    v182 = cons(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-1] = v182;
    v182 = stack[-2];
    v183 = qcar(v182);
    v182 = stack[-1];
    v182 = qcar(v182);
    fn = elt(env, 18); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-2];
    v183 = qcdr(v182);
    v182 = stack[-1];
    v182 = qcdr(v182);
    v182 = Lappend(nil, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = cons(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-3] = v182;
    v182 = stack[-3];
    stack[-5] = qcar(v182);
    v182 = stack[-3];
    v182 = qcdr(v182);
    stack[-4] = v182;
    v182 = stack[-4];
    if (v182 == nil) goto v186;
    v182 = stack[-4];
    v182 = qcar(v182);
    stack[0] = v182;
    v182 = stack[0];
    v182 = qcar(v182);
    fn = elt(env, 9); /* reorder */
    v183 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[0];
    v182 = qcdr(v182);
    v182 = cons(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    stack[-2] = v182;
    stack[-3] = v182;
    goto v187;

v187:
    v182 = stack[-4];
    v182 = qcdr(v182);
    stack[-4] = v182;
    v182 = stack[-4];
    if (v182 == nil) goto v188;
    stack[-1] = stack[-2];
    v182 = stack[-4];
    v182 = qcar(v182);
    stack[0] = v182;
    v182 = stack[0];
    v182 = qcar(v182);
    fn = elt(env, 9); /* reorder */
    v183 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[0];
    v182 = qcdr(v182);
    v182 = cons(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = Lrplacd(nil, stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    v182 = stack[-2];
    v182 = qcdr(v182);
    stack[-2] = v182;
    goto v187;

v188:
    v182 = stack[-3];
    goto v189;

v189:
    v182 = cons(stack[-5], v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-8];
    goto v60;

v186:
    v182 = qvalue(elt(env, 4)); /* nil */
    goto v189;

v160:
    v182 = qvalue(elt(env, 3)); /* t */
    goto v159;

v54:
    v182 = qvalue(elt(env, 3)); /* t */
    goto v103;
/* error exit handlers */
v185:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    popv(9);
    return nil;
}



/* Code for acfsf_0mk2 */

static Lisp_Object CC_acfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v24, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v40 = v26;
    v24 = v0;
/* end of prologue */
    v115 = qvalue(elt(env, 1)); /* nil */
    return list3(v24, v40, v115);
}



/* Code for integralir */

static Lisp_Object MS_CDECL CC_integralir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integralir");
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
    v191 = qvalue(elt(env, 1)); /* atts */
    v126 = elt(env, 2); /* name */
    fn = elt(env, 7); /* find */
    v126 = (*qfn2(fn))(qenv(fn), v191, v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v126 = Lintern(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-1] = v126;
    v126 = elt(env, 3); /* (bvar x 1) */
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[0] = v126;
    v191 = stack[-1];
    v126 = elt(env, 5); /* defint */
    if (!(v191 == v126)) goto v140;
    fn = elt(env, 8); /* lex */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    goto v140;

v140:
    fn = elt(env, 8); /* lex */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v126;
    v126 = stack[-2];
    v126 = Lconsp(nil, v126);
    env = stack[-3];
    if (v126 == nil) goto v11;
    v126 = stack[-2];
    v191 = qcar(v126);
    v126 = elt(env, 6); /* lambda */
    if (!(v191 == v126)) goto v11;
    v126 = stack[-2];
    fn = elt(env, 10); /* lambdavar */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[0] = v126;
    v126 = stack[-2];
    fn = elt(env, 11); /* lambdafun */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v126;
    goto v11;

v11:
    v191 = stack[-1];
    v126 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list2(v191, v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v126 = stack[-2];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v126 = Lappend(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v75;
    {
        Lisp_Object v192 = stack[-1];
        popv(4);
        return Lappend(nil, v192, v126);
    }
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for is_buble */

static Lisp_Object CC_is_buble(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for is_buble");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */
    v8 = stack[-1];
    v42 = stack[0];
    fn = elt(env, 2); /* diff_vertex */
    v42 = (*qfn2(fn))(qenv(fn), v8, v42);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    v42 = Llength(nil, v42);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    stack[-2] = v42;
    v8 = stack[-2];
    v42 = (Lisp_Object)33; /* 2 */
    v42 = (Lisp_Object)geq2(v8, v42);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v42 = v42 ? lisp_true : nil;
    env = stack[-3];
    if (v42 == nil) goto v16;
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v42); }

v16:
    v8 = (Lisp_Object)33; /* 2 */
    v42 = stack[-2];
    stack[-2] = times2(v8, v42);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    v42 = stack[0];
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v142 = stack[-2];
        Lisp_Object v106 = stack[-1];
        popv(4);
        return list2star(v142, v106, v42);
    }
/* error exit handlers */
v92:
    popv(4);
    return nil;
}



/* Code for groeb!=testc1 */

static Lisp_Object CC_groebMtestc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testc1");
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
    v7 = stack[0];
    v41 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v41 = (*qfn2(fn))(qenv(fn), v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v41 = qcar(v41);
    fn = elt(env, 2); /* bas_dpoly */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v7 = stack[0];
    v41 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 1); /* pnth */
    v41 = (*qfn2(fn))(qenv(fn), v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v41 = qcar(v41);
    fn = elt(env, 2); /* bas_dpoly */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    fn = elt(env, 4); /* mo_sum */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v7 = stack[0];
    v41 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v41 = (*qfn2(fn))(qenv(fn), v7, v41);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v41 = qcar(v41);
    {
        Lisp_Object v91 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_equal!? */
        return (*qfn2(fn))(qenv(fn), v91, v41);
    }
/* error exit handlers */
v82:
    popv(3);
    return nil;
}



/* Code for checkcoeffts */

static Lisp_Object CC_checkcoeffts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkcoeffts");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */

v89:
    v84 = stack[-1];
    if (v84 == nil) goto v31;
    v84 = stack[-1];
    v84 = qcar(v84);
    v81 = qcar(v84);
    v84 = stack[0];
    fn = elt(env, 3); /* evaluatecoeffts */
    v84 = (*qfn2(fn))(qenv(fn), v81, v84);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-2];
    v81 = v84;
    v84 = v81;
    if (v84 == nil) goto v14;
    v84 = (Lisp_Object)1; /* 0 */
    v84 = (v81 == v84 ? lisp_true : nil);
    goto v15;

v15:
    if (v84 == nil) goto v52;
    v84 = stack[-1];
    v81 = qcdr(v84);
    v84 = stack[0];
    stack[-1] = v81;
    stack[0] = v84;
    goto v89;

v52:
    v84 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v84); }

v14:
    v84 = qvalue(elt(env, 1)); /* t */
    goto v15;

v31:
    v84 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v84); }
/* error exit handlers */
v3:
    popv(3);
    return nil;
}



/* Code for pasf_dnf */

static Lisp_Object CC_pasf_dnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dnf");
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
    fn = elt(env, 2); /* pasf_pnf */
    v18 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[0];
    v60 = elt(env, 1); /* dnf */
    {
        popv(1);
        fn = elt(env, 3); /* pasf_pbnf */
        return (*qfn2(fn))(qenv(fn), v18, v60);
    }
/* error exit handlers */
v39:
    popv(1);
    return nil;
}



/* Code for bra_mk */

static Lisp_Object MS_CDECL CC_bra_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v115, v103;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bra_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_mk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v4;
    v115 = v26;
    v103 = v0;
/* end of prologue */
    return list3(v103, v115, v24);
}



/* Code for ofsf_sacrel!-and */

static Lisp_Object CC_ofsf_sacrelKand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel-and");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v26;
    v38 = v0;
/* end of prologue */
    v52 = elt(env, 1); /* ((lessp (lessp . keep) (leq . keep2) (equal . drop) (neq . keep2) (geq . drop) (greaterp . drop)) (leq (lessp . keep1) (leq . keep) (equal . keep1) (neq . lessp) (geq . equal
) (greaterp . drop)) (equal (lessp . drop) (leq . keep2) (equal . keep) (neq . drop) (geq . keep2) (greaterp . drop)) (neq (lessp . keep1) (leq . lessp) (equal . drop) (neq . keep) (geq . greaterp) (g
reaterp . keep1)) (geq (lessp . drop) (leq . equal) (equal . keep1) (neq . greaterp) (geq . keep) (greaterp . keep1)) (greaterp (lessp . drop) (leq . drop) (equal . drop) (neq . keep2) (geq . keep2) (
greaterp . keep))) */
    v37 = Latsoc(nil, v37, v52);
    v37 = qcdr(v37);
    v37 = Latsoc(nil, v38, v37);
    v37 = qcdr(v37);
    return onevalue(v37);
}



/* Code for ciom */

static Lisp_Object CC_ciom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v10;
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
    v50 = elt(env, 1); /* "<OMATTR>" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 3); /* "<OMATP>" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 4); /* "<OMS cd=""typmml"" name=""type"">" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 5); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v10 = Lintern(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 6)); /* mmltypes!* */
    v50 = Lassoc(nil, v10, v50);
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v10 = Lintern(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 6)); /* mmltypes!* */
    v50 = Lassoc(nil, v10, v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 7); /* """>" */
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 9); /* "</OMATP>" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    fn = elt(env, 13); /* objectom */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v50 = elt(env, 10); /* "</OMATTR>" */
    fn = elt(env, 11); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v12;
    v50 = nil;
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for operator */

static Lisp_Object CC_operator(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator");
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
    v140 = v0;
/* end of prologue */
    stack[0] = v140;
    goto v31;

v31:
    v140 = stack[0];
    if (v140 == nil) goto v20;
    v140 = stack[0];
    v140 = qcar(v140);
    fn = elt(env, 2); /* mkop */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v31;

v20:
    v140 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v140); }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for sroot1 */

static Lisp_Object CC_sroot1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138, v196, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroot1");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-3] = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* freevars */
    qvalue(elt(env, 1)) = nil; /* freevars */
    stack[-1] = qvalue(elt(env, 2)); /* substitution */
    qvalue(elt(env, 2)) = nil; /* substitution */
    v138 = qvalue(elt(env, 3)); /* rpt */
    v137 = elt(env, 4); /* inf */
    if (v138 == v137) goto v30;
    v138 = qvalue(elt(env, 3)); /* rpt */
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (Lisp_Object)lesseq2(v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v137 = v137 ? lisp_true : nil;
    env = stack[-5];
    goto v40;

v40:
    if (!(v137 == nil)) goto v162;
    v137 = stack[-3];
    if (!consp(v137)) goto v21;
    v137 = stack[-3];
    v138 = qcar(v137);
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcar(v137);
    v137 = qcar(v137);
    v137 = Lneq(nil, v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v16;

v16:
    if (!(v137 == nil)) goto v162;
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcar(v137);
    fn = elt(env, 12); /* findnewvars */
    v138 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 13); /* union */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 1)) = v137; /* freevars */
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    qvalue(elt(env, 2)) = v137; /* substitution */
    v137 = qvalue(elt(env, 1)); /* freevars */
    stack[-4] = v137;
    goto v160;

v160:
    v137 = stack[-4];
    if (v137 == nil) goto v159;
    v137 = stack[-4];
    v137 = qcar(v137);
    fn = elt(env, 14); /* newenv */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = stack[-4];
    v137 = qcdr(v137);
    stack[-4] = v137;
    goto v160;

v159:
    v137 = qvalue(elt(env, 7)); /* !*trpm */
    if (v137 == nil) goto v100;
    v137 = elt(env, 8); /* "Trying rule  " */
    v137 = Lprinc(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = stack[0];
    fn = elt(env, 15); /* rprint */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = elt(env, 9); /* "against      " */
    v137 = Lprinc(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = stack[-3];
    fn = elt(env, 15); /* rprint */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v100;

v100:
    v137 = stack[0];
    v137 = qcdr(v137);
    v197 = qcar(v137);
    v196 = stack[-3];
    v138 = qvalue(elt(env, 6)); /* t */
    v137 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* amatch */
    v137 = (*qfnn(fn))(qenv(fn), 4, v197, v196, v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-4] = v137;
    v137 = qvalue(elt(env, 7)); /* !*trpm */
    if (v137 == nil) goto v113;
    v137 = stack[-4];
    if (v137 == nil) goto v130;
    v137 = elt(env, 10); /* "producing    " */
    v137 = Lprinc(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-4] = v137;
    fn = elt(env, 15); /* rprint */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v65;

v65:
    v137 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v113;

v113:
    v137 = qvalue(elt(env, 1)); /* freevars */
    stack[0] = v137;
    goto v95;

v95:
    v137 = stack[0];
    if (v137 == nil) goto v199;
    v137 = stack[0];
    v137 = qcar(v137);
    fn = elt(env, 18); /* restorenv */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = stack[0];
    v137 = qcdr(v137);
    stack[0] = v137;
    goto v95;

v199:
    v137 = stack[-4];
    if (v137 == nil) goto v132;
    v138 = qvalue(elt(env, 3)); /* rpt */
    v137 = elt(env, 4); /* inf */
    if (v138 == v137) goto v116;
    v137 = qvalue(elt(env, 3)); /* rpt */
    v137 = sub1(v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 3)) = v137; /* rpt */
    goto v116;

v116:
    v137 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v46;

v46:
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    { popv(6); return onevalue(v137); }

v132:
    v137 = stack[-3];
    goto v46;

v130:
    v137 = elt(env, 11); /* "failed" */
    v137 = Lprinc(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v137 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    goto v65;

v162:
    v137 = stack[-3];
    goto v46;

v21:
    v137 = qvalue(elt(env, 6)); /* t */
    goto v16;

v30:
    v137 = qvalue(elt(env, 5)); /* nil */
    goto v40;
/* error exit handlers */
v198:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    popv(6);
    return nil;
}



/* Code for ratnump */

static Lisp_Object CC_ratnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratnump");
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
    v24 = v0;
/* end of prologue */
    fn = elt(env, 2); /* simp!* */
    v115 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[0];
    v24 = v115;
    v115 = qcar(v115);
    if (!consp(v115)) goto v35;
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v24); }

v35:
    v24 = qcdr(v24);
    v24 = (consp(v24) ? nil : lisp_true);
    { popv(1); return onevalue(v24); }
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for remove_least_item */

static Lisp_Object CC_remove_least_item(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_least_item");
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
    v6 = v0;
/* end of prologue */

v35:
    v51 = v6;
    v51 = qcdr(v51);
    if (v51 == nil) goto v46;
    v51 = v6;
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v51 = qcdr(v51);
    if (v51 == nil) goto v58;
    v6 = qcdr(v6);
    v6 = qcar(v6);
    goto v35;

v58:
    {
        popv(1);
        fn = elt(env, 3); /* remove_root_item */
        return (*qfn1(fn))(qenv(fn), v6);
    }

v46:
    v6 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v6 == nil)) goto v40;
    v6 = elt(env, 2); /* "How did we get here?" */
    fn = elt(env, 4); /* lprie */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[0];
    goto v40;

v40:
    v6 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v6 = nil;
    { popv(1); return onevalue(v6); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for defined_vertex */

static Lisp_Object CC_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_vertex");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */

v31:
    v30 = stack[-1];
    if (v30 == nil) goto v19;
    v30 = stack[-1];
    v36 = qcar(v30);
    v30 = stack[0];
    fn = elt(env, 3); /* memq_edgelist */
    v30 = (*qfn2(fn))(qenv(fn), v36, v30);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    if (v30 == nil) goto v15;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v31;

v15:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v19:
    v30 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v41, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */

v20:
    v34 = v41;
    v7 = qcar(v34);
    v34 = (Lisp_Object)17; /* 1 */
    if (v7 == v34) goto v46;
    v34 = v41;
    v34 = qcdr(v34);
    if (v34 == nil) goto v5;
    v34 = elt(env, 1); /* times */
    return cons(v34, v41);

v5:
    v34 = v41;
    v34 = qcar(v34);
    return onevalue(v34);

v46:
    v34 = v41;
    v34 = qcdr(v34);
    if (v34 == nil) goto v38;
    v34 = v41;
    v34 = qcdr(v34);
    v41 = v34;
    goto v20;

v38:
    v34 = (Lisp_Object)17; /* 1 */
    return onevalue(v34);
}



/* Code for algebnp */

static Lisp_Object CC_algebnp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algebnp");
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

v89:
    v41 = stack[0];
    if (!consp(v41)) goto v35;
    v41 = stack[0];
    v7 = qcar(v41);
    v41 = elt(env, 2); /* !:ar!: */
    if (v7 == v41) goto v19;
    v41 = stack[0];
    if (!consp(v41)) goto v25;
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = (consp(v41) ? nil : lisp_true);
    goto v28;

v28:
    if (v41 == nil) goto v36;
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v41); }

v36:
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = qcdr(v41);
    v41 = CC_algebnp(env, v41);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    if (!(v41 == nil)) { popv(2); return onevalue(v41); }
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[0] = v41;
    goto v89;

v25:
    v41 = qvalue(elt(env, 3)); /* t */
    goto v28;

v19:
    v41 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v41); }

v35:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v41); }
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for movebds */

static Lisp_Object MS_CDECL CC_movebds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "movebds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for movebds");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v26;
    stack[-2] = v0;
/* end of prologue */
    v23 = qvalue(elt(env, 1)); /* !*intp */
    v80 = stack[-1];
    fn = elt(env, 2); /* sgn1 */
    v23 = (*qfn2(fn))(qenv(fn), v23, v80);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v80 = stack[0];
    if (equal(v23, v80)) goto v25;
    v23 = stack[-2];
    v80 = stack[-1];
        popv(3);
        return Lrplaca(nil, v23, v80);

v25:
    v23 = stack[-2];
    v80 = stack[-1];
        popv(3);
        return Lrplacd(nil, v23, v80);
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for gd_newtype */

static Lisp_Object CC_gd_newtype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v50, v10, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_newtype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v26;
    v11 = v0;
/* end of prologue */
    v50 = v11;
    v2 = v10;
    if (v50 == v2) return onevalue(v11);
    v50 = v11;
    v2 = elt(env, 1); /* gec */
    if (v50 == v2) goto v5;
    v50 = v11;
    v2 = elt(env, 2); /* geg */
    if (v50 == v2) return onevalue(v10);
    v50 = v10;
    v2 = elt(env, 1); /* gec */
    if (v50 == v2) goto v82;
    v2 = elt(env, 4); /* ger */
    return onevalue(v2);

v82:
    v2 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v2);

v5:
    v50 = v10;
    v2 = elt(env, 2); /* geg */
    if (v50 == v2) goto v52;
    v2 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v2);

v52:
    v2 = elt(env, 1); /* gec */
    return onevalue(v2);
}



/* Code for addexptsdf */

static Lisp_Object CC_addexptsdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addexptsdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v49;

v49:
    v11 = stack[-1];
    if (v11 == nil) goto v20;
    v11 = stack[0];
    if (v11 == nil) goto v6;
    v11 = stack[-1];
    v12 = qcar(v11);
    v11 = stack[0];
    v11 = qcar(v11);
    fn = elt(env, 3); /* exptplus */
    v12 = (*qfn2(fn))(qenv(fn), v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v11 = stack[-2];
    v11 = cons(v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[-2] = v11;
    v11 = stack[-1];
    v11 = qcdr(v11);
    stack[-1] = v11;
    v11 = stack[0];
    v11 = qcdr(v11);
    stack[0] = v11;
    goto v49;

v6:
    stack[0] = stack[-2];
    v11 = elt(env, 2); /* "Y too long" */
    fn = elt(env, 4); /* interr */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    {
        Lisp_Object v47 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v47, v11);
    }

v20:
    v11 = stack[0];
    if (v11 == nil) goto v40;
    stack[0] = stack[-2];
    v11 = elt(env, 1); /* "X too long" */
    fn = elt(env, 4); /* interr */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    {
        Lisp_Object v48 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v48, v11);
    }

v40:
    v11 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for min2!-order */

static Lisp_Object MS_CDECL CC_min2Korder(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v26,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "min2-order");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min2-order");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v26,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v26;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v46;

v46:
    v45 = stack[-3];
    if (v45 == nil) goto v162;
    v45 = stack[-1];
    v45 = qcar(v45);
    stack[0] = v45;
    v45 = (Lisp_Object)1; /* 0 */
    v76 = v45;
    goto v53;

v53:
    v45 = stack[0];
    if (v45 == nil) goto v36;
    v45 = stack[0];
    v45 = qcar(v45);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v45 = (*qfn2(fn))(qenv(fn), v45, v76);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    v76 = v45;
    v45 = stack[0];
    v45 = qcdr(v45);
    stack[0] = v45;
    goto v53;

v36:
    v45 = v76;
    stack[0] = v45;
    v76 = stack[0];
    v45 = stack[-2];
    v45 = qcar(v45);
    fn = elt(env, 2); /* tayexp!-greaterp */
    v45 = (*qfn2(fn))(qenv(fn), v76, v45);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    if (v45 == nil) goto v131;
    v76 = stack[0];
    v45 = stack[-3];
    v45 = qcar(v45);
    fn = elt(env, 3); /* tayexp!-min2 */
    v45 = (*qfn2(fn))(qenv(fn), v76, v45);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    v76 = v45;
    goto v140;

v140:
    v45 = stack[-4];
    v45 = cons(v76, v45);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    stack[-4] = v45;
    v45 = stack[-3];
    v45 = qcdr(v45);
    stack[-3] = v45;
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v46;

v131:
    v45 = stack[-3];
    v45 = qcar(v45);
    v76 = v45;
    goto v140;

v162:
    v45 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v45);
    }
/* error exit handlers */
v125:
    popv(6);
    return nil;
}



/* Code for depend!-l */

static Lisp_Object CC_dependKl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-l");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v0;
/* end of prologue */

v31:
    v15 = stack[-1];
    if (v15 == nil) goto v19;
    v15 = stack[-1];
    v15 = qcar(v15);
    fn = elt(env, 3); /* simp */
    v14 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v15 = stack[0];
    fn = elt(env, 4); /* depend!-sq */
    v15 = (*qfn2(fn))(qenv(fn), v14, v15);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    if (v15 == nil) goto v38;
    v15 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v15); }

v38:
    v15 = stack[-1];
    v15 = qcdr(v15);
    stack[-1] = v15;
    goto v31;

v19:
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v15); }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for pasf_ordatp */

static Lisp_Object CC_pasf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v101, v195, v64, v156, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ordatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v64 = v26;
    v156 = v0;
/* end of prologue */
    v201 = v156;
    v201 = qcdr(v201);
    v201 = qcar(v201);
    v99 = v201;
    v201 = v64;
    v201 = qcdr(v201);
    v201 = qcar(v201);
    v195 = v201;
    v101 = v99;
    v201 = v195;
    if (equal(v101, v201)) goto v7;
    v201 = v99;
    v101 = v195;
    {
        popv(1);
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v201, v101);
    }

v7:
    v101 = v156;
    v201 = elt(env, 1); /* true */
    if (v101 == v201) goto v34;
    v101 = v156;
    v201 = elt(env, 3); /* false */
    v201 = (v101 == v201 ? lisp_true : nil);
    goto v33;

v33:
    if (v201 == nil) goto v23;
    v201 = v156;
    v195 = v201;
    goto v76;

v76:
    v101 = v64;
    v201 = elt(env, 1); /* true */
    if (v101 == v201) goto v44;
    v101 = v64;
    v201 = elt(env, 3); /* false */
    v201 = (v101 == v201 ? lisp_true : nil);
    goto v191;

v191:
    if (v201 == nil) goto v127;
    v201 = v64;
    goto v17;

v17:
    {
        popv(1);
        fn = elt(env, 5); /* pasf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v195, v201);
    }

v127:
    v201 = v64;
    v201 = qcar(v201);
    v201 = Lconsp(nil, v201);
    env = stack[0];
    if (v201 == nil) goto v62;
    v201 = v64;
    v201 = qcar(v201);
    v201 = qcar(v201);
    goto v17;

v62:
    v201 = v64;
    v201 = qcar(v201);
    goto v17;

v44:
    v201 = qvalue(elt(env, 2)); /* t */
    goto v191;

v23:
    v201 = v156;
    v201 = qcar(v201);
    v201 = Lconsp(nil, v201);
    env = stack[0];
    if (v201 == nil) goto v131;
    v201 = v156;
    v201 = qcar(v201);
    v201 = qcar(v201);
    v195 = v201;
    goto v76;

v131:
    v201 = v156;
    v201 = qcar(v201);
    v195 = v201;
    goto v76;

v34:
    v201 = qvalue(elt(env, 2)); /* t */
    goto v33;
}



/* Code for aex_minus */

static Lisp_Object CC_aex_minus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_minus");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v26;
    stack[-3] = v0;
/* end of prologue */
    v41 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v41 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_minus */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v41 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v41 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v41 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    if (v41 == nil) goto v17;
    v41 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    goto v60;

v60:
    {
        Lisp_Object v92 = stack[-4];
        Lisp_Object v142 = stack[-1];
        Lisp_Object v106 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v92, v142, v106, v41);
    }

v17:
    v41 = qvalue(elt(env, 1)); /* nil */
    goto v60;
/* error exit handlers */
v43:
    popv(6);
    return nil;
}



/* Code for dip_condense */

static Lisp_Object CC_dip_condense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_condense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    return onevalue(v9);
}



/* Code for matrixir */

static Lisp_Object MS_CDECL CC_matrixir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v3, v1;
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
    v141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    fn = elt(env, 6); /* omobjs */
    v141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v1 = v141;
    v141 = v1;
    v141 = qcdr(v141);
    v141 = qcar(v141);
    v141 = qcdr(v141);
    v141 = qcar(v141);
    v3 = qcar(v141);
    v141 = elt(env, 1); /* matrixcolumn */
    if (v3 == v141) goto v25;
    stack[0] = elt(env, 3); /* matrixrow */
    v141 = v1;
    fn = elt(env, 7); /* matrixelems */
    v3 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v141 = qvalue(elt(env, 2)); /* nil */
    v141 = list2star(stack[0], v3, v141);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v1 = v141;
    goto v82;

v82:
    v141 = elt(env, 4); /* matrix */
    v3 = qvalue(elt(env, 2)); /* nil */
    popv(2);
    return list2star(v141, v3, v1);

v25:
    stack[0] = elt(env, 1); /* matrixcolumn */
    v141 = v1;
    fn = elt(env, 7); /* matrixelems */
    v3 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v141 = qvalue(elt(env, 2)); /* nil */
    v141 = list2star(stack[0], v3, v141);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v1 = v141;
    goto v82;
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for crnprimp */

static Lisp_Object CC_crnprimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crnprimp");
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
    v71 = stack[0];
    v71 = qcdr(v71);
    v72 = qcar(v71);
    v71 = (Lisp_Object)17; /* 1 */
    if (v72 == v71) goto v27;
    v71 = qvalue(elt(env, 1)); /* nil */
    goto v46;

v46:
    if (v71 == nil) goto v17;
    v71 = elt(env, 2); /* i */
    { popv(3); return onevalue(v71); }

v17:
    v71 = stack[0];
    stack[-1] = qcar(v71);
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    fn = elt(env, 5); /* !:minus */
    v72 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = list2star(stack[-1], v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v70 = v71;
    v71 = v70;
    v71 = qcdr(v71);
    v72 = qcar(v71);
    v71 = (Lisp_Object)17; /* 1 */
    if (v72 == v71) goto v12;
    v71 = qvalue(elt(env, 1)); /* nil */
    goto v106;

v106:
    if (v71 == nil) goto v107;
    v71 = elt(env, 3); /* minus */
    v72 = elt(env, 2); /* i */
    popv(3);
    return list2(v71, v72);

v107:
    stack[-1] = elt(env, 4); /* times */
    v71 = stack[0];
    fn = elt(env, 6); /* rnprep!: */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v72 = elt(env, 2); /* i */
    {
        Lisp_Object v108 = stack[-1];
        popv(3);
        return list3(v108, v71, v72);
    }

v12:
    v71 = v70;
    v71 = qcdr(v71);
    v72 = qcdr(v71);
    v71 = (Lisp_Object)17; /* 1 */
    v71 = (v72 == v71 ? lisp_true : nil);
    goto v106;

v27:
    v71 = stack[0];
    v71 = qcdr(v71);
    v72 = qcdr(v71);
    v71 = (Lisp_Object)17; /* 1 */
    v71 = (v72 == v71 ? lisp_true : nil);
    goto v46;
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for arprep!: */

static Lisp_Object CC_arprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arprep:");
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
    v115 = v0;
/* end of prologue */
    v24 = qvalue(elt(env, 1)); /* !*reexpress */
    if (v24 == nil) goto v60;
    v24 = v115;
    v24 = qcdr(v24);
    fn = elt(env, 2); /* express!-in!-arvars */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[0];
    goto v35;

v35:
    {
        popv(1);
        fn = elt(env, 3); /* prepf */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v60:
    v24 = v115;
    v24 = qcdr(v24);
    goto v35;
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for make_spoly_pair */

static Lisp_Object CC_make_spoly_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v200, v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_spoly_pair");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v26;
    stack[-3] = v0;
/* end of prologue */

v18:
    v200 = stack[-2];
    v164 = stack[-3];
    fn = elt(env, 3); /* pfordp */
    v164 = (*qfn2(fn))(qenv(fn), v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    if (v164 == nil) goto v38;
    v164 = stack[-2];
    v200 = v164;
    v164 = stack[-3];
    stack[-2] = v164;
    v164 = v200;
    stack[-3] = v164;
    goto v18;

v38:
    v164 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v164 = stack[-2];
    fn = elt(env, 4); /* xval */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    fn = elt(env, 5); /* xlcm */
    v164 = (*qfn2(fn))(qenv(fn), stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-4] = v164;
    v164 = stack[-3];
    v164 = qcdr(v164);
    if (!(v164 == nil)) goto v81;
    v164 = stack[-2];
    v164 = qcdr(v164);
    if (!(v164 == nil)) goto v81;
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v164); }

v81:
    stack[-1] = stack[-4];
    v164 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v164 = stack[-2];
    fn = elt(env, 4); /* xval */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    fn = elt(env, 6); /* triviallcm */
    v164 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    if (v164 == nil) goto v106;
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v164); }

v106:
    v164 = stack[-4];
    fn = elt(env, 7); /* mknwedge */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    fn = elt(env, 8); /* xdegreecheck */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    if (v164 == nil) goto v73;
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v164); }

v73:
    v71 = stack[-4];
    v72 = elt(env, 2); /* spoly_pair */
    v200 = stack[-3];
    v164 = stack[-2];
    popv(6);
    return list4(v71, v72, v200, v164);
/* error exit handlers */
v124:
    popv(6);
    return nil;
}



/* Code for evalsubset */

static Lisp_Object CC_evalsubset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsubset");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v38 = v26;
    v52 = v0;
/* end of prologue */
    v53 = elt(env, 1); /* subset */
    fn = elt(env, 2); /* evalsetbool */
    v38 = (*qfnn(fn))(qenv(fn), 3, v53, v52, v38);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    v52 = v38;
    v38 = v52;
    if (!consp(v38)) { popv(1); return onevalue(v52); }
    v38 = v52;
    {
        popv(1);
        fn = elt(env, 3); /* evalsymsubset */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v5:
    popv(1);
    return nil;
}



/* Code for r2speclist */

static Lisp_Object CC_r2speclist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v50, v10;
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
    v50 = v0;
/* end of prologue */
    v10 = v50;
    v2 = elt(env, 1); /* plus */
    if (!consp(v10)) goto v115;
    v10 = qcar(v10);
    if (!(v10 == v2)) goto v115;
    v2 = v50;
    v2 = qcdr(v2);
    goto v9;

v9:
    v50 = v2;
    v2 = v50;
    stack[-3] = v2;
    v2 = stack[-3];
    if (v2 == nil) goto v15;
    v2 = stack[-3];
    v2 = qcar(v2);
    fn = elt(env, 3); /* r2speclist1 */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    stack[-1] = v2;
    stack[-2] = v2;
    goto v38;

v38:
    v2 = stack[-3];
    v2 = qcdr(v2);
    stack[-3] = v2;
    v2 = stack[-3];
    if (v2 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v2 = stack[-3];
    v2 = qcar(v2);
    fn = elt(env, 3); /* r2speclist1 */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    v2 = Lrplacd(nil, stack[0], v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    v2 = stack[-1];
    v2 = qcdr(v2);
    stack[-1] = v2;
    goto v38;

v15:
    v2 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v2); }

v115:
    v2 = v50;
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    goto v9;
/* error exit handlers */
v79:
    popv(5);
    return nil;
}



/* Code for bassoc */

static Lisp_Object CC_bassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v42, v8, v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v26;
    v82 = v0;
/* end of prologue */

v31:
    v7 = v8;
    if (v7 == nil) goto v19;
    v42 = v82;
    v7 = v8;
    v7 = qcar(v7);
    v7 = qcar(v7);
    if (v42 == v7) goto v115;
    v42 = v82;
    v7 = v8;
    v7 = qcar(v7);
    v7 = qcdr(v7);
    v7 = (v42 == v7 ? lisp_true : nil);
    goto v24;

v24:
    if (v7 == nil) goto v32;
    v7 = v8;
    v7 = qcar(v7);
    return onevalue(v7);

v32:
    v7 = v8;
    v7 = qcdr(v7);
    v8 = v7;
    goto v31;

v115:
    v7 = qvalue(elt(env, 2)); /* t */
    goto v24;

v19:
    v7 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v7);
}



/* Code for subs2chkex */

static Lisp_Object CC_subs2chkex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v80, v23;
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

v89:
    v22 = stack[0];
    if (v22 == nil) goto v35;
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 2); /* subs2chk */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v80 = v22;
    if (v80 == nil) goto v6;
    v80 = stack[0];
    v80 = qcar(v80);
    v23 = qcar(v80);
    v80 = v22;
    v22 = stack[0];
    v22 = qcdr(v22);
    popv(2);
    return acons(v23, v80, v22);

v6:
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v89;

v35:
    v22 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v22); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepcadr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v25 = v37;
    v25 = qcdr(v25);
    v25 = qcar(v25);
    v25 = qcar(v25);
    if (v25 == nil) goto v35;
    v25 = v37;
    v25 = qcdr(v25);
    v37 = qcar(v25);
    v25 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v37, v25);
    }

v35:
    v25 = (Lisp_Object)1; /* 0 */
    return onevalue(v25);
}



/* Code for mo_from_ei */

static Lisp_Object CC_mo_from_ei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v15, v14;
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
    v14 = v0;
/* end of prologue */
    v15 = v14;
    v5 = (Lisp_Object)1; /* 0 */
    if (v15 == v5) goto v35;
    v5 = v14;
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    stack[0] = v5;
    fn = elt(env, 1); /* mo!=deglist */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v36 = stack[0];
        popv(2);
        return cons(v36, v5);
    }

v35:
    {
        popv(2);
        fn = elt(env, 2); /* mo_zero */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for !*v2j */

static Lisp_Object CC_Hv2j(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v80;
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
    v80 = v0;
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* ordering */
    v21 = elt(env, 2); /* lex */
    if (v22 == v21) goto v40;
    stack[0] = (Lisp_Object)17; /* 1 */
    v22 = v80;
    v21 = qvalue(elt(env, 3)); /* varlist */
    fn = elt(env, 4); /* sub01 */
    v21 = (*qfn2(fn))(qenv(fn), v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v32;
    {
        Lisp_Object v33 = stack[0];
        popv(1);
        return cons(v33, v21);
    }

v40:
    v22 = v80;
    v21 = qvalue(elt(env, 3)); /* varlist */
    {
        popv(1);
        fn = elt(env, 4); /* sub01 */
        return (*qfn2(fn))(qenv(fn), v22, v21);
    }
/* error exit handlers */
v32:
    popv(1);
    return nil;
}



/* Code for general!-difference!-mod!-p */

static Lisp_Object CC_generalKdifferenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-difference-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v18 = v26;
    v39 = v0;
/* end of prologue */
    stack[0] = v39;
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    {
        Lisp_Object v115 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v115, v18);
    }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for max!-degree */

static Lisp_Object CC_maxKdegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v77, v78, v79;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for max-degree");
#endif
    if (stack >= stacklimit)
    {
        push2(v26,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v77 = v26;
    v78 = v0;
/* end of prologue */

v49:
    v12 = v78;
    if (!consp(v12)) goto v39;
    v12 = v78;
    v12 = qcar(v12);
    v12 = (consp(v12) ? nil : lisp_true);
    goto v18;

v18:
    if (!(v12 == nil)) { popv(2); return onevalue(v77); }
    v79 = v77;
    v12 = v78;
    v12 = qcar(v12);
    v12 = qcar(v12);
    v12 = qcdr(v12);
    if (((int32_t)(v79)) > ((int32_t)(v12))) goto v25;
    v12 = v78;
    v12 = qcdr(v12);
    stack[0] = v12;
    v12 = v78;
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v77 = v78;
    v77 = qcar(v77);
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v12 = CC_maxKdegree(env, v12, v77);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v77 = v12;
    v12 = stack[0];
    v78 = v12;
    goto v49;

v25:
    v12 = v78;
    v12 = qcdr(v12);
    stack[0] = v12;
    v12 = v78;
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = CC_maxKdegree(env, v12, v77);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v77 = v12;
    v12 = stack[0];
    v78 = v12;
    goto v49;

v39:
    v12 = qvalue(elt(env, 1)); /* t */
    goto v18;
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for list_assoc */

static Lisp_Object CC_list_assoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v26)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v15, v14, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list_assoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v26;
    v14 = v0;
/* end of prologue */

v31:
    v5 = v15;
    if (v5 == nil) return onevalue(v15);
    v5 = v15;
    v5 = qcar(v5);
    v29 = qcar(v5);
    v5 = v14;
    if (equal(v29, v5)) return onevalue(v15);
    v5 = v15;
    v5 = qcdr(v5);
    v15 = v5;
    goto v31;
}



/* Code for girationalize!: */

static Lisp_Object CC_girationalizeT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v200, v71;
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
    v164 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v164; /* !*gcd */
    stack[-1] = stack[-5];
    v164 = stack[-4];
    v164 = qcdr(v164);
    stack[-5] = v164;
    fn = elt(env, 4); /* conjgd */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    stack[0] = v164;
    if (equal(stack[-1], v164)) goto v162;
    stack[-2] = stack[0];
    v200 = stack[-5];
    v164 = stack[0];
    fn = elt(env, 5); /* addf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    v164 = stack[-5];
    fn = elt(env, 6); /* negf */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    v71 = elt(env, 3); /* !:gi!: */
    v200 = (Lisp_Object)1; /* 0 */
    v164 = (Lisp_Object)17; /* 1 */
    v164 = list2star(v71, v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    fn = elt(env, 7); /* multf */
    v164 = (*qfn2(fn))(qenv(fn), stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    fn = elt(env, 8); /* gcdf */
    v200 = (*qfn2(fn))(qenv(fn), stack[-1], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    v164 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* quotf */
    v164 = (*qfn2(fn))(qenv(fn), v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v164 = (*qfn2(fn))(qenv(fn), stack[-2], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    stack[0] = v164;
    v164 = stack[-4];
    v200 = qcar(v164);
    v164 = stack[0];
    fn = elt(env, 7); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    v200 = stack[-5];
    v164 = stack[0];
    fn = elt(env, 7); /* multf */
    v164 = (*qfn2(fn))(qenv(fn), v200, v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    fn = elt(env, 10); /* gigcdsq */
    v164 = (*qfn2(fn))(qenv(fn), stack[-1], v164);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-6];
    goto v49;

v49:
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    { popv(7); return onevalue(v164); }

v162:
    v164 = stack[-4];
    goto v49;
/* error exit handlers */
v124:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    popv(7);
    return nil;
}



/* Code for seprd */

static Lisp_Object MS_CDECL CC_seprd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v29;
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
    v29 = qvalue(elt(env, 2)); /* char */
    v14 = elt(env, 3); /* (s e p !/) */
    if (equal(v29, v14)) goto v19;
    v29 = elt(env, 4); /* "<sep/>" */
    v14 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* errorml */
    v14 = (*qfn2(fn))(qenv(fn), v29, v14);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    goto v19;

v19:
    fn = elt(env, 6); /* lex */
    v14 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    v14 = qvalue(elt(env, 2)); /* char */
        popv(1);
        return Lcompress(nil, v14);
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



setup_type const u39_setup[] =
{
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"rassoc",                  too_few_2,      CC_rassoc,     wrong_no_2},
    {"strand-alg-top",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_strandKalgKtop},
    {"reduce-weights",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKweights},
    {"fs:timescoeff",           too_few_2,      CC_fsTtimescoeff,wrong_no_2},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"*q2f",                    CC_Hq2f,        too_many_1,    wrong_no_1},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {"mri_opn",                 CC_mri_opn,     too_many_1,    wrong_no_1},
    {"pasf_anegateat",          CC_pasf_anegateat,too_many_1,  wrong_no_1},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"vdp_getprop",             too_few_2,      CC_vdp_getprop,wrong_no_2},
    {"csymbolrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_csymbolrd},
    {"ps:term-rthpow",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTtermKrthpow},
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"sfpf",                    CC_sfpf,        too_many_1,    wrong_no_1},
    {"dipnumcontent",           too_few_2,      CC_dipnumcontent,wrong_no_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,too_many_1,wrong_no_1},
    {"xpartitk",                CC_xpartitk,    too_many_1,    wrong_no_1},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"indordlp",                too_few_2,      CC_indordlp,   wrong_no_2},
    {"s_noparents",             CC_s_noparents, too_many_1,    wrong_no_1},
    {"*hfac",                   CC_Hhfac,       too_many_1,    wrong_no_1},
    {"mod/",                    too_few_2,      CC_modV,       wrong_no_2},
    {"cl_nnfnot",               CC_cl_nnfnot,   too_many_1,    wrong_no_1},
    {"addfactors",              too_few_2,      CC_addfactors, wrong_no_2},
    {"ofsf_simplequal",         too_few_2,      CC_ofsf_simplequal,wrong_no_2},
    {"factorf",                 CC_factorf,     too_many_1,    wrong_no_1},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"is_buble",                too_few_2,      CC_is_buble,   wrong_no_2},
    {"groeb=testc1",            CC_groebMtestc1,too_many_1,    wrong_no_1},
    {"checkcoeffts",            too_few_2,      CC_checkcoeffts,wrong_no_2},
    {"pasf_dnf",                CC_pasf_dnf,    too_many_1,    wrong_no_1},
    {"bra_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bra_mk},
    {"ofsf_sacrel-and",         too_few_2,      CC_ofsf_sacrelKand,wrong_no_2},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"operator",                CC_operator,    too_many_1,    wrong_no_1},
    {"sroot1",                  too_few_2,      CC_sroot1,     wrong_no_2},
    {"ratnump",                 CC_ratnump,     too_many_1,    wrong_no_1},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"defined_vertex",          too_few_2,      CC_defined_vertex,wrong_no_2},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"algebnp",                 CC_algebnp,     too_many_1,    wrong_no_1},
    {"movebds",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_movebds},
    {"gd_newtype",              too_few_2,      CC_gd_newtype, wrong_no_2},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"depend-l",                too_few_2,      CC_dependKl,   wrong_no_2},
    {"pasf_ordatp",             too_few_2,      CC_pasf_ordatp,wrong_no_2},
    {"aex_minus",               too_few_2,      CC_aex_minus,  wrong_no_2},
    {"dip_condense",            CC_dip_condense,too_many_1,    wrong_no_1},
    {"matrixir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixir},
    {"crnprimp",                CC_crnprimp,    too_many_1,    wrong_no_1},
    {"arprep:",                 CC_arprepT,     too_many_1,    wrong_no_1},
    {"make_spoly_pair",         too_few_2,      CC_make_spoly_pair,wrong_no_2},
    {"evalsubset",              too_few_2,      CC_evalsubset, wrong_no_2},
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
    {"seprd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_seprd},
    {NULL, (one_args *)"u39", (two_args *)"11079 2404913 5680557", 0}
};

/* end of generated code */
