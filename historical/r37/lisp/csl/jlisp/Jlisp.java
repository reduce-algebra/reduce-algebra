// Jlisp
//
// Standard Lisp system coded in Java. Actually this goes
// way beyond the Standard Lisp Report and includes a large fraction
// of that which is present in the CSL Lisp system.
//
// The purpose of this implementation is to support
// REDUCE. Early versions of jlisp were amazingly slow but
// performance is gradually improving!

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//


import java.io.*;
import java.math.*;
import java.util.*;
import java.util.zip.*;
import java.text.*;

public class Jlisp
{

// Within this file I will often reference lispIO and lispErr
// directly. Elsewhere they should ONLY be accessed via the Lisp
// variables that point towards them. The direct access here is in
// cases where the Lisp world may not have been fully set up.
static LispStream lispIO, lispErr;
static boolean interactivep = false;
static boolean debugFlag = false;
static boolean headline = true;
static boolean backtrace = true;
static LispObject errorCode;
static int verbosFlag = 1;

static void print(String s)
{
    ((LispStream)(lit[Lit.std_output].car/*value*/)).print(s);
}

static void println(String s)
{
    ((LispStream)(lit[Lit.std_output].car/*value*/)).println(s);
}

static void println()
{
    ((LispStream)(lit[Lit.std_output].car/*value*/)).println();
}

static void errprint(String s)
{
    ((LispStream)(lit[Lit.err_output].car/*value*/)).print(s);
}

static void errprintln(String s)
{
    ((LispStream)(lit[Lit.err_output].car/*value*/)).println(s);
}

static void errprintln()
{
    ((LispStream)(lit[Lit.err_output].car/*value*/)).println();
}

static void traceprint(String s)
{
    ((LispStream)(lit[Lit.tr_output].car/*value*/)).print(s);
}

static void traceprintln(String s)
{
    ((LispStream)(lit[Lit.tr_output].car/*value*/)).println(s);
}

static void traceprintln()
{
    ((LispStream)(lit[Lit.tr_output].car/*value*/)).println();
}

static LispObject error(String s) throws LispException
{
    if (headline)
    {   errprintln();
        errprintln("++++ " + s);
    }
    throw new LispException(s);
}

static LispObject error(String s, LispObject a) throws LispException
{
    if (headline)
    {   errprintln();
        errprint("++++ " + s + ": ");
        a.errPrint();
        errprintln();
    }
    throw new LispException(s);
}


// The main parts of this file relate to system startup options

static PDS [] images = new PDS[10];
static int outputImagePos;
static int imageCount;

static String [] imageFile = new String[10];

public static void main(String [] args)
{
    startup(args,
            new InputStreamReader(System.in),
            new PrintWriter(System.out),
            true);
}

static Reader in;
static PrintWriter out;

static boolean standAlone;

static Vector openOutputFiles = null;

static boolean restarting = false;
static String  restartModule = null;
static String  restartFn = null;
static String  restartArg = null;

static boolean finishingUp = false;

public static void startup(String [] args, 
                           Reader Xin, PrintWriter Xout,
                           boolean standAloneFlag)
{
    in = Xin;
    out = Xout;
    lispIO = null;
    standAlone = standAloneFlag;
    Thread t = null;
    if (standAlone)
    {   final int screenRefreshInterval = 2500;
        t = new FlushOutputThread();
        t.start();
    }
// I am pretty keen that all output files should be closed (and in the
// process they should be flushed) so that data is never lost. So I keep
// a record (in this Vector) of ones that are liable to need closing, and
// then in a "finally" clause I zoom through cleaning up.
    openOutputFiles = new Vector(10, 5);
    try
    {   startup1(args);
    }
    finally
    {
        lispIO = null;
        finishingUp = true;
        t.interrupt();     // so it can exit
        int i;
// In general I close in the opposite order from that in which I opened files.
// The code here is such that if closing one file happened to have a side
// effect of closing another along the way that would not be a calamity.
        while ((i=openOutputFiles.size()) != 0)
        {   ((LispStream)openOutputFiles.get(i-1)).close();
        }
    }
// If I was run as an application not an applet (via any route!) I am
// permitted to exit.
    if (!CWin.isApplet) System.exit(0);
}

static void startup1(String [] args)
{
    long startTime = System.currentTimeMillis();
    String [] inputFile = new String [10];
    int inputCount = 0;
    imageCount = 0;
    outputImagePos = -1;
    boolean coldStart = false;
    String mainOutput = null;
    String logFile = null;
    boolean verbose = false;
    boolean copyrightRequest = false;
    String [] errs = new String [10];
    int errCount = 0;
    String [] defineSymbol = new String [10];
    int defineCount = 0;
    String [] undefineSymbol = new String [10];
    int undefineCount = 0;
    boolean noRestart = false;
    boolean batchSwitch = false;

// The options that I accept here are intended to match (as far as I can
// reasonably make them) the ones used with the "CSL" Lisp implementation.
// I scan the command line to decode them. Note that until this has
// been completed I can not do proper Lisp output because I will not have
// seen redirection requests.
    int i;
    for (i=0; i<args.length; i++)
    {   String arg = args[i];
        String arg1;
        if (arg.length() >= 2 && arg.charAt(0) == '-')
        {   char key = Character.toLowerCase(arg.charAt(1));
            switch (key)
            {
        case '-': // redirect all output
                break;
        case 'b': // flips batchp() result
                batchSwitch = true;
                continue;
        case 'c': // display copyright notice
                copyrightRequest = true;
                continue;
        case 'd': // define symbol
                break;
        case 'e': // "experiment" control
                continue;
        case 'f': // serve on a socket
                break;
        case 'g': // enhance debugging
                debugFlag = true;
                continue;
        case 'i': // specify (input) image or library
                break;
        case 'k': // indicate amount of memory to use
                break;
        case 'l': // transcript of output to a log file
                break;
        case 'm': // (memory trace control)
                continue;
        case 'n': // ignore restart function in image
                noRestart = true;
                continue;
        case 'o': // output image
                break;
        case 'p': // profile option
                continue;
        case 'q': // quiet mode
                verbose = false;
                continue;
        case 'r': // initial random seed
                break;
        case 's': // view machine code from any compilation
                continue;
        case 't': // inspect time-stamp on a module
                continue;
        case 'u': // undefined symbol
                break;
        case 'v': // verbose mode
                verbose = true;
                continue;
        case 'w': // run in windowed mode
                continue;
        case 'x': // less trapping of possibly internal errors
                continue;
        case 'y': // ignore restart-function in saved image
                continue;
        case 'z': // cold start mode
                coldStart = true;
                continue;
        default:
                if (errCount < errs.length)
                    errs[errCount++] =
                        "Invalid option \"" + arg + "\"";
                continue;
            }
// In many cases an option takes an argument. I permit either -Ixx or -I xx
// and separate off xxx here.
            if (arg.length() > 2) arg1 = arg.substring(2);
            else if (i+1<args.length) arg1 = args[++i];
            else
            {   if (errCount < errs.length)
                    errs[errCount++] =
                        "Option \"" + arg +
                        "\" invalid as final option";
                continue;
            }
// Now arg is the initial key and arg1 is the follow-up.
            switch (key)
            {
        case '-': // redirect all output
                mainOutput = arg1;
                break;
        case 'd': // define a symbol
                if (defineCount < defineSymbol.length)
                    defineSymbol[defineCount++] = arg1;
                break;
        case 'f': // serve on a socket
                break;
        case 'i': // specify (input) image or library
                if (imageCount < imageFile.length)
                    imageFile[imageCount++] = arg1;
                break;
        case 'k': // indicate amount of memory to use
                break;
        case 'l': // transcript of output to a log file
                logFile = arg1;
                break;
        case 'o': // output image
// If the user specifies an output image then I will make it available
// as an input image too, in the place in the search-list that it
// appears on the command-line: eg
//    -i file1.img -o file2.img -i file3.img
// will scan in order file1/file2/file3 when loading files, and will
// write to file2.
                if (imageCount < imageFile.length)
                {   outputImagePos = imageCount;
                    imageFile[imageCount++] = arg1;
                }
                break;
        case 'r': // initial random seed
                break;
        case 'u': // undefined symbol
                if (undefineCount < undefineSymbol.length)
                    undefineSymbol[undefineCount++] = arg1;
                break;
            }
        }
        else inputFile[inputCount++] = arg;
    }
// Now I have finished decoding the command line. The first parts I
// process are those relating to the intended destination for
// output.

    Writer transcript = null;
// The directive "-l file" arranges that a copy of all output goes to
// the named file (if it can be opened) in addition to the usual
// destination (which may have been adjusted using "-- file").
    if (logFile != null)
    {   try
        {   transcript = new BufferedWriter(
                new FileWriter(LispStream.nameConvert(logFile)));
        }
        catch (IOException e)
        {   transcript = null;
            if (errCount < errs.length)
                errs[errCount++] =
                    "File \"" + logFile +
                    "\" unavailable as a log file";
        }
    }

// If the user had specified "-- file" then the main output is to that
// file. Otherwise the main output is to the initial "standard" stream.
// If the file named after "--" can not be opened for writing then the
// directive is ignored and output again goes to the "standard" place.

    if (mainOutput == null)
    {   if (transcript == null) lispIO = new LispOutputStream();
        else lispIO = new DoubleWriter(transcript);
    }
    else
    {   try
        {   if (transcript == null) lispIO = new LispOutputStream(mainOutput);
        else lispIO = new DoubleWriter(mainOutput, transcript);
        }
        catch (IOException e)
        {    errs[errCount++] =
                 "File \"" + mainOutput + "\" could not be written to";
            if (transcript == null) lispIO = new LispOutputStream();
            else lispIO = new DoubleWriter(transcript);
        }
    }
    if (transcript != null)
        lispIO.println("Transcript sent to file " + logFile);
    lispErr = lispIO; // lispErr sent to spool file if lispIO is...
// now I have Java variables that refer to the output streams I need
// to establish.

// Now I am in a position to display any errors relating to
// command line options.
    for (i=0; i<errCount; i++)
        lispErr.println(errs[i]);

    LispSmallInteger.preAllocate();  // some small integers treated specially

// For use while I am re-loading images and also to assist the
// custom Lisp bytecoded stuff I build a table of all the functions
// that I have built into this Lisp.
//
    builtinFunctions = new HashMap();
    builtinSpecials  = new HashMap();
    for (i=0; i<fns1.builtins.length; i++)
    {   ((LispFunction)fns1.builtins[i][1]).name =
            (String)fns1.builtins[i][0];
        builtinFunctions.put(fns1.builtins[i][0], fns1.builtins[i][1]);
    }
    for (i=0; i<fns2.builtins.length; i++)
    {   ((LispFunction)fns2.builtins[i][1]).name =
            (String)fns2.builtins[i][0];
        builtinFunctions.put(fns2.builtins[i][0], fns2.builtins[i][1]);
    }
    for (i=0; i<fns3.builtins.length; i++)
    {   ((LispFunction)fns3.builtins[i][1]).name =
            (String)fns3.builtins[i][0];
        builtinFunctions.put(fns3.builtins[i][0], fns3.builtins[i][1]);
    }
    for (i=0; i<fns4.builtins.length; i++)
    {   ((LispFunction)fns4.builtins[i][1]).name =
            (String)fns4.builtins[i][0];
        builtinFunctions.put(fns4.builtins[i][0], fns4.builtins[i][1]);
    }
    for (i=0; i<specfn.specials.length; i++)
    {   ((SpecialFunction)specfn.specials[i][1]).name =
            (String)specfn.specials[i][0];
        builtinSpecials.put(specfn.specials[i][0], specfn.specials[i][1]);
    }
    Bytecode.setupBuiltins();

// I open all the image files that the user had mentioned...
    if (imageCount == 0)
    {   if (verbose)
            lispErr.println(
                "Image file defaulting to in-store data");
        imageFile[0] = "-";
        imageCount = 1;
    }
    for (i=0; i<imageCount; i++)
    {   images[i] = null;
        try
        {   if (imageFile[0].equals("-"))
            {
// I get the ClassLoader for LispStream as a randomish convenient
// class that is part of my code. Then I can access my image as
// a resource, searching for it wherever I loaded my classes from.
// This may well be the .jar file I am using...
                ClassLoader cl = lispIO.getClass().getClassLoader();
                InputStream is = cl.getResourceAsStream("default.img");
                if (is != null) images[i] = new PDS(is);
            }
            else images[i] = new PDS(imageFile[i], i==outputImagePos);
        }
        catch (IOException e)
        {
        }
    }

// The next stage is either to create an initial Lisp heap or to
// re-load one that had been saved from a previous session. Things are
// made MUCH more complicated here because a running Lisp can (under program
// control) get itself restarted either in cold or warm-start mode.

    boolean loaded;

    for (;;)  // loop here is for the oddly named RESTART-CSL function
    {
        loaded = false;
// The next section is a sort of admission of confusion. When I restart the
// whole of the old word ought to get discarded: Java garbage collection
// ought to reap it. However that seems not to happen anything like as well
// as I intended, with BAD effects on total storage use in restarted systems
// (most of the old as well as most of the new heap remains!). This could
// well be MY fault with some valid Lisp root not being restored, but
// right now I can not find it and it COULD also be a consequence of
// a conservative GC strategy in the Java world. Anyway to reduce the pain as
// much as possible I will destroy a lot of connectivity in the old heap
// now so that even if bits of it are still referred to that will only lead
// to a small memory loss not a huge one.
        if (restarting)
        {   for (i=0; i<chars.length; i++)  chars[i] = null;
            for (i=0; i<oblist.length; i++)
            {   nil = oblist[i];
                // Do a radical clean-up of all existing symbols
                if (nil != null)
                {   nil.car/*value*/ = null;
                    nil.cdr/*plist*/ = null;
                    nil.fn = null;
                    nil.special = null;
                }
                oblist[i] = null;
            }
            oblistCount = 0;
            ((LispHash)lit[Lit.hashtab]).hash.clear();
            for (i=0; i<lit.length; i++)    lit[i] = null;
            for (i=0; i<spine.length; i++)  spine[i] = null;
            lispIO.tidyup(null);
            lispErr.tidyup(null);
            nil = null;
            lispTrue = null;
            modulus = 1;
            bigModulus = BigInteger.valueOf(modulus);
            Specfn.progData = null;
            Specfn.progEvent = Specfn.NONE;
            errorCode = null;
        }
        if (!coldStart)
        {   GZIPInputStream image = null;
            PDSInputStream ii = null;
// I will re-load from the first checkpoint file in the list that has
// a HeapImage stored in it.
            for (i=0; i<imageCount; i++)
            {   try
                {   ii = new PDSInputStream(images[i], "HeapImage");
                }
                catch (IOException e)
                {
                }
                if (ii != null) break;
            }
            try
            {   if (ii == null)
                    throw new IOException("No valid checkpoint file found");
                image = new GZIPInputStream(
                    new BufferedInputStream(ii, 32768));
                Symbol.symbolCount =
                Cons.consCount =
                LispString.stringCount = 0;
                restore(image);
                loaded = true;
            }
            catch (Exception e)
            {   lispErr.println("Failed to load image \"" +
                                       imageFile[0] + "<HeapImage>\"");
// The next two lines are for debugging at least
                lispErr.println(e.getMessage());
                e.printStackTrace(new PrintWriter(new WriterToLisp(lispErr)));
                loaded = false;
            }
            finally
            {   if (image != null)
                {   try
                    {   image.close();
                    }
                    catch (IOException e)
                    {   lispErr.println("Failed to load image");
                        loaded = false;
                    }
                }
            }
            if (restarting && !loaded)
            {   lispIO.println("+++ No image file when restarting");
                return;
            }
        }

// If no image file was available I will fall back to a cold start. This is
// probably not what is wanted in the long run but will be useful while
// testing.
        if (!loaded)
        {   initSymbols();
            DateFormat df = DateFormat.getInstance();
            df.setTimeZone(TimeZone.getDefault());
            lit[Lit.birthday] = new LispString(df.format(new Date()));
        }
        else
        {   // System.out.println("Bodge here...");
            initfns(fns4.builtins);
        }
        lispIO.tidyup(nil);
        lispErr.tidyup(nil);

// Having set up an image I optionally display a banner.
        if (verbose)
        {   lispIO.println("Jlisp 0.93a ... " +
               ((LispString)lit[Lit.birthday]).string);
            if (loaded)
            {   lispIO.println("Sym    = " + Symbol.symbolCount);
                lispIO.println("Cons   = " + Cons.consCount);
                lispIO.println("String = " + LispString.stringCount);
            }
            if (copyrightRequest)
            {
                lispIO.println("Copyright \u00a9 (C) Codemist Ltd, 1998-2000");
            }
        }

// If the user specifed -Dxxx, -Dxxx=yyy or -Uxxx on the command
// line I process that here. I will perform all the "undefine"
// operations before any of the "define" ones, but otherwise
// proceed left to right
        for (i=0; i<undefineCount; i++)
        {   Symbol s = Symbol.intern(undefineSymbol[i]);
            s.car/*value*/ = lit[Lit.undefined];
            s = null;
        }
        for (i=0; i<defineCount; i++)
        {   String name = defineSymbol[i];
            LispObject value;
            int eqPos = name.indexOf('=');
// Just -Dname without an "=" sets the name to T
            if (eqPos == -1) value = lispTrue;
            else
            {   String v = name.substring(eqPos+1);
                name = name.substring(0, eqPos);
                int lv = v.length();
// If the value specified was enclosed in double quotes I strip those
// off. Thus -Dname=xxx and -Dname="xxx" both set name to a string "xxx".
// Note that -Dname= will set name to the empty string "" which is non-nil
// so is OK for "true".
                if (lv != 0 &&
                    v.charAt(0) == '\"' &&
                    v.charAt(lv-1) == '\"')
                    v = v.substring(1, lv-1);
                value = new LispString(v);
            }
            Symbol s = Symbol.intern(name);
            s.car/*value*/ = value;
            s = null;
            value = null;
        }

        for (i=0; i<128; i++) // To speed up readch()
        {   chars[i] = Symbol.intern(String.valueOf((char)i));
        }

// If no input files had been specified I will read from the standard
// input - often the keyboard. Otherwise I will process each file that
// is given. This seems a bulky bit of code because of Java's
// insistence on exception processing. I do not work too hard on that!
        if (inputCount == 0)
        {   interactivep = !batchSwitch;
            if (!restarting)
                lispIO.setReader("<stdin>", in, standAlone, true);
            standardStreams();
            try
            {   readEvalPrintLoop(noRestart);
                throw new ProgEvent(ProgEvent.STOP, nil, "EOF");
            }
            catch (ProgEvent e)
            {   switch (e.type)
                {
            case ProgEvent.STOP:
                    restarting = false;
                    break;
            case ProgEvent.PRESERVE:
                    Cons w = (Cons)e.details;
                    preserve(w.car, w.cdr);
                    restarting = false;
                    break;
            case ProgEvent.RESTART:
                    println();
                    println("Restart Lisp...");
// the RESTART event has (details/extra) as Lisp items carried
// with it. 
//    If details=nil it asks for a cold start
//    If details=t   it asks for a normal start using the default
//                   restart-action from the image
//    if details=f   it does a warm restart but then calls function f
//                   (this is any atomic f not nil or t)
//    if details=(m f) it does a warm start, then loads module m and
//                   finally calls function f
// In the two latter cases (ie details other than nil/t) if extra is provided
// it is passed on as an argument to the user-specified restart function f.
//
// This elaborate behaviour is as grew up piecemeal in CSL and it is expected
// that this function is only used when setting up scripts to rebuild major
// bits of software so MAYBE the fact that it is a bit obscure is not too
// much of a problem.
                    restartFn = null;
                    restartModule = null;
                    restartArg = null;
                    if (e.details == nil) coldStart = true;
                    else try
                    {   coldStart = false;
                        if (e.details != lispTrue)
                        {   if (e.details.atom)
                            {   restartFn = Fns.explodeToString(e.details);
                            }
                            else
                            {   restartModule =
                                    Fns.explodeToString(e.details.car);
                                LispObject w1 = e.details.cdr;
                                if (!w1.atom) w1 = w1.car;
                                restartFn = Fns.explodeToString(w1);
                            }
                            if (e.extras != null)
                                restartArg = Fns.explodeToString(e.extras);
                        }
                    }
                    catch (Exception e1)
                    {   System.out.println("Unexpected exception " + e1);
                    }
// @@@ next line for debugging
print("restart mode " + restartFn + " " + restartModule + " " + restartArg);
                    restarting = true;
                    continue;
            default:
                    errprintln();
                    errprintln("Stopping because of " + e.message);
                    restarting = false;
                    break;
                }
            }
            if (restarting) continue;
            else break;
        }
        else
        {   interactivep = batchSwitch;
            if (restarting) inputCount = 1;
            for (i=0; i<inputCount; i++)
            {   try
                {   if (!restarting)
                        lispIO.setReader(
                            inputFile[i],
                            new BufferedReader(
                                new FileReader(inputFile[i])),
                            false, true);
                    standardStreams();
                    try
                    {   readEvalPrintLoop(noRestart);
                    }
                    catch (ProgEvent e)
                    {   switch (e.type)
                        {
                    case ProgEvent.STOP:
                            restarting = false;
                            i = inputCount;
                            break;
                    case ProgEvent.PRESERVE:
                            Cons w = (Cons)e.details;
                            preserve(w.car, w.cdr);
                            i = inputCount;
                            restarting = false;
                            break;
                    case ProgEvent.RESTART:
                            println();
                            println("Restart Lisp...");
                            restartFn = null;
                            restartModule = null;
                            restartArg = null;
                            if (e.details == nil) coldStart = true;
                            else try
                            {   coldStart = false;
                                if (e.details != lispTrue)
                                {   if (e.details.atom)
                                    {   restartFn = Fns.explodeToString(e.details);
                                    }
                                    else
                                    {   restartModule =
                                            Fns.explodeToString(e.details.car);
                                        LispObject w1 = e.details.cdr;
                                        if (!w1.atom) w1 = w1.car;
                                        restartFn = Fns.explodeToString(w1);
                                    }
                                    if (e.extras != null)
                                        restartArg = Fns.explodeToString(e.extras);
                                }
                            }
                            catch (Exception e1)
                            {   System.out.println("Unexpected exception " + e);
                            }
// @@@
println("restart mode " + restartFn + " " + restartModule + " " + restartArg);
                            i = inputCount;
                            restarting = true;
                            break;
                    default:
                            errprintln();
                            errprintln(
                                "Stopping because of " + e.message);
                            i = inputCount;
                            restarting = false;
                            break;
                        }
                    }
                    finally
                    {   if (!restarting) lispIO.reader.close();
                    }
                }
                catch (IOException e)
                {   errprintln("Failed to read from \"" +
                                       inputFile[i] + "\"");
                }
            }
        }
        if (restarting) continue;
        else break; // loop to do with RESTART-CSL calls
    }
    if (verbose)
    {   long endTime = System.currentTimeMillis();
        long elapsed = endTime - startTime;
        long secs = elapsed / 1000;
        long millis = elapsed % 1000;
        long tenths = millis / 100;
        long hunds = (millis % 100) / 10;
        lispIO.println("End of Lisp run after " +
            secs + "." + tenths + hunds + " seconds");
    }

    lispIO.close();

}

static void standardStreams()
{
    lit[Lit.std_output].car/*value*/  = lispIO;
    lit[Lit.tr_output].car/*value*/   = lispIO;
    lit[Lit.err_output].car/*value*/  = lispErr;
    lit[Lit.std_input].car/*value*/   = lispIO;
    lit[Lit.terminal_io].car/*value*/ = lispIO;
    lit[Lit.debug_io].car/*value*/    = lispIO;
    lit[Lit.query_io].car/*value*/    = lispIO;
}


static void preserve(LispObject arg1, LispObject arg2)
{
    PDS imagePDS = images[outputImagePos];
    if (imagePDS == null)
    {   errprintln("no output image file available");
        return;
    }
    LispObject save1 = lit[Lit.restart];
    LispObject save2 = lit[Lit.banner];
    lit[Lit.restart] = arg1;
    lit[Lit.banner] = arg2;

    LispObject oldBirthday = lit[Lit.birthday];
// I want the new image file to have a fresh date
    DateFormat df = DateFormat.getInstance();
    df.setTimeZone(TimeZone.getDefault());
    lit[Lit.birthday] =
        new LispString(df.format(new Date()));

    GZIPOutputStream dump = null;
    try
    {   dump = new GZIPOutputStream(
                   new BufferedOutputStream(
                       new PDSOutputStream(imagePDS, "HeapImage"),
                       32768));
        preserve(dump);
        println();
        println("Image written");
    }
    catch (IOException e)
    {   errprintln("IO error on dump file: " + e.getMessage());
    }
    finally
    {   if (dump != null)
        try
        {   dump.close();
        }
        catch (IOException e)
        {
        }
        lit[Lit.birthday] = oldBirthday;
        lit[Lit.restart] = save1;
        lit[Lit.banner] = save2;
    }
}

// At one stage the code that follows was in a separate class. That was done
// so that I could serialize the instance of the class concerned to capture
// the entire useful state of Lisp. Now I use my own serialization code
// it is nicer to have enerything in one top-level class

public static Symbol nil, lispTrue;
static LispObject [] lit = new LispObject[Lit.names.length];

static int modulus = 1;
static BigInteger bigModulus = BigInteger.ONE;
static int printprec = 15;

static Fns1 fns1 = new Fns1();
static Fns2 fns2 = new Fns2();
static Fns3 fns3 = new Fns3();
static Fns4 fns4 = new Fns4();
static Specfn specfn = new Specfn();

// I choose my initial oblist size so that REDUCE can run without need
// for re-hashing at all often. The size must also be a prime, and 9001
// seems to fit the bill.
static int oblistSize = 9001;
static int oblistCount = 0;
static Symbol [] oblist = new Symbol[oblistSize];
static LispVector obvector = new LispVector((LispObject [])oblist);

static Symbol [] chars  = new Symbol[128];  // to speed up READCH
static LispObject [] spine = new LispObject[17]; // for PRESERVE


static int inputType;

static OutputStream odump;
static InputStream  idump;

static HashSet objects;
static HashMap repeatedObjects;
static int sharedIndex;
static Stack stack;
static boolean specialNil, descendSymbols;

static void scanObject(LispObject a)
{
    if (a == null) return;
    stack.push(a);
    try              // keep going until the stack empties.
    {   for (;;)
        {   LispObject w = (LispObject)stack.pop();
            w.scan();
        }
    }
    catch (EmptyStackException e)
    {
    }
}

static void writeObject(LispObject a) throws IOException
{
    if (a == null)
    {   odump.write(LispObject.X_NULL);
        return;
    }
    stack.push(a);
    try              // keep going until the stack empties.
    {   for (;;)
        {   LispObject w = (LispObject)stack.pop();
            if (w == null) odump.write(LispObject.X_NULL);
            else w.dump();
        }
    }
    catch (EmptyStackException e)
    {
    }
}

static void preserve(OutputStream dump) throws IOException
{
    int i;
    odump = dump;
    descendSymbols = true;
    LispNumber g1 = LispInteger.valueOf(Fns.gensymCounter);
    LispNumber g2 = LispInteger.valueOf(modulus);
    LispNumber g3 = LispInteger.valueOf(printprec);
    LispString gp = null;
    if (Fns.prompt != null) gp = new LispString(Fns.prompt);
    try
    {   objects = new HashSet();
        repeatedObjects = new HashMap();
        stack = new Stack();
        sharedIndex = 0;
// First scan to detect shared sub-structures
        scanObject(nil);
        scanObject(lispTrue);
        for (i=0; i<Lit.names.length; i++)
            scanObject(lit[i]);
        for (i=0; i<oblistSize; i++)
        {   scanObject(oblist[i]);
        }
        scanObject(gp);
        scanObject(g1);
        scanObject(g2);
        scanObject(g3);

// Now write it out. The code here MUST process the same set of things as
// that above. But before I write out the main heap I will dump
// some special header info...
        int n = repeatedObjects.size();
        odump.write(n>>16);
        odump.write(n>>8);
        odump.write(n);
// See comments where the banner is loaded and displayed to the effect that
// I might want to store this information elsewhere...
        byte [] rep = null;
        if (lit[Lit.banner] instanceof LispString)
        {   rep = ((LispString)lit[Lit.banner]).string.getBytes("UTF8");
            n = rep.length;
        }
        else n = 0;
        odump.write(n>>16);
        odump.write(n>>8);
        odump.write(n);
        for (i=0; i<n; i++) odump.write(rep[i]);

// OK - now for the bulk of the heap
        specialNil = false; // extra careful while writing NIL itself!
        writeObject(nil);
        specialNil = true;
        writeObject(lispTrue);
        for (i=0; i<Lit.names.length; i++)
            writeObject(lit[i]);
        for (i=0; i<oblistSize; i++)
        {   Symbol s = oblist[i];
            if (s!=null)
            {   writeObject(s);
            }
        }
        odump.write(LispObject.X_ENDHASH); // marks end of oblist data
        if (Fns.prompt == null) odump.write(0);
        else
        {   odump.write(1);
            writeObject(new LispString(Fns.prompt));
        }
        writeObject(g1);
        writeObject(g2);
        writeObject(g3);

    }
    finally
    {   objects = null;
        repeatedObjects = null;
        stack = null;
    }

}

static void dumpTree(LispObject a, OutputStream dump) throws IOException
{
    int i;
    odump = dump;
    descendSymbols = false;
    try
    {   objects = new HashSet();
        repeatedObjects = new HashMap();
        stack = new Stack();
        sharedIndex = 0;
        scanObject(a);
        i = repeatedObjects.size();
        odump.write(i>>16);
        odump.write(i>>8);
        odump.write(i);
        writeObject(a);
    }
    finally
    {   objects = null;
        repeatedObjects = null;
        stack = null;
    }

}

static final int S_VECTOR     =  0;      // + number of items to come

static final int S_START      = -1;
static final int S_CDR        = -2;
static final int S_HASHKEY    = -3;
static final int S_HASHVAL    = -4;
static final int S_SYMVAL     = -5;
static final int S_SYMPLIST   = -6;
static final int S_SYMFN      = -7;
static final int S_SYMSPECIAL = -8;
static final int S_AUTONAME   = -9;
static final int S_AUTODATA   = -10;
static final int S_INTERP_BODY= -11;
static final int S_MACRO_BODY = -12;
static final int S_CALLAS_BODY= -13;

static final int S_CADR       = -100;  // +0 to +15 offsets from this used

static int istacklimit;
static int [] istack;
static int sharedSize;
static LispObject [] shared;
static HashMap builtinFunctions, builtinSpecials;


static void preRestore() throws IOException
{
    sharedIndex = 0;
    sharedSize = idump.read();
    sharedSize = (sharedSize<<8) + idump.read();
    sharedSize = (sharedSize<<8) + idump.read();
    shared = new LispObject[sharedSize];
    istacklimit = 500;
    istack = new int[istacklimit];
    stack = new Stack();
    stack.push(new Cons()); // to make "peek()" valid even when empty
}

static void postRestore()
{
    istack = null;
    stack = null;
    shared = null;
}


static void restore(InputStream dump) throws IOException
{
    idump = dump;
    preRestore();
    descendSymbols = true;
// First I will read and display the banner...
// I would like to be able to update JUST this banner in a heap image. To
// support that I will (sometime!) change my heap format to put the
// banner as an initial chunk of bytes in the PDS outside the compressed
// data that represents the main heap image. One natural place to put it
// will be as part of the directory entry for the initial image, and another
// would be at the very start of the whole image file.
    int n, i;
    n = idump.read();
    n = (n<<8) + idump.read();
    n = (n<<8) + idump.read();
    if (n != 0)
    {   byte [] b = new byte[n];
        for (i=0; i<n; i++) b[i] = (byte)idump.read();
        lispIO.println(new String(b, "UTF8"));
        lispIO.flush();
    }

    nil = (Symbol)readObject();

    lispTrue = (Symbol)readObject();

    for (i=0; i<Lit.names.length; i++)
    {   lit[i] = readObject();
    }

    for (i=0; i<oblistSize; i++) oblist[i] = null;
    oblistCount = 0;
    Symbol s;
// When restoring a heap image my oblist handling can be fairly
// simple: I should NEVER get any attempt to insert an item that is already
// there and when I start I start with an empty table so there are no deleted
// items to worry about.
    while ((s = (Symbol)readObject()) != null)
    {
        String name = s.pname;
//if (name.length() > 1) System.out.println("restore symbol <" + name + "> length " + name.length());
        int inc = name.hashCode();
//System.out.println("raw hash = " + Integer.toHexString(inc));
// I want my hash addresses and the increment to be positive...
// and Java tells me what the hash algorithm for strings is. What I do here
// ensures that strings that differ only in their final character get placed
// some multiple of 169 apart (is not quite adjacant).
        int hash = ((169*inc) & 0x7fffffff) % oblistSize;
        inc = 1 + ((inc & 0x7fffffff) % (oblistSize-1)); // never zero
//System.out.println("first probe = " + hash + " " + inc);
        while (oblist[hash] != null)
        {   if (oblist[hash].pname.equals(name))
                System.out.println("Two symbols called <" + name + "> " +
                   Integer.toHexString((int)name.charAt(0)));
            hash += inc;
            if (hash >= oblistSize) hash -= oblistSize;
//System.out.println("next probe = " + hash);
        }
//System.out.println("Put <" + name + "> at " + hash + " " + inc);
        oblist[hash] = s;
        oblistCount++;
// I will permit the hash table loading to reach 0.75, but then I take action
        if (4*oblistCount > 3*oblistSize) reHashOblist();
    }
//System.out.println("termination of oblist found : " + oblistCount);

    LispObject w;

    if (idump.read() == 0) Fns.prompt = null;
    else
    {   w = readObject();
        Fns.prompt = ((LispString)w).string;
    }

    w = readObject();
    try { Fns.gensymCounter = w.intValue(); }
    catch (Exception ee) { Fns.gensymCounter = 0; }

    w = readObject();
    try { modulus = w.intValue(); }
    catch (Exception ee) { modulus = 1; }
    bigModulus = BigInteger.valueOf(modulus);

    w = readObject();
    try { printprec = w.intValue(); }
    catch (Exception ee) { printprec = 14; }


    postRestore();
}

static boolean isPrime(int n)
{
// the input must be odd and fairly large here... so the case of even
// numbers is not important, as is the status of the number 1.
    for (int f=3; f*f<=n; f+=2)
    {   if (n%f == 0) return false;
    }
    return true;
}

static void reHashOblist()
{
System.out.println("ReHashing");
    int n = ((3*oblistSize)/2) | 1;
    while (!isPrime(n)) n += 2;
    Symbol [] v = new Symbol[n];
    for (int i=0; i<n; i++) v[i] = null;
    for (int i=0; i<oblistSize; i++)
    {   Symbol s = oblist[i];
        if (s == null) continue;
        int inc = s.pname.hashCode();
        int hash = ((169*inc) & 0x7fffffff) % n;
        inc = 1 + ((inc & 0x7fffffff) % (n-1)); // never zero
        while (v[hash] != null)
        {   if (v[hash].pname.equals(s.pname))
                System.out.println("Two symbols called <" + s.pname + "> " +
                    Integer.toHexString((int)s.pname.charAt(0)));
            hash += inc;
            if (hash >= n) hash -= n;
        }
//System.out.println("Relocate <" + s.pname + "> at " + hash + " " + inc);
        v[hash] = s;
    }
    oblist = v;
    oblistSize = n;
    obvector.vec = v;
}

static LispObject readObject() throws IOException
{
// Reloading an image uses an explicit stack to manage the recusion that
// it needs. It controls this stack using a finite-state control. The states
// are identified here as constants S_xxx.

    int state = S_START;
    int sp = 0;

    LispObject w = null;
    boolean setLabel = false;
    int i;

    for (;;)
    {   if (sp >= istacklimit-2)  // grow integer stack if needbe.
        {   int [] newistack = new int[2*istacklimit];
            for (i=0; i<istacklimit; i++) newistack[i] = istack[i];
            istack = newistack;
            istacklimit = 2*istacklimit;
        }
// At the start of the loop here I will read another object. I "continue"
// if the object can not be completed all at once, having adjusted my
// state and the stack suitably.
        int opcode = idump.read();
        if (opcode == -1) throw new IOException("End of file");
        int operand = 0;
        if (opcode < LispObject.X_BREAK1)
        {   operand = opcode & 0x3f;
            opcode &= ~0x3f;
        }
        else if (opcode < LispObject.X_BREAK2)
        {   operand = opcode & 0x0f;
            opcode &= ~0x0f;
        }
        else if (opcode < LispObject.X_BREAK3)
        {
// The first class of opcodes have a selector in their bottom two bits,
// and that indicates whether they are followed by 1, 2, 3 or 4 bytes
// of operand.
            switch (opcode & 3)
            {
        case 0: operand = idump.read();
                break;
        case 1: operand = idump.read();
                operand = (operand << 8) | idump.read();
                break;
        case 2: operand = idump.read();
                operand = (operand << 8) | idump.read();
                operand = (operand << 8) | idump.read();
                break;
        case 3: operand = idump.read();
                operand = (operand << 8) | idump.read();
                operand = (operand << 8) | idump.read();
                operand = (operand << 8) | idump.read();
                break;
            }
            opcode &= ~3;
        }
// Other cases do not have an (explicit) operand.
        switch (opcode)
        {
    case LispObject.X_REFn:
            if (operand >= 48) operand = sharedIndex - (operand + 1 - 48);
    case LispObject.X_REF:       // refer to an item that has already been read
            w = shared[operand];
            break;
    case LispObject.X_REFBACK:
            w = shared[sharedIndex - operand];
            break;
    case LispObject.X_RECENT:
            Fasl.recentn++;
            w = Fasl.recent[idump.read()];
	    if (setLabel)
	    {   shared[sharedIndex++] = w;
	        setLabel = false;
	    }
	    break;
    case LispObject.X_RECENT1:
            Fasl.recentn++;
            w = Fasl.recent[idump.read()+256];
	    if (setLabel)
	    {   shared[sharedIndex++] = w;
	        setLabel = false;
	    }
	    break;
    case LispObject.X_OBLIST:
            w = obvector;
            break;
    case LispObject.X_INT:       // a LispInteger
    case LispObject.X_INTn:
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                w = LispInteger.valueOf(new BigInteger(data));
            }
            break;
    case LispObject.X_FIXNUM:
// Slighly curious encoding of signed numbers so that the variable-length
// packing in the image file works well.
            if ((operand & 1) == 0) operand = (operand >>> 1);
            else if (operand == 1) operand = 0x80000000;
            else operand = -(operand >>> 1);
            w = LispInteger.valueOf(operand);
            break;
    case LispObject.X_STR:
    case LispObject.X_STRn:
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                w = new LispString(new String(data, "UTF8"));
                LispString.stringCount++;
            }
            break;
    case LispObject.X_GENSYM:
    case LispObject.X_GENSYMn:
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                Symbol ws = new Gensym(new String(data, "UTF8"));
                Symbol.symbolCount++;
                if (setLabel)
                {   shared[sharedIndex++] = ws;
                    setLabel = false;
                }
                if (!descendSymbols)
                {   ws.car/*value*/ = lit[Lit.undefined];
                    ws.cdr/*plist*/ = nil;
                    ws.fn = new Undefined(ws.pname);
                    ws.special = null;
                    w = ws;
                    break;
                }
                stack.push(ws);
                istack[sp++] = state;
                state = S_SYMFN;
                continue;
            }
    case LispObject.X_SYM:
            opcode = LispObject.X_SYMn; // drop through
    case LispObject.X_SYMn:
    case LispObject.X_UNDEF:
    case LispObject.X_UNDEFn:
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                if (descendSymbols)
                {   Symbol ws = new Symbol();
                    Symbol.symbolCount++;
                    ws.pname = new String(data, "UTF8");
                    stack.push(ws);
                    istack[sp++] = state;
                    if (opcode == LispObject.X_SYMn) state = S_SYMFN;
                    else
                    {   ws.fn = new Undefined(ws.pname);
                        state = S_SYMSPECIAL;
                    }
                    if (setLabel)
                    {   shared[sharedIndex++] = ws;
                        setLabel = false;
                    }
                    continue;
                }
                else
                {   w = Symbol.intern(new String(data, "UTF8"));
		    Fasl.recent[Fasl.recentp++ & 0x1ff] = w;
                    break;
                }
            }
    case LispObject.X_VEC:
            w = new LispVector(operand);
            if (setLabel)
            {   shared[sharedIndex++] = w;
                setLabel = false;
            }
            if (operand == 0) break;  // vector with 0 elements
            stack.push(w);
            istack[sp++] = state;
            state = S_VECTOR + operand;
            continue;
    case LispObject.X_HASH:
            w = new LispHash(new HashMap(), 0);
            stack.push(w);
            istack[sp++] = state;
            state = S_HASHKEY;
            if (setLabel)
            {   shared[sharedIndex++] = w;
                setLabel = false;
            }
            continue;
    case LispObject.X_HASH2:
            w = new LispHash(new LispEqualHash(), 2);
            stack.push(w);
            istack[sp++] = state;
            state = S_HASHKEY;
            if (setLabel)
            {   shared[sharedIndex++] = w;
                setLabel = false;
            }
            continue;
    case LispObject.X_ENDHASH:
            w = null;          // marker for end of hash table entries
            break;
    case LispObject.X_UNDEF1:
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                w = new Undefined(new String(data, "UTF8"));
            }
            break;
    case LispObject.X_MACRO:
            {   Macro wm = new Macro();
                if (setLabel)
                {   shared[sharedIndex++] = wm;
                    setLabel = false;
                }
                stack.push(wm);
                istack[sp++] = state;
                state = S_MACRO_BODY;
            }
            continue;
    case LispObject.X_AUTOLOAD:
            {   AutoLoad wa = new AutoLoad(null, null);
                if (setLabel)
                {   shared[sharedIndex++] = wa;
                    setLabel = false;
                }
                stack.push(wa);
                istack[sp++] = state;
                state = S_AUTONAME;
                continue;
            }
    case LispObject.X_INTERP:
            {   Interpreted wi = new Interpreted();
                if (setLabel)
                {   shared[sharedIndex++] = wi;
                    setLabel = false;
                }
                stack.push(wi);
                istack[sp++] = state;
                state = S_INTERP_BODY;
                continue;
            }
    case LispObject.X_CALLAS:
            {   CallAs wi = new CallAs(idump.read());
                if (setLabel)
                {   shared[sharedIndex++] = wi;
                    setLabel = false;
                }
                stack.push(wi);
                istack[sp++] = state;
                state = S_CALLAS_BODY;
                continue;
            }
    case LispObject.X_BPS:
            {   byte [] data;
                int nargs = 0;
                int n1 = idump.read(), n2=0, n3=0;
                if ((n1 & 0x80) != 0)
                {   n1 &= 0x7f;
                    n2 = idump.read();
                    if ((n2 & 0x80) != 0)
                    {   n2 &= 0x7f;
                        n3 = idump.read();
                    }
                }
                nargs = n1 + (n2<<7) + (n3<<14);
                if (operand == 0) data = null;
                else
                {   data = new byte[operand];
                    for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                }
                FnWithEnv ws;
                if (nargs > 0xff) ws = new ByteOpt(nargs);
                else 
                {   ws = new Bytecode();
                    ws.nargs = nargs;
                }
                ws.bytecodes = data;
// the X_BPS format is curious in that it should ALWAYS be followed
// by an X_VEC. So I look for that here. I think I should also note that
// I have a fragment of design here that is not fully worked through.
// My Bytecoded is a sub-class of FnWithEnv - a general class for functions
// that want a vector of LispObjects kept with them. But at present
// Bytecode is the only sub-class that exists and the only one that this
// rea-loading code can ever re-create.  So I expect to have to do more
// work when or if I add more, for instance for code that has been reduced
// to real Jaba bytecodes rather than my Jlisp-specific ones.
                opcode = idump.read();
                if (opcode < LispObject.X_VEC || opcode > LispObject.X_VEC+3)
                    throw new IOException("Corrupted image file");
                switch (opcode & 3)
                {
            case 0: operand = idump.read();
                    break;
            case 1: operand = idump.read();
                    operand = (operand << 8) | idump.read();
                    break;
            case 2: operand = idump.read();
                    operand = (operand << 8) | idump.read();
                    operand = (operand << 8) | idump.read();
                    break;
            case 3: operand = idump.read();
                    operand = (operand << 8) | idump.read();
                    operand = (operand << 8) | idump.read();
                    operand = (operand << 8) | idump.read();
                    break;
                }
		ws.env = new LispObject [operand];
                if (operand == 0)
                {   w = ws;
                    break;
                }
                stack.push(ws);
                istack[sp++] = state;
                state = S_VECTOR + operand;
                continue;
            }
    case LispObject.X_LIST:
            w = nil;
            if (operand == 0) break;
            for (i=0; i<operand; i++)
                w = new Cons(nil, w);
            Cons.consCount += operand;
            if (setLabel)
            {   shared[sharedIndex++] = w;
                setLabel = false;
            }
            stack.push(w);
            istack[sp++] = state;
            state = S_CADR+operand;
            continue;
    case LispObject.X_LISTX:
            w = new Cons(nil, nil);
            {   LispObject w1 = w;
                for (i=0; i<operand; i++)
                    w = new Cons(nil, w);
                Cons.consCount += operand+1;
                if (setLabel)
                {   shared[sharedIndex++] = w;
                    setLabel = false;
                }
                stack.push(w);
                istack[sp++] = state;
                state = S_CADR+operand+1;
                stack.push(w1);
// I will fill in the very tail and then drop back to
// the case used with X_LIST
                istack[sp++] = state;
                state = S_CDR;
                continue;
            }
    case LispObject.X_NULL:
            w = null;
            break;
    case LispObject.X_DOUBLE:
            {   long v = idump.read();
                for (i=0; i<7; i++)
                    v = (v << 8) | idump.read();
                w = new LispFloat(Double.longBitsToDouble(v));
            }
            break;
    case LispObject.X_SPID:
            w = new Spid(idump.read());
            break;
    case LispObject.X_DEFINMOD:
