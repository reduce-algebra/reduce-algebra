
/* $destdir\u49.c        Machine generated C code */

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


/* Code for gcd!-in!-vector */

static Lisp_Object MS_CDECL CC_gcdKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0066, v0067, v0068, v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gcd-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0002;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0066 = stack[-2];
    v0065 = (Lisp_Object)1; /* 0 */
    if (v0066 == v0065) goto v0071;
    v0066 = stack[0];
    v0065 = (Lisp_Object)1; /* 0 */
    v0065 = (v0066 == v0065 ? lisp_true : nil);
    goto v0072;

v0072:
    if (v0065 == nil) goto v0073;
    v0067 = stack[-3];
    v0066 = (Lisp_Object)1; /* 0 */
    v0065 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0067 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL))) = v0065;
    v0065 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0065); }

v0073:
    v0066 = stack[-2];
    v0065 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0066)) < ((int32_t)(v0065))) goto v0074;
    v0066 = stack[0];
    v0065 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v0066)) < ((int32_t)(v0065)))) goto v0075;

v0074:
    v0065 = elt(env, 2); /* "GCD WITH ZERO NOT ALLOWED" */
    fn = elt(env, 4); /* errorf */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    goto v0075;

v0075:
    v0068 = stack[-3];
    v0067 = stack[-2];
    v0066 = stack[-1];
    v0065 = stack[0];
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0065 = (*qfnn(fn))(qenv(fn), 4, v0068, v0067, v0066, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-2] = v0065;
    v0066 = stack[-2];
    v0065 = (Lisp_Object)1; /* 0 */
    if (v0066 == v0065) goto v0077;
    v0066 = stack[-2];
    v0065 = (Lisp_Object)-15; /* -1 */
    if (v0066 == v0065) goto v0078;
    v0068 = stack[-1];
    v0067 = stack[0];
    v0066 = stack[-3];
    v0065 = stack[-2];
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0065 = (*qfnn(fn))(qenv(fn), 4, v0068, v0067, v0066, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[0] = v0065;
    v0066 = stack[0];
    v0065 = (Lisp_Object)1; /* 0 */
    if (v0066 == v0065) goto v0079;
    v0066 = stack[0];
    v0065 = (Lisp_Object)-15; /* -1 */
    if (!(v0066 == v0065)) goto v0075;
    v0066 = stack[-3];
    v0065 = stack[-2];
    v0065 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    v0065 = Lmodular_reciprocal(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    v0070 = v0065;
    v0066 = v0070;
    v0065 = (Lisp_Object)17; /* 1 */
    if (v0066 == v0065) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0065 = (Lisp_Object)1; /* 0 */
    v0069 = v0065;
    goto v0080;

v0080:
    v0066 = stack[-2];
    v0065 = v0069;
    v0065 = (Lisp_Object)(int32_t)((int32_t)v0066 - (int32_t)v0065 + TAG_FIXNUM);
    v0065 = ((intptr_t)(v0065) < 0 ? lisp_true : nil);
    if (!(v0065 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0068 = stack[-3];
    v0067 = v0069;
    v0066 = stack[-3];
    v0065 = v0069;
    v0066 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    v0065 = v0070;
    v0065 = Lmodular_times(nil, v0066, v0065);
    env = stack[-4];
    *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL))) = v0065;
    v0065 = v0069;
    v0065 = (Lisp_Object)((int32_t)(v0065) + 0x10);
    v0069 = v0065;
    goto v0080;

v0079:
    v0067 = stack[-3];
    v0066 = (Lisp_Object)1; /* 0 */
    v0065 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0067 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL))) = v0065;
    v0065 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0065); }

v0078:
    v0066 = stack[-1];
    v0065 = stack[0];
    v0065 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    v0065 = Lmodular_reciprocal(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    v0070 = v0065;
    v0065 = (Lisp_Object)1; /* 0 */
    v0069 = v0065;
    goto v0081;

v0081:
    v0066 = stack[0];
    v0065 = v0069;
    v0065 = (Lisp_Object)(int32_t)((int32_t)v0066 - (int32_t)v0065 + TAG_FIXNUM);
    v0065 = ((intptr_t)(v0065) < 0 ? lisp_true : nil);
    if (!(v0065 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0068 = stack[-3];
    v0067 = v0069;
    v0066 = stack[-1];
    v0065 = v0069;
    v0066 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    v0065 = v0070;
    v0065 = Lmodular_times(nil, v0066, v0065);
    env = stack[-4];
    *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL))) = v0065;
    v0065 = v0069;
    v0065 = (Lisp_Object)((int32_t)(v0065) + 0x10);
    v0069 = v0065;
    goto v0081;

v0077:
    v0067 = stack[-3];
    v0066 = (Lisp_Object)1; /* 0 */
    v0065 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0067 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL))) = v0065;
    v0065 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0065); }

v0071:
    v0065 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0076:
    popv(5);
    return nil;
}



/* Code for gcd!-with!-number */

static Lisp_Object CC_gcdKwithKnumber(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0047, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd-with-number");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0047 = v0000;
/* end of prologue */

v0072:
    v0077 = v0047;
    v0048 = (Lisp_Object)17; /* 1 */
    if (v0077 == v0048) goto v0092;
    v0048 = v0047;
    if (!consp(v0048)) goto v0062;
    v0048 = qvalue(elt(env, 1)); /* t */
    goto v0093;

v0093:
    if (v0048 == nil) goto v0094;
    v0048 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0048); }

v0094:
    v0048 = stack[0];
    if (!consp(v0048)) goto v0095;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = (consp(v0048) ? nil : lisp_true);
    goto v0057;

v0057:
    if (v0048 == nil) goto v0096;
    v0048 = stack[0];
    if (v0048 == nil) goto v0097;
    v0048 = stack[0];
    if (!consp(v0048)) goto v0098;
    v0048 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0048); }

v0098:
    v0048 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v0047, v0048);
    }

v0097:
    v0048 = v0047;
        popv(2);
        return Labsval(nil, v0048);

v0096:
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = qcdr(v0048);
    v0048 = CC_gcdKwithKnumber(env, v0047, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    v0047 = v0048;
    v0048 = stack[0];
    v0048 = qcdr(v0048);
    stack[0] = v0048;
    goto v0072;

v0095:
    v0048 = qvalue(elt(env, 1)); /* t */
    goto v0057;

v0062:
    v0077 = qvalue(elt(env, 2)); /* dmode!* */
    v0048 = elt(env, 3); /* field */
    v0048 = Lflagp(nil, v0077, v0048);
    env = stack[-1];
    goto v0093;

v0092:
    v0048 = qvalue(elt(env, 1)); /* t */
    goto v0093;
/* error exit handlers */
v0099:
    popv(2);
    return nil;
}



/* Code for put!-kvalue */

static Lisp_Object MS_CDECL CC_putKkvalue(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0112, v0113, v0114, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "put-kvalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-kvalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0002;
    stack[-3] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0112 = stack[-1];
    v0111 = elt(env, 1); /* !*sq */
    if (!consp(v0112)) goto v0073;
    v0112 = qcar(v0112);
    if (!(v0112 == v0111)) goto v0073;
    v0112 = stack[-2];
    v0111 = stack[-1];
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    fn = elt(env, 6); /* sf_member */
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    if (!(v0111 == nil)) goto v0086;
    v0112 = stack[-2];
    v0111 = stack[-1];
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    fn = elt(env, 6); /* sf_member */
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    goto v0086;

v0086:
    if (v0111 == nil) goto v0051;
    v0115 = qvalue(elt(env, 2)); /* nil */
    v0114 = stack[-2];
    v0113 = elt(env, 3); /* "improperly defined in terms of itself" */
    v0112 = qvalue(elt(env, 2)); /* nil */
    v0111 = qvalue(elt(env, 4)); /* t */
    {
        popv(6);
        fn = elt(env, 7); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0115, v0114, v0113, v0112, v0111);
    }

v0051:
    stack[-4] = stack[0];
    stack[0] = elt(env, 5); /* kvalue */
    v0112 = stack[-2];
    v0111 = stack[-1];
    v0111 = list2(v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0111 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0111 = Lnconc(nil, stack[-3], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    {
        Lisp_Object v0078 = stack[-4];
        Lisp_Object v0117 = stack[0];
        popv(6);
        return Lputprop(nil, 3, v0078, v0117, v0111);
    }

v0073:
    v0112 = stack[-2];
    v0111 = stack[-1];
    fn = elt(env, 8); /* smember */
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    goto v0086;
/* error exit handlers */
v0116:
    popv(6);
    return nil;
}



/* Code for test!-ideal */

static Lisp_Object CC_testKideal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0053, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for test-ideal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0123 = v0000;
/* end of prologue */
    v0053 = qvalue(elt(env, 1)); /* id!-vars!* */
    v0054 = elt(env, 2); /* list */
    if (!consp(v0053)) goto v0071;
    v0053 = qcar(v0053);
    if (!(v0053 == v0054)) goto v0071;
    v0053 = v0123;
    v0054 = elt(env, 2); /* list */
    if (!consp(v0053)) goto v0057;
    v0053 = qcar(v0053);
    if (!(v0053 == v0054)) goto v0057;
    v0054 = elt(env, 4); /* i */
    v0053 = v0123;
    v0053 = qcdr(v0053);
    return cons(v0054, v0053);

v0057:
    v0053 = v0123;
    v0054 = elt(env, 4); /* i */
    if (!consp(v0053)) goto v0124;
    v0053 = qcar(v0053);
    if (v0053 == v0054) return onevalue(v0123);
    else goto v0124;

v0124:
    v0053 = v0123;
    v0054 = elt(env, 5); /* "polynomial ideal" */
    {
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0053, v0054);
    }

v0071:
    v0053 = qvalue(elt(env, 1)); /* id!-vars!* */
    v0054 = elt(env, 3); /* "ideal setting; set variables first" */
    {
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0053, v0054);
    }
}



/* Code for setequal */

static Lisp_Object CC_setequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0127 = stack[-1];
    v0126 = stack[0];
    fn = elt(env, 2); /* subsetp */
    v0126 = (*qfn2(fn))(qenv(fn), v0127, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    if (v0126 == nil) goto v0009;
    v0127 = stack[0];
    v0126 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* subsetp */
        return (*qfn2(fn))(qenv(fn), v0127, v0126);
    }

