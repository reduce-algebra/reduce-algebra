package uk.ac.cam.aa582.reduce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.PipedReader;
import java.io.PipedWriter;
import java.io.PrintWriter;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.Font;
import uk.ac.cam.aa582.structures.boxes.MultilineBox;
import uk.ac.cam.aa582.structures.boxes.MultilineBox.Alignment;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox.Space;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;
import uk.ac.cam.aa582.structures.reducible.Reducible;
import uk.ac.cam.aa582.structures.tex.TexParser;
import uk.co.codemist.jlisp.Jlisp;
import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;

/**
 * Serves as access layer to JLisp, which in turn is running REDUCE.<br/>
 * Every interaction with REDUCE takes place through the methods inside this class.
 * 
 * @author Ahmad Akra
 *
 */
public class Reduce {
	
	/**
	 * This context is only used to reach JLisp
	 * in the assets directory
	 */
	Context context;

	/**
	 * Keeps track of how many inputs were sent to
	 * REDUCE so far.
	 */
	private static int inputCount = 0;
	
	/**
	 * Constructor
	 * @param ctx
	 */
	public Reduce(Context ctx) {
		context = ctx;
	}
	
	/**
	 * Undo the effects of the last input,
	 * This is necessary because REDUCE remembers some
	 * state, for example the number of inputs and the
	 * previous answer.
	 */
	public void undo() {
		if(inputCount > 1)
			inputCount--;
	}
	
	public static int getInputCount() {
		return inputCount;
	}

	// ---------------- public methods -------------------
	
	/**
	 * This method performs all the magic, an input
	 * structure is flattened to a string in the REDUCE
	 * language, fed into REDUCE, the TEX output is then
	 * parsed and returned in the form of a drawable 
	 * structure (Boxes)
	 * 
	 * @param reducible The input
	 * @return the REDUCE Output in the form of a drawable structure
	 */
	public Box reduce(Reducible reducible){
		
		String reduce_input = flattenToReduceLanguage(reducible);
		String[] reduce_output = reduce(reduce_input);
		
		//String[] reduce_output = new String[] { "\\frac{\\log\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(\\tan\\left(x\\right)^2\\right)^2\\right)^2\\right)^2\\right)^2\\right)^2\\right)^2\\right)^2\\right)^2+1\\right)}2$" };

		Box drawable = parseTex3(reduce_output);
		return drawable;
	}
	
	private Box parseTex3(String[] reduce_output) {
		LinkedList<Box> lines = new LinkedList<Box>();
		
		for(String line : reduce_output) {
			if(line.trim().startsWith("latex:\\black")) {
				
				line = line.replaceAll(".*(\\$.*\\$).*", "$1"); // leaves only pure TeX
				line = line.replaceAll("\\$\\\\displaystyle\\s*", "\\$"); // remove the erroneous \displaystyle
				line = line.replaceAll("\\$", ""); // removes the dollar signs				
				
				Box b = tryParseTex3(line);
				lines.add(b);
				
				continue;
			}
			LinkedList<Box> l = new LinkedList<Box>();
			for(int i=0; i < line.length(); i++) {
				if(line.charAt(i) == ' ') {
					l.add(new SpaceBox());
				} else {
					l.add(new SymbolBox(line.charAt(i)+"",Font.regular));
				}
			}
			lines.add(new SequenceBox(l.toArray(new Box[0])));
		}
		if(lines.size() == 1) return lines.getFirst();
		else return new MultilineBox(-1,-1,-1, Alignment.left, lines.toArray(new Box[0]));
	}
	
	private Box tryParseTex3(String latex) {
		
		TexParser p = new TexParser(latex);
		Box result;
		
		try {
			result = p.parse();
			
		} catch (Exception ex) {
			
			result = new SymbolBox("$" + latex + "$", Font.regular);
		}
		
		return result;
	}

