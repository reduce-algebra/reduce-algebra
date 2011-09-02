/* jitx86.c                   Copyright (C) 2006-2007, Codemist Ltd */
/*                                                  and J O'Connell */

/*
 * Just in time x86 compiler.
 *
 * specifically Intel/AMD x86 processing.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */



/* Signature: 4f6e2f64 18-Jan-2007 */

#include "headers.h"
#include "bytes.h"
#include "jit.h"

#define PSIZE 4 /* size of pointer */

void inc_reg(int reg)
{
	if(isreg(reg)) {
		putbyte(0x40+reg);
	}
	else aerror("Error: inc reg is not a register");
}

void dec_reg(int reg)
{
	if(isreg(reg)) {
		putbyte(0x48+reg);
	}
	else aerror("Error: dec reg is not a register");
}

void sub_imm8_rm32(int size, int reg)
{
	//check if register
	if(isreg(reg)) {
		putbyte(0x83); //sub sign-extended imm8 from r/m32
		putbyte(0xe8+reg);
		putbyte(size);
	}
	else {
		putbyte(0x83);
		putbyte(0x28+reg-0x8);//FIXME is this right?
		putbyte(size);
	}
}

void sub_imm32_rm32(int size, int reg)
{
	if(isreg(reg)) {
		putbyte(0x81);
		putbyte(0xe8+reg);
		put_little_endian(size);
	}
	else {
		putbyte(0x81);
		putbyte(0x28+reg-0x8);
		put_little_endian(size);
	}
}

void add_imm8_addr(int size, void *addr)
{
	put2bytes(0x8305);
	put_addr(addr);
	putbyte(size);
}

void sub_imm8_addr(int size, void *addr)
{
	put2bytes(0x832d);
	put_addr(addr);
	putbyte(size);
}

/* 
 * below in add:
 * imm8 because of special case if reg==EAX then it makes it AL.
 * So instead just explicitly make me declare what size imm i want.
 *
 * Longer(slower?) but safer.  Can optimise later
 */

void add_imm8_rm32(int size, int reg)
{
	//check if register
	if(isreg(reg)) {
		//special case for accumulator register eax
		if(reg==EAX) {
			putbyte(0x04);
			putbyte(size);
		}
		else {
			putbyte(0x83);
			putbyte(0xc0+reg);
			putbyte(size);
		}
	}
	//memory location
	else {
		putbyte(0x83);
		putbyte(reg-0x8);
		putbyte(size);
	}
}
void add_imm32_rm32(int size, int reg)
{
	//size is bigger than imm8
	if(isreg(reg)) {
		//special case for accumulator register eax
		if(reg==EAX) {
			putbyte(0x05);
			put_little_endian(size);
		}
		else {
			putbyte(0x81);
			putbyte(0xc0+reg);
			put_little_endian(size);
		}
	}
	else {
		putbyte(0x81);
		putbyte(reg-0x8);
		put_little_endian(size);
	}
}

void and_imm_rm32(int size, int reg)
{
	/*
	 * imm is ok because it is sign extended
	 * unlike add and sub when reg==eax
	 */
	//check if size is an imm8
	if(0x0<=size && size <=0xff) {
		//check if register
		if(isreg(reg)) {
			//special case for accumulator register eax
/*			if(reg==EAX) {
 				//add imm8 to r8
				putbyte(0x24);
				putbyte(size);
			}
			else {*/
				//add sign extended imm8 to r32
				putbyte(0x83);
				putbyte(0xe0+reg);
				putbyte(size);
//			}
		}
		//memory location
		else {
			putbyte(0x83);
			putbyte(0x20+reg-0x8);
			putbyte(size);
		}
	}
	//size is bigger than imm8
	else {
		if(isreg(reg)) {
			//special case for accumulator register eax
			if(reg==EAX) {
				putbyte(0x25);
				put4bytes(size);
			}
			else {
				putbyte(0x81);
				putbyte(0xe0+reg);
				put4bytes(size);
			}
		}
		else {
			putbyte(0x81);
			putbyte(0x20+reg-0x8);
			put4bytes(size);
		}
	}
}

