package uk.co.codemist.jlisp.core;


// $Id$


//    Date: 09/02/02
//    Name: Vijay P. Chauhan
//    Supervisor: Dr. Arthur Norman
//    "Jlisp to JVM Compiler" - Part II Project
//
// 21/02/02
// ClassDescription4.java for using with jlisp to make LengthFn.class
// ClassDescription3.java THIS IS FOR getting resolveAll() to work
// ClassDescription2.java works fine (with one cheat).
// resolveAll wasn't working because I was casting to Code_attribute
// needed to access attribute[].info with offset 8(maxstack,locals,length,etc)

// Class File format (.class) mapped out according to JVM spec
// map structure -> byte[] -> written to file (.class)

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

import java.util.*;
import java.io.*;
import java.lang.reflect.*;

public class ClassDescription
{
// all access flags included for COMPLETENESS even though not all used

    public static final short ACC_DEFAULT       = 0x0000;
    public static final short ACC_PUBLIC        = 0x0001;
    public static final short ACC_PRIVATE       = 0x0002;
    public static final short ACC_PROTECTED     = 0x0004;
    public static final short ACC_STATIC        = 0x0008;
    public static final short ACC_FINAL         = 0x0010;
    public static final short ACC_SYNCHRONIZED  = 0x0020;
    public static final short ACC_SUPER         = 0x0020;
    public static final short ACC_VOLATILE      = 0x0040;
    public static final short ACC_TRANSIENT     = 0x0080;
    public static final short ACC_NATIVE        = 0x0100;
    public static final short ACC_INTERFACE     = 0x0200;
    public static final short ACC_ABSTRACT      = 0x0400;
    public static final short ACC_STRICT        = 0x0800;

    // check if versions supported by jdk1.4.0 beta3
    // Note that I REALLY HOPE that the code here is not sensitive to
    // just which release of Java is in use. Thre is no good reason why
    // it should be!
    static final int MAGIC              = 0xcafebabe;
    static final short minor_version    = 0x0;
    static final short major_version    = 0x2e;
    short constant_pool_count = 0;
    Cp_info constant_pool[];
    short access_flags;
    short this_class; //= 14
    short super_class; //= 7
    short interfaces_count = 0;       // counts are initialised to 0
    short interfaces[];               //should be [interfaces_count]
    short fields_count = 0;
    Field_info fields[];              //should be [fields_count]
    short methods_count = 0;
    Method_info methods[]; //should be [methods_count]
    short attributes_count = 0;       //LineNumberTable, SourceFile not implmtd
    Attribute_info attributes[] ;     //should be [attributes_count]


    //NOT part of classfile structure -> see VM spec for above
    String thisString;
    String superString = "java/lang/Object";
    String init = "<init>";
    String code = "Code";
    String exceptions_attribute = "Exceptions";
    String exception = "java/lang/Exception";
    short this_Utf8, super_Utf8, code_Utf8;
    short globalIndex;
    short initNAT, initref;    //for holding reference to methodref_info for <init>
    Exceptions_attribute ea = new Exceptions_attribute();
    
    byte[] ClassBytes;
    
// note from ACN to VPC. There is a Java tradition of naming little
// methods that just set a field xxx as setxxx.

    void mNumber(int a)    //number of methods defined in the class
    //N.B. which is NOT necessarily equal to number of methodref_infos
    {   methods = new Method_info[a];
    }

    void setAccess(short access)
    {   access_flags = access;
    }

    void addCode() throws IOException
    {   addUtf8(code);
        code_Utf8 = globalIndex;
    }    //put "Code" for Code_attribute in cp[1] since cp[0] is null   
    
    void addExceptions() throws IOException
    {   addUtf8(exceptions_attribute);
        //put "Exceptions" for Exceptions_attribute in cp[2]
        ea.attribute_name_index = globalIndex;
        //put "java/lang/Exception" in cp[3]
        addUtf8(exception);    
        addCInfo(globalIndex);
        ea.exception_index_table[0] = globalIndex;
        ea.toInfo();
    }   
        
    void setThis(String thisName)
        throws UnsupportedEncodingException,
               IOException
    {   thisString = thisName;
        addUtf8(thisName); //add CONSTANT_Utf8_info
        this_Utf8 = globalIndex;
        addCInfo(this_Utf8); //add CONSTANT_Class_info
        this_class = globalIndex;
        // put thisName in ConstantPool and then set this_class
    }

    void setSuper() throws UnsupportedEncodingException, IOException
    {   addUtf8(superString); //add CONSTANT_Utf8_info
        super_Utf8 = globalIndex;
        addCInfo(super_Utf8); //add CONSTANT_Class_info
        super_class = globalIndex;
        //if no argument given then default superclass is java.lang.Object
    }