	@SuppressWarnings("unused")
	private Box parseTex2(String[] reduce_output) {
		
		if(reduce_output.length == 1) {
			String line = reduce_output[0];

			line = line.replaceAll(".*(\\$.*\\$).*", "$1"); // leaves only pure TeX
			line = line.replaceAll("\\$\\\\displaystyle\\s*", "\\$"); // remove the erroneous \displaystyle
			line = line.replaceAll("\\$", ""); // removes the dollar signs
			
			
			
			return tryParseTex(line);

		}
		Box[] boxes = new Box[reduce_output.length];
		for(int i=0; i<reduce_output.length; i++) {
			boxes[i] = tryParseTex(reduce_output[i]);
		}
		return new MultilineBox(-1,-1,-1, Alignment.left, boxes); // TODO finish
	}

	protected Box tryParseTex(String line) {
		TexParser p = new TexParser(line);
		Box result;
		
		try {
			if(line.startsWith("***")) throw new Exception();
			result = p.parse();
			
		} catch (Exception ex) {
			LinkedList<Box> boxes = new LinkedList<Box>();
			
			for(char c : line.toCharArray()) {
				if(c == ' ')
					boxes.add(new SpaceBox(Space.space));
				else boxes.add(new SymbolBox(c+"", Font.regular));
			}
			
			result = new SequenceBox(boxes.toArray(new Box[0]));
		}
			
		
		return result;
	}

	/**
	 * Set the precision of REDUCE to the given value,
	 * by calling "precision(p);"
	 * 
	 * @param p The new precision value for REDUCE
	 */
	public void precision(int p) {
		try {
			// set the REDUCE precision value
			reducePrintln("precision(" + p + ");");
			waitForPrompt(); 
		} catch(Exception e) {
			Log.d("Precision", e.getMessage());
		}
	}

	
	/**
	 * Turn on or off the "rounded" flag of REDUCE, when the flag
	 * "rounded" is on, REDUCE works on numeric approximations,
	 * but when "rounded" is off, REDUCE works on exact algebraic
	 * expressions.
	 * 
	 * @param on True to call "on rounded" and false to call "off rounded"
	 */
	public void rounded(boolean on) {
		try {
			// turn rounded on or off
			reducePrintln((on?"on":"off") + " rounded;");
			waitForPrompt(); 
		} catch(Exception e) {
			Log.d("Precision", e.getMessage());
		}
	}
	
//	public Box reduce(String reduceInput) {
//		String reduce_output = reduce2(reduceInput);
//		Box drawable = parseTex(reduce_output);
//		return drawable;
//	}

	// ---------------- helper methods -------------------

	// translation to reduce
	private String flattenToReduceLanguage(Reducible reducible) {
		/*
		 *  it is much easier to have every sub-class of Reducible
		 *  override its toString(), this way translating
		 *  every Reducible object is specified in that class's file
		 *  rather then have all the specifications in one place.
		 */
		
		return reducible.toString();
	}
	
	
	
	///////////// input and output from REDUCE /////////////////
	
	

	/**
	 * Send input to JLisp through this
	 * writer
	 */
	private static PrintWriter inReduce;

	/**
	 * Read the output from JLisp from 
	 * this reader
	 */
	private static BufferedReader outReduce;
	
	/**
	 * The thread that is running reduce
	 */
	private static Thread jlispThread;
	
	
	public String[] reduce(String reduce_input) {
		try {
			if(notStarted()){
				start(); // Start the thread that runs JLisp
			}
			
			// add ";" to the input if there isn't one
			if(!reduce_input.endsWith(";")) 
				reduce_input += ";";
			
			// pass in the input
			reducePrintln(reduce_input);
			
			// I have no idea why this was necessary
			waitForPrompt();
			printLine();
			
			// read the output
			LinkedList<String> lines = new LinkedList<String>();
			String line = reduceReadLine();
			while(!line.equals(Jlisp.promptSignal)) {
				if(!line.trim().equals("")) {
					lines.add(line);
				}
				line = reduceReadLine();
			}
		
			// return the result
			return lines.toArray(new String[0]);

		} catch(Exception e) { 
			
			return new String[] { 
					"Faulty Input:" + reduce_input, 
					e.getClass().getSimpleName(), 
					"Message:" + e.getMessage() }; 
		}
	}

	/**
	 * Keeps reading lines until REDUCE prompts for input
	 * 
	 * @throws IOException
	 */
	private void waitForPrompt() throws IOException {
		while(!reduceReadLine().equals(Jlisp.promptSignal)) { }
	}

