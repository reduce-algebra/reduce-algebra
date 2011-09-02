class ReverseFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1)
    {
        LispObject r = Jlisp.nil;
        while (!arg1.atom)
	{   LispObject a = arg1;
            r = new Cons(a.car, r);
            arg1 = a.cdr;
        }
        return r;
    }
}