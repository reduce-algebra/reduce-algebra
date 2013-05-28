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
    Jlisp.initfns(u01.builtins); 
    Jlisp.initfns(u02.builtins); 
    Jlisp.initfns(u03.builtins); 
    Jlisp.initfns(u04.builtins); 
    Jlisp.initfns(u05.builtins); 
    Jlisp.initfns(u06.builtins); 
    Jlisp.initfns(u07.builtins); 
    Jlisp.initfns(u08.builtins); 
    Jlisp.initfns(u09.builtins); 
    Jlisp.initfns(u10.builtins); 
    Jlisp.initfns(u11.builtins); 
    Jlisp.initfns(u12.builtins); 
    Jlisp.initfns(u13.builtins); 
    Jlisp.initfns(u14.builtins); 
    Jlisp.initfns(u15.builtins); 
    Jlisp.initfns(u16.builtins); 
    Jlisp.initfns(u17.builtins); 
    Jlisp.initfns(u18.builtins); 
    Jlisp.initfns(u19.builtins); 
    Jlisp.initfns(u20.builtins); 
    Jlisp.initfns(u21.builtins); 
    Jlisp.initfns(u22.builtins); 
    Jlisp.initfns(u23.builtins); 
    Jlisp.initfns(u24.builtins); 
    Jlisp.initfns(u25.builtins); 
    Jlisp.initfns(u26.builtins); 
    Jlisp.initfns(u27.builtins); 
    Jlisp.initfns(u28.builtins); 
    Jlisp.initfns(u29.builtins); 
    Jlisp.initfns(u30.builtins); 
    Jlisp.initfns(u31.builtins); 
    Jlisp.initfns(u32.builtins); 
    Jlisp.initfns(u33.builtins); 
    Jlisp.initfns(u34.builtins); 
    Jlisp.initfns(u35.builtins); 
    Jlisp.initfns(u36.builtins); 
    Jlisp.initfns(u37.builtins); 
    Jlisp.initfns(u38.builtins); 
    Jlisp.initfns(u39.builtins); 
    Jlisp.initfns(u40.builtins); 
    Jlisp.initfns(u41.builtins); 
    Jlisp.initfns(u42.builtins); 
    Jlisp.initfns(u43.builtins); 
    Jlisp.initfns(u44.builtins); 
    Jlisp.initfns(u45.builtins); 
    Jlisp.initfns(u46.builtins); 
    Jlisp.initfns(u47.builtins); 
    Jlisp.initfns(u48.builtins); 
    Jlisp.initfns(u49.builtins); 
    Jlisp.initfns(u50.builtins); 
    Jlisp.initfns(u51.builtins); 
    Jlisp.initfns(u52.builtins); 
    Jlisp.initfns(u53.builtins); 
    Jlisp.initfns(u54.builtins); 
    Jlisp.initfns(u55.builtins); 
    Jlisp.initfns(u56.builtins); 
    Jlisp.initfns(u57.builtins); 
    Jlisp.initfns(u58.builtins); 
    Jlisp.initfns(u59.builtins); 
    Jlisp.initfns(u60.builtins); 
}

public static void main(String []args)
{
    Jlisp.extrabuiltins = new Reduce();
    CWin.main(args);
}

}

// End of Reduce.java

