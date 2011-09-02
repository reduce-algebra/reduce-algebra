//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.security.*;

class LispStringReader extends LispStream
{

    int pos;

    LispStringReader(String data)
    {
        super("<read from string>");
        stringData = data;
        pos = 0;
        needsPrompt = false;
        escaped = false;
        this.allowOctal = allowOctal;
        nextChar = -2;
    }

    int read()
    {
        if (pos >= stringData.length()) return -1;
        else return (int)stringData.charAt(pos++);
    }

    void close()
    {
        stringData = null;
    }

}

// end of LispStringReader.java
