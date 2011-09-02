//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class PDSInputStream extends InputStream
{

PDS pds;

long savedPosition;
int left;

PDSInputStream(PDS pds, String member) throws IOException
{
    this.pds = pds;
    if (pds == null || (pds.f == null && pds.data == null))
        throw new IOException("PDS member " + member + " not found"); 
    Object on = pds.directory.get(member);
    if (on == null)
        throw new IOException("PDS member " + member + " not found");
    left = ((PDSEntry)on).len;
    savedPosition = pds.getFilePointer();
    pds.seek((long)((PDSEntry)on).loc);
}

public int available()
{
    return left;
}

public void close() throws IOException
{
    pds.seek(savedPosition);
}

public boolean markSupported()
{
    return false;
}

public int read() throws IOException
{
    if (left <= 0) return -1;
    else
    {   left--;
        return pds.read();
    }    
}

public int read(byte [] b) throws IOException
{
    return read(b, 0, b.length);
}

public int read(byte [] b, int off, int len) throws IOException
{
    if (left <= 0) return -1;
    if (left < len) len = left;
    int n = pds.read(b, off, len);
    left -= n;
    return n;
}

}

// end of PDSInputStream.java

