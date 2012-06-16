package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;
import uk.ac.cam.aa582.structures.boxes.OperationBox;
import uk.ac.cam.aa582.structures.boxes.S;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox.Space;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;

/**
 * The smallest single unit of user input, many
 * buttons on the keyboard will be entering just
 * a single symbol, this can be a digit, a variable
 * name, the symbol can be multiple characters such
 * as "sin(", but in which case if the user hits
 * delete only once, all these characters disappear together
 * 
 * @author Ahmad Akra
 *
 */
public class Symbol extends Expression {
	
	/**
	 * The string inside this symbol, displayed in default CMR font
	 */
	String symbol = "";
	
	/**
	 * A single character, encoded in a short integer using the
	 * encoding rules in {@link S}, i.e. the short integer should
	 * encode the char in 0x00FF, and the font in 0x0F00. <br/>
	 * If this field is negative, it means that {@link Symbol#symbol}
	 * should be used on its own.
	 */
	short symbol2 = -1;
	
	/**
	 *  All touch events should be delegated to this object
	 */
	private OnTouchHandler<Object> touchHandler;
	
	/**
	 * Constructor, the symbol string will be empty 
	 */
	public Symbol() {}
	
	/**
	 * Constructor, the symbol shows the provided string in CMR font.
	 * @param s The provided string
	 */
	public Symbol(String s) { symbol = s; }
	
	/**
	 * Constructor, the symbol shows a single character in the font
	 * encoded by the given short integer. </br>
	 * The encoding should follow the guidelines set in {@link S}
	 * @param s The provided short integer
	 */
	public Symbol(short s) { symbol2 = s; symbol = S.text(s); };

	@Override
	protected String toReduce() {
		// The idea is that every symbol is translated to itself 
		// when turned to reduce, But...
		// Here is a list of exceptions, where the displayed symbol
		// is not the symbol that goes to reduce
		if(symbol.equalsIgnoreCase("ans"))
			// give me answer to the last input
			return "ws"; // + Reduce.getInputCount();
		if(symbol.equalsIgnoreCase("ln(")) // user
			return "log("; // reduce		
		if(symbol.equalsIgnoreCase("fact(")) // user
			return "factorial("; // reduce
		else return symbol;
	}
	
	
	

	@Override
	public Box toDrawable() {
		// This is not a very good code, but it works
		if(symbol.equals(":=") || symbol2 == S.equals)
			return new OperationBox(
					(SymbolBox) (symbol2 >=0? new SymbolBox(symbol2) : new SymbolBox(symbol)).registerTouchHandler(touchHandler, this),
					new SpaceBox(0,0),
					new SpaceBox(0,0));
		else if(symbol.equals(","))
			return new SequenceBox(new SymbolBox(symbol).registerTouchHandler(touchHandler, this), new SpaceBox(Space.comma /* narrow space */));
		else if(symbol2 >=0)
			return new SymbolBox(symbol2).registerTouchHandler(touchHandler, this);
		else 
			return new SymbolBox(symbol).registerTouchHandler(touchHandler, this);
	}
	
	/**
	 * Sets the touch handler which is notified by 
	 * {@link SymbolBox} about any touch events
	 */
	public void setTouchHandler(OnTouchHandler<Object> touchHandler) {
		this.touchHandler = touchHandler;
	}
	
	@Override
	public Symbol copy() {
		if(symbol2 >=0)
			return new Symbol(symbol2);
		else 
			return new Symbol(symbol);
	}
	
//	public boolean reduceTranslationBeginsWithLetter() {
////		if(symbol2 >= 0) {
////			Font f = S.font(symbol2);
////			return (f == Font.cmmi || f == Font.cmr) && symbol.matches("[a-zA-Z].*");
////		} else {
////			return symbol.matches("[a-zA-Z].*");
////		}
//		
//		return this.toReduce().matches("[a-zA-Z\\(].*");
//	}
//	
//	public boolean reduceTranslationEndsWithLetter() {
////		if(symbol2 >= 0) {
////			Font f = S.font(symbol2);
////			return (f == Font.cmmi || f == Font.cmr) && symbol.matches(".*[a-zA-Z]");
////		} else {
////			return symbol.matches(".*[a-zA-Z]");
////		}
//		
//		return this.toReduce().matches(".*[a-zA-Z\\)]");
//	}
	
	public boolean isDigit() {
		return symbol.matches("[0-9]+");
	}
}
