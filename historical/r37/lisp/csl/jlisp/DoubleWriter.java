
//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class DoubleWriter extends LispStream
{
    Writer log;
    boolean closeMe;

    DoubleWriter(String n, Writer log) throws IOException // to a named file
    {
        super(n);
        wr = new BufferedWriter(new FileWriter(nameConvert(n)));
        this.log = log;
        closeMe = true;
        Jlisp.openOutputFiles.add(this);
    }

    DoubleWriter(Writer log) // uses standard input, no extra buffering.
    {
        super("<stdout>");
        wr = Jlisp.out;
        this.log = log;
        closeMe = false;
        Jlisp.openOutputFiles.add(this);
    }

    void flush()
    {
        try
        {   wr.flush();
            log.flush();
        }
        catch (IOException e)
        {}
    }

    void close()
    {
        Jlisp.openOutputFiles.removeElement(this);
        try
        {   wr.flush();
            log.flush();
            if (closeMe) wr.close();
            log.close();
        }
        catch (IOException e)
        {}
    }

    void print(String s)
    {
        if (s == null) s = "null";
        char [] v = s.toCharArray();
// It *MAY* be better to use getChars here and move data into a pre-allocated
// array of characters.
        try
        {   int p = 0;
            for (int i=0; i<v.length; i++)
            {   char c = v[i];
// See commentary if LispOutputStream.java
                if (c == '\n') 
                {   wr.write(v, p, i-p);
                    wr.write(eol);
                    log.write(v, p, i-p);
                    log.write(eol);
                    p = i+1;
                    column = 0;
                }
                else if (c == '\r')
                {   wr.write(v, p, i-p);
                    log.write(v, p, i-p);
                    p = i+1;
                    column = 0;
                }
                else column++;
            }
            wr.write(v, p, v.length-p);
            log.write(v, p, v.length-p);
        }
        catch (IOException e)
        {}
    }

    void println(String s)
    {
        if (s == null) s = "null";
        char [] v = s.toCharArray();
        try
        {   int p = 0;
            for (int i=0; i<v.length; i++)
            {   char c = v[i];
                if (c == '\n') 
                {   wr.write(v, p, i-p);
                    wr.write(eol);
                    log.write(v, p, i-p);
                    log.write(eol);
                    p = i+1;
                }
                else if (c == '\r')
                {   wr.write(v, p, i-p);
                    log.write(v, p, i-p);
                    p = i+1;
                }
            }
            wr.write(v, p, v.length-p);
            wr.write(eol);
            log.write(v, p, v.length-p);
            log.write(eol);
        }
        catch (IOException e)
        {}
        column = 0;
    }

}

// end of DoubleWriter.java


