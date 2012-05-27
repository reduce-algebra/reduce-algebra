
/* $destdir\u46.c        Machine generated C code */

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


/* Code for letscalar */

static Lisp_Object MS_CDECL CC_letscalar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100, v101, v102, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "letscalar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letscalar");
#endif
    if (stack >= stacklimit)
    {
        push6(v5,v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v3,v4,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v5;
    stack[-3] = v4;
    stack[-4] = v3;
    stack[-5] = v2;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    v99 = stack[-4];
    if (!consp(v99)) goto v105;
    v99 = stack[-4];
    v99 = qcar(v99);
    if (symbolp(v99)) goto v106;
    v103 = elt(env, 1); /* "Syntax error:" */
    v102 = stack[-7];
    v101 = elt(env, 2); /* "invalid" */
    v100 = qvalue(elt(env, 3)); /* nil */
    v99 = elt(env, 4); /* hold */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v103, v102, v101, v100, v99);
    }

v106:
    v99 = stack[-4];
    v100 = qcar(v99);
    v99 = elt(env, 5); /* df */
    if (v100 == v99) goto v107;
    v99 = stack[-4];
    v99 = qcar(v99);
    fn = elt(env, 32); /* getrtype */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    if (v99 == nil) goto v109;
    v99 = stack[-4];
    fn = elt(env, 33); /* reval */
    v102 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v101 = stack[-6];
    v100 = stack[-5];
    v99 = stack[-3];
    {
        popv(10);
        fn = elt(env, 34); /* let2 */
        return (*qfnn(fn))(qenv(fn), 4, v102, v101, v100, v99);
    }

v109:
    v99 = stack[-4];
    v100 = qcar(v99);
    v99 = elt(env, 6); /* simpfn */
    v99 = get(v100, v99);
    env = stack[-9];
    if (!(v99 == nil)) goto v110;
    v99 = stack[-4];
    v100 = qcar(v99);
    v99 = elt(env, 7); /* "operator" */
    fn = elt(env, 35); /* redmsg */
    v99 = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = stack[-4];
    v99 = qcar(v99);
    fn = elt(env, 36); /* mkop */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v103 = stack[-7];
    v102 = stack[-6];
    v101 = stack[-5];
    v100 = stack[-3];
    v99 = stack[-2];
    {
        popv(10);
        fn = elt(env, 37); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v103, v102, v101, v100, v99);
    }

v110:
    v100 = stack[-4];
    v99 = elt(env, 23); /* expt */
    if (!consp(v100)) goto v111;
    v100 = qcar(v100);
    if (!(v100 == v99)) goto v111;
    v99 = stack[-4];
    v99 = qcdr(v99);
    v99 = qcdr(v99);
    v100 = qcar(v99);
    v99 = qvalue(elt(env, 24)); /* frlis!* */
    v99 = Lmemq(nil, v100, v99);
    goto v112;

v112:
    if (v99 == nil) goto v113;
    stack[-8] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v101 = stack[-4];
    v100 = (Lisp_Object)17; /* 1 */
    v99 = (Lisp_Object)17; /* 1 */
    v99 = acons(v101, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = (Lisp_Object)17; /* 1 */
    v101 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v100 = stack[-3];
    v99 = stack[-2];
    fn = elt(env, 38); /* letexprn */
    v99 = (*qfnn(fn))(qenv(fn), 6, stack[-8], stack[-1], stack[0], v101, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    goto v114;

v114:
    v99 = qvalue(elt(env, 21)); /* t */
    stack[0] = qvalue(elt(env, 28)); /* !*precise */
    qvalue(elt(env, 28)) = v99; /* !*precise */
    v99 = stack[-4];
    fn = elt(env, 39); /* simp0 */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-9];
    stack[-4] = v99;
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    v99 = stack[-4];
    v99 = qcar(v99);
    if (!consp(v99)) goto v116;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v99 = (consp(v99) ? nil : lisp_true);
    goto v117;

v117:
    if (v99 == nil) goto v118;
    v103 = elt(env, 29); /* "Substitution for" */
    v102 = stack[-7];
    v101 = elt(env, 30); /* "not allowed" */
    v100 = qvalue(elt(env, 3)); /* nil */
    v99 = qvalue(elt(env, 21)); /* t */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v103, v102, v101, v100, v99);
    }

v118:
    v104 = stack[-7];
    v103 = stack[-6];
    v102 = stack[-5];
    v101 = stack[-4];
    v100 = stack[-3];
    v99 = stack[-2];
    {
        popv(10);
        fn = elt(env, 38); /* letexprn */
        return (*qfnn(fn))(qenv(fn), 6, v104, v103, v102, v101, v100, v99);
    }

v116:
    v99 = qvalue(elt(env, 21)); /* t */
    goto v117;

v113:
    v100 = stack[-4];
    v99 = elt(env, 25); /* sqrt */
    if (!consp(v100)) goto v114;
    v100 = qcar(v100);
    if (!(v100 == v99)) goto v114;
    v99 = qvalue(elt(env, 21)); /* t */
    qvalue(elt(env, 26)) = v99; /* !*sqrtrulep */
    v101 = elt(env, 23); /* expt */
    v99 = stack[-4];
    v99 = qcdr(v99);
    v100 = qcar(v99);
    v99 = elt(env, 27); /* (quotient 1 2) */
    v102 = list3(v101, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v101 = stack[-6];
    v100 = stack[-5];
    v99 = stack[-3];
    fn = elt(env, 34); /* let2 */
    v99 = (*qfnn(fn))(qenv(fn), 4, v102, v101, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    goto v114;

v111:
    v99 = qvalue(elt(env, 3)); /* nil */
    goto v112;

v107:
    v103 = stack[-7];
    v102 = stack[-6];
    v101 = stack[-5];
    v100 = stack[-4];
    v99 = stack[-3];
    fn = elt(env, 40); /* letdf */
    v99 = (*qfnn(fn))(qenv(fn), 5, v103, v102, v101, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    if (v99 == nil) goto v110;
    v99 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v99); }

v105:
    v99 = stack[-3];
    if (v99 == nil) goto v119;
    v99 = qvalue(elt(env, 3)); /* nil */
    goto v120;

v120:
    if (v99 == nil) goto v110;
    v100 = stack[-4];
    v99 = elt(env, 8); /* avalue */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 9); /* rtype */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v99 = stack[-4];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = elt(env, 10); /* antisymmetric */
    v99 = Lremflag(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 11); /* infix */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 12); /* kvalue */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v99 = stack[-4];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = elt(env, 13); /* linear */
    v99 = Lremflag(nil, v100, v99);
    env = stack[-9];
    v99 = stack[-4];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = elt(env, 14); /* noncom */
    v99 = Lremflag(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 15); /* op */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 16); /* opmtch */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = elt(env, 6); /* simpfn */
    v99 = Lremprop(nil, v100, v99);
    env = stack[-9];
    v99 = stack[-4];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = elt(env, 17); /* symmetric */
    v99 = Lremflag(nil, v100, v99);
    env = stack[-9];
    v100 = stack[-4];
    v99 = qvalue(elt(env, 18)); /* wtl!* */
    fn = elt(env, 41); /* delasc */
    v99 = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    qvalue(elt(env, 18)) = v99; /* wtl!* */
    v100 = stack[-4];
    v99 = elt(env, 19); /* opfn */
    v99 = Lflagp(nil, v100, v99);
    env = stack[-9];
    if (v99 == nil) goto v121;
    v99 = stack[-4];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = elt(env, 19); /* opfn */
    v99 = Lremflag(nil, v100, v99);
    env = stack[-9];
    v99 = stack[-4];
    v99 = Lremd(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    goto v121;

v121:
    v100 = qvalue(elt(env, 20)); /* !*sqvar!* */
    v99 = qvalue(elt(env, 3)); /* nil */
    v99 = Lrplaca(nil, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    v99 = qvalue(elt(env, 21)); /* t */
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    qvalue(elt(env, 20)) = v99; /* !*sqvar!* */
    v99 = qvalue(elt(env, 3)); /* nil */
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-9];
    qvalue(elt(env, 22)) = v99; /* alglist!* */
    v99 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v99); }

v119:
    v99 = stack[-5];
    v99 = (v99 == nil ? lisp_true : nil);
    goto v120;
/* error exit handlers */
v115:
    env = stack[-9];
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    popv(10);
    return nil;
v108:
    popv(10);
    return nil;
}



/* Code for delqip */

static Lisp_Object CC_delqip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delqip");
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
    v96 = v0;
