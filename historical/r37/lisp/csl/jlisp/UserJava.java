
// This is to demonstrate how user Java code can be called from Jlisp.
// You may edit this file to put in arbitrary Java definitions in the
// various methods (which had better be public static and named as shown 
// here). 
//
// From within Jlisp (and hence REDUCE) the function USERJAVA will then
// call the method from here that corresponds to the relevant number of
// arguments. This class MUST be called "UserJava" but it is loaded
// dynamically when Jlisp is running and when the first use of it is
// attempted. So the class file must be somewhere that the default Java
// classloader will look. But this file does NOT need to be present when
// Jlisp is built.
//

public class UserJava
{
    public static LispObject op0()
    {
        return new LispString("Sample");
    }

    public static LispObject op1(LispObject a)
    {
        return new Cons(a, a);
    }

    public static LispObject op2(LispObject a, LispObject b)
    {
        return new Cons(b, a);
    }

    public static LispObject opn(LispObject [] a)
    {
        LispObject r = Jlisp.nil;
        for (int i=0; i<a.length; i++)
            r = new Cons(a[i], r);
        return r;
    }
}
