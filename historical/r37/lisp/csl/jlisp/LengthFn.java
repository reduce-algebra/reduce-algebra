class LengthFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1)
    {
        int n = 0;
        while (!arg1.atom)
        {   n++;
            arg1 = arg1.cdr;
        }
        return LispInteger.valueOf(n);
    }
}