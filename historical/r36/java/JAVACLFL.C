/* javaclfl.c:  Copyright (C) Codemist Ltd., 1996.                      */
 
#include <stdio.h>
#include <string.h>
#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#include "javahost.h"
#include "javaglb.h"
/* #include "javatype.h" */

#define D_CLASSFILE 1
#define D_CLASSFILEIO 2
#define D_CLASSFILECODE 4

static int depth;

static unsigned32 rd1(FILE *f)
{   unsigned32 x = getc(f);
    if (debugging & D_CLASSFILEIO) jdebug("rd1 %d", x);
    return x;
}

static unsigned32 rd2(FILE *f)
{   unsigned32 x = getc(f);
    x = x<<8 | getc(f);
    if (debugging & D_CLASSFILEIO) jdebug("rd2 0x%.4x", x);
    return x;
}

static unsigned32 rd4(FILE *f)
{   unsigned32 x = getc(f);
    x = x<<8 | getc(f);
    x = x<<8 | getc(f);
    x = x<<8 | getc(f);
    if (debugging & D_CLASSFILEIO) jdebug("rd4 0x%.8x", x);
    return x;
}

static char *rd1string(FILE *f, unsigned32 n)
{   int i;
    unsigned8 *p = (unsigned8 *)jmalloc((n+1) * sizeof(*p));
    for (i=0; i<n; i++) p[i] = rd1(f);
    p[n] = 0;           /* @@@ ease C access for debugging (temp?) */
    return (char *)p;
}

static char *rd2string(FILE *f, unsigned32 n)
{   int i;
    unsigned16 *p = (unsigned16 *)jmalloc(n * sizeof(*p));
    for (i=0; i<n; i++) p[i] = rd2(f);
    return (char *)p;
}

static char *cpname(unsigned32 cpx, ClassFile *cf)
{   if (cpx < cf->constant_pool_count)
    {   Cp_Info *cpitem = &cf->constant_pool[cpx];
        if (cpitem->tag == CONSTANT_Utf8) return cpitem->u.utf8;
        return "<non-utf8 const pool index>";
    }
    return "<bad const pool index>";
}

static Attribute_Sort lookup_attribute_sort(char *utf8, unsigned32 len)
{   /* Should use 'len' not rely on rd1string() zero padding.           */
    if (strcmp(utf8,"SourceFile") == 0) return ATT_SourceFile;
    if (strcmp(utf8,"ConstantValue") == 0) return ATT_ConstantValue;
    if (strcmp(utf8,"Code") == 0) return ATT_Code;
    if (strcmp(utf8,"Exceptions") == 0) return ATT_Exceptions;
    if (strcmp(utf8,"LineNumberTable") == 0) return ATT_LineNumberTable;
    if (strcmp(utf8,"LocalVariableTable") == 0) return  ATT_LocalVariableTable;
    return ATT_unknown;
}

static int rdAttribute_Info(FILE *f, ClassFile *cf, unsigned32 n, Attribute_Info **res);

static int rdSourceFile_Attribute(FILE *f, ClassFile *cf,
                                  SourceFile_Attribute **res)
{   SourceFile_Attribute *p = (SourceFile_Attribute *)jmalloc(sizeof(*p));
    depth++;
    p->sourcefile_index = rd2(f);
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute Sourcefile '%s'",
               depth*2, "", cpname(p->sourcefile_index, cf));
    *res = p;
    return (depth--, 0);
}

static int rdConstantValue_Attribute(FILE *f, ClassFile *cf,
                                  ConstantValue_Attribute **res)
{   ConstantValue_Attribute *p = (ConstantValue_Attribute *)jmalloc(sizeof(*p));
    depth++;
    p->constantvalue_index = rd2(f);
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute ConstantValue [%d]",
               depth*2, "", p->constantvalue_index);
    *res = p;
    return (depth--, 0);
}