v0009:
    v0126 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0126); }
/* error exit handlers */
v0109:
    popv(3);
    return nil;
}



/* Code for rand!-mons!-dense */

static Lisp_Object MS_CDECL CC_randKmonsKdense(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0184, v0185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rand-mons-dense");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-dense");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0002;
    stack[-11] = v0001;
    stack[-12] = v0000;
/* end of prologue */
    v0183 = stack[-12];
    v0183 = qcar(v0183);
    stack[-13] = v0183;
    v0183 = stack[-12];
    v0183 = qcdr(v0183);
    stack[-12] = v0183;
    v0183 = stack[-12];
    if (v0183 == nil) goto v0127;
    v0185 = stack[-12];
    v0184 = stack[-11];
    v0183 = stack[-10];
    stack[-9] = CC_randKmonsKdense(env, 3, v0185, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = (Lisp_Object)17; /* 1 */
    stack[-8] = v0183;
    goto v0031;

v0031:
    v0184 = stack[-11];
    v0183 = stack[-8];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lminusp(nil, v0183);
    env = stack[-14];
    if (v0183 == nil) goto v0187;
    v0183 = qvalue(elt(env, 1)); /* nil */
    goto v0188;

v0188:
    {
        Lisp_Object v0189 = stack[-9];
        popv(15);
        return Lappend(nil, v0189, v0183);
    }

v0187:
    v0184 = stack[-13];
    v0183 = stack[-8];
    fn = elt(env, 2); /* mksq */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = qcar(v0183);
    stack[-4] = v0183;
    stack[-2] = stack[-12];
    v0184 = stack[-11];
    v0183 = stack[-8];
    stack[-1] = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0184 = stack[-10];
    v0183 = stack[-8];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    fn = elt(env, 3); /* max */
    v0183 = (*qfn2(fn))(qenv(fn), stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = CC_randKmonsKdense(env, 3, stack[-2], stack[-1], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-3] = v0183;
    v0183 = stack[-3];
    if (v0183 == nil) goto v0190;
    v0183 = stack[-3];
    v0183 = qcar(v0183);
    v0184 = stack[-4];
    fn = elt(env, 4); /* multf */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-1] = v0183;
    stack[-2] = v0183;
    goto v0191;

v0191:
    v0183 = stack[-3];
    v0183 = qcdr(v0183);
    stack[-3] = v0183;
    v0183 = stack[-3];
    if (v0183 == nil) goto v0192;
    stack[0] = stack[-1];
    v0183 = stack[-3];
    v0183 = qcar(v0183);
    v0184 = stack[-4];
    fn = elt(env, 4); /* multf */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lrplacd(nil, stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    stack[-1] = v0183;
    goto v0191;

v0192:
    v0183 = stack[-2];
    goto v0193;

v0193:
    stack[-7] = v0183;
    v0183 = stack[-7];
    fn = elt(env, 5); /* lastpair */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-6] = v0183;
    v0183 = stack[-8];
    v0183 = add1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-8] = v0183;
    v0183 = stack[-6];
    if (!consp(v0183)) goto v0031;
    else goto v0194;

v0194:
    v0184 = stack[-11];
    v0183 = stack[-8];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lminusp(nil, v0183);
    env = stack[-14];
    if (v0183 == nil) goto v0008;
    v0183 = stack[-7];
    goto v0188;

v0008:
    stack[-5] = stack[-6];
    v0184 = stack[-13];
    v0183 = stack[-8];
    fn = elt(env, 2); /* mksq */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = qcar(v0183);
    stack[-4] = v0183;
    stack[-2] = stack[-12];
    v0184 = stack[-11];
    v0183 = stack[-8];
    stack[-1] = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0184 = stack[-10];
    v0183 = stack[-8];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    fn = elt(env, 3); /* max */
    v0183 = (*qfn2(fn))(qenv(fn), stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = CC_randKmonsKdense(env, 3, stack[-2], stack[-1], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-3] = v0183;
    v0183 = stack[-3];
    if (v0183 == nil) goto v0195;
    v0183 = stack[-3];
    v0183 = qcar(v0183);
    v0184 = stack[-4];
    fn = elt(env, 4); /* multf */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-1] = v0183;
    stack[-2] = v0183;
    goto v0196;

v0196:
    v0183 = stack[-3];
    v0183 = qcdr(v0183);
    stack[-3] = v0183;
    v0183 = stack[-3];
    if (v0183 == nil) goto v0197;
    stack[0] = stack[-1];
    v0183 = stack[-3];
    v0183 = qcar(v0183);
    v0184 = stack[-4];
    fn = elt(env, 4); /* multf */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lrplacd(nil, stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    stack[-1] = v0183;
    goto v0196;

v0197:
    v0183 = stack[-2];
    goto v0198;

v0198:
    v0183 = Lrplacd(nil, stack[-5], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = stack[-6];
    fn = elt(env, 5); /* lastpair */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-6] = v0183;
    v0183 = stack[-8];
    v0183 = add1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-8] = v0183;
    goto v0194;

v0195:
    v0183 = qvalue(elt(env, 1)); /* nil */
    goto v0198;

v0190:
    v0183 = qvalue(elt(env, 1)); /* nil */
    goto v0193;

v0127:
    v0184 = stack[-10];
    v0183 = (Lisp_Object)1; /* 0 */
    v0183 = (Lisp_Object)greaterp2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-14];
    if (v0183 == nil) goto v0059;
    v0184 = stack[-13];
    v0183 = stack[-10];
    fn = elt(env, 2); /* mksq */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = qcar(v0183);
    stack[-3] = v0183;
    goto v0090;

v0090:
    v0183 = stack[-10];
    v0183 = add1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-4] = v0183;
    v0184 = stack[-11];
    v0183 = stack[-4];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lminusp(nil, v0183);
    env = stack[-14];
    if (v0183 == nil) goto v0098;
    v0183 = qvalue(elt(env, 1)); /* nil */
    goto v0091;

v0091:
    {
        Lisp_Object v0199 = stack[-3];
        popv(15);
        return cons(v0199, v0183);
    }

v0098:
    v0184 = stack[-13];
    v0183 = stack[-4];
    fn = elt(env, 2); /* mksq */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = qcar(v0183);
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-1] = v0183;
    stack[-2] = v0183;
    goto v0200;

v0200:
    v0183 = stack[-4];
    v0183 = add1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    stack[-4] = v0183;
    v0184 = stack[-11];
    v0183 = stack[-4];
    v0183 = difference2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lminusp(nil, v0183);
    env = stack[-14];
    if (v0183 == nil) goto v0201;
    v0183 = stack[-2];
    goto v0091;

v0201:
    stack[0] = stack[-1];
    v0184 = stack[-13];
    v0183 = stack[-4];
    fn = elt(env, 2); /* mksq */
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = qcar(v0183);
    v0183 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = Lrplacd(nil, stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-14];
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    stack[-1] = v0183;
    goto v0200;

v0059:
    v0183 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0183;
    goto v0090;
/* error exit handlers */
v0186:
    popv(15);
    return nil;
}



/* Code for acmemb */

static Lisp_Object CC_acmemb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acmemb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0009:
    v0202 = stack[0];
    if (v0202 == nil) goto v0203;
    v0109 = stack[-1];
    v0202 = stack[0];
    v0202 = qcar(v0202);
    fn = elt(env, 2); /* aceq */
    v0202 = (*qfn2(fn))(qenv(fn), v0109, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    if (v0202 == nil) goto v0125;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    { popv(3); return onevalue(v0202); }

v0125:
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0009;

v0203:
    v0202 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0202); }
/* error exit handlers */
v0062:
    popv(3);
    return nil;
}



/* Code for coeff1_calc */

static Lisp_Object MS_CDECL CC_coeff1_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0074, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff1_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff1_calc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0002;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0204;

v0204:
    v0095 = stack[0];
    if (v0095 == nil) goto v0072;
    v0179 = stack[-2];
    v0074 = stack[-1];
    v0095 = stack[0];
    v0095 = qcar(v0095);
    fn = elt(env, 1); /* calc_coeffmap_ */
    v0074 = (*qfnn(fn))(qenv(fn), 3, v0179, v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0095 = stack[-3];
    v0095 = cons(v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-3] = v0095;
    v0095 = stack[0];
    v0095 = qcdr(v0095);
    stack[0] = v0095;
    goto v0204;

v0072:
    stack[0] = stack[-3];
    v0095 = (Lisp_Object)1; /* 0 */
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    {
        Lisp_Object v0205 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0205, v0095);
    }
/* error exit handlers */
v0124:
    popv(5);
    return nil;
}



/* Code for pst_equitable */

