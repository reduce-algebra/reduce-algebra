/* jit3.c                   Copyright (C) 2006-2008, Codemist Ltd */
/*                                                and J O'Connell */


/*
 * Just in time compiler.
 * This is the main section of the compiler, and it ubpacks bytecodes
 * and generates the correspdonding machine code. Although this file is
 * very long it is really just a little section for each separate
 * byte operation.
 */

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




/* Signature: 00fdf200 24-May-2008 */

#ifndef WIN32
#include <sys/mman.h>
#endif

#include "headers.h"
#include "bytes.h"
#include "jit.h"
#include "opnames.c"

#ifdef X86
#include "distorm.h"
#endif

#ifdef MEMORY_TRACE
#define next_byte (cmemory_reference((intptr_t)ppc), *ppc++)
#else
#define next_byte *ppc++
#endif

//#define WTF 1

//extern Lisp_Object *do_freebind(Lisp_Object bvec, Lisp_Object *stk);

Lisp_Object *Jdo_freebind(Lisp_Object bvec, Lisp_Object *stk)
{
   int32_t n, k;
   n = length_of_header(vechdr(bvec));
   for (k=CELL; k<n; k+=CELL)
   {   Lisp_Object v = *(Lisp_Object *)((intptr_t)bvec + k - TAG_VECTOR);
       //push(qvalue(v));
       *++stk = qvalue(v);
       qvalue(v) = C_nil;
   }
/*
 * TAG_FBIND is a value that can NEVER occur elsewhere in the Lisp system,
 * and so it unambiguously marks a block of fluid bindings on that stack.
 */
    //push2(bvec, (Lisp_Object)SPID_FBIND);
    stk[1] = bvec; stk[2] = (Lisp_Object)SPID_FBIND; stk+=2;
    return stk;
}

Lisp_Object *Jdo_freerstr(Lisp_Object *stk)
{
    Lisp_Object bv;
    int32_t n;
    //popv(1);
    stk -= 1;
    //pop(bv);
    bv = *stk--;
    n = length_of_header(vechdr(bv));
    while (n>CELL)
    {   Lisp_Object v = *(Lisp_Object *)((intptr_t)bv + n - (CELL + TAG_VECTOR));
        n -= CELL;
        qvalue(v) = *stk--;
        //pop(qvalue(v));
    }
    return stk;
}

void test()
{
        printf("\ntest\n");
        return;
}

void breakpoint()
{

        //Lisp_Object nil = C_nil;
        
//        printf("\nSTART OF JIT CODE\n");
        
//        printf("C_stack: %x\tlitvec: %x\tC_nil: %x\t&C_nil: %x\n",(Lisp_Object)C_stack,(Lisp_Object)litvec,C_nil,(Lisp_Object)&C_nil);
//        printf("stack: %x\tC_stack: %x\tC_stack[-1]: %x\tC_stack[0]: %x\tC_stack[1]: %x\n",(Lisp_Object)stack,(Lisp_Object)C_stack,C_stack[-1],C_stack[0],C_stack[1]);
printf("\nC_stack: %p\n",C_stack);        
int i;
for(i=0;i<6;i++) {
        printf("C_stack[%d]: %x ",i-5,C_stack[i-5]);
}
printf("C_nil: %p",(void *)C_nil);
        return;
}

void bytecode_breakpoint(int ppc)
{
        printf("%s\n",opnames[ppc]);
        fflush(stdout);
        return;
}

void print_ffname(char *name)
{
        printf("\n---CALLING: %s\n",name);
        fflush(stdout);
        return;
}

void Jprint3(char* name)
{
        printf("%p\n",name);
        fflush(stdout);
        return;
}

void Jprint2(char* name)
{
        printf("%s\n",name);
        fflush(stdout);
        return;
}


void Jprint()
{
        /*
         * Prints celt(qcdr(def,0))
         */
        add_imm32_rm32(20,EAX);
        mov_rm32_rm32(EAXM,EAX);
        sub_imm32_rm32(2,EAX);
        mov_rm32_rm32(EAX,ESPM);
        Jcall_abs_fn(Jprint2);
        return;
}

void push_litvec()
{
        Lisp_Object nil = C_nil;
        //push(litvec);
        *++C_stack = litvec;
        return;
}

void pop_litvec()
{
        Lisp_Object nil = C_nil;
        //pop(litvec);
        litvec = *C_stack--;
        return;
}
void Jexception_pending()
{
        load_nil_into(EAX);
        and_imm_rm32(0x1,EAX);
        put2bytes(0x85c0);//test eax, eax
        return;
}

void Jcall_error()
{
        mov_rm32_rm32_disp(EBPM,EAX,3); //mov 12(ebp), eax
        put3bytes(0xc1e004); //sal $4, eax
        inc_reg(EAX); //inc eax
        mov_rm32_rm32_disp(EAX,ESPM,3);
        mov_rm32_rm32_disp(EBPM,EAX,2); //mov 8(ebp), eax
        mov_rm32_rm32_disp(EAXM,EAX,1); //mov 4(eax), eax
        sub_imm32_rm32(0x2,EAX); //sub 2, eax
        mov_rm32_rm32(EAXM,EAX); //mov (eax), eax
        mov_rm32_rm32_disp(EAX,ESPM,2);
        put4bytes(0xbe060000); put4bytes(0x00897424); putbyte(0x04); //mov 6, 4(esp)
        put4bytes(0xc7042402); put3bytes(0x000000); //mov 2, (esp)
        Jcall_abs_fn(error); //call error
        exit_stack_pointers(); //4 chars long
        //FIXME preserve registers from before? should pop them
        return;
}

void call0(int fname)
{
        /* r1 = elt(litvec, fname) */
        load_litvec_into(EBX);
        putbyte(0xb8);put_little_endian(fname);
        put3bytes(0xc1e002); //look at CALL3
        //put2bytes(0x0303);
        put2bytes(0x01d8);
        sub_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        /* f345 = qfn1(r1) */
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x10,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-8);
        //save_pc
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        put4bytes(0xc7442404);put4bytes(0x00000000);//mov 0, 4(esp)
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM);
        mov_rm32_rm32_disp(EBPM,EAX,-8);
        put2bytes(0xffd0);//call *eax
        store_A_reg_from(EAX);
        mov_addr_r32(&C_nil,EAX);
        store_nil_from(EAX);
        //exception pending
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        //restore pc
        return;
}

void call1(int fname)
{
        /* r1 = elt(litvec, fname) */
        load_litvec_into(EBX);
        putbyte(0xb8);put_little_endian(fname);
        put3bytes(0xc1e002); //look at CALL3
        put2bytes(0x01d8);
        //put2bytes(0x0303);
        sub_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        /* f1 = qfn1(r1) */
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x8,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-6);
        //save_pc
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        load_A_reg_into(EAX);
        mov_rm32_rm32_disp(EAX,ESPM,1);
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM);
        mov_rm32_rm32_disp(EBPM,EAX,-6);
        put2bytes(0xffd0);//call *eax
        store_A_reg_from(EAX);
        mov_addr_r32(&C_nil,EAX);
        store_nil_from(EAX);
        //exception pending
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        //restore pc
        return;
}

void call2(int fname)
{
        /* r1 = elt(litvec, fname) */
        load_litvec_into(EBX);
        putbyte(0xb8);put_little_endian(fname);
        put3bytes(0xc1e002); //look at CALL3
        put2bytes(0x01d8);
        //put2bytes(0x0303);
        sub_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        /* f2 = qfn2(r1) */
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0xc,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-7);
        //save_pc
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        load_A_reg_into(EAX);
        mov_rm32_rm32_disp(EAX,ESPM,2);
        load_B_reg_into(EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,ESPM,1);
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM);
        mov_rm32_rm32_disp(EBPM,EAX,-7);
        put2bytes(0xffd0);//call *eax
        store_A_reg_from(EAX);
        mov_addr_r32(&C_nil,EAX);
        store_nil_from(EAX);
        //exception pending
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        //restore pc
        return;
}

void call2r(int fname)
{
        /* r1 = elt(litvec, fname) */
        load_litvec_into(EBX);
        putbyte(0xb8);put_little_endian(fname);
        put3bytes(0xc1e002); //look at CALL3
        put2bytes(0x01d8);        
        //put2bytes(0x0303);
        sub_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        /* f2 = qfn2(r1) */
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0xc,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-7);
        //save_pc
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        load_B_reg_into(EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,ESPM,2);
        load_A_reg_into(EAX);
        mov_rm32_rm32_disp(EAX,ESPM,1);
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM);
        mov_rm32_rm32_disp(EBPM,EAX,-7);
        put2bytes(0xffd0);//call *eax
        store_A_reg_from(EAX);
        mov_addr_r32(&C_nil,EAX);
        store_nil_from(EAX);
        //exception pending
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        //restore pc
        return;
}

void jcall2(int fname)
{
        /* r1 = elt(litvec, fname) */
        load_litvec_into(EBX);
        putbyte(0xb8);put_little_endian(fname);
        put3bytes(0xc1e002); //look at CALL3
        put2bytes(0x01d8);
        //put2bytes(0x0303);
        sub_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        /* f2 = qfn2(r1) */
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0xc,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-7);
#ifdef DEBUG
#endif
//FIXME add below
        
