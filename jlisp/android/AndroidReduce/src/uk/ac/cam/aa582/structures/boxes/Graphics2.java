package uk.ac.cam.aa582.structures.boxes;

public interface Graphics2 {

	void drawLine(float lineThickness, float startX, float startY, float stopX, float stopY);
	

	void drawChar(char c, float startX, float startY);
	

	void drawString(String s, float startX, float startY);
	

	float advancingWidth(char c);
	

	float boundingHeight(char c);
	

	float baseline(char c);
	

	float boundingWidth(char c);
	

	float advancingWidth(String s);
	

	float boundingHeight(String s);
	

	float baseline(String s);
	

	float boundingWidth(String s);
	

	void setFont(Font font, int number);
	

	void setFontSize(float fontSize);
	

	void setBackgroundColor(int color);
	

	void setDrawingColor(int color);
	

	Graphics2 newGraphics();
	
	
	void setOnDrawListener(OnDrawListener p);
	

	void setOnTouchHandler(OnTouchHandler<Graphics> h);
	

	void drawGraphics(Graphics g, float x, float y, float w, float h);


	void invalidate();

	
	void drawVisualPointer(float x, float baseline);
}
