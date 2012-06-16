package uk.ac.cam.aa582.structures.boxes;

/**
 * {@link Box}es use this interface to draw chars and lines on the screen. It contains all 
 * the functionality needed for that. The implementation of this interface typically 
 * calls in turn some graphics library such as Android graphics library of Java Swing,
 * The developer may wish to have a separate implementation of this interface for unit testing.
 * <br/><br/>
 * The Graphics object origin point for all the coordinates by default is (0,0) at the upper left corner. But
 * the origin can be any (x,y) point <u>relative</u> to the origin of another Graphics object, setting a different
 * origin then the default one is the function of {@link Graphics#drawGraphics(Graphics, float, float, float, float)}
 * <br/><br/>
 * Once this interface is implemented by a class e.g. MyGraphics, this is how the fraction 1/2
 * can be drawn using the functions in the implementation 
 * <br/><br/>
 * 
 * <tt>
 * Box formula = new FractionBox(new SymbolBox("1"), new SymbolBox("2")); <br/>
 * MyGraphics g = new MyGraphics(); <br/>
 * formula.setGraphics(g); <br/> 
 * formula.onDraw(); <br/><br/>
 * </tt>
 * 
 * 
 * @author Ahmad Akra
 *
 */
public interface Graphics {

	/**
	 * Draws a line on the screen between (StartX,StartY) and
	 * (StopX,StopY) relative to the origin.
	 * 
	 * @param lineThickness The line thickness
	 * @param startX x-coordinate of the starting point
	 * @param startY y-coordinate of the starting point
	 * @param stopX x-coordinate of the stopping point
	 * @param stopY y-coordinate of the stopping point
	 */
	void drawLine(float lineThickness, float startX, float startY, float stopX, float stopY);
	
	/**
	 * Draws a line on the screen between (StartX,StartY) and
	 * (StopX,StopY) relative to the origin.
	 * 
	 * @param lineThickness The line thickness
	 * @param startX x-coordinate of the starting point
	 * @param startY y-coordinate of the starting point
	 * @param stopX x-coordinate of the stopping point
	 * @param stopY y-coordinate of the stopping point
	 * @param color specifies the color of the line
	 */
	void drawLine(float lineThickness, float startX, float startY, float stopX, float stopY, int color);
	
	/**
	 * Draws the specified character in the current font on the screen.
	 * 
	 * @param c the char to be drawn
	 * @param startX x-coordinates of the upper left corner of the drawn char
	 * @param startY y-coordinates of the upper left corner of the drawn char
	 */
	void drawChar(char c, Font font, int fontNumber, float fontSize, float startX, float startY);
	
	/**
	 * Draws the specified string in the current font on the screen.
	 * 
	 * @param c the string to be drawn
	 * @param startX x-coordinates of the upper left corner of the drawn string
	 * @param startY y-coordinates of the upper left corner of the drawn string
	 */
	void drawString(String s, Font font, int fontNumber, float fontSize, float startX, float startY);
	
