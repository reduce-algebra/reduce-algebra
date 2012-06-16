package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * Just an empty space with width and height specified as
 * constructor parameters, there is an option to display
 * a border around the space by calling {@link SpaceBox#showBorder()}
 * 
 * @author Ahmad Akra
 *
 */
public class SpaceBox extends Box {
	
	public enum Space { space, semicolon, colon, comma, asterisk, nospace, exclamation }
	
	private float widthFactor = 0;
	private float heightFactor = 0;
	private boolean squeezable = false;
	private boolean borderVisible = false;

	public SpaceBox() {
		this(C.default_space_box_width_factor, C.default_space_box_height_factor, false);
	}
	
	public SpaceBox(Space space) {
		this(determineWidthFactor(space), C.default_space_box_height_factor, false);
	}

	
	private static float determineWidthFactor(Space space) {
		float factor = 0f;
		switch(space) {
		case space : 		factor = C.space_space_width_factor; break;
		case semicolon : 	factor = C.semicolon_space_width_factor; break;
		case colon : 		factor = C.colon_space_width_factor; break;
		case asterisk : 	factor = C.asterisk_space_width_factor; break;
		case comma : 		factor = C.comma_space_width_factor; break;
		case nospace : 		factor = 0f; break;
		case exclamation : 	factor = C.exclamation_space_width_factor; break;
		}
		return factor;
	}

	public SpaceBox(float widthFactor, float heightFactor) {
		this(widthFactor, heightFactor, false);
	}
	
	public SpaceBox(float widthFactor, float heightFactor, boolean squeezable) {
		
		this.widthFactor = widthFactor;
		this.heightFactor = heightFactor;
		this.squeezable  = squeezable;
	}
	
	/**
	 * Displays a rectangle around the edges of this box.
	 * @return Itself for convenience.
	 */
	public SpaceBox showBorder() {
		borderVisible = true;
		return this;
	}

	@Override
	public Iterator<Box> iterator() {
		return iteratorOver();
	}

	@Override
	public float width() {
		return widthFactor * fontSize();
	}

	@Override
	public float height() {
		return heightFactor * fontSize();
	}

	@Override
	public float axis() {
		return height()/2;
	}


	@Override
	protected void setChildrenStyle() {

	}

	@Override
	protected void eraseMemory() {

	}
	
	@Override
	public void onDraw() {
		graphics.setOrigin(xOrigin(), yOrigin());
		if(borderVisible) {
			float m = 1f; // margin
			float lt = 1f; // line thickness
			float x1=0, x2=width()-m, x3=width()-m, x4=0,y1=0,y2=0,y3=height()-m,y4=height()-m;
			graphics.drawLine(lt,x1,y1,x2,y2);
			graphics.drawLine(lt,x2,y2,x3,y3);
			graphics.drawLine(lt,x3,y3,x4,y4);
			graphics.drawLine(lt,x4,y4,x1,y1);
		}
	}


	@Override
	public float getSquashingDistance() {
		if(squeezable) return this.width();
		else return 0f;
	}
	
	@Override
	public Box setGraphics(Graphics g) {
		if(this.handler != null)
			g.setOnTouchHandler(this);
		return super.setGraphics(g);
	}


	@Override
	public Box squash(float factor) {
		if(squeezable)
			widthFactor = widthFactor * factor;
		return this;
	}


	@Override
	public Box[] split(Level level) {
		return new Box[] { this };
	}
	
	@Override
	public Box registerTouchHandler(OnTouchHandler<Object> handler, Object arg)  {
		this.handler = handler;
		this.onTouchArg = arg;
		if(graphics != null) graphics.setOnTouchHandler(this);
		return this;
	}
}