#ifndef OUT_OF_LINE
        //dec countdown
        //cmp 0, countdown
        //cond_jump(,JNS);
        //Jcall_abs_fn(deal_with_tick);
        
        //putbyte(0xa1);put_addr(&stacklimit);//mov stacklimit,eax
        mov_addr_r32(stacklimit,EAX);
        cmp_rm32_rm32_disp(EAX,EBPM,-2);
        cond_jump("jcall22",JB);
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        put4bytes(0xc744240c);put4bytes(0x00000000);//mov 0, 12(esp)
        put4bytes(0xc7442408);put4bytes(0x02000000);//mov 2, 8(esp)
        put4bytes(0xc7442404);put4bytes(0x00000000);//mov LC1, 4(esp) FIXME
        load_A_reg_into(EAX);
        mov_rm32_rm32(EAX,ESPM);
        Jcall_abs_fn(reclaim);
        store_A_reg_from(EAX);
        mov_addr_r32(&C_nil,EAX);
        store_nil_from(EAX);
        //exception pending
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
#else

        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        
#endif
        add_label("jcall22");

        /*
         * Call bytestream_interpret instead of changing ppc.
         * This has more overhead but will be quicker for
         * bytecoded fns than running code below.
         */

        //FIXME add code here
        
        /*
         * This just calls f2(qenv(r1), B_reg, A_reg)
         */
        mov_rm32_rm32_disp(EBPM,EAX,4);
        mov_r32_addr(EAX,stack);
        load_A_reg_into(EAX);
        mov_rm32_rm32_disp(EAX,ESPM,2);
        load_B_reg_into(EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,ESPM,1);
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM);
        mov_rm32_rm32_disp(EBPM,EAX,-7);
        put2bytes(0xffd0);
        //really return out of bytecode stream
        mov_rm32_rm32_disp(EAX,EBPM,-15);
        exit_bytecode();
        return;
}

void Jcheck_nargs0()
{
        mov_rm32_rm32_disp(EBPM,EAX,3); //mov 0xc(%ebp), %eax
        cmp_imm_r32(0x0,EAX);
        cond_jump("L0",JE);
        Jcall_error();
        return;
}

void Jcheck_nargs3()
{
        /*
         * if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),
         *                                     fixnum_of_int((int32_t)nargs));
         */
        
        mov_addr_r32(&C_nil,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-6); //nil=C_nil
        mov_rm32_rm32_disp(EBPM,EAX,3); //mov 0xc(%ebp), %eax
        cmp_imm_r32(0x3,EAX);
        cond_jump("L1",JE);
        Jcall_error();
        
        /* 
         *     va_start(aa, nargs);
         *     a = va_arg(aa, Lisp_Object);
         *     b = va_arg(aa, Lisp_Object);
         *     c = va_arg(aa, Lisp_Object);
         *     va_end(aa);
         */
        
        add_label("L1");
        lea_m32_r32_disp(EBPM,EAX,4); //leal    16(%ebp), %eax
        mov_rm32_rm32_disp(EAX,EBPM,-1); //movl    %eax, -4(%ebp)
        mov_rm32_rm32_disp(EBPM,EDX,-1); //movl    -4(%ebp), %edx
        lea_m32_r32_disp(EBPM,EAX,-1); //leal    -4(%ebp), %eax
        add_imm32_rm32(0x4,EAXM); //addl    $4, (%eax)
        mov_rm32_rm32(EDXM,EAX); //movl    (%edx), %eax
        mov_rm32_rm32_disp(EAX,EBPM,-3); //movl    %eax, -12(%ebp)
        mov_rm32_rm32_disp(EBPM,EDX,-1); //movl    -4(%ebp), %edx
        lea_m32_r32_disp(EBPM,EAX,-1); //leal    -4(%ebp), %eax
        add_imm32_rm32(0x4,EAXM); //addl    $4, (%eax)
        mov_rm32_rm32(EDXM,EAX); //movl    (%edx), %eax
        mov_rm32_rm32_disp(EAX,EBPM,-4); //movl    %eax, -16(%ebp)
        mov_rm32_rm32_disp(EBPM,EDX,-1); //movl    -4(%ebp), %edx
        lea_m32_r32_disp(EBPM,EAX,-1); //leal    -4(%ebp), %eax
        add_imm32_rm32(0x4,EAXM); //addl    $4, (%eax)
        mov_rm32_rm32(EDXM,EAX); //movl    (%edx), %eax
        mov_rm32_rm32_disp(EAX,EBPM,-5); //movl    %eax, -20(%ebp)

        //push5
        /*
        mov_addr_r32(stack,EDX); //movl    C_stack, %edx
        add_imm32_rm32(0x4,EDX); //addl    $4, %edx
        mov_rm32_rm32_disp(EBPM,EAX,-6); //movl    -24(%ebp), %eax
        add_imm32_rm32(LITVEC,EAX); //addl    $220, %eax
        mov_rm32_rm32(EAXM,EAX); //movl    (%eax), %eax
        mov_rm32_rm32(EAX,EDXM); //movl    %eax, (%edx)
        mov_addr_r32(stack,EDX); //movl    C_stack, %edx
        add_imm32_rm32(0x8,EDX); //addl    $8, %edx
        mov_rm32_rm32_disp(EBPM,EAX,-6); //movl    -24(%ebp), %eax
        add_imm32_rm32(CODEVEC,EAX); //addl    $216, %eax
        mov_rm32_rm32(EAXM,EAX); //movl    (%eax), %eax
        mov_rm32_rm32(EAX,EDXM);//movl    %eax, (%edx)
        */
        mov_addr_r32(stack,EAX); //movl    C_stack, %edx
        add_imm32_rm32(0x4,EAX); //addl    $12, %edx
        mov_rm32_rm32_disp(EBPM,EBX,-3); //movl    -12(%ebp), %eax
        mov_rm32_rm32(EBX,EAXM); //movl    %eax, (%edx)
        mov_addr_r32(stack,EAX); //movl    C_stack, %edx
        add_imm32_rm32(0x8,EAX); //addl        $16, %edx
        mov_rm32_rm32_disp(EBPM,EBX,-4); //movl    -16(%ebp), %eax
        mov_rm32_rm32(EBX,EAXM); //movl    %eax, (%edx)
        mov_addr_r32(stack,EAX); //movl    C_stack, %edx
        add_imm32_rm32(0xc,EAX); //addl        $20, %edx
        mov_rm32_rm32_disp(EBPM,EBX,-5); //movl    -20(%ebp), %eax
        mov_rm32_rm32(EBX,EAXM); //movl    %eax, (%edx)
        
        mov_addr_r32(stack,EAX);
        add_imm32_rm32(0xc,EAX);
        mov_r32_addr(EAX,stack);
        
        //add_imm8_addr(0xc,stack); //FIXME ILLEGAL INSTRUCTION?
}

void Jcheck_nargsn()
{
        mov_addr_r32(stack,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-4); //stack_save
        /*
        mov_addr_r32(stack,EDX);
        add_imm32_rm32(0x4,EDX);
        mov_rm32_rm32_disp(EBPM,EAX,-2);
        add_imm32_rm32(LITVEC,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,EDXM);
        mov_addr_r32(stack,EDX);
        add_imm32_rm32(0x8,EDX);
        mov_rm32_rm32_disp(EBPM,EAX,-2);
        add_imm32_rm32(CODEVEC,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,EDXM);
        mov_addr_r32(stack,EDX);
        add_imm32_rm32(0x8,EDX);
        mov_r32_addr(EDX,stack);
        */
        put4bytes(0x837d0c00);//cmpl $0, 12(%ebp)
        cond_jump("L2",JE);
        lea_m32_r32_disp(EBPM,EAX,4);
        mov_rm32_rm32_disp(EAX,EBPM,-5);
        mov_rm32_rm32_disp(EBPM,EAX,3);
        mov_rm32_rm32_disp(EAX,ESPM,1);
        mov_rm32_rm32_disp(EBPM,EAX,-5);
        mov_rm32_rm32(EAX,ESPM);
        Jcall_abs_fn(push_args);
        add_label("L2");
        //insert stackcheck1
        
        mov_rm32_rm32_disp(EBPM,EAX,2);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-1);
        mov_rm32_rm32_disp(EBPM,EAX,-1);
        put3bytes(0xc1e81c);//shrl $28,%eax
        put4bytes(0x8d148500); put3bytes(0x000000);//leal 0(,%eax,4), %edx
        mov_addr_r32(&bps_pages,EAX);
        put3bytes(0x8b0402);//movl (%edx,%eax), %eax FIXME not sure about x86
        add_imm32_rm32(0x7,EAX);
        mov_rm32_rm32(EAX,EDX);
        and_imm_rm32(0xf8,EDX);
        mov_rm32_rm32_disp(EBPM,EAX,-1);
        put3bytes(0xc1f806);//sarl 6, %eax
        put4bytes(0x25fcff3f); putbyte(0x00);//andl 4194300, %eax //little_endian
        put4bytes(0x0fb60402);//movzbl (%edx,%eax), %eax FIXME not sure about x86
        put3bytes(0x3b450c);//cmpl 12(%ebp), %eax
        cond_jump("L3",JE);
        mov_rm32_rm32_disp(EBPM,EAX,3);
        put4bytes(0x8d148500); put3bytes(0x000000);//leal 0(,%eax,4), %edx
        mov_addr_r32(stack,EAX);
        put2bytes(0x29d0);//sub %edx, %eax
        sub_imm32_rm32(0x8,EAX);
        mov_r32_addr(EAX,stack);
        Jcall_error();

        add_label("L3");//bytestream_interpret
}

