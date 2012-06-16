package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * Any subclasses of this should remember to override
 * the {@link Box#split(Level)} method
 * 
 * @author Ahmad Akra
 *
 */
public abstract class WrapperBox extends Box {
	
	protected Box innerBox;
	
	public WrapperBox(Box b) {
		if(b != null)
			innerBox = b;
		else
			innerBox = defaultBox();
	}

	@Override
	public float axis() {
		return innerBox.axis();
	}

	@Override
	public float height() {
		return innerBox.height();
	}

	@Override
	public Iterator<Box> iterator() {
		return innerBox.iterator();
	}

	@Override
	public Box squash(float factor) {
		return innerBox.squash(factor);
	}

	@Override
	public float getSquashingDistance() {
		return innerBox.getSquashingDistance();
	}

	@Override
	public float width() {
		return innerBox.width();
	}

	@Override
	protected void eraseMemory() {
		innerBox.eraseMemory();
	}

	@Override
	protected void setChildrenStyle() {
		innerBox.setChildrenStyle();
	}

	@Override
	public void onDraw() {
		innerBox.onDraw();
	}

}
