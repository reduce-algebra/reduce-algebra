//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class Undefined extends LispFunction
{

    public Undefined(String name)
    {
        this.name = name;
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
	    putPrefix(length, X_UNDEF1);
	    for (int i=0; i<length; i++)
	        Jlisp.odump.write(rep[i]);
	}
    }


}

// end of Undefined.java