/* end of prologue */
    v94 = stack[0];
    if (!consp(v94)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v95 = v96;
    v94 = stack[0];
    v94 = qcar(v94);
    if (v95 == v94) goto v126;
    v95 = v96;
    v94 = stack[0];
    fn = elt(env, 1); /* delqip1 */
    v94 = (*qfn2(fn))(qenv(fn), v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v98;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v126:
    v94 = stack[0];
    v94 = qcdr(v94);
    { popv(1); return onevalue(v94); }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for unary */

static Lisp_Object CC_unary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unary");
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
    v96 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v96 = elt(env, 2); /* "<" */
    v96 = Lprinc(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v96 = stack[0];
    v96 = Lprinc(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v96 = elt(env, 3); /* "/>" */
    v96 = Lprinc(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v97 = qvalue(elt(env, 4)); /* indent */
    v96 = (Lisp_Object)49; /* 3 */
    v96 = plus2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    qvalue(elt(env, 4)) = v96; /* indent */
    v96 = stack[-1];
    v96 = qcar(v96);
    fn = elt(env, 7); /* expression */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v97 = qvalue(elt(env, 4)); /* indent */
    v96 = (Lisp_Object)49; /* 3 */
    v96 = difference2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    qvalue(elt(env, 4)) = v96; /* indent */
    v96 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    v96 = nil;
    { popv(3); return onevalue(v96); }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for pm!:gensym */

static Lisp_Object MS_CDECL CC_pmTgensym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:gensym");
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
    v133 = qvalue(elt(env, 3)); /* pm!:gensym!-count!* */
    v133 = add1(v133);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    qvalue(elt(env, 3)) = v133; /* pm!:gensym!-count!* */
    v133 = Lexplode(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v133 = list2star(stack[-1], stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v125;
        popv(3);
        return Lcompress(nil, v133);
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for texaeval */

static Lisp_Object CC_texaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texaeval");
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
    v139 = v0;
/* end of prologue */
    v138 = qvalue(elt(env, 1)); /* !*lasimp */
    if (v138 == nil) goto v128;
    stack[0] = elt(env, 2); /* tex */
    v138 = v139;
    fn = elt(env, 3); /* aeval */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v123 = stack[0];
        popv(1);
        return list2(v123, v138);
    }

v128:
    v138 = elt(env, 2); /* tex */
    popv(1);
    return list2(v138, v139);
/* error exit handlers */
v122:
    popv(1);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v1;
    v151 = v0;
/* end of prologue */
    stack[-7] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v152 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    v151 = v152;
    v152 = qcar(v152);
    stack[-5] = v152;
    v151 = qcdr(v151);
    v152 = v151;
    v152 = qcar(v152);
    stack[-4] = v152;
    v151 = qcdr(v151);
    stack[-3] = v151;
    goto v125;

v125:
    v151 = stack[-3];
    if (v151 == nil) goto v155;
    v151 = stack[-3];
    v151 = qcar(v151);
    stack[-2] = v151;
    v151 = stack[-5];
    v151 = sub1(v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    stack[-5] = v151;
    v151 = stack[-4];
    v151 = qcdr(v151);
    v152 = qcar(v151);
    v151 = (Lisp_Object)1; /* 0 */
    if (v152 == v151) goto v156;
    v153 = stack[-5];
    v152 = stack[-4];
    v151 = stack[-7];
    v151 = acons(v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    stack[-7] = v151;
    goto v156;

v156:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v151 = stack[-6];
    v151 = qcdr(v151);
    v152 = qcar(v151);
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcar(v151);
    stack[0] = times2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    v151 = stack[-6];
    v151 = qcdr(v151);
    v152 = qcdr(v151);
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v151 = plus2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    v151 = list2star(stack[-1], stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    stack[-4] = v151;
    v151 = stack[-2];
    if (v151 == nil) goto v85;
    v152 = stack[-2];
    v151 = stack[-4];
    fn = elt(env, 4); /* plus!: */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-8];
    stack[-4] = v151;
    goto v85;

v85:
    v151 = stack[-3];
    v151 = qcdr(v151);
    stack[-3] = v151;
    goto v125;

v155:
    v152 = stack[-4];
    v151 = stack[-7];
    popv(9);
    return cons(v152, v151);
/* error exit handlers */
v154:
    popv(9);
    return nil;
}



/* Code for simplog */

static Lisp_Object CC_simplog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simplog");
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
    v175 = stack[-1];
    v176 = qcdr(v175);
    v175 = elt(env, 0); /* simplog */
    fn = elt(env, 8); /* carx */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    stack[-2] = v175;
    v175 = qvalue(elt(env, 1)); /* !*expandlogs */
    if (v175 == nil) goto v133;
    v175 = qvalue(elt(env, 2)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* !*expandlogs */
    qvalue(elt(env, 1)) = v175; /* !*expandlogs */
    v177 = stack[-2];
    v175 = stack[-1];
    v176 = qcar(v175);
    v175 = elt(env, 3); /* log10 */
    if (v176 == v175) goto v122;
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v135;

v135:
    fn = elt(env, 9); /* simplogbi */
    v175 = (*qfn2(fn))(qenv(fn), v177, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    fn = elt(env, 10); /* resimp */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    { popv(4); return onevalue(v175); }

v122:
    v175 = (Lisp_Object)161; /* 10 */
    goto v135;

v133:
    v175 = stack[-2];
    v175 = integerp(v175);
    if (v175 == nil) goto v153;
    v175 = stack[-1];
    v176 = qcar(v175);
    v175 = elt(env, 3); /* log10 */
    if (v176 == v175) goto v179;
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v180;

v180:
    if (v175 == nil) goto v153;
    v176 = stack[-2];
    v175 = stack[-1];
    v177 = qcar(v175);
    v175 = elt(env, 3); /* log10 */
    if (v177 == v175) goto v181;
    v175 = qvalue(elt(env, 2)); /* nil */
    v177 = v175;
    goto v182;

v182:
    v175 = qvalue(elt(env, 5)); /* t */
    {
        popv(4);
        fn = elt(env, 11); /* simplogbn */
        return (*qfnn(fn))(qenv(fn), 3, v176, v177, v175);
    }

v181:
    v175 = (Lisp_Object)161; /* 10 */
    v177 = v175;
    goto v182;

v153:
    v176 = stack[-2];
    v175 = elt(env, 6); /* quotient */
    if (!consp(v176)) goto v183;
    v176 = qcar(v176);
    if (!(v176 == v175)) goto v183;
    v175 = stack[-2];
    v175 = qcdr(v175);
    v176 = qcar(v175);
    v175 = (Lisp_Object)17; /* 1 */
    if (v176 == v175) goto v154;
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v79;

v79:
    if (v175 == nil) goto v184;
    v175 = stack[-1];
    v176 = qcar(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    fn = elt(env, 12); /* simpiden */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    stack[0] = v175;
    v175 = stack[0];
    v175 = qcar(v175);
    fn = elt(env, 13); /* negf */
    v176 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v175 = stack[0];
    v175 = qcdr(v175);
    popv(4);
    return cons(v176, v175);

v184:
    v175 = stack[-1];
    {
        popv(4);
        fn = elt(env, 12); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v175);
    }

v154:
    v175 = qvalue(elt(env, 7)); /* !*precise */
    if (v175 == nil) goto v185;
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = qcar(v175);
    fn = elt(env, 14); /* realvaluedp */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    goto v79;

v185:
    v175 = qvalue(elt(env, 5)); /* t */
    goto v79;

v183:
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v79;

v179:
    v175 = qvalue(elt(env, 4)); /* dmode!* */
    if (v175 == nil) goto v90;
    v176 = elt(env, 3); /* log10 */
    v175 = qvalue(elt(env, 4)); /* dmode!* */
    v175 = get(v176, v175);
    env = stack[-3];
    goto v186;

v186:
    v175 = (v175 == nil ? lisp_true : nil);
    goto v180;

v90:
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v186;
/* error exit handlers */
v178:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    popv(4);
    return nil;
v64:
    popv(4);
    return nil;
}



/* Code for drop_rl_with */

static Lisp_Object CC_drop_rl_with(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v122, v123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_rl_with");
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
    v187 = v1;
    v122 = v0;
/* end of prologue */
    stack[-1] = v187;
    stack[0] = elt(env, 1); /* rl_with */
    v123 = v122;
    v122 = v187;
    v187 = elt(env, 1); /* rl_with */
    v187 = get(v122, v187);
    env = stack[-2];
    v187 = Ldelete(nil, v123, v187);
    nil = C_nil;
    if (exception_pending()) goto v95;
    {
        Lisp_Object v96 = stack[-1];
        Lisp_Object v97 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v96, v97, v187);
    }
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for reset_opnums */

static Lisp_Object MS_CDECL CC_reset_opnums(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reset_opnums");
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
/* end of prologue */
    v191 = qvalue(elt(env, 1)); /* oporder!* */
    stack[-4] = v191;
    v191 = (Lisp_Object)17; /* 1 */
    stack[-3] = v191;
    goto v194;

v194:
    v191 = stack[-4];
    if (v191 == nil) goto v137;
    v191 = stack[-4];
    v191 = qcar(v191);
    v192 = v191;
    v191 = stack[-4];
    v191 = qcdr(v191);
    stack[-4] = v191;
    v191 = v192;
    if (symbolp(v191)) goto v195;
    v191 = v192;
    v191 = qcar(v191);
    stack[-2] = v191;
    v191 = v192;
    v191 = qcdr(v191);
    goto v97;

v97:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); /* opnum */
    v192 = v191;
    v191 = stack[-3];
    v193 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    v192 = stack[-2];
    v191 = elt(env, 3); /* opnum */
    v191 = get(v192, v191);
    env = stack[-5];
    fn = elt(env, 4); /* !*xadd */
    v191 = (*qfn2(fn))(qenv(fn), v193, v191);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    v191 = Lputprop(nil, 3, stack[-1], stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    v191 = stack[-3];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    stack[-3] = v191;
    goto v194;

v195:
    v191 = v192;
    stack[-2] = v191;
    v191 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v137:
    v191 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v191); }
/* error exit handlers */
v145:
    popv(6);
    return nil;
}



/* Code for all_defined */

static Lisp_Object CC_all_defined(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined");
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
    v128 = v0;
/* end of prologue */
    stack[-1] = v128;
    fn = elt(env, 1); /* map__edges */
    v129 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v128 = stack[0];
    fn = elt(env, 2); /* defined_append */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    {
        Lisp_Object v135 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* all_defined_map_ */
        return (*qfn2(fn))(qenv(fn), v135, v128);
    }
/* error exit handlers */
v195:
    popv(3);
    return nil;
}



/* Code for !*sf2ex */

static Lisp_Object CC_Hsf2ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v142, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sf2ex");
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
    goto v199;

v199:
    v198 = stack[-1];
    if (v198 == nil) goto v126;
    v198 = stack[-1];
    if (!consp(v198)) goto v200;
    v198 = stack[-1];
    v198 = qcar(v198);
    v198 = (consp(v198) ? nil : lisp_true);
    goto v201;

v201:
    if (v198 == nil) goto v96;
    v198 = qvalue(elt(env, 1)); /* t */
    goto v202;

v202:
    if (v198 == nil) goto v87;
    stack[0] = stack[-2];
    v198 = qvalue(elt(env, 2)); /* nil */
    v142 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v198 = stack[-1];
    v198 = cons(v142, v198);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    {
        Lisp_Object v86 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v86, v198);
    }

v87:
    v198 = stack[-1];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    v182 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v198 = stack[-1];
    v198 = qcar(v198);
    v142 = qcdr(v198);
    v198 = stack[-2];
    v198 = acons(v182, v142, v198);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    stack[-2] = v198;
    v198 = stack[-1];
    v198 = qcdr(v198);
    stack[-1] = v198;
    goto v199;

v96:
    v198 = stack[-1];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v142 = qcar(v198);
    v198 = stack[0];
    v198 = Lmemq(nil, v142, v198);
    v198 = (v198 == nil ? lisp_true : nil);
    goto v202;

v200:
    v198 = qvalue(elt(env, 1)); /* t */
    goto v201;

v126:
    v198 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v198);
    }
/* error exit handlers */
v85:
    popv(4);
    return nil;
}



/* Code for i2fourier */

static Lisp_Object CC_i2fourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2fourier");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v0;
/* end of prologue */
    v128 = qvalue(elt(env, 1)); /* dmode!* */
    v125 = elt(env, 2); /* !:fs!: */
    if (!(v128 == v125)) return onevalue(v129);
    v125 = v129;
    {
        fn = elt(env, 3); /* !*d2fourier */
        return (*qfn1(fn))(qenv(fn), v125);
    }
}



/* Code for lf!=less */

static Lisp_Object CC_lfMless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v135, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=less");
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
    v135 = v0;
/* end of prologue */
    v134 = elt(env, 1); /* cali */
    v195 = elt(env, 2); /* varlessp */
    stack[-2] = get(v134, v195);
    env = stack[-3];
    v195 = v135;
    fn = elt(env, 3); /* lf!=lvar */
    stack[0] = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v195 = stack[-1];
    fn = elt(env, 3); /* lf!=lvar */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v123 = stack[-2];
        Lisp_Object v127 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v123, v127, v195);
    }
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for fix_or_str */

