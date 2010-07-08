//04/03/02 for adding java/lang/Exception to Method_info
//note if more exceptions need adding...
//make a ByteArray.shortArrayToByteArray() for infotemp[1]

//Exceptions_attribute.java

import java.io.*;

public class Exceptions_attribute extends Attribute_info
{
   // short attribute_name_index;
   // int   attribute_length;
   // byte  info[];    //should be [attribute_length]

  short   number_of_exceptions = (short)1; //only ONE exception
	short[] exception_index_table = new short[number_of_exceptions];   
   
    void toInfo() throws IOException
    {
        byte[][] infoTemp = new byte[2][0];
        infoTemp[0] = ByteArray.shortToByteArray(number_of_exceptions);
        infoTemp[1] = ByteArray.shortToByteArray(exception_index_table[0]);
        //assume only one entry in exception_table
        
        info = ByteArray.flatBytes(infoTemp);
        attribute_length = info.length;
    }
}

// end of Exceptions_attribute.java


	
	
	
	
	
	
	