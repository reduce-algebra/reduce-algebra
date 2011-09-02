//24/02/02 created for seeing if I have all tools necessary for Lisp
class AtomFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1)
    {   return arg1.atom ? Jlisp.lispTrue :
                           Jlisp.nil;
    }
}