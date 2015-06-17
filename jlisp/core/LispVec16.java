package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id: LispVector.java 3127 2015-06-11 16:17:22Z arthurcnorman $


import java.io.*;

class LispVec16 extends LispObject
{
    short [] vec;

    LispVec16(int n)
    {
        vec = new short [n];
        for (int i=0; i<n; i++) vec[i] = 0;
    }

    LispVec16(short [] v)
    {
        vec = v;
    }

    LispObject eval()
    { 
        return this; 
    }

    void iprint() throws ResourceException
    {
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 4 > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print("#V16(");
        if (vec.length == 0)
	{   if ((currentFlags & noLineBreak) == 0 &&
                currentOutput.column + 1 > currentOutput.lineLength)
                currentOutput.println();
            currentOutput.print(")");
            return;
        }
        String s = String.format("%d", vec[0]);
        if ((currentFlags & noLineBreak) == 0 &&
                currentOutput.column + s.length() > currentOutput.lineLength)
                currentOutput.println();
        currentOutput.print(s);
        for (int i=1; i<vec.length; i++)
	{   if ((currentFlags & noLineBreak) == 0 &&
                currentOutput.column + 1 > currentOutput.lineLength)
                currentOutput.println();
            else currentOutput.print(" ");
            String s1 = String.format("%d", vec[i]);
            if ((currentFlags & noLineBreak) == 0 &&
                    currentOutput.column + s1.length() > currentOutput.lineLength)
                    currentOutput.println();
            currentOutput.print(s1);
        }
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 1 > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(")");
    }

    void blankprint() throws ResourceException
    {
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + 1 >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        iprint();
    }

    public boolean lispequals(Object b)
    {
        if (!(b instanceof LispVec16)) return false;
        if (b == this) return true;
        LispVec16 vb = (LispVec16)b;
        if (vec.length != vb.vec.length) return false;
        for (int i=0; i<vec.length; i++)
            if (vec[i] != vb.vec[i]) return false;
        return true;
    }

    public boolean equals(Object b)
    {
        return lispequals(b);
    }

    public int lisphashCode()
    {
        int r = 33;
        for (int i=0; i<vec.length; i++) 
	{   int b = vec[i];
            r = 0x16421*r + 163*b;
        }
        return r;  
    }

    public int hashcode()
    {
        return lisphashCode();
    }

    void scan()
    {
        if (Jlisp.objects.contains(this)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(this))
	    {   Jlisp.repeatedObjects.put(
	            this,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else Jlisp.objects.add(this);
    }

    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            this,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(LispObject.X_STORE);
            }
	    int length = vec.length;
	    putPrefix(length, LispObject.X_VECxx);
            int n = vec.length + (LispObject.XX_VEC16 << 29);
            Jlisp.odump.write(n);
            Jlisp.odump.write(n>>8);
            Jlisp.odump.write(n>>16);
            Jlisp.odump.write(n>>24);
	    for (int i=0; i<vec.length; i++)
            {   Jlisp.odump.write(vec[i]);
	        Jlisp.odump.write(vec[i]>>8);
            }
	}
    }


}

// end of LispVec16.java

