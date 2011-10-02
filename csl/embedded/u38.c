
/* $destdir\u38.c        Machine generated C code */

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


/* Code for rationalizef */

static Lisp_Object CC_rationalizef(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizef");
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
    v0048 = stack[-2];
    v0047 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 10); /* kernels1 */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    stack[0] = v0047;
    stack[-3] = v0047;
    goto v0050;

v0050:
    v0047 = stack[-3];
    if (v0047 == nil) goto v0051;
    v0047 = stack[-3];
    v0047 = qcar(v0047);
    stack[-1] = v0047;
    v0048 = stack[-1];
    v0047 = elt(env, 2); /* expt */
    if (!consp(v0048)) goto v0052;
    v0048 = qcar(v0048);
    if (!(v0048 == v0047)) goto v0052;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    v0048 = qcar(v0047);
    v0047 = elt(env, 3); /* quotient */
    if (!consp(v0048)) goto v0053;
    v0048 = qcar(v0048);
    if (!(v0048 == v0047)) goto v0053;
    v0048 = stack[0];
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    fn = elt(env, 11); /* lowertowerp */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    goto v0054;

v0054:
    if (!(v0047 == nil)) goto v0055;
    v0048 = stack[-1];
    v0047 = elt(env, 4); /* i */
    if (v0048 == v0047) goto v0056;
    v0048 = stack[-1];
    v0047 = elt(env, 2); /* expt */
    if (!consp(v0048)) goto v0057;
    v0048 = qcar(v0048);
    if (!(v0048 == v0047)) goto v0057;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    v0048 = qcar(v0047);
    v0047 = elt(env, 6); /* (quotient 1 2) */
    v0047 = (equal(v0048, v0047) ? lisp_true : nil);
    goto v0058;

v0058:
    if (v0047 == nil) goto v0059;
    v0047 = qvalue(elt(env, 5)); /* t */
    goto v0060;

v0060:
    if (v0047 == nil) goto v0061;
    v0048 = stack[-2];
    v0047 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v0048 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0047 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* conjquadratic */
        return (*qfn2(fn))(qenv(fn), v0048, v0047);
    }

v0061:
    v0048 = stack[-1];
    v0047 = elt(env, 2); /* expt */
    if (!consp(v0048)) goto v0062;
    v0048 = qcar(v0048);
    if (!(v0048 == v0047)) goto v0062;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    v0048 = qcar(v0047);
    v0047 = elt(env, 8); /* (quotient 1 3) */
    v0047 = (equal(v0048, v0047) ? lisp_true : nil);
    goto v0063;

v0063:
    if (v0047 == nil) goto v0064;
    v0048 = stack[-2];
    v0047 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v0048 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0047 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* conjcubic */
        return (*qfn2(fn))(qenv(fn), v0048, v0047);
    }

v0064:
    v0048 = stack[-1];
    v0047 = elt(env, 2); /* expt */
    if (!consp(v0048)) goto v0065;
    v0048 = qcar(v0048);
    if (!(v0048 == v0047)) goto v0065;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    v0048 = qcar(v0047);
    v0047 = elt(env, 9); /* (quotient 1 4) */
    v0047 = (equal(v0048, v0047) ? lisp_true : nil);
    goto v0066;

v0066:
    if (v0047 == nil) goto v0055;
    v0048 = stack[-2];
    v0047 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v0048 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0047 = stack[-1];
    {
        popv(5);
        fn = elt(env, 15); /* conjquartic */
        return (*qfn2(fn))(qenv(fn), v0048, v0047);
    }

v0055:
    v0047 = stack[-3];
    v0047 = qcdr(v0047);
    stack[-3] = v0047;
    goto v0050;

v0065:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0066;

v0062:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0063;

v0059:
    v0048 = stack[-1];
    v0047 = elt(env, 7); /* sqrt */
    v0047 = Leqcar(nil, v0048, v0047);
    env = stack[-4];
    goto v0060;

v0057:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0058;

v0056:
    v0047 = qvalue(elt(env, 5)); /* t */
    goto v0060;

v0053:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0052:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0051:
    v0047 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0047); }
/* error exit handlers */
v0049:
    popv(5);
    return nil;
}



/* Code for lf!=zero */

static Lisp_Object CC_lfMzero(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0067 = v0000;
/* end of prologue */
    v0067 = qcdr(v0067);
    v0067 = (v0067 == nil ? lisp_true : nil);
    return onevalue(v0067);
}



/* Code for add!-factor */

static Lisp_Object CC_addKfactor(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0079, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */
    v0052 = stack[0];
    v0052 = Lconsp(nil, v0052);
    env = stack[-2];
    if (v0052 == nil) goto v0081;
    v0079 = stack[-1];
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0052 = (Lisp_Object)greaterp2(v0079, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0052 = v0052 ? lisp_true : nil;
    env = stack[-2];
    if (v0052 == nil) goto v0083;
    v0052 = qvalue(elt(env, 1)); /* nil */
    goto v0039;

v0039:
    v0079 = v0052;
    v0052 = v0079;
    if (v0052 == nil) goto v0084;
    stack[-1] = v0079;
    v0052 = v0079;
    v0052 = qcdr(v0052);
    v0052 = add1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0052 = Lrplacd(nil, stack[-1], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0084:
    v0080 = stack[-1];
    v0079 = (Lisp_Object)17; /* 1 */
    v0052 = stack[0];
    popv(3);
    return acons(v0080, v0079, v0052);

v0083:
    v0079 = stack[-1];
    v0052 = stack[0];
    v0052 = Lassoc(nil, v0079, v0052);
    goto v0039;

v0081:
    v0052 = qvalue(elt(env, 1)); /* nil */
    goto v0039;
/* error exit handlers */
v0082:
    popv(3);
    return nil;
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0068,
                         Lisp_Object v0044, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0038, v0053;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0044,v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0068,v0044);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0044;
    stack[-2] = v0068;
    stack[-3] = v0000;
/* end of prologue */
    v0038 = stack[-1];
    v0088 = (Lisp_Object)1; /* 0 */
    v0088 = (Lisp_Object)greaterp2(v0038, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-5];
    if (v0088 == nil) goto v0090;
    v0088 = stack[-3];
    stack[-4] = qcdr(v0088);
    stack[0] = stack[-2];
    v0088 = stack[-1];
    v0088 = sub1(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0088 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[0] = v0088;
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    if (v0088 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0038 = stack[-2];
    v0088 = stack[-1];
    v0053 = cons(v0038, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0088 = stack[-3];
    v0038 = qcar(v0088);
    v0088 = stack[0];
    popv(6);
    return acons(v0053, v0038, v0088);

v0090:
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    { popv(6); return onevalue(v0088); }
/* error exit handlers */
v0089:
    popv(6);
    return nil;
}



/* Code for rl_pnf */

static Lisp_Object CC_rl_pnf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_pnf");
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
    v0092 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_pnf!* */
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    {
        Lisp_Object v0045 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0045, v0092);
    }
/* error exit handlers */
v0093:
    popv(2);
    return nil;
}



/* Code for simp0 */

static Lisp_Object CC_simp0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp0");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*factor */
    qvalue(elt(env, 1)) = nil; /* !*factor */
    v0106 = stack[-5];
    v0105 = elt(env, 2); /* !*sq */
    if (!consp(v0106)) goto v0087;
    v0106 = qcar(v0106);
    if (!(v0106 == v0105)) goto v0087;
    v0105 = stack[-5];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 10); /* prepsq!* */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    v0105 = CC_simp0(env, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    goto v0050;

v0050:
    qvalue(elt(env, 1)) = stack[-6]; /* !*factor */
    { popv(8); return onevalue(v0105); }

v0087:
    v0106 = stack[-5];
    v0105 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 11); /* frvarsof */
    v0105 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    fn = elt(env, 12); /* setkorder */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-3] = v0105;
    v0106 = qvalue(elt(env, 4)); /* subfg!* */
    v0105 = qvalue(elt(env, 5)); /* !*sub2 */
    v0105 = cons(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-4] = v0105;
    v0105 = qvalue(elt(env, 3)); /* nil */
    v0105 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    qvalue(elt(env, 6)) = v0105; /* alglist!* */
    v0105 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0105; /* subfg!* */
    v0105 = stack[-5];
    if (!consp(v0105)) goto v0086;
    v0105 = stack[-5];
    v0105 = qcar(v0105);
    if (symbolp(v0105)) goto v0107;
    v0105 = qvalue(elt(env, 3)); /* nil */
    goto v0072;

v0072:
    if (v0105 == nil) goto v0108;
    v0105 = stack[-5];
    fn = elt(env, 13); /* simp */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-2] = v0105;
    goto v0109;

v0109:
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    v0105 = qvalue(elt(env, 6)); /* alglist!* */
    v0105 = qcar(v0105);
    stack[0] = v0105;
    v0105 = stack[0];
    if (v0105 == nil) goto v0110;
    v0106 = stack[-5];
    v0105 = stack[0];
    fn = elt(env, 14); /* remhash */
    v0105 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    v0105 = stack[0];
    goto v0032;

v0032:
    v0105 = Lrplaca(nil, stack[-1], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    v0105 = stack[-4];
    v0105 = qcar(v0105);
    qvalue(elt(env, 4)) = v0105; /* subfg!* */
    v0105 = stack[-4];
    v0105 = qcdr(v0105);
    qvalue(elt(env, 5)) = v0105; /* !*sub2 */
    v0105 = stack[-3];
    fn = elt(env, 12); /* setkorder */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    v0105 = stack[-2];
    goto v0050;

v0110:
    v0105 = qvalue(elt(env, 3)); /* nil */
    goto v0032;

v0108:
    v0105 = stack[-5];
    fn = elt(env, 15); /* simpiden */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-2] = v0105;
    goto v0109;

v0107:
    v0105 = stack[-5];
    v0106 = qcar(v0105);
    v0105 = elt(env, 8); /* simp0fn */
    v0105 = Lflagp(nil, v0106, v0105);
    env = stack[-7];
    if (v0105 == nil) goto v0034;
    v0105 = qvalue(elt(env, 7)); /* t */
    goto v0072;

