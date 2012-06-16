package uk.co.codemist.jlisp;


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

public class CONSTANT_NameAndType_info extends Cp_info
{
    public static void main(String[] args) throws IOException, ResourceException
    {
        short nidx = (short)0x5;
        short didx = (short)0x6;
        CONSTANT_NameAndType_info cnt =
            new CONSTANT_NameAndType_info(nidx,didx);
        cnt.printBytes(cnt.dumpBytes());
        Jlisp.println("\n");
        
        short nidx2 = (short)0xb;
        short didx2 = (short)0xc;
        CONSTANT_NameAndType_info cnt2 =
            new CONSTANT_NameAndType_info(nidx2,didx2);
        cnt2.printBytes(cnt2.dumpBytes());
        Jlisp.println("\n");
        
    }
    
    short name_index;
    short descriptor_index;
    

    //constructor
    CONSTANT_NameAndType_info(short nameIndex, short desIndex)
                             throws IOException
    {    tag = CONSTANT_NameAndType;    
        name_index = nameIndex;
        descriptor_index = desIndex;
        //below is the toInfo() method of Code_Attribute.java
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = shortToByteArray(name_index);
        infoTemp[1] = shortToByteArray(descriptor_index);
                
        info = new byte[4];
        info = flatBytes(infoTemp);
    }
    
}


// end of CONSTANT_NameAndType_info.java
