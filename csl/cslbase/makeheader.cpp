// makeheader.cpp                          Copyright (C) 1990-2025 Codemist

// $Id$


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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




// This is to take a C++ source file and return just the declarations
// wherever there are function definitions.
// Well I will also keep definitions of templated functions and classes.
// And furthermore it is important to keep definitions that are
// constexpr because they may be used at compile time.

// So here is my current analysis of what need to be done...

// Tokenize to the extent of noticing comments, character literals and
// strings and noticing the symbols "const", "template", "if", "constexpr",
// "while", "for", "catch", "(", ")", "[", "]", "[[", "]]", "{" and "}".

// I will discuss "template" later on...

// Seek '){' and in MOST cases it will be the boundary between
// a function prototype and the body of that definition of that function
// so in the case replace with ');' and discard until and including the
// terminating '}'. Well there can be some "noise" between the ")" and "{",
// in particular "const", "noexcept" and [[ ... ]]". Until C++20 there
// is "throw( ... )" but since that is already deprecated I will probably
// not support it.
//
//
// The other cases where '){' can arise are
//      [...         ] (...) {
//                  if (...) {
//      if   constexpr (...) {
//               while (...} {
//               catch (...) {
//    constexpr T name (...) {
// and all of these can be identified because the token just before
// the "(" is special. Well possibly "[[...]]" could intervene there but
// that is easy to skip over. 
//
// This should identify the start of the body of a function definition,
// Well I will DEMAND to make life easier for myself that "constexpr"
// there is on the same line as the function name. I guess I should
// therefor look backward from the name until I see either a newline or
// a semicolon looking for that magic word.
//
// Templates are an extra issue. There are several cases I will consider:
// I will first note that the <...> could contain ">" within it in a
// potentially confusing manner, but any such must be protected by enclosing
// parentheses. Other keywords such as "class" can be in there and so
// whenever I encounter the word "template" I will skip ahead across the
// following <...>  before considering anything else.
////
// (1) Simple template function as in
//      template <...>
//      ... name(...) { ...
// where there may be type-trait tests that judge whether the template is
// to be considered applicable.
// (2) Class template
//      template <...>
//      ... class ... {
//         ... zero or more function definitions ...
//                    };
// (3) Explicit instantiation
//      template [class/struct/union] teplatename<arg list>;
// (4) Alias template
//      template <...> ... using ...
// (5) Variable template
//      template <...> ... variable_declaration
// (6) Concepts
//      template <...> concept ...
//
// When I see the word "template" I will scan forward (skipping nested
// (), []. {} and [[]]) until I find one of:
//  (1) A "{" that by consideraion of its broader context is the start of
//      a function definition. I.e. there is something like "name(args)"
//      before it with possibly interleaved annotation. I then scan to the
//      matching "}" copying everything and declare this template complete.
//  (2) "class". Find the following "{" and copy from there to the closing
//      "}".
//  (3) ";". Declare that I had just spotted an explicit instantiation
//      or a variable template.
//  (4) "using" or "concept" indicate just those cases.

// HA HA HA...
// When a function has been declared within a class, as in
//     class A
//     {   void f();
//     };
// there will be a definition later on in the form
//     void A::f() { ... }
// and for a header file I need to preserve the declaration within the
// class (that will happen anyway) but totally delete the definition.
// I must not merely downgrade it to read
//     void A::f{};
// so to handle that I need to take any place where I was about to
// turn a definition into a declaration, and scan back to the very start.
// This must involve noticing that the symbol used has a name with
// embeeded "::" but it is worse than that bacause the part before the
// "::" could indicate a namespace not a class.
// Well the lexer can distinguish between plain and qualified names.

// Well now I make the lexer return "token" structures. These are allocated
// for each token in the input and never deleted, so they use up space.
// Some may call that a space-leak. I call it simplified programming!


#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cstdint>
#include <cstring>
#include <cassert>

using namespace std;

extern int mygetchar();

#define YY_INPUT yy_input
extern void YY_INPUT(char* buf, int& result, int max_size);

#include "lexheader.cpp"

int yywrap()
{   return 1;
}