static Lisp_Object CC_pst_equitable(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_equitable");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0077 = v0000;
/* end of prologue */
    v0047 = v0077;
    v0047 = qcdr(v0047);
    if (v0047 == nil) { popv(4); return onevalue(v0077); }
    v0047 = v0077;
    v0047 = qcar(v0047);
    stack[-1] = v0047;
    v0047 = v0077;
    v0047 = qcdr(v0047);
    fn = elt(env, 1); /* pst_reduce */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    stack[-2] = v0047;
    stack[0] = stack[-2];
    v0077 = stack[-1];
    v0047 = stack[-2];
    v0047 = qcar(v0047);
    v0047 = Lappend(nil, v0077, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0047 = Lrplaca(nil, stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    goto v0207;

v0207:
    v0047 = stack[-2];
    v0047 = qcar(v0047);
    stack[-1] = v0047;
    stack[0] = stack[-1];
    v0077 = stack[-1];
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    fn = elt(env, 2); /* pst_equitable1 */
    v0047 = (*qfn2(fn))(qenv(fn), v0077, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0047 = cons(stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    stack[-2] = v0047;
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    fn = elt(env, 1); /* pst_reduce */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    stack[0] = v0047;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    if (v0047 == nil) goto v0208;
    v0077 = stack[-1];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0077 = Lappend(nil, v0077, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = cons(v0077, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    stack[-2] = v0047;
    goto v0208;

v0208:
    v0047 = stack[0];
    v0047 = qcar(v0047);
    stack[0] = v0047;
    v0047 = stack[0];
    if (v0047 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v0207;
/* error exit handlers */
v0201:
    popv(4);
    return nil;
}



/* Code for eval_uni_poly */

static Lisp_Object CC_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0113, v0114;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval_uni_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0112 = stack[-2];
    if (!consp(v0112)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0114 = v0112;
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0113 = v0112;
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    stack[-2] = v0112;
    goto v0126;

v0126:
    v0112 = stack[-2];
    if (!consp(v0112)) goto v0085;
    stack[-3] = v0114;
    stack[0] = stack[-1];
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0112 = difference2(v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0112 = Lexpt(nil, stack[0], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0113 = times2(stack[-3], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0112 = plus2(v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0114 = v0112;
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0113 = v0112;
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    stack[-2] = v0112;
    goto v0126;

v0085:
    stack[0] = v0114;
    v0112 = stack[-1];
    v0112 = Lexpt(nil, v0112, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0112 = times2(stack[0], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0114 = v0112;
    v0112 = stack[-2];
    if (v0112 == nil) { popv(5); return onevalue(v0114); }
    v0113 = v0114;
    v0112 = stack[-2];
    v0112 = plus2(v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0114 = v0112;
    { popv(5); return onevalue(v0114); }
/* error exit handlers */
v0043:
    popv(5);
    return nil;
}



/* Code for liqsimp1!-check */

static Lisp_Object MS_CDECL CC_liqsimp1Kcheck(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "liqsimp1-check");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liqsimp1-check");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v0059 = v0002;
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0057 = v0059;
    v0059 = elt(env, 1); /* min */
    if (v0057 == v0059) goto v0064;
    v0057 = stack[-1];
    v0059 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* liqsimp1!-check1 */
        return (*qfn2(fn))(qenv(fn), v0057, v0059);
    }

v0064:
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    fn = elt(env, 3); /* negf */
    v0057 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    v0057 = cons(v0057, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    v0059 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* liqsimp1!-check1 */
        return (*qfn2(fn))(qenv(fn), v0057, v0059);
    }
/* error exit handlers */
v0179:
    popv(3);
    return nil;
}



/* Code for co_get */

static Lisp_Object CC_co_get(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for co_get");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0000;
/* end of prologue */
    v0060 = qvalue(elt(env, 1)); /* !*rlqedfs */
    if (v0060 == nil) goto v0094;
    v0060 = v0072;
    {
        fn = elt(env, 2); /* co_pop */
        return (*qfn1(fn))(qenv(fn), v0060);
    }

v0094:
    v0060 = v0072;
    {
        fn = elt(env, 3); /* co_dequeue */
        return (*qfn1(fn))(qenv(fn), v0060);
    }
}



/* Code for put!-avalue */

static Lisp_Object MS_CDECL CC_putKavalue(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0216, v0035, v0036, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "put-avalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-avalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0002;
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0216 = stack[-2];
    v0215 = elt(env, 1); /* scalar */
    if (v0216 == v0215) goto v0087;
    v0216 = stack[0];
    v0215 = stack[-1];
    fn = elt(env, 9); /* smember */
    v0215 = (*qfn2(fn))(qenv(fn), v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    if (v0215 == nil) goto v0217;
    v0033 = qvalue(elt(env, 3)); /* nil */
    v0036 = stack[0];
    v0035 = elt(env, 4); /* "improperly defined in terms of itself" */
    v0216 = qvalue(elt(env, 3)); /* nil */
    v0215 = qvalue(elt(env, 5)); /* t */
    {
        popv(5);
        fn = elt(env, 10); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0033, v0036, v0035, v0216, v0215);
    }

v0217:
    stack[-3] = stack[0];
    stack[0] = elt(env, 8); /* avalue */
    v0216 = stack[-2];
    v0215 = stack[-1];
    v0215 = list2(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    {
        Lisp_Object v0157 = stack[-3];
        Lisp_Object v0193 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0157, v0193, v0215);
    }

v0087:
    v0216 = stack[-1];
    v0215 = elt(env, 2); /* !*sq */
    if (!consp(v0216)) goto v0097;
    v0216 = qcar(v0216);
    if (!(v0216 == v0215)) goto v0097;
    v0216 = stack[0];
    v0215 = stack[-1];
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    v0215 = qcar(v0215);
    fn = elt(env, 11); /* sf_member */
    v0215 = (*qfn2(fn))(qenv(fn), v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    if (!(v0215 == nil)) goto v0091;
    v0216 = stack[0];
    v0215 = stack[-1];
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    v0215 = qcdr(v0215);
    fn = elt(env, 11); /* sf_member */
    v0215 = (*qfn2(fn))(qenv(fn), v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    goto v0091;

v0091:
    if (v0215 == nil) goto v0218;
    v0033 = qvalue(elt(env, 3)); /* nil */
    v0036 = stack[0];
    v0035 = elt(env, 4); /* "improperly defined in terms of itself" */
    v0216 = qvalue(elt(env, 3)); /* nil */
    v0215 = qvalue(elt(env, 5)); /* t */
    {
        popv(5);
        fn = elt(env, 10); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0033, v0036, v0035, v0216, v0215);
    }

v0218:
    v0215 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v0215 == nil) goto v0099;
    v0035 = stack[0];
    v0216 = stack[-1];
    v0215 = elt(env, 7); /* generic */
    {
        popv(5);
        fn = elt(env, 12); /* putobject */
        return (*qfnn(fn))(qenv(fn), 3, v0035, v0216, v0215);
    }

v0099:
    stack[-3] = stack[0];
    stack[0] = elt(env, 8); /* avalue */
    v0216 = stack[-2];
    v0215 = stack[-1];
    v0215 = list2(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    {
        Lisp_Object v0191 = stack[-3];
        Lisp_Object v0219 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0191, v0219, v0215);
    }

v0097:
    v0215 = qvalue(elt(env, 3)); /* nil */
    goto v0091;
/* error exit handlers */
v0163:
    popv(5);
    return nil;
}



/* Code for rl_ex */

static Lisp_Object CC_rl_ex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0218, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0218 = v0001;
    v0090 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ex!* */
    v0218 = list2(v0090, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-1];
    {
        Lisp_Object v0064 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0064, v0218);
    }
/* error exit handlers */
v0107:
    popv(2);
    return nil;
}



/* Code for !*addsq */

static Lisp_Object CC_Haddsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *addsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    if (v0021 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0021 = stack[-2];
    v0021 = qcar(v0021);
    if (v0021 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0021 = stack[-3];
    v0170 = qcdr(v0021);
    v0021 = (Lisp_Object)17; /* 1 */
    if (v0170 == v0021) goto v0202;
    v0021 = qvalue(elt(env, 1)); /* nil */
    goto v0218;

v0218:
    if (v0021 == nil) goto v0103;
    v0021 = stack[-3];
    v0170 = qcar(v0021);
    v0021 = stack[-2];
    v0021 = qcar(v0021);
    fn = elt(env, 2); /* addf */
    v0170 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0021 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0170, v0021);

v0103:
    v0021 = stack[-3];
    v0170 = qcdr(v0021);
    stack[-4] = v0170;
    v0021 = stack[-2];
    v0021 = qcdr(v0021);
    stack[-1] = v0021;
    fn = elt(env, 3); /* gcdf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[0] = v0021;
    v0170 = stack[-4];
    v0021 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-4] = v0021;
    v0170 = stack[-1];
    v0021 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-1] = v0021;
    v0170 = stack[-1];
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    fn = elt(env, 5); /* !*multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0170 = stack[-4];
    v0021 = stack[-2];
    v0021 = qcar(v0021);
    fn = elt(env, 5); /* !*multf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    fn = elt(env, 2); /* addf */
    v0021 = (*qfn2(fn))(qenv(fn), stack[0], v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-2] = v0021;
    v0021 = stack[-2];
    if (v0021 == nil) goto v0237;
    v0021 = stack[-3];
    v0170 = qcdr(v0021);
    v0021 = stack[-1];
    fn = elt(env, 5); /* !*multf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-1] = v0021;
    v0021 = stack[-1];
    fn = elt(env, 6); /* minusf */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    if (v0021 == nil) goto v0238;
    v0021 = stack[-2];
    fn = elt(env, 7); /* negf */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-2] = v0021;
    v0021 = stack[-1];
    fn = elt(env, 7); /* negf */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[-1] = v0021;
    goto v0238;

v0238:
    v0170 = stack[-2];
    v0021 = stack[-1];
    fn = elt(env, 3); /* gcdf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    stack[0] = v0021;
    v0170 = stack[0];
    v0021 = (Lisp_Object)17; /* 1 */
    if (v0170 == v0021) goto v0191;
    v0170 = stack[-2];
    v0021 = stack[0];
    fn = elt(env, 4); /* quotf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-5];
    v0170 = stack[-1];
    v0021 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0021 = (*qfn2(fn))(qenv(fn), v0170, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    {
        Lisp_Object v0239 = stack[-2];
        popv(6);
        return cons(v0239, v0021);
    }

v0191:
    v0170 = stack[-2];
    v0021 = stack[-1];
    popv(6);
    return cons(v0170, v0021);

v0237:
    v0170 = qvalue(elt(env, 1)); /* nil */
    v0021 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0170, v0021);

v0202:
    v0021 = stack[-2];
    v0170 = qcdr(v0021);
    v0021 = (Lisp_Object)17; /* 1 */
    v0021 = (v0170 == v0021 ? lisp_true : nil);
    goto v0218;
/* error exit handlers */
v0236:
    popv(6);
    return nil;
}



/* Code for equal!+matrices!+p */

static Lisp_Object CC_equalLmatricesLp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0030, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equal+matrices+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0030 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 4); /* same!+dim!+squared!+p */
    v0032 = (*qfn2(fn))(qenv(fn), v0030, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    if (v0032 == nil) goto v0244;
    v0030 = (Lisp_Object)-15; /* -1 */
    v0032 = (Lisp_Object)17; /* 1 */
    v0030 = cons(v0030, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0032 = stack[0];
    fn = elt(env, 5); /* mk!+scal!+mult!+mat */
    v0032 = (*qfn2(fn))(qenv(fn), v0030, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 6); /* mk!+mat!+plus!+mat */
    v0032 = (*qfn2(fn))(qenv(fn), stack[-1], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    stack[0] = v0032;
    v0030 = qvalue(elt(env, 1)); /* nil */
    v0032 = (Lisp_Object)17; /* 1 */
    v0032 = cons(v0030, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0211 = v0032;
    v0032 = stack[0];
    stack[-3] = v0032;
    goto v0119;

v0119:
    v0032 = stack[-3];
    if (v0032 == nil) goto v0118;
    v0032 = stack[-3];
    v0032 = qcar(v0032);
    stack[-2] = v0032;
    goto v0106;

v0106:
    v0032 = stack[-2];
    if (v0032 == nil) goto v0105;
    v0032 = stack[-2];
    v0032 = qcar(v0032);
    v0030 = v0032;
    v0032 = qvalue(elt(env, 2)); /* !*complex */
    if (v0032 == nil) goto v0232;
    stack[-1] = v0211;
    stack[0] = v0030;
    v0032 = v0030;
    fn = elt(env, 7); /* mk!+conjugate!+sq */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 8); /* multsq */
    v0032 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 9); /* addsq */
    v0032 = (*qfn2(fn))(qenv(fn), stack[-1], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0211 = v0032;
    goto v0100;

v0100:
    v0032 = stack[-2];
    v0032 = qcdr(v0032);
    stack[-2] = v0032;
    goto v0106;

v0232:
    stack[0] = v0211;
    v0032 = v0030;
    fn = elt(env, 8); /* multsq */
    v0032 = (*qfn2(fn))(qenv(fn), v0032, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 9); /* addsq */
    v0032 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0211 = v0032;
    goto v0100;

v0105:
    v0032 = stack[-3];
    v0032 = qcdr(v0032);
    stack[-3] = v0032;
    goto v0119;

v0118:
    v0032 = v0211;
    fn = elt(env, 10); /* change!+sq!+to!+algnull */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0030 = v0032;
    v0032 = (Lisp_Object)1; /* 0 */
    if (v0030 == v0032) goto v0081;
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0032); }

v0081:
    v0032 = qvalue(elt(env, 3)); /* t */
    { popv(5); return onevalue(v0032); }

v0244:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0032); }
/* error exit handlers */
v0243:
    popv(5);
    return nil;
}



/* Code for pasf_premf1 */

static Lisp_Object CC_pasf_premf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0112, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_premf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0111 = stack[-3];
    if (!consp(v0111)) goto v0071;
    v0111 = stack[-3];
    v0111 = qcar(v0111);
    v0111 = (consp(v0111) ? nil : lisp_true);
    goto v0072;

v0072:
    if (v0111 == nil) goto v0058;
    v0111 = stack[-3];
    fn = elt(env, 2); /* minusf */
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    if (v0111 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0112 = stack[-3];
    v0111 = stack[-2];
    {
        popv(6);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v0112, v0111);
    }

v0058:
    v0111 = stack[-3];
    v0111 = qcar(v0111);
    v0112 = qcdr(v0111);
    v0111 = stack[-2];
    v0111 = CC_pasf_premf1(env, v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    stack[-4] = v0111;
    v0111 = stack[-3];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0113 = qcar(v0111);
    v0112 = (Lisp_Object)17; /* 1 */
    v0111 = (Lisp_Object)17; /* 1 */
    v0111 = acons(v0113, v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0111 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    stack[-1] = v0111;
    v0111 = stack[-3];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    stack[0] = v0111;
    v0111 = stack[-3];
    v0112 = qcdr(v0111);
    v0111 = stack[-2];
    v0111 = CC_pasf_premf1(env, v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    stack[-2] = v0111;
    stack[-3] = stack[-4];
    v0112 = stack[-1];
    v0111 = stack[0];
    fn = elt(env, 4); /* exptf */
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    fn = elt(env, 5); /* multf */
    v0112 = (*qfn2(fn))(qenv(fn), stack[-3], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0111 = stack[-2];
    {
        popv(6);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v0112, v0111);
    }

v0071:
    v0111 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0043:
    popv(6);
    return nil;
}



/* Code for qqe_prefix!-length */

static Lisp_Object CC_qqe_prefixKlength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0120, v0200;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_prefix-length");
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
    v0120 = v0000;
/* end of prologue */
    v0073 = (Lisp_Object)1; /* 0 */
    v0200 = v0073;
    v0073 = v0120;
    if (v0073 == nil) goto v0094;
    v0073 = v0120;
    stack[0] = v0073;
    goto v0090;

v0090:
    v0073 = stack[0];
    if (v0073 == nil) { popv(2); return onevalue(v0200); }
    v0073 = stack[0];
    if (!consp(v0073)) { popv(2); return onevalue(v0200); }
    v0073 = stack[0];
    v0120 = qcar(v0073);
    v0073 = elt(env, 2); /* (rtail ltail rhead lhead) */
    v0073 = Lmemq(nil, v0120, v0073);
    if (v0073 == nil) goto v0109;
    v0073 = v0200;
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-1];
    v0200 = v0073;
    goto v0109;

v0109:
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    stack[0] = v0073;
    goto v0090;

v0094:
    v0073 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0073;
    goto v0090;
/* error exit handlers */
v0205:
    popv(2);
    return nil;
}



/* Code for dip_f2dip1 */

static Lisp_Object MS_CDECL CC_dip_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0101, v0083, v0209, v0214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip_f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_f2dip1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0002;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0100 = stack[-2];
    if (v0100 == nil) goto v0242;
    v0100 = stack[-2];
    if (!consp(v0100)) goto v0072;
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    v0100 = (consp(v0100) ? nil : lisp_true);
    goto v0060;

v0060:
    if (v0100 == nil) goto v0178;
    v0100 = stack[-2];
    fn = elt(env, 3); /* bc_fd */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    fn = elt(env, 4); /* bc_prod */
    v0101 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0100 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* dip_fmon */
        return (*qfn2(fn))(qenv(fn), v0101, v0100);
    }

v0178:
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    v0214 = qcar(v0100);
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    v0209 = qcdr(v0100);
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    v0083 = qcdr(v0100);
    v0101 = stack[-1];
    v0100 = stack[0];
    fn = elt(env, 6); /* dip_f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v0214, v0209, v0083, v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0100 = stack[-2];
    v0083 = qcdr(v0100);
    v0101 = stack[-1];
    v0100 = stack[0];
    v0100 = CC_dip_f2dip1(env, 3, v0083, v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    {
        Lisp_Object v0241 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* dip_sum */
        return (*qfn2(fn))(qenv(fn), v0241, v0100);
    }

v0072:
    v0100 = qvalue(elt(env, 2)); /* t */
    goto v0060;

v0242:
    v0100 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0100); }
/* error exit handlers */
v0099:
    popv(5);
    return nil;
}



