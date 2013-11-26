
/* $destdir/u32.c        Machine generated C code */

/* Signature: 00000000 26-Nov-2013 */

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


/* Code for redall */

static Lisp_Object MS_CDECL CC_redall(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0052, v0053;
    Lisp_Object fn;
    Lisp_Object v0022, v0049, v0050;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "redall");
    va_start(aa, nargs);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    v0022 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0022,v0049,v0050);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0050,v0049,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0022;
    v0052 = v0049;
    v0051 = v0050;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0051; /* gg!* */
    v0051 = v0052;
    stack[-6] = v0051;
    v0051 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0051; /* shortway!* */
    qvalue(elt(env, 4)) = v0051; /* thirdway!* */
    v0051 = qvalue(elt(env, 5)); /* t */
    stack[-1] = v0051;
    goto v0054;

v0054:
    v0051 = stack[-6];
    if (v0051 == nil) goto v0055;
    v0051 = stack[-6];
    v0051 = Lreverse(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = qcar(v0051);
    stack[-5] = v0051;
    v0052 = stack[-5];
    v0051 = stack[-6];
    v0051 = Ldelete(nil, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    stack[-6] = v0051;
    v0051 = stack[-5];
    v0051 = qcar(v0051);
    stack[-2] = v0051;
    v0052 = qvalue(elt(env, 6)); /* gv!* */
    v0051 = stack[-2];
    v0051 = *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0051/(16/CELL)));
    stack[-4] = v0051;
    v0051 = qvalue(elt(env, 7)); /* path */
    if (v0051 == nil) goto v0057;
    v0051 = stack[-1];
    if (v0051 == nil) goto v0058;
    v0051 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = Lprinc(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = elt(env, 8); /* " ==> " */
    v0051 = Lprinc(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    goto v0057;

v0057:
    stack[-3] = qvalue(elt(env, 6)); /* gv!* */
    stack[0] = stack[-2];
    v0053 = stack[-4];
    v0052 = qvalue(elt(env, 1)); /* gg!* */
    v0051 = stack[-7];
    fn = elt(env, 13); /* nf */
    v0051 = (*qfnn(fn))(qenv(fn), 3, v0053, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0051;
    stack[-5] = v0051;
    v0051 = stack[-5];
    if (v0051 == nil) goto v0059;
    v0051 = stack[-5];
    fn = elt(env, 12); /* ljet */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    goto v0060;

v0060:
    stack[-3] = v0051;
    v0051 = qvalue(elt(env, 7)); /* path */
    if (v0051 == nil) goto v0061;
    v0051 = stack[-3];
    v0051 = Lprinc(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    goto v0061;

v0061:
    v0051 = stack[-5];
    if (v0051 == nil) goto v0054;
    v0051 = stack[-3];
    fn = elt(env, 14); /* ord */
    v0052 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = (Lisp_Object)1; /* 0 */
    if (v0052 == v0051) goto v0062;
    v0051 = stack[-5];
    fn = elt(env, 12); /* ljet */
    stack[0] = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    if (equal(stack[0], v0051)) goto v0063;
    v0051 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v0051; /* shortway!* */
    goto v0063;

v0063:
    v0051 = stack[-1];
    if (v0051 == nil) goto v0064;
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0065;

v0065:
    if (v0051 == nil) goto v0066;
    v0051 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v0051; /* thirdway!* */
    goto v0066;

v0066:
    v0051 = qvalue(elt(env, 1)); /* gg!* */
    stack[-4] = v0051;
    goto v0067;

v0067:
    v0051 = stack[-4];
    if (v0051 == nil) goto v0068;
    v0051 = stack[-4];
    v0051 = qcar(v0051);
    stack[-1] = v0051;
    v0052 = stack[-3];
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    fn = elt(env, 15); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0052 = stack[-7];
    v0051 = (Lisp_Object)33; /* 2 */
    v0051 = plus2(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = (Lisp_Object)geq2(stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-9];
    if (v0051 == nil) goto v0069;
    v0052 = stack[-1];
    v0051 = qvalue(elt(env, 1)); /* gg!* */
    v0051 = Ldelete(nil, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0051; /* gg!* */
    v0052 = stack[-1];
    v0051 = stack[-6];
    fn = elt(env, 16); /* insert */
    v0051 = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    stack[-6] = v0051;
    v0053 = qvalue(elt(env, 11)); /* bv!* */
    v0051 = stack[-1];
    v0052 = qcar(v0051);
    v0051 = qvalue(elt(env, 5)); /* t */
    *(Lisp_Object *)((char *)v0053 + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL))) = v0051;
    goto v0069;

v0069:
    v0051 = stack[-4];
    v0051 = qcdr(v0051);
    stack[-4] = v0051;
    goto v0067;

v0068:
    v0052 = stack[-2];
    v0051 = stack[-3];
    v0052 = cons(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = qvalue(elt(env, 1)); /* gg!* */
    fn = elt(env, 16); /* insert */
    v0051 = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0051; /* gg!* */
    v0051 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0051;
    goto v0054;

v0064:
    v0052 = stack[-5];
    v0051 = stack[-4];
    v0051 = Lneq(nil, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    goto v0065;

v0062:
    v0052 = stack[-5];
    v0051 = qvalue(elt(env, 10)); /* conds!* */
    v0051 = cons(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    qvalue(elt(env, 10)) = v0051; /* conds!* */
    goto v0054;

v0059:
    v0051 = (Lisp_Object)1; /* 0 */
    goto v0060;

v0058:
    v0051 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = Lprinc(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    v0051 = elt(env, 9); /* " --> " */
    v0051 = Lprinc(nil, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-9];
    goto v0057;

v0055:
    v0051 = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = stack[-8]; /* gg!* */
    { popv(10); return onevalue(v0051); }
/* error exit handlers */
v0056:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* gg!* */
    popv(10);
    return nil;
}



/* Code for pa_list2vect */

static Lisp_Object CC_pa_list2vect(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_list2vect");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0050;
    stack[0] = v0070;
/* end of prologue */
    stack[-4] = nil;
    v0094 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0094;
    v0094 = stack[-5];
    v0094 = sub1(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = Lmkvect(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    stack[-6] = v0094;
    v0094 = stack[0];
    stack[-2] = v0094;
    goto v0002;

v0002:
    v0094 = stack[-2];
    if (v0094 == nil) goto v0031;
    v0094 = stack[-2];
    v0094 = qcar(v0094);
    stack[0] = v0094;
    v0095 = elt(env, 2); /* min */
    v0094 = stack[0];
    v0094 = cons(v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    fn = elt(env, 3); /* eval */
    v0095 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = stack[-4];
    v0094 = cons(v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    stack[-4] = v0094;
    v0094 = stack[0];
    stack[-1] = v0094;
    goto v0097;

v0097:
    v0094 = stack[-1];
    if (v0094 == nil) goto v0098;
    v0094 = stack[-1];
    v0094 = qcar(v0094);
    stack[0] = stack[-6];
    v0095 = sub1(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = stack[-4];
    v0094 = qcar(v0094);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL))) = v0094;
    v0094 = stack[-1];
    v0094 = qcdr(v0094);
    stack[-1] = v0094;
    goto v0097;

v0098:
    v0094 = stack[-2];
    v0094 = qcdr(v0094);
    stack[-2] = v0094;
    goto v0002;

v0031:
    v0094 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0094;
    goto v0040;

v0040:
    v0095 = stack[-5];
    v0094 = stack[-1];
    v0094 = difference2(v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = Lminusp(nil, v0094);
    env = stack[-7];
    if (v0094 == nil) goto v0060;
    v0094 = stack[-4];
    v0095 = Lreverse(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0094 = stack[-6];
    popv(8);
    return cons(v0095, v0094);

v0060:
    stack[0] = stack[-6];
    v0094 = stack[-1];
    v0094 = sub1(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0094/(16/CELL)));
    if (!(v0094 == nil)) goto v0042;
    v0095 = stack[-3];
    v0094 = (Lisp_Object)1; /* 0 */
    if (!(v0095 == v0094)) goto v0099;
    v0094 = stack[-1];
    stack[-3] = v0094;
    v0095 = stack[-3];
    v0094 = stack[-4];
    v0094 = cons(v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    stack[-4] = v0094;
    goto v0099;

v0099:
    stack[0] = stack[-6];
    v0094 = stack[-1];
    v0095 = sub1(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0094 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL))) = v0094;
    goto v0042;

v0042:
    v0094 = stack[-1];
    v0094 = add1(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    stack[-1] = v0094;
    goto v0040;
/* error exit handlers */
v0096:
    popv(8);
    return nil;
}



/* Code for simpsqrt2 */

static Lisp_Object CC_simpsqrt2(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrt2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0046 = stack[0];
    fn = elt(env, 2); /* minusf */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    if (v0046 == nil) goto v0098;
    v0103 = stack[0];
    v0046 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 3); /* iequal */
    v0046 = (*qfn2(fn))(qenv(fn), v0103, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    if (v0046 == nil) goto v0055;
    v0046 = qvalue(elt(env, 1)); /* gaussiani */
    { popv(2); return onevalue(v0046); }

v0055:
    v0046 = stack[0];
    fn = elt(env, 4); /* negf */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0103 = v0046;
    v0046 = v0103;
    if (is_number(v0046)) goto v0105;
    v0046 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v0046);
    }

v0105:
    stack[0] = qvalue(elt(env, 1)); /* gaussiani */
    v0046 = v0103;
    fn = elt(env, 5); /* simpsqrt3 */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    {
        Lisp_Object v0106 = stack[0];
        popv(2);
        fn = elt(env, 6); /* multf */
        return (*qfn2(fn))(qenv(fn), v0106, v0046);
    }

v0098:
    v0046 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v0046);
    }
/* error exit handlers */
v0104:
    popv(2);
    return nil;
}



/* Code for depend!-sq */

static Lisp_Object CC_dependKsq(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    v0107 = stack[-1];
    v0092 = qcar(v0107);
    v0107 = stack[0];
    fn = elt(env, 1); /* depend!-f */
    v0107 = (*qfn2(fn))(qenv(fn), v0092, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    if (!(v0107 == nil)) { popv(3); return onevalue(v0107); }
    v0107 = stack[-1];
    v0092 = qcdr(v0107);
    v0107 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v0092, v0107);
    }
/* error exit handlers */
v0108:
    popv(3);
    return nil;
}



/* Code for ofsf_simplequal */

static Lisp_Object CC_ofsf_simplequal(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0042, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simplequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0050;
    stack[-2] = v0070;
/* end of prologue */
    v0044 = stack[-2];
    fn = elt(env, 8); /* ofsf_posdefp */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[-3] = v0044;
    v0042 = stack[-3];
    v0044 = elt(env, 1); /* stsq */
    if (v0042 == v0044) goto v0007;
    v0044 = stack[-2];
    fn = elt(env, 9); /* sfto_sqfpartf */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[0] = v0044;
    v0044 = stack[0];
    fn = elt(env, 8); /* ofsf_posdefp */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    v0043 = v0044;
    v0042 = v0043;
    v0044 = elt(env, 1); /* stsq */
    if (v0042 == v0044) goto v0108;
    v0044 = qvalue(elt(env, 3)); /* !*rlsitsqspl */
    if (v0044 == nil) goto v0119;
    v0044 = qvalue(elt(env, 4)); /* !*rlsiexpla */
    if (!(v0044 == nil)) goto v0120;
    v0044 = qvalue(elt(env, 5)); /* !*rlsiexpl */
    if (v0044 == nil) goto v0119;
    v0042 = stack[-1];
    v0044 = elt(env, 6); /* and */
    if (!(v0042 == v0044)) goto v0119;

v0120:
    v0042 = v0043;
    v0044 = elt(env, 7); /* tsq */
    if (v0042 == v0044) goto v0121;
    v0042 = stack[-3];
    v0044 = elt(env, 7); /* tsq */
    if (!(v0042 == v0044)) goto v0119;
    v0044 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v0044);
    }

v0119:
    v0042 = stack[0];
    v0044 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_facequal!* */
        return (*qfn2(fn))(qenv(fn), v0042, v0044);
    }

v0121:
    v0044 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v0044);
    }

v0108:
    v0044 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0044); }

