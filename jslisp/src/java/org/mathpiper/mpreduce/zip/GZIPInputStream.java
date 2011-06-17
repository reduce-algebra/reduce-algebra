/**************************************************************************
 * Copyright (C) 2011 Ted Kosan                                           *
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
package org.mathpiper.mpreduce.zip;

import java.io.IOException;
import org.mathpiper.mpreduce.io.streams.InputStream;
import java.io.OutputStream;

public class GZIPInputStream extends InputStream {

    private Gzip gzip;
    private byte[] buffer;
    private int tail;
    private int head;


    public GZIPInputStream(InputStream input) {

        buffer = new byte[3000];
        tail = 0;
        head = 0;



        gzip = new Gzip(input, new SimpleOutputStream());

        try {
            gzip.readHeader();
            gzip.resetCrc();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }


    public int read() throws IOException {


        if(tail != head)
        {
            return getByte() & 0xff;
        }


        if (gzip.chooseBlockMode == true) {
            gzip.inflateBlockStep();
        }

        gzip.inflateNextStep();

        if (gzip.chooseBlockMode == true ) {
            gzip.inflateBlockStep();
            gzip.inflateNextStep();
        }


        int nextByte = getByte() & 0xff;

        return nextByte;
    }


    public void addByte(byte toAdd) throws IOException
    {
        if (head != (tail - 1)) {
            buffer[head++] = toAdd;
        } else {
            throw new IOException("Buffer overflow.");
        }
        head = head % buffer.length;
    }


    private byte getByte() throws IOException
    {
        byte t = 0;
        int adjTail = tail > head ? tail - buffer.length : tail;
        if (adjTail < head) {
            t = buffer[tail++];
            tail = tail % buffer.length;
        } else {
            throw new IOException("Buffer underflow.");
        }
        return t;
    }

    
    public void close() throws IOException
    {
        gzip.endInflate();
    }

    
    public class SimpleOutputStream extends OutputStream {

        public void write(int b) throws IOException {
            addByte((byte) b);
        }

        public void flush()
        {
            
        }

    }//End class SimpleOutputStream.






}//End class GZIPInputStream.