/* Code for ldf!-all!-var */

static Lisp_Object CC_ldfKallKvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-all-var");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0221 = stack[-1];
    fn = elt(env, 1); /* ldf!-dep!-var */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0221 = stack[-1];
    fn = elt(env, 2); /* ldf!-pow!-var */
    stack[0] = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0221 = stack[-1];
    fn = elt(env, 3); /* ldf!-spf!-var */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    fn = elt(env, 4); /* appends */
    v0221 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* makeset */
        return (*qfn1(fn))(qenv(fn), v0221);
    }
/* error exit handlers */
v0107:
    popv(4);
    return nil;
}



/* Code for subeval */

static Lisp_Object CC_subeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0240, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* sublist!* */
    qvalue(elt(env, 1)) = nil; /* sublist!* */
    v0082 = elt(env, 2); /* sub */
    v0240 = elt(env, 3); /* psopfn */
    v0206 = elt(env, 4); /* subeval0 */
    v0206 = Lputprop(nil, 3, v0082, v0240, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    stack[0] = elt(env, 4); /* subeval0 */
    v0206 = stack[-1];
    v0206 = Lmkquote(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0206 = list2(stack[0], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    stack[0] = v0206;
    v0082 = elt(env, 2); /* sub */
    v0240 = elt(env, 3); /* psopfn */
    v0206 = elt(env, 0); /* subeval */
    v0206 = Lputprop(nil, 3, v0082, v0240, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0206 = stack[0];
    if (!consp(v0206)) goto v0057;
    v0206 = stack[0];
    v0206 = qcdr(v0206);
    goto v0059;

v0059:
    if (v0206 == nil) goto v0089;
    v0206 = qvalue(elt(env, 6)); /* errmsg!* */
    if (v0206 == nil) goto v0075;
    v0206 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v0206 == nil)) goto v0208;
    v0206 = qvalue(elt(env, 6)); /* errmsg!* */
    fn = elt(env, 9); /* lprie */
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0208;

v0208:
    v0206 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0089;

v0089:
    v0206 = stack[0];
    v0206 = qcar(v0206);
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    { popv(4); return onevalue(v0206); }

v0075:
    v0206 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v0206 == nil)) goto v0106;
    v0206 = elt(env, 2); /* sub */
    fn = elt(env, 9); /* lprie */
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0106;

v0106:
    v0206 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0089;

v0057:
    v0206 = qvalue(elt(env, 5)); /* t */
    goto v0059;
/* error exit handlers */
v0209:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    popv(4);
    return nil;
}



/* Code for vdpenumerate */

