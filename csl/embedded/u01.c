
/* $destdir\u01.c        Machine generated C code */

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


/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num-exponents");
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

v0007:
    v0006 = stack[0];
    if (!consp(v0006)) goto v0001;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = (consp(v0006) ? nil : lisp_true);
    goto v0008;

v0008:
    if (v0006 == nil) goto v0009;
    v0006 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0006); }

v0009:
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0006 = integerp(v0006);
    if (v0006 == nil) goto v0010;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0006 = CC_numKexponents(env, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    if (v0006 == nil) goto v0012;
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    stack[0] = v0006;
    goto v0007;

v0012:
    v0006 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0006); }

v0010:
    v0006 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0006); }

v0001:
    v0006 = qvalue(elt(env, 1)); /* t */
    goto v0008;
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for arraychk */

static Lisp_Object CC_arraychk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arraychk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    if (v0004 == nil) goto v0013;
    v0004 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0004);

v0013:
    v0004 = elt(env, 1); /* array */
    return onevalue(v0004);
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypeor");
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

v0007:
    v0014 = stack[0];
    if (v0014 == nil) goto v0013;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    fn = elt(env, 2); /* getrtype */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (!(v0014 == nil)) { popv(2); return onevalue(v0014); }
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0007;

v0013:
    v0014 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0014); }
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2q");
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
    v0023 = stack[0];
    if (is_number(v0023)) goto v0013;
    v0023 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    if (v0023 == nil) goto v0006;
    v0024 = qvalue(elt(env, 1)); /* nil */
    v0023 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0024, v0023);

v0006:
    v0024 = stack[0];
    v0023 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0024, v0023);

v0013:
    v0023 = stack[0];
    v0023 = (Lisp_Object)zerop(v0023);
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-1];
    if (v0023 == nil) goto v0026;
    v0024 = qvalue(elt(env, 1)); /* nil */
    v0023 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0024, v0023);

v0026:
    v0024 = stack[0];
    v0023 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0024, v0023);
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for readch1 */

static Lisp_Object MS_CDECL CC_readch1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readch1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readch1");
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
    v0032 = qvalue(elt(env, 1)); /* peekchar!* */
    if (v0032 == nil) goto v0034;
    v0032 = qvalue(elt(env, 1)); /* peekchar!* */
    v0032 = qcar(v0032);
    stack[0] = v0032;
    v0032 = qvalue(elt(env, 1)); /* peekchar!* */
    v0032 = qcdr(v0032);
    qvalue(elt(env, 1)) = v0032; /* peekchar!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0034:
    v0032 = qvalue(elt(env, 2)); /* !*int */
    if (v0032 == nil) goto v0035;
    v0032 = qvalue(elt(env, 3)); /* ifl!* */
    if (!(v0032 == nil)) goto v0035;
    v0032 = qvalue(elt(env, 7)); /* crbuf1!* */
    if (v0032 == nil) goto v0036;
    v0032 = qvalue(elt(env, 7)); /* crbuf1!* */
    v0032 = qcar(v0032);
    stack[0] = v0032;
    v0032 = qvalue(elt(env, 7)); /* crbuf1!* */
    v0032 = qcdr(v0032);
    qvalue(elt(env, 7)) = v0032; /* crbuf1!* */
    goto v0023;

v0023:
    v0033 = stack[0];
    v0032 = qvalue(elt(env, 8)); /* crbuf!* */
    v0032 = cons(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0032; /* crbuf!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0036:
    v0032 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    stack[0] = v0032;
    goto v0023;

v0035:
    v0032 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    stack[0] = v0032;
    v0033 = stack[0];
    v0032 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (!(v0033 == v0032)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0032 = qvalue(elt(env, 5)); /* curline!* */
    v0032 = add1(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0032; /* curline!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0037:
    popv(2);
    return nil;
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0040, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0040 = v0029;
    v0041 = v0000;
/* end of prologue */
    v0039 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = v0039; /* !*exp */
    v0039 = v0041;
    fn = elt(env, 3); /* quotf1 */
    v0039 = (*qfn2(fn))(qenv(fn), v0039, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v0039); }
/* error exit handlers */
v0042:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for monomcompare */

static Lisp_Object CC_monomcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0045, v0025, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0025 = v0029;
    v0046 = v0000;
/* end of prologue */
    v0045 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v0024 = elt(env, 2); /* lex */
    if (v0045 == v0024) goto v0042;
    v0045 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v0024 = elt(env, 4); /* deglex */
    if (v0045 == v0024) goto v0047;
    v0024 = v0046;
    v0045 = v0025;
    {
        fn = elt(env, 5); /* monomcomparedegrevlex */
        return (*qfn2(fn))(qenv(fn), v0024, v0045);
    }

v0047:
    v0024 = v0046;
    v0045 = v0025;
    {
        fn = elt(env, 6); /* monomcomparedeglex */
        return (*qfn2(fn))(qenv(fn), v0024, v0045);
    }

v0042:
    v0024 = v0046;
    v0045 = v0025;
    {
        fn = elt(env, 7); /* monomcomparelex */
        return (*qfn2(fn))(qenv(fn), v0024, v0045);
    }
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smember");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */

v0008:
    v0049 = stack[-1];
    v0018 = stack[0];
    if (equal(v0049, v0018)) goto v0034;
    v0018 = stack[0];
    if (!consp(v0018)) goto v0041;
    v0049 = stack[-1];
    v0018 = stack[0];
    v0018 = qcar(v0018);
    v0018 = CC_smember(env, v0049, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    if (!(v0018 == nil)) { popv(3); return onevalue(v0018); }
    v0049 = stack[-1];
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    stack[-1] = v0049;
    stack[0] = v0018;
    goto v0008;

v0041:
    v0018 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0018); }

v0034:
    v0018 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0018); }
/* error exit handlers */
v0006:
    popv(3);
    return nil;
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0050;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0050 = elt(env, 1); /* list */
    return onevalue(v0050);
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    v0031 = v0030;
    if (!consp(v0031)) goto v0001;
    v0031 = v0030;
    v0031 = qcar(v0031);
    v0031 = (consp(v0031) ? nil : lisp_true);
    goto v0008;

v0008:
    if (v0031 == nil) goto v0022;
    v0031 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0031);

v0022:
    v0031 = v0030;
    v0031 = qcar(v0031);
    v0031 = qcar(v0031);
    v0031 = qcar(v0031);
    v0030 = qvalue(elt(env, 2)); /* wuvarlist!* */
    v0031 = Lmemq(nil, v0031, v0030);
    v0031 = (v0031 == nil ? lisp_true : nil);
    return onevalue(v0031);

v0001:
    v0031 = qvalue(elt(env, 1)); /* t */
    goto v0008;
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkcopy");
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
    stack[-1] = nil;
    goto v0034;

v0034:
    v0030 = stack[0];
    if (!consp(v0030)) goto v0038;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0012 = CC_mkcopy(env, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0030 = stack[-1];
    v0030 = cons(v0012, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0034;

v0038:
    v0012 = stack[-1];
    v0030 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0012, v0030);
    }
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0025, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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

v0013:
    v0045 = stack[0];
    if (!consp(v0045)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0045 = stack[0];
    v0025 = qcar(v0045);
    v0045 = elt(env, 1); /* !*sq */
    if (v0025 == v0045) goto v0004;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    fn = elt(env, 2); /* remove!-free!-vars */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = CC_removeKfreeKvarsKl(env, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0045 = cons(stack[-1], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    v0046 = v0045;
    v0025 = v0046;
    v0045 = stack[0];
    if (equal(v0025, v0045)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else { popv(3); return onevalue(v0046); }

v0004:
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = qcar(v0045);
    fn = elt(env, 3); /* prepsq!* */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[0] = v0045;
    goto v0013;
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk*");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0060 = stack[-1];
    v0059 = stack[0];
    fn = elt(env, 3); /* mchk */
    v0059 = (*qfn2(fn))(qenv(fn), v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    v0060 = v0059;
    if (!(v0059 == nil)) { popv(3); return onevalue(v0060); }
    v0059 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v0059 == nil)) goto v0014;
    v0059 = stack[-1];
    if (!consp(v0059)) goto v0054;
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    v0059 = (consp(v0059) ? nil : lisp_true);
    v0059 = (v0059 == nil ? lisp_true : nil);
    goto v0021;

v0021:
    if (v0059 == nil) goto v0016;
    v0059 = stack[0];
    if (!consp(v0059)) goto v0036;
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0059 = (consp(v0059) ? nil : lisp_true);
    v0059 = (v0059 == nil ? lisp_true : nil);
    goto v0062;

v0062:
    if (v0059 == nil) goto v0014;
    v0059 = stack[-1];
    fn = elt(env, 4); /* prepf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    v0059 = stack[0];
    fn = elt(env, 4); /* prepf */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    {
        Lisp_Object v0063 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* mchk */
        return (*qfn2(fn))(qenv(fn), v0063, v0059);
    }

v0014:
    v0059 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0059); }

v0036:
    v0059 = qvalue(elt(env, 2)); /* nil */
    goto v0062;

v0016:
    v0059 = qvalue(elt(env, 2)); /* nil */
    goto v0062;

v0054:
    v0059 = qvalue(elt(env, 2)); /* nil */
    goto v0021;
/* error exit handlers */
v0061:
    popv(3);
    return nil;
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf");
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
    v0004 = v0000;
/* end of prologue */
    v0038 = v0004;
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a */
    v0004 = (*qfn2(fn))(qenv(fn), v0038, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus1 */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0039:
    popv(1);
    return nil;
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    v0044 = v0029;
    v0026 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v0044 = (*qfn2(fn))(qenv(fn), v0026, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    v0026 = qcar(v0044);
    v0044 = stack[0];
    fn = elt(env, 1); /* pnth */
    v0044 = (*qfn2(fn))(qenv(fn), v0026, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0044 = qcar(v0044);
    { popv(2); return onevalue(v0044); }
/* error exit handlers */
v0064:
    popv(2);
    return nil;
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0032, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusf");
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
    v0032 = v0000;
/* end of prologue */

v0013:
    v0057 = v0032;
    if (v0057 == nil) goto v0008;
    v0057 = v0032;
    if (!consp(v0057)) goto v0041;
    v0057 = v0032;
    v0057 = qcar(v0057);
    v0057 = (consp(v0057) ? nil : lisp_true);
    goto v0040;

v0040:
    if (v0057 == nil) goto v0045;
    v0057 = v0032;
    if (!consp(v0057)) goto v0031;
    v0057 = v0032;
    v0033 = qcar(v0057);
    v0057 = elt(env, 3); /* minusp */
    v0057 = get(v0033, v0057);
        return Lapply1(nil, v0057, v0032);

v0031:
    v0057 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0032, v0057);

v0045:
    v0057 = v0032;
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    v0032 = v0057;
    goto v0013;

v0041:
    v0057 = qvalue(elt(env, 2)); /* t */
    goto v0040;

v0008:
    v0057 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0057);
}



/* Code for qqe_rqopp */

static Lisp_Object CC_qqe_rqopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rqopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = elt(env, 1); /* (qequal qneq) */
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



/* Code for kernels1 */

static Lisp_Object CC_kernels1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0059, v0060, v0068;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernels1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0060 = v0029;
    v0067 = v0000;
/* end of prologue */

v0007:
    v0059 = v0067;
    if (!consp(v0059)) goto v0002;
    v0059 = v0067;
    v0059 = qcar(v0059);
    v0059 = (consp(v0059) ? nil : lisp_true);
    goto v0001;

v0001:
    if (!(v0059 == nil)) { popv(4); return onevalue(v0060); }
    v0059 = v0067;
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0068 = v0059;
    v0059 = v0067;
    v0059 = qcar(v0059);
    stack[-2] = qcdr(v0059);
    stack[-1] = qcdr(v0067);
    v0059 = v0068;
    v0067 = v0060;
    v0067 = Lmemq(nil, v0059, v0067);
    if (v0067 == nil) goto v0028;
    v0067 = v0060;
    goto v0048;

v0048:
    v0059 = CC_kernels1(env, stack[-1], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    v0067 = stack[-2];
    v0060 = v0059;
    goto v0007;

v0028:
    stack[0] = v0060;
    v0067 = v0068;
    v0067 = ncons(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    v0067 = Lappend(nil, stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    goto v0048;

v0002:
    v0059 = qvalue(elt(env, 1)); /* t */
    goto v0001;
/* error exit handlers */
v0069:
    popv(4);
    return nil;
}



/* Code for ibalp_clmember */

static Lisp_Object CC_ibalp_clmember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */

v0007:
    v0031 = stack[0];
    if (v0031 == nil) goto v0034;
    v0030 = stack[-1];
    v0031 = stack[0];
    v0031 = qcar(v0031);
    fn = elt(env, 2); /* ibalp_cequal */
    v0031 = (*qfn2(fn))(qenv(fn), v0030, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0031 == nil)) { popv(3); return onevalue(v0031); }
    v0030 = stack[-1];
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    stack[-1] = v0030;
    stack[0] = v0031;
    goto v0007;

v0034:
    v0031 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0031); }
