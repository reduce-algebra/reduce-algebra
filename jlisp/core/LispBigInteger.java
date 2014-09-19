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


import java.math.*;
import java.io.*;
import java.util.*;

class LispBigInteger extends LispInteger
{
    BigInteger value;

    LispBigInteger(int value)
    {
        this.value = BigInteger.valueOf((long)value);
    }

    LispBigInteger(long value)
    {
        this.value = BigInteger.valueOf(value);
    }

    LispBigInteger(BigInteger value)
    {
        this.value = value;
    }

    int intValue() throws Exception
    {
        int n;
        if (value.bitLength() <= 31 &&
            (n = value.intValue()) <= 0x3fffffff &&
            n >= -0x40000000) return n;
        Jlisp.error("Integer is too large", this);
        return 0; // never reached
    }

    BigInteger bigIntValue()
    {
        return value;
    }

    LispObject eval()
    {
        return this;
    }

    String printAs()
    {
        if ((currentFlags & (printBinary | printOctal | printHex)) == 0)   
            return value.toString();
        else if ((currentFlags & printBinary) != 0)
            return value.toString(2);
        else if ((currentFlags & printOctal) != 0)
            return value.toString(8);
        else // if ((currentFlags & printHex) != 0)
            return value.toString(16);
    }

    void iprint() throws ResourceException
    {
        String s = printAs();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint() throws ResourceException
    {
        String s = printAs();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
    }

    double doubleValue()
    {
        return value.doubleValue();
    }

    public boolean lispequals(Object b)
    {
        if (!(b instanceof LispBigInteger)) return false;
        return value.compareTo(((LispBigInteger)b).value) == 0;
    }
    
    public boolean equals(Object b)
    {
        if (!(b instanceof LispBigInteger)) return false;
	return value.compareTo(((LispBigInteger)b).value) == 0;
    }

    public int lisphashCode()
    {
        return value.hashCode();
    }
    
    public int hashCode()
    {
        return value.hashCode();
    }
    
    void scan()
    {
        if (Jlisp.objects.contains(value)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(value))
	    {   Jlisp.repeatedObjects.put(
	            value,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else Jlisp.objects.add(value);
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(value);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            value,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
// Now this is the first time I see this integer while writing a dump
// file. I will put out a byte that says "here comes an integer", then
// the number of bytes used to represent it, and finally the set of bytes
// concerned. To save a little space I have variants to cope with the
// various possible sizes of length-code needed.
	    byte [] rep = value.toByteArray();
	    int length = rep.length;
	    putPrefix2(length, X_INTn, X_INT);
	    for (int i=0; i<length; i++)
	        Jlisp.odump.write(rep[i]);
	}
    }

    public LispObject negate() throws Exception
    {
        return valueOf(value.negate());
    }

    public LispObject abs() throws Exception
    {
        if (value.signum() >= 0) return this;
        else return valueOf(value.negate());
    }

    public LispObject msd() throws Exception
    {
        return valueOf(value.bitLength());
    }

    public LispObject lsd() throws Exception
    {
        return valueOf(value.getLowestSetBit());
    }

    public LispObject not() throws Exception
    {
        return valueOf(value.not());
    }

    public LispObject reduceMod() throws Exception
    {
        return valueOf(value.mod(Jlisp.bigModulus));
    }

    public LispObject add1() throws Exception
    {
        return valueOf(value.add(BigInteger.ONE));
    }

    public LispObject sub1() throws Exception
    {
        return valueOf(value.subtract(BigInteger.ONE));
    }

    public LispObject floor() throws Exception
    {
        return this;
    }

    public LispObject ceiling() throws Exception
    {
        return this;
    }

    public LispObject round() throws Exception
    {
        return this;
    }

    public LispObject truncate() throws Exception
    {
        return this;
    }

    public LispObject ash(int n) throws Exception
    {
        if (n > 0) return valueOf(value.shiftLeft(n));
        else if (n < 0) return valueOf(value.shiftRight(-n));
        else return this;
    }

    public LispObject ash1(int n) throws Exception
    {
        if (n > 0) return valueOf(value.shiftLeft(n));
        else if (n < 0)
        {   if (value.signum() >= 0)
                return valueOf(value.shiftRight(-n));
            else return valueOf(value.negate().shiftRight(-n).negate());
        }
        else return this;
    }

    public LispObject leftshift(int n) throws Exception
    {
        return valueOf(value.shiftLeft(n));
    }

    public LispObject rightshift(int n) throws Exception
    {
        return valueOf(value.shiftRight(n));
    }

    public LispObject evenp() throws Exception
    {
        return value.testBit(0) ? Jlisp.nil : Jlisp.lispTrue;
    }

    public LispObject oddp() throws Exception
    {
        return value.testBit(0) ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject fix() throws Exception
    {
        return this;
    }

    public LispObject fixp() throws Exception
    {
        return Jlisp.lispTrue;
    }

    public LispObject integerp() throws Exception
    {
        return Jlisp.lispTrue;
    }

    public LispObject jfloat() throws Exception
    {
        return new LispFloat(value.doubleValue());
    }

    public LispObject floatp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject minusp() throws Exception
    {
        return value.signum() < 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject plusp() throws Exception
    {
        return value.signum() >= 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject zerop() throws Exception
    {
        return value.signum() == 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject onep() throws Exception
    {
        return (value.compareTo(BigInteger.ONE) == 0) ? 
               Jlisp.lispTrue :
               Jlisp.nil;
    }

    public LispObject add(LispObject a) throws Exception
    {
        return a.addInteger(this);
    }

    public LispObject subtract(LispObject a) throws Exception
    {
        return a.subtractInteger(this);
    }

    public LispObject multiply(LispObject a) throws Exception
    {
        return a.multiplyInteger(this);
    }

    public LispObject expt(LispObject a) throws Exception
    {
        return a.exptInteger(this);
    }

    public LispObject divide(LispObject a) throws Exception
    {
        return a.divideInteger(this);
    }

    public LispObject remainder(LispObject a) throws Exception
    {
        return a.remainderInteger(this);
    }

    public LispObject quotientAndRemainder(LispObject a) throws Exception
    {
        return a.quotientAndRemainderInteger(this);
    }

    public LispObject mod(LispObject a) throws Exception
    {
        return a.modInteger(this);
    }

    public LispObject max(LispObject a) throws Exception
    {
        return a.maxInteger(this);
    }

    public LispObject min(LispObject a) throws Exception
    {
        return a.minInteger(this);
    }

    public LispObject and(LispObject a) throws Exception
    {
        return a.andInteger(this);
    }

    public LispObject or(LispObject a) throws Exception
    {
        return a.orInteger(this);
    }

    public LispObject xor(LispObject a) throws Exception
    {
        return a.xorInteger(this);
    }

    public LispObject gcd(LispObject a) throws Exception
    {
        return a.gcdInteger(this);
    }

    public LispObject lcm(LispObject a) throws Exception
    {
        return a.lcmInteger(this);
    }

    boolean eqn(LispObject a) throws Exception
    {
        return a.eqnInteger(this);
    }

    boolean neqn(LispObject a) throws Exception
    {
        return a.neqnInteger(this);
    }

    boolean ge(LispObject a) throws Exception
    {
        return a.geInteger(this);
    }

    boolean geq(LispObject a) throws Exception
    {
        return a.geqInteger(this);
    }

    boolean le(LispObject a) throws Exception
    {
        return a.leInteger(this);
    }

    boolean leq(LispObject a) throws Exception
    {
        return a.leqInteger(this);
    }

// now versions that know they have 2 integer args

    public LispObject addInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.add(value));
    }

    public LispObject subtractInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.subtract(value));
    }

    public LispObject multiplyInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.multiply(value));
    }

