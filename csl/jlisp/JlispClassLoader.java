// 26/02/02 Load a class and return an instance of it.

import java.io.*;
import java.lang.reflect.*;

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


public class JlispClassLoader extends ClassLoader 
// ClassLoader
{

    Object loadMyInstance(String className, byte [] bytes)
    {
        //ByteArray.printBytes(bytes);
        try
        {   Class newClass = defineClass(className, bytes, 0, bytes.length);
            resolveClass(newClass);
            return newClass.newInstance();
        }
        catch (VerifyError e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (ClassFormatError e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (InstantiationException e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (IllegalAccessException e)
        {   Jlisp.println("Error: " + e);
            return null;
        }
    }

    Object loadMyInstance(String className)
    {
        try
        {   Class newClass = loadClass(className, true);
            return newClass.newInstance();
        }
        catch (VerifyError e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (ClassNotFoundException e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (InstantiationException e)
        {   Jlisp.println("Error: " + e);
            return Jlisp.nil;
        }
        catch (IllegalAccessException e)
        {   Jlisp.println("Error: " + e);
            return null;
        }
    }


}


// end of JlispClassLoader.java 

