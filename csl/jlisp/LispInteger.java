//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//


import java.math.*;
import java.io.*;
import java.util.*;

abstract class LispInteger extends LispNumber
{

    static LispInteger valueOf(int value)
    {
        if (value <= LispSmallInteger.MAX &&
            value >= LispSmallInteger.MIN)
            return LispSmallInteger.preAllocated[value - LispSmallInteger.MIN];
        else if (value <= 0x3fffffff &&
            value >= -0x40000000) return new LispSmallInteger(value);
        else return new LispBigInteger(BigInteger.valueOf((long)value));
    }

    static LispInteger valueOf(long value)
    {
        if (value <= LispSmallInteger.MAX &&
            value >= LispSmallInteger.MIN)
            return LispSmallInteger.preAllocated[
                       (int)(value - LispSmallInteger.MIN)];
        else if (value <= 0x3fffffffL &&
            value >= -0x40000000L) return new LispSmallInteger((int)value);
        else return new LispBigInteger(BigInteger.valueOf(value));
    }

    static LispInteger valueOf(BigInteger value)
    {
        if (value.bitLength() <= 31)
        {   int n = value.intValue();
            if (n <= LispSmallInteger.MAX &&
                n >= LispSmallInteger.MIN)
                return LispSmallInteger.preAllocated[n - LispSmallInteger.MIN];
            else if (n <= 0x3fffffff &&
                     n >= -0x40000000) return new LispSmallInteger(n);
        }
        return new LispBigInteger(value);
    }


}

// End of LispInteger.java