    public LispObject divideInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.divide(value));
    }

    public LispObject remainderInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.remainder(value));
    }

    public LispObject quotientAndRemainderInteger(LispBigInteger a) throws Exception
    {
        BigInteger [] r = a.value.divideAndRemainder(value);
        return new Cons(valueOf(r[0]), valueOf(r[1]));
    }

    public LispObject modInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.mod(value));
    }

    public LispObject exptInteger(LispBigInteger a) throws Exception
    {
        switch (value.signum())
        {
    case -1: return valueOf(0);
    case 0:  return valueOf(1);
    default:
             if (value.bitLength() > 15)
                 return Jlisp.error("integer result would be too large");
             else return valueOf(a.value.pow(value.intValue()));
        }
    }

    public LispObject maxInteger(LispBigInteger a) throws Exception
    {
        if (a.value.compareTo(value) >= 0) return a;
        else return this;
    }

    public LispObject minInteger(LispBigInteger a) throws Exception
    {
        if (a.value.compareTo(value) <= 0) return a;
        else return this;
    }

    public LispObject andInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.and(value));
    }

    public LispObject orInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.or(value));
    }

    public LispObject xorInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.xor(value));
    }

    public LispObject gcdInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.gcd(value));
    }

    public LispObject lcmInteger(LispBigInteger a) throws Exception
    {
        return valueOf(biglcm(a.value, value));
    }

    public boolean eqnInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) == 0);
    }

    public boolean neqnInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) != 0);
    }

    public boolean geInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) > 0);
    }

    public boolean geqInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) >= 0);
    }

    public boolean leInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) < 0);
    }

    public boolean leqInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(value) <= 0);
    }

