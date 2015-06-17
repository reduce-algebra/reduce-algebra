package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
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

// $Id$


class BytecodeCore extends FnWithEnv
{

static LispObject catchTags;

static StringBuffer sb = new StringBuffer();

String printAs()
{
    sb.setLength(0);
    sb.append("#BPS");   
    if (nargs > 0xff)
    {   sb.append(Integer.toHexString(nargs >> 8));
        sb.append(":");
    }
    sb.append(Integer.toString(nargs & 0xff));
    sb.append("<");
    if (bytecodes == null) sb.append("null");
    else for (int i=0; i<bytecodes.length; i++)
    {   String s = Integer.toHexString(bytecodes[i] & 0xff);
        if (s.length() == 1) s = "0" + s;
        sb.append(s);
    }
    sb.append(">");
    return sb.toString();
}

void iprint() throws ResourceException
{
    String s = printAs();
    if ((currentFlags & noLineBreak) == 0 &&
        currentOutput.column + s.length() > currentOutput.lineLength)
        currentOutput.println();
    currentOutput.print(s);
}

void blankprint() throws ResourceException
{
    String s = printAs();
    if ((currentFlags & noLineBreak) == 0 &&
        currentOutput.column + s.length() >= currentOutput.lineLength)
        currentOutput.println();
    else currentOutput.print(" ");
    currentOutput.print(s);
}

public LispObject op0() throws Exception
{
    if (nargs != 0) Jlisp.error("Wrong number of arguments for " + name);
    return interpret(0);
}

public LispObject op1(LispObject a1) throws Exception
{
    if (nargs != 1) Jlisp.error("Wrong number of arguments for " + name);
    int spsave = sp;
    LispObject r = Jlisp.nil;
    stack[++sp] = a1;
    try
    {   r = interpret(0);
        sp--;
    }
    catch (Exception e)
    {   sp = spsave;
        throw e;
    }
    return r;
}

public LispObject op2(LispObject a1, LispObject a2) throws Exception
{
    if (nargs != 2) Jlisp.error("Wrong number of arguments for " + name);
    int spsave = sp;
    LispObject r = Jlisp.nil;
    stack[++sp] = a1;
    stack[++sp] = a2;
    try
    {   r = interpret(0);
        sp -= 2;
    }
    catch (Exception e)
    {   sp = spsave;
        throw e;
    }
    return r;
}

public LispObject opn(LispObject [] args) throws Exception
{
    int n = args.length;
    if (nargs != n) Jlisp.error("Wrong number of arguments for " + name);
    int spsave = sp;
    for (int i=0; i<args.length; i++)
        stack[++sp] = args[i];
    if (n > 3)
    {   if (n != (bytecodes[0] & 0xff)) 
        {   sp = spsave;
            error("Wrong number of args");
        }
        n = 1;
    }
    else n = 0;
    LispObject r = Jlisp.nil;
    try
    {   r = interpret(n);
        sp = spsave;
    }
    catch (Exception e)
    {   sp = spsave;
        throw e;
    }
    return r;
}


static LispFunction builtin0[], builtin1[], builtin2[], builtin3[];

static LispFunction find(String s) throws ResourceException
{
    LispFunction r = (LispFunction)Jlisp.builtinFunctions.get(s);
    if (r == null) Jlisp.printf("Function \"%s\" not found%n", s);
    return r;
}

static int BIbatchp, BIdate, BIeject, BIerror1, BIgctime,
    BIgensym, BIlposn, BIrandom_fixnum, BIposn, BIread,
    BIreadch, BIterpri, BItime, BItyi, BIload_spid,
    BIabs, BIadd1, BIatan, BIapply0, BIatom,
    BIboundp, BIchar_code, BIclose, BIcodep, BIcompress,
    BIconstantp, BIdigit, BIendp, BIeval, BIevenp,
    BIevlis, BIexplode, BIexplode2lc, BIexplode2, BIexplodec,
    BIfixp, BIfloat, BIfloatp, BIsymbol_specialp, BIgc,
    BIgensym1, BIgetenv, BIsymbol_globalp, BIiadd1, BIsymbolp,
    BIiminus, BIiminusp, BIindirect, BIintegerp, BIintern,
    BIisub1, BIlength, BIlengthc, BIlinelength, BIliter,
    BIload_module, BIlognot, BImacroexpand, BImacroexpand_1, BImacro_function,
    BImake_bps, BImake_global, BImake_simple_string, BImake_special, BIminus,
    BIminusp, BImkvect, BImodular_minus, BImodular_number, BImodular_reciprocal,
    BInull, BIoddp, BIonep, BIpagelength, BIpairp,
    BIplist, BIplusp, BIprin, BIprinc, BIprint,
    BIprintc, BIrandom, BIrational, BIrdf, BIrds,
    BIremd, BIreverse, BIreversip, BIreversip2, BIseprp, BIset_small_modulus,
    BIspaces, BIxtab, BIspecial_char, BIspecial_form_p, BIspool,
    BIstop, BIstringp, BIsub1, BIsymbol_env, BIsymbol_function,
    BIsymbol_name, BIsymbol_value, BIsystem, BIfix, BIttab,
    BItyo, BIremob, BIunmake_global, BIunmake_special, BIupbv,
    BIvectorp, BIsimple_vectorp, BIverbos, BIwrs, BIzerop,
    BIcar, BIcdr, BIcaar, BIcadr, BIcdar,
    BIcddr, BIqcar, BIqcdr, BIqcaar, BIqcadr,
    BIqcdar, BIqcddr, BIncons, BInumberp, BIis_spid,
    BIspid_to_nil, BImv_listSTAR, BIappend, BIash, BIassoc,
    BIatsoc, BIdeleq, BIdelete, BIdivide, BIeqcar,
    BIeql, BIeqn, BIexpt, BIflag, BIflagpcar,
    BIgcdn, BIgeq, BIgetv, BIgreaterp, BIidifference,
    BIigreaterp, BIilessp, BIimax, BIimin, BIiplus2,
    BIiquotient, BIiremainder, BIirightshift, BIitimes2, BIlcm,
    BIleq, BIlessp, BImake_random_state, BImax2, BImember,
    BImemq, BImin2, BImod, BImodular_difference, BImodular_expt,
    BImodular_plus, BImodular_quotient, BImodular_times, BInconc, BIneq,
    BIorderp, BIordp, BIquotient, BIremainder, BIremflag,
    BIremprop, BIrplaca, BIrplacd, BIschar, BIset,
    BIsmemq, BIsubla, BIsublis, BIsymbol_set_definition, BIsymbol_set_env,
    BIxcons, BIequal, BIeq, BIcons,
    BIlist2, BIget, BIqgetv, BIflagp, BIapply1,
    BIdifference, BIplus2, BItimes2, BIequalcar, BIiequal, BIbps_putv,
    BIerrorset, BIlist2STAR, BIlist3, BIputprop, BIputv,
    BIputv_char, BIsubst, BIapply2, BIacons;

static void setupBuiltins() throws ResourceException
{
    builtin0 = new LispFunction[15];
    builtin1 = new LispFunction[114];
    builtin2 = new LispFunction[73];
    builtin3 = new LispFunction[10];

    builtin0[0] =find("batchp");               BIbatchp =                0;
    builtin0[1] =find("date");                 BIdate =                  1;
    builtin0[2] =find("eject");                BIeject =                 2;
    builtin0[3] =find("error1");               BIerror1 =                3;
    builtin0[4] =find("gctime");               BIgctime =                4;
    builtin0[5] =find("gensym");               BIgensym =                5;
    builtin0[6] =find("lposn");                BIlposn =                 6;
    builtin0[7] =find("random-fixnum");        BIrandom_fixnum =           7;
    builtin0[8] =find("posn");                 BIposn =                  8;
    builtin0[9] =find("read");                 BIread =                  9;
    builtin0[10]=find("readch");               BIreadch =                10;
    builtin0[11]=find("terpri");               BIterpri =                11;
    builtin0[12]=find("time");                 BItime =                  12;
    builtin0[13]=find("~tyi");                 BItyi =                   13;
    builtin0[14]=find("load-spid");            BIload_spid =             14;

    builtin1[0] =find("abs");                  BIabs =                   0;
    builtin1[1] =find("add1");                 BIadd1 =                  1;
    builtin1[2] =find("atan");                 BIatan =                  2;
    builtin1[3] =find("apply0");               BIapply0 =                3;
    builtin1[4] =find("atom");                 BIatom =                  4;
    builtin1[5] =find("boundp");               BIboundp =                5;
    builtin1[6] =find("char-code");            BIchar_code =             6;
    builtin1[7] =find("close");                BIclose =                 7;
    builtin1[8] =find("codep");                BIcodep =                 8;
    builtin1[9] =find("compress");             BIcompress =              9;
    builtin1[10]=find("constantp");            BIconstantp =             10;
    builtin1[11]=find("digit");                BIdigit =                 11;
    builtin1[12]=find("endp");                 BIendp =                  12;
    builtin1[13]=find("eval");                 BIeval =                  13;
    builtin1[14]=find("evenp");                BIevenp =                 14;
    builtin1[15]=find("evlis");                BIevlis =                 15;
    builtin1[16]=find("explode");              BIexplode =               16;
    builtin1[17]=find("explode2lc");           BIexplode2lc =            17;
    builtin1[18]=find("explode2");             BIexplode2 =              18;
    builtin1[18]=find("explodec");             BIexplodec =              18;
    builtin1[19]=find("fixp");                 BIfixp =                  19;
    builtin1[20]=find("float");                BIfloat =                 20;
    builtin1[21]=find("floatp");               BIfloatp =                21;
    builtin1[22]=find("fluidp");               BIsymbol_specialp =       22;
    builtin1[23]=find("reclaim");              BIgc =                    23;
    builtin1[24]=find("gensym1");              BIgensym1 =               24;
    builtin1[25]=find("getenv");               BIgetenv =                25;
    builtin1[26]=find("globalp");              BIsymbol_globalp =        26;
    builtin1[27]=find("iadd1");                BIiadd1 =                 27;
    builtin1[28]=find("symbolp");              BIsymbolp =               28;
    builtin1[29]=find("iminus");               BIiminus =                29;
    builtin1[30]=find("iminusp");              BIiminusp =               30;
    builtin1[31]=find("indirect");             BIindirect =              31;
    builtin1[32]=find("integerp");             BIintegerp =              32;
    builtin1[33]=find("intern");               BIintern =                33;
    builtin1[34]=find("isub1");                BIisub1 =                 34;
    builtin1[35]=find("length");               BIlength =                35;
    builtin1[36]=find("lengthc");              BIlengthc =               36;
    builtin1[37]=find("linelength");           BIlinelength =            37;
    builtin1[38]=find("liter");                BIliter =                 38;
    builtin1[39]=find("load-module");          BIload_module =           39;
    builtin1[40]=find("lognot");               BIlognot =                40;
    builtin1[41]=find("macroexpand");          BImacroexpand =           41;
    builtin1[42]=find("macroexpand-1");        BImacroexpand_1 =         42;
    builtin1[43]=find("macro-function");       BImacro_function =        43;
    builtin1[44]=find("make-bps");             BImake_bps =              44;
    builtin1[45]=find("make-global");          BImake_global =           45;
    builtin1[46]=find("make-simple-string");   BImake_simple_string =    46;
    builtin1[47]=find("make-special");         BImake_special =          47;
    builtin1[48]=find("minus");                BIminus =                 48;
    builtin1[49]=find("minusp");               BIminusp =                49;
    builtin1[50]=find("mkvect");               BImkvect =                50;
    builtin1[51]=find("modular-minus");        BImodular_minus =         51;
    builtin1[52]=find("modular-number");       BImodular_number =        52;
    builtin1[53]=find("modular-reciprocal");   BImodular_reciprocal =    53;
    builtin1[54]=find("null");                 BInull =                  54;
    builtin1[55]=find("oddp");                 BIoddp =                  55;
    builtin1[56]=find("onep");                 BIonep =                  56;
    builtin1[57]=find("pagelength");           BIpagelength =            57;
    builtin1[58]=find("pairp");                BIpairp =                 58;
    builtin1[59]=find("plist");                BIplist =                 59;
    builtin1[60]=find("plusp");                BIplusp =                 60;
    builtin1[61]=find("prin");                 BIprin =                  61;
    builtin1[62]=find("princ");                BIprinc =                 62;
    builtin1[63]=find("print");                BIprint =                 63;
    builtin1[64]=find("printc");               BIprintc =                64;
    builtin1[65]=find("random");               BIrandom =                65;
    builtin1[66]=find("rational");             BIrational =              66;
    builtin1[67]=find("rdf");                  BIrdf =                   67;
    builtin1[68]=find("rds");                  BIrds =                   68;
    builtin1[69]=find("remd");                 BIremd =                  69;
    builtin1[70]=find("reverse");              BIreverse =               70;
    builtin1[71]=find("reversip");             BIreversip =              71;
    builtin1[72]=find("seprp");                BIseprp =                 72;
    builtin1[73]=find("set-small-modulus");    BIset_small_modulus =     73;
    builtin1[74]=find("spaces");               BIspaces =                74;
    builtin1[74]=find("xtab");                 BIxtab =                  74;
    builtin1[75]=find("special-char");         BIspecial_char =          75;
    builtin1[76]=find("special-form-p");       BIspecial_form_p =        76;
    builtin1[77]=find("spool");                BIspool =                 77;
    builtin1[78]=find("stop");                 BIstop =                  78;
    builtin1[79]=find("stringp");              BIstringp =               79;
    builtin1[80]=find("sub1");                 BIsub1 =                  80;
    builtin1[81]=find("symbol-env");           BIsymbol_env =            81;
    builtin1[82]=find("symbol-function");      BIsymbol_function =       82;
    builtin1[83]=find("symbol-name");          BIsymbol_name =           83;
    builtin1[84]=find("symbol-value");         BIsymbol_value =          84;
    builtin1[85]=find("system");               BIsystem =                85;
    builtin1[86]=find("fix");                  BIfix =                   86;
    builtin1[87]=find("ttab");                 BIttab =                  87;
    builtin1[88]=find("tyo");                  BItyo =                   88;
    builtin1[89]=find("remob");                BIremob =                 89;
    builtin1[90]=find("unmake-global");        BIunmake_global =         90;
    builtin1[91]=find("unmake-special");       BIunmake_special =        91;
    builtin1[92]=find("upbv");                 BIupbv =                  92;
    builtin1[93]=find("vectorp");              BIvectorp =               93;
    builtin1[93]=find("simple-vectorp");       BIsimple_vectorp =        93;
    builtin1[94]=find("verbos");               BIverbos =                94;
    builtin1[95]=find("wrs");                  BIwrs =                   95;
    builtin1[96]=find("zerop");                BIzerop =                 96;
    builtin1[97]=find("car");                  BIcar =                   97;
    builtin1[98]=find("cdr");                  BIcdr =                   98;
    builtin1[99]=find("caar");                 BIcaar =                  99;
    builtin1[100]=find("cadr");                BIcadr =                  100;
    builtin1[101]=find("cdar");                BIcdar =                  101;
    builtin1[102]=find("cddr");                BIcddr =                  102;
    builtin1[103]=find("qcar");                BIqcar =                  103;
    builtin1[104]=find("qcdr");                BIqcdr =                  104;
    builtin1[105]=find("qcaar");               BIqcaar =                 105;
    builtin1[106]=find("qcadr");               BIqcadr =                 106;
    builtin1[107]=find("qcdar");               BIqcdar =                 107;
    builtin1[108]=find("qcddr");               BIqcddr =                 108;
    builtin1[109]=find("ncons");               BIncons =                 109;
    builtin1[110]=find("numberp");             BInumberp =               110;
    builtin1[111]=find("is-spid");             BIis_spid =               111;
    builtin1[112]=find("spid-to-nil");         BIspid_to_nil =           112;
    builtin1[113]=find("mv-list");             BImv_listSTAR =           113;

    builtin2[0] =find("append");               BIappend =                0;
    builtin2[1] =find("ash");                  BIash =                   1;
    builtin2[2] =find("assoc");                BIassoc =                 2;
    builtin2[3] =find("atsoc");                BIatsoc =                 3;
    builtin2[4] =find("deleq");                BIdeleq =                 4;
    builtin2[5] =find("delete");               BIdelete =                5;
    builtin2[6] =find("divide");               BIdivide =                6;
    builtin2[7] =find("eqcar");                BIeqcar =                 7;
    builtin2[8] =find("eql");                  BIeql =                   8;
    builtin2[9] =find("eqn");                  BIeqn =                   9;
    builtin2[10]=find("expt");                 BIexpt =                  10;
    builtin2[11]=find("flag");                 BIflag =                  11;
    builtin2[12]=find("flagpcar");             BIflagpcar =              12;
    builtin2[13]=find("gcdn");                 BIgcdn =                  13;
    builtin2[14]=find("geq");                  BIgeq =                   14;
    builtin2[15]=find("getv");                 BIgetv =                  15;
    builtin2[16]=find("greaterp");             BIgreaterp =              16;
    builtin2[17]=find("idifference");          BIidifference =           17;
    builtin2[18]=find("igreaterp");            BIigreaterp =             18;
    builtin2[19]=find("ilessp");               BIilessp =                19;
    builtin2[20]=find("imax");                 BIimax =                  20;
    builtin2[21]=find("imin");                 BIimin =                  21;
    builtin2[22]=find("iplus2");               BIiplus2 =                22;
    builtin2[23]=find("iquotient");            BIiquotient =             23;
    builtin2[24]=find("iremainder");           BIiremainder =            24;
    builtin2[25]=find("irightshift");          BIirightshift =           25;
    builtin2[26]=find("itimes2");              BIitimes2 =               26;
    builtin2[27]=find("lcm");                  BIlcm =                   27;
    builtin2[28]=find("leq");                  BIleq =                   28;
    builtin2[29]=find("lessp");                BIlessp =                 29;
    builtin2[30]=find("make-random-state");    BImake_random_state =     30;
    builtin2[31]=find("max2");                 BImax2 =                  31;
    builtin2[32]=find("member");               BImember =                32;
    builtin2[33]=find("memq");                 BImemq =                  33;
    builtin2[34]=find("min2");                 BImin2 =                  34;
    builtin2[35]=find("mod");                  BImod =                   35;
    builtin2[36]=find("modular-difference");   BImodular_difference =    36;
    builtin2[37]=find("modular-expt");         BImodular_expt =          37;
    builtin2[38]=find("modular-plus");         BImodular_plus =          38;
    builtin2[39]=find("modular-quotient");     BImodular_quotient =      39;
    builtin2[40]=find("modular-times");        BImodular_times =         40;
    builtin2[41]=find("nconc");                BInconc =                 41;
    builtin2[42]=find("neq");                  BIneq =                   42;
    builtin2[43]=find("orderp");               BIorderp =                43;
    builtin2[43]=find("ordp");                 BIordp =                  43;
    builtin2[44]=find("quotient");             BIquotient =              44;
    builtin2[45]=find("remainder");            BIremainder =             45;
    builtin2[46]=find("remflag");              BIremflag =               46;
    builtin2[47]=find("remprop");              BIremprop =               47;
    builtin2[48]=find("rplaca");               BIrplaca =                48;
    builtin2[49]=find("rplacd");               BIrplacd =                49;
    builtin2[50]=find("schar");                BIschar =                 50;
    builtin2[51]=find("set");                  BIset =                   51;
    builtin2[52]=find("smemq");                BIsmemq =                 52;
    builtin2[53]=find("subla");                BIsubla =                 53;
    builtin2[54]=find("sublis");               BIsublis =                54;
    builtin2[55]=find("symbol-set-definition");BIsymbol_set_definition = 55;
    builtin2[56]=find("symbol-set-env");       BIsymbol_set_env =        56;
    builtin2[57]=find("times2");               BItimes2 =                57;
    builtin2[58]=find("xcons");                BIxcons =                 58;
    builtin2[59]=find("equal");                BIequal =                 59;
    builtin2[60]=find("eq");                   BIeq =                    60;
    builtin2[61]=find("cons");                 BIcons =                  61;
    builtin2[62]=find("list2");                BIlist2 =                 62;
    builtin2[63]=find("get");                  BIget =                   63;
    builtin2[64]=find("qgetv");                BIqgetv =                 64;
    builtin2[65]=find("flagp");                BIflagp =                 65;
    builtin2[66]=find("apply1");               BIapply1 =                66;
    builtin2[67]=find("difference");           BIdifference =            67;
    builtin2[68]=find("plus2");                BIplus2 =                 68;
    builtin2[69]=find("times2");               BItimes2 =                69;
    builtin2[70]=find("equalcar");             BIequalcar =              70;
    builtin2[71]=find("iequal");               BIiequal =                71;
    builtin2[72]=find("reversip");             BIreversip2 =             72;

    builtin3[0] =find("bps-putv");             BIbps_putv =              0;
    builtin3[1] =find("errorset");             BIerrorset =              1;
    builtin3[2] =find("list2*");               BIlist2STAR =             2;
    builtin3[3] =find("list3");                BIlist3 =                 3;
    builtin3[4] =find("put");                  BIputprop =               4;
    builtin3[5] =find("putv");                 BIputv =                  5;
    builtin3[6] =find("putv-char");            BIputv_char =             6;
    builtin3[7] =find("subst");                BIsubst =                 7;
    builtin3[8] =find("apply2");               BIapply2 =                8;
    builtin3[9] =find("acons");                BIacons =                 9;
}



static final int LOADLOC       =     0x00;
static final int LOADLOC0      =     0x01;
static final int LOADLOC1      =     0x02;
static final int LOADLOC2      =     0x03;
static final int LOADLOC3      =     0x04;
static final int LOADLOC4      =     0x05;
static final int LOADLOC5      =     0x06;
static final int LOADLOC6      =     0x07;
static final int LOADLOC7      =     0x08;
static final int LOADLOC8      =     0x09;
static final int LOADLOC9      =     0x0a;
static final int LOADLOC10     =     0x0b;
static final int LOADLOC11     =     0x0c;
static final int LOC0LOC1      =     0x0d;
static final int LOC1LOC2      =     0x0e;
static final int LOC2LOC3      =     0x0f;
static final int LOC1LOC0      =     0x10;
static final int LOC2LOC1      =     0x11;
static final int LOC3LOC2      =     0x12;
static final int VNIL          =     0x13;
static final int LOADLIT       =     0x14;
static final int LOADLIT1      =     0x15;
static final int LOADLIT2      =     0x16;
static final int LOADLIT3      =     0x17;
static final int LOADLIT4      =     0x18;
static final int LOADLIT5      =     0x19;
static final int LOADLIT6      =     0x1a;
static final int LOADLIT7      =     0x1b;
static final int LOADFREE      =     0x1c;
static final int LOADFREE1     =     0x1d;
static final int LOADFREE2     =     0x1e;
static final int LOADFREE3     =     0x1f;
static final int LOADFREE4     =     0x20;
static final int STORELOC      =     0x21;
static final int STORELOC0     =     0x22;
static final int STORELOC1     =     0x23;
static final int STORELOC2     =     0x24;
static final int STORELOC3     =     0x25;
static final int STORELOC4     =     0x26;
static final int STORELOC5     =     0x27;
static final int STORELOC6     =     0x28;
static final int STORELOC7     =     0x29;
static final int STOREFREE     =     0x2a;
static final int STOREFREE1    =     0x2b;
static final int STOREFREE2    =     0x2c;
static final int STOREFREE3    =     0x2d;
static final int LOADLEX       =     0x2e;
static final int STORELEX      =     0x2f;
static final int CLOSURE       =     0x30;
static final int CARLOC0       =     0x31;
static final int CARLOC1       =     0x32;
static final int CARLOC2       =     0x33;
static final int CARLOC3       =     0x34;
static final int CARLOC4       =     0x35;
static final int CARLOC5       =     0x36;
static final int CARLOC6       =     0x37;
static final int CARLOC7       =     0x38;
static final int CARLOC8       =     0x39;
static final int CARLOC9       =     0x3a;
static final int CARLOC10      =     0x3b;
static final int CARLOC11      =     0x3c;
static final int CDRLOC0       =     0x3d;
static final int CDRLOC1       =     0x3e;
static final int CDRLOC2       =     0x3f;
static final int CDRLOC3       =     0x40;
static final int CDRLOC4       =     0x41;
static final int CDRLOC5       =     0x42;
static final int CAARLOC0      =     0x43;
static final int CAARLOC1      =     0x44;
static final int CAARLOC2      =     0x45;
static final int CAARLOC3      =     0x46;
static final int CALL0         =     0x47;
static final int CALL1         =     0x48;
static final int CALL2         =     0x49;
static final int CALL2R        =     0x4a;
static final int CALL3         =     0x4b;
static final int CALLN         =     0x4c;
static final int CALL0_0       =     0x4d;
static final int CALL0_1       =     0x4e;
static final int CALL0_2       =     0x4f;
static final int CALL0_3       =     0x50;
static final int CALL1_0       =     0x51;
static final int CALL1_1       =     0x52;
static final int CALL1_2       =     0x53;
static final int CALL1_3       =     0x54;
static final int CALL1_4       =     0x55;
static final int CALL1_5       =     0x56;
static final int CALL2_0       =     0x57;
static final int CALL2_1       =     0x58;
static final int CALL2_2       =     0x59;
static final int CALL2_3       =     0x5a;
static final int CALL2_4       =     0x5b;
static final int BUILTIN0      =     0x5c;
static final int BUILTIN1      =     0x5d;
static final int BUILTIN2      =     0x5e;
static final int BUILTIN2R     =     0x5f;
static final int BUILTIN3      =     0x60;
static final int APPLY1        =     0x61;
static final int APPLY2        =     0x62;
static final int APPLY3        =     0x63;
static final int APPLY4        =     0x64;
static final int JCALL         =     0x65;
static final int JCALLN        =     0x66;
static final int JUMP          =     0x67;
static final int JUMP_B        =     0x68;
static final int JUMP_L        =     0x69;
static final int JUMP_BL       =     0x6a;
static final int JUMPNIL       =     0x6b;
static final int JUMPNIL_B     =     0x6c;
static final int JUMPNIL_L     =     0x6d;
static final int JUMPNIL_BL    =     0x6e;
static final int JUMPT         =     0x6f;
static final int JUMPT_B       =     0x70;
static final int JUMPT_L       =     0x71;
static final int JUMPT_BL      =     0x72;
static final int JUMPATOM      =     0x73;
static final int JUMPATOM_B    =     0x74;
static final int JUMPATOM_L    =     0x75;
static final int JUMPATOM_BL   =     0x76;
static final int JUMPNATOM     =     0x77;
static final int JUMPNATOM_B   =     0x78;
static final int JUMPNATOM_L   =     0x79;
static final int JUMPNATOM_BL  =     0x7a;
static final int JUMPEQ        =     0x7b;
static final int JUMPEQ_B      =     0x7c;
static final int JUMPEQ_L      =     0x7d;
static final int JUMPEQ_BL     =     0x7e;
static final int JUMPNE        =     0x7f;
// I will put these things into byte arrays so I want to have values
// in the range -128 to +127.
static final int JUMPNE_B      =     0x80 - 0x100;
static final int JUMPNE_L      =     0x81 - 0x100;
static final int JUMPNE_BL     =     0x82 - 0x100;
static final int JUMPEQUAL     =     0x83 - 0x100;
static final int JUMPEQUAL_B   =     0x84 - 0x100;
static final int JUMPEQUAL_L   =     0x85 - 0x100;
static final int JUMPEQUAL_BL  =     0x86 - 0x100;
static final int JUMPNEQUAL    =     0x87 - 0x100;
static final int JUMPNEQUAL_B  =     0x88 - 0x100;
static final int JUMPNEQUAL_L  =     0x89 - 0x100;
static final int JUMPNEQUAL_BL =     0x8a - 0x100;
static final int JUMPL0NIL     =     0x8b - 0x100;
static final int JUMPL0T       =     0x8c - 0x100;
static final int JUMPL1NIL     =     0x8d - 0x100;
static final int JUMPL1T       =     0x8e - 0x100;
static final int JUMPL2NIL     =     0x8f - 0x100;
static final int JUMPL2T       =     0x90 - 0x100;
static final int JUMPL3NIL     =     0x91 - 0x100;
static final int JUMPL3T       =     0x92 - 0x100;
static final int JUMPL4NIL     =     0x93 - 0x100;
static final int JUMPL4T       =     0x94 - 0x100;
static final int JUMPST0NIL    =     0x95 - 0x100;
static final int JUMPST0T      =     0x96 - 0x100;
static final int JUMPST1NIL    =     0x97 - 0x100;
static final int JUMPST1T      =     0x98 - 0x100;
static final int JUMPST2NIL    =     0x99 - 0x100;
static final int JUMPST2T      =     0x9a - 0x100;
static final int JUMPL0ATOM    =     0x9b - 0x100;
static final int JUMPL0NATOM   =     0x9c - 0x100;
static final int JUMPL1ATOM    =     0x9d - 0x100;
static final int JUMPL1NATOM   =     0x9e - 0x100;
static final int JUMPL2ATOM    =     0x9f - 0x100;
static final int JUMPL2NATOM   =     0xa0 - 0x100;
static final int JUMPL3ATOM    =     0xa1 - 0x100;
static final int JUMPL3NATOM   =     0xa2 - 0x100;
static final int JUMPFREE1NIL  =     0xa3 - 0x100;
static final int JUMPFREE1T    =     0xa4 - 0x100;
static final int JUMPFREE2NIL  =     0xa5 - 0x100;
static final int JUMPFREE2T    =     0xa6 - 0x100;
static final int JUMPFREE3NIL  =     0xa7 - 0x100;
static final int JUMPFREE3T    =     0xa8 - 0x100;
static final int JUMPFREE4NIL  =     0xa9 - 0x100;
static final int JUMPFREE4T    =     0xaa - 0x100;
static final int JUMPFREENIL   =     0xab - 0x100;
static final int JUMPFREET     =     0xac - 0x100;
static final int JUMPLIT1EQ    =     0xad - 0x100;
static final int JUMPLIT1NE    =     0xae - 0x100;
static final int JUMPLIT2EQ    =     0xaf - 0x100;
static final int JUMPLIT2NE    =     0xb0 - 0x100;
static final int JUMPLIT3EQ    =     0xb1 - 0x100;
static final int JUMPLIT3NE    =     0xb2 - 0x100;
static final int JUMPLIT4EQ    =     0xb3 - 0x100;
static final int JUMPLIT4NE    =     0xb4 - 0x100;
static final int JUMPLITEQ     =     0xb5 - 0x100;
static final int JUMPLITNE     =     0xb6 - 0x100;
static final int JUMPB1NIL     =     0xb7 - 0x100;
static final int JUMPB1T       =     0xb8 - 0x100;
static final int JUMPB2NIL     =     0xb9 - 0x100;
static final int JUMPB2T       =     0xba - 0x100;
static final int JUMPFLAGP     =     0xbb - 0x100;
static final int JUMPNFLAGP    =     0xbc - 0x100;
static final int JUMPEQCAR     =     0xbd - 0x100;
static final int JUMPNEQCAR    =     0xbe - 0x100;
static final int CATCH         =     0xbf - 0x100;
static final int CATCH_B       =     0xc0 - 0x100;
static final int CATCH_L       =     0xc1 - 0x100;
static final int CATCH_BL      =     0xc2 - 0x100;
static final int UNCATCH       =     0xc3 - 0x100;
static final int THROW         =     0xc4 - 0x100;
static final int PROTECT       =     0xc5 - 0x100;
static final int UNPROTECT     =     0xc6 - 0x100;
static final int PVBIND        =     0xc7 - 0x100;
static final int PVRESTORE     =     0xc8 - 0x100;
static final int FREEBIND      =     0xc9 - 0x100;
static final int FREERSTR      =     0xca - 0x100;
static final int EXIT          =     0xcb - 0x100;
static final int NILEXIT       =     0xcc - 0x100;
static final int LOC0EXIT      =     0xcd - 0x100;
static final int LOC1EXIT      =     0xce - 0x100;
static final int LOC2EXIT      =     0xcf - 0x100;
static final int PUSH          =     0xd0 - 0x100;
static final int PUSHNIL       =     0xd1 - 0x100;
static final int PUSHNIL2      =     0xd2 - 0x100;
static final int PUSHNIL3      =     0xd3 - 0x100;
static final int PUSHNILS      =     0xd4 - 0x100;
static final int POP           =     0xd5 - 0x100;
static final int LOSE          =     0xd6 - 0x100;
static final int LOSE2         =     0xd7 - 0x100;
static final int LOSE3         =     0xd8 - 0x100;
static final int LOSES         =     0xd9 - 0x100;
static final int SWOP          =     0xda - 0x100;
static final int EQ            =     0xdb - 0x100;
static final int EQCAR         =     0xdc - 0x100;
static final int EQUAL         =     0xdd - 0x100;
static final int NUMBERP       =     0xde - 0x100;
static final int CAR           =     0xdf - 0x100;
static final int CDR           =     0xe0 - 0x100;
static final int CAAR          =     0xe1 - 0x100;
static final int CADR          =     0xe2 - 0x100;
static final int CDAR          =     0xe3 - 0x100;
static final int CDDR          =     0xe4 - 0x100;
static final int CONS          =     0xe5 - 0x100;
static final int NCONS         =     0xe6 - 0x100;
static final int XCONS         =     0xe7 - 0x100;
static final int ACONS         =     0xe8 - 0x100;
static final int LENGTH        =     0xe9 - 0x100;
static final int LIST2         =     0xea - 0x100;
static final int LIST2STAR     =     0xeb - 0x100;
static final int LIST3         =     0xec - 0x100;
static final int PLUS2         =     0xed - 0x100;
static final int ADD1          =     0xee - 0x100;
static final int DIFFERENCE    =     0xef - 0x100;
static final int SUB1          =     0xf0 - 0x100;
static final int TIMES2        =     0xf1 - 0x100;
static final int GREATERP      =     0xf2 - 0x100;
static final int LESSP         =     0xf3 - 0x100;
static final int FLAGP         =     0xf4 - 0x100;
static final int GET           =     0xf5 - 0x100;
static final int LITGET        =     0xf6 - 0x100;
static final int GETV          =     0xf7 - 0x100;
static final int QGETV         =     0xf8 - 0x100;
static final int QGETVN        =     0xf9 - 0x100;
static final int BIGSTACK      =     0xfa - 0x100;
static final int BIGCALL       =     0xfb - 0x100;
static final int ICASE         =     0xfc - 0x100;
static final int FASTGET       =     0xfd - 0x100;
static final int SPARE1        =     0xfe - 0x100;
static final int SPARE2        =     0xff - 0x100;

// The table of names is just for debugging - but that is of course
// very important!
//- 
//- static final String [] opnames =
//- {
//-     "LOADLOC      ", "LOADLOC0     ", "LOADLOC1     ", "LOADLOC2     ",
//-     "LOADLOC3     ", "LOADLOC4     ", "LOADLOC5     ", "LOADLOC6     ",
//-     "LOADLOC7     ", "LOADLOC8     ", "LOADLOC9     ", "LOADLOC10    ",
//-     "LOADLOC11    ", "LOC0LOC1     ", "LOC1LOC2     ", "LOC2LOC3     ",
//-     "LOC1LOC0     ", "LOC2LOC1     ", "LOC3LOC2     ", "VNIL         ",
//-     "LOADLIT      ", "LOADLIT1     ", "LOADLIT2     ", "LOADLIT3     ",
//-     "LOADLIT4     ", "LOADLIT5     ", "LOADLIT6     ", "LOADLIT7     ",
//-     "LOADFREE     ", "LOADFREE1    ", "LOADFREE2    ", "LOADFREE3    ",
//-     "LOADFREE4    ", "STORELOC     ", "STORELOC0    ", "STORELOC1    ",
//-     "STORELOC2    ", "STORELOC3    ", "STORELOC4    ", "STORELOC5    ",
//-     "STORELOC6    ", "STORELOC7    ", "STOREFREE    ", "STOREFREE1   ",
//-     "STOREFREE2   ", "STOREFREE3   ", "LOADLEX      ", "STORELEX     ",
//-     "CLOSURE      ", "CARLOC0      ", "CARLOC1      ", "CARLOC2      ",
//-     "CARLOC3      ", "CARLOC4      ", "CARLOC5      ", "CARLOC6      ",
//-     "CARLOC7      ", "CARLOC8      ", "CARLOC9      ", "CARLOC10     ",
//-     "CARLOC11     ", "CDRLOC0      ", "CDRLOC1      ", "CDRLOC2      ",
//-     "CDRLOC3      ", "CDRLOC4      ", "CDRLOC5      ", "CAARLOC0     ",
//-     "CAARLOC1     ", "CAARLOC2     ", "CAARLOC3     ", "CALL0        ",
//-     "CALL1        ", "CALL2        ", "CALL2R       ", "CALL3        ",
//-     "CALLN        ", "CALL0_0      ", "CALL0_1      ", "CALL0_2      ",
//-     "CALL0_3      ", "CALL1_0      ", "CALL1_1      ", "CALL1_2      ",
//-     "CALL1_3      ", "CALL1_4      ", "CALL1_5      ", "CALL2_0      ",
//-     "CALL2_1      ", "CALL2_2      ", "CALL2_3      ", "CALL2_4      ",
//-     "BUILTIN0     ", "BUILTIN1     ", "BUILTIN2     ", "BUILTIN2R    ",
//-     "BUILTIN3     ", "APPLY1       ", "APPLY2       ", "APPLY3       ",
//-     "APPLY4       ", "JCALL        ", "JCALLN       ", "JUMP         ",
//-     "JUMP_B       ", "JUMP_L       ", "JUMP_BL      ", "JUMPNIL      ",
//-     "JUMPNIL_B    ", "JUMPNIL_L    ", "JUMPNIL_BL   ", "JUMPT        ",
//-     "JUMPT_B      ", "JUMPT_L      ", "JUMPT_BL     ", "JUMPATOM     ",
//-     "JUMPATOM_B   ", "JUMPATOM_L   ", "JUMPATOM_BL  ", "JUMPNATOM    ",
//-     "JUMPNATOM_B  ", "JUMPNATOM_L  ", "JUMPNATOM_BL ", "JUMPEQ       ",
//-     "JUMPEQ_B     ", "JUMPEQ_L     ", "JUMPEQ_BL    ", "JUMPNE       ",
//-     "JUMPNE_B     ", "JUMPNE_L     ", "JUMPNE_BL    ", "JUMPEQUAL    ",
//-     "JUMPEQUAL_B  ", "JUMPEQUAL_L  ", "JUMPEQUAL_BL ", "JUMPNEQUAL   ",
//-     "JUMPNEQUAL_B ", "JUMPNEQUAL_L ", "JUMPNEQUAL_BL", "JUMPL0NIL    ",
//-     "JUMPL0T      ", "JUMPL1NIL    ", "JUMPL1T      ", "JUMPL2NIL    ",
//-     "JUMPL2T      ", "JUMPL3NIL    ", "JUMPL3T      ", "JUMPL4NIL    ",
//-     "JUMPL4T      ", "JUMPST0NIL   ", "JUMPST0T     ", "JUMPST1NIL   ",
//-     "JUMPST1T     ", "JUMPST2NIL   ", "JUMPST2T     ", "JUMPL0ATOM   ",
//-     "JUMPL0NATOM  ", "JUMPL1ATOM   ", "JUMPL1NATOM  ", "JUMPL2ATOM   ",
//-     "JUMPL2NATOM  ", "JUMPL3ATOM   ", "JUMPL3NATOM  ", "JUMPFREE1NIL ",
//-     "JUMPFREE1T   ", "JUMPFREE2NIL ", "JUMPFREE2T   ", "JUMPFREE3NIL ",
//-     "JUMPFREE3T   ", "JUMPFREE4NIL ", "JUMPFREE4T   ", "JUMPFREENIL  ",
//-     "JUMPFREET    ", "JUMPLIT1EQ   ", "JUMPLIT1NE   ", "JUMPLIT2EQ   ",
//-     "JUMPLIT2NE   ", "JUMPLIT3EQ   ", "JUMPLIT3NE   ", "JUMPLIT4EQ   ",
//-     "JUMPLIT4NE   ", "JUMPLITEQ    ", "JUMPLITNE    ", "JUMPB1NIL    ",
//-     "JUMPB1T      ", "JUMPB2NIL    ", "JUMPB2T      ", "JUMPFLAGP    ",
//-     "JUMPNFLAGP   ", "JUMPEQCAR    ", "JUMPNEQCAR   ", "CATCH        ",
//-     "CATCH_B      ", "CATCH_L      ", "CATCH_BL     ", "UNCATCH      ",
//-     "THROW        ", "PROTECT      ", "UNPROTECT    ", "PVBIND       ",
//-     "PVRESTORE    ", "FREEBIND     ", "FREERSTR     ", "EXIT         ",
//-     "NILEXIT      ", "LOC0EXIT     ", "LOC1EXIT     ", "LOC2EXIT     ",
//-     "PUSH         ", "PUSHNIL      ", "PUSHNIL2     ", "PUSHNIL3     ",
//-     "PUSHNILS     ", "POP          ", "LOSE         ", "LOSE2        ",
//-     "LOSE3        ", "LOSES        ", "SWOP         ", "EQ           ",
//-     "EQCAR        ", "EQUAL        ", "NUMBERP      ", "CAR          ",
//-     "CDR          ", "CAAR         ", "CADR         ", "CDAR         ",
//-     "CDDR         ", "CONS         ", "NCONS        ", "XCONS        ",
//-     "ACONS        ", "LENGTH       ", "LIST2        ", "LIST2STAR    ",
//-     "LIST3        ", "PLUS2        ", "ADD1         ", "DIFFERENCE   ",
//-     "SUB1         ", "TIMES2       ", "GREATERP     ", "LESSP        ",
//-     "FLAGP        ", "GET          ", "LITGET       ", "GETV         ",
//-     "QGETV        ", "QGETVN       ", "BIGSTACK     ", "BIGCALL      ",
//-     "ICASE        ", "FASTGET      ", "SPARE1       ", "SPARE2       "
//- };

static int stack_size = 5000;
static LispObject [] stack = new LispObject[stack_size];
static int sp = 0;

static int poll_time_countdown = 0;

static long last_clock = -1;

//
// The Java systems I am using at present seem to treat the code here
// in a very unkind manner. Even though it is the one main hot-spot for the
// whole of Jlisp the default behaviour of the JIT is to observe that it is
// a bulky procedure and refuse to compile it unless one uses the specialist
// command line option -XX:-DontCompileHugeMethods. The consequence is a
// substantial performance hit. It seems that by default that methods that
// involve over 8K instructions in the JVM bytecode form will be rejected
// for compilation - originally this was over twice that size. When one does a
// web search many people say "Fire the programmer who wrote the large procedure"
// but for the current purpose I remain of the opinion that the original code I had
// here was about what I wanted, and the hacked version here now is ugly and
// unnatural and the awkwardness is merely to try to work around JIT
// limitations.
//
// The main method "interpret" here is now, at the time of measuring 7560 Java
// instructions long, and the JIT will compile methods of length up to 8K, so
// this now just squeezes in. But if I get round to supporting catch, throw and
// other things I may bump up against the limit again!               ACN May 2015



LispObject liftcalln(int arg, int iw, int sp,
                     LispObject a, LispObject b) throws Exception
{
    switch (iw)
    {
case 4: return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], b, a});
case 5: return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], b, a});
case 6: return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4], b, a});
case 7: return ((Symbol)env[arg]).fn.opn(new LispObject []
	    {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], b, a});
