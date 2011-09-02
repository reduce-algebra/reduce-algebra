//24/02/02 created for seeing if I have all tools necessary for Lisp
class NullFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1)
    {
        return arg1 == Jlisp.nil ?
               Jlisp.lispTrue :
               Jlisp.nil;
    }
}