void mov_rm32_rm32(int dest, int source)
{
	//eg, "mov dest, source"
	if(isreg(dest)) {
		//destination is a register
		putbyte(0x89);
		if(isreg(source)) {
			//we have a "mov %eax,%ebx"
			putbyte((0xc0+(dest*0x8))+source);
		}
		else {
			if(dest==ESP) aerror("Error: ESP in mov_rm32_rm32");
			if(source==ESPM) {
				putbyte(0x4+(dest*0x8));
				putbyte(0x24); //SIB ESP
			}
			else {
				//we have a "mov %eax,(%ebx)"
				putbyte((dest*0x8)+source-0x8);
			}
		}
	}
	else {
		//destination is a memory offset located in register
		putbyte(0x8b);
		if(isreg(source)) {
			//we have a "mov (%eax),%ebx"
			putbyte((source*0x8)+dest-0x8);
		}
		else {
			//we have a "mov (%eax),(%ebx)"
			//this is an illegal instruction
			aerror("Error: in mov_rm32_rm32");
		}
	}
}

void mov_rm32_rm32_disp(int dest, int source, int disp)
{
	//eg, "mov 0xdisp(dest), source"
	//check if a disp8
	if(-127<=(disp*PSIZE) && (disp*PSIZE)<=128) {
		if(isreg(dest)) {
			//destination is a register
			putbyte(0x89);
			if(isreg(source)) {
				//we have a "mov %eax,%ebx"
				aerror("Error: no mem loc in disp mov");
			}
			else {
				if(dest==ESP) aerror("Error: ESP in mov_rm32_rm32_disp");
				if(source==ESPM) {
					putbyte(0x44+(dest*0x8));
					putbyte(0x24); //SIB ESP
					putbyte((PSIZE*disp)&0xff);
				}
				else {
					//we have a "mov %eax,0xdisp(%ebx)"
					putbyte(0x40+(dest*0x8)+source-0x8);
					putbyte((PSIZE*disp)&0xff);
				}
			}
		}
		else {
			//destination is a memory offset located in register
			putbyte(0x8b);
			if(isreg(source)) {
				//we have a "mov 0xdisp(%eax),%ebx"
				putbyte(0x40+(source*0x8)+dest-0x8);
				putbyte((PSIZE*disp)&0xff);
			}
			else {
				//we have a "mov (%eax),(%ebx)"
				//this is an illegal instruction
				aerror("Error: in mov_rm32_rm32_disp");
			}
		}
	}
	//its a disp32
	else {
		if(isreg(dest)) {
			//destination is a register
			putbyte(0x89);
			if(isreg(source)) {
				//we have a "mov %eax,%ebx"
				aerror("Error: no mem loc in disp mov");
			}
			else {
				//we have a "mov %eax,0xdisp(%ebx)"
				putbyte(0x80+(dest*0x8)+source-0x8);
				put_little_endian(PSIZE*disp);
			}
		}
		else {
			//destination is a memory offset located in register
			putbyte(0x8b);
			if(isreg(source)) {
				//we have a "mov 0xdisp(%eax),%ebx"
				putbyte(0x80+(source*0x8)+dest-0x8);
				put_little_endian(PSIZE*disp);
			}
			else {
				//we have a "mov (%eax),(%ebx)"
				//this is an illegal instruction
				aerror("Error: in mov_rm32_rm32_disp");
			}
		}
	}
}

void cmp_imm_r32(int size, int reg)
{
	//sign extended imm
	if(0<=size && size<=255) {
		if(isreg(reg)) {
			putbyte(0x83);
			putbyte(0xf8+reg);
			putbyte(size);
		}
		else aerror("Error: not reg in cmp_imm_r32");
	}
	else {
		//imm32
		if(isreg(reg)) {
			putbyte(0x81);
			putbyte(0xf8+reg);
			put4bytes(size);
		}
		else aerror("Error: not reg in cmp_imm_r32");
	}
}

void cmp_rm32_rm32(int dest, int source)
{
	//eg, "cmp dest, source"
	if(isreg(dest)) {
		//destination is a register
		putbyte(0x39);
		if(isreg(source)) {
			//we have a "cmp %eax,%ebx"
			putbyte((0xc0+(dest*0x8))+source);
		}
		else {
			//we have a "cmp %eax,(%ebx)"
			putbyte((dest*0x8)+source-0x8);
		}
	}
	else {
		//destination is a memory offset located in register
		putbyte(0x3b);
		if(isreg(source)) {
			//we have a "cmp (%eax),%ebx"
			putbyte((source*0x8)+dest-0x8);
		}
		else {
			//we have a "cmp (%eax),(%ebx)"
			//this is an illegal instruction
			aerror("Error: in cmp_rm32_rm32");
		}
	}
}

