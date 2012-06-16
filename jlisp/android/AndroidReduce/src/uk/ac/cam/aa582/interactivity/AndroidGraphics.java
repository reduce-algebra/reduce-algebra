package uk.ac.cam.aa582.interactivity;

import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.Font;
import uk.ac.cam.aa582.structures.boxes.Graphics;
import uk.ac.cam.aa582.structures.boxes.OnDrawListener;
import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;
import uk.ac.cam.aa582.structures.boxes.Timer;
import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.Typeface;
import android.view.MotionEvent;
import android.widget.RelativeLayout;

public class AndroidGraphics extends RelativeLayout implements Graphics {
	
	Paint paint = new Paint();
	Canvas canvas;
	LinkedList<OnDrawListener> listeners = new LinkedList<OnDrawListener>();
	LinkedList<OnTouchHandler<Graphics>> handlers = new LinkedList<OnTouchHandler<Graphics>>();

	public AndroidGraphics(Context context) {
		this(context, null, false);
	}
	public AndroidGraphics(Context context, Paint p) {
		this(context, p, false);
	}
	public AndroidGraphics(Context context, Paint p, boolean antiAlias) {
		super(context);
		if(p != null) this.paint = p;
		setWillNotDraw(false);
		paint.setAntiAlias(true);
		//this.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));		
	}
	
	@Override
	public void onDraw(Canvas c) {
		super.onDraw(c);
		
		Timer.start();
		
		canvas = c;
		for(OnDrawListener box : listeners){
			box.onDraw();
		//	box.onDrawBorders();
		}

		Timer.finish();
		
//		Log.d("Evaluation", "Start Time " + (start_time));
//		Log.d("Evaluation", "Finish Time " + (finish_time));
//		Log.d("Evaluation", "Difference " + (finish_time-start_time));
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		super.onTouchEvent(event);
		float x = event.getX();
		float y = event.getY();
		
		// This code finds the closest handler (the winner)
		// to touch point and notifies it.
		float minProximity = Float.POSITIVE_INFINITY;
		OnTouchHandler<Graphics> winner = null;
		
		for(OnTouchHandler<Graphics> handler : handlers) {
			float proximity = handler.proximity(x, y);
			
			if(proximity < minProximity) {
				winner = handler;
				minProximity = proximity;
			}
		}
		if(winner != null) winner.onTouch(this);
		
		return false;		
	}

	@Override
	public void drawLine(float lineThickness, float startX, float startY,
			float stopX, float stopY) {
		paint.setStrokeWidth(lineThickness);
		canvas.drawLine(x(startX), y(startY), x(stopX), y(stopY), paint);
	}
	
	@Override
	public void drawLine(float lineThickness, float startX, float startY,
			float stopX, float stopY, int color) {
		paint.setStrokeWidth(lineThickness);
		int originalColor = paint.getColor();
		paint.setColor(color);
		
		canvas.drawLine(x(startX), y(startY), x(stopX), y(stopY), paint);
		
		paint.setColor(originalColor);
	}

	private float y(float startY) {
		return startY + yOrigin;
	}
	private float x(float startX) {
		return startX + xOrigin;
	}
	
	@Override
	public void drawChar(char c, Font font, int fontNumber, float fontSize, float x, float y) {
		drawString(c+"", font, fontNumber, fontSize, x, y);
	}

	@Override
	public void drawString(String s, Font font, int fontNumber, float fontSize, float x, float y) {
		setFont(font, fontNumber);
		setFontSize(fontSize);
		canvas.drawText(s, x(x), y(y+baseline(s,font,fontNumber,fontSize)), paint);
	}

	@Override
	public float advancingWidth(char c, Font font, int fontNumber, float fontSize) {
		return advancingWidth(c+"", font, fontNumber, fontSize);
	}
	
	@Override
	public float advancingWidth(String s, Font font, int fontNumber, float fontSize) {
		float[] widthes = new float[s.length()];
		setFont(font, fontNumber);
		setFontSize(fontSize);
		paint.getTextWidths(s, widthes);
		return sum(widthes);
	}
	
	private float sum(float[] arr) {
		float result = 0f;
		for(int i=0; i<arr.length; i++)
			result += arr[i];
		
		return result;
	}

	@Override
	public float boundingHeight(char c, Font font, int fontNumber, float fontSize) {
		return boundingHeight(c+"", font, fontNumber, fontSize);
	}

	@Override
	public float baseline(char c, Font font, int fontNumber, float fontSize) {
		return baseline(c+"", font, fontNumber, fontSize);
	}

	@Override
	public float boundingWidth(char c, Font font, int fontNumber, float fontSize) {
		return boundingWidth(c+"", font, fontNumber, fontSize);
	}

	@Override
	public float boundingHeight(String s, Font font, int fontNumber, float fontSize) {
		if(s == null || s.length() == 0) return 1.0f;

		setFont(font, fontNumber);
		setFontSize(fontSize);
		Rect bounds = new Rect();
		paint.getTextBounds(s, 0, s.length(), bounds);
		return bounds.height();
	}