// This case is ONLY expected to be present in FASL modules, and it is a
// prefix indicating what to do with some subsequent stuff.
            {   int n0=idump.read(), n1=0, n2=0;
                if ((n0 & 0x80) != 0)
                {   n0 &= 0x7f;
                    n1 = idump.read();
                    if ((n1 & 0x80) != 0)
                    {   n1 &= 0x7f;
                        n2 = idump.read();
                    }
                }
                n0 = n0 + (n1 << 7) + (n2 << 14);
// That has read in a 22-bit number. Actually only 18 bits are really needed
// in the CSL byte-compiler model so I have some spare capacity. I offset
// values by 1 so I can represent "-1" too.
                w = new Spid(Spid.DEFINMOD, n0-1);
            }
            break;
    case LispObject.X_STREAM:
            w = Jlisp.nil;       // new LispStream();
            break;
    case LispObject.X_FNAME:
            operand = idump.read();
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                String s = new String(data, "UTF8");
                w = (LispObject)builtinFunctions.get(s);
                if (w == null)
                    Jlisp.lispErr.println(s + " not found");
            }
            break;
    case LispObject.X_SPECFN:
            operand = idump.read();
            {   byte [] data = new byte[operand];
                for (i=0; i<operand; i++) data[i] = (byte)idump.read();
                String s = new String(data, "UTF8");
                w = (LispObject)builtinSpecials.get(s);
                if (w == null)
                    Jlisp.lispErr.println(s + " not found");
            }
            break;
    case LispObject.X_STORE:
            setLabel = true;
            continue;
    default:
            throw new IOException("Bad byte in image file");
        }
