/* jadecode.c:  Copyright (C) Codemist Ltd., 1996.                      */

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

static struct { char *opname; } optable[211] = {
  "\x00""nop",			/* 0 */
  "\x00""aconst_null",		/* 1 */
  "\x00""iconst_m1",		/* 2 */
  "\x00""iconst_0",		/* 3 */
  "\x00""iconst_1",		/* 4 */
  "\x00""iconst_2",		/* 5 */
  "\x00""iconst_3",		/* 6 */
  "\x00""iconst_4",		/* 7 */
  "\x00""iconst_5",		/* 8 */
  "\x00""lconst_0",		/* 9 */
  "\x00""lconst_1",		/* 10 */
  "\x00""fconst_0",		/* 11 */
  "\x00""fconst_1",		/* 12 */
  "\x00""fconst_2",		/* 13 */
  "\x00""dconst_0",		/* 14 */
  "\x00""dconst_1",		/* 15 */
  "\x01""bipush",		/* 16 */
  "\x02""sipush",		/* 17 */
  "\x11""ldc1",			/* 18 */
  "\x12""ldc2",			/* 19 */
  "\x12""ldc2w",		/* 20 */
  "\x01""iload",		/* 21 */
  "\x01""lload",		/* 22 */
  "\x01""fload",		/* 23 */
  "\x01""dload",		/* 24 */
  "\x01""aload",		/* 25 */
  "\x00""iload_0",		/* 26 */
  "\x00""iload_1",		/* 27 */
  "\x00""iload_2",		/* 28 */
  "\x00""iload_3",		/* 29 */
  "\x00""lload_0",		/* 30 */
  "\x00""lload_1",		/* 31 */
  "\x00""lload_2",		/* 32 */
  "\x00""lload_3",		/* 33 */
  "\x00""fload_0",		/* 34 */
  "\x00""fload_1",		/* 35 */
  "\x00""fload_2",		/* 36 */
  "\x00""fload_3",		/* 37 */
  "\x00""dload_0",		/* 38 */
  "\x00""dload_1",		/* 39 */
  "\x00""dload_2",		/* 40 */
  "\x00""dload_3",		/* 41 */
  "\x00""aload_0",		/* 42 */
  "\x00""aload_1",		/* 43 */
  "\x00""aload_2",		/* 44 */
  "\x00""aload_3",		/* 45 */
  "\x00""iaload",		/* 46 */
  "\x00""laload",		/* 47 */
  "\x00""faload",		/* 48 */
  "\x00""daload",		/* 49 */
  "\x00""aaload",		/* 50 */
  "\x00""baload",		/* 51 */
  "\x00""caload",		/* 52 */
  "\x00""saload",		/* 53 */
  "\x01""istore",		/* 54 */
  "\x01""lstore",		/* 55 */
  "\x01""fstore",		/* 56 */
  "\x01""dstore",		/* 57 */
  "\x01""astore",		/* 58 */
  "\x00""istore_0",		/* 59 */
  "\x00""istore_1",		/* 60 */
  "\x00""istore_2",		/* 61 */
  "\x00""istore_3",		/* 62 */
  "\x00""lstore_0",		/* 63 */
  "\x00""lstore_1",		/* 64 */
  "\x00""lstore_2",		/* 65 */
  "\x00""lstore_3",		/* 66 */
  "\x00""fstore_0",		/* 67 */
  "\x00""fstore_1",		/* 68 */
  "\x00""fstore_2",		/* 69 */
  "\x00""fstore_3",		/* 70 */
  "\x00""dstore_0",		/* 71 */
  "\x00""dstore_1",		/* 72 */
  "\x00""dstore_2",		/* 73 */
  "\x00""dstore_3",		/* 74 */
  "\x00""astore_0",		/* 75 */
  "\x00""astore_1",		/* 76 */
  "\x00""astore_2",		/* 77 */
  "\x00""astore_3",		/* 78 */
  "\x00""iastore",		/* 79 */
  "\x00""lastore",		/* 80 */
  "\x00""fastore",		/* 81 */
  "\x00""dastore",		/* 82 */
  "\x00""aastore",		/* 83 */
  "\x00""bastore",		/* 84 */
  "\x00""castore",		/* 85 */
  "\x00""sastore",		/* 86 */
  "\x00""pop",			/* 87 */
  "\x00""pop2",			/* 88 */
  "\x00""dup",			/* 89 */
  "\x00""dup_x1",		/* 90 */
  "\x00""dup_x2",		/* 91 */
  "\x00""dup2",			/* 92 */
  "\x00""dup2_x1",		/* 93 */
  "\x00""dup2_x2",		/* 94 */
  "\x00""swap",			/* 95 */
  "\x00""iadd",			/* 96 */
  "\x00""ladd",			/* 97 */
  "\x00""fadd",			/* 98 */
  "\x00""dadd",			/* 99 */
  "\x00""isub",			/* 100 */
  "\x00""lsub",			/* 101 */
  "\x00""fsub",			/* 102 */
  "\x00""dsub",			/* 103 */
  "\x00""imul",			/* 104 */
  "\x00""lmul",			/* 105 */
  "\x00""fmul",			/* 106 */
  "\x00""dmul",			/* 107 */
  "\x00""idiv",			/* 108 */
  "\x00""ldiv",			/* 109 */
  "\x00""fdiv",			/* 110 */
  "\x00""ddiv",			/* 111 */
  "\x00""irem",			/* 112 */
  "\x00""lrem",			/* 113 */
  "\x00""frem",			/* 114 */
  "\x00""drem",			/* 115 */
  "\x00""ineg",			/* 116 */
  "\x00""lneg",			/* 117 */
  "\x00""fneg",			/* 118 */
  "\x00""dneg",			/* 119 */
  "\x00""ishl",			/* 120 */
  "\x00""ishr",			/* 121 */
  "\x00""iushr",		/* 122 */
  "\x00""lshl",			/* 123 */
  "\x00""lshr",			/* 124 */
  "\x00""lushr",		/* 125 */
  "\x00""iand",			/* 126 */
  "\x00""land",			/* 127 */
  "\x00""ior",			/* 128 */
  "\x00""lor",			/* 129 */
  "\x00""ixor",			/* 130 */
  "\x00""lxor",			/* 131 */
  "\x03""iinc",			/* 132 */
  "\x00""i2l",			/* 133 */
  "\x00""i2f",			/* 134 */
  "\x00""i2d",			/* 135 */
  "\x00""l2i",			/* 136 */
  "\x00""l2f",			/* 137 */
  "\x00""l2d",			/* 138 */
  "\x00""f2i",			/* 139 */
  "\x00""f2l",			/* 140 */
  "\x00""f2d",			/* 141 */
  "\x00""d2i",			/* 142 */
  "\x00""d2l",			/* 143 */
  "\x00""d2f",			/* 144 */
  "\x00""int2byte",		/* 145 */
  "\x00""int2char",		/* 146 */
  "\x00""int2short",		/* 147 */
  "\x00""lcmp",			/* 148 */
  "\x00""fcmpl",		/* 149 */
  "\x00""fcmpg",		/* 150 */
  "\x00""dcmpl",		/* 151 */
  "\x00""dcmpg",		/* 152 */
  "\x08""ifeq",			/* 153 */
  "\x08""ifne",			/* 154 */
  "\x08""iflt",			/* 155 */
  "\x08""ifge",			/* 156 */
  "\x08""ifgt",			/* 157 */
  "\x08""ifle",			/* 158 */
  "\x08""if_icmpeq",		/* 159 */
  "\x08""if_icmpne",		/* 160 */
  "\x08""if_icmplt",		/* 161 */
  "\x08""if_icmpge",		/* 162 */
  "\x08""if_icmpgt",		/* 163 */
  "\x08""if_icmple",		/* 164 */
  "\x08""if_acmpeq",		/* 165 */
  "\x08""if_acmpne",		/* 166 */
  "\x08""goto",			/* 167 */
  "\x08""jsr",			/* 168 */
  "\x01""ret",			/* 169 */
  "\x06""tableswitch",		/* 170 */
  "\x07""lookupswitch",		/* 171 */
  "\x00""ireturn",		/* 172 */
  "\x00""lreturn",		/* 173 */
  "\x00""freturn",		/* 174 */
  "\x00""dreturn",		/* 175 */
  "\x00""areturn",		/* 176 */
  "\x00""return",		/* 177 */
  "\x12""getstatic",		/* 178 */
  "\x12""putstatic",		/* 179 */
  "\x12""getfield",		/* 180 */
  "\x12""putfield",		/* 181 */
  "\x12""invokevirtual",	/* 182 */
  "\x12""invokenonvirtual",	/* 183 */
  "\x12""invokestatic",		/* 184 */
  "\x14""invokeinterface",	/* 185 */
  "\x00""<missing186>",             /* 186 */
  "\x12""new",			/* 187 */
  "\x01""newarray",		/* 188 */
  "\x12""anewarray",		/* 189 */
  "\x00""arraylength",		/* 190 */
  "\x00""athrow",		/* 191 */
  "\x12""checkcast",		/* 192 */
  "\x12""instanceof",		/* 193 */
  "\x00""monitorenter",		/* 194 */
  "\x00""monitorexit",		/* 195 */
  "\x01""wide",			/* 196 */
  "\x13""multinewarray",	/* 197 */
  "\x08""ifnull",		/* 198 */
  "\x08""ifnonnull",		/* 199 */
  "\x09""goto_w",		/* 200 */
  "\x09""jsr_w",		/* 201 */
  "\x00""breakpoint",		/* 202 */
  "\x00""<missing203>",             /* 203 */
  "\x00""<missing204>",             /* 204 */
  "\x00""<missing205>",             /* 205 */
  "\x00""<missing206>",             /* 206 */
  "\x00""<missing207>",             /* 207 */
  "\x00""<missing208>",             /* 208 */
  "\x02""ret_w",		/* 209 */
  "\x00""<missing >= 210>" };