    void setSuper(String superName)
        throws UnsupportedEncodingException, IOException
    {   superString = superName;
        addUtf8(superString); //add CONSTANT_Utf8_info
        super_Utf8 = globalIndex;
        addCInfo(super_Utf8); //add CONSTANT_Class_info
        super_class = globalIndex;
        // put superString in ConstantPool
    }

    void addInit(Method_info m1) throws IOException
    // how to add <init>, ()V since needed for every class
    {
        m1.setAccess((short)ACC_PUBLIC); // ACC_PUBLIC in some cases?
        //make <init> PUBLIC by default
        lookupUtf8(init);    // DO NOT ASSUME THERE IS ONLY 1 "<init>" made.
        if (utf8Index == 0)  // not made so far
        {   addUtf8(init);   // then make it
            m1.name_index = globalIndex;
        }
        else m1.name_index = utf8Index;
        addUtf8("()V"); //"()V"
        m1.descriptor_index = globalIndex;
        addNAT(m1);
        initNAT = globalIndex;
        //addCInfo(super_Utf8);    //invoked from super_class (whatever it is)
        //super_class = globalIndex; //7
        addCMInfo(super_class, initNAT);
        initref = globalIndex;

        /*
        addUtf8("<init>"); //"<init>"
        m1.name_index = globalIndex; //4
        addUtf8("()V"); //"()V"
        m1.descriptor_index = globalIndex; //5
        addNAT(m1);
        NATindex = globalIndex; //6
        //addCInfo(super_Utf8);    //invoked from super_class (whatever it is)
        //super_class = globalIndex; //7
        addCMInfo(super_class, NATindex);
        */

        // m1.attributes_count = (short)1; fixed in Method_info.java
        Code_attribute ca1 = new Code_attribute();
        ca1.attribute_name_index = code_Utf8;
        ca1.setStackLocals((short)1,(short)1);
        ca1.addInstruction(ByteCodes.ALOAD_0);
        //lookupRef("<init>", ca1); //no need to lookup really? save time?
        //byte[] arg1 = ByteArray.shortToByteArray(methodrefIndex[0]);//{0x00, 0x08}; //cp[8]
        //byte[] arg1 = ByteArray.shortToByteArray(refIndex);
        byte[] arg1 = ByteArray.shortToByteArray(initref);
        ca1.addInstruction(ByteCodes.INVOKESPECIAL, arg1);
        ca1.addInstruction(ByteCodes.RETURN);
        ca1.toInfo();
        m1.attributes = new Attribute_info[m1.attributes_count];
        m1.attributes[0] = ca1;
        methods[methods_count++] = m1;
    }

    void addMethod(Method_info m3, String methodName, String methodDesc)
        throws IOException
    // makes Methodref_info irrespective -> see other addMethod(...,boolean b)
    {
        //m3.setAccess((short)(ClassDescription4.ACC_STATIC));
        addUtf8(methodName);
        m3.name_index = globalIndex;
        addUtf8(methodDesc);    // argument and result types, eg "(I)I"
        m3.descriptor_index = globalIndex;
        addNAT(m3);
        //addCInfo(this_Utf8);    // NOT super_class but this_class
        //any method after <init> (not 'main') has this_class as class_index
        //this_class = globalIndex;
        addCMInfo(this_class, globalIndex);
    }

    void addMethod(Method_info m3,
                   String methodName,
                   String methodDesc,
                   boolean b) throws IOException
    // if (b==true) then it means we do want a Methodref too, otherwise not
    {   addUtf8(methodName);
        m3.name_index = globalIndex;
        addUtf8(methodDesc); // eg "(I)I"
        m3.descriptor_index = globalIndex;
        if (b)
        {   addNAT(m3);
            addCMInfo(this_class, globalIndex);
        }
    }

    Vector cptemp = new Vector(20,10); //default size 20, increment 10 if full.
    //change to more appropriate numbers depending on likely cp size.
    //process of incrementing takes time (see Java 2-Ivor Horton, pg 410).
    //possible optimisation HERE

