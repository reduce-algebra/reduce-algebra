package uk.co.codemist.jlisp.core;


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2011.
//

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
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


// Lisp has a single inclusive data-type, which I call
// LispObject here. It has sub-types that are symbols,
// numbers, strings and lists. Here I give just a few
// methods (eg print and eval) that may be used on anything.

import java.io.*;
import java.math.*;

public abstract class LispObject extends Object
{
    public boolean atom;   // true if it is atomic
    public LispObject car; // car and cdr fields to reduce number of expensive casts!
    public LispObject cdr;

    LispObject()
    {
        car = cdr = null;
        atom = true;
    }

// The following constructor is ONLY intended for use via a call
//       super(car, cdr);
// in the constructor for the "Cons" sub-class.

    LispObject(LispObject car, LispObject cdr)
    {
        atom = false;
        this.car = car; 
        this.cdr = cdr;
    }

    static final int printEscape      = 1; // flags to pass to print(n)
    static final int printBinary      = 2;
    // (decimal is the default)       = 4
    static final int printOctal       = 8;
    static final int printHex         = 16;
    static final int printLower       = 32;
    static final int printUpper       = 64;
    static final int noLineBreak      = 128;
    static final int checksumEscape   = 256;

    void print() throws ResourceException
    {
        currentOutput = (LispStream)Jlisp.lit[Lit.std_output].car/*value*/;
        currentFlags = 0;
        iprint();
    }

    void print(int flags) throws ResourceException
    {
        currentOutput = (LispStream)Jlisp.lit[Lit.std_output].car/*value*/;
        currentFlags = flags;
        iprint();
    }

// real printing will usually be done by iprint where the current output
// stream and format flags can be accessed via static variables.

    static LispStream currentOutput;
    static int currentFlags;

    abstract void iprint() throws ResourceException;
    abstract void blankprint() throws ResourceException; // print but with whitespace before it

    void errPrint() throws ResourceException // print to error output stream
    {
        currentOutput = (LispStream)Jlisp.lit[Lit.err_output].car/*value*/;
        currentFlags = printEscape;
        iprint();
    }

    void tracePrint() throws ResourceException // print to trace output stream
    {
        currentOutput = (LispStream)Jlisp.lit[Lit.tr_output].car/*value*/;
        currentFlags = printEscape;
        iprint();
    }

// Codes for use in my (custom) serialisation format.

// I make special provision for references to 64 things. I will use
// this for the first 48 things used at all and the 16 most recent ones.

    static final int X_REFn     = 0x00;

    static final int X_BREAK1   = 0x40;

// The next bunch are optimisations for common cases when the
// length code is short. The length code is folded into the main byte. Thus
// (eg) symbols whose name is from 0 to 15 characters long are dealt with
// especially neatly.

    static final int X_SYMn     = 0x40; // symbol with 0 to 15 chars
    static final int X_UNDEFn   = 0x50; // symbol (0-15), not a function
    static final int X_GENSYMn  = 0x60; // gensym with 0 to 15 bytes
    static final int X_LIST     = 0x70; // list with 0 to 15 items: (LIST) = NIL
    static final int X_LISTX    = 0x80; // like (LIST* ..) with 1-16 items then tail
    static final int X_INTn     = 0x90; // integer with 0 to 15 bytes
    static final int X_STRn     = 0xa0; // string, 0 to 15 chars

    static final int X_BREAK2   = 0xb0;

    static final int X_REF      = 0xb0; // refer to a previously mentioned item
    static final int X_REFBACK  = 0xb4; // (only 1 and 2 byte versions used)
    static final int X_INT      = 0xb8; // LispBigInteger represented by an array
    static final int X_STR      = 0xbc; // Strings
    static final int X_SYM      = 0xc0; // Symbol with given name
    static final int X_UNDEF    = 0xc4; // Symbol (not a function)
    static final int X_UNDEF1   = 0xc8; // disembodied undefined function
    static final int X_GENSYM   = 0xcc; // a gensym or other uninterned name
    static final int X_BPS      = 0xd0; // "binary code" ha ha ha.
    static final int X_VEC      = 0xd4; // a Lisp vector
// perhaps X_INT with a short-enough operand could be used for X_FIXNUM
// as a rationalisation here.
    static final int X_FIXNUM   = 0xd8; // 1, 2, 3 or 4-byte small integer

//  0xdc spare at present

    static final int X_BREAK3   = 0xe0;

// The final collection of codes are all one-byte incidental ones and
// the amount of any associated data is implicit in them. Eg X_DOUBLE will
// be followed by 8 bytes that represent a double-precision floating point
// value. X_FNAME is followed by a single length byte (n) then n characters.

    static final int X_NULL     = 0xe0; // empty cell (ie Java null)
    static final int X_DOUBLE   = 0xe1; // double-precision number
    static final int X_STREAM   = 0xe2; // an open file (not dumpable)
    static final int X_FNAME    = 0xe3; // built-in function
    static final int X_SPECFN   = 0xe4; // built-in special form
    static final int X_STORE    = 0xe5; // the next item will be re-used
    static final int X_HASH     = 0xe6; // EQ hash
    static final int X_HASH1    = 0xe7; // EQL hash (not used)
    static final int X_HASH2    = 0xe8; // EQUAL hash
    static final int X_HASH3    = 0xe9; // EQUALS hash (not used)
    static final int X_HASH4    = 0xea; // EQUALP hash (not used)
    static final int X_ENDHASH  = 0xeb; // end of data for hash table
    static final int X_AUTOLOAD = 0xec; // autoloading fn def
    static final int X_SPID     = 0xed; // internal marker
    static final int X_DEFINMOD = 0xee; // "define-in-module" in fasl files
    static final int X_INTERP   = 0xef; // interpreted code
    static final int X_MACRO    = 0xf0; // interpreted macro
    static final int X_CALLAS   = 0xf1; // simple tail-call object
    static final int X_RECENT   = 0xf2; // used in FASL but not checkpoints
    static final int X_RECENT1  = 0xf3; // used in FASL but not checkpoints
    static final int X_OBLIST   = 0xf4; // oblist vector

// 0xf2 to 0xff spare at present...