v0007:
    v0044 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0044); }
/* error exit handlers */
v0118:
    popv(5);
    return nil;
}



/* Code for ev_mtest!? */

static Lisp_Object CC_ev_mtestW(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0091, v0089, v0124, v0098;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0089 = v0050;
    v0124 = v0070;
/* end of prologue */
    v0093 = qvalue(elt(env, 1)); /* t */
    v0098 = v0093;
    goto v0015;

v0015:
    v0093 = v0124;
    if (v0093 == nil) return onevalue(v0098);
    v0093 = v0098;
    if (v0093 == nil) return onevalue(v0098);
    v0093 = v0124;
    v0091 = qcar(v0093);
    v0093 = v0089;
    v0093 = qcar(v0093);
    if (((int32_t)(v0091)) < ((int32_t)(v0093))) goto v0055;
    v0093 = v0124;
    v0093 = qcdr(v0093);
    v0124 = v0093;
    v0093 = v0089;
    v0093 = qcdr(v0093);
    v0089 = v0093;
    goto v0015;

v0055:
    v0093 = qvalue(elt(env, 2)); /* nil */
    v0098 = v0093;
    v0124 = v0093;
    goto v0015;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0093, v0091;
    Lisp_Object fn;
    Lisp_Object v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0070,v0050,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0050;
    v0048 = v0070;
/* end of prologue */
    v0093 = stack[-1];
    v0091 = qcar(v0093);
    v0093 = v0048;
    v0048 = elt(env, 1); /* and */
    v0048 = (v0093 == v0048 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0091, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0093 = stack[0];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    fn = elt(env, 4); /* addsq */
    v0048 = (*qfn2(fn))(qenv(fn), v0093, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0048 = qcar(v0048);
    v0093 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v0128 = stack[-2];
        popv(4);
        return list3(v0128, v0048, v0093);
    }
/* error exit handlers */
v0097:
    popv(4);
    return nil;
}



/* Code for lowupperlimitml */

static Lisp_Object CC_lowupperlimitml(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lowupperlimitml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0123 = elt(env, 1); /* "<lowlimit>" */
    fn = elt(env, 7); /* printout */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    fn = elt(env, 9); /* expression */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = elt(env, 4); /* "</lowlimit>" */
    fn = elt(env, 7); /* printout */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = elt(env, 5); /* "<uplimit>" */
    fn = elt(env, 7); /* printout */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    fn = elt(env, 9); /* expression */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0123 = elt(env, 6); /* "</uplimit>" */
    fn = elt(env, 7); /* printout */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    v0123 = nil;
    { popv(2); return onevalue(v0123); }
/* error exit handlers */
v0122:
    popv(2);
    return nil;
}



/* Code for lengthn */

static Lisp_Object CC_lengthn(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0129 = stack[0];
    if (v0129 == nil) goto v0073;
    v0129 = stack[0];
    v0129 = qcar(v0129);
    if (is_number(v0129)) goto v0008;
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    v0129 = CC_lengthn(env, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    popv(3);
    return add1(v0129);

v0008:
    v0129 = stack[0];
    v0129 = qcar(v0129);
    stack[-1] = sub1(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    v0129 = CC_lengthn(env, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    {
        Lisp_Object v0105 = stack[-1];
        popv(3);
        return plus2(v0105, v0129);
    }

v0073:
    v0129 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0129); }
/* error exit handlers */
v0130:
    popv(3);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2pf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */

v0131:
    v0047 = stack[0];
    if (v0047 == nil) goto v0001;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = qcdr(v0047);
    fn = elt(env, 1); /* resimp */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0048 = v0047;
    v0048 = qcar(v0048);
    if (v0048 == nil) goto v0130;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0093 = qcar(v0048);
    v0048 = v0047;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    popv(2);
    return acons(v0093, v0048, v0047);

v0130:
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0131;

v0001:
    v0047 = nil;
    { popv(2); return onevalue(v0047); }
/* error exit handlers */
v0089:
    popv(2);
    return nil;
}



/* Code for mk_binding */

static Lisp_Object CC_mk_binding(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_binding");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    v0108 = stack[-1];
    v0123 = qcar(v0108);
    v0108 = stack[0];
    fn = elt(env, 2); /* can_be_proved */
    v0108 = (*qfn2(fn))(qenv(fn), v0123, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0108 == nil) goto v0001;
    v0108 = stack[-1];
    v0123 = qcdr(v0108);
    v0108 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* edge_bind */
        return (*qfn2(fn))(qenv(fn), v0123, v0108);
    }

v0001:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0108); }
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for listminimize */

static Lisp_Object CC_listminimize(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0107, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listminimize");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0100 = v0050;
    v0107 = v0070;
/* end of prologue */
    v0092 = v0107;
    if (v0092 == nil) goto v0001;
    v0092 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* cali!=min */
    v0100 = (*qfnn(fn))(qenv(fn), 3, v0092, v0107, v0100);
    errexit();
        return Lreverse(nil, v0100);

v0001:
    v0100 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0100);
}



/* Code for extract_vars */