case 8: return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], b, a});
case 9: return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], b, a});
case 10:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8], b, a});
case 11:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], b, a});
case 12:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], b, a});
case 13:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], b, a});
case 14:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12], b, a});
case 15:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], b, a});
// The Standard Lisp Report mandates at least 15 arguments must be supported.
// Common Lisp maybe does not have any real limit? Anyway I will go to 20
// here.
case 16:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], b, a});
case 17:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], b, a});
case 18:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16], b, a});
case 19:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16],
             stack[sp+17], b, a});
case 20:return ((Symbol)env[arg]).fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16],
             stack[sp+17], stack[sp+18], b, a});
default:
        Jlisp.error("calls with over 20 args not supported in this Lisp");
        return Jlisp.nil;
    }
}

LispObject liftjcalln(int arg, int nargs, int sp,
                      LispObject a, LispObject b) throws Exception
{
    Symbol tocall = (Symbol)env[arg];
    switch (nargs)  // number of args
    {
// Just at present I do not treat calls to self specially here (in the
// way that I do for JCALL rather than JCALLN). This is something that I
// should fix sometime...
case 0: return tocall.fn.op0();
case 1: return tocall.fn.op1(a);
case 2: return tocall.fn.op2(b, a);
case 3: return tocall.fn.opn(new LispObject []
            {stack[sp], b, a});
case 4: sp -= 2;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], b, a});
case 5: sp -= 3;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], b, a});
case 6: sp -= 4;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4], b, a});
case 7: sp -= 5;
        return tocall.fn.opn(new LispObject []
	    {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
            stack[sp+5], b, a});
