//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//



import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

// Support for "special functions"

class Specfn
{

    static int        progEvent = 0;
    static LispObject progData  = null;

    static final int NONE   = 0;
    static final int GOTO   = 1;
    static final int RETURN = 2;


    Object [][] specials = 
    {
        {"cond",     new CondSpecial()},
        {"quote",    new QuoteSpecial()},
        {"function", new FunctionSpecial()},
        {"lambda",   new LambdaSpecial()},
        {"defun",    new DefunSpecial()},
        {"de",       new DefunSpecial()},
        {"dm",       new DmSpecial()},
        {"go",       new GoSpecial()},
        {"setq",     new SetqSpecial()},
        {"if",       new IfSpecial()},
        {"when",     new WhenSpecial()},
        {"unless",   new UnlessSpecial()},
        {"block",    new BlockSpecial()},
        {"~let",     new LetSpecial()},
        {"let*",     new LetStarSpecial()},
        {"prog",     new ProgSpecial()},
        {"and",      new AndSpecial()},
        {"or",       new OrSpecial()},
        {"plus",     new PlusSpecial()},
        {"times",    new TimesSpecial()},
        {"list",     new ListSpecial()},
        {"list*",    new ListStarSpecial()},
    };



// (quote xx) evaluates to just xx

class QuoteSpecial extends SpecialFunction
{
    LispObject op(LispObject args)
    {
        if (args.atom) return Jlisp.nil;
        else return args.car;
    }
}

// in an ideal world (function xxx) would create a closure.
// however my Lisp implementation is shallow-bound and so this is
// not a (convenient) option. I therefore make it a synonym for
// quote.

class FunctionSpecial extends SpecialFunction
{
    LispObject op(LispObject args)
    {
        if (args.atom) return Jlisp.nil;
        else return args.car;
    }
}

// (lambda (x) A B C) evaluates to itself, as a minor convenience

class LambdaSpecial extends SpecialFunction
{
    LispObject op(LispObject args)
    {
        return new Cons(Jlisp.lit[Lit.lambda], args);
    }
}

// (cond (p1 e1)        if p1 then e1
//       (p2 e2)        else if p2 then e2
//       (p3 e3) )      else if p3 then e3
//                      else nil

class CondSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {   while (!args.atom)
        {   LispObject a = args;  // ((p1 e1) ...) 
            LispObject x = a.car; // (p1 e1)
            args = a.cdr;
            if (x.atom) continue;
            LispObject predicate = x.car;   // p1
            LispObject consequent = x.cdr;  // (e1)
            predicate = predicate.eval();
            if (progEvent != NONE) return Jlisp.nil;
            if (predicate != Jlisp.nil)
            {   LispObject r = Jlisp.nil;
                while (!consequent.atom)
                {   LispObject cc = consequent;
                    r = cc.car.eval();
                    if (progEvent != NONE) return Jlisp.nil;
                    consequent = cc.cdr;
                }
                return r;
            }
        }
        return Jlisp.nil;
    }
}

class IfSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return Jlisp.nil;
        LispObject c1 = args;     // car is the predicate
        if (c1.cdr.atom)
        {   c1.car.eval();        // degenerate case (IF p)
            return Jlisp.nil;
        }
        LispObject c2 = c1.cdr; // car is the consequent
        c1 = c1.car.eval();
        if (progEvent != NONE) return Jlisp.nil;
        if (c1 != Jlisp.nil) return c2.car.eval();
        args = c2.cdr;
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   c2 = args;
            r = c2.car.eval();
            if (progEvent != NONE) return Jlisp.nil;
            args = c2.cdr;
        }
        return r;
    }
}

class WhenSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return Jlisp.nil;
        LispObject c = args;
        if (c.car.eval() == Jlisp.nil) return Jlisp.nil;
        if (progEvent != NONE) return Jlisp.nil;
        args = c.cdr;
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   c = args;
            r = c.car.eval();
            if (progEvent != NONE) return Jlisp.nil;
            args = c.cdr;
        }
        return r;   
    }
}

class UnlessSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return Jlisp.nil;
        LispObject c = args;
        if (c.car.eval() != Jlisp.nil) return Jlisp.nil;
        if (progEvent != NONE) return Jlisp.nil;
        args = c.cdr;
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   c = args;
            r = c.car.eval();
            if (progEvent != NONE) return Jlisp.nil;
            args = c.cdr;
        }
        return r;   
    }
}

// (defun name (a1 a2 a3) body-of-function(with implied progn))

class DefunSpecial extends SpecialFunction
{
    LispObject op(LispObject a) throws Exception
    {
        if (a.atom) return Jlisp.nil;  // (de) with no args at all!
        Symbol name = (Symbol)(a.car);
        name.fn = new Interpreted(a.cdr);
        if (Jlisp.lit[Lit.starcomp].car/*value*/ != Jlisp.nil &&
            !(((Symbol)Jlisp.lit[Lit.compile]).fn instanceof Undefined))
        {   a = new Cons(name , Jlisp.nil);
            ((Symbol)Jlisp.lit[Lit.compile]).fn.op1(a);
        }
        return name;
    }
}

