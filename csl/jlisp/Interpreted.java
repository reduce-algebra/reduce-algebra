
//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
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


// If a symbol has an interpreted definition its
// associated function is this job, which knows how to
// extract the saved definition and activate it.

import java.io.*;

class Interpreted extends LispFunction
{
    LispObject body;

    void iprint()
    {
        body.iprint();	
    }
    
    void blankprint()
    {
        body.blankprint();	
    }
    
    Interpreted()
    {
    }
    
    Interpreted(LispObject def)
    {
        body = new Cons(Jlisp.lit[Lit.lambda], def);
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
            Jlisp.stack.push(body);
        }
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            this,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
	    Jlisp.odump.write(X_INTERP);
            Jlisp.stack.push(body);
	}
    }
    

// All interpreted function calls check that the number of arguments
// actually passed agrees with the number expected. Shallow binding is
// used for all variables.

    public LispObject op0() throws Exception
    {
        return Fns.applyInner(body, 0);
    }

    public LispObject op1(LispObject arg1) throws Exception
    {
        Fns.args[0] = arg1;
        return Fns.applyInner(body, 1);
    }

    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        Fns.args[0] = arg1;
        Fns.args[1] = arg2;
        return Fns.applyInner(body, 2);
    }

    public LispObject opn(LispObject [] actual) throws Exception
    {
        int n = actual.length;
        for (int i=0; i<n; i++) Fns.args[i] = actual[i];
        return Fns.applyInner(body, n);
    }
}

// End of Interpreted.java