void Jpop_vecs()
{
        //mov_addr_r32(stack,EDX); //mov C_stack,%edx
        //sub_imm32_rm32(0x8, EDX);
        //mov_r32_addr(EDX,stack); //mov %edx, C_stack
        //Jcall_abs_fn(dec_stack);
        //Jcall_abs_fn(dec_stack);
        /*
        
        sub_imm8_addr(0x8,stack); FIXME ILLEGAL INSTRUCTION?
        
        mov_rm32_rm32_disp(EBPM,EDX,-2); //mov -8(%ebp), %edx //C_nil
        add_imm32_rm32(CODEVEC,EDX); //add 216, %edx
        mov_addr_r32(stack,EAX); //mov C_stack, %eax
        add_imm32_rm32(0x8, EAX); //addl $0x8,%eax
        mov_rm32_rm32(EAXM,EAX); //mov (%eax),%eax
        mov_rm32_rm32(EAX,EDXM); //mov %eax, (%edx)
        mov_rm32_rm32_disp(EBPM,EDX,-2); //mov -8(%ebp), %edx //C_nil
        add_imm32_rm32(LITVEC,EDX); //add 220, %edx
        mov_addr_r32(stack,EAX); //mov C_stack, %eax
        add_imm32_rm32(0x4, EAX); //addl $0x4,%eax
        mov_rm32_rm32(EAXM,EAX); //mov (%eax),%eax
        mov_rm32_rm32(EAX,EDXM); //mov %eax, (%edx)
*/
        //move result to local var
        mov_rm32_rm32_disp(EBPM,EAX,-1); //mov -4(%ebp), %eax
        mov_rm32_rm32_disp(EAX,EBPM,-3); //mov %eax, -12(%ebp)
}
                                                

void MS_CDECL Jpush_stack(int nargs) //ifndef MEMORY_TRACE in externs.h
{
        //must align stack correctly 4 bytes for 32bit, 8 bytes for 64bit
        //and check for BASE.  nil-4 in common lisp
        
        add_label("L0");
        //Jnil_eq_C_nil();//nil=C_nil
        /*
        mov_addr_r32(stack,EDX); //mov C_stack, %edx
        add_imm32_rm32(0x4, EDX); //add 04, %edx
        mov_rm32_rm32_disp(EBPM,EAX,-2);//mov -8(%ebp), %eax //C_nil
        add_imm32_rm32(LITVEC, EAX); //add 220, %eax
        mov_rm32_rm32(EAXM,EAX); //mov (%eax),%eax
        mov_rm32_rm32(EAX,EDXM); //mov %eax, (%edx)
        mov_addr_r32(stack,EDX); //mov C_stack, %edx
        add_imm32_rm32(0x8, EDX); //add 08, %edx
        mov_rm32_rm32_disp(EBPM,EAX,-2);//mov -8(%ebp), %eax //C_nil
        add_imm32_rm32(CODEVEC, EAX); //add 216 eax
        mov_rm32_rm32(EAXM,EAX); //mov (%eax),%eax
        mov_rm32_rm32(EAX,EDXM); //mov %eax, (%edx)
        */
                                                        
        if (nargs==0)
        {
                //add_imm8_addr(0x8,stack);
                                                
        }
        
        if (nargs==1)
        {
                mov_addr_r32(stack,EAX); //mov C_stack, %edx
                add_imm32_rm32(0x4, EAX); //addl 0xc,%edx
                mov_rm32_rm32_disp(EBPM,EBX,3); //mov 0xc(%ebp), %eax
                mov_rm32_rm32(EBX,EAXM); //mov %eax,(%edx)
                
                mov_addr_r32(stack,EAX);
                add_imm32_rm32(0x4,EAX);
                mov_r32_addr(EAX,stack);
                //add_imm8_addr(0x4,stack);
        }

        
        if (nargs==2)
        {
                mov_addr_r32(stack,EAX); //mov C_stack, %edx
                add_imm32_rm32(0x4, EAX); //addl $0x0c,%edx
                mov_rm32_rm32_disp(EBPM,EBX,3); //mov 0xc(%ebp), %eax
                mov_rm32_rm32(EBX,EAXM); //mov %eax,(%edx)
                mov_addr_r32(stack,EAX); //mov C_stack, %edx
                add_imm32_rm32(0x8, EAX); //addl $0x10,%edx
                mov_rm32_rm32_disp(EBPM,EBX,4); //mov 0x10(%ebp), %eax
                mov_rm32_rm32(EBX,EAXM); //mov %eax,(%edx)
                
                mov_addr_r32(stack,EAX);
                add_imm32_rm32(0x8,EAX);
                mov_r32_addr(EAX,stack);
                //add_imm8_addr(0x8,stack);
        }
}

void Jstackcheck1(int k)
{
        /* stackcheck in #externs.h */
        //FIXME below
        //dec countdown
        //cmp 0 countdown
        //jns stackcheck10
        //test eax eax
        //jne stackcheck11
        add_disassembler_label("STACKCHECK");
        mov_addr_r32(stacklimit,EAX);
        put2bytes(0x3905);put_addr(stack);
        //mov_addr_r32(stack,EBX);
        //cmp_rm32_rm32(EAX,EBX);
        cond_jump("stackcheck11",JAE);
        jump("stackcheck12");
        add_label("stackcheck11");
        put4bytes(0xc744240c);put4bytes(0x00000000);//mov 0, 12(esp)
        put4bytes(0xc7442408);put4bytes(0x02000000);//mov 2, 8(esp)
        put4bytes(0xc7442404);put4bytes(0x65656500);//mov LC0, 4(esp) FIXME
        mov_rm32_rm32_disp(EBPM,EAX,2);//def
        mov_rm32_rm32(EAX,ESPM);
        Jcall_abs_fn(reclaim);
        mov_rm32_rm32_disp(EAX,EBPM,2);
        /*
        mov_addr_r32(&C_nil,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-6); //FIXME consistent address for nil?
        */
        //exceptionpending
        add_label("stackcheck12");//end
        return;
}

void Jcall(char *label, int pos)
{
        reloc_table *tmp;
        int offset;
        tmp = labels_table;
        while(tmp != NULL)
        {
                printf("\n%s\n",tmp->label);
                if(strcmp(label,tmp->label)==0)
                {
                        offset = tmp->pos - pos;
                        printf("\n%d\n",offset);
                }
                else tmp = tmp->next;
        }
}

void Jprepare_bytecode_compiler(int nargs)
{
        add_disassembler_label("BYTESTREAM_INTERPRET");
        if(nargs!=0 && nargs!=1 && nargs!=2 && nargs!=3) {
                mov_rm32_rm32_disp(EBPM,EAX,3);
                put4bytes(0x8d148500); put3bytes(0x000000);//leal 0(,%eax,4), %edx
                mov_addr_r32(stack,EAX);
                put2bytes(0x29d0); //sub edx, eax
                mov_rm32_rm32_disp(EAX,ESPM,2);
                mov_rm32_rm32_disp(EBPM,EAX,2);
                mov_rm32_rm32_disp(EAXM,EAX,1);
                mov_rm32_rm32_disp(EAX,ESPM,1);
                mov_rm32_rm32_disp(EBPM,EAX,-1);
                dec_reg(EAX);
                mov_rm32_rm32(EAX,ESPM);
                call_rel_fn("bytestream_interpret");
        }
        else {
                mov_addr_r32(stack,EAX); //mov C_stack, eax
                if(nargs==1) sub_imm32_rm32(0x4, EAX); //sub 4, eax
                if(nargs==2) sub_imm32_rm32(0x8, EAX); //sub 8, eax
                if(nargs==3) sub_imm32_rm32(0xc, EAX); //sub c, eax
                mov_rm32_rm32_disp(EAX,ESPM,2);
                mov_rm32_rm32_disp(EBPM,EAX,2); //mov 0x8(ebp), eax
                mov_rm32_rm32_disp(EAXM,EAX,1); //mov 0x4(eax),eax
                mov_rm32_rm32_disp(EAX,ESPM,1);
                mov_rm32_rm32_disp(EBPM,EAX,2); //mov 0x8(ebp), eax
                mov_rm32_rm32(EAXM,EAX); //mov (eax), eax
                sub_imm32_rm32(0x2, EAX); //sub 0x2, eax
                mov_rm32_rm32(EAX,ESPM);
                call_rel_fn("bytestream_interpret");
        }
}

Lisp_Object Jbpsupbv(Lisp_Object nil, Lisp_Object v)
{
        Header h;
        int32_t n;
        CSL_IGNORE(nil);
        if (!(is_bps(v))) return aerror1("bps-upbv", v);
        h = *(Header *)((char *)data_of_bps(v) - CELL);
        n = length_of_header(h) - CELL;
        //return fixnum_of_int(n-1);
        return n;
}

