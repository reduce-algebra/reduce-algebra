package uk.co.codemist.jlisp.core;


// $Id$


// amended 03/02/02 so that it actually does something

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
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

import java.io.*;

public class Method_info
{
    short access_flags;
    short name_index;
    short descriptor_index;
    short attributes_count = (short)1; //change to 2 if "Exceptions" included
    Attribute_info attributes[]; //should be [attributes_count]

    byte[] methodName;
    byte[] descriptor;

    void setAccess(short access)
    {
        access_flags = access;
    }

    void setName(String s) throws UnsupportedEncodingException
    {
        methodName = s.getBytes("UTF-8");
    }

    void setDescriptor(String s) throws UnsupportedEncodingException
    {
        descriptor = s.getBytes("UTF-8");
    }

    byte[] dumpBytes()
    {
        byte[][] Bytes = new byte[5][0];

        Bytes[0] = shortToByteArray(access_flags);
        Bytes[1] = shortToByteArray(name_index);
        Bytes[2] = shortToByteArray(descriptor_index);
        Bytes[3] = shortToByteArray(attributes_count);
				Bytes[4] = attToByteArray(attributes);
        
        int size = totalArraySize(Bytes);
        byte[] FlatBytes = new byte[size];
        return flatBytes(Bytes);
    }

    byte[] flatBytes(byte[][] DArray)
    {
        byte[] FlatBytes = new byte[totalArraySize(DArray)];

        int k=0;
        for (int i=0; i<DArray.length; i++)
            for (int j=0; j<DArray[i].length; j++)
                FlatBytes[k++] = DArray[i][j];
        return FlatBytes;
    }

    int totalArraySize(byte[][] Bytes)
    {
        int k=0;
        for (int i=0; i<Bytes.length; i++)
            k+=Bytes[i].length;
        return k;
    }


    public void printBytes(byte[] Bytes)
    {
        for (int i=0; i<Bytes.length; i++)
        {
            System.out.print(Integer.toHexString(Bytes[i] & 0xff) + " ");
            if (i%4 == 3) System.out.println();
        }
    }

    byte[] attToByteArray(Attribute_info[] ai)
    {
        byte[][] byteDArray = new byte[ai.length][];
        for (int i=0; i<ai.length; i++)
            byteDArray[i] = ai[i].dumpBytes();
        return flatBytes(byteDArray);
    }

    byte[] intToByteArray(int a)
    {
        byte[] byteArray = new byte[4];
        for (int i=3; i>=0; i--)
        {   byte b = (byte)(a >>> (8*(3-i)));
            byteArray[i] = b;
        }
        return byteArray;
    }

    byte[] shortToByteArray(short s)
    {
        byte[] byteArray = new byte[2];
        for (int i=1; i>=0; i--)
        {   byte b = (byte)(s >>> (8*(1-i)));
            byteArray[i] = b;
        }
        return byteArray;
    }



}

// need all fields for "methods" type and replace all methods with
// MethodDescription need to make same for attributes, fields
// maybe rename to something shorter e.g. or even just Methods,
// Fields, Attributes to correspond with the JVM spec:
// Method_info, field_info and attribute_info

// end of Method_info.java