   void addMethodref(String cl, String nm, String des) throws IOException
    {   short nmidx;
        short desidx;

        Code_attribute ca = new Code_attribute();
        lookupCinfo(cl,ca, false); // don't want to add to toResolveClass list
        if (cinfoIndex == 0)       // if no class entry by this name..
        {   addUtf8(cl);           // ..then create one
            addCInfo(globalIndex);
            cinfoIndex = globalIndex;
        }
        lookupUtf8(nm);
        if (utf8Index == 0)        // not made so far
        {   addUtf8(nm);           // then make it
            nmidx = globalIndex;
        }
        else nmidx = utf8Index;
        lookupUtf8(des);
        if (utf8Index == 0)        // not made so far
        {   addUtf8(des);          // then make it
            desidx = globalIndex;
        }
        else desidx = utf8Index;
        
        if (!isNAT(nmidx, desidx))
        {  addNAT(nmidx, desidx);
           addCMInfo(cinfoIndex, globalIndex);
        }
        else 
          if (!isRef(cinfoIndex, nameAndTypeIndex))  
          {  addCMInfo(cinfoIndex, nameAndTypeIndex); }
          // else System.out.print("**************NO NEED TO MAKE MREF");
        
        utf8Index = 0;
        nameAndTypeIndex = 0;
        cinfoIndex = 0; // before anyone else uses this value again
    }
    
    void addFieldref(String cl, String nm, String des) throws IOException
    {   short nmidx;
        short desidx;

        Code_attribute ca = new Code_attribute();
        lookupCinfo(cl,ca, false); // don't want to add to toResolveClass list
        if (cinfoIndex == 0)       // if no class entry by this name..
        {   addUtf8(cl);           // ..then create one
            addCInfo(globalIndex);
            cinfoIndex = globalIndex;
        }
        lookupUtf8(nm);
        if (utf8Index == 0)        // not made so far
        {   addUtf8(nm);           // then make it
            nmidx = globalIndex;
        }
        else nmidx = utf8Index;
        lookupUtf8(des);
        if (utf8Index == 0)        // not made so far
        {   addUtf8(des);          // then make it
            desidx = globalIndex;
        }
        else desidx = utf8Index;
        
        if (!isNAT(nmidx, desidx))
        {  addNAT(nmidx, desidx);
           addCFInfo(cinfoIndex, globalIndex);
        }
        else 
          if (!isRef(cinfoIndex, nameAndTypeIndex))  
          {  addCFInfo(cinfoIndex, nameAndTypeIndex); }
          //else System.out.print("**************NO NEED TO MAKE FREF")
        
        utf8Index = 0;
        nameAndTypeIndex = 0;
        cinfoIndex = 0; // before anyone else uses this value again
    }

    void addClassInfo(String cl)throws IOException
    {   Code_attribute ca = new Code_attribute();
        lookupCinfo(cl,ca,false);
        if (cinfoIndex == 0)      // if no class entry by this name..
        {   addUtf8(cl);          // ..then create one
            addCInfo(globalIndex);
        }
    }

    void addCFInfo(short classindex, short NATindex) throws IOException
    {   CONSTANT_Fieldref_info cf =
            new CONSTANT_Fieldref_info(classindex, NATindex);
        addToCP(cf);
    }

    void addCMInfo(short classindex, short NATindex) throws IOException
    {   CONSTANT_Methodref_info cm =
            new CONSTANT_Methodref_info(classindex, NATindex);
        addToCP(cm);
    }

    void addCInfo(short classindex) throws IOException
    {   CONSTANT_Class_info ci = new CONSTANT_Class_info(classindex);
        addToCP(ci);
    }

    void addNAT(short nidx, short didx) throws IOException
    // if Methodref/Fieldref_info not associated with declared method/field
    {   CONSTANT_NameAndType_info cnt =
            new CONSTANT_NameAndType_info(nidx, didx);
        addToCP(cnt);
    }

    void addNAT(Method_info m) throws IOException
    // NEED one for Field_info? in future maybe if Field_info needed.
    {   CONSTANT_NameAndType_info cnt =
            new CONSTANT_NameAndType_info(m.name_index, m.descriptor_index);
        addToCP(cnt);
    }

    void addUtf8(String s) throws IOException
    {   CONSTANT_Utf8_info cu = new CONSTANT_Utf8_info(s);
        addToCP(cu);
    }

    void addToCP(Cp_info c)
    {   cptemp.add(c);
        globalIndex = (short)(cptemp.indexOf(c)+1);
        //very important: globalIndex
        //or just do globalIndex++ ?
        //+1 because CP entries start from cp[1], not from cp[0]
    }

    Vector labels = new Vector();
    Vector positions = new Vector();
    Vector mcountsL = new Vector();
    Vector labelToLookup = new Vector();
    Vector positionToPut = new Vector();

    void setLabel(String label, Code_attribute ca)
    {
      labels.add(label);
        Integer pointer = new Integer(ca.code.length);
      positions.add(pointer);
        Short methodIndex = new Short(methods_count);
      mcountsL.add(methodIndex);
    }