v0034:
    v0105 = stack[-5];
    v0106 = qcar(v0105);
    v0105 = elt(env, 9); /* rtype */
    v0105 = get(v0106, v0105);
    env = stack[-7];
    goto v0072;

v0086:
    v0105 = qvalue(elt(env, 7)); /* t */
    goto v0072;
/* error exit handlers */
v0022:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*factor */
    popv(8);
    return nil;
}



/* Code for get!-min!-degreelist */

static Lisp_Object CC_getKminKdegreelist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-min-degreelist");
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
/* copy arguments values to proper place */
    v0118 = v0000;
/* end of prologue */
    v0117 = v0118;
    if (v0117 == nil) goto v0039;
    v0117 = v0118;
    v0117 = qcdr(v0117);
    if (v0117 == nil) goto v0074;
    v0117 = v0118;
    v0117 = qcar(v0117);
    stack[0] = qcar(v0117);
    v0117 = v0118;
    v0117 = qcdr(v0117);
    v0117 = CC_getKminKdegreelist(env, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    {
        Lisp_Object v0027 = stack[0];
        popv(6);
        fn = elt(env, 2); /* taymindegreel */
        return (*qfn2(fn))(qenv(fn), v0027, v0117);
    }

v0074:
    v0117 = v0118;
    v0117 = qcar(v0117);
    v0117 = qcar(v0117);
    stack[-4] = v0117;
    v0117 = stack[-4];
    if (v0117 == nil) goto v0119;
    v0117 = stack[-4];
    v0117 = qcar(v0117);
    stack[0] = v0117;
    v0117 = (Lisp_Object)1; /* 0 */
    v0118 = v0117;
    goto v0120;

v0120:
    v0117 = stack[0];
    if (v0117 == nil) goto v0103;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0117 = (*qfn2(fn))(qenv(fn), v0117, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0118 = v0117;
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0120;

v0103:
    v0117 = v0118;
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    stack[-2] = v0117;
    stack[-3] = v0117;
    goto v0051;

v0051:
    v0117 = stack[-4];
    v0117 = qcdr(v0117);
    stack[-4] = v0117;
    v0117 = stack[-4];
    if (v0117 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0117 = stack[-4];
    v0117 = qcar(v0117);
    stack[0] = v0117;
    v0117 = (Lisp_Object)1; /* 0 */
    v0118 = v0117;
    goto v0121;

v0121:
    v0117 = stack[0];
    if (v0117 == nil) goto v0122;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0117 = (*qfn2(fn))(qenv(fn), v0117, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0118 = v0117;
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0121;

v0122:
    v0117 = v0118;
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0117 = Lrplacd(nil, stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    goto v0051;

v0119:
    v0117 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0117); }

v0039:
    v0117 = elt(env, 0); /* get!-min!-degreelist */
    {
        popv(6);
        fn = elt(env, 4); /* confusion */
        return (*qfn1(fn))(qenv(fn), v0117);
    }
/* error exit handlers */
v0026:
    popv(6);
    return nil;
}



/* Code for get!*order */

static Lisp_Object CC_getHorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*order");
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
    v0050 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* get!*elements */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    errexit();
        return Llength(nil, v0050);
}



/* Code for qqe_simplbtat */

static Lisp_Object CC_qqe_simplbtat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplbtat");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0058 = v0068;
    stack[-2] = v0000;
/* end of prologue */
    v0058 = stack[-2];
    fn = elt(env, 6); /* rl_prepat */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    stack[-3] = v0058;
    v0058 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    stack[0] = v0058;
    v0058 = stack[-3];
    fn = elt(env, 8); /* qqe_arg2l */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    stack[-1] = v0058;
    v0058 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    v0108 = v0058;
    v0058 = stack[-1];
    if (v0058 == nil) goto v0078;
    v0058 = v0108;
    if (!(v0058 == nil)) goto v0078;
    v0108 = stack[0];
    v0058 = elt(env, 1); /* neq */
    if (v0108 == v0058) goto v0042;
    v0058 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0058); }

v0042:
    v0058 = elt(env, 3); /* true */
    { popv(5); return onevalue(v0058); }

v0078:
    v0058 = v0108;
    if (v0058 == nil) goto v0085;
    v0058 = stack[-1];
    if (!(v0058 == nil)) goto v0085;
    v0108 = stack[0];
    v0058 = elt(env, 1); /* neq */
    if (v0108 == v0058) goto v0037;
    v0058 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0058); }

v0037:
    v0058 = elt(env, 3); /* true */
    { popv(5); return onevalue(v0058); }

v0085:
    v0058 = stack[-1];
    if (v0058 == nil) goto v0125;
    v0058 = v0108;
    if (v0058 == nil) goto v0125;
    v0058 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v0108 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-4];
    v0058 = elt(env, 5); /* equal */
    if (v0108 == v0058) goto v0024;
    v0058 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0058); }

v0024:
    v0058 = elt(env, 3); /* true */
    { popv(5); return onevalue(v0058); }

v0125:
    v0058 = stack[-3];
    {
        popv(5);
        fn = elt(env, 11); /* rl_simpat */
        return (*qfn1(fn))(qenv(fn), v0058);
    }
/* error exit handlers */
v0109:
    popv(5);
    return nil;
}



/* Code for pasf_pnf */

static Lisp_Object CC_pasf_pnf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pnf");
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
    v0067 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_pnf1 */
        return (*qfn1(fn))(qenv(fn), v0067);
    }
/* error exit handlers */
v0094:
    popv(1);
    return nil;
}



/* Code for dvfsf_0mk2 */

static Lisp_Object CC_dvfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046, v0127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0068;
    v0046 = v0000;
/* end of prologue */
    v0127 = qvalue(elt(env, 1)); /* nil */
    return list3(v0046, v0045, v0127);
}



/* Code for symbolsrd */

static Lisp_Object MS_CDECL CC_symbolsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0141, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "symbolsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsrd");
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
    stack[-4] = nil;
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    v0141 = qvalue(elt(env, 2)); /* char */
    v0140 = elt(env, 3); /* (b v a r) */
    if (equal(v0141, v0140)) goto v0077;
    v0141 = elt(env, 5); /* "<bvar>" */
    v0140 = (Lisp_Object)225; /* 14 */
    fn = elt(env, 10); /* errorml */
    v0140 = (*qfn2(fn))(qenv(fn), v0141, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0080;

v0080:
    v0141 = qvalue(elt(env, 2)); /* char */
    v0140 = elt(env, 6); /* (l o w l i m i t) */
    if (equal(v0141, v0140)) goto v0052;
    v0140 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0140;
    goto v0144;

v0144:
    v0141 = qvalue(elt(env, 2)); /* char */
    v0140 = elt(env, 7); /* (i n t e r v a l) */
    if (equal(v0141, v0140)) goto v0034;
    v0140 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0140;
    goto v0032;

v0032:
    v0141 = qvalue(elt(env, 2)); /* char */
    v0140 = elt(env, 8); /* (c o n d i t i o n) */
    if (equal(v0141, v0140)) goto v0114;
    v0140 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0140;
    goto v0109;

v0109:
    fn = elt(env, 11); /* mathml2 */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    stack[-1] = v0140;
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    v0140 = stack[-3];
    if (v0140 == nil) goto v0112;
    v0142 = stack[-4];
    v0141 = stack[-3];
    v0140 = stack[-1];
    popv(6);
    return list3(v0142, v0141, v0140);

v0112:
    v0140 = stack[-2];
    if (v0140 == nil) goto v0106;
    v0142 = stack[-4];
    v0141 = stack[-2];
    v0140 = stack[-1];
    popv(6);
    return list3(v0142, v0141, v0140);

v0106:
    v0140 = stack[0];
    if (v0140 == nil) goto v0145;
    v0142 = stack[-4];
    v0141 = stack[0];
    v0140 = stack[-1];
    popv(6);
    return list3(v0142, v0141, v0140);

v0145:
    v0141 = stack[-4];
    v0142 = qvalue(elt(env, 1)); /* nil */
    v0140 = stack[-1];
    popv(6);
    return list3(v0141, v0142, v0140);

v0114:
    fn = elt(env, 12); /* conditionrd */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    stack[0] = v0140;
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0109;

v0034:
    fn = elt(env, 13); /* intervalrd */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    stack[-2] = v0140;
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0032;

v0052:
    fn = elt(env, 14); /* lowupperlimitrd */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    stack[-3] = v0140;
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0144;

v0077:
    fn = elt(env, 15); /* bvarrd */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    stack[-4] = v0140;
    v0140 = stack[-4];
    v0140 = qcdr(v0140);
    v0140 = qcdr(v0140);
    v0141 = qcar(v0140);
    v0140 = (Lisp_Object)17; /* 1 */
    if (v0141 == v0140) goto v0075;
    v0141 = elt(env, 4); /* "" */
    v0140 = (Lisp_Object)209; /* 13 */
    fn = elt(env, 10); /* errorml */
    v0140 = (*qfn2(fn))(qenv(fn), v0141, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0146;

v0146:
    fn = elt(env, 9); /* lex */
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-5];
    goto v0080;

v0075:
    v0140 = stack[-4];
    stack[-4] = v0140;
    goto v0146;
/* error exit handlers */
v0143:
    popv(6);
    return nil;
}



/* Code for search_att */

