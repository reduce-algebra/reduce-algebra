package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * This represents a base box with both a superscript and a subscript
 * both which are optional (pass null to the constructor if you don't
 * want a superscript or if you don't want a subscript) <br/>
 * In LaTeX this is equivalent to <tt>base^superscript_subscript</tt>. <br/>
 * The {@link IntegralBox} makes use of this class to draw the integral limits,
 * so do large operators that have limits too.
 * 
 * @author Ahmad Akra
 *
 */
public class ScriptBox extends Box {
	
	/**
	 * Superscripts and subscripts appear in two different ways: <br/>
	 * 1 - Either to the right side of the base expression, represented by {@link ScriptMode#side} <br/>
	 * 2 - Or above and below the base expression, represented by {@link ScriptMode#overunder}
	 * @author Ahmad Akra
	 *
	 */
	public enum ScriptMode {
		
		/**
		 * The superscript and subscript are on the right side of the base expression
		 */
		side, 
		
		/**
		 * The superscript and subscript are above and below the base expression respectively
		 */
		overunder
	}
	
	/**
	 * The base expression (The expression with the superscript and subscript next to it
	 */
	Box base;
	
	/**
	 * The superscript
	 */
	Box sup;
	
	/**
	 * The subscript
	 */
	Box sub;
	
	/**
	 * Optimization field
	 */
	boolean superscriptExists = false;
	
	/**
	 * Optimization field
	 */
	boolean subscriptExists = false;
	
	/**
	 * The script mode for this {@link ScriptBox}, see {@link ScriptMode} for more detail
	 */
	ScriptMode scriptMode;
	
	/**
	 * This value is multiplied by every squeezable distance before rendering the box.
	 */
	private float squeezingFactor = 1.0f;
	
	/**
	 * Constructor
	 * 
	 * @param base The base box (the base of the superscript and subscript).
	 * @param superscript The box that will be drawn as superscript.
	 * 
	 */
	public ScriptBox(Box base, Box superscript) {
		this(base, superscript, null, null, 1.0f);
	}
	
	/**
	 * Constructor
	 * 
	 * @param base The base box (the base of the superscript and subscript).
	 * @param superscript The box that will be drawn as superscript.
	 * @param subscript The box that will be drawn as a subscript.
	 */
	public ScriptBox(Box base, Box superscript, Box subscript) {
		this(base, superscript, subscript, null, 1.0f);
	}
	
	/**
	 * Constructor
	 * 
	 * @param base The base box (the base of the superscript and subscript).
	 * @param superscript The box that will be drawn as superscript.
	 * @param subscript The box that will be drawn as a subscript.
	 * @param mode Whether the superscript and subscript are drawn to the side or over and under the base
	 */
	public ScriptBox(Box base, Box superscript, Box subscript, ScriptMode mode) {
		this(base, superscript, subscript, mode, 1.0f);
	}
	
	/**
	 * Constructor
	 * 
	 * @param base The base box (the base of the superscript and subscript).
	 * @param superscript The box that will be drawn as superscript.
	 * @param subscript The box that will be drawn as a subscript.
	 * @param mode Whether the superscript and subscript are drawn to the side or over and under the base
	 * @param squeezingFactor All squeezable margins are multiplied by this value, default is 1.0f
	 */
	private ScriptBox(Box base, Box superscript, Box subscript, ScriptMode mode, float squeezingFactor) {
		
		if(base == null) this.base = defaultBox();
		else this.base = base;
		
		if(superscript == null) this.sup = defaultBox(); //new NullBox(ctx,style,0.05f,0.05f);
		else { this.sup = superscript; superscriptExists = true; }
		
		if(subscript == null) this.sub = defaultBox(); // new NullBox(ctx,style,0.05f,0.05f);
		else { this.sub = subscript; subscriptExists = true; }
		
		if(mode == null) this.scriptMode = ScriptMode.side;
		else this.scriptMode = mode;
		
		this.squeezingFactor = squeezingFactor;
		
		setChildrenStyle();		
	}
	
	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(base, sup, sub);
	}

	@Override
	public float width() {
		if(optimize && width >= 0f) return width;
		
		if(scriptMode == ScriptMode.overunder) {
			width = 
					Math.max(base.width(), 
							Math.max(superscriptExists ? sup.width() : Float.NEGATIVE_INFINITY, 
									subscriptExists ? sub.width() : Float.NEGATIVE_INFINITY));
			return width;
		} else {
			width =
					base.width() + baseScriptMargin() + 
					Math.max(superscriptExists ? sup.width() - base.superscriptShift() : Float.NEGATIVE_INFINITY, 
							subscriptExists ? sub.width() - base.subscriptShift() : Float.NEGATIVE_INFINITY)
							+ rightMargin();
			return width;
		}
	}

	@Override
	public float height() {
		if(optimize && height >= 0f) 
			return height;
		
		if(scriptMode == ScriptMode.overunder) {
			float supHeight = superscriptExists ? sup.height() + scriptBaseVerticalMargin() : 0f;
			float subHeight = subscriptExists ? sub.height() + scriptBaseVerticalMargin() : 0f;
			float baseHeight = base.height();
			height = baseHeight + supHeight + subHeight;
			
			return height;
		} else {
			float base_y1 = this.axis() - base.axis();
			float base_y2 = base_y1 + base.height();
			
			float sup_y1 = superscriptExists ? base_y2 - this.superscriptAxisElevation() - sup.axis() : Float.POSITIVE_INFINITY;
			float sup_y2 = superscriptExists ? sup_y1 + sup.height() : Float.NEGATIVE_INFINITY;
			
			float sub_y1 = subscriptExists ? base_y1 + this.subscriptAxisDip() - sub.axis() : Float.POSITIVE_INFINITY;
			float sub_y2 = subscriptExists ? sub_y1 + sub.height() : Float.NEGATIVE_INFINITY;
			
			height = Math.max(base_y2, Math.max(sup_y2, sub_y2)) -
					Math.min(base_y1, Math.min(sup_y1, sub_y1));
			
			return height;
		}
	}	

	private float scriptBaseVerticalMargin() {
		return C.overunder_script_base_margin_factor * fontSize();
	}

	@Override
	public float axis() {
		if(optimize && axis >= 0f) return axis;
		
		if(scriptMode == ScriptMode.overunder) {
			float supHeight = superscriptExists ? sup.height() + scriptBaseVerticalMargin() : 0f;

			return base.axis() + supHeight;
		} else {
			return axis = Math.max(
					superscriptExists ? sup.axis() + superscriptAxisElevation() - base.depth() : Float.NEGATIVE_INFINITY,
					base.axis());
		}
	}
	
	@Override
	public void onDraw() {
		
		if(scriptMode == ScriptMode.overunder) {
			// base
			float x1 = (this.width() - base.width()) / 2;
			float y1 = this.axis() - base.axis();
			drawBox(base, x1, y1);
			
			// superscript
			if(superscriptExists) {
				float x2 = (this.width() - sup.width()) / 2;
				float y2 = 0f;
				drawBox(sup, x2, y2);
			}
			// subscript
			if(subscriptExists) {
				float x3 = (this.width() - sub.width()) / 2;
				float y3 = this.height() - sub.height();
				drawBox(sub, x3, y3);
			}
		} else {
			// base
			float x1 = 0f;
			float y1 = this.axis() - base.axis(); // axis of base is the axis of the ScripBox
			drawBox(base,x1,y1);
			
			// superscript
			if(superscriptExists) {
				float x2 = base.width() + baseScriptMargin() - superscriptDislocation();
				float y2 = y1 + base.height() - sup.axis() - superscriptAxisElevation();
				drawBox(sup, x2, y2);
			}
			// subscript
			if(subscriptExists) {
				float x3 = base.width() + baseScriptMargin() - subscriptDislocation();
				float y3 = y1 - sub.axis() + subscriptAxisDip();
				drawBox(sub, x3, y3);
			}
		}
	}

	@Override
	protected void setChildrenStyle() {
		base.setStyle(style);
		sup.setStyle(TexRules.superscriptOf(style));
		sub.setStyle(TexRules.subscriptOf(style));
	}

	@Override
	protected void eraseMemory() {
		supAxisElevation = Float.NEGATIVE_INFINITY;
		subAxisDip = Float.NEGATIVE_INFINITY;
	}
	
	/**
	 * Optimization field
	 */
	private float supAxisElevation = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	private float subAxisDip = Float.NEGATIVE_INFINITY;
	
	private float superscriptAxisElevation() {
		if(supAxisElevation < -Float.MAX_VALUE)
			calculateSupSubAxisElevationDip();
		
		return supAxisElevation;
	}
	
	private float subscriptAxisDip() {

		if(subAxisDip < -Float.MAX_VALUE)
			calculateSupSubAxisElevationDip();
		
		return subAxisDip;
	}
	
	/**
	 * Initializes the correct value to both {@link this#subAxisDip} 
	 * and {@link this#supAxisElevation}, this is only used when
	 * the script mode is {@link ScriptMode#side}
	 */
	private void calculateSupSubAxisElevationDip(){
		// the elevation of the superscript axis from the base floor, ignoring subscript
		float supAxisElevation = base.height() - sup.axis(); // align with top if the superscript does not exist
		if(superscriptExists) {
			supAxisElevation = preferredSupAxisBaseAxisElevation() + base.depth();
			if(supAxisElevation < base.height() - maximumSupAxisBaseRoofDistance())
				supAxisElevation = base.height() - maximumSupAxisBaseRoofDistance();
			float supFloorElevation = supAxisElevation - sup.depth();
			if(supFloorElevation < base.depth() - maximumSupFloorBaseAxisDistance())
				supAxisElevation = base.depth() - maximumSupFloorBaseAxisDistance() + sup.depth();
		}
		
		// the dip of the subscript axis from the base roof, ignoring superscript
		float subAxisDip = base.height() - sub.depth();
		if(subscriptExists) {
			subAxisDip = preferredSubAxisBaseAxisDip() + base.axis();
			if(subAxisDip < base.height() - maximumSubAxisBaseFloorDistance())
				subAxisDip = base.height() - maximumSubAxisBaseFloorDistance();
			float subRoofDip = subAxisDip - sub.axis();
			if(subRoofDip < base.axis() - maximumSubRoofBaseAxisDistance())
				subAxisDip = base.axis() - maximumSubRoofBaseAxisDistance() + sub.axis();
		}
		
		// in case of superscript subscript coming too close
		if(superscriptExists && subscriptExists) {
			float supFloorDip = base.height() - supAxisElevation + sup.depth();
			float subRoofElevation = base.height() - subAxisDip + sub.axis();
			if(base.height() - supFloorDip - subRoofElevation < minimumSupFloorSubRoofDistance()) {
				float referenceDip = base.axis() - (minimumSupFloorSubRoofDistance()/2);
				float referenceElevation = base.depth() - (minimumSupFloorSubRoofDistance()/2);
				
				if(supFloorDip > referenceDip && subRoofElevation > referenceElevation) {
					supAxisElevation = base.height() - referenceDip + sup.depth();
					subAxisDip = base.height() - referenceElevation + sub.axis();
				} else if(supFloorDip > referenceDip){
					supAxisElevation = sup.depth() + subRoofElevation + minimumSupFloorSubRoofDistance();
				} else if(subRoofElevation > referenceElevation){
					subAxisDip = sub.axis() + supFloorDip + minimumSupFloorSubRoofDistance();
				}		
			}
		}

		
		this.supAxisElevation = supAxisElevation;
		this.subAxisDip = subAxisDip;
	}

	private float minimumSupFloorSubRoofDistance() {
		if(styleIsCramped()) {
			return C.minimum_cramped_subscript_superscript_margin_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.minimum_display_subscript_superscript_margin_factor * fontSize(); break;
		case T : result =  C.minimum_text_subscript_superscript_margin_factor * fontSize(); break;
		case S : result =  C.minimum_script_subscript_superscript_margin_factor * fontSize(); break;
		case SS : result =  C.minimum_sscript_subscript_superscript_margin_factor * fontSize(); break;
		}
		return result;
	}

	private float maximumSubRoofBaseAxisDistance() {
		if(styleIsCramped()) {
			return C.maximum_cramped_subscriptRoof_baseAxis_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.maximum_display_subscriptRoof_baseAxis_distance_factor * fontSize(); break;
		case T : result =  C.maximum_text_subscriptRoof_baseAxis_distance_factor * fontSize(); break;
		case S : result =  C.maximum_script_subscriptRoof_baseAxis_distance_factor * fontSize(); break;
		case SS : result =  C.maximum_sscript_subscriptRoof_baseAxis_distance_factor * fontSize(); break;
		}
		return result;
	}

	private float maximumSubAxisBaseFloorDistance() {
		if(styleIsCramped()) {
			return C.maximum_cramped_subscriptAxis_baseFloor_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.maximum_display_subscriptAxis_baseFloor_distance_factor * fontSize(); break;
		case T : result =  C.maximum_text_subscriptAxis_baseFloor_distance_factor * fontSize(); break;
		case S : result =  C.maximum_script_subscriptAxis_baseFloor_distance_factor * fontSize(); break;
		case SS : result =  C.maximum_sscript_subscriptAxis_baseFloor_distance_factor * fontSize(); break;
		}
		return result;
	}

	private float preferredSubAxisBaseAxisDip() {
		if(styleIsCramped()) {
			return C.normal_cramped_subscriptAxis_baseAxis_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.normal_display_subscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case T : result =  C.normal_text_subscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case S : result =  C.normal_script_subscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case SS : result =  C.normal_sscript_subscriptAxis_baseAxis_distance_factor * fontSize(); break;
		}
		return result;
	}

	private float maximumSupFloorBaseAxisDistance() {
		if(styleIsCramped()) {
			return C.maximum_cramped_superscriptFloor_baseAxis_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.maximum_display_superscriptFloor_baseAxis_distance_factor * fontSize(); break;
		case T : result =  C.maximum_text_superscriptFloor_baseAxis_distance_factor * fontSize(); break;
		case S : result =  C.maximum_script_superscriptFloor_baseAxis_distance_factor * fontSize(); break;
		case SS : result =  C.maximum_sscript_superscriptFloor_baseAxis_distance_factor * fontSize(); break;
		}
		return result;
	}

	private float maximumSupAxisBaseRoofDistance() {
		if(styleIsCramped()) {
			return C.maximum_cramped_superscriptAxis_baseRoof_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.maximum_display_superscriptAxis_baseRoof_distance_factor * fontSize(); break;
		case T : result =  C.maximum_text_superscriptAxis_baseRoof_distance_factor * fontSize(); break;
		case S : result =  C.maximum_script_superscriptAxis_baseRoof_distance_factor * fontSize(); break;
		case SS : result =  C.maximum_sscript_superscriptAxis_baseRoof_distance_factor * fontSize(); break;
		}
		return result;
	}

	private float preferredSupAxisBaseAxisElevation() {
		if(styleIsCramped()) {
			return C.normal_cramped_superscriptAxis_baseAxis_distance_factor * fontSize();
		}
		float result = 0f;
		switch(style) {
		case D : result =  C.normal_display_superscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case T : result =  C.normal_text_superscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case S : result =  C.normal_script_superscriptAxis_baseAxis_distance_factor * fontSize(); break;
		case SS : result =  C.normal_sscript_superscriptAxis_baseAxis_distance_factor * fontSize(); break;
		}
		return result;
	}
	
	private float baseScriptMargin() {
		return C.base_superscript_margin_factor * fontSize() * squeezingFactor ;
	}
	
	private float superscriptDislocation() {
		return base.superscriptShift();
	}
	
	private float subscriptDislocation() {
		return base.subscriptShift();
	}
	
	private float rightMargin() {
		return C.script_box_right_margin * fontSize();
	}

	@Override
	public float getSquashingDistance() {
		// TODO this one is tricky
		if(scriptMode == ScriptMode.overunder) return 0f;
		
		return base.getSquashingDistance() + baseScriptMargin();
	}

	@Override
	public Box squash(float factor) {
		if(scriptMode == ScriptMode.overunder) return this;
		
		ScriptBox result = new ScriptBox(base.squash(factor), sup, sub, scriptMode, factor);
		result.setState(this);
		return result;
	}

	@Override
	public Box[] split(Level level) {
		if(scriptMode == ScriptMode.overunder || level == Level.easy) {
			// no splitting
			return new Box[] { this };
		} else {
			Box[] result = base.split(level);
			result[result.length - 1] = new ScriptBox(
							result[result.length - 1], 
							superscriptExists ? sup: null, 
							subscriptExists ? sub : null);
			return result;
		}
	}
}