    void lookupLabel(String label, Code_attribute ca)
    {
      labelToLookup.add(label);
      Integer pointer = new Integer(ca.code.length+1);
      positionToPut.add(pointer); //because GOTO or IF_CMP instr not yet added
    }

    void resolveLabels() //only one pass overall
    { 
      for (int i=0; i<labelToLookup.size(); i++)
      { for (int j=0; j<labels.size(); j++)
        { if (labelToLookup.get(i) == labels.get(j))
          { 
//Jlisp.println("i = " + i + " j = " + j);
//Jlisp.println(positions.size() + " " + positionToPut.size() + " " +
//mcountsL.size() + " " + methods.length);
            int offset = ((Integer)positions.get(j)).intValue() 
                         - ((Integer)positionToPut.get(i)).intValue() + 1;
            byte[] bytesoffset = ByteArray.shortToByteArray((short)offset);   
            int pointer = ((Integer)positionToPut.get(i)).intValue();
            short methodIndex = ((Short)mcountsL.get(j)).shortValue();
// ACN changed the above from i to j                 ^
            (methods[methodIndex].attributes[0]).info[pointer+8]=bytesoffset[0];
            (methods[methodIndex].attributes[0]).info[pointer+8+1]=bytesoffset[1];
            break; //don't need to check anymore
          }         
        }
      }
    }
    
    short refIndex = (short)0;    //check when these indexes change
    short cinfoIndex = (short)0;
    short utf8Index = (short)0;
    short nameAndTypeIndex =(short)0;
    short mfRefIndex = (short)0;
    int resolveFlag = 0; //check when changes and when changes back (Per loop)

    
    boolean isRef(short cl, short nat)
                   throws UnsupportedEncodingException, IOException
    {  Vector cptemp1 = cptemp;
       Vector frefs = new Vector();
       Vector mrefs = new Vector();
       Vector FRefs = new Vector();
       Vector MRefs = new Vector();
       mfRefIndex = (short)0; //in case changed somewhere before
       
       for (int i=0; i<cptemp1.size(); i++)
       { Cp_info cpEntry = (Cp_info)cptemp1.get(i);
         Short presentIndex = new Short((short)(i+1));
         if (cpEntry.tag == (byte)0x9) //fref
         { frefs.add(cpEntry); 
           FRefs.add(presentIndex);
         }
         else if (cpEntry.tag == (byte)0xa) //mref
         { mrefs.add(cpEntry); 
           MRefs.add(presentIndex);
         }
        }
       for (int k=0; k<frefs.size(); k++)
       {  CONSTANT_Fieldref_info cpEntry =
                    (CONSTANT_Fieldref_info)frefs.get(k);
          if ((cpEntry.class_index == cl) & 
              (cpEntry.name_and_type_index == nat))
             {  mfRefIndex = ((Short)FRefs.get(k)).shortValue();
                return true; 
             }  
       }
       for (int j=0; j<mrefs.size(); j++)
       {  CONSTANT_Methodref_info cpEntry =
                    (CONSTANT_Methodref_info)mrefs.get(j);
          if ((cpEntry.class_index == cl) &
              (cpEntry.name_and_type_index == nat))
             {  mfRefIndex = ((Short)MRefs.get(j)).shortValue();
                return true; 
             }  
       }
       return false; 
    }
    
    boolean isNAT(short nm, short des)
                   throws UnsupportedEncodingException, IOException
    {  Vector cptemp1 = cptemp;
              
       for (int i=0; i<cptemp1.size(); i++)
       { Cp_info cpEntry = (Cp_info)cptemp1.get(i);
         short presentIndex = (short)(i+1);
         if (cpEntry.tag == (byte)0xc) //NAT_info
         {  CONSTANT_NameAndType_info natEntry =
                    (CONSTANT_NameAndType_info)cpEntry;
            if ((natEntry.name_index == nm) & 
                (natEntry.descriptor_index == des))
            {  nameAndTypeIndex = presentIndex;
               //System.out.println("************FOUND A NAT MATCH");
               return true; 
            }
         }
       }
       return false;
    }
    
