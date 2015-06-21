package uk.co.codemist.jlisp.core;


// $Id$


// amended 02/02/02 so that it actually does something
// a lot of code simply copied over from Attribute_info
// maybe an idea to make all infos inherit from somewhere=>no copying
// maybe more efficient code that way, no duplicates of same code

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

public class Cp_info
{
    public static void main(String[] args) throws IOException,
                                                  ResourceException,
                                                  UnsupportedEncodingException
    {
        short cidx =    (short)0x4;
        short ntidx = (short)0xf;
        CONSTANT_Methodref_info cm = new CONSTANT_Methodref_info(cidx, ntidx);
        cm.printBytes(cm.dumpBytes());
        Jlisp.println("\n");
        
        short cidx2 =    (short)0x3;
        short ntidx2 = (short)0x10;
        CONSTANT_Methodref_info cm2 = new CONSTANT_Methodref_info(cidx2, ntidx2);
        cm2.printBytes(cm2.dumpBytes());
        Jlisp.println("\n");
        
        short index = (short)0x11;
        CONSTANT_Class_info ci = new CONSTANT_Class_info(index);
        ci.printBytes(ci.dumpBytes());
        Jlisp.println("\n");
        
        short index2 = (short)0x12;
        CONSTANT_Class_info ci2 = new CONSTANT_Class_info(index2);
        ci2.printBytes(ci2.dumpBytes());
        Jlisp.println("\n");
        
        String s = "<init>";
        CONSTANT_Utf8_info cu = new CONSTANT_Utf8_info(s);
        cu.printBytes(cu.dumpBytes());
        Jlisp.println("\n");
        
        String s1 = "()V";
        CONSTANT_Utf8_info cu1 = new CONSTANT_Utf8_info(s1);
        cu1.printBytes(cu1.dumpBytes());
        Jlisp.println("\n");
        
        String s2 = "Code";
        CONSTANT_Utf8_info cu2 = new CONSTANT_Utf8_info(s2);
        cu2.printBytes(cu2.dumpBytes());
        Jlisp.println("\n");
        
        String s3 = "LineNumberTable";
        CONSTANT_Utf8_info cu3 = new CONSTANT_Utf8_info(s3);
        cu3.printBytes(cu3.dumpBytes());
        Jlisp.println("\n");
        
        String s4 = "main";
        CONSTANT_Utf8_info cu4 = new CONSTANT_Utf8_info(s4);
        cu4.printBytes(cu4.dumpBytes());
        Jlisp.println("\n");
                
        String s5 = "([Ljava/lang/String;)V";
        CONSTANT_Utf8_info cu5 = new CONSTANT_Utf8_info(s5);
        cu5.printBytes(cu5.dumpBytes());
        Jlisp.println("\n");
        
        String s6 = "trivialMethod";
        CONSTANT_Utf8_info cu6 = new CONSTANT_Utf8_info(s6);
        cu6.printBytes(cu6.dumpBytes());
        Jlisp.println("\n");
        
        String s7 = "(I)I";
        CONSTANT_Utf8_info cu7 = new CONSTANT_Utf8_info(s7);
        cu7.printBytes(cu7.dumpBytes());
        Jlisp.println("\n");
        
        String s8 = "SourceFile";
        CONSTANT_Utf8_info cu8 = new CONSTANT_Utf8_info(s8);
        cu8.printBytes(cu8.dumpBytes());
        Jlisp.println("\n");
        
        String s9 = "Trivial.java";
        CONSTANT_Utf8_info cu9 = new CONSTANT_Utf8_info(s9);
        cu9.printBytes(cu9.dumpBytes());
        Jlisp.println("\n");
        
        short nidx =    (short)0x5;
        short didx =    (short)0x6;
        CONSTANT_NameAndType_info cnt = new CONSTANT_NameAndType_info(nidx,didx);
        cnt.printBytes(cnt.dumpBytes());
        Jlisp.println("\n");
        
        short nidx2 =    (short)0xb;
        short didx2 = (short)0xc;
        CONSTANT_NameAndType_info cnt2 = new CONSTANT_NameAndType_info(nidx2,didx2);
        cnt2.printBytes(cnt2.dumpBytes());
        Jlisp.println("\n");
        
        String s10 = "Trivial";
        CONSTANT_Utf8_info cu10 = new CONSTANT_Utf8_info(s10);
        cu10.printBytes(cu10.dumpBytes());
        Jlisp.println("\n");
        
        String s11 = "java/lang/Object";
        CONSTANT_Utf8_info cu11 = new CONSTANT_Utf8_info(s11);
        cu11.printBytes(cu11.dumpBytes());
        Jlisp.println("\n");
    }
    
    
    
    static final byte CONSTANT_Class                = 0x07;
    static final byte CONSTANT_Fieldref             = 0x09;
    static final byte CONSTANT_Methodref            = 0x0a;
    static final byte CONSTANT_InterfaceMethodref   = 0x0b;
    static final byte CONSTANT_String               = 0x08;
    static final byte CONSTANT_Integer              = 0x03;
    static final byte CONSTANT_Float                = 0x04;
    static final byte CONSTANT_Long                 = 0x05;
    static final byte CONSTANT_Double               = 0x06;
    static final byte CONSTANT_NameAndType          = 0x0c;
    static final byte CONSTANT_Utf8                 = 0x01;

    byte tag;
    byte info[];
        
    byte[] dumpBytes()
    {
        byte[][] Bytes = new byte[2][0];
        
        byte[] tagarray = new byte[1];
        tagarray[0]     = tag;
        Bytes[0]        = tagarray;
        Bytes[1]        = info;
            
        
        int size = totalArraySize(Bytes);
        byte[] FlatBytes = new byte[size];
        return flatBytes(Bytes);
    }
    
    byte[] flatBytes(byte[][] DArray)
    {            
        byte[] FlatBytes = new byte[totalArraySize(DArray)];
        
        int k=0;    
        for (int i=0; i<DArray.length; i++)
        {
            for (int j=0; j<DArray[i].length; j++)
                FlatBytes[k++] = DArray[i][j];
        }
        return FlatBytes;
    }
    
    int totalArraySize(byte[][] Bytes)
    {
        int k=0;
        for (int i=0; i<Bytes.length; i++)
            k+=Bytes[i].length;
        return k;
    }
    
    
    public void printBytes(byte[] Bytes) throws ResourceException
    {
        for (int i=0; i<Bytes.length; i++)
        {    
            int b = Bytes[i] & 0xff;
            if ((i+1)%8==0) //prints four bytes per line
                Jlisp.println(Integer.toHexString(b));
            else 
                Jlisp.print(Integer.toHexString(b)+ " ");
        }
    }
    
    byte[] intToByteArray(int a)
    {    
        byte[] byteArray = new byte[4];
                
        for (int i=3; i>=0; i--)
        {
            byte b = (byte)(a >>> (8*(3-i)));
            byteArray[i] = b;
        }
        return byteArray;
    }
    
    byte[] shortToByteArray(short s)
    {    
        byte[] byteArray = new byte[2];
        
        for (int i=1; i>=0; i--)
        {
            byte b = (byte)(s >>> (8*(1-i)));
            byteArray[i] = b;
        }
        return byteArray;
    }        
    
    
}

// end of Cp_info.java
