package uk.co.codemist.jlisp.core;


//04/03/02 for adding java/lang/Exception to Method_info
//note if more exceptions need adding...
//make a ByteArray.shortArrayToByteArray() for infotemp[1]

//Exceptions_attribute.java

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

public class Exceptions_attribute extends Attribute_info
{
   // short attribute_name_index;
   // int   attribute_length;
   // byte  info[];    //should be [attribute_length]

  short   number_of_exceptions = (short)1; //only ONE exception
	short[] exception_index_table = new short[number_of_exceptions];   
   
    void toInfo() throws IOException
    {
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = ByteArray.shortToByteArray(number_of_exceptions);
        infoTemp[1] = ByteArray.shortToByteArray(exception_index_table[0]);
        //assume only one entry in exception_table
        
        info = ByteArray.flatBytes(infoTemp);
        attribute_length = info.length;
    }
}

// end of Exceptions_attribute.java


	
	
	
	
	
	
	