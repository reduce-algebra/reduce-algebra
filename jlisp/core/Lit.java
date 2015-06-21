package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
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

// $Id$

class Lit
{
    static String [] names =
    {
// The first few items in the "literals" table are not really literals at
// all in that they are values that can be changed at least when a heap
// image is being dumped. But putting them here provides me with a
// simple scheme that lets me save them in image files.

        "nil",             // restart function
	"nil",             // banner
	"nil",             // system-wide hash-table
	"nil",             // birthday
        "nil",             // SPARE

// The ones below here are all constant values	
        "*undefined-value*",
	"lambda",
	"quote",
	",",               // used in back-quote input syntax
	",@",
	"cons",
	"append",
	"special",
	"global",
	"expr",
	"subr",
	"macro",
	"fexpr",
	"input",
	"output",
	"noncom",          // special treatment or ORDERP for Reduce. Ugh!
	"\udbff\udfff",    // various special characters. Eof is U+10ffff
	" ",
	"\n",
	"\b",
	"\t",
	"\f",
	"\r",
	"\u007f",          // rubout/delete
	"\u001b",          // ESCAPE
	"lispsystem*",
	"*raise",
	"*lower",
	"*comp",
        "compile",
	"common-lisp-mode",
        "*echo",
        "&optional",
        "&rest",
        "*savedef",
        "*package*",
        "*terminal-io*",
        "*standard-output*",
        "*standard-input*",
        "*error-output*",
        "*trace-output*",
        "*debug-io*",
        "*query-io*",
        "*redefmsg",
        "*resources*",
        "lose",

        "++spare1++"
    };
    
// The names listed here MUST be in the same order as entries in the
// above table.

    static final int restart    = 0;
    static final int banner     = 1;
    static final int hashtab    = 2;
    static final int birthday   = 3;
    static final int spareV     = 4;
 
    static final int undefined  = 5; 
    static final int lambda     = 6; 
    static final int quote      = 7; 
    static final int comma      = 8; 
    static final int commaAt    = 9; 
    static final int cons       = 10;
    static final int append     = 11;
    static final int special    = 12;
    static final int global     = 13;
    static final int expr       = 14;
    static final int subr       = 15;
    static final int macro      = 16;
    static final int fexpr      = 17;
    static final int input      = 18;
    static final int output     = 19;
    static final int noncom     = 20;
    static final int eof        = 21;
    static final int space      = 22;
    static final int newline    = 23;
    static final int backspace  = 24;
    static final int tab        = 25;
    static final int formFeed   = 26;
    static final int cr         = 27;
    static final int rubout     = 28;
    static final int escape     = 29;
    static final int lispsystem = 30;
    static final int raise      = 31;
    static final int lower      = 32;
    static final int starcomp   = 33;
    static final int compile    = 34;
    static final int commonLisp = 35;
    static final int starecho   = 36;
    static final int optional   = 37;
    static final int rest       = 38;
    static final int savedef    = 39;
    static final int starpackage= 40;
    static final int terminal_io= 41;
    static final int std_output = 42;
    static final int std_input  = 43;
    static final int err_output = 44;
    static final int tr_output  = 45;
    static final int debug_io   = 46;
    static final int query_io   = 47;
    static final int redefmsg   = 48;
    static final int resources  = 49;
    static final int lose       = 50;
    static final int spare1     = 51;
}

// end of Lit.java
