package uk.ac.cam.aa582.structures.tex;

import java.util.EnumSet;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.Font;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox;
import uk.ac.cam.aa582.structures.boxes.OperationBox;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;
import uk.ac.cam.aa582.structures.boxes.SpaceBox.Space;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;
import uk.ac.cam.aa582.structures.boxes.TableBox;
import uk.ac.cam.aa582.structures.tex.TexLexer.LexFont;
import uk.ac.cam.aa582.structures.tex.TexLexer.LexType;

/**
 * 
 * This is a parser for LaTeX strings. For example passing 
 * in <tt>"$ 1 + \frac{x^2.2}3 $"</tt> through th constructor 
 * and calling {@link TexParser#parse()} will return a tree
 * of boxes that stands for that formula. This parser internally
 * uses a {@link TexLexer} to perform the lexical analysis.<br/><br/>
 * 
 * 
 * The code inside this class is either copied and translated from, or 
 * heavily resembles code in FXShowMath.cpp by Dr. Arthur C. Norman,
 * and most of the comments are his original comments. Therefore this 
 * is NOT original work of Ahmad Akra. 
 * FXShowMath.cpp is included in the same package for reference.
 * 
 * @author Ahmad Akra
 *
 */
public class TexParser {

	private enum Stop { comma, tab, nl, ket };
	private class TeXState { 
		LexFont currentFont = LexFont.FntItalic; 
	//	boolean insideFrac = false; 
	}

	private TexLexer lexer;
	private Token lexKey;
	private LexType lexType;
	private TeXState currentState = new TeXState();

	public TexParser(String tex) {
		lexer = new TexLexer(tex);
	}

	public Box parse() {
		nextSymbol();
		return readE1();
	}
	
	private Box readE1()
	{
	// Read stuff until EOF.
	    Box result = null;
	    while (lexType != LexType.lexError &&
	           lexType != LexType.lexEOF)
	    {
	// Here if I get an "unexpected" close bracket I will in effect insert a
	// "\left ." at the start of my input to match it.
	        if (lexType == LexType.lexEnd)
	        {   BlockHandlerFunction fn = (BlockHandlerFunction)lexKey.ptr;
	            if (result == null) result = new SpaceBox();
	            if (fn != null) result = fn.execute(lexKey.charCode,'.', result);
	            nextSymbol();
	            continue;
	        }
	        Box n = readS();
	        if (result == null) { result = n; }
	        else if (n != null) {
	        	if(result instanceof SequenceBox) {
	        		result = ((SequenceBox)result).append(n);
	        	} else {
	        		result = new SequenceBox(result, n);
	        	}
	        }
	         //   result = makeNestBox(BoxBeside, result, n);
	    }
	    return result;
	}

	// TODO change the name of this to "lex"
	private void nextSymbol() {
		lexKey = lexer.lex();
		lexType = lexer.lexType();
	}


	private Box readS() {
		Box base=readP(), 
				sup=null, 
				sub=null;

		while(true)
		{   
			if(lexType == LexType.lexSuper)
			{   
				nextSymbol();
				TeXState saveState = currentState;
				//if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
				sup = readP();
				currentState = saveState;
				if(lexType == LexType.lexSub)
				{   
					nextSymbol();
					saveState = currentState;
					//if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
					sub = readP();
					currentState = saveState;
				}
			}
			else if(lexType == LexType.lexSub)
			{   
				nextSymbol();
				TeXState saveState = currentState;
				//if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
				sub = readP();
				currentState = saveState;
				if (lexType == LexType.lexSuper)
				{   nextSymbol();
				saveState = currentState;
				//if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
				sup = readP();
				currentState = saveState;
				}
			}
			// Now I have parsed a bit: glue the boxes together...
			if (sub != null || sup != null) {
				base = new ScriptBox(base, sup, sub);
			}
			// Going beyond what TeX supports I will permit things like
			// x^y^z and x_y_z. I group sub- and superscripts so that at each level
			// I support one of each in either order. The resulting layout may be
			// less then perfect but should be what you would have got with
			// {x^y}^z etc so is not outrageous. 
			if (lexType != LexType.lexSuper &&
					lexType != LexType.lexSub) break;
		}
		return base;
	}

