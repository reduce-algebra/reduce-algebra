package uk.ac.cam.aa582.interactivity;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.BoxUtil;
import uk.ac.cam.aa582.structures.reducible.ExpressionBuilder;
import uk.ac.cam.aa582.structures.reducible.OnRedrawListener;
import uk.ac.cam.aa582.structures.reducible.OnRequestGainFocusListener;
import uk.ac.cam.aa582.structures.reducible.Reducible;
import android.content.Context;
import android.graphics.Color;
public class SimplifyInputView extends InputView implements OnRedrawListener, OnRequestGainFocusListener {
	
	private static int lastId = 0;
	
	ExpressionBuilder toSimplify;
	private int m = 5; // margin
	private boolean canGainFocus = true;
	
	public void setToSimplify(ExpressionBuilder eb) {
		toSimplify = eb;
		eb.setOnRequestGainFocusListener(this);
		onRedraw(toSimplify);
	}

	public SimplifyInputView(Context context) {
		super(context);
		this.setId(++lastId);
		this.setBackgroundColor(Color.WHITE);
		LayoutParams params = new LayoutParams(LayoutParams.FILL_PARENT, LayoutParams.WRAP_CONTENT);
		this.setLayoutParams(params);
		setToSimplify(new ExpressionBuilder());
	}

	@Override
	public void setInputKeyboard(KeyboardManager keyboard) {
		toSimplify.setOnRedrawListener(this);
		
		keyboard.enableAllButtons();
		keyboard.marryToBuilder(toSimplify);
	}

	@Override
	public Reducible toReducible() {
		return toSimplify;
	}

	@Override
	public void onRedraw(ExpressionBuilder b) {

		Box box = b.toDrawable();

		AndroidGraphics g = new AndroidGraphics(getContext());
		box.setGraphics(g);
		
		box =  BoxUtil.wrap(box, this.screenWidth() - m);

		g = new AndroidGraphics(getContext());
		box.setGraphics(g);
		
		int axisDip = 25; // preferred axis dip from roof
		int axisElev = 10;
//		LayoutParams params = new LayoutParams(LayoutParams.FILL_PARENT, (int) Math.max(box.axis() + axisDip, box.height() + m));
//		params.leftMargin = m;
//		params.topMargin = (int) Math.max(axisDip-box.axis(), m);
//		params.bottomMargin = (int) Math.max(axisElev-box.depth(), m);
		
		float height;
		float topMargin;
		float bottomMargin;
		
		if(box.height() > axisDip + axisElev) {
			height = box.height();
			topMargin = 0f;
			bottomMargin = 0f;
		} else {
			height = axisDip + axisElev;
			topMargin = axisDip - box.axis();
			bottomMargin = axisElev - box.depth();
			
			if(topMargin < 0f) {
				bottomMargin += topMargin;
				topMargin = 0f;
			}
			if(bottomMargin < 0f) {
				topMargin += bottomMargin;
				bottomMargin = 0f;
			}
		}
//		Log.d("top margin", topMargin+"");
//		Log.d("bottom margin", bottomMargin+"");
//		float height = Math.max(box.height(), axisDip + axisElev);
//		float topMargin = axisDip - box.axis();
//		float bottomMargin = axisElev - box.depth();
		
		LayoutParams params = new LayoutParams(LayoutParams.FILL_PARENT, (int) height + 2*m);
		params.leftMargin = m;
		params.topMargin = (int) topMargin + m;
		
	//	g.setPadding(0,(int) topMargin, 0, (int)bottomMargin);
		params.bottomMargin = (int) bottomMargin + m; // TODO: find out what is wrong here
		
		this.removeAllViews();
		this.addView(g, params);
	}
	
	@Override
	public void onMeasure(int w, int h) {
		super.onMeasure(w, h);
		setMeasuredDimension(getMeasuredWidth(), getMeasuredHeight());
	}

	@Override
	public void onLoseFocus() {
		toSimplify.loseFocus();
		canGainFocus  = false;
	}

	@Override
	public boolean onRequestGainFocus(ExpressionBuilder builder) {
		return canGainFocus;
	}

	@Override
	public void onGainFocus() {
		canGainFocus  = true;
		toSimplify.gainFocus();
		
	}
	
	@Override
	public SimplifyInputView setScreenInfo(ScreenInfo info) {
		super.setScreenInfo(info);
		return this;
	}

}