case 8: sp -= 6;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], b, a});
case 9: sp -= 7;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], b, a});
case 10:sp -= 8;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8], b, a});
case 11:sp -= 9;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], b, a});
case 12:sp -= 10;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], b, a});
case 13:sp -= 11;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], b, a});
case 14:sp -= 12;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12], b, a});
case 15:sp -= 13;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], b, a});
// The Standard Lisp Report mandates at least 15 arguments must be supported.
// Common Lisp maybe does not have any real limit? Anyway I will go to 20
// here.
case 16:sp -= 14;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], b, a});
case 17:sp -= 15;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], b, a});
case 18:sp -= 16;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16], b, a});
case 19:sp -= 17;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16],
             stack[sp+17], b, a});
case 20:sp -= 18;
        return tocall.fn.opn(new LispObject []
            {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4],
             stack[sp+5], stack[sp+6], stack[sp+7], stack[sp+8],
             stack[sp+9], stack[sp+10], stack[sp+11], stack[sp+12],
             stack[sp+13], stack[sp+14], stack[sp+15], stack[sp+16],
             stack[sp+17], stack[sp+18], b, a});
default:
        Jlisp.error("calls with over 20 args not supported in this Lisp",
                    LispInteger.valueOf(nargs));
        return Jlisp.nil;
    }
}