	private Box readE(EnumSet<Stop> stopAt) {
		// I ALWAYS stop if I see a "}" or an "\end{xxx}". I can optionally
		// stop on ",", "&" or "\\" (the first of these is used in optional argument
		// lists and the second two in matrixes.
		LinkedList<Box> result = new LinkedList<Box>();
		// This ALWAYS stops as a lexEnd (or error or eof). Depending on the
		// bitmask given as an argument it may stop at "\\", "&", "," or "]" too
//		while (lexType != LexType.lexEnd && lexType != LexType.lexError && lexType != LexType.lexEOF &&
//				(		!stopAt.contains(Stop.tab) ||
//						lexType != LexType.lexSpecial ||
//						(lexKey.name.equals("&")) &&
//						!stopAt.contains(Stop.nl) ||
//						lexType != LexType.lexSpecial ||
//						(lexKey.name.equals("\\\\")) &&
//						!stopAt.contains(Stop.ket) ||
//						lexType != LexType.lexSpecial ||
//						(lexKey.name.equals("]")) &&
//						!stopAt.contains(Stop.comma) ||
//						lexType != LexType.lexSpecial ||
//						lexKey.name.equals(",")))
//		{  
		while(true) {
			
			if(lexType == LexType.lexEnd) break;
			if(lexType == LexType.lexError) break;
			if(lexType == LexType.lexEOF) break;
			if(lexType == LexType.lexSpecial) {
				if(stopAt.contains(Stop.tab) && lexKey.name.equals("&")) break;
				if(stopAt.contains(Stop.nl) && lexKey.name.equals("\\\\")) break;
				if(stopAt.contains(Stop.ket) && lexKey.name.equals("]")) break;
				if(stopAt.contains(Stop.comma) && lexKey.name.equals(",")) break;
			}
			
			Box s = readS();
			result.add(s);
		}
		if(result.size() == 1) return result.getFirst();
		else return new SequenceBox(result.toArray(new Box[0]));
	}

