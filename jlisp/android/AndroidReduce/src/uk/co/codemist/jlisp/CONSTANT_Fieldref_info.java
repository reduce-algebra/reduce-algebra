package uk.co.codemist.jlisp;


//created 20/02/02 since it wasn't needed for Trivial.java
// exactly same as CONSTANT_Methodref_info with "Method" replaced by "Field"

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

public class CONSTANT_Fieldref_info extends Cp_info
{
    public static void main(String[] args) throws IOException, ResourceException
    {
        short cidx = (short)0x4;
        short ntidx = (short)0xf;
        CONSTANT_Fieldref_info cm = new CONSTANT_Fieldref_info(cidx, ntidx);
        cm.printBytes(cm.dumpBytes());
        Jlisp.println("\n");
                
        short cidx2 =        (short)0x3;
        short ntidx2 = (short)0x10;
        CONSTANT_Fieldref_info cm2 = new CONSTANT_Fieldref_info(cidx2, ntidx2);
        cm2.printBytes(cm2.dumpBytes());
        Jlisp.println("\n");
    }
        
    short class_index;
    short name_and_type_index;
                

    //constructor
    CONSTANT_Fieldref_info(short classIndex, short ntIndex)
        throws IOException
    {   tag = CONSTANT_Fieldref;        
        class_index = classIndex;
        name_and_type_index = ntIndex;
        //below is the toInfo() method of Code_Attribute.java
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = shortToByteArray(class_index);
        infoTemp[1] = shortToByteArray(name_and_type_index);
                                
        info = new byte[4];
        info = flatBytes(infoTemp);
    }
}

// end of CONSTANT_Fieldref_info.java
