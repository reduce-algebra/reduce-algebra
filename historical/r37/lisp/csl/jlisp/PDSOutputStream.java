//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;
import java.util.*;

class PDSOutputStream extends OutputStream
{

PDS pds;
String member;
int length;

long savedPosition;

PDSOutputStream(PDS pds, String member) throws IOException
{
    this.pds = pds;
    this.member = member;
    if (pds.f != null) savedPosition = pds.f.getFilePointer();
    else savedPosition = -1;
    if (pds.memberData != 0)
        throw new IOException("Attempt to have two output files open in one PDS");
    pds.addToDirectory(member);
    length = 0;
}

public void close() throws IOException
{
    if (pds == null) return;
Jlisp.println("at close member: length = " + length + " memberData = " + pds.memberData);
    pds.f.seek(pds.memberData);
    pds.f.write(pds.memberStart >> 24);
    pds.f.write(pds.memberStart >> 16);
    pds.f.write(pds.memberStart >> 8);
    pds.f.write(pds.memberStart);
    pds.f.write(length >> 24);
    pds.f.write(length >> 16);
    pds.f.write(length >> 8);
    pds.f.write(length);
    long date = new Date().getTime();
    pds.f.write((int)(date >> 56));
    pds.f.write((int)(date >> 48));
    pds.f.write((int)(date >> 40));
    pds.f.write((int)(date >> 32));
    pds.f.write((int)(date >> 24));
    pds.f.write((int)(date >> 16));
    pds.f.write((int)(date >> 8));
    pds.f.write((int)date);
    pds.memberData = 0;
    pds.directory.put(member,
        new PDSEntry(member, pds.memberStart, length, date));
    if (savedPosition >= 0) pds.f.seek(savedPosition);
    pds = null;
}

public void write(int c) throws IOException
{
    pds.f.write(c);
    length++;
}

}

// end of PDSInputStream.java


