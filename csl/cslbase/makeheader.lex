%{// makeheader.lex                             Copyright (C) 2025 Codemist 

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


/* This is for scanning C++ code and extracting about the minimum information
// I need for removing definitions from a source file leaving only
// declarations.
// The strategy is that a definition (of a function) has the header line
// ending with "){" and if I find that I scan forward to the matching "}"
// replacing all that with just ";".
// There are four main complications:
// (1) "#ifdef", "#pramga" etc may cause confsion. I will just insist that
//     source files for use here do not have them in manners that cause
//     me confusion!
// (2) I want to leave templated definitions intact. So I spot the keyword
//     "template". That must be introducing a definition.
// (3) There can be various bits of noise after a procedure header before
//     its body. Eg "const" or "noexcept" or "throw".
// (4) Several C++ constructs other than procedure definitions can lead to
//     the sequence "){". Notably
//        if (X) {
//        for (X;Y;Z) {
//        while (X) {
//        catch (X) {
// (5) Lambda expressions must not mess things up. Ones dested within
//     procedures are OK because the procedure covers their treatment,
//     but ones following variable definitions may be an issue:
//        int var = ([](){...})();
//     is not too bad because the "){" is within parens, but
//        functiontype* foo = [](){... };
//     looks harder. I will not allow that in source files to be used here!
//
// This file provides a lexer that discards comments and whitespace and
// does what I hope will be just enough classification to let me do all this.
//
// If this needed to handle Unicode it would need to use the derived
// properties ID_Start and ID_Continue when recognizing symbols. Well I do
// not believe that flex is Unicode-aware and what I do will not cope
// with any such!
*/

enum
{   UNKNOWN = 0,

    ALIGNAS,
    CATCH,
    CLASS,
    CONCEPT,
    CONST,
    CONSTEVAL,
    CONSTEXPR,
    DIRECTIVE,
    FOR,
    IF,
    LBRACE,
    LBRACKET,
    LBRACKETS,
    LITERAL,
    LPAREN,
    NAME,
    SCOPEDNAME,
    NOEXCEPT,
    NUMBER,
    OPERATOR,
    RBRACE,
    RBRACKET,
    RBRACKETS,
    RPAREN,
    SEMICOLON,
    TEMPLATE,
    THROW,
    USING,
    WHILE,
    END
};

#include <unordered_set>

std::unordered_set<std::string> classnames;
// insert(), count()

%}

%{
// There is a mess here to document the format for binary, octal, decimal
// and hex numbers, and floating point.  
%}

bit           [0-1]
binary        "0b"{bit}+
octit         [0-7]
octal         "0"{octit}*
digit         [0-9]
decimal       [1-9]{digit}*
hexit         [0-9a-fA-F]
hex           "0x"{hexit}+
float1        {decimal}"."{digit}*([eEdDfF][+-]?{decimal})?
float2        "."{digit}+([eEdDfF][+-]?{decimal})?
number        {binary}|{octal}|{decimal}|{hex}|{float1}|{float2}

%{
// Symbols are straightforward save that it is unecessary to allow
// for prefix or embedded "::". When one of those is present I call it
// a "scoped symbol" and the scope may indicate either a namespace or
// a class.
// So actually things are NOT straightforward! At the level that flex
// processes things I will sometimes see
//  "class" ("[["..."]]" | "alignas("...")")* (symbol|scopedsymbol)
// and I want to record the symbol name in a list of class names.
// Then when I see a scopedsymbol I need to check if the scoping
// part matches that. If so I have a name in a class rather than in
// a namespace.
// Well "using" and nested classes and namespaces can make the
// proper version of that test harder, so I plan to support JUST
// the cases
//     class <attributes> symbol
// and
//     classname::symbol
//
// Another awkwardness is that eg "operator ++" behaves rather like a
// symbol. My parsing here will accept eg
//   "operator new::operator[]::blah"
// as a name with the operator overload denotations where class or
// namespace designators would ne required. Such case should not arise
// in valid input so I am not too worried! Well there are many many
// other bad inputs that it will not fuss about.

vector<char> buff;

class token
{
public:
    int type;
    char* text;
    size_t where;
    token(int type)
    {   this->type = type;
        this->text = new char[strlen(yytext)+1];
        std::strcpy(this->text, yytext);
        where = buff.size();
    }
};

#define YY_DECL token* yylex()

%}

