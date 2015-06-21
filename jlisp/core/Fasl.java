package uk.co.codemist.jlisp.core;


// $Id$


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
import java.io.*;
import java.math.*;
import java.util.zip.*;

class Fasl
{
    static OutputStream writer = null;
    static InputStream  reader = null;

    static LispObject [] recent = null;
    static int recentp, recentn;

    static String moduleName = "";

    static LispObject startModule(LispObject arg1) throws LispException
    {
        if (arg1 == Jlisp.nil) // terminate file
        {   if (writer != null)
            {   try
                {   writer.write(0);
                    writer.write(0);
                    writer.write(0); // repeated object count for NULL!
                    writer.write(LispObject.X_NULL);
                    writer.close();
                }
                catch (IOException e)
                {   writer = null;
                    Jlisp.errprintln(
                        "+++ IO error on FASL file: " +
                        e.getMessage());
                    return Jlisp.nil;
                }
                writer = null;
                recent = null;
                Jlisp.println("+++ FASLEND " + moduleName);
                moduleName = "";
                return Jlisp.lispTrue;
            }
            else return arg1;
        }
        if (Jlisp.outputImagePos < 0 ||
            Jlisp.images[Jlisp.outputImagePos] == null)
            return Jlisp.error("no output image available");
        String name;
        if (arg1 instanceof Symbol)
        {   ((Symbol)arg1).completeName();
            name = ((Symbol)arg1).pname;
        }
        else if (arg1 instanceof LispString) name = ((LispString)arg1).string;
        else return Jlisp.error("start-module needs a symbol or string");
        name = name + ".fasl";
        moduleName = name;
        try
        {   writer =
                new GZIPOutputStream(
                    new BufferedOutputStream(
                        new PDSOutputStream(
                            Jlisp.images[Jlisp.outputImagePos],
                            name),
                        32768));
        }
        catch (IOException e)
        {   Jlisp.errprintln(
                "+++ Trouble with file \"" + name +
                "\": " + e.getMessage());
            return Jlisp.nil;
        }
        recent = new LispObject [512];
        recentp = recentn = 0;
        return Jlisp.lispTrue;
    }

    static void defineInModule(int n) throws IOException
    {
// here I expect n to be in the range -1 to 0x3ffff
        n++;   // work with an offset number so that valid range includes "-1"
        writer.write(0); writer.write(0); writer.write(1); // sharedSize!
        writer.write(LispObject.X_DEFINMOD);
        int n1 = n >> 7;
        if (n1 == 0) writer.write(n);
        else
        {   writer.write(n | 0x80);
            n = n1;
            n1 = n >> 7;
            if (n1 == 0) writer.write(n);
            else
            {   writer.write(n | 0x80);
                writer.write(n >> 7);
            }
        }
    }

    static void faslWrite(LispObject arg1) throws Exception
    {
        Jlisp.dumpTree(arg1, writer);
    }
    
    static String name;

    static boolean openModule(LispObject arg1) throws LispException
    {
        name = "unknown";
        if (arg1 instanceof Symbol)
        {   ((Symbol)arg1).completeName();
            name = ((Symbol)arg1).pname;
        }
        else if (arg1 instanceof LispString) name = ((LispString)arg1).string;
        else Jlisp.error("symbol or string needed as module name");
        name = name + ".fasl";
        try 
        {   PDSInputStream ff = null;
            for (int i=0; i<Jlisp.imageCount; i++)
            {   try
                {   ff = new PDSInputStream(Jlisp.images[i], name);
                }
                catch (IOException e)
                {
                }
                if (ff != null) break;
            }
            if (ff == null) throw new IOException("module not found");
            reader =
                new GZIPInputStream(
                    new BufferedInputStream(ff, 32768));
        }
        catch (IOException e)
        {   Jlisp.errprintln(
                "+++ Trouble with file \"" + name +
                "\": " + e.getMessage());
            return true;  // failed
        }
        return false;
    }