// For objects that were read all in one gulp I arrive here and must
// impose sharing.
        if (setLabel)
        {   shared[sharedIndex++] = w;
            setLabel = false;
        }
// Now I have read in an object (it is in w) so I need to consider what to
// do with it! It may be that processing this object will complete another
// whose actions had been stacked, so I have a loop here which unwinds
// the stack. If I "break" that will take me back to where the next item
// gets read.
        for (;;)
        {   LispObject y = (LispObject)stack.peek();
            if (state > S_VECTOR)
            {   if (y instanceof LispVector)
                    ((LispVector)y).vec[--state - S_VECTOR] = w;
                else if (y instanceof FnWithEnv)
                    ((FnWithEnv)y).env[--state - S_VECTOR] = w;
                else throw new IOException("Corrupt image file");
                if (state == S_VECTOR) // now completed?
                {   if (y instanceof LispVector)
                    {   stack.pop();
                        w = y;
                        state = istack[--sp];
                        continue;
                    }
                    else if (y instanceof FnWithEnv)
                    {   stack.pop();
                        w = y;
                        state = istack[--sp];
                        continue;
                    }
                }
                else break;
            }
            else switch (state)
            {
        case S_START:
                return w;
        case S_CADR+16:
                y = y.cdr;
        case S_CADR+15:
                y = y.cdr;
        case S_CADR+14:
                y = y.cdr;
        case S_CADR+13:
                y = y.cdr;
        case S_CADR+12:
                y = y.cdr;
        case S_CADR+11:
                y = y.cdr;
        case S_CADR+10:
                y = y.cdr;
        case S_CADR+9:
                y = y.cdr;
        case S_CADR+8:
                y = y.cdr;
        case S_CADR+7:
                y = y.cdr;
        case S_CADR+6:
                y = y.cdr;
        case S_CADR+5:
                y = y.cdr;
        case S_CADR+4:
                y = y.cdr;
        case S_CADR+3:
                y = y.cdr;
        case S_CADR+2:
                y = y.cdr;
                y.car = w;
                state--;
                break;
        case S_CADR+1:
                y.car = w;
                w = (LispObject)stack.pop();
                state = istack[--sp];
                continue;
        case S_CDR:
                {   Cons wc = (Cons)stack.pop();
                    wc.cdr = w;
                    state = istack[--sp];  // will be S_CADR+nn
                }
                break;
        case S_HASHKEY:
                if (w == null)  // hash table now complete
                {   w = (LispObject)stack.pop();
                    state = istack[--sp];
                    continue;
                }
                stack.push(w);
                state = S_HASHVAL;
                break;
        case S_HASHVAL:
                {   LispObject k = (LispObject)stack.pop();
                    LispHash h = (LispHash)stack.peek();
                    h.hash.put(k, w);
                }
                state = S_HASHKEY;
                break;
        case S_SYMFN:
                {   Symbol ws = (Symbol)stack.peek();
                    ws.fn = (LispFunction)w;
                    state = S_SYMSPECIAL;
                    break;
                }
        case S_SYMSPECIAL:
                {   Symbol ws = (Symbol)stack.peek();
                    ws.special = (SpecialFunction)w;
                    state = S_SYMPLIST;
                    break;
                }
        case S_SYMPLIST:
                {   Symbol ws = (Symbol)stack.peek();
                    ws.cdr/*plist*/ = (LispObject)w;
                    state = S_SYMVAL;
                    break;
                }
        case S_SYMVAL:
                {   Symbol ws = (Symbol)stack.pop();
                    ws.car/*value*/ = (LispObject)w;
                    w = ws;
                    state = istack[--sp];
                    continue;
                }
        case S_AUTONAME:
                {   AutoLoad wa = (AutoLoad)stack.peek();
                    wa.name = (Symbol)w;
                    state = S_AUTODATA;
                    break;
                }
        case S_AUTODATA:
                {   AutoLoad wa = (AutoLoad)stack.pop();
                    wa.data = w;
                    w = wa;
                    state = istack[--sp];
                    continue;
                }
        case S_INTERP_BODY:
                {   Interpreted wa = (Interpreted)stack.pop();
                    wa.body = w;
                    w = wa;
                    state = istack[--sp];
                    continue;
                }
        case S_MACRO_BODY:
                {   Macro wa = (Macro)stack.pop();
                    wa.body = w;
                    w = wa;
                    state = istack[--sp];
                    continue;
                }
        case S_CALLAS_BODY:
                {   CallAs wa = (CallAs)stack.pop();
                    wa.body = w;
                    w = wa;
                    state = istack[--sp];
                    continue;
                }
        default:
                lispIO.println("Unknown state");
                throw new IOException("Malformed image file (bad state)");
            }
            break;    // so "break" in the switch corresponds to
                      // requesting a SHIFT, while "continue" is a REDUCE.
        }
    }
}


