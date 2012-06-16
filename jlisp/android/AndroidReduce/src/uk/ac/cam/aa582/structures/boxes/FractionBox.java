package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * <tt>
 * &nbsp&nbsp&nbsp&nbsp
 * 
 *    3      <br/> &nbsp
 * _______   <br/>
 *           <br/> &nbsp
 * (x + y)   <br/>
 *  		 <br/>
 *  </tt>
 * Is a FractioBox with numerator <tt>'3'</tt> and denominator <tt>'(x + y)'</tt>.<br/>
 * 
 * @author Ahmad Akra
 *
 */
public class FractionBox extends Box {

	Box numerator;
	Box denominator;
	private float squeezingFactor = 1.0f;
	
	public FractionBox(Box n, Box d) {
		this(n, d, 1.0f);
	}
	
	private FractionBox(Box n, Box d, float squeezingFactor) {
		if(n != null) numerator = n;
		else numerator = defaultBox();
		if(d != null) denominator = d;
		else denominator = defaultBox();
		
		this.squeezingFactor = squeezingFactor;
		
		setChildrenStyle();
	}
	
	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(numerator,denominator);
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;
		
		return width = this.innerWidth() + (2 * leftMargin());
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		
		height =
				// top height
				(numeratorTooLarge() ? (numerator.height() + minimumNumBarMargin()) : 
					(numerator.axis() + numAxisBarRegularMargin())) +
				// fraction bar thickness
					lineThickness() +
				// bottom height
				(denominatorTooLarge() ? (denominator.height() + minimumDenomBarMargin()) : 
					(denominator.depth() + denomAxisBarRegularMargin()));
		