static Lisp_Object CC_search_att(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search_att");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    v0161 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0161;
    v0161 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0161;
    v0162 = stack[-2];
    v0161 = stack[-1];
    fn = elt(env, 8); /* find */
    v0161 = (*qfn2(fn))(qenv(fn), v0162, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    stack[-2] = v0161;
    v0162 = stack[-2];
    v0161 = elt(env, 2); /* (stop) */
    if (!(equal(v0162, v0161))) goto v0073;
    v0161 = nil;
    { popv(5); return onevalue(v0161); }

v0073:
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 3); /* !  */
    if (v0162 == v0161) goto v0081;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 4); /* != */
    if (v0162 == v0161) goto v0072;
    v0161 = stack[-1];
    v0162 = Lcompress(nil, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    v0161 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* errorml */
    v0161 = (*qfn2(fn))(qenv(fn), v0162, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    goto v0164;

v0164:
    v0161 = stack[0];
    v0161 = qcar(v0161);
    v0162 = elt(env, 5); /* !" */
    if (!(v0161 == v0162)) goto v0165;
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    stack[0] = v0161;
    goto v0165;

v0165:
    v0161 = stack[0];
        popv(5);
        return Lreverse(nil, v0161);

v0072:
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    goto v0080;

v0080:
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 3); /* !  */
    if (v0162 == v0161) goto v0070;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 5); /* !" */
    if (!(v0162 == v0161)) goto v0166;
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    goto v0032;

v0032:
    v0162 = stack[-3];
    v0161 = (Lisp_Object)1; /* 0 */
    if (!(v0162 == v0161)) goto v0164;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = stack[0];
    v0161 = cons(v0162, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    stack[0] = v0161;
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 3); /* !  */
    if (v0162 == v0161) goto v0026;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 7); /* !$ */
    v0161 = (v0162 == v0161 ? lisp_true : nil);
    goto v0167;

v0167:
    if (v0161 == nil) goto v0032;
    v0161 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0161;
    goto v0032;

v0026:
    v0161 = qvalue(elt(env, 6)); /* t */
    goto v0167;

v0166:
    v0162 = stack[-3];
    v0161 = (Lisp_Object)1; /* 0 */
    if (!(v0162 == v0161)) goto v0164;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = stack[0];
    v0161 = cons(v0162, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-4];
    stack[0] = v0161;
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 3); /* !  */
    if (v0162 == v0161) goto v0013;
    v0161 = stack[-2];
    v0162 = qcar(v0161);
    v0161 = elt(env, 7); /* !$ */
    v0161 = (v0162 == v0161 ? lisp_true : nil);
    goto v0143;

v0143:
    if (v0161 == nil) goto v0166;
    v0161 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0161;
    goto v0166;

v0013:
    v0161 = qvalue(elt(env, 6)); /* t */
    goto v0143;

v0070:
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    goto v0080;

v0081:
    v0161 = stack[-2];
    v0161 = qcdr(v0161);
    stack[-2] = v0161;
    goto v0073;
/* error exit handlers */
v0163:
    popv(5);
    return nil;
}



/* Code for !*rd2cr */

static Lisp_Object CC_Hrd2cr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *rd2cr");
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
    v0076 = v0000;
/* end of prologue */
    v0075 = v0076;
    v0075 = qcdr(v0075);
    if (!consp(v0075)) goto v0067;
    v0075 = v0076;
    goto v0039;

v0039:
    fn = elt(env, 3); /* convchk */
    v0075 = (*qfn1(fn))(qenv(fn), v0075);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[0];
    v0076 = v0075;
    if (!consp(v0075)) goto v0119;
    v0075 = qvalue(elt(env, 2)); /* bfz!* */
    goto v0077;

v0077:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v0076, v0075);
    }

v0119:
    v0075 = elt(env, 1); /* 0.0 */
    goto v0077;

v0067:
    v0075 = v0076;
    v0075 = qcdr(v0075);
    goto v0039;
/* error exit handlers */
v0104:
    popv(1);
    return nil;
}



/* Code for splitcomplex */

static Lisp_Object CC_splitcomplex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitcomplex");
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
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0156 = qvalue(elt(env, 1)); /* kord!* */
    v0056 = qvalue(elt(env, 2)); /* t */
    stack[-4] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = v0156; /* kord!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = v0056; /* !*exp */
    v0156 = elt(env, 4); /* i */
    v0056 = elt(env, 5); /* idvalfn */
    v0056 = get(v0156, v0056);
    env = stack[-5];
    if (v0056 == nil) goto v0146;
    v0056 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    goto v0172;

