
/* $destdir\u46.c        Machine generated C code */

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


/* Code for pst_d */

static Lisp_Object MS_CDECL CC_pst_d(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0071, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0002;
    stack[-9] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0070 = stack[-2];
    fn = elt(env, 2); /* listp */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    if (v0070 == nil) goto v0074;
    v0070 = stack[-9];
    fn = elt(env, 2); /* listp */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    if (v0070 == nil) goto v0075;
    v0070 = stack[-2];
    stack[-10] = v0070;
    v0070 = stack[-10];
    if (v0070 == nil) goto v0076;
    v0070 = stack[-10];
    v0070 = qcar(v0070);
    stack[-4] = v0070;
    v0070 = stack[-9];
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0077;
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = stack[-4];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    stack[-1] = v0070;
    stack[-2] = v0070;
    goto v0078;

v0078:
    v0070 = stack[-3];
    v0070 = qcdr(v0070);
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0079;
    stack[0] = stack[-1];
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = stack[-4];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = Lrplacd(nil, stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    stack[-1] = v0070;
    goto v0078;

v0079:
    v0070 = stack[-2];
    goto v0080;

v0080:
    fn = elt(env, 3); /* ordn */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    stack[-6] = v0070;
    stack[-7] = v0070;
    goto v0081;

v0081:
    v0070 = stack[-10];
    v0070 = qcdr(v0070);
    stack[-10] = v0070;
    v0070 = stack[-10];
    if (v0070 == nil) goto v0082;
    stack[-5] = stack[-6];
    v0070 = stack[-10];
    v0070 = qcar(v0070);
    stack[-4] = v0070;
    v0070 = stack[-9];
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0083;
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = stack[-4];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    stack[-1] = v0070;
    stack[-2] = v0070;
    goto v0084;

v0084:
    v0070 = stack[-3];
    v0070 = qcdr(v0070);
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0085;
    stack[0] = stack[-1];
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = stack[-4];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = Lrplacd(nil, stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    stack[-1] = v0070;
    goto v0084;

v0085:
    v0070 = stack[-2];
    goto v0086;

v0086:
    fn = elt(env, 3); /* ordn */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = Lrplacd(nil, stack[-5], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = stack[-6];
    v0070 = qcdr(v0070);
    stack[-6] = v0070;
    goto v0081;

v0083:
    v0070 = qvalue(elt(env, 1)); /* nil */
    goto v0086;

v0082:
    v0070 = stack[-7];
    goto v0087;

v0087:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0077:
    v0070 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0076:
    v0070 = qvalue(elt(env, 1)); /* nil */
    goto v0087;

v0075:
    v0070 = stack[-2];
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0088;
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = v0070;
    v0071 = stack[-9];
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    stack[-1] = v0070;
    stack[-2] = v0070;
    goto v0089;

v0089:
    v0070 = stack[-3];
    v0070 = qcdr(v0070);
    stack[-3] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0090;
    stack[0] = stack[-1];
    v0070 = stack[-3];
    v0070 = qcar(v0070);
    v0072 = v0070;
    v0071 = stack[-9];
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = Lrplacd(nil, stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    stack[-1] = v0070;
    goto v0089;

v0090:
    v0070 = stack[-2];
    goto v0091;

v0091:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0088:
    v0070 = qvalue(elt(env, 1)); /* nil */
    goto v0091;

v0074:
    v0070 = stack[-9];
    fn = elt(env, 2); /* listp */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    if (v0070 == nil) goto v0092;
    v0070 = stack[-9];
    stack[-4] = v0070;
    v0070 = stack[-4];
    if (v0070 == nil) goto v0093;
    v0070 = stack[-4];
    v0070 = qcar(v0070);
    v0072 = stack[-2];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    stack[-1] = v0070;
    stack[-3] = v0070;
    goto v0094;

v0094:
    v0070 = stack[-4];
    v0070 = qcdr(v0070);
    stack[-4] = v0070;
    v0070 = stack[-4];
    if (v0070 == nil) goto v0095;
    stack[0] = stack[-1];
    v0070 = stack[-4];
    v0070 = qcar(v0070);
    v0072 = stack[-2];
    v0071 = v0070;
    v0070 = stack[-8];
    v0070 = CC_pst_d(env, 3, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = Lrplacd(nil, stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-11];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    stack[-1] = v0070;
    goto v0094;

v0095:
    v0070 = stack[-3];
    goto v0096;

v0096:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0093:
    v0070 = qvalue(elt(env, 1)); /* nil */
    goto v0096;

v0092:
    v0072 = stack[-2];
    v0071 = stack[-9];
    v0070 = stack[-8];
    {
        popv(12);
        fn = elt(env, 4); /* pst_d1 */
        return (*qfnn(fn))(qenv(fn), 3, v0072, v0071, v0070);
    }
/* error exit handlers */
v0073:
    popv(12);
    return nil;
}



/* Code for rlval */

static Lisp_Object CC_rlval(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0096, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlval");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0001;
    v0096 = v0000;
/* end of prologue */
    v0006 = v0096;
    if (!consp(v0006)) goto v0125;
    v0006 = v0096;
    v0006 = qcar(v0006);
    v0006 = (consp(v0006) ? nil : lisp_true);
    goto v0126;

v0126:
    if (!(v0006 == nil)) { popv(8); return onevalue(v0096); }
    v0006 = stack[-5];
    if (!consp(v0006)) goto v0127;
    v0006 = stack[-5];
    v0006 = qcdr(v0006);
    v0094 = qcar(v0006);
    v0006 = (Lisp_Object)1; /* 0 */
    v0006 = (v0094 == v0006 ? lisp_true : nil);
    goto v0081;

v0081:
    if (v0006 == nil) goto v0128;
    v0006 = v0096;
    v0006 = qcar(v0006);
    v0094 = qcar(v0006);
    v0006 = (Lisp_Object)1; /* 0 */
    if (v0094 == v0006) goto v0129;
    v0006 = (Lisp_Object)1; /* 0 */
    {
        popv(8);
        fn = elt(env, 5); /* r2flbf */
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0129:
    v0006 = v0096;
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    { popv(8); return onevalue(v0006); }

v0128:
    v0094 = stack[-5];
    v0006 = elt(env, 2); /* !:rd!: */
    if (!consp(v0094)) goto v0130;
    v0094 = qcar(v0094);
    if (!(v0094 == v0006)) goto v0130;
    v0006 = stack[-5];
    v0006 = qcdr(v0006);
    v0006 = (consp(v0006) ? nil : lisp_true);
    v0006 = (v0006 == nil ? lisp_true : nil);
    goto v0079;

v0079:
    stack[-4] = v0006;
    v0006 = v0096;
    fn = elt(env, 6); /* ncoeffs */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    v0006 = qcdr(v0006);
    v0096 = v0006;
    v0006 = qcar(v0006);
    stack[-6] = v0006;
    v0006 = v0096;
    v0006 = qcdr(v0006);
    stack[-3] = v0006;
    goto v0059;

v0059:
    v0006 = stack[-3];
    if (v0006 == nil) goto v0058;
    v0006 = stack[-3];
    v0006 = qcar(v0006);
    stack[-2] = v0006;
    v0006 = stack[-4];
    if (v0006 == nil) goto v0132;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v0006 = stack[-5];
    v0006 = qcdr(v0006);
    v0096 = qcar(v0006);
    v0006 = stack[-6];
    v0006 = qcdr(v0006);
    v0006 = qcar(v0006);
    stack[0] = times2(v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    v0006 = stack[-5];
    v0006 = qcdr(v0006);
    v0096 = qcdr(v0006);
    v0006 = stack[-6];
    v0006 = qcdr(v0006);
    v0006 = qcdr(v0006);
    v0006 = plus2(v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    v0006 = list2star(stack[-1], stack[0], v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    goto v0133;

v0133:
    stack[-6] = v0006;
    v0006 = stack[-2];
    if (v0006 == nil) goto v0134;
    v0006 = stack[-4];
    if (v0006 == nil) goto v0135;
    v0096 = stack[-2];
    v0006 = stack[-6];
    fn = elt(env, 7); /* plus!: */
    v0006 = (*qfn2(fn))(qenv(fn), v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    goto v0039;

v0039:
    stack[-6] = v0006;
    goto v0134;

v0134:
    v0006 = stack[-3];
    v0006 = qcdr(v0006);
    stack[-3] = v0006;
    goto v0059;

v0135:
    v0096 = stack[-6];
    v0006 = stack[-2];
    v0006 = plus2(v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    goto v0039;

v0132:
    v0096 = stack[-5];
    v0006 = stack[-6];
    v0006 = times2(v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    goto v0133;

v0058:
    v0006 = stack[-4];
    if (v0006 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v0006 = stack[-6];
    v0006 = qcdr(v0006);
    v0006 = qcar(v0006);
    v0094 = v0006;
    v0096 = v0094;
    v0006 = (Lisp_Object)1; /* 0 */
    if (v0096 == v0006) goto v0032;
    v0096 = v0094;
    v0006 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 8); /* inorm */
    v0006 = (*qfn2(fn))(qenv(fn), v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-7];
    v0094 = v0006;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v0006 = v0094;
    stack[0] = qcar(v0006);
    v0006 = v0094;
    v0096 = qcdr(v0006);
    v0006 = stack[-6];
    v0006 = qcdr(v0006);
    v0006 = qcdr(v0006);
    v0006 = plus2(v0096, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    {
        Lisp_Object v0136 = stack[-1];
        Lisp_Object v0137 = stack[0];
        popv(8);
        return list2star(v0136, v0137, v0006);
    }

v0032:
    v0094 = elt(env, 2); /* !:rd!: */
    v0096 = (Lisp_Object)1; /* 0 */
    v0006 = (Lisp_Object)1; /* 0 */
    popv(8);
    return list2star(v0094, v0096, v0006);

v0130:
    v0006 = qvalue(elt(env, 3)); /* nil */
    goto v0079;

v0127:
    v0006 = stack[-5];
    v0006 = (Lisp_Object)zerop(v0006);
    v0006 = v0006 ? lisp_true : nil;
    env = stack[-7];
    goto v0081;

v0125:
    v0006 = qvalue(elt(env, 1)); /* t */
    goto v0126;
/* error exit handlers */
v0131:
    popv(8);
    return nil;
}



/* Code for ofsf_sminsert */

static Lisp_Object CC_ofsf_sminsert(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0158, v0159, v0160, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sminsert");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    goto v0162;

v0162:
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0161 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0160 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0159 = qcar(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    fn = elt(env, 5); /* ofsf_sminsert1 */
    v0157 = (*qfnn(fn))(qenv(fn), 5, v0161, v0160, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-2] = v0157;
    v0157 = stack[-2];
    if (v0157 == nil) goto v0163;
    v0157 = stack[-2];
    if (symbolp(v0157)) goto v0163;
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    stack[-3] = v0157;
    v0157 = stack[-2];
    stack[-4] = v0157;
    goto v0163;

v0163:
    v0157 = stack[-2];
    if (v0157 == nil) goto v0164;
    v0157 = stack[-2];
    v0157 = Lsymbolp(nil, v0157);
    env = stack[-6];
    if (!(v0157 == nil)) goto v0165;
    v0157 = stack[-3];
    v0157 = (v0157 == nil ? lisp_true : nil);
    goto v0165;

v0165:
    if (v0157 == nil) goto v0162;
    v0158 = stack[-2];
    v0157 = elt(env, 2); /* false */
    if (v0158 == v0157) goto v0166;
    v0158 = stack[-2];
    v0157 = elt(env, 3); /* true */
    if (v0158 == v0157) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v0157 = stack[-3];
    if (v0157 == nil) goto v0167;
    v0157 = stack[-3];
    stack[0] = v0157;
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0168;

v0168:
    v0157 = stack[-1];
    if (v0157 == nil) goto v0102;
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    stack[-5] = v0157;
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0161 = qcar(v0157);
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0160 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0159 = qcar(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    fn = elt(env, 5); /* ofsf_sminsert1 */
    v0157 = (*qfnn(fn))(qenv(fn), 5, v0161, v0160, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-2] = v0157;
    v0158 = stack[-2];
    v0157 = elt(env, 3); /* true */
    if (v0158 == v0157) goto v0132;
    v0158 = stack[-2];
    v0157 = elt(env, 2); /* false */
    if (v0158 == v0157) goto v0169;
    v0157 = stack[-2];
    if (v0157 == nil) goto v0110;
    v0158 = stack[0];
    v0157 = stack[-1];
    fn = elt(env, 6); /* setcdr */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0157 = stack[-2];
    stack[-4] = v0157;
    goto v0168;

v0110:
    v0157 = stack[0];
    v0157 = qcdr(v0157);
    stack[0] = v0157;
    goto v0168;

v0169:
    v0157 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = v0157;
    v0157 = elt(env, 2); /* false */
    stack[-5] = v0157;
    goto v0168;

v0132:
    v0157 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = v0157;
    v0157 = elt(env, 3); /* true */
    stack[-5] = v0157;
    goto v0168;

v0102:
    v0158 = stack[-5];
    v0157 = elt(env, 2); /* false */
    if (v0158 == v0157) goto v0089;
    v0157 = stack[-5];
    v0158 = elt(env, 3); /* true */
    if (v0157 == v0158) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v0158 = stack[-4];
    v0157 = stack[-3];
    popv(7);
    return cons(v0158, v0157);

v0089:
    v0157 = elt(env, 2); /* false */
    { popv(7); return onevalue(v0157); }

v0167:
    v0157 = stack[-4];
    popv(7);
    return ncons(v0157);

v0166:
    v0157 = elt(env, 2); /* false */
    { popv(7); return onevalue(v0157); }

v0164:
    v0157 = qvalue(elt(env, 1)); /* t */
    goto v0165;
/* error exit handlers */
v0026:
    popv(7);
    return nil;
}



/* Code for gcdk */

static Lisp_Object CC_gcdk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205, v0206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdk");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0001;
    stack[0] = v0000;
/* end of prologue */
    stack[-10] = nil;
    stack[-8] = nil;
    v0205 = stack[0];
    v0204 = stack[-9];
    if (equal(v0205, v0204)) { Lisp_Object res = stack[0]; popv(12); return onevalue(res); }
    v0204 = stack[0];
    if (!consp(v0204)) goto v0207;
    v0204 = stack[0];
    v0204 = qcar(v0204);
    v0204 = (consp(v0204) ? nil : lisp_true);
    goto v0208;

v0208:
    if (v0204 == nil) goto v0209;
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0210;

v0210:
    if (v0204 == nil) goto v0211;
    v0204 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v0204); }

v0211:
    v0204 = stack[0];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0205 = qcdr(v0204);
    v0204 = stack[-9];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = (Lisp_Object)lessp2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0204 = v0204 ? lisp_true : nil;
    env = stack[-11];
    if (v0204 == nil) goto v0213;
    v0204 = stack[0];
    stack[-7] = v0204;
    v0204 = stack[-9];
    stack[0] = v0204;
    v0204 = stack[-7];
    stack[-9] = v0204;
    goto v0213;

v0213:
    v0205 = stack[0];
    v0204 = stack[-9];
    fn = elt(env, 9); /* quotf1 */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    if (!(v0204 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v0204 = qvalue(elt(env, 2)); /* !*heugcd */
    if (v0204 == nil) goto v0044;
    v0205 = stack[0];
    v0204 = stack[-9];
    fn = elt(env, 10); /* heu!-gcd */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0205 = v0204;
    if (!(v0204 == nil)) { popv(12); return onevalue(v0205); }

v0044:
    v0204 = stack[-9];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0205 = qcdr(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    if (v0205 == v0204) goto v0214;
    v0204 = elt(env, 3); /* modular!-multicheck */
    fn = elt(env, 11); /* getd */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    if (v0204 == nil) goto v0051;
    v0206 = stack[0];
    v0205 = stack[-9];
    v0204 = stack[-8];
    fn = elt(env, 3); /* modular!-multicheck */
    v0204 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    goto v0117;

v0117:
    if (!(v0204 == nil)) goto v0036;
    v0204 = qvalue(elt(env, 5)); /* !*mcd */
    v0204 = (v0204 == nil ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0204 == nil) goto v0134;
    v0204 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v0204); }

v0134:
    v0205 = stack[0];
    v0204 = stack[-9];
    fn = elt(env, 12); /* remk */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    stack[-7] = v0204;
    v0204 = stack[-7];
    if (v0204 == nil) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v0205 = stack[-7];
    v0204 = stack[-8];
    fn = elt(env, 13); /* degr */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0204 = (Lisp_Object)1; /* 0 */
    if (v0205 == v0204) goto v0215;
    v0205 = stack[-9];
    v0204 = stack[-10];
    fn = elt(env, 14); /* addlc */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    stack[-10] = v0204;
    v0205 = stack[-7];
    v0204 = stack[-7];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    fn = elt(env, 9); /* quotf1 */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0205 = v0204;
    if (v0204 == nil) goto v0030;
    v0204 = v0205;
    stack[-7] = v0204;
    goto v0140;

v0140:
    v0204 = stack[-9];
    stack[0] = v0204;
    stack[-1] = stack[-7];
    v0204 = stack[-7];
    fn = elt(env, 15); /* comfac */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0205 = v0204;
    v0204 = v0205;
    v0204 = qcar(v0204);
    if (v0204 == nil) goto v0216;
    v0204 = v0205;
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    goto v0217;

v0217:
    fn = elt(env, 9); /* quotf1 */
    v0204 = (*qfn2(fn))(qenv(fn), stack[-1], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    stack[-9] = v0204;
    v0205 = stack[-9];
    v0204 = stack[-8];
    fn = elt(env, 13); /* degr */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0204 = (Lisp_Object)1; /* 0 */
    if (!(v0205 == v0204)) goto v0134;
    v0204 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v0204); }

v0216:
    v0204 = v0205;
    v0204 = qcdr(v0204);
    goto v0217;

v0030:
    v0204 = stack[-10];
    stack[-6] = v0204;
    goto v0218;

v0218:
    v0204 = stack[-6];
    if (v0204 == nil) goto v0140;
    v0204 = stack[-6];
    v0204 = qcar(v0204);
    stack[-5] = v0204;
    v0204 = stack[-5];
    if (!consp(v0204)) goto v0023;
    v0204 = qvalue(elt(env, 4)); /* nil */
    goto v0098;

v0098:
    if (v0204 == nil) goto v0006;
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0219;

v0219:
    if (!(v0204 == nil)) goto v0220;

v0022:
    v0204 = stack[-6];
    v0204 = qcdr(v0204);
    stack[-6] = v0204;
    goto v0218;

v0220:
    v0205 = stack[-7];
    v0204 = stack[-5];
    fn = elt(env, 9); /* quotf1 */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0205 = v0204;
    if (v0204 == nil) goto v0022;
    v0204 = v0205;
    stack[-7] = v0204;
    goto v0220;

v0006:
    v0204 = stack[-5];
    if (!consp(v0204)) goto v0221;
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = (consp(v0204) ? nil : lisp_true);
    goto v0222;

v0222:
    if (v0204 == nil) goto v0223;
    v0205 = qvalue(elt(env, 6)); /* dmode!* */
    v0204 = elt(env, 7); /* field */
    v0204 = Lflagp(nil, v0205, v0204);
    env = stack[-11];
    if (v0204 == nil) goto v0224;
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0225;

v0225:
    v0204 = (v0204 == nil ? lisp_true : nil);
    goto v0219;

v0224:
    v0204 = stack[-5];
    v0205 = qcar(v0204);
    v0204 = elt(env, 8); /* units */
    v0204 = get(v0205, v0204);
    env = stack[-11];
    v0205 = v0204;
    if (v0204 == nil) goto v0226;
    stack[-4] = stack[-5];
    v0204 = v0205;
    stack[-3] = v0204;
    v0204 = stack[-3];
    if (v0204 == nil) goto v0227;
    v0204 = stack[-3];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    stack[-1] = v0204;
    stack[-2] = v0204;
    goto v0228;

v0228:
    v0204 = stack[-3];
    v0204 = qcdr(v0204);
    stack[-3] = v0204;
    v0204 = stack[-3];
    if (v0204 == nil) goto v0229;
    stack[0] = stack[-1];
    v0204 = stack[-3];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0204 = Lrplacd(nil, stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    stack[-1] = v0204;
    goto v0228;

v0229:
    v0204 = stack[-2];
    goto v0230;

v0230:
    v0204 = Lmember(nil, stack[-4], v0204);
    goto v0225;

v0227:
    v0204 = qvalue(elt(env, 4)); /* nil */
    goto v0230;

v0226:
    v0204 = qvalue(elt(env, 4)); /* nil */
    goto v0225;

v0223:
    v0204 = qvalue(elt(env, 4)); /* nil */
    goto v0225;

v0221:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0222;

v0023:
    v0205 = qvalue(elt(env, 6)); /* dmode!* */
    v0204 = elt(env, 7); /* field */
    v0204 = Lflagp(nil, v0205, v0204);
    env = stack[-11];
    v0204 = (v0204 == nil ? lisp_true : nil);
    goto v0098;

v0215:
    v0204 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v0204); }

v0051:
    v0204 = qvalue(elt(env, 4)); /* nil */
    goto v0117;

v0214:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0036;

v0209:
    v0205 = stack[-9];
    v0204 = stack[0];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    stack[-8] = v0204;
    fn = elt(env, 13); /* degr */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-11];
    v0204 = (Lisp_Object)1; /* 0 */
    v0204 = (v0205 == v0204 ? lisp_true : nil);
    goto v0210;

v0207:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0208;
/* error exit handlers */
v0212:
    popv(12);
    return nil;
}



/* Code for evaluateuconst */

static Lisp_Object CC_evaluateuconst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluateuconst");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0111 = stack[0];
    if (v0111 == nil) goto v0126;
    v0111 = stack[0];
    if (!consp(v0111)) goto v0240;
    v0111 = stack[0];
    v0111 = qcar(v0111);
    v0111 = (consp(v0111) ? nil : lisp_true);
    goto v0074;

v0074:
    if (v0111 == nil) goto v0129;
    v0114 = stack[0];
    v0111 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0114, v0111);

v0129:
    v0111 = stack[0];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    v0114 = qcar(v0111);
    v0111 = qvalue(elt(env, 2)); /* cmap */
    v0114 = Lassoc(nil, v0114, v0111);
    v0111 = v0114;
    if (v0114 == nil) goto v0066;
    v0114 = qvalue(elt(env, 3)); /* cval */
    v0111 = qcdr(v0111);
    v0111 = *(Lisp_Object *)((char *)v0114 + (CELL-TAG_VECTOR) + ((int32_t)v0111/(16/CELL)));
    goto v0241;

v0241:
    stack[-1] = v0111;
    v0111 = stack[0];
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    v0111 = CC_evaluateuconst(env, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    fn = elt(env, 4); /* !*multsq */
    v0111 = (*qfn2(fn))(qenv(fn), stack[-1], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    stack[-1] = v0111;
    v0111 = stack[0];
    v0111 = qcdr(v0111);
    v0111 = CC_evaluateuconst(env, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    {
        Lisp_Object v0243 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* !*addsq */
        return (*qfn2(fn))(qenv(fn), v0243, v0111);
    }

v0066:
    v0111 = stack[0];
    v0111 = qcar(v0111);
    v0114 = qcar(v0111);
    v0111 = (Lisp_Object)17; /* 1 */
    v0111 = cons(v0114, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    v0114 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    v0111 = (Lisp_Object)17; /* 1 */
    v0111 = cons(v0114, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    goto v0241;

v0240:
    v0111 = qvalue(elt(env, 1)); /* t */
    goto v0074;

v0126:
    v0111 = qvalue(elt(env, 1)); /* t */
    goto v0074;
/* error exit handlers */
v0242:
    popv(3);
    return nil;
}



/* Code for quotfx1 */

static Lisp_Object CC_quotfx1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0272, v0273, v0274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfx1");
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
/* copy arguments values to proper place */
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    v0272 = stack[-8];
    if (v0272 == nil) goto v0143;
    v0273 = stack[-8];
    v0272 = stack[-7];
    if (equal(v0273, v0272)) goto v0054;
    v0273 = stack[-7];
    v0272 = (Lisp_Object)17; /* 1 */
    if (v0273 == v0272) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0272 = stack[-7];
    if (!consp(v0272)) goto v0129;
    v0272 = stack[-7];
    v0272 = qcar(v0272);
    v0272 = (consp(v0272) ? nil : lisp_true);
    goto v0163;

v0163:
    if (v0272 == nil) goto v0080;
    v0273 = stack[-8];
    v0272 = stack[-7];
    {
        popv(11);
        fn = elt(env, 4); /* quotfdx */
        return (*qfn2(fn))(qenv(fn), v0273, v0272);
    }

v0080:
    v0272 = stack[-8];
    if (!consp(v0272)) goto v0108;
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = (consp(v0272) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0272 == nil) goto v0275;
    v0272 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0272 == nil)) goto v0276;
    v0272 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0276;

v0276:
    v0272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = nil;
    { popv(11); return onevalue(v0272); }

v0275:
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0273 = qcar(v0272);
    v0272 = stack[-7];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    if (v0273 == v0272) goto v0130;
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0273 = qcar(v0272);
    v0272 = stack[-7];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    fn = elt(env, 6); /* ordop */
    v0272 = (*qfn2(fn))(qenv(fn), v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    if (v0272 == nil) goto v0278;
    v0273 = stack[-8];
    v0272 = stack[-7];
    {
        popv(11);
        fn = elt(env, 7); /* quotkx */
        return (*qfn2(fn))(qenv(fn), v0273, v0272);
    }

v0278:
    v0272 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0272 == nil)) goto v0279;
    v0272 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0279;

v0279:
    v0272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = nil;
    { popv(11); return onevalue(v0272); }

v0130:
    stack[-9] = nil;
    stack[-1] = nil;
    v0272 = stack[-7];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0272 = qcdr(v0272);
    stack[-5] = v0272;
    goto v0083;

v0083:
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0273 = qcdr(v0272);
    stack[-6] = v0273;
    v0272 = stack[-5];
    v0272 = (Lisp_Object)lessp2(v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = v0272 ? lisp_true : nil;
    env = stack[-10];
    if (v0272 == nil) goto v0084;
    v0272 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0272 == nil)) goto v0149;
    v0272 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0149;

v0149:
    v0272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = nil;
    { popv(11); return onevalue(v0272); }

v0084:
    v0272 = stack[-8];
    fn = elt(env, 8); /* lt!* */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[0] = v0272;
    v0272 = stack[-7];
    fn = elt(env, 8); /* lt!* */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    v0273 = stack[-7];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    stack[-4] = v0273;
    v0273 = stack[0];
    v0273 = qcdr(v0273);
    v0272 = qcdr(v0272);
    v0272 = CC_quotfx1(env, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[-3] = v0272;
    v0273 = stack[-6];
    v0272 = stack[-5];
    v0272 = (Lisp_Object)(int32_t)((int32_t)v0273 - (int32_t)v0272 + TAG_FIXNUM);
    stack[0] = v0272;
    v0273 = stack[0];
    v0272 = (Lisp_Object)1; /* 0 */
    if (v0273 == v0272) goto v0028;
    v0273 = stack[-4];
    v0272 = stack[0];
    v0272 = cons(v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[-2] = v0272;
    v0272 = stack[-9];
    if (!(v0272 == nil)) goto v0280;
    v0273 = stack[-6];
    v0272 = stack[0];
    v0272 = (Lisp_Object)(int32_t)((int32_t)v0273 - (int32_t)v0272 + TAG_FIXNUM);
    v0272 = (Lisp_Object)((int32_t)(v0272) - 0x10);
    v0274 = v0272;
    v0273 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v0274)) < ((int32_t)(v0273))) goto v0105;
    v0274 = stack[-8];
    v0273 = stack[-4];
    fn = elt(env, 9); /* cutf1 */
    v0272 = (*qfnn(fn))(qenv(fn), 3, v0274, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0104;

v0104:
    stack[-8] = v0272;
    goto v0280;

v0280:
    v0272 = qvalue(elt(env, 3)); /* t */
    stack[-9] = v0272;
    v0273 = stack[-5];
    v0272 = stack[0];
    v0272 = (Lisp_Object)(int32_t)((int32_t)v0273 - (int32_t)v0272 + TAG_FIXNUM);
    v0272 = (Lisp_Object)((int32_t)(v0272) - 0x10);
    v0274 = v0272;
    v0273 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v0274)) < ((int32_t)(v0273))) goto v0094;
    v0274 = stack[-7];
    v0273 = stack[-4];
    fn = elt(env, 9); /* cutf1 */
    v0272 = (*qfnn(fn))(qenv(fn), 3, v0274, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0096;

v0096:
    stack[-7] = v0272;
    stack[-6] = stack[-8];
    v0273 = stack[0];
    v0272 = (Lisp_Object)1; /* 0 */
    if (v0273 == v0272) goto v0008;
    v0273 = stack[-2];
    v0272 = (Lisp_Object)17; /* 1 */
    v0272 = cons(v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    v0273 = ncons(v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    v0272 = stack[-7];
    fn = elt(env, 10); /* multf */
    v0272 = (*qfn2(fn))(qenv(fn), v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[0] = v0272;
    goto v0281;

v0281:
    v0272 = stack[-3];
    fn = elt(env, 11); /* negf */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    fn = elt(env, 10); /* multf */
    v0272 = (*qfn2(fn))(qenv(fn), stack[0], v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    fn = elt(env, 12); /* addf */
    v0272 = (*qfn2(fn))(qenv(fn), stack[-6], v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[-8] = v0272;
    v0272 = stack[-8];
    if (v0272 == nil) goto v0282;
    v0272 = stack[-8];
    if (!consp(v0272)) goto v0283;
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = (consp(v0272) ? nil : lisp_true);
    goto v0284;

v0284:
    if (v0272 == nil) goto v0285;
    v0272 = qvalue(elt(env, 3)); /* t */
    goto v0286;

v0286:
    if (v0272 == nil) goto v0282;
    v0272 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0272 == nil)) goto v0287;
    v0272 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0287;

v0287:
    v0272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = nil;
    { popv(11); return onevalue(v0272); }

v0282:
    stack[0] = stack[-1];
    v0273 = stack[-2];
    v0272 = stack[-3];
    v0272 = cons(v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    v0272 = ncons(v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    v0272 = Lnconc(nil, stack[0], v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    stack[-1] = v0272;
    v0272 = stack[-8];
    if (v0272 == nil) { Lisp_Object res = stack[-1]; popv(11); return onevalue(res); }
    else goto v0083;

v0285:
    v0272 = stack[-8];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0273 = qcar(v0272);
    v0272 = stack[-4];
    v0272 = (v0273 == v0272 ? lisp_true : nil);
    v0272 = (v0272 == nil ? lisp_true : nil);
    goto v0286;

v0283:
    v0272 = qvalue(elt(env, 3)); /* t */
    goto v0284;

v0008:
    v0272 = stack[-7];
    stack[0] = v0272;
    goto v0281;

v0094:
    v0272 = stack[-7];
    goto v0096;

v0105:
    v0272 = stack[-8];
    goto v0104;

v0028:
    v0273 = stack[-1];
    v0272 = stack[-3];
    {
        popv(11);
        fn = elt(env, 13); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v0273, v0272);
    }

v0108:
    v0272 = qvalue(elt(env, 3)); /* t */
    goto v0067;

v0129:
    v0272 = qvalue(elt(env, 3)); /* t */
    goto v0163;

v0054:
    v0272 = (Lisp_Object)17; /* 1 */
    { popv(11); return onevalue(v0272); }

v0143:
    v0272 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0272 == nil)) goto v0288;
    v0272 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-10];
    goto v0288;

v0288:
    v0272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    v0272 = nil;
    { popv(11); return onevalue(v0272); }
/* error exit handlers */
v0277:
    popv(11);
    return nil;
}



/* Code for ratpoly_toaf */

static Lisp_Object CC_ratpoly_toaf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_toaf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    v0053 = v0034;
    v0053 = qcar(v0053);
    if (v0053 == nil) goto v0145;
    v0053 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v0034, v0053);
    }

v0145:
    v0053 = (Lisp_Object)1; /* 0 */
    return onevalue(v0053);
}



/* Code for tryreduction */

static Lisp_Object MS_CDECL CC_tryreduction(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tryreduction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tryreduction");
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
    v0036 = stack[-2];
    v0036 = qcar(v0036);
    stack[-3] = v0036;
    v0036 = stack[-3];
    if (!consp(v0036)) goto v0210;
    v0036 = stack[-3];
    stack[-2] = v0036;
    v0036 = stack[-2];
    v0036 = qcar(v0036);
    stack[-3] = v0036;
    goto v0210;

v0210:
    v0214 = stack[-3];
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0214 == v0036) goto v0127;
    v0214 = stack[-3];
    v0036 = (Lisp_Object)17; /* 1 */
    v0036 = (v0214 == v0036 ? lisp_true : nil);
    goto v0081;

v0081:
    if (!(v0036 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0214 = stack[-3];
    v0036 = (Lisp_Object)33; /* 2 */
    v0036 = Ldivide(nil, v0214, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-3] = v0036;
    v0214 = stack[-2];
    v0036 = stack[-3];
    v0036 = qcdr(v0036);
    v0036 = Lrplaca(nil, v0214, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    v0036 = stack[-3];
    v0036 = qcar(v0036);
    stack[-3] = v0036;
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    fn = elt(env, 2); /* simp */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-1] = v0036;
    v0214 = stack[-1];
    v0036 = stack[-3];
    fn = elt(env, 3); /* !*exptsq */
    v0036 = (*qfn2(fn))(qenv(fn), v0214, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-1] = v0036;
    v0214 = (Lisp_Object)17; /* 1 */
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    stack[-2] = cons(v0214, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    v0036 = stack[-1];
    v0036 = qcar(v0036);
    fn = elt(env, 4); /* f2df */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    fn = elt(env, 5); /* multdfconst */
    v0036 = (*qfn2(fn))(qenv(fn), stack[-2], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-3] = v0036;
    v0036 = stack[0];
    if (v0036 == nil) goto v0292;
    v0214 = stack[0];
    v0036 = stack[-3];
    fn = elt(env, 6); /* multdf */
    v0036 = (*qfn2(fn))(qenv(fn), v0214, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    stack[0] = v0036;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0292:
    v0036 = stack[-3];
    stack[0] = v0036;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0127:
    v0036 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0047:
    popv(5);
    return nil;
}



/* Code for groebsimpcontnormalform */

static Lisp_Object CC_groebsimpcontnormalform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0152 = stack[-2];
    if (v0152 == nil) goto v0126;
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    v0152 = (v0152 == nil ? lisp_true : nil);
    goto v0074;

v0074:
    if (!(v0152 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0152 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[0] = v0152;
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    stack[-3] = v0152;
    v0152 = stack[-2];
    fn = elt(env, 5); /* vdpsimpcont */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[-2] = v0152;
    v0151 = stack[-2];
    v0152 = stack[0];
    fn = elt(env, 6); /* gsetsugar */
    v0152 = (*qfn2(fn))(qenv(fn), v0151, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0152 = qvalue(elt(env, 2)); /* !*groebprot */
    if (v0152 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0151 = stack[-3];
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    if (equal(v0151, v0152)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 3); /* quotient */
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    fn = elt(env, 7); /* vbc2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0152 = stack[-3];
    fn = elt(env, 7); /* vbc2a */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0152 = list3(stack[-1], stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    fn = elt(env, 8); /* reval */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    fn = elt(env, 9); /* groebreductionprotocol2 */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0126:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0074;
/* error exit handlers */
v0213:
    popv(5);
    return nil;
}



/* Code for vdpappendmon */

static Lisp_Object MS_CDECL CC_vdpappendmon(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0275, v0213, v0294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpappendmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpappendmon");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0002;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    v0275 = stack[-4];
    if (v0275 == nil) goto v0295;
    v0275 = stack[-4];
    v0275 = qcdr(v0275);
    v0275 = qcdr(v0275);
    v0275 = qcdr(v0275);
    v0275 = qcar(v0275);
    v0275 = (v0275 == nil ? lisp_true : nil);
    goto v0125;

v0125:
    if (v0275 == nil) goto v0074;
    v0213 = stack[-3];
    v0275 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* vdpfmon */
        return (*qfn2(fn))(qenv(fn), v0213, v0275);
    }

v0074:
    v0275 = stack[-3];
    fn = elt(env, 5); /* vbczero!? */
    v0275 = (*qfn1(fn))(qenv(fn), v0275);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-6];
    if (!(v0275 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-5] = elt(env, 2); /* vdp */
    v0275 = stack[-4];
    v0275 = qcdr(v0275);
    stack[-1] = qcar(v0275);
    v0275 = stack[-4];
    v0275 = qcdr(v0275);
    v0275 = qcdr(v0275);
    stack[0] = qcar(v0275);
    v0275 = stack[-4];
    v0275 = qcdr(v0275);
    v0275 = qcdr(v0275);
    v0275 = qcdr(v0275);
    stack[-4] = qcar(v0275);
    v0294 = stack[-2];
    v0213 = stack[-3];
    v0275 = qvalue(elt(env, 3)); /* nil */
    v0275 = list2star(v0294, v0213, v0275);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-6];
    fn = elt(env, 6); /* dipsum */
    v0213 = (*qfn2(fn))(qenv(fn), stack[-4], v0275);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-6];
    v0275 = qvalue(elt(env, 3)); /* nil */
    v0275 = list2(v0213, v0275);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    {
        Lisp_Object v0297 = stack[-5];
        Lisp_Object v0292 = stack[-1];
        Lisp_Object v0167 = stack[0];
        popv(7);
        return list3star(v0297, v0292, v0167, v0275);
    }

v0295:
    v0275 = qvalue(elt(env, 1)); /* t */
    goto v0125;
/* error exit handlers */
v0296:
    popv(7);
    return nil;
}



/* Code for texaeval */

static Lisp_Object CC_texaeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texaeval");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0156 = v0000;
/* end of prologue */
    v0076 = qvalue(elt(env, 1)); /* !*lasimp */
    if (v0076 == nil) goto v0053;
    stack[0] = elt(env, 2); /* tex */
    v0076 = v0156;
    fn = elt(env, 3); /* aeval */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    {
        Lisp_Object v0207 = stack[0];
        popv(1);
        return list2(v0207, v0076);
    }

v0053:
    v0076 = elt(env, 2); /* tex */
    popv(1);
    return list2(v0076, v0156);
/* error exit handlers */
v0208:
    popv(1);
    return nil;
}



/* Code for expt!-separate */

static Lisp_Object CC_exptKseparate(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0235, v0236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-separate");
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
    v0235 = stack[-1];
    v0079 = elt(env, 1); /* expt */
    if (!consp(v0235)) goto v0125;
    v0235 = qcar(v0235);
    if (!(v0235 == v0079)) goto v0125;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0235 = qcar(v0079);
    v0079 = stack[0];
    fn = elt(env, 5); /* depends */
    v0079 = (*qfn2(fn))(qenv(fn), v0235, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-2];
    if (!(v0079 == nil)) goto v0126;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0235 = qcar(v0079);
    v0079 = elt(env, 3); /* plus */
    v0079 = Leqcar(nil, v0235, v0079);
    env = stack[-2];
    v0079 = (v0079 == nil ? lisp_true : nil);
    goto v0126;

v0126:
    if (v0079 == nil) goto v0069;
    v0079 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v0079); }

v0069:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0236 = qcdr(v0079);
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0235 = qcar(v0079);
    v0079 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* expt!-separate1 */
        return (*qfnn(fn))(qenv(fn), 3, v0236, v0235, v0079);
    }

v0125:
    v0079 = qvalue(elt(env, 2)); /* t */
    goto v0126;
/* error exit handlers */
v0166:
    popv(3);
    return nil;
}



/* Code for rappend */

static Lisp_Object CC_rappend(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rappend");
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
    v0057 = elt(env, 1); /* append */
    v0056 = stack[0];
    v0056 = cons(v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    fn = elt(env, 4); /* argnochk */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    v0056 = stack[0];
    v0056 = qcar(v0056);
    fn = elt(env, 5); /* reval */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    stack[-2] = v0056;
    fn = elt(env, 6); /* getrtype */
    v0057 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    v0056 = elt(env, 2); /* list */
    if (v0057 == v0056) goto v0080;
    v0057 = stack[-2];
    v0056 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    goto v0240;

v0240:
    v0056 = nil;
    { popv(4); return onevalue(v0056); }

v0080:
    v0056 = stack[0];
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    fn = elt(env, 5); /* reval */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    stack[-1] = v0056;
    fn = elt(env, 6); /* getrtype */
    v0057 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    v0056 = elt(env, 2); /* list */
    if (v0057 == v0056) goto v0066;
    v0057 = stack[-1];
    v0056 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    goto v0240;

v0066:
    stack[0] = elt(env, 2); /* list */
    v0056 = stack[-2];
    v0057 = qcdr(v0056);
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    v0056 = Lappend(nil, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    {
        Lisp_Object v0241 = stack[0];
        popv(4);
        return cons(v0241, v0056);
    }
/* error exit handlers */
v0130:
    popv(4);
    return nil;
}



/* Code for modroots2 */

static Lisp_Object MS_CDECL CC_modroots2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0304, v0305, v0149, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots2");
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
/* copy arguments values to proper place */
    v0149 = v0002;
    stack[-3] = v0001;
    v0118 = v0000;
/* end of prologue */
    v0304 = v0118;
    if (!consp(v0304)) goto v0239;
    v0304 = v0118;
    v0304 = qcar(v0304);
    v0304 = (consp(v0304) ? nil : lisp_true);
    goto v0162;

v0162:
    if (v0304 == nil) goto v0199;
    v0304 = v0118;
    goto v0125;

v0125:
    if (v0304 == nil) goto v0074;
    v0304 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0304); }

v0074:
    v0304 = v0118;
    if (v0304 == nil) goto v0080;
    v0305 = stack[-3];
    v0304 = (Lisp_Object)33; /* 2 */
    if (v0305 == v0304) goto v0045;
    v0305 = v0118;
    v0304 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* modroots3 */
        return (*qfn2(fn))(qenv(fn), v0305, v0304);
    }

v0045:
    v0305 = v0118;
    v0304 = qvalue(elt(env, 1)); /* t */
    {
        popv(6);
        fn = elt(env, 5); /* modroots4 */
        return (*qfnn(fn))(qenv(fn), 3, v0305, v0304, v0149);
    }

v0080:
    v0305 = stack[-3];
    v0304 = (Lisp_Object)33; /* 2 */
    if (v0305 == v0304) goto v0064;
    v0304 = qvalue(elt(env, 2)); /* nil */
    goto v0065;

v0065:
    if (v0304 == nil) goto v0069;
    v0304 = elt(env, 3); /* (-1 0 1) */
    { popv(6); return onevalue(v0304); }

v0069:
    v0304 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0304;
    v0304 = stack[-3];
    v0305 = sub1(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = stack[-4];
    v0304 = difference2(v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = Lminusp(nil, v0304);
    env = stack[-5];
    if (v0304 == nil) goto v0066;
    v0304 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0304); }

v0066:
    v0304 = stack[-4];
    v0304 = ncons(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    stack[-1] = v0304;
    stack[-2] = v0304;
    goto v0201;

v0201:
    v0304 = stack[-4];
    v0304 = add1(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    stack[-4] = v0304;
    v0304 = stack[-3];
    v0305 = sub1(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = stack[-4];
    v0304 = difference2(v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = Lminusp(nil, v0304);
    env = stack[-5];
    if (!(v0304 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0304 = stack[-4];
    v0304 = ncons(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = Lrplacd(nil, stack[0], v0304);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-5];
    v0304 = stack[-1];
    v0304 = qcdr(v0304);
    stack[-1] = v0304;
    goto v0201;

v0064:
    v0304 = v0149;
    goto v0065;

v0199:
    v0304 = qvalue(elt(env, 2)); /* nil */
    goto v0125;

v0239:
    v0304 = qvalue(elt(env, 1)); /* t */
    goto v0162;
/* error exit handlers */
v0306:
    popv(6);
    return nil;
}



/* Code for solvevars */

static Lisp_Object CC_solvevars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvevars");
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
    v0064 = v0000;
/* end of prologue */
    v0065 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0065;
    v0065 = v0064;
    fn = elt(env, 2); /* allbkern */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    stack[-1] = v0065;
    goto v0074;

v0074:
    v0065 = stack[-1];
    if (v0065 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    stack[0] = v0065;
    v0065 = stack[0];
    fn = elt(env, 3); /* constant_exprp */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    if (!(v0065 == nil)) goto v0034;
    v0064 = stack[0];
    v0065 = stack[-2];
    fn = elt(env, 4); /* ordad */
    v0065 = (*qfn2(fn))(qenv(fn), v0064, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    stack[-2] = v0065;
    goto v0034;

v0034:
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    goto v0074;
/* error exit handlers */
v0163:
    popv(4);
    return nil;
}



/* Code for constructinvolutivebasis */

static Lisp_Object CC_constructinvolutivebasis(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0316, v0317;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constructinvolutivebasis");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0316 = stack[0];
    v0186 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 6); /* polynomlistautoreduce */
    v0186 = (*qfn2(fn))(qenv(fn), v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    stack[0] = v0186;
    goto v0087;

v0087:
    v0186 = stack[0];
    v0186 = qcar(v0186);
    if (v0186 == nil) goto v0077;
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v0186 = stack[0];
    v0186 = qcar(v0186);
    fn = elt(env, 7); /* createtriple */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v0186 = (*qfn2(fn))(qenv(fn), stack[-1], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0087;

v0077:
    v0186 = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v0186 = qcar(v0186);
    if (v0186 == nil) goto v0318;
    fn = elt(env, 9); /* setqget */
    v0186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    stack[-6] = v0186;
    v0316 = stack[-6];
    v0186 = (Lisp_Object)17; /* 1 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    v0186 = qcar(v0186);
    stack[-4] = v0186;
    v0316 = stack[-6];
    v0186 = (Lisp_Object)17; /* 1 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    fn = elt(env, 10); /* normalform */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    stack[-3] = v0186;
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    stack[-2] = v0186;
    v0186 = stack[-2];
    if (v0186 == nil) goto v0077;
    v0186 = qvalue(elt(env, 4)); /* fluidbibasisnonzeronormalforms */
    v0186 = (Lisp_Object)((int32_t)(v0186) + 0x10);
    qvalue(elt(env, 4)) = v0186; /* fluidbibasisnonzeronormalforms */
    v0186 = qvalue(elt(env, 2)); /* nil */
    v0186 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    stack[0] = v0186;
    v0186 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v0186;
    goto v0213;

v0213:
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    if (v0186 == nil) goto v0319;
    v0186 = stack[-1];
    v0316 = qcar(v0186);
    v0186 = (Lisp_Object)17; /* 1 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    v0316 = qcar(v0186);
    v0186 = stack[-2];
    fn = elt(env, 11); /* monomisdivisibleby */
    v0186 = (*qfn2(fn))(qenv(fn), v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    if (v0186 == nil) goto v0147;
    v0186 = stack[-1];
    v0316 = qcar(v0186);
    v0186 = (Lisp_Object)1; /* 0 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    fn = elt(env, 12); /* setqdeletedescendants */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0316 = stack[0];
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v0186 = (*qfn2(fn))(qenv(fn), v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0186 = stack[-1];
    v0316 = qcar(v0186);
    v0186 = (Lisp_Object)17; /* 1 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    v0186 = qcar(v0186);
    fn = elt(env, 13); /* janettreedelete */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0316 = stack[-1];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0316 = Lrplaca(nil, v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = Lrplacd(nil, v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    goto v0213;

v0147:
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0213;

v0319:
    v0316 = stack[-4];
    v0186 = stack[-2];
    if (v0316 == v0186) goto v0020;
    v0186 = stack[-3];
    fn = elt(env, 7); /* createtriple */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    goto v0040;

v0040:
    v0186 = stack[0];
    fn = elt(env, 15); /* settcollectnonmultiprolongations */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0316 = stack[-2];
    v0186 = (Lisp_Object)1; /* 0 */
    v0316 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    v0186 = (Lisp_Object)1; /* 0 */
    v0186 = Leqn(nil, v0316, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    if (v0186 == nil) goto v0101;
    v0186 = qvalue(elt(env, 2)); /* nil */
    v0186 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    qvalue(elt(env, 3)) = v0186; /* fluidbibasissetq */
    goto v0077;

v0101:
    v0186 = stack[0];
    fn = elt(env, 16); /* setqinsertlist */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    goto v0077;

v0020:
    v0317 = stack[-3];
    v0316 = stack[-6];
    v0186 = (Lisp_Object)33; /* 2 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    fn = elt(env, 17); /* createtriplewithancestor */
    v0186 = (*qfn2(fn))(qenv(fn), v0317, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0186 = qvalue(elt(env, 5)); /* fluidbibasissett */
    v0317 = qcar(v0186);
    v0316 = stack[-6];
    v0186 = (Lisp_Object)49; /* 3 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    fn = elt(env, 18); /* triplesetprolongset */
    v0186 = (*qfn2(fn))(qenv(fn), v0317, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    goto v0040;

v0318:
    v0186 = qvalue(elt(env, 2)); /* nil */
    v0186 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    stack[0] = v0186;
    v0186 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v0186;
    goto v0221;

v0221:
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    if (v0186 == nil) goto v0320;
    v0317 = stack[0];
    v0186 = stack[-1];
    v0316 = qcar(v0186);
    v0186 = (Lisp_Object)17; /* 1 */
    v0186 = *(Lisp_Object *)((char *)v0316 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL)));
    fn = elt(env, 19); /* sortedpolynomlistinsert */
    v0186 = (*qfn2(fn))(qenv(fn), v0317, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-7];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0221;

v0320:
    v0316 = stack[0];
    v0186 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* polynomlistautoreduce */
        return (*qfn2(fn))(qenv(fn), v0316, v0186);
    }
/* error exit handlers */
v0010:
    popv(8);
    return nil;
}



/* Code for ofsf_facneq!* */

static Lisp_Object CC_ofsf_facneqH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0080, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facneq*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0080 = v0001;
    v0078 = v0000;
/* end of prologue */
    v0055 = qvalue(elt(env, 1)); /* !*rlsifac */
    if (v0055 == nil) goto v0203;
    v0055 = qvalue(elt(env, 2)); /* !*rlsiexpla */
    if (!(v0055 == nil)) goto v0143;
    v0055 = qvalue(elt(env, 3)); /* !*rlsiexpl */
    if (v0055 == nil) goto v0203;
    v0055 = elt(env, 4); /* and */
    if (!(v0080 == v0055)) goto v0203;

v0143:
    v0055 = v0078;
    {
        fn = elt(env, 7); /* ofsf_facneq */
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0203:
    v0055 = elt(env, 5); /* neq */
    v0080 = v0078;
    v0078 = qvalue(elt(env, 6)); /* nil */
    return list3(v0055, v0080, v0078);
}



/* Code for available!*p */

static Lisp_Object CC_availableHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for available*p");
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
    v0156 = stack[0];
    if (symbolp(v0156)) goto v0034;
    v0156 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0156 == nil)) goto v0303;
    v0156 = elt(env, 2); /* "this is no group identifier" */
    fn = elt(env, 4); /* lprie */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-1];
    goto v0303;

v0303:
    v0156 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-1];
    goto v0034;

v0034:
    v0156 = stack[0];
    v0203 = elt(env, 3); /* available */
        popv(2);
        return Lflagp(nil, v0156, v0203);
/* error exit handlers */
v0207:
    popv(2);
    return nil;
}



/* Code for qqe_length!-graph!-neighbors */

static Lisp_Object CC_qqe_lengthKgraphKneighbors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0295, v0288;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0295 = v0000;
/* end of prologue */
    v0288 = elt(env, 1); /* neighbors */
    return get(v0295, v0288);
}



/* Code for pasf_sacat */

static Lisp_Object MS_CDECL CC_pasf_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object v0143, v0144, v0074;
    argcheck(nargs, 3, "pasf_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0143 = v0002;
    v0144 = v0001;
    v0074 = v0000;
/* end of prologue */
    v0143 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0143);
}



/* Code for formopr */

static Lisp_Object MS_CDECL CC_formopr(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0200, v0209, v0300, v0237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formopr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formopr");
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
    v0200 = v0002;
    v0300 = v0001;
    v0237 = v0000;
/* end of prologue */
    v0209 = v0200;
    v0200 = elt(env, 1); /* symbolic */
    if (v0209 == v0200) goto v0240;
    stack[0] = elt(env, 4); /* operator */
    v0200 = v0237;
    v0200 = qcdr(v0200);
    v0209 = v0300;
    fn = elt(env, 5); /* mkarg */
    v0200 = (*qfn2(fn))(qenv(fn), v0200, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    {
        Lisp_Object v0293 = stack[0];
        popv(3);
        return list2(v0293, v0200);
    }

v0240:
    stack[-1] = elt(env, 2); /* flag */
    v0200 = v0237;
    v0200 = qcdr(v0200);
    stack[0] = Lmkquote(nil, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    v0200 = elt(env, 3); /* opfn */
    v0200 = Lmkquote(nil, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    {
        Lisp_Object v0153 = stack[-1];
        Lisp_Object v0165 = stack[0];
        popv(3);
        return list3(v0153, v0165, v0200);
    }
/* error exit handlers */
v0202:
    popv(3);
    return nil;
}



/* Code for powmtch */

static Lisp_Object MS_CDECL CC_powmtch(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0057, v0152, v0151, v0061;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powmtch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powmtch");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0056 = v0002;
    v0057 = v0001;
    v0152 = v0000;
/* end of prologue */

v0322:
    v0151 = v0057;
    if (v0151 == nil) goto v0144;
    v0061 = v0152;
    v0151 = v0057;
    v0151 = qcar(v0151);
    v0151 = Latsoc(nil, v0061, v0151);
    v0061 = v0151;
    v0151 = v0061;
    if (v0151 == nil) goto v0203;
    v0151 = v0061;
    v0061 = qcdr(v0151);
    v0151 = v0056;
    v0151 = (equal(v0061, v0151) ? lisp_true : nil);
    goto v0156;

v0156:
    if (v0151 == nil) goto v0235;
    v0151 = v0057;
    stack[0] = qcar(v0151);
    v0057 = qcdr(v0057);
    v0056 = CC_powmtch(env, 3, v0152, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    {
        Lisp_Object v0275 = stack[0];
        popv(1);
        return cons(v0275, v0056);
    }

v0235:
    v0057 = qcdr(v0057);
    goto v0322;

v0203:
    v0151 = qvalue(elt(env, 2)); /* t */
    goto v0156;

v0144:
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0056); }
/* error exit handlers */
v0241:
    popv(1);
    return nil;
}



/* Code for ps!:times!: */

static Lisp_Object CC_psTtimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0239, v0323, v0240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:times:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0239 = v0001;
    v0323 = v0000;
/* end of prologue */
    v0240 = elt(env, 1); /* times */
    {
        fn = elt(env, 2); /* ps!:operator!: */
        return (*qfnn(fn))(qenv(fn), 3, v0240, v0323, v0239);
    }
}



/* Code for poly!-remainder */

static Lisp_Object CC_polyKremainder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0162, v0239, v0323;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-remainder");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0162 = v0000;
/* end of prologue */
    v0323 = v0162;
    v0239 = elt(env, 1); /* remainder */
    v0162 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v0323, v0239, v0162);
    }
}



/* Code for dip!-nc!-ev!-prod */

static Lisp_Object MS_CDECL CC_dipKncKevKprod(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0139, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0155, v0063, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dip-nc-ev-prod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0139,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0062 = v0139;
    v0155 = v0002;
    v0063 = v0001;
    v0065 = v0000;
/* end of prologue */
    stack[-2] = v0063;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = v0062;
    v0062 = v0065;
    fn = elt(env, 2); /* bcprod */
    v0155 = (*qfn2(fn))(qenv(fn), v0062, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0062 = qvalue(elt(env, 1)); /* nil */
    v0062 = list2star(stack[0], v0155, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    {
        Lisp_Object v0163 = stack[-2];
        Lisp_Object v0129 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* dip!-nc!-ev!-prod1 */
        return (*qfnn(fn))(qenv(fn), 3, v0163, v0129, v0062);
    }
/* error exit handlers */
v0078:
    popv(4);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0139,
                         Lisp_Object v0145, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190, v0263, v0101, v0013, v0015, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0145,v0139,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0002,v0139,v0145);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0145;
    stack[-2] = v0139;
    stack[-3] = v0002;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0190 = stack[-5];
    stack[-6] = v0190;
    v0190 = stack[-6];
    if (v0190 == nil) goto v0323;
    v0190 = stack[-6];
    if (is_number(v0190)) goto v0078;
    v0190 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    stack[0] = v0190;
    v0190 = stack[-2];
    if (v0190 == nil) goto v0233;
    v0190 = stack[-6];
    if (!(symbolp(v0190))) goto v0233;
    v0263 = stack[-6];
    v0190 = elt(env, 5); /* rtype */
    v0190 = Lremprop(nil, v0263, v0190);
    env = stack[-7];
    v0263 = stack[-6];
    v0190 = elt(env, 6); /* avalue */
    v0190 = Lremprop(nil, v0263, v0190);
    env = stack[-7];
    goto v0233;

v0233:
    v0190 = stack[-6];
    fn = elt(env, 9); /* getrtype */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    v0101 = v0190;
    if (v0190 == nil) goto v0213;
    v0263 = v0101;
    v0190 = elt(env, 7); /* typeletfn */
    v0190 = get(v0263, v0190);
    env = stack[-7];
    v0263 = v0190;
    if (v0190 == nil) goto v0270;
    stack[-3] = v0263;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v0101;
    v0190 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    v0190 = list2(stack[-2], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    v0190 = list3star(stack[-5], stack[-1], stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    {
        Lisp_Object v0221 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v0221, v0190);
    }

v0270:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v0101;
    v0190 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    {
        Lisp_Object v0262 = stack[-3];
        Lisp_Object v0131 = stack[-1];
        Lisp_Object v0136 = stack[0];
        Lisp_Object v0137 = stack[-2];
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v0262, v0131, v0136, v0137, v0190);
    }

v0213:
    v0190 = stack[0];
    if (v0190 == nil) goto v0022;
    v0263 = stack[0];
    v0190 = elt(env, 8); /* yetunknowntype */
    if (v0263 == v0190) goto v0022;
    v0263 = stack[0];
    v0190 = elt(env, 7); /* typeletfn */
    v0190 = get(v0263, v0190);
    env = stack[-7];
    v0263 = v0190;
    if (v0190 == nil) goto v0138;
    stack[-3] = v0263;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v0263 = stack[-2];
    v0190 = stack[0];
    v0190 = list2(v0263, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    v0190 = list3star(stack[-5], stack[-4], stack[-1], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-7];
    {
        Lisp_Object v0019 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v0019, v0190);
    }

v0138:
    v0015 = stack[-6];
    v0013 = stack[-4];
    v0101 = qvalue(elt(env, 3)); /* nil */
    v0263 = stack[-2];
    v0190 = stack[0];
    {
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v0015, v0013, v0101, v0263, v0190);
    }

v0022:
    v0014 = stack[-5];
    v0015 = stack[-4];
    v0013 = stack[-3];
    v0101 = stack[-6];
    v0263 = stack[-2];
    v0190 = stack[-1];
    fn = elt(env, 12); /* letscalar */
    v0190 = (*qfnn(fn))(qenv(fn), 6, v0014, v0015, v0013, v0101, v0263, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    v0190 = nil;
    { popv(8); return onevalue(v0190); }

v0078:
    v0015 = elt(env, 1); /* "Substitution for" */
    v0013 = stack[-5];
    v0101 = elt(env, 2); /* "not allowed" */
    v0263 = qvalue(elt(env, 3)); /* nil */
    v0190 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0015, v0013, v0101, v0263, v0190);
    }

v0323:
    v0190 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0190;
    v0015 = elt(env, 1); /* "Substitution for" */
    v0013 = stack[-5];
    v0101 = elt(env, 2); /* "not allowed" */
    v0263 = qvalue(elt(env, 3)); /* nil */
    v0190 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0015, v0013, v0101, v0263, v0190);
    }
/* error exit handlers */
v0222:
    popv(8);
    return nil;
}



/* Code for find_bubles1_coeff */

static Lisp_Object MS_CDECL CC_find_bubles1_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0139, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_bubles1_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0139,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0139;
    stack[0] = v0002;
    stack[-1] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0322:
    v0234 = stack[-4];
    if (v0234 == nil) goto v0288;
    v0234 = stack[-4];
    v0128 = qcar(v0234);
    v0234 = stack[0];
    fn = elt(env, 1); /* find_bubles1 */
    v0234 = (*qfn2(fn))(qenv(fn), v0128, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[-2] = v0234;
    v0234 = stack[-4];
    stack[-4] = qcdr(v0234);
    v0234 = stack[-2];
    v0128 = qcdr(v0234);
    v0234 = stack[-1];
    stack[-1] = cons(v0128, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0234 = stack[-2];
    v0234 = qcar(v0234);
    if (v0234 == nil) goto v0293;
    v0234 = stack[-2];
    v0128 = qcar(v0234);
    v0234 = stack[-3];
    v0234 = cons(v0128, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    goto v0055;

v0055:
    stack[-3] = v0234;
    goto v0322;

v0293:
    v0234 = stack[-3];
    goto v0055;

v0288:
    v0128 = stack[-3];
    v0234 = stack[-1];
    popv(6);
    return cons(v0128, v0234);
/* error exit handlers */
v0056:
    popv(6);
    return nil;
}



/* Code for dependsp */

static Lisp_Object CC_dependsp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsp");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0084 = stack[0];
    if (v0084 == nil) goto v0143;
    v0198 = stack[-1];
    v0084 = stack[0];
    fn = elt(env, 5); /* depends */
    v0084 = (*qfn2(fn))(qenv(fn), v0198, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-3];
    if (!(v0084 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0084 = stack[-1];
    if (!consp(v0084)) goto v0156;
    v0084 = stack[-1];
    v0198 = qcar(v0084);
    v0084 = elt(env, 3); /* !*sq */
    if (v0198 == v0084) goto v0300;
    v0084 = stack[-1];
    fn = elt(env, 6); /* taylorp */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-3];
    if (v0084 == nil) goto v0289;
    v0198 = stack[0];
    v0084 = qvalue(elt(env, 4)); /* taylorvariable */
    if (v0198 == v0084) goto v0211;
    v0084 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0084); }

v0211:
    v0084 = qvalue(elt(env, 4)); /* taylorvariable */
    { popv(4); return onevalue(v0084); }

v0289:
    v0198 = stack[-1];
    v0084 = stack[0];
    if (equal(v0198, v0084)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0084 = stack[-1];
    stack[-2] = v0084;
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    stack[-1] = v0084;
    goto v0130;

v0130:
    v0084 = stack[-1];
    if (v0084 == nil) goto v0231;
    v0084 = stack[-1];
    v0198 = qcar(v0084);
    v0084 = stack[0];
    v0084 = CC_dependsp(env, v0198, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-3];
    if (!(v0084 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    stack[-1] = v0084;
    goto v0130;

v0231:
    v0084 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0084); }

v0300:
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    v0198 = qcar(v0084);
    v0084 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* involvesq */
        return (*qfn2(fn))(qenv(fn), v0198, v0084);
    }

v0156:
    v0198 = stack[-1];
    v0084 = stack[0];
    if (v0198 == v0084) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0084 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0084); }

v0143:
    v0084 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0084); }