/* error exit handlers */
v0056:
    popv(3);
    return nil;
}



/* Code for adjoin!-term */

static Lisp_Object MS_CDECL CC_adjoinKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0026, v0062, v0064;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adjoin-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjoin-term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0053;
    v0026 = v0029;
    v0062 = v0000;
/* end of prologue */
    v0064 = v0026;
    if (v0064 == nil) return onevalue(v0044);
    return acons(v0062, v0026, v0044);
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delall");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */

v0034:
    v0071 = stack[0];
    if (v0071 == nil) goto v0001;
    v0065 = stack[-1];
    v0071 = stack[0];
    v0071 = qcar(v0071);
    if (equal(v0065, v0071)) goto v0038;
    v0071 = stack[0];
    v0071 = qcar(v0071);
    stack[-2] = ncons(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0065 = stack[-1];
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = CC_delall(env, v0065, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        Lisp_Object v0055 = stack[-2];
        popv(4);
        return Lappend(nil, v0055, v0071);
    }

v0038:
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    stack[0] = v0071;
    goto v0034;

v0001:
    v0071 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0071); }
/* error exit handlers */
v0036:
    popv(4);
    return nil;
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfp1");
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

v0007:
    v0006 = stack[0];
    if (!consp(v0006)) goto v0001;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = (consp(v0006) ? nil : lisp_true);
    goto v0008;

v0008:
    if (v0006 == nil) goto v0013;
    v0006 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0006); }

v0013:
    v0006 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v0006 == nil) goto v0010;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcar(v0006);
    v0006 = qcar(v0006);
    fn = elt(env, 4); /* noncomp1 */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    goto v0015;

v0015:
    if (!(v0006 == nil)) { popv(2); return onevalue(v0006); }
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0006 = CC_noncomfp1(env, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    if (!(v0006 == nil)) { popv(2); return onevalue(v0006); }
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    stack[0] = v0006;
    goto v0007;

v0010:
    v0006 = qvalue(elt(env, 3)); /* nil */
    goto v0015;

v0001:
    v0006 = qvalue(elt(env, 1)); /* t */
    goto v0008;
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0006, v0072, v0011, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0011 = v0029;
    v0036 = v0000;
/* end of prologue */
    v0065 = qvalue(elt(env, 1)); /* kord!* */
    v0072 = v0065;
    goto v0005;

v0005:
    v0065 = v0072;
    if (v0065 == nil) goto v0040;
    v0006 = v0036;
    v0065 = v0072;
    v0065 = qcar(v0065);
    if (v0006 == v0065) goto v0015;
    v0006 = v0011;
    v0065 = v0072;
    v0065 = qcar(v0065);
    if (v0006 == v0065) goto v0031;
    v0065 = v0072;
    v0065 = qcdr(v0065);
    v0072 = v0065;
    goto v0005;

v0031:
    v0065 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0065);

v0015:
    v0065 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0065);

v0040:
    v0065 = v0036;
    v0006 = v0011;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0065, v0006);
    }
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0066, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:getv");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0058 = v0000;
/* end of prologue */
    v0066 = v0058;
    v0037 = elt(env, 1); /* !:ps!: */
    if (!consp(v0066)) goto v0065;
    v0066 = qcar(v0066);
    if (!(v0066 == v0037)) goto v0065;
    v0037 = v0058;
    v0037 = qcdr(v0037);
    if (symbolp(v0037)) goto v0015;
    v0037 = v0058;
    v0066 = qcdr(v0037);
    v0037 = stack[0];
    v0037 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0037/(16/CELL)));
    { popv(2); return onevalue(v0037); }

v0015:
    v0037 = v0058;
    v0037 = qcdr(v0037);
    fn = elt(env, 5); /* eval */
    v0066 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0037 = stack[0];
    v0037 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0037/(16/CELL)));
    { popv(2); return onevalue(v0037); }

v0065:
    v0037 = elt(env, 2); /* "PS:GETV: not a ps" */
    v0066 = v0058;
    v0037 = list2(v0037, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-1];
    v0066 = v0037;
    v0037 = v0066;
    qvalue(elt(env, 3)) = v0037; /* errmsg!* */
    v0037 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0037 == nil)) goto v0046;
    v0037 = v0066;
    fn = elt(env, 6); /* lprie */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-1];
    goto v0046;

v0046:
    v0037 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0037 = nil;
    { popv(2); return onevalue(v0037); }
/* error exit handlers */
v0059:
    popv(2);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */

v0007:
    v0049 = stack[-1];
    if (v0049 == nil) goto v0034;
    v0049 = stack[-1];
    if (!consp(v0049)) goto v0039;
    v0049 = stack[-1];
    v0071 = qcar(v0049);
    v0049 = stack[0];
    fn = elt(env, 2); /* depends */
    v0049 = (*qfn2(fn))(qenv(fn), v0071, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    if (!(v0049 == nil)) { popv(3); return onevalue(v0049); }
    v0049 = stack[-1];
    v0071 = qcdr(v0049);
    v0049 = stack[0];
    stack[-1] = v0071;
    stack[0] = v0049;
    goto v0007;

v0039:
    v0071 = stack[-1];
    v0049 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* depends */
        return (*qfn2(fn))(qenv(fn), v0071, v0049);
    }

v0034:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0049); }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0071, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0049 = v0029;
    v0071 = v0000;
/* end of prologue */
    v0065 = v0071;
    v0065 = Lconsp(nil, v0065);
    env = stack[0];
    if (v0065 == nil) goto v0005;
    v0065 = v0049;
    v0065 = Lconsp(nil, v0065);
    env = stack[0];
    if (v0065 == nil) goto v0062;
    v0071 = qcdr(v0071);
    v0049 = qcdr(v0049);
        popv(1);
        return Llessp(nil, v0071, v0049);

v0062:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0049); }

v0005:
    v0065 = v0049;
    v0065 = Lconsp(nil, v0065);
    env = stack[0];
    if (v0065 == nil) goto v0048;
    v0049 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0049); }

v0048:
        popv(1);
        return Llessp(nil, v0071, v0049);
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero2nil");
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
    v0038 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    if (v0038 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0038 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0038); }
/* error exit handlers */
v0040:
    popv(2);
    return nil;
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binding");
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
    v0009 = v0000;
/* end of prologue */
    v0014 = v0009;
    v0009 = elt(env, 0); /* binding */
    v0009 = get(v0014, v0009);
    v0014 = v0009;
    v0009 = v0014;
    if (v0009 == nil) goto v0040;
    v0009 = v0014;
    v0009 = qcar(v0009);
    return onevalue(v0009);

v0040:
    v0009 = nil;
    return onevalue(v0009);
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0009 = v0029;
    v0014 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
    v0009 = list2(v0014, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    {
        Lisp_Object v0010 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0010, v0009);
    }
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0019, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0019 = v0029;
    stack[0] = v0000;
/* end of prologue */

v0034:
    v0043 = stack[0];
    if (v0043 == nil) goto v0001;
    v0018 = v0019;
    v0043 = (Lisp_Object)17; /* 1 */
    if (v0018 == v0043) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    stack[0] = v0043;
    v0043 = v0019;
    v0043 = sub1(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    v0019 = v0043;
    goto v0034;

v0001:
    v0043 = elt(env, 1); /* "Index out of range" */
    v0019 = v0043;
    v0043 = v0019;
    qvalue(elt(env, 2)) = v0043; /* errmsg!* */
    v0043 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0043 == nil)) goto v0042;
    v0043 = v0019;
    fn = elt(env, 4); /* lprie */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    goto v0042;

v0042:
    v0043 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0043 = nil;
    { popv(2); return onevalue(v0043); }
/* error exit handlers */
v0071:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0081, v0082, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */

v0007:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0003;
    v0080 = stack[-1];
    v0080 = (v0080 == nil ? lisp_true : nil);
    goto v0002;