v0172:
    stack[-2] = v0056;
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    fn = elt(env, 7); /* repartf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0056 = stack[-2];
    stack[0] = qcdr(v0056);
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    fn = elt(env, 8); /* impartf */
    v0156 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0056 = cons(v0156, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0056 = acons(stack[-1], stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    { popv(6); return onevalue(v0056); }

v0146:
    v0156 = elt(env, 4); /* i */
    v0056 = stack[0];
    v0056 = Lsmemq(nil, v0156, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    if (v0056 == nil) goto v0083;
    v0156 = elt(env, 4); /* i */
    v0056 = qvalue(elt(env, 1)); /* kord!* */
    v0056 = cons(v0156, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0056 = stack[0];
    fn = elt(env, 10); /* reorder */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    stack[0] = v0056;
    goto v0083;

v0083:
    v0056 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    fn = elt(env, 11); /* subs2 */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    goto v0172;
/* error exit handlers */
v0033:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    popv(6);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestzerop:");
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
    v0077 = v0000;
/* end of prologue */
    v0051 = v0077;
    v0051 = integerp(v0051);
    if (v0051 == nil) goto v0172;
    v0051 = v0077;
    fn = elt(env, 1); /* simp */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    errexit();
    goto v0003;

v0003:
    v0051 = qcar(v0051);
    v0051 = (v0051 == nil ? lisp_true : nil);
    return onevalue(v0051);

v0172:
    v0051 = v0077;
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    goto v0003;
}



/* Code for dipretimes */

static Lisp_Object CC_dipretimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0169, v0173;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipretimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0169 = v0000;
/* end of prologue */

v0074:
    v0085 = v0169;
    v0173 = qcar(v0085);
    v0085 = (Lisp_Object)17; /* 1 */
    if (v0173 == v0085) goto v0050;
    v0085 = v0169;
    v0085 = qcdr(v0085);
    if (v0085 == nil) goto v0035;
    v0085 = elt(env, 1); /* times */
    return cons(v0085, v0169);

v0035:
    v0085 = v0169;
    v0085 = qcar(v0085);
    return onevalue(v0085);

v0050:
    v0085 = v0169;
    v0085 = qcdr(v0085);
    if (v0085 == nil) goto v0055;
    v0085 = v0169;
    v0085 = qcdr(v0085);
    v0169 = v0085;
    goto v0074;

v0055:
    v0085 = (Lisp_Object)17; /* 1 */
    return onevalue(v0085);
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205, v0206, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoppri");
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
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0204 = stack[-8];
    if (symbolp(v0204)) goto v0092;
    v0204 = stack[-8];
    v0204 = qcar(v0204);
    goto v0172;

v0172:
    stack[-9] = v0204;
    v0204 = stack[-8];
    if (symbolp(v0204)) goto v0168;
    v0204 = stack[-8];
    v0204 = qcdr(v0204);
    goto v0171;

v0171:
    stack[-7] = v0204;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v0206 = elt(env, 5); /* !*nat */
    v0205 = elt(env, 6); /* " contract= " */
    v0204 = elt(env, 7); /* !*contract */
    v0204 = list3(v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = list3star(stack[-2], stack[-1], stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = list3star(stack[-5], stack[-4], stack[-3], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = qvalue(elt(env, 5)); /* !*nat */
    if (v0204 == nil) goto v0034;
    v0204 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v0204 == nil)) goto v0034;
    v0204 = stack[-9];
    v0204 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    v0204 = stack[-9];
    v0205 = Llength(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = (Lisp_Object)33; /* 2 */
    v0204 = (Lisp_Object)greaterp2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    v0204 = v0204 ? lisp_true : nil;
    env = stack[-10];
    if (v0204 == nil) goto v0209;
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = elt(env, 14); /* !- */
    if (v0205 == v0204) goto v0210;
    v0204 = stack[-9];
    v0205 = qcar(v0204);
    v0204 = elt(env, 16); /* !+ */
    if (v0205 == v0204) goto v0211;
    v0204 = stack[-9];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    goto v0212;

v0212:
    stack[0] = elt(env, 8); /* !" */
    v0204 = stack[-9];
    v0204 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[0] = cons(stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = elt(env, 8); /* !" */
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lappend(nil, stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    v0204 = stack[-7];
    if (v0204 == nil) goto v0213;
    v0205 = stack[-9];
    v0204 = stack[-7];
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    goto v0165;

v0165:
    stack[-3] = v0204;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v0207 = elt(env, 17); /* " z= " */
    v0206 = stack[-6];
    v0205 = elt(env, 18); /* " x1= " */
    v0204 = stack[-3];
    v0204 = list4(v0207, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = list3star(stack[-2], stack[-1], stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = stack[-6];
    if (v0204 == nil) goto v0214;
    v0206 = elt(env, 19); /* expt */
    v0205 = stack[-3];
    v0204 = stack[-6];
    v0206 = list3(v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0205 = elt(env, 19); /* expt */
    v0204 = elt(env, 20); /* infix */
    v0204 = get(v0205, v0204);
    env = stack[-10];
    fn = elt(env, 22); /* exptpri */
    v0204 = (*qfn2(fn))(qenv(fn), v0206, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0214:
    v0204 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = stack[-7];
    if (v0204 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0204 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0204; /* obrkp!* */
    v0206 = elt(env, 11); /* !*comma!* */
    v0205 = (Lisp_Object)1; /* 0 */
    v0204 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v0204 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0204; /* obrkp!* */
    v0204 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0213:
    v0204 = stack[-9];
    goto v0165;

v0211:
    v0204 = elt(env, 16); /* !+ */
    stack[-6] = v0204;
    v0205 = stack[-9];
    v0204 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 25); /* pnth */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    goto v0212;

v0210:
    v0205 = elt(env, 14); /* !- */
    v0204 = elt(env, 15); /* !1 */
    v0204 = list2(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-6] = v0204;
    v0205 = stack[-9];
    v0204 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 25); /* pnth */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    goto v0212;

v0209:
    v0204 = stack[-9];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    goto v0212;

v0034:
    stack[0] = elt(env, 8); /* !" */
    v0204 = stack[-9];
    v0204 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[0] = cons(stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = elt(env, 8); /* !" */
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lappend(nil, stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = Lcompress(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    stack[-9] = v0204;
    v0204 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = stack[-7];
    if (v0204 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0204 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0204; /* obrkp!* */
    v0206 = elt(env, 11); /* !*comma!* */
    v0205 = (Lisp_Object)1; /* 0 */
    v0204 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v0204 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-10];
    v0204 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0204; /* obrkp!* */
    v0204 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0168:
    v0204 = qvalue(elt(env, 1)); /* nil */
    goto v0171;

v0092:
    v0204 = stack[-8];
    goto v0172;
/* error exit handlers */
v0208:
    popv(11);
    return nil;
}



/* Code for zeros */

static Lisp_Object CC_zeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0146, v0075;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeros");
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
    v0146 = v0000;
/* end of prologue */

v0039:
    v0054 = v0146;
    if (v0054 == nil) goto v0050;
    v0054 = v0146;
    v0075 = qcar(v0054);
    v0054 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0054) goto v0092;
    v0054 = v0146;
    v0054 = qcdr(v0054);
    v0146 = v0054;
    goto v0039;

v0092:
    v0054 = v0146;
    v0054 = qcdr(v0054);
    v0054 = CC_zeros(env, v0054);
    errexit();
    return add1(v0054);

v0050:
    v0054 = (Lisp_Object)1; /* 0 */
    return onevalue(v0054);
}



/* Code for listminimize */

static Lisp_Object CC_listminimize(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0119, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listminimize");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0215 = v0068;
    v0119 = v0000;
/* end of prologue */
    v0055 = v0119;
    if (v0055 == nil) goto v0067;
    v0055 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* cali!=min */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0055, v0119, v0215);
    errexit();
        return Lreverse(nil, v0215);

v0067:
    v0215 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0215);
}



/* Code for general!-modular!-difference */

static Lisp_Object CC_generalKmodularKdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0120;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-difference");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0170 = v0068;
    v0120 = v0000;
/* end of prologue */
    v0170 = difference2(v0120, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    stack[0] = v0170;
    v0120 = stack[0];
    v0170 = (Lisp_Object)1; /* 0 */
    v0170 = (Lisp_Object)lessp2(v0120, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0170 = v0170 ? lisp_true : nil;
    env = stack[-1];
    if (v0170 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0120 = stack[0];
    v0170 = qvalue(elt(env, 1)); /* current!-modulus */
    v0170 = plus2(v0120, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    stack[0] = v0170;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0043:
    popv(2);
    return nil;
}



/* Code for ofsf_qesubqat */

static Lisp_Object MS_CDECL CC_ofsf_qesubqat(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0068,
                         Lisp_Object v0044, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0064, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_qesubqat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubqat");
#endif
    if (stack >= stacklimit)
    {
        push3(v0044,v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0068,v0044);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0044;
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = stack[-1];
    v0151 = stack[-2];
    fn = elt(env, 8); /* ofsf_varlat */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0151 = Lmemq(nil, stack[-3], v0151);
    if (v0151 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0151 = stack[-2];
    v0151 = qcdr(v0151);
    stack[-3] = qcar(v0151);
    v0151 = stack[0];
    v0151 = qcar(v0151);
    if (v0151 == nil) goto v0139;
    v0064 = stack[0];
    v0151 = elt(env, 1); /* prepf */
    fn = elt(env, 9); /* sqform */
    v0151 = (*qfn2(fn))(qenv(fn), v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    goto v0073;

v0073:
    v0151 = cons(stack[-1], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0151 = ncons(v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    fn = elt(env, 10); /* subf */
    v0151 = (*qfn2(fn))(qenv(fn), stack[-3], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[-1] = v0151;
    v0151 = stack[-2];
    v0151 = qcar(v0151);
    stack[0] = v0151;
    v0151 = qvalue(elt(env, 2)); /* !*rlqelocal */
    if (v0151 == nil) goto v0123;
    v0064 = stack[0];
    v0151 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_qesubqat!-local */
        return (*qfn2(fn))(qenv(fn), v0064, v0151);
    }

v0123:
    v0064 = stack[0];
    v0151 = elt(env, 3); /* equal */
    if (v0064 == v0151) goto v0102;
    v0064 = stack[0];
    v0151 = elt(env, 5); /* neq */
    if (v0064 == v0151) goto v0058;
    v0209 = elt(env, 6); /* geq */
    v0151 = stack[-1];
    v0064 = qcdr(v0151);
    v0151 = qvalue(elt(env, 7)); /* nil */
    v0064 = list3(v0209, v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0151 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 12); /* ofsf_surep */
    v0151 = (*qfn2(fn))(qenv(fn), v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    goto v0101;

v0101:
    if (v0151 == nil) goto v0024;
    v0064 = stack[0];
    v0151 = stack[-1];
    v0151 = qcar(v0151);
    v0209 = qvalue(elt(env, 7)); /* nil */
    popv(5);
    return list3(v0064, v0151, v0209);

v0024:
    v0151 = stack[-1];
    v0151 = qcdr(v0151);
    fn = elt(env, 13); /* sfto_pdecf */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0151 = qcar(v0151);
    stack[-2] = v0151;
    v0209 = elt(env, 6); /* geq */
    v0064 = stack[-2];
    v0151 = qvalue(elt(env, 7)); /* nil */
    v0064 = list3(v0209, v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0151 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 12); /* ofsf_surep */
    v0151 = (*qfn2(fn))(qenv(fn), v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    if (v0151 == nil) goto v0013;
    v0064 = stack[0];
    v0151 = stack[-1];
    v0151 = qcar(v0151);
    v0209 = qvalue(elt(env, 7)); /* nil */
    popv(5);
    return list3(v0064, v0151, v0209);

v0013:
    v0151 = stack[-1];
    v0064 = qcar(v0151);
    v0151 = stack[-2];
    fn = elt(env, 14); /* multf */
    v0151 = (*qfn2(fn))(qenv(fn), v0064, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0064 = qvalue(elt(env, 7)); /* nil */
    {
        Lisp_Object v0222 = stack[0];
        popv(5);
        return list3(v0222, v0151, v0064);
    }

v0058:
    v0151 = qvalue(elt(env, 4)); /* t */
    goto v0101;

v0102:
    v0151 = qvalue(elt(env, 4)); /* t */
    goto v0101;

v0139:
    v0151 = (Lisp_Object)1; /* 0 */
    goto v0073;
/* error exit handlers */
v0009:
    popv(5);
    return nil;
}



/* Code for pasf_premf */

static Lisp_Object CC_pasf_premf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_premf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    v0051 = v0000;
/* end of prologue */
    v0077 = v0051;
    v0051 = stack[0];
    fn = elt(env, 1); /* remf */
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-1];
    v0051 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* pasf_premf1 */
        return (*qfn2(fn))(qenv(fn), v0077, v0051);
    }
/* error exit handlers */
v0168:
    popv(2);
    return nil;
}



/* Code for pasf_floor */

static Lisp_Object CC_pasf_floor(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0105, v0106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_floor");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */
    v0137 = stack[-1];
    if (!consp(v0137)) goto v0093;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0126;

v0126:
    if (v0137 == nil) goto v0104;
    v0137 = stack[0];
    if (!consp(v0137)) goto v0119;
    v0137 = stack[0];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0137 == nil) goto v0227;
    v0137 = stack[-1];
    if (v0137 == nil) goto v0043;
    v0105 = stack[-1];
    v0137 = stack[0];
    v0105 = Cremainder(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0137 = (Lisp_Object)1; /* 0 */
    if (v0105 == v0137) goto v0053;
    v0105 = stack[-1];
    v0137 = stack[0];
    v0105 = times2(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0137 = (Lisp_Object)1; /* 0 */
    v0137 = (Lisp_Object)greaterp2(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0137 = v0137 ? lisp_true : nil;
    env = stack[-2];
    if (v0137 == nil) goto v0115;
    v0105 = stack[-1];
    v0137 = stack[0];
    v0137 = quot2(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    goto v0173;

v0173:
    fn = elt(env, 5); /* simp */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0137 = qcar(v0137);
    { popv(3); return onevalue(v0137); }

v0115:
    v0105 = stack[-1];
    v0137 = stack[0];
    v0137 = quot2(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0137 = sub1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    goto v0173;

v0053:
    v0105 = stack[-1];
    v0137 = stack[0];
    v0137 = quot2(v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    goto v0173;

v0043:
    v0137 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0137); }

v0227:
    v0137 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0137 == nil)) goto v0202;
    v0106 = elt(env, 4); /* "pasf_floor: not a domain valued sf in input" 
*/
    v0105 = stack[-1];
    v0137 = stack[0];
    v0137 = list3(v0106, v0105, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    fn = elt(env, 6); /* lprie */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    goto v0202;

v0202:
    v0137 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0137 = nil;
    { popv(3); return onevalue(v0137); }

v0119:
    v0137 = qvalue(elt(env, 1)); /* t */
    goto v0091;

v0104:
    v0137 = qvalue(elt(env, 2)); /* nil */
    goto v0091;

v0093:
    v0137 = qvalue(elt(env, 1)); /* t */
    goto v0126;
/* error exit handlers */
v0154:
    popv(3);
    return nil;
}



/* Code for cd_ordatp */

static Lisp_Object CC_cd_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0060, v0056, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0056 = v0068;
    v0156 = v0000;
/* end of prologue */
    v0024 = v0156;
    v0060 = qcar(v0024);
    v0024 = elt(env, 1); /* neq */
    if (v0060 == v0024) goto v0077;
    v0024 = qvalue(elt(env, 3)); /* nil */
    goto v0091;

v0091:
    if (v0024 == nil) goto v0043;
    v0024 = qvalue(elt(env, 4)); /* t */
    return onevalue(v0024);

v0043:
    v0024 = v0156;
    v0060 = qcar(v0024);
    v0024 = elt(env, 2); /* equal */
    if (v0060 == v0024) goto v0173;
    v0024 = qvalue(elt(env, 3)); /* nil */
    goto v0170;

v0170:
    if (v0024 == nil) goto v0088;
    v0024 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0024);

v0088:
    v0024 = v0156;
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    v0060 = v0056;
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    {
        fn = elt(env, 5); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0024, v0060);
    }

v0173:
    v0024 = v0056;
    v0060 = qcar(v0024);
    v0024 = elt(env, 1); /* neq */
    v0024 = (v0060 == v0024 ? lisp_true : nil);
    goto v0170;

v0077:
    v0024 = v0056;
    v0060 = qcar(v0024);
    v0024 = elt(env, 2); /* equal */
    v0024 = (v0060 == v0024 ? lisp_true : nil);
    goto v0091;
}



/* Code for matrixrd */

static Lisp_Object MS_CDECL CC_matrixrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrd");
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
    v0122 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0122;
    v0122 = nil;
    stack[0] = v0122;
    goto v0127;

v0127:
    v0025 = stack[-1];
    v0122 = (Lisp_Object)1; /* 0 */
    if (v0025 == v0122) goto v0093;
    v0025 = elt(env, 6); /* mat */
    v0122 = stack[0];
    v0122 = cons(v0025, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* aeval */
        return (*qfn1(fn))(qenv(fn), v0122);
    }

v0093:
    fn = elt(env, 8); /* lex */
    v0122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0025 = qvalue(elt(env, 2)); /* char */
    v0122 = elt(env, 3); /* (m a t r i x r o w) */
    if (equal(v0025, v0122)) goto v0087;
    v0122 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0122;
    goto v0127;

v0087:
    fn = elt(env, 9); /* matrixrowrd */
    v0122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0025 = v0122;
    v0122 = stack[0];
    if (v0122 == nil) goto v0086;
    v0122 = v0025;
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0122 = Lappend(nil, stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    stack[0] = v0122;
    goto v0124;

v0124:
    v0025 = qvalue(elt(env, 2)); /* char */
    v0122 = elt(env, 4); /* (!/ m a t r i x r o w) */
    if (equal(v0025, v0122)) goto v0127;
    v0025 = elt(env, 5); /* "</matrixrow>" */
    v0122 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 10); /* errorml */
    v0122 = (*qfn2(fn))(qenv(fn), v0025, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0127;

v0086:
    v0122 = v0025;
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    stack[0] = v0122;
    goto v0124;
/* error exit handlers */
v0100:
    popv(3);
    return nil;
}



/* Code for look_for_rational */

static Lisp_Object MS_CDECL CC_look_for_rational(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0068,
                         Lisp_Object v0044, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0210, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_rational");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_rational");
#endif
    if (stack >= stacklimit)
    {
        push3(v0044,v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0068,v0044);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0044;
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    v0234 = stack[0];
    v0210 = qcar(v0234);
    v0234 = elt(env, 1); /* sqrt */
    if (v0210 == v0234) goto v0171;
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0074;

v0074:
    if (v0234 == nil) goto v0072;
    v0061 = stack[-2];
    v0210 = stack[-1];
    v0234 = (Lisp_Object)33; /* 2 */
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v0061, v0210, v0234);
    }

v0072:
    v0234 = stack[0];
    v0210 = qcar(v0234);
    v0234 = elt(env, 3); /* expt */
    if (v0210 == v0234) goto v0088;
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0235;

v0235:
    if (v0234 == nil) goto v0015;
    v0061 = stack[-2];
    v0210 = stack[-1];
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v0061, v0210, v0234);
    }

v0015:
    v0234 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0234); }

v0088:
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0210 = qcar(v0234);
    v0234 = stack[-1];
    if (equal(v0210, v0234)) goto v0226;
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0235;

v0226:
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    fn = elt(env, 6); /* listp */
    v0234 = (*qfn1(fn))(qenv(fn), v0234);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    if (v0234 == nil) goto v0024;
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    v0210 = qcar(v0234);
    v0234 = elt(env, 4); /* quotient */
    if (v0210 == v0234) goto v0144;
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0235;

v0144:
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    if (is_number(v0234)) goto v0110;
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0235;

v0110:
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcdr(v0234);
    v0234 = qcar(v0234);
    v0234 = (is_number(v0234) ? lisp_true : nil);
    goto v0235;

v0024:
    v0234 = qvalue(elt(env, 2)); /* nil */
    goto v0235;

v0171:
    v0234 = stack[0];
    v0234 = qcdr(v0234);
    v0210 = qcar(v0234);
    v0234 = stack[-1];
    v0234 = (equal(v0210, v0234) ? lisp_true : nil);
    goto v0074;
/* error exit handlers */
v0200:
    popv(4);
    return nil;
}



/* Code for listeq */

static Lisp_Object CC_listeq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173, v0235;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */

v0067:
    v0173 = stack[-1];
    if (!consp(v0173)) goto v0092;
    v0173 = stack[0];
    if (!consp(v0173)) goto v0077;
    v0173 = stack[-1];
    v0235 = qcar(v0173);
    v0173 = stack[0];
    v0173 = qcar(v0173);
    v0173 = CC_listeq(env, v0235, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    if (v0173 == nil) goto v0157;
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    stack[0] = v0173;
    goto v0067;

v0157:
    v0173 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0173); }

v0077:
    v0173 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0173); }

v0092:
    v0235 = stack[-1];
    v0173 = stack[0];
    v0173 = (v0235 == v0173 ? lisp_true : nil);
    { popv(3); return onevalue(v0173); }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for evequal */

static Lisp_Object CC_evequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0124, v0226, v0037, v0088;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0226 = v0068;
    v0037 = v0000;
/* end of prologue */

v0067:
    v0090 = v0037;
    if (v0090 == nil) goto v0126;
    v0090 = qvalue(elt(env, 1)); /* nil */
    goto v0092;

v0092:
    if (v0090 == nil) goto v0074;
    v0090 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0090);

v0074:
    v0090 = v0037;
    if (v0090 == nil) goto v0168;
    v0090 = v0226;
    if (v0090 == nil) goto v0055;
    v0088 = (Lisp_Object)1; /* 0 */
    v0090 = v0037;
    v0124 = qcar(v0090);
    v0090 = v0226;
    v0090 = qcar(v0090);
    v0090 = (Lisp_Object)(int32_t)((int32_t)v0124 - (int32_t)v0090 + TAG_FIXNUM);
    if (v0088 == v0090) goto v0104;
    v0090 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0090);

v0104:
    v0090 = v0037;
    v0090 = qcdr(v0090);
    v0037 = v0090;
    v0090 = v0226;
    v0090 = qcdr(v0090);
    v0226 = v0090;
    goto v0067;

v0055:
    v0090 = elt(env, 3); /* (0) */
    v0226 = v0090;
    goto v0067;

v0168:
    v0090 = elt(env, 3); /* (0) */
    v0037 = v0090;
    goto v0067;

v0126:
    v0090 = v0226;
    v0090 = (v0090 == nil ? lisp_true : nil);
    goto v0092;
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0068,
                         Lisp_Object v0044, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0103, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-strand");
#endif
    if (stack >= stacklimit)
    {
        push3(v0044,v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0068,v0044);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0044;
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0050;

v0050:
    v0036 = stack[-1];
    if (v0036 == nil) goto v0172;
    v0103 = stack[-2];
    v0036 = stack[-1];
    v0036 = qcar(v0036);
    fn = elt(env, 1); /* color!-roads */
    v0139 = (*qfn2(fn))(qenv(fn), v0103, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-4];
    v0103 = stack[0];
    v0036 = stack[-3];
    v0036 = acons(v0139, v0103, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-4];
    stack[-3] = v0036;
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    stack[-1] = v0036;
    v0036 = stack[0];
    v0036 = add1(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-4];
    stack[0] = v0036;
    goto v0050;

v0172:
    v0036 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
/* error exit handlers */
v0235:
    popv(5);
    return nil;
}



/* Code for quotofd */

static Lisp_Object CC_quotofd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotofd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0094;

v0094:
    v0115 = stack[-2];
    if (v0115 == nil) goto v0074;
    v0115 = stack[-2];
    if (!consp(v0115)) goto v0051;
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = (consp(v0115) ? nil : lisp_true);
    goto v0158;

v0158:
    if (v0115 == nil) goto v0101;
    v0115 = stack[-2];
    if (!consp(v0115)) goto v0104;
    v0115 = qvalue(elt(env, 2)); /* nil */
    goto v0076;

v0076:
    if (v0115 == nil) goto v0226;
    stack[0] = stack[-3];
    v0032 = stack[-2];
    v0115 = stack[-1];
    fn = elt(env, 3); /* mkrn */
    v0115 = (*qfn2(fn))(qenv(fn), v0032, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    fn = elt(env, 4); /* int!-equiv!-chk */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    {
        Lisp_Object v0096 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0096, v0115);
    }

v0226:
    stack[0] = stack[-3];
    v0032 = stack[-2];
    v0115 = stack[-1];
    fn = elt(env, 6); /* lowest!-terms */
    v0115 = (*qfn2(fn))(qenv(fn), v0032, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    {
        Lisp_Object v0227 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0227, v0115);
    }

v0104:
    v0115 = stack[-1];
    v0115 = (consp(v0115) ? nil : lisp_true);
    goto v0076;

v0101:
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    stack[0] = qcar(v0115);
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0032 = qcdr(v0115);
    v0115 = stack[-1];
    v0032 = CC_quotofd(env, v0032, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0115 = stack[-3];
    v0115 = acons(stack[0], v0032, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    stack[-3] = v0115;
    v0115 = stack[-2];
    v0115 = qcdr(v0115);
    stack[-2] = v0115;
    goto v0094;

v0051:
    v0115 = qvalue(elt(env, 1)); /* t */
    goto v0158;

v0074:
    v0115 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0115);
    }
/* error exit handlers */
v0098:
    popv(5);
    return nil;
}



/* Code for subsq */

static Lisp_Object CC_subsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */
    v0056 = stack[-1];
    v0156 = qcar(v0056);
    v0056 = stack[0];
    fn = elt(env, 5); /* subf */
    v0056 = (*qfn2(fn))(qenv(fn), v0156, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-2] = v0056;
    v0056 = stack[-1];
    v0156 = qcdr(v0056);
    v0056 = stack[0];
    fn = elt(env, 5); /* subf */
    v0056 = (*qfn2(fn))(qenv(fn), v0156, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-1] = v0056;
    v0056 = stack[-1];
    fn = elt(env, 6); /* subs2!* */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0056 = qcar(v0056);
    if (!(v0056 == nil)) goto v0052;
    v0056 = stack[-2];
    fn = elt(env, 6); /* subs2!* */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0056 = qcar(v0056);
    if (v0056 == nil) goto v0104;
    v0056 = elt(env, 4); /* "Zero divisor" */
    v0156 = v0056;
    v0056 = v0156;
    qvalue(elt(env, 2)) = v0056; /* errmsg!* */
    v0056 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0056 == nil)) goto v0124;
    v0056 = v0156;
    fn = elt(env, 7); /* lprie */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0124;

v0124:
    v0056 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0052;

v0052:
    stack[0] = stack[-2];
    v0056 = stack[-1];
    fn = elt(env, 8); /* invsq */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    {
        Lisp_Object v0121 = stack[0];
        popv(4);
        fn = elt(env, 9); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0121, v0056);
    }