/* error exit handlers */
v0330:
    popv(4);
    return nil;
}



/* Code for setmod */

static Lisp_Object CC_setmod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmod");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    v0213 = stack[0];
    if (!consp(v0213)) goto v0144;
    v0213 = stack[0];
    v0213 = qcar(v0213);
    stack[0] = v0213;
    goto v0144;

v0144:
    v0213 = stack[0];
    fn = elt(env, 7); /* reval */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[0] = v0213;
    v0213 = stack[0];
    v0213 = integerp(v0213);
    if (v0213 == nil) goto v0067;
    v0294 = stack[0];
    v0213 = (Lisp_Object)1; /* 0 */
    v0213 = (Lisp_Object)greaterp2(v0294, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0213 = v0213 ? lisp_true : nil;
    env = stack[-2];
    if (v0213 == nil) goto v0067;
    v0213 = stack[0];
    fn = elt(env, 8); /* primep */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    if (v0213 == nil) goto v0200;
    v0294 = elt(env, 2); /* (!:mod!:) */
    v0213 = elt(env, 3); /* field */
    v0213 = Lflag(nil, v0294, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    goto v0154;

v0154:
    v0213 = stack[0];
    fn = elt(env, 9); /* set!-general!-modulus */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    goto v0145;

v0145:
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    { popv(3); return onevalue(v0213); }

v0200:
    v0294 = elt(env, 2); /* (!:mod!:) */
    v0213 = elt(env, 3); /* field */
    v0213 = Lremflag(nil, v0294, v0213);
    env = stack[-2];
    goto v0154;

v0067:
    v0294 = stack[0];
    v0213 = (Lisp_Object)1; /* 0 */
    if (v0294 == v0213) goto v0068;
    v0213 = stack[0];
    v0213 = (v0213 == nil ? lisp_true : nil);
    goto v0233;

v0233:
    if (v0213 == nil) goto v0057;
    v0213 = qvalue(elt(env, 5)); /* current!-modulus */
    goto v0145;

v0057:
    v0294 = stack[0];
    v0213 = elt(env, 6); /* "modulus" */
    fn = elt(env, 10); /* typerr */
    v0213 = (*qfn2(fn))(qenv(fn), v0294, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0213 = nil;
    goto v0145;

v0068:
    v0213 = qvalue(elt(env, 4)); /* t */
    goto v0233;
/* error exit handlers */
v0121:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    popv(3);
    return nil;
}



/* Code for bdstest */

static Lisp_Object CC_bdstest(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bdstest");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0199 = stack[0];
    v0199 = qcar(v0199);
    fn = elt(env, 1); /* r2bf */
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-2];
    v0199 = stack[0];
    v0199 = qcdr(v0199);
    fn = elt(env, 1); /* r2bf */
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-2];
    stack[0] = v0199;
    fn = elt(env, 3); /* equal!: */
    v0199 = (*qfn2(fn))(qenv(fn), stack[-1], v0199);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    if (!(v0199 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0199 = nil;
    { popv(3); return onevalue(v0199); }
/* error exit handlers */
v0156:
    popv(3);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199, v0210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0199 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v0199; /* dmode!* */
    v0199 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    stack[-1] = v0199;
    v0210 = stack[-1];
    v0199 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v0199 = (*qfn2(fn))(qenv(fn), v0210, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    v0199 = stack[-1];
    v0210 = qcar(v0199);
    v0199 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v0199 = (*qfn2(fn))(qenv(fn), v0210, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0199); }
/* error exit handlers */
v0208:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for dvfsf_susitf */

static Lisp_Object CC_dvfsf_susitf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object v0145, v0143;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0145 = v0001;
    v0143 = v0000;
/* end of prologue */
    return onevalue(v0143);
}



/* Code for initmonomials */

static Lisp_Object MS_CDECL CC_initmonomials(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initmonomials");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initmonomials");
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
    v0163 = qvalue(elt(env, 1)); /* fluidbibasisvariables */
    v0163 = Llength(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0163; /* fluidbibasisnumberofvariables */
    v0163 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v0163 = Lmkvect(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0163; /* fluidbibasissinglevariablemonomialss 
*/
    v0163 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0163;
    goto v0054;

v0054:
    v0129 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v0163 = stack[-2];
    v0163 = difference2(v0129, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0163 = Lminusp(nil, v0163);
    env = stack[-3];
    if (v0163 == nil) goto v0076;
    v0163 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0163; /* fluidbibasistripleid */
    v0163 = nil;
    { popv(4); return onevalue(v0163); }

v0076:
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissinglevariablemonomialss 
*/
    stack[0] = stack[-2];
    v0163 = stack[-2];
    fn = elt(env, 6); /* createsinglevariablemonom */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0163;
    v0163 = stack[-2];
    v0163 = add1(v0163);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    stack[-2] = v0163;
    goto v0054;
/* error exit handlers */
v0321:
    popv(4);
    return nil;
}



/* Code for rl_simpatom */

static Lisp_Object CC_rl_simpatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0331, v0332, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpatom");
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
    v0331 = stack[0];
    if (!(v0331 == nil)) goto v0144;
    v0332 = elt(env, 1); /* "nil" */
    v0331 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    goto v0144;

v0144:
    v0331 = stack[0];
    if (!(is_number(v0331))) goto v0053;
    v0332 = elt(env, 3); /* "number" */
    v0331 = stack[0];
    v0332 = list2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0331 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    goto v0053;

v0053:
    v0331 = stack[0];
    v0331 = Lstringp(nil, v0331);
    env = stack[-1];
    if (v0331 == nil) goto v0080;
    v0332 = elt(env, 4); /* "string" */
    v0331 = stack[0];
    v0332 = list2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0331 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    goto v0080;

v0080:
    v0331 = stack[0];
    fn = elt(env, 12); /* rl_gettype */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0169 = v0331;
    if (v0331 == nil) goto v0214;
    v0332 = v0169;
    v0331 = elt(env, 5); /* (logical equation scalar slprog) */
    v0331 = Lmemq(nil, v0332, v0331);
    if (v0331 == nil) goto v0292;
    v0332 = stack[0];
    v0331 = elt(env, 6); /* avalue */
    v0331 = get(v0332, v0331);
    env = stack[-1];
    v0331 = qcdr(v0331);
    v0331 = qcar(v0331);
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v0331);
    }

v0292:
    v0332 = v0169;
    v0331 = stack[0];
    v0332 = list2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0331 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    goto v0214;

v0214:
    v0332 = stack[0];
    v0331 = elt(env, 7); /* true */
    if (v0332 == v0331) goto v0035;
    v0332 = stack[0];
    v0331 = elt(env, 9); /* false */
    v0331 = (v0332 == v0331 ? lisp_true : nil);
    goto v0243;

v0243:
    if (!(v0331 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0331 = stack[0];
    v0331 = Lboundp(nil, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    if (v0331 == nil) goto v0196;
    v0331 = stack[0];
    fn = elt(env, 14); /* eval */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v0331);
    }

v0196:
    v0332 = elt(env, 10); /* "unbound id" */
    v0331 = stack[0];
    v0332 = list2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0331 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    v0331 = nil;
    { popv(2); return onevalue(v0331); }

v0035:
    v0331 = qvalue(elt(env, 8)); /* t */
    goto v0243;
/* error exit handlers */
v0039:
    popv(2);
    return nil;
}



/* Code for giminusp!: */

static Lisp_Object CC_giminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0076, v0156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giminusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0000;
/* end of prologue */
    v0210 = v0076;
    v0210 = qcdr(v0210);
    v0156 = qcar(v0210);
    v0210 = (Lisp_Object)1; /* 0 */
    if (v0156 == v0210) goto v0145;
    v0210 = v0076;
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
        return Lminusp(nil, v0210);

v0145:
    v0210 = v0076;
    v0210 = qcdr(v0210);
    v0210 = qcdr(v0210);
        return Lminusp(nil, v0210);
}



/* Code for dependsl */

static Lisp_Object CC_dependsl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsl");
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

v0322:
    v0238 = stack[0];
    if (v0238 == nil) goto v0143;
    v0062 = stack[-1];
    v0238 = stack[0];
    v0238 = qcar(v0238);
    fn = elt(env, 2); /* depends */
    v0238 = (*qfn2(fn))(qenv(fn), v0062, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    if (!(v0238 == nil)) { popv(3); return onevalue(v0238); }
    v0062 = stack[-1];
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    stack[-1] = v0062;
    stack[0] = v0238;
    goto v0322;

v0143:
    v0238 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0238); }
