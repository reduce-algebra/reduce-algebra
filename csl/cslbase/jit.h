/* jit.h               Copyright (C) 2006-2008 J O'Connell & Codemist Ltd */

#ifndef header_jit_h
#define header_jit_h 1



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 65075512 24-May-2008 */


/*
 * At present the CSL JIT only supports the Intel/AMD x86 architecture.
 * Attempts to use it on other sorts of machine may have really bad
 * confusing consequences!
 */

#define x86arch    1

/*
 * Debug switch for the JIT
 */

#define JDEBUG     1


/* register, eg EAX */

#define EAX 0x0
#define ECX 0x1
#define EDX 0x2
#define EBX 0x3
#define ESP 0x4
#define EBP 0x5
#define ESI 0x6
#define EDI 0x7

/* memory indirection, eg [EAX] */

#define EAXM 0x8
#define ECXM 0x9
#define EDXM 0xa
#define EBXM 0xb
#define ESPM 0xc
#define EBPM 0xd
#define ESIM 0xe
#define EDIM 0xf

/* memory offset */

#define DISP32 0x10

/*
 * At some stage it may be good to arrange that the JIT assembler can decide
 * whether it needs a long-form branch or if a short one will suffice. At this
 * stage the choice is made globally. Define JUMPREL8 if you guarantee
 * all functions are tiny and you want the shortest code, or leave it
 * undefined for safer treatment of bigger examples.
 */

#ifdef JUMPREL8

/* Conditional branches with rel8 offset */

#define JA   0x77
#define JAE   0x73
#define JB    0x72
#define JBE   0x76
#define JC    0x72
#define JCXZ  0xe3
#define JECXZ 0xe3
#define JRCXZ 0xe3
#define JE    0x74
#define JG    0x7f
#define JGE   0x7d
#define JL    0x7c
#define JLE   0x7e
#define JNA   0x76
#define JNAE  0x72
#define JNB   0x73
#define JNBE  0x77
#define JNC   0x73
#define JNE   0x75
#define JNG   0x7e
#define JNGE  0x7c
#define JNL   0x7d
#define JNLE  0x7f
#define JNO   0x71
#define JNP   0x7b
#define JNS   0x79
#define JNZ   0x75
#define JO    0x70
#define JP    0x7a
#define JPE   0x7a
#define JPO   0x7b
#define JS    0x78
#define JZ    0x74

#else

/* Conditional branches with rel32 offset */

#define JA    0x0f87
#define JAE   0x0f83
#define JB    0x0f82
#define JBE   0x0f86
#define JC    0x0f82
#define JE    0x0f84
#define JG    0x0f8f
#define JGE   0x0f8d
#define JL    0x0f8c
#define JLE   0x0f8e
#define JNA   0x0f86
#define JNAE  0x0f82
#define JNB   0x0f83
#define JNBE  0x0f87
#define JNC   0x0f83
#define JNE   0x0f85
#define JNG   0x0f8e
#define JNGE  0x0f8c
#define JNL   0x0f8d
#define JNLE  0x0f8f
#define JNO   0x0f81
#define JNP   0x0f8b
#define JNS   0x0f89
#define JNZ   0x0f85
#define JO    0x0f80
#define JP    0x0f8a
#define JPE   0x0f8a
#define JPO   0x0f8b
#define JS    0x0f88
#define JZ    0x0f84

#endif /* JUMPREL */

/* Function defintions */

/* jitx86.h */

extern void inc_reg(int reg);
extern void dec_reg(int reg);
extern void sub_imm8_rm32(int size, int reg);
extern void sub_imm32_rm32(int size, int reg);
extern void add_imm8_addr(int size, void *addr);
extern void sub_imm8_addr(int size, void *addr);
extern void add_imm8_rm32(int size, int reg);
extern void add_imm32_rm32(int size, int reg);
extern void and_imm_rm32(int size, int reg);
extern void mov_rm32_rm32(int dest, int source);
extern void mov_rm32_rm32_disp(int dest, int source, int disp);
extern void cmp_imm_r32(int size, int reg);
extern void cmp_rm32_rm32(int dest, int source);
extern void cmp_rm32_rm32_disp(int dest, int source, int disp);
extern void mov_r32_addr(int dest, void *source);
extern void mov_addr_r32(void *dest, int source);
extern void lea_m32_r32_disp(int source, int dest, int disp);
extern void lea_m32_r32_disp(int source, int dest, int disp);
extern void MS_CDECL Jpush(int nargs, ...);
extern void MS_CDECL Jpop(int nargs, ...);

/* jit2.c */

typedef struct reloc_table_struct 
{
    char *label;
    unsigned long pos;
    struct reloc_table_struct *next;
} reloc_table;

typedef struct variables_table_struct 
{
    int addr;
    unsigned long pos;
    struct variables_table_struct *next;
} variables_table;

extern reloc_table *labels_table;
extern reloc_table *callers_table;
extern reloc_table *jumpers_table;
extern variables_table *vars_table;
extern reloc_table *disassembler_labels;

