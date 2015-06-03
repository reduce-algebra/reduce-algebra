package uk.co.codemist.jlisp.core;


/* $Id$ */


//created 02/02/02

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

public class CONSTANT_Utf8_info extends Cp_info
{
    public static void main(String[] args)
                       throws IOException, UnsupportedEncodingException,
                              ResourceException
    {
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
            
        String s10 = "Trivial";
        CONSTANT_Utf8_info cu10 = new CONSTANT_Utf8_info(s10);
        cu10.printBytes(cu10.dumpBytes());
        Jlisp.println("\n");
        
        String s11 = "java/lang/Object";
        CONSTANT_Utf8_info cu11 = new CONSTANT_Utf8_info(s11);
        cu11.printBytes(cu11.dumpBytes());
        Jlisp.println("\n");
        
    }
        
    
    short length;
    byte bytes[];    //should be [length]
    
    //constructor
    CONSTANT_Utf8_info(String s)
        throws IOException, UnsupportedEncodingException
    {   tag = CONSTANT_Utf8;
        bytes = s.getBytes("UTF-8");
        length = (short)bytes.length;
        
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = shortToByteArray(length);
        infoTemp[1] = bytes;
        
        info = new byte[totalArraySize(infoTemp)];
        info = flatBytes(infoTemp);
    }
    
}

// end of CONSTANT_Utf8_info.java
