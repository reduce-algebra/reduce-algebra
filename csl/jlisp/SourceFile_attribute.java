// amended 01/02/02
// 16/02/02 IGNORE SOURCEFILE_ATTRIBUTE since OPTIONAL
// associated code in ClassDescription has been commented out

import java.io.*;

public class SourceFile_attribute extends Attribute_info
{
    //attribute_length for SourceFile must always be 2        
    
    void setSource(short name_index, short sf_index)
    {
        attribute_name_index = name_index;
        info = ByteArray.shortToByteArray(sf_index);
        attribute_length = 2;
    }
    
}

// end of SourceFile_attribute.java