v0104:
    v0056 = elt(env, 1); /* "0/0 formed" */
    v0156 = v0056;
    v0056 = v0156;
    qvalue(elt(env, 2)) = v0056; /* errmsg!* */
    v0056 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0056 == nil)) goto v0085;
    v0056 = v0156;
    fn = elt(env, 7); /* lprie */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0085;

v0085:
    v0056 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0052;
/* error exit handlers */
v0123:
    popv(4);
    return nil;
}



/* Code for red!=subst1 */

static Lisp_Object CC_redMsubst1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0216, v0152, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=subst1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0068;
    stack[-6] = v0000;
/* end of prologue */
    v0216 = stack[-6];
    fn = elt(env, 5); /* bas_dpoly */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[0] = v0216;
    v0216 = stack[0];
    fn = elt(env, 6); /* dp_lc */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-1] = v0216;
    v0216 = stack[-6];
    fn = elt(env, 7); /* bas_rep */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-7] = v0216;
    v0216 = stack[-5];
    fn = elt(env, 5); /* bas_dpoly */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-3] = v0216;
    v0216 = stack[-3];
    fn = elt(env, 6); /* dp_lc */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-2] = v0216;
    v0216 = qvalue(elt(env, 1)); /* !*bcsimp */
    if (v0216 == nil) goto v0060;
    v0216 = stack[-2];
    fn = elt(env, 8); /* bc_inv */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-4] = v0216;
    if (v0216 == nil) goto v0229;
    v0152 = stack[-1];
    v0216 = stack[-4];
    fn = elt(env, 9); /* bc_prod */
    v0216 = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-1] = v0216;
    v0216 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* bc_fi */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-2] = v0216;
    goto v0060;