v0002:
    if (!(v0080 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    stack[-3] = v0080;
    v0081 = stack[-3];
    v0080 = (Lisp_Object)1; /* 0 */
    v0080 = Leqn(nil, v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0016;
    v0080 = stack[-2];
    v0082 = qcdr(v0080);
    v0080 = stack[-1];
    v0081 = qcdr(v0080);
    v0080 = stack[0];
    stack[-2] = v0082;
    stack[-1] = v0081;
    stack[0] = v0080;
    goto v0007;

v0016:
    v0081 = stack[-3];
    v0080 = (Lisp_Object)17; /* 1 */
    v0080 = Leqn(nil, v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0085;
    v0080 = stack[-2];
    v0083 = qcdr(v0080);
    v0080 = stack[-1];
    v0082 = qcdr(v0080);
    v0081 = stack[0];
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = (Lisp_Object)(int32_t)((int32_t)v0081 + (int32_t)v0080 - TAG_FIXNUM);
    stack[-2] = v0083;
    stack[-1] = v0082;
    stack[0] = v0080;
    goto v0007;

v0085:
    v0083 = stack[-2];
    v0082 = stack[-3];
    v0081 = stack[-1];
    v0080 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v0083, v0082, v0081, v0080);
    }

v0003:
    v0080 = qvalue(elt(env, 1)); /* t */
    goto v0002;
/* error exit handlers */
v0084:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0005 = qcar(v0005);
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



/* Code for add_prin_char */

static Lisp_Object CC_add_prin_char(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0087, v0061;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0068 = qvalue(elt(env, 1)); /* !*nat */
    if (v0068 == nil) goto v0034;
    v0061 = qvalue(elt(env, 3)); /* posn!* */
    v0087 = stack[0];
    v0068 = qvalue(elt(env, 4)); /* ycoord!* */
    v0061 = acons(v0061, v0087, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0087 = stack[-1];
    v0068 = qvalue(elt(env, 5)); /* pline!* */
    v0068 = acons(v0061, v0087, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0068; /* pline!* */
    v0068 = stack[0];
    qvalue(elt(env, 3)) = v0068; /* posn!* */
    { popv(3); return onevalue(v0068); }

v0034:
    v0068 = stack[-1];
    v0068 = Lstringp(nil, v0068);
    env = stack[-2];
    if (!(v0068 == nil)) goto v0003;
    v0087 = stack[-1];
    v0068 = elt(env, 2); /* switch!* */
    v0068 = get(v0087, v0068);
    env = stack[-2];
    if (!(v0068 == nil)) goto v0003;
    v0068 = stack[-1];
    v0068 = Ldigitp(nil, v0068);
    env = stack[-2];
    if (!(v0068 == nil)) goto v0003;
    v0068 = stack[-1];
    v0068 = Lexplodec(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0087 = qcar(v0068);
    v0068 = elt(env, 2); /* switch!* */
    v0068 = get(v0087, v0068);
    if (!(v0068 == nil)) goto v0003;
    v0068 = stack[-1];
        popv(3);
        return Lprin(nil, v0068);

v0003:
    v0068 = stack[-1];
        popv(3);
        return Lprinc(nil, v0068);
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for int!-equiv!-chk */

static Lisp_Object CC_intKequivKchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096, v0097;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v0095 = qvalue(elt(env, 1)); /* !*noequiv */
    if (!(v0095 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0095 = stack[0];
    if (!consp(v0095)) goto v0010;
    v0095 = stack[0];
    v0096 = qcar(v0095);
    v0095 = elt(env, 3); /* zerop */
    v0096 = get(v0096, v0095);
    env = stack[-1];
    v0095 = stack[0];
    v0095 = Lapply1(nil, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    if (v0095 == nil) goto v0032;
    v0095 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0095); }

v0032:
    v0095 = stack[0];
    v0096 = qcar(v0095);
    v0095 = elt(env, 4); /* onep */
    v0096 = get(v0096, v0095);
    env = stack[-1];
    v0095 = stack[0];
    v0095 = Lapply1(nil, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    if (v0095 == nil) goto v0088;
    v0095 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0095); }

v0088:
    v0095 = stack[0];
    v0096 = qcar(v0095);
    v0095 = elt(env, 5); /* intequivfn */
    v0095 = get(v0096, v0095);
    env = stack[-1];
    v0097 = v0095;
    if (v0095 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0096 = v0097;
    v0095 = stack[0];
    v0095 = Lapply1(nil, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    v0097 = v0095;
    if (v0095 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0096 = v0097;
    v0095 = (Lisp_Object)1; /* 0 */
    if (!(v0096 == v0095)) { popv(2); return onevalue(v0097); }
    v0095 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0095); }

v0010:
    v0096 = stack[0];
    v0095 = (Lisp_Object)1; /* 0 */
    if (!(v0096 == v0095)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0095 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0095); }
/* error exit handlers */
v0098:
    popv(2);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0027;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp");
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
    v0027 = v0000;
/* end of prologue */
    v0046 = v0027;
    if (!consp(v0046)) goto v0013;
    v0046 = v0027;
    v0046 = qcar(v0046);
    if (symbolp(v0046)) goto v0072;
    v0046 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0046); }

v0072:
    v0046 = v0027;
    v0027 = qcar(v0046);
    v0046 = elt(env, 2); /* rtype */
    v0046 = get(v0027, v0046);
    env = stack[0];
    v0027 = elt(env, 3); /* physop */
    v0046 = (v0046 == v0027 ? lisp_true : nil);
    { popv(1); return onevalue(v0046); }

v0013:
    v0046 = v0027;
    if (symbolp(v0046)) goto v0044;
    v0046 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0046); }

v0044:
    v0046 = elt(env, 2); /* rtype */
    v0046 = get(v0027, v0046);
    env = stack[0];
    v0027 = elt(env, 3); /* physop */
    v0046 = (v0046 == v0027 ? lisp_true : nil);
    { popv(1); return onevalue(v0046); }
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0029;
    v0039 = v0000;
/* end of prologue */
    v0039 = qcar(v0039);
    v0038 = Lassoc(nil, v0039, v0038);
    return onevalue(v0038);
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termsf");
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
    v0011 = (Lisp_Object)1; /* 0 */
    v0036 = v0011;
    goto v0001;

v0001:
    v0011 = stack[0];
    if (!consp(v0011)) goto v0041;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = (consp(v0011) ? nil : lisp_true);
    goto v0040;

v0040:
    if (v0011 == nil) goto v0064;
    v0011 = stack[0];
    if (v0011 == nil) { popv(3); return onevalue(v0036); }
    v0011 = v0036;
    popv(3);
    return add1(v0011);

v0064:
    stack[-1] = v0036;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = qcdr(v0011);
    v0011 = CC_termsf(env, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0011 = plus2(stack[-1], v0011);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0036 = v0011;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0001;

v0041:
    v0011 = qvalue(elt(env, 1)); /* t */
    goto v0040;
/* error exit handlers */
v0016:
    popv(3);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkspm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0027 = stack[0];
    v0046 = (Lisp_Object)1; /* 0 */
    if (v0027 == v0046) goto v0034;
    v0046 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0046 == nil) goto v0015;
    v0027 = stack[-1];
    v0046 = qvalue(elt(env, 2)); /* asymplis!* */
    v0046 = Latsoc(nil, v0027, v0046);
    v0027 = v0046;
    if (v0046 == nil) goto v0015;
    v0046 = v0027;
    v0027 = qcdr(v0046);
    v0046 = stack[0];
    v0046 = (Lisp_Object)lesseq2(v0027, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0046 = v0046 ? lisp_true : nil;
    env = stack[-2];
    if (v0046 == nil) goto v0015;
    v0046 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0046); }

v0015:
    v0046 = stack[-1];
    fn = elt(env, 4); /* sub2chk */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0027 = stack[-1];
    v0046 = stack[0];
    popv(3);
    return cons(v0027, v0046);

v0034:
    v0046 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0046); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for mo_comp */

static Lisp_Object CC_mo_comp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_comp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0041 = v0040;
    v0041 = qcar(v0041);
    if (v0041 == nil) goto v0013;
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    return onevalue(v0040);

v0013:
    v0040 = (Lisp_Object)1; /* 0 */
    return onevalue(v0040);
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v0053;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c_zero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0053 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0053);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0067, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0058 = stack[-2];
    if (!(v0058 == nil)) goto v0040;
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0058); }

v0040:
    v0058 = stack[-1];
    if (v0058 == nil) goto v0043;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0067 = qcdr(v0058);
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    v0058 = (Lisp_Object)greaterp2(v0067, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0058 = v0058 ? lisp_true : nil;
    env = stack[-3];
    if (v0058 == nil) goto v0043;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0040;

v0043:
    v0058 = stack[-2];
    if (v0058 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0058 = stack[-1];
    if (v0058 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0059 = stack[-2];
    v0058 = stack[-1];
    v0067 = qcar(v0058);
    v0058 = stack[0];
    fn = elt(env, 2); /* reduce_pv0 */
    v0058 = (*qfnn(fn))(qenv(fn), 3, v0059, v0067, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    stack[-2] = v0058;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0043;
/* error exit handlers */
v0061:
    popv(4);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */

v0007:
    v0010 = v0015;
    if (v0010 == nil) goto v0013;
    v0010 = v0015;
    if (!consp(v0010)) goto v0009;
    v0015 = qcdr(v0015);
    goto v0007;

v0009:
    v0015 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0015);

v0013:
    v0015 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0015);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0038 = qcdr(v0004);
    v0004 = (Lisp_Object)1; /* 0 */
    v0004 = (v0038 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



/* Code for xcomment */

static Lisp_Object CC_xcomment(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0052, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xcomment");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0051 = v0029;
    v0052 = v0000;
/* end of prologue */
    v0064 = v0051;
    if (v0064 == nil) { popv(3); return onevalue(v0052); }
    stack[-1] = elt(env, 1); /* comment */
    v0064 = v0051;
    stack[0] = Lnreverse(nil, v0064);
    env = stack[-2];
    v0064 = v0052;
    v0064 = ncons(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    v0064 = Lnconc(nil, stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    v0064 = cons(stack[-1], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    v0052 = v0064;
    { popv(3); return onevalue(v0052); }
/* error exit handlers */
v0070:
    popv(3);
    return nil;
}



/* Code for monomgetvariabledegree */

static Lisp_Object CC_monomgetvariabledegree(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomgetvariabledegree");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0057 = v0000;
/* end of prologue */
    v0032 = v0057;
    v0057 = (Lisp_Object)17; /* 1 */
    v0057 = *(Lisp_Object *)((char *)v0032 + (CELL-TAG_VECTOR) + ((int32_t)v0057/(16/CELL)));
    stack[-1] = v0057;
    goto v0035;

v0035:
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    if (v0057 == nil) goto v0041;
    v0057 = stack[-1];
    v0032 = qcar(v0057);
    v0057 = stack[0];
    v0057 = (Lisp_Object)greaterp2(v0032, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0057 = v0057 ? lisp_true : nil;
    env = stack[-2];
    if (v0057 == nil) goto v0041;
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0035;

v0041:
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    if (v0057 == nil) goto v0025;
    v0057 = stack[-1];
    v0032 = qcar(v0057);
    v0057 = stack[0];
    if (!(equal(v0032, v0057))) goto v0025;
    v0057 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0057); }

v0025:
    v0057 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0057); }
/* error exit handlers */
v0037:
    popv(3);
    return nil;
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for rl_smupdknowl */

static Lisp_Object MS_CDECL CC_rl_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, Lisp_Object v0050, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0052, v0051, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v0050,v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0029,v0053,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0064 = v0050;
    v0052 = v0053;
    v0051 = v0029;
    v0021 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smupdknowl!* */
    v0064 = list4(v0021, v0051, v0052, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    {
        Lisp_Object v0031 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0031, v0064);
    }
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0065, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0065 = v0029;
    v0006 = v0000;
/* end of prologue */
    v0071 = v0006;
    if (!consp(v0071)) goto v0039;
    v0071 = v0006;
    v0071 = qcar(v0071);
    v0071 = (consp(v0071) ? nil : lisp_true);
    goto v0038;

v0038:
    if (v0071 == nil) goto v0062;
    v0071 = qvalue(elt(env, 1)); /* t */
    goto v0001;

v0001:
    if (v0071 == nil) goto v0086;
    v0071 = (Lisp_Object)1; /* 0 */
    return onevalue(v0071);

v0086:
    v0071 = v0006;
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0071 = qcdr(v0071);
    return onevalue(v0071);

v0062:
    v0071 = v0006;
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0071 = (v0071 == v0065 ? lisp_true : nil);
    v0071 = (v0071 == nil ? lisp_true : nil);
    goto v0001;

v0039:
    v0071 = qvalue(elt(env, 1)); /* t */
    goto v0038;
}



/* Code for prepf1a */

static Lisp_Object CC_prepf1a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0035, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf1a");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0029;
    v0035 = v0000;
/* end of prologue */
    v0042 = v0035;
    v0035 = v0041;
    v0041 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a_reversed */
    v0041 = (*qfnn(fn))(qenv(fn), 3, v0042, v0035, v0041);
    errexit();
        return Lnreverse(nil, v0041);
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0044, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setkorder");
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
    v0026 = v0000;
/* end of prologue */
    v0010 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v0010;
    v0044 = v0026;
    v0010 = stack[0];
    if (equal(v0044, v0010)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0010 = v0026;
    qvalue(elt(env, 1)) = v0010; /* kord!* */
    v0010 = qvalue(elt(env, 2)); /* nil */
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0010; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0064:
    popv(2);
    return nil;
}



/* Code for ibalp_emptyclausep */

static Lisp_Object CC_ibalp_emptyclausep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = qcar(v0065);
    if (v0065 == nil) goto v0042;
    v0065 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0065); }

v0042:
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0006 = qcar(v0065);
    v0065 = (Lisp_Object)1; /* 0 */
    v0065 = Leqn(nil, v0006, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    if (v0065 == nil) goto v0040;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0006 = qcar(v0065);
    v0065 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leqn(nil, v0006, v0065);

v0040:
    v0065 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0065); }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0085 = stack[-2];
    if (v0085 == nil) goto v0034;
    v0100 = stack[-1];
    v0085 = (Lisp_Object)17; /* 1 */
    if (v0100 == v0085) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0085 = stack[-2];
    if (!consp(v0085)) goto v0044;
    v0085 = stack[-2];
    v0085 = qcar(v0085);
    v0085 = (consp(v0085) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0085 == nil) goto v0024;
    v0100 = stack[-2];
    v0085 = stack[-1];
    v0085 = Lmodular_times(nil, v0100, v0085);
    env = stack[-4];
    v0100 = v0085;
    v0085 = v0100;
    v0085 = (Lisp_Object)zerop(v0085);
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-4];
    if (v0085 == nil) { popv(5); return onevalue(v0100); }
    v0085 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0085); }