void YY_INPUT(char* buf, int& result, int max_size)
{   int c = mygetchar();
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1);
}


const char* lexname(int n)
{   switch (n)
    {
    case DIRECTIVE:    return "DIRECTIVE";
    case CONST:        return "CONST";
    case NOEXCEPT:     return "NOEXCEPT";
    case IF:           return "IF";
    case CONSTEVAL:    return "CONSTEVAL";
    case CONSTEXPR:    return "CONSTEXPR";
    case FOR:          return "FOR";
    case WHILE:        return "WHILE";
    case CATCH:        return "CATCH";
    case LBRACE:       return "LBRACE";
    case LBRACKET:     return "LBRACKET";
    case LBRACKETS:    return "LBRACKETS";
    case LITERAL:      return "LITERAL";
    case LPAREN:       return "LPAREN";
    case NAME:         return "NAME";
    case SCOPEDNAME:   return "SCOPEDNAME";
    case NUMBER:       return "NUMBER";
    case OPERATOR:     return "OPERATOR";
    case RBRACE:       return "RBRACE";
    case RBRACKET:     return "RBRACKET";
    case RBRACKETS:    return "RBRACKETS";
    case RPAREN:       return "RPAREN";
    case TEMPLATE:     return "TEMPLATE";
    case CONCEPT:      return "CONCEPT";
    case THROW:        return "THROW";
    case UNKNOWN:      return "UNKNOWN";
    case SEMICOLON:    return "SEMICOLON";
    default:           static char unknown[32];
                       snprintf(unknown, sizeof(unknown), "Op_%d", n);
                       return unknown;
    }
}

vector<token*> lexbuff;
int parens = 0, brackets = 0, braces = 0;
istream* instream = &cin;
ostream* outstream = &cout;
token* lex;

int mygetchar()
{   int ch = instream->get();
    if (!instream->good()) return EOF;
    buff.push_back(ch);
    return ch;
}    

// scan backwards starting by looking at the token at position n
// and skipping matched parents, brackets etc. Return with a pointer
// either ti a token of type ender or a marker value NOT_FOUND.

const size_t NOT_FOUND = SIZE_MAX;

size_t skipBackOverBalanced(size_t n, int ender)
{   unsigned int parens=0, brackets=0, braces=0;
    while (n>0)
    {   lex = lexbuff[n];
        if (lex->type == ender && parens==0 && brackets==0 && braces==0) return n;
        if (parens > 100 ||
            brackets > 100 ||
            braces > 100)
        {   cout << "\n+++ nesting disaster +++\n";
            cout << "parens " << parens
                 << " bracksts " << brackets
                 << " braces " << braces << "\n";
            for (int j=(n==0?n:n-1); j<min(n,lexbuff.size()); j++)
                cout << j << ": " << lexname(lexbuff[j]->type) << "\n";
            for (char ch:buff) cout << ch;
            cout << "\n";
            abort();
        }
        switch (lex->type)
        {
        case LPAREN:
            parens--;
            break;
        case LBRACKET:
            brackets--;
            n--;
            break;
        case LBRACKETS:
            brackets-=2;;
            break;
        case LBRACE:
            braces--;
            break;
        case RPAREN:
            parens++;
            break;
        case RBRACKET:
            brackets++;
            break;
        case RBRACKETS:
            brackets+=2;
            break;
        case RBRACE:
            braces++;
            break;
        }
        n--;
    }
    return NOT_FOUND;
}

// Read tokens until one matching ender is found subject to skipping
// sequences that are enclosed in (), [] or {}. If ennd of file is
// detected return NOT_FOUND. The closing delimiter will be the final
// token read.

void note(int a, int b, int c)
{   char w[100];
    snprintf(w, 100, "/*%d %d %d*/", a, b, c);
    for (char* p=w; *p!=0; p++)
        buff.push_back(*p);
}

// Here I have a token that names a class. If it is of the form
//    p1::p2::tail
// I will record p1::p2::tail, p2::tail and tail as names it
// might sometimes be referred to by.

