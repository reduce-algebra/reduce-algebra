//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class LispOutputStream extends LispStream
{

    boolean closeMe;

    LispOutputStream(String n) throws IOException // to a named file
    {
        super(n);
        wr = new BufferedWriter(new FileWriter(nameConvert(n)));
        closeMe = true;
        Jlisp.openOutputFiles.add(this);
    }

    LispOutputStream(File n) throws IOException // to a named file
    {
        super(n.getName());
        wr = new BufferedWriter(new FileWriter(n));
        closeMe = true;
        Jlisp.openOutputFiles.add(this);
    }

    LispOutputStream(String n, boolean appendp) throws IOException
    // to a file, but with an "append" option
    {
        super(n);
        wr = new BufferedWriter(new FileWriter(nameConvert(n), appendp));
        closeMe = true;
        Jlisp.openOutputFiles.add(this);
    }

    LispOutputStream() // uses standard input, no extra buffering.
                       // but note that I have made it a Writer already...
    {
        super("<stdout>");
        wr = Jlisp.out;
        closeMe = false;
        Jlisp.openOutputFiles.add(this);
    }

    void flush()
    {
        try
        {   wr.flush();
        }
        catch (IOException e)
        {}
    }

    void close()
    {
        Jlisp.openOutputFiles.removeElement(this);
        try
        {   wr.flush();
            if (closeMe) wr.close();
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
// In counting columns here I do not take any account of
//   (a) tab
//   (b) backspace
//   (c) '\p' and any other oddities
// in fact I just count anything apart from '\n' as one character position.
                if (c == '\n') 
                {   wr.write(v, p, i-p);
                    wr.write(eol);
                    p = i+1;
                    column = 0;
                }
// There is a delicacy here. If the user issues ('\r' '\n') rather than
// just '\n' I need to take action. What I do is to ignore the '\r' and
// map the '\n' onto a platform-specific end-of-line.
                else if (c == '\r')
                {   wr.write(v, p, i-p);
                    p = i+1;
                    column = 0;
                }
                else column++;
            }
            wr.write(v, p, v.length-p);
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
                    p = i+1;
                }
                else if (c == '\r')
                {   wr.write(v, p, i-p);
                    p = i+1;
                }
            }
            wr.write(v, p, v.length-p);
            wr.write(eol);
        }
        catch (IOException e)
        {}
        column = 0;
    }

}

// end of LispOutputStream.java


