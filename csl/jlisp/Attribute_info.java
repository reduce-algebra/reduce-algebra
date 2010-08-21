
public class Attribute_info
{
    static short attributes_count;

    short attribute_name_index;
    int   attribute_length;
    byte  info[];    //should be [attribute_length]

    byte[] dumpBytes()
    {
        byte[][] Bytes = new byte[3][0];
        Bytes[0] = ByteArray.shortToByteArray(attribute_name_index);
        Bytes[1] = ByteArray.intToByteArray(attribute_length);
        Bytes[2] = info;
        return ByteArray.flatBytes(Bytes);
    }

}

// end of Attribute_info.java