v0060:
    v0216 = stack[0];
    fn = elt(env, 11); /* dp_lmon */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = stack[-3];
    fn = elt(env, 11); /* dp_lmon */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    fn = elt(env, 12); /* mo_diff */
    v0216 = (*qfn2(fn))(qenv(fn), stack[-4], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-4] = v0216;
    v0152 = stack[-2];
    v0216 = stack[0];
    fn = elt(env, 13); /* dp_times_bc */
    stack[0] = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0151 = stack[-1];
    v0152 = stack[-4];
    v0216 = stack[-3];
    fn = elt(env, 14); /* dp_times_bcmo */
    v0216 = (*qfnn(fn))(qenv(fn), 3, v0151, v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v0216 = (*qfn2(fn))(qenv(fn), stack[0], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[0] = v0216;
    v0152 = stack[-2];
    v0216 = stack[-7];
    fn = elt(env, 13); /* dp_times_bc */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = stack[-5];
    fn = elt(env, 7); /* bas_rep */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    fn = elt(env, 14); /* dp_times_bcmo */
    v0216 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-4], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v0216 = (*qfn2(fn))(qenv(fn), stack[-2], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-1] = v0216;
    fn = elt(env, 16); /* cali_trace */
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = (Lisp_Object)1265; /* 79 */
    v0216 = (Lisp_Object)greaterp2(v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0216 = v0216 ? lisp_true : nil;
    env = stack[-8];
    if (v0216 == nil) goto v0237;
    v0216 = elt(env, 2); /* "---> " */
    v0216 = Lprinc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = stack[0];
    fn = elt(env, 17); /* dp_print */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    goto v0211;

v0211:
    fn = elt(env, 16); /* cali_trace */
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = (Lisp_Object)1425; /* 89 */
    v0216 = (Lisp_Object)greaterp2(v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0216 = v0216 ? lisp_true : nil;
    env = stack[-8];
    if (v0216 == nil) goto v0238;
    v0216 = elt(env, 4); /* " uses " */
    v0216 = Lprinc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = stack[-3];
    fn = elt(env, 17); /* dp_print */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    goto v0238;

v0238:
    v0216 = stack[-6];
    fn = elt(env, 18); /* bas_nr */
    v0151 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0152 = stack[0];
    v0216 = stack[-1];
    {
        popv(9);
        fn = elt(env, 19); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v0151, v0152, v0216);
    }

v0237:
    fn = elt(env, 16); /* cali_trace */
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = (Lisp_Object)1; /* 0 */
    v0216 = (Lisp_Object)greaterp2(v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0216 = v0216 ? lisp_true : nil;
    env = stack[-8];
    if (v0216 == nil) goto v0211;
    v0216 = elt(env, 3); /* "." */
    v0216 = Lprinc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    goto v0211;

v0229:
    v0152 = stack[-2];
    v0216 = stack[-1];
    fn = elt(env, 20); /* bc_gcd */
    v0216 = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    stack[-4] = v0216;
    v0152 = stack[-2];
    v0216 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v0216 = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = qcar(v0216);
    stack[-2] = v0216;
    v0152 = stack[-1];
    v0216 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v0216 = (*qfn2(fn))(qenv(fn), v0152, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-8];
    v0216 = qcar(v0216);
    stack[-1] = v0216;
    goto v0060;
/* error exit handlers */
v0236:
    popv(9);
    return nil;
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0239, v0223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkindxlist");
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
/* copy arguments values to proper place */
    v0239 = v0000;
/* end of prologue */
    stack[-4] = v0239;
    v0239 = stack[-4];
    if (v0239 == nil) goto v0092;
    v0239 = stack[-4];
    v0239 = qcar(v0239);
    v0223 = v0239;
    v0239 = v0223;
    v0239 = integerp(v0239);
    if (v0239 == nil) goto v0078;
    v0239 = v0223;
    fn = elt(env, 3); /* !*num2id */
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    goto v0171;

v0171:
    v0239 = ncons(v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    stack[-2] = v0239;
    stack[-3] = v0239;
    goto v0050;

v0050:
    v0239 = stack[-4];
    v0239 = qcdr(v0239);
    stack[-4] = v0239;
    v0239 = stack[-4];
    if (v0239 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0239 = stack[-4];
    v0239 = qcar(v0239);
    v0223 = v0239;
    v0239 = v0223;
    v0239 = integerp(v0239);
    if (v0239 == nil) goto v0024;
    v0239 = v0223;
    fn = elt(env, 3); /* !*num2id */
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    goto v0107;

v0107:
    v0239 = ncons(v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    v0239 = Lrplacd(nil, stack[-1], v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    v0239 = stack[-2];
    v0239 = qcdr(v0239);
    stack[-2] = v0239;
    goto v0050;

v0024:
    v0239 = v0223;
    v0239 = Lconsp(nil, v0239);
    env = stack[-5];
    if (v0239 == nil) goto v0114;
    v0239 = v0223;
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    v0239 = integerp(v0239);
    if (v0239 == nil) goto v0114;
    stack[0] = elt(env, 2); /* minus */
    v0239 = v0223;
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    fn = elt(env, 3); /* !*num2id */
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    v0239 = list2(stack[0], v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    goto v0107;

v0114:
    v0239 = v0223;
    goto v0107;

v0078:
    v0239 = v0223;
    v0239 = Lconsp(nil, v0239);
    env = stack[-5];
    if (v0239 == nil) goto v0229;
    v0239 = v0223;
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    v0239 = integerp(v0239);
    if (v0239 == nil) goto v0229;
    stack[0] = elt(env, 2); /* minus */
    v0239 = v0223;
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    fn = elt(env, 3); /* !*num2id */
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    v0239 = list2(stack[0], v0239);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-5];
    goto v0171;

v0229:
    v0239 = v0223;
    goto v0171;

v0092:
    v0239 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0239); }
/* error exit handlers */
v0029:
    popv(6);
    return nil;
}



/* Code for simpsqrt3 */

static Lisp_Object CC_simpsqrt3(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0024, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrt3");
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
    v0024 = stack[0];
    v0082 = qvalue(elt(env, 1)); /* listofallsqrts */
    v0082 = Lassoc(nil, v0024, v0082);
    stack[-1] = v0082;
    v0082 = stack[-1];
    if (v0082 == nil) goto v0168;
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    { popv(3); return onevalue(v0082); }

v0168:
    v0024 = qvalue(elt(env, 2)); /* listofnewsqrts */
    v0082 = qvalue(elt(env, 3)); /* knowntobeindep */
    v0082 = Latsoc(nil, v0024, v0082);
    stack[-1] = v0082;
    v0082 = stack[-1];
    if (v0082 == nil) goto v0067;
    v0024 = stack[0];
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    v0082 = Lassoc(nil, v0024, v0082);
    stack[-1] = v0082;
    v0082 = stack[-1];
    if (v0082 == nil) goto v0067;
    v0024 = stack[-1];
    v0082 = qvalue(elt(env, 1)); /* listofallsqrts */
    v0082 = cons(v0024, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0082; /* listofallsqrts */
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    { popv(3); return onevalue(v0082); }

v0067:
    v0082 = stack[0];
    fn = elt(env, 4); /* actualsimpsqrt */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[-1] = v0082;
    v0060 = stack[0];
    v0024 = stack[-1];
    v0082 = qvalue(elt(env, 1)); /* listofallsqrts */
    v0082 = acons(v0060, v0024, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0082; /* listofallsqrts */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for rtrnda */

static Lisp_Object CC_rtrnda(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0084, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtrnda");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0084 = v0068;
    stack[0] = v0000;
/* end of prologue */
    v0203 = stack[0];
    if (!consp(v0203)) goto v0074;
    v0203 = stack[0];
    v0203 = qcdr(v0203);
    v0090 = qcar(v0203);
    v0203 = (Lisp_Object)1; /* 0 */
    v0203 = (v0090 == v0203 ? lisp_true : nil);
    goto v0091;

v0091:
    if (v0203 == nil) goto v0043;
    v0084 = (Lisp_Object)1; /* 0 */
    v0203 = (Lisp_Object)1; /* 0 */
    v0203 = cons(v0084, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0203; /* rlval!# */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0043:
    v0203 = stack[0];
    fn = elt(env, 2); /* round!:dec1 */
    v0203 = (*qfn2(fn))(qenv(fn), v0203, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-1];
    v0084 = v0203;
    qvalue(elt(env, 1)) = v0084; /* rlval!# */
    v0084 = qcar(v0084);
    v0203 = qcdr(v0203);
    {
        popv(2);
        fn = elt(env, 3); /* decimal2internal */
        return (*qfn2(fn))(qenv(fn), v0084, v0203);
    }

v0074:
    v0203 = stack[0];
    v0203 = (Lisp_Object)zerop(v0203);
    v0203 = v0203 ? lisp_true : nil;
    env = stack[-1];
    goto v0091;
/* error exit handlers */
v0226:
    popv(2);
    return nil;
}



/* Code for !*s2i */

static Lisp_Object CC_Hs2i(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0171 = v0000;
/* end of prologue */
    v0077 = v0171;
    v0077 = integerp(v0077);
    if (!(v0077 == nil)) return onevalue(v0171);
    v0077 = elt(env, 1); /* "integer" */
    {
        fn = elt(env, 2); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0171, v0077);
    }
}



/* Code for even_action_pow */

static Lisp_Object MS_CDECL CC_even_action_pow(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0068,
                         Lisp_Object v0044, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0133, v0153, v0145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_pow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_pow");
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0044,v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0068,v0044,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
    stack[-3] = v0044;
    stack[-4] = v0068;
    v0145 = v0000;
/* end of prologue */
    v0131 = stack[-4];
    v0131 = qcar(v0131);
    v0153 = v0131;
    v0131 = stack[-4];
    v0131 = qcdr(v0131);
    stack[-1] = v0131;
    v0133 = v0153;
    v0131 = v0145;
    v0131 = Lassoc(nil, v0133, v0131);
    stack[0] = v0131;
    if (v0131 == nil) goto v0058;
    v0133 = stack[-1];
    v0131 = (Lisp_Object)17; /* 1 */
    if (v0133 == v0131) goto v0103;
    stack[-4] = v0153;
    v0131 = stack[-1];
    v0133 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    v0131 = stack[-1];
    v0153 = acons(stack[-4], v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    v0133 = qvalue(elt(env, 1)); /* nil */
    v0131 = (Lisp_Object)17; /* 1 */
    v0131 = acons(v0153, v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    goto v0024;

v0024:
    v0153 = stack[0];
    v0133 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v0131 = (*qfnn(fn))(qenv(fn), 3, v0153, v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    stack[0] = v0131;
    v0133 = stack[0];
    v0131 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0133, v0131);
    }

v0103:
    v0133 = (Lisp_Object)17; /* 1 */
    v0131 = (Lisp_Object)17; /* 1 */
    v0131 = cons(v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    goto v0024;

v0058:
    v0133 = v0153;
    v0153 = v0145;
    v0131 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* find_active_components */
    v0131 = (*qfnn(fn))(qenv(fn), 3, v0133, v0153, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    stack[-1] = v0131;
    v0133 = qvalue(elt(env, 1)); /* nil */
    v0131 = (Lisp_Object)17; /* 1 */
    v0131 = cons(v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    stack[0] = v0131;
    v0131 = stack[-1];
    stack[-5] = v0131;
    goto v0202;

v0202:
    v0131 = stack[-5];
    if (v0131 == nil) goto v0200;
    v0131 = stack[-5];
    v0131 = qcar(v0131);
    stack[-1] = v0131;
    v0133 = stack[-4];
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    fn = elt(env, 5); /* diffp */
    v0131 = (*qfn2(fn))(qenv(fn), v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    v0153 = stack[-1];
    v0133 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v0131 = (*qfnn(fn))(qenv(fn), 3, v0153, v0133, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v0131 = (*qfn2(fn))(qenv(fn), stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-6];
    stack[0] = v0131;
    v0131 = stack[-5];
    v0131 = qcdr(v0131);
    stack[-5] = v0131;
    goto v0202;

v0200:
    v0133 = stack[0];
    v0131 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0133, v0131);
    }
/* error exit handlers */
v0129:
    popv(7);
    return nil;
}



/* Code for gd_gcasesimpl */

static Lisp_Object CC_gd_gcasesimpl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_gcasesimpl");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0171 = stack[0];
    stack[-1] = qcar(v0171);
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    v0171 = qcar(v0171);
    fn = elt(env, 1); /* gd_simpl */
    v0168 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    v0171 = qcdr(v0171);
    v0171 = qcar(v0171);
    {
        Lisp_Object v0055 = stack[-1];
        popv(2);
        return list3(v0055, v0168, v0171);
    }
/* error exit handlers */
v0119:
    popv(2);
    return nil;
}



/* Code for taymindegreel */

static Lisp_Object CC_taymindegreel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taymindegreel");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0094;

v0094:
    v0088 = stack[-2];
    if (v0088 == nil) goto v0074;
    v0088 = stack[-2];
    v0088 = qcar(v0088);
    stack[0] = v0088;
    v0088 = (Lisp_Object)1; /* 0 */
    v0038 = v0088;
    goto v0076;

v0076:
    v0088 = stack[0];
    if (v0088 == nil) goto v0043;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-4];
    v0038 = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0076;

v0043:
    v0088 = v0038;
    v0038 = v0088;
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    fn = elt(env, 2); /* tayexp!-min2 */
    v0038 = (*qfn2(fn))(qenv(fn), v0038, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-4];
    v0088 = stack[-3];
    v0088 = cons(v0038, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-4];
    stack[-3] = v0088;
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    stack[-2] = v0088;
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0094;

v0074:
    v0088 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
/* error exit handlers */
v0079:
    popv(5);
    return nil;
}



/* Code for pasf_lnegrel */

static Lisp_Object CC_pasf_lnegrel(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0239, v0223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v0223 = v0000;
/* end of prologue */
    v0239 = v0223;
    v0095 = elt(env, 1); /* equal */
    if (v0239 == v0095) goto v0039;
    v0239 = v0223;
    v0095 = elt(env, 2); /* neq */
    if (v0239 == v0095) goto v0045;
    v0239 = v0223;
    v0095 = elt(env, 3); /* leq */
    if (v0239 == v0095) goto v0119;
    v0239 = v0223;
    v0095 = elt(env, 5); /* lessp */
    if (v0239 == v0095) goto v0081;
    v0239 = v0223;
    v0095 = elt(env, 6); /* geq */
    if (v0239 == v0095) goto v0085;
    v0239 = v0223;
    v0095 = elt(env, 4); /* greaterp */
    if (v0239 == v0095) goto v0040;
    v0239 = v0223;
    v0095 = elt(env, 7); /* cong */
    if (v0239 == v0095) goto v0053;
    v0239 = v0223;
    v0095 = elt(env, 8); /* ncong */
    if (v0239 == v0095) goto v0060;
    v0095 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v0095 == nil)) goto v0099;
    v0095 = elt(env, 10); /* "pasf_lnegrel: unknown operator" */
    v0239 = v0223;
    v0095 = list2(v0095, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[0];
    goto v0099;

v0099:
    v0095 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0095 = nil;
    { popv(1); return onevalue(v0095); }

v0060:
    v0095 = elt(env, 7); /* cong */
    { popv(1); return onevalue(v0095); }

v0053:
    v0095 = elt(env, 8); /* ncong */
    { popv(1); return onevalue(v0095); }

v0040:
    v0095 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v0095); }

v0085:
    v0095 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v0095); }

v0081:
    v0095 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v0095); }

v0119:
    v0095 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v0095); }

