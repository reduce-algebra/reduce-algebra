class CarFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        if (arg1.atom) return error("Attempt to take car of an atom");
        else return arg1.car;
    }
}