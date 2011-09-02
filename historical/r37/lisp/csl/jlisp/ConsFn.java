//24/02/02 created for seeing if I have all tools necessary for Lisp
class ConsFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2)
    {   return new Cons(arg1, arg2);
    }
}