static Lisp_Object CC_extract_vars(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extract_vars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    stack[-1] = nil;
    goto v0001;

v0001:
    v0093 = stack[0];
    if (v0093 == nil) goto v0132;
    v0093 = stack[0];
    v0093 = qcar(v0093);
    fn = elt(env, 2); /* raiseind!: */
    v0091 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0093 = elt(env, 1); /* variable */
    v0093 = Lflagp(nil, v0091, v0093);
    env = stack[-2];
    if (v0093 == nil) goto v0115;
    v0093 = stack[0];
    v0091 = qcar(v0093);
    v0093 = stack[-1];
    v0093 = cons(v0091, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0001;

v0115:
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0001;

v0132:
    v0093 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for list2vect!* */

static Lisp_Object CC_list2vectH(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2vect*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0050;
    stack[-4] = v0070;
/* end of prologue */
    v0137 = stack[-4];
    v0137 = Llength(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0137 = sub1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0137 = Lmkvect(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    stack[-5] = v0137;
    v0137 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0137;
    goto v0055;

v0055:
    v0137 = stack[-5];
    v0137 = Lupbv(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0057 = add1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0137 = stack[-2];
    v0137 = difference2(v0057, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0137 = Lminusp(nil, v0137);
    env = stack[-6];
    if (!(v0137 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v0137 = stack[-2];
    stack[0] = sub1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    v0057 = stack[-3];
    v0137 = elt(env, 2); /* algebraic */
    if (v0057 == v0137) goto v0138;
    v0057 = stack[-4];
    v0137 = stack[-2];
    fn = elt(env, 3); /* nth */
    v0137 = (*qfn2(fn))(qenv(fn), v0057, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    goto v0115;

v0115:
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0137;
    v0137 = stack[-2];
    v0137 = add1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    stack[-2] = v0137;
    goto v0055;

v0138:
    v0057 = stack[-4];
    v0137 = stack[-2];
    fn = elt(env, 3); /* nth */
    v0137 = (*qfn2(fn))(qenv(fn), v0057, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    fn = elt(env, 4); /* symb_to_alg */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-6];
    goto v0115;
/* error exit handlers */
v0039:
    popv(7);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0129;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for taylorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0129 = v0070;
/* end of prologue */
    v0123 = v0129;
    if (!consp(v0123)) goto v0127;
    v0123 = v0129;
    v0123 = qcar(v0123);
    if (!consp(v0123)) goto v0100;
    v0123 = v0129;
    v0123 = qcar(v0123);
    v0123 = qcar(v0123);
    v0129 = elt(env, 1); /* taylor */
        return Lflagp(nil, v0123, v0129);

v0100:
    v0123 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0123);

v0127:
    v0123 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0123);
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *n2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0031 = v0070;
/* end of prologue */
    v0008 = v0031;
    v0008 = integerp(v0008);
    if (!(v0008 == nil)) return onevalue(v0031);
    v0008 = v0031;
    {
        fn = elt(env, 1); /* !*q2a */
        return (*qfn1(fn))(qenv(fn), v0008);
    }
}



/* Code for maxfrom */

static Lisp_Object CC_maxfrom(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0002 = v0050;
    v0139 = v0070;
/* end of prologue */
    stack[0] = v0139;
    v0139 = add1(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0002 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v0102 = stack[0];
        popv(2);
        fn = elt(env, 1); /* maxfrom1 */
        return (*qfnn(fn))(qenv(fn), 3, v0102, v0139, v0002);
    }
/* error exit handlers */
v0101:
    popv(2);
    return nil;
}



/* Code for depend!-p */

static Lisp_Object CC_dependKp(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0086, v0087, v0141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0050;
    v0141 = v0070;
/* end of prologue */
    v0086 = v0141;
    v0120 = v0087;
    if (v0086 == v0120) goto v0001;
    v0120 = v0141;
    if (!consp(v0120)) goto v0002;
    v0120 = v0141;
    v0120 = qcar(v0120);
    if (!consp(v0120)) goto v0130;
    v0120 = v0141;
    v0086 = v0087;
    {
        fn = elt(env, 4); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v0120, v0086);
    }

v0130:
    v0120 = v0141;
    v0086 = qcar(v0120);
    v0120 = elt(env, 3); /* !*sq */
    if (v0086 == v0120) goto v0089;
    v0120 = v0141;
    v0120 = qcdr(v0120);
    v0086 = v0087;
    {
        fn = elt(env, 5); /* depend!-l */
        return (*qfn2(fn))(qenv(fn), v0120, v0086);
    }

v0089:
    v0120 = v0141;
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0086 = v0087;
    {
        fn = elt(env, 6); /* depend!-sq */
        return (*qfn2(fn))(qenv(fn), v0120, v0086);
    }

v0002:
    v0120 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0120);

v0001:
    v0120 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0120);
}



/* Code for mri_ofsf2mriat */

static Lisp_Object CC_mri_ofsf2mriat(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0101, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0142 = v0050;
    v0101 = v0070;
/* end of prologue */
    v0102 = v0101;
    v0102 = qcar(v0102);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0102, v0101, v0142);
    }
}



/* Code for ofsf_negateat */

static Lisp_Object CC_ofsf_negateat(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0130, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0130 = qcar(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0090 = qcdr(v0090);
    v0090 = qcar(v0090);
    v0090 = list2(v0130, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    stack[-1] = v0090;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    fn = elt(env, 1); /* ofsf_lnegrel */
    v0105 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    v0090 = stack[-1];
    v0130 = qcar(v0090);
    v0090 = stack[-1];
    v0090 = qcdr(v0090);
    v0090 = qcar(v0090);
    popv(3);
    return list3(v0105, v0130, v0090);
/* error exit handlers */
v0125:
    popv(3);
    return nil;
}



/* Code for cnml */

static Lisp_Object MS_CDECL CC_cnml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cnml");
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
    v0158 = qvalue(elt(env, 2)); /* atts */
    v0157 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 12); /* search_att */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-2] = v0157;
    fn = elt(env, 13); /* lex */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = qvalue(elt(env, 4)); /* char */
    stack[0] = v0157;
    fn = elt(env, 13); /* lex */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0158 = stack[-2];
    v0157 = elt(env, 5); /* (c o n s t a n t) */
    if (!(equal(v0158, v0157))) goto v0055;
    v0157 = stack[0];
    v0157 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0158 = Lintern(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = qvalue(elt(env, 6)); /* rdci!* */
    v0158 = Lassoc(nil, v0158, v0157);
    v0157 = v0158;
    if (v0158 == nil) goto v0055;
    v0158 = v0157;
    v0158 = qcdr(v0158);
    v0158 = qcar(v0158);
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    {
        popv(4);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v0158, v0157);
    }

v0055:
    v0157 = stack[0];
    v0157 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    if (!(symbolp(v0157))) goto v0160;
    v0157 = stack[0];
    v0158 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = (Lisp_Object)257; /* 16 */
    fn = elt(env, 15); /* errorml */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    goto v0160;

v0160:
    v0157 = stack[-2];
    if (v0157 == nil) goto v0137;
    v0158 = stack[-2];
    v0157 = elt(env, 7); /* ((r e a l) (i n t e g e r)) */
    v0157 = Lmember(nil, v0158, v0157);
    if (v0157 == nil) goto v0161;
    v0157 = stack[0];
        popv(4);
        return Lcompress(nil, v0157);

v0161:
    v0158 = stack[-2];
    v0157 = elt(env, 8); /* ((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r)) 
*/
    v0157 = Lmember(nil, v0158, v0157);
    if (v0157 == nil) goto v0043;
    fn = elt(env, 16); /* seprd */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-1] = v0157;
    v0158 = stack[-2];
    v0157 = elt(env, 9); /* (r a t i o n a l) */
    if (equal(v0158, v0157)) goto v0162;
    v0158 = stack[-2];
    v0157 = elt(env, 10); /* (c o m p l e x !- c a r t e s i a n) */
    if (equal(v0158, v0157)) goto v0036;
    v0158 = stack[-2];
    v0157 = elt(env, 11); /* (c o m p l e x !- p o l a r) */
    if (!(equal(v0158, v0157))) goto v0043;
    v0157 = stack[0];
    v0158 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[-1];
    fn = elt(env, 17); /* po2ca */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-1] = v0157;
    fn = elt(env, 13); /* lex */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[-1];
    v0158 = qcar(v0157);
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v0158, v0157);
    }

v0043:
    v0157 = nil;
    { popv(4); return onevalue(v0157); }

v0036:
    fn = elt(env, 13); /* lex */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[0];
    v0158 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[-1];
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v0158, v0157);
    }

v0162:
    fn = elt(env, 13); /* lex */
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[0];
    v0158 = Lcompress(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0157 = stack[-1];
    {
        popv(4);
        fn = elt(env, 19); /* alg_quotient */
        return (*qfn2(fn))(qenv(fn), v0158, v0157);
    }

v0137:
    v0157 = stack[0];
        popv(4);
        return Lcompress(nil, v0157);
/* error exit handlers */
v0159:
    popv(4);
    return nil;
}



/* Code for sc_mkmatrix */

