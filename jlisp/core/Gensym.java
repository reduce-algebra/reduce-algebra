package uk.co.codemist.jlisp.core;


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

import java.io.*;

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

class Gensym extends Symbol
{
    String nameBase = "G";
    static int gensymCounter = 0;
    int myNumber = -1;

    Gensym(String name)
    {
        pname = null;
        nameBase = name;
        car/*value*/ = Jlisp.lit[Lit.undefined];
        cdr/*plist*/ = Jlisp.nil;
        fn = new Undefined(name);
        special = null;
        myNumber = -1;
    }

    void completeName()
    {   if (pname != null) return;
        myNumber = gensymCounter++;
        pname = nameBase;
        if (myNumber < 10) pname += "0";
        if (myNumber < 100) pname += "0";
        if (myNumber < 1000) pname += "0";
        pname += myNumber;
    }

    String toPrint() throws ResourceException
    {
        if ((currentFlags & LispObject.checksumEscape) == 0)
            return super.toPrint(); // do what a Symbol would do
// Here I need to make a string "#Gnnn"
        if (Symbol.localGensyms == null) Symbol.localGensyms = Jlisp.nil;
        LispObject w = Symbol.localGensyms;
        while (w != Jlisp.nil)
        {   if (w.car.car == this) break;
System.out.println("gensym loop");
            w = w.cdr;
        }
        int n;
        if (w == Jlisp.nil)
        {   Symbol.localGensyms = new Cons(
                new Cons(this,
                         LispInteger.valueOf(n = Symbol.localGensymCount++)),
                Symbol.localGensyms);
        }
        else n = ((LispSmallInteger)w.car.cdr).value;
        return String.format("#G%d", n);
    }

    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
	if (w != null &&
	    w instanceof Integer)
	    putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            this,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
	    byte [] rep = nameBase.getBytes("UTF8");
	    int length = rep.length;
	    putPrefix2(length, X_GENSYMn, X_GENSYM);
	    for (int i=0; i<length; i++)
	        Jlisp.odump.write(rep[i]);
            Jlisp.odump.write(myNumber & 0xff);
            Jlisp.odump.write((myNumber >> 8) & 0xff);
            Jlisp.odump.write((myNumber >> 16) & 0xff);
            Jlisp.odump.write((myNumber >> 24) & 0xff);
	    if (Jlisp.descendSymbols)	
	    {   Jlisp.stack.push(car/*value*/);
	        Jlisp.stack.push(cdr/*plist*/);
	        Jlisp.stack.push(special);
	        Jlisp.stack.push(fn);
	    }
	}
    }

}

// end of Gensym.java

