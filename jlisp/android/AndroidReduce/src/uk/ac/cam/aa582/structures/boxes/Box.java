package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * The base class for all the boxes, every formula can be defined as a large box
 * which recursively contains small sub-formulae or smaller boxes. The purpose of 
 * the boxes is to draw the formula on the screen. This idea is inspired from the 
 * TEX type-setting system. Notable subclasses include {@link SymbolBox}, 
 * {@link SequenceBox}, {@link FractionBox}, {@link ScriptBox}, {@link DelimiterBox}, {@link SqrtBox},
 * {@link OperationBox} and {@link RelationBox } <br/><br/>
 * 
 * Every Box should be able to calculate its {@link Box#width()}, {@link Box#height()} 
 * and {@link Box#axis()} based on the width, height and axis information provided by sub-boxes,
 * and a {@link Graphics} object which provides information about the dimensions
 * of chars and fonts. 
 * 
 * 
 * @author Ahmad Akra
 *
 */
public abstract class Box extends OnDrawListener implements OnTouchHandler<Graphics>, Iterable<Box>, BoxStateProvider {
	
	/**
	 * Many methods that calculate layouts values are parameterless.
	 * For example {@link Box#height()}.
	 * We can make the program run faster if we let every
	 * method "remember" the value it returns the first time it is called, 
	 * and the method can simply return the stored value every time it gets
	 * called subsequently. 
	 * This boolean fields determines whether or not this optimization
	 * should take effect.
	 */
	public static boolean optimize = true;
	
	/**
	 * Stores the box font size for the display/text TEX style
	 */
	private float display_font_size = C.default_font_size;
	
	public static TexStyle universalStyle = TexStyle.T;
	
	/**
	 * Stores the TEX style under which this box is drawn. See 
	 * {@link TexStyle} for an explanation of what that is
	 */
	protected TexStyle style = universalStyle;	// default style
	
	/**
	 * The x coordinates of the origin of the box. This value
	 * is 0 by default and is set by the parent of the box
	 * typically inside {@link Box#onDraw()}. The box can access
	 * this value through {@link Box#xOrigin()} and should use it
	 * as an origin when it draw itself and sets the origin for
	 * its children.
	 */
	private float x_origin = 0f;
	
	/**
	 * The x coordinates of the origin of the box. This value
	 * is 0 by default and is set by the parent of the box
	 * typically inside {@link Box#onDraw()}. The box can access
	 * this value through {@link Box#yOrigin()} and should use it
	 * as an origin when it draw itself and sets the origin for
	 * its children.
	 */
	private float y_origin = 0f;
	
	/**
	 * Stores which font is used by this box, there are only five
	 * different fonts: CMR, CMMI, CMEX, CMSY and regular.<br/>
	 * See {@link Font} for more detail
	 */
	protected Font font = Font.cmr;
	
	/**
	 * The same computer modern font usually comes in many
	 * different "numbers" that differ slightly in their 
	 * thickness, for example, cmr10 is like cmr5 except that 
	 * chars in the latter are a little "fatter" than in the former.<br/>
	 * TeX uses different font numbers for different styles,
	 * because for example, a style in which characters are
	 * small (like script style) would be associated with a lower
	 * number so that the characters are thicker and easier to see. <br/><br/>
	 * This field stores which font number is used by this box, the value
	 * this field is typically set in {@link Box#useFont(Font)}
	 */
	protected int fontNumber = 10;
	
	
	/**
	 * Stores the underlying graphics layer used by this
	 * object to draw things on the screen
	 */
	protected Graphics graphics;
	
	/**
	 * Stores the object that listens to touch event, this object
	 * is notified whenever the user touches the current box on
	 * the screen, this is set through 
	 * {@link Box#registerTouchHandler(OnTouchHandler, Object)}
	 */
	protected OnTouchHandler<Object> handler;
	
	/**
	 * This is simply the arguments that gets passed to 
	 * {@link OnTouchHandler#onTouch(Object)}, this is set through 
	 * {@link Box#registerTouchHandler(OnTouchHandler, Object)}
	 */
	protected Object onTouchArg;
	

	// the following fields are used for optimization, expensive methods
	// execute only once and store the result in these fields to return
	// them again later.
	/**
	 * Optimization field
	 */
	private float fontSize = -1;
	
	/**
	 * Optimization field
	 */
	protected float axis = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	protected float height = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	protected float width = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	private float depth = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	float lineThickness = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	private boolean styleIsCramped = false;
	
	/**
	 * Optimization field
	 */
	private boolean calledAlready = false;

	
	
	public float xOrigin() {
		return this.x_origin;
	}
	
	public float yOrigin() {
		return this.y_origin;
	}
	
	/**
	 * 
	 * Every box defines an axis point that aids in positioning
	 * the box correctly relative to the other boxes. The point
	 * lies at (0,a) relative to the top left corner of
	 * the box. a is called the "axis height" and is returned by 
	 * this method
	 * 
	 * <u>Contract</u>: {@link Box#setGraphics(Graphics)} should be called before 
	 * calling this method, otherwise a {@link NullReferenceException}
	 * may be thrown <br/><br/>
	 * 
	 * @return axis height of this box
	 */
	public abstract float axis();
	
	/**
	 * 
	 * The depth of the box is the distance between its axis point
	 * and its floor. See {@link Box#axis()} for definition of axis
	 * point. <br/>
	 * The depth value satisfies: depth = height - axis
	 * 
	 * <br/><br/>
	 * <u>Contract</u>: {@link Box#setGraphics(Graphics)} should be called before 
	 * calling this method, otherwise a NullReferenceException
	 * may be thrown
	 * 
	 * @return The depth of the box when drawn on the screen
	 */
	public float depth(){
		if(optimize && depth >= 0) return depth;
		return (depth = height() - axis());
	}
	
	/**
	 * Helper method, draws the given box starting at an upper left origin of (x,y)
	 * <u> Contract </u>: need to set the <@link Graphics/> object before calling
	 * this method
	 * 
	 * @param box The box to be drawn
	 * @param x x-coordinates of the origin of drawing
	 * @param y y-coordinates of the origin of drawing
	 */
	protected void drawBox(Box box, float x, float y) {
		box.x_origin = this.x_origin + x;
		box.y_origin = this.y_origin + y;
	}
	
	/**
	 * 
	 * @return The underlying graphics objects used by this box to render itself.
	 */
	public Graphics getGraphics(){
		return graphics;
	}
	
	/**
	 * <u>Contract</u>: {@link Box#setGraphics(Graphics)} should be called before 
	 * calling this method, otherwise a {@link NullPointerException}
	 * may be thrown
	 * 
	 * @return the height of the box when drawn on the screen
	 */
	public abstract float height();
	
	@Override
	public abstract Iterator<Box> iterator();
	
	/**
	 * Sets the object that should be notified about touch events 
	 * 
	 * @param handler the object to notify about touch events by calling {@link OnTouchHandler#onTouch(Object)}
	 * @param arg the arguments that is passed to {@link OnTouchHandler#onTouch(Object)}
	 * @return The same {@link Box} object for convenience
	 */
	public Box registerTouchHandler(OnTouchHandler<Object> handler, Object arg) {

		return this;
	}
	
	/**
	 * Changes the state of the box, by changing its font size,
	 * all the dimensions of the box increase or decrease in proportion with
	 * the new font size, even the small margins around operators
	 * and brackets
	 * 
	 * @param fs the new font size
	 */
	public void setFontSize(float fs) {
		this.display_font_size = fs;
		forget();
		for(Box box : this)
			box.setFontSize(fs);
	}
	
	/**
	 * Sets the underlying graphics layer for this Box and all its sub-boxes,
	 *  see {@link Graphics} for more information
	 *  
	 * @param g the graphics object to use as the underlying graphics layer
	 * @return the same box after the graphics has been set (for convenience)
	 */
	public Box setGraphics(Graphics g){
		if(g == null) return this;
		if(g == graphics) return this;
		graphics = g;
		
//		g.setFont(font, TexRules.selectFontNumber(font, style));
//		g.setFontSize(fontSize());
		g.setOnDrawListener(this);
//		g.setOnTouchHandler(this);
		
		for(Box box : this) {
			
			box.setGraphics(g.sameGraphics());

		}
		return this;
	}
	
	/**
	 * Breaks the Box at every point where it can be broken and
	 * returns the pieces in an array of Boxes.
	 * 
	 * @param level specifies which places to break the box at as follows: <br/>
	 *  - easy = break only at non delimited infix operators and relation signs <br/>
	 *  - medium = easy + break inside brackets and within the scope of large operators <br/>
	 *  - hard = medium + change fractions into slashes and remove the horizontal bars of square roots and break inside those <br/> 
	 *  - nightmare = hard + break around every symbol
	 *  
	 * @return the broken pieces in an array of Boxes.
	 */
	public abstract Box[] split(Level level);
	
//	/**
//	 * Breaks the box at every point where it can 
//	 * @return
//	 */
//	public abstract Box[] split2();
	
	/**
	 * 'Squashingng' a box is defined as either reducing or completely removing all the extra horizontal
	 * spaces that has been inserted for esthetic purposes.<br/>
	 * For example squashing (a + b - c) yields (a+b-c)
	 * 
	 * @param factor A float value in the range 0.0-1.0, which all the extra margins in this Box
	 * are multiplied by it. For complete removal of the margins pass 0.0, for no effect pass 1.0
	 * 
	 * @return A box that represents the original box except that it has been squashed, i.e. every 
	 * margin that existed in the original box has now been multiplied by the given factor
	 * 
	 */
	public abstract Box squash(float factor);
	
	/**
	 * 'Squashing' a box is defined as either reducing or completely removing all the extra horizontal
	 * spaces that has been inserted for esthetic purposes.<br/>
	 * For example squashing (a + b - c) yields (a+b-c)
	 * 
	 * @return the maximum distance that this box can 'squeeze' horizontally
	 */
	public abstract float getSquashingDistance();
	
	/**
	 * Set the current style of this Box to the given TEX style
	 * @param s the TexStyle to set this Box to
	 */
	public void setStyle(TexStyle s) {
		
		// don't do redundant work
		if(this.style == s) return;
		
		// set the current style
		this.style = s;
		
		// set the style of the children according the style rules
		setChildrenStyle();
		
		// delete all the values in the optimization fields
		forget();
	}
	
	public TexStyle getStyle() {
		return this.style;
	}
	
	
	/**
	 * @return True if the current TeX style belongs to one of the 4 cramped
	 * variants, or false otherwise. See {@link TexStyle} for more information
	 */
	public boolean styleIsCramped(){
		if(calledAlready) return styleIsCramped;
		calledAlready = true;
		return 	styleIsCramped = 
				this.style == TexStyle.DC 	||
				this.style == TexStyle.TC 	||
				this.style == TexStyle.SC 	||
				this.style == TexStyle.SSC;
	}
	
	/**
	 * <u>Contract</u>: {@link Box#setGraphics(Graphics)} should be called before 
	 * calling this method, otherwise a NullReferenceException
	 * may be thrown
	 * 
	 * @return the width of the box when drawn on the screen
	 */
	public abstract float width();
	
	/**
	 * Each formula is rendered in one of four styles
	 * (display, text, script, scriptscript), one of the main
	 * differences between these styles is the font size
	 * the field 'display_font_size' defines the font
	 * size when drawing in display and text style. the font size
	 * used for script and scriptscript is defined as a fraction
	 * (or scale) of the display/text font size and the
	 * purpose of this method is to tell you that scale.
	 * Hence if you pass TexStyle.D or TexStyle.T the method
	 * returns 1, otherwise it returns a float less than 1
	 * 
	 * @param s the text style (display, script, cramped script, etc...)
	 * @return the scale-down factor from display
	 */
	private float fontSizeScaleOf(TexStyle s) {
		switch(s) {
		case D : 			return C.text_font_scale;
		case DC : 			return C.text_font_scale;
		case T : 			return C.text_font_scale;
		case TC : 			return C.text_font_scale;
		case S : 			return C.script_font_scale;
		case SC : 			return C.script_font_scale;
		case SS : 			return C.scriptscript_font_scale;
		case SSC : 			return C.scriptscript_font_scale;
		default: return 100.0f;// shoud never reach here
		}
	}
	
	/**
	 * Deletes all optimization fields, and if a graphics object is available
	 * reinitializes it with the new values, and also invalidates its current
	 * rendering
	 */
	private void forget() {
		useFont(font);
		
		fontSize = Float.NEGATIVE_INFINITY;
		depth = Float.NEGATIVE_INFINITY;
		lineThickness = Float.NEGATIVE_INFINITY;
		width = Float.NEGATIVE_INFINITY;
		height = Float.NEGATIVE_INFINITY;
		axis = Float.NEGATIVE_INFINITY;

		if(graphics != null) {
//			graphics.setFontSize(fontSize());
			graphics.invalidate();
		}
		eraseMemory();
	}
	
	/**
	 * Deletes all the memory that remembers calculated values such as 
	 * width and height for optimization. This method is called when
	 * something changes that affects the outcome of the methods, and
	 * makes the stored values invalid. (e.g. {@link Box#setFontSize(float)}
	 */
	protected abstract void eraseMemory();
	
	/**
	 * Determines the font size that should be used base on
	 * the current display font size, the minimum font size
	 * and the current {@link TexStyle} of this {@link Box}
	 * @return
	 */
	protected float fontSize(){
		if(optimize && fontSize >= 0) return fontSize;
		return fontSize = Math.max(C.minimum_font_size, this.display_font_size * fontSizeScaleOf(this.style));
	}
	
	public float displayFontSize() {
		return this.display_font_size;
	}
	
	/**
	 * Serves as syntactic sugar, takes any number of box
	 * objects as arguments and returns an iterator that
	 * iterates over them. Used by subclasses which override
	 * the iterator() method
	 * 
	 * @param params all the boxes that need to be iterated
	 * @return an iterator over the given boxes
	 */
	protected static Iterator<Box> iteratorOver(Box... params){
		LinkedList<Box> boxes = new LinkedList<Box>();
		if(params == null) return boxes.iterator();
		for(int i=0; i<params.length; i++){
			boxes.add(params[i]);
		}
		return boxes.iterator();
	}
	
	/**
	 * Determines what the thickness of bars should be <u>display</u>
	 * style, bars include the {@link FractionBox} bar, {@link SqrtBox} 
	 * horizontal bar and the absolute value bars.
	 * @return
	 */
	protected float lineThickness() {
		if(optimize && lineThickness >= 0) return lineThickness;
		
		return lineThickness = Math.max(1, Math.max(C.minimum_font_size, this.display_font_size) * C.bar_thickness_factor);
	}
	
	/**
	 * Helper method which is useful for constructing towers of
	 * chars such as the extended square root or the extended
	 * delimiters.
	 * 
	 * @param b (float)
	 * @param a (float)
	 * @param m (float)
	 * @param h (float)
	 * @return the minimum integer n such that b+na+m > h
	 */
	protected static int minimumN(float b, float a, float m, float h) {
		int n = (int) Math.ceil((h-m-b)/a);
		return n;
	}
	
	/**
	 * Sets the style of the children of this box based on
	 * the current style of the box and the rules of TeX.
	 * Should be implemented by all sub-classes <br/>
	 * For example if this is a {@link FractionBox} and 
	 * the current style is text then
	 * the numerator is set to script and the denominator
	 * is set to cramped script 
	 */
	protected abstract void setChildrenStyle();
	
	/**
	 * If the current box has a subscript on its right, how
	 * much should the subscript be displaced to the left to
	 * make it look better? 
	 * @return how far should the subscript be displaced to the
	 * left
	 */
	protected float subscriptShift() {
		return 0f;
	}
	
	/**
	 * If the current box has a superscript on its right, how
	 * much should the superscript be displaced to the left to
	 * make it look better? 
	 * @return how far should the superscript be displaced to the
	 * left
	 */
	protected float superscriptShift() {
		return 0f;
	}
	
	/**
	 * Sets the current font of the Box to the specified
	 * {@link Font} and sets the underlying graphics object
	 * (if one exists) to the appropriate font and font number
	 * based on the current style.<br/><br/>
	 * For example if the given font is <i>cmsy</i> and the current 
	 * style is <i>script</i>, the graphics object (if exists) is
	 * set to the font <i>cmsy7</i>
	 *  
	 * @param font The specified font
	 */
	protected void useFont(Font font) {
		this.fontNumber  = TexRules.selectFontNumber(font, style);
		this.font = font;
	}
	
	/**
	 * Concatenates many arrays of boxes into a single array, 
	 * for example given {a}, {b,c} {d} {e,f,g}, it concatenates
	 * them into {a,b,c,d,e,f,g}
	 * 
	 * @param arrays the arrays to be concatenated
	 * @return all the provided arrays concatenated into a
	 * single array
	 */
	protected static Box[] concat(Box[]... arrays) {
		int totalLength = 0;
		for(Box[] array : arrays)
			totalLength += array.length;
		
		Box[] result = new Box[totalLength];
		int i = 0;
		for(Box[] array : arrays) {
			for(Box box : array) {
				result[i] = box;
				i++;
			}
		}
			
		return result;
	}

	/**
	 * 
	 * @return Whatever box is used by default instead of null
	 */
	protected static Box defaultBox(){
		return new SpaceBox();
	}
	
	@Override
	public void onTouch(Graphics g) {
		if(handler != null) handler.onTouch(onTouchArg);
	}
	
	//////////// Convenience methods /////////////
	/*
	 * The following methods constructs common expressions
	 * from existing Boxes (which are not defined as box class)
	 */

	// Legacy code, left here for compatibility reasons
	public static Box newMatrix(int rows, int cols, Box... boxes) {
		
		return new MatrixBox(rows, cols, boxes);

	}
	
	public static Box newAssignmentOperator(Box var, Box expression) {
		return new SequenceBox( 
				(var == null) ? defaultBox() : var, 
						new SymbolBox(":="),  
				(expression == null) ? defaultBox() : expression
			);
	}	
	
	@Override
	public float proximity(float x, float y) {
		float centerX = this.xOrigin() + (this.width()/2);
		float centerY = this.yOrigin() + (this.height()/2);
		
		return (centerY-y)*(centerY-y) + (centerX-x)*(centerX-x);
	}
	
	@Override
	public void onDrawBorders() {
		
		graphics.setOrigin(xOrigin(), yOrigin());
		
		// the borders
		float x1,x2,y1,y2;
		x1 = 0;
		y1 = 0;
		x2 = x1 + this.width()-1;
		y2 = y1 + this.height()-1;

		int red = 0x88AA3333;
		
		getGraphics().drawLine(2f, x1, y1, x2, y1, red);
		getGraphics().drawLine(2f, x1, y1, x1, y2, red);
		getGraphics().drawLine(2f, x2, y2, x2, y1, red);
		getGraphics().drawLine(2f, x2, y2, x1, y2, red);
		
		// the axis line
		int blue = 0x883333AA;
		getGraphics().drawLine(1f, x1, y1+this.axis(), x2, y1+this.axis(), blue);
		
	}
	
	
	public String toString() {
		String result = this.getClass().getSimpleName() + "[" + (graphics != null?this.width() : "") + "," + this.style +"](";
		for(Box child : this) {
			result += child.toString();
			result += ", ";
		}
		result += ")";
		return result;		
	}
	
	public Box setState(BoxStateProvider p) {
		this.setGraphics(p.getGraphics());
		this.setFontSize(p.displayFontSize());
		this.setStyle(p.getStyle());
		
		return this;
	}
}
