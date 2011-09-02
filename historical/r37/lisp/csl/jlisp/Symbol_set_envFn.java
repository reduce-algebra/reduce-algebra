//07/03/02
//purely made for testing and looking at jvm Bytecodes by javap -c

class Symbol_set_envFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        if (!(arg1 instanceof Symbol)) return Jlisp.nil;
        LispFunction f = ((Symbol)arg1).fn;
        if (f instanceof FnWithEnv) 
            ((FnWithEnv)f).env = ((LispVector)arg2).vec;
        else return Jlisp.nil; // quiet in case it fails?
        return ((Symbol)((FnWithEnv)f).env[0]).fn.op0();
				//return arg2;
    }
}