    void lookupUtf8(String utf8)
        throws UnsupportedEncodingException, IOException
    {   Vector cptemp1 = cptemp;
        Vector utf8s = new Vector(); //vectors for holding cp_info itself
        Vector Utf8s = new Vector(); //vectors for holding cp-indexes

        //System.out.println(cptemp1.size()+" CP entries");

        for (int i=0; i<cptemp1.size(); i++)
        {   Cp_info cpEntry = (Cp_info)cptemp1.get(i);
            Short presentIndex = new Short((short)(i+1));
            // i.e. give cp-index, not vector index by i+1...
            // ...because first entry in CP is cp[1] NOT cp[0]

            switch (cpEntry.tag)
            {
        case (byte)0x1:    //Utf8_info
                utf8s.add(cpEntry);
                //System.out.println(presentIndex+ " we have a utf8");
                Utf8s.add(presentIndex); break;
        default:
                break;
            }
        }

        short index = (short)-1;

        for (int i=0; i<utf8s.size(); i++)
        {   CONSTANT_Utf8_info cpEntry = (CONSTANT_Utf8_info)utf8s.get(i);
            String compare = new String(cpEntry.bytes, "UTF-8");
            //System.out.println(utf8 + " == " + compare+" ?");
            if (utf8.equals(compare))
            {   index = ((Short)Utf8s.get(i)).shortValue();
                //System.out.println("Hello. we got UTF8 match. Index no. "+index);
                break; // assume there is only one match or no match
            }
        }
        if (index == (short)-1)    // i.e. no utf8 matches found
            utf8Index = 0;         // in case this value has been changed
        else utf8Index = index;
    }

    void lookupCinfo(String classname, Code_attribute ca, boolean b)
    // just like lookupRef
        throws UnsupportedEncodingException, IOException
    {   Vector cptemp1 = cptemp;
        Vector utf8s = new Vector(); //vectors for holding cp_info itself
        Vector classes = new Vector();

        Vector Utf8s = new Vector(); //vectors for holding cp-indexes
        Vector Classes = new Vector();

        //System.out.println(cptemp1.size()+" CP entries");

        for (int i=0; i<cptemp1.size(); i++)
        {   Cp_info cpEntry = (Cp_info)cptemp1.get(i);
            Short presentIndex = new Short((short)(i+1));
            // i.e. give cp-index, not vector index by i+1...
            // ...because first entry in CP is cp[1] NOT cp[0]
            switch (cpEntry.tag)
            {
        case (byte)0x1:    //Utf8_info
                utf8s.add(cpEntry);
                //System.out.println(presentIndex+ " we have a utf8");
                Utf8s.add(presentIndex);
                break;
        case (byte)0x7:    //class_info
                classes.add(cpEntry);
                //System.out.println(presentIndex+ " we have a class");
                Classes.add(presentIndex);
                break;
        default:
                break;
            }
        }

        short index = (short)-1;
        for (int i=0; i<utf8s.size(); i++)
        {   CONSTANT_Utf8_info cpEntry = (CONSTANT_Utf8_info)utf8s.get(i);
            String compare = new String(cpEntry.bytes, "UTF-8");
            //System.out.println(classname + " == " + compare+" ?");
            if (classname.equals(compare))
            {   index = ((Short)Utf8s.get(i)).shortValue();
                //System.out.println("Hello. we got a match. Index no. "+index);
                break; // assume there is only one match or no match
            }
        }

        if (index == (short)-1)    //i.e. no utf8 matches found
        {   cinfoIndex = 0; //in case this value has been changed
            if (b) addToResolveClass(classname, ca);
            return;
        }
        else
        {   for (int i=0; i<classes.size(); i++)
            {   CONSTANT_Class_info cpEntry =
                    (CONSTANT_Class_info)classes.get(i);
                if (cpEntry.name_index == index)
                {   cinfoIndex = ((Short)Classes.get(i)).shortValue();
                    //System.out.println("Class_info match. index no. "+cinfoIndex);
                    break;    //assume only one match for NAT or no match
                }
            }
        }
    }



