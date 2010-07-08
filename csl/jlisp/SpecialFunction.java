//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

abstract class SpecialFunction extends LispObject
{
    String name;

    abstract LispObject op(LispObject args) throws Exception;

    LispObject error(String s) throws Exception
    {
        return Jlisp.error(s);
    }

    void iprint()
    {
        String s = "#Special<" + name + ">";
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }
    
    void blankprint()
    {
        String s = "#Special<" + name + ">";
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
	    byte [] rep = name.getBytes("UTF8");
	    int length = rep.length;
	    if (length <= 0xff)
	    {   Jlisp.odump.write(X_SPECFN);
	        Jlisp.odump.write(length);
	    }
	    else throw new IOException("overlong name for a function");
	    for (int i=0; i<length; i++)
	        Jlisp.odump.write(rep[i]);
	}
    }

}

// End of SpecialFunction.java

