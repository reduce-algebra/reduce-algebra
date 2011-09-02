//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class LispExploder extends LispStream
{

    boolean asSymbols;

    LispExploder(boolean n) // builds a list of all characters
                            // n true for symbols, false for numeric codes
    {
        super("<exploder>");
        asSymbols = n;
        exploded = Jlisp.nil;
    }

    void flush()
    {
    }

    void close()
    {
        exploded = Jlisp.nil;
    }

    void print(String s)
    {
        char [] v = s.toCharArray();
        for (int i=0; i<v.length; i++)
        {   char c = v[i];
            LispObject w;
            if (asSymbols)
            {   if ((int)c < 128) w = Jlisp.chars[(int)c];
                else w = Symbol.intern(String.valueOf(c));
            }
            else w = LispInteger.valueOf((int)c);
            exploded = new Cons(w, exploded);
        }
    }

    void println(String s)
    {
        print(s);
        if (asSymbols) exploded = new Cons(Jlisp.chars['\n'], exploded);
        else exploded = new Cons(LispInteger.valueOf('\n'), exploded);
    }

}

// end of LispExploder.java


