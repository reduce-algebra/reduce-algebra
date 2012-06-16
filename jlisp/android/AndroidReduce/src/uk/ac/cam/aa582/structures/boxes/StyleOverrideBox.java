package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * This box ignored calls from its parent box to
 * change its style, and keeps the style at the given
 * value passed at the constructor. Useful when parsing
 * "x^{\displaystyle 2}" Since the "2" symbol box can
 * be wrapped in StyleOverrideBox with styleOverride of
 * display.
 * 
 * @author Ahmad Akra
 *
 */
public class StyleOverrideBox extends WrapperBox {
	
	private TexStyle styleOverride;
	
	public StyleOverrideBox(Box b, TexStyle styleOverride) {
		super(b);
		this.styleOverride = styleOverride == null ? TexStyle.D : styleOverride;
	}
	
	@Override
	public void setStyle(TexStyle style) {
		// ignore the given style
		super.setStyle(this.styleOverride);
	}

	@Override
	public Box[] split(Level level) {
		Box[] result = this.innerBox.split(level);
		for(int i=0; i<result.length; i++)
			result[i] = new StyleOverrideBox(result[i], styleOverride);
		return result;
	}
}
