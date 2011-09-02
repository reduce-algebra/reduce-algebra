//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class LispCounter extends LispStream
{

    LispCounter()
    {
        super("<character counter>");
        column = 0;
    }

    void flush()
    {
    }

    void close()
    {
    }

    void print(String s)
    {
        column += s.length();
    }

    void println(String s)
    {
        column += s.length() + 1;
    }

}

// end of LispCounter.java