    void lookupRef(String name, Code_attribute ca)
    //works for field_info as well as method_info (I hope)
        throws UnsupportedEncodingException, IOException
    {   Vector cptemp1 = cptemp;
        Vector utf8s = new Vector(); //vectors for holding cp_info itself
        Vector nats = new Vector();
        Vector mrefs = new Vector();
        Vector classes = new Vector();
        Vector frefs = new Vector();

        Vector Utf8s = new Vector(); //vectors for holding cp-indexes
        Vector Nats = new Vector();
        Vector Mrefs = new Vector();
        Vector Classes = new Vector();
        Vector Frefs = new Vector();

        //System.out.println(cptemp1.size()+" CP entries");

        for (int i=0; i<cptemp1.size(); i++)
        {   Cp_info cpEntry = (Cp_info)cptemp1.get(i);
            Short presentIndex = new Short((short)(i+1));
            // i.e. give cp-index, not vector index by i+1...
            // ...because first entry in CP is cp[1] NOT cp[0]
            switch (cpEntry.tag)
            {
        case (byte)0x1:    //Utf8_info
                utf8s.add(cpEntry);
                Utf8s.add(presentIndex);
                break;
        case (byte)0xc: //nat_info
                nats.add(cpEntry);
                Nats.add(presentIndex);
                break;
        case (byte)0xa:    //mref_info
                mrefs.add(cpEntry);
                Mrefs.add(presentIndex);
                break;
        case (byte)0x7:    //class_info
                classes.add(cpEntry);
                Classes.add(presentIndex);
                break;
        case (byte)0x9:    //fieldref_info
                frefs.add(cpEntry);
                Frefs.add(presentIndex);
                break;
        default:
                //System.out.println("some other type of Cp_info?");
                break;
            }
        }

        short index = (short)-1;
        short natIndex = (short)-1;
        short mrefidx = (short)-1;

        for (int i=0; i<utf8s.size(); i++)
        {   CONSTANT_Utf8_info cpEntry = (CONSTANT_Utf8_info)utf8s.get(i);
            String compare = new String(cpEntry.bytes, "UTF-8");
            //System.out.println(name + " == " + compare+" ?");
            if (name.equals(compare))
            {   index = ((Short)Utf8s.get(i)).shortValue();
                //System.out.println("Hello. we got a match. Index no. "+index);
                break; // assume there is only one match or no match
            }
        }

        if (index == (short)-1)    //i.e. no utf8 matches found
        {   if (resolveFlag == 0)
            {   addToResolveList(name, ca);
                refIndex = (short)0; //incase it contains a value from previous call
                //System.out.println("this method/field not found...so far");
                return; //i.e. return from method if no utf8 match
            }
            else //i.e. part of resolveAll() so addToResolveList() already done
                //System.out.println("ERROR! Method "+name+" was NEVER declared")
              ;
        }
        //ASSUMPTION: there are no fields (or other utf8s) by same name as method
        //if there is a field then next stage would find a fieldref
        //and say we can't cast to Methodref_info as a result
        else
        {
            for (int i=0; i<nats.size(); i++)
            {   CONSTANT_NameAndType_info cpEntry =
                    (CONSTANT_NameAndType_info)nats.get(i);
                if (cpEntry.name_index == index)
                {   natIndex = ((Short)Nats.get(i)).shortValue();
                    //System.out.println("NAT match. Natindex no. "+natIndex);
                    if (natIndex == initNAT)
                        continue;    //continue with loop and look for next match
                    else break;
                }
            }
        }

        if (natIndex == (short)-1)
        {
            //System.out.println("name "+name+" not a method(or maybe 'main'");
            return;
        }
        //ASSUMPTION: we are not going to have overloaded methods
        //otherwise need to check that type descriptor matches too
        //also assume there is NOT both methodref+fieldref for any string
        else
        {
            for(int i=0; i<mrefs.size(); i++)
            {   CONSTANT_Methodref_info cpEntry =
                    (CONSTANT_Methodref_info)mrefs.get(i);
                if (cpEntry.name_and_type_index == natIndex)
                {   mrefidx = ((Short)Mrefs.get(i)).shortValue();
                    //System.out.println("Methodref_info MATCH! no. "+mrefidx);
                    refIndex=mrefidx;
                }
            }
            for(int i=0; i<frefs.size(); i++)
            {   CONSTANT_Fieldref_info cpEntry =
                    (CONSTANT_Fieldref_info)frefs.get(i);
                if (cpEntry.name_and_type_index == natIndex)
                {   mrefidx = ((Short)Frefs.get(i)).shortValue();
                    //System.out.println("Fieldref_info MATCH! no. "+mrefidx);
                    refIndex=mrefidx;
                }
            }
        }
        if (mrefidx == (short)-1)    //i.e. couldn't find the mref_idx
        //System.out.println("something wrong? utf8, NAT but no methodref")
          ;
    }

