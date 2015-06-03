package uk.co.codemist.jlisp.core;


/* $Id$ */


/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/*
 *   Projects also trying to compile for the JVM will be able to
 *   make use of this, as will other projects building on my project
 **/

public abstract class ByteCodes
{
    // All the other opcodes here for completeness
    // most of them being of no relevance to my project.

    static final byte NOP                 = (byte)0x00;
    static final byte ACONST_NULL         = (byte)0x01;
    static final byte ICONST_M1           = (byte)0x02;
    static final byte ICONST_0            = (byte)0x03;
    static final byte ICONST_1            = (byte)0x04;
    static final byte ICONST_2            = (byte)0x05;
    static final byte ICONST_3            = (byte)0x06;
    static final byte ICONST_4            = (byte)0x07;
    static final byte ICONST_5            = (byte)0x08;
    static final byte LCONST_0            = (byte)0x09;
    static final byte LCONST_1            = (byte)0x0a;
    static final byte FCONST_0            = (byte)0x0b;
    static final byte FCONST_1            = (byte)0x0c;
    static final byte FCONST_2            = (byte)0x0d;
    static final byte DCONST_0            = (byte)0x0e;
    static final byte DCONST_1            = (byte)0x0f;
    static final byte BIPUSH              = (byte)0x10;
    static final byte SIPUSH              = (byte)0x11;
    static final byte LDC                 = (byte)0x12;
    static final byte LDC_W               = (byte)0x13;
    static final byte LDC2_W              = (byte)0x14;
    static final byte ILOAD               = (byte)0x15;
    static final byte LLOAD               = (byte)0x16;
    static final byte FLOAD               = (byte)0x17;
    static final byte DLOAD               = (byte)0x18;
    static final byte ALOAD               = (byte)0x19;
    static final byte ILOAD_0             = (byte)0x1a;
    static final byte ILOAD_1             = (byte)0x1b;
    static final byte ILOAD_2             = (byte)0x1c;
    static final byte ILOAD_3             = (byte)0x1d;
    static final byte LLOAD_0             = (byte)0x1e;
    static final byte LLOAD_1             = (byte)0x1f;
    static final byte LLOAD_2             = (byte)0x20;
    static final byte LLOAD_3             = (byte)0x21;
    static final byte FLOAD_0             = (byte)0x22;
    static final byte FLOAD_1             = (byte)0x23;
    static final byte FLOAD_2             = (byte)0x24;
    static final byte FLOAD_3             = (byte)0x25;
    static final byte DLOAD_0             = (byte)0x26;
    static final byte DLOAD_1             = (byte)0x27;
    static final byte DLOAD_2             = (byte)0x28;
    static final byte DLOAD_3             = (byte)0x29;
    static final byte ALOAD_0             = (byte)0x2a;
    static final byte ALOAD_1             = (byte)0x2b;
    static final byte ALOAD_2             = (byte)0x2c;
    static final byte ALOAD_3             = (byte)0x2d;
    static final byte IALOAD              = (byte)0x2e;
    static final byte LALOAD              = (byte)0x2f;
    static final byte FALOAD              = (byte)0x30;
    static final byte DALOAD              = (byte)0x31;
    static final byte AALOAD              = (byte)0x32;
    static final byte BALOAD              = (byte)0x33;
    static final byte CALOAD              = (byte)0x34;
    static final byte SALOAD              = (byte)0x35;
    static final byte ISTORE              = (byte)0x36;
    static final byte LSTORE              = (byte)0x37;
    static final byte FSTORE              = (byte)0x38;
    static final byte DSTORE              = (byte)0x39;
    static final byte ASTORE              = (byte)0x3a;
    static final byte ISTORE_0            = (byte)0x3b;
    static final byte ISTORE_1            = (byte)0x3c;
    static final byte ISTORE_2            = (byte)0x3d;
    static final byte ISTORE_3            = (byte)0x3e;
    static final byte LSTORE_0            = (byte)0x3f;
    static final byte LSTORE_1            = (byte)0x40;
    static final byte LSTORE_2            = (byte)0x41;
    static final byte LSTORE_3            = (byte)0x42;
    static final byte FSTORE_0            = (byte)0x43;
    static final byte FSTORE_1            = (byte)0x44;
    static final byte FSTORE_2            = (byte)0x45;
    static final byte FSTORE_3            = (byte)0x46;
    static final byte DSTORE_0            = (byte)0x47;
    static final byte DSTORE_1            = (byte)0x48;
    static final byte DSTORE_2            = (byte)0x49;
    static final byte DSTORE_3            = (byte)0x4a;
    static final byte ASTORE_0            = (byte)0x4b;
    static final byte ASTORE_1            = (byte)0x4c;
    static final byte ASTORE_2            = (byte)0x4d;
    static final byte ASTORE_3            = (byte)0x4e;
    static final byte IASTORE             = (byte)0x4f;
    static final byte LASTORE             = (byte)0x50;
    static final byte FASTORE             = (byte)0x51;
    static final byte DASTORE             = (byte)0x52;
    static final byte AASTORE             = (byte)0x53;
    static final byte BASTORE             = (byte)0x54;
    static final byte CASTORE             = (byte)0x55;
    static final byte SASTORE             = (byte)0x56;
    static final byte POP                 = (byte)0x57;
    static final byte POP2                = (byte)0x58;
    static final byte DUP                 = (byte)0x59;
    static final byte DUP_X1              = (byte)0x5a;
    static final byte DUP_X2              = (byte)0x5b;
    static final byte DUP2                = (byte)0x5c;
    static final byte DUP2_X1             = (byte)0x5d;
    static final byte DUP2_X2             = (byte)0x5e;
    static final byte SWAP                = (byte)0x5f;
    static final byte IADD                = (byte)0x60;
    static final byte LADD                = (byte)0x61;
    static final byte FADD                = (byte)0x62;
    static final byte DADD                = (byte)0x63;
    static final byte ISUB                = (byte)0x64;
    static final byte LSUB                = (byte)0x65;
    static final byte FSUB                = (byte)0x66;
    static final byte DSUB                = (byte)0x67;
    static final byte IMUL                = (byte)0x68;
    static final byte LMUL                = (byte)0x69;
    static final byte FMUL                = (byte)0x6a;
    static final byte DMUL                = (byte)0x6b;
    static final byte IDIV                = (byte)0x6c;
    static final byte LDIV                = (byte)0x6d;
    static final byte FDIV                = (byte)0x6e;
    static final byte DDIV                = (byte)0x6f;
    static final byte IREM                = (byte)0x70;
    static final byte LREM                = (byte)0x71;
    static final byte FREM                = (byte)0x72;
    static final byte DREM                = (byte)0x73;
    static final byte INEG                = (byte)0x74;
    static final byte LNEG                = (byte)0x75;
    static final byte FNEG                = (byte)0x76;
    static final byte DNEG                = (byte)0x77;
    static final byte ISHL                = (byte)0x78;
    static final byte LSHL                = (byte)0x79;
    static final byte ISHR                = (byte)0x7a;
    static final byte LSHR                = (byte)0x7b;
    static final byte IUSHR               = (byte)0x7c;
    static final byte LUSHR               = (byte)0x7d;
    static final byte IAND                = (byte)0x7e;
    static final byte LAND                = (byte)0x7f;
    static final byte IOR                 = (byte)0x80;
    static final byte LOR                 = (byte)0x81;
    static final byte IXOR                = (byte)0x82;
    static final byte LXOR                = (byte)0x83;
    static final byte IINC                = (byte)0x84;
    static final byte I2L                 = (byte)0x85;
    static final byte I2F                 = (byte)0x86;
    static final byte I2D                 = (byte)0x87;
    static final byte L2I                 = (byte)0x88;
    static final byte L2F                 = (byte)0x89;
    static final byte L2D                 = (byte)0x8a;
    static final byte F2I                 = (byte)0x8b;
    static final byte F2L                 = (byte)0x8c;
    static final byte F2D                 = (byte)0x8d;
    static final byte D2I                 = (byte)0x8e;
    static final byte D2L                 = (byte)0x8f;
    static final byte D2F                 = (byte)0x90;
    static final byte I2B                 = (byte)0x91;
    static final byte I2C                 = (byte)0x92;
    static final byte I2S                 = (byte)0x93;
    static final byte LCMP                = (byte)0x94;
    static final byte FCMPL               = (byte)0x95;
    static final byte FCMPG               = (byte)0x96;
    static final byte DCMPL               = (byte)0x97;
    static final byte DCMPG               = (byte)0x98;
    static final byte IFEQ                = (byte)0x99;
    static final byte IFNE                = (byte)0x9a;
    static final byte IFLT                = (byte)0x9b;
    static final byte IFGE                = (byte)0x9c;
    static final byte IFGT                = (byte)0x9d;
    static final byte IFLE                = (byte)0x9e;
    static final byte IF_ICMPEQ           = (byte)0x9f;
    static final byte IF_ICMPNE           = (byte)0xa0;
    static final byte IF_ICMPLT           = (byte)0xa1;
    static final byte IF_ICMPGE           = (byte)0xa2;
    static final byte IF_ICMPGT           = (byte)0xa3;
    static final byte IF_ICMPLE           = (byte)0xa4;
    static final byte IF_ACMPEQ           = (byte)0xa5;
    static final byte IF_ACMPNE           = (byte)0xa6;
    static final byte GOTO                = (byte)0xa7;
    static final byte JSR                 = (byte)0xa8;
    static final byte RET                 = (byte)0xa9;
    static final byte TABLESWITCH         = (byte)0xaa;
    static final byte LOOKUPSWITCH        = (byte)0xab;
    static final byte IRETURN             = (byte)0xac;
    static final byte LRETURN             = (byte)0xad;
    static final byte FRETURN             = (byte)0xae;
    static final byte DRETURN             = (byte)0xaf;
    static final byte ARETURN             = (byte)0xb0;
    static final byte RETURN              = (byte)0xb1;
    static final byte GETSTATIC           = (byte)0xb2;
    static final byte PUTSTATIC           = (byte)0xb3;
    static final byte GETFIELD            = (byte)0xb4;
    static final byte PUTFIELD            = (byte)0xb5;
    static final byte INVOKEVIRTUAL       = (byte)0xb6;
    static final byte INVOKESPECIAL       = (byte)0xb7;
    static final byte INVOKESTATIC        = (byte)0xb8;
    static final byte INVOKEINTERFACE     = (byte)0xb9;
    static final byte NEW                 = (byte)0xbb;
    static final byte NEWARRAY            = (byte)0xbc;
    static final byte ANEWARRAY           = (byte)0xbd;
    static final byte ARRAYLENGTH         = (byte)0xbe;
    static final byte ATHROW              = (byte)0xbf;
    static final byte CHECKCAST           = (byte)0xc0;
    static final byte INSTANCEOF          = (byte)0xc1;
    static final byte MONITORENTER        = (byte)0xc2;
    static final byte MONITOREXIT         = (byte)0xc3;
    static final byte WIDE                = (byte)0xc4;
    static final byte MULTIANEWARRAY      = (byte)0xc5;
    static final byte IFNULL              = (byte)0xc6;
    static final byte IFNONNULL           = (byte)0xc7;
    static final byte GOTO_W              = (byte)0xc8;
    static final byte JSR_W               = (byte)0xc9;
    static final byte BREAKPOINT          = (byte)0xca;    // reserved opcode
    static final byte RET_W               = (byte)0xd1;
    static final byte IMPDEP1             = (byte)0xfe;    // reserved opcode
    static final byte IMPDEP2             = (byte)0xff;    // reserved opcode
}

// end of ByteCodes.java
