// 16/02/02 actually made to do something
// almost exactly identical to Method_info so may consider making a superclass
// and then subclassing Method_info and Field_info from it?

import java.io.*;

public class Field_info
{
    static short fields_count;

    short access_flags;
    short name_index;
    short descriptor_index;
    short attributes_count;
    Attribute_info attributes[];    // should be [attributes_count]

    byte[] fieldName;
    byte[] descriptor;

    void setAccess(short access)
    {
        access_flags = access;
    }

    void setName(String s) throws UnsupportedEncodingException
    {
        fieldName = s.getBytes("UTF-8");
    }

    void setDescriptor(String s) throws UnsupportedEncodingException
    {
        descriptor = s.getBytes("UTF-8");
    }

    byte[] dumpBytes()
    {
        byte[][] Bytes = new byte[5][0];
        Bytes[0] = ByteArray.shortToByteArray(access_flags);
        Bytes[1] = ByteArray.shortToByteArray(name_index);
        Bytes[2] = ByteArray.shortToByteArray(descriptor_index);
        Bytes[3] = ByteArray.shortToByteArray(attributes_count);
        Bytes[4] = ByteArray.attToByteArray(attributes);
        return ByteArray.flatBytes(Bytes);
    }

}

// end of Field_info.java