	/**
	 * @return True if the thread running JLisp has
	 * not been initialized yet
	 */
	private boolean notStarted() {
		return jlispThread == null;
	}

	/**
	 * Prints a dummy input to REDUCE
	 */
	private void printLine() {
		reducePrintln(";");
	}
	
	/**
	 * Prints an input line to REDUCE
	 * @param line The string to input to REDUCE
	 */
	private void reducePrintln(String line) {
		inputCount++;
		Log.i("Reduce", line);
		inReduce.println(line);
	}

	/**
	 * Reads a single line from REDUCE
	 * @return a single line from REDUCE
	 * @throws IOException
	 */
	private String reduceReadLine() throws IOException {
		String line = outReduce.readLine();
		Log.d("Reduce", line);
		return line;
	}
	
//	private Box parseTex(String[] reduce_output) {
//		
//		if(reduce_output.length == 1) {
//			String line = reduce_output[0];
//
//			line = line.replaceAll(".*(\\$.*\\$).*", "$1"); // leaves only pure TeX
//			line = line.replaceAll("\\$\\\\displaystyle\\s*", "\\$"); // remove the erroneous \displaystyle
//			
//			LinkedList<Box> boxes = new LinkedList<Box>();
//			
//			for(char c : line.toCharArray()) {
//				if(c == ' ')
//					boxes.add(new SpaceBox(Space.space));
//				else boxes.add(new SymbolBox(c+"", Font.regular));
//			}
//			
//			return new SequenceBox(boxes.toArray(new Box[0]));
//
//		}
//		Box[] boxes = new Box[reduce_output.length];
//		for(int i=0; i<reduce_output.length; i++) {
//			boxes[i] = new SymbolBox(reduce_output[i],Font.regular);
//		}
//		return new MultilineBox(-1,-1,-1, Alignment.left, boxes); // TODO finish
//	}

	public void start() {
		try {
			Log.d("Reduce", "*****************************************");
			
			// the input to REDUCE
			final PipedReader inReader = new PipedReader(); // this the input to JLisp
			PipedWriter inWriter = new PipedWriter(inReader); 
			inReduce = new PrintWriter(inWriter); // I use this to write into the input
		
			// the output from REDUCE
			PipedWriter outWriter = new PipedWriter(); 
			final PrintWriter outPrintWriter = new PrintWriter(outWriter); // output from JLisp
			PipedReader outReader = new PipedReader(outWriter);
			outReduce = new BufferedReader(outReader); // I use this to read from the output
			
			/* get reduce.img (REDUCE compiled by JLisp)
			 * the file in the project is given the extension
			 * png because otherwise it will be compressed by
			 * Android's packaging tool, And the rule says
			 * that I cannot read any compressed file that is
			 * larger than 1 MB, the packaging tool however
			 * does not compress png (amongst few others)
			 */
			AssetManager mgr = context.getAssets();
			final InputStream reduceImageStream = mgr.open("reduce.png");
		
			// create a background thread to run JLisp in the background
			Thread t = new Thread(
					new ThreadGroup("arbitrary"),
					new Runnable() {
						@Override
						public void run() {
							
							//Log.d("Memory", );
							
							// This will be running in the background
							Jlisp.startup(
									new String[] { },
									inReader, 
									outPrintWriter, 
									true, 
									reduceImageStream
									);
						}
					}, 
					"jlisp_thread", // thread name
					20 * 1000 * 1000); // stack size 20MB
			
			
			// start JLisp
			t.start();
			
			// turn on TeX style output from REDUCE
			// and wait for another input prompt
			reducePrintln("on fancy;");
		
			waitForPrompt();
			
			// make sure REDUCE does not try to do
			// the line breaking for me.
			// this pretends that the line width is 
			// so huge that no breaking is needed
			reducePrintln("linelength 100000;");
		
			waitForPrompt();
			
			// Enter something to make REDUCE load its core packages
			reducePrintln("1;");
		
			waitForPrompt();
			
			// make sure the previous code (inside the 
			// if statement) is never executed again
			jlispThread = t;
		} catch (Exception e) {
			
		}
	}
}



 