// read a single parenthesised expression.
// Supports  'xx as a short-hand for (quote xx)
// which is what most Lisps do.

// Formal syntax:
//    read => SYMBOL | NUMBER | STRING
//         => ' read
//         => ` read
//         => , read
//         => ,@ read
//         => ( tail
//    tail => )
//         => . read )
//         => read readtail

static LispStream readIn;

static LispObject read() throws Exception
{
    LispObject r;
    r = lit[Lit.std_input].car/*value*/;
    if (r instanceof LispStream) readIn = (LispStream)r;
    else throw new EOFException();
    if (!readIn.inputValid)
    {   inputType = readIn.nextToken();
        readIn.inputValid = true;
    }
    switch (inputType)
    {
case LispStream.TT_EOF:
        throw new EOFException();
case LispStream.TT_WORD:
        readIn.inputValid = false;
        return readIn.value;
        //case LispStream.TT_NUMBER:
        //readIn.inputValid = false;
        //return readIn.value;
        //case '\"':  // String
        //r = new LispString(readIn.sval);
        //readIn.inputValid = false;
        //return r;
case '\'':
        readIn.inputValid = false;
        r = read();
        return new Cons(lit[Lit.quote], new Cons(r, nil));
case '`':
        readIn.inputValid = false;
        r = read();
        return expandBackquote(r);
case ',':
        readIn.inputValid = false;
        r = read();
        return new Cons(lit[Lit.comma], new Cons(r, nil));
case 0x10000:  // ",@"
        readIn.inputValid = false;
        r = read();
        return new Cons(lit[Lit.commaAt], new Cons(r, nil));
case '(':
        readIn.inputValid = false;
        return readTail();
case ')':
case '.':
        readIn.inputValid = false;
        return nil;
default:
        if (inputType < 128) r = chars[inputType];
        else r = Symbol.intern(String.valueOf((char)inputType));
        readIn.inputValid = false;
        return r;
    }
}

