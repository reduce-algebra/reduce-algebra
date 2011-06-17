package org.mathpiper.mpreduce.base64;

/*
 * Licence (BSD):
 * ==============
 *
 * Copyright (c) 2004, Mikael Grev, MiG InfoCom AB. (base64 @ miginfocom . com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 * Neither the name of the MiG InfoCom AB nor the names of its contributors may be
 * used to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;

/**
 * Base64 for InputStream<br/> Licence = BSD
 *
 * @see Base64
 * @author shamilbi shamilbi@users.sourceforge.net
 */
public class Base64IO {

    private static final byte[] CA = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".getBytes();
    private static final int _8_BIT = 0xff;
    private static final int _6_BIT = 0x3f;
    private static final byte EQUAL = '=';


    /**
     * Encodes a raw InputStream into a BASE64 OutputStream representation in
     * accordance with RFC 2045. This implementation was inspired by MIG Base64
     * {@link Base64#encodeToByte(byte[], boolean)}
     *
     * @param in
     * @param out
     * @param lineSep
     *            Optional "\r\n" after 76 characters, unless end of file.<br>
     *            No line separator will be in breach of RFC 2045 which
     *            specifies max 76 per line but will be a little faster.
     * @throws IOException
     */
    public final static void encode(java.io.InputStream in, OutputStream out,
            boolean lineSep) throws IOException {
        // must be inBuf.length % 3 == 0
        final byte[] inBuf = new byte[1024 * 32 * 3];
        final byte[] outBuf = new byte[4 * 19 + 2];

        int eLen = inBuf.length; // Length of even 24-bits.
        int left = 0;
        int inOff = 0;
        boolean needsRn = false;
        int cc = 0;

        while (true) {
            // read full buffer
            final int read = in.read(inBuf, inOff, inBuf.length - inOff);

            if (read == -1) {
                // last bytes
                left = inOff % 3; // 0 - 2.
                eLen = inOff - left; // Length of even 24-bits.
            } else {
                inOff += read;
                if (inOff != inBuf.length) {
                    continue;
                }
            }

            int outOff = 0;

            // encode buffer
            // Encode even 24-bits

            for (int s = 0/* , d = 0, cc = 0 */; s < eLen;) {
                if (needsRn) {
                    outBuf[outOff++] = '\r';
                    outBuf[outOff++] = '\n';
                    needsRn = false;
                }

                // Copy next three bytes into lower 24 bits of int, paying
                // attension to sign.
                int i = (inBuf[s++] & _8_BIT) << 16
                        | (inBuf[s++] & _8_BIT) << 8 | (inBuf[s++] & _8_BIT);

                // Encode the int into four chars
                int outOff2 = outOff += 4;
                outBuf[--outOff2] = CA[i & _6_BIT];
                outBuf[--outOff2] = CA[(i >>>= 6) & _6_BIT];
                outBuf[--outOff2] = CA[(i >>>= 6) & _6_BIT];
                outBuf[--outOff2] = CA[(i >>>= 6) & _6_BIT];

                if (++cc == 19 /* && d < dLen - 2 */) {
                    cc = 0;
                    out.write(outBuf, 0, outOff);
                    outOff = 0;

                    // Add optional line separator
                    if (lineSep) {
                        needsRn = true;
                    }
                }
            }
            out.write(outBuf, 0, outOff);

            // Pad and encode last bits if source isn't an even 24 bits.
            if (left > 0) {
                // Prepare the int
                int i = ((inBuf[eLen] & _8_BIT) << 10)
                        | (left == 2 ? ((inBuf[inOff - 1] & _8_BIT) << 2) : 0);

                // Set last four chars
                outBuf[3] = EQUAL;
                outBuf[2] = left == 2 ? CA[i & _6_BIT] : EQUAL;
                outBuf[1] = CA[(i >>>= 6) & _6_BIT];
                outBuf[0] = CA[i >> 6];
                out.write(outBuf, 0, 4);
            }

            if (read == -1) {
                break;
            }

            // new block
            inOff = 0;
        }
    } //end method.


    public static void main(String[] args) {

        //Create base64 file.
        FileInputStream fileIn;
        FileOutputStream fileOut;
        try {
            fileIn = new FileInputStream("minireduce.img");
            fileOut = new FileOutputStream("minireduce.base64");
            Base64IO.encode(fileIn, fileOut, true);
            fileIn.close();
            fileOut.close();
        } catch (Exception e) {
            e.printStackTrace();
        }


        //Create Java class that contains base64 encoded strings.
        try {
            BufferedReader in = new BufferedReader(new FileReader("minireduce.base64"));

            FileWriter out = new FileWriter("ReduceImageInputStream.java");


            String topOfClass =
                    "package org.mathpiper.mpreduce;\n"
                    + "\n"
                    + "import java.io.IOException;\n"
                    + "import org.mathpiper.mpreduce.io.streams.InputStream;\n"
                    + "import org.mathpiper.mpreduce.base64.Base64;\n"
                    + "\n"
                    + "public class ReduceImageInputStream extends InputStream {\n"
                    + "\n"
                    + "    private int stringSelector = 0;\n"
                    + "\n"
                    + "    private int byteIndex = -1;\n"
                    + "\n"
                    + "    private byte[] bytes = null;\n"
                    + "\n"
                    + "    private boolean emptyFlag = false;\n"
                    + "\n"
                    + "    public ReduceImageInputStream()\n"
                    + "    {\n"
                    + "        bytes = Base64.decode(reduceImage[stringSelector]);\n"
                    + "    }\n"
                    + "\n"
                    + "    public int read() throws IOException {\n"
                    + "\n"
                    + "        if(emptyFlag == true)\n"
                    + "        {\n"
                    + "            return -1;\n"
                    + "        }\n"
                    + "\n"
                    + "        byteIndex++;\n"
                    + "\n"
                    + "        if(byteIndex == bytes.length)\n"
                    + "        {\n"
                    + "            if(stringSelector != reduceImage.length - 1)\n"
                    + "            {\n"
                    + "                byteIndex = 0;\n"
                    + "\n"
                    + "                stringSelector++;\n"
                    + "\n"
                    + "                bytes = Base64.decodeFast(reduceImage[stringSelector]);\n"
                    + "            }\n"
                    + "            else\n"
                    + "            {\n"
                    + "                emptyFlag = true;\n"
                    + "\n"
                    + "                return -1;\n"
                    + "            }\n"
                    + "        }//end if.\n"
                    + "\n"
                    + "        int character = 0;\n"
                    + "\n"
                    + "        character = bytes[byteIndex] & 0xff;\n"
                    + "\n"
                    + "        return character;\n"
                    + "\n"
                    + "    }//end read.\n"
                    + "\n"
                    + "\n"
                    + "public String[] reduceImage = new String[] {\n";

            out.write(topOfClass);

            int stringLineCount = 0;

            String line;

            while ((line = in.readLine()) != null) {

                line = "\"" + line + "\"";

                out.write(line);

                if (stringLineCount++ == 30) {
                    stringLineCount = 0;

                    out.write(",\n");
                } else {
                    out.write(" +\n");
                }

            }//end while.

            out.write("\"\" };\n}");


            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }//end method.

}//end class.