void cmp_rm32_rm32_disp(int dest, int source, int disp)
{
	//eg, "cmp 0xdisp(dest), source"
	//check if a disp8
	if(-127<=(disp*PSIZE) && (disp*PSIZE)<=128) {
		if(isreg(dest)) {
			//destination is a register
			putbyte(0x39);
			if(isreg(source)) {
				//we have a "cmp %eax,%ebx"
				aerror("Error: no mem loc in disp cmp");
			}
			else {
				//we have a "cmp %eax,0xdisp(%ebx)"
				putbyte(0x40+(dest*0x8)+source-0x8);
				putbyte((PSIZE*disp)&0xff);
			}
		}
		else {
			//destination is a memory offset located in register
			putbyte(0x3b);
			if(isreg(source)) {
				//we have a "cmp 0xdisp(%eax),%ebx"
				putbyte(0x40+(source*0x8)+dest-0x8);
				putbyte((PSIZE*disp)&0xff);
			}
			else {
				//we have a "cmp (%eax),(%ebx)"
				//this is an illegal instruction
				aerror("Error: in cmp_rm32_rm32_disp");
			}
		}
	}
	//its a disp32
	else {
		if(isreg(dest)) {
			//destination is a register
			putbyte(0x39);
			if(isreg(source)) {
				//we have a "cmp %eax,%ebx"
				aerror("Error: no mem loc in disp cmp");
			}
			else {
				//we have a "cmp %eax,0xdisp(%ebx)"
				putbyte(0x80+(dest*0x8)+source-0x8);
				put_little_endian(PSIZE*disp);
			}
		}
		else {
			//destination is a memory offset located in register
			putbyte(0x3b);
			if(isreg(source)) {
				//we have a "cmp 0xdisp(%eax),%ebx"
				putbyte(0x80+(source*0x8)+dest-0x8);
				put_little_endian(PSIZE*disp);
			}
			else {
				//we have a "cmp (%eax),(%ebx)"
				//this is an illegal instruction
				aerror("Error: in cmp_rm32_rm32_disp");
			}
		}
	}
}


void mov_r32_addr(int dest, void *source)
{
	//eg, "mov %eax, 0x0" where 0x0 = C_stack
	if(isreg(dest)) {
		//special case for eax
		if(dest==EAX) {
			putbyte(0xa3);
			put_addr(source);
		}
		else {
			putbyte(0x89);
			putbyte((dest*0x8)+0x5);
			put_addr(source);
		}
	}
	else aerror("Error in moving an address to a reg");
}	

void mov_addr_r32(void *dest, int source)
{
	//eg, "mov 0x0, %eax" where 0x0 = C_stack
	if(isreg(source)) {
		//special case for eax
		if(source==EAX) {
			putbyte(0xa1);
			put_addr(dest);
		}
		else {
			putbyte(0x8b);
			putbyte((source*0x8)+0x5);
			put_addr(dest);
		}
	}
	else aerror("Error in moving a reg to an address");
}

void lea_m32_r32_disp(int source, int dest, int disp)
{
	if(!isreg(source)) {
		if(isreg(dest)) {
			putbyte(0x8d);
			if(-127<=(PSIZE*disp) && (disp*PSIZE)<=128) {
				putbyte(0x40+(dest*0x8)+source-0x8);
				putbyte((PSIZE*disp)&0xff);
			}
			else {
				putbyte(0x80+(dest*0x8)+source-0x8);
				put_little_endian(PSIZE*disp);
			}
		}
		else aerror("Error in lea. dest is not a register");
	}
	else aerror("Error in lea. source is not a memory loc");
}

void MS_CDECL Jpush(int nargs, ...)
{
	va_list arg_ptr;
	int i;
	if (nargs != 0)
	{
		va_start(arg_ptr, nargs);
		for(i=0; i<nargs; i++)
		{
			putbyte(0x50+va_arg(arg_ptr, int));
		}
		va_end(arg_ptr);
	}
}

void MS_CDECL Jpop(int nargs, ...)
{
        va_list arg_ptr;
        int i;
        if (nargs != 0)
        {
                va_start(arg_ptr, nargs);
                for(i=0; i<nargs; i++)
                {
                        putbyte(0x58+va_arg(arg_ptr, int));
		}
		va_end(arg_ptr);
	}
}


/* end of jitx86.c */