	private Box readP() {
		switch (lexType) {
		case lexBegin:
		{   
			LexFont w = lexKey.font; // used to say which sort of "begin"
			if (w == LexFont.matchMatrix) return readMatrix();
			int chL = lexKey.charCode;
			Box contents = null;
			TeXState saveState = currentState;
			BlockHandlerFunction fn = (BlockHandlerFunction)lexKey.ptr;
			if (lexKey.ptr != null) fn.execute(' ', chL, null);
			nextSymbol();
			contents = readE(EnumSet.noneOf(Stop.class));
			if (lexType == LexType.lexError) return null;
			else if (lexType == LexType.lexEOF)
			{
				// Here if I find an EOF when I was expecting a close bracket of some sort
				// I just treat it as if the close bracket had been found, an in the case
				// of \left..\right I treat it as if I had seen "\right .".
				if (fn != null) contents = fn.execute('.', chL, contents);
				return contents;
			} else if (lexType != LexType.lexEnd || w != lexKey.font) {   
				System.err.printf("end does not match begin properly\n");
				System.err.printf("Want %d/%d got %d/%d\n",
						LexType.lexEnd, w, lexType, lexKey.font);
				lexType = LexType.lexError;
				// In this case I will not perform any side-effects that calling the handler
				// function normally would at the end of a block. That certainly means,
				// for instance, that I lose track of whether I am inside or outside "$"
				// markers. But since I have reported an error and the parse is getting
				// nowhere this does not worry me.
				return null;
			}
			currentState = saveState;
			if (lexKey.ptr != null) contents = fn.execute(lexKey.charCode, chL, contents);
			nextSymbol();
			return contents;
		}
		case lexWord:
		{   
			Box b = makeTextBox(lexKey.name, currentState.currentFont); // includes currentSize
			nextSymbol();
			return b;
		}
		case lexNumber:
		{   	
			Box b = makeTextBox(lexKey.name, LexFont.FntRoman);
			nextSymbol();
			return b;
		}
		case lexSpecial:   // in this case lexKey tells me which keyword it is.
			switch (lexKey.type)
			{
			case TeXSymbol:
			{   
				char sym = remap(lexKey.charCode);
				Box b = makeTextBox(sym+"", lexKey.font);
				nextSymbol();
				return b;
			}
			case TeXWSymbol:
			{
				char sym = remap(lexKey.charCode);
				short si = pack(sym, lexKey.font); // contains information about char and font
				nextSymbol();
				// TODO: Make distinction between operation and relation boxes
				return new OperationBox(si, new SpaceBox(Space.nospace), new SpaceBox(Space.nospace));
			}
			case TeXVSymbol:
				// This case will need MORE WORK in a couple of ways:
				//   (a) the symbol used is from the cmex font and so is positioned as
				//	       a descender. It will need moving to put it where it wants to go!
				//   (b) subscripts and superscripts for these objects get put in special
				//	       places. Eg consider \sum{i=0}^{n}.
				// I mark for these by setting the "FntBig" bit in the byte that gives font
				// and size. That then mostly has to adjust the code that lays out subscripts.
			{   
				char s = remap(lexKey.charCode);
				LargeOp op = null;
				if(lexKey.name.equals("int")) { op = LargeOp.integral; } 
				else if(lexKey.name.equals("Int")){ op = LargeOp.integral; }
				else if(lexKey.name.equals("oint")){ op = LargeOp.ointegral; }
				else if(lexKey.name.equals("prod")){ op = LargeOp.prod; }
				else if(lexKey.name.equals("sum")){ op = LargeOp.sum; }
				
				if(op != null) {
					Box b = new LargeOperatorSymbolBox(op);
					nextSymbol();
					return b;
				}
				else {
					
				    Box b = makeTextBox(s+"", lexKey.font);
					nextSymbol();
					return b;
				}
			}
			case TeXRoman:
			{   
				Box b = makeTextBox(lexKey.name, LexFont.FntRoman);
				nextSymbol();
				return b;
			}
			case TeXScript:
				System.err.printf("TeX script-marker found but not handled (%s)\n", lexKey.name);
				nextSymbol();
				return null;
			case TeX0Arg:
				if (lexKey.ptr != null)
				{   
					Box b = ((KeywordHandlerFunction)(lexKey.ptr)).execute(lexKey.charCode);
					//Box b = fn(lexKey.ptr,-1,lexKey.charCode,null);
					nextSymbol();
					return b;
				}
				System.err.printf("TeX keyword 0 found but not handled (%s)\n", lexKey.name);
				nextSymbol();
				return null;
			case TeX1Arg:
				// One-arg things can include cases such as "\sqrt" which need to support
				// optional args as well as the mandatory one. As best I can see in the
				// current tmprint code "\sqrt" is the only such case used! Furthermore
				// I think it only ever puts ONE item within the "[]", as in
				//	           \sqrt[3]{1+x}      or    \sqrt[p]{A}
				// but it does put a "\," within the square brackets to adjust spacing.
			{   
				Token key = lexKey;   // remember what introduced this
				Box contents = null, optarg = null;
				TeXState saveState = currentState;

				OneArgHandlerFunction fn = (OneArgHandlerFunction)key.ptr;
				nextSymbol();
				// Check here for a "["
				if (lexType == LexType.lexSpecial &&
						lexKey.name.equals("["))
				{   
					nextSymbol();
					//if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
					optarg = readE(EnumSet.of(Stop.ket));
					if (lexType != LexType.lexSpecial ||
							!lexKey.name.equals("]"))
					{   
						System.err.printf("\"]\" not found\n");
						lexType = LexType.lexError;
						currentState = saveState;
						return null;
					}
					currentState = saveState;
					nextSymbol();
				}
				// The state I use when parsing the argument may be changed by this where I
				// call the handler with NULL arguments.
				if (key.ptr != null) fn.execute(null, null);
				if (lexType != LexType.lexBegin ||
						lexKey.font != LexFont.matchBrace)
				{   
					System.err.printf("\"{\" expected after keyword \"\\%s\"\n", lexKey.name);
					lexType = LexType.lexError;
					currentState = saveState;
					return null;
				} else nextSymbol();
				contents = readE(EnumSet.noneOf(Stop.class));
				if (lexType == LexType.lexError)
				{   
					currentState = saveState;
					return null;
				}
				else if (lexType != LexType.lexEnd || lexKey.font != LexFont.matchBrace)
				{
					// While I am lenient about SOME forms of bracketing, the "{}" surrounding
					// arguments must be complete in one section of TeX input.
					System.err.printf("\"}\" not found\n");
					lexType = LexType.lexError;
					currentState = saveState;
					return null;
				}
				nextSymbol();
				currentState = saveState;
				//if (fn != NULL) contents = fn(contents, optarg);
				if (fn != null) contents = fn.execute(contents, optarg);

				return contents;
			}
			case TeX2Arg:
			{   
				Token key = lexKey;
				Box b1, b2;
				TeXState saveState = currentState;
				TwoArgsHandlerFunction fn = (TwoArgsHandlerFunction)key.ptr;
				if (fn == null)
				{   
					System.err.printf("incomplete implementation for \"\\%s\"\n", lexKey.name);
					return null;
				}
				nextSymbol();
				if (lexType != LexType.lexBegin ||
						lexKey.font != LexFont.matchBrace)
				{   
					System.err.printf("\"{\" expected after keyword \"\\%s\"\n", lexKey.name);
					lexType = LexType.lexError;
					return null;
				}
				else nextSymbol();
				// The SECOND (and deeper) depth of \frac causes its contents
				// to be set in a smaller font, as for subscripts.
//				if (key.font == '/')
//				{   
//					if (currentState.insideFrac)
//					{   
//						//					if (currentSize < FntScrScr)
//						//						currentState.currentFont+=FntScript;
//					}
//					else currentState.insideFrac = true;
//				}
//				if (key.font == 'S' && currentSize < FntScrScr)
//					currentState.currentFont+=FntScript;

				b1 = readE(EnumSet.noneOf(Stop.class));
				if (lexType == LexType.lexError)
				{   
					currentState = saveState;
					return null;
				}
				else if (lexType != LexType.lexEnd || lexKey.font != LexFont.matchBrace)
				{   
					System.err.printf("\"}\" not found\n");
					lexType = LexType.lexError;
					currentState = saveState;
					return null;
				}
				nextSymbol();
				currentState = saveState;
//				if (key.font == '/')
//				{   
//					if (currentState.insideFrac)
//					{   
//						//					if (currentSize < FntScrScr)
//						//						currentState.currentFont+=FntScript;
//					}
//					else currentState.insideFrac = true;
//				}
				// The second arg can be any sort of block, but it could
				// also be a simple atom. Thus "\frac{1}2" will be accepted
				b2 = readP();
				currentState = saveState;
				return fn.execute(b1, b2);
			}
			//			case TeXRule:  // I want to support \rule[offset]{height}{width}
			//			{  
			//				Box b1;
			//				int depth=0, height=0, width=0;
			//				TeXState saveState = currentState;
			//				nextSymbol();
			//				if (lexType == LexType.lexSpecial &&
			//					lexKey.name.equals("["))
			//				{   
			//					nextSymbol();
			//					depth = readNumber();
			//			if (lexType != lexSpecial ||
			//					strcmp(lexKey->name, "]") != 0)
			//			{   printf("\"]\" not found\n");
			//			lexType = lexError;
			//			currentState = saveState;
			//			return NULL;
			//			}
			//			currentState = saveState;
			//			nextSymbol();
			//			}
			//			currentState = saveState;
			//			if (lexType != lexBegin ||
			//					lexKey->font != matchBrace)
			//			{   printf("\"{\" expected after keyword \"\\%s\"\n",
			//					lexKey->name);
			//			lexType = lexError;
			//			currentState = saveState;
			//			return NULL;
			//			}
			//			else nextSymbol();
			//			width = readNumber();
			//			if (lexType == lexError)
			//			{   currentState = saveState;
			//			return NULL;
			//			}
			//			else if (lexType != lexEnd || lexKey->font != matchBrace)
			//			{   printf("\"}\" not found\n");
			//			lexType = lexError;
			//			currentState = saveState;
			//			return NULL;
			//			}
			//			nextSymbol();
			//			currentState = saveState;
			//			// The second arg can be any sort of block, but it could
			//			// also be a simple atom. Thus "\rule{1}2" will be accepted.
			//			if (lexType == lexBegin &&
			//					lexKey->font == matchBrace)
			//			{   nextSymbol();
			//			height = readNumber();
			//			if (lexType == lexError) return NULL;
			//			else if (lexType != lexEnd || lexKey->font != matchBrace)
			//			{   printf("\"}\" not found\n");
			//			lexType = lexError;
			//			return NULL;
			//			}
			//			nextSymbol();
			//			}
			//			else height = readNumber();
			//			currentState = saveState;
			//			b1 = makeSymBox(SymRule);
			//			b1->sym.height = height+depth;
			//			b1->sym.depth = -depth;
			//			b1->sym.width = width;
			//			return b1;
			//			}
			default:
				System.err.printf("TeX keyword found but not handled (%s)\n", lexKey.name);
				nextSymbol();
				return null;
			}
		default:
			System.err.printf("TeX syntax problem\n");
			lexType = LexType.lexError;
		case lexError:     // if the token is lexError a diagnostic has already
			// been printed.
			return null;
		}
	}