void recordClassName(token* lex)
{   char* text = lex->text;
    char* w;
    char* n;
    while ((w = std::strstr(text, "::")) != nullptr)
    {   n = new char[strlen(text)+1];
        std::strcpy(n, text);
        classnames.insert(std::string(n));
        text = w + 2;
    }
    n = new char[strlen(text)+1];
    std::strcpy(n, text);
    classnames.insert(std::string(n));
}

void skipForwardOverBalanced(int ender)
{   unsigned int parens=0, brackets=0, braces=0;
    token* prevlex = nullptr;
    while (instream->good())
    {   prevlex = lex;
        lex = yylex();
        if (lex->type == END) break;
        lexbuff.push_back(lex);
        if (lex->type == CLASS)
        {   skipForwardOverBalanced(NAME);
// Now lex should be the name of the class being defined#
            recordClassName(lex);
        }
        if (lex->type==ender && parens==0 && brackets==0 && braces==0) return;
        if (parens > 100 ||
            brackets > 100 ||
            braces > 100)
        {   cout << "\n+++ nesting disaster in forward scan +++\n";
            cout << "ender = " << lexname(ender) << "\n";
            cout << "prevlex = " << lexname(prevlex->type) << "\n";
            cout << "lex = " << lexname(lex->type) << "\n";
            cout << "parens " << parens
                 << " bracksts " << brackets
                 << " braces " << braces << "\n";
            for (int j=0; j<lexbuff.size(); j++)
                cout << j << ": " << lexname(lexbuff[j]->type) << "\n";
            for (char ch:buff) cout << ch;
            cout << "\n";
            abort();
        }
        switch (lex->type)
        {
        case LPAREN:
            parens++;
//            note(parens, brackets, braces);
            continue;
        case LBRACKET:
            brackets++;
            continue;
        case LBRACKETS:
            brackets+=2;
            continue;
        case LBRACE:
            braces++;
//            note(parens, brackets, braces);
            continue;
        case RPAREN:
            parens--;
//            note(parens, brackets, braces);
            continue;
        case RBRACKET:
            brackets--;
            continue;
        case RBRACKETS:
            brackets-=2;
            continue;
        case RBRACE:
            braces--;
//            note(parens, brackets, braces);
            continue;
        }
    }
}

size_t skipBackOverPrototypeQualifiers(size_t n)
{
// I want to find a token in lexbuff earliert than at position n
// such that it is not const, noexcept or [[...]]. Also I will stop
// if n gets down to 0 because the syntax I need to detect only
// occurs if there us material before the things skipped here.
    while (n > 0)
    {   if (lexbuff[n]->type == NOEXCEPT || lexbuff[n]->type == CONST)
        {   n--;
            continue;
        }
        // A sequence "[[ ... ]]" is skipped and I do not need to worry
        // about nested double-brackets so the search for matching them
        // here is really simple.
        else if (lexbuff[n]->type == RBRACKETS)
        {   while (n > 0 && lexbuff[n]->type != LBRACKETS) n--;
            if (n > 0) n--;
            continue;
        }
        else return n;   // Position of ")" if I have a procedure. 
    }
    return NOT_FOUND;
}

