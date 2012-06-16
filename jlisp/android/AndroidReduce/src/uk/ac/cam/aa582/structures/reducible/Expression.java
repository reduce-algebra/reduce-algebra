package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;

/**
 * Represents a mathematical expression, for example "integral of [sqrt(1+3x^2)]"<br/>
 * An expression in general can contain smaller sub-expressions in a hierarchy.
 * As the user clicks on the keyboard, an {@link ExpressionBuilder} is responding to each input
 * and constructing a hierarchy of {@link Expression}s.
 * 
 * @author Ahmad Akra
 *
 */
public abstract class Expression extends Reducible {
	
	/**
	 * Sets the touch handler which should be notified about
	 * any touch events, When the user touches this expression
	 * on the screen, the reaction is delegated to the object
	 * set by this method.
	 * 
	 * @param touchHandler, the object that listens and handles touch events
	 */
	public abstract void setTouchHandler(OnTouchHandler<Object> touchHandler);

	/**
	 * @return A carbon copy of this {@link Expression}
	 */
	public abstract Expression copy();

}