operator      "operator"(" "*)

letter        [a-zA-Z]
sym           (({letter}|"_")+({letter}|{digit}|"_")*)|({operator}{opnamex})
sym1          {sym}("::"{sym})*
symbol        ("::"{sym1})|{sym1}

opname1       "+"|"-"|"*"|"/"|"%"|"^"|"&"|"|"|"~"|"!"|"="|"<"|">"
opname2       "+="|"-="|"*="|"/="|"%="|"^="|"&="|"|="|"<<"|">>"
opname3       ">>="|"<<="|"=="|"!="|"<="|">="|"<=>"|"&&"|"||"
opname4       "++"|"--"|","|"->*"|"->"|"new"|"delete"|"co_await"
opname        {opname1}|{opname2}|{opname3}|{opname4}
opnamex       {opname}|"()"|"[]"

%{
// Character and string literals need to allow for backslash escapes
// and they also need to avoid the terminating ['] or ["] appearing
// unescaped.
%}

singlequote   [']
doublequote   ["]
backslash     [\\]
charlit       (({backslash}.)|[^\\\'])
stringlit     (({backslash}.)|[^\\\"])*

%{
// Comments introduced by "/*" are handled here by saying that the
// body is a repetition of either non-stars, or at least one star
// termianted by a character that is neither "*" nor "/". Then at the
// end it has at least one star and the final "/". The idea behind this
// is to ensure that the sequence "*/" is not present within the body.
%}

longcomment   "/*"([^*]|("*"+[^*/]))*"*"+"/" 

%%

{opname}             { return new token(OPERATOR);   }

"?"                  { return new token(OPERATOR);   }
":"                  { return new token(OPERATOR);   }
"."                  { return new token(OPERATOR);   }
"\\"                 { return new token(OPERATOR);   }
"#"                  { return new token(OPERATOR);   }

"("                  { return new token(LPAREN);     }
")"                  { return new token(RPAREN);     }
"["                  { return new token(LBRACKET);   }
"]"                  { return new token(RBRACKET);   }
"{"                  { return new token(LBRACE);     }
"}"                  { return new token(RBRACE);     }
"[["                 { return new token(LBRACKETS);  }
"]]"                 { return new token(RBRACKETS);  }

"alignas"            { return new token(ALIGNAS);    }
"const"              { return new token(CONST);      }
"noexcept"           { return new token(NOEXCEPT);   }
"throw"              { return new token(THROW);      }

"template"           { return new token(TEMPLATE);   }
"class"              { return new token(CLASS);      }
"using"              { return new token(USING);      }
"concept"            { return new token(CONCEPT);    }
";"                  { return new token(SEMICOLON);  }

"if"                 { return new token(IF);         }
"constexpr"          { return new token(CONSTEXPR);  }
"consteval"          { return new token(CONSTEVAL);  }
"for"                { return new token(FOR);        }
"while"              { return new token(WHILE);      }
"catch"              { return new token(CATCH);      }

"#"{letter}{letter}* { return new token(DIRECTIVE);  }

{symbol}             { return new token(NAME);       }

{number}             { return new token(NUMBER);     }

{singlequote}{charlit}{singlequote}      { return new token(LITERAL); }
{doublequote}{stringlit}{doublequote}    { return new token(LITERAL); }

"//"[^\n]*           { /* Single line comment */ }
{longcomment}        { /* Potentially multi-line comment */ }
[ \t\n\r]            { /* skip whitespace */ }

.                    { printf("Unknown character [%c:%.2x]\n",
                               yytext[0], yytext[0]);
                       return new token(UNKNOWN);    }
<<EOF>>              { return new token(END);        }
%%