/* error exit handlers */
v0065:
    popv(3);
    return nil;
}



/* Code for get_rep_of_generator */

static Lisp_Object CC_get_rep_of_generator(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0296, v0297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_of_generator");
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
    v0297 = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0296 = stack[-2];
    v0059 = elt(env, 1); /* id */
    if (v0296 == v0059) goto v0295;
    v0059 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v0059;
    v0059 = v0297;
    stack[0] = v0059;
    goto v0208;

v0208:
    v0059 = stack[-3];
    if (v0059 == nil) goto v0078;
    v0059 = qvalue(elt(env, 2)); /* nil */
    goto v0063;

v0063:
    if (v0059 == nil) goto v0203;
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0296 = qcar(v0059);
    v0059 = stack[-2];
    if (!(equal(v0296, v0059))) goto v0202;
    v0059 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v0059;
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    stack[-1] = v0059;
    goto v0202;

v0202:
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0208;

v0203:
    v0059 = stack[-3];
    if (!(v0059 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0059 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0059 == nil)) goto v0213;
    v0059 = elt(env, 5); /* " error in get rep of generators" */
    fn = elt(env, 6); /* lprie */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-4];
    goto v0213;

v0213:
    v0059 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0059 = nil;
    { popv(5); return onevalue(v0059); }

