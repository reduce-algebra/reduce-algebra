package uk.ac.cam.aa582.structures.boxes;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * 0, 2, 514, 3.4, x, y, g, sin, ln 
 * are all SymbolBoxes.
 * 
 * @author Ahmad Akra
 *
 */
public class SymbolBox extends Box {

	protected String symbol = "";
	
	public SymbolBox(String symbol) {
		this(symbol, null);
	}
	
	public SymbolBox(String symbol, Font f) {
		
		if(f != null) font = f;
		
		
		if(symbol != null)
			this.symbol = symbol.trim().replaceAll("\\s", "_"); // no spaces allowed in a symbol
	}
	
	public SymbolBox(short s) {
	
		font = S.font(s);
		
		char symbol = S.symbol(s);
		this.symbol = symbol+"";
	}
	
	public String getSymbol() {
		return symbol;
	}


	@Override
	public Iterator<Box> iterator() {
		// a symbol does not contain any sub expressions
		return new LinkedList<Box>().iterator(); 
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;
		width = graphics.advancingWidth(symbol, font, fontNumber, fontSize());
//		if(width > 20000) {
//			Log.d("Symbol Value", "\"" + symbol+"\"");
//			Log.d("Symbol Width", width+"");
//		}
		return width;
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		
	//	if(symbol.equals("")) return 1.0f;
		else return height = graphics.boundingHeight(symbol, font, fontNumber, fontSize());
	}
	
	@Override
	public float axis() { // fixed
		if(optimize && axis >= 0) return axis;
		
		return axis = graphics.baseline(symbol, font, fontNumber, fontSize()) - (C.baseline_axis_distance_factor * this.fontSize());
	}

	@Override
	protected void eraseMemory() {
		
	}

	@Override
	public void onDraw() {
		graphics.setOrigin(xOrigin(), yOrigin()); // set the origin of the drawing
		graphics.drawString(symbol, font, fontNumber, fontSize(), 0f, 0f);
	}



	@Override
	public void setChildrenStyle() {
		// no children, nothing to do (no pun implied!)
	}
	
	@Override
	protected float superscriptShift(){

		if(font == Font.cmmi) {
			char lastChar = symbol.charAt(symbol.length()-1);
			Float shift = superscriptShifts.get(lastChar);
			if(shift != null) 
				return shift.floatValue();
		}
		// if(symbol.charAt(symbol.length()-1) == 'f' && font == Font.cmmi) return -0.0694f * fontSize();
		
		return 0f;
	}
	@Override
	protected float subscriptShift(){
		// if((symbol.charAt(symbol.length()-1) == 'f') && font == Font.cmmi) return 0.0556f * fontSize();	

		if(font == Font.cmmi) {
			char lastChar = symbol.charAt(symbol.length()-1);
			Float shift = subscriptShifts.get(lastChar);
			if(shift != null) // so a value does exist
				return shift.floatValue();
		}
		
		return 0f;
	}

	static Hashtable<Character,Float> superscriptShifts = new Hashtable<Character,Float>();
	static Hashtable<Character,Float> subscriptShifts = new Hashtable<Character,Float>();
	
	static {
		
		// This place should list all characters and specify superscript and subscript shifts for every one.
		// I was just too lazy to do it myself. I only did for 'f' as an illustration.
		superscriptShifts.put('f',-0.0694f);
		
		//
		subscriptShifts.put('f', 0.0556f);
	}

	@Override
	public float getSquashingDistance() {
		return 0;
	}

	@Override
	public Box squash(float factor) {
		// Can't squeeze a symbol 	
		return this;
	}

	@Override
	public Box[] split(Level level) {
		return new Box[] { this };
	}
	
	@Override
	public Box setGraphics(Graphics g) {
		if(this.handler != null)
			g.setOnTouchHandler(this);
		return super.setGraphics(g);
	}
	
	@Override
	public Box registerTouchHandler(OnTouchHandler<Object> handler, Object arg)  {
		this.handler = handler;
		this.onTouchArg = arg;
		if(graphics != null) graphics.setOnTouchHandler(this);
		return this;
	}
	
	@Override
	public String toString() {
		return this.symbol;
	}
}
