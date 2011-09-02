//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

public class LispString extends LispObject
{

    static int stringCount = 0;

    String string;

    LispString(String s)
    {
        this.string = s;
    }

    static StringBuffer sb = new StringBuffer();

    void iprint()
    {
        String s;
        if ((currentFlags & printEscape) != 0) s = escapedPrint(); 
        else s = string;
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println(); 
        currentOutput.print(s);
    }

    String escapedPrint()
    {
        sb.setLength(0);
        sb.append("\"");
        int n = string.indexOf('"');
        if (n == -1) sb.append(string);
        else
        {   int s = 0;
            while (n != -1)
            {   sb.append(string.substring(s, n+1));
                sb.append("\"");
                s = n+1;
                n = string.indexOf('"', s);
            }
            sb.append(string.substring(s, string.length()));
        }
        sb.append("\"");
        return sb.toString();
    }

    void blankprint()
    {
        String s;
        if ((currentFlags & printEscape) != 0) s = escapedPrint(); 
        else s = string;
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
    }

    public boolean lispequals(Object b)
    {   if (!(b instanceof LispString)) return false;
        return string.equals(((LispString)b).string);
    }

    public boolean equals(Object b)
    {   if (!(b instanceof LispString)) return false;
        return string.equals(((LispString)b).string);
    }

    public int lisphashCode()
    {
        return string.hashCode();
    }
    
    public int hashCode()
    {
        return string.hashCode();
    }

    void scan()
    {
        if (Jlisp.objects.contains(string)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(string))
	    {   Jlisp.repeatedObjects.put(
	            string,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else Jlisp.objects.add(string);
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(string);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            string,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
// The next line turns the string into bytes using the platform's default
// encoding. I would LIKE to use a representation guaranteed to be available
// and to behave consistently everywhere... 
	    byte [] rep = string.getBytes("UTF8");
	    int length = rep.length;
	    putPrefix2(length, X_STRn, X_STR);
	    for (int i=0; i<length; i++)
	    {   Jlisp.odump.write(rep[i]);
            }
	}
    }

    private void readObject(ObjectInputStream stream)
                 throws ClassNotFoundException, IOException
    {
        stream.defaultReadObject();
        stringCount++;
    }


}


// end of LispString.java

