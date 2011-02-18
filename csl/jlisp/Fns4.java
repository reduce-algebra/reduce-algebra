//    Date: 09/02/02
//    Name: Vijay P. Chauhan
//    Supervisor: Dr. Arthur Norman
//    "Jlisp to JVM Compiler" - Part II Project

// Fns4.java
// Amended 26/02/02 to accomodate for ClassDescription4.java
// see ClassFileTest4 for more info about the methods for making a class

// Each built-in function is created wrapped in a class
// that is derived from BuiltinFunction.

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

import java.io.*;
import java.util.*;
import java.util.zip.*;
import java.text.*;
import java.math.*;

class Fns4
{
    ClassDescription cd = new ClassDescription();
    Code_attribute ca = new Code_attribute();
    Method_info mi = new Method_info();
    // make sure same ca and mi are not used for additional methods

    Object [][] builtins = 
    {
        {"make-java-class",      new MakeJavaClassFn()},
        {"method-number",        new MethodNumberFn()},
        {"set-access",           new SetAccessFn()},
        {"add-code",             new AddCodeFn()},
        {"add-exceptions",       new AddExceptionsFn()},
        {"set-this",             new SetThisFn()},
        {"set-super",            new SetSuperFn()},
        {"add-class-info",       new AddClassInfoFn()},
        {"add-methodref",        new AddMethodrefFn()},
        {"add-fieldref",         new AddFieldrefFn()},
        {"make-init",            new MakeInitFn()},
        {"make-method",          new MakeMethodFn()},
        {"set-stack-locals",     new SetStackLocalsFn()},
        {"set-label",            new SetLabelFn()},
        {"lookup-label",         new LookupLabelFn()},
        {"lookup-ref",           new LookupRefFn()},
        {"lookup-cinfo",         new LookupCinfoFn()},
        {"add-instr",            new AddInstrFn()},
        {"add-instr-args",       new AddInstrArgsFn()},
        {"finish-method",        new FinishMethodFn()},
        {"make-cp",              new MakeCpFn()},
        {"resolve-all",          new ResolveAllFn()},
        {"print-cp",             new PrintCpFn()},
        {"finish-class",         new FinishClassFn()},
        {"print-bytes",          new PrintBytesFn()},    // not used    
        {"bytes-to-file",        new BytesToFileFn()},   // for debugging
        {"load-class",           new LoadClassFn()},     // deprecated
        {"instance-from-bytes",  new InstanceFromBytesFn()}
    };

class MakeJavaClassFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd = new ClassDescription();
        //Jlisp.println("MakeJavaClassFn called");
        return Jlisp.nil;
    }
}

class MethodNumberFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg) throws Exception
    {
        int mnumber = arg.intValue();
        cd.mNumber(mnumber);
        //Jlisp.println("MethodNumberFn called" + mnumber);
        return Jlisp.nil;
    }
}
 
class SetAccessFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.setAccess((short)(ClassDescription.ACC_PUBLIC |
                             ClassDescription.ACC_SUPER));
        //Jlisp.println("SetAccessFn called");
        return Jlisp.nil;
    }
}

class AddCodeFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.addCode();
        //Jlisp.println("AddCodeFn called");
        return Jlisp.nil;
    }
}

class AddExceptionsFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.addExceptions();
        //Jlisp.println("AddExceptionsFn called");
        return Jlisp.nil;
    }
}

class SetThisFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("argument 1 to set-this must be a string", a);
        String name = ((LispString)a).string;
        cd.setThis(name);
        Jlisp.println("Setting class name: " + name);
        return a;
    }
}

class SetSuperFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {        
        cd.setSuper("JavaFn");
        //Jlisp.println("Setting super_class: JavaFn");
        return Jlisp.nil;
    }

    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("argument 1 to set-super must be a string", a);
        String name = ((LispString)a).string;
        cd.setSuper(name);
        //Jlisp.println("Setting super_class: " + name);
        return a;
    }
}

class AddClassInfoFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("argument 1 to add-class-info must be a string", a);
        String name = ((LispString)a).string;
        cd.addClassInfo(name);
        //Jlisp.println("AddClassInfoFn called for class: " + name);
        return Jlisp.nil;
    }
}

class AddMethodrefFn extends BuiltinFunction
{
    public LispObject opn(LispObject[] args) throws Exception
    {
        if (args.length != 3) 
            return error("add-methodref called with " + args.length +
                         " args when 3 were expected");
        String classname = ((LispString)args[0]).string;
        String name = ((LispString)args[1]).string;
        String descriptor = ((LispString)args[2]).string;
        cd.addMethodref(classname, name, descriptor);
        //Jlisp.println("AddMethodrefFn called for: "
        //             +classname+" "+name+" "+descriptor);
        return Jlisp.nil;
    }
}

class AddFieldrefFn extends BuiltinFunction
{
    public LispObject opn(LispObject[] args) throws Exception
    {
        if (args.length != 3) 
            return error("add-fieldref called with " + args.length +
                         " args when 3 were expected");
        String classname = ((LispString)args[0]).string;
        String name = ((LispString)args[1]).string;
        String descriptor = ((LispString)args[2]).string;
        cd.addFieldref(classname, name, descriptor);
        //Jlisp.println("AddFieldrefFn called for: "
        //             +classname+" "+name+" "+descriptor);
        return Jlisp.nil;
    }
}

class MakeInitFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        Method_info m1 = new Method_info();
        cd.addInit(m1);
        //Jlisp.println("MakeInitFn called");
        return Jlisp.nil;
    }
}

class MakeMethodFn extends BuiltinFunction
{
    public LispObject op2(LispObject a, LispObject b) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("arg1 to make-method must be a string", a);
        if (!(b instanceof LispString)) 
            return error("arg2 to make-method must be a string", b);
                String name = ((LispString)a).string;
        String desc = ((LispString)b).string;
        mi = new Method_info();
        cd.addMethod(mi, name, desc, true);
        mi.setAccess((short)(ClassDescription.ACC_PUBLIC));
        mi.attributes_count = (short)2; //because of Exception
        //must be PUBLIC for classfileloader6 to invoke it
        ca = new Code_attribute();
        ca.attribute_name_index = cd.code_Utf8;
        //Jlisp.println("MakeMethodFn called");
        return Jlisp.nil;
    }
}

class SetStackLocalsFn extends BuiltinFunction
{
    public LispObject op2(LispObject a, LispObject b) throws Exception
    {
        int stack = a.intValue();
        int locals = b.intValue();
        ca.setStackLocals((short)stack,(short)locals);
        //Jlisp.println("SetStackLocalsFn called");
        return Jlisp.nil;
    }
}    

class SetLabelFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof Gensym)) 
            return error("argument 1 to lookup-ref must be a gensym", a);
        ((Gensym)a).completeName();
        String label = ((Gensym)a).pname;
        cd.setLabel(label, ca);
        //Jlisp.println("SetLabelFn called for: " + label);
        return Jlisp.nil;
    }
}

class LookupLabelFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof Gensym)) 
            return error("argument 1 to lookup-ref must be a gensym", a);
        ((Gensym)a).completeName();
        String label = ((Gensym)a).pname;
        cd.lookupLabel(label, ca);
        //Jlisp.println("LookupLabelFn called for: " + label);
        return Jlisp.nil;
    }
}

class LookupRefFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("argument 1 to lookup-ref must be a string", a);
        String name = ((LispString)a).string;
        cd.lookupRef(name, ca);
        //Jlisp.println("LookupRefFn called for: " + name);
        LispSmallInteger index = new LispSmallInteger(cd.refIndex);
        return index;
    }
}

class LookupCinfoFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        if (!(a instanceof LispString)) 
            return error("argument 1 to lookup-cinfo must be a string", a);
        String name = ((LispString)a).string;
        cd.lookupCinfo(name, ca, true); 
        //'true' means 'add to ResolveList' if not found first time
        //Jlisp.println("LookupCinfoFn called for: " + name);
        LispSmallInteger index = new LispSmallInteger(cd.cinfoIndex);
        return index;
    }
}

class AddInstrFn extends BuiltinFunction
{
    public LispObject op1(LispObject a) throws Exception
    {
        int opcode = a.intValue();
        ca.addInstruction((byte)opcode);
        //Jlisp.println("AddInstrFn called");
        return Jlisp.nil;
    }
}

class AddInstrArgsFn extends BuiltinFunction
{
    public LispObject op2(LispObject a, LispObject b) throws Exception
    {
        int opcode = a.intValue();
        int args = b.intValue();
        ca.addInstruction((byte)opcode, (short)args);
        //assume argument to OPCODE is SHORT value (e.g. goto, if<>)
        //Jlisp.println("AddInstrArgsFn called "+opcode+", "+args);
        return Jlisp.nil;
    }
}

class FinishMethodFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        Jlisp.println("@@@@@@@@@@@@@@@@@@@@@@@JVM Instructions: "+ca.code_length);
        ca.toInfo();
        mi.attributes = new Attribute_info[mi.attributes_count];
        mi.attributes[0] = ca;
        mi.attributes[1] = cd.ea; //Exceptions attribute
        cd.methods[cd.methods_count++] = mi;
        //Jlisp.println("FinishMethodFn called");
        return Jlisp.nil;
    }
}
    
class MakeCpFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.makeCP();
        //Jlisp.println("MakeCpFn called");
        return Jlisp.nil;
    }
}
class ResolveAllFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.resolveAll(); // resolve all outstanding references
        //Jlisp.println("ResolveAllFn called");
        return Jlisp.nil;
    }
}

class PrintCpFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.printCP(); //prints out contents of cp[]
        //Jlisp.println("PrintCpFn called");
        return Jlisp.nil;
    }
}

class FinishClassFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.dumpBytes(); //need do cd.dumpBytes() once
        //Jlisp.println("FinishClassFn called");
        return Jlisp.nil;
    }
}

class PrintBytesFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        ByteArray.printBytes(cd.ClassBytes);
        //Jlisp.println("PrintBytesFn called");
        return Jlisp.nil;
    }
}

class BytesToFileFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        cd.bytesToFile(cd.ClassBytes);
        //Jlisp.println("BytesToFileFn called");
        return Jlisp.nil;
    }
}

class LoadClassFn extends BuiltinFunction //deprecated
{
    public LispObject op0() throws Exception
    {
        return (LispObject)cd.loadCF();
    }
}

class InstanceFromBytesFn extends BuiltinFunction
{
    public LispObject op0() throws Exception
    {
        return (LispObject)cd.instanceFromBytes();
    }
}


}

// end of Fns4.java