v0024:
    v0085 = stack[-2];
    v0085 = qcar(v0085);
    stack[-3] = qcar(v0085);
    v0085 = stack[-2];
    v0085 = qcar(v0085);
    v0100 = qcdr(v0085);
    v0085 = stack[-1];
    stack[0] = CC_multiplyKbyKconstantKmodKp(env, v0100, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    v0085 = stack[-2];
    v0100 = qcdr(v0085);
    v0085 = stack[-1];
    v0085 = CC_multiplyKbyKconstantKmodKp(env, v0100, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    {
        Lisp_Object v0091 = stack[-3];
        Lisp_Object v0092 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0091, v0092, v0085);
    }

v0044:
    v0085 = qvalue(elt(env, 2)); /* t */
    goto v0010;

v0034:
    v0085 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0085); }
/* error exit handlers */
v0101:
    popv(5);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0006, v0072, v0011;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0029;
    v0072 = v0000;
/* end of prologue */

v0002:
    v0011 = v0006;
    v0065 = nil;
    if (v0011 == v0065) goto v0008;
    v0065 = v0006;
    v0065 = qcar(v0065);
    v0072 = Lmember(nil, v0065, v0072);
    v0065 = v0006;
    v0065 = qcdr(v0065);
    v0006 = v0065;
    goto v0002;

v0008:
    v0065 = v0072;
    if (v0065 == nil) goto v0044;
    v0065 = v0072;
    v0065 = qcdr(v0065);
    return onevalue(v0065);

v0044:
    v0065 = elt(env, 1); /* (stop) */
    return onevalue(v0065);
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0036, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for butes");
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
    v0055 = v0000;
/* end of prologue */
    v0011 = v0055;
    v0011 = qcar(v0011);
    qvalue(elt(env, 1)) = v0011; /* cha */
    v0036 = qvalue(elt(env, 1)); /* cha */
    v0011 = elt(env, 2); /* !  */
    if (v0036 == v0011) goto v0039;
    v0036 = qvalue(elt(env, 1)); /* cha */
    v0011 = elt(env, 4); /* !$ */
    v0011 = (v0036 == v0011 ? lisp_true : nil);
    goto v0038;

v0038:
    if (v0011 == nil) goto v0086;
    v0011 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0011); }

v0086:
    v0011 = v0055;
    stack[0] = qcar(v0011);
    v0011 = v0055;
    v0011 = qcdr(v0011);
    v0011 = CC_butes(env, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    {
        Lisp_Object v0023 = stack[0];
        popv(1);
        return cons(v0023, v0011);
    }

v0039:
    v0011 = qvalue(elt(env, 3)); /* t */
    goto v0038;
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0072, v0011;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0000;
/* end of prologue */

v0007:
    v0006 = v0072;
    if (v0006 == nil) goto v0013;
    v0006 = v0072;
    v0011 = qcar(v0006);
    v0006 = qvalue(elt(env, 2)); /* frlis!* */
    v0006 = Lmemq(nil, v0011, v0006);
    if (v0006 == nil) goto v0038;
    v0006 = v0072;
    v0011 = qcar(v0006);
    v0006 = v0072;
    v0006 = qcdr(v0006);
    v0006 = Lmember(nil, v0011, v0006);
    if (v0006 == nil) goto v0051;
    v0006 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0006);

v0051:
    v0006 = v0072;
    v0006 = qcdr(v0006);
    v0072 = v0006;
    goto v0007;

v0038:
    v0006 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0006);

v0013:
    v0006 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0006);
}



/* Code for nil2zero */

static Lisp_Object CC_nil2zero(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nil2zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0038 = v0004;
    if (!(v0038 == nil)) return onevalue(v0004);
    v0004 = (Lisp_Object)1; /* 0 */
    return onevalue(v0004);
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:free");
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
    v0004 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[0];
    v0038 = elt(env, 1); /* unbound */
    v0004 = (v0004 == v0038 ? lisp_true : nil);
    { popv(1); return onevalue(v0004); }
/* error exit handlers */
v0039:
    popv(1);
    return nil;
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0036, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcsize");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0036 = v0029;
    stack[0] = v0000;
/* end of prologue */

v0008:
    v0055 = v0036;
    v0011 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v0055)) > ((int32_t)(v0011))) goto v0034;
    v0011 = stack[0];
    if (!consp(v0011)) { popv(2); return onevalue(v0036); }
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0036 = (Lisp_Object)((int32_t)(v0036) + 0x10);
    v0011 = CC_vbcsize(env, v0011, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0036 = v0011;
    v0011 = v0036;
    if (v0011 == nil) goto v0047;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0008;

v0047:
    v0011 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0011); }

v0034:
    v0011 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0011); }
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0015, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgefax");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0022 = v0015;
    v0010 = elt(env, 1); /* wedge */
    if (!consp(v0022)) goto v0035;
    v0022 = qcar(v0022);
    if (!(v0022 == v0010)) goto v0035;
    v0022 = v0015;
    v0022 = qcdr(v0022);
    return onevalue(v0022);

v0035:
    v0022 = v0015;
    return ncons(v0022);
}



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0102, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_normbf");
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
    stack[-3] = nil;
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    v0102 = qcar(v0078);
    stack[0] = v0102;
    v0078 = (Lisp_Object)1; /* 0 */
    if (v0102 == v0078) goto v0003;
    v0102 = stack[0];
    v0078 = (Lisp_Object)1; /* 0 */
    v0078 = (Lisp_Object)lessp2(v0102, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-4];
    if (v0078 == nil) goto v0044;
    v0078 = stack[0];
    v0078 = negate(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    stack[0] = v0078;
    v0078 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0078;
    goto v0044;

v0044:
    v0078 = stack[0];
    fn = elt(env, 4); /* lsd */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    stack[-1] = v0078;
    v0078 = stack[-1];
    v0078 = negate(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    v0078 = ash(stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    stack[0] = v0078;
    v0078 = stack[-3];
    if (v0078 == nil) goto v0025;
    v0078 = stack[0];
    v0078 = negate(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    stack[0] = v0078;
    goto v0025;

v0025:
    v0102 = stack[-1];
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    v0078 = qcdr(v0078);
    v0078 = plus2(v0102, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    stack[-1] = v0078;
    v0079 = elt(env, 3); /* !:rd!: */
    v0102 = stack[0];
    v0078 = stack[-1];
    popv(5);
    return list2star(v0079, v0102, v0078);

v0003:
    v0078 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v0078); }
/* error exit handlers */
v0085:
    popv(5);
    return nil;
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0071;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0000;
/* end of prologue */
    v0049 = v0071;
    if (!consp(v0049)) goto v0013;
    v0049 = v0071;
    v0049 = qcar(v0049);
    if (symbolp(v0049)) goto v0047;
    v0049 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0049);

v0047:
    v0049 = v0071;
    v0049 = qcar(v0049);
    v0071 = elt(env, 2); /* phystype */
    return get(v0049, v0071);

v0013:
    v0049 = v0071;
    if (symbolp(v0049)) goto v0035;
    v0049 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0049);

v0035:
    v0049 = v0071;
    v0071 = elt(env, 2); /* phystype */
    return get(v0049, v0071);
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0052 = stack[-1];
    v0064 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v0064 = (*qfn2(fn))(qenv(fn), v0052, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    if (!(v0064 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0052 = stack[-1];
    v0064 = stack[0];
    popv(2);
    return cons(v0052, v0064);
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0124, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0005;

v0005:
    v0123 = stack[-2];
    if (v0123 == nil) goto v0039;
    v0123 = stack[-1];
    if (v0123 == nil) goto v0026;
    v0123 = stack[-2];
    if (!consp(v0123)) goto v0047;
    v0123 = stack[-2];
    v0123 = qcar(v0123);
    v0123 = (consp(v0123) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0123 == nil) goto v0031;
    v0124 = stack[-2];
    v0123 = stack[-1];
    fn = elt(env, 2); /* addd */
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    {
        Lisp_Object v0127 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0127, v0123);
    }

v0031:
    v0123 = stack[-1];
    if (!consp(v0123)) goto v0099;
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    v0123 = (consp(v0123) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0123 == nil) goto v0101;
    v0124 = stack[-1];
    v0123 = stack[-2];
    fn = elt(env, 2); /* addd */
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    {
        Lisp_Object v0128 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0128, v0123);
    }

v0101:
    v0123 = stack[-2];
    v0123 = qcar(v0123);
    v0124 = qcar(v0123);
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    v0123 = qcar(v0123);
    if (equal(v0124, v0123)) goto v0090;
    v0123 = stack[-2];
    v0123 = qcar(v0123);
    v0124 = qcar(v0123);
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    v0123 = qcar(v0123);
    fn = elt(env, 4); /* ordpp */
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    if (v0123 == nil) goto v0129;
    v0123 = stack[-2];
    v0124 = qcar(v0123);
    v0123 = stack[0];
    v0123 = cons(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    stack[0] = v0123;
    v0123 = stack[-2];
    v0123 = qcdr(v0123);
    stack[-2] = v0123;
    goto v0005;

v0129:
    v0123 = stack[-1];
    v0124 = qcar(v0123);
    v0123 = stack[0];
    v0123 = cons(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    stack[0] = v0123;
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    stack[-1] = v0123;
    goto v0005;

v0090:
    stack[-3] = stack[0];
    v0123 = stack[-2];
    v0123 = qcar(v0123);
    v0124 = qcdr(v0123);
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    v0123 = qcdr(v0123);
    stack[0] = CC_addf(env, v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    v0123 = stack[-2];
    v0124 = qcdr(v0123);
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    v0123 = CC_addf(env, v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    v0124 = stack[0];
    v0125 = v0124;
    if (v0125 == nil) goto v0084;
    v0125 = stack[-2];
    v0125 = qcar(v0125);
    v0125 = qcar(v0125);
    v0123 = acons(v0125, v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    goto v0084;

v0084:
    {
        Lisp_Object v0130 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0130, v0123);
    }

v0099:
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0033;

v0047:
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0012;

v0026:
    v0124 = stack[0];
    v0123 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0124, v0123);
    }

v0039:
    v0124 = stack[0];
    v0123 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0124, v0123);
    }
/* error exit handlers */
v0126:
    popv(5);
    return nil;
}



/* Code for expdrmacro */

static Lisp_Object CC_expdrmacro(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expdrmacro");
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
    v0023 = stack[0];
    fn = elt(env, 7); /* getrmacro */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-1];
    v0045 = v0023;
    if (v0023 == nil) goto v0004;
    v0024 = stack[0];
    v0023 = elt(env, 2); /* noexpand */
    v0023 = Lflagp(nil, v0024, v0023);
    env = stack[-1];
    goto v0003;

v0003:
    if (v0023 == nil) goto v0001;
    v0023 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0023); }