    void printCP() //prints out contents of final CP entries
        //makes use of lookup...() technology
        throws UnsupportedEncodingException, IOException
    {   Vector cptemp1 = cptemp;
        Vector utf8s = new Vector(); //vectors for holding cp_info itself
        Vector nats = new Vector();
        Vector mrefs = new Vector();
        Vector classes = new Vector();
        Vector frefs = new Vector();

        Vector Utf8s = new Vector(); //vectors for holding cp-indexes
        Vector Nats = new Vector();
        Vector Mrefs = new Vector();
        Vector Classes = new Vector();
        Vector Frefs = new Vector();

        //System.out.println(cptemp1.size()+" CP entries");

        for (int i=0; i<cptemp1.size(); i++)
        {   Cp_info cpEntry = (Cp_info)cptemp1.get(i);
            Short presentIndex = new Short((short)(i+1));
            //i.e. give cp-index, not vector index by i+1...
            //...because first entry in CP is cp[1] NOT cp[0]
            switch (cpEntry.tag)
            {
        case (byte)0x1:    //Utf8_info
                utf8s.add(cpEntry);
                CONSTANT_Utf8_info cpEntry1 = (CONSTANT_Utf8_info)cpEntry;
                String utf8name = new String(cpEntry1.bytes, "UTF-8");
                //System.out.println("cp["+presentIndex+ "]\tutf8:\t"+utf8name);
                Utf8s.add(presentIndex);
                break;
        case (byte)0xc: //nat_info
                nats.add(cpEntry);
                CONSTANT_NameAndType_info cpEntry2 =
                    (CONSTANT_NameAndType_info)cpEntry;
                short nmix =  cpEntry2.name_index;
                short tyix    =     cpEntry2.descriptor_index;
                //System.out.println("cp["+presentIndex+ "]\tnat:\t"+
                //                   nmix+","+tyix);
                Nats.add(presentIndex);
                break;
        case (byte)0xa:    //mref_info
                mrefs.add(cpEntry);
                CONSTANT_Methodref_info cpEntry3 =
                    (CONSTANT_Methodref_info)cpEntry;
                short clix =  cpEntry3.class_index;
                short ntix    =     cpEntry3.name_and_type_index;
                //System.out.println("cp["+presentIndex+ "]\tmref:\t"+clix+","+ntix);
                Mrefs.add(presentIndex);
                break;
        case (byte)0x7:    //class_info
                classes.add(cpEntry);
                CONSTANT_Class_info cpEntry4 = (CONSTANT_Class_info)cpEntry;
                nmix =  cpEntry4.name_index;
                //System.out.println("cp["+presentIndex+ "]\tclass:\t"+nmix);
                Classes.add(presentIndex);
                break;
        case (byte)0x9:    //fieldref_info
                frefs.add(cpEntry);
                CONSTANT_Fieldref_info cpEntry5 =
                    (CONSTANT_Fieldref_info)cpEntry;
                clix =  cpEntry5.class_index;
                ntix    =     cpEntry5.name_and_type_index;
                //System.out.println("cp["+presentIndex+ "]\tfref:\t"+
                //                   clix+","+ntix);
                Frefs.add(presentIndex);
                break;
        default:
                //System.out.println("some other type of Cp_info?");
                break;
            }
        }
    }


    Vector toResolve = new Vector();  // hold names to be resolved
    Vector mcounts = new Vector();    // which methods[i] it appears in
    Vector pointers = new Vector();   // which bit of code to be changed


    void addToResolveList(String name, Code_attribute ca)
    {
        toResolve.add(name);    //method name to be resolved
        Short methodIndex = new Short(methods_count);
        mcounts.add(methodIndex);    //which method the code appears in
        Integer pointer = new Integer(ca.code.length); //length is where you
        //got upto before when the cp index was needed and NOT resolved
        pointers.add(pointer);//pointer to which code to be amended

        //Vector of strings to resolve, with index of where to update in code.
    }

    Vector toResolveC = new Vector();  // hold names to be resolved
    Vector mcountsC = new Vector();    // which methods[i] it appears in
    Vector pointersC = new Vector();   // which bit of code to be changed

    void addToResolveClass(String name, Code_attribute ca) //for resolving class_infos
    {
        toResolveC.add(name);    //method name to be resolved
        Short methodIndex = new Short(methods_count);
        mcountsC.add(methodIndex);    //which method the code appears in
        Integer pointer = new Integer(ca.code.length); //length is where you
        //got upto before when the cp index was needed and NOT resolved
        pointersC.add(pointer);//pointer to which code to be amended

        //Vector of strings to resolve, with index of where to update in code.
    }

