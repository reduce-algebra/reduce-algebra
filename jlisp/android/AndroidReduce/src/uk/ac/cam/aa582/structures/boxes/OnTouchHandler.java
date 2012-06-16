package uk.ac.cam.aa582.structures.boxes;

/**
 * This represents an object that listens for touch events,
 * notable implementations include {@link Box} which listens
 * for touch events sent from the underlying graphics object.<br/>
 * 
 * 
 * @author Ahmad Akra
 *
 * @param <T> The type of the object that is passed to onTouch
 */
public interface OnTouchHandler<T> {
	
	/**
	 * Should be called when a touch event happens
	 * @param t An optional parameter that could come in handy,
	 * implementations usually expect the caller to pass itself
	 */
	void onTouch(T t);

	/**
	 * How far away are the given coordinates, The class
	 * that notifies this object, will typically have multiple
	 * OnTouchHandlers around, and will only notify the one
	 * that returns the smallest value from this method.
	 * 
	 * @param x coordinates of the touching point
	 * @param y coordinates of the touching point
	 * @return the distance square from the given 
	 * coordinates to the center of the symbol
	 */
	float proximity(float x, float y);
}
