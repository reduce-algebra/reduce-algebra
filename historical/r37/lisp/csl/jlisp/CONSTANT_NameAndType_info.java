//created 02/02/02

import java.io.*;

public class CONSTANT_NameAndType_info extends Cp_info
{
    public static void main(String[] args) throws IOException
    {
        short nidx = (short)0x5;
        short didx = (short)0x6;
        CONSTANT_NameAndType_info cnt =
            new CONSTANT_NameAndType_info(nidx,didx);
        cnt.printBytes(cnt.dumpBytes());
        Jlisp.println("\n");
        
        short nidx2 = (short)0xb;
        short didx2 = (short)0xc;
        CONSTANT_NameAndType_info cnt2 =
            new CONSTANT_NameAndType_info(nidx2,didx2);
        cnt2.printBytes(cnt2.dumpBytes());
        Jlisp.println("\n");
        
    }
    
    short name_index;
    short descriptor_index;
    

    //constructor
    CONSTANT_NameAndType_info(short nameIndex, short desIndex)
                             throws IOException
    {    tag = CONSTANT_NameAndType;    
        name_index = nameIndex;
        descriptor_index = desIndex;
        //below is the toInfo() method of Code_Attribute.java
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = shortToByteArray(name_index);
        infoTemp[1] = shortToByteArray(descriptor_index);
                
        info = new byte[4];
        info = flatBytes(infoTemp);
    }
    
}


// end of CONSTANT_NameAndType_info.java
