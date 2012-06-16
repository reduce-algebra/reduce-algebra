package uk.ac.cam.aa582.structures.reducible;

/**
 * This is implemented by an object that would
 * like the an {@link ExpressionBuilder} to notify it
 * that the expression has changed.
 * 
 * @author Ahmad Akra
 *
 */
public interface OnRedrawListener {
	
	/**
	 * Notify that the expression shape has changed
	 * 
	 * @param b The builder of the expression which has changed shape
	 */
	void onRedraw(ExpressionBuilder b);
}
