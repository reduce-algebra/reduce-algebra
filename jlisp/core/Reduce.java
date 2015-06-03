package uk.co.codemist.jlisp.core;


/* $Id$ */


// Reduce
//
// Standard Lisp system coded in Java. Actually this goes
// way beyond the Standard Lisp Report and includes a large fraction
// of that which is present in the CSL Lisp system.
//
// The purpose of this implementation is to support
// REDUCE. Early versions of jlisp were amazingly slow but
// performance is gradually improving! This version has hooks to load
// classes U01 to U60 which can contain parts of Reduce compiled into
// Java.

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

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.zip.*;
import java.text.*;

public class Reduce extends JlispExtras
{

static Uxx[] translatedCode =
{
    new U01(),  new U02(),  new U03(),  new U04(),  new U05(),
    new U06(),  new U07(),  new U08(),  new U09(),  new U10(),
    new U11(),  new U12(),  new U13(),  new U14(),  new U15(),
    new U16(),  new U17(),  new U18(),  new U19(),  new U20(),
    new U21(),  new U22(),  new U23(),  new U24(),  new U25(),
    new U26(),  new U27(),  new U28(),  new U29(),  new U30(),
    new U31(),  new U32(),  new U33(),  new U34(),  new U35(),
    new U36(),  new U37(),  new U38(),  new U39(),  new U40(),
    new U41(),  new U42(),  new U43(),  new U44(),  new U45(),
    new U46(),  new U47(),  new U48(),  new U49(),  new U50(),
    new U51(),  new U52(),  new U53(),  new U54(),  new U55(),
    new U56(),  new U57(),  new U58(),  new U59(),  new U60(),
};

int countFunctions()
{
    int n = 0;
    for (Uxx u : translatedCode)
        n += u.builtins.length;
    return n;
}

void inituserfns()
{
    for (Uxx u : translatedCode)
    {   Jlisp.inituserfns(u.builtins);
    } 
}

private void record1(Object [][]builtins, HashMap builtinFunctions)
{
    for (int i=0; i<builtins.length; i++)
    {   ((LispFunction)builtins[i][1]).name = (String)builtins[i][0];
        builtinFunctions.put(builtins[i][0], builtins[i][1]);
    }
}

void recorduserfns(HashMap builtinFunctions)
{
    for (Uxx u : translatedCode)
    {   record1(u.builtins, builtinFunctions);
    }
}

public static void main(String []args)
{
    Jlisp.extrabuiltins = new Reduce();
    CWin.main(args);
}

}

// End of Reduce.java