int Jbytecode_compile(Lisp_Object def, int nargs)
{
        /*
         * A_reg uses register ECX
         */
        
        Lisp_Object nil = C_nil;
        register unsigned char *ppc;
        Lisp_Object code;
        if(nargs>3) {
                code = qcar(def)-1;
        }
        else {
                code = qcar(def)-2;
        }
        ppc = (unsigned char *)data_of_bps(code);
        ppc = ppc + ((int32_t)code & 3);

        int bytecodes = 0;//FIXME overflow ?
        int length = 0;
        char label[64]=""; /* used for bytecode label */

        char label1[64]="";
        char label2[64]="";
        char label3[64]="";
        char label4[64]="";
        int i; //used in loops for bytecode
        
        //Add entry to label table indicating start of bytecodes
        add_label("bytestream_interpret");
        init_stack_pointers();
        sub_imm32_rm32(0x78, ESP); //sub 0x78,esp FIXME not AMD64 comp
        //Lisp_Object nil = C_nil
        mov_addr_r32(&C_nil,EAX); //nil=C_nil
        mov_rm32_rm32_disp(EAX,EBPM,-1); //mov %eax, -4(ebp)
        //Lisp_Object *stack = C_stack
        mov_addr_r32(stack,EAX); //mov C_stack, %eax
        mov_rm32_rm32_disp(EAX,EBPM,-2); //mov %eax, -8(ebp)
        /*
        //litvec = lit = qcdr(def) passed as arg to this fn
        mov_rm32_rm32_disp(EBPM,EDX,-1);
        add_imm32_rm32(LITVEC,EDX);
        mov_rm32_rm32_disp(EBPM,EAX,3);
        mov_rm32_rm32(EAX,EDXM);
        */
        //codevec = (Lisp_Object)(((int32_t)code & ~3) + 2)
        /*
        mov_rm32_rm32_disp(EBPM,EDX,-1);
        add_imm32_rm32(CODEVEC,EDX);
        mov_rm32_rm32_disp(EBPM,EAX,2);
        and_imm_rm32(0xfc,EAX);
        add_imm32_rm32(0x2,EAX);
        mov_rm32_rm32(EAX,EDXM);
        */
        //A_reg=nil
        mov_rm32_rm32_disp(EBPM,ECX,-1);
        mov_rm32_rm32_disp(ECX,EBPM,-17);
        mov_rm32_rm32(ECX,EDI);

        Lisp_Object bytecode = Lsymbol_env(nil,elt(qcdr(def),0));
        length = Jbpsupbv(nil, qcar(bytecode));
        if(nargs>3) {
                length--;
        }
        //printf("Length: %x\n",length);
        
        for (;bytecodes<length;)
        {
#ifdef X86
                //add label for disassembler output
                add_disassembler_label(opnames[*ppc]);
#endif
                
                //add a label for each iteration through loop
                sprintf(label, "BC%x",bytecodes);
                add_label(label);
#ifdef JDEBUG
                printf("Bytecode %i: %s\tcodep: %lu\n",bytecodes,opnames[*ppc],codep);
#endif
                bytecodes++; //counter use for jump bytecodes
#define JDEBUG1
#ifdef JDEBUG1
                //print name of bytecode running now
                putbyte(0xb8); put_little_endian(*ppc);
                mov_rm32_rm32(EAX,ESPM);
                Jcall_abs_fn(bytecode_breakpoint);
#endif

/*
 * cant dirty ECX or EDX any more if using OPTIMISE_REG
 * A_reg = ECX
 * B_reg = EDX
 */
                
        switch (next_byte) // *ppc++
        {
                case OP_LOC0EXIT:
                        /* A_reg = stack[0]; */
                        load_stack_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        /* C_stack = entry_stack; */
                        load_entry_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        /* return A_reg; */
                        load_A_reg_into(EAX);
                        //store_result_from(ECX);
                        exit_bytecode();
                        continue;

                case OP_LOC1EXIT:
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4, ECX); //sub 0x4, %eax
                        mov_rm32_rm32(ECXM,ECX); //mov (%eax), %eax
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        load_entry_stack_into(EAX);
                        mov_r32_addr(EAX,stack); //C_stack = entry_stack
                        load_A_reg_into(EAX);
                        //store_result_from(ECX);
                        exit_bytecode();
                        continue;

                case OP_LOC2EXIT:
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX); //sub $0x8,%eax
                        mov_rm32_rm32(ECXM,ECX); //mov (%eax),%eax
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        load_entry_stack_into(EAX);
                        mov_r32_addr(EAX,stack); //C_stack = entry_stack
                        load_A_reg_into(EAX);
                        //store_result_from(EAX);
                        exit_bytecode();
                        continue;

                case OP_NILEXIT:
                        load_entry_stack_into(EAX);
                        mov_r32_addr(EAX,stack); //C_stack = entry_stack
                        load_nil_into(EAX);
                        store_result_from(EAX);
                        exit_bytecode();
                        continue;

                case OP_FREEBIND:
                        load_stack_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_litvec_into(EBX);
                        putbyte(0xb8);put_little_endian(*ppc);
                        put3bytes(0xc1e002);//sall 2, eax
                        //put2bytes(0x0303);//add_rm32_rm32(EBXM,EAX);//FIXME or 01
                        put2bytes(0x01d8); //litvec is mem now
                        sub_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(Jdo_freebind);
                        store_stack_from(EAX);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_FREERSTR:
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(Jdo_freerstr);
                        store_stack_from(EAX);
                        continue;

                case OP_STOREFREE:
                        load_litvec_into(EBX);
                        putbyte(0xb8);put_little_endian(*ppc);
                        put3bytes(0xc1e002);//sall 2, eax
                        put2bytes(0x01d8);//add_rm32_rm32(EBX,EAX);
                        sub_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_STOREFREE1:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        continue;

                case OP_STOREFREE2:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x6,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        continue;

                case OP_STOREFREE3:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(10,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        continue;

                case OP_PUSHNILS:
                        for(i=0; i<*ppc; i++) {
                                load_stackaddr_into(EAX);
                                add_imm32_rm32(0x4,EAXM);
                                load_stack_into(EBX);
                                load_nil_into(EAX);
                                mov_rm32_rm32(EAX,EBXM);
                        }
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_VNIL:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_nil_into(EAX);
                        store_A_reg_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_SWOP:
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        store_A_reg_from(EAX);
                        continue;

                case OP_NCONS:
#ifndef OUT_OF_LINE
                        load_fringe_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_nil_into(EBX);
                        mov_rm32_rm32_disp(EBX,EAXM,1);//FIXME ok disp?
                        load_fringe_into(EBX);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,EBXM);
                        //FIXME heaplimit?
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        store_A_reg_from(EAX);
#else
#endif
#ifdef COMMON
#endif
                        continue;

                case OP_XCONS:
#ifdef OUT_OF_LINE
                        load_fringe_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_B_reg_into(EBX);
                        mov_rm32_rm32(EBXM,EBX);
                        mov_rm32_rm32_disp(EBX,EAXM,1);
                        load_fringe_into(EBX);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,EBXM);
                        //heaplimit?
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        store_A_reg_from(EAX);
#else
#endif
#ifdef COMMON
#endif
                        continue;

                case OP_LIST2:
                        //FIXME outofline
                        //save_pc
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(list2);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restorepc
                        continue;

                case OP_ACONS:
#ifndef OUT_OF_LINE
                        load_fringe_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        sub_imm32_rm32(0x10,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        mov_rm32_rm32_disp(EBPM,ECX,-3);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAX,ECXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32_disp(EBX,EAXM,1); //FIXME of disp?
                        mov_rm32_rm32_disp(EBPM,EBX,-3);
                        add_imm32_rm32(0x8,EBX);
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,ECX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        mov_rm32_rm32(ECXM,EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        mov_rm32_rm32_disp(EBPM,ECX,-3);
                        add_imm32_rm32(0x8,ECX);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,ECXM,4);//FIXME ok disp?
                        load_fringe_into(ECX);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,ECXM);
                        //heaplimit?
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        store_A_reg_from(EAX);
#else
#endif
#ifdef COMMON
#endif
                        continue;

                case OP_LIST2STAR:
#ifndef OUT_OF_LINE
                        load_fringe_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        sub_imm32_rm32(0x10,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        mov_rm32_rm32_disp(EBPM,EBX,-3);
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,ECX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        mov_rm32_rm32(ECXM,EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        mov_rm32_rm32_disp(EBPM,EBX,-3);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32_disp(EAX,EBXM,1);
                        mov_rm32_rm32_disp(EBPM,EBX,-3);
                        add_imm32_rm32(0x8,EBX);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0x8,EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32_disp(EBX,EAXM,1);
                        load_fringe_into(EBX);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,EBXM);
                        //heaplimit?
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        store_A_reg_from(EAX);
#else
#endif
#ifdef COMMON
#endif
                        continue;

                case OP_ADD1:
                        make_label(label1,"ADD1",1);
                        make_label(label2,"ADD1",2);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7, ECX);
                        cmp_imm_r32(0x1,ECX);
                        cond_jump(label1,JNE);
                        put3bytes(0x817dbc); put4bytes(0x7ffffff1);//cmp 2147483647, -68(ebp)
                        cond_jump(label1,JE);
                        put4bytes(0x8345bc10);//add 16, -68(ebp) FIXME should be for ecx
                        jump(label2); //jump to end of bytecode
#ifdef COMMON
#endif
                        /* floating, bignum or error arithmetic support */
                        add_label(label1);
                        //save_pc()
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        put4bytes(0xb8110000);putbyte(0x00); put4bytes(0x89442404);//mov 17, 4(esp) 
                        //put4bytes(0xc7442404); put4bytes(0xf1ffffff);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,ESPM);
                        Jcall_abs_fn(plus2);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
