package uk.co.codemist.jlisp.core;


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
// Copyright \u00a9 (C) Codemist Ltd, 1998-2013.
//

/**************************************************************************
 * Copyright (C) 1998-2013, Codemist Ltd.                A C Norman       *
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

static U01 u01 = new U01();
static U02 u02 = new U02();
static U03 u03 = new U03();
static U04 u04 = new U04();
static U05 u05 = new U05();
static U06 u06 = new U06();
static U07 u07 = new U07();
static U08 u08 = new U08();
static U09 u09 = new U09();
static U10 u10 = new U10();
static U11 u11 = new U11();
static U12 u12 = new U12();
static U13 u13 = new U13();
static U14 u14 = new U14();
static U15 u15 = new U15();
static U16 u16 = new U16();
static U17 u17 = new U17();
static U18 u18 = new U18();
static U19 u19 = new U19();
static U20 u20 = new U20();
static U21 u21 = new U21();
static U22 u22 = new U22();
static U23 u23 = new U23();
static U24 u24 = new U24();
static U25 u25 = new U25();
static U26 u26 = new U26();
static U27 u27 = new U27();
static U28 u28 = new U28();
static U29 u29 = new U29();
static U30 u30 = new U30();
static U31 u31 = new U31();
static U32 u32 = new U32();
static U33 u33 = new U33();
static U34 u34 = new U34();
static U35 u35 = new U35();
static U36 u36 = new U36();
static U37 u37 = new U37();
static U38 u38 = new U38();
static U39 u39 = new U39();
static U40 u40 = new U40();
static U41 u41 = new U41();
static U42 u42 = new U42();
static U43 u43 = new U43();
static U44 u44 = new U44();
static U45 u45 = new U45();
static U46 u46 = new U46();
static U47 u47 = new U47();
static U48 u48 = new U48();
static U49 u49 = new U49();
static U50 u50 = new U50();
static U51 u51 = new U51();
static U52 u52 = new U52();
static U53 u53 = new U53();
static U54 u54 = new U54();
static U55 u55 = new U55();
static U56 u56 = new U56();
static U57 u57 = new U57();
static U58 u58 = new U58();
static U59 u59 = new U59();
static U60 u60 = new U60();

void inituserfns()
{
    Jlisp.inituserfns(u01.builtins); 
    Jlisp.inituserfns(u02.builtins); 
    Jlisp.inituserfns(u03.builtins); 
    Jlisp.inituserfns(u04.builtins); 
    Jlisp.inituserfns(u05.builtins); 
    Jlisp.inituserfns(u06.builtins); 
    Jlisp.inituserfns(u07.builtins); 
    Jlisp.inituserfns(u08.builtins); 
    Jlisp.inituserfns(u09.builtins); 
    Jlisp.inituserfns(u10.builtins); 
    Jlisp.inituserfns(u11.builtins); 
    Jlisp.inituserfns(u12.builtins); 
    Jlisp.inituserfns(u13.builtins); 
    Jlisp.inituserfns(u14.builtins); 
    Jlisp.inituserfns(u15.builtins); 
    Jlisp.inituserfns(u16.builtins); 
    Jlisp.inituserfns(u17.builtins); 
    Jlisp.inituserfns(u18.builtins); 
    Jlisp.inituserfns(u19.builtins); 
    Jlisp.inituserfns(u20.builtins); 
    Jlisp.inituserfns(u21.builtins); 
    Jlisp.inituserfns(u22.builtins); 
    Jlisp.inituserfns(u23.builtins); 
    Jlisp.inituserfns(u24.builtins); 
    Jlisp.inituserfns(u25.builtins); 
    Jlisp.inituserfns(u26.builtins); 
    Jlisp.inituserfns(u27.builtins); 
    Jlisp.inituserfns(u28.builtins); 
    Jlisp.inituserfns(u29.builtins); 
    Jlisp.inituserfns(u30.builtins); 
    Jlisp.inituserfns(u31.builtins); 
    Jlisp.inituserfns(u32.builtins); 
    Jlisp.inituserfns(u33.builtins); 
    Jlisp.inituserfns(u34.builtins); 
    Jlisp.inituserfns(u35.builtins); 
    Jlisp.inituserfns(u36.builtins); 
    Jlisp.inituserfns(u37.builtins); 
    Jlisp.inituserfns(u38.builtins); 
    Jlisp.inituserfns(u39.builtins); 
    Jlisp.inituserfns(u40.builtins); 
    Jlisp.inituserfns(u41.builtins); 
    Jlisp.inituserfns(u42.builtins); 
    Jlisp.inituserfns(u43.builtins); 
    Jlisp.inituserfns(u44.builtins); 
    Jlisp.inituserfns(u45.builtins); 
    Jlisp.inituserfns(u46.builtins); 
    Jlisp.inituserfns(u47.builtins); 
    Jlisp.inituserfns(u48.builtins); 
    Jlisp.inituserfns(u49.builtins); 
    Jlisp.inituserfns(u50.builtins); 
    Jlisp.inituserfns(u51.builtins); 
    Jlisp.inituserfns(u52.builtins); 
    Jlisp.inituserfns(u53.builtins); 
    Jlisp.inituserfns(u54.builtins); 
    Jlisp.inituserfns(u55.builtins); 
    Jlisp.inituserfns(u56.builtins); 
    Jlisp.inituserfns(u57.builtins); 
    Jlisp.inituserfns(u58.builtins); 
    Jlisp.inituserfns(u59.builtins); 
    Jlisp.inituserfns(u60.builtins); 
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
    record1(u01.builtins, builtinFunctions); 
    record1(u02.builtins, builtinFunctions); 
    record1(u03.builtins, builtinFunctions); 
    record1(u04.builtins, builtinFunctions); 
    record1(u05.builtins, builtinFunctions); 
    record1(u06.builtins, builtinFunctions); 
    record1(u07.builtins, builtinFunctions); 
    record1(u08.builtins, builtinFunctions); 
    record1(u09.builtins, builtinFunctions); 
    record1(u10.builtins, builtinFunctions); 
    record1(u11.builtins, builtinFunctions); 
    record1(u12.builtins, builtinFunctions); 
    record1(u13.builtins, builtinFunctions); 
    record1(u14.builtins, builtinFunctions); 
    record1(u15.builtins, builtinFunctions); 
    record1(u16.builtins, builtinFunctions); 
    record1(u17.builtins, builtinFunctions); 
    record1(u18.builtins, builtinFunctions); 
    record1(u19.builtins, builtinFunctions); 
    record1(u20.builtins, builtinFunctions); 
    record1(u21.builtins, builtinFunctions); 
    record1(u22.builtins, builtinFunctions); 
    record1(u23.builtins, builtinFunctions); 
    record1(u24.builtins, builtinFunctions); 
    record1(u25.builtins, builtinFunctions); 
    record1(u26.builtins, builtinFunctions); 
    record1(u27.builtins, builtinFunctions); 
    record1(u28.builtins, builtinFunctions); 
    record1(u29.builtins, builtinFunctions); 
    record1(u30.builtins, builtinFunctions); 
    record1(u31.builtins, builtinFunctions); 
    record1(u32.builtins, builtinFunctions); 
    record1(u33.builtins, builtinFunctions); 
    record1(u34.builtins, builtinFunctions); 
    record1(u35.builtins, builtinFunctions); 
    record1(u36.builtins, builtinFunctions); 
    record1(u37.builtins, builtinFunctions); 
    record1(u38.builtins, builtinFunctions); 
    record1(u39.builtins, builtinFunctions); 
    record1(u40.builtins, builtinFunctions); 
    record1(u41.builtins, builtinFunctions); 
    record1(u42.builtins, builtinFunctions); 
    record1(u43.builtins, builtinFunctions); 
    record1(u44.builtins, builtinFunctions); 
    record1(u45.builtins, builtinFunctions); 
    record1(u46.builtins, builtinFunctions); 
    record1(u47.builtins, builtinFunctions); 
    record1(u48.builtins, builtinFunctions); 
    record1(u49.builtins, builtinFunctions); 
    record1(u50.builtins, builtinFunctions); 
    record1(u51.builtins, builtinFunctions); 
    record1(u52.builtins, builtinFunctions); 
    record1(u53.builtins, builtinFunctions); 
    record1(u54.builtins, builtinFunctions); 
    record1(u55.builtins, builtinFunctions); 
    record1(u56.builtins, builtinFunctions); 
    record1(u57.builtins, builtinFunctions); 
    record1(u58.builtins, builtinFunctions); 
    record1(u59.builtins, builtinFunctions); 
    record1(u60.builtins, builtinFunctions); 
}

public static void main(String []args)
{
    Jlisp.extrabuiltins = new Reduce();
    CWin.main(args);
}

}

// End of Reduce.java

