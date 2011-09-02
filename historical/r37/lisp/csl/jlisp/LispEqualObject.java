//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

// This class exists just so that I can hash LispObjects using an EQUAL
// test. I do so by wrapping them up as LispEqualObjects at which stage the
// relevant methods emerge.

class LispEqualObject extends Object
{
    LispObject value;

    LispEqualObject(Object a)
    {   this.value = (LispObject)a;
    }

    public boolean equals(Object b)
    {
        if (!(b instanceof LispEqualObject)) return false;
	return value.lispequals(((LispEqualObject)b).value);
    }

    public int hashCode()
    {   return value.lisphashCode();
    }

}

// end of LispEqualObject.java