v0001:
    v0023 = qvalue(elt(env, 4)); /* !*cref */
    if (v0023 == nil) { popv(2); return onevalue(v0045); }
    v0024 = stack[0];
    v0023 = elt(env, 5); /* expand */
    v0023 = Lflagp(nil, v0024, v0023);
    env = stack[-1];
    if (v0023 == nil) goto v0012;
    v0023 = qvalue(elt(env, 3)); /* nil */
    goto v0030;

v0030:
    if (v0023 == nil) { popv(2); return onevalue(v0045); }
    v0023 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0023); }

v0012:
    v0023 = qvalue(elt(env, 6)); /* !*force */
    v0023 = (v0023 == nil ? lisp_true : nil);
    goto v0030;

v0004:
    v0023 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0046:
    popv(2);
    return nil;
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    v0034 = qcar(v0034);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v0034);
    }
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0033 = nil;
    goto v0005;

v0005:
    v0032 = stack[0];
    if (v0032 == nil) goto v0041;
    v0032 = stack[0];
    if (!consp(v0032)) goto v0026;
    v0032 = stack[0];
    v0032 = qcar(v0032);
    v0032 = (consp(v0032) ? nil : lisp_true);
    goto v0044;

v0044:
    if (v0032 == nil) goto v0017;
    stack[-2] = v0033;
    v0033 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 2); /* adddm */
    v0032 = (*qfn2(fn))(qenv(fn), v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    {
        Lisp_Object v0067 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0067, v0032);
    }

v0017:
    v0032 = stack[0];
    v0032 = qcar(v0032);
    v0032 = cons(v0032, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    v0033 = v0032;
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    stack[0] = v0032;
    goto v0005;

v0026:
    v0032 = qvalue(elt(env, 1)); /* t */
    goto v0044;

v0041:
    v0032 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0033, v0032);
    }
/* error exit handlers */
v0058:
    popv(4);
    return nil;
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0086, v0048;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub2chk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0000;
/* end of prologue */
    v0054 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0054 == nil) goto v0034;
    v0086 = v0048;
    v0054 = qvalue(elt(env, 2)); /* powlis!* */
    v0054 = Latsoc(nil, v0086, v0054);
    if (!(v0054 == nil)) goto v0013;
    v0054 = v0048;
    if (!consp(v0054)) goto v0030;
    v0054 = v0048;
    v0086 = qcar(v0054);
    v0054 = elt(env, 3); /* (expt sqrt) */
    v0054 = Lmemq(nil, v0086, v0054);
    goto v0022;

v0022:
    if (!(v0054 == nil)) goto v0013;

v0034:
    v0054 = nil;
    return onevalue(v0054);

v0013:
    v0054 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 6)) = v0054; /* !*sub2 */
    return onevalue(v0054);

v0030:
    v0054 = qvalue(elt(env, 4)); /* nil */
    goto v0022;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0029;
    v0040 = v0000;
/* end of prologue */
    v0040 = qcar(v0040);
    v0039 = qcar(v0039);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v0040, v0039);
    }
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0077, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0077 = v0029;
    v0131 = v0000;
/* end of prologue */
    v0079 = v0131;
    if (!consp(v0079)) goto v0002;
    v0079 = qvalue(elt(env, 1)); /* nil */
    goto v0001;

v0001:
    if (v0079 == nil) goto v0061;
    v0079 = v0131;
    v0079 = times2(v0079, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[0];
    v0131 = v0079;
    v0079 = qvalue(elt(env, 2)); /* dmode!* */
    if (v0079 == nil) goto v0031;
    v0077 = qvalue(elt(env, 2)); /* dmode!* */
    v0079 = elt(env, 4); /* convert */
    v0079 = Lflagp(nil, v0077, v0079);
    env = stack[0];
    v0079 = (v0079 == nil ? lisp_true : nil);
    goto v0070;

v0070:
    if (!(v0079 == nil)) { popv(1); return onevalue(v0131); }
    v0077 = qvalue(elt(env, 2)); /* dmode!* */
    v0079 = elt(env, 5); /* i2d */
    v0079 = get(v0077, v0079);
    v0077 = v0131;
        popv(1);
        return Lapply1(nil, v0079, v0077);

v0031:
    v0079 = qvalue(elt(env, 3)); /* t */
    goto v0070;

v0061:
    v0079 = elt(env, 6); /* times */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0131, v0077, v0079);
    }

v0002:
    v0079 = v0077;
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0001;
/* error exit handlers */
v0093:
    popv(1);
    return nil;
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020, v0070, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dssoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0070 = v0029;
    v0031 = v0000;
/* end of prologue */

v0034:
    v0021 = v0070;
    if (v0021 == nil) goto v0001;
    v0020 = v0031;
    v0021 = v0070;
    v0021 = qcar(v0021);
    v0021 = qcdr(v0021);
    if (equal(v0020, v0021)) goto v0038;
    v0021 = v0070;
    v0021 = qcdr(v0021);
    v0070 = v0021;
    goto v0034;

v0038:
    v0021 = v0070;
    v0021 = qcar(v0021);
    return onevalue(v0021);

v0001:
    v0021 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0021);
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomlistp");
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

v0007:
    v0022 = stack[0];
    v0022 = Lconsp(nil, v0022);
    env = stack[-1];
    if (v0022 == nil) goto v0013;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    fn = elt(env, 2); /* noncomp1 */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    if (!(v0022 == nil)) { popv(2); return onevalue(v0022); }
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0007;

v0013:
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0022); }
/* error exit handlers */
v0010:
    popv(2);
    return nil;
}



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0038 = qcdr(v0038);
    v0039 = qcar(v0038);
    v0038 = (Lisp_Object)1; /* 0 */
    v0038 = (v0039 == v0038 ? lisp_true : nil);
    return onevalue(v0038);
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0038 = qcdr(v0004);
    v0004 = (Lisp_Object)17; /* 1 */
    v0004 = (v0038 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



/* Code for eolcheck */

static Lisp_Object MS_CDECL CC_eolcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eolcheck");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eolcheck");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0086 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (!(v0086 == nil)) goto v0035;
    v0086 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0086); }

v0035:
    v0048 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0086 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (v0048 == v0086) goto v0052;
    v0086 = nil;
    { popv(1); return onevalue(v0086); }

v0052:
    v0048 = qvalue(elt(env, 5)); /* cursym!* */
    v0086 = elt(env, 6); /* end */
    if (v0048 == v0086) goto v0062;
    fn = elt(env, 8); /* token1 */
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    goto v0026;

v0026:
    qvalue(elt(env, 3)) = v0086; /* nxtsym!* */
    goto v0035;

v0062:
    v0086 = elt(env, 7); /* !; */
    goto v0026;
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for mtchp1 */