static Lisp_Object CC_fix_or_str(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fix_or_str");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v126 = v0;
/* end of prologue */
    v132 = v126;
    v132 = integerp(v132);
    if (!(v132 == nil)) return onevalue(v132);
        return Lstringp(nil, v126);
}



/* Code for dependsp */

static Lisp_Object CC_dependsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsp");
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
    v166 = stack[0];
    if (v166 == nil) goto v5;
    v162 = stack[-1];
    v166 = stack[0];
    fn = elt(env, 5); /* depends */
    v166 = (*qfn2(fn))(qenv(fn), v162, v166);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-3];
    if (!(v166 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v166 = stack[-1];
    if (!consp(v166)) goto v139;
    v166 = stack[-1];
    v162 = qcar(v166);
    v166 = elt(env, 3); /* !*sq */
    if (v162 == v166) goto v169;
    v166 = stack[-1];
    fn = elt(env, 6); /* taylorp */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-3];
    if (v166 == nil) goto v83;
    v162 = stack[0];
    v166 = qvalue(elt(env, 4)); /* taylorvariable */
    if (v162 == v166) goto v91;
    v166 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v166); }

v91:
    v166 = qvalue(elt(env, 4)); /* taylorvariable */
    { popv(4); return onevalue(v166); }

v83:
    v162 = stack[-1];
    v166 = stack[0];
    if (equal(v162, v166)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v166 = stack[-1];
    stack[-2] = v166;
    v166 = stack[-1];
    v166 = qcdr(v166);
    stack[-1] = v166;
    goto v211;

v211:
    v166 = stack[-1];
    if (v166 == nil) goto v140;
    v166 = stack[-1];
    v162 = qcar(v166);
    v166 = stack[0];
    v166 = CC_dependsp(env, v162, v166);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-3];
    if (!(v166 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v166 = stack[-1];
    v166 = qcdr(v166);
    stack[-1] = v166;
    goto v211;

v140:
    v166 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v166); }

v169:
    v166 = stack[-1];
    v166 = qcdr(v166);
    v162 = qcar(v166);
    v166 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* involvesq */
        return (*qfn2(fn))(qenv(fn), v162, v166);
    }

v139:
    v162 = stack[-1];
    v166 = stack[0];
    if (v162 == v166) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v166 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v166); }

v5:
    v166 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v166); }
/* error exit handlers */
v210:
    popv(4);
    return nil;
}



/* Code for bdstest */

static Lisp_Object CC_bdstest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bdstest");
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
    v135 = stack[0];
    v135 = qcar(v135);
    fn = elt(env, 1); /* r2bf */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    v135 = stack[0];
    v135 = qcdr(v135);
    fn = elt(env, 1); /* r2bf */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[0] = v135;
    fn = elt(env, 3); /* equal!: */
    v135 = (*qfn2(fn))(qenv(fn), stack[-1], v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    if (!(v135 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v135 = nil;
    { popv(3); return onevalue(v135); }
/* error exit handlers */
v139:
    popv(3);
    return nil;
}



/* Code for redmsg */

static Lisp_Object CC_redmsg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v197, v211, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redmsg");
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
    v196 = qvalue(elt(env, 1)); /* !*wsm */
    if (!(v196 == nil)) goto v5;
    v196 = qvalue(elt(env, 2)); /* !*msg */
    if (v196 == nil) goto v105;
    v197 = stack[0];
    v196 = elt(env, 4); /* "operator" */
    v196 = Lneq(nil, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v131;

v131:
    if (!(v196 == nil)) goto v5;
    v196 = qvalue(elt(env, 6)); /* !*int */
    if (v196 == nil) goto v107;
    v196 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v196 == nil)) goto v107;
    v214 = elt(env, 8); /* "Declare" */
    v211 = stack[-1];
    v197 = stack[0];
    v196 = elt(env, 9); /* "?" */
    v196 = list4(v214, v211, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    fn = elt(env, 12); /* yesp */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v83;
    if (!(v196 == nil)) { popv(4); return onevalue(v196); }
        popv(4);
        return Lerror0(nil, 0);

v107:
    v196 = qvalue(elt(env, 2)); /* !*msg */
    if (v196 == nil) goto v190;
    stack[-2] = elt(env, 10); /* "***" */
    v211 = stack[-1];
    v197 = elt(env, 11); /* "declared" */
    v196 = stack[0];
    v196 = list3(v211, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    {
        Lisp_Object v143 = stack[-2];
        popv(4);
        fn = elt(env, 13); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v143, v196);
    }

v190:
    v196 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v196); }

v5:
    v196 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v196); }

v105:
    v196 = qvalue(elt(env, 3)); /* t */
    goto v131;
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for ofsf_smeqtable */

static Lisp_Object CC_ofsf_smeqtable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v188, v150, v149, v92, v93;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smeqtable");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v149 = v1;
    v92 = v0;
/* end of prologue */
    v215 = elt(env, 1); /* ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq . greaterp) (leq . lessp) (greaterp . greaterp) (
lessp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (less
p . lessp))) */
    v93 = v215;
    v150 = v149;
    v188 = v92;
    v215 = v93;
    v215 = Latsoc(nil, v188, v215);
    v215 = Latsoc(nil, v150, v215);
    if (!(v215 == nil)) goto v194;
    v215 = v92;
    v188 = v149;
    v150 = v93;
    v188 = Latsoc(nil, v188, v150);
    v215 = Latsoc(nil, v215, v188);
    goto v194;

v194:
    v215 = qcdr(v215);
    return onevalue(v215);
}



/* Code for evalleq */

static Lisp_Object CC_evalleq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalleq");
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
/* copy arguments values to proper place */
    v105 = v1;
    v137 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v105 = (*qfn2(fn))(qenv(fn), v137, v105);
    errexit();
    v105 = (v105 == nil ? lisp_true : nil);
    return onevalue(v105);
}



/* Code for dependsl */

static Lisp_Object CC_dependsl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsl");
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

v216:
    v94 = stack[0];
    if (v94 == nil) goto v5;
    v95 = stack[-1];
    v94 = stack[0];
    v94 = qcar(v94);
    fn = elt(env, 2); /* depends */
    v94 = (*qfn2(fn))(qenv(fn), v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    if (!(v94 == nil)) { popv(3); return onevalue(v94); }
    v95 = stack[-1];
    v94 = stack[0];
    v94 = qcdr(v94);
    stack[-1] = v95;
    stack[0] = v94;
    goto v216;

v5:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v94); }
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for get!*generators */

static Lisp_Object CC_getHgenerators(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*generators");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v0;
/* end of prologue */
    v137 = elt(env, 1); /* generators */
    return get(v105, v137);
}



/* Code for mri_irsplit */

static Lisp_Object CC_mri_irsplit(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v217, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_irsplit");
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
    v171 = v0;
/* end of prologue */
    v217 = v171;
    v144 = elt(env, 1); /* floor */
    if (!consp(v217)) goto v200;
    v217 = qcar(v217);
    if (!(v217 == v144)) goto v200;
    v144 = v171;
    v144 = qcdr(v144);
    v144 = qcar(v144);
    fn = elt(env, 2); /* simp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v144 = qcar(v144);
    fn = elt(env, 3); /* mri_simplfloor */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    fn = elt(env, 4); /* mri_irsplit1 */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v217 = v144;
    v144 = v217;
    stack[-1] = qcar(v144);
    v144 = v217;
    v144 = qcdr(v144);
    if (v144 == nil) goto v213;
    stack[0] = elt(env, 1); /* floor */
    v144 = v217;
    v144 = qcdr(v144);
    fn = elt(env, 5); /* prepf */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v144 = list2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    fn = elt(env, 6); /* !*a2k */
    v171 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v217 = (Lisp_Object)17; /* 1 */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = acons(v171, v217, v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    goto v215;

v215:
    {
        Lisp_Object v205 = stack[-1];
        popv(3);
        return cons(v205, v144);
    }

v213:
    v144 = nil;
    goto v215;

v200:
    v217 = (Lisp_Object)17; /* 1 */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = acons(v171, v217, v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v212;
    popv(3);
    return ncons(v144);
/* error exit handlers */
v212:
    popv(3);
    return nil;
}



/* Code for qqe_length!-graph!-bterm */

static Lisp_Object CC_qqe_lengthKgraphKbterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-bterm");
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
    v192 = stack[-1];
    if (v192 == nil) goto v131;
    v192 = stack[-1];
    v192 = (consp(v192) ? nil : lisp_true);
    goto v132;

v132:
    if (!(v192 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v192 = stack[-1];
    fn = elt(env, 4); /* qqe_op */
    v193 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-2];
    v192 = elt(env, 2); /* (lhead rhead) */
    v192 = Lmemq(nil, v193, v192);
    if (v192 == nil) goto v215;
    v193 = stack[-1];
    v192 = stack[0];
    fn = elt(env, 5); /* qqe_length!-graph!-bterm!-update!-headmin */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v144;
    stack[0] = v192;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v215:
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v93;

v93:
    v192 = stack[-1];
    if (v192 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v192 = stack[-1];
    v192 = qcar(v192);
    v193 = v192;
    v192 = stack[0];
    v192 = CC_qqe_lengthKgraphKbterm(env, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-2];
    stack[0] = v192;
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v93;

v131:
    v192 = qvalue(elt(env, 1)); /* t */
    goto v132;
/* error exit handlers */
v144:
    popv(3);
    return nil;
}



/* Code for tidysqrt */

static Lisp_Object CC_tidysqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrt");
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
    v96 = stack[0];
    v96 = qcar(v96);
    fn = elt(env, 2); /* tidysqrtf */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    stack[-1] = v96;
    v96 = stack[-1];
    if (v96 == nil) goto v133;
    v96 = stack[0];
    v96 = qcdr(v96);
    fn = elt(env, 2); /* tidysqrtf */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    stack[0] = stack[-1];
    fn = elt(env, 3); /* invsq */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    {
        Lisp_Object v106 = stack[0];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v106, v96);
    }

v133:
    v97 = qvalue(elt(env, 1)); /* nil */
    v96 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v97, v96);
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minus-erule");
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
    v134 = v1;
    v138 = v0;
/* end of prologue */
    v138 = qcdr(v138);
    v138 = qcar(v138);
    fn = elt(env, 1); /* ps!:evaluate */
    v134 = (*qfn2(fn))(qenv(fn), v138, v134);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    stack[0] = v134;
    v134 = stack[0];
    v134 = qcar(v134);
    fn = elt(env, 2); /* negf */
    v138 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v134 = stack[0];
    v134 = qcdr(v134);
    popv(2);
    return cons(v138, v134);
/* error exit handlers */
v187:
    popv(2);
    return nil;
}



