// make-image.cpp                               Copyright (C) 2023 Codemist


// $Id$


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

// This is a jiffy program that turns a (binary) file into C++ source
// code that defined a potentially huge data array containing the contents
// of the original file. This array is one of 64-bit integers and on a
// little-endian system is liable to be a binary match for the original
// data. The array pads the data will zero bytes to be a multiple of 8
// bytes in all.
// Usage:
//    make-image [source-file [destination-file [array-name]]]
// where the defaults are
//    make-image reduce.img image.cpp image_file


// #include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <cctype>
#include <cstdint>
#include <ctime>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>

using std::cerr;
using std::ifstream;
using std::ofstream;

int main(int argc, char *argv[])
{
    const char *src = "reduce.img";
    const char *dest = "image.cpp";
    const char *arrayname = "image_file";
    switch (argc)
    {
    case 4:
        arrayname = argv[3];
    case 3:
        dest = argv[2];
    case 2:
        src = argv[1];
        if (strcmp(argv[1], "--help") != 0) break;
    default:
        cerr <<
            "Usage: " << argv[0] << " [source-file [destination-file [array-name]]]\n";
        cerr <<
            "default: " << argv[0] << " reduce.img image.cpp image_file\n";
        std::exit(1);
    case 1:
        break;
    }
    ifstream instream;
    ofstream outstream;
    instream.open(src, std::ios::in|std::ios::binary);
    if (!instream.good())
    {   cerr << "Failed to open input file " << src << "\n";
        std::exit(1);
    }
    outstream.open(dest, std::ios::out);
    if (!outstream.good())
    {   cerr << "Failed to open output file " << dest << "\n";
        std::exit(1);
    }
    time_t tt = time(NULL);
    struct tm ttt = *localtime(&tt);
    const char *tts = asctime(&ttt);
    outstream << "// " << dest << " (for " << src << ") created " << tts << "\n";
    outstream << "\n#include <stdint.h>\n";
    outstream << "\nconst uint64_t " << arrayname << "[] = {\n";
    outstream << "#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n";
    uint64_t w = 0;
    size_t i = 0;
    uint64_t currentLine[4];
    outstream << std::hex << std::setfill('0');
    for (;;)
    {   uint64_t c = instream.get() & 0xff;
        if (instream.eof()) break;
        w = w | (c << (8*(7-(i&7))));
        if ((i&31) == 31)
        {   outstream << "0x"  << std::setw(16) << w << ",\n";
            currentLine[3] = w;
            if (i < 160)
            {   outstream << "//";
                for (int j=0; j<4; j++)
                {   if (j != 0) outstream << "    ";
                    w = currentLine[j];
                    for (int k=0; k<8; k++)
                    {   int b = (w >> (8*(7-k))) & 0xff;
                        if (0x20 <= b && b < 0x7f)
                            outstream << " " << static_cast<char>(b);
                        else outstream << std::setw(2) << b;
                    }
                }
                outstream << "\n";
            }
            w = 0;
        }
        else if ((i&7) == 7)
        {   outstream << "0x"  << std::setw(16) << w << ", ";
            currentLine[((i-7)/8)%4] = w;
            w = 0;
        }
        i++;
    }
    outstream << "0x"  << std::setw(16) << w << "\n};\n";
    outstream << "#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__\n";
    instream.clear();
    instream.seekg(0);
    w = 0;
    i = 0;
    for (;;)
    {   uint64_t c = instream.get() & 0xff;
        if (instream.eof()) break;
        w = w | (c << (8*(i&7)));
        if ((i&31) == 31)
        {   outstream << "0x"  << std::setw(16) << w << ",\n";
            w = 0;
        }
        else if ((i&7) == 7)
        {   outstream << "0x"  << std::setw(16) << w << ", ";
            w = 0;
        }
        i++;
    }
    outstream << "0x"  << std::setw(16) << w << "\n};\n";
    outstream << "#else\n";
    outstream << "#error Byte ordering for target machine unknown.\n";
    outstream << "#endif\n\n";
    outstream << "const unsigned char *reduce_image =\n";
    outstream <<
    "   reinterpret_cast<const unsigned char *>(&" << arrayname << "[0]);\n";
    outstream << "#define REDUCE_IMAGE_SIZE " << std::dec << i << "\n\n";

    outstream << "// End of " << dest << "\n";
    instream.close();
    outstream.close();
    return 0;
}

// end of make-image.c
