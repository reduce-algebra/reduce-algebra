//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.util.*;
import java.io.*;

class LispHash extends LispObject
{
    HashMap hash;
    int flavour;
    
    LispHash(HashMap hash, int n)
    {
        this.hash = hash; 
        this.flavour = n;  // 0 to 4, with only 0 and 2 used!
    }

    void iprint()
    {
        String s = "#<HashTable>";
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint()
    {
        String s = "#<HashTable>";
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
	else 
	{   Jlisp.objects.add(this);
            for (Iterator e = hash.keySet().iterator();
                 e.hasNext();
	        )
            {   Object k = e.next();
                Object v = hash.get(k);
		Jlisp.stack.push(v);
		Jlisp.stack.push(k);
	    }
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
	    Jlisp.odump.write(X_HASH + flavour);
	    for (Iterator e = hash.keySet().iterator();
	         e.hasNext();
		)
            {   Object k = e.next();
	        Object v = hash.get(k);
		Jlisp.stack.push(v);
		Jlisp.stack.push(k);
            }
	    Jlisp.odump.write(X_ENDHASH);
	}
    }


}


// end of LispHash.java

