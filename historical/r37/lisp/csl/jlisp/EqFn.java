//24/02/02 created for seeing if I have all tools necessary for Lisp
class EqFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2)
    {
        if (arg1 instanceof LispNumber)                                // @@@
            return arg1.lispequals(arg2) ? Jlisp.lispTrue : Jlisp.nil; // @@@
        else return arg1==arg2 ? Jlisp.lispTrue : Jlisp.nil;
    }
}