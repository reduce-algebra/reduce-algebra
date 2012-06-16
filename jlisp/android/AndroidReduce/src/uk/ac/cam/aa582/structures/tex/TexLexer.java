package uk.ac.cam.aa582.structures.tex;

import java.util.Hashtable;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.Delimiters;
import uk.ac.cam.aa582.structures.boxes.FractionBox;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox.Space;
import uk.ac.cam.aa582.structures.boxes.SqrtBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;
import uk.ac.cam.aa582.structures.tex.TexParser.BlockHandlerFunction;
import uk.ac.cam.aa582.structures.tex.TexParser.KeywordHandlerFunction;
import uk.ac.cam.aa582.structures.tex.TexParser.OneArgHandlerFunction;
import uk.ac.cam.aa582.structures.tex.TexParser.StringFunction;
import uk.ac.cam.aa582.structures.tex.TexParser.TwoArgsHandlerFunction;

/**
 * 
 * This is a lexical analyzer for TeX strings, it breaks the TeX string and
 * returns a stream of {@link Token}s in accordance with the TeX
 * Syntax. For example passing in <tt>"$ 1 + \frac{x^2.2}3 $"</tt> will return
 * the following tokens from {@link TexLexer#lex()}: <br/>
 * <br/>$
 * <br/>1
 * <br/>+
 * <br/>frac
 * <br/>{
 * <br/>x
 * <br/>^
 * <br/>2.2
 * <br/>}
 * <br/>3
 * <br/>$
 * 
 * <br/><br/>
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
public class TexLexer {

	public enum Do {
		/**
		 * block
		 */
		doLeftRight,
		/**
		 * block
		 */
		doMathBrace, 
		/**
		 * block
		 */
		doDollar, 
		
		/**
		 * 1 arg
		 */
		doPmod,
		
		same, 
		
		/**
		 * keyword
		 */
		doSpaceCommand,
		/**
		 * keyword
		 */
		doNeq,
		/**
		 * keyword
		 */
		doNot, 
		/**
		 * keyword
		 */
		doDisplayStyle, 
		
		/**
		 * keyword
		 */
		doLarge, 
		
		/**
		 * 1 arg
		 */
		doMathRm,
		/**
		 * 1 arg
		 */
		doMathIt, // 1 arg
		/**
		 * 1 arg
		 */
		doSqrt, // 1 arg
		/**
		 * 1 arg
		 */
		doFbox, // 1 arg
		/**
		 * 1 arg
		 */
		doSymb, // 1 arg
		
		/**
		 * 2 arg
		 */
		doFrac, // 2 arg
		/**
		 * 2 arg
		 */
		doStackrel // 2 arg

	}
	public enum LexType {
		lexError     ,
		lexEOF       ,
		lexSpecial   ,
		lexWord      ,
		lexNumber    ,
		lexBegin     ,
		lexEnd       ,
		lexSuper     ,
		lexSub       
	}
	public enum TokenType {
		/**  single character glyph */
		TeXSymbol,
		/**  single character glyph, but subscripts and superscripts form tower */
		TeXVSymbol,
		/**  single character glyph, but allow extra space on either side */
		TeXWSymbol,
		/**  word to be set in Roman font (eg function name like "sin") */
		TeXRoman,
		/**  keyword not taking an argument, eg \longleftarrow, \not */
		TeX0Arg,
		/**  keyword taking one arg, eg \sqrt */
		TeX1Arg,
		/**  keyword taking 2 args, eg \frac */
		TeX2Arg,
		/**  the \rule keyword */
		TeXRule,
		/**  the \begin keyword */
		TeXBeginWord,
		/**  keyword that forms a sort of "open bracket" */
		TeXBegin,
		/** "close bracket" to match TeXBegin */
		TeXEnd,
		/**  "^" or "_". */
		TeXScript,

		TeXFlag,
	}

	public enum LexFont {
		zero, 
		one, 
		LexFont, 
		matchLeftRight, 
		matchCenter, 
		matchMatrix,
		matchParen, 
		matchBracket, 
		matchDollar, 
		matchBrace,  
		
		FntItalic, 
		FntRoman, 		
		FntSymbol, 
		TeXtension, 
		
		forwardSlash, 
		capitalS,
	}


	private boolean insideDollars = false;
	private String tex;
	private int index = 0;
	private LexType lexType = null;
	private Token lexKey = null;
	private char curChar = (char) ' ';
	private LinkedList<Character> lexerBuffer = new LinkedList<Character>();

	public TexLexer(String tex) {

		tex = tex.replaceAll("\\\\displaystyle\\s*", ""); // remove the erroneous \displaystyle
		this.tex = tex;
		//rehashKeywordTable();
	}


	/**
	 * This method returns the next {@link Token} of the String passed 
	 * originally to the constructor. The {@link Token} is returned in
	 * accordance with the TeX Syntax. For example if <tt>"$ 1 + \frac{x^2.2}3 $"</tt>
	 * was passed to the constructor, calling this method multiple times will return 
	 * the following tokens in this order: <br/>
	 * <br/>$
	 * <br/>1
	 * <br/>+
	 * <br/>frac
	 * <br/>{
	 * <br/>x
	 * <br/>^
	 * <br/>2.2
	 * <br/>}
	 * <br/>3
	 * <br/>$
	 * 
	 * @return The next token from the string according
	 * to TeX syntax.
	 */
	public Token lex() {
		lexKey = null;
		nextSymbol();
		//		System.out.println("Buffer: " + lexerBuffer);
		return lexKey;
	}

	public LexType lexType() {
		return lexType;
	}

	private char nextChar() {
		if(index == tex.length()) return 0;
		else return tex.charAt(index++);
	}

	private void nextSymbol() {
		//Discard whitespace
		while (curChar != 0 && isspace(curChar)) curChar = nextChar();
		//	System.err.println("\""+curChar+"\"");
		//Detect end of input
		if (curChar == 0) {   
			lexType = LexType.lexEOF;
			return;
		}
		//OK, now we have the start of a new symbol.
		switch (curChar)
		{
		case '%': // discard comments
			while ((curChar = nextChar()) != 0 && curChar != '\n');
			nextSymbol();
			return;		
		case '^':
			lexerBuffer.clear();
			lexType = LexType.lexSuper;
			bufferCurChar();
			curChar = nextChar();
			lexKey = new Token(hashKey(lexerBuffer), TokenType.TeXScript, null, (char)0, null, null);
			return;
		case '_':
			lexerBuffer.clear();
			lexType = LexType.lexSub;
			bufferCurChar();
			curChar = nextChar();
			lexKey = new Token(hashKey(lexerBuffer), TokenType.TeXScript, null, (char)0, null, null);
			return;
		case '{':
		case '}':
		case '&':
			lexerBuffer.clear();
			bufferCurChar();
			bufferZero();
			lexKey = lookupHash(lexerBuffer);
			if (curChar == '{') lexType = LexType.lexBegin;
			else if (curChar == '}') lexType = LexType.lexEnd;
			else lexType = LexType.lexSpecial;
			curChar = nextChar();
			return;
		case '$':
			lexerBuffer.clear();
			bufferCurChar();
			bufferZero();
			lexKey = lookupHash(lexerBuffer);
			//"$" will be a BEGIN if you are not in math mode, or an END if you are!
			//This is yet another curious hack to cope with the syntax of LaTeX, which
			//appears somewhat curious in places.
			lexType = insideDollars ? LexType.lexEnd : LexType.lexBegin;
			insideDollars = !insideDollars;
			curChar = nextChar();
			return;
			//A bunch of characters are handled in a magic way here because they
			//might map onto some specific font or character coding.
		case '+':   case '-':   case '*':   case '/':
		case ':':   case ';':   case '@':   case ',':
		case '.':   case '?':   case '!':   case '|':
		case '`':   case '#':   case '~':   case '=':
		case '(':   case ')':   case '<':   case '>':
		case '[':   case ']':
			//"NOTSIGN" ??
			lexerBuffer.clear();
			bufferCurChar();
			bufferZero();
			lexKey = lookupHash(lexerBuffer);
			lexType = LexType.lexSpecial;
			curChar = nextChar();
			return;
		case '\\':
			lexerBuffer.clear();
			curChar = nextChar();
			if (curChar == 0) {             //  Treat "\<eof>" as just <eof>
				lexType = LexType.lexEOF;
				return;
			}
			while (isalnum(curChar)) {
				bufferCurChar();
				curChar = nextChar();
			}
			//I assemble EITHER "\word" or "\delim"
			if (lexerBuffer.isEmpty()) {   
				lexerBuffer.add('\\');   // put the "\" explicitly there
				bufferCurChar();
				curChar = nextChar();
			}
			bufferZero();
			//lexerBuffer.set(0, (char)0x0);
			//There is an UTTERLY odd bit of lexical treatment here that
			//makes "\left(" one token. What I do is to take "\left" and "\right"
			//and treat the token after it as part of a single token.
			//Thus I have in effect "\left (" as just one token.
			//The item following one of the words \left or \right must be a TeX
			//"delimiter" and they can be in one of 3 forms:
			//character            (,),[,],/,|
			//escaped character    \{, \}, \|
			//escaped word         \lfloor, \Uparrow etc etc
			//I will pack things in being a bit generous in what I allow, but bad cases
			//will then get spotted because they will count as unknown TeX keywords.
			if((strcmp(lexerBuffer, "left") == 0 ||
					strcmp(lexerBuffer, "right") == 0) &&
					curChar != 0) {   
				while(curChar != 0 && isspace(curChar)) { curChar = nextChar(); }
				lexerBuffer.add(':');
				if(curChar == '\\') {   
					bufferCurChar();
					curChar = nextChar();
					if(curChar != 0 && isalnum(curChar)) {
						while (isalnum(curChar)) {       // \word
							bufferCurChar();
							curChar = nextChar();
						}
					} else if(curChar != 0) {              // \delim
						bufferCurChar();
						curChar = nextChar();
					}
				} else if(curChar != 0) {                   // just a delim
					bufferCurChar();
					curChar = nextChar();
				}

				bufferZero();
			}
			lexKey = lookupHash(lexerBuffer);
			if(lexKey == null) {
				System.out.printf("Unrecognised keyword \"\\%s\"\n", lexerBuffer);
				lexType = LexType.lexError;
				return;
			}
			if (lexKey.type == TokenType.TeXBeginWord) // "\begin" or "\end"
			{   
				LexFont beginFlag = lexKey.font;
				while (curChar != 0 && isspace(curChar)) curChar = nextChar();
				if (curChar != '{') {   
					System.err.printf("Brace expected after \\begin or \\end\n");
					lexType = LexType.lexError;
					return;
				}
				else curChar = nextChar();
				while (curChar != 0 && isspace(curChar)) 
					curChar = nextChar();
				lexerBuffer.clear();
				lexerBuffer.add(beginFlag != LexFont.zero ? '(' : ')');
				while (isalnum(curChar)) {
					bufferCurChar();
					curChar = nextChar();
				}
				while (curChar != 0 && isspace(curChar)) 
					curChar = nextChar();
				if (curChar != '}') {
					System.err.printf("Closing brace expected after \\begin or \\end\n");
					lexType = LexType.lexError;
					return;
				} else curChar = nextChar();
				bufferZero();
				lexKey = lookupHash(lexerBuffer);
				if (lexKey == null) {
					System.err.printf("Unrecognised \\begin or \\end \"\\%s\"\n", lexerBuffer.get(1));
					lexType = LexType.lexError;
					return;
				}
				lexType = beginFlag != LexFont.zero ? LexType.lexBegin : LexType.lexEnd;
				return;
			}
			//I now need to cope with "\left(", "\(" and the like which are "begin/end"
			//style items.
			if (lexKey.type == TokenType.TeXBegin) lexType = LexType.lexBegin;
			else if (lexKey.type == TokenType.TeXEnd) lexType = LexType.lexEnd;
			else lexType = LexType.lexSpecial;
			return;
		default:
			lexerBuffer.clear();
			//Anything that starts with a digit will be taken to be a number. I permit
			//digits then possibly "." followed by more digits and possibly an exponent
			//introduced by "e" or "E".
			if (isdigit(curChar)) {   // handle as a number
				while (isdigit(curChar)) {
					//	if (lexLength < maxLexLength)
					bufferCurChar();
					curChar = nextChar();
				}
				if (curChar == '.') {
					bufferCurChar();
					curChar = nextChar();
					while (isdigit(curChar)) {
						bufferCurChar();
						curChar = nextChar();
					}
				}
				if (curChar == 'e' || curChar == 'E') {
					bufferCurChar();
					curChar = nextChar();
					if (curChar == '+' || curChar == '-') {
						bufferCurChar();
						curChar = nextChar();
					}
					while (isdigit(curChar)) {
						bufferCurChar();
						curChar = nextChar();
					}
				}
				bufferZero();
				lexType = LexType.lexNumber;
				lexKey = new Token(hashKey(lexerBuffer), null, LexFont.FntRoman, (char)0, null, null);
				return;
			}
			while (isalnum(curChar)) {
				bufferCurChar();
				curChar = nextChar();
			}
			if (lexerBuffer.isEmpty()) {
				bufferCurChar();
				curChar = nextChar();
			}
			bufferZero();
			lexType = LexType.lexWord;
			lexKey = new Token(hashKey(lexerBuffer), null, LexFont.FntRoman, (char)0, null, null);
			return;
		}
	}



	private void bufferZero() {
		//	buffer((char)0);
	}



	private void bufferCurChar() {
		buffer(curChar);
	}

	private void buffer(char c) {
		if(lexerBuffer.size() > 0 && lexerBuffer.get(lexerBuffer.size()-1) == (char)0) {
			lexerBuffer.add(lexerBuffer.size()-1, c);
			return;
		} else lexerBuffer.add(c);
	}

	private int strcmp(LinkedList<Character> buff, String str2) {
		String str1 = "";
		for(char c : buff) {
			if(c == 0) break;
			str1 += c;
		}
		return str1.equals(str2) ? 0 : 1;
	}

	private boolean isalnum(char c) {
		return (c+"").matches("[0-9a-zA-Z]");
	}

	private Token lookupHash(LinkedList<Character> buff) {
		String key = hashKey(buff);
		//		System.out.println("Key: " + key);
		//		while(true) {
		//			  if (texWords[h].name == NULL) return NULL;
		//		      else if (strcmp(s, texWords[h].name) == 0) return texWords[h];
		//		      else h = (h + 1) % hashTableSize;
		//		}
		return keywords.get(key);
	}

	private String hashKey(LinkedList<Character> buff) {
		String key = "";
		for(char c : buff) {
			if(c == 0) break;
			key += c;
		}
		return key;
	}

	private boolean isdigit(char c) {		
		return c == '0' ||
				c == '1' ||
				c == '2' ||
				c == '3' ||
				c == '4' ||
				c == '5' ||
				c == '6' ||
				c == '7' ||
				c == '8' ||
				c == '9';
	}

	private boolean isspace(char c) {
		return c == ' ';
	}

	private static void rehashKeywordTable() {
		//	if(keywords.isEmpty())
		for(Token keyword : keywordsArray)
			keywords.put(keyword.name, keyword);
	}

	private static Hashtable<String, Token> keywords = new Hashtable<String, Token>();

	/**
	 * This is only an array that is easy to view for the programmer, 
	 * however once the program starts, all the items in this array
	 * are hashed inside a hash table {@link TexLexer#keywords}
	 */
	public static Token[] keywordsArray = new Token[] {
		// Some important control words
		//				    name          type      			 font       charCode  ptr
		// The next two NEVER get out from the lexer.
		new Token("begin",      TokenType.TeXBeginWord,  LexFont.one,         (char)0x00,    null, null),
		new Token("end",        TokenType.TeXBeginWord,  LexFont.zero,         (char)0x00,    null, null),
		// My lexer will map "\begin{center}" onto a single token "(center"
		// and similarly for other uses of \begin and \end. In fact with the
		// current REDUCE "tmprint" module the only brackets of this sort that
		// are used are "center" and "matrix". Also in the CSL driver I will not
		// actually generate the "center" case...
		new Token("(center",    TokenType.TeXBegin,  LexFont.matchCenter,    'c',  null, null),
		new Token(")center",    TokenType.TeXEnd,    LexFont.matchCenter,    'c',  null, null),
		new Token("(matrix",    TokenType.TeXBegin,  LexFont.matchMatrix,    'm',  null, null),
		new Token(")matrix",    TokenType.TeXEnd,    LexFont.matchMatrix,    'm',  null, null),

		// Special-case bracket-like items (delimiters that get displayed
		// at a size the cover the item on one size of them). The case "\right("
		// is probably never used, but I include all cases here for consistency.
		// A "\left" must match with a "\right", but the associated delimiter
		// does not have to match.
		new Token("left:(",     TokenType.TeXBegin,  LexFont.matchLeftRight, '(',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:(",    TokenType.TeXEnd,    LexFont.matchLeftRight, '(',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:)",     TokenType.TeXBegin,  LexFont.matchLeftRight, ')',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:)",    TokenType.TeXEnd,    LexFont.matchLeftRight, ')',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:[",     TokenType.TeXBegin,  LexFont.matchLeftRight, '[',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:[",    TokenType.TeXEnd,    LexFont.matchLeftRight, '[',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:]",     TokenType.TeXBegin,  LexFont.matchLeftRight, ']',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:]",    TokenType.TeXEnd,    LexFont.matchLeftRight, ']',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\{",   TokenType.TeXBegin,  LexFont.matchLeftRight, '{',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\{",  TokenType.TeXEnd,    LexFont.matchLeftRight, '{',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\}",   TokenType.TeXBegin,  LexFont.matchLeftRight, '}',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\}",  TokenType.TeXEnd,    LexFont.matchLeftRight, '}',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:|",     TokenType.TeXBegin,  LexFont.matchLeftRight, '|',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		// Note that I map left and right vertical bars onto different things (I
		// abuse an exclamation mark to stand for the right one) since they may
		// call for different spacings.
		new Token("right:|",    TokenType.TeXEnd,    LexFont.matchLeftRight, '!',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		// "\left." and "\right." are invisible!
		new Token("left:.",     TokenType.TeXBegin,  LexFont.matchLeftRight, '.',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:.",    TokenType.TeXEnd,   LexFont.matchLeftRight, '.',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		// "/", "\", "L", "G" (lceil), "J", "7" (rceil), "<", ">",
		// "#" (double vertical bar), "^" (uparrow), "v" (downarrow), "A" (Uparrow)
		// "V" (Downarrow), "b" (updownarrow), "B" (Updownarrow)
		new Token("left:/",        TokenType.TeXBegin,     LexFont.matchLeftRight, '/',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:/",       TokenType.TeXEnd,       LexFont.matchLeftRight, '/',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\|",      TokenType.TeXBegin,     LexFont.matchLeftRight, '#',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\|",     TokenType.TeXEnd,       LexFont.matchLeftRight, '#',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\langle", TokenType.TeXBegin,     LexFont.matchLeftRight, '<',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\langle",TokenType.TeXEnd,       LexFont.matchLeftRight, '<',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\rangle", TokenType.TeXBegin,     LexFont.matchLeftRight, '>',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\rangle",TokenType.TeXEnd,       LexFont.matchLeftRight, '>',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\backslash", TokenType.TeXBegin,  LexFont.matchLeftRight, '\\', Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\backslash",TokenType.TeXEnd,    LexFont.matchLeftRight, '\\', Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\lfloor", TokenType.TeXBegin,     LexFont.matchLeftRight, 'L',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\lfloor",TokenType.TeXEnd,       LexFont.matchLeftRight, 'L',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\rfloor", TokenType.TeXBegin,     LexFont.matchLeftRight, 'J',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\rfloor",TokenType.TeXEnd,       LexFont.matchLeftRight, 'J',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\lceil",  TokenType.TeXBegin,     LexFont.matchLeftRight, 'G',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\lceil", TokenType.TeXEnd,       LexFont.matchLeftRight, 'G',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\rceil",  TokenType.TeXBegin,     LexFont.matchLeftRight, '7',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\rceil", TokenType.TeXEnd,       LexFont.matchLeftRight, '7',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\uparrow", TokenType.TeXBegin,    LexFont.matchLeftRight, '^',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\uparrow",TokenType.TeXEnd,      LexFont.matchLeftRight, '^',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\downarrow", TokenType.TeXBegin,  LexFont.matchLeftRight, 'v',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\downarrow",TokenType.TeXEnd,    LexFont.matchLeftRight, 'v',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\updownarrow", TokenType.TeXBegin,LexFont.matchLeftRight, 'b',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\updownarrow",TokenType.TeXEnd,  LexFont.matchLeftRight, 'b',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\Uparrow", TokenType.TeXBegin,    LexFont.matchLeftRight, 'A',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\Uparrow",TokenType.TeXEnd,      LexFont.matchLeftRight, 'A',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\Downarrow", TokenType.TeXBegin,  LexFont.matchLeftRight, 'V',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\Downarrow",TokenType.TeXEnd,    LexFont.matchLeftRight, 'V',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("left:\\Updownarrow", TokenType.TeXBegin,LexFont.matchLeftRight, 'B',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		new Token("right:\\Updownarrow",TokenType.TeXEnd,  LexFont.matchLeftRight, 'B',  Do.doLeftRight, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doLeftRight(c,i,b); }}),
		// Some other things that generate enclosing conKeywordType.TeXts
		new Token("{",          TokenType.TeXBegin,  LexFont.matchBrace,     '{',  null, null),
		new Token("}",          TokenType.TeXEnd,    LexFont.matchBrace,     '{',  null, null),
		// "[" and "]" are fairly ordinary characters when they just happen in
		// random places. But after "\sqrt" (and possibly other things) they
		// enclose an optional argument.
		new Token("[",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x5b, null, null),
		new Token("]",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x5d, null, null),
		// At present I will treate "\(" and "\[" as synonyms - both just
		// enter maths mode.
		new Token("\\(",        TokenType.TeXBegin,  LexFont.matchParen,     '(',  Do.doMathBrace, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doMathBrace(c,i,b); }}),
		new Token("\\)",        TokenType.TeXEnd,    LexFont.matchParen,     '(',  Do.doMathBrace, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doMathBrace(c,i,b); }}),
		new Token("\\[",        TokenType.TeXBegin,  LexFont.matchBracket,   '[',  Do.doMathBrace, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doMathBrace(c,i,b); }}),
		new Token("\\]",        TokenType.TeXEnd,    LexFont.matchBracket,   '[',  Do.doMathBrace, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doMathBrace(c,i,b); }}),
		new Token("$",          TokenType.TeXBegin,  LexFont.matchDollar,    '$',  Do.doDollar, new BlockHandlerFunction() { public Box execute(char c, int i, Box b) { return doDollar(c,i,b); }}),

		// Treatment for "\&" etc that just generate literal characters.
		// Note and be warned - the KeywordType.TeX fonts that are going to be used
		// here have their own special encoding schemes so the numeric values
		// that stand for even ordinary-seeming glyphs need careful attention.
		new Token("\\{",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x66, null, null),
		new Token("\\}",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x67, null, null),
		new Token("\\$",        TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x24, null, null),
		new Token("\\&",        TokenType.TeXWSymbol,LexFont.FntRoman,  (char)0x26, null, null),
		new Token("\\%",        TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x25, null, null),

		// subscripts and superscripts involve some parsing magic
		new Token("^",          TokenType.TeXScript, LexFont.zero,        (char)0x00,    null, null),
		new Token("_",          TokenType.TeXScript, LexFont.one,         (char)0x00,    null, null),

		// Simple symbols that need some care because the normal code used
		// here may not match KeywordType.TeX font encodings.
		new Token("+",          TokenType.TeXWSymbol,LexFont.FntRoman,  (char)0x2b, null, null),
		new Token("-",          TokenType.TeXWSymbol,LexFont.FntSymbol, (char)0x00, null, null), // Roman (char)0x2d is hyphen
		new Token("=",          TokenType.TeXWSymbol,LexFont.FntRoman,  (char)0x3d, null, null),
		new Token("*",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x2a, null, null),
		new Token("/",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x2f, null, null),
		new Token(":",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x3a, null, null),
		new Token(";",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x3b, null, null),
		new Token("@",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x40, null, null),
		new Token(",",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x2c, null, null),
		new Token(".",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x2e, null, null),
		new Token("?",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x3f, null, null),
		new Token("!",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x21, null, null),
		new Token("|",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6a, null, null),
		new Token("`",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x12, null, null),
		//  {"NOTSIGN",    KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x3a, null, null),
		new Token("#",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x23, null, null),
		new Token("~",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x7f, null, null),
		new Token("(",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x28, null, null),
		new Token(")",          TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x29, null, null),
		new Token("<",          TokenType.TeXSymbol, LexFont.FntItalic, (char)0x3c, null, null),
		new Token(">",          TokenType.TeXSymbol, LexFont.FntItalic, (char)0x3e, null, null),

		// Lower case Greek

		new Token("alpha",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0b, null, null),
		new Token("beta",       TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0c, null, null),
		new Token("gamma",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0d, null, null),
		new Token("delta",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0e, null, null),
		new Token("epsilon",    TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0f, null, null),
		new Token("varepsilon", TokenType.TeXSymbol, LexFont.FntItalic, (char)0x22, null, null),
		new Token("zeta",       TokenType.TeXSymbol, LexFont.FntItalic, (char)0x10, null, null),
		new Token("eta",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x11, null, null),
		new Token("theta",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x12, null, null),
		new Token("vartheta",   TokenType.TeXSymbol, LexFont.FntItalic, (char)0x23, null, null),
		new Token("iota",       TokenType.TeXSymbol, LexFont.FntItalic, (char)0x13, null, null),
		new Token("kappa",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x14, null, null),
		new Token("varkappa",   TokenType.TeXSymbol, LexFont.FntItalic, (char)0x14, null, null),
		new Token("lambda",     TokenType.TeXSymbol, LexFont.FntItalic, (char)0x15, null, null),
		new Token("mu",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x16, null, null),
		new Token("nu",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x17, null, null),
		new Token("xi",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x18, null, null),
		new Token("omicron",    TokenType.TeXSymbol, LexFont.FntItalic, 'o',  null, null),
		new Token("pi",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x19, null, null),
		new Token("varpi",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x24, null, null),
		new Token("rho",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1a, null, null),
		new Token("varrho",     TokenType.TeXSymbol, LexFont.FntItalic, (char)0x25, null, null),
		new Token("sigma",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1b, null, null),
		new Token("varsigma",   TokenType.TeXSymbol, LexFont.FntItalic, (char)0x26, null, null),
		new Token("tau",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1c, null, null),
		new Token("upsilon",    TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1d, null, null),
		new Token("phi",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1e, null, null),
		new Token("varphi",     TokenType.TeXSymbol, LexFont.FntItalic, (char)0x27, null, null),
		new Token("chi",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x1f, null, null),
		new Token("psi",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x20, null, null),
		new Token("omega",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x21, null, null),
		//
		// Upper case Greek (using Maths Italic for A, B etc where shapes are
		// the same).

		new Token("Alpha",      TokenType.TeXSymbol, LexFont.FntItalic, 'A',  null, null),
		new Token("Beta",       TokenType.TeXSymbol, LexFont.FntItalic, 'B',  null, null),
		new Token("Gamma",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x00, null, null),
		new Token("Delta",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x01, null, null),
		new Token("Epsilon",    TokenType.TeXSymbol, LexFont.FntItalic, 'E',  null, null),
		new Token("Zeta",       TokenType.TeXSymbol, LexFont.FntItalic, 'Z',  null, null),
		new Token("Eta",        TokenType.TeXSymbol, LexFont.FntItalic, 'H',  null, null),
		new Token("Theta",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x02, null, null),
		new Token("Iota",       TokenType.TeXSymbol, LexFont.FntItalic, 'I',  null, null),
		new Token("Kappa",      TokenType.TeXSymbol, LexFont.FntItalic, 'K',  null, null),
		new Token("Lambda",     TokenType.TeXSymbol, LexFont.FntItalic, (char)0x03, null, null),
		new Token("Mu",         TokenType.TeXSymbol, LexFont.FntItalic, 'M',  null, null),
		new Token("Nu",         TokenType.TeXSymbol, LexFont.FntItalic, 'N',  null, null),
		new Token("Xi",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x04, null, null),
		new Token("Omicron",    TokenType.TeXSymbol, LexFont.FntItalic, 'O',  null, null),
		new Token("Pi",         TokenType.TeXSymbol, LexFont.FntItalic, (char)0x05, null, null),
		new Token("Rho",        TokenType.TeXSymbol, LexFont.FntItalic, 'R',  null, null),
		new Token("Sigma",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x06, null, null),
		new Token("Tau",        TokenType.TeXSymbol, LexFont.FntItalic, 'T',  null, null),
		new Token("Upsilon",    TokenType.TeXSymbol, LexFont.FntItalic, (char)0x07, null, null),
		new Token("Phi",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x08, null, null),
		new Token("Chi",        TokenType.TeXSymbol, LexFont.FntItalic, 'X',  null, null),
		new Token("Psi",        TokenType.TeXSymbol, LexFont.FntItalic, (char)0x09, null, null),
		new Token("Omega",      TokenType.TeXSymbol, LexFont.FntItalic, (char)0x0a, null, null),
		//
		// More mathematical symbols. I have copied all the names from my LaKeywordType.TeX
		// book and identified available characters in the cmmi or cmsy fonts where
		// I can. I have at present commented out all characters for which I do not
		// have a glyph. The effect will be that the KeywordType.TeX symbol that names them will
		// be rejected. In some cases I note another font that could help.

		new Token("pm",               TokenType.TeXWSymbol,LexFont.FntSymbol, (char)0x06, null, null),
		new Token("mp",               TokenType.TeXWSymbol,LexFont.FntSymbol, (char)0x07, null, null),
		new Token("times",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x02, null, null),
		new Token("div",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x04, null, null),
		new Token("ast",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x03, null, null),
		new Token("star",             TokenType.TeXSymbol, LexFont.FntItalic, (char)0x3f, null, null),
		new Token("circ",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0e, null, null),
		new Token("bullet",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0f, null, null),
		new Token("cdot",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x01, null, null),
		new Token("cap",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x5c, null, null),
		new Token("cup",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x5b, null, null),
		new Token("uplus",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x5d, null, null),
		new Token("sqcap",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x75, null, null),
		new Token("sqcup",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x74, null, null),
		new Token("vee",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x5f, null, null),
		new Token("wedge",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x5e, null, null),
		// The Variable-sized symbols tend to come in two sizes, and although KeywordType.TeX
		// only used one name (eg \int) and selects which to use based on whether
		// one is in displaymath or ordinary (in-line) mode. Here I am "always" in
		// displaymath mode so I always want the larger versions. But I provide
		// alternative names starting "small" to keep the others available.
		new Token("smallsum",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x50, null, null),
		new Token("sum",              TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x58, null, null),
		new Token("smallprod",        TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x51, null, null),
		new Token("prod",             TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x59, null, null),
		new Token("smallcoprod",      TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x60, null, null),
		new Token("coprod",           TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x61, null, null),
		new Token("smallint",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x52, null, null),
		new Token("int",              TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5a, null, null),
		// It looks to me as if tmprint.red can generate either \int or \Int
		// and maybe it expects one to be smaller than the other...???
		new Token("Int",              TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5a, null, null),
		new Token("smalloint",        TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x48, null, null),
		new Token("oint",             TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x49, null, null),
		new Token("smallbigcup",      TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x53, null, null),
		new Token("nigcup",           TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5b, null, null),
		new Token("smallbigcap",      TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x54, null, null),
		new Token("bigcap",           TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5c, null, null),
		new Token("smallbiguplus",    TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x55, null, null),
		new Token("biguplus",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5d, null, null),
		new Token("smallbigodot",     TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4a, null, null),
		new Token("bigodot",          TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4b, null, null),
		new Token("smallbigotimes",   TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4e, null, null),
		new Token("bigotimes",        TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4f, null, null),
		new Token("smallbigoplus",    TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4c, null, null),
		new Token("bigoplus",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x4d, null, null),
		new Token("smallbigsqcup",    TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x46, null, null),
		new Token("bigsqcup",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x47, null, null),
		new Token("smallbigwedge",    TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x56, null, null),
		new Token("bigwedge",         TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5e, null, null),
		new Token("smallbigvee",      TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x57, null, null),
		new Token("bigvee",           TokenType.TeXVSymbol, LexFont.TeXtension, (char)0x5f, null, null),
		// end of variable sized things
		new Token("setminus",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6e, null, null),
		new Token("wr",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6f, null, null),
		new Token("diamond",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x05, null, null),
		new Token("bigtriangleup",    TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x35, null, null),
		new Token("bigtriangledown",  TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x36, null, null),
		new Token("triangleleft",     TokenType.TeXSymbol, LexFont.FntItalic, (char)0x2f, null, null),
		new Token("triangleright",    TokenType.TeXSymbol, LexFont.FntItalic, (char)0x2e, null, null),
		//  {"lhd",              KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x43
		//  {"rhd",              KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x42
		//  {"unlhd",            KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x45
		//  {"unrhd",            KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x44
		new Token("oplus",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x08, null, null),
		new Token("ominus",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x09, null, null),
		new Token("otimes",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0a, null, null),
		new Token("oslash",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0b, null, null),
		new Token("odot",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0c, null, null),
		new Token("bigcirc",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x0d, null, null),
		new Token("dagger",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x79, null, null),
		new Token("ddagger",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x7a, null, null),
		new Token("amalg",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x71, null, null),
		new Token("leq",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x14, null, null),
		new Token("prec",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1e, null, null),
		new Token("preceq",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x16, null, null),
		new Token("ll",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1c, null, null),
		new Token("subset",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1a, null, null),
		new Token("subseteq",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x12, null, null),
		//  {"sqsubset",         KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // lasy (char)0x3c
		new Token("sqsubseteq",       TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x75, null, null),
		new Token("in",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x32, null, null),
		new Token("vdash",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x60, null, null),
		new Token("geq",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x15, null, null),
		new Token("succ",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1f, null, null),
		new Token("succeq",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x17, null, null),
		new Token("gg",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1d, null, null),
		new Token("supset",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x1b, null, null),
		new Token("supseteq",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x13, null, null),
		//  {"sqsupset",         KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // lasy (char)0x3d
		new Token("sqsupseteq",       TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x77, null, null),
		new Token("ni",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x33, null, null),
		new Token("dashv",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x61, null, null),
		new Token("equiv",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x11, null, null),
		new Token("sim",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x18, null, null),
		new Token("simeq",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x27, null, null),
		new Token("asymp",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x10, null, null),
		new Token("approx",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x19, null, null),
		new Token("cong",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msbm (char)0x74
		//  {"doteq",            KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"propto",           KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x2f, null, null),
		new Token("models",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x0f
		//  {"perp",             KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x3f, null, null),
		new Token("mid",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6a, null, null),
		new Token("parallel",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6b, null, null),
		//  {"bowtie",           KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // lasy (char)0x31
		//  {"join",             KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		new Token("smile",            TokenType.TeXSymbol, LexFont.FntItalic, (char)0x5e, null, null),
		new Token("frown",            TokenType.TeXSymbol, LexFont.FntItalic, (char)0x5f, null, null),
		new Token("leftarrow",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x20, null, null),
		new Token("Leftarrow",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x28, null, null),
		new Token("rightarrow",       TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x21, null, null),
		new Token("Rightarrow",       TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x29, null, null),
		new Token("leftrightarrow",   TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x24, null, null),
		new Token("Leftrightarrow",   TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x2c, null, null),
		//  {"mapsto",           KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?msam (char)0x110
		//  {"hookleftarrow",    KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"leftharpoonup",    KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // euex (char)0x18
		//  {"leftharpoondown",  KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // euex (char)0x19
		//  {"rightleftharpoons",KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"longmapsto",       KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"hookrightarrow",   KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"rightharpoonup",   KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // euex (char)0x1a
		//  {"rightharpoondown", KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // euex (char)0x1b
		//  {"leadsto",          KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // lasy (char)0x3a
		new Token("uparrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x22, null, null),
		new Token("Uparrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x2a, null, null),
		new Token("downarrow",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x23, null, null),
		new Token("Downarrow",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x2b, null, null),
		new Token("updownarrow",      TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6c, null, null),
		new Token("Updownarrow",      TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6d, null, null),
		new Token("nearrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x25, null, null),
		new Token("searrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x26, null, null),
		new Token("swarrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x2e, null, null),
		new Token("nwarrow",          TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x2d, null, null),
		new Token("aleph",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x40, null, null),
		//  {"hbar",             KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msbm (char)0x7e
		new Token("imath",            TokenType.TeXSymbol, LexFont.FntItalic, (char)0x7b, null, null),
		new Token("jmath",            TokenType.TeXSymbol, LexFont.FntItalic, (char)0x7c, null, null),
		//  {"ell",              KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // ?
		//  {"wp",               KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // eufb (char)0x50
		new Token("Re",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3c, null, null),
		new Token("Im",               TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3d, null, null),
		//  {"mho",              KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // lasy (char)0x30
		new Token("prime",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x30, null, null),
		new Token("emptyset",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3b, null, null),
		new Token("nabla",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x35, null, null),
		new Token("surd",             TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x72, null, null),
		new Token("top",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3e, null, null),
		new Token("bot",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3f, null, null),
		new Token("|",                TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6b, null, null),
		//  {"angle",            KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x5c
		new Token("forall",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x38, null, null),
		new Token("exists",           TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x39, null, null),
		new Token("neg",              TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x3a, null, null),
		new Token("flat",             TokenType.TeXSymbol, LexFont.FntItalic, (char)0x5d, null, null),
		new Token("natural",          TokenType.TeXSymbol, LexFont.FntItalic, (char)0x5c, null, null),
		new Token("sharp",            TokenType.TeXSymbol, LexFont.FntItalic, (char)0x5b, null, null),
		new Token("backslash",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6e, null, null),
		new Token("KeywordType.TeXtbackslash",    TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x6e, null, null),
		new Token("KeywordType.TeXtasciicircum",  TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x5e, null, null),
		new Token("KeywordType.TeXtasciitilde",   TokenType.TeXSymbol, LexFont.FntRoman,  (char)0x7e, null, null),
		new Token("partial",          TokenType.TeXSymbol, LexFont.FntItalic, (char)0x40, null, null),
		new Token("infty",            TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x31, null, null),
		//  {"Box",              KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x04
		//  {"Diamond",          KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x07
		//  {"Triangle",         KeywordType.TeXSymbol, LexFont.FntSymbol, (char)0x00, null, null),  // msam (char)0x4d
		new Token("clubsuit",         TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x7c, null, null),
		new Token("diamondsuit",      TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x7d, null, null),
		new Token("heartsuit",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x7e, null, null),
		new Token("spadesuit",        TokenType.TeXSymbol, LexFont.FntSymbol, (char)0x7f, null, null),

		//
		// Things to be rendered in Roman since they are function names

		new Token("arccos",     TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "arccos"; } }),
		new Token("arcsin",     TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "arcsin"; } }),
		new Token("arctan",     TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "arctan"; } }),
		new Token("arg",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "arg"; } }),
		new Token("cos",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "cos"; } }),
		new Token("cosh",       TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "cosh"; } }),
		new Token("cot",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "cot"; } }),
		new Token("coth",       TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "coth"; } }),
		new Token("csc",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "csc"; } }),
		new Token("deg",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "deg"; } }),
		new Token("det",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "det"; } }),
		new Token("dim",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "dim"; } }),
		new Token("exp",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "exp"; } }),
		new Token("gcd",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "gcd"; } }),
		new Token("hom",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "hom"; } }),
		new Token("inf",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "inf"; } }),
		new Token("ker",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "ker"; } }),
		new Token("lg",         TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "lg"; } }),
		new Token("lim",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "lim"; } }),
		new Token("liminf",     TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "liminf"; } }),
		new Token("limsup",     TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "limsup"; } }),
		new Token("ln",         TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "ln"; } }),
		new Token("log",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "log"; } }),
		new Token("max",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "max"; } }),
		new Token("min",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "min"; } }),
		new Token("Pr",         TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "Pr"; } }),
		new Token("sec",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "sec"; } }),
		new Token("sin",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "sin"; } }),
		new Token("sinh",       TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "sinh"; } }),
		new Token("sup",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "sup"; } }),
		new Token("tan",        TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "tan"; } }),
		new Token("tanh",       TokenType.TeXRoman,  LexFont.zero,   (char)-0x01,    Do.same, new StringFunction() { public String execute() { return "tanh"; } }),


		//
		// KeywordType.TeX things that take do not take an argument, as in
		//	              \word
		// eg \displaystyle

		new Token("displaystyle", TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    Do.doDisplayStyle, new KeywordHandlerFunction() { public Box execute(int i) { return doDisplayStyle(i); } }),
		// I only intend (at least to start with!) to support the \large
		// directive in the conKeywordType.TeXt of \stackrel{\large A}{B} where it defeats
		// the way that stackrel would otherwise shrink its first argument.
		new Token("large",        TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    Do.doLarge, new KeywordHandlerFunction() { public Box execute(int i) { return doLarge(i); } }),
		// \neq seems to be a unique horrid case for me. I can not see a glyph for
		// it in the Computer Modern set and so will end up synthesizing it as
		// an overstrike of "=" and "/".
		new Token("neq",          TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    Do.doNeq, new KeywordHandlerFunction() { public Box execute(int i) { return doNeq(i); } }),
		new Token("not",          TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    Do.doNot, new KeywordHandlerFunction() { public Box execute(int i) { return doNot(i); } }),

		// The next two are needed for matrix layout. Maybe and with luck they
		// will not occur freestanding.
		new Token("&",            TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    null, null),
		new Token("\\\\",         TokenType.TeX0Arg, LexFont.zero,    (char)-0x01,    null, null),
		// The next bunch insert spacing manually
		new Token("\\*",          TokenType.TeX0Arg, LexFont.zero, '*',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\ ",          TokenType.TeX0Arg, LexFont.zero, ' ',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\,",          TokenType.TeX0Arg, LexFont.zero, ',',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\!",          TokenType.TeX0Arg, LexFont.zero, '!',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\:",          TokenType.TeX0Arg, LexFont.zero, ':',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\;",          TokenType.TeX0Arg, LexFont.zero, ';',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),
		new Token("\\_",          TokenType.TeX0Arg, LexFont.zero, '_',  Do.doSpaceCommand, new KeywordHandlerFunction() { public Box execute(int i) { return doSpaceCommand(i); } }),

		//	#define pack4ints(a,b,c,d) (((a)<<24) + ((b)<<16) + ((c)<<8) + (d))
		//
		//	    new Keyword("longleftarrow",      KeywordType.TeX0Arg, LexFont.zero,
		//	                           pack4ints(FntSymbol, (char)0x20, FntSymbol, (char)0x0null, null), 
		//	                           Do.doAdjacent),
		//	    new Keyword("Longleftarrow",      KeywordType.TeX0Arg, 0,
		//	                           pack4ints(FntSymbol, (char)0x28, FntRoman, (char)0x3d),
		//	                           Do.doAdjacent),
		//	    new Keyword("longrightarrow",     KeywordType.TeX0Arg, 0,
		//	                           pack4ints(FntSymbol, (char)0x00, FntSymbol, (char)0x21), 
		//	                           Do.doAdjacent),
		//	    new Keyword("Longrightarrow",     KeywordType.TeX0Arg, 0,
		//	                           pack4ints(FntRoman, (char)0x3d, FntSymbol, (char)0x29), 
		//	                           Do.doAdjacent),
		//	    new Keyword("longleftrightarrow", KeywordType.TeX0Arg, 0,
		//	                           pack4ints(FntSymbol, (char)0x20, FntSymbol, (char)0x21), 
		//	                           Do.doAdjacent),
		//	    new Keyword("Longleftrightarrow", KeywordType.TeX0Arg, 0,
		//	                           pack4ints(FntSymbol, (char)0x28, FntSymbol, (char)0x29), 
		//	                           Do.doAdjacent),


		//
		// KeywordType.TeX things that take one argument, as in
		//	              \word {arg}
		// eg \pmod{whatever}

		new Token("pmod",       TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doPmod, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doPmod(b1,b2); } }),
		new Token("mathrm",     TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doMathRm, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doMathRm(b1,b2); } }),
		new Token("mathit",     TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doMathIt, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doMathIt(b1,b2); } }),
		new Token("sqrt",       TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doSqrt, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doSqrt(b1,b2); } }),
		new Token("fbox",       TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doFbox, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doFbox(b1,b2); } }),
		new Token("symb",       TokenType.TeX1Arg,   LexFont.zero,    (char)-0x01,    Do.doSymb, new OneArgHandlerFunction() { public Box execute(Box b1, Box b2) { return doSymb(b1,b2); } }),
		//
		// KeywordType.TeX things that take two arguments, as in
		//	              \word {arg1} {arg2}
		// eg \frac{numerator}{denominator}
		// Note that both frac and stackrel both make adjustments to the
		// size of the naterial set as their arguments... but in eccentric
		// and one-off ways!
		new Token("frac",       TokenType.TeX2Arg,   LexFont.forwardSlash,       (char)-0x01,    Do.doFrac, new TwoArgsHandlerFunction() { public Box execute(Box b1, Box b2) { return doFrac(b1,b2); } }),
		new Token("stackrel",   TokenType.TeX2Arg,   LexFont.capitalS,       (char)-0x01,    Do.doStackrel, new TwoArgsHandlerFunction() { public Box execute(Box b1, Box b2) { return doStackrel(b1,b2); } }),

		new Token("rule",       TokenType.TeXRule,   LexFont.zero,         (char)-0x01,    null, null),
		new Token("NULL",         null,         null,         (char)-0x01,    null, null)

	}; 

	private static Box doLeftRight(char c, int i, Box b) {
		if(b == null) return null;
		switch(i) {
		case '(' : return new DelimiterBox(b, Delimiters.paren);
		case '[' : return new DelimiterBox(b, Delimiters.square);
		case '{' : return new DelimiterBox(b, Delimiters.curly);
		case '|' : return new DelimiterBox(b, Delimiters.abs);
		
		default : return new DelimiterBox(b, Delimiters.paren);
		}
	}

	protected static Box doStackrel(Box b1, Box b2) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doFrac(Box b1, Box b2) {
		if(b1 == null) return b2;
		else if(b2 == null) return b1;
		else return new FractionBox(b1, b2);
	}


	protected static Box doSymb(Box b, Box opt) {
		if(b == null) return null;
		else return b; // TODO
	}


	protected static Box doFbox(Box b1, Box b2) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doSqrt(Box b, Box opt) {
	    if (b == null) return null;
	    if(opt == null) {
	    	Box r = new SqrtBox(b);
	    	// TODO
	    	return r;
	    } else {
	    	Box r = new ScriptBox(new DelimiterBox(b,Delimiters.paren), new FractionBox(new SymbolBox("1"), opt));
	    	return r;
	    }
	}


	protected static Box doMathIt(Box b1, Box b2) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doMathRm(Box b, Box b2) {
		if(b == null) return null;
		// return new SymbolBox(b.toString());
		if(b instanceof SymbolBox) 
			return new SymbolBox(b.toString()); // default is CMR font
		
		else return b; // TODO
	}


	protected static Box doPmod(Box b1, Box b2) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doSpaceCommand(int w) {
	    switch (w)
	    {
			default:
			case ' ': return new SpaceBox(Space.space); 
			case '*': return new SpaceBox(Space.asterisk); 
			case ',': return new SpaceBox(Space.comma); 
			case '!': return new SpaceBox(Space.exclamation);  
			case ':': return new SpaceBox(Space.colon); 
			case ';': return new SpaceBox(Space.semicolon); 
			//case '_': return new SpaceBox(Space.);  
	    }
	}


	protected static Box doNot(int i) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doNeq(int i) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doLarge(int i) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doDisplayStyle(int i) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doDollar(char c, int i, Box b) {
		// TODO Auto-generated method stub
		return null;
	}


	protected static Box doMathBrace(char c, int i, Box b) {
		// TODO Auto-generated method stub
		return b;
	}

	
	
	
	static {
		rehashKeywordTable();
	}

}