int jcallself(int arg, int spsave, LispObject a, LispObject b) throws Exception
{
    switch (arg & 0xe0)  // number of args
    {
case 0x00: return 0;
case 0x20: stack[spsave] =a;
           return 0;
case 0x40: stack[spsave] = a;
           stack[spsave-1] = b;
           return 0;
case 0x60: stack[spsave] = a;
           stack[spsave-1] = b;
           stack[spsave-2] = stack[sp];
           return 0;
case 0x80: stack[spsave] = a;
           stack[spsave-1] = b;
           stack[spsave-2] = stack[sp];
           stack[spsave-3] = stack[sp-1];
           return 1;  // NB to allow for arg-count byte
case 0xa0: stack[spsave] = a;
           stack[spsave-1] = b;
           stack[spsave-2] = stack[sp];
           stack[spsave-3] = stack[sp-1];
           stack[spsave-4] = stack[sp-2];
           return 1;
case 0xc0: stack[spsave] = a;
           stack[spsave-1] = b;
           stack[spsave-2] = stack[sp];
           stack[spsave-3] = stack[sp-1];
           stack[spsave-4] = stack[sp-2];
           stack[spsave-5] = stack[sp-3];
           return 1;
case 0xe0: stack[spsave] = a;
           stack[spsave-1] = b;
           stack[spsave-2] = stack[sp];
           stack[spsave-3] = stack[sp-1];
           stack[spsave-4] = stack[sp-2];
           stack[spsave-5] = stack[sp-3];
           stack[spsave-6] = stack[sp-4];
           return 1;
default:
           Jlisp.error("oddity with JCALL " +
                       Integer.toHexString(arg));
           return 0;
    }
}

