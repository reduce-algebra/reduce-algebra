//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class TracedFunction extends LispFunction
{
    Symbol name;
    LispFunction fn;
    static int traceDepth = 0;
        
    TracedFunction(Symbol name, LispFunction fn)
    {
        this.name = name;
        this.fn = fn;
    }
    
    void indent()
    {
        for (int i=0; i<traceDepth; i++)
	    Jlisp.traceprint(" ");
    }
    
    public LispObject op0() throws Exception
    {
        indent();
        Jlisp.traceprint("Calling "); name.tracePrint();
	Jlisp.traceprintln(" with 0 args");
	traceDepth++;
        LispObject r = fn.op0();
	traceDepth--;
	indent();
	name.tracePrint(); Jlisp.traceprint(" = ");
	r.tracePrint(); Jlisp.traceprintln();
        return r;
    }

    public LispObject op1(LispObject a1) throws Exception
    {
        indent();
        Jlisp.traceprint("Calling "); name.tracePrint();
	Jlisp.traceprintln();
	indent();
	Jlisp.traceprint("Arg1: "); a1.tracePrint();
	Jlisp.traceprintln();
	traceDepth++;
        LispObject r = fn.op1(a1);
	traceDepth--;
	indent();
	name.tracePrint(); Jlisp.traceprint(" = ");
	r.tracePrint(); Jlisp.traceprintln();
        return r;
    }

    public LispObject op2(LispObject a1, LispObject a2) throws Exception
    {
        indent();
        Jlisp.traceprint("Calling "); name.tracePrint();
	Jlisp.traceprintln();
	indent();
	Jlisp.traceprint("Arg1: "); a1.tracePrint();
	Jlisp.traceprintln();
	indent();
	Jlisp.traceprint("Arg2: "); a2.tracePrint();
	Jlisp.traceprintln();
	traceDepth++;
        LispObject r = fn.op2(a1, a2);
	traceDepth--;
	indent();
	name.tracePrint(); Jlisp.traceprint(" = ");
	r.tracePrint(); Jlisp.traceprintln();
        return r;
    }

    public LispObject opn(LispObject [] args) throws Exception
    {
        indent();
        Jlisp.traceprint("Calling "); name.tracePrint();
	Jlisp.traceprintln();
	for (int i=0; i<args.length; i++)
	{   indent();
	    Jlisp.traceprint("Arg" + i + ": ");
	    args[i].tracePrint();
	    Jlisp.traceprintln();
	}
	traceDepth++;
        LispObject r = fn.opn(args);
	traceDepth--;
	indent();
	name.tracePrint(); Jlisp.traceprint(" = ");
	r.tracePrint(); Jlisp.traceprintln();
        return r;
    }

    void print()
    {
        Jlisp.print("Traced:");
	name.print();
    }

    void print(int n)
    {
        Jlisp.print("Traced:");
	name.print(n);
    }
    
// If you take a checkpoint image and some functions are traced then
// in the dump the fact of tracing is thrown away and when an image is
// re-loaded the functions will not be traced any more. I could have
// saved trace info if I had wanted but this is MARGINALLY easier and
// perhaps in some ways nicer?
    
    void scan()
    {
        fn.scan();
    }
    
    void dump() throws IOException
    {
        fn.dump();
    }

}

// End of TracedFunction.java


