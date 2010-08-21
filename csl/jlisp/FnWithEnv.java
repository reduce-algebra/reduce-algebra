//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

public class FnWithEnv extends LispFunction
{

int nargs;           // integer field saved in image file
byte [] bytecodes;   // can be null if not needed (never shared?)
public LispObject [] env;   // vector of lisp objects, eg literals

FnWithEnv()
{
    env = new LispObject[0];
    bytecodes = null;
    nargs = 0;
}

FnWithEnv(LispObject [] env)
{
    this.env = env;
    bytecodes = null;
    nargs = 0;
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
    for (int i=0; i<env.length; i++)
        Jlisp.stack.push(env[i]);
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
        int length;
        if (bytecodes == null) length = 0;
        else length = bytecodes.length;
        putPrefix(length, X_BPS);
        int n = nargs;
// nargs can be up to 22 bits, ie 0x003fffff (7+7+8 bits)
        if (n <= 0x7f) Jlisp.odump.write(n);
        else
        {   Jlisp.odump.write(n | 0x80);
            n = n >> 7;
            if (n <= 0x7f) Jlisp.odump.write(n);
            else
            {   Jlisp.odump.write(n | 0x80);
                Jlisp.odump.write(n >> 7);
            }
        }
        for (int i=0; i<length; i++)
            Jlisp.odump.write(bytecodes[i]);
        length = env.length;
        putPrefix(length, X_VEC);  // context after BPS decodes this case!
        for (int i=0; i<length; i++)
            Jlisp.stack.push(env[i]);
    }
}


}


// End of FnWithEnv.java

