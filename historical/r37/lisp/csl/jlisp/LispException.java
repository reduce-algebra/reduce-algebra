//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

class LispException extends Exception
{
    LispObject details;
    String message;
    
    LispException()
    {
        this.message = "unknown"; 
	this.details = Jlisp.nil;
    }
    
    LispException(String message)
    {
        this.message=message;
	this.details=null; 
    }
    
    LispException(String message, LispObject details)
    {
        this.message = message;
	this.details = details; 
    }
}