static Lisp_Object CC_sc_mkmatrix(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0041, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_mkmatrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0050;
    stack[-6] = v0070;
/* end of prologue */
    v0039 = stack[-6];
    v0039 = sub1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = Lmkvect(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    stack[-7] = v0039;
    v0039 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0039;
    goto v0055;

v0055:
    v0039 = stack[-6];
    v0041 = sub1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = stack[-3];
    v0039 = difference2(v0041, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = Lminusp(nil, v0039);
    env = stack[-8];
    if (!(v0039 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v0039 = stack[-5];
    v0039 = sub1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = Lmkvect(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    stack[-4] = v0039;
    v0039 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0039;
    goto v0098;

v0098:
    v0039 = stack[-5];
    v0041 = sub1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = stack[-2];
    v0039 = difference2(v0041, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = Lminusp(nil, v0039);
    env = stack[-8];
    if (v0039 == nil) goto v0138;
    v0040 = stack[-7];
    v0041 = stack[-3];
    v0039 = stack[-4];
    fn = elt(env, 2); /* sc_iputv */
    v0039 = (*qfnn(fn))(qenv(fn), 3, v0040, v0041, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = stack[-3];
    v0039 = add1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    stack[-3] = v0039;
    goto v0055;

v0138:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v0039 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 3); /* sc_simp */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    fn = elt(env, 2); /* sc_iputv */
    v0039 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    v0039 = stack[-2];
    v0039 = add1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-8];
    stack[-2] = v0039;
    goto v0098;
/* error exit handlers */
v0042:
    popv(9);
    return nil;
}



/* Code for !:log10 */

static Lisp_Object CC_Tlog10(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :log10");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0124 = elt(env, 0); /* !:log10 */
    v0089 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0089;
    v0124 = stack[-1];
    v0089 = elt(env, 1); /* not_found */
    if (!(v0124 == v0089)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0124 = qvalue(elt(env, 2)); /* bften!* */
    v0089 = stack[0];
    fn = elt(env, 4); /* log!: */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0089;
    v0124 = elt(env, 0); /* !:log10 */
    v0089 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0128:
    popv(3);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indexvp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0031 = v0070;
/* end of prologue */
    v0008 = v0031;
    if (!consp(v0008)) goto v0030;
    v0008 = v0031;
    v0008 = qcar(v0008);
    if (!symbolp(v0008)) v0008 = nil;
    else { v0008 = qfastgets(v0008);
           if (v0008 != nil) { v0008 = elt(v0008, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0008 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0008 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0008 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0008 == SPID_NOPROP) v0008 = nil; else v0008 = lisp_true; }}
#endif
    return onevalue(v0008);

v0030:
    v0008 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0008);
}



/* Code for verify_tens_ids */

static Lisp_Object CC_verify_tens_ids(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for verify_tens_ids");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0070;
/* end of prologue */
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0088 = v0138;
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    v0138 = qcar(v0138);
    stack[0] = v0138;
    v0138 = v0088;
    fn = elt(env, 4); /* extract_dummy_ids */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    fn = elt(env, 5); /* repeats */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    if (!(v0138 == nil)) goto v0107;
    v0138 = stack[0];
    fn = elt(env, 4); /* extract_dummy_ids */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    fn = elt(env, 5); /* repeats */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    if (!(v0138 == nil)) goto v0107;
    v0138 = qvalue(elt(env, 3)); /* t */
    { popv(4); return onevalue(v0138); }

v0107:
    stack[-2] = elt(env, 1); /* cantens */
    stack[0] = (Lisp_Object)33; /* 2 */
    v0138 = stack[-1];
    v0088 = qcar(v0138);
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    v0138 = qcar(v0138);
    v0088 = list2(v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    v0138 = elt(env, 2); /* "are inconsistent lists of indices" */
    v0138 = list2(v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    fn = elt(env, 6); /* rerror */
    v0138 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0138 = nil;
    { popv(4); return onevalue(v0138); }
/* error exit handlers */
v0135:
    popv(4);
    return nil;
}



/* Code for get_char_group */

static Lisp_Object CC_get_char_group(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object v0000;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_char_group");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0000 = v0070;
/* end of prologue */
    v0000 = qcar(v0000);
    return onevalue(v0000);
}



/* Code for rl_bnfsimpl */

static Lisp_Object CC_rl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0101 = v0050;
    v0102 = v0070;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bnfsimpl!* */
    v0101 = list2(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    {
        Lisp_Object v0054 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0054, v0101);
    }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for ratpoly_subrat1 */

static Lisp_Object MS_CDECL CC_ratpoly_subrat1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0043;
    Lisp_Object fn;
    Lisp_Object v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratpoly_subrat1");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_subrat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0070,v0050,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0049;
    v0042 = v0050;
    stack[0] = v0070;
/* end of prologue */
    v0043 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 2); /* sfto_mvartest */
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    if (v0042 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0042 = stack[-1];
    v0042 = qcar(v0042);
    stack[-5] = v0042;
    v0042 = stack[-1];
    v0042 = qcdr(v0042);
    stack[-4] = v0042;
    v0042 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0042;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 3); /* coeffs */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    v0043 = v0042;
    v0042 = v0043;
    v0042 = qcar(v0042);
    stack[0] = v0042;
    v0042 = v0043;
    v0042 = qcdr(v0042);
    stack[-2] = v0042;
    goto v0091;

v0091:
    v0042 = stack[-2];
    if (v0042 == nil) goto v0166;
    v0042 = stack[-2];
    v0042 = qcar(v0042);
    stack[-1] = v0042;
    v0043 = stack[-3];
    v0042 = stack[-4];
    v0042 = times2(v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    stack[-3] = v0042;
    v0043 = stack[0];
    v0042 = stack[-5];
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    v0043 = stack[-1];
    v0042 = stack[-3];
    fn = elt(env, 4); /* multf */
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    v0042 = (*qfn2(fn))(qenv(fn), stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-6];
    stack[0] = v0042;
    v0042 = stack[-2];
    v0042 = qcdr(v0042);
    stack[-2] = v0042;
    goto v0091;

v0166:
    v0043 = stack[0];
    v0042 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0043, v0042);
/* error exit handlers */
v0082:
    popv(7);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_surep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0101 = v0050;
    v0102 = v0070;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v0101 = list2(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    {
        Lisp_Object v0054 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0054, v0101);
    }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for matrixir */

static Lisp_Object MS_CDECL CC_matrixir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0121, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixir");
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
    fn = elt(env, 5); /* lex */
    v0135 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    fn = elt(env, 6); /* omobjs */
    v0135 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0140 = v0135;
    v0135 = v0140;
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    v0121 = qcar(v0135);
    v0135 = elt(env, 1); /* matrixcolumn */
    if (v0121 == v0135) goto v0100;
    stack[0] = elt(env, 3); /* matrixrow */
    v0135 = v0140;
    fn = elt(env, 7); /* matrixelems */
    v0121 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0135 = qvalue(elt(env, 2)); /* nil */
    v0135 = list2star(stack[0], v0121, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0140 = v0135;
    goto v0103;

v0103:
    v0135 = elt(env, 4); /* matrix */
    v0121 = qvalue(elt(env, 2)); /* nil */
    popv(2);
    return list2star(v0135, v0121, v0140);

v0100:
    stack[0] = elt(env, 1); /* matrixcolumn */
    v0135 = v0140;
    fn = elt(env, 7); /* matrixelems */
    v0121 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0135 = qvalue(elt(env, 2)); /* nil */
    v0135 = list2star(stack[0], v0121, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0140 = v0135;
    goto v0103;
/* error exit handlers */
v0086:
    popv(2);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:zerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0002 = v0070;
/* end of prologue */
    fn = elt(env, 2); /* ps!:value */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[0];
    v0139 = v0002;
    v0002 = v0139;
    if (is_number(v0002)) goto v0029;
    v0002 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0002); }

v0029:
    v0002 = v0139;
        popv(1);
        return Lzerop(nil, v0002);
/* error exit handlers */
v0142:
    popv(1);
    return nil;
}



/* Code for remzzzz */

static Lisp_Object CC_remzzzz(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0104, v0106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remzzzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    v0106 = nil;
    goto v0000;

v0000:
    v0136 = stack[-1];
    if (v0136 == nil) goto v0008;
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    v0104 = qcar(v0136);
    v0136 = stack[0];
    v0136 = qcar(v0136);
    v0136 = qcar(v0136);
    if (equal(v0104, v0136)) goto v0117;
    v0136 = stack[0];
    v0136 = qcar(v0136);
    v0104 = v0106;
    v0136 = cons(v0136, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0106 = v0136;
    v0136 = stack[0];
    v0136 = qcdr(v0136);
    stack[0] = v0136;
    goto v0000;

v0117:
    v0136 = stack[-1];
    v0136 = qcdr(v0136);
    stack[-1] = v0136;
    v0136 = stack[0];
    v0136 = qcdr(v0136);
    stack[0] = v0136;
    goto v0000;

v0008:
    v0104 = v0106;
    v0136 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0104, v0136);
    }
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for multsqpf */

static Lisp_Object CC_multsqpf(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multsqpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0050;
    stack[-2] = v0070;
/* end of prologue */
    stack[-3] = nil;
    goto v0000;

v0000:
    v0136 = stack[-1];
    if (v0136 == nil) goto v0008;
    v0136 = stack[-2];
    v0136 = qcar(v0136);
    v0136 = (v0136 == nil ? lisp_true : nil);
    goto v0007;

v0007:
    if (v0136 == nil) goto v0126;
    v0136 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0136);
    }

v0126:
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    stack[0] = qcar(v0136);
    v0104 = stack[-2];
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    v0136 = qcdr(v0136);
    fn = elt(env, 3); /* multsq */
    v0104 = (*qfn2(fn))(qenv(fn), v0104, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0136 = stack[-3];
    v0136 = acons(stack[0], v0104, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    stack[-3] = v0136;
    v0136 = stack[-1];
    v0136 = qcdr(v0136);
    stack[-1] = v0136;
    goto v0000;

v0008:
    v0136 = qvalue(elt(env, 1)); /* t */
    goto v0007;
/* error exit handlers */
v0113:
    popv(5);
    return nil;
}



/* Code for !:log2 */

static Lisp_Object CC_Tlog2(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :log2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0124 = elt(env, 0); /* !:log2 */
    v0089 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0089;
    v0124 = stack[-1];
    v0089 = elt(env, 1); /* not_found */
    if (!(v0124 == v0089)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0124 = qvalue(elt(env, 2)); /* bftwo!* */
    v0089 = stack[0];
    fn = elt(env, 4); /* log!: */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0089;
    v0124 = elt(env, 0); /* !:log2 */
    v0089 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v0089 = (*qfn2(fn))(qenv(fn), v0124, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0128:
    popv(3);
    return nil;
}



/* Code for subfindices */

static Lisp_Object CC_subfindices(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subfindices");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0050;
    stack[-2] = v0070;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0178 = qvalue(elt(env, 2)); /* nil */
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0178; /* alglist!* */
    v0178 = stack[-2];
    if (!consp(v0178)) goto v0031;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = (consp(v0178) ? nil : lisp_true);
    goto v0008;

v0008:
    if (v0178 == nil) goto v0093;
    v0179 = stack[-2];
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    goto v0001;

v0001:
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    { popv(5); return onevalue(v0178); }

v0093:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (!consp(v0178)) goto v0140;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 5); /* sfp */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    if (v0178 == nil) goto v0180;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = stack[-1];
    v0179 = CC_subfindices(env, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    fn = elt(env, 6); /* exptsq */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[0] = v0178;
    goto v0181;

v0181:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = stack[-1];
    v0178 = CC_subfindices(env, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    fn = elt(env, 7); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = stack[-2];
    v0179 = qcdr(v0178);
    v0178 = stack[-1];
    v0178 = CC_subfindices(env, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    fn = elt(env, 8); /* addsq */
    v0178 = (*qfn2(fn))(qenv(fn), stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    goto v0001;

v0180:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0178 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0178 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0178 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; else v0178 = lisp_true; }}
#endif
    if (v0178 == nil) goto v0148;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    stack[0] = qcar(v0178);
    v0179 = stack[-1];
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = Lsubla(nil, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = cons(stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    fn = elt(env, 9); /* simpindexvar */
    v0179 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    fn = elt(env, 6); /* exptsq */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[0] = v0178;
    goto v0181;

v0148:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = elt(env, 4); /* (wedge d partdf innerprod liedf hodge vardf) 
*/
    v0178 = Lmemq(nil, v0179, v0178);
    if (v0178 == nil) goto v0182;
    v0179 = stack[-1];
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 10); /* subindk */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    fn = elt(env, 11); /* simp */
    v0179 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    fn = elt(env, 6); /* exptsq */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[0] = v0178;
    goto v0181;

v0182:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0179 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[0] = v0178;
    goto v0181;

v0140:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0179 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[0] = v0178;
    goto v0181;

v0031:
    v0178 = qvalue(elt(env, 3)); /* t */
    goto v0008;
/* error exit handlers */
v0016:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    popv(5);
    return nil;
}



/* Code for compactf1 */

static Lisp_Object MS_CDECL CC_compactf1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0093, v0091, v0089, v0124;
    Lisp_Object fn;
    Lisp_Object v0022, v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "compactf1");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    v0022 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0022,v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0070,v0050,v0049,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
    stack[-1] = v0049;
    stack[-2] = v0050;
    stack[-3] = v0070;
/* end of prologue */
    v0093 = stack[-1];
    v0048 = stack[0];
    fn = elt(env, 1); /* intersection */
    v0048 = (*qfn2(fn))(qenv(fn), v0093, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0093 = v0048;
    if (v0093 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0124 = stack[-3];
    v0089 = stack[-2];
    v0091 = stack[-1];
    v0093 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* compactf11 */
        return (*qfnn(fn))(qenv(fn), 5, v0124, v0089, v0091, v0093, v0048);
    }
/* error exit handlers */
v0046:
    popv(5);
    return nil;
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0097, v0128;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0097 = v0070;
/* end of prologue */

v0015:
    v0098 = v0097;
    v0128 = qcar(v0098);
    v0098 = (Lisp_Object)17; /* 1 */
    if (v0128 == v0098) goto v0165;
    v0098 = v0097;
    v0098 = qcdr(v0098);
    if (v0098 == nil) goto v0108;
    v0098 = elt(env, 1); /* times */
    return cons(v0098, v0097);

v0108:
    v0098 = v0097;
    v0098 = qcar(v0098);
    return onevalue(v0098);

v0165:
    v0098 = v0097;
    v0098 = qcdr(v0098);
    if (v0098 == nil) goto v0092;
    v0098 = v0097;
    v0098 = qcdr(v0098);
    v0097 = v0098;
    goto v0015;

v0092:
    v0098 = (Lisp_Object)17; /* 1 */
    return onevalue(v0098);
}



/* Code for makecoeffpairs */

static Lisp_Object MS_CDECL CC_makecoeffpairs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0054, v0100, v0107;
    Lisp_Object fn;
    Lisp_Object v0022, v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    v0022 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0022,v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0070,v0050,v0049,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0022;
    v0054 = v0049;
    v0100 = v0050;
    v0107 = v0070;
/* end of prologue */
    fn = elt(env, 1); /* makecoeffpairs1 */
    v0055 = (*qfnn(fn))(qenv(fn), 4, v0107, v0100, v0054, v0055);
    errexit();
    v0055 = qcdr(v0055);
        return Lnreverse(nil, v0055);
}



/* Code for mri_2ofsfat */

static Lisp_Object CC_mri_2ofsfat(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2ofsfat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0002 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0002 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0139 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0117 = stack[-1];
        popv(3);
        return list3(v0117, v0002, v0139);
    }
/* error exit handlers */
v0102:
    popv(3);
    return nil;
}



/* Code for quotfx1 */

static Lisp_Object CC_quotfx1(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219, v0220, v0221, v0222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfx1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0050;
    stack[-8] = v0070;
/* end of prologue */
    v0219 = stack[-8];
    if (v0219 == nil) goto v0015;
    v0220 = stack[-8];
    v0219 = stack[-7];
    if (equal(v0220, v0219)) goto v0139;
    v0220 = stack[-7];
    v0219 = (Lisp_Object)17; /* 1 */
    if (v0220 == v0219) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0219 = stack[-7];
    if (!consp(v0219)) goto v0093;
    v0219 = stack[-7];
    v0219 = qcar(v0219);
    v0219 = (consp(v0219) ? nil : lisp_true);
    goto v0048;

v0048:
    if (v0219 == nil) goto v0125;
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 2); /* quotfdx */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0125:
    v0219 = stack[-8];
    if (!consp(v0219)) goto v0140;
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = (consp(v0219) ? nil : lisp_true);
    goto v0121;

v0121:
    if (v0219 == nil) goto v0110;
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); /* quotfxerr */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0110:
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0220 = qcar(v0219);
    v0219 = stack[-7];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    if (v0220 == v0219) goto v0223;
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0220 = qcar(v0219);
    v0219 = stack[-7];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    fn = elt(env, 4); /* ordop */
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    if (v0219 == nil) goto v0225;
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 5); /* quotkx */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0225:
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); /* quotfxerr */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0223:
    stack[-9] = nil;
    stack[-1] = nil;
    v0219 = stack[-7];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0219 = qcdr(v0219);
    stack[-5] = v0219;
    goto v0226;

v0226:
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0220 = qcdr(v0219);
    stack[-6] = v0220;
    v0219 = stack[-5];
    v0219 = (Lisp_Object)lessp2(v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    v0219 = v0219 ? lisp_true : nil;
    env = stack[-10];
    if (v0219 == nil) goto v0152;
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); /* quotfxerr */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0152:
    v0219 = stack[-8];
    fn = elt(env, 6); /* lt!* */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[0] = v0219;
    v0219 = stack[-7];
    fn = elt(env, 6); /* lt!* */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    v0220 = stack[-7];
    v0220 = qcar(v0220);
    v0220 = qcar(v0220);
    v0220 = qcar(v0220);
    stack[-4] = v0220;
    v0220 = stack[0];
    v0220 = qcdr(v0220);
    v0219 = qcdr(v0219);
    v0219 = CC_quotfx1(env, v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-3] = v0219;
    v0220 = stack[-6];
    v0219 = stack[-5];
    v0219 = (Lisp_Object)(int32_t)((int32_t)v0220 - (int32_t)v0219 + TAG_FIXNUM);
    stack[0] = v0219;
    v0220 = stack[0];
    v0219 = (Lisp_Object)1; /* 0 */
    if (v0220 == v0219) goto v0157;
    v0220 = stack[-4];
    v0219 = stack[0];
    fn = elt(env, 7); /* to */
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-2] = v0219;
    v0219 = stack[-9];
    if (!(v0219 == nil)) goto v0227;
    v0222 = stack[-8];
    v0221 = stack[-4];
    v0220 = stack[-6];
    v0219 = stack[0];
    v0219 = (Lisp_Object)(int32_t)((int32_t)v0220 - (int32_t)v0219 + TAG_FIXNUM);
    v0219 = (Lisp_Object)((int32_t)(v0219) - 0x10);
    fn = elt(env, 8); /* cutf */
    v0219 = (*qfnn(fn))(qenv(fn), 3, v0222, v0221, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-8] = v0219;
    goto v0227;

v0227:
    v0219 = qvalue(elt(env, 1)); /* t */
    stack[-9] = v0219;
    v0222 = stack[-7];
    v0221 = stack[-4];
    v0220 = stack[-5];
    v0219 = stack[0];
    v0219 = (Lisp_Object)(int32_t)((int32_t)v0220 - (int32_t)v0219 + TAG_FIXNUM);
    v0219 = (Lisp_Object)((int32_t)(v0219) - 0x10);
    fn = elt(env, 8); /* cutf */
    v0219 = (*qfnn(fn))(qenv(fn), 3, v0222, v0221, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-7] = v0219;
    stack[-6] = stack[-8];
    v0220 = stack[0];
    v0219 = (Lisp_Object)1; /* 0 */
    if (v0220 == v0219) goto v0228;
    v0220 = stack[-2];
    v0219 = (Lisp_Object)17; /* 1 */
    v0219 = cons(v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    v0220 = ncons(v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    v0219 = stack[-7];
    fn = elt(env, 9); /* multf */
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[0] = v0219;
    goto v0229;

v0229:
    v0219 = stack[-3];
    fn = elt(env, 10); /* negf */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    fn = elt(env, 9); /* multf */
    v0219 = (*qfn2(fn))(qenv(fn), stack[0], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    fn = elt(env, 11); /* addf */
    v0219 = (*qfn2(fn))(qenv(fn), stack[-6], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-8] = v0219;
    v0219 = stack[-8];
    if (v0219 == nil) goto v0230;
    v0219 = stack[-8];
    if (!consp(v0219)) goto v0231;
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = (consp(v0219) ? nil : lisp_true);
    goto v0232;

v0232:
    if (v0219 == nil) goto v0233;
    v0219 = qvalue(elt(env, 1)); /* t */
    goto v0234;

v0234:
    if (v0219 == nil) goto v0230;
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); /* quotfxerr */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0230:
    stack[0] = stack[-1];
    v0220 = stack[-2];
    v0219 = stack[-3];
    v0219 = cons(v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    fn = elt(env, 12); /* aconc!* */
    v0219 = (*qfn2(fn))(qenv(fn), stack[0], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-10];
    stack[-1] = v0219;
    v0219 = stack[-8];
    if (v0219 == nil) { Lisp_Object res = stack[-1]; popv(11); return onevalue(res); }
    else goto v0226;

v0233:
    v0219 = stack[-8];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0220 = qcar(v0219);
    v0219 = stack[-4];
    v0219 = (v0220 == v0219 ? lisp_true : nil);
    v0219 = (v0219 == nil ? lisp_true : nil);
    goto v0234;

v0231:
    v0219 = qvalue(elt(env, 1)); /* t */
    goto v0232;

v0228:
    v0219 = stack[-7];
    stack[0] = v0219;
    goto v0229;

v0157:
    v0220 = stack[-1];
    v0219 = stack[-3];
    {
        popv(11);
        fn = elt(env, 13); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }

v0140:
    v0219 = qvalue(elt(env, 1)); /* t */
    goto v0121;

v0093:
    v0219 = qvalue(elt(env, 1)); /* t */
    goto v0048;

v0139:
    v0219 = (Lisp_Object)17; /* 1 */
    { popv(11); return onevalue(v0219); }

v0015:
    v0220 = stack[-8];
    v0219 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); /* quotfxerr */
        return (*qfn2(fn))(qenv(fn), v0220, v0219);
    }
/* error exit handlers */
v0224:
    popv(11);
    return nil;
}



/* Code for numir */

static Lisp_Object MS_CDECL CC_numir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0020, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "numir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numir");
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
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* end of prologue */
    v0020 = qvalue(elt(env, 1)); /* atts */
    v0250 = elt(env, 2); /* name */
    fn = elt(env, 12); /* find */
    v0250 = (*qfn2(fn))(qenv(fn), v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0250 = Lintern(nil, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    stack[-1] = v0250;
    fn = elt(env, 13); /* lex */
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    stack[0] = v0250;
    fn = elt(env, 13); /* lex */
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0021 = stack[-1];
    v0020 = elt(env, 3); /* complex_cartesian */
    if (!(v0021 == v0020)) goto v0040;
    v0020 = stack[0];
    if (symbolp(v0020)) goto v0093;
    v0020 = v0250;
    if (!(symbolp(v0020))) goto v0040;

v0093:
    stack[-4] = elt(env, 4); /* plus */
    stack[-3] = qvalue(elt(env, 5)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v0021 = v0250;
    v0020 = elt(env, 7); /* !&imaginaryi!; */
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(v0021, v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0020 = list2star(stack[-1], stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(stack[-2], v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        Lisp_Object v0208 = stack[-4];
        Lisp_Object v0206 = stack[-3];
        popv(8);
        return list2star(v0208, v0206, v0250);
    }

v0040:
    v0021 = stack[-1];
    v0020 = elt(env, 8); /* complex_polar */
    if (!(v0021 == v0020)) goto v0066;
    v0020 = stack[0];
    if (symbolp(v0020)) goto v0193;
    v0020 = v0250;
    if (!(symbolp(v0020))) goto v0066;

v0193:
    stack[-6] = elt(env, 6); /* times */
    stack[-5] = qvalue(elt(env, 5)); /* nil */
    stack[-4] = stack[0];
    stack[-3] = elt(env, 9); /* exp */
    stack[-2] = qvalue(elt(env, 5)); /* nil */
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v0021 = v0250;
    v0020 = elt(env, 7); /* !&imaginaryi!; */
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(v0021, v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0250 = list2star(stack[-1], stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0020 = list2star(stack[-3], stack[-2], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-7];
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(stack[-4], v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        Lisp_Object v0251 = stack[-6];
        Lisp_Object v0252 = stack[-5];
        popv(8);
        return list2star(v0251, v0252, v0250);
    }

v0066:
    v0021 = stack[-1];
    v0020 = elt(env, 10); /* rational */
    if (!(v0021 == v0020)) goto v0253;
    v0020 = stack[0];
    if (symbolp(v0020)) goto v0254;
    v0020 = v0250;
    if (!(symbolp(v0020))) goto v0253;

v0254:
    stack[-2] = elt(env, 11); /* divide */
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v0021 = stack[0];
    v0020 = v0250;
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(v0021, v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        Lisp_Object v0255 = stack[-2];
        Lisp_Object v0256 = stack[-1];
        popv(8);
        return list2star(v0255, v0256, v0250);
    }

v0253:
    stack[-2] = stack[-1];
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v0021 = stack[0];
    v0020 = v0250;
    v0250 = qvalue(elt(env, 5)); /* nil */
    v0250 = list2star(v0021, v0020, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        Lisp_Object v0013 = stack[-2];
        Lisp_Object v0014 = stack[-1];
        popv(8);
        return list2star(v0013, v0014, v0250);
    }
/* error exit handlers */
v0017:
    popv(8);
    return nil;
}



/* Code for mulpower */

static Lisp_Object CC_mulpower(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0088, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mulpower");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0138 = v0050;
    v0088 = v0070;
/* end of prologue */
    stack[0] = nil;
    fn = elt(env, 3); /* addexptsdf */
    v0138 = (*qfn2(fn))(qenv(fn), v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    stack[-1] = v0138;
    v0138 = qvalue(elt(env, 1)); /* sqrtlist */
    if (v0138 == nil) goto v0129;
    v0088 = stack[-1];
    v0138 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 4); /* reduceroots */
    v0138 = (*qfn2(fn))(qenv(fn), v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    stack[0] = v0138;
    goto v0129;

v0129:
    v0113 = stack[-1];
    v0088 = (Lisp_Object)17; /* 1 */
    v0138 = (Lisp_Object)17; /* 1 */
    v0138 = list2star(v0113, v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    v0138 = ncons(v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    stack[-1] = v0138;
    v0138 = stack[0];
    if (v0138 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0088 = stack[-1];
    v0138 = stack[0];
    fn = elt(env, 5); /* multdf */
    v0138 = (*qfn2(fn))(qenv(fn), v0088, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    stack[-1] = v0138;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0135:
    popv(3);
    return nil;
}



/* Code for sfpf */

static Lisp_Object CC_sfpf(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0127 = v0070;
/* end of prologue */
    v0092 = v0127;
    if (!consp(v0092)) goto v0132;
    v0092 = v0127;
    v0092 = qcar(v0092);
    v0092 = (consp(v0092) ? nil : lisp_true);
    goto v0165;

v0165:
    if (v0092 == nil) goto v0073;
    v0092 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0092);

v0073:
    v0092 = v0127;
    v0092 = qcar(v0092);
    v0092 = qcar(v0092);
    v0092 = qcar(v0092);
    {
        fn = elt(env, 3); /* sfp */
        return (*qfn1(fn))(qenv(fn), v0092);
    }

v0132:
    v0092 = qvalue(elt(env, 1)); /* t */
    goto v0165;
}



/* Code for gbfdiff */

static Lisp_Object CC_gbfdiff(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    v0123 = stack[-1];
    v0129 = qcar(v0123);
    v0123 = stack[0];
    v0123 = qcar(v0123);
    fn = elt(env, 1); /* difbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0129, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    v0123 = stack[-1];
    v0129 = qcdr(v0123);
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    fn = elt(env, 1); /* difbf */
    v0123 = (*qfn2(fn))(qenv(fn), v0129, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    {
        Lisp_Object v0116 = stack[-2];
        popv(4);
        return cons(v0116, v0123);
    }
/* error exit handlers */
v0105:
    popv(4);
    return nil;
}



/* Code for listquotient */

static Lisp_Object CC_listquotient(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048, v0093, v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listquotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0093 = v0050;
    v0091 = v0070;
/* end of prologue */
    v0048 = v0093;
    v0047 = (Lisp_Object)17; /* 1 */
    if (v0048 == v0047) return onevalue(v0091);
    v0048 = v0093;
    v0047 = v0091;
    if (equal(v0048, v0047)) goto v0002;
    v0047 = elt(env, 1); /* quotient */
    v0048 = v0091;
    return list3(v0047, v0048, v0093);

v0002:
    v0047 = (Lisp_Object)17; /* 1 */
    return onevalue(v0047);
}



/* Code for boolvalue!* */

static Lisp_Object CC_boolvalueH(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0117;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for boolvalue*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0117 = v0070;
/* end of prologue */
    v0102 = v0117;
    if (v0102 == nil) goto v0073;
    v0102 = (Lisp_Object)1; /* 0 */
    v0102 = (v0117 == v0102 ? lisp_true : nil);
    v0102 = (v0102 == nil ? lisp_true : nil);
    return onevalue(v0102);

v0073:
    v0102 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0102);
}



/* Code for fs!:minusp!: */

static Lisp_Object CC_fsTminuspT(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0001 = v0070;
/* end of prologue */
    v0001 = qcdr(v0001);
    {
        fn = elt(env, 1); /* fs!:minusp */
        return (*qfn1(fn))(qenv(fn), v0001);
    }
}



/* Code for groeb!=crita */

static Lisp_Object CC_groebMcrita(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0070;
/* end of prologue */
    v0029 = v0030;
    v0030 = elt(env, 1); /* groeb!=testa */
    {
        fn = elt(env, 2); /* listminimize */
        return (*qfn2(fn))(qenv(fn), v0029, v0030);
    }
}



/* Code for flattens1 */

static Lisp_Object CC_flattens1(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flattens1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */

v0073:
    v0090 = stack[0];
    if (!consp(v0090)) goto v0165;
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    if (v0090 == nil) goto v0108;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    stack[-1] = CC_flattens1(env, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0090 = CC_flattens1(env, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    {
        Lisp_Object v0115 = stack[-1];
        popv(3);
        return Lappend(nil, v0115, v0090);
    }

v0108:
    v0090 = stack[0];
    v0090 = qcar(v0090);
    stack[0] = v0090;
    goto v0073;

v0165:
    v0090 = stack[0];
    popv(3);
    return ncons(v0090);
/* error exit handlers */
v0116:
    popv(3);
    return nil;
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0201, v0273, v0274, v0275, v0276, v0277, v0278;
    Lisp_Object fn;
    Lisp_Object v0022, v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    v0022 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0022,v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0070,v0050,v0049,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0022;
    stack[-2] = v0049;
    v0273 = v0050;
    stack[-3] = v0070;
/* end of prologue */
    v0201 = v0273;
    v0203 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0201)) < ((int32_t)(v0203))) { popv(6); return onevalue(v0273); }
    v0201 = stack[-1];
    v0203 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0201)) < ((int32_t)(v0203))) goto v0142;
    v0201 = v0273;
    v0203 = stack[-1];
    if (((int32_t)(v0201)) < ((int32_t)(v0203))) goto v0108;
    v0201 = v0273;
    v0203 = stack[-1];
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 - (int32_t)v0203 + TAG_FIXNUM);
    stack[-4] = v0203;
    v0203 = stack[-4];
    stack[0] = v0203;
    goto v0088;

v0088:
    v0203 = stack[0];
    v0203 = ((intptr_t)(v0203) < 0 ? lisp_true : nil);
    if (v0203 == nil) goto v0074;
    v0203 = (Lisp_Object)1; /* 0 */
    stack[0] = v0203;
    goto v0181;

v0181:
    v0203 = stack[-1];
    v0201 = (Lisp_Object)((int32_t)(v0203) - 0x10);
    v0203 = stack[0];
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 - (int32_t)v0203 + TAG_FIXNUM);
    v0203 = ((intptr_t)(v0203) < 0 ? lisp_true : nil);
    if (v0203 == nil) goto v0279;
    v0203 = (Lisp_Object)1; /* 0 */
    v0276 = v0203;
    goto v0280;

v0280:
    v0201 = stack[-4];
    v0203 = v0276;
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 - (int32_t)v0203 + TAG_FIXNUM);
    v0203 = ((intptr_t)(v0203) < 0 ? lisp_true : nil);
    if (!(v0203 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0275 = stack[-3];
    v0274 = v0276;
    v0273 = stack[-3];
    v0201 = stack[-1];
    v0203 = v0276;
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 + (int32_t)v0203 - TAG_FIXNUM);
    v0203 = *(Lisp_Object *)((char *)v0273 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    *(Lisp_Object *)((char *)v0275 + (CELL-TAG_VECTOR) + ((int32_t)v0274/(16/CELL))) = v0203;
    v0203 = v0276;
    v0203 = (Lisp_Object)((int32_t)(v0203) + 0x10);
    v0276 = v0203;
    goto v0280;

v0279:
    v0201 = stack[-3];
    v0203 = stack[0];
    v0201 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    v0203 = (Lisp_Object)1; /* 0 */
    if (v0201 == v0203) goto v0238;
    v0203 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-5];
    goto v0238;

v0238:
    v0203 = stack[0];
    v0203 = (Lisp_Object)((int32_t)(v0203) + 0x10);
    stack[0] = v0203;
    goto v0181;

v0074:
    v0273 = stack[-3];
    v0201 = stack[-1];
    v0203 = stack[0];
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 + (int32_t)v0203 - TAG_FIXNUM);
    v0273 = *(Lisp_Object *)((char *)v0273 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    v0201 = stack[-2];
    v0203 = stack[-1];
    v0203 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    v0203 = Lmodular_quotient(nil, v0273, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-5];
    v0278 = v0203;
    v0203 = (Lisp_Object)1; /* 0 */
    v0277 = v0203;
    goto v0282;

v0282:
    v0203 = stack[-1];
    v0201 = (Lisp_Object)((int32_t)(v0203) - 0x10);
    v0203 = v0277;
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 - (int32_t)v0203 + TAG_FIXNUM);
    v0203 = ((intptr_t)(v0203) < 0 ? lisp_true : nil);
    if (v0203 == nil) goto v0152;
    v0273 = stack[-3];
    v0201 = stack[-1];
    v0203 = stack[0];
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 + (int32_t)v0203 - TAG_FIXNUM);
    v0201 = v0278;
    *(Lisp_Object *)((char *)v0273 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL))) = v0201;
    v0203 = stack[0];
    v0203 = (Lisp_Object)((int32_t)(v0203) - 0x10);
    stack[0] = v0203;
    goto v0088;

v0152:
    v0276 = stack[-3];
    v0201 = stack[0];
    v0203 = v0277;
    v0275 = (Lisp_Object)(int32_t)((int32_t)v0201 + (int32_t)v0203 - TAG_FIXNUM);
    v0273 = stack[-3];
    v0201 = stack[0];
    v0203 = v0277;
    v0203 = (Lisp_Object)(int32_t)((int32_t)v0201 + (int32_t)v0203 - TAG_FIXNUM);
    v0274 = *(Lisp_Object *)((char *)v0273 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    v0273 = v0278;
    v0201 = stack[-2];
    v0203 = v0277;
    v0203 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL)));
    v0203 = Lmodular_times(nil, v0273, v0203);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v0274) - int_of_fixnum(v0203);
        if (w < 0) w += current_modulus;
        v0203 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0276 + (CELL-TAG_VECTOR) + ((int32_t)v0275/(16/CELL))) = v0203;
    v0203 = v0277;
    v0203 = (Lisp_Object)((int32_t)(v0203) + 0x10);
    v0277 = v0203;
    goto v0282;