static int rdCode_Attribute(FILE *f, ClassFile *cf, Code_Attribute **res)
{   Code_Attribute *p = (Code_Attribute *)jmalloc(sizeof(*p));
    unsigned32 i,n;
    depth++;
    p->max_stack = rd2(f);
    p->max_locals = rd2(f);
    p->code_length = n = rd4(f);
    p->code = (unsigned8 *)jmalloc(n * sizeof(*p->code));
    for (i=0; i<n; i++) p->code[i] = rd1(f);
    p->exception_table_length = n = rd2(f);
    p->exception_table = (Exception_Info *)jmalloc(n * sizeof(*p->exception_table));
    for (i=0; i<n; i++)
    {   Exception_Info *q = &p->exception_table[i];
        q->start_pc = rd2(f);
        q->end_pc = rd2(f);
        q->handler_pc = rd2(f);
        q->catch_type = rd2(f);
    }
    p->attributes_count = n = rd2(f);
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute Code \
(stack %d, locals %d, bytes %d, exceptions %d)",
               depth*2, "",
               p->max_stack, p->max_locals,
               p->code_length, p->exception_table_length);
    if (debugging & D_CLASSFILECODE)
        javadecode(p->code, p->code_length,
                   cf->constant_pool, cf->constant_pool_count);
    if (rdAttribute_Info(f, cf, n, &p[i].attributes)) return 5;
    *res = p;
    return (depth--, 0);
}

static int rdExceptions_Attribute(FILE *f, ClassFile *cf,
                                       Exceptions_Attribute **res)
{   Exceptions_Attribute *p = (Exceptions_Attribute *)jmalloc(sizeof(*p));
    unsigned32 i,n;
    depth++;
    p->number_of_exceptions = n = rd2(f);
    p->exception_index_table = (unsigned16 *)jmalloc(n * sizeof(*p->exception_index_table));
    for (i=0; i<n; i++)
        p->exception_index_table[i] = rd2(f);
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute Exceptions (entries %d)",
               depth*2, "", p->number_of_exceptions);
    *res = p;
    return (depth--, 0);
}

static int rdLineNumberTable_Attribute(FILE *f, ClassFile *cf,
                                       LineNumberTable_Attribute **res)
{   LineNumberTable_Attribute *p = (LineNumberTable_Attribute *)jmalloc(sizeof(*p));
    unsigned32 i,n;
    depth++;
    p->line_number_table_length = n = rd2(f);
    p->line_number_table = (LineNumber_Info *)jmalloc(n * sizeof(*p->line_number_table));
    for (i=0; i<n; i++)
    {   LineNumber_Info *q = &p->line_number_table[i];
        q->start_pc = rd2(f);
        q->line_number = rd2(f);
    }
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute LineNumberTable (entries %d)",
               depth*2, "", p->line_number_table_length);
    *res = p;
    return (depth--, 0);
}

static int rdLocalVariableTable_Attribute(FILE *f, ClassFile *cf,
                                       LocalVariableTable_Attribute **res)
{   LocalVariableTable_Attribute *p = (LocalVariableTable_Attribute *)jmalloc(sizeof(*p));
    unsigned32 i,n;
    depth++;
    p->local_variable_table_length = n = rd2(f);
    p->local_variable_table = (LocalVariable_Info *)jmalloc(n * sizeof(*p->local_variable_table));
    for (i=0; i<n; i++)
    {   LocalVariable_Info *q = &p->local_variable_table[i];
        q->start_pc = rd2(f);
        q->length = rd2(f);
        q->name_index = rd2(f);
        q->signature_index = rd2(f);
        q->slot = rd2(f);
    }
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttribute LocalVariableTable (entries %d)",
               depth*2, "", p->local_variable_table_length);
    *res = p;
    return (depth--, 0);
}

