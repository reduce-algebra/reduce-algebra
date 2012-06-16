package uk.ac.cam.aa582.interactivity;

import uk.ac.cam.aa582.structures.reducible.Reducible;
import android.content.Context;
import android.graphics.Color;
import android.widget.RelativeLayout;

public abstract class InputView extends RelativeLayout {

	private ScreenInfo screenInfo;

	public InputView(Context context) {
		super(context);
		this.setBackgroundColor(Color.WHITE);
	}
	
	public abstract void setInputKeyboard(KeyboardManager keyboard);
	public abstract Reducible toReducible();
	public abstract void onLoseFocus();
	public abstract void onGainFocus();
	
	public InputView setScreenInfo(ScreenInfo info) {
		this.screenInfo = info;
		return this;
	}
	
	protected float screenWidth() {
		return screenInfo == null ? Float.MAX_VALUE : screenInfo.screenWidth();
	}
	
	protected float screenHeight() {
		return screenInfo == null ? Float.MAX_VALUE : screenInfo.screenHeight();
	}
	
}
