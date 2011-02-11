//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
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

import java.io.*;

class AutoLoad extends LispFunction
{

    Symbol name;
    LispObject data;
    
    AutoLoad(Symbol name, LispObject data)
    {
        this.name = name;
	this.data = data;
    }
    
    public LispObject op0() throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op0();
    }

    public LispObject op1(LispObject a1) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op1(a1);
    }

    public LispObject op2(LispObject a1, LispObject a2) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op2(a1, a2);
    }

    public LispObject opn(LispObject [] args) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.opn(args);
    }

    void print()
    {
        Jlisp.print("#Autoload<" + name.pname + ">");
    }

    void print(int n)
    {
        Jlisp.print("#Autoload<" + name.pname + ">");
    }
    
    void scan()
    {
        if (Jlisp.objects.contains(this)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(this))
	    {   Jlisp.repeatedObjects.put(
	            this,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else
	{   Jlisp.objects.add(this);
	    Jlisp.stack.push(name);
	    Jlisp.stack.push(data);
	}
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w);
	else
	{   if (w != null)
	    {   Jlisp.repeatedObjects.put(
	            this,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
	    }
	    Jlisp.odump.write(X_AUTOLOAD);
	    Jlisp.stack.push(data);
	    Jlisp.stack.push(name);
	}
    }
    
}

// End of LispFunction.java