static LispObject readTail() throws Exception
{
    LispObject r;
    if (!readIn.inputValid)
    {   inputType = readIn.nextToken();
        readIn.inputValid = true;
    }
    switch (inputType)
    {
case '.':
        readIn.inputValid = false;
        r = read();
        if (!readIn.inputValid)
        {   inputType = readIn.nextToken();
            readIn.inputValid = true;
        }
        if (inputType == ')') readIn.inputValid = false;
        return r;
case LispStream.TT_EOF:
        throw new EOFException();
case ')':
        readIn.inputValid = false;
        return nil;
default:r = read();
        return new Cons(r, readTail());
    }
}

static LispObject expandBackquote(LispObject a)
{
    if (a == nil) return a;
    else if (a.atom)
        return new Cons(lit[Lit.quote], new Cons(a, nil));
    LispObject aa = a;
    if (aa.car == lit[Lit.comma]) return aa.cdr.car;
    if (!aa.car.atom)
    {   LispObject aaa = aa.car;
        if (aaa.car == lit[Lit.commaAt])
        {   LispObject v = aaa.cdr.car;
            LispObject t = expandBackquote(aa.cdr);
            return new Cons(lit[Lit.append],
                new Cons(v, new Cons(t, nil)));
        }
    }
    return new Cons(lit[Lit.cons],
        new Cons(expandBackquote(aa.car),
            new Cons(expandBackquote(aa.cdr), nil)));
}