	/**
	 * Measures the advancing width of the char in the current font, which is the 
	 * width that the char would occupy when drawn in between other chars in a word. <br/>
	 * For example in monospace fonts, all chars have the same advancing width.
	 * 
	 * @param c The char to be measured
	 * @return The advancing width of the char
	 */
	float advancingWidth(char c, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the bounding height of the char, this is the minimum height that would
	 * encompass the char completely, for example 'f' has a larger bounding height than 'x'.
	 * 
	 * @param c The char to be measured
	 * @return The bounding height of the char
	 */
	float boundingHeight(char c, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the baseline height of the char, the baseline height of a char is the distance 
	 * from the highest point in the char to the baseline. Which is the line over which the letters
	 * rest, letter 'a' for example just touches that line while the tail of 'y' goes underneath it.
	 * 
	 * @param c The char to be measured
	 * @return The baseline height of the char
	 */
	float baseline(char c, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the bounding width of the char, this is the minimum width that would
	 * encompass the char completely, for example 'w' has a larger bounding width than 'v',
	 * even in monospace fonts.
	 * 
	 * @param c The char to be measured
	 * @return The bounding width of the char
	 */
	float boundingWidth(char c, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the advancing width of the string in the current font, which is the 
	 * width that the string would occupy when drawn amongst a larger string.
	 * 
	 * @param c The string to be measured
	 * @return The advancing width of the string
	 */
	float advancingWidth(String s, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the bounding height of the string, this is the minimum height that would
	 * encompass the string completely, for example "fry" has a larger bounding height than "was".
	 * 
	 * @param c The string to be measured
	 * @return The bounding height of the string
	 */
	float boundingHeight(String s, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the baseline height of the string, the baseline height of a string is the distance 
	 * from the highest point in the char to the baseline. Which is the line over which the letters
	 * rest, letter 'a' for example touches the baseline while 'y' has a tale that goes underneath it.
	 * 
	 * @param s The string to be measured
	 * @return The baseline height of the string
	 */
	float baseline(String s, Font font, int fontNumber, float fontSize);
	
	/**
	 * Measures the bounding width of the string, this is the minimum width that would
	 * encompass the string completely, for example 'www' has a slightly larger bounding width than 'vvv',
	 * even in monospace fonts.
	 * 
	 * @param s The string to be measured
	 * @return The bounding width of the string
	 */
	float boundingWidth(String s, Font font, int fontNumber, float fontSize);
	
//	/**
//	 * Sets the current font to (font)(number).ttf <br/>
//	 * For example, setFont(Font.cmmi, 7) would set the current font
//	 * to cmmi7.ttf <br/>
//	 * <u>Contract</u>: number can only be 5,7 or 10
//	 * 
//	 * @param font The enum representation of the font to use
//	 * @param number The number of the font file, can only be 5,7 or 10.
//	 */
//	void setFont(Font font, int number);
//	
//	/**
//	 * Sets the current font size to the value given
//	 * 
//	 * @param fontSize The new font size
//	 */
//	void setFontSize(float fontSize);
//	
//	/**
//	 * Sets the background color of the Graphics object between the origin
//	 * and (+infinity,+infinity) to the color specified.
//	 * 
//	 * @param color The new background color, comes in the format: <tt> 0xAARRGGBB </tt>
//	 */
//	void setBackgroundColor(int color);
//	
//	/**
//	 * Sets the current drawing color to the value specified, for example
//	 * calling; <br/><br/> <tt>
//	 * Graphics g = new MyGraphics(); <br/>
//	 * g.setDrawingColor(0xFF000000); <br/>
//	 * g.drawChar('A',0.0f,0.0f); <br/>
//	 * g.setDrawingColor(0xFFFF0000); <br/>
//	 * g.drawLine(3,0f,0.0f,0.0f,15.0f,15.0f); <br/>
//	 * </tt><br/><br/>
//	 * Should draw a black 'A' and a red line.
//	 * 
//	 * @param color The new drawing color, comes in the format: <tt> 0xAARRGGBB </tt>
//	 */
//	void setDrawingColor(int color);
	
	/**
	 * 
	 * @return A new object that implements {@link Graphics}
	 */
	Graphics newGraphics();
	
	/**
	 * 
	 * @return the same graphics object
	 */
	Graphics sameGraphics();
	
	/**
	 * OnDrawListener is an event handler, meant to listen for the suitable
	 * time to start drawing things using this interface. This method
	 * stores the given OnDrawListener in the Graphics object, on the hope that
	 * the Graphics object will notify it when the time for drawing has come
	 * (e.g. when the app has loaded for example)<br/>
	 * OnDrawListener.onDraw() is the method to use for notifying the OnDrawListener object. 
	 * 
	 * @param p The Painter object to register
	 */
	void setOnDrawListener(OnDrawListener p);
	
	/**
	 * OnTouchHandler is an event handler, which should be notified for touch events from the user.
	 * When the user touches the screen area assigned to this Graphics object, the implementation
	 * should call in {@link OnTouchHandler#onTouch()}, if such a handler has been registered in the Graphics object
	 * using this method
	 * 
	 * @param h The handler to store in the Graphics object and notify for touch events
	 */
	void setOnTouchHandler(OnTouchHandler<Graphics> h);
	
	/**
	 * Assigns a new area of the screen to the given Graphics object which has an origin
	 * at (x,y) <u> relative </u> to the origin of callee Graphics object.
	 * 
	 * @param g The given graphics object
	 * @param x x-coordinates of g's new origin relative to the callee's origin
	 * @param y y-coordinates of g's new origin relative to the callee's origin
	 * @param w The width of the area to be assigned to g, if g wants to go beyond w, the rest could be cut away (up to implementer)
	 * @param h The height of the area to be assigned to g, if g wants to go beyond w, the rest could be cut away (up to implementer)
	 */
	void drawGraphics(Graphics g, float x, float y, float w, float h);
	
	/**
	 * Asks the Graphics object to erase everything drawn so far and draw everything
	 * all over again (by notifying the stored Painter object)
	 */
	void invalidate();

	/**
	 * Draw a vertical pointer (could be blinking or of any shape or color)
	 * centered at (x,baseline) and the height of the pointer
	 * chosen suitably to go nicely with the font size
	 * 
	 * @param x
	 * @param baseline
	 * @param fontSize
	 */
	void drawVisualPointer(float x, float baseline, float fontSize);
	
	/**
	 * Sets the new origin of the graphics object, any subsequent
	 * call to one of the draw methods, and everything drawn will
	 * be positioned relative to that origin
	 * 	
	 * @param x coordinate of the new origin
	 * @param y coordinate of the new origin
	 * @return the same Graphics object for convenience
	 */
	Graphics setOrigin(float x, float y);


}