LispObject jcall(int arg, int sp, LispObject a, LispObject b) throws Exception
{
    switch (arg & 0xe0)  // number of args
    {
case 0x00: return ((Symbol)env[arg & 0x1f]).fn.op0();
case 0x20: return ((Symbol)env[arg & 0x1f]).fn.op1(a);
case 0x40: return ((Symbol)env[arg & 0x1f]).fn.op2(b, a);
case 0x60: return ((Symbol)env[arg & 0x1f]).fn.opn(
                      new LispObject [] {stack[sp--], b, a});
case 0x80: sp -= 2;
           return ((Symbol)env[arg & 0x1f]).fn.opn(
               new LispObject [] {stack[sp+1], stack[sp+2], b, a});
case 0xa0: sp -= 3;
           return ((Symbol)env[arg & 0x1f]).fn.opn(
               new LispObject [] {stack[sp+1], stack[sp+2], stack[sp+3], b, a});
case 0xc0: sp -= 4;
           return ((Symbol)env[arg & 0x1f]).fn.opn(
               new LispObject [] {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4], b, a});
case 0xe0: sp -= 5;
           return ((Symbol)env[arg & 0x1f]).fn.opn(
               new LispObject [] {stack[sp+1], stack[sp+2], stack[sp+3], stack[sp+4], stack[sp+5], b, a});
default:
           return Jlisp.error("oddity with JCALL " +
                              Integer.toHexString(arg));
    }
}

