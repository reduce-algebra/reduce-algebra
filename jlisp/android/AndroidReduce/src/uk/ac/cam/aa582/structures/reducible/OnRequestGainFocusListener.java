package uk.ac.cam.aa582.structures.reducible;

/**
 * Implemented by an object which serves as listener and permission granter
 * for an object that wishes to gain focus. This is used for example by the 
 * {@link ExpressionBuilder} to request that it wants to gain focus because (e.g.
 * the user has touched it) and an the OnRequestGainFocusListener gives permission
 * to the {@link ExpressionBuilder} and deals with any job that should be performed
 * first (e.g. removing focus from another {@link ExpressionBuilder} object)
 * 
 * @author Ahmad Akra
 *
 */
public interface OnRequestGainFocusListener {
	
	/**
	 * Notify and ask permission for gaining focus
	 * 
	 * @param builder the object that wants to regain focus
	 * @return true if permission to gain focus is granted and false otherwise
	 */
	public boolean onRequestGainFocus(ExpressionBuilder builder);
}