v0108:
    v0203 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0203);
    }

v0142:
    v0203 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0203);
    }
/* error exit handlers */
v0281:
    popv(6);
    return nil;
}



/* Code for algmodep */

static Lisp_Object CC_algmodep(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0117;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algmodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0117 = v0070;
/* end of prologue */
    v0102 = v0117;
    if (!consp(v0102)) goto v0139;
    v0102 = v0117;
    v0102 = qcar(v0102);
    v0117 = elt(env, 1); /* (aeval aeval!*) */
    v0102 = Lmemq(nil, v0102, v0117);
    return onevalue(v0102);

v0139:
    v0102 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0102);
}



/* Code for sfchk */

static Lisp_Object CC_sfchk(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
/* end of prologue */
    v0008 = stack[0];
    fn = elt(env, 1); /* sfp */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    if (v0008 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0008 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v0008);
    }
/* error exit handlers */
v0002:
    popv(2);
    return nil;
}



/* Code for maxfrom1 */

static Lisp_Object MS_CDECL CC_maxfrom1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0116;
    Lisp_Object fn;
    Lisp_Object v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0070,v0050,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0050;
    stack[-2] = v0070;
/* end of prologue */

v0000:
    v0105 = stack[-2];
    if (v0105 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0116 = qcar(v0105);
    v0105 = stack[-1];
    fn = elt(env, 1); /* nth */
    v0116 = (*qfn2(fn))(qenv(fn), v0116, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    v0105 = stack[0];
    fn = elt(env, 2); /* max */
    v0105 = (*qfn2(fn))(qenv(fn), v0116, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[0] = v0105;
    v0105 = stack[-2];
    v0105 = qcdr(v0105);
    stack[-2] = v0105;
    goto v0000;
/* error exit handlers */
v0048:
    popv(4);
    return nil;
}



/* Code for replace!-next */

static Lisp_Object CC_replaceKnext(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0106, v0156, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace-next");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    stack[-2] = nil;
    goto v0000;

v0000:
    v0104 = stack[-1];
    if (v0104 == nil) goto v0015;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0138 = qcar(v0104);
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0156 = qcar(v0104);
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0106 = qcar(v0104);
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0106 = list4(v0138, v0156, v0106, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    v0104 = stack[-2];
    v0104 = cons(v0106, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    stack[-2] = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    goto v0000;

v0015:
    v0104 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0104);
    }
/* error exit handlers */
v0160:
    popv(4);
    return nil;
}



/* Code for mk!+equation */

static Lisp_Object CC_mkLequation(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0142, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+equation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0139 = v0050;
    v0142 = v0070;
/* end of prologue */
    v0101 = elt(env, 1); /* equal */
    return list3(v0101, v0142, v0139);
}



/* Code for iv_new */

static Lisp_Object CC_iv_new(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0123, v0129;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0123 = v0050;
    v0129 = v0070;
/* end of prologue */
    v0108 = v0129;
    if (v0108 == nil) goto v0139;
    v0108 = v0129;
    v0129 = v0108;
    goto v0165;

v0165:
    v0108 = v0123;
    if (v0108 == nil) goto v0092;
    v0108 = v0123;
    goto v0132;

v0132:
    v0108 = cons(v0129, v0108);
    errexit();
    return ncons(v0108);

v0092:
    v0108 = (Lisp_Object)1; /* 0 */
    goto v0132;

v0139:
    v0108 = (Lisp_Object)1; /* 0 */
    v0129 = v0108;
    goto v0165;
}



/* Code for csymbolrd */

static Lisp_Object MS_CDECL CC_csymbolrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0100, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "csymbolrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for csymbolrd");
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
    fn = elt(env, 2); /* fnrd */
    v0054 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    stack[0] = v0054;
    fn = elt(env, 3); /* stats_getargs */
    v0054 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    v0100 = v0054;
    v0054 = stack[0];
    v0107 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list2star(v0054, v0107, v0100);
/* error exit handlers */
v0127:
    popv(2);
    return nil;
}