static unsigned char *labtab;

static void notelab(unsigned32 l)
{   if (l < 0x10000) labtab[l/8] |= 1 << (l%8);
    /* err_printf("notelab %d\n", l); */
}

static int islab(unsigned32 l)
{   int b = 1 << l%8;
    /* err_printf("islab %d\n", l); */
    if (l < 0x10000 && labtab[l/8] & b)
    {   /* labtab[l/8] ^= b; */
        return 1;
    }
    return 0;
}

static int reflab(unsigned32 l)
{   int b = 1 << l%8;
    if (l < 0x10000 && labtab[l/8] & b)
    {   err_printf("L%.4x", l);
        return 1;
    }
    return 0;
}

#define ztos16(w) (((unsigned32)(w) ^ 0x8000) - 0x8000)

static void decode_lit(unsigned32 n, Cp_Info *cp, unsigned32 cplen)
{   for (;;)
    {   if (n == 0 || n >= cplen)
        {   err_printf("<bad literal 0x%x>", n);
            return;
        }
        else switch (cp[n].tag)
        {
case CONSTANT_Class:            err_printf("Class"); goto redo;
case CONSTANT_FieldRef:         err_printf("FieldRef"); goto redo2;
case CONSTANT_MethodRef:        err_printf("MethodRef"); goto redo2;
case CONSTANT_InterfaceMethodRef: err_printf("InterfaceMethodRef"); goto redo2;
case CONSTANT_String:           err_printf("String"); goto redo;
case CONSTANT_Integer:          err_printf("Integer:%d",n); return;
case CONSTANT_Float:            err_printf("Float:%d",n); return;
case CONSTANT_Long:             err_printf("Long:%d",n); return;
case CONSTANT_Double:           err_printf("Double:%d",n); return;
case CONSTANT_Utf8:             err_printf("Utf8[%d'%*s']", n,
                                       cp[n].len, cp[n].u.utf8); return;
case CONSTANT_Unicode:          err_printf("Unicode:%d",n); return;
case CONSTANT_NameAndType:      err_printf("NameAndType"); goto redo2;
default:    err_printf("<unknown literal[%.4x] %d>", n, cp[n].tag); return;
        }
redo:   err_printf("[%d]:", n); n = cp[n].u.val; continue;
redo2:  err_printf("[%d]:<", n);
        decode_lit(cp[n].u.val, cp, cplen);
        err_printf(",");
        decode_lit(cp[n].len, cp, cplen);
        err_printf(">"); return;
    }
}