#ifdef COMMON
#endif
                        add_label(label2);
                        continue;

                case OP_SUB1:
                        make_label(label1,"SUB1",1);
                        make_label(label2,"SUB1",2);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7, ECX);
                        cmp_imm_r32(0x1,ECX);
                        cond_jump(label1,JNE);
                        put3bytes(0x817dbc); put4bytes(0x01000080);//cmp -2147483647, -68(ebp)
                        cond_jump(label1,JE);
                        put4bytes(0x836dbc10);//sub 16, -68(ebp) FIXME should be for ecx
                        jump(label2); //jump to end of bytecode
#ifdef COMMON
#endif
                        /* floating, bignum or error arithmetic support */
                        add_label(label1);
                        //save_pc()
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        put4bytes(0xb8f1ffff);putbyte(0xff); put4bytes(0x89442404);//mov -15, 4(esp) 
                        //put4bytes(0xc7442404); put4bytes(0xf1ffffff);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,ESPM);
                        Jcall_abs_fn(plus2);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
#ifdef COMMON
#endif
                        add_label(label2);
                        continue;

                case OP_TIMES2:
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,1);
                        load_B_reg_into(EDX);
                        mov_rm32_rm32(EDXM,EDX);
                        mov_rm32_rm32(EDX,ESPM);
                        Jcall_abs_fn(times2);
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_LESSP:
                        make_label(label1,"LESSP",1);
                        make_label(label2,"LESSP",2);
                        make_label(label3,"LESSP",3);
                        make_label(label4,"LESSP",4);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        cmp_imm_r32(0x1,EAX);
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        cmp_imm_r32(0x1,EAX);
                        cond_jump(label1,JNE);
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        put3bytes(0x0f9cc0);//set al
                        put3bytes(0x0fb6c0);//movzbl al, eax
                        mov_rm32_rm32_disp(EAX,EBPM,-11);
                        jump(label2);
                        add_label(label1);
                        //save_pc
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(lessp2);
                        mov_rm32_rm32_disp(EAX,EBPM,-11);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
                        add_label(label2);
                        put4bytes(0x837dd400);//cmp 0, -44ebp
                        cond_jump(label3,JE);
                        load_nil_into(EAX);
                        add_imm32_rm32(100,EAX);
                        add_imm32_rm32(100,EAX);
                        add_imm32_rm32(100,EAX);
                        add_imm32_rm32(100,EAX);
                        add_imm32_rm32(32,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label4);
                        add_label(label3);
                        load_nil_into(EAX);
                        store_A_reg_from(EAX);
                        add_label(label4);
#ifdef COMMON
#endif
                        continue;

                case OP_APPLY1:
                        make_label(label1,"APPLY1",1);
                        make_label(label2,"APPLY1",2);
                        //save_pc
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        cmp_imm_r32(0x4,EAX);
                        cond_jump(label1,JNE);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-6);
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x4,EAXM);
                        load_stack_into(EBX);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-6);
                        put2bytes(0xffd0); //call *eax
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        //restore_pc
                        jump(label2);
                        add_label(label1);
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x4,EAXM);
                        load_stack_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,3);
                        load_nil_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        putbyte(0xb8);put4bytes(0x01000000);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(apply);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
                        add_label(label2);
                        continue;

                case OP_APPLY2:
                        make_label(label1,"APPLY2",1);
                        make_label(label2,"APPLY2",2);
                        //save_pc
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-4);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        and_imm_rm32(0x7,EAX);
                        cmp_imm_r32(0x4,EAX);
                        cond_jump(label1,JNE);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        add_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-7);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        add_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-7);
                        put2bytes(0xffd0); //call *eax
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        //restore_pc
                        jump(label2);
                        add_label(label1);
                        load_stack_into(EBX);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x4,EAXM);
                        load_stack_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        mov_rm32_rm32_disp(EAX,ESPM,3);
                        load_nil_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        putbyte(0xb8);put4bytes(0x02000000);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(apply);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
                        add_label(label2);
                        continue;


                case OP_GETV:
//FIXME add below

#ifndef OUT_OF_LINE
                        //FIXME add checks
                        load_B_reg_into(EBX);
                        load_A_reg_into(EAX);
                        put3bytes(0xc1f804);//sarl 4, eax
                        put3bytes(0xc1e002);//sall 2, eax
                        put2bytes(0x0303);//add_rm32_rm32(EBXM,EAX);
                        sub_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