/* Code for dip!-nc!-ev!-prod */

static Lisp_Object MS_CDECL CC_dipKncKevKprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dip-nc-ev-prod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v95 = v3;
    v96 = v2;
    v97 = v1;
    v98 = v0;
/* end of prologue */
    stack[-2] = v97;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = v95;
    v95 = v98;
    fn = elt(env, 2); /* bcprod */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    v95 = qvalue(elt(env, 1)); /* nil */
    v95 = list2star(stack[0], v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    {
        Lisp_Object v215 = stack[-2];
        Lisp_Object v188 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* dip!-nc!-ev!-prod1 */
        return (*qfnn(fn))(qenv(fn), 3, v215, v188, v95);
    }
/* error exit handlers */
v218:
    popv(4);
    return nil;
}



/* Code for mod!-dump */

static Lisp_Object CC_modKdump(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v215, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-dump");
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
    v218 = stack[-1];
    v218 = qcar(v218);
    fn = elt(env, 1); /* freeind */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    if (v218 == nil) goto v131;
    v218 = stack[-1];
    v188 = qcar(v218);
    v218 = stack[-1];
    v218 = qcdr(v218);
    v215 = qcar(v218);
    v218 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* mod!-dump1 */
        return (*qfnn(fn))(qenv(fn), 3, v188, v215, v218);
    }

v131:
    v218 = stack[-1];
    v218 = qcdr(v218);
    v188 = qcar(v218);
    v218 = stack[-1];
    v215 = qcar(v218);
    v218 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* mod!-dump1 */
        return (*qfnn(fn))(qenv(fn), 3, v188, v215, v218);
    }
/* error exit handlers */
v92:
    popv(3);
    return nil;
}



/* Code for boolean!-eval1 */

static Lisp_Object CC_booleanKeval1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v189, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolean-eval1");
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
    v172 = nil;
    v189 = stack[0];
    v156 = elt(env, 1); /* sq!* */
    if (!consp(v189)) goto v188;
    v189 = qcar(v189);
    if (!(v189 == v156)) goto v188;
    v156 = stack[0];
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    if (v156 == nil) goto v195;
    v156 = stack[0];
    v156 = qcdr(v156);
    v156 = qcar(v156);
    fn = elt(env, 4); /* prespsq */
    v189 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    v172 = v189;
    v156 = elt(env, 3); /* boolean */
    v156 = Leqcar(nil, v189, v156);
    env = stack[-1];
    goto v132;

v132:
    if (v156 == nil) goto v169;
    v156 = v172;
    v156 = qcdr(v156);
    v156 = qcar(v156);
    {
        popv(2);
        fn = elt(env, 5); /* boolean!-eval2 */
        return (*qfn1(fn))(qenv(fn), v156);
    }

v169:
    v156 = stack[0];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    fn = elt(env, 6); /* simp!-prop */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    v156 = qcar(v156);
    fn = elt(env, 7); /* prepf */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); /* boolean!-eval2 */
        return (*qfn1(fn))(qenv(fn), v156);
    }

v195:
    v156 = qvalue(elt(env, 2)); /* nil */
    goto v132;

v188:
    v156 = qvalue(elt(env, 2)); /* nil */
    goto v132;
/* error exit handlers */
v170:
    popv(2);
    return nil;
}



/* Code for monic */