void dopoll() throws Exception
{
    {   poll_time_countdown = 10000;
        long t = System.currentTimeMillis();;
        if (last_clock < 0) last_clock = t;
        else while (t - last_clock > 1000)
        {   last_clock += 1000;
            ResourceException.time_now++;
            if (ResourceException.time_limit > 0 &&
                ResourceException.time_now > ResourceException.time_limit)
            {   if (Jlisp.headline)
                {   Jlisp.errprint("\n+++ Time limit exceeded\n");
                }
                throw new ResourceException("time limit exceeded");
            }
        }
    } 
}

void extendstack() throws Exception
{
    int new_size = (3*stack_size)/2;
    LispObject [] new_stack = new LispObject[new_size];
    for (int i=0; i<=sp; i++) new_stack[i] = stack[i];
    stack = new_stack;
    stack_size = new_size;
    if (Jlisp.verbosFlag != 0)
        Jlisp.errprint("+++ Stack enlarged to " + stack_size);
}

int freebind(int arg, int sp)
{
    LispObject [] v = ((LispVector)env[arg]).vec;
    for (int i=0; i<v.length; i++)
    {   stack[++sp] = v[i].car/*value*/;
        v[i].car/*value*/ = Jlisp.nil;
    }
    stack[++sp] = env[arg];
    stack[++sp] = Spid.fbind;
    return sp;
}