size_t IfForWhileCatchSyntax(size_t n)
{   while (lexbuff[n]->type == RBRACKETS)
    {   while (n>0 && lexbuff[n]->type!=LBRACKETS) n--;
        if (n==0) return NOT_FOUND;
        n--;
    }
    if (lexbuff[n]->type==RBRACKET ||    // a lambda expression
        lexbuff[n]->type==IF ||
        lexbuff[n]->type==CONSTEXPR ||   // "if constexpr"
        lexbuff[n]->type==FOR ||
        lexbuff[n]->type==WHILE ||
        lexbuff[n]->type==CATCH) return NOT_FOUND;
// Now n is the index in lexbuff of the function name - which is
// expected to be a name.
    int m = n;
// I scan for "constexpr" on the same line as the function name, also stopping
// if I encounter a semicolon. I think there are slightly pathological cases
// that might break this, sg
//    constexpr struct { int a; int b; } f(...
// where the semicolon stops my scan too early,
//    constexpt int a=1; int f(...
// where the semicolon must stop the scan. If I was more careful I would
// scan backwars over "{..}" balanced sections. And not then pay attention to
// newlines..., but worry strongly about
//    constexpr int f1() {return 1;} int f2() {return 2;}
// where the first procedure is constexpr but the second is not. Well that
// gets coped with my arranging that when the first procedure is processed
// if flushes all buffers so its text is no longer visible.
// The remaining worry is maybe
//    constexpr class A { ..very long.. } f( ...
// which puts the word constexpr remote from the function name - and what is
// worse will have had some functions defined within the class tending to
// mess with buffering etc. So for now I take a simplistic route...
    while (m > 0)
    {   token* lex = lexbuff[--m];
        size_t where = lex->where;
        char ch = buff[where];     // char after the symbol lex.
        if (lex->type == CONSTEXPR) return NOT_FOUND;
        else if (lex->type == SEMICOLON || ch == '\n') break;
    }
    return n;
}
size_t isProcedureBodyStart()
{
// Here I have found a "(". I need to judge whether it is part of
// a procedure header. If it is the tokens leading up to it will
// follow one of these patterns:
//       )   {
//       ) const {
//       ) noexcept {
//       ) [[ ... ]] {
// There us also a deprecated syntax
//       } throw ( ...) {
// that I do not expect to encounter and that will be removed in a
// later C++ version.
// If none of these apply this is certainly not a procedure definition
// and so I will treat the "{" as an ordinary token not calling for
// and special action. I will have code that skips past the intervening
// "noise words" so at the top level of my checking I just look for
//       )   {
// One thing I do not believe I can handle neatly is the possibility that
// one or more of the above structures has been introduced via a "#define"
// macro. Detecting that would be somewhat horrid and while I can imagine
// ways to make some progress on it for now I will just disallow any such
// games.
    size_t n = lexbuff.size() - 1;  // The "{"
    if (n>0) n--;                   // Just before the "{"
    int rpar = skipBackOverPrototypeQualifiers(n);
    if (rpar==NOT_FOUND || lexbuff[rpar]->type!=RPAREN || rpar==0)
        return NOT_FOUND;
// Now I have what is in essense ") {". Look for a previous "(".
// I must skip balanced nested parens and brackets and braces in what
// is liable to be a parameter specification.
// So note that braces could be present as in the definition
//       void foo(int a, int b=([](){ .. return ...})(a)) { ...
// where a default value for a parameter is set using a lambda-expression.
// But that is OK because all I need to do is to match "{" with "}" as
// I scan looking for that start of the function prototype.
    int lpar = skipBackOverBalanced(rpar-1, LPAREN);
    if (lpar == NOT_FOUND || lpar==0) return NOT_FOUND;
// detect the cases
//       throw ( ... ) {
//          In this case I ought to go back and keep looking for
//              ) ... throw ( ...) ... {
//          Howver for simplicity I will just detect it and issue a
//          diagnostic if it occurs. People are now expected to use
//          noexcept rather than throw() to document exception behavior.
//       ] ( ... ) ... {             Lambda
//       if ( ... ) ... {
//       [if] constexpr ( ... ) ... {
//       for ( ... ) ... {
//       while ( ... ) ... {
//       catch ( ... ) ... {
// If any of these apply then again we do not have a procedure definition
// so the "(" is not to be treated as special in any way. If the item
// just before the "(" is something other than one of these keywords it
// should be a symbol, and it matters whether it is one with "::" embedded!
// Note that "[[ ... ]]" can intervene pretty well anywhere as well.
    size_t fname;
    if ((fname=IfForWhileCatchSyntax(lpar-1)) == NOT_FOUND) return NOT_FOUND;
    return fname;
}

int newlines = 0;
void output(int c)
{   if (c == '\n')
    {   newlines++;
        if (newlines > 2) return;
    }
    else newlines = 0;
    (*outstream) << (char)c;
}