/* 'Attributes' occur more than once in a Classfile, hence they are     */
/* stored in *res (OK/NOK is return value), but reading Attributes      */
/* also requires cf to access the previously read Cp_Info.              */
static int rdAttribute_Info(FILE *f, ClassFile *cf, unsigned32 n, Attribute_Info **res)
{   Attribute_Info *p;
    unsigned32 i;
    if (n > 0xffff) return 1;
    p = (Attribute_Info *)jmalloc(n * sizeof(*p));
    if (debugging & D_CLASSFILE)
        jdebug("%*sAttributes_Info %d", depth*2, "", n);
    for (i=0; i<n; i++)
    {   unsigned32 cpx = rd2(f);
        unsigned32 len = rd4(f);
        Cp_Info *cpitem = &cf->constant_pool[cpx];
        if (cpitem->tag != CONSTANT_Utf8) return 3;
        switch (p[i].sort = lookup_attribute_sort(cpitem->u.utf8, cpitem->len))
        {
case ATT_Code:
            if (rdCode_Attribute(f, cf, &p[i].uattr.code)) return 6;
            break;
case ATT_SourceFile:
            if (rdSourceFile_Attribute(f, cf, &p[i].uattr.sourcefile)) return 6;
            break;
case ATT_ConstantValue:
            if (rdConstantValue_Attribute(f, cf, &p[i].uattr.constantvalue))
                return 6;
            break;
case ATT_Exceptions:
            if (rdExceptions_Attribute(f, cf, &p[i].uattr.exceptions))
                return 6;
            break;
case ATT_LineNumberTable:
            if (rdLineNumberTable_Attribute(f, cf, &p[i].uattr.linenumbertable))
                return 6;
            break;
case ATT_LocalVariableTable:
            if (rdLocalVariableTable_Attribute(f, cf, &p[i].uattr.localvariabletable))
                return 6;
            break;
default:    /* currently ignore other attributes */
            if (debugging & D_CLASSFILE)
                jdebug("%*sAttribute '%s' unknown", (depth+1)*2, "",
                       cpitem->u.utf8);
            while (len) rd1(f), len--;
        }
    }
    *res = p;
    return 0;
}

static int rdCp_Info(FILE *f, ClassFile *cf, unsigned32 n)
{   Cp_Info *p;
    unsigned32 i, nn;
    depth++;
    if (n > 0xffff) return 1;
    if (debugging & D_CLASSFILE) jdebug("Cp_Info %d", n);
    p = (Cp_Info *)jmalloc(n * sizeof(*p));
    /* Yes, the next line really is '1'!                                */
    for (i=1; i<n; i++) switch (p[i].tag = rd1(f))
    {
default:                jsyserr("tag %d", p[i].tag); return 2;
case CONSTANT_Class:
                        p[i].u.val = rd2(f); break;
case CONSTANT_FieldRef:
case CONSTANT_MethodRef:
case CONSTANT_InterfaceMethodRef:
                        /* stuff name_and_type_index into len */
                        p[i].u.val = rd2(f); p[i].len = rd2(f); break;
case CONSTANT_String:
                        p[i].u.val = rd2(f); break;
case CONSTANT_Integer: 
case CONSTANT_Float:    p[i].u.val = rd4(f);
                        break;
case CONSTANT_Long: 
case CONSTANT_Double:   p[i].u.val = rd4(f);
                        i++; p[i].tag = CONSTANT_Xhalf; p[i].u.val = rd4(f);
                        break;
case CONSTANT_Utf8:     if ((nn = rd2(f)) > 0xffff) nn = 0;   /* EOF */
                        p[i].len = nn; p[i].u.utf8 = rd1string(f, nn);
                        break;
case CONSTANT_Unicode:  if ((nn = rd2(f)) > 0xffff) nn = 0;   /* EOF */
                        p[i].len = nn; p[i].u.utf8 = rd2string(f, nn);
                        break;
case CONSTANT_NameAndType:
                        /* stuff signature_index into len */
                        p[i].u.val = rd2(f); p[i].len = rd2(f); break;
    }
    cf->constant_pool = p;
    return (depth--, 0);
}

static int rdInterface_Info(FILE *f, ClassFile *cf, unsigned32 n)
{   unsigned16 *p;
    unsigned32 i;
    depth++;
    if (n > 0xffff) return 1;
    if (debugging & D_CLASSFILE) jdebug("Interface_Info %d", n);
    p = (unsigned16 *)jmalloc(n * sizeof(*p));
    for (i=0; i<n; i++) p[i] = rd2(f);
    cf->interfaces = p;
    return (depth--, 0);
}

