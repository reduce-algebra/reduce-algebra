//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;
import java.security.*;

class LispDigester extends LispStream
{

    LispDigester()
    {
        super("<md5 digester>");
        try
        {   md = MessageDigest.getInstance("MD5", "SUN");
        }
        catch (NoSuchAlgorithmException e)
        {
            Jlisp.errprintln("No MD5 available: " + e.getMessage());
            md = null;
        }
        catch (NoSuchProviderException e)
        {
            Jlisp.errprintln("No provider: " + e.getMessage());
            md = null;
        }
    }

    void flush()
    {
    }

    void close()
    {
        md = null;
    }

    void print(String s)
    {
        if (md == null) return;
        char [] v = s.toCharArray();
// It *MAY* be better to use getChars here and move data into a pre-allocated
// array of characters.
        for (int i=0; i<v.length; i++)
        {   char c = v[i];
// characters are in general 16-bits wide (even though all the charcters that
// I will normally use in the UK are only 7 bits) so I pass them to the
// message digest process as two bytes each.
            md.update((byte)(c >> 8));
            md.update((byte)c);
        }
    }

    void println(String s)
    {
        print(s);
        if (md != null)
        {   md.update((byte)0);
            md.update((byte)'\n');
        }
    }

}

// end of LispDigester.java


