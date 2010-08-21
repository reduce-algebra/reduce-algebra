public class StaticFns 
{
	static LispObject cons(LispObject a, LispObject b)
	{
		return new Cons(a, b);
	}
	static LispObject cons3(LispObject a, LispObject b, LispObject c)
	{
		return new Cons(a, new Cons(b, c));
	}
}