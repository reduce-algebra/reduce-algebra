package uk.ac.cam.aa582.structures.boxes;

/**
 * Base class for objects that listen for
 * a command and know how to handle drawing.<br/>
 * All {@link Box}es extend this class, since they are responsible
 * for drawing themselves on the screen using the injected
 * {@link Graphics} object.
 * 
 * @author Ahmad Akra
 *
 */
public abstract class OnDrawListener {
	
	/**
	 * Notifies this object that it is time
	 * to draw itself on the screen.
	 */
	public abstract void onDraw();
	
	// only for debugging
	public abstract void onDrawBorders();
}
