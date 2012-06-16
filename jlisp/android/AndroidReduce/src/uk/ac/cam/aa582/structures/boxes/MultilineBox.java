package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

public class MultilineBox extends Box {
	
	public enum Alignment {
		left, right, centre
	}
	
	public Box[] boxes = new Box[0];
	float interBoxMarginFactor = -1;
	float lineHeightFactor = -1;
	float widthOverrideFactor = -1;
	Alignment alignment = Alignment.left;
		
	public MultilineBox(float interBoxMarginFactor, float lineHeightFactor, float widthOverrideFactor, Alignment alignment, Box... boxes) {
		

		if(interBoxMarginFactor >= 0)
			this.interBoxMarginFactor = interBoxMarginFactor;
		if(lineHeightFactor > 0)
			this.lineHeightFactor = lineHeightFactor;
		if(widthOverrideFactor > 0)
			this.widthOverrideFactor = widthOverrideFactor;
		if(alignment != null)
			this.alignment = alignment;
		if(boxes != null) 
			this.boxes = boxes;
		
		
	}
	
	private float interBoxMargin() {
		if(interBoxMarginFactor >= 0) return interBoxMarginFactor * fontSize();
		else  return C.default_multiline_box_interbox_margin_factor * fontSize();
	}

	@Override
	public float axis() {
		if(optimize && axis >= 0) return axis;
		
		return axis = (this.height() / 2);
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		
		float sum = 0f;

		for(Box box : this)
			sum += Math.max(lineHeight(), box.height());

		sum += (boxes.length - 1) * interBoxMargin();
		return height = sum;
	}

	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(boxes);
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;
		
		float max = 0f;
		for(Box box : this) {
			max = Math.max(max, box.width());
		}
		
		return width = Math.max(max, widthOverride());
	}

	private float widthOverride() {
		return widthOverrideFactor * fontSize();
	}

	@Override
	protected void eraseMemory() {

	}

	@Override
	protected void setChildrenStyle() {
		for(Box box : this)
			box.setStyle(style);
	}

	@Override
	public float getSquashingDistance() {
		float maximumSqueezedWidth = 0f;
		
		for(Box box : this) {
			float squeezedWidth = box.width() - box.getSquashingDistance();
			maximumSqueezedWidth = Math.max(maximumSqueezedWidth, squeezedWidth);
		}
		
		return this.width() - maximumSqueezedWidth;
	}

	@Override
	public Box squash(float factor) {
		Box[] squeezedBoxes = new Box[boxes.length];
		for(int i=0; i< boxes.length; i++)
			squeezedBoxes[i] = boxes[i].squash(factor);
		
		MultilineBox squeezed = new MultilineBox(interBoxMarginFactor, lineHeightFactor, widthOverrideFactor, alignment, squeezedBoxes);
		squeezed.setState(this);
		return squeezed;
	}

	@Override
	public void onDraw() {
		float x = 0f;
		float y = 0f;
		
		// for each line
		for(int i=0; i< boxes.length; i++) {
			
			// calculate x
			if(alignment == Alignment.left){
				x = 0f;
			} else if(alignment == Alignment.centre) {
				x = (this.width() - boxes[i].width()) / 2;
			} else {
				x = this.width() - boxes[i].width();
			}
			
			// adjust for line height
			if(lineHeight() > boxes[i].height()) {
				y += ((lineHeight() - boxes[i].height()) /2);
			}
			
			// draw the box
			drawBox(boxes[i], x, y);
			
			// go to next line
			y += boxes[i].height();
			y += interBoxMargin();
			
			// adjust for line height again
			if(lineHeight() > boxes[i].height()) {
				y += ((lineHeight() - boxes[i].height()) /2);
			}
		}
	}

	private float lineHeight() {
		return lineHeightFactor * fontSize();
	}

	@Override
	public Box[] split(Level level) {
		return new Box[] { this };
	}
}