// set up fixed definitions

static void initfns(Object [][] builtins)
{
    for (int i=0; i<builtins.length; i++)
    {   Object [] s = builtins[i];
        String name = (String)s[0];
        LispFunction fn = (LispFunction)s[1];
        fn.name = name;
        Symbol.intern(name, fn, null);
    }

}

static void initSymbols()
{
//System.out.println("Beginning cold start: " + oblistCount);
    Fns.prompt = null;
    Fns.gensymCounter = 1;

// set up nil first since it is needed by Symbol.intern
    nil = Symbol.intern("nil");
    nil.cdr/*plist*/ = nil;
    nil.car/*value*/ = nil;
    nil.car = nil.cdr = nil;

// next set up "undefined" and "t" which both have themselves as value
    lit[Lit.undefined]       = Symbol.intern("*undefined-value*");
    ((Symbol)lit[Lit.undefined]).car/*value*/ = lit[Lit.undefined];
    lispTrue                 = Symbol.intern("t");
    lispTrue.car/*value*/           = lispTrue;

// Now the remaining literals. It does not matter that undefined gets
// looked up again here, since the version already created will be found.
    for (int i=0; i<Lit.names.length; i++)
    {   lit[i] = Symbol.intern(Lit.names[i]);
    }

// The object list has a funny treatment to make it agree with CSL
    lit[Lit.starpackage].car/*value*/ =
        new LispVector(new LispObject [] {nil, obvector});

    ((Symbol)lit[Lit.raise]).car/*value*/ = nil;
    ((Symbol)lit[Lit.lower]).car/*value*/ = lispTrue;
    ((Symbol)lit[Lit.redefmsg]).car/*value*/ = lispTrue;

// The things put in lispsystem* must include various ones relied upon
// by the REDUCE (3.7) build scripts!
    ((Symbol)lit[Lit.lispsystem]).car/*value*/ =
        new Cons(new Cons(Symbol.intern("c-code"), LispInteger.valueOf(0)),
        new Cons(new Cons(Symbol.intern("name"),   new LispString("java")),
        new Cons(Symbol.intern("csl"),  // a lie, in some sense!
        new Cons(Symbol.intern("jlisp"),
        nil))));

    Fns.fluid(nil);
    Fns.fluid(lispTrue);
    Fns.fluid(lit[Lit.lispsystem]);
    Fns.fluid(lit[Lit.raise]);
    Fns.fluid(lit[Lit.lower]);
    Fns.fluid(lit[Lit.starcomp]);
    Fns.fluid(lit[Lit.commonLisp]);
    Fns.fluid(lit[Lit.redefmsg]);

    initfns(fns1.builtins);
    initfns(fns2.builtins);
    initfns(fns3.builtins);
    initfns(fns4.builtins);
    // initfns(fns5.builtins);
    // initfns(fns6.builtins);

    {   Object [][] specials = specfn.specials;
        for (int i=0; i<specials.length; i++)
        {   Object [] s = specials[i];
            String name = (String)s[0];
            SpecialFunction fn = (SpecialFunction)s[1];
            fn.name = name;
            Symbol.intern(name, null, fn);
        }
    }

    lit[Lit.restart] = nil;
    lit[Lit.hashtab] = new LispHash(new LispEqualHash(), 2);
    lit[Lit.banner]  = new LispString("Jlisp");

    modulus = 1;
    bigModulus = BigInteger.valueOf(modulus);
//System.out.println("After cold start: " + oblistCount);
}

