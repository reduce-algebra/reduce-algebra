
//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

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