v0078:
    v0059 = stack[0];
    v0296 = Llength(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-4];
    v0059 = (Lisp_Object)1; /* 0 */
    v0059 = (Lisp_Object)greaterp2(v0296, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0059 = v0059 ? lisp_true : nil;
    env = stack[-4];
    goto v0063;

v0295:
    v0059 = v0297;
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    fn = elt(env, 7); /* get!+row!+nr */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v0059);
    }
/* error exit handlers */
v0082:
    popv(5);
    return nil;
}



/* Code for mri_irsplit */

static Lisp_Object CC_mri_irsplit(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0290, v0291, v0276;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_irsplit");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v0276 = v0000;
/* end of prologue */
    v0291 = v0276;
    v0290 = elt(env, 1); /* floor */
    if (!consp(v0291)) goto v0081;
    v0291 = qcar(v0291);
    if (!(v0291 == v0290)) goto v0081;
    v0290 = v0276;
    v0290 = qcdr(v0290);
    v0290 = qcar(v0290);
    fn = elt(env, 2); /* simp */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0290 = qcar(v0290);
    fn = elt(env, 3); /* mri_simplfloor */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    fn = elt(env, 4); /* mri_irsplit1 */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0291 = v0290;
    v0290 = v0291;
    stack[-1] = qcar(v0290);
    v0290 = v0291;
    v0290 = qcdr(v0290);
    if (v0290 == nil) goto v0209;
    stack[0] = elt(env, 1); /* floor */
    v0290 = v0291;
    v0290 = qcdr(v0290);
    fn = elt(env, 5); /* prepf */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0290 = list2(stack[0], v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    fn = elt(env, 6); /* !*a2k */
    v0276 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0291 = (Lisp_Object)17; /* 1 */
    v0290 = (Lisp_Object)17; /* 1 */
    v0290 = acons(v0276, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0290 = ncons(v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    goto v0163;

v0163:
    {
        Lisp_Object v0152 = stack[-1];
        popv(3);
        return cons(v0152, v0290);
    }

v0209:
    v0290 = nil;
    goto v0163;

v0081:
    v0291 = (Lisp_Object)17; /* 1 */
    v0290 = (Lisp_Object)17; /* 1 */
    v0290 = acons(v0276, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0290 = ncons(v0290);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    popv(3);
    return ncons(v0290);
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for qqe_length!-graph!-marked */

static Lisp_Object CC_qqe_lengthKgraphKmarked(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0295, v0288;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0295 = v0000;
/* end of prologue */
    v0288 = elt(env, 1); /* blockmark */
    return get(v0295, v0288);
}



/* Code for delqip */

static Lisp_Object CC_delqip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0062, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delqip");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0155 = v0000;
/* end of prologue */
    v0238 = stack[0];
    if (!consp(v0238)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0062 = v0155;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    if (v0062 == v0238) goto v0125;
    v0062 = v0155;
    v0238 = stack[0];
    fn = elt(env, 1); /* delqip1 */
    v0238 = (*qfn2(fn))(qenv(fn), v0062, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v0125:
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    { popv(1); return onevalue(v0238); }
/* error exit handlers */
v0065:
    popv(1);
    return nil;
}



/* Code for crn!:onep */

static Lisp_Object CC_crnTonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0207, v0154;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:onep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0154 = v0000;
/* end of prologue */
    v0208 = v0154;
    v0208 = qcdr(v0208);
    v0208 = qcdr(v0208);
    v0207 = qcar(v0208);
    v0208 = (Lisp_Object)1; /* 0 */
    if (v0207 == v0208) goto v0240;
    v0208 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0208);

v0240:
    v0208 = v0154;
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    v0207 = elt(env, 1); /* (1 . 1) */
    v0208 = (equal(v0208, v0207) ? lisp_true : nil);
    return onevalue(v0208);
}



/* Code for pm!:gensym */

static Lisp_Object MS_CDECL CC_pmTgensym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:gensym");
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
    stack[-1] = elt(env, 1); /* !? */
    stack[0] = elt(env, 2); /* !_ */
    v0323 = qvalue(elt(env, 3)); /* pm!:gensym!-count!* */
    v0323 = add1(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0323; /* pm!:gensym!-count!* */
    v0323 = Lexplode(nil, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0323 = list2star(stack[-1], stack[0], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0054;
        popv(3);
        return Lcompress(nil, v0323);
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for mkset */

static Lisp_Object CC_mkset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkset");
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
    v0144 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* getrlist */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[0];
    fn = elt(env, 2); /* delete!-dups */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* make!-set */
        return (*qfn1(fn))(qenv(fn), v0144);
    }
/* error exit handlers */
v0074:
    popv(1);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0302, v0044, v0333;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0001;
    v0302 = v0000;
/* end of prologue */
    stack[-7] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v0044 = (*qfn1(fn))(qenv(fn), v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    v0302 = v0044;
    v0044 = qcar(v0044);
    stack[-5] = v0044;
    v0302 = qcdr(v0302);
    v0044 = v0302;
    v0044 = qcar(v0044);
    stack[-4] = v0044;
    v0302 = qcdr(v0302);
    stack[-3] = v0302;
    goto v0054;

v0054:
    v0302 = stack[-3];
    if (v0302 == nil) goto v0133;
    v0302 = stack[-3];
    v0302 = qcar(v0302);
    stack[-2] = v0302;
    v0302 = stack[-5];
    v0302 = sub1(v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    stack[-5] = v0302;
    v0302 = stack[-4];
    v0302 = qcdr(v0302);
    v0044 = qcar(v0302);
    v0302 = (Lisp_Object)1; /* 0 */
    if (v0044 == v0302) goto v0164;
    v0333 = stack[-5];
    v0044 = stack[-4];
    v0302 = stack[-7];
    v0302 = acons(v0333, v0044, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    stack[-7] = v0302;
    goto v0164;

v0164:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v0302 = stack[-6];
    v0302 = qcdr(v0302);
    v0044 = qcar(v0302);
    v0302 = stack[-4];
    v0302 = qcdr(v0302);
    v0302 = qcar(v0302);
    stack[0] = times2(v0044, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    v0302 = stack[-6];
    v0302 = qcdr(v0302);
    v0044 = qcdr(v0302);
    v0302 = stack[-4];
    v0302 = qcdr(v0302);
    v0302 = qcdr(v0302);
    v0302 = plus2(v0044, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    v0302 = list2star(stack[-1], stack[0], v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    stack[-4] = v0302;
    v0302 = stack[-2];
    if (v0302 == nil) goto v0060;
    v0044 = stack[-2];
    v0302 = stack[-4];
    fn = elt(env, 4); /* plus!: */
    v0302 = (*qfn2(fn))(qenv(fn), v0044, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-8];
    stack[-4] = v0302;
    goto v0060;

v0060:
    v0302 = stack[-3];
    v0302 = qcdr(v0302);
    stack[-3] = v0302;
    goto v0054;

v0133:
    v0044 = stack[-4];
    v0302 = stack[-7];
    popv(9);
    return cons(v0044, v0302);
/* error exit handlers */
v0301:
    popv(9);
    return nil;
}



/* Code for forttab */

static Lisp_Object CC_forttab(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0321, v0200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for forttab");
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
    v0200 = qvalue(elt(env, 1)); /* fortlinelen!* */
    v0321 = qvalue(elt(env, 2)); /* minfortlinelen!* */
    v0321 = difference2(v0200, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-1];
    fn = elt(env, 5); /* min0 */
    v0200 = (*qfn2(fn))(qenv(fn), stack[0], v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-1];
    v0321 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 6); /* max */
    v0321 = (*qfn2(fn))(qenv(fn), v0200, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0321; /* !*fortcurrind!* */
    v0200 = qvalue(elt(env, 3)); /* !*fortcurrind!* */
    v0321 = qvalue(elt(env, 4)); /* !*posn!* */
    v0200 = difference2(v0200, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-1];
    stack[0] = v0200;
    v0321 = (Lisp_Object)1; /* 0 */
    v0321 = (Lisp_Object)greaterp2(v0200, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0321 = v0321 ? lisp_true : nil;
    env = stack[-1];
    if (v0321 == nil) goto v0156;
    v0321 = stack[0];
    fn = elt(env, 7); /* nspaces */
    v0321 = (*qfn1(fn))(qenv(fn), v0321);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* pprin2 */
        return (*qfn1(fn))(qenv(fn), v0321);
    }

v0156:
    v0321 = nil;
    { popv(2); return onevalue(v0321); }
/* error exit handlers */
v0300:
    popv(2);
    return nil;
}



setup_type const u46_setup[] =
{
    {"pst_d",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d},
    {"rlval",                   too_few_2,      CC_rlval,      wrong_no_2},
    {"ofsf_sminsert",           too_few_2,      CC_ofsf_sminsert,wrong_no_2},
    {"gcdk",                    too_few_2,      CC_gcdk,       wrong_no_2},
    {"evaluateuconst",          CC_evaluateuconst,too_many_1,  wrong_no_1},
    {"quotfx1",                 too_few_2,      CC_quotfx1,    wrong_no_2},
    {"ratpoly_toaf",            CC_ratpoly_toaf,too_many_1,    wrong_no_1},
    {"tryreduction",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_tryreduction},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"vdpappendmon",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpappendmon},
    {"texaeval",                CC_texaeval,    too_many_1,    wrong_no_1},
    {"expt-separate",           too_few_2,      CC_exptKseparate,wrong_no_2},
    {"rappend",                 CC_rappend,     too_many_1,    wrong_no_1},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"solvevars",               CC_solvevars,   too_many_1,    wrong_no_1},
    {"constructinvolutivebasis",too_few_2,      CC_constructinvolutivebasis,wrong_no_2},
    {"ofsf_facneq*",            too_few_2,      CC_ofsf_facneqH,wrong_no_2},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"formopr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formopr},
    {"powmtch",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powmtch},
    {"ps:times:",               too_few_2,      CC_psTtimesT,  wrong_no_2},
    {"poly-remainder",          CC_polyKremainder,too_many_1,  wrong_no_1},
    {"dip-nc-ev-prod",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"find_bubles1_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles1_coeff},
    {"dependsp",                too_few_2,      CC_dependsp,   wrong_no_2},
    {"setmod",                  CC_setmod,      too_many_1,    wrong_no_1},
    {"bdstest",                 CC_bdstest,     too_many_1,    wrong_no_1},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"dvfsf_susitf",            too_few_2,      CC_dvfsf_susitf,wrong_no_2},
    {"initmonomials",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_initmonomials},
    {"rl_simpatom",             CC_rl_simpatom, too_many_1,    wrong_no_1},
    {"giminusp:",               CC_giminuspT,   too_many_1,    wrong_no_1},
    {"dependsl",                too_few_2,      CC_dependsl,   wrong_no_2},
    {"get_rep_of_generator",    too_few_2,      CC_get_rep_of_generator,wrong_no_2},
    {"mri_irsplit",             CC_mri_irsplit, too_many_1,    wrong_no_1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"crn:onep",                CC_crnTonep,    too_many_1,    wrong_no_1},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"mkset",                   CC_mkset,       too_many_1,    wrong_no_1},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"forttab",                 CC_forttab,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u46", (two_args *)"6621 4420391 2519153", 0}
};

/* end of generated code */