/* Code for ps!:mkpow */

static Lisp_Object MS_CDECL CC_psTmkpow(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0085, v0112, v0133;
    Lisp_Object v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:mkpow");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:mkpow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0070,v0050,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    v0112 = v0050;
    v0133 = v0070;
/* end of prologue */
    v0085 = v0112;
    v0058 = (Lisp_Object)1; /* 0 */
    if (v0085 == v0058) goto v0000;
    v0085 = v0112;
    v0058 = (Lisp_Object)17; /* 1 */
    if (v0085 == v0058) goto v0055;
    v0058 = elt(env, 1); /* expt */
    v0085 = v0133;
    v0058 = list3(v0058, v0085, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-1];
    goto v0117;

v0117:
    v0085 = stack[0];
    if (v0085 == nil) goto v0120;
    v0112 = elt(env, 2); /* quotient */
    v0085 = (Lisp_Object)17; /* 1 */
    v0058 = list3(v0112, v0085, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    popv(2);
    return ncons(v0058);

v0120:
    popv(2);
    return ncons(v0058);

v0055:
    v0058 = v0133;
    goto v0117;

v0000:
    v0058 = (Lisp_Object)17; /* 1 */
    popv(2);
    return ncons(v0058);
/* error exit handlers */
v0155:
    popv(2);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0137, v0057;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findhr");
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
    stack[-1] = nil;
    goto v0008;

v0008:
    v0137 = qvalue(elt(env, 1)); /* headhisto */
    v0074 = (Lisp_Object)1; /* 0 */
    v0074 = (Lisp_Object)greaterp2(v0137, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    if (v0074 == nil) goto v0001;
    v0137 = qvalue(elt(env, 2)); /* codhisto */
    v0074 = qvalue(elt(env, 1)); /* headhisto */
    v0074 = *(Lisp_Object *)((char *)v0137 + (CELL-TAG_VECTOR) + ((int32_t)v0074/(16/CELL)));
    stack[-1] = v0074;
    if (!(v0074 == nil)) goto v0001;
    v0074 = qvalue(elt(env, 1)); /* headhisto */
    v0074 = sub1(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0074; /* headhisto */
    goto v0008;

v0001:
    v0074 = stack[-1];
    if (v0074 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0074 = stack[-1];
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0074; /* psi */
    v0074 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v0074; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v0137 = qvalue(elt(env, 7)); /* maxvar */
    v0074 = stack[-1];
    v0074 = plus2(v0137, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0057 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0074/(16/CELL)));
    v0137 = (Lisp_Object)1; /* 0 */
    v0074 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0137/(16/CELL))) = v0074;
    v0137 = stack[-1];
    v0074 = qvalue(elt(env, 8)); /* rcoccup */
    v0074 = cons(v0137, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0074; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0223:
    popv(3);
    return nil;
}



/* Code for dipnumcontent */

static Lisp_Object CC_dipnumcontent(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipnumcontent");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */

v0000:
    v0130 = stack[0];
    fn = elt(env, 1); /* bcone!? */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    if (!(v0130 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0130 = stack[-1];
    if (v0130 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    v0130 = qcdr(v0130);
    stack[-2] = v0130;
    v0105 = stack[0];
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    v0130 = qcar(v0130);
    fn = elt(env, 2); /* vbcgcd */
    v0130 = (*qfn2(fn))(qenv(fn), v0105, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    stack[0] = v0130;
    v0130 = stack[-2];
    stack[-1] = v0130;
    goto v0000;
/* error exit handlers */
v0047:
    popv(4);
    return nil;
}



/* Code for xexptpf */

static Lisp_Object CC_xexptpf(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xexptpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    stack[-2] = nil;
    goto v0031;

v0031:
    v0136 = stack[0];
    v0103 = (Lisp_Object)17; /* 1 */
    if (v0136 == v0103) goto v0132;
    v0136 = stack[-1];
    v0103 = stack[-2];
    v0103 = cons(v0136, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    stack[-2] = v0103;
    v0103 = stack[0];
    v0103 = sub1(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    stack[0] = v0103;
    goto v0031;

v0132:
    v0103 = stack[-1];
    v0136 = v0103;
    goto v0015;

v0015:
    v0103 = stack[-2];
    if (v0103 == nil) { popv(4); return onevalue(v0136); }
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    fn = elt(env, 1); /* wedgepf */
    v0103 = (*qfn2(fn))(qenv(fn), v0103, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0136 = v0103;
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0015;
/* error exit handlers */
v0138:
    popv(4);
    return nil;
}



/* Code for xreadlist */

static Lisp_Object MS_CDECL CC_xreadlist(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xreadlist");
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
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); /* scan */
    v0079 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    v0078 = elt(env, 1); /* !*rcbkt!* */
    if (!(v0079 == v0078)) goto v0165;
    fn = elt(env, 10); /* scan */
    v0078 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    v0078 = elt(env, 2); /* list */
    popv(5);
    return ncons(v0078);

v0165:
    v0078 = stack[-1];
    if (v0078 == nil) goto v0108;
    v0078 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    fn = elt(env, 12); /* nconc2 */
    v0078 = (*qfn2(fn))(qenv(fn), stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    stack[0] = v0078;
    goto v0100;

v0100:
    v0078 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-3] = v0078;
    v0079 = stack[-3];
    v0078 = elt(env, 5); /* !*semicol!* */
    if (v0079 == v0078) goto v0140;
    fn = elt(env, 10); /* scan */
    v0079 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    v0078 = elt(env, 1); /* !*rcbkt!* */
    if (v0079 == v0078) goto v0111;
    v0078 = qvalue(elt(env, 7)); /* nil */
    goto v0155;

v0155:
    if (v0078 == nil) goto v0284;
    v0079 = elt(env, 9); /* "Syntax error: invalid comma in list" */
    v0078 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v0078 = (*qfn2(fn))(qenv(fn), v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    goto v0284;

v0284:
    v0079 = stack[-3];
    v0078 = elt(env, 1); /* !*rcbkt!* */
    if (v0079 == v0078) goto v0271;
    v0078 = stack[-2];
    if (!(v0078 == nil)) goto v0165;
    v0078 = stack[-3];
    stack[-2] = v0078;
    goto v0165;

v0271:
    v0079 = elt(env, 2); /* list */
    v0078 = stack[-1];
    popv(5);
    return cons(v0079, v0078);

v0111:
    v0079 = stack[-3];
    v0078 = elt(env, 8); /* !*comma!* */
    v0078 = (v0079 == v0078 ? lisp_true : nil);
    goto v0155;

v0140:
    v0079 = elt(env, 6); /* "Syntax error: semicolon in list" */
    v0078 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v0078 = (*qfn2(fn))(qenv(fn), v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    goto v0284;

v0108:
    stack[0] = stack[-1];
    v0078 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    fn = elt(env, 14); /* aconc */
    v0078 = (*qfn2(fn))(qenv(fn), stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-4];
    stack[0] = v0078;
    stack[-1] = v0078;
    goto v0100;
/* error exit handlers */
v0037:
    popv(5);
    return nil;
}



/* Code for gfquotient */

static Lisp_Object CC_gfquotient(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0108, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfquotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0050;
    v0123 = v0070;
/* end of prologue */
    v0126 = v0123;
    v0126 = qcar(v0126);
    if (!consp(v0126)) goto v0030;
    v0126 = v0123;
    {
        fn = elt(env, 1); /* gbfquot */
        return (*qfn2(fn))(qenv(fn), v0126, v0108);
    }

v0030:
    v0126 = v0123;
    {
        fn = elt(env, 2); /* gffquot */
        return (*qfn2(fn))(qenv(fn), v0126, v0108);
    }
}



/* Code for intrdsortin */

static Lisp_Object CC_intrdsortin(Lisp_Object env,
                         Lisp_Object v0070, Lisp_Object v0050)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intrdsortin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0070,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0070;
/* end of prologue */
    stack[-2] = nil;
    goto v0000;

v0000:
    v0085 = stack[0];
    if (v0085 == nil) goto v0008;
    v0085 = stack[-1];
    v0112 = qcar(v0085);
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    fn = elt(env, 1); /* !:difference */
    v0085 = (*qfn2(fn))(qenv(fn), v0112, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    fn = elt(env, 2); /* !:minusp */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    if (v0085 == nil) goto v0121;
    v0085 = stack[0];
    v0112 = qcar(v0085);
    v0085 = stack[-2];
    v0085 = cons(v0112, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    stack[-2] = v0085;
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[0] = v0085;
    goto v0000;

v0121:
    v0112 = stack[-1];
    v0085 = stack[0];
    v0085 = cons(v0112, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    {
        Lisp_Object v0074 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0074, v0085);
    }

v0008:
    stack[0] = stack[-2];
    v0085 = stack[-1];
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    {
        Lisp_Object v0137 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0137, v0085);
    }
/* error exit handlers */
v0180:
    popv(4);
    return nil;
}



/* Code for toolongassignp */

static Lisp_Object CC_toolongassignp(Lisp_Object env,
                         Lisp_Object v0070)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0165 = v0070;
/* end of prologue */
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    {
        fn = elt(env, 1); /* toolongexpp */
        return (*qfn1(fn))(qenv(fn), v0165);
    }
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0091, v0089;
    Lisp_Object fn;
    Lisp_Object v0049, v0050, v0070;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
    va_start(aa, nargs);
    v0070 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    v0049 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0050,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0070,v0050,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0049;
    stack[-1] = v0050;
    stack[-2] = v0070;
/* end of prologue */
    stack[-3] = nil;
    goto v0165;

v0165:
    v0093 = stack[-1];
    if (v0093 == nil) goto v0030;
    v0091 = stack[-2];
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    fn = elt(env, 1); /* color!-roads */
    v0089 = (*qfn2(fn))(qenv(fn), v0091, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0091 = stack[0];
    v0093 = stack[-3];
    v0093 = acons(v0089, v0091, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    stack[-3] = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    v0093 = stack[0];
    v0093 = add1(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    stack[0] = v0093;
    goto v0165;

v0030:
    v0093 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
/* error exit handlers */
v0045:
    popv(5);
    return nil;
}



setup_type const u32_setup[] =
{
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"simpsqrt2",               CC_simpsqrt2,   too_many_1,    wrong_no_1},
    {"depend-sq",               too_few_2,      CC_dependKsq,  wrong_no_2},
    {"ofsf_simplequal",         too_few_2,      CC_ofsf_simplequal,wrong_no_2},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"lengthn",                 CC_lengthn,     too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"mk_binding",              too_few_2,      CC_mk_binding, wrong_no_2},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"extract_vars",            CC_extract_vars,too_many_1,    wrong_no_1},
    {"list2vect*",              too_few_2,      CC_list2vectH, wrong_no_2},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"depend-p",                too_few_2,      CC_dependKp,   wrong_no_2},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"ofsf_negateat",           CC_ofsf_negateat,too_many_1,   wrong_no_1},
    {"cnml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnml},
    {"sc_mkmatrix",             too_few_2,      CC_sc_mkmatrix,wrong_no_2},
    {":log10",                  CC_Tlog10,      too_many_1,    wrong_no_1},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"verify_tens_ids",         CC_verify_tens_ids,too_many_1, wrong_no_1},
    {"get_char_group",          CC_get_char_group,too_many_1,  wrong_no_1},
    {"rl_bnfsimpl",             too_few_2,      CC_rl_bnfsimpl,wrong_no_2},
    {"ratpoly_subrat1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_subrat1},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"matrixir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixir},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"remzzzz",                 too_few_2,      CC_remzzzz,    wrong_no_2},
    {"multsqpf",                too_few_2,      CC_multsqpf,   wrong_no_2},
    {":log2",                   CC_Tlog2,       too_many_1,    wrong_no_1},
    {"subfindices",             too_few_2,      CC_subfindices,wrong_no_2},
    {"compactf1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf1},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"makecoeffpairs",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs},
    {"mri_2ofsfat",             CC_mri_2ofsfat, too_many_1,    wrong_no_1},
    {"quotfx1",                 too_few_2,      CC_quotfx1,    wrong_no_2},
    {"numir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_numir},
    {"mulpower",                too_few_2,      CC_mulpower,   wrong_no_2},
    {"sfpf",                    CC_sfpf,        too_many_1,    wrong_no_1},
    {"gbfdiff",                 too_few_2,      CC_gbfdiff,    wrong_no_2},
    {"listquotient",            too_few_2,      CC_listquotient,wrong_no_2},
    {"boolvalue*",              CC_boolvalueH,  too_many_1,    wrong_no_1},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"quotfail-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfailKinKvector},
    {"algmodep",                CC_algmodep,    too_many_1,    wrong_no_1},
    {"sfchk",                   CC_sfchk,       too_many_1,    wrong_no_1},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"mk+equation",             too_few_2,      CC_mkLequation,wrong_no_2},
    {"iv_new",                  too_few_2,      CC_iv_new,     wrong_no_2},
    {"csymbolrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_csymbolrd},
    {"ps:mkpow",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTmkpow},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"dipnumcontent",           too_few_2,      CC_dipnumcontent,wrong_no_2},
    {"xexptpf",                 too_few_2,      CC_xexptpf,    wrong_no_2},
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"gfquotient",              too_few_2,      CC_gfquotient, wrong_no_2},
    {"intrdsortin",             too_few_2,      CC_intrdsortin,wrong_no_2},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {NULL, (one_args *)"u32", (two_args *)"11280 2316791 2780798", 0}
};

/* end of generated code */