extern unsigned char codebuffer[8192];   /* rather arbitrary size! */
extern unsigned long codep;

extern void free_labels_table(reloc_table *head);
extern void free_var_table(variables_table *head);
extern void reloc_calls();
extern void reloc_jumps();
extern void reloc_vars();

extern void startcode();
extern void putbyte(int c);
extern void put2bytes(int c);
extern void put3bytes(int c);
extern void put4bytes(int c);
extern void put5bytes(long long c);
extern void put_little_endian(Lisp_Object c);
extern void put_addr(void *c);
extern int isreg(int reg);
extern void call_rel_fn(char *label);
extern void jump(char *label);
extern void cond_jump(char *label, int cond);
extern void add_label(char *label);
extern void add_disassembler_label(char *label);
extern void Jcall_abs_fn(void *addr_big_endian);

/* jit3.c */

#define init_stack_pointers() { put3bytes(0x5589e5); }
#define exit_stack_pointers() { put4bytes(0x89ec5dc3); }

#define exit_bytecode() exit_stack_pointers();
#define Jpush_all() { putbyte(0x60); }
#define Jpop_all()  { putbyte(0x61); }

#undef stack
#define stack &C_stack

/*
 * 83 ec 28              sub    $0x28,%esp
 * a1 xx xx xx xx        mov 0x0, %eax
 * 89 45 f8              mov %eax, 0xfffffff8(%ebp)
 */

#define Jsetup_nil() { put4bytes(0x83ec38a1);   \
        put_addr(&C_nil);                       \
        mov_rm32_rm32_disp(EAX,EBPM,-2); }

#define Jnil_eq_C_nil() { putbyte(0xa1);        \
        put_addr(&C_nil);                       \
        mov_rm32_rm32_disp(EAX,EBPM,-2); }

#define Jresult() { put3bytes(0x8b45f4); }

/*
 * used in bytecode compiler:
 */

#define load_stack_into(REG)        mov_rm32_rm32_disp(EBPM,REG,-2);
#define load_stackaddr_into(REG)    lea_m32_r32_disp(EBPM,REG,-2);
#define store_stack_from(REG)       mov_rm32_rm32_disp(REG,EBPM,-2);
#define load_nil_into(REG)          mov_rm32_rm32_disp(EBPM,REG,-1);
#define store_nil_from(REG)         mov_rm32_rm32_disp(REG,EBPM,-1);
#define load_entry_stack_into(REG)  mov_rm32_rm32_disp(EBPM,REG,4);
#define store_entry_stack_from(REG) mov_rm32_rm32_disp(REG,EBPM,4);
#define store_result_from(REG)      mov_rm32_rm32_disp(REG,EBPM,-15);

/*
 * OPTIMISE_REG is a pending enhancement!
 */

#ifndef OPTIMISE_REG

#define load_A_reg_into(REG)        mov_rm32_rm32_disp(EBPM,REG,-17);
#define store_A_reg_from(REG)       mov_rm32_rm32_disp(REG,EBPM,-17);
#define load_B_reg_into(REG)        { load_nil_into(REG);            \
                                      add_imm32_rm32(B_REG,REG); }
#else

#define load_A_reg_into(REG)        mov_rm32_rm32(EDI,REG);
#define store_A_reg_from(REG)       mov_rm32_rm32(REG,EDI);
#define load_B_reg_into(REG)        { load_nil_into(REG);            \
                                      add_imm32_rm32(B_REG,REG); }

#endif /* OPTIMISE_REG */

#define push_A_reg()                mov_rm32_rm32_disp(EDI,EBPM,-17);
#define pop_A_reg()                 mov_rm32_rm32_disp(EBPM,EDI,-17);

#define load_fringe_into(REG)    { load_nil_into(REG);               \
                                    add_imm32_rm32(FRINGE,REG); }

#define load_heaplimit_into(REG) { load_nil_into(REG);               \
                                   add_imm32_rm32(HEAPLIMIT,REG); }

#define load_codevec_into(REG)   { load_nil_into(REG);               \
                                   add_imm32_rm32(CODEVEC,REG); }

#ifdef LITVEC_FROM_NIL
#define load_litvec_into(REG)    { load_nil_into(REG);               \
                                   add_imm32_rm32(LITVEC,REG); }
#else
/* 
 * Loads litvec into REG from qcdr(def) which is passed as arg
 * to bytestream_interpret in 12(ebp)
 */
#define load_litvec_into(REG)      mov_rm32_rm32_disp(EBPM,REG,3); 
#endif

#define FRINGE 0x48 /* FIXME only works for x86 */
#define HEAPLIMIT 0x4c
#define B_REG 0xd4
#define CODEVEC 0xd8
#define LITVEC 0xdc

#define make_bc_label() sprintf(label,"BC%x",*ppc+bytecodes+1);
#define make_bc_label_backwards() sprintf(label,"BC%x",bytecodes-*ppc+1);
#define make_label(label,op,num) sprintf(label,"%s%i%i",op,num,bytecodes);


#endif /* header_jit_h */

/* end of jit.h */
