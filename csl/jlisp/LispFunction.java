//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

public abstract class LispFunction extends LispObject
{
    String name = "unknown-function";

    public LispObject op0() throws Exception
    {
        return error("undefined " + name + " with 0 args");
    }

    public LispObject op1(LispObject a1) throws Exception
    {
        return error("undefined " + name + " with 1 arg");
    }

    public LispObject op2(LispObject a1, LispObject a2) throws Exception
    {
        return error("undefined " + name + " with 2 args");
    }

    public LispObject opn(LispObject [] args) throws Exception
    {
        return error("undefined " + name + " with " + args.length + " args");
    }

    LispObject error(String s) throws Exception
    {
        return Jlisp.error(s);
    }

    LispObject error(String s, LispObject a) throws Exception
    {
        return Jlisp.error(s, a);
    }

    void iprint()
    {
        String s = "#Fn<" + name + ">";
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint()
    {
        String s = "#Fn<" + name + ">";
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
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
    }
    

}

// End of LispFunction.java


