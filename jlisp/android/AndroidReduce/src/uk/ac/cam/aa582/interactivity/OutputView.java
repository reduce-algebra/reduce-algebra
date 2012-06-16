package uk.ac.cam.aa582.interactivity;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.BoxUtil;
import uk.ac.cam.aa582.structures.boxes.TexStyle;
import android.content.Context;
import android.graphics.Canvas;
import android.widget.RelativeLayout;

public class OutputView extends RelativeLayout {

	private static int lastId = 0;
	Box box;
	int topMargin;
	
	public OutputView(Context context, Box box, ScreenInfo screenInfo) {
		super(context);
		this.setId(lastId++);
//		TexParser p = new TexParser("\\left\\{x=\\frac{\\sqrt{-4\\*a\\*c+b^2}-b}{2\\*a}\\,\\mathrm{,\\,}\\,x=\\frac{-\\left(\\sqrt{-4\\*a\\*c+b^2}+b\\right)}{2\\*a}\\right\\}");
//		box = p.parse();
		
		this.box = box;

		this.setBackgroundColor(0x33FFFF66); // light yellow
//		this.setBackgroundColor(Color.LTGRAY); // light gray
		
		AndroidGraphics g = new AndroidGraphics(context);
		box.setStyle(TexStyle.D); // Display style
		box.setGraphics(g);

//		Log.d("Original Box Width",box.width()+"");
//		Log.d("Original Box Height",box.height()+"");
//		Log.d("Screen Width",screenInfo.screenWidth()+"");
//		Log.d("Original Box structure", box.toString());
		

		Box.universalStyle = TexStyle.D;
		box = BoxUtil.fitWithin(box, screenInfo.screenWidth());
		Box.universalStyle = TexStyle.T;

		g = new AndroidGraphics(context);
		box.setStyle(TexStyle.D);
		box.setGraphics(g);
		

//		Log.d("Broken Box",box.getClass().getSimpleName());
//		Log.d("Broken Box Width",box.width()+"");
//		Log.d("Broken Box Height",box.height()+"");
//		Log.d("Broken Box structure", box.toString());
//		
//		for(Box b : ((MultilineBox)((MultilineBox)((MultilineBox)box).boxes[1]).boxes[0]).boxes) {
//			Log.d("Element",b.getClass().getSimpleName());	
//			Log.d("Element Width",b.width()+"");	
//			Log.d("Element Height",b.height()+"");			
//		}
		
		int preferredHeight = 0;
		int m = 5;
		int actualHeight = Math.max(preferredHeight, (int) box.height()+2 + 2*m);
		

		LayoutParams params = new LayoutParams((int) box.width(), (int) box.height()+2);
		params.addRule(CENTER_IN_PARENT, -1);
		
		this.setLayoutParams(new LayoutParams(LayoutParams.FILL_PARENT, (int) actualHeight));
		this.addView(g, params);
	}
	
	@Override
	public void onDraw(Canvas c) {
		super.onDraw(c);
	}

	
	@Override
	public void onMeasure(int w, int h) {
		super.onMeasure(w, h);
		setMeasuredDimension(getMeasuredWidth(), getMeasuredHeight());		
	}


}
