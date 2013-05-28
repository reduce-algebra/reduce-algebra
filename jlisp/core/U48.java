package uk.co.codemist.jlisp.core;


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2013.
//

/**************************************************************************
 * Copyright (C) 1998-2013, Codemist Ltd.                  A C Norman     *
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

// U48.java

// Each built-in function is created wrapped in a class
// that is derived from BuiltinFunction.

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.BigInteger;

class U48
{
    Object [][] builtins = 
    {
        {"u48-sample",                  new U48_sampleFn()},
    };


class U48_sampleFn extends BuiltinFunction
{
    public LispObject op0()
    {
        return Jlisp.nil;
    }
    public LispObject op1(LispObject arg1)
    {
        return arg1;
    }
    public LispObject op2(LispObject arg1, LispObject arg2) throws ResourceException
    {
        return arg1;
    }
    public LispObject opn(LispObject [] args) throws ResourceException
    {
        int n = args.length;
        if (n == 0) return Jlisp.nil;
        else return args[0];
        
    }
}



}

// end of U48.java