class DmSpecial extends SpecialFunction
{
    LispObject op(LispObject a) throws Exception
    {
        if (a.atom) return Jlisp.nil;
        Symbol name = (Symbol)a.car;
        name.fn = new Macro(a.cdr);
        if (Jlisp.lit[Lit.starcomp].car/*value*/ != Jlisp.nil &&
            !(((Symbol)Jlisp.lit[Lit.compile]).fn instanceof Undefined))
        {   a = new Cons(name , Jlisp.nil);
            ((Symbol)Jlisp.lit[Lit.compile]).fn.op1(a);
        }
        return name;
    }
}

class SetqSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        LispObject value = Jlisp.nil;
        Symbol name;
        while (!args.atom)
        {   name = (Symbol)args.car;
            args = args.cdr;
            if (!args.atom)
            {   value = args.car.eval();
                if (progEvent != NONE) return Jlisp.nil;
                args = args.cdr;
            }
            else value = Jlisp.nil;
            name.car/*value*/ = value;
        }
        return value;
    }
}

class BlockSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {    return error("BLOCK not implemented yet");
    }
}

class LetSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {    return error("LET not implemented yet");
    }
}

class LetStarSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {    return error("LET* not implemented yet");
    }
}


class GoSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {    
        if (args.atom) 
            return error("go called without an argument");
        progEvent = GOTO;
        progData = args.car;
        return Jlisp.nil;
    }
}

class ProgSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return Jlisp.nil; // (PROG)
        LispObject bvl = args.car;
        args = args.cdr;
        if (args.atom) return Jlisp.nil; // (PROG (v))
        int nvars = 0;
        LispObject bvlsave = bvl;
        while (!bvl.atom)
        {   LispObject w = bvl;
// I really want to check that all the items are symbols here because
// I want the code that saves away values to be guaranteed to succeed
// so that I can be certain not to leave a mess because of things crashing
// part way through
            if (!(w.car instanceof Symbol))
                return error("non-symbol in variable list for prog");
            bvl = w.cdr;
            nvars++;
        }
        LispObject [] save = new LispObject [nvars];
        bvl = bvlsave;
        for (int i=0; i<nvars; i++)
        {   LispObject w = bvl;
            Symbol name = (Symbol)(w.car);
            bvl = w.cdr;
            save[i] = name.car/*value*/;
            name.car/*value*/ = Jlisp.nil;
        }
        try
        {   LispObject pc = args;
            while (!pc.atom)
            {   LispObject s = pc.car;
                pc = pc.cdr;
                if (!s.atom)
                {   
                    s.eval();
                    switch (progEvent)
                    {
                case RETURN:
                        s = progData;
                        progEvent = NONE;
                        progData = Jlisp.nil;
                        return s;
                case GOTO:
                        pc = args;
                        while (!pc.atom)
                        {   if (pc.car == progData) break;
                            pc = pc.cdr;
                        }
                        progEvent = NONE;
                        progData = Jlisp.nil;
                        if (!pc.atom) pc = pc.cdr;
                        else return error("label not found in GO");
                        continue;
                default:
                        continue;
                    }
                }
            }
        }
        finally
        {   bvl = bvlsave;
// Here I restore variables in the same left to right order
// that I saved them. This causes a mess if a name is used
// twice in the list! But working backwards seems unnecessarily
// hard to do (without wasting too much time & space).
            for (int i=0; i<nvars; i++)
            {   LispObject w = bvl;
                Symbol name = (Symbol)(w.car);
                bvl = w.cdr;
                name.car/*value*/ = save[i];
            }
        }
// If the prog block terminates by dropping off the end I
// will give back the result NIL.
        return Jlisp.nil;
    }
}

class AndSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        LispObject r = Jlisp.lispTrue;
        while (!args.atom)
        {   r = args.car.eval();
            if (progEvent != NONE || r == Jlisp.nil) break;
            args = args.cdr;
        }
        return r;
    }
}

class OrSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   r = args.car.eval();
            if (progEvent != NONE || r != Jlisp.nil) break;
            args = args.cdr;
        }
        return r;
    }
}

class PlusSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return LispInteger.valueOf(0);
        LispObject r = args.car.eval();
        args = args.cdr;
        while (!args.atom)
        {   r = r.add(args.car.eval());
            args = args.cdr;
        }
        return r;
    }
}

class TimesSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return LispInteger.valueOf(1);
        LispObject r = args.car.eval();
        args = args.cdr;
        while (!args.atom)
        {   r = r.multiply(args.car.eval());
            args = args.cdr;
        }
        return r;
    }
}

class ListSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   r = new Cons(args.car.eval(), r);
            args = args.cdr;
        }
        args = Jlisp.nil;
        while (!r.atom)
        {   LispObject w = r;
            r = r.cdr;
            w.cdr = args;
            args = w;
        }
        return args;
    }
}

class ListStarSpecial extends SpecialFunction
{
    LispObject op(LispObject args) throws Exception
    {
        if (args.atom) return error("list* with no args");
        LispObject r = Jlisp.nil;
        while (!args.atom)
        {   r = new Cons(args.car.eval(), r);
            args = args.cdr;
        }
        args = r.car;
        r = r.cdr;
        while (!r.atom)
        {   LispObject w = r;
            r = r.cdr;
            w.cdr = args;
            args = w;
        }
        return args;
    }
}

}

// End of Specfn.java

