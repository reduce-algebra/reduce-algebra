//24/02/02 created for seeing if I have all tools necessary for Lisp
class CdrFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        if (arg1.atom) return error("Attempt to take cdr of an atom");
        else return arg1.cdr;
    }
}