static Lisp_Object CC_vdpenumerate(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0200, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpenumerate");
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
    v0120 = stack[0];
    if (v0120 == nil) goto v0203;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0120 = (v0120 == nil ? lisp_true : nil);
    goto v0204;

v0204:
    if (!(v0120 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0120 = stack[0];
    fn = elt(env, 4); /* vdpsave */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    stack[0] = v0120;
    v0200 = stack[0];
    v0120 = elt(env, 2); /* number */
    fn = elt(env, 5); /* vdpgetprop */
    v0120 = (*qfn2(fn))(qenv(fn), v0200, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    if (!(v0120 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0124 = stack[0];
    v0200 = elt(env, 2); /* number */
    v0120 = qvalue(elt(env, 3)); /* pcount!* */
    v0120 = (Lisp_Object)((int32_t)(v0120) + 0x10);
    qvalue(elt(env, 3)) = v0120; /* pcount!* */
    fn = elt(env, 6); /* vdpputprop */
    v0120 = (*qfnn(fn))(qenv(fn), 3, v0124, v0200, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    stack[0] = v0120;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0203:
    v0120 = qvalue(elt(env, 1)); /* t */
    goto v0204;
/* error exit handlers */
v0056:
    popv(2);
    return nil;
}



/* Code for cvt5 */

static Lisp_Object CC_cvt5(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvt5");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0125 = v0000;
/* end of prologue */
    v0126 = v0125;
    v0125 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 1); /* round!:mt */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    v0126 = stack[0];
    v0125 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 1); /* round!:mt */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    {
        Lisp_Object v0109 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v0109, v0125);
    }
/* error exit handlers */
v0202:
    popv(3);
    return nil;
}



/* Code for exp!: */

static Lisp_Object CC_expT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0303, v0304, v0305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0001;
    stack[-11] = v0000;
/* end of prologue */
    v0303 = stack[-10];
    v0303 = integerp(v0303);
    if (v0303 == nil) goto v0094;
    v0304 = stack[-10];
    v0303 = (Lisp_Object)1; /* 0 */
    v0303 = (Lisp_Object)lesseq2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    v0303 = v0303 ? lisp_true : nil;
    env = stack[-14];
    goto v0203;

v0203:
    if (v0303 == nil) goto v0108;
    stack[0] = (Lisp_Object)1; /* 0 */
    v0304 = elt(env, 2); /* "Invalid argument to" */
    v0303 = elt(env, 0); /* exp!: */
    v0303 = list2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    {
        Lisp_Object v0307 = stack[0];
        popv(15);
        fn = elt(env, 7); /* error */
        return (*qfn2(fn))(qenv(fn), v0307, v0303);
    }

v0108:
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    if (v0304 == v0303) goto v0089;
    stack[0] = elt(env, 4); /* !:rd!: */
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    v0303 = (Lisp_Object)greaterp2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    v0303 = v0303 ? lisp_true : nil;
    env = stack[-14];
    if (v0303 == nil) goto v0077;
    v0303 = stack[-11];
    goto v0085;

v0085:
    stack[-1] = v0303;
    v0304 = v0303;
    v0304 = qcdr(v0304);
    v0304 = qcar(v0304);
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0304 = Lash1(nil, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-9] = v0304;
    v0303 = (Lisp_Object)1; /* 0 */
    v0303 = list2star(stack[0], v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[0] = v0303;
    v0304 = stack[-1];
    v0303 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-2] = stack[-10];
    v0303 = stack[-9];
    fn = elt(env, 9); /* msd */
    v0304 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = (Lisp_Object)113; /* 7 */
    v0303 = plus2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = plus2(stack[-2], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-12] = v0303;
    v0304 = stack[-1];
    v0303 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-8] = v0303;
    v0303 = stack[0];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    if (v0304 == v0303) goto v0243;
    v0303 = stack[-12];
    stack[0] = qvalue(elt(env, 5)); /* !:bprec!: */
    qvalue(elt(env, 5)) = v0303; /* !:bprec!: */
    v0303 = stack[-12];
    fn = elt(env, 10); /* !:e */
    v0304 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-14];
    v0303 = stack[-9];
    fn = elt(env, 11); /* texpt!: */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-14];
    stack[-7] = v0303;
    qvalue(elt(env, 5)) = stack[0]; /* !:bprec!: */
    goto v0309;