static Lisp_Object MS_CDECL CC_mtchp1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, Lisp_Object v0050, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mtchp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchp1");
#endif
    if (stack >= stacklimit)
    {
        push4(v0050,v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0029,v0053,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0143 = v0050;
    stack[0] = v0053;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0103 = stack[-2];
    v0143 = stack[-1];
    if (equal(v0103, v0143)) goto v0003;
    v0143 = stack[-2];
    v0103 = qcar(v0143);
    v0143 = stack[-1];
    v0143 = qcar(v0143);
    fn = elt(env, 5); /* mchk!* */
    v0143 = (*qfn2(fn))(qenv(fn), v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[-3] = v0143;
    if (v0143 == nil) goto v0015;
    v0143 = stack[-1];
    v0103 = qcdr(v0143);
    v0143 = qvalue(elt(env, 2)); /* frlis!* */
    v0143 = Lmemq(nil, v0103, v0143);
    if (v0143 == nil) goto v0047;
    v0143 = stack[-2];
    v0103 = qcdr(v0143);
    v0143 = (Lisp_Object)17; /* 1 */
    if (v0103 == v0143) goto v0017;
    v0143 = stack[-1];
    v0104 = qcdr(v0143);
    v0103 = stack[-3];
    v0143 = stack[-2];
    v0143 = qcdr(v0143);
    fn = elt(env, 6); /* powmtch */
    v0143 = (*qfnn(fn))(qenv(fn), 3, v0104, v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[-3] = v0143;
    v0143 = (v0143 == nil ? lisp_true : nil);
    goto v0055;

v0055:
    if (v0143 == nil) goto v0094;
    v0143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0143); }

v0094:
    stack[0] = stack[-3];
    v0143 = stack[-1];
    v0103 = qcdr(v0143);
    v0143 = stack[-2];
    v0143 = qcdr(v0143);
    v0143 = cons(v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    {
        Lisp_Object v0144 = stack[0];
        popv(5);
        fn = elt(env, 7); /* mapcons */
        return (*qfn2(fn))(qenv(fn), v0144, v0143);
    }

v0017:
    v0143 = qvalue(elt(env, 3)); /* t */
    goto v0055;

v0047:
    v0143 = stack[0];
    if (v0143 == nil) goto v0145;
    v0143 = stack[-2];
    v0103 = qcdr(v0143);
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    if (!(equal(v0103, v0143))) goto v0082;

v0145:
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    if (is_number(v0143)) goto v0146;
    v0143 = qvalue(elt(env, 3)); /* t */
    goto v0119;

v0119:
    if (v0143 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    else goto v0082;

v0082:
    v0143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0143); }

v0146:
    v0143 = stack[-2];
    v0143 = qcdr(v0143);
    if (is_number(v0143)) goto v0114;
    v0143 = qvalue(elt(env, 3)); /* t */
    goto v0119;

v0114:
    v0143 = qvalue(elt(env, 4)); /* !*mcd */
    if (v0143 == nil) goto v0147;
    v0143 = stack[-2];
    v0103 = qcdr(v0143);
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    v0143 = (Lisp_Object)lessp2(v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    v0143 = v0143 ? lisp_true : nil;
    env = stack[-4];
    goto v0119;

v0147:
    v0143 = stack[-2];
    v0103 = qcdr(v0143);
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    v0103 = times2(v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0143 = (Lisp_Object)1; /* 0 */
    v0143 = (Lisp_Object)lessp2(v0103, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    v0143 = v0143 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0143 == nil)) goto v0119;
    v0143 = stack[-2];
    v0143 = qcdr(v0143);
    stack[0] = Labsval(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    v0143 = Labsval(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0143 = (Lisp_Object)lessp2(stack[0], v0143);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    v0143 = v0143 ? lisp_true : nil;
    env = stack[-4];
    goto v0119;

v0015:
    v0143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0143); }

v0003:
    v0143 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return ncons(v0143);
/* error exit handlers */
v0125:
    popv(5);
    return nil;
}



/* Code for mri_floorkernelp */

static Lisp_Object CC_mri_floorkernelp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_floorkernelp");
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
    v0004 = v0000;
/* end of prologue */
    v0038 = v0004;
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* kernels1 */
    v0004 = (*qfn2(fn))(qenv(fn), v0038, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mri_floorp */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0039:
    popv(1);
    return nil;
}



/* Code for qqe_qoptailp */

static Lisp_Object CC_qqe_qoptailp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0000;
/* end of prologue */
    v0035 = v0041;
    v0041 = elt(env, 1); /* (rtail ltail) */
    v0041 = Lmemq(nil, v0035, v0041);
    if (v0041 == nil) goto v0034;
    v0041 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0041);

v0034:
    v0041 = nil;
    return onevalue(v0041);
}



/* Code for lto_setequalq */

static Lisp_Object CC_lto_setequalq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0079, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setequalq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0102 = qvalue(elt(env, 1)); /* !*rlsetequalqhash */
    if (v0102 == nil) goto v0070;
    v0079 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 4); /* lto_hashequalq */
    v0102 = (*qfn2(fn))(qenv(fn), v0079, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    goto v0035;

v0035:
    if (v0102 == nil) goto v0043;
    v0102 = qvalue(elt(env, 3)); /* t */
    v0077 = v0102;
    goto v0072;

v0072:
    v0102 = v0077;
    if (v0102 == nil) { popv(3); return onevalue(v0077); }
    v0102 = stack[-1];
    if (v0102 == nil) { popv(3); return onevalue(v0077); }
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    v0079 = v0102;
    v0102 = stack[0];
    v0102 = Lmemq(nil, v0079, v0102);
    if (v0102 == nil) goto v0063;
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0072;

v0063:
    v0102 = qvalue(elt(env, 2)); /* nil */
    v0077 = v0102;
    goto v0072;

v0043:
    v0102 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0102); }

v0070:
    v0079 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 5); /* lto_equallengthp */
    v0102 = (*qfn2(fn))(qenv(fn), v0079, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    goto v0035;
/* error exit handlers */
v0094:
    popv(3);
    return nil;
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */

v0007:
    v0044 = v0010;
    if (v0044 == nil) goto v0013;
    v0044 = v0010;
    v0044 = qcar(v0044);
    if (is_number(v0044)) goto v0042;
    v0010 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0010);

v0042:
    v0010 = qcdr(v0010);
    goto v0007;

v0013:
    v0010 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0010);
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0064;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constp");
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
    v0062 = v0000;
/* end of prologue */
    v0064 = v0062;
    v0064 = (is_number(v0064) ? lisp_true : nil);
    if (!(v0064 == nil)) { popv(1); return onevalue(v0064); }
    v0064 = v0062;
    v0064 = Lconsp(nil, v0064);
    env = stack[0];
    if (v0064 == nil) goto v0002;
    v0062 = qcar(v0062);
    v0064 = qvalue(elt(env, 2)); /* domainlist!* */
    v0062 = Lmemq(nil, v0062, v0064);
    { popv(1); return onevalue(v0062); }

v0002:
    v0062 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0062); }
}



/* Code for replus1 */

static Lisp_Object CC_replus1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0023, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replus1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    v0016 = v0024;
    if (v0016 == nil) goto v0013;
    v0016 = v0024;
    if (!consp(v0016)) goto v0038;
    v0023 = v0024;
    v0016 = elt(env, 2); /* plus */
    if (!consp(v0023)) goto v0031;
    v0023 = qcar(v0023);
    if (!(v0023 == v0016)) goto v0031;
    v0016 = v0024;
    v0016 = qcdr(v0016);
    goto v0004;

v0004:
    if (!(v0016 == nil)) return onevalue(v0024);
    v0016 = v0024;
    v0016 = qcdr(v0016);
    if (v0016 == nil) goto v0056;
    v0016 = elt(env, 2); /* plus */
    v0023 = v0024;
    return cons(v0016, v0023);

v0056:
    v0016 = v0024;
    v0016 = qcar(v0016);
    return onevalue(v0016);

v0031:
    v0016 = qvalue(elt(env, 3)); /* nil */
    goto v0004;

v0038:
    v0016 = qvalue(elt(env, 1)); /* t */
    goto v0004;

v0013:
    v0016 = (Lisp_Object)1; /* 0 */
    return onevalue(v0016);
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0086, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0086 = stack[0];
    v0054 = stack[-1];
    fn = elt(env, 4); /* vevmtest!? */
    v0054 = (*qfn2(fn))(qenv(fn), v0086, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    if (v0054 == nil) goto v0034;
    v0054 = qvalue(elt(env, 2)); /* gmodule!* */
    if (v0054 == nil) goto v0022;
    v0048 = stack[-1];
    v0086 = stack[0];
    v0054 = qvalue(elt(env, 2)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 5); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v0048, v0086, v0054);
    }

v0022:
    v0054 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v0054); }

v0034:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0018:
    popv(3);
    return nil;
}



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0065, v0006, v0072;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublistp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0065 = v0029;
    v0006 = v0000;
/* end of prologue */

v0007:
    v0071 = v0006;
    if (v0071 == nil) goto v0034;
    v0071 = v0006;
    v0072 = qcar(v0071);
    v0071 = v0065;
    v0071 = Lmember(nil, v0072, v0071);
    if (v0071 == nil) goto v0039;
    v0071 = v0006;
    stack[0] = qcdr(v0071);
    v0071 = v0006;
    v0071 = qcar(v0071);
    v0071 = Ldelete(nil, v0071, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    v0006 = stack[0];
    v0065 = v0071;
    goto v0007;

v0039:
    v0071 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0071); }

v0034:
    v0071 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0071); }
/* error exit handlers */
v0036:
    popv(2);
    return nil;
}



/* Code for !:times */

static Lisp_Object CC_Ttimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0016, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :times");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0029;
    v0023 = v0000;
/* end of prologue */
    v0017 = v0023;
    if (v0017 == nil) goto v0002;
    v0017 = v0016;
    v0017 = (v0017 == nil ? lisp_true : nil);
    goto v0001;

v0001:
    if (v0017 == nil) goto v0005;
    v0017 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0017);

v0005:
    v0017 = v0023;
    if (!consp(v0017)) goto v0010;
    v0017 = qvalue(elt(env, 2)); /* nil */
    goto v0015;

v0015:
    if (v0017 == nil) goto v0065;
    v0017 = v0023;
    return times2(v0017, v0016);

v0065:
    v0017 = elt(env, 3); /* times */
    {
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0023, v0016, v0017);
    }

v0010:
    v0017 = v0016;
    v0017 = (consp(v0017) ? nil : lisp_true);
    goto v0015;

v0002:
    v0017 = qvalue(elt(env, 1)); /* t */
    goto v0001;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pprin2");
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
    v0044 = stack[0];
    v0010 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v0010 = cons(v0044, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0010; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v0010 = stack[0];
    v0010 = Lexplodec(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0010 = Llength(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0010 = plus2(stack[-1], v0010);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0010; /* !*posn!* */
    v0010 = nil;
    { popv(3); return onevalue(v0010); }
/* error exit handlers */
v0064:
    popv(3);
    return nil;
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0099, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isanindex");
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
    v0037 = v0000;
/* end of prologue */
    v0033 = v0037;
    if (symbolp(v0033)) goto v0039;
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0033); }

v0039:
    v0099 = v0037;
    v0033 = qvalue(elt(env, 2)); /* physopindices!* */
    v0033 = Lmemq(nil, v0099, v0033);
    if (!(v0033 == nil)) { popv(1); return onevalue(v0033); }
    v0099 = v0037;
    v0033 = qvalue(elt(env, 3)); /* physopvarind!* */
    v0033 = Lmember(nil, v0099, v0033);
    if (!(v0033 == nil)) { popv(1); return onevalue(v0033); }
    v0099 = v0037;
    v0033 = qvalue(elt(env, 4)); /* frlis!* */
    v0033 = Lmemq(nil, v0099, v0033);
    if (v0033 == nil) goto v0012;
    v0099 = v0037;
    v0033 = qvalue(elt(env, 5)); /* frasc!* */
    fn = elt(env, 6); /* revassoc */
    v0033 = (*qfn2(fn))(qenv(fn), v0099, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[0];
    v0099 = qvalue(elt(env, 2)); /* physopindices!* */
    v0033 = Lmember(nil, v0033, v0099);
    { popv(1); return onevalue(v0033); }

v0012:
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0033); }
/* error exit handlers */
v0066:
    popv(1);
    return nil;
}



/* Code for formlis */

