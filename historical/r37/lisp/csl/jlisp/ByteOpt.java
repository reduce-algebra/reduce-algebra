//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

class ByteOpt extends Bytecode
{

// nargs is inherited from Bytecode.
//  treated here as (flags/nopts/nargs) in 2:8:8 bits

// flags & 1     use Spid.noarg not nil as default
// flags & 2     use a &rest argument
//(flags & 4)    (marks a CallAs...)

// The code here seems pretty messy and sordid. Perhaps I can think
// harder some-time and write a cleaned up version!

ByteOpt(byte [] b, LispObject [] e, int w, int o, int fg)
{
    bytecodes = b;
    env = e;
    nargs = w + (o<<8) + (fg<<16);
}

ByteOpt(int packed)
{
    bytecodes = null;
    env = new LispObject [0];
    nargs = packed;
}

public LispObject op0() throws Exception
{
    if ((nargs & 0xff) > 0) error("not enough arguments");
    int spsave = sp;
    LispObject r;
    for (int i = 0; i<((nargs>>8)&0xff); i++)
        stack[++sp] = (nargs & 0x10000) != 0 ? (LispObject)Spid.noarg : (LispObject)Jlisp.nil;
    if ((nargs & 0x20000) != 0) stack[++sp] = Jlisp.nil;
    try
    {   r = interpret(2);
    }
    finally
    {   sp = spsave;
    }
    return r;
}

public LispObject op1(LispObject a1) throws Exception
{
    if ((nargs & 0xff) > 1) error("not enough arguments");
    int spsave = sp;
    if ((nargs & 0xff) == 0 && ((nargs>>8)&0xff) == 0)
    {   if ((nargs & 0x20000)==0) error("too many args");
        stack[++sp] = new Cons(a1, Jlisp.nil); // all in the &rest arg
    }
    else
    {   stack[++sp] = a1;
        for (int i = 0; i<(nargs & 0xff)+((nargs>>8)&0xff)-1; i++)
            stack[++sp] = (nargs & 0x10000) != 0 ? (LispObject)Spid.noarg : (LispObject)Jlisp.nil;
        if ((nargs & 0x20000) != 0) stack[++sp] = Jlisp.nil;
    }
    LispObject r;
    try
    {   r = interpret(2);
    }
    finally
    {   sp = spsave;
    }
    return r;
}

public LispObject op2(LispObject a1, LispObject a2) throws Exception
{
    if ((nargs & 0xff) > 2) error("not enough arguments");
    int spsave = sp;
    switch ((nargs & 0xff)+((nargs>>8)&0xff))
    {
case 0: if ((nargs & 0x20000)==0) error("too many args");
        stack[++sp] = new Cons(a1, new Cons(a2, Jlisp.nil));
        break;
case 1: if ((nargs & 0x20000)==0) error("too many args");
        stack[++sp] = a1; // will be either needed or optional
        stack[++sp] = new Cons(a2, Jlisp.nil);
        break;
case 2: stack[++sp] = a1;
        stack[++sp] = a2;
        if ((nargs & 0x20000)!=0) stack[++sp] = Jlisp.nil;
        break;
default:stack[++sp] = a1;
        stack[++sp] = a2;
        for (int i = 0; i<(nargs & 0xff)+((nargs>>8)&0xff)-2; i++)
            stack[++sp] = (nargs & 0x10000) != 0 ? (LispObject)Spid.noarg : (LispObject)Jlisp.nil;
        if ((nargs & 0x20000) != 0) stack[++sp] = Jlisp.nil;
    }
    LispObject r;
    try
    {   r = interpret(2);
    }
    finally
    {   sp = spsave;
    }
    return r;
}

public LispObject opn(LispObject [] args) throws Exception
{
// @@@
    error("byteopt call with 3 or more args not yet implemented, sorry");
    return Jlisp.nil;
}

}

// End of ByteOpt.java