v0045:
    v0095 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v0095); }

v0039:
    v0095 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v0095); }
/* error exit handlers */
v0098:
    popv(1);
    return nil;
}



/* Code for dvfsf_smcpknowl */

static Lisp_Object CC_dvfsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0000;
/* end of prologue */
    v0093 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0093 == nil) goto v0074;
    v0093 = v0045;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0074:
    v0093 = v0045;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
}



/* Code for cnml */

static Lisp_Object MS_CDECL CC_cnml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0011;
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
    v0011 = qvalue(elt(env, 2)); /* atts */
    v0142 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 12); /* search_att */
    v0142 = (*qfn2(fn))(qenv(fn), v0011, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-2] = v0142;
    fn = elt(env, 13); /* lex */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = qvalue(elt(env, 4)); /* char */
    stack[0] = v0142;
    fn = elt(env, 13); /* lex */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0011 = stack[-2];
    v0142 = elt(env, 5); /* (c o n s t a n t) */
    if (!(equal(v0011, v0142))) goto v0168;
    v0142 = stack[0];
    v0142 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0011 = Lintern(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = qvalue(elt(env, 6)); /* rdci!* */
    v0011 = Lassoc(nil, v0011, v0142);
    v0142 = v0011;
    if (v0011 == nil) goto v0168;
    v0011 = v0142;
    v0011 = qcdr(v0011);
    v0011 = qcar(v0011);
    v0142 = qcdr(v0142);
    v0142 = qcdr(v0142);
    {
        popv(4);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v0011, v0142);
    }

