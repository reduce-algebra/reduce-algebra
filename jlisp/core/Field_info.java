package uk.co.codemist.jlisp.core;


// 16/02/02 actually made to do something
// almost exactly identical to Method_info so may consider making a superclass
// and then subclassing Method_info and Field_info from it?

import java.io.*;

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
public class Field_info
{
    static short fields_count;

    short access_flags;
    short name_index;
    short descriptor_index;
    short attributes_count;
    Attribute_info attributes[];    // should be [attributes_count]

    byte[] fieldName;
    byte[] descriptor;

    void setAccess(short access)
    {
        access_flags = access;
    }

    void setName(String s) throws UnsupportedEncodingException
    {
        fieldName = s.getBytes("UTF-8");
    }

    void setDescriptor(String s) throws UnsupportedEncodingException
    {
        descriptor = s.getBytes("UTF-8");
    }

    byte[] dumpBytes()
    {
        byte[][] Bytes = new byte[5][0];
        Bytes[0] = ByteArray.shortToByteArray(access_flags);
        Bytes[1] = ByteArray.shortToByteArray(name_index);
        Bytes[2] = ByteArray.shortToByteArray(descriptor_index);
        Bytes[3] = ByteArray.shortToByteArray(attributes_count);
        Bytes[4] = ByteArray.attToByteArray(attributes);
        return ByteArray.flatBytes(Bytes);
    }

}

// end of Field_info.java
