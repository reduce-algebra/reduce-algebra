//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.security.*;

class ListReader extends LispStream
{

    ListReader(LispObject data)
    {
        super("<read from list>");
        inputData = data;
        needsPrompt = false;
        escaped = false;
        this.allowOctal = allowOctal;
        nextChar = -2;
    }

    int read() throws Exception
    {
        if (inputData.atom) return -1;
        LispObject w = inputData.car;
        inputData = inputData.cdr;
        if (w instanceof LispString)
            return (int)((LispString)w).string.charAt(0);
        else if (w instanceof Symbol)
            return (int)((Symbol)w).pname.charAt(0);
        else if (w instanceof LispInteger)
            return w.intValue();
        else return -1;
    }

    void close()
    {
        inputData = Jlisp.nil;
    }

}

// end of ListReader.java