static Lisp_Object MS_CDECL CC_formlis(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0054, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0008;

v0008:
    v0056 = stack[-2];
    if (v0056 == nil) goto v0003;
    v0056 = stack[-2];
    v0086 = qcar(v0056);
    v0054 = stack[-1];
    v0056 = stack[0];
    fn = elt(env, 1); /* form1 */
    v0054 = (*qfnn(fn))(qenv(fn), 3, v0086, v0054, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0056 = stack[-3];
    v0056 = cons(v0054, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    stack[-3] = v0056;
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0008;

v0003:
    v0056 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0056);
/* error exit handlers */
v0049:
    popv(5);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval*");
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
    stack[-1] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0041 = qvalue(elt(env, 2)); /* nil */
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0041; /* alglist!* */
    v0035 = stack[0];
    v0041 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* reval1 */
    v0041 = (*qfn2(fn))(qenv(fn), v0035, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    { popv(3); return onevalue(v0041); }
/* error exit handlers */
v0014:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    popv(3);
    return nil;
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0038 = v0029;
    v0039 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v0038 = (*qfn2(fn))(qenv(fn), v0039, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
/* error exit handlers */
v0040:
    popv(1);
    return nil;
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0049, v0071, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dlesslex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0029;
    v0071 = v0000;
/* end of prologue */

v0034:
    v0018 = v0071;
    if (v0018 == nil) goto v0001;
    v0018 = v0071;
    v0065 = qcar(v0018);
    v0018 = v0049;
    v0018 = qcar(v0018);
    if (((int32_t)(v0065)) > ((int32_t)(v0018))) goto v0038;
    v0018 = v0071;
    v0065 = qcar(v0018);
    v0018 = v0049;
    v0018 = qcar(v0018);
    if (((int32_t)(v0065)) < ((int32_t)(v0018))) goto v0026;
    v0018 = v0071;
    v0018 = qcdr(v0018);
    v0071 = v0018;
    v0018 = v0049;
    v0018 = qcdr(v0018);
    v0049 = v0018;
    goto v0034;

v0026:
    v0018 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0018);

v0038:
    v0018 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0018);

v0001:
    v0018 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0018);
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0053;
    stack[-4] = v0029;
    stack[0] = v0000;
/* end of prologue */
    v0111 = stack[-4];
    if (v0111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0111 = stack[0];
    if (v0111 == nil) goto v0003;
    v0111 = stack[0];
    stack[-5] = v0111;
    goto v0044;

v0044:
    v0111 = stack[-5];
    if (v0111 == nil) goto v0010;
    v0111 = stack[-4];
    if (v0111 == nil) goto v0010;
    v0111 = stack[-5];
    v0111 = qcar(v0111);
    v0112 = qcdr(v0111);
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    v0111 = (Lisp_Object)greaterp2(v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    v0111 = v0111 ? lisp_true : nil;
    env = stack[-6];
    if (v0111 == nil) goto v0010;
    v0111 = stack[-5];
    v0111 = qcdr(v0111);
    stack[-5] = v0111;
    goto v0044;

v0010:
    v0111 = stack[-5];
    if (v0111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0111 = stack[-4];
    if (v0111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0112 = qcdr(v0111);
    v0111 = stack[-5];
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    if (!(equal(v0112, v0111))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0111 = stack[-5];
    v0111 = qcar(v0111);
    v0112 = qcar(v0111);
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    fn = elt(env, 3); /* lcm */
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    stack[-2] = v0111;
    v0112 = stack[-2];
    v0111 = stack[-5];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0111 = quot2(v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    stack[0] = stack[-4];
    v0112 = stack[-2];
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0111 = quot2(v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    v0111 = negate(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v0111 = (*qfn2(fn))(qenv(fn), stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v0111 = (*qfn2(fn))(qenv(fn), stack[-1], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    stack[0] = v0111;
    v0111 = stack[-3];
    if (v0111 == nil) goto v0115;
    v0111 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0111; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0115:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v0112 = stack[-2];
    v0111 = stack[-5];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0111 = quot2(v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    v0111 = times2(stack[-1], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-6];
    qvalue(elt(env, 2)) = v0111; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0003:
    v0111 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0111); }
/* error exit handlers */
v0136:
    popv(7);
    return nil;
}



/* Code for upbve */

static Lisp_Object CC_upbve(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for upbve");
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
    v0040 = stack[0];
    v0040 = Lupbv(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    if (v0040 == nil) goto v0013;
    v0040 = stack[0];
    v0040 = Lupbv(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    popv(2);
    return add1(v0040);

v0013:
    v0040 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0040); }
/* error exit handlers */
v0035:
    popv(2);
    return nil;
}



/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0015, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0022 = v0015;
    v0022 = qcdr(v0022);
    v0015 = v0022;
    v0010 = qcdr(v0022);
    v0022 = (Lisp_Object)17; /* 1 */
    if (v0010 == v0022) goto v0013;
    v0022 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0022);

v0013:
    v0022 = v0015;
    v0022 = qcar(v0022);
    return onevalue(v0022);
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0005;

v0005:
    v0121 = stack[-1];
    if (v0121 == nil) goto v0002;
    v0122 = stack[-1];
    v0121 = (Lisp_Object)17; /* 1 */
    if (v0122 == v0121) goto v0026;
    v0121 = stack[-1];
    if (!consp(v0121)) goto v0047;
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = (consp(v0121) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0121 == nil) goto v0033;
    stack[0] = stack[-3];
    v0122 = stack[-2];
    v0121 = stack[-1];
    fn = elt(env, 2); /* multdm */
    v0121 = (*qfn2(fn))(qenv(fn), v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    {
        Lisp_Object v0073 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0073, v0121);
    }

v0033:
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    stack[0] = qcar(v0121);
    v0122 = stack[-2];
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    v0122 = CC_multd(env, v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0121 = stack[-3];
    v0121 = acons(stack[0], v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    stack[-3] = v0121;
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    stack[-1] = v0121;
    goto v0005;

v0047:
    v0121 = qvalue(elt(env, 1)); /* t */
    goto v0012;

v0026:
    v0122 = stack[-3];
    v0121 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0122, v0121);
    }

v0002:
    v0121 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0121);
    }
/* error exit handlers */
v0092:
    popv(5);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2mod");
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
    v0034 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0034);
    }
/* error exit handlers */
v0005:
    popv(1);
    return nil;
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-times");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0018 = v0029;
    v0049 = v0000;
/* end of prologue */
    v0049 = times2(v0049, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    v0018 = qvalue(elt(env, 1)); /* current!-modulus */
    v0018 = Cremainder(v0049, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    stack[0] = v0018;
    v0049 = stack[0];
    v0018 = (Lisp_Object)1; /* 0 */
    v0018 = (Lisp_Object)lessp2(v0049, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0018 = v0018 ? lisp_true : nil;
    env = stack[-1];
    if (v0018 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0049 = stack[0];
    v0018 = qvalue(elt(env, 1)); /* current!-modulus */
    v0018 = plus2(v0049, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    stack[0] = v0018;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0065:
    popv(2);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getpower");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0019 = stack[-1];
    v0018 = qcar(v0019);
    v0019 = elt(env, 1); /* expt */
    if (!consp(v0018)) goto v0051;
    v0018 = qcar(v0018);
    if (!(v0018 == v0019)) goto v0051;
    v0018 = stack[0];
    v0019 = (Lisp_Object)17; /* 1 */
    v0019 = (Lisp_Object)greaterp2(v0018, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0019 = v0019 ? lisp_true : nil;
    env = stack[-2];
    goto v0001;

v0001:
    if (v0019 == nil) goto v0030;
    v0019 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 4)) = v0019; /* !*sub2 */
    goto v0030;

v0030:
    v0019 = stack[-1];
    v0018 = qcar(v0019);
    v0019 = stack[0];
    popv(3);
    return cons(v0018, v0019);

v0051:
    v0019 = qvalue(elt(env, 2)); /* nil */
    goto v0001;
/* error exit handlers */
v0065:
    popv(3);
    return nil;
}



/* Code for anform */

static Lisp_Object CC_anform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform");
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
    v0093 = stack[0];
    if (!consp(v0093)) goto v0013;
    v0093 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* anform1 */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0013:
    v0093 = qvalue(elt(env, 1)); /* !*globals */
    if (v0093 == nil) goto v0003;
    v0093 = stack[0];
    if (v0093 == nil) goto v0003;
    v0094 = stack[0];
    v0093 = lisp_true;
    if (v0094 == v0093) goto v0065;
    v0093 = stack[0];
    if (symbolp(v0093)) goto v0056;
    v0093 = qvalue(elt(env, 2)); /* nil */
    goto v0009;

v0009:
    if (v0093 == nil) goto v0003;
    v0094 = stack[0];
    v0093 = elt(env, 4); /* glb2rf */
    v0093 = Lflagp(nil, v0094, v0093);
    env = stack[-1];
    if (v0093 == nil) goto v0032;
    v0093 = nil;
    { popv(2); return onevalue(v0093); }

v0032:
    v0093 = stack[0];
    v0094 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0093 = elt(env, 4); /* glb2rf */
    v0093 = Lflag(nil, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0094 = stack[0];
    v0093 = qvalue(elt(env, 5)); /* globs!* */
    v0093 = cons(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0093; /* globs!* */
    { popv(2); return onevalue(v0093); }

v0003:
    v0093 = nil;
    { popv(2); return onevalue(v0093); }

v0056:
    v0094 = stack[0];
    v0093 = qvalue(elt(env, 3)); /* locls!* */
    v0093 = Lassoc(nil, v0094, v0093);
    v0093 = (v0093 == nil ? lisp_true : nil);
    goto v0009;

v0065:
    v0093 = qvalue(elt(env, 2)); /* nil */
    goto v0009;
/* error exit handlers */
v0100:
    popv(2);
    return nil;
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reorder");
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
    goto v0005;

v0005:
    v0037 = stack[-1];
    if (!consp(v0037)) goto v0041;
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    v0037 = (consp(v0037) ? nil : lisp_true);
    goto v0040;

v0040:
    if (v0037 == nil) goto v0070;
    v0037 = stack[-1];
    v0066 = v0037;
    goto v0001;

v0001:
    v0037 = stack[-2];
    if (v0037 == nil) { popv(4); return onevalue(v0066); }
    v0037 = stack[-2];
    v0037 = qcar(v0037);
    fn = elt(env, 2); /* raddf */
    v0037 = (*qfn2(fn))(qenv(fn), v0037, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0066 = v0037;
    v0037 = stack[-2];
    v0037 = qcdr(v0037);
    stack[-2] = v0037;
    goto v0001;

v0070:
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    stack[0] = qcar(v0037);
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    v0037 = qcdr(v0037);
    v0037 = CC_reorder(env, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    fn = elt(env, 3); /* rmultpf */
    v0066 = (*qfn2(fn))(qenv(fn), stack[0], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0037 = stack[-2];
    v0037 = cons(v0066, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[-2] = v0037;
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0005;

v0041:
    v0037 = qvalue(elt(env, 1)); /* t */
    goto v0040;
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0029,
                         Lisp_Object v0053, Lisp_Object v0050, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0019, v0018, v0049, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0019 = v0050;
    v0018 = v0053;
    v0049 = v0029;
    v0071 = v0000;
/* end of prologue */
    v0043 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0043 == nil) goto v0052;
    v0043 = v0071;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0043, v0049, v0018, v0019);
    }

v0052:
    v0043 = v0071;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0043, v0049, v0018, v0019);
    }
}



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020, v0070, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for finde");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0031 = v0029;
    v0070 = v0000;
/* end of prologue */

v0034:
    v0021 = v0070;
    if (v0021 == nil) goto v0001;
    v0020 = v0031;
    v0021 = v0070;
    v0021 = qcar(v0021);
    v0021 = qcdr(v0021);
    v0021 = Lmemq(nil, v0020, v0021);
    if (!(v0021 == nil)) return onevalue(v0070);
    v0021 = v0070;
    v0021 = qcdr(v0021);
    v0070 = v0021;
    goto v0034;

v0001:
    v0021 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0021);
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0204, v0205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0029;
    stack[-4] = v0000;
/* end of prologue */

v0003:
    v0204 = stack[-4];
    v0203 = stack[-3];
    if (equal(v0204, v0203)) goto v0001;
    v0204 = stack[-4];
    v0203 = elt(env, 2); /* !*sq */
    if (!consp(v0204)) goto v0056;
    v0204 = qcar(v0204);
    if (!(v0204 == v0203)) goto v0056;
    v0203 = stack[-4];
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    fn = elt(env, 9); /* prepsqxx */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-4] = v0203;
    goto v0003;

v0056:
    v0204 = stack[-3];
    v0203 = elt(env, 2); /* !*sq */
    if (!consp(v0204)) goto v0012;
    v0204 = qcar(v0204);
    if (!(v0204 == v0203)) goto v0012;
    v0203 = stack[-3];
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    fn = elt(env, 9); /* prepsqxx */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-3] = v0203;
    goto v0003;

v0012:
    v0203 = stack[-3];
    if (!consp(v0203)) goto v0024;
    v0203 = stack[-4];
    if (!consp(v0203)) goto v0088;
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = elt(env, 6); /* difference */
    if (v0204 == v0203) goto v0112;
    v0203 = stack[-4];
    v0204 = qcar(v0203);
    v0203 = elt(env, 8); /* dname */
    v0203 = get(v0204, v0203);
    env = stack[-6];
    if (!(v0203 == nil)) goto v0105;
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = elt(env, 8); /* dname */
    v0203 = get(v0204, v0203);
    env = stack[-6];
    if (!(v0203 == nil)) goto v0105;
    v0203 = stack[-4];
    v0204 = qcar(v0203);
    v0203 = stack[-3];
    v0203 = qcar(v0203);
    if (v0204 == v0203) goto v0207;
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = qvalue(elt(env, 3)); /* frlis!* */
    v0203 = Lmemq(nil, v0204, v0203);
    if (v0203 == nil) goto v0208;
    v0203 = stack[-4];
    v0205 = qcar(v0203);
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = stack[-4];
    v0203 = qcdr(v0203);
    stack[0] = Lsubst(nil, 3, v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = stack[-4];
    v0205 = qcar(v0203);
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = stack[-3];
    v0203 = qcdr(v0203);
    v0204 = Lsubst(nil, 3, v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = stack[-4];
    v0203 = qcar(v0203);
    fn = elt(env, 10); /* mcharg */
    v0203 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-5] = v0203;
    v0203 = stack[-5];
    if (v0203 == nil) goto v0209;
    v0203 = stack[-5];
    v0203 = qcar(v0203);
    v0204 = stack[-3];
    v0205 = qcar(v0204);
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0203 = acons(v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = ncons(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-1] = v0203;
    stack[-2] = v0203;
    goto v0210;

v0210:
    v0203 = stack[-5];
    v0203 = qcdr(v0203);
    stack[-5] = v0203;
    v0203 = stack[-5];
    if (v0203 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0203 = stack[-5];
    v0203 = qcar(v0203);
    v0204 = stack[-3];
    v0205 = qcar(v0204);
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0203 = acons(v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = ncons(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = Lrplacd(nil, stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    stack[-1] = v0203;
    goto v0210;

v0209:
    v0203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0203); }

v0208:
    v0203 = stack[-4];
    v0204 = qcar(v0203);
    v0203 = elt(env, 4); /* minus */
    if (v0204 == v0203) goto v0211;
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = elt(env, 5); /* optional */
    v0203 = get(v0204, v0203);
    env = stack[-6];
    v0204 = v0203;
    if (v0204 == nil) goto v0212;
    v0205 = stack[-4];
    v0204 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0205, v0204, v0203);
    }

v0212:
    v0203 = nil;
    { popv(7); return onevalue(v0203); }

v0211:
    v0203 = stack[-4];
    v0203 = qcdr(v0203);
    v0204 = qcar(v0203);
    v0203 = stack[-3];
    {
        popv(7);
        fn = elt(env, 12); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v0204, v0203);
    }

v0207:
    v0203 = stack[-4];
    v0205 = qcdr(v0203);
    v0203 = stack[-3];
    v0204 = qcdr(v0203);
    v0203 = stack[-4];
    v0203 = qcar(v0203);
    {
        popv(7);
        fn = elt(env, 10); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v0205, v0204, v0203);
    }

v0105:
    v0203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0203); }

v0112:
    stack[-1] = elt(env, 7); /* plus */
    v0203 = stack[-3];
    v0203 = qcdr(v0203);
    stack[0] = qcar(v0203);
    v0204 = elt(env, 4); /* minus */
    v0203 = stack[-3];
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    v0203 = list2(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = list3(stack[-1], stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-3] = v0203;
    goto v0003;

v0088:
    v0203 = stack[-4];
    if (!(is_number(v0203))) goto v0119;
    v0204 = stack[-4];
    v0203 = (Lisp_Object)1; /* 0 */
    v0203 = (Lisp_Object)lessp2(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    v0203 = v0203 ? lisp_true : nil;
    env = stack[-6];
    if (v0203 == nil) goto v0119;
    v0204 = stack[-3];
    v0203 = elt(env, 4); /* minus */
    if (!consp(v0204)) goto v0119;
    v0204 = qcar(v0204);
    if (!(v0204 == v0203)) goto v0119;
    stack[0] = elt(env, 4); /* minus */
    v0203 = stack[-4];
    v0203 = negate(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = list2(stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-4] = v0203;
    goto v0003;

v0119:
    v0203 = stack[-3];
    v0204 = qcar(v0203);
    v0203 = elt(env, 5); /* optional */
    v0203 = get(v0204, v0203);
    env = stack[-6];
    v0204 = v0203;
    if (v0204 == nil) goto v0213;
    v0205 = stack[-4];
    v0204 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0205, v0204, v0203);
    }

v0213:
    v0203 = nil;
    { popv(7); return onevalue(v0203); }

v0024:
    v0204 = stack[-3];
    v0203 = qvalue(elt(env, 3)); /* frlis!* */
    v0203 = Lmemq(nil, v0204, v0203);
    if (v0203 == nil) goto v0061;
    v0204 = stack[-3];
    v0203 = stack[-4];
    v0203 = cons(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0203 = ncons(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    popv(7);
    return ncons(v0203);

v0061:
    v0203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0203); }

v0001:
    v0203 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v0203);
/* error exit handlers */
v0206:
    popv(7);
    return nil;
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0220, v0221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0029;
    stack[-3] = v0000;
/* end of prologue */
    v0220 = stack[-3];
    v0220 = qcar(v0220);
    if (v0220 == nil) goto v0002;
    v0220 = stack[-2];
    v0220 = qcar(v0220);
    v0220 = (v0220 == nil ? lisp_true : nil);
    goto v0001;

v0001:
    if (v0220 == nil) goto v0030;
    v0221 = qvalue(elt(env, 2)); /* nil */
    v0220 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0221, v0220);

v0030:
    v0220 = stack[-3];
    v0221 = qcdr(v0220);
    v0220 = (Lisp_Object)17; /* 1 */
    if (v0221 == v0220) goto v0019;
    v0220 = qvalue(elt(env, 2)); /* nil */
    goto v0020;

v0020:
    if (v0220 == nil) goto v0079;
    v0220 = stack[-3];
    v0221 = qcar(v0220);
    v0220 = stack[-2];
    v0220 = qcar(v0220);
    fn = elt(env, 3); /* multf */
    v0221 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0220 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0221, v0220);