static int rdField_Info(FILE *f, ClassFile *cf, unsigned32 n)
{   Field_Info *p;
    unsigned32 i;
    depth++;
    if (n > 0xffff) return 1;
    if (debugging & D_CLASSFILE) jdebug("Field_Info %d", n);
    p = (Field_Info *)jmalloc(n * sizeof(*p));
    for (i=0; i<n; i++)
    {   unsigned32 nn;
        p[i].access_flags = rd2(f);
        p[i].name_index = rd2(f);
        p[i].signature_index = rd2(f);
        p[i].attributes_count = nn = rd2(f);
        if (debugging & D_CLASSFILE)
            jdebug("  Field '%s' signature '%s' flags 0x%x",
                   cpname(p[i].name_index, cf),
                   cpname(p[i].signature_index, cf),
                   p[i].access_flags);
        if (rdAttribute_Info(f, cf, nn, &p[i].attributes)) return 4;
    }
    cf->fields = p;
    return (depth--, 0);
}

static int rdMethod_Info(FILE *f, ClassFile *cf, unsigned32 n)
{   Method_Info *p;
    unsigned32 i;
    depth++;
    if (n > 0xffff) return 1;
    if (debugging & D_CLASSFILE) jdebug("Method_Info %d", n);
    p = (Method_Info *)jmalloc(n * sizeof(*p));
    for (i=0; i<n; i++)
    {   unsigned32 nn;
        p[i].access_flags = rd2(f);
        p[i].name_index = rd2(f);
        p[i].signature_index = rd2(f);
        p[i].attributes_count = nn = rd2(f);
        if (debugging & D_CLASSFILE)
            jdebug("  Method '%s' signature '%s' flags 0x%x",
                   cpname(p[i].name_index, cf),
                   cpname(p[i].signature_index, cf),
                   p[i].access_flags);
        if (rdAttribute_Info(f, cf, nn, &p[i].attributes)) return 4;
    }
    cf->methods = p;
    return (depth--, 0);
}

ClassFile *rdClassFile(char *name)
{   FILE *f = fopen(name, "rb");
    ClassFile *cf = rdClassFILE1(f, name);
    fclose(f);
    return cf;
}

ClassFile *rdClassFILE1(FILE *f, char *name)
{
    ClassFile *cf;
    unsigned32 n;
    depth = 0;
    if (f == 0)
      { jsyserr("cannot read '%s'", name); return 0; }
    if (rd4(f) != JAVA_MAGIC)
      { jsyserr("not class file '%s'", name); return 0; }
    if ((n = rd2(f)) > JAVA_THIS_MIN)
        jdebug("ClassFile '%s' wrong minor vsn %d", name, n); 
    if ((n = rd2(f)) != JAVA_THIS_MAJ)
        jdebug("ClassFile '%s' wrong major vsn %d", name, n);
    cf = (ClassFile *)jmalloc(sizeof(ClassFile));
    cf->constant_pool_count = n = rd2(f);
    if (rdCp_Info(f, cf, n)) goto corrupt;
    cf->access_flags = rd2(f);
    cf->this_class = rd2(f);
    cf->super_class = rd2(f);
    cf->interfaces_count = n = rd2(f);
    if (rdInterface_Info(f, cf, n)) goto corrupt;
    cf->fields_count = n = rd2(f);
    if (rdField_Info(f, cf, n)) goto corrupt;
    cf->methods_count = n = rd2(f);
    if (rdMethod_Info(f, cf, n)) goto corrupt;
    cf->attributes_count = n = rd2(f);
    if (rdAttribute_Info(f, cf, n, &cf->attributes)) goto corrupt;
    if (rd1(f) != EOF) jdebug("junk at end of ClassFile '%s'", name);
    return cf;
corrupt:
    jsyserr("ClassFile '%s' corrupted", name);
    return 0;
}