static Lisp_Object CC_monic(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monic");
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
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v221 = stack[-3];
    v221 = Lreverse(nil, v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    stack[-3] = v221;
    v221 = qvalue(elt(env, 1)); /* varlist */
    v221 = Llength(nil, v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    stack[-1] = v221;
    v221 = (Lisp_Object)17; /* 1 */
    stack[0] = v221;
    goto v200;

v200:
    v222 = stack[-1];
    v221 = stack[0];
    v221 = difference2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    v221 = Lminusp(nil, v221);
    env = stack[-5];
    if (v221 == nil) goto v96;
    v221 = qvalue(elt(env, 1)); /* varlist */
    v221 = qcdr(v221);
    stack[-3] = v221;
    v221 = stack[-3];
    if (v221 == nil) goto v171;
    v221 = (Lisp_Object)1; /* 0 */
    v221 = ncons(v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    stack[-1] = v221;
    stack[-2] = v221;
    goto v193;

v193:
    v221 = stack[-3];
    v221 = qcdr(v221);
    stack[-3] = v221;
    v221 = stack[-3];
    if (v221 == nil) goto v143;
    stack[0] = stack[-1];
    v221 = (Lisp_Object)1; /* 0 */
    v221 = ncons(v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    v221 = Lrplacd(nil, stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    v221 = stack[-1];
    v221 = qcdr(v221);
    stack[-1] = v221;
    goto v193;

v143:
    v221 = stack[-2];
    goto v186;

v186:
    v221 = (equal(stack[-4], v221) ? lisp_true : nil);
    { popv(6); return onevalue(v221); }

v171:
    v221 = qvalue(elt(env, 2)); /* nil */
    goto v186;

v96:
    v222 = stack[0];
    v221 = stack[-2];
    if (equal(v222, v221)) goto v127;
    v222 = stack[-3];
    v221 = stack[0];
    fn = elt(env, 3); /* pnth */
    v221 = (*qfn2(fn))(qenv(fn), v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    v222 = qcar(v221);
    v221 = stack[-4];
    v221 = cons(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    stack[-4] = v221;
    goto v127;

v127:
    v221 = stack[0];
    v221 = add1(v221);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-5];
    stack[0] = v221;
    goto v200;
/* error exit handlers */
v153:
    popv(6);
    return nil;
}



/* Code for setmod */

static Lisp_Object CC_setmod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmod");
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
    stack[-1] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    v142 = stack[0];
    if (!consp(v142)) goto v199;
    v142 = stack[0];
    v142 = qcar(v142);
    stack[0] = v142;
    goto v199;

v199:
    v142 = stack[0];
    fn = elt(env, 7); /* reval */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[0] = v142;
    v142 = stack[0];
    v142 = integerp(v142);
    if (v142 == nil) goto v186;
    v182 = stack[0];
    v142 = (Lisp_Object)1; /* 0 */
    v142 = (Lisp_Object)greaterp2(v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v142 = v142 ? lisp_true : nil;
    env = stack[-2];
    if (v142 == nil) goto v186;
    v142 = stack[0];
    fn = elt(env, 8); /* primep */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    if (v142 == nil) goto v209;
    v182 = elt(env, 2); /* (!:mod!:) */
    v142 = elt(env, 3); /* field */
    v142 = Lflag(nil, v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    goto v127;

v127:
    v142 = stack[0];
    fn = elt(env, 9); /* set!-general!-modulus */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    goto v4;

v4:
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    { popv(3); return onevalue(v142); }

v209:
    v182 = elt(env, 2); /* (!:mod!:) */
    v142 = elt(env, 3); /* field */
    v142 = Lremflag(nil, v182, v142);
    env = stack[-2];
    goto v127;

v186:
    v182 = stack[0];
    v142 = (Lisp_Object)1; /* 0 */
    if (v182 == v142) goto v173;
    v142 = stack[0];
    v142 = (v142 == nil ? lisp_true : nil);
    goto v172;

v172:
    if (v142 == nil) goto v212;
    v142 = qvalue(elt(env, 5)); /* current!-modulus */
    goto v4;

v212:
    v182 = stack[0];
    v142 = elt(env, 6); /* "modulus" */
    fn = elt(env, 10); /* typerr */
    v142 = (*qfn2(fn))(qenv(fn), v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v142 = nil;
    goto v4;

v173:
    v142 = qvalue(elt(env, 4)); /* t */
    goto v172;
/* error exit handlers */
v84:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    popv(3);
    return nil;
}



/* Code for spreadvar */

static Lisp_Object MS_CDECL CC_spreadvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v83, v143;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spreadvar");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v83 = v2;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v223:
    v182 = stack[-1];
    if (!consp(v182)) goto v136;
    v182 = stack[-1];
    v182 = qcar(v182);
    v182 = (consp(v182) ? nil : lisp_true);
    goto v137;

v137:
    if (!(v182 == nil)) { popv(4); return onevalue(v83); }
    v182 = stack[-1];
    v182 = qcar(v182);
    v182 = qcar(v182);
    v143 = qcar(v182);
    v182 = stack[0];
    if (equal(v143, v182)) goto v149;
    v182 = qvalue(elt(env, 2)); /* nil */
    goto v127;

v127:
    if (v182 == nil) goto v139;
    v182 = stack[-1];
    v182 = qcar(v182);
    v182 = qcar(v182);
    v182 = qcdr(v182);
    v182 = cons(v182, v83);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    v83 = v182;
    goto v139;

v139:
    v182 = stack[-1];
    v182 = qcdr(v182);
    stack[-2] = v182;
    v182 = stack[-1];
    v182 = qcar(v182);
    v143 = qcdr(v182);
    v182 = stack[0];
    v182 = CC_spreadvar(env, 3, v143, v182, v83);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    v83 = v182;
    v182 = stack[-2];
    stack[-1] = v182;
    goto v223;

v149:
    v182 = stack[-1];
    v182 = qcar(v182);
    v182 = qcar(v182);
    v143 = qcdr(v182);
    v182 = v83;
    v182 = Lmember(nil, v143, v182);
    v182 = (v182 == nil ? lisp_true : nil);
    goto v127;

v136:
    v182 = qvalue(elt(env, 1)); /* t */
    goto v137;
/* error exit handlers */
v181:
    popv(4);
    return nil;
}



/* Code for preptaylor!*2 */

static Lisp_Object CC_preptaylorH2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v225, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*2");
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
    v109 = stack[-1];
    v109 = qcdr(v109);
    fn = elt(env, 4); /* prepsq!* */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v226 = v109;
    v225 = (Lisp_Object)1; /* 0 */
    if (v226 == v225) goto v126;
    v226 = v109;
    v225 = elt(env, 2); /* quotient */
    if (!consp(v226)) goto v147;
    v226 = qcar(v226);
    if (!(v226 == v225)) goto v147;
    v225 = v109;
    v225 = qcdr(v225);
    v226 = qcar(v225);
    v225 = elt(env, 3); /* minus */
    v225 = Leqcar(nil, v226, v225);
    env = stack[-3];
    goto v96;

v96:
    if (v225 == nil) goto v214;
    stack[-2] = elt(env, 3); /* minus */
    v226 = elt(env, 2); /* quotient */
    v225 = v109;
    v225 = qcdr(v225);
    v225 = qcar(v225);
    v225 = qcdr(v225);
    v225 = qcar(v225);
    v109 = qcdr(v109);
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = list3(v226, v225, v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v109 = list2(stack[-2], v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-2] = v109;
    goto v83;

v83:
    v109 = stack[-1];
    v225 = qcar(v109);
    v109 = stack[0];
    fn = elt(env, 5); /* preptaycoeff */
    v109 = (*qfn2(fn))(qenv(fn), v225, v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v109 = cons(stack[-2], v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v81;
    popv(4);
    return ncons(v109);

v214:
    stack[-2] = v109;
    goto v83;

v147:
    v225 = qvalue(elt(env, 1)); /* nil */
    goto v96;

v126:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v109); }
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for collectpolyvarsaux */

static Lisp_Object CC_collectpolyvarsaux(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectpolyvarsaux");
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
    v89 = v1;
    stack[-1] = v0;
/* end of prologue */
    v91 = stack[-1];
    if (!consp(v91)) goto v126;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = (consp(v91) ? nil : lisp_true);
    goto v194;

v194:
    if (!(v91 == nil)) { popv(4); return onevalue(v89); }
    stack[0] = v89;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v91 = qcar(v91);
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    v91 = stack[-1];
    v91 = qcar(v91);
    v89 = qcdr(v91);
    v91 = qvalue(elt(env, 2)); /* nil */
    stack[0] = CC_collectpolyvarsaux(env, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    v91 = stack[-1];
    v89 = qcdr(v91);
    v91 = qvalue(elt(env, 2)); /* nil */
    v91 = CC_collectpolyvarsaux(env, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    v91 = (*qfn2(fn))(qenv(fn), stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    {
        Lisp_Object v193 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v193, v91);
    }

v126:
    v91 = qvalue(elt(env, 1)); /* t */
    goto v194;
/* error exit handlers */
v192:
    popv(4);
    return nil;
}



/* Code for !*addsq */

static Lisp_Object CC_Haddsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *addsq");
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
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v239 = stack[-3];
    v239 = qcar(v239);
    if (v239 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v239 = stack[-2];
    v239 = qcar(v239);
    if (v239 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v239 = stack[-3];
    v240 = qcdr(v239);
    v239 = (Lisp_Object)17; /* 1 */
    if (v240 == v239) goto v122;
    v239 = qvalue(elt(env, 1)); /* nil */
    goto v125;

v125:
    if (v239 == nil) goto v191;
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = stack[-2];
    v239 = qcar(v239);
    fn = elt(env, 2); /* addf */
    v240 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v240, v239);

v191:
    v239 = stack[-3];
    v240 = qcdr(v239);
    stack[-4] = v240;
    v239 = stack[-2];
    v239 = qcdr(v239);
    stack[-1] = v239;
    fn = elt(env, 3); /* gcdf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[0] = v239;
    v240 = stack[-4];
    v239 = stack[0];
    fn = elt(env, 4); /* quotf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-4] = v239;
    v240 = stack[-1];
    v239 = stack[0];
    fn = elt(env, 4); /* quotf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-1] = v239;
    v240 = stack[-1];
    v239 = stack[-3];
    v239 = qcar(v239);
    fn = elt(env, 5); /* !*multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v240 = stack[-4];
    v239 = stack[-2];
    v239 = qcar(v239);
    fn = elt(env, 5); /* !*multf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    fn = elt(env, 2); /* addf */
    v239 = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-2] = v239;
    v239 = stack[-2];
    if (v239 == nil) goto v154;
    v239 = stack[-3];
    v240 = qcdr(v239);
    v239 = stack[-1];
    fn = elt(env, 5); /* !*multf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-1] = v239;
    v239 = stack[-1];
    fn = elt(env, 6); /* minusf */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    if (v239 == nil) goto v183;
    v239 = stack[-2];
    fn = elt(env, 7); /* negf */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-2] = v239;
    v239 = stack[-1];
    fn = elt(env, 7); /* negf */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-1] = v239;
    goto v183;

v183:
    v240 = stack[-2];
    v239 = stack[-1];
    fn = elt(env, 3); /* gcdf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[0] = v239;
    v240 = stack[0];
    v239 = (Lisp_Object)17; /* 1 */
    if (v240 == v239) goto v67;
    v240 = stack[-2];
    v239 = stack[0];
    fn = elt(env, 4); /* quotf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v240 = stack[-1];
    v239 = stack[0];
    fn = elt(env, 4); /* quotf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    {
        Lisp_Object v242 = stack[-2];
        popv(6);
        return cons(v242, v239);
    }

v67:
    v240 = stack[-2];
    v239 = stack[-1];
    popv(6);
    return cons(v240, v239);

v154:
    v240 = qvalue(elt(env, 1)); /* nil */
    v239 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v240, v239);

v122:
    v239 = stack[-2];
    v240 = qcdr(v239);
    v239 = (Lisp_Object)17; /* 1 */
    v239 = (v240 == v239 ? lisp_true : nil);
    goto v125;
/* error exit handlers */
v241:
    popv(6);
    return nil;
}



/* Code for cl_susimkatl */

static Lisp_Object MS_CDECL CC_cl_susimkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v259, v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susimkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susimkatl");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    v258 = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = v258;
    goto v137;

v137:
    v258 = stack[-6];
    if (v258 == nil) goto v125;
    v258 = stack[-6];
    v258 = qcar(v258);
    v260 = v258;
    v258 = v260;
    v259 = qcdr(v258);
    v258 = stack[-3];
    if (equal(v259, v258)) goto v139;
    v258 = nil;
    goto v138;

v138:
    stack[-2] = v258;
    v258 = stack[-2];
    fn = elt(env, 8); /* lastpair */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    stack[-1] = v258;
    v258 = stack[-6];
    v258 = qcdr(v258);
    stack[-6] = v258;
    v258 = stack[-1];
    if (!consp(v258)) goto v137;
    else goto v136;

v136:
    v258 = stack[-6];
    if (v258 == nil) goto v179;
    stack[0] = stack[-1];
    v258 = stack[-6];
    v258 = qcar(v258);
    v260 = v258;
    v258 = v260;
    v259 = qcdr(v258);
    v258 = stack[-3];
    if (equal(v259, v258)) goto v88;
    v258 = nil;
    goto v172;

v172:
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = stack[-1];
    fn = elt(env, 8); /* lastpair */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    stack[-1] = v258;
    v258 = stack[-6];
    v258 = qcdr(v258);
    stack[-6] = v258;
    goto v136;

v88:
    v258 = v260;
    v258 = qcar(v258);
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    goto v172;

v179:
    v258 = stack[-2];
    goto v105;

v105:
    v260 = v258;
    v258 = v260;
    if (v258 == nil) goto v182;
    v259 = v260;
    v258 = stack[-4];
    fn = elt(env, 9); /* rl_susipost */
    v258 = (*qfn2(fn))(qenv(fn), v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v260 = v258;
    v259 = v260;
    v258 = elt(env, 2); /* true */
    if (v259 == v258) goto v262;
    v259 = v260;
    v258 = elt(env, 4); /* false */
    v258 = (v259 == v258 ? lisp_true : nil);
    goto v263;

v263:
    if (v258 == nil) goto v264;
    v259 = stack[-5];
    v258 = elt(env, 5); /* and */
    v258 = (v259 == v258 ? lisp_true : nil);
    fn = elt(env, 10); /* cl_cflip */
    v258 = (*qfn2(fn))(qenv(fn), v260, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    popv(8);
    return ncons(v258);

v264:
    v259 = v260;
    v258 = elt(env, 6); /* inctheo */
    if (v259 == v258) goto v265;
    v259 = stack[-5];
    v258 = elt(env, 7); /* or */
    if (!(v259 == v258)) goto v236;
    v258 = v260;
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v63;
    v258 = stack[-3];
    v258 = qcar(v258);
    fn = elt(env, 11); /* rl_negateat */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    stack[-1] = v258;
    stack[-2] = v258;
    goto v176;

v176:
    v258 = stack[-3];
    v258 = qcdr(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v239;
    stack[0] = stack[-1];
    v258 = stack[-3];
    v258 = qcar(v258);
    fn = elt(env, 11); /* rl_negateat */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = stack[-1];
    v258 = qcdr(v258);
    stack[-1] = v258;
    goto v176;

v239:
    v258 = stack[-2];
    goto v175;

v175:
    v260 = v258;
    goto v236;

v236:
    v258 = v260;
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v53;
    v258 = stack[-3];
    v258 = qcar(v258);
    v259 = v258;
    v258 = stack[-4];
    fn = elt(env, 12); /* rl_susitf */
    v258 = (*qfn2(fn))(qenv(fn), v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    stack[-1] = v258;
    stack[-2] = v258;
    goto v266;

v266:
    v258 = stack[-3];
    v258 = qcdr(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v258 = stack[-3];
    v258 = qcar(v258);
    v259 = v258;
    v258 = stack[-4];
    fn = elt(env, 12); /* rl_susitf */
    v258 = (*qfn2(fn))(qenv(fn), v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    v258 = stack[-1];
    v258 = qcdr(v258);
    stack[-1] = v258;
    goto v266;

v53:
    v258 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v258); }

v63:
    v258 = qvalue(elt(env, 1)); /* nil */
    goto v175;

v265:
    v260 = elt(env, 4); /* false */
    v259 = stack[-5];
    v258 = elt(env, 5); /* and */
    v258 = (v259 == v258 ? lisp_true : nil);
    {
        popv(8);
        fn = elt(env, 10); /* cl_cflip */
        return (*qfn2(fn))(qenv(fn), v260, v258);
    }

v262:
    v258 = qvalue(elt(env, 3)); /* t */
    goto v263;

v182:
    v258 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v258); }

v139:
    v258 = v260;
    v258 = qcar(v258);
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-7];
    goto v138;

v125:
    v258 = qvalue(elt(env, 1)); /* nil */
    goto v105;
/* error exit handlers */
v261:
    popv(8);
    return nil;
}



/* Code for ldf!-pow!-var */

static Lisp_Object CC_ldfKpowKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v224, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-pow-var");
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
    v206 = v0;
/* end of prologue */
    v224 = nil;
    stack[-2] = nil;
    stack[-1] = v206;
    goto v126;

v126:
    v206 = stack[-1];
    if (v206 == nil) goto v194;
    v206 = stack[-1];
    v206 = qcar(v206);
    stack[0] = v224;
    v224 = qcdr(v206);
    v206 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 5); /* kernels1 */
    v206 = (*qfn2(fn))(qenv(fn), v224, v206);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    v206 = Lappend(nil, stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    v224 = v206;
    v206 = stack[-1];
    v206 = qcdr(v206);
    stack[-1] = v206;
    goto v126;

v194:
    v206 = v224;
    fn = elt(env, 6); /* makeset */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    fn = elt(env, 7); /* prlist */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    stack[0] = v206;
    goto v215;

v215:
    v206 = stack[0];
    if (v206 == nil) goto v218;
    v206 = stack[0];
    v206 = qcar(v206);
    v109 = v206;
    v224 = v109;
    v206 = elt(env, 2); /* x */
    if (!consp(v224)) goto v217;
    v224 = qcar(v224);
    if (!(v224 == v206)) goto v217;
    v206 = qvalue(elt(env, 3)); /* t */
    goto v172;

v172:
    if (v206 == nil) goto v147;
    v224 = v109;
    v206 = stack[-2];
    v206 = cons(v224, v206);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    stack[-2] = v206;
    goto v147;

v147:
    v206 = stack[0];
    v206 = qcdr(v206);
    stack[0] = v206;
    goto v215;

v217:
    v224 = v109;
    v206 = elt(env, 4); /* u */
    v206 = Leqcar(nil, v224, v206);
    env = stack[-3];
    goto v172;

v218:
    v206 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* makeset */
        return (*qfn1(fn))(qenv(fn), v206);
    }
/* error exit handlers */
v220:
    popv(4);
    return nil;
}



/* Code for impartsq */

static Lisp_Object CC_impartsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v182, v83, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartsq");
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
    v142 = stack[0];
    v142 = qcar(v142);
    fn = elt(env, 1); /* splitcomplex */
    stack[-1] = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v142 = stack[0];
    v142 = qcdr(v142);
    fn = elt(env, 1); /* splitcomplex */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v182 = stack[-1];
    v83 = v182;
    v143 = qcar(v83);
    v83 = qcdr(v182);
    v182 = v142;
    v182 = qcar(v182);
    v142 = qcdr(v142);
    stack[0] = v143;
    stack[-3] = v182;
    stack[-2] = v142;
    v182 = v83;
    v142 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v182 = stack[0];
    v142 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v142 = (*qfn2(fn))(qenv(fn), v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    stack[0] = v142;
    v142 = stack[0];
    v142 = qcar(v142);
    fn = elt(env, 3); /* negf */
    v182 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v142 = stack[0];
    v142 = qcdr(v142);
    v142 = cons(v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v182 = stack[-3];
    v142 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v182 = stack[-2];
    v142 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v142 = (*qfn2(fn))(qenv(fn), v182, v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v142 = (*qfn2(fn))(qenv(fn), stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    fn = elt(env, 5); /* invsq */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    {
        Lisp_Object v224 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v224, v142);
    }
/* error exit handlers */
v206:
    popv(5);
    return nil;
}



/* Code for groebcplistsort */

static Lisp_Object CC_groebcplistsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsort");
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
    v122 = v0;
/* end of prologue */
    v123 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v122;
    goto v223;

v223:
    v122 = stack[0];
    if (v122 == nil) { popv(2); return onevalue(v123); }
    v122 = stack[0];
    v122 = qcar(v122);
    fn = elt(env, 2); /* groebcplistsortin */
    v122 = (*qfn2(fn))(qenv(fn), v122, v123);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v123 = v122;
    v122 = stack[0];
    v122 = qcdr(v122);
    stack[0] = v122;
    goto v223;
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for declared!-as!-float */

static Lisp_Object CC_declaredKasKfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for declared-as-float");
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
    v123 = v0;
/* end of prologue */
    v127 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* symtabget */
    v123 = (*qfn2(fn))(qenv(fn), v127, v123);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    v127 = v123;
    if (v123 == nil) goto v223;
    v123 = v127;
    v123 = qcdr(v123);
    v123 = qcar(v123);
    v127 = elt(env, 2); /* (real real!*8 real!*16 double! precision double float) 
*/
    v123 = Lmemq(nil, v123, v127);
    { popv(1); return onevalue(v123); }

v223:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v123); }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for pa_part2list */

static Lisp_Object CC_pa_part2list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163;
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
    v163 = stack[-6];
    v163 = qcdr(v163);
    fn = elt(env, 2); /* upbve */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v163;
    v163 = stack[0];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = Lmkvect(nil, v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-7] = v163;
    v163 = stack[0];
    stack[-4] = v163;
    goto v125;

v125:
    v163 = stack[-4];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = Lminusp(nil, v163);
    env = stack[-8];
    if (v163 == nil) goto v187;
    v163 = stack[-6];
    v163 = qcar(v163);
    stack[-4] = v163;
    goto v208;

v208:
    v163 = stack[-4];
    if (v163 == nil) goto v212;
    v163 = stack[-4];
    v163 = qcar(v163);
    stack[0] = stack[-7];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v163/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-3] = v163;
    v163 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-2] = v163;
    v163 = stack[-4];
    v163 = qcdr(v163);
    stack[-4] = v163;
    v163 = stack[-2];
    if (!consp(v163)) goto v208;
    else goto v144;

v144:
    v163 = stack[-4];
    if (v163 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v163 = stack[-4];
    v163 = qcar(v163);
    stack[0] = stack[-7];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v163/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = Lrplacd(nil, stack[-1], v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-2] = v163;
    v163 = stack[-4];
    v163 = qcdr(v163);
    stack[-4] = v163;
    goto v144;

v212:
    v163 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v163); }

v187:
    v163 = stack[-6];
    stack[0] = qcdr(v163);
    v163 = stack[-4];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v163/(16/CELL)));
    stack[-5] = v163;
    stack[-3] = stack[-7];
    v163 = stack[-5];
    stack[-2] = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v163 = stack[-5];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v163 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v163/(16/CELL)));
    v163 = cons(stack[-1], v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v163;
    v163 = stack[-4];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-4] = v163;
    goto v125;
