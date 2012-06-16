package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;
import uk.ac.cam.aa582.structures.boxes.S;

/**
 * This class wraps an initially empty {@link Expression} object  
 * and provides a convenient way of constructing it through many
 * methods. After the construction is complete,the ExpressionBuilder
 * can provide the result in the form of a {@link Reducible} object
 * or a drawable object (a {@link Box}) <br/><br/><br/>
 * 
 * 
 * For example here is how this class is used to construct <tt>"1+sqrt(x)":<br/><br/>
 * 
 * ExpressionBuilder builder = new ExpressionBuilder();
 * builder.appendSymbol("1");				<br/>
 * builder.appendSymbol(S.plus);			<br/>
 * builder.appendSqrt();					<br/>
 * builder.appendSymbol(S.x);				<br/>
 * Box box = builder.toDrawable(); // the drawable version of this expression
 * </tt><br/><br/><br/>
 * 
 * 
 * The {@link ExpressionBuilder} also provides navigation, so the
 * following code would also construct <tt>"1+sqrt(x)"<tt><br/><br/>
 * 
 * ExpressionBuilder builder = new ExpressionBuilder();
 * builder.appendSqrt();					<br/>
 * builder.appendSymbol(S.x);				<br/>
 * builder.movePointertoTheLeft();			<br/>
 * builder.movePointertoTheLeft();			<br/>
 * builder.appendSymbol("1");				<br/>
 * builder.appendSymbol(S.plus);			<br/>
 * Box box = builder.toDrawable(); // the drawable version of this expression
 * </tt><br/>
 * 
 * @author Ahmad Akra
 *
 */
public class ExpressionBuilder extends Reducible implements OnTouchHandler<Object> {
	
	/**
	 * The expression is built as a tree of {@link Expression}s 
	 * with each interleaving level containing only 
	 * {@link Sequence} objects. This field is the root of the
	 * tree (which is a {@link Sequence})
	 */
	private Sequence top = new Sequence().gainFocus();
	
	/**
	 * At every moment in time there is one {@link Sequence} that
	 * is holding the focus inside this {@link ExpressionBuilder},
	 * this {@link Sequence} is stored in this field
	 */
	private Sequence focus = top;	
	
	/**
	 * Causes the cursor to move to the right, any subsequent calls
	 * to append will insert things one position to the right of
	 * the previous location, unless the previous location is at the
	 * end of the root of the expression tree
	 * this method notifies {@link ExpressionBuilder#redrawListener}
	 */
	public void moveCursorToTheRight() {
		moveCursorToTheRightInternal();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}

	/**
	 * Causes the cursor to move to the right, any subsequent calls
	 * to append will insert things one position to the right of
	 * the previous location, unless the previous location is at the
	 * end of the root of the expression tree
	 * this method does not notify {@link ExpressionBuilder#redrawListener}
	 */
	private void moveCursorToTheRightInternal() {
		focus = focus.movePointerToTheRight();
	}

