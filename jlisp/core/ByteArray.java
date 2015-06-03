package uk.co.codemist.jlisp.core;


/* $Id$ */


// Convert basic datatypes into byte arrays etc

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

abstract class ByteArray
{

static int totalArraySize(byte[][] Bytes)
{
    int k=0;
    for (int i=0; i<Bytes.length; i++)
        k+=Bytes[i].length;
    return k;
}

static byte[] flatBytes(byte[][] array_2d)
{
    byte[] array_1d = new byte[totalArraySize(array_2d)];
    int k=0;
    for (int i=0; i<array_2d.length; i++)
    {
        for (int j=0; j<array_2d[i].length; j++)
            array_1d[k++] = array_2d[i][j];
    }
    return array_1d;
}

static void printBytes(byte[] Bytes)
{
    for (int i=0; i<Bytes.length; i++)
    {   int n = Bytes[i] & 0xff;
        if (n < 16) System.out.print("0" + Integer.toHexString(n));
        else System.out.print(Integer.toHexString(n));
        if (i%4 == 3) System.out.println();
        else System.out.print(" ");
    }
    System.out.println();
}

static byte[] intToByteArray(int a)
{
    return new byte[] 
        {(byte)(a>>24), (byte)(a>>16), (byte)(a>>8), (byte)a};
//      {(byte)a, (byte)(a>>8), (byte)(a>>16), (byte)(a>>24)};
}

static byte[] shortToByteArray(short s)
{
    return new byte[]
        {(byte)(s>>8), (byte)s};
}

static byte[] byteToByteArray(byte b)
{
    return new byte[] {b};
}

static byte[] attToByteArray(Attribute_info[] ai)
{
    byte[][] byteDArray = new byte[ai.length][];
    for (int i=0; i<ai.length; i++)
        byteDArray[i] = ai[i].dumpBytes();
    return flatBytes(byteDArray);
}

static byte[] cpToByteArray(Cp_info[] cpi)
{
    byte[][] byteDArray = new byte[cpi.length][];
    for (int i=0; i<cpi.length; i++)
        byteDArray[i] = cpi[i].dumpBytes();
    return flatBytes(byteDArray);
}

static byte[] miToByteArray(Method_info[] mi)
{
    byte[][] byteDArray = new byte[mi.length][];
    for (int i=0; i<mi.length; i++)
        byteDArray[i] = mi[i].dumpBytes();
    return flatBytes(byteDArray);
}

static byte[] fiToByteArray(Field_info[] fi)
{
    byte[][] byteDArray = new byte[fi.length][];
    for (int i=0; i<fi.length; i++)
        byteDArray[i] = fi[i].dumpBytes();
    return flatBytes(byteDArray);
}


}

// end of ByteArray.java