/* error exit handlers */
v268:
    popv(9);
    return nil;
}



/* Code for get_first_kernel */

static Lisp_Object CC_get_first_kernel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v133, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_first_kernel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v136 = v1;
    v133 = v0;
/* end of prologue */
    v124 = v133;
    v133 = v136;
    v136 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* gfk */
        return (*qfnn(fn))(qenv(fn), 3, v124, v133, v136);
    }
}



/* Code for rl_simpatom */

static Lisp_Object CC_rl_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v237, v238;
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
    v72 = stack[0];
    if (!(v72 == nil)) goto v199;
    v237 = elt(env, 1); /* "nil" */
    v72 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    goto v199;

v199:
    v72 = stack[0];
    if (!(is_number(v72))) goto v128;
    v237 = elt(env, 3); /* "number" */
    v72 = stack[0];
    v237 = list2(v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    v72 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    goto v128;

v128:
    v72 = stack[0];
    v72 = Lstringp(nil, v72);
    env = stack[-1];
    if (v72 == nil) goto v106;
    v237 = elt(env, 4); /* "string" */
    v72 = stack[0];
    v237 = list2(v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    v72 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    goto v106;

v106:
    v72 = stack[0];
    fn = elt(env, 12); /* rl_gettype */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    v238 = v72;
    if (v72 == nil) goto v80;
    v237 = v238;
    v72 = elt(env, 5); /* (logical equation scalar slprog) */
    v72 = Lmemq(nil, v237, v72);
    if (v72 == nil) goto v109;
    v237 = stack[0];
    v72 = elt(env, 6); /* avalue */
    v72 = get(v237, v72);
    env = stack[-1];
    v72 = qcdr(v72);
    v72 = qcar(v72);
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v72);
    }

v109:
    v237 = v238;
    v72 = stack[0];
    v237 = list2(v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    v72 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    goto v80;

v80:
    v237 = stack[0];
    v72 = elt(env, 7); /* true */
    if (v237 == v72) goto v161;
    v237 = stack[0];
    v72 = elt(env, 9); /* false */
    v72 = (v237 == v72 ? lisp_true : nil);
    goto v222;

v222:
    if (!(v72 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v72 = stack[0];
    v72 = Lboundp(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    if (v72 == nil) goto v273;
    v72 = stack[0];
    fn = elt(env, 14); /* eval */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 13); /* rl_simp1 */
        return (*qfn1(fn))(qenv(fn), v72);
    }

v273:
    v237 = elt(env, 10); /* "unbound id" */
    v72 = stack[0];
    v237 = list2(v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-1];
    v72 = elt(env, 2); /* "logical" */
    fn = elt(env, 11); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v237, v72);
    nil = C_nil;
    if (exception_pending()) goto v272;
    v72 = nil;
    { popv(2); return onevalue(v72); }

v161:
    v72 = qvalue(elt(env, 8)); /* t */
    goto v222;
/* error exit handlers */
v272:
    popv(2);
    return nil;
}