v0079:
    v0220 = stack[-3];
    v0221 = qcar(v0220);
    v0220 = stack[-2];
    v0220 = qcdr(v0220);
    fn = elt(env, 4); /* gcdf */
    v0220 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    stack[-4] = v0220;
    v0220 = stack[-2];
    v0221 = qcar(v0220);
    v0220 = stack[-3];
    v0220 = qcdr(v0220);
    fn = elt(env, 4); /* gcdf */
    v0220 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    stack[-1] = v0220;
    v0220 = stack[-3];
    v0221 = qcar(v0220);
    v0220 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    v0220 = stack[-2];
    v0221 = qcar(v0220);
    v0220 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v0220 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v0220 = (*qfn2(fn))(qenv(fn), stack[0], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    stack[0] = v0220;
    v0220 = stack[-3];
    v0221 = qcdr(v0220);
    v0220 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    v0220 = stack[-2];
    v0221 = qcdr(v0220);
    v0220 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v0220 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v0220 = (*qfn2(fn))(qenv(fn), stack[-1], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    stack[-4] = v0220;
    v0221 = stack[0];
    v0220 = stack[-4];
    v0220 = cons(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0220);
    }

v0019:
    v0220 = stack[-2];
    v0221 = qcdr(v0220);
    v0220 = (Lisp_Object)17; /* 1 */
    v0220 = (v0221 == v0220 ? lisp_true : nil);
    goto v0020;

v0002:
    v0220 = qvalue(elt(env, 1)); /* t */
    goto v0001;
/* error exit handlers */
v0196:
    popv(6);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0070 = v0000;
/* end of prologue */

v0013:
    v0031 = v0070;
    if (!consp(v0031)) goto v0004;
    v0031 = v0070;
    v0031 = qcar(v0031);
    v0031 = (consp(v0031) ? nil : lisp_true);
    goto v0003;

v0003:
    if (!(v0031 == nil)) return onevalue(v0070);
    v0031 = v0070;
    v0031 = qcdr(v0031);
    if (v0031 == nil) goto v0015;
    v0070 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0070);

v0015:
    v0070 = qcar(v0070);
    v0070 = qcdr(v0070);
    goto v0013;

v0004:
    v0031 = qvalue(elt(env, 1)); /* t */
    goto v0003;
}



/* Code for qqe_rbopp */

static Lisp_Object CC_qqe_rbopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = elt(env, 1); /* (equal neq lessp leq geq greaterp) */
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



setup_type const u01_setup[] =
{
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"arraychk",                CC_arraychk,    too_many_1,    wrong_no_1},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"readch1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_readch1},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"monomcompare",            too_few_2,      CC_monomcompare,wrong_no_2},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"qqe_rqopp",               CC_qqe_rqopp,   too_many_1,    wrong_no_1},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"adjoin-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_adjoinKterm},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"xcomment",                too_few_2,      CC_xcomment,   wrong_no_2},
    {"monomgetvariabledegree",  too_few_2,      CC_monomgetvariabledegree,wrong_no_2},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"rl_smupdknowl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smupdknowl},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"prepf1a",                 too_few_2,      CC_prepf1a,    wrong_no_2},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"nil2zero",                CC_nil2zero,    too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"expdrmacro",              CC_expdrmacro,  too_many_1,    wrong_no_1},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"mri_floorkernelp",        CC_mri_floorkernelp,too_many_1,wrong_no_1},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"replus1",                 CC_replus1,     too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"anform",                  CC_anform,      too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u01", (two_args *)"22238 7946220 5378968", 0}
};

/* end of generated code */