#else
                        //FIXME doesnt work?
                        //savepc
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(Lgetv);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restorepc
#endif
#ifdef COMMON
#endif
                        continue;

                case OP_LOC0LOC1:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOC1LOC2:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOC2LOC3:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0xc,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;
                        
                case OP_LOC1LOC0:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOC2LOC1:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOC3LOC2:
                        load_B_reg_into(EDX);
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC0:
                        make_label(label1,"CDRLOC0",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC1:
                        make_label(label1,"CDRLOC1",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC2:
                        make_label(label1,"CDRLOC2",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC3:
                        make_label(label1,"CDRLOC3",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0xc,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC4:
                        make_label(label1,"CDRLOC4",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x10,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDRLOC5:
                        make_label(label1,"CDRLOC5",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x14,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $1, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        jump("error_1_A");//jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECXM,ECX,1);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CAARLOC0:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        continue;
                        
                case OP_CAARLOC1:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        sub_imm32_rm32(4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        continue;
                
                case OP_CAARLOC2:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        sub_imm32_rm32(8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        continue;

                case OP_CAARLOC3:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        sub_imm32_rm32(12,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        continue;

                case OP_CAAR:
                        make_label(label1,"CAAR",1);
                        make_label(label2,"CAAR",2);
                        make_label(label3,"CAAR",3);
                        make_label(label4,"CAAR",4);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label2);
                        add_label(label1);
                        /*FIXME add error_1_a */
                        add_label(label2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label3,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label4);
                        add_label(label3);
                        //FIXME error_1_A
                        add_label(label4);
                        continue;

                case OP_CADR:
                        make_label(label1,"CADR",1);
                        make_label(label2,"CADR",2);
                        make_label(label3,"CADR",3);
                        make_label(label4,"CADR",4);
                        load_A_reg_into(EAX);
                        and_imm_rm32(7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAXM,EAX,1);
                        store_A_reg_from(EAX);
                        jump(label2);
                        add_label(label1);
                        //FIXME error_1_A
                        add_label(label2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label3,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label4);
                        add_label(label3);
                        //FIXME error_1_A
                        add_label(label4);
                        continue;

                case OP_CDAR:
                        make_label(label1,"CDAR",1);
                        make_label(label2,"CDAR",2);
                        make_label(label3,"CDAR",3);
                        make_label(label4,"CDAR",4);
                        load_A_reg_into(EAX);
                        and_imm_rm32(7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label2);
                        add_label(label1);
                        //FIXME error_1_A
                        add_label(label2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(7,EAX);
                        put2bytes(0x85c0);
                        cond_jump(label3,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAXM,EAX,1);
                        store_A_reg_from(EAX);
                        jump(label4);
                        add_label(label3);
                        //FIXME error_1_A
                        add_label(label4);
                        continue;

                case OP_CDDR:
                        make_label(label1,"CDDR",1);
                        make_label(label2,"CDDR",2);
                        make_label(label3,"CDDR",3);
                        make_label(label4,"CDDR",4);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        cond_jump(label1,JNE);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32_disp(EBXM,EBX,1);//mov 4(ebx),ebx
                        store_A_reg_from(EBX);
                        jump(label2);
                        add_label(label1);
                        /*FIXME add error_1_A stuff */
                        add_label(label2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        cond_jump(label3,JNE);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32_disp(EBXM,EBX,1);//mov 4(ebx),ebx
                        store_A_reg_from(EBX);
                        jump(label4);
                        add_label(label3);
                        //FIXME add error_1_A
                        add_label(label4); //END
                        continue;

                case OP_JUMPL0NIL:
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL0T:
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL1NIL:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL1T:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL2NIL:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL2T:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL3NIL:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL3T:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL4NIL:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x10,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL4T:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x10,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL0ATOM:
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL0NATOM:
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL1ATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL1NATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL2ATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL2NATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL3ATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPL3NATOM:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT1EQ:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x2,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT1NE:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x2,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT2EQ:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x6,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT2NE:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x6,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT3EQ:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0xa,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT3NE:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0xa,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT4EQ:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0xe,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLIT4NE:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0xe,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;
/*
                case OP_JUMPLITEQ:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_rm32_rm32(EBXM,EAX);
                        sub_imm32_rm32(0x2,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPLITNE:
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x2,EAX);
                        load_A_reg_into(EBX);
                        cmp_rm32_rm32(EBX,EAXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;
*/
                case OP_JUMPB1NIL:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&one_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-6);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-6);
                        put2bytes(0xffd0); //call *eax
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        load_A_reg_into(EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;
                        
                case OP_JUMPB1T:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&one_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-6);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-6);
                        put2bytes(0xffd0); //call *eax
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        load_A_reg_into(EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPNATOM:
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax eax
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JUMPNE:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        cmp_rm32_rm32(ECX,EDXM);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte; //skip past offset in next bytecode
                        bytecodes++;
                        continue;
/*
                case OP_JUMPEQUAL:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        cmp_rm32_rm32(ECX,EDXM);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        printf("\nblah\n");
                        continue;
*/        
                case OP_JUMP_B:
                        make_label(label1,"JUMP_B",1);
#ifndef OUT_OF_LINE
                        //FIXME countdown stuff
                        mov_addr_r32(stacklimit,EAX);
                        cmp_rm32_rm32_disp(EAX,EBPM,-2);
                        cond_jump(label1,JB);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        put4bytes(0xc744240c);put4bytes(0x00000000);//mov 0, 12(esp)
                        put4bytes(0xc7442408);put4bytes(0x02000000);//mov 2, 8(esp)
                        put4bytes(0xc7442404);put4bytes(0x00000000);//mov LC1, 4(esp) FIXME
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(reclaim);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                                                
#else
#endif

                        add_label(label1);
                        make_bc_label_backwards()
                        jump(label);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_CALL0_0:
                        call0(0);
                        continue;

                case OP_CALL0_1:
                        call0(1);
                        continue;

                case OP_CALL0_2:
                        call0(2);
                        continue;

                case OP_CALL0_3:
                        call0(3);
                        continue;

                case OP_CALL0:
                        call0(*ppc);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JCALL:
                        switch((*ppc >> 5) & 0x7) {
                                //case 0: Jcall0(*ppc & 0x1f);
                                //case 1: {
                                //                call1(*ppc & 0x1f);
                                //                break;
                                //        }
                                case 2: {
                                                jcall2(*ppc & 0x1f);
                                                break;
                                        }
                                //case 3: Jcall3(*ppc & 0x1f);
                                //default: Jcalln(*ppc & 0x1f);
                        }
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_JCALLN:
                        /* must next_byte 2x */
                        switch(next_byte) {
                                case 2: {
                                                jcall2(*ppc);
                                                break;
                                        }
                        }
                        next_byte;
                        bytecodes++;
                        bytecodes++;
                        continue;

                case OP_CALL1_0:
                        //FIXME must preserve codevec and litvec for all 0
                        //or not?
                        /*
                         * this fn just gotos call1 like CALL1_1 
                         * instead of being a special case
                         */
                        call1(0);
                        continue;

                case OP_CALL1_1:
                        call1(1);
                        continue;

                case OP_CALL1_2:
                        call1(2);
                        continue;

                case OP_CALL1_3:
                        call1(3);
                        continue;

                case OP_CALL1_4:
                        call1(4);
                        continue;

                case OP_CALL1_5:
                        call1(5);
                        continue;

                case OP_CALL1:
                        call1(*ppc);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_CALL2_0:
                        /*
                         * this fn just gotos call2 like CALL2_1
                         * instead of being a special case
                         */
                        call2(0);
                        continue;

                case OP_CALL2_1:
                        call2(1);
                        continue;

                case OP_CALL2_2:
                        call2(2);
                        continue;

                case OP_CALL2_3:
                        call2(3);
                        continue;

                case OP_CALL2_4:
                        call2(4);
                        continue;

                case OP_CALL2:
                        call2(*ppc);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_CALL2R:
                        call2r(*ppc);
                        next_byte;
                        bytecodes++;
                        continue;
                        
                case OP_CALL3:
                        //Jcall_abs_fn(breakpoint);
                        load_litvec_into(EBX);
                        putbyte(0xb8);put_little_endian(*ppc);//mov next_byte, eax
                        //put3bytes(0x0fb600);//movzbl (eax), eax
                        //putbyte(0xb8); put4bytes(0x00000000);
                        put3bytes(0xc1e002);//sall 2, eax
                        put2bytes(0x01d8); //add_rm32_rm32(EBX,EAX);
                        //put2bytes(0x0303);//add_rm32_rm32(EBXM,EAX);//FIXME or 01
                        sub_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        
                        /* extra code to print what you are calling */
                        
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0x10,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-8);
                        
                        //save_pc
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,EBX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        mov_rm32_rm32(EBXM,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-4);
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //Jcall_abs_fn(breakpoint);
                        //Jcall_abs_fn(push_litvec);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,4);
                        load_B_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32_disp(EAX,ESPM,3);
                        mov_rm32_rm32_disp(EBPM,EAX,-4);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        put4bytes(0xb8030000);putbyte(0x00); put4bytes(0x89442404);//mov 3, 4(esp)
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0x4,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-8);
                        //Jpush(1,EDI);
                        put2bytes(0xffd0);//call *eax
                        //Jpop(1,EDI);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //Jcall_abs_fn(pop_litvec);
                        //Jexception_pending();
                        //cond_jump("call_error_exit",JNE);
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_BUILTIN0:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&zero_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-8);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        put4bytes(0xc7442404);put4bytes(0x00000000);//mov 0, 4(esp)
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-8);
                        put2bytes(0xffd0); //call *eax
                        //mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending? FIXME
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        continue;

                case OP_BUILTIN2R:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&two_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-7);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_B_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,2);
                        load_A_reg_into(EDX);
                        mov_rm32_rm32_disp(EDX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-7);
                        put2bytes(0xffd0); //call *eax
                        //mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending? FIXME
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        continue;

                case OP_BUILTIN3:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&three_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-8);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,4);
                        load_B_reg_into(EDX);
                        mov_rm32_rm32(EDXM,EDX);
                        mov_rm32_rm32_disp(EDX,ESPM,3);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32_disp(EAX,ESPM,2);
                        put4bytes(0xc7442403);put4bytes(0x00000000);//mov 0, 4(esp)
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-8);
                        put2bytes(0xffd0); //call *eax
                        //mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending? FIXME
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        continue;
/*
                case OP_LOADLOC:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        continue;
*/                        
                case OP_LOADLOC0:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;
                
                case OP_LOADLOC1:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC2:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC3:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0xc,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC4:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x10,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC5:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x14,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC6:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x18,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC7:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x1c,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC8:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x20,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC9:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x24,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC10:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x28,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLOC11:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x2c,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CAR:
                        make_label(label1,"CAR",1);
                        make_label(label2,"CAR",2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax eax
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        jump(label2);
                        add_label(label1);
                        //mov 0 csl FIXME
                        //stack
                        jump("error_1_A");
                        add_label(label2);//end
#ifdef COMMON
#endif
                        continue;
                        
                case OP_CARLOC0:
                        make_label(label1,"CARLOC0",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC1:
                        make_label(label1,"CARLOC1",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x4,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC2:
                        make_label(label1,"CARLOC2",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x8,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC3:
                        make_label(label1,"CARLOC3",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0xc,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC4:
                        make_label(label1,"CARLOC4",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x10,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC5:
                        make_label(label1,"CARLOC5",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x14,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC6:
                        make_label(label1,"CARLOC6",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x18,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC7:
                        make_label(label1,"CARLOC7",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x1c,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC8:
                        make_label(label1,"CARLOC8",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x20,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC9:
                        make_label(label1,"CARLOC9",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x24,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC10:
                        make_label(label1,"CARLOC10",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x28,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CARLOC11:
                        make_label(label1,"CARLOC11",1);
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_stack_into(ECX);
                        sub_imm32_rm32(0x2c,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
                        load_A_reg_into(ECX);
                        and_imm_rm32(0x7,ECX);
                        put2bytes(0x85c9); //test ecx,ecx
                        cond_jump(label1,JE);
                        //mov $0, CSLerrcode
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        //jmp error_1_A //FIXME
                        add_label(label1);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_CDR:
                        make_label(label1,"CDR",1);
                        make_label(label2,"CDR",2);
                        load_A_reg_into(EAX);
                        and_imm_rm32(0x7,EAX);
                        put2bytes(0x85c0);//test eax, eax
                        cond_jump(label1,JNE);
                        load_A_reg_into(EAX);
                        mov_rm32_rm32_disp(EAXM,EAX,1);
                        store_A_reg_from(EAX);
                        jump(label2);
                        add_label(label1);
                        //mov 1, csler
                        //stack
                        jump("error_1_A");//FIXME
                        add_label(label2);//end

#ifdef COMMON
#endif
                        continue;
                        
                case OP_STORELOC0:
                        load_stack_into(EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC1:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x4,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC2:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x8,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC3:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0xc,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC4:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x10,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC5:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x14,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC6:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x18,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;

                case OP_STORELOC7:
                        load_stack_into(EAX);
                        sub_imm32_rm32(0x1c,EAX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EAXM);
                        continue;
                
                case OP_LOADLIT:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(EBX);
                        putbyte(0xb8); put_little_endian(*ppc); //ppc in eax
                        put3bytes(0xc1e002);//sall 2, eax
                        //put2bytes(0x0303);//add (ebx), eax FIXME not sure
                        put2bytes(0x01d8);
                        sub_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,ECX);
                        store_A_reg_from(ECX);
                        next_byte;
                        bytecodes++;
#ifdef COMMON
#endif
                        continue;
                        
                case OP_LOADLIT1:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0x2,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLIT2:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0x6,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLIT3:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0xa,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLIT4:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0xe,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLIT5:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0x12,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;
                
                case OP_LOADLIT6:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0x16,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADLIT7:
                        load_B_reg_into(EDX);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32(ECX,EDXM);
                        load_litvec_into(ECX);
                        //mov_rm32_rm32(ECXM,ECX);
                        add_imm32_rm32(0x1a,ECX);
                        mov_rm32_rm32(ECXM,ECX);
                        store_A_reg_from(ECX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADFREE:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_litvec_into(EBX);
                        putbyte(0xb8); put_little_endian(*ppc);
                        put3bytes(0xc1e002);//sall 2, eax
                        put2bytes(0x01d8);//add_rm32_rm32(EBX,EAX);
                        sub_imm32_rm32(2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
                        next_byte;
                        bytecodes++;
#ifdef COMMON
#endif
                        continue;

                case OP_LOADFREE1:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x2,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADFREE2:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(0x6,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADFREE3:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(10,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOADFREE4:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_litvec_into(EAX);
                        //mov_rm32_rm32(EAXM,EAX);
                        add_imm32_rm32(14,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        store_A_reg_from(EAX);
#ifdef COMMON
#endif
                        continue;

                case OP_JUMPNIL:
                        load_A_reg_into(EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JE);
                        next_byte;
                        bytecodes++;
                        continue;
                        
                case OP_JUMPT:
                        load_A_reg_into(EAX);
                        cmp_rm32_rm32_disp(EBPM,EAX,-1);
                        make_bc_label();
                        cond_jump(label,JNE);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_BUILTIN1:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&one_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-7);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-7);
                        put2bytes(0xffd0); //call *eax
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending? FIXME
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        continue;

                case OP_BUILTIN2:
                        putbyte(0xb8); put_little_endian(*ppc); //mov *ppc, eax
                        next_byte;
                        bytecodes++;
                        put3bytes(0x8b0485);
                        put_addr(&two_arg_functions);//mov two_arg_functions(,%eax,4), %eax
                        mov_rm32_rm32_disp(EAX,EBPM,-7);
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,2);
                        load_B_reg_into(EDX);
                        mov_rm32_rm32(EDXM,EDX);
                        mov_rm32_rm32_disp(EDX,ESPM,1);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        mov_rm32_rm32_disp(EBPM,EAX,-7);
                        put2bytes(0xffd0); //call *eax
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending? FIXME
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc() ?
                        continue;
                
                case OP_EXIT:
                        load_entry_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(EAX);
                        //store_result_from(ECX);
                        exit_bytecode();
                        continue;

                case OP_PUSH:
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x4,EAXM);
                        load_stack_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);

                        //load_stack_into(EAX);
                        //add_imm32_rm32(0x4,EAXM);
                        continue;

                case OP_PUSHNIL:
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x4,EAXM);
                        load_stack_into(EBX);
                        load_nil_into(EAX);
                        mov_rm32_rm32(EAX,EBXM);
                        continue;

                case OP_PUSHNIL2:
                        /*
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(Jprint3);
                        Jcall_abs_fn(breakpoint);
                        */
                        load_stack_into(EAX);
                        add_imm32_rm32(0x4,EAX);
                        load_nil_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        add_imm32_rm32(0x8,EAX);
                        load_nil_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stackaddr_into(EAX);
                        add_imm32_rm32(0x8,EAXM);
                        
                        //load_stack_into(EAX);
                        //add_imm32_rm32(0x8,EAXM);
                        /*
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(Jprint3);
                        Jcall_abs_fn(breakpoint);
                        */
                        continue;

                case OP_PUSHNIL3:
                        load_stack_into(EAX);
                        add_imm32_rm32(0x4,EAX);
                        load_nil_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        add_imm32_rm32(0x8,EAX);
                        load_nil_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        add_imm32_rm32(0xc,EAX);
                        load_nil_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        lea_m32_r32_disp(EBPM,EAX,-3);
                        add_imm32_rm32(0xc,EAXM);
                        continue;

                case OP_POP:
                        load_B_reg_into(EAX);
                        load_A_reg_into(EBX);
                        mov_rm32_rm32(EBX,EAXM);
                        load_stack_into(EAX);
                        mov_rm32_rm32(EAX,EBX);
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        mov_rm32_rm32(EBXM,EBX);
                        store_A_reg_from(EBX);
#ifdef COMMON
#endif
                        continue;

                case OP_LOSE:
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x4,EAXM);
                        continue;

                case OP_LOSE2:
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(0x8,EAXM);
                        continue;

                case OP_LOSE3:
                        load_stackaddr_into(EAX);
                        sub_imm32_rm32(12,EAXM);
                        continue;

                case OP_LOSES:
                        putbyte(0xb8);put_little_endian(*ppc);
                        put4bytes(0x8d148500); put3bytes(0x000000);//leal 0(,%eax,4), %edx
                        //FIXME is above lea necessary?
                        load_stackaddr_into(EBX);
                        sub_imm32_rm32(EDX,EBXM);
                        next_byte;
                        bytecodes++;
                        continue;

                case OP_CONS:
#ifndef OUT_OF_LINE
                        make_label(label1,"CONS",1);
                        make_label(label2,"CONS",2);
                        load_fringe_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        sub_imm32_rm32(0x8,EAX);
                        mov_rm32_rm32_disp(EAX,EBPM,-3);
                        load_B_reg_into(EDX);
                        mov_rm32_rm32(EDXM,EDX);
                        mov_rm32_rm32(EDX,EAXM);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,EAXM,1);
                        load_fringe_into(EBX);
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,EBXM);
                        load_heaplimit_into(EAX);
                        mov_rm32_rm32(EAXM,EAX);
                        cmp_rm32_rm32_disp(EAX,EBPM,-3);
                        cond_jump(label1,JA);
                        //save_pc
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        put4bytes(0xb8000000);putbyte(0x00); put4bytes(0x8944240c);//mov 0, 12(esp)
                        put4bytes(0xb8030000);putbyte(0x00); put4bytes(0x89442408);//mov 3, 8(esp)
                        //mov LC34, 4(esp) FIXME for text at end
                        mov_rm32_rm32_disp(EBPM,EAX,-3);
                        mov_rm32_rm32(EAX,ESPM);
                        Jcall_abs_fn(reclaim);
                        store_A_reg_from(EAX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
                        //restore_pc();
                        jump(label2);
                        
                        add_label(label1);
                        mov_rm32_rm32_disp(EBPM,ECX,-3);
                        store_A_reg_from(ECX);
#else
                        //save_pc() ?
                        load_stack_into(EAX);
                        mov_r32_addr(EAX,stack);
                        load_A_reg_into(ECX);
                        mov_rm32_rm32_disp(ECX,ESPM,1);
                        load_B_reg_into(EDX);
                        mov_rm32_rm32(EDXM,EDX);
                        mov_rm32_rm32(EDX,ESPM);
                        Jcall_abs_fn(cons);
                        mov_rm32_rm32(EAX,ECX);
                        store_A_reg_from(ECX);
                        mov_addr_r32(&C_nil,EAX);
                        store_nil_from(EAX);
                        //exception pending?
                        mov_addr_r32(stack,EAX);
                        store_stack_from(EAX);
#endif
#ifdef DEBUG
#endif
#ifdef COMMON
#endif
                        add_label(label2);
                        continue;

               default: printf("Error: cant translate bytecode %s\n",opnames[*(ppc-1)]);
                        return -1;
        }
        }
        return 0;
}

void build_gotos(Lisp_Object def, int nargs)
{
        /* all fns jumped from bytecode_compile so in same frame */
        
        /* call3 */
        
        add_label("call_error_exit");
        
        /* error_1_A */
        add_label("error_1_A");
        Jcall_abs_fn(test);
#ifdef BUILDGOTOSDONE
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        load_A_reg_into(ECX);
        //mov ecx, 8(esp)
        //mov CSLerrcode, eax
        //mov eax, 4(esp)
        //mov 1, (esp)
        Jcall_abs_fn(error);
        mov_addr_r32(&C_nil, EAX);
        store_nil_from(EAX);
        load_nil_into(EAX);
        //xor 1, eax
        mov_r32_addr(EAX, &C_nil);
        mov_addr_r32(&C_nil, EAX);
        store_nil_from(EAX);
        jump("pop_stack_and_exit");

        /* pop_stack_and_exit */
        add_label("pop_stack_and_exit");
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        load_nil_into(EAX);
        //add_imm_r32(0x64, EAX);
        mov_rm32_rm32(EAXM,EAX);
        //and_imm_r32(0xff, EAX); //FIXME imm32?
        //test eax, eax
        cond_jump("pop_stack_and_exit0", JE);
        //mov LC36, (esp)
        Jcall_abs_fn(err_printf);
        load_litvec_into(EAX);
        //mov_rm32_rm32(EAXM,EAX);
        sub_imm32_rm32(0x2, EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32(EAX,ESPM); //FIXME correct x86 code?
        Jcall_abs_fn(loop_print_error);
        //mov LC13, (esp)
        Jcall_abs_fn(err_printf);
        mov_addr_r32(&C_nil, EAX);
        store_nil_from(EAX);
        load_nil_into(EAX);
        //and_imm_r32(0x1, EAX);
        //test eax, eax
        cond_jump("pop_stack_and_exit0", JE);
        load_nil_into(EAX);
        //xor 1, eax
        mov_r32_addr(EAX,&C_nil);//FIXME macro for flipexception
        mov_addr_r32(&C_nil, EAX);
        store_nil_from(EAX);
        add_label("pop_stack_and_exit0");
        //mov 1, 4(esp)
        load_entry_stack_into(EAX);
        //mov eax, (esp)
        Jcall_abs_fn(unwind_stack);
        mov_addr_r32(stack, EAX);
        cmp_rm32_rm32_disp(EBPM,EAX,4);
        cond_jump("pop_stack_and_exit1", JNE);
        //mov 0, -44(ebp)
        jump("pop_stack_and_exit2");
        add_label("pop_stack_and_exit1");
        mov_addr_r32(stack,EAX);
        store_stack_from(EAX);
        load_stackaddr_into(EAX);
        //sub_imm32_rm32(0x8,EAXM); FIXME mem loc
        mov_rm32_rm32_disp(EBPM,EAX,-2);
        add_imm32_rm32(0x8, EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-3);
        load_stack_into(EAX);
        add_imm32_rm32(0x4,EAX);
        mov_rm32_rm32(EAXM,EAX);
        mov_rm32_rm32_disp(EAX,EBPM,-4);
        load_stack_into(EAX);
        mov_r32_addr(EAX,stack);
        mov_rm32_rm32_disp(EBPM,EAX,-4);
        //sar 4, eax
        mov_rm32_rm32_disp(EAX,EBPM,-11);
        mov_rm32_rm32_disp(EBPM,EAX,-3);
        //cmp 0x3c2 (EAX)
        cond_jump("pop_stack_and_exit2",JNE);
        //5436
        add_label("pop_stack_and_exit2"); //FIXME shouldnt be here
#endif
}

#ifdef X86
void Jdisassemble(char *compiledcode)
{
/*
 * Try to disassemble... This used the "distorm" disassembler,
 * which can handle 32-bit or 64-bit x86 code. It is obviously not
 * relevant for other architectures. In principle much of the rest
 * of the JIT framework could be ported to eg powerpc, sparc, etc, so
 * the test on X86 is limited to just this bit right now. Later on
 * the whole JIT framework will need to sense the architecture in use and
 * only translate in cases where it knows how to. For that it should make
 * a run-time check on linker_type (in machineid.c) rather than trust to
 * a compile-time choice. Perhaps I should do that here...
 */
   {   _DecodedInst *instrout;
        instrout = (_DecodedInst*) malloc(codep*sizeof(_DecodedInst));
        unsigned long icount;
        int i, j, pos, p;
        reloc_table *dislabels = disassembler_labels;
        reloc_table *labels = labels_table;
        reloc_table *calllabels = callers_table;
        reloc_table *jumplabels = jumpers_table;
        //variables_table *varlabels = vars_table;
        char buffer[80];
        i = distorm_decode((unsigned long)compiledcode,
                      (unsigned char *)compiledcode,
                      (unsigned long)codep,
                      Decode32Bits,           /* 32-bit mode */
                      instrout,               /* where the output goes */
                      codep*sizeof(_DecodedInst),                 /* size of output array */
                      &icount);               /* gets amount of output used */
        printf("distorm64 return code = %d, count=%d\n", i, (int)icount);
        fflush(stdout);
        p = 0;
        pos = 0;
        for (i=0; i<icount; i++)
        {   
                buffer[0] = 0;
                unsigned int len = instrout[i].instructionHex.length;
            unsigned char *s = instrout[i].instructionHex.p;
            
            /* Need to do this in case label is in middle of instruction */
            for(j=0; j<instrout[i].size; j++, pos++) {
                    /* Make sure you don't dereference garbage first */
                    /* there can be multiple labels per pos */
                    if(dislabels!=NULL) {
                            while(pos == dislabels->pos) {
                                    printf("===============[ %s ]===============\n",dislabels->label);
                                    if(dislabels->next != NULL) {
                                            dislabels = dislabels->next;
                                    }
                                    else break; //end of list
                            }
                    }
                    /* there can be multiple labels per pos */
                    if(labels!=NULL) {
                            while(pos == labels->pos) {
                                    printf("<%s: >\n",labels->label);
                                    if(labels->next != NULL) {
                                            labels = labels->next;
                                    }
                                    else break;
                            }
                    }
                                                        
                    if(calllabels!=NULL) {
                            if(pos == calllabels->pos) {
                                    sprintf(buffer,"<CALL: %s>\n",calllabels->label);
                                    if(calllabels->next != NULL) calllabels = calllabels->next;
                            }
                    }
                    if(jumplabels!=NULL) {
                            if(pos == jumplabels->pos) {
                                    sprintf(buffer,"<JUMP: %s>\n",jumplabels->label);
                                    if(jumplabels->next != NULL) jumplabels = jumplabels->next;
                            }
                    }
                    
            }
            printf("  %.8x: %-24s", (int)instrout[i].offset, s);
/*
 * The hex version of the instruction will usually be fairly short,
 * so I put it in a 24-char field and wrap after it if it was too
 * long for that.
 */
            if (len > 24) printf("\n%34s", " ");
            printf(" %s %s\n",
                instrout[i].mnemonic.p,
                instrout[i].operands.p);
            fflush(stdout);
            printf("%s",buffer);
            //pos += instrout[i].size;
        }
        printf("disassembly complete\n");
        fflush(stdout);
    }
}
#endif /* X86 */

void print_dis()
{
        reloc_table *labels = labels_table;
        while(labels != NULL)
        {
                printf("%s\t%lu",labels->label,labels->pos);
                labels=labels->next;
        }
}

#ifdef x86arch
char* Jcompile(Lisp_Object def, int nargs)
{
        int compile_ok = 0;
        
        //initialise linkage data
        labels_table = NULL;
        callers_table = NULL;
        jumpers_table = NULL;
        vars_table = NULL;
        disassembler_labels = NULL;
        codebuffer[0] = 0;
        startcode();

add_disassembler_label("START");
        
        //move ebp and esp around for start of function call
        init_stack_pointers();

        //Lisp_Object nil = C_nil
        //add 0x38 to esp
        //put the address of C_nil in -8(%ebp) as a local var
        Jsetup_nil();

        Jpush(6,EAX,EBX,EDX,ECX,ESI,EDI); //preserve state of registers

#ifdef WTF
        Jcall_abs_fn(push_litvec);
        Jcall_abs_fn(push_litvec);
        Jcall_abs_fn(push_litvec);
#endif
#ifdef JDEBUG2
        /*
         * Prints name of function being run for debugging
         * beware! ffname gets clobbered by gc
         */
        char *ffname = &celt(qpname(elt(qcdr(def), 0)), 0);
        CSL_IGNORE(ffname);
        putbyte(0xb8); put_addr(ffname);
        mov_rm32_rm32(EAX,ESPM);
        Jcall_abs_fn(print_ffname);
#endif
        
#ifdef JDEBUG
        //Jcall_abs_fn(breakpoint);
#endif
        
        if(nargs==0) {
                Jcheck_nargs0();
                Jpush_stack(0);
                //Jstackcheck1(0);
        }
        
        if(nargs==1 || nargs==2) {
                //push(litvec, codevec, a) || push(litvec, codevec, a, b)
                Jpush_stack(nargs); //push onto C_stack
                //if (nargs==1) Jstackcheck1(3);
                //else Jstackcheck1(4);
        }
        if(nargs==3) {
                //if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),fixnum_of_int((int32_t)nargs));
                Jcheck_nargs3();
                //Jstackcheck1(3);
        }
        if(nargs!=0 && nargs!=1 && nargs!=2 && nargs!=3) {
                //nargs == n
                Jcheck_nargsn();
                //FIXME stackcheck
        }
        Jstackcheck1(nargs);

        //Jcall_abs_fn(breakpoint);
        
        //prepare for a function call to the bytecoded data
        //compiled bytecodes are stored at the end of codebuffer so we make
        //a call to it from here then link back
        Jprepare_bytecode_compiler(nargs);
        
        //store result from bytestream_interpret(eax) in -4(ebp)
        mov_rm32_rm32_disp(EAX,EBPM,-1); //mov eax, -4(ebp)
        
        //nil = C_nil
        //Jnil_eq_C_nil();
        
        //pop(codevec, litvec)
        Jpop_vecs();
        
        //remove local vars from stack -- DONE IN exit_stack_pointers()
        //strcat(Jcode, "83c428"); //add 0x28, %esp

#ifdef JDEBUG
        //Jcall_abs_fn(breakpoint);
#endif

        Jpop(6,EDI,ESI,ECX,EDX,EBX,EAX);
#ifdef WTF
        Jcall_abs_fn(pop_litvec);
        Jcall_abs_fn(pop_litvec);
        Jcall_abs_fn(pop_litvec);
#endif
        //%eax = result
        Jresult();
        
        exit_stack_pointers();

        if(Jbytecode_compile(def, nargs)==0) {
                compile_ok = 1;
        }

        if(compile_ok == 0) {
                printf("Error - couldn't compile\n");
                return NULL;
        }

        build_gotos(def,nargs);

        //print_dis();
        
        //fix relocation address
        reloc_vars();
        reloc_jumps();
        reloc_calls();

#ifdef X86
        if(compile_ok == 1) Jdisassemble(codebuffer);
#endif
        
        free_labels_table(labels_table);
        free_labels_table(callers_table);
        free_labels_table(jumpers_table);
        free_var_table(vars_table);
        free_labels_table(disassembler_labels);
        
        //printf("\n%s\n",codebuffer);
        printf("JIT COMPILED: %lu bytes\n", codep);
        
        return codebuffer;
}
#endif //x86arch

/* end of jit3.c */