void handleTemplate()
{   while (instream->good())
    {   lex = yylex();
        if (lex->type == END) break;
        lexbuff.push_back(lex);
        if (lex->type == CLASS)
        {   skipForwardOverBalanced(NAME);
// Now lex should be the name of the class being defined#
            recordClassName(lex);
            while (lex->type != LBRACE) lex = yylex();
            skipForwardOverBalanced(RBRACE);
            for (auto c:buff) output(c);
            buff.clear();
            lexbuff.clear();
            return;
        }
        else if (lex->type == SEMICOLON ||
                 lex->type == USING ||
                 lex->type == CONCEPT) return;
        else if (lex->type == LBRACE && isProcedureBodyStart()!=NOT_FOUND)
// Here I have a procedure definition that I must keep.
        {   skipForwardOverBalanced(RBRACE);
            for (auto c:buff) output(c);
            buff.clear();
            lexbuff.clear();
            return;
        }
    }
}

// I hold that a name is "in a class" if it is of the form
//    leader::leaf
// and classnames.count[leader]!=0.

bool isNameInClass(char* name)
{   char* w;
    char* p = name;
    while ((w = strstr(p, "::")) != nullptr) p = w+2;
// Now p points to the leaf.
    if (p == name) return false;  // unqualified name
    char b[1000];
    strcpy(b, name);
    b[p-name-2] = 0;
    string bb(b);
    if (classnames.count(bb) == 0) return false;
//@ cout << bb << " is a class name\n";
    return true;
}

void process(istream& instream0, ostream& outstream0, const char* src, const char* dest)
{   cout << src << " -> " << dest << "\n";
    instream = &instream0;
    outstream = &outstream0;
    while (instream->good())
    {   lex = yylex();
        if (lex->type == END) break;
        lexbuff.push_back(lex);
        size_t procname;
        if (lex->type == CLASS)
        {   skipForwardOverBalanced(NAME);
// Now lex should be the name of the class being defined#
            recordClassName(lex);
        }
        else if (lex->type == TEMPLATE) handleTemplate();
        else if (lex->type == LBRACE &&
                 (procname=isProcedureBodyStart())!=NOT_FOUND)
// Here I have a procedure definition that I am going to downgrade into a
// declaration. I change the "{" into a ";" and skip everything up to
// and including the matching "}".  Well if it was an out-of class definition
// I want to discard it totally.
        {   if (isNameInClass(lexbuff[procname]->text))
            {   size_t charPos = lexbuff[procname]->where - 1;
                while (charPos>0 &&
                       buff[charPos] != '\n') charPos--;
                for (size_t i=0; i<=charPos; i++)
                    output(buff[i]);
                skipForwardOverBalanced(RBRACE);
                buff.clear();
                lexbuff.clear();
            }
            else
            {   assert(buff[buff.size()-1] == '{');
                buff.pop_back(); // loses the "{"
// Here I could have
//     int f(int a)
//     // commentary about f
//     { body of f
// and if I remove all whitespace before the "{" the ";" that
// replaces it can end up in the comment - which would be bad. So I
// will in fact end up with the rather ugly
//     int f(int x)
//     ;
// in the case that there is no comment but when the "{" is on the next
// line.
                while (buff.size()>0 &&
                       (buff[buff.size()-1]) == ' ') buff.pop_back();
                buff.push_back(';');
                for (auto c:buff) output(c);
                buff.clear();
                skipForwardOverBalanced(RBRACE);
                buff.clear();
                lexbuff.clear();
            }
        }
    }
    for (auto c:buff) output(c);
    output('\n');
}

int main(int argc, char* argv[])
{   ifstream i;
    ofstream o;
    const char* src = "-";
    const char* dest = "-";  
    switch (argc)
    {
    default:
        cout << "Bad number of arguments (" << argc << ")\n";
        return 1;
    case 3:
        src = argv[1];
        i.open(src);
        dest = argv[2];
        o.open(dest);
        process(i, o, src, dest);
        break;
    case 2:
        src = argv[1];
        i.open(src);
        process(i, cout, src, dest);
        break;
    case 1:
        process(cin, cout, src, dest);
        break;
    }

//@ for (auto n:classnames)
//@     cout << "class " << n << "\n";
    return 0;

}

// end of makeheader.cpp