    static LispObject loadModule(LispObject arg1, boolean sourceonly)
        throws Exception
    {
        InputStream readerSave = reader;
        LispObject [] recentSave = recent;
        LispObject r = Jlisp.nil;
        Symbol savedef = Symbol.intern("*savedef");
        LispObject saveSavedef = savedef.car;
        int recentpSave = recentp;
        reader = null;
        boolean saveHeadline = Jlisp.headline,
                saveBacktrace = Jlisp.backtrace;
        if (openModule(arg1)) return Jlisp.nil;
        try
        {   if ((Jlisp.verbosFlag & 2) != 0)
                Jlisp.println(
                  (sourceonly ? "Loading source for \"" :
                                "Fasl-loading \"") + name + "\"");
            Jlisp.headline = Jlisp.backtrace = true;
            recent = new LispObject [512];
            recentp = recentn = 0;
            LispObject lastSaveDef = Jlisp.nil;
            if (sourceonly) savedef.car = savedef;
            try
            {
                for (;;)
                {   LispObject w = faslRead();
                    if (w == null) break;
                    else if (w instanceof Spid)
                    {   Spid sw = (Spid)w;
                        if (sw.tag != Spid.DEFINMOD)
                        {   Jlisp.errprintln(
                                "bad data in loaded file (wrong Spid)");
                            break;
                        }
                        else
                        {   if (sw.data == -1) lastSaveDef = faslRead();
                            else 
                            {   readByteDef(sw.data, lastSaveDef, sourceonly);
                                lastSaveDef = Jlisp.nil;
                            }
                        }
                    }
                    try
                    {   if (!sourceonly) w.eval();
                    }
// Note that I catch and ignore STOP etc requests from fasl files
// as well as "normal" Lisp errors. Mildly dubious?
                    catch (Exception e)
                    {   Jlisp.errprintln(
                            "+++ Ignoring error in loaded file");
                        if (Jlisp.backtrace)
                        {   e.printStackTrace(new PrintWriter(
                              new WriterToLisp(
                                (LispStream)Jlisp.lit[Lit.err_output].car
                                    /*value*/)));
                        }
                    }
                }
            }
            catch (IOException e)
            {   Jlisp.errprintln(
                    "+++ IO error on fasl file: " + e.getMessage());
            }
            finally
            {   try
                {   if (reader != null) reader.close();
                }
                catch (IOException e)
                {   // Ignore IO errors on closing an input file.
                }
                savedef.car = saveSavedef;
            }
        }
        finally
        {   reader = readerSave;
            recent = recentSave;
            recentp = recentpSave;
            Jlisp.headline = saveHeadline;
            Jlisp.backtrace = saveBacktrace;
        }
        return Jlisp.nil;
    }

    static void readByteDef(int nargs, LispObject saved_definition, boolean sourceonly)
        throws Exception
    {
        Symbol name = (Symbol)faslRead();
        LispObject bps1 = faslRead();
        if (bps1 instanceof LispInteger)
        {   LispObject linkTo = faslRead();
            int nargs1 = bps1.intValue();
            LispFunction f = new CallAs(nargs, linkTo, nargs1);
            if (!sourceonly) name.fn = f;
            return;
        }
        LispObject env1 = faslRead();
        LispVector env = (LispVector)env1;
        Bytecode bps = (Bytecode)bps1;
        if (nargs >= 0x100)
        {   Bytecode bps2 =
                Jlisp.instrumented ? new InstrumentedByteOpt(nargs) :
                new ByteOpt(nargs);
            bps2.bytecodes = bps.bytecodes;
            bps = bps2;
        }
        bps.env = env.vec;
        bps.nargs = nargs;
        if (!sourceonly) name.fn = bps;
// Things are messy and complicated here because I want to track behaviour
// that is to some extent a matter of historical accident in CSL and
// complications that arise there. So I had better try to document what I
// think needs to happen. Note that compiler.red is liable to generate the
// same sequence of calls to define-in-module etc and hence put the same
// information in fasl files in each case, even though the detailed byte-level
// encoding of the data differs.
//
// if *savedef is false at load-time then any saved definitions that might
// be in the fasl file are ignored.
        if (Jlisp.lit[Lit.savedef].car == Jlisp.nil)
            saved_definition = Jlisp.nil;
// If we are only loading source then further filtering is done as to which
// definitions will be restored:
//   If the load-source property of a symbol is an integer then I check the
//   md60 of the definition I am thinking on loading and only accept it if
//   it matches. The purpose of this is to allow for cases where Reduce as a
//   whole has multiple definitions of the same name and I want to retrieve
//   a specific one. I can set the load-source property of the name to
//   identify the one I want. For this to work the "md60" checksummer must
//   behave identically as between the Lisp image creating the checksum and
//   the one loading it. Ideally that would go as far as matching between
//   CSL and Jlisp. Ha ha when I start to check that is far from being the
//   case - I will look to see how much pain would be involved in bringing the
//   two into agreement.
//   Well - I have just adjusted the code here so that at least most of the
//   time it is in exact alignment with CSL!

// More to do here @@@@ Specifically load things if the correct info is on the
// property list.

        if (saved_definition != Jlisp.nil)
            Fns.put(name, (Symbol)Jlisp.lit[Lit.savedef], saved_definition);
    }


    static LispObject faslRead() throws Exception
    {
        Jlisp.idump = reader;
        Jlisp.preRestore();
        Jlisp.descendSymbols = false;
        LispObject r = Jlisp.readObject();
        Jlisp.postRestore();
        return r;
    }

}

// end of Fasl.java