long count = 0;

LispObject interpret(int pc) throws Exception
{
    Jlisp.printf("%nBytecodeCode.interpret called%n");
    System.exit(1);
    return Jlisp.nil;
}

int unwinder(int sp, int spsave, Exception e) throws ResourceException
{
    LispObject a;
    while (sp != spsave)
    {   a = stack[sp--];
        if (a == Spid.catcher)
        {   a = stack[sp--];
            catchTags = a.cdr;
// Ha ha I will return -sp if I find an active UNWIND-PROTECT record.
// Note that in this case sp will not be 0 because the jump address will
// still be stacked.
            if (a.car == Spid.protecter) return -sp;
            if (e instanceof LispThrow &&
                ((LispThrow)e).throwtag == a.car) return sp;
// If a CATCH record is not relevant just pop the three items that make it
// up.
            sp--;
            continue;
        }
        else if (a != Spid.fbind) continue;
        LispObject [] v = ((LispVector)stack[sp--]).vec;
        for (int i=v.length-1; i>=0; i--)
        {   v[i].car/*value*/ = stack[sp--];
        }
    }
    if (Jlisp.backtrace && !(e instanceof LispThrow))
    {   try
        {   Jlisp.errprint("Within: ");
            env[0].errPrint();
            Jlisp.errprintln();
        }
        catch (Exception e1)
        {}
    }
    return sp;
}

}

// End of BytecodeCore.java
