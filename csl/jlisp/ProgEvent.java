//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

class ProgEvent extends LispException
{
    static final int STOP     = 2;
    static final int RESTART  = 3;
    static final int THROW    = 4;
    static final int PRESERVE = 5;
    
    LispObject details;
    LispObject extras;
    String message;
    int type;

    ProgEvent(int type, LispObject details, String message)
    {
        this.type = type;
        this.details = details;
        this.extras = null;
        this.message = message; 
    }

    ProgEvent(int type, LispObject details, LispObject extras, String message)
    {
        this.type = type;
        this.details = details;
        this.extras = extras;
        this.message = message; 
    }

}