/* Code for deleteq */

static Lisp_Object CC_deleteq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v209, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteq");
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
    v213 = nil;
    goto v199;

v199:
    v93 = stack[-1];
    if (v93 == nil) goto v126;
    v93 = stack[-1];
    v209 = qcar(v93);
    v93 = stack[0];
    if (v209 == v93) goto v134;
    v93 = stack[-1];
    v93 = qcar(v93);
    v209 = v213;
    v93 = cons(v93, v209);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v213 = v93;
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v199;

v134:
    v209 = v213;
    v93 = stack[-1];
    v93 = qcdr(v93);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v209, v93);
    }

v126:
    v93 = v213;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v93);
    }
/* error exit handlers */
v179:
    popv(3);
    return nil;
}



/* Code for ioto_tprin2 */

static Lisp_Object CC_ioto_tprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v202, v125, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ioto_tprin2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v128 = v124;
    v125 = qvalue(elt(env, 1)); /* t */
    v202 = qvalue(elt(env, 2)); /* nil */
    v124 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* ioto_prin21 */
        return (*qfnn(fn))(qenv(fn), 4, v128, v125, v202, v124);
    }
}



/* Code for qqe_length!-graph!-neighbors */

static Lisp_Object CC_qqe_lengthKgraphKneighbors(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v131;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v132 = v0;
/* end of prologue */
    v131 = elt(env, 1); /* neighbors */
    return get(v132, v131);
}



/* Code for iv_cutn */

static Lisp_Object CC_iv_cutn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v135;
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
    v135 = v0;
/* end of prologue */
    v195 = v135;
    v195 = qcdr(v195);
    if (v195 == nil) goto v128;
    v195 = v135;
    stack[0] = qcar(v195);
    v195 = v135;
    v195 = qcdr(v195);
    v195 = CC_iv_cutn(env, v195);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    {
        Lisp_Object v139 = stack[0];
        popv(2);
        fn = elt(env, 1); /* iv_cut */
        return (*qfn2(fn))(qenv(fn), v139, v195);
    }

v128:
    v195 = v135;
    v195 = qcar(v195);
    { popv(2); return onevalue(v195); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for bc_dcont */

static Lisp_Object CC_bc_dcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_dcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v5 = qcar(v5);
    {
        fn = elt(env, 1); /* sfto_dcontentf */
        return (*qfn1(fn))(qenv(fn), v5);
    }
}



/* Code for subeval */

static Lisp_Object CC_subeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v211, v214;
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
    v214 = elt(env, 2); /* sub */
    v211 = elt(env, 3); /* psopfn */
    v197 = elt(env, 4); /* subeval0 */
    v197 = Lputprop(nil, 3, v214, v211, v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[0] = elt(env, 4); /* subeval0 */
    v197 = stack[-1];
    v197 = Lmkquote(nil, v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v197 = list2(stack[0], v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[0] = v197;
    v214 = elt(env, 2); /* sub */
    v211 = elt(env, 3); /* psopfn */
    v197 = elt(env, 0); /* subeval */
    v197 = Lputprop(nil, 3, v214, v211, v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v197 = stack[0];
    if (!consp(v197)) goto v149;
    v197 = stack[0];
    v197 = qcdr(v197);
    goto v150;

v150:
    if (v197 == nil) goto v106;
    v197 = qvalue(elt(env, 6)); /* errmsg!* */
    if (v197 == nil) goto v88;
    v197 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v197 == nil)) goto v173;
    v197 = qvalue(elt(env, 6)); /* errmsg!* */
    fn = elt(env, 9); /* lprie */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v173;

v173:
    v197 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v106;

v106:
    v197 = stack[0];
    v197 = qcar(v197);
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    { popv(4); return onevalue(v197); }

v88:
    v197 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v197 == nil)) goto v208;
    v197 = elt(env, 2); /* sub */
    fn = elt(env, 9); /* lprie */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v208;

v208:
    v197 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v106;

v149:
    v197 = qvalue(elt(env, 5)); /* t */
    goto v150;
/* error exit handlers */
v83:
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
    Lisp_Object v150, v149, v92;
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
    v92 = v0;
/* end of prologue */
    v150 = v92;
    v150 = integerp(v150);
    if (v150 == nil) goto v125;
    v150 = (Lisp_Object)1; /* 0 */
    v149 = v150;
    goto v194;

v194:
    v150 = (Lisp_Object)1; /* 0 */
    if (v149 == v150) goto v4;
    v150 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v150); }

v4:
    v150 = v92;
    v150 = integerp(v150);
    if (v150 == nil) goto v95;
    v150 = v92;
    fn = elt(env, 2); /* simp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[0];
    goto v138;

v138:
    v150 = qcar(v150);
    {
        popv(1);
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v150);
    }

v95:
    v150 = v92;
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    goto v138;

v125:
    v150 = v92;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v149 = v150;
    goto v194;
/* error exit handlers */
v93:
    popv(1);
    return nil;
}



/* Code for groebmakepair */

static Lisp_Object CC_groebmakepair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebmakepair");
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
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v226 = stack[-3];
    v226 = qcdr(v226);
    v219 = qcar(v226);
    v226 = stack[-2];
    v226 = qcdr(v226);
    v226 = qcar(v226);
    fn = elt(env, 2); /* vevlcm */
    v226 = (*qfn2(fn))(qenv(fn), v219, v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    stack[-4] = v226;
    v226 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v226 == nil) goto v83;
    v226 = stack[-3];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v219 = stack[-4];
    v226 = stack[-3];
    v226 = qcdr(v226);
    v226 = qcar(v226);
    fn = elt(env, 4); /* vevdif */
    v226 = (*qfn2(fn))(qenv(fn), v219, v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v226 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v226 - TAG_FIXNUM);
    stack[-1] = v226;
    v226 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v219 = stack[-4];
    v226 = stack[-2];
    v226 = qcdr(v226);
    v226 = qcar(v226);
    fn = elt(env, 4); /* vevdif */
    v226 = (*qfn2(fn))(qenv(fn), v219, v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v226 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v226 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v219 = stack[-1];
    fn = elt(env, 6); /* max */
    v226 = (*qfn2(fn))(qenv(fn), v219, v226);
    nil = C_nil;
    if (exception_pending()) goto v155;
    {
        Lisp_Object v168 = stack[0];
        Lisp_Object v221 = stack[-3];
        Lisp_Object v222 = stack[-2];
        popv(6);
        return list4(v168, v221, v222, v226);
    }

v83:
    v220 = stack[-4];
    v219 = stack[-3];
    v226 = stack[-2];
    popv(6);
    return list3(v220, v219, v226);
/* error exit handlers */
v155:
    popv(6);
    return nil;
}



/* Code for idealp */

static Lisp_Object CC_idealp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v138, v139;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idealp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v139 = v0;
/* end of prologue */
    v138 = v139;
    v134 = elt(env, 1); /* i */
    if (!consp(v138)) goto v125;
    v138 = qcar(v138);
    if (!(v138 == v134)) goto v125;
    v134 = qvalue(elt(env, 2)); /* t */
    return onevalue(v134);

v125:
    v134 = v139;
    v138 = elt(env, 3); /* list */
        return Leqcar(nil, v134, v138);
}



/* Code for mkuniquewedge */

static Lisp_Object CC_mkuniquewedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147;
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
    goto v199;

v199:
    v146 = stack[0];
    if (v146 == nil) goto v223;
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = qcar(v146);
    fn = elt(env, 2); /* mkuniquewedge1 */
    v147 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    fn = elt(env, 3); /* multpfsq */
    v147 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    v146 = stack[-1];
    v146 = cons(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    stack[-1] = v146;
    v146 = stack[0];
    v146 = qcdr(v146);
    stack[0] = v146;
    goto v199;

v223:
    v146 = qvalue(elt(env, 1)); /* nil */
    v147 = v146;
    goto v194;

v194:
    v146 = stack[-1];
    if (v146 == nil) { popv(3); return onevalue(v147); }
    v146 = stack[-1];
    v146 = qcar(v146);
    fn = elt(env, 4); /* addpf */
    v146 = (*qfn2(fn))(qenv(fn), v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    v147 = v146;
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v194;
/* error exit handlers */
v189:
    popv(3);
    return nil;
}



/* Code for contain_edge */

static Lisp_Object CC_contain_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v97, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contain_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v1;
    v97 = v0;
/* end of prologue */

v216:
    v95 = v96;
    if (v95 == nil) goto v5;
    v95 = v97;
    v98 = qcar(v95);
    v95 = v96;
    v95 = qcar(v95);
    v95 = Lassoc(nil, v98, v95);
    if (!(v95 == nil)) return onevalue(v95);
    v95 = v96;
    v95 = qcdr(v95);
    v96 = v95;
    goto v216;

v5:
    v95 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v95);
}



/* Code for dfppri */

static Lisp_Object CC_dfppri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v153, v203;
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
    v152 = qvalue(elt(env, 1)); /* !*nat */
    if (v152 == nil) goto v105;
    v152 = qvalue(elt(env, 3)); /* !*fort */
    goto v131;

v131:
    if (v152 == nil) goto v223;
    v152 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v152); }

v223:
    v152 = stack[-1];
    v152 = qcdr(v152);
    v152 = qcar(v152);
    stack[-2] = v152;
    v152 = stack[-1];
    v152 = qcdr(v152);
    v152 = qcdr(v152);
    v152 = qcar(v152);
    stack[0] = v152;
    v152 = stack[-2];
    if (!consp(v152)) goto v95;
    v152 = stack[-2];
    v153 = qcar(v152);
    v152 = elt(env, 5); /* generic_function */
    v152 = get(v153, v152);
    env = stack[-3];
    v152 = (v152 == nil ? lisp_true : nil);
    goto v94;

v94:
    if (v152 == nil) goto v187;
    v152 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v152); }