static void readEvalPrintLoop(boolean noRestart) throws ProgEvent
{
// If the user had set a restart-function when an image was preserved
// then I will run that now unless the command-line had gone "-n" (for
// "ignore restart function". That option is only intended for allowing
// experts to recover when an image is a bit mangled!
    LispObject r = lit[Lit.restart];
    LispObject a = null;
//@
println("restart mode in read eval print loop " + restartFn + " " +
        restartModule + " " + restartArg);
    if (restarting && restartFn != null)
    {   r = Symbol.intern(restartFn);
        if (restartArg != null)
        {   LispObject save = lit[Lit.std_input].car/*value*/;
            try
            {   lit[Lit.std_input].car/*value*/ =
                    new LispStringReader(restartArg);
                a = read();
                ((LispStream)lit[Lit.std_input].car/*value*/).close();
            }
            catch (Exception e)
            {   a = null;
                System.out.println("Unexpected exception " + e);
            }
            finally
            {   lit[Lit.std_input].car/*value*/ = save;
            }
        }
        if (restartModule != null)
        {   try
            {   Fasl.loadModule(new LispString(restartModule));
            }
            catch (Exception ex)
            {   System.out.println("Unexpected exception " + ex);
            }
        }
        restartFn = null;
        restartArg = null;
        restartModule = null;
    }
    if (noRestart ||
        (r instanceof Symbol &&
         ((Symbol)r).fn instanceof Undefined) ||
        (r instanceof Undefined) ||
        (!r.atom && r.car != lit[Lit.lambda]) ||
        !(r instanceof Symbol || r instanceof Cons ||
          r instanceof LispFunction))
    {}    // cases when the restart object looks wrong
    else
    {   try
        {   if (a == null)
            {   if (r instanceof Symbol)
                    ((Symbol)r).fn.op0();
                else if (r instanceof LispFunction)
                    ((LispFunction)r).op0();
                else Fns.apply0(r);
            }
            else
            {   if (r instanceof Symbol)
                    ((Symbol)r).fn.op1(a);
                else if (r instanceof LispFunction)
                    ((LispFunction)r).op1(a);
                else Fns.apply1(r, a);
            }
        }
        catch (ProgEvent e)
        {   throw e;
        }
        catch (Exception e)
        {   // ignore all other exceptions
            System.err.println("Stopping because of error: " +
                               e.getMessage());
        }
        return;
    }
// Otherwise I will run a simple READ-EVAL-PRINT loop
    for (;;)
    {   try
        {   r = read();
        }
        catch (EOFException e)
        {
            break;
        }
        catch (Exception e)
        {   errprintln(
                "Error while reading: " + e.getMessage());
            e.printStackTrace(new PrintWriter(new WriterToLisp(
                ((LispStream)Jlisp.lit[Lit.err_output].car/*value*/))));
            break;
        }
        try
        {   LispObject v = r.eval();
            if (Specfn.progEvent != Specfn.NONE)
            {   Specfn.progEvent = Specfn.NONE;
                error("GO or RETURN out of context");
            }
            println();
            print("Value: ");
            v.print(LispObject.printEscape);
            println();
        }
        catch (Exception e)
        {   if (e instanceof LispException)
            {
                if (e instanceof ProgEvent)
                {   ProgEvent ep = (ProgEvent)e;
                    switch (ep.type)
                    {
                case ProgEvent.STOP:
                case ProgEvent.PRESERVE:
                case ProgEvent.RESTART:
                        throw ep;
                default:
                        break;
                    }
                }
                LispException e1 = (LispException)e;
                errprintln();
                errprint("+++++ Error: " + e1.message);
                if (e1.details != null)
                {   errprint(": ");
                    e1.details.errPrint();
                }
                errprintln();
            }
            else
            {   errprintln();
                errprintln("+++++ Error: " +
                                             e.getMessage());
            }
            e.printStackTrace(new PrintWriter(new WriterToLisp(
                ((LispStream)Jlisp.lit[Lit.err_output].car/*value*/))));
        }
    }
    return;
}


}

class FlushOutputThread extends Thread
{
    public void run()
    {
        for (;;)
        {   try
            {   sleep(2500);
            }
            catch (InterruptedException e)
            {}
            if (Jlisp.finishingUp) return;
// The only stream that I flush regularly is the main output one, since
// others should be directed to files (not the screen).
            if (Jlisp.lispIO != null) Jlisp.lispIO.flush();
// Well maybe I will flush the one that is currently selected if that
// is different...
            LispObject a = Jlisp.lit[Lit.std_output];
            if (a != null &&
                a instanceof Symbol) a = a.car/*value*/;
            if (a != null &&
                a != Jlisp.lispIO &&
                a instanceof LispStream)
            {   ((LispStream)a).flush();
            }
        }
    }
}

// End of Jlisp.java

