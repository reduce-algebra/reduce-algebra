//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class WriterToLisp extends Writer
{
    LispStream stream;

    WriterToLisp(LispStream s)
    {
        stream = s;
    }

    public void close()
    {
        stream.close();
    }

    public void flush()
    {
        stream.flush();
    }

    public void write(char [] buffer, int off, int len)
    {
        stream.print(new String(buffer, off, len));
    }

}

// end of WriterToLisp.java