	private short pack(char sym, LexFont font) {
		switch(font) {
		case FntRoman : return (short) (((short)sym) + 0x0A00);
		case FntItalic : return (short) (((short)sym) + 0x0B00);
		case TeXtension : return (short) (((short)sym) + 0x0C00);
		case FntSymbol : return (short) (((short)sym) + 0x0D00); 
		default : return (short) (((short)sym) + 0x0A00);
		}
	}

	private char remap(char ch) {
//		#ifndef WIN32
		// If I use Xft to render things I can afford to (and indeed had better)
		// use glyph positions in ther original locations. Also if I am printing
		// I will avoid remapping.
//		    return (char)ch;
//		#else
		    int ch1;
		    ch &= 0xff;       // in case chars are signed.
		    if (ch <= 0x20) ch1 = remapTable[ch];
		    else if (ch == 0x7f) ch1 = 0xc4;
		    else ch1 = ch;
//		#ifdef TEST
//		    if ((char)ch != (char)ch1) printf("Char %x mapped to %x\n", ch, ch1 & 0xff);
//		#endif
		    return (char)ch1;
//		#endif
	}
	
	static char[] remapTable = new char[]
		{
		    0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8,
		    0xa9, 0xaa, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2,
		    0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba,
		    0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2,
		    0xc3
		};