// Finally versions that mix big and small integers. I will generally cope by
// converting the small integer to a big one.

    LispObject addSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).add(value));
    }

    LispObject subtractSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).subtract(value));
    }

    LispObject multiplySmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).multiply(value));
    }

    LispObject divideSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).divide(value));
    }

    LispObject remainderSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).remainder(value));
    }

    LispObject quotientAndRemainderSmallInteger(LispSmallInteger a) throws Exception
    {
        BigInteger [] r = BigInteger.valueOf((long)a.value).divideAndRemainder(value);
        return new Cons(valueOf(r[0]), valueOf(r[1]));
    }

    LispObject modSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).mod(value));
    }

    LispObject exptSmallInteger(LispSmallInteger a) throws Exception
    {
        switch (value.signum())
        {
    case -1: return valueOf(0);
    case 0:  return valueOf(1);
    default:
             if (value.bitLength() > 15)
                 return Jlisp.error("integer result would be too large");
             else return valueOf(BigInteger.valueOf((long)a.value).pow(value.intValue()));
        }
    }

    LispObject maxSmallInteger(LispSmallInteger a) throws Exception
    {
        if (BigInteger.valueOf((long)a.value).compareTo(value) >= 0) return a;
        else return this;
    }

    LispObject minSmallInteger(LispSmallInteger a) throws Exception
    {
        if (BigInteger.valueOf((long)a.value).compareTo(value) <= 0) return a;
        else return this;
    }

    LispObject andSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).and(value));
    }

    LispObject orSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).or(value));
    }

    LispObject xorSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).xor(value));
    }

    LispObject gcdSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(BigInteger.valueOf((long)a.value).gcd(value));
    }

    LispObject lcmSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(biglcm(BigInteger.valueOf((long)a.value), value));
    }

    boolean eqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) == 0);
    }

    boolean neqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) != 0);
    }

    boolean geSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) > 0);
    }

    boolean geqSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) >= 0);
    }

    boolean leSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) < 0);
    }

    boolean leqSmallInteger(LispSmallInteger a) throws Exception
    {
        return (BigInteger.valueOf((long)a.value).compareTo(value) <= 0);
    }


    static public BigInteger biglcm(BigInteger a, BigInteger b)
    {
        a = a.abs();
        b = b.abs();
        if (a.equals(BigInteger.ZERO) &&
            b.equals(BigInteger.ZERO)) return BigInteger.ONE;
        BigInteger g = a.gcd(b);
        b = b.divide(g);
        return a.multiply(b);
    }
}

// End of LispBigInteger.java


