// getargs.h                                    Copyright (C) 2019 Codemist

// $Id$


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

// I have transcribed the code from here into the file csl.cpp, but keep
// this separate version because I may want it in some other program or
// project.


// Usage:
//   void setupArgs(argSpec vec[], int argc, const char *argv[]);
// where vec is a vector whose elements esch specify a possible argument
// format and provide an action to perform if it is seen in
// argv.
//


// Arguments of the form "-x" for any single letter x might have an
// associated value which can be written as either "-xVAL" or "-x VAL".
// Arguments written in the form "--word" can have an associated value
// either as "--word=VAL" or "--word VAL".
// As a special case "--args" terminates scanning.

#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

typedef void argAction(std::string key, bool takesVal, std::string value);

struct argSpec
{   const char *name;      // e.g. "-k"
    bool takesVal;         // true if either "-k NN" or "-k=NN" will be valid
    std::string help;      // e.g. "-k NN: set memory allocation to NN"
    std::function<void(std::string,bool,std::string)>action;
                           // procedure to call when this case arises.
};

static std::unordered_map<std::string, argSpec *> argIndex;

// All command-line items that do not begin with "-" are collected in the
// vector simpleArgs[]. They will be treated as names of files to be
// read from. Also an isolated "-" is treated this way so it can be used
// to indicate a default file-name, as in "-I -".

static std::vector<std::string> simpleArgs;

// If an item is not recognized I will collect it here. This will also
// apply if an item does not expect an associated value but is provided
// with one. If an item is expecting a value but nothing is provided it
// will just use the empty string "".

static std::vector<std::string> badArgs;

void setupArgs(argSpec *v, int argc, const char *argv[])
{   argIndex.clear(); // Just to be safe!
    simpleArgs.clear();
    badArgs.clear();
// I start by putting all the key values into my unordered_map.
    for (int i=0; v[i].name != NULL; i++)  argIndex[v[i].name] = &v[i];
// Now scan the arguments.
    for (int i=1; i<argc && argv[i]!=NULL; i++)
    {   std::string a(argv[i]);       // The next argument provided
        std::string aSave(a);
        if (a.compare("--args") == 0) break;
        std::string val;
        bool hasVal = false;
        if (a[0] == '-' && a[1] != 0)
        {   if (a[1] == '-')            // Here I have "--word"
            {   auto pos = a.find('=');
                if (pos != std::string::npos) //       "--word=VAL"
                {   val = a.substr(pos+1);
                    hasVal = true;
                    a = a.substr(0, pos);
                }
            }
            else                 // Here I have "-x"
            {   if (a[1] != 0 && a[2] != 0)
                {   val = a.substr(2);  //             "-xVAL"
                    hasVal = true;
                    a = a.substr(0, 2);
                }
            }
        }
        else simpleArgs.push_back(a); // No initial "-" or JUST "-".
        argSpec *aspec;
        try                           // Look up the keyword.
        {   std::string aLow(a);
            std::transform(aLow.begin(), aLow.end(), aLow.begin(),
                [](int c){ return std::tolower(c); });
            aspec = argIndex.at(aLow);
        }
        catch (std::out_of_range &)
        {   badArgs.push_back(aSave); // Item not recognized at all.
            continue;
        }
// If the keyword takes a "value" then if there is another item on the command
// line and that does not start with "-" then that will be used as the
// operand. Otherwise an empty string will be used.
        if (aspec->takesVal)
        {   if (!hasVal)
            {   if (i+1 < argc &&
                    (argv[i+1][0] != '-' ||
                     argv[i+1][1] == 0))     // Permit "-" as value.
                {   val = argv[++i];
                    hasVal = true;
                }
                else val = "";
            }
        }
// But if you have something like "--word=VAL" and --word is not expecting
// an associated value I will put the argument on my list of bad items. The
// same is the case for "-xVAL" for a single-letter option x where  a value
// is not wanted.
        else if (hasVal)
        {   badArgs.push_back(aSave);
            continue;                  // Ignore item.
        }
// Now invoke the action that this calls for.
        (aspec->action)(a, hasVal, val);
    }
}

// end of getargs.cpp

