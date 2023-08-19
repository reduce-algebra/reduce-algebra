// multcounts.cpp                               Copyright (C) 2023 Codemist


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

// This reads a file of "multiplication count data" as generated when
// a version of CSL has been configured with the options
//           "--with-arithlib --enable-count-multiplication"
// which cause it to count every lisp-level call for multiplication and
// record the length (in 64-bit digits) of the two operands.
//
// I see this as a "jiffy program" rather than as a proper production
// utility, so it may be a bit fragile if faced with corrupt input!

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <cinttypes>

using namespace std;

// Usage:
//    multcounts <name of data file>

// The format of the data file is
//
//   ++ MultCounts ++                   A header line
//   biggest bignum: NN                 Digits in biggest bignum
//   fixnum*fixnum: NN MM               NN had fixnum result, MM=>bignum
//   data: NN
//   x, x, x, ... x,                    An NNxNN table of size as in the
//   x, x, x, ... x,                      "data:" line.
//   ...                                The entry at i,j is the number of
//   x, x, x, ... x,                    multiplications of an i digit value
//   ++ End of counts ++                by a j digit one. Length 0 is fixnum.

// The final row and column include counts for bignums longer than will
// fit exactly in the table.

int main(int argc, char* argv[])
{   ifstream data;
    if (argc > 1) data.open(argv[1]);
    else
    {   std::cerr << "Usage: multcounts <log-file-name>\n";
        return 1;
    }
    unsigned int tableSize;
    uint64_t small, large;
    vector<vector<uint64_t>> full;
    while (data)
    {   string s;
        if (!getline(data, s)) break;
        if (s.compare("") == 0) continue;
        if (s.compare("++ MultCounts ++") == 0) continue;
        unsigned int w;
        if (std::sscanf(s.c_str(), "biggest bignum: %u", &w) == 1)
        {   std::cout << "Biggest bignum multiplicand had " << w << " digits\n";
            continue;
        }
        if (std::sscanf(s.c_str(), "fixnum*fixnum: %" SCNu64 " %" SCNu64,
                        &small, &large) == 2)
        {   std::cout << "Multiplying fixnums => fixnum result " << small
                      << " times and => bignum in " << large
                      << " cases\n";
            continue;
        }
        if (std::sscanf(s.c_str(), "data: %u", &tableSize) != 1)
        {   std::cerr << "data file seems damaged or badly formatted\n";
            std::cerr << s << "\n";
            return 1;
        }
        break;
    }
    for (auto i=0; i<tableSize; i++)
    {   string s;
        if (!getline(data, s)) break;
        istringstream ss(s);
        vector<uint64_t> record;
        unsigned int onThisLine = 0; 
        for (string val; std::getline(ss, val, ','); )
        {   if (val.compare("") == 0 ||
                val.compare(" ") == 0) continue;
            record.push_back(stoll(val));
            onThisLine++;
            if (onThisLine > tableSize)
            {   std::cerr << "data file seems damaged or badly formatted\n";
                std::cerr << "too many numbers on this line\n";
                std::cerr << s << "\n";
                std::cerr << "expecting " << tableSize << "\n";
                return 1;
            }
        }
        if (onThisLine < tableSize)
        {   std::cerr << "data file seems damaged or badly formatted\n";
            std::cerr << "not enough numbers on this line\n";
            std::cerr << s << "\n";
            std::cerr << "expecting " << tableSize << "\n";
            return 1;
        }
        full.push_back(record);
    }

// Re-work the timimgs so that counts where M<N are transferred from (M,N)
// to (N,M).
    for (size_t i=0; i<tableSize; i++)
        for (size_t j=i+1; j<tableSize; j++)
        {   full[i][j] += full[j][i];
            full[j][i] = 0;
        }
// Collect totals where at least one argument is a fixnum or a 1-word bignum.
    uint64_t totalSmallCount=0, totalSmallCost=0;
    for (unsigned int i=0; i<2; i++)
        for (unsigned int j=0; j<tableSize; j++)
        {   totalSmallCount += full[i][j];
            totalSmallCost += max(1u,i)*max(1u,j)*full[i][j];
        }
// Collect total Count and Cost info. I will only add up cases where both
// inputs to the multiplication are bignums. Note that one-word bignums
// multiplied by anything at least as large will feature in this and
// also on the "fixnum or 1-word" report.
    uint64_t totalCount=0, totalCost=0;
    for (unsigned int i=1; i<tableSize; i++)
        for (unsigned int j=1; j<tableSize; j++)
        {   totalCount += full[i][j];
            totalCost += max(1u,i)*max(1u,j)*full[i][j];
        }
    if (totalCount == 0)
    {   cout << "No bignum multiplications used in this case!\n";
        return 0;
    }
    cout << "There were " << totalCount
         << " bignum multiplications at cost " << totalCost << "\n";
    cout << "and " << totalSmallCount
         << " single multiplications where one arg was short, at cost "
         << totalSmallCost << "\n";
    cout << "\nMultiplication by fixnum or 1-word bignum (value up to 2^63):\n";
    cout << scientific << setprecision(4);
    cout << " fixnum  "
            "    1    "
            "    2    "
            "    3    "
            "    4    "
            "    5    "
            "    6    "
            "    7\n";
    for (size_t i=0; i<8; i++)
    {   cout << setw(9) << fixed << setprecision(6)
             << (100.0*(full[i][0] + full[i][1])/totalSmallCount);
    }
    cout << "\n";
    cout << "  8-12   "
            "  13-16  "
            "  17-20  "
            "  21-24  "
            "  25-28  "
            "  29-32  "
            "  33-36  "
            "  37-40\n";
    for (size_t i=8; i<40; i+=4)
    {   uint64_t v = full[i][0]   + full[i][1] +
                     full[i+1][0] + full[i+1][1] +
                     full[i+2][0] + full[i+2][1] +
                     full[i+3][0] + full[i+3][1];
        cout << setw(9) << fixed << setprecision(6)
             << (100.0*v/totalSmallCost);
    }
    cout << "\n";
    uint64_t leftOverSmall = 0;
    for (size_t i=44; i<tableSize; i++)
        leftOverSmall += full[i][0] + full[i][1];
    if (leftOverSmall != 0)
        cout << "Plus " << leftOverSmall << " with bigger second operands\n";
    cout << "\nBignum multiplications counts as percentages of total\n";
    const char* labels[] =
    {   " 1-6 ",
        " 7-12",
        "13-18",
        "19-24",
        "25-30",
        "31-36",
        "37-42",
        "43-48",
    };
    cout << "       ";
    for (int i=0; i<8; i++) cout << "  " << labels[i] << "  ";
    cout << "\n";
    size_t labnum=0;
    for (size_t i=1; i<48; i+=6)
    {   cout << labels[labnum++] << ":";
        for (size_t j=1; j<48; j+=6)
        {   uint64_t v=0;
// I will use 6x6 buckets, so total up data from all involved.
            for (size_t ii=0; ii<6; ii++)
                for (size_t jj=0; jj<6; jj++)
                    v += full[i+ii][j+jj];
            if (i > j) cout << "         "; else
            cout << setw(9) << fixed << setprecision(5)
                 << ((100.0*v)/totalCount);
        }
        cout << "\n";
    }
    uint64_t leftOver = 0;
    for (size_t i=49; i<tableSize; i++)
        for (size_t j=i; j<tableSize; j++) leftOver += full[i][j];
    if (leftOver != 0)
        cout << "Plus " << leftOver << " with bigger bignums\n";
    cout << "\nEstimated bignum multiplications costs as percentages\n";
    cout << "       ";
    for (int i=0; i<8; i++) cout << "  " << labels[i] << "  ";
    cout << "\n";
    labnum = 0;
    for (size_t i=1; i<48; i+=6)
    {   cout << labels[labnum++] << ":";
        for (size_t j=1; j<48; j+=6)
        {   uint64_t v=0;
            for (size_t ii=0; ii<6; ii++)
                for (size_t jj=0; jj<6; jj++)
                    v += (i+ii)*(j+jj)*full[i+ii][j+jj];
            if (i > j) cout << "         "; else
            cout << setw(9) << fixed << setprecision(5)
                 << (100.0*v/totalCost);
        }
        cout << "\n";
    }

    cout << "\n==== end of report ====\n";
    return 0;
}

// end of multcounts.cpp