v187:
    v152 = stack[-2];
    v152 = qcar(v152);
    fn = elt(env, 12); /* prin2!* */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v152 = qvalue(elt(env, 6)); /* ycoord!* */
    v152 = sub1(v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    qvalue(elt(env, 6)) = v152; /* ycoord!* */
    v153 = qvalue(elt(env, 6)); /* ycoord!* */
    v152 = qvalue(elt(env, 7)); /* ymin!* */
    v152 = (Lisp_Object)lessp2(v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v152 = v152 ? lisp_true : nil;
    env = stack[-3];
    if (v152 == nil) goto v190;
    v152 = qvalue(elt(env, 6)); /* ycoord!* */
    qvalue(elt(env, 7)) = v152; /* ymin!* */
    goto v190;

v190:
    v152 = stack[0];
    v152 = qcdr(v152);
    stack[0] = v152;
    goto v207;

v207:
    v152 = stack[0];
    if (v152 == nil) goto v193;
    v152 = stack[0];
    v152 = qcar(v152);
    fn = elt(env, 12); /* prin2!* */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v152 = stack[0];
    v152 = qcdr(v152);
    stack[0] = v152;
    goto v207;

v193:
    v152 = qvalue(elt(env, 6)); /* ycoord!* */
    v152 = add1(v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    qvalue(elt(env, 6)) = v152; /* ycoord!* */
    v152 = stack[-2];
    v152 = qcdr(v152);
    if (v152 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v152 = elt(env, 9); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v203 = elt(env, 10); /* !*comma!* */
    v153 = (Lisp_Object)1; /* 0 */
    v152 = stack[-2];
    v152 = qcdr(v152);
    fn = elt(env, 13); /* inprint */
    v152 = (*qfnn(fn))(qenv(fn), 3, v203, v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v152 = elt(env, 11); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v167;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v95:
    v152 = qvalue(elt(env, 2)); /* t */
    goto v94;

v105:
    v152 = qvalue(elt(env, 2)); /* t */
    goto v131;
/* error exit handlers */
v167:
    popv(4);
    return nil;
}



/* Code for !*sq2fourier */

static Lisp_Object CC_Hsq2fourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v208, v144;
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
    v207 = stack[0];
    v207 = qcar(v207);
    if (v207 == nil) goto v4;
    v207 = (Lisp_Object)49; /* 3 */
    v207 = Lmkvect(nil, v207);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-2] = v207;
    v144 = stack[-2];
    v208 = (Lisp_Object)1; /* 0 */
    v207 = stack[0];
    *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v208/(16/CELL))) = v207;
    v144 = stack[-2];
    v208 = (Lisp_Object)17; /* 1 */
    v207 = elt(env, 2); /* cos */
    *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v208/(16/CELL))) = v207;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* fs!:make!-nullangle */
    v207 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v207;
    v144 = stack[-2];
    v208 = (Lisp_Object)49; /* 3 */
    v207 = qvalue(elt(env, 1)); /* nil */
    *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v208/(16/CELL))) = v207;
    v208 = elt(env, 3); /* fourier */
    v207 = elt(env, 4); /* tag */
    v208 = get(v208, v207);
    v207 = stack[-2];
    popv(4);
    return cons(v208, v207);

v4:
    v207 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v207); }
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for square!-free!-mod!-p */

static Lisp_Object CC_squareKfreeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v188;
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
    v188 = v0;
/* end of prologue */
    v215 = v188;
    if (!consp(v215)) goto v194;
    v215 = v188;
    v215 = qcar(v215);
    v215 = (consp(v215) ? nil : lisp_true);
    goto v223;

v223:
    if (v215 == nil) goto v201;
    v215 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v215); }

v201:
    stack[0] = v188;
    v215 = v188;
    fn = elt(env, 2); /* derivative!-mod!-p */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    fn = elt(env, 3); /* gcd!-mod!-p */
    v215 = (*qfn2(fn))(qenv(fn), stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v188 = v215;
    v215 = v188;
    if (!consp(v215)) goto v94;
    v215 = v188;
    v215 = qcar(v215);
    v215 = (consp(v215) ? nil : lisp_true);
    { popv(2); return onevalue(v215); }

v94:
    v215 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v215); }

v194:
    v215 = qvalue(elt(env, 1)); /* t */
    goto v223;
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for legendre!-symbol */

static Lisp_Object CC_legendreKsymbol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for legendre-symbol");
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
    v128 = v1;
    v129 = v0;
/* end of prologue */
    stack[0] = v129;
    v129 = sub1(v128);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    v128 = (Lisp_Object)33; /* 2 */
    v128 = quot2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    {
        Lisp_Object v195 = stack[0];
        popv(2);
        fn = elt(env, 1); /* general!-modular!-expt */
        return (*qfn2(fn))(qenv(fn), v195, v128);
    }
/* error exit handlers */
v200:
    popv(2);
    return nil;
}



/* Code for flatten */

static Lisp_Object CC_flatten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v186;
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
    v186 = nil;
    goto v5;

v5:
    v170 = stack[-1];
    if (v170 == nil) goto v194;
    v170 = stack[-1];
    if (!consp(v170)) goto v202;
    v170 = stack[-1];
    v170 = qcar(v170);
    if (!consp(v170)) goto v123;
    stack[-2] = v186;
    v170 = stack[-1];
    v170 = qcar(v170);
    stack[0] = CC_flatten(env, v170);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v170 = stack[-1];
    v170 = qcdr(v170);
    v170 = CC_flatten(env, v170);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v170 = Lnconc(nil, stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    {
        Lisp_Object v88 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v88, v170);
    }

v123:
    v170 = stack[-1];
    v170 = qcar(v170);
    v170 = cons(v170, v186);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v186 = v170;
    v170 = stack[-1];
    v170 = qcdr(v170);
    stack[-1] = v170;
    goto v5;

v202:
    stack[0] = v186;
    v170 = stack[-1];
    v170 = ncons(v170);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    {
        Lisp_Object v191 = stack[0];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v191, v170);
    }

v194:
    v170 = v186;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v170);
    }
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for getsetvarlis */

static Lisp_Object CC_getsetvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v151;
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
    goto v5;

v5:
    v80 = stack[0];
    if (v80 == nil) goto v194;
    v80 = stack[0];
    if (!consp(v80)) goto v134;
    v80 = stack[0];
    v80 = qcar(v80);
    if (!consp(v80)) goto v174;
    v80 = stack[0];
    v80 = qcar(v80);
    v151 = qcar(v80);
    v80 = elt(env, 2); /* (setel setk) */
    v80 = Lmemq(nil, v151, v80);
    if (v80 == nil) goto v171;
    v80 = stack[0];
    v80 = qcar(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    v151 = CC_getsetvarlis(env, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    v80 = stack[-1];
    v80 = cons(v151, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v5;

v171:
    v80 = stack[0];
    v80 = qcar(v80);
    v151 = qcar(v80);
    v80 = elt(env, 3); /* setq */
    if (v151 == v80) goto v142;
    v80 = stack[0];
    v151 = qcar(v80);
    v80 = stack[-1];
    v80 = cons(v151, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v5;

v142:
    v80 = stack[0];
    v80 = qcar(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    v151 = Lmkquote(nil, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    v80 = stack[-1];
    v80 = cons(v151, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v5;

v174:
    v80 = stack[0];
    v151 = qcar(v80);
    v80 = stack[-1];
    v80 = cons(v151, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v5;

v134:
    v151 = elt(env, 1); /* "getsetvarlis" */
    v80 = stack[0];
    v80 = list2(v151, v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    fn = elt(env, 4); /* errach */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    {
        Lisp_Object v204 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v204, v80);
    }

v194:
    v80 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v80);
    }
/* error exit handlers */
v203:
    popv(3);
    return nil;
}



setup_type const u46_setup[] =
{
    {"letscalar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_letscalar},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"texaeval",                CC_texaeval,    too_many_1,    wrong_no_1},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"simplog",                 CC_simplog,     too_many_1,    wrong_no_1},
    {"drop_rl_with",            too_few_2,      CC_drop_rl_with,wrong_no_2},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"all_defined",             too_few_2,      CC_all_defined,wrong_no_2},
    {"*sf2ex",                  too_few_2,      CC_Hsf2ex,     wrong_no_2},
    {"i2fourier",               CC_i2fourier,   too_many_1,    wrong_no_1},
    {"lf=less",                 too_few_2,      CC_lfMless,    wrong_no_2},
    {"fix_or_str",              CC_fix_or_str,  too_many_1,    wrong_no_1},
    {"dependsp",                too_few_2,      CC_dependsp,   wrong_no_2},
    {"bdstest",                 CC_bdstest,     too_many_1,    wrong_no_1},
    {"redmsg",                  too_few_2,      CC_redmsg,     wrong_no_2},
    {"ofsf_smeqtable",          too_few_2,      CC_ofsf_smeqtable,wrong_no_2},
    {"evalleq",                 too_few_2,      CC_evalleq,    wrong_no_2},
    {"dependsl",                too_few_2,      CC_dependsl,   wrong_no_2},
    {"get*generators",          CC_getHgenerators,too_many_1,  wrong_no_1},
    {"mri_irsplit",             CC_mri_irsplit, too_many_1,    wrong_no_1},
    {"qqe_length-graph-bterm",  too_few_2,      CC_qqe_lengthKgraphKbterm,wrong_no_2},
    {"tidysqrt",                CC_tidysqrt,    too_many_1,    wrong_no_1},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {"dip-nc-ev-prod",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod},
    {"mod-dump",                too_few_2,      CC_modKdump,   wrong_no_2},
    {"boolean-eval1",           CC_booleanKeval1,too_many_1,   wrong_no_1},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"setmod",                  CC_setmod,      too_many_1,    wrong_no_1},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"collectpolyvarsaux",      too_few_2,      CC_collectpolyvarsaux,wrong_no_2},
    {"*addsq",                  too_few_2,      CC_Haddsq,     wrong_no_2},
    {"cl_susimkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susimkatl},
    {"ldf-pow-var",             CC_ldfKpowKvar, too_many_1,    wrong_no_1},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {"groebcplistsort",         CC_groebcplistsort,too_many_1, wrong_no_1},
    {"declared-as-float",       CC_declaredKasKfloat,too_many_1,wrong_no_1},
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
    {NULL, (one_args *)"u46", (two_args *)"5808 2688661 8897023", 0}
};

/* end of generated code */
