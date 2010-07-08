//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

// A Lisp macro is really very much like an ordinary
// function with exactly one argument. It is the way that the
// interpreted processes it that makes it different. Well actually because
// of views on Common Lisp compatibility the function that is a macro
// has one essential argument and one optional one (which I never use!)

import java.io.*;

class Macro extends LispFunction
{
    LispObject body;

    void iprint()
    {
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 7 > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print("[Macro:");
        body.blankprint();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 1 > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print("]");
    }
											    
    void blankprint()
    {
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 7 >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print("[Macro:");
        body.blankprint();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 1 > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print("]");
    }
											    
    Macro()
    {
    }
    
    Macro(LispObject def) throws Exception
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
	else Jlisp.objects.add(this);
        Jlisp.stack.push(body);
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
            Jlisp.odump.write(X_MACRO);
            Jlisp.stack.push(body);
	}
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

}

// End of Macro.java

