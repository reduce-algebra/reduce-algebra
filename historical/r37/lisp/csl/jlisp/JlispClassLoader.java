// 26/02/02 Load a class and return an instance of it.

import java.io.*;
import java.lang.reflect.*;

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