v0168:
    v0142 = stack[0];
    v0142 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    if (!(symbolp(v0142))) goto v0090;
    v0142 = stack[0];
    v0011 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = (Lisp_Object)257; /* 16 */
    fn = elt(env, 15); /* errorml */
    v0142 = (*qfn2(fn))(qenv(fn), v0011, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    goto v0090;

v0090:
    v0142 = stack[-2];
    if (v0142 == nil) goto v0060;
    v0011 = stack[-2];
    v0142 = elt(env, 7); /* ((r e a l) (i n t e g e r)) */
    v0142 = Lmember(nil, v0011, v0142);
    if (v0142 == nil) goto v0233;
    v0142 = stack[0];
        popv(4);
        return Lcompress(nil, v0142);

v0233:
    v0011 = stack[-2];
    v0142 = elt(env, 8); /* ((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r)) 
*/
    v0142 = Lmember(nil, v0011, v0142);
    if (v0142 == nil) goto v0224;
    fn = elt(env, 16); /* seprd */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-1] = v0142;
    v0011 = stack[-2];
    v0142 = elt(env, 9); /* (r a t i o n a l) */
    if (equal(v0011, v0142)) goto v0227;
    v0011 = stack[-2];
    v0142 = elt(env, 10); /* (c o m p l e x !- c a r t e s i a n) */
    if (equal(v0011, v0142)) goto v0027;
    v0011 = stack[-2];
    v0142 = elt(env, 11); /* (c o m p l e x !- p o l a r) */
    if (!(equal(v0011, v0142))) goto v0224;
    v0142 = stack[0];
    v0011 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[-1];
    fn = elt(env, 17); /* po2ca */
    v0142 = (*qfn2(fn))(qenv(fn), v0011, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-1] = v0142;
    fn = elt(env, 13); /* lex */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[-1];
    v0011 = qcar(v0142);
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    v0142 = qcar(v0142);
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v0011, v0142);
    }

v0224:
    v0142 = nil;
    { popv(4); return onevalue(v0142); }

v0027:
    fn = elt(env, 13); /* lex */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[0];
    v0011 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[-1];
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v0011, v0142);
    }

v0227:
    fn = elt(env, 13); /* lex */
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[0];
    v0011 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0142 = stack[-1];
    {
        popv(4);
        fn = elt(env, 19); /* alg_quotient */
        return (*qfn2(fn))(qenv(fn), v0011, v0142);
    }

v0060:
    v0142 = stack[0];
        popv(4);
        return Lcompress(nil, v0142);
/* error exit handlers */
v0159:
    popv(4);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0116 = qvalue(elt(env, 2)); /* maxvar */
    v0040 = stack[0];
    v0040 = plus2(v0116, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    v0116 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0040/(16/CELL)));
    v0040 = (Lisp_Object)81; /* 5 */
    v0040 = *(Lisp_Object *)((char *)v0116 + (CELL-TAG_VECTOR) + ((int32_t)v0040/(16/CELL)));
    if (v0040 == nil) goto v0104;
    v0040 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0040); }

v0104:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0116 = qvalue(elt(env, 2)); /* maxvar */
    v0040 = stack[0];
    v0040 = plus2(v0116, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0116 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0040/(16/CELL)));
    v0040 = (Lisp_Object)49; /* 3 */
    v0040 = *(Lisp_Object *)((char *)v0116 + (CELL-TAG_VECTOR) + ((int32_t)v0040/(16/CELL)));
    v0040 = (is_number(v0040) ? lisp_true : nil);
    { popv(3); return onevalue(v0040); }
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for termorder1 */

static Lisp_Object CC_termorder1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */

v0067:
    v0038 = stack[-1];
    if (v0038 == nil) goto v0091;
    v0038 = stack[-1];
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0093;
    v0038 = stack[0];
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0093;
    v0038 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0038); }

v0093:
    v0038 = stack[-1];
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0078;
    v0038 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0038); }

v0078:
    v0038 = stack[0];
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0081;
    v0038 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0038); }

v0081:
    v0038 = stack[-1];
    v0053 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcar(v0038);
    v0038 = (Lisp_Object)lessp2(v0053, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0235;
    v0038 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0038); }

v0235:
    v0038 = stack[-1];
    v0053 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcar(v0038);
    v0038 = (Lisp_Object)greaterp2(v0053, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-2];
    if (v0038 == nil) goto v0084;
    v0038 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0038); }

v0084:
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    stack[-1] = v0038;
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    stack[0] = v0038;
    goto v0067;

v0091:
    v0038 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0038); }
/* error exit handlers */
v0052:
    popv(3);
    return nil;
}



/* Code for xexptpf */

static Lisp_Object CC_xexptpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xexptpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0045;

v0045:
    v0072 = stack[0];
    v0071 = (Lisp_Object)17; /* 1 */
    if (v0072 == v0071) goto v0091;
    v0072 = stack[-1];
    v0071 = stack[-2];
    v0071 = cons(v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    stack[-2] = v0071;
    v0071 = stack[0];
    v0071 = sub1(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    stack[0] = v0071;
    goto v0045;

v0091:
    v0071 = stack[-1];
    v0072 = v0071;
    goto v0074;

v0074:
    v0071 = stack[-2];
    if (v0071 == nil) { popv(4); return onevalue(v0072); }
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    fn = elt(env, 1); /* wedgepf */
    v0071 = (*qfn2(fn))(qenv(fn), v0071, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0072 = v0071;
    v0071 = stack[-2];
    v0071 = qcdr(v0071);
    stack[-2] = v0071;
    goto v0074;
/* error exit handlers */
v0040:
    popv(4);
    return nil;
}



/* Code for adjp */

static Lisp_Object CC_adjp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjp");
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
    v0032 = stack[-1];
    v0115 = elt(env, 1); /* unit */
    if (v0032 == v0115) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0115 = stack[-1];
    if (!consp(v0115)) goto v0051;
    v0115 = stack[-1];
    v0032 = qcar(v0115);
    v0115 = elt(env, 3); /* comm */
    if (v0032 == v0115) goto v0120;
    v0115 = stack[-1];
    v0032 = qcar(v0115);
    v0115 = elt(env, 4); /* anticomm */
    if (v0032 == v0115) goto v0053;
    v0115 = stack[-1];
    v0032 = qcar(v0115);
    v0115 = elt(env, 2); /* adjoint */
    v0032 = get(v0032, v0115);
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    popv(4);
    return cons(v0032, v0115);

v0053:
    stack[-2] = elt(env, 4); /* anticomm */
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    stack[0] = CC_adjp(env, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-3];
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    v0115 = CC_adjp(env, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        Lisp_Object v0098 = stack[-2];
        Lisp_Object v0096 = stack[0];
        popv(4);
        return list3(v0098, v0096, v0115);
    }

v0120:
    stack[-2] = elt(env, 3); /* comm */
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    stack[0] = CC_adjp(env, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-3];
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    v0115 = CC_adjp(env, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        Lisp_Object v0227 = stack[-2];
        Lisp_Object v0110 = stack[0];
        popv(4);
        return list3(v0227, v0110, v0115);
    }

v0051:
    v0115 = stack[-1];
    v0032 = elt(env, 2); /* adjoint */
    popv(4);
    return get(v0115, v0032);
/* error exit handlers */
v0223:
    popv(4);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v0043 = stack[0];
    v0042 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    v0043 = (Lisp_Object)49; /* 3 */
    if (!(v0042 == v0043)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0043 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    v0042 = v0043;
    if (v0042 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0042 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 2); /* mk_edge_parents */
    v0043 = (*qfn2(fn))(qenv(fn), v0042, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0103:
    popv(2);
    return nil;
}



setup_type const u38_setup[] =
{
    {"rationalizef",            CC_rationalizef,too_many_1,    wrong_no_1},
    {"lf=zero",                 CC_lfMzero,     too_many_1,    wrong_no_1},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"rl_pnf",                  CC_rl_pnf,      too_many_1,    wrong_no_1},
    {"simp0",                   CC_simp0,       too_many_1,    wrong_no_1},
    {"get-min-degreelist",      CC_getKminKdegreelist,too_many_1,wrong_no_1},
    {"get*order",               CC_getHorder,   too_many_1,    wrong_no_1},
    {"qqe_simplbtat",           too_few_2,      CC_qqe_simplbtat,wrong_no_2},
    {"pasf_pnf",                CC_pasf_pnf,    too_many_1,    wrong_no_1},
    {"dvfsf_0mk2",              too_few_2,      CC_dvfsf_0mk2, wrong_no_2},
    {"symbolsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbolsrd},
    {"search_att",              too_few_2,      CC_search_att, wrong_no_2},
    {"*rd2cr",                  CC_Hrd2cr,      too_many_1,    wrong_no_1},
    {"splitcomplex",            CC_splitcomplex,too_many_1,    wrong_no_1},
    {"nestzerop:",              CC_nestzeropT,  too_many_1,    wrong_no_1},
    {"dipretimes",              CC_dipretimes,  too_many_1,    wrong_no_1},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"zeros",                   CC_zeros,       too_many_1,    wrong_no_1},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"general-modular-difference",too_few_2,    CC_generalKmodularKdifference,wrong_no_2},
    {"ofsf_qesubqat",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubqat},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"look_for_rational",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_rational},
    {"listeq",                  too_few_2,      CC_listeq,     wrong_no_2},
    {"evequal",                 too_few_2,      CC_evequal,    wrong_no_2},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"subsq",                   too_few_2,      CC_subsq,      wrong_no_2},
    {"red=subst1",              too_few_2,      CC_redMsubst1, wrong_no_2},
    {"mkindxlist",              CC_mkindxlist,  too_many_1,    wrong_no_1},
    {"simpsqrt3",               CC_simpsqrt3,   too_many_1,    wrong_no_1},
    {"rtrnda",                  too_few_2,      CC_rtrnda,     wrong_no_2},
    {"*s2i",                    CC_Hs2i,        too_many_1,    wrong_no_1},
    {"even_action_pow",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_pow},
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
    {NULL, (one_args *)"u38", (two_args *)"3095 5716622 8890993", 0}
};

/* end of generated code */