    void resolveAll() throws IOException, UnsupportedEncodingException
    {
        //System.out.println("*****NUMBER OF REFS TO RESOLVE IS: "+toResolve.size());
        for (int i=0; i<toResolve.size(); i++)
        {   resolveFlag = 1;    //to say that this is resolveAll()
            Code_attribute ca = new Code_attribute();
        // made purely for passing on to satisfy parameter requirements
        // of lookupMref
            lookupRef((String)toResolve.get(i), ca);
            byte[] newIndex = ByteArray.shortToByteArray(refIndex);
            int pointer = ((Integer)pointers.get(i)).intValue();
            short methodIndex = ((Short)mcounts.get(i)).shortValue();

            (methods[methodIndex].attributes[0]).info[pointer+8+1]=newIndex[0];
            (methods[methodIndex].attributes[0]).info[pointer+8+2]=newIndex[1];
        }
        //System.out.println("RESOLVE-REFS ALL DONE");

        //System.out.println("*****NUMBER OF CINFOS TO RESOLVE IS: "+toResolveC.size());
        for (int i=0; i<toResolveC.size(); i++)
        {   Code_attribute ca = new Code_attribute();
            lookupCinfo((String)toResolveC.get(i), ca, false);
            byte[] newIndex = ByteArray.shortToByteArray(cinfoIndex);
            int pointer = ((Integer)pointersC.get(i)).intValue();
            short methodIndex = ((Short)mcountsC.get(i)).shortValue();

            (methods[methodIndex].attributes[0]).info[pointer+8+1]=newIndex[0];
            (methods[methodIndex].attributes[0]).info[pointer+8+2]=newIndex[1];
        }
        //System.out.println("RESOLVE-CLASSES ALL DONE");
        resolveLabels();
    }

    //NEED RESOLVE TO DEAL WITH CLASSINFO too:


    void makeCP() throws UnsupportedEncodingException
    {
        cptemp.trimToSize();    //no need for this? capacity vs. size
        constant_pool_count = (short)(cptemp.size()+1);
        //System.out.println("constant_pool_count = " + constant_pool_count);
        constant_pool = new Cp_info[constant_pool_count-1];
        for (int i=0; i<cptemp.size(); i++)
        {   constant_pool[i] = (Cp_info)(cptemp.get(i));
            // System.out.println("\n\n" + i);
            // constant_pool[i].printBytes(constant_pool[i].dumpBytes());
        }
    }

    byte[] dumpBytes()
    {   byte[][] Bytes = new byte[13][0];

        Bytes[0]    = ByteArray.intToByteArray(MAGIC);
        Bytes[1]    = ByteArray.shortToByteArray(minor_version);
        Bytes[2]    = ByteArray.shortToByteArray(major_version);

        Bytes[3]    = ByteArray.shortToByteArray(constant_pool_count);
        Bytes[4]    = ByteArray.cpToByteArray(constant_pool);
        Bytes[5]    = ByteArray.shortToByteArray(access_flags);

        Bytes[6]    = ByteArray.shortToByteArray(this_class);
        Bytes[7]    = ByteArray.shortToByteArray(super_class);

        Bytes[8]    = ByteArray.shortToByteArray(interfaces_count);
        // ignore interfaces[] since never likely to need it
        Bytes[9]    = ByteArray.shortToByteArray(fields_count);
        Bytes[10]   = ByteArray.shortToByteArray(methods_count);
        Bytes[11]   = ByteArray.miToByteArray(methods);

        Bytes[12]   = ByteArray.shortToByteArray(attributes_count);

        //Bytes[13] = attributes[0].dumpBytes();

        // Bytes[16] = ByteArray.byteToByteArray((byte)0);
        // Is zero at end of class file? (eof marker?)
        ClassBytes = ByteArray.flatBytes(Bytes);
        return ClassBytes; 
    }


    //writes byte array to a file
    void bytesToFile(byte[] Bytes)
        throws IOException, FileNotFoundException
    {
        //File f1 = new File("D:/jlisp/MyCode/"+thisString+".class");
        File f1 = new File("./"+thisString+".class");
        DataOutputStream outStream =
            new DataOutputStream(
                new BufferedOutputStream(
                    new FileOutputStream(f1)));
        for (int i=0; i<Bytes.length; i++)
            outStream.writeByte(Bytes[i]);
        outStream.close();
    }

    Object loadCF()
        throws IOException, ClassNotFoundException,
               InstantiationException, IllegalAccessException,
               NoSuchMethodException, InvocationTargetException,
               ResourceException
    {
// This loads a class using the current CLASSPATH...
        JlispClassLoader loader = new JlispClassLoader();
        Object r = loader.loadMyInstance(thisString);
        //System.out.println("Object = " + r + " of type " + r.getClass());
        return r;
    }

    Object instanceFromBytes()
        throws IOException, ClassNotFoundException,
               InstantiationException, IllegalAccessException,
               NoSuchMethodException, InvocationTargetException,
               ResourceException
    {
// Load a class from an array of bytes and create an instance of it.
        // byte [] bytes = dumpBytes(); //no need to...ClassBytes
        JlispClassLoader loader = new JlispClassLoader();
        Object r = loader.loadMyInstance(thisString, ClassBytes);
        //System.out.println("Object = " + r + " of type " + r.getClass());
        return r;
    }


}

// end of ClassDescription.java
