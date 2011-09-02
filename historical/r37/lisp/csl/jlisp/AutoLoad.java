//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.io.*;

class AutoLoad extends LispFunction
{

    Symbol name;
    LispObject data;
    
    AutoLoad(Symbol name, LispObject data)
    {
        this.name = name;
	this.data = data;
    }
    
    public LispObject op0() throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op0();
    }

    public LispObject op1(LispObject a1) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op1(a1);
    }

    public LispObject op2(LispObject a1, LispObject a2) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.op2(a1, a2);
    }

    public LispObject opn(LispObject [] args) throws Exception
    {
        name.fn = new Undefined(name.pname);
        Fasl.loadModule(data.car);
        return name.fn.opn(args);
    }

    void print()
    {
        Jlisp.print("#Autoload<" + name.pname + ">");
    }

    void print(int n)
    {
        Jlisp.print("#Autoload<" + name.pname + ">");
    }
    
    void scan()
    {
        if (Jlisp.objects.contains(this)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(this))
	    {   Jlisp.repeatedObjects.put(
	            this,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else
	{   Jlisp.objects.add(this);
	    Jlisp.stack.push(name);
	    Jlisp.stack.push(data);
	}
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w);
	else
	{   if (w != null)
	    {   Jlisp.repeatedObjects.put(
	            this,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
	    }
	    Jlisp.odump.write(X_AUTOLOAD);
	    Jlisp.stack.push(data);
	    Jlisp.stack.push(name);
	}
    }
    
}

// End of LispFunction.java


