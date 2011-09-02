//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;
import java.util.*;

// This is an object that the user should NEVER get directly hold of
// but which may be used internally as a marker.

class Spid extends LispObject
{
    int tag;
    int data;   // NB NB NB   the field not saved in checkpoint files

    static final int FBIND    = 1;  // free bindings on stack in bytecode
    static final int NOARG    = 2;  // "no argument" after &opt
    static final int DEFINMOD = 3;  // introduces bytecode def in fasl file

    static final Spid fbind = new Spid(FBIND);
    static final Spid noarg = new Spid(NOARG);

    Spid(int tag)
    {
        this.tag = tag & 0xff;
        data = 0;
    }

    Spid(int tag, int data)
    {
        this.tag = tag & 0xff;
        this.data = data;
    }

    LispObject eval()
    {
        return this;
    }

    void iprint()
    {
        String s = "#SPID" + tag;
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint()
    {
        String s = "#SPID" + tag;
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
    }

    void scan()
    {
        Object w = new Integer(tag);
        if (Jlisp.objects.contains(w)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(w))
	    {   Jlisp.repeatedObjects.put(
	            w,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else Jlisp.objects.add(w);
    }
    
    void dump() throws IOException
    {
        Object d = new Integer(tag);
        Object w = Jlisp.repeatedObjects.get(d);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            d,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
	    Jlisp.odump.write(X_SPID);
	    Jlisp.odump.write(tag);
// NOTE that I do NOT dump and restore the data field here. That is because
// I only use it in cases to do with reading FASL files and the relevant
// objects should NEVER need saving in a heap.
	}
    }


}

