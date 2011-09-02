//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class LispOutputString extends LispStream
{

    LispOutputString()
    {
        super("<string output>");
        sb = new StringBuffer();
    }

    void flush()
    {
    }

    void close()
    {
        sb = null;
    }

    void print(String s)
    {
        sb.append(s);
    }

    void println(String s)
    {
        sb.append(s);
        sb.append("\n");
    }

}

// end of LispOutputString.java