v0309:
    v0303 = stack[-8];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    if (v0304 == v0303) goto v0310;
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v0303 = stack[-12];
    v0303 = negate(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = list2star(stack[-1], stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-4] = v0303;
    v0303 = qvalue(elt(env, 3)); /* bfone!* */
    stack[0] = v0303;
    stack[-2] = v0303;
    stack[-6] = v0303;
    v0303 = (Lisp_Object)17; /* 1 */
    stack[-9] = v0303;
    v0303 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0303;
    goto v0311;

v0311:
    v0304 = stack[0];
    v0303 = stack[-4];
    fn = elt(env, 12); /* greaterp!: */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    if (v0303 == nil) goto v0312;
    stack[0] = elt(env, 4); /* !:rd!: */
    stack[-1] = stack[-9];
    v0303 = stack[-5];
    v0303 = add1(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-5] = v0303;
    v0304 = times2(stack[-1], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-9] = v0304;
    v0303 = (Lisp_Object)1; /* 0 */
    v0303 = list2star(stack[0], v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-3] = v0303;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = stack[-8];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    stack[0] = times2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0304 = qcdr(v0303);
    v0303 = stack[-8];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = plus2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[0] = list2star(stack[-1], stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-12];
    v0303 = negate(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 13); /* cut!:ep */
    v0303 = (*qfn2(fn))(qenv(fn), stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-2] = v0303;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[-13] = stack[-12];
    v0303 = stack[-3];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    if (v0304 == v0303) goto v0146;
    v0303 = stack[-3];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    v0303 = Labsval(nil, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-3];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = sub1(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = plus2(stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    goto v0313;

v0313:
    stack[-13] = difference2(stack[-13], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    if (v0304 == v0303) goto v0197;
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    v0303 = Labsval(nil, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = sub1(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = plus2(stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    goto v0314;

v0314:
    v0303 = plus2(stack[-13], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 14); /* max */
    v0303 = (*qfn2(fn))(qenv(fn), stack[-1], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0305 = stack[-2];
    v0304 = stack[-3];
    fn = elt(env, 15); /* divide!: */
    v0303 = (*qfnn(fn))(qenv(fn), 3, v0305, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[0] = v0303;
    v0304 = stack[-6];
    v0303 = stack[0];
    fn = elt(env, 16); /* plus!: */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-6] = v0303;
    v0304 = stack[-5];
    v0303 = (Lisp_Object)161; /* 10 */
    v0304 = Cremainder(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = (Lisp_Object)1; /* 0 */
    if (!(v0304 == v0303)) goto v0311;
    stack[-1] = stack[-6];
    v0303 = stack[-12];
    v0303 = negate(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 13); /* cut!:ep */
    v0303 = (*qfn2(fn))(qenv(fn), stack[-1], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-6] = v0303;
    goto v0311;

v0197:
    v0303 = (Lisp_Object)1; /* 0 */
    goto v0314;

v0146:
    v0303 = (Lisp_Object)1; /* 0 */
    goto v0313;

v0312:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v0303 = stack[-7];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = stack[-6];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    stack[0] = times2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-7];
    v0303 = qcdr(v0303);
    v0304 = qcdr(v0303);
    v0303 = stack[-6];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = plus2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[0] = list2star(stack[-1], stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-10];
    v0303 = add1(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    fn = elt(env, 17); /* cut!:mt */
    v0303 = (*qfn2(fn))(qenv(fn), stack[0], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    stack[-1] = v0303;
    v0304 = stack[-11];
    v0303 = elt(env, 4); /* !:rd!: */
    if (!consp(v0304)) goto v0315;
    v0304 = qcar(v0304);
    if (!(v0304 == v0303)) goto v0315;
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0303 = (consp(v0303) ? nil : lisp_true);
    v0303 = (v0303 == nil ? lisp_true : nil);
    goto v0316;

v0316:
    if (v0303 == nil) goto v0317;
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = (Lisp_Object)1; /* 0 */
    v0303 = (Lisp_Object)lessp2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    v0303 = v0303 ? lisp_true : nil;
    env = stack[-14];
    goto v0318;

v0318:
    if (v0303 == nil) goto v0319;
    v0305 = qvalue(elt(env, 3)); /* bfone!* */
    v0304 = stack[-1];
    v0303 = stack[-10];
    {
        popv(15);
        fn = elt(env, 15); /* divide!: */
        return (*qfnn(fn))(qenv(fn), 3, v0305, v0304, v0303);
    }

v0319:
    v0304 = stack[-1];
    v0303 = stack[-10];
    {
        popv(15);
        fn = elt(env, 18); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0304, v0303);
    }

v0317:
    v0303 = qvalue(elt(env, 6)); /* nil */
    goto v0318;

v0315:
    v0303 = qvalue(elt(env, 6)); /* nil */
    goto v0316;

v0310:
    v0303 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-6] = v0303;
    goto v0312;

v0243:
    v0303 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-7] = v0303;
    goto v0309;

v0077:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    v0304 = negate(v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    v0303 = stack[-11];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = list2star(stack[-1], v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-14];
    goto v0085;

v0089:
    v0303 = qvalue(elt(env, 3)); /* bfone!* */
    { popv(15); return onevalue(v0303); }

v0094:
    v0303 = qvalue(elt(env, 1)); /* t */
    goto v0203;
/* error exit handlers */
v0308:
    env = stack[-14];
    qvalue(elt(env, 5)) = stack[0]; /* !:bprec!: */
    popv(15);
    return nil;
v0306:
    popv(15);
    return nil;
}



/* Code for declared!-as!-float */

static Lisp_Object CC_declaredKasKfloat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for declared-as-float");
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
    v0109 = v0000;
/* end of prologue */
    v0122 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* symtabget */
    v0109 = (*qfn2(fn))(qenv(fn), v0122, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[0];
    v0122 = v0109;
    if (v0109 == nil) goto v0204;
    v0109 = v0122;
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    v0122 = elt(env, 2); /* (real real!*8 real!*16 double! precision double float) 
*/
    v0109 = Lmemq(nil, v0109, v0122);
    { popv(1); return onevalue(v0109); }

v0204:
    v0109 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0109); }
/* error exit handlers */
v0061:
    popv(1);
    return nil;
}



/* Code for gcdlist */

static Lisp_Object CC_gcdlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0389, v0390, v0391;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdlist");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0389 = stack[0];
    if (v0389 == nil) goto v0154;
    v0389 = stack[0];
    v0389 = qcdr(v0389);
    if (v0389 == nil) goto v0203;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    if (!consp(v0389)) goto v0090;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    v0389 = qcar(v0389);
    v0389 = (consp(v0389) ? nil : lisp_true);
    goto v0218;

v0218:
    if (v0389 == nil) goto v0121;
    v0389 = stack[0];
    v0390 = qcdr(v0389);
    v0389 = stack[0];
    v0389 = qcar(v0389);
    {
        popv(15);
        fn = elt(env, 4); /* gcdld */
        return (*qfn2(fn))(qenv(fn), v0390, v0389);
    }

v0121:
    stack[-1] = nil;
    goto v0073;

v0073:
    v0389 = stack[0];
    if (v0389 == nil) goto v0178;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    if (v0389 == nil) goto v0119;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    if (!consp(v0389)) goto v0103;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    v0389 = qcar(v0389);
    v0389 = (consp(v0389) ? nil : lisp_true);
    goto v0075;

v0075:
    if (v0389 == nil) goto v0113;
    v0389 = stack[0];
    stack[-2] = qcdr(v0389);
    v0389 = stack[-1];
    fn = elt(env, 5); /* mapcarcar */
    v0390 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[0];
    v0389 = qcar(v0389);
    fn = elt(env, 4); /* gcdld */
    v0389 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    fn = elt(env, 4); /* gcdld */
    v0389 = (*qfn2(fn))(qenv(fn), stack[-2], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-1] = v0389;
    v0389 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0389;
    goto v0073;

v0113:
    v0389 = stack[0];
    stack[-2] = qcar(v0389);
    v0389 = stack[0];
    v0389 = qcar(v0389);
    fn = elt(env, 6); /* powers1 */
    v0390 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-1];
    v0389 = acons(stack[-2], v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-1] = v0389;
    v0389 = stack[0];
    v0389 = qcdr(v0389);
    stack[0] = v0389;
    goto v0073;

v0103:
    v0389 = qvalue(elt(env, 2)); /* t */
    goto v0075;

v0119:
    v0389 = stack[0];
    v0389 = qcdr(v0389);
    stack[0] = v0389;
    goto v0073;

v0178:
    v0389 = stack[-1];
    if (v0389 == nil) goto v0037;
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    if (v0389 == nil) goto v0393;
    v0389 = qvalue(elt(env, 1)); /* nil */
    stack[-13] = v0389;
    v0389 = qvalue(elt(env, 1)); /* nil */
    stack[-12] = v0389;
    v0389 = stack[-1];
    stack[-11] = v0389;
    v0389 = stack[-11];
    if (v0389 == nil) goto v0244;
    v0389 = stack[-11];
    v0389 = qcar(v0389);
    stack[-7] = v0389;
    stack[-6] = nil;
    v0389 = stack[-7];
    v0389 = qcdr(v0389);
    stack[-5] = v0389;
    v0389 = stack[-5];
    if (v0389 == nil) goto v0163;
    v0389 = stack[-5];
    v0389 = qcar(v0389);
    stack[-1] = v0389;
    v0389 = stack[-1];
    v0391 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcdr(v0389);
    v0389 = stack[-6];
    v0389 = acons(v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-6] = v0389;
    v0389 = stack[-1];
    stack[0] = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0389 = qcdr(v0389);
    v0389 = difference2(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = cons(stack[0], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-3] = v0389;
    stack[-4] = v0389;
    goto v0033;

v0033:
    v0389 = stack[-5];
    v0389 = qcdr(v0389);
    stack[-5] = v0389;
    v0389 = stack[-5];
    if (v0389 == nil) goto v0394;
    stack[-2] = stack[-3];
    v0389 = stack[-5];
    v0389 = qcar(v0389);
    stack[-1] = v0389;
    v0389 = stack[-1];
    v0391 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcdr(v0389);
    v0389 = stack[-6];
    v0389 = acons(v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-6] = v0389;
    v0389 = stack[-1];
    stack[0] = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0389 = qcdr(v0389);
    v0389 = difference2(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = cons(stack[0], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = Lrplacd(nil, stack[-2], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-3];
    v0389 = qcdr(v0389);
    stack[-3] = v0389;
    goto v0033;

v0394:
    v0389 = stack[-4];
    goto v0036;

v0036:
    stack[-1] = v0389;
    v0389 = stack[-7];
    v0389 = qcar(v0389);
    fn = elt(env, 7); /* numeric!-content */
    v0389 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-2] = v0389;
    v0389 = stack[-12];
    if (v0389 == nil) goto v0395;
    v0390 = stack[-13];
    v0389 = stack[-6];
    fn = elt(env, 8); /* vintersection */
    v0389 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-13] = v0389;
    v0390 = stack[-12];
    v0389 = stack[-2];
    fn = elt(env, 9); /* gcddd */
    v0389 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-12] = v0389;
    goto v0396;

v0396:
    v0389 = stack[-6];
    stack[-3] = v0389;
    goto v0196;

v0196:
    v0389 = stack[-3];
    if (v0389 == nil) goto v0397;
    v0389 = stack[-3];
    v0389 = qcar(v0389);
    stack[0] = v0389;
    v0389 = stack[0];
    v0390 = qcdr(v0389);
    v0389 = (Lisp_Object)1; /* 0 */
    if (v0390 == v0389) goto v0398;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    fn = elt(env, 10); /* fkern */
    v0390 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[0];
    v0389 = qcdr(v0389);
    fn = elt(env, 11); /* getpower */
    v0390 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = (Lisp_Object)17; /* 1 */
    v0389 = cons(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    fn = elt(env, 12); /* multf */
    v0389 = (*qfn2(fn))(qenv(fn), stack[-2], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-2] = v0389;
    goto v0398;

v0398:
    v0389 = stack[-3];
    v0389 = qcdr(v0389);
    stack[-3] = v0389;
    goto v0196;

v0397:
    v0389 = stack[-7];
    v0391 = qcar(v0389);
    v0390 = stack[-2];
    v0389 = elt(env, 3); /* "Term content division failed" */
    fn = elt(env, 13); /* quotfail1 */
    v0390 = (*qfnn(fn))(qenv(fn), 3, v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-1];
    v0389 = cons(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-9] = v0389;
    stack[-10] = v0389;
    goto v0399;

v0399:
    v0389 = stack[-11];
    v0389 = qcdr(v0389);
    stack[-11] = v0389;
    v0389 = stack[-11];
    if (v0389 == nil) goto v0400;
    stack[-8] = stack[-9];
    v0389 = stack[-11];
    v0389 = qcar(v0389);
    stack[-7] = v0389;
    stack[-6] = nil;
    v0389 = stack[-7];
    v0389 = qcdr(v0389);
    stack[-5] = v0389;
    v0389 = stack[-5];
    if (v0389 == nil) goto v0401;
    v0389 = stack[-5];
    v0389 = qcar(v0389);
    stack[-1] = v0389;
    v0389 = stack[-1];
    v0391 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcdr(v0389);
    v0389 = stack[-6];
    v0389 = acons(v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-6] = v0389;
    v0389 = stack[-1];
    stack[0] = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0389 = qcdr(v0389);
    v0389 = difference2(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = cons(stack[0], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-3] = v0389;
    stack[-4] = v0389;
    goto v0402;

v0402:
    v0389 = stack[-5];
    v0389 = qcdr(v0389);
    stack[-5] = v0389;
    v0389 = stack[-5];
    if (v0389 == nil) goto v0403;
    stack[-2] = stack[-3];
    v0389 = stack[-5];
    v0389 = qcar(v0389);
    stack[-1] = v0389;
    v0389 = stack[-1];
    v0391 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcdr(v0389);
    v0389 = stack[-6];
    v0389 = acons(v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-6] = v0389;
    v0389 = stack[-1];
    stack[0] = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0390 = qcar(v0389);
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    v0389 = qcdr(v0389);
    v0389 = difference2(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = cons(stack[0], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = Lrplacd(nil, stack[-2], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-3];
    v0389 = qcdr(v0389);
    stack[-3] = v0389;
    goto v0402;

v0403:
    v0389 = stack[-4];
    goto v0404;

v0404:
    stack[-1] = v0389;
    v0389 = stack[-7];
    v0389 = qcar(v0389);
    fn = elt(env, 7); /* numeric!-content */
    v0389 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-2] = v0389;
    v0389 = stack[-12];
    if (v0389 == nil) goto v0251;
    v0390 = stack[-13];
    v0389 = stack[-6];
    fn = elt(env, 8); /* vintersection */
    v0389 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-13] = v0389;
    v0390 = stack[-12];
    v0389 = stack[-2];
    fn = elt(env, 9); /* gcddd */
    v0389 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-12] = v0389;
    goto v0405;

v0405:
    v0389 = stack[-6];
    stack[-3] = v0389;
    goto v0303;

v0303:
    v0389 = stack[-3];
    if (v0389 == nil) goto v0406;
    v0389 = stack[-3];
    v0389 = qcar(v0389);
    stack[0] = v0389;
    v0389 = stack[0];
    v0390 = qcdr(v0389);
    v0389 = (Lisp_Object)1; /* 0 */
    if (v0390 == v0389) goto v0407;
    v0389 = stack[0];
    v0389 = qcar(v0389);
    fn = elt(env, 10); /* fkern */
    v0390 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[0];
    v0389 = qcdr(v0389);
    fn = elt(env, 11); /* getpower */
    v0390 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = (Lisp_Object)17; /* 1 */
    v0389 = cons(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    fn = elt(env, 12); /* multf */
    v0389 = (*qfn2(fn))(qenv(fn), stack[-2], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-2] = v0389;
    goto v0407;

v0407:
    v0389 = stack[-3];
    v0389 = qcdr(v0389);
    stack[-3] = v0389;
    goto v0303;

v0406:
    v0389 = stack[-7];
    v0391 = qcar(v0389);
    v0390 = stack[-2];
    v0389 = elt(env, 3); /* "Term content division failed" */
    fn = elt(env, 13); /* quotfail1 */
    v0390 = (*qfnn(fn))(qenv(fn), 3, v0391, v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-1];
    v0389 = cons(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = Lrplacd(nil, stack[-8], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-9];
    v0389 = qcdr(v0389);
    stack[-9] = v0389;
    goto v0399;

v0251:
    v0389 = stack[-6];
    stack[-13] = v0389;
    v0389 = stack[-2];
    stack[-12] = v0389;
    goto v0405;

v0401:
    v0389 = qvalue(elt(env, 1)); /* nil */
    goto v0404;

v0400:
    v0389 = stack[-10];
    goto v0227;

v0227:
    stack[0] = v0389;
    v0389 = stack[-13];
    stack[-2] = v0389;
    goto v0408;

v0408:
    v0389 = stack[-2];
    if (v0389 == nil) goto v0409;
    v0389 = stack[-2];
    v0389 = qcar(v0389);
    stack[-1] = v0389;
    stack[-3] = stack[-12];
    v0389 = stack[-1];
    v0389 = qcar(v0389);
    fn = elt(env, 10); /* fkern */
    v0390 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = stack[-1];
    v0389 = qcdr(v0389);
    fn = elt(env, 11); /* getpower */
    v0390 = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = (Lisp_Object)17; /* 1 */
    v0389 = cons(v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    v0389 = ncons(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    fn = elt(env, 12); /* multf */
    v0389 = (*qfn2(fn))(qenv(fn), stack[-3], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    stack[-12] = v0389;
    v0389 = stack[-2];
    v0389 = qcdr(v0389);
    stack[-2] = v0389;
    goto v0408;

v0409:
    stack[-1] = stack[-12];
    v0389 = stack[0];
    fn = elt(env, 14); /* gcdlist1 */
    v0389 = (*qfn1(fn))(qenv(fn), v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    fn = elt(env, 12); /* multf */
    v0389 = (*qfn2(fn))(qenv(fn), stack[-1], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-14];
    {
        popv(15);
        fn = elt(env, 15); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0389);
    }

v0395:
    v0389 = stack[-6];
    stack[-13] = v0389;
    v0389 = stack[-2];
    stack[-12] = v0389;
    goto v0396;

v0163:
    v0389 = qvalue(elt(env, 1)); /* nil */
    goto v0036;

v0244:
    v0389 = qvalue(elt(env, 1)); /* nil */
    goto v0227;

v0393:
    v0389 = stack[-1];
    v0389 = qcar(v0389);
    v0389 = qcar(v0389);
    {
        popv(15);
        fn = elt(env, 15); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0389);
    }

v0037:
    v0389 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v0389); }

v0090:
    v0389 = qvalue(elt(env, 2)); /* t */
    goto v0218;

v0203:
    v0389 = stack[0];
    v0389 = qcar(v0389);
    {
        popv(15);
        fn = elt(env, 15); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0389);
    }

v0154:
    v0389 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v0389); }
/* error exit handlers */
v0392:
    popv(15);
    return nil;
}



/* Code for physopsubs */

static Lisp_Object CC_physopsubs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0176, v0130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsubs");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0175 = qvalue(elt(env, 2)); /* nil */
    v0175 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0175; /* alglist!* */
    v0175 = stack[-1];
    fn = elt(env, 12); /* physop2sq */
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[-1] = v0175;
    v0175 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v0175;
    goto v0072;

v0072:
    v0175 = stack[0];
    if (v0175 == nil) goto v0179;
    v0175 = stack[0];
    v0175 = qcar(v0175);
    v0130 = v0175;
    v0176 = v0130;
    v0175 = elt(env, 4); /* rtype */
    v0175 = Lremprop(nil, v0176, v0175);
    env = stack[-3];
    v0176 = elt(env, 5); /* simpfn */
    v0175 = elt(env, 6); /* simpiden */
    v0175 = Lputprop(nil, 3, v0130, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    stack[0] = v0175;
    goto v0072;

v0179:
    v0176 = elt(env, 7); /* (dot) */
    v0175 = elt(env, 8); /* physopfn */
    v0175 = Lremflag(nil, v0176, v0175);
    env = stack[-3];
    v0130 = elt(env, 9); /* dot */
    v0176 = elt(env, 5); /* simpfn */
    v0175 = elt(env, 6); /* simpiden */
    v0175 = Lputprop(nil, 3, v0130, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0175 = stack[-1];
    fn = elt(env, 13); /* subs2 */
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[-1] = v0175;
    v0175 = qvalue(elt(env, 10)); /* !*nosq */
    if (v0175 == nil) goto v0104;
    v0175 = stack[-1];
    fn = elt(env, 14); /* prepsqxx */
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    goto v0103;

v0103:
    stack[-1] = v0175;
    v0175 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v0175;
    goto v0206;

v0206:
    v0175 = stack[0];
    if (v0175 == nil) goto v0230;
    v0175 = stack[0];
    v0175 = qcar(v0175);
    v0130 = v0175;
    v0176 = v0130;
    v0175 = elt(env, 5); /* simpfn */
    v0175 = Lremprop(nil, v0176, v0175);
    env = stack[-3];
    v0176 = elt(env, 4); /* rtype */
    v0175 = elt(env, 11); /* physop */
    v0175 = Lputprop(nil, 3, v0130, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    stack[0] = v0175;
    goto v0206;

v0230:
    v0176 = elt(env, 9); /* dot */
    v0175 = elt(env, 5); /* simpfn */
    v0175 = Lremprop(nil, v0176, v0175);
    env = stack[-3];
    v0176 = elt(env, 7); /* (dot) */
    v0175 = elt(env, 8); /* physopfn */
    v0175 = Lflag(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0175 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    { popv(4); return onevalue(v0175); }

v0104:
    v0175 = stack[-1];
    fn = elt(env, 15); /* mk!*sq */
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    goto v0103;
/* error exit handlers */
v0213:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for permp!: */

static Lisp_Object CC_permpT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0205, v0056, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0205 = v0001;
    v0056 = v0000;
/* end of prologue */

v0009:
    v0124 = v0056;
    if (v0124 == nil) goto v0203;
    v0124 = v0056;
    v0055 = qcar(v0124);
    v0124 = v0205;
    v0124 = qcar(v0124);
    if (equal(v0055, v0124)) goto v0092;
    v0124 = v0056;
    stack[0] = qcdr(v0124);
    v0124 = v0205;
    v0124 = qcar(v0124);
    v0056 = qcar(v0056);
    v0205 = qcdr(v0205);
    v0124 = Lsubst(nil, 3, v0124, v0056, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    v0124 = CC_permpT(env, stack[0], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0124 = (v0124 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0124); }

v0092:
    v0124 = v0056;
    v0124 = qcdr(v0124);
    v0056 = v0124;
    v0124 = v0205;
    v0124 = qcdr(v0124);
    v0205 = v0124;
    goto v0009;

v0203:
    v0124 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0124); }
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for constant_exprp */

static Lisp_Object CC_constant_exprp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0412, v0413;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constant_exprp");
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
    v0412 = v0000;
/* end of prologue */
    v0244 = v0412;
    if (!consp(v0244)) goto v0154;
    v0244 = v0412;
    v0413 = qcar(v0244);
    v0244 = elt(env, 6); /* realvalued */
    v0244 = Lflagp(nil, v0413, v0244);
    env = stack[0];
    if (v0244 == nil) goto v0051;
    v0244 = qvalue(elt(env, 2)); /* t */
    goto v0097;

v0097:
    if (v0244 == nil) goto v0205;
    v0244 = v0412;
    v0244 = qcdr(v0244);
    if (!consp(v0244)) goto v0217;
    v0244 = v0412;
    v0244 = qcdr(v0244);
    {
        popv(1);
        fn = elt(env, 12); /* constant_expr_listp */
        return (*qfn1(fn))(qenv(fn), v0244);
    }

v0217:
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0244); }

v0205:
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0244); }

v0051:
    v0244 = v0412;
    v0413 = qcar(v0244);
    v0244 = elt(env, 7); /* alwaysrealvalued */
    v0244 = Lflagp(nil, v0413, v0244);
    env = stack[0];
    if (v0244 == nil) goto v0047;
    v0244 = qvalue(elt(env, 2)); /* t */
    goto v0097;

v0047:
    v0244 = v0412;
    v0413 = qcar(v0244);
    v0244 = elt(env, 8); /* (plus minus difference times quotient) */
    v0244 = Lmemq(nil, v0413, v0244);
    if (!(v0244 == nil)) goto v0097;
    v0244 = v0412;
    v0413 = qcar(v0244);
    v0244 = elt(env, 9); /* !:rd!: */
    v0244 = get(v0413, v0244);
    env = stack[0];
    if (!(v0244 == nil)) goto v0097;
    v0244 = qvalue(elt(env, 10)); /* !*complex */
    if (v0244 == nil) goto v0117;
    v0244 = v0412;
    v0413 = qcar(v0244);
    v0244 = elt(env, 11); /* !:cr!: */
    v0244 = get(v0413, v0244);
    env = stack[0];
    goto v0097;

v0117:
    v0244 = qvalue(elt(env, 5)); /* nil */
    goto v0097;

v0154:
    v0244 = v0412;
    v0244 = (is_number(v0244) ? lisp_true : nil);
    if (!(v0244 == nil)) { popv(1); return onevalue(v0244); }
    v0413 = v0412;
    v0244 = elt(env, 1); /* constant */
    v0244 = Lflagp(nil, v0413, v0244);
    env = stack[0];
    if (v0244 == nil) goto v0062;
    v0244 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0244); }

