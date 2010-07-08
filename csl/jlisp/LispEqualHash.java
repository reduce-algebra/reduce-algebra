//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

import java.util.*;

class LispEqualHash extends HashMap
{

    public Object put(Object key, Object value)
    {
        super.put(new LispEqualObject(key), value);
        return value;
    }

    public Object get(Object key)
    {
        return super.get(new LispEqualObject(key));
    }

    public Object remove(Object key)
    {
        return super.remove(new LispEqualObject(key));
    }

}

// end of LispEqualHash.java