	/**
	 * Causes the cursor to move to the left, any subsequent calls
	 * to append will insert things one position to the left of
	 * the previous location, unless the previous location is at the
	 * beginning of the root of the expression tree
	 * this method notifies {@link ExpressionBuilder#redrawListener}
	 */
	public void moveCursorToTheLeft() {
		moveCursorToTheLeftInternal();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	/**
	 * Causes the cursor to move to the left, any subsequent calls
	 * to append will insert things one position to the left of
	 * the previous location, unless the previous location is at the
	 * beginning of the root of the expression tree
	 * this method does not notify {@link ExpressionBuilder#redrawListener}
	 */
	private void moveCursorToTheLeftInternal() {
		focus = focus.movePointerToTheLeft();
	}
	
	/**
	 * Have this expression lose focus, amongst other things
	 * the pointer should disappear and 
	 * {@link ExpressionBuilder#redrawListener} should be notified
	 */
	public void loseFocus() {
		focus = focus.loseFocus();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	/**
	 * Have this expression gain focus, amongst other things
	 * the pointer should become visible, should be moved
	 * to the far right and {@link ExpressionBuilder#redrawListener} 
	 * should be notified
	 */
	public void gainFocusAndTakePointerToTheRight() {
		gainFocusAndTakePointerToTheRightInternal();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	


	/**
	 * Have this expression gain focus, amongst other things
	 * the pointer should become visible and should be moved
	 * to the far right, no redraw notification
	 */
	private void gainFocusAndTakePointerToTheRightInternal() {
		top.gainFocus();
		takePointerToTheRightEnd();
	}

	private int takePointerToTheRightEnd() {
		int result = 0;
		while(!this.pointerAtRightEnd()) {
			moveCursorToTheRight();
			result++;
		}
		return result;
	}
	
	/**
	 * Have this expression gain focus, the pointer should become 
	 * visible, and {@link ExpressionBuilder#redrawListener} 
	 * should be notified
	 */
	public void gainFocus() {
		gainFocusInternal();
		if(redrawListener != null) redrawListener.onRedraw(this);		
	}
	
	/**
	 * Have this expression gain focus, the pointer should become 
	 * visible, do not notify {@link ExpressionBuilder#redrawListener} 
	 */
	private void gainFocusInternal() {
		top.gainFocus();
		
	}
	
	/**
	 * Sets the OnRequestGainFocusListener object which allows this
	 * ExpressionBuilder to bring focus back to itself when
	 * it needs to (e.g. if the user touches it)
	 * 
	 * @param listener
	 * @return the same object for convenience
	 */
	public ExpressionBuilder setOnRequestGainFocusListener(OnRequestGainFocusListener listener) {
		focusListener = listener;
		return this;
	}
	
	/**
	 * The object to ask permission for if this {@link ExpressionBuilder}
	 * wishes to gain focus again.
	 */
	OnRequestGainFocusListener focusListener;
	
	public void deleteNext() {
		focus = focus.deleteNext();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void deletePrevious() {
		
		deletePreviousInternal();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}

	private void deletePreviousInternal() {
		moveCursorToTheLeftInternal();
		focus.deleteNext();
	}
	
	public void undoDeletePrevious(boolean wasAtLeftEnd) {
		focus.undoDeleteNext();
		if(!wasAtLeftEnd)
			moveCursorToTheRightInternal();		
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public boolean pointerAtRightEnd() {
		return top.pointerAtRightEnd();
	}
	
	public boolean pointerAtLeftEnd() {
		return top.pointerAtLeftEnd();
	}
	

	public void appendSymbol(String s) {
		focus.appendSymbol(s);
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	

	public void appendSymbol(short s) {
		focus.appendSymbol(s);
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void square() {
		focus = focus.raiseToPower();
		focus = focus.appendSymbol("2");
		this.moveCursorToTheRightInternal();

		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void cube() {
		focus = focus.raiseToPower();
		focus = focus.appendSymbol("3");
		this.moveCursorToTheRightInternal();

		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void raiseToMinusOne() {
		focus = focus.raiseToPower();
		focus = focus.appendSymbol(S.minus);
		focus = focus.appendSymbol("1");
		this.moveCursorToTheRightInternal(); // get out of the superscript

		if(redrawListener != null) redrawListener.onRedraw(this);
		
	}

	
	public void raiseToPower() {
		focus = focus.raiseToPower();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	

	public void appendSqrt() {

		focus = focus.appendSqrt();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	

	public void appendIntegral() {

		focus = focus.appendIntegral();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void appendIntegralWithLimits() {
		focus = focus.appendIntegralWithLimits();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void appendSummation() {
		focus = focus.appendSummation();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	

	public void appendDifferential() {

		focus = focus.appendDifferential();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}
	
	public void appendFraction() {
		focus = focus.appendFraction();
		if(redrawListener != null) redrawListener.onRedraw(this);
	}

	public void setOnRedrawListener(OnRedrawListener listener) {
		this.redrawListener = listener;
		
	}
	
	/**
	 * The object to notify when the appearance of the 
	 * expression changes
	 */
	OnRedrawListener redrawListener;

	public Box toDrawable() {
		top.setTouchHandler(this);
		return top.toDrawable(true);
	}

	public String toReduce() {
		// number of left brackets == number of right brackets.
		String result = top.toReduce();

		// Could be better off without this feature
		// But I will leave it anyways
		
		//		while(nonClosedBrackets < 0) {
		//			// remove as many 
		//			if(result.endsWith(")")) {
		//				result = result.substring(0, result.length()-1);
		//				nonClosedBrackets++;
		//			} else break;
		//		}
			
		return result;
	}



	public void append(WrapperExpression e) {
		focus = focus.append(e);
		if(redrawListener != null) redrawListener.onRedraw(this);		
	}
	
	public ExpressionBuilder copy() {
		ExpressionBuilder result = new ExpressionBuilder();
		result.top = top.copy();
		result.focus = result.top;
		result.takePointerToTheRightEnd();
		return result;
	}

	public void undoSquare() {
		// suppose we start with "x^[2]|" (where "|" is the cursor)
		// go inside the superscript "x^[2|]"
		this.deletePreviousInternal();
		// delete the 2: "x^[|]"
		this.deletePreviousInternal();
		// delete the superscript "x|"
		this.deletePrevious();
		
	}
	
	@Override
	public void onTouch(final Object o) {
		if(keyboard == null || focusListener == null || !focusListener.onRequestGainFocus(this)) return;
		keyboard.execute(new Action() {
			
			int movedPositions = 0;
			
			@Override
			public void exec() {
				gainFocus();
				movedPositions = takePointerToTheRightEnd();
				//gainFocusAndTakePointerToTheRightInternal();
				while(!focus.haveReached(o)) {
					moveCursorToTheLeftInternal();
				}
				keyboard.redo(); // So that moving the cursor is not counted as an event worthy of undo
				if(redrawListener != null) redrawListener.onRedraw(ExpressionBuilder.this);
				
			}

			@Override
			public void undo() {
				takePointerToTheRightEnd();
				for(int i=0; i<movedPositions; i++)
					moveCursorToTheLeftInternal();
				keyboard.undo(); // So that cursor movement is not counted as an event worthy of undo
				if(redrawListener != null) redrawListener.onRedraw(ExpressionBuilder.this);
			}
		});
	}



	public void setKeyboardInterface(Keyboard kb) {
		keyboard = kb;
		
//		ExpressionBuilder builder = new ExpressionBuilder(); 
//		
//		builder.appendSymbol("1"); 
//		builder.appendSymbol(S.plus); 
//		builder.appendSqrt(); 
//		builder.appendSymbol(S.x);
//		
//		// the drawable version of this expression 
//		Box boxTree = builder.toDrawable();
//		
//		String reduceString = builder.toReduce();
	}
	
	Keyboard keyboard;

	@Override
	public float proximity(float x, float y) {
		// TODO: think about removing this
		return 0;
	}
}