		return height;
	}
	
	@Override
	public float axis() {
		if(optimize && axis >= 0) return axis;
		
		return axis = 
				(numeratorTooLarge() ? (numerator.height() + minimumNumBarMargin()) : 
			(numerator.axis() + numAxisBarRegularMargin())) + (lineThickness()/2);
	}

	@Override
	protected void eraseMemory() {
		denomAxisBarRegularMargin = Float.NEGATIVE_INFINITY;
		minimumDenomBarMargin = Float.NEGATIVE_INFINITY;
		denominatorTooLargeAlreadyCalled = false;
		denominatorTooLarge = false;
		numAxisBarRegularMargin = Float.NEGATIVE_INFINITY;
		minimumNumBarMargin = Float.NEGATIVE_INFINITY;
		numeratorTooLargeAlreadyCalled = false;
		numeratorTooLarge = false;
		leftMargin = Float.NEGATIVE_INFINITY;
		innerWidth = Float.NEGATIVE_INFINITY;	
	}

	@Override
	public void onDraw() {
		// numerator
		float x1 = leftMargin() + (numerator.width() < this.innerWidth() ? ((this.innerWidth() - numerator.width()) / 2) : 0f);
		float y1 = 0f;
		drawBox(numerator, x1, y1);
		
		// fraction bar
		float startX = leftMargin();
		float startY = axis();
		float stopX = startX + innerWidth();
		float stopY = startY;
		graphics.setOrigin(xOrigin(), yOrigin()).drawLine(lineThickness(), startX, startY, stopX, stopY);
		
		// denominator
		float x2 = leftMargin() + (denominator.width() < this.innerWidth() ? ((this.innerWidth() - denominator.width()) / 2) : 0);
		float y2 = this.height() - denominator.height();
		drawBox(denominator, x2, y2);
	}

	private float denomAxisBarRegularMargin() {
		if(optimize && denomAxisBarRegularMargin >= 0) return denomAxisBarRegularMargin;
		
		return denomAxisBarRegularMargin = (style == TexStyle.D) ?
			C.denominator_axis_bar_display_margin_factor * fontSize() :
			C.denominator_axis_bar_nondisplay_margin_factor * fontSize();
	}

	private float minimumDenomBarMargin() {
		if(optimize && minimumDenomBarMargin >= 0) return minimumDenomBarMargin;
		
		return minimumDenomBarMargin = (style == TexStyle.D) ? 
				Math.max(2f, C.minimum_denominator_bar_display_margin_factor * fontSize()) :
				Math.max(2f, C.minimum_denominator_bar_nondisplay_margin_factor * fontSize());
	}

	private boolean denominatorTooLarge() {
		if(optimize && denominatorTooLargeAlreadyCalled) return denominatorTooLarge;
		denominatorTooLargeAlreadyCalled = true;
		
		return denominatorTooLarge =
				((denomAxisBarRegularMargin() - denominator.axis()) < minimumDenomBarMargin());
	}

	private float numAxisBarRegularMargin() {
		if(optimize && numAxisBarRegularMargin >= 0) return numAxisBarRegularMargin;
		
		return numAxisBarRegularMargin = (style == TexStyle.D) ?
				C.numerator_axis_bar_display_margin_factor * fontSize() :
				C.numerator_axis_bar_nondisplay_margin_factor * fontSize();
	}

	private float minimumNumBarMargin() {
		if(optimize && minimumNumBarMargin >= 0) return minimumNumBarMargin;
		
		return minimumNumBarMargin = (style == TexStyle.D) ? 
				Math.max(2f, C.minimum_numerator_bar_display_margin_factor * fontSize()) :
				Math.max(2f, C.minimum_numerator_bar_nondisplay_margin_factor * fontSize());
	}

	private boolean numeratorTooLarge() {
		if(optimize && numeratorTooLargeAlreadyCalled) return numeratorTooLarge;
		numeratorTooLargeAlreadyCalled = true;
		
		return numeratorTooLarge =
				(numAxisBarRegularMargin() - numerator.depth()) < minimumNumBarMargin(); 
	}
	
	private float leftMargin() {
		if(optimize && leftMargin >= 0) return leftMargin;
		
		return leftMargin = (C.fraction_box_left_and_right_margin_factor * fontSize() * squeezingFactor);
	}

	private float innerWidth() {
		if(optimize && innerWidth >= 0) return innerWidth;
		return innerWidth = Math.max(numerator.width(), denominator.width());
	}
	
	// -------- memory ----------
	float denomAxisBarRegularMargin = Float.NEGATIVE_INFINITY;
	float minimumDenomBarMargin = Float.NEGATIVE_INFINITY;
	boolean denominatorTooLargeAlreadyCalled = false;
	boolean denominatorTooLarge = false;
	float numAxisBarRegularMargin = Float.NEGATIVE_INFINITY;
	float minimumNumBarMargin = Float.NEGATIVE_INFINITY;
	boolean numeratorTooLargeAlreadyCalled = false;
	boolean numeratorTooLarge = false;
	float leftMargin = Float.NEGATIVE_INFINITY;
	float innerWidth = Float.NEGATIVE_INFINITY;

	@Override
	public void setChildrenStyle() {
		numerator.setStyle(TexRules.numeratorOf(style));
		denominator.setStyle(TexRules.denominatorOf(style));
		
	}

	@Override
	public float getSquashingDistance() {
		float dw = this.denominator.width();
		float nw = this.numerator.width();
		float d_squeeze = denominator.getSquashingDistance();
		float n_squeeze = numerator.getSquashingDistance();
		float dn_squeeze = this.innerWidth() - Math.max(dw - d_squeeze, nw - n_squeeze);
		float result = dn_squeeze + (2*leftMargin());
		//Log.d("squashing distance", result+"");
		return result; // bogus!
		
	}

	@Override
	public Box squash(float factor) {
		FractionBox result = new FractionBox(numerator.squash(factor), denominator.squash(factor), factor);
		result.setState(this);
		return result;
	}

	@Override
	public Box[] split(Level level) {
		if(level == Level.easy || level == Level.medium) {
			return new Box[] { this };
		} else {
			Box[] empty1 = new Box[] { new SpaceBox(0.0f,0.0f) };
			Box[] brokenNum = (this.numerator instanceof DelimiterBox) ? this.numerator.split(level) : new DelimiterBox(this.numerator).setState(numerator).split(level);
			Box[] brokenDenom = (this.denominator instanceof DelimiterBox) ? this.denominator.split(level) : new DelimiterBox(this.denominator).setState(denominator).split(level);
			Box[] empty2 = new Box[] { new SpaceBox(0.0f,0.0f) };
			
			Box[] result = concat(empty1, 
					
					brokenNum, 
					new Box[] { new SymbolBox(S.slash).setGraphics(graphics.sameGraphics()) }, brokenDenom, empty2);
			return result;
		}
	}
	
}
