// prototypes.cpp                                   A C Norman, August 2017

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <clang-c/Index.h>
using namespace std;

// $Id$

// The tutorial at http://shaharmike.com/cpp/libclang/ with title
// "Using libclang to Parse C++ (aka libclang 101)".
// and his sample code and explanation really helped me get started.
// Thank you. If you are concerned about licenses please check that
// web-site, which is not explicit on that front but I believe clearly
// does not intend to restrict use of the material. And anyway all that
// actually remains of Mike's original code is very standard use of the
// clang API. And this files as a whole is rather trivial. So as far as
// I (A C Norman) am concerned it is sample code that anybody can use
// without worrying about my contributions. But obviously the BSD-style
// disclaimers of liability hold.
//
//   A C Norman, 2017

// Here is the fragment of Makefile that I use to build this - and I have
// tried that on Linux (Ubuntu) and cygwin (64-bit).

/*

prototypes:	prototypes.cpp
	g++ -std=gnu++14 -I/usr/lib/llvm-4.0/include prototypes.cpp \
	-L /usr/lib/llvm-4.0/lib -lclang -o prototypes

*/

// C++ does not support dymamic free variables (in lambda expressions) and
// so I make the source file static.
static FILE *srcfile;

int main(int argc, char *argv[])
{   if (argc == 1)
    {   cout << "Usage: prototypes [-I dir] f1.cpp f2.cpp ...\n"
             << "extract (non-static) function prototypes from source files\n";
        return 0;
    }
// I will process each of the files named on the command line. If one can not
// be accessed I will give up.
    const char *searchdir = NULL;
    for (int k=1; k<argc; k++)
    {   const char *arg = argv[k];
// I aupport the crudent imaginable scheme to indicate where the files
// will be found. "-I dirname" can preceed the list of files. Only one
// directory may be given.
        if (strcmp(arg, "-I") == 0 && k<argc-2)
        {   searchdir = argv[++k];
            continue;
        }
        char source[1000];
        if (searchdir==NULL) strcpy(source, arg);
        else sprintf(source, "%s/%s", searchdir, arg);
        CXIndex index = clang_createIndex(0, 0);
        CXTranslationUnit unit = clang_parseTranslationUnit(
                                     index,      // Index
                                     source,     // source file name
                                     nullptr,    // command line args
                                     0,          // count of command line args
                                     nullptr,    // unsaved files
                                     0,          // count of unsaved files
                                     CXTranslationUnit_None); // options
// Then get the source file ready for reading.
        srcfile = fopen(source, "r");
        if (unit == nullptr || srcfile == NULL)
        {   cerr << "Unable to parse translation unit. Quitting." << endl;
            exit(1);
        }
// I will traverse the Abstract Parse Tree that libclang has created.
        CXCursor cursor = clang_getTranslationUnitCursor(unit);
        clang_visitChildren(
            cursor,
            [](CXCursor c, CXCursor parent, CXClientData client_data)
        {
// The only things I am interested in here are function definitions. This
// may pick up mere declarations that are in the source code too.
            if (clang_getCursorKind(c) == CXCursorKind::CXCursor_FunctionDecl)
            {


                CXSourceRange r = clang_getCursorExtent(c);
// Given a function declaration I link back to where it exists in the
// source code.
                CXSourceLocation start = clang_getRangeStart(r);
// If it was in something that was #included I will ignore it. Thus
// definitions in header files will only be processed if you can the header
// file explicitly.
                if (clang_Location_isFromMainFile(start))
                {   CXFile file;
                    unsigned line, column, foffset;
                    clang_getFileLocation(start, &file, &line, &column, &foffset);
// The offset lets me seek in the source file to fine the start of the
// function declaration.
                    fseek(srcfile, foffset, SEEK_SET);
// I will impose a fixed limit to the size of declarations that I am
// willing to extract.
#define DEFSIZE 4000
                    static char def[DEFSIZE+2];
                    int n = 0; // character count
                    int p = 0; // parenthesis nesting level.
// I will take the view that the function prototype ends with a ')' that
// is not nested within further parentheses.
// There are a number of respects in which this is Not Good Enough.
// (a) There could be comments embedded within the prototype and they
//     might have mis-matched parentheses, leading to confusion.
// (b) If the return-type for the function is itself a function you could
//     have parentheses in its description, which would be misinterpreted
//     by the naive code here.
// (c) I might be that there are other C++ situations and idioms that I have
//     not for now though of! Things like decorations at the end of the
//     protytype, default values for arguments, ...
// So a proper scheme would use more of libclang to discover the source
// extent of the function prototype PROPERLY, and perhaps the resulting code
// would be neater than the mess I have here at present. If some helpful
// person with more libclang experience than I have could sort that out and
// and me a better version (or just publish it on their own site and tell
// me about it) that would be very nice!
                    for (int i=0; i<DEFSIZE; i++)
                    {   int c = getc(srcfile);
                        if (c == '(') p++;
                        else if (c == ')') p--;
                        def[n++] = c;
                        if (c==')' && p==0) break;
                    }
                    def[n++] = ';';
                    def[n] = 0;
// My purpose is to collect prototypes that might properly go in header
// files, and so static ones can be discarded. My textual search for the
// characters "static " would be inadequate in the face of presence of
// names that had that string as a suffix! Again proper use of libclang
// could resolve this!
                    if (strstr(def, "static ") == NULL)
                        cout << "extern " << def << "\n";
                }
            }
            return CXChildVisit_Recurse;
        },
        nullptr);
        fclose(srcfile);
        clang_disposeTranslationUnit(unit);
        clang_disposeIndex(index);
    }
    return 0;
}

// end of prototype.cpp
