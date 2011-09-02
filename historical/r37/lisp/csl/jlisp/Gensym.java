//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class Gensym extends Symbol
{

    Gensym(String name)
    {
        pname = name;
        car/*value*/ = Jlisp.lit[Lit.undefined];
        cdr/*plist*/ = Jlisp.nil;
        fn = new Undefined(name);
        special = null;
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
	    byte [] rep = pname.getBytes("UTF8");
	    int length = rep.length;
	    putPrefix2(length, X_GENSYMn, X_GENSYM);
	    for (int i=0; i<length; i++)
	        Jlisp.odump.write(rep[i]);
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