    abstract void scan();
    abstract void dump() throws IOException;

// dealing with references to shared structure has the most complicated
// treatment here because it appears to be an especially heavily used
// case and one where special cases may make some real difference.

    void putSharedRef(Object w) throws IOException
    {
        int n = ((Integer)w).intValue();
        if (n < 48)
        {   Jlisp.odump.write(X_REFn + n);
            return;
        }
	int n1 = Jlisp.sharedIndex - n;
        if (n1 < 17)  // range 1 to 16 is possible here (0 can not arise)
        {   Jlisp.odump.write(X_REFn + n1 - 1 + 48);
            return;
        }
	if (n >= 0x100 && n1 < 0x100 ||
	    n >= 0x10000 && n1 < 0x10000) putPrefix(n1, X_REFBACK);
        else putPrefix(n, X_REF);
    }

    void putPrefix2(int n, int code1, int code2) throws IOException
    {
        if (n < 16)
	{   Jlisp.odump.write(code1+n);
	}
	else putPrefix(n, code2);
    }

    void putPrefix(int n, int code) throws IOException
    {
	if ((n & 0xffffff00) == 0)
	{   Jlisp.odump.write(code);
            Jlisp.odump.write(n);
        }
        else if ((n & 0xffff0000) == 0)
        {   Jlisp.odump.write(code+1);
            Jlisp.odump.write(n >> 8);
            Jlisp.odump.write(n);
        }
	else if ((n & 0xff000000) == 0)
	{   Jlisp.odump.write(code+2);
	    Jlisp.odump.write(n >> 16);
	    Jlisp.odump.write(n >> 8);
	    Jlisp.odump.write(n);
	}
        else
        {   Jlisp.odump.write(code+3);
            Jlisp.odump.write(n >> 24);
            Jlisp.odump.write(n >> 16);
            Jlisp.odump.write(n >> 8);
            Jlisp.odump.write(n);
        }
    }

    public boolean lispequals(Object a)
    {
        return this.equals(a);
    }

    LispObject eval() throws Exception
    {
        return this;
    }

    LispObject copy()
    {
        return this;
    }

    int lisphashCode()
    {
        return this.hashCode();
    }

    double doubleValue() throws Exception
    {
        Jlisp.error("Number needed", this);
        return 0.0;  // never reached!
    }

    int intValue() throws Exception
    {
        Jlisp.error("Number needed", this);
        return 0;    // never reached!
    }

    BigInteger bigIntValue() throws Exception
    {
        Jlisp.error("Number needed", this);
        return null;    // never reached!
    }

    public LispObject negate() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject ash(int n) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject ash1(int n) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject leftshift(int n) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject rightshift(int n) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject add1() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject sub1() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject floor() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject ceiling() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject round() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject truncate() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject evenp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject oddp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject fix() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject fixp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject integerp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject jfloat() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject floatp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject minusp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject plusp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject zerop() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject onep() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject abs() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject msd() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject lsd() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject not() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modMinus() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modRecip() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject safeModRecip() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject reduceMod() throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject add(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject subtract(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject multiply(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject divide(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject remainder(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject quotientAndRemainder(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject mod(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject expt(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject max(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject min(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject and(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    public LispObject or(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject xor(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject gcd(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject lcm(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modAdd(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modSubtract(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modMultiply(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modDivide(LispObject a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modExpt(int n) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    boolean eqn(LispObject a) throws Exception
    {
        return (this == a);
    }

    boolean neqn(LispObject a) throws Exception
    {
        return (this != a);
    }

    boolean ge(LispObject a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean geq(LispObject a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean le(LispObject a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean leq(LispObject a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }


    LispObject addInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject subtractInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject multiplyInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject divideInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject remainderInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject quotientAndRemainderInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject exptInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject maxInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject minInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject andInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject orInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject xorInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject gcdInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject lcmInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modAddInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modSubtractInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modMultiplyInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modDivideInteger(LispBigInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    boolean eqnInteger(LispBigInteger a) throws Exception
    {
        return false;
    }

    boolean neqnInteger(LispBigInteger a) throws Exception
    {
        return true;
    }

    boolean geInteger(LispBigInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean geqInteger(LispBigInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean leInteger(LispBigInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean leqInteger(LispBigInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    LispObject addSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject subtractSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject multiplySmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject divideSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject remainderSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject quotientAndRemainderSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject exptSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject maxSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject minSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject andSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject orSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject xorSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject gcdSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject lcmSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modAddSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modSubtractSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modMultiplySmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    LispObject modDivideSmallInteger(LispSmallInteger a) throws Exception
    {
        return Jlisp.error("Number needed", this);
    }

    boolean eqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return false;
    }

    boolean neqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return true;
    }

    boolean geSmallInteger(LispSmallInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean geqSmallInteger(LispSmallInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean leSmallInteger(LispSmallInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

    boolean leqSmallInteger(LispSmallInteger a) throws Exception
    {
        Jlisp.error("Number needed", this);
        return false;
    }

}

// End of LispObject.java

