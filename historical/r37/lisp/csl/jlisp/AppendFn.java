class AppendFn extends BuiltinFunction
{
    public LispObject op0()
    { return Jlisp.nil; }
    public LispObject op1(LispObject arg1)
    { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2)
    {
        LispObject r = Jlisp.nil;
        while (!arg1.atom)
        {   LispObject a = arg1;
            r = new Cons(a.car, r);
            arg1 = a.cdr;
        }
        while (!r.atom)
        {   LispObject a = r;
            r = a.cdr;
            a.cdr = arg2;
            arg2 = a;
        }
        return arg2;
    }
    public LispObject opn(LispObject [] args)
    {
        int n = args.length;
        LispObject r = args[--n];
        for (int i=n-1; i>=0; i--)
        {   r = op2(args[i], r);
        }
        return r;
    }
}