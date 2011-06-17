// Gzip implementation for J2ME
// Copyright 2011 Igor Gatis  All rights reserved.
// http://code.google.com/p/compress-j2me/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Google Inc. nor the names of its contributors may
//       be used to endorse or promote products derived from this software
//       without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
package org.mathpiper.mpreduce.zip;

import java.io.IOException;
import org.mathpiper.mpreduce.io.streams.InputStream;
import org.mathpiper.mpreduce.zip.GZIPInputStream.SimpleOutputStream;

public class Gzip {

    private String filename;
    private String comment;
    private int litLenCode = 0;
    private int[] litLenTree;
    private int[] distTree;
    private ZStream in;
    private ZStream out;
    public boolean chooseBlockMode = true;
    private boolean finalBlock;


    private Gzip() {
    }


    public Gzip(InputStream in, SimpleOutputStream out) {
        this.in = new ZStream(in, false, 0);
        this.out = new ZStream(out, true, INFLATE_WINDOW_BITS);
    }


    public String getFilename() {
        return filename;
    }


    public String getComment() {
        return comment;
    }

    //---------------------------------------------------------------------------
    // Inflate specific.
    //---------------------------------------------------------------------------
    private final byte BTYPE_NO_COMPRESSION = 0x00;
    private final byte BTYPE__HUFFMAN = 0x01;
    private final byte BTYPE_DYNAMIC_HUFFMAN = 0x02;
    private final byte BTYPE_RESERVED = 0x03;
    private final int INFLATE_WINDOW_BITS = 15;
    final int DEFLATE_HASH_SIZE = 1 << 11;
    private final int DEFLATE_WINDOW_BITS = 11;
    final int MAX_DEFLATE_DISTANCE = 1 << DEFLATE_WINDOW_BITS;
    final int MAX_DEFLATE_LENGTH = 256;


    private void inflateRawBlock() throws IOException {
        int len = in.readLittleEndian(2);
        int nlen = in.readLittleEndian(2);
        if ((len ^ nlen) != 0xFFFF) {
            throw new IOException("Invalid block.");
        }
        while (len-- > 0) {
            int ch = in.read();
            if (ch < 0) {
                throw new IOException("Unexpected EOF.");
            }
            out.write(ch);
        }
    }


    void inflateNextStep() throws IOException {
        litLenCode = Huffman.decodeSymbol(in, litLenTree);

        if(litLenCode == Huffman.END_OF_BLOCK_CODE)
        {
            this.chooseBlockMode = true;
            return;
        }

            if (litLenCode < Huffman.END_OF_BLOCK_CODE) {
                out.write(litLenCode);
            } else {
                if (distTree == null) {
                    throw new IOException("no distance tree");
                }
                int length = Huffman.decodeLength(litLenCode, in);
                int distCode = Huffman.decodeSymbol(in, distTree);
                int distance = Huffman.decodeDistance(distCode, in);
                //System.out.println("d=" + distance + ",l=" + length);
                out.copyFromEnd(distance, length);

                
            }

    }


    private void inflateHuffman() throws IOException {

        litLenCode = 0;

        this.chooseBlockMode = false;


    }


    private void inflateDynamicHuffman()
            throws IOException {
        int hlit = in.readBits(5) + 257;
        int hdist = in.readBits(5) + 1;
        int hclen = in.readBits(4) + 4;

        // Build tree which will be used to decode lengths for nodes of
        // literal/length and distance trees.
        // Will read 4-19 items. Each item ranges from 0 to 7 (3 bits).
        char[] hcLengths = new char[19];
        for (int i = 0; i < hclen; i++) {
            hcLengths[Huffman.HC_PERM[i]] = (char) in.readBits(3);
        }
        int[] hcTree = Huffman.buildCodeTree(7, hcLengths);

        char[] litCodeLens = Huffman.readLengths(in, hcTree, hlit);
        litLenTree = Huffman.buildCodeTree(15, litCodeLens);

        char[] distCodeLens = Huffman.readLengths(in, hcTree, hdist);
        distTree = null;
        // Check corner case where there are only literals and no lengths.
        if (distCodeLens.length != 1 || distCodeLens[0] != 0) {
            distTree = Huffman.buildCodeTree(15, distCodeLens);
        }
        inflateHuffman();
    }


    boolean inflateBlockStep() throws IOException {

        finalBlock = in.readBits(1) != 0;
        int blockType = in.readBits(2);
        switch (blockType) {
            case BTYPE_NO_COMPRESSION:
                in.alignInputBytes(); // Discard the rest of header.
                inflateRawBlock();
                break;
            case BTYPE__HUFFMAN:
                litLenTree = Huffman.CANONICAL_LITLENS_TREE;
                distTree = Huffman.CANONICAL_DISTANCES_TREE;
                inflateHuffman();
                break;
            case BTYPE_DYNAMIC_HUFFMAN:
                inflateDynamicHuffman();
                break;
            default:
            case BTYPE_RESERVED:
                throw new IOException("Invalid block.");
        }

        return finalBlock;
    }


    public long endInflate() throws IOException {

        in.alignInputBytes();
        return out.getSize();
    }


    /*public  long inflate(InputStream in, OutputStream out) throws IOException {
    Gzip.in = new ZStream(in, false, 0);
    Gzip.out = new ZStream(out, true, INFLATE_WINDOW_BITS);
    return inflate();
    }*/
    //---------------------------------------------------------------------------
    // Gunzip specific.
    //---------------------------------------------------------------------------
    Gzip readHeader() throws IOException {
        Gzip gzip = new Gzip();
        in.resetCrc();
        if (in.readLittleEndian(2) != ZStream.GZIP_MAGIC_NUMBER) {
            throw new IOException("Bad magic number");
        }
        if (in.readLittleEndian(1) != ZStream.CM_DEFLATE) {
            throw new IOException("Unsupported compression method");
        }
        int flg = in.readLittleEndian(1);
        // mtime=4, xfl=1, os=1
        in.skipBytes(6);
        if ((flg & ZStream.FEXTRA) != 0) {
            int xlen = in.readLittleEndian(2);
            while (xlen-- > 0) {
                in.read();
            }
        }
        if ((flg & ZStream.FNAME) != 0) {
            gzip.filename = in.readZeroTerminatedString();
        }
        if ((flg & ZStream.FCOMMENT) != 0) {
            gzip.comment = in.readZeroTerminatedString();
        }
        if ((flg & ZStream.FHCRC) != 0) {
            int headerCrc16 = in.getCrc() & 0xFFFF;
            int expectedHeaderCrc16 = in.readLittleEndian(2);
            if (expectedHeaderCrc16 != headerCrc16) {
                throw new IOException("Header CRC check failed.");
            }
        }
        in.setKeepCrc(false);
        return gzip;
    }


    void readFooter() throws IOException {
        int actualCrc = out.getCrc();
        int expectedCrc = in.readLittleEndian(4);
        if (expectedCrc != actualCrc) {
            throw new IOException("CRC check failed.");
        }
        int actualSize = out.getSize();
        int expectedSize = in.readLittleEndian(4);
        if ((actualSize & 0xFFFFFFFF) != expectedSize) {
            throw new IOException("Size mismatches.");
        }
    }


    void resetCrc() {
        this.out.resetCrc();
    }


}//end class.
