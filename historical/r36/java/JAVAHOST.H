/* javahost.h:  Copyright (C) Codemist Ltd., 1996.                      */
 

#define JAVA_MAGIC 0xCAFEBABE
#define JAVA_THIS_MAJ 45
#define JAVA_THIS_MIN 3

/* The following structures define the internal format of a class file: */

typedef int32 *(*JavaBuiltin)(int32 *);

typedef enum Attribute_Sort
{   ATT_unknown,
    ATT_SourceFile,
    ATT_ConstantValue,
    ATT_Code,
    ATT_Exceptions,
    ATT_LineNumberTable,
    ATT_LocalVariableTable
} Attribute_Sort;

typedef struct Attribute_Info Attribute_Info;

typedef struct SourceFile_Attribute
{   unsigned16 sourcefile_index;
} SourceFile_Attribute;

typedef struct ConstantValue_Attribute
{   unsigned16 constantvalue_index;
} ConstantValue_Attribute;

    /* logically local to Code_Attribute */
    typedef struct Exception_Info
    {   unsigned16 start_pc;
        unsigned16 end_pc;
        unsigned16 handler_pc;
        unsigned16 catch_type;
    } Exception_Info;

typedef struct Code_Attribute
{   unsigned16 max_stack;
    unsigned16 max_locals;
    unsigned32 code_length;
    unsigned16 exception_table_length;
    unsigned16 attributes_count;
    unsigned8  *code;
    Exception_Info *exception_table;
    Attribute_Info *attributes;
} Code_Attribute;

typedef struct Exceptions_Attribute
{   unsigned16 number_of_exceptions;
    unsigned16 *exception_index_table;
} Exceptions_Attribute;

    /* logically local to LineNumberTable_Attribute */
    typedef struct LineNumber_Info
    {   unsigned16 start_pc;
        unsigned16 line_number;
    } LineNumber_Info;

typedef struct LineNumberTable_Attribute
{   unsigned16 line_number_table_length;
    LineNumber_Info *line_number_table;
} LineNumberTable_Attribute;

    /* logically local to LocalVariableTable_Attribute */
    typedef struct LocalVariable_Info
    {   unsigned16 start_pc;
        unsigned16 length;
        unsigned16 name_index;
        unsigned16 signature_index;
        unsigned16 slot;
    } LocalVariable_Info;

typedef struct LocalVariableTable_Attribute
{   unsigned16 local_variable_table_length;
    LocalVariable_Info *local_variable_table;
} LocalVariableTable_Attribute;

/*typedef*/ struct Attribute_Info
{   enum Attribute_Sort sort;
    union { SourceFile_Attribute *sourcefile;
            ConstantValue_Attribute *constantvalue;
            Code_Attribute *code;
            Exceptions_Attribute *exceptions;
            LineNumberTable_Attribute *linenumbertable;
            LocalVariableTable_Attribute *localvariabletable; }  uattr;
};

typedef struct Cp_Info
{   unsigned8 tag;
    unsigned16 len;
    union { unsigned32 val; char *utf8; void *ptr; } u;
} Cp_Info;

/* Currently Field_Info and Method_Info are identical, but note they    */
/* allow different attributes.                                          */
typedef struct Field_Info
{   unsigned16 access_flags;
    unsigned16 name_index;
    unsigned16 signature_index;
    unsigned16 attributes_count;
    Attribute_Info *attributes;
} Field_Info;

typedef struct Method_Info
{   unsigned16 access_flags;
    unsigned16 name_index;
    unsigned16 signature_index;
    unsigned16 attributes_count;
    Attribute_Info *attributes;
} Method_Info;

typedef struct ClassFile {
/* Internal representation of class file: see rdClassFile().            */
    unsigned16 access_flags;
    unsigned16 this_class;
    unsigned16 super_class;

    unsigned16 constant_pool_count;
    unsigned16 interfaces_count;
    unsigned16 fields_count;
    unsigned16 methods_count;
    unsigned16 attributes_count;

    Cp_Info *constant_pool;
    unsigned16 *interfaces;
    Field_Info *fields;
    Method_Info *methods;
    Attribute_Info *attributes;
} ClassFile;

/* Cp_Info tags: */
#define CONSTANT_Class          7
#define CONSTANT_FieldRef       9
#define CONSTANT_MethodRef     10
#define CONSTANT_InterfaceMethodRef     11
#define CONSTANT_String         8
#define CONSTANT_Integer        3
#define CONSTANT_Float          4
#define CONSTANT_Long           5
#define CONSTANT_Double         6
#define CONSTANT_NameAndType   12
#define CONSTANT_Utf8           1
#define CONSTANT_Unicode        2
/* The next (illegal) tag represents the 2nd word of a long or double.  */
#define CONSTANT_Xhalf         42

/* access_flags: */
#define ACC_PUBLIC              0x0001
#define ACC_PRIVATE             0x0002
#define ACC_PROTECTED           0x0004
#define ACC_STATIC              0x0008
#define ACC_FINAL               0x0010
#define ACC_SYNCHRONIZED        0x0020
#define ACC_VOLATILE            0x0040
#define ACC_TRANSIENT           0x0080
#define ACC_NATIVE              0x0100
#define ACC_INTERFACE           0x0200
#define ACC_ABSTRACT            0x0400

/* end of javahost.h */