	@Override
	public float baseline(String s, Font font, int fontNumber, float fontSize) {
		if(s == null) s = "";	
		Rect bounds = new Rect();

		setFont(font, fontNumber);
		setFontSize(fontSize);
		paint.getTextBounds(s,0, s.length(), bounds);
		
		return -bounds.top;
	}
	
	@Override
	public float boundingWidth(String s, Font font, int fontNumber, float fontSize) {
		Rect bounds = new Rect();

		setFont(font, fontNumber);
		setFontSize(fontSize);
		paint.getTextBounds(s, 0, s.length(), bounds);
		return bounds.width();
	}

//	@Override
	public void setFont(Font font, int number) {
		Typeface tf = getCachedFontFile(font, number);
		paint.setTypeface(tf);
	}
	
//	@Override
	public void setFontSize(float fontSize) {
		paint.setTextSize(fontSize);
	}

	@Override
	public Graphics sameGraphics() {
		// AndroidGraphics result = new AndroidGraphics(getContext());
		return this;
	}
	
	@Override
	public Graphics newGraphics() {
		return new AndroidGraphics(getContext());
	}
	
	@Override
	public void drawGraphics(Graphics g, float x, float y, float w, float h) {
		AndroidGraphics toAdd = (AndroidGraphics) g;
		
		// TODO find out why this is needed, and rewrite it in a more professional way
		if(toAdd.getParent() != null) return; 
		
		RelativeLayout.LayoutParams params = 
				new RelativeLayout.LayoutParams((int) w, (int) h);
		
		params.leftMargin = (int)x(x);
		params.topMargin = (int)y(y);
		
		this.addView(toAdd, params);
	}

	@Override
	public void setOnDrawListener(OnDrawListener p) {
		if(p != null)
			listeners.add(p);		
	}

	@Override
	public void setOnTouchHandler(OnTouchHandler<Graphics> h) {
		if(h != null)
			handlers.add(h);		
	}
	
	
	private Typeface getCachedFontFile(Font font, int number) {
		if(font == Font.regular) 
			return Typeface.MONOSPACE;
		
		
		if(cmex == null) { // still not initialized
			AssetManager manager = getContext().getAssets();
			
			String dirName = "fonts/";
			cmr[0] = Typeface.createFromAsset(manager, dirName + "cmr10.ttf");
			cmr[1] = Typeface.createFromAsset(manager, dirName + "cmr7.ttf");
			cmr[2] = Typeface.createFromAsset(manager, dirName + "cmr5.ttf");

			cmmi[0] = Typeface.createFromAsset(manager, dirName + "cmmi10.ttf");
			cmmi[1] = Typeface.createFromAsset(manager, dirName + "cmmi7.ttf");
			cmmi[2] = Typeface.createFromAsset(manager, dirName + "cmmi5.ttf");

			cmsy[0] = Typeface.createFromAsset(manager, dirName + "cmsy10.ttf");
			cmsy[1] = Typeface.createFromAsset(manager, dirName + "cmsy7.ttf");
			cmsy[2] = Typeface.createFromAsset(manager, dirName + "cmsy5.ttf");

			cmex = Typeface.createFromAsset(manager, dirName + "cmex10.ttf");
		}

		switch(font){
		case cmr : {
			switch(number) {
			case 10: return cmr[0];
			case 7 : return cmr[1];
			case 5 : return cmr[2];
			}}
		case cmmi : {
			switch(number) {
			case 10: return cmmi[0];
			case 7 : return cmmi[1];
			case 5 : return cmmi[2];
			}}

		case cmsy : {
			switch(number) {
			case 10: return cmsy[0];
			case 7 : return cmsy[1];
			case 5 : return cmsy[2];
			}}
		case cmex : return cmex;
		}
		return null; // should not reach here
	}


	private static Typeface[] cmr = new Typeface[3];
	private static Typeface[] cmmi = new Typeface[3];
	private static Typeface[] cmsy = new Typeface[3];
	private static Typeface cmex;

//	@Override
	public void setDrawingColor(int color) {
		paint.setColor(color);
		
	}
	@Override
	public void drawVisualPointer(float x, float baseline, float fontSize) {
		int originalColor = paint.getColor();
		this.setDrawingColor(Color.RED);
		float halfPointer = fontSize/3;
		float pointerWidth = 3f;
		this.drawLine(pointerWidth, x+(pointerWidth/2), baseline - halfPointer, x+(pointerWidth/2), baseline + halfPointer);
		this.setDrawingColor(originalColor);
	}
	
	@Override
	public void onMeasure(int w, int h) {
		super.onMeasure(w, h);
		this.setMeasuredDimension(getMeasuredWidth(), getMeasuredHeight());
	}
	
	private float xOrigin = 0f;
	private float yOrigin = 0f;
	
	@Override
	public Graphics setOrigin(float x, float y) {
		xOrigin = x;
		yOrigin = y;
		return this;
	}
}