v0062:
    v0244 = elt(env, 3); /* i */
    if (v0412 == v0244) goto v0089;
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0244); }

v0089:
    v0244 = elt(env, 3); /* i */
    v0412 = elt(env, 4); /* idvalfn */
    popv(1);
    return get(v0244, v0412);
}



/* Code for co_save */

static Lisp_Object CC_co_save(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127, v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for co_save");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0127 = v0001;
    v0235 = v0000;
/* end of prologue */
    v0126 = qvalue(elt(env, 1)); /* !*rlqedfs */
    if (v0126 == nil) goto v0090;
    v0126 = v0235;
    {
        fn = elt(env, 2); /* co_push */
        return (*qfn2(fn))(qenv(fn), v0126, v0127);
    }

v0090:
    v0126 = v0235;
    {
        fn = elt(env, 3); /* co_enqueue */
        return (*qfn2(fn))(qenv(fn), v0126, v0127);
    }
}



/* Code for cl_ex */

static Lisp_Object CC_cl_ex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0071, v0220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_ex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0001;
    v0071 = v0000;
/* end of prologue */
    v0220 = elt(env, 1); /* ex */
    {
        fn = elt(env, 2); /* cl_closure */
        return (*qfnn(fn))(qenv(fn), 3, v0220, v0071, v0072);
    }
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0083 = stack[-2];
    v0101 = elt(env, 1); /* id */
    if (v0083 == v0101) goto v0094;
    v0101 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v0101;
    goto v0110;

