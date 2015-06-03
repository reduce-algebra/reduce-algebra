package uk.co.codemist.jlisp.core;


/* $Id$ */


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
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
class InstrumentedBytecode extends Bytecode
{

InstrumentedBytecode()
{
    env = new LispObject [0];
}

InstrumentedBytecode(LispObject [] env)
{
    this.env = env;
}

InstrumentedBytecode(int n)
{
    env = new LispObject [0];
    bytecodes = new byte [n];
}

LispObject interpret(int pc) throws Exception
{
    if (--poll_time_countdown < 0) dopoll();
    int spsave = sp;
    int arg;
    LispObject a = Jlisp.nil, b = Jlisp.nil, w;
    int iw, fname;
    if (sp > stack_size - 500) // the 500 is a pretty arbitrary margin!
        extendstack();         // bad enough code could breach it.
    count += 30;

    for (;;)
    {
    try
    {
    for (;;)
    {
        count++;
// In Jlisp I will count the number of bytecode ops executed in any function
// and I will attribute an overhead of 30 to function entry+exit.
    switch (arg = bytecodes[pc++])
    {
case LOADLOC:
        b = a; a = stack[sp-(bytecodes[pc++] & 0xff)];
        continue;
case LOADLOC0:
case LOADLOC1:
case LOADLOC2:
case LOADLOC3:
case LOADLOC4:
case LOADLOC5:
case LOADLOC6:
case LOADLOC7:
case LOADLOC8:
case LOADLOC9:
case LOADLOC10:
case LOADLOC11:
        b = a;
        a = stack[sp - (arg-LOADLOC0)];
        continue;
case LOC0LOC1:
        b = stack[sp-0];
        a = stack[sp-1];
        continue;
case LOC1LOC2:
        b = stack[sp-1];
        a = stack[sp-2];
        continue;
case LOC2LOC3:
        b = stack[sp-2];
        a = stack[sp-3];
        continue;
case LOC1LOC0:
        b = stack[sp-1];
        a = stack[sp-0];
        continue;
case LOC2LOC1:
        b = stack[sp-2];
        a = stack[sp-1];
        continue;
case LOC3LOC2:
        b = stack[sp-3];
        a = stack[sp-2];
        continue;
case VNIL:
        b = a; a = Jlisp.nil;
        continue;
case LOADLIT:
        b = a; a = env[bytecodes[pc++] & 0xff];
        continue;
case LOADLIT1:
case LOADLIT2:
case LOADLIT3:
case LOADLIT4:
case LOADLIT5:
case LOADLIT6:
case LOADLIT7:
        b = a;
        a = env[arg - (LOADLIT1-1)];
        continue;
case LOADFREE:
        b = a; a = env[bytecodes[pc++] & 0xff].car/*value*/;
        continue;
case LOADFREE1:
case LOADFREE2:
case LOADFREE3:
case LOADFREE4:
        b = a;
        a = env[arg - (LOADFREE1-1)].car/*value*/;
        continue;
case STORELOC:
        stack[sp - (bytecodes[pc++] & 0xff)] = a;
        continue;
case STORELOC0:
case STORELOC1:
case STORELOC2:
case STORELOC3:
case STORELOC4:
case STORELOC5:
case STORELOC6:
case STORELOC7:
        stack[sp - (arg-STORELOC0)] = a;
        continue;
case STOREFREE:
        env[bytecodes[pc++] & 0xff].car/*value*/ = a;
        continue;
case STOREFREE1:
case STOREFREE2:
case STOREFREE3:
        env[arg - (STOREFREE1-1)].car/*value*/ = a;
        continue;
case LOADLEX:
        Jlisp.error("bytecode LOADLEX not implemented");
case STORELEX:
        Jlisp.error("bytecode STORELEX not implemented");
case CLOSURE:
        Jlisp.error("bytecode CLOSURE not implemented");
case CARLOC0:
case CARLOC1:
case CARLOC2:
case CARLOC3:
case CARLOC4:
case CARLOC5:
case CARLOC6:
case CARLOC7:
case CARLOC8:
case CARLOC9:
case CARLOC10:
case CARLOC11:
        b = a;
        a = stack[sp - (arg - CARLOC0)];
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        continue;
case CDRLOC0:
case CDRLOC1:
case CDRLOC2:
case CDRLOC3:
case CDRLOC4:
case CDRLOC5:
        b = a;
        a = stack[sp - (arg - CDRLOC0)];
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        continue;
case CAARLOC0:
case CAARLOC1:
case CAARLOC2:
case CAARLOC3:
        b = a;
        a = stack[sp - (arg - CAARLOC0)];
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        continue;
case CALL0:
	a = ((Symbol)env[bytecodes[pc++] & 0xff]).fn.op0();
	continue;
case CALL1:
	a = ((Symbol)env[bytecodes[pc++] & 0xff]).fn.op1(a);
	continue;
case CALL2:
	a = ((Symbol)env[bytecodes[pc++] & 0xff]).fn.op2(b, a);
	continue;
case CALL2R:
	a = ((Symbol)env[bytecodes[pc++] & 0xff]).fn.op2(a, b);
	continue;
case CALL3:
        a = ((Symbol)env[bytecodes[pc++] & 0xff]).fn.opn(new LispObject [] {stack[sp--], b, a});
	continue;
case CALLN:
        arg = bytecodes[pc++] & 0xff;
        iw = bytecodes[pc++] & 0xff;
        sp -= (iw-2);
        a = liftcalln(arg, iw, sp, a, b);
        continue;
case CALL0_0:
	a = op0();   // optimisation on call to self!
	continue;
case CALL0_1:
case CALL0_2:
case CALL0_3:
	a = ((Symbol)env[arg-CALL0_0]).fn.op0();
	continue;
case CALL1_0:
	a = op1(a);   // call to self
	continue;
case CALL1_1:
case CALL1_2:
case CALL1_3:
case CALL1_4:
case CALL1_5:
	a = ((Symbol)env[arg-CALL1_0]).fn.op1(a);
	continue;
case CALL2_0:
	a = op2(b, a);   // call to self
	continue;
case CALL2_1:
case CALL2_2:
case CALL2_3:
case CALL2_4:
	a = ((Symbol)env[arg-CALL2_0]).fn.op2(b, a);
	continue;
case BUILTIN0:
	a = builtin0[bytecodes[pc++] & 0xff].op0();
	continue;
case BUILTIN1:
	a = builtin1[bytecodes[pc++] & 0xff].op1(a);
	continue;
case BUILTIN2:
	a = builtin2[bytecodes[pc++] & 0xff].op2(b, a);
	continue;
case BUILTIN2R:
	a = builtin2[bytecodes[pc++] & 0xff].op2(a, b);
 	continue;
case BUILTIN3:
	a = builtin3[bytecodes[pc++] & 0xff].opn(new LispObject [] {stack[sp--], b, a});
	continue;
case APPLY1:
        if (b instanceof Symbol)
        {   a = ((Symbol)b).fn.op1(a);
        }
        else if (b instanceof LispFunction)
        {   a = ((LispFunction)b).op1(a);
        }
        else a = Fns.apply1(b, a);
        continue;
case APPLY2:
        if (stack[sp] instanceof Symbol)
        {   a = ((Symbol)stack[sp--]).fn.op2(b, a);
        }
        else if (stack[sp] instanceof LispFunction)
        {   a = ((LispFunction)stack[sp--]).op2(b, a);
        }
        else a = Fns.apply2(stack[sp--], b, a);
        continue;
case APPLY3:
        sp -= 2;
        if (stack[sp+1] instanceof Symbol)
        {   a = ((Symbol)stack[sp+1]).fn.opn(new LispObject [] {stack[sp+2], b, a});
        }
        else if (stack[sp+1] instanceof LispFunction)
        {   a = ((LispFunction)stack[sp+1]).opn(new LispObject [] {stack[sp+2], b, a});
        }
        else a = Fns.apply3(stack[sp+1], stack[sp+2], b, a);
        continue;
case APPLY4:
        sp -= 3;
        if (stack[sp+1] instanceof Symbol)
        {   a = ((Symbol)stack[sp+1]).fn.opn(new LispObject [] {stack[sp+2], stack[sp+3], b, a});
        }
        else if (stack[sp+1] instanceof LispFunction)
        {   a = ((LispFunction)stack[sp+1]).opn(new LispObject [] {stack[sp+2], stack[sp+3], b, a});
        }
        else a = Fns.applyn(stack[sp+1], 
            new LispObject [] {stack[sp+2], stack[sp+3], b, a});
        continue;
case JCALL:
        arg = bytecodes[pc++];
        if ((arg & 0x1f) == 0) // callself case
        {   pc = jcallself(arg, spsave, a, b);
            sp = spsave;
            continue;
        }
        else
        {   iw = sp;
            sp = spsave;
            return jcall(arg, iw, a, b);
        }
case JCALLN:
        arg = bytecodes[pc++];
        iw = sp;
        sp = spsave;
        return liftjcalln(arg, bytecodes[pc++] & 0xff, iw, a, b);
case JUMP:
        arg = 0;
// "break" here drops out to some commoned up code that completes the
// implementation of a forward branch.
        break;
case JUMP_B:
        pc = pc - (bytecodes[pc] & 0xff) + 1;
        continue;
case JUMP_L:
        arg = bytecodes[pc++] & 0xff;
        break;
case JUMP_BL:
        arg = bytecodes[pc++] & 0xff;
        pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        continue;
case JUMPNIL:
        arg = 0;
        if (a == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPNIL_B:
        if (a == Jlisp.nil) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPNIL_L:
        arg = bytecodes[pc++] & 0xff;
        if (a == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPNIL_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a == Jlisp.nil) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPT:
        arg = 0;
        if (a != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPT_B:
        if (a != Jlisp.nil) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPT_L:
        arg = bytecodes[pc++] & 0xff;
        if (a != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPT_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a != Jlisp.nil) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPATOM:
        arg = 0;
        if (a.atom) break;
        else pc++;
        continue;
case JUMPATOM_B:
        if (a.atom) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPATOM_L:
        arg = bytecodes[pc++] & 0xff;
        if (a.atom) break;
        else pc++;
        continue;
case JUMPATOM_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a.atom) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPNATOM:
        arg = 0;
        if (!a.atom) break;
        else pc++;
        continue;
case JUMPNATOM_B:
        if (!a.atom) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPNATOM_L:
        arg = bytecodes[pc++] & 0xff;
        if (!a.atom) break;
        else pc++;
        continue;
case JUMPNATOM_BL:
        arg = bytecodes[pc++] & 0xff;
        if (!a.atom) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPEQ:
// Beware small integers!
        arg = 0;
        if (a == b ||
            (a instanceof LispSmallInteger && a.lispequals(b))) break;
        else pc++;
        continue;
case JUMPEQ_B:
        if (a == b ||
            (a instanceof LispSmallInteger && a.lispequals(b)))
            pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPEQ_L:
        arg = bytecodes[pc++] & 0xff;
        if (a == b ||
            (a instanceof LispSmallInteger && a.lispequals(b))) break;
        else pc++;
        continue;
case JUMPEQ_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a == b ||
            (a instanceof LispSmallInteger && a.lispequals(b)))
            pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPNE:
        arg = 0;
        if (a != b &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(b))) break;
        else pc++;
        continue;
case JUMPNE_B:
        if (a != b &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(b)))
            pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPNE_L:
        arg = bytecodes[pc++] & 0xff;
        if (a != b &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(b))) break;
        else pc++;
        continue;
case JUMPNE_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a != b &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(b)))
            pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPEQUAL:
        arg = 0;
        if (a.lispequals(b)) break;
        else pc++;
        continue;
case JUMPEQUAL_B:
        if (a.lispequals(b)) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPEQUAL_L:
        arg = bytecodes[pc++] & 0xff;
        if (a.lispequals(b)) break;
        else pc++;
        continue;
case JUMPEQUAL_BL:
        arg = bytecodes[pc++] & 0xff;
        if (a.lispequals(b)) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPNEQUAL:
        arg = 0;
        if (!a.lispequals(b)) break;
        else pc++;
        continue;
case JUMPNEQUAL_B:
        if (!a.lispequals(b)) pc = pc - (bytecodes[pc] & 0xff) + 1;
        else pc++;
        continue;
case JUMPNEQUAL_L:
        arg = bytecodes[pc++] & 0xff;
        if (!a.lispequals(b)) break;
        else pc++;
        continue;
case JUMPNEQUAL_BL:
        arg = bytecodes[pc++] & 0xff;
        if (!a.lispequals(b)) pc = pc - ((arg << 8) + (bytecodes[pc] & 0xff)) + 1;
        else pc++;
        continue;
case JUMPL0NIL:
        arg = 0;
        if (stack[sp-0] == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL0T:
        arg = 0;
        if (stack[sp-0] != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL1NIL:
        arg = 0;
        if (stack[sp-1] == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL1T:
        arg = 0;
        if (stack[sp-1] != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL2NIL:
        arg = 0;
        if (stack[sp-2] == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL2T:
        arg = 0;
        if (stack[sp-2] != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL3NIL:
        arg = 0;
        if (stack[sp-3] == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL3T:
        arg = 0;
        if (stack[sp-3] != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL4NIL:
        arg = 0;
        if (stack[sp-4] == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL4T:
        arg = 0;
        if (stack[sp-4] != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST0NIL:
        arg = 0;
        if ((stack[sp-0] = a) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST0T:
        arg = 0;
        if ((stack[sp-0] = a) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST1NIL:
        arg = 0;
        if ((stack[sp-1] = a) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST1T:
        arg = 0;
        if ((stack[sp-1] = a) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST2NIL:
        arg = 0;
        if ((stack[sp-2] = a) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPST2T:
        arg = 0;
        if ((stack[sp-2] = a) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPL0ATOM:
        arg = 0;
        if (stack[sp-0].atom) break;
        else pc++;
        continue;
case JUMPL0NATOM:
        arg = 0;
        if (!stack[sp-0].atom) break;
        else pc++;
        continue;
case JUMPL1ATOM:
        arg = 0;
        if (stack[sp-1].atom) break;
        else pc++;
        continue;
case JUMPL1NATOM:
        arg = 0;
        if (!stack[sp-1].atom) break;
        else pc++;
        continue;
case JUMPL2ATOM:
        arg = 0;
        if (stack[sp-2].atom) break;
        else pc++;
        continue;
case JUMPL2NATOM:
        arg = 0;
        if (!stack[sp-2].atom) break;
        else pc++;
        continue;
case JUMPL3ATOM:
        arg = 0;
        if (stack[sp-3].atom) break;
        else pc++;
        continue;
case JUMPL3NATOM:
        arg = 0;
        if (!stack[sp-3].atom) break;
        else pc++;
        continue;
case JUMPFREE1NIL:
        arg = 0;
        if (env[1].car/*value*/ == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE1T:
        arg = 0;
        if (env[1].car/*value*/ != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE2NIL:
        arg = 0;
        if (env[2].car/*value*/ == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE2T:
        arg = 0;
        if (env[2].car/*value*/ != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE3NIL:
        arg = 0;
        if (env[3].car/*value*/ == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE3T:
        arg = 0;
        if (env[3].car/*value*/ != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE4NIL:
        arg = 0;
        if (env[4].car/*value*/ == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREE4T:
        arg = 0;
        if (env[4].car/*value*/ != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREENIL:
        arg = 0;
        if (env[bytecodes[pc++] & 0xff].car/*value*/ == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFREET:
        arg = 0;
        if (env[bytecodes[pc++] & 0xff].car/*value*/ != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPLIT1EQ:
        arg = 0;
        if (env[1] == a ||
            (a instanceof LispSmallInteger && a.lispequals(env[1]))) break;
        else pc++;
        continue;
case JUMPLIT1NE:
        arg = 0;
        if (env[1] != a &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(env[1]))) break;
        else pc++;
        continue;
case JUMPLIT2EQ:
        arg = 0;
        if (env[2] == a ||
            (a instanceof LispSmallInteger && a.lispequals(env[2]))) break;
        else pc++;
        continue;
case JUMPLIT2NE:
        arg = 0;
        if (env[2] != a &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(env[2]))) break;
        else pc++;
        continue;
case JUMPLIT3EQ:
        arg = 0;
        if (env[3] == a ||
            (a instanceof LispSmallInteger && a.lispequals(env[3]))) break;
        else pc++;
        continue;
case JUMPLIT3NE:
        arg = 0;
        if (env[3] != a &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(env[3]))) break;
        else pc++;
        continue;
case JUMPLIT4EQ:
        arg = 0;
        if (env[4] == a ||
            (a instanceof LispSmallInteger && a.lispequals(env[4]))) break;
        else pc++;
        continue;
case JUMPLIT4NE:
        arg = 0;
        if (env[4] != a &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(env[4]))) break;
        else pc++;
        continue;
case JUMPLITEQ:
        arg = 0;
        if ((w = env[bytecodes[pc++] & 0xff]) == a ||
            (a instanceof LispSmallInteger && a.lispequals(w))) break;
        else pc++;
        continue;
case JUMPLITNE:
        arg = 0;
        if ((w = env[bytecodes[pc++] & 0xff]) != a &&
            (!(a instanceof LispSmallInteger) || !a.lispequals(w))) break;
        else pc++;
        continue;
case JUMPB1NIL:
        arg = 0;
        if (builtin1[bytecodes[pc++] & 0xff].op1(a) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPB1T:
        arg = 0;
        if (builtin1[bytecodes[pc++] & 0xff].op1(a) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPB2NIL:
        arg = 0;
        if (builtin2[bytecodes[pc++] & 0xff].op2(b, a) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPB2T:
        arg = 0;
        if (builtin2[bytecodes[pc++] & 0xff].op2(b, a) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPFLAGP:
        arg = 0;
        if (builtin2[BIflagp].op2(a, env[bytecodes[pc++] & 0xff]) != Jlisp.nil) break;
        else pc++;
        continue;
case JUMPNFLAGP:
        arg = 0;
        if (builtin2[BIflagp].op2(a, env[bytecodes[pc++] & 0xff]) == Jlisp.nil) break;
        else pc++;
        continue;
case JUMPEQCAR:
        arg = bytecodes[pc++] & 0xff;
        if (!a.atom && ((w = env[arg]) == a.car ||
            (w instanceof LispSmallInteger && w.lispequals(a.car))))
        {   arg = 0;
            break;
        }
        else pc++;
        continue;
case JUMPNEQCAR:
        arg = bytecodes[pc++] & 0xff;
        if (a.atom || ((w = env[arg]) != a.car &&
           (!(w instanceof LispSmallInteger) || !w.lispequals(a.car))))
        {   arg = 0;
            break;
        }
        else pc++;
        continue;
case CATCH:
        iw = pc + (bytecodes[pc] & 0xff) + 1;
        pc++;
        catchTags = new Cons(a, catchTags);
        stack[++sp] = LispInteger.valueOf(iw);
        stack[++sp] = catchTags;
        stack[++sp] = Spid.catcher;
        continue;
case CATCH_B:
        iw = pc - (bytecodes[pc] & 0xff);
        pc++;
        catchTags = new Cons(a, catchTags);
        stack[++sp] = LispInteger.valueOf(iw);
        stack[++sp] = catchTags;
        stack[++sp] = Spid.catcher;
        continue;
case CATCH_L:
        iw = bytecodes[pc++] & 0xff;
        iw = pc + (iw<<8) + (bytecodes[pc] & 0xff);
        pc++;
        catchTags = new Cons(a, catchTags);
        stack[++sp] = LispInteger.valueOf(iw);
        stack[++sp] = catchTags;
        stack[++sp] = Spid.catcher;
        continue;
case CATCH_BL:
        iw = bytecodes[pc++] & 0xff;
        iw = pc - ((iw<<8) + (bytecodes[pc] & 0xff));
        pc++;
        catchTags = new Cons(a, catchTags);
        stack[++sp] = LispInteger.valueOf(iw);
        stack[++sp] = catchTags;
        stack[++sp] = Spid.catcher;
        continue;
case UNCATCH:
        sp--;
        w = stack[sp--];
        sp--;
        catchTags = w.cdr;
        w.car = w;
        w.cdr = Jlisp.nil;
        continue;
case THROW:
        throw new LispThrow(b, a);
case PROTECT:
// I obey this when an UNWIND-PROTECT block has completed without any
// special events. So I remove the "CATCH" frams on the stack and leave things
// with whatever my current value of the "a" register is there.
        stack[sp] = a;
        continue;
case UNPROTECT:
        a = stack[sp];
        sp -= 3;
        if (a instanceof LispSavedException) throw ((LispSavedException)a).e;
        continue;
case PVBIND:
        Jlisp.error("bytecode PVBIND not implemented");
case PVRESTORE:
        Jlisp.error("bytecode PVRESTORE not implemented");
case FREEBIND:
        sp = freebind(bytecodes[pc++] & 0xff, sp);
        continue;
case FREERSTR:
        {   sp--;   // ought to be the Spid
            LispObject [] v = ((LispVector)stack[sp--]).vec;
            for (int i=v.length-1; i>=0; i--)
            {   v[i].car/*value*/ = stack[sp--];
            }
        }
        continue;
case EXIT:
        sp = spsave;
        return a;
case NILEXIT:
        sp = spsave;
        return Jlisp.nil;
case LOC0EXIT:
        pc = sp;
        sp = spsave;
        return stack[pc-0];
case LOC1EXIT:
        pc = sp;
        sp = spsave;
        return stack[pc-1];
case LOC2EXIT:
        pc = sp;
        sp = spsave;
        return stack[pc-2];
case PUSH:
        stack[++sp] = a;
        continue;
case PUSHNIL:
        stack[++sp] = Jlisp.nil;
        continue;
case PUSHNIL2:
        stack[++sp] = Jlisp.nil;
        stack[++sp] = Jlisp.nil;
        continue;
case PUSHNIL3:
        stack[++sp] = Jlisp.nil;
        stack[++sp] = Jlisp.nil;
        stack[++sp] = Jlisp.nil;
        continue;
case PUSHNILS:
        arg = bytecodes[pc++] & 0xff;
        for (int i=0; i<arg; i++)
            stack[++sp] = Jlisp.nil;
        continue;
case POP:
        b = a;
        a = stack[sp--];
        continue;
case LOSE:
        sp--;
        continue;
case LOSE2:
        sp -= 2;
        continue;
case LOSE3:
        sp -= 3;
        continue;
case LOSES:
        sp -= (bytecodes[pc++] & 0xff);
        continue;
case SWOP:
        w = a; a = b; b = w;
        continue;
case EQCAR:
        if (b.atom)
        {   a = Jlisp.nil;
            continue;
        }
        else b = b.car;
        // drop through into EQ
case EQ:
// I have a nasty cop-out here, and need to consider it everywhere that
// EQ is used not just in this in-line version. In CSL all sufficiently
// small integers are stored as immediate data and so EQ is a reliable
// test on them... at present the range is numbers whose signed value fits
// within 28 bits, but that should not be considered long-term guaranteed.
// PSL has "inums" and it looks as if they are 27 or 56-bits wide.
//
// All this means that there is a real denger that there can be extant
// Reduce code that (perhaps improperly) uses EQ to compare numbers that
// it expects to be small integers, and so despite the fact that it will
// slow me down I will support that test here.
        if (a == b ||
            (a instanceof LispSmallInteger &&
             a.lispequals(b))) a = Jlisp.lispTrue;
        else a = Jlisp.nil;
        continue;
case EQUAL:
        a = (a.lispequals(b)) ? Jlisp.lispTrue : Jlisp.nil;
        continue;
case NUMBERP:
        a = (a instanceof LispNumber) ? Jlisp.lispTrue : Jlisp.nil;
        continue;
case CAR:
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        continue;
case CDR:
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        continue;
case CAAR:
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        continue;
case CADR:
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        continue;
case CDAR:
        if (a.atom) Jlisp.error("attempt to take car of an atom", a);
        a = a.car;
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        continue;
case CDDR:
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        if (a.atom) Jlisp.error("attempt to take cdr of an atom", a);
        a = a.cdr;
        continue;
case CONS:
        a = new Cons(b, a);
        continue;
case NCONS:
        a = new Cons(a, Jlisp.nil);
        continue;
case XCONS:
        a = new Cons(a, b);
        continue;
case ACONS:
        a = new Cons(new Cons(stack[sp--], b), a);
        continue;
case LENGTH:
        a = builtin1[BIlength].op1(a);
        continue;
case LIST2:
        a = new Cons(b, new Cons(a, Jlisp.nil));
        continue;
case LIST2STAR:
        a = new Cons(stack[sp--], new Cons(b, a));
        continue;
case LIST3:
        a = new Cons(stack[sp--], new Cons(b, new Cons(a, Jlisp.nil)));
        continue;
case PLUS2:
        a = builtin2[BIplus2].op2(b, a);
        continue;
case ADD1:
        a = builtin1[BIadd1].op1(a);
        continue;
case DIFFERENCE:
        a = builtin2[BIdifference].op2(b, a);
        continue;
case SUB1:
        a = builtin1[BIsub1].op1(a);
        continue;
case TIMES2:
        a = builtin2[BItimes2].op2(b, a);
        continue;
case GREATERP:
        a = builtin2[BIgreaterp].op2(b, a);
        continue;
case LESSP:
        a = builtin2[BIlessp].op2(b, a);
        continue;
case FLAGP:
        a = builtin2[BIflagp].op2(b, a);
        continue;
case GET:
        a = builtin2[BIget].op2(b, a);
        continue;
case LITGET:
        arg = bytecodes[pc++] & 0xff;
        a = builtin2[BIget].op2(a, env[arg]);
        continue;
case GETV:
        a = builtin2[BIgetv].op2(b, a);
        continue;
case QGETV:
        a = builtin2[BIqgetv].op2(b, a);
        continue;
case QGETVN:
        arg = bytecodes[pc++] & 0xff;
        a = builtin2[BIgetv].op2(a, LispInteger.valueOf(arg));
        continue;
case BIGSTACK:
        iw = bytecodes[pc++] & 0xff;
        Jlisp.printf("BIGSTACK %x%n", iw);
        switch (iw & 0xc0)
        {
    default:
    //case 0x00:
            b = a;
            iw = (iw & 0x3f) << 8;
            a = stack[sp-(iw + (bytecodes[pc++] & 0xff))];
            continue;
    case 0x40:
            iw = (iw & 0x3f) << 8;
            stack[sp-(iw + (bytecodes[pc++] & 0xff))] = a;
            continue;
    case 0x80:
            Jlisp.error("BIG CLOSURE not implemented");
    case 0xc0:
            Jlisp.error("BIG LEX ACCESS not implemented");
//          n = bytecodes[pc++] & 0xff;
//          k = bytecodes[pc++] & 0xff;
//          n = (n << 4) | (k >> 4);
//          r1 = stack[sp+1-n];
//          b = a;
//          n = w & 0x1f;
//          while (n != 0) n--;
//          if ((w & 0x20) == 0)
//              a = 0;
//          else ?? = a;
//          continue;
        }
case BIGCALL:
        iw = bytecodes[pc++] & 0xff;
//      Jlisp.printf("BIGCALL %x%n", iw);
        fname = (bytecodes[pc++] & 0xff) + ((iw & 0xf) << 8);
        switch (iw >> 4)
        {
    default:
    //case 0: // call0
	    a = ((Symbol)env[fname]).fn.op0();
            continue;
    case 1:   // call1
	    a = ((Symbol)env[fname]).fn.op1(a);
            continue;
    case 2:   // call2
	    a = ((Symbol)env[fname]).fn.op2(b, a);
            continue;
    case 3:   // call3
            a = ((Symbol)env[fname]).fn.opn(
                new LispObject [] {stack[sp--], b, a});
            continue;
    case 4:   // calln
            Jlisp.error("BIG CALLN not implemented");
    case 5:   // call2r
	    a = ((Symbol)env[fname]).fn.op2(a, b);
            continue;
    case 6:   // loadfree
            b = a;
            a = env[fname].car/*value*/;
            continue;
    case 7:   // storefree
            env[fname].car/*value*/ = a;
            continue;
    case 8:   // jcall0
            sp = spsave;
            return ((Symbol)env[fname]).fn.op0();
    case 9:   // jcall1
            sp = spsave;
            return ((Symbol)env[fname]).fn.op1(a);
    case 10:  // jcall2
            sp = spsave;
            return ((Symbol)env[fname]).fn.op2(b, a);
    case 11:  // jcall3
            pc = sp;
            sp = spsave;
            return ((Symbol)env[fname]).fn.opn(
                new LispObject [] {stack[pc--], b, a});
    case 12:  // jcalln
            Jlisp.error("BIG JCALLN not implemented");
    case 13:  // freebind
            Jlisp.error("BIG FREEBIND not implemented");
    case 14:  // litget
            Jlisp.error("BIG LITGET not implemented");
    case 15:  // loadlit
            b = a;
            a = env[fname];
            continue;
        }
case ICASE:
//
// The ICASE opcode is followed by a byte (n say) that indicates the number
// of cases that follow, followed by n+1 double-byte label values.
// If these addresses are called L<dflt>, L<0>, L<1>, ... L<n-1> then if the
// A register contains an integer in the range 0 <= k < n then control is
// transferred to L<k>, while if the A register does not hold an integer or
// if its value is out of range then control goes to L<dflt>.
//
        Jlisp.error("bytecode ICASE not implemented");
case FASTGET:
//
// FASTGET n
//     0 <= n < 64       (GET A_reg property_n)
//    64 <= n < 128      (GET A_reg property_n B_reg)
//   128 <= n < 192      (FLAGP A_reg property_n)
//   192 <= n < 256      not used at present.
//
        iw = bytecodes[pc++] & 0xff;
        if (!(a instanceof Symbol)) a = Jlisp.nil;
        if (((Symbol)a).fastgets == null)
        {   if ((iw & 0x40) != 0) a = b; // GET with a non-nil default
            else a = Jlisp.nil;
            continue;
        }
        a = ((Symbol)a).fastgets[iw & 0x3f];
        if (a == Spid.noprop)
        {   if ((iw & 0x40) != 0) a = b;
            else a = Jlisp.nil;
        }
        continue;
case SPARE1:
        Jlisp.error("bytecode SPARE1 not implemented");
case SPARE2:
        Jlisp.error("bytecode SPARE2 not implemented");
    } // end of switch
// This should be where I get to if I do a "break;" in the big switch
// statement above. Note that I am still within the for loop.
    pc = pc + (arg << 8) + (bytecodes[pc] & 0xff) + 1;
    continue;
    } // end of for loop
    } // end of try block
    catch (Exception e)
    {
// ordinary RETURNs out of a function do not come here, but cases of errors
// or THROWs generated by things called from this function do. I have several
// cases that I must detect:
// (a) If there had been fluid bindings then I need to undo them.
// (b) If there had been an UNWIND-PROTECT active in the current
//     function then I need to temporarily suppress the tendany to
//     exit and go and process the recovery code that came with that. This
//     is a bit similar in intend to what restoring fluids do but involves
//     running arbitrary code rather than performing a simple fixed
//     operation.
// (c) If this function had set up a CATCH and the exit being processed
//     is a matching THROW then I need to handle the situation by transferring
//     control back into the current function.
// I will note that after the recovery code that UNWIND-PROTECT can trigger
// I may sometimes need to come back and continue the unwinding that is
// happening here. However if the protected block had not triggered an unusual
// exit I will continue after the recovery action...
//
// All of the above are handled by having a special marker (referred to here
// as a "Spid" (for Special Identifier) on the (software) stack.
// For fluid bindings the format is
//         Spid.fbind
//         [v1 v2 v3 ...]      all the variables as bound
//         old value of vn
//         ...
//         old value of v1
// and this can be processed entirely within the unwinder code.
//
// For a CATCH the stack format is
//         Spid.catcher
//         (this-catch-tag ...)
//         <label>
// and the list shown has the current catch tag as its first item and
// all other active catch tags as the rest of the list. So an instance
// of THROW needs to check its tag against the first item on that list.
// The <label> is represented as a LispSmallInteger that represents the
// value of "pc", ie the bytecode program counter.
//
// UNWIND-PROTECT starts as if it was
//    (CATCH (LOAD!-SPID) ...)
// so its stack marker is again Spid.catcher but the catch tag used is
// the special value Spid.protecter.
// I will come back and discuss what happens later in the process of
// handling the recovery part of UNWIND-PROTECT later.
//
// The function unwind will unwind the stack restoring fluid variables.
// It will stop either when sp is back to spsave (ie there is no more
// stacked information relevant to the current function or if it finds
// a frame relevant to CATCH or UNWIND-PROTECT. It will ignore CATCH records
// that allude to tags not currently being thrown.
        sp = unwinder(sp, spsave, e);
        if (sp < 0) // processing UNWIND-PROTECT
        {   sp = -sp;
// unwinder returns a negative value to indicate that it detected an
// UNWIND-PROTECT frame. The stack must end up wuth (still) 3 items on it,
// the top of which must be either the value of the protected block (if
// that completed normally) or a packaged up exception to re-throw after
// doing the cleanup. It is vital to use stack positions because this is what
// the compiler assumes and relies on if it need to refer to local variables
// from the cleanup code. So in Jlisp two of those locations will merely
// contain nil - a bit of a waste of space.
            a = Jlisp.nil; // just to be tidy
            pc = stack[sp].intValue();
// Save the exception that is to be reinstated when the recovery block
// is done.
            stack[++sp] = a;
            stack[++sp] = a;
            stack[sp] = new LispSavedException(e);
            continue;
        }
// If we have run out of stack frame for this function then the exception
// raised is real.
        if (sp == spsave) throw e;
// Finally we have a CATCH that is catching a matching THROW.
        if (e instanceof LispThrow) a = ((LispThrow)e).details;
        else a = Jlisp.nil;
        pc = stack[sp--].intValue();
        continue;
    }
    } // end of outer for loop
}

}

// end of InstrumentedBytecode.java