char *jdecodeopname(unsigned32 op)
{
    if (op >= 210) op = 210;
    return optable[op].opname+1;
}

void javadecode(unsigned8 *code, unsigned32 len, Cp_Info *cp, unsigned32 cplen)
{   unsigned8 *p;
    if (labtab == 0) labtab = (unsigned char *)jmalloc(0x10000/8);
    memset(labtab, 0, 0x10000/8);
    for (p = code; p < code+len;)
    {   unsigned32 op = *p++;
        if (op >= 210) op = 210;
        switch (optable[op].opname[0])
        {
default:    break;
case 0x11:
case 0x01:  p++; break;
case 0x12:
case 0x02:  p += 2; break;
case 0x08:  notelab(p-1-code + ztos16(p[0]<<8 | p[1])); p += 2; break;
case 0x03:  p += 2; break;
case 0x13:  p += 3; break;
case 0x14:
case 0x04:  p += 4; break;
case 0x09:  notelab(p-1-code + (p[0]<<24 | p[1]<<16 | p[2]<<8 | p[3])); p += 4;
            break;
case 0x06:  ("\ttableswitch!"); break;
case 0x07:  ("\tlookupswitch!"); break;
        }
    }
    for (p = code; p < code+len;)
    {   unsigned32 op = *p++;
        unsigned32 off;
        if (op >= 210) op = 210;
        if (islab(p-1 - code)) err_printf("L%.4x:", p-1 - code);
        err_printf("\t%s", optable[op].opname+1);
        if (optable[op].opname[0] != 0x00 && strlen(optable[op].opname+1) < 8)
            err_printf("\t");
        switch (optable[op].opname[0])
        {
default:    break;
case 0x01:  err_printf("\t%d", *p++); break;
case 0x11:  err_printf("\t"); decode_lit(*p++, cp, cplen); break;
case 0x02:  err_printf("\t0x%.4x", p[0]<<8 | p[1]); p += 2; break;
case 0x12:  err_printf("\t"); decode_lit(p[0]<<8 | p[1], cp, cplen); p += 2; break;
case 0x08:  off = ztos16(p[0]<<8 | p[1]);
            err_printf("\t");
            if (!reflab(p-1-code+off)) err_printf("$+0x%.4x", off);
            p += 2; break;
case 0x03:  err_printf("\t%d,%d", p[0], p[1]); p += 2; break;
case 0x13:  err_printf("\t"); decode_lit(p[0]<<8 | p[1], cp, cplen);
            err_printf(",%d", p[2]); p += 3; break;
case 0x14:  err_printf("\t"); decode_lit(p[0]<<8 | p[1], cp, cplen);
            err_printf(",%d,%d", p[2], p[3]); p += 4; break;
case 0x04:  err_printf("\t0x%.8x", p[0]<<24 | p[1]<<16 | p[2]<<8 | p[3]); p += 4;
            break;
case 0x09:  off = p[0]<<24 | p[1]<<16 | p[2]<<8 | p[3];
            err_printf("\t(big)");
            if (!reflab(p-1-code+off)) err_printf("\t$+0x%.8x", off);
            p += 4; break;
case 0x06:  err_printf("\tswitch!");
            break;
case 0x07:  err_printf("\tswitch!");
            break;
        }
        err_printf("\n");
    }
}

/* end of jadecode.c */