v0110:
    v0101 = stack[-1];
    v0083 = Llength(nil, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0101 = (Lisp_Object)1; /* 0 */
    v0101 = (Lisp_Object)greaterp2(v0083, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-4];
    if (v0101 == nil) goto v0126;
    v0101 = stack[-3];
    if (!(v0101 == nil)) goto v0126;
    v0083 = stack[-2];
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    if (!(equal(v0083, v0101))) goto v0074;
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    stack[0] = v0101;
    v0101 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v0101;
    goto v0074;

v0074:
    v0101 = stack[-1];
    v0101 = qcdr(v0101);
    stack[-1] = v0101;
    goto v0110;

v0126:
    v0101 = stack[-3];
    if (!(v0101 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0101 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0101 == nil)) goto v0049;
    v0101 = elt(env, 5); /* "error in get_mat" */
    fn = elt(env, 6); /* lprie */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    goto v0049;

v0049:
    v0101 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    v0101 = nil;
    { popv(5); return onevalue(v0101); }

v0094:
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 7); /* get!+row!+nr */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
/* error exit handlers */
v0077:
    popv(5);
    return nil;
}



/* Code for qqe_qadd!-inside */

static Lisp_Object CC_qqe_qaddKinside(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0414, v0237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qadd-inside");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0414 = stack[0];
    if (v0414 == nil) goto v0071;
    v0414 = stack[0];
    v0414 = (consp(v0414) ? nil : lisp_true);
    goto v0072;

v0072:
    if (v0414 == nil) goto v0086;
    v0414 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0414); }

v0086:
    v0414 = stack[0];
    fn = elt(env, 6); /* qqe_op */
    v0414 = (*qfn1(fn))(qenv(fn), v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    stack[-1] = v0414;
    v0237 = elt(env, 3); /* a */
    v0414 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    v0414 = cons(v0237, v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0414; /* qqe_qadd!-location!* */
    v0414 = stack[0];
    v0414 = Lconsp(nil, v0414);
    env = stack[-3];
    if (v0414 == nil) goto v0207;
    v0414 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v0414 = (*qfn1(fn))(qenv(fn), v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    if (!(v0414 == nil)) goto v0207;
    v0414 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v0414;
    v0414 = stack[-1];
    v0237 = v0414;
    v0414 = stack[0];
    v0414 = qcdr(v0414);
    stack[-1] = v0414;
    v0414 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    stack[0] = v0414;
    goto v0200;

v0200:
    v0414 = stack[-1];
    if (v0414 == nil) goto v0120;
    v0414 = stack[-2];
    if (v0414 == nil) goto v0120;
    v0237 = elt(env, 5); /* d */
    v0414 = stack[0];
    v0414 = cons(v0237, v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0414; /* qqe_qadd!-location!* */
    v0414 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    stack[0] = v0414;
    v0414 = stack[-1];
    if (!consp(v0414)) goto v0102;
    v0414 = stack[-1];
    v0414 = qcar(v0414);
    v0414 = Lconsp(nil, v0414);
    env = stack[-3];
    if (v0414 == nil) goto v0206;
    v0414 = stack[-1];
    v0414 = qcar(v0414);
    v0414 = CC_qqe_qaddKinside(env, v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    goto v0180;

v0180:
    if (v0414 == nil) goto v0105;
    v0414 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0414;
    goto v0105;

v0105:
    v0414 = stack[-1];
    v0237 = v0414;
    v0414 = stack[-1];
    v0414 = qcdr(v0414);
    stack[-1] = v0414;
    goto v0200;

v0206:
    v0414 = qvalue(elt(env, 2)); /* nil */
    goto v0180;

v0102:
    v0414 = qvalue(elt(env, 2)); /* nil */
    goto v0180;

v0120:
    v0414 = stack[-2];
    if (v0414 == nil) { popv(4); return onevalue(v0237); }
    v0414 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0414); }

v0207:
    v0414 = stack[0];
    v0414 = Lconsp(nil, v0414);
    env = stack[-3];
    if (v0414 == nil) goto v0188;
    v0414 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v0414 = (*qfn1(fn))(qenv(fn), v0414);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-3];
    if (v0414 == nil) goto v0188;
    v0414 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0414); }

v0188:
    v0414 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0414); }

v0071:
    v0414 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0300:
    popv(4);
    return nil;
}



/* Code for cl_applysac1 */

static Lisp_Object MS_CDECL CC_cl_applysac1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0002;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0113 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0113;
    goto v0060;

v0060:
    v0115 = stack[-2];
    v0114 = stack[-1];
    v0113 = stack[0];
    fn = elt(env, 5); /* cl_applysac2 */
    v0113 = (*qfnn(fn))(qenv(fn), 3, v0115, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0115 = v0113;
    v0114 = v0115;
    v0113 = elt(env, 2); /* break */
    if (!(v0114 == v0113)) goto v0087;
    v0113 = elt(env, 3); /* (nil) */
    v0115 = v0113;
    v0113 = elt(env, 2); /* break */
    stack[-3] = v0113;
    goto v0087;

v0087:
    v0113 = v0115;
    v0113 = qcar(v0113);
    if (v0113 == nil) goto v0207;
    v0113 = v0115;
    v0113 = qcar(v0113);
    v0113 = qcar(v0113);
    if (!(v0113 == nil)) goto v0207;
    v0113 = qvalue(elt(env, 4)); /* nil */
    stack[-3] = v0113;
    v0113 = v0115;
    v0113 = qcar(v0113);
    v0113 = qcdr(v0113);
    stack[-2] = v0113;
    v0113 = v0115;
    v0113 = qcdr(v0113);
    stack[-1] = v0113;
    goto v0207;

v0207:
    v0113 = v0115;
    v0113 = qcar(v0113);
    if (v0113 == nil) goto v0208;
    v0113 = v0115;
    v0113 = qcar(v0113);
    v0113 = qcar(v0113);
    goto v0210;

v0210:
    if (v0113 == nil) goto v0060;
    v0114 = stack[-3];
    v0113 = elt(env, 2); /* break */
    if (v0114 == v0113) goto v0106;
    v0113 = v0115;
    v0113 = qcar(v0113);
    if (v0113 == nil) { popv(5); return onevalue(v0115); }
    v0114 = stack[-3];
    v0113 = v0115;
    v0113 = qcar(v0113);
    v0113 = qcdr(v0113);
    v0115 = qcdr(v0115);
    popv(5);
    return acons(v0114, v0113, v0115);

v0106:
    v0113 = elt(env, 2); /* break */
    { popv(5); return onevalue(v0113); }

v0208:
    v0113 = qvalue(elt(env, 1)); /* t */
    goto v0210;
/* error exit handlers */
v0042:
    popv(5);
    return nil;
}



/* Code for vdp_putprop */

static Lisp_Object MS_CDECL CC_vdp_putprop(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119, v0210, v0208, v0228;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_putprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_putprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v0210 = v0002;
    v0208 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    v0118 = qcdr(v0118);
    v0118 = qcdr(v0118);
    v0118 = qcdr(v0118);
    v0119 = v0118;
    v0228 = v0208;
    v0118 = v0119;
    v0118 = qcar(v0118);
    v0118 = Latsoc(nil, v0228, v0118);
    v0228 = v0118;
    v0118 = v0228;
    if (v0118 == nil) goto v0088;
    v0118 = v0228;
    v0119 = v0210;
    v0118 = Lrplacd(nil, v0118, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0088:
    stack[-1] = v0119;
    v0118 = v0208;
    v0119 = qcar(v0119);
    v0118 = acons(v0118, v0210, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0118 = Lrplaca(nil, stack[-1], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0123:
    popv(3);
    return nil;
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minus-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0125 = v0001;
    v0126 = v0000;
/* end of prologue */
    v0126 = qcdr(v0126);
    v0126 = qcar(v0126);
    fn = elt(env, 1); /* ps!:evaluate */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-1];
    stack[0] = v0125;
    v0125 = stack[0];
    v0125 = qcar(v0125);
    fn = elt(env, 2); /* negf */
    v0126 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    popv(2);
    return cons(v0126, v0125);
/* error exit handlers */
v0235:
    popv(2);
    return nil;
}



setup_type const u49_setup[] =
{
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"gcd-with-number",         too_few_2,      CC_gcdKwithKnumber,wrong_no_2},
    {"put-kvalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKkvalue},
    {"test-ideal",              CC_testKideal,  too_many_1,    wrong_no_1},
    {"setequal",                too_few_2,      CC_setequal,   wrong_no_2},
    {"rand-mons-dense",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_randKmonsKdense},
    {"acmemb",                  too_few_2,      CC_acmemb,     wrong_no_2},
    {"coeff1_calc",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff1_calc},
    {"pst_equitable",           CC_pst_equitable,too_many_1,   wrong_no_1},
    {"eval_uni_poly",           too_few_2,      CC_eval_uni_poly,wrong_no_2},
    {"liqsimp1-check",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_liqsimp1Kcheck},
    {"co_get",                  CC_co_get,      too_many_1,    wrong_no_1},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"rl_ex",                   too_few_2,      CC_rl_ex,      wrong_no_2},
    {"*addsq",                  too_few_2,      CC_Haddsq,     wrong_no_2},
    {"equal+matrices+p",        too_few_2,      CC_equalLmatricesLp,wrong_no_2},
    {"pasf_premf1",             too_few_2,      CC_pasf_premf1,wrong_no_2},
    {"qqe_prefix-length",       CC_qqe_prefixKlength,too_many_1,wrong_no_1},
    {"dip_f2dip1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_f2dip1},
    {"ldf-all-var",             CC_ldfKallKvar, too_many_1,    wrong_no_1},
    {"subeval",                 CC_subeval,     too_many_1,    wrong_no_1},
    {"vdpenumerate",            CC_vdpenumerate,too_many_1,    wrong_no_1},
    {"cvt5",                    too_few_2,      CC_cvt5,       wrong_no_2},
    {"exp:",                    too_few_2,      CC_expT,       wrong_no_2},
    {"declared-as-float",       CC_declaredKasKfloat,too_many_1,wrong_no_1},
    {"gcdlist",                 CC_gcdlist,     too_many_1,    wrong_no_1},
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"permp:",                  too_few_2,      CC_permpT,     wrong_no_2},
    {"constant_exprp",          CC_constant_exprp,too_many_1,  wrong_no_1},
    {"co_save",                 too_few_2,      CC_co_save,    wrong_no_2},
    {"cl_ex",                   too_few_2,      CC_cl_ex,      wrong_no_2},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"qqe_qadd-inside",         CC_qqe_qaddKinside,too_many_1, wrong_no_1},
    {"cl_applysac1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_applysac1},
    {"vdp_putprop",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_putprop},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {NULL, (one_args *)"u49", (two_args *)"6391 1305189 437796", 0}
};

/* end of generated code */
