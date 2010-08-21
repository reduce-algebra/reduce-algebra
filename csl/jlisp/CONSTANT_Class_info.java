// created 02/02/02

import java.io.*;

public class CONSTANT_Class_info extends Cp_info
{
    public static void main(String[] args) throws IOException
    {
        short index = (short)0x11;
        CONSTANT_Class_info ci = new CONSTANT_Class_info(index);
        ci.printBytes(ci.dumpBytes());
                
        short index2 = (short)0x12;
        CONSTANT_Class_info ci2 = new CONSTANT_Class_info(index2);
        ci2.printBytes(ci2.dumpBytes());
    }
        
    short name_index;
        
    //constructor
    CONSTANT_Class_info(short nameIndex)throws IOException
    {   tag = CONSTANT_Class;        
        name_index = nameIndex;
        info = shortToByteArray(name_index);
    }
                
}

// end of CONSTANT_Class_info.java
