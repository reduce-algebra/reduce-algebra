//created 02/02/02

import java.io.*;

public class CONSTANT_Utf8_info extends Cp_info
{
    public static void main(String[] args)
                       throws IOException, UnsupportedEncodingException
    {
        String s = "<init>";
        CONSTANT_Utf8_info cu = new CONSTANT_Utf8_info(s);
        cu.printBytes(cu.dumpBytes());
        Jlisp.println("\n");
        
        String s1 = "()V";
        CONSTANT_Utf8_info cu1 = new CONSTANT_Utf8_info(s1);
        cu1.printBytes(cu1.dumpBytes());
        Jlisp.println("\n");
        
        String s2 = "Code";
        CONSTANT_Utf8_info cu2 = new CONSTANT_Utf8_info(s2);
        cu2.printBytes(cu2.dumpBytes());
        Jlisp.println("\n");
        
        String s3 = "LineNumberTable";
        CONSTANT_Utf8_info cu3 = new CONSTANT_Utf8_info(s3);
        cu3.printBytes(cu3.dumpBytes());
        Jlisp.println("\n");
        
        String s4 = "main";
        CONSTANT_Utf8_info cu4 = new CONSTANT_Utf8_info(s4);
        cu4.printBytes(cu4.dumpBytes());
        Jlisp.println("\n");
                
        String s5 = "([Ljava/lang/String;)V";
        CONSTANT_Utf8_info cu5 = new CONSTANT_Utf8_info(s5);
        cu5.printBytes(cu5.dumpBytes());
        Jlisp.println("\n");
        
        String s6 = "trivialMethod";
        CONSTANT_Utf8_info cu6 = new CONSTANT_Utf8_info(s6);
        cu6.printBytes(cu6.dumpBytes());
        Jlisp.println("\n");
        
        String s7 = "(I)I";
        CONSTANT_Utf8_info cu7 = new CONSTANT_Utf8_info(s7);
        cu7.printBytes(cu7.dumpBytes());
        Jlisp.println("\n");
        
        String s8 = "SourceFile";
        CONSTANT_Utf8_info cu8 = new CONSTANT_Utf8_info(s8);
        cu8.printBytes(cu8.dumpBytes());
        Jlisp.println("\n");
        
        String s9 = "Trivial.java";
        CONSTANT_Utf8_info cu9 = new CONSTANT_Utf8_info(s9);
        cu9.printBytes(cu9.dumpBytes());
        Jlisp.println("\n");
            
        String s10 = "Trivial";
        CONSTANT_Utf8_info cu10 = new CONSTANT_Utf8_info(s10);
        cu10.printBytes(cu10.dumpBytes());
        Jlisp.println("\n");
        
        String s11 = "java/lang/Object";
        CONSTANT_Utf8_info cu11 = new CONSTANT_Utf8_info(s11);
        cu11.printBytes(cu11.dumpBytes());
        Jlisp.println("\n");
        
    }
        
    
    short length;
    byte bytes[];    //should be [length]
    
    //constructor
    CONSTANT_Utf8_info(String s)
        throws IOException, UnsupportedEncodingException
    {   tag = CONSTANT_Utf8;
        bytes = s.getBytes("UTF-8");
        length = (short)bytes.length;
        
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = shortToByteArray(length);
        infoTemp[1] = bytes;
        
        info = new byte[totalArraySize(infoTemp)];
        info = flatBytes(infoTemp);
    }
    
}

// end of CONSTANT_Utf8_info.java