	private Box makeTextBox(String name, LexFont currentFont) {
		switch(currentFont) {
		case FntRoman : return new SymbolBox(name, Font.cmr);
		case FntItalic : return new SymbolBox(name, Font.cmmi);
		case FntSymbol : return new SymbolBox(name, Font.cmsy);
		case TeXtension : return new SymbolBox(name, Font.cmex);
		default : return new SymbolBox(name); // default is roman
		}
	}

	@SuppressWarnings("unused")
	private String readNumber()
	{
		String r;
		if (lexType == LexType.lexNumber)
		{   
			r = lexKey.name;
			nextSymbol();
			skipUnit();
			return r;
		}
		else if (lexType == LexType.lexSpecial && lexKey.name.equals("-"))
		{   nextSymbol();
		if (lexType == LexType.lexNumber)
		{   
			r = lexKey.name;
			nextSymbol();
			skipUnit();
			return "-" + r;
		}
		}
		return "0";
	}

	private void skipUnit()
	{
		if (lexType != LexType.lexWord) return;
		if (lexKey.equals("pt")) nextSymbol();
	}

	private TableBox readMatrix() {
		TableBox contents = null;
		TeXState saveState = currentState;
		nextSymbol();
		contents = readRows();
		if (lexType == LexType.lexError) return null;
		else if (lexType != LexType.lexEnd || LexFont.matchMatrix != lexKey.font)
		{  
			System.err.printf("end does not match begin properly\n");
			System.err.printf("Want \\end{matrix} got %d/%d\n", lexType, lexKey.font);
			lexType = LexType.lexError;
			return null;
		}
		currentState = saveState;
		nextSymbol();
		return contents;
	}
	
	

	private TableBox readRows() { 
		LinkedList<Box> result = new LinkedList<Box>();
		LinkedList<Box> n = readRow();
		int cols = 0;
		int rows = 0;
		if (n != null) { 
			rows++;
			cols = n.size();
			result.addAll(n);
		}

		while (lexType == LexType.lexSpecial &&
				lexKey.name.equals("\\\\")) {

			nextSymbol();
			n = readRow();
			if (n != null) {
				rows++;
				if(n.size() != cols) System.err.println("At least 2 Matrix rows do not have consistent length");
				result.addAll(n);
			}
		}
		return new TableBox(rows, cols, result.toArray(new Box[0]));
	}

	private LinkedList<Box> readRow() {
		LinkedList<Box> result = new LinkedList<Box>();

		Box n = readE(EnumSet.of(Stop.tab, Stop.nl));
		if (n != null) result.add(n);
		while (lexer.lexType() == LexType.lexSpecial &&
				lexKey.name.equals("&")) {
			nextSymbol();
			n = readE(EnumSet.of(Stop.tab, Stop.nl));
			if (n != null) result.add(n);
		}
		return result;
	}



	public static abstract class Function {

	}

	public static abstract class StringFunction extends Function {
		public abstract String execute();
	}

	public static abstract class KeywordHandlerFunction extends Function {
		public abstract Box execute(int c);
	}

	public static abstract class BlockHandlerFunction extends Function {
		public abstract Box execute(char c, int i, Box b);
	}

	public static abstract class OneArgHandlerFunction extends Function {
		public abstract Box execute(Box b, Box opt);
	}

	public static abstract class TwoArgsHandlerFunction extends Function {
		public abstract Box execute(Box b1, Box b2);
	}
}

