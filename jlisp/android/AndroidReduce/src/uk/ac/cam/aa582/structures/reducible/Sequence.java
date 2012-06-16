package uk.ac.cam.aa582.structures.reducible;

import java.util.LinkedList;
import java.util.Stack;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.C;
import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;

public class Sequence extends Expression {

	private interface UndoAction {
		void exec();
	}

	private int pointer = 0;
	private boolean isParent = false;
	private boolean hidePointer = true;
	private LinkedList<Expression> expressions = new LinkedList<Expression>();
	private Sequence rightSequence = null;
	private Sequence leftSequence = null;
	private Stack<UndoAction> undoStack = new Stack<UndoAction>();
	
	protected boolean isEmpty() {
		return expressions.size() == 0;
	}
	
	public Sequence setRightSequence(Sequence r) {
		rightSequence = r;
		return this;
	}
	
	public Sequence setLeftSequence(Sequence l) {
		leftSequence = l;
		return this;
	}
	
	@Override
	protected String toReduce() {
		String result = "";
		// String prevReduce = null;
		
		// this inserts multiplication sign between
		// say x and y in "xy", or "xsin(x)"
		// changing them into "x*y" and "x*sin(x)"
		// I felt it is more intuitive to the user.
		// to interpret xsin(x) as x*sin(x) rather
		// then some function xsin applied to x.
		// and therefore Reduce should have the same
		// interpretation which it doesn't by default
		// unfortunately.
//		for(Expression e : expressions) {
//			//TODO: make sure something like m3sqrt never happens
//			//TODO: also take care of "E" and "i"
//			String eReduce = e.toReduce();
//			if(prevReduce != null && 
//					eReduce.matches("[a-zA-Z\\(].*") && // begins with a letter or a bracket
//					prevReduce.matches(".*[a-zA-Z\\)]")) { // ends with a letter or a bracket
//				result += "*";
//			}
//			result += eReduce;
//			prevReduce = eReduce;
//		}
		
		boolean afterLetter = false;
		boolean afterBracket = false;
		for(Expression e : expressions) {
			String eReduce = e.toReduce(); 
			// if preceded with a letter or a bracket
			if(eReduce.matches("[a-zA-Z\\(].*")) {
				if(afterLetter || afterBracket) 
					result += "*";				
			}
			result += eReduce;

			if(eReduce.matches(".*[0-9]")) {
				// leave afterLetter as it is
				afterBracket = false;
			} else if(eReduce.matches(".*[a-zA-Z]")) {
				afterLetter = true;
				afterBracket = false;
				
			} else if(eReduce.endsWith(")")) {
				afterLetter = false;
				afterBracket = true;
			} else {
				afterLetter = false;
				afterBracket = false;
			}
		}
		
		// Reduce by default does not do that (e.g. if I
		// input "sin(x" into reduce, it will complain about
		// missing brackets, so I fix the brackets here
		// before sending the string input to reduce.
		
		// Calculate the number of missing right brackets
		int nonClosedBrackets = 0;
		for(int i=0; i<result.length(); i++) {
			if(result.charAt(i)=='(')
				nonClosedBrackets++;
			else if(result.charAt(i)==')')
				nonClosedBrackets--;
		}
		// add missing closing brackets at the end
		while(nonClosedBrackets > 0) {
			result += ")";
			nonClosedBrackets--;
		}
		
		return result;
	}

	@Override
	public Box toDrawable() {
		return toDrawable(false);
	}
	
	@Override
	public Sequence copy() {
		Sequence seqCopy = new Sequence();
		for(int i=0; i< expressions.size(); i++) {
			Expression exCopy = expressions.get(i).copy();
			seqCopy.expressions.add(exCopy);
			if(exCopy instanceof WrapperExpression)
				seqCopy.leftRight((WrapperExpression) exCopy);
		}
		return seqCopy;
	}
	
	public Box toDrawable(boolean isTopLevel) {
		// If there is nothing in the sequence
		// and this is the top sequence in the hierarchy
		if(expressions.size() == 0 && !isTopLevel) {
			// Draw a space box with borders (small rectangle with visual pointer)
			return new SequenceBox(new SpaceBox().showBorder().registerTouchHandler(handler, this))
							.setVisualPointer(hidePointer ? -1 : 0);
		// Else if there is nothing in the sequence
		// and this is not the top sequence in the hierarchy
		} else if (expressions.size() == 0 && isTopLevel) {
			// Draw a space box without borders (just to show the visual pointer)
			return new SequenceBox(new SpaceBox().registerTouchHandler(handler, this))
							.setVisualPointer(hidePointer ? -1 : 0);			
		} else {
			Box[] boxes = new Box[expressions.size()];
			int i=0;
			boolean afterLetter = false;
			for(Expression e : expressions) {
				// If the this expression is a variable name (e.g. x)
				if(e instanceof Symbol && e.toReduce().matches(".*[a-zA-DF-Z]")) { 
					// Draw as normal, but set flag to indicate that
					// what follows comes after a variable name
					afterLetter = true;
					boxes[i] = e.toDrawable();
				}
				// else if this expression is a symbol
				else if(e instanceof Symbol && e.toReduce().matches("[0-9]")) {
					// Need care when drawing digits
					if(afterLetter)
						// This line is very ugly but it does the job
						// If digit comes immediate after letter, make it subscript
						boxes[i] = new ScriptBox(
								new SpaceBox(-C.base_superscript_margin_factor-C.script_box_right_margin,0f), 
								null, // superscript
								e.toDrawable()); // subscript
					else
						// Else draw the digit normally
						boxes[i] = e.toDrawable();
				// else (if the expression is neither a variable nor a number)
				} else {
					// set a flag to indicate that we are not after
					// a variable name any more (don't draw digits as subscripts)
					afterLetter = false;
					boxes[i] = e.toDrawable();
				}
				
				i++;
			}
			
			return new SequenceBox(boxes).setVisualPointer(hidePointer? -1 : pointer);
		}
	}

	public void insert(Expression e) {
		//expressions.add(pointer, e);
		expressions.add(pointer, e);
		this.movePointerToTheRight();
	}
	
	public Sequence movePointerToTheRight() {
		if(pointer >= expressions.size()) {
			if(rightSequence != null) { // has reached the end and there is a right sequence, let it take over
				this.loseFocus();
				rightSequence.gainFocus();
				if(rightSequence.isParent) { 
					rightSequence.pointer++; 
					rightSequence.isParent = false; 
				}
				return rightSequence;
			} else { // has reached the end and there isn't a right sequence => stay in place
				return this;
			}
		} else { // somewhere in the middle
			Expression e = expressions.get(pointer);
			if(e instanceof Symbol) {
				pointer++;
				return this;
			} else {
				WrapperExpression wrapper = (WrapperExpression) e;
				Sequence seq = wrapper.getLeftmostSequence();
				this.isParent = true;
				this.loseFocus();
				seq.gainFocus();
				return seq;
			}
		}
	}
	


	public Sequence movePointerToTheLeft() {
		if(pointer <= 0) {
			if(leftSequence != null) { // has reached the end and there is a left sequence, let it take over
				this.loseFocus();
				leftSequence.gainFocus();
				if(leftSequence.isParent) {
					leftSequence.isParent = false;
				}
				return leftSequence;
			} else { // has reached the end and there isn't a right sequence => stay in place
				return this;
			}
		} else { // somewhere in the middle
			Expression e = expressions.get(pointer-1);
			if(e instanceof Symbol) {
				pointer--;
				return this;
			} else {
				WrapperExpression wrapper = (WrapperExpression) e;
				Sequence seq = wrapper.getRightmostSequence();
				this.pointer--;
				this.isParent = true;
				this.loseFocus();
				seq.gainFocus();
				return seq;
			}
		}
	}
	
	public Sequence loseFocus() {
		hidePointer = true;
		return this;
	}
	
	public Sequence gainFocus() {
		hidePointer = false;
		return this;
	}
	
	public boolean isFocused() {
		return !hidePointer;
	}
	
	public Sequence deleteNext() {
		if(pointer == expressions.size()) {
			// for undo don't do anything
			undoStack.push(new UndoAction() { @Override public void exec() { } });
			return this;
		}
		else {
			final Expression e = expressions.get(pointer);
			if(e instanceof Symbol) {
				expressions.remove(pointer);
				undoStack.push(new UndoAction() { @Override public void exec() { expressions.add(pointer, e); } });
				
			} else {
				final WrapperExpression wrapper = (WrapperExpression) e;
				expressions.remove(pointer);
				int offset = 0;
				for(Sequence seq : wrapper) {
					for(Expression exp : seq.expressions) {
						expressions.add(pointer+offset,exp);
						offset++;
						if(exp instanceof WrapperExpression)
							leftRight((WrapperExpression) exp);
					}
				}
				
				// this one is tricky
				undoStack.push(new UndoAction() {
					
					@Override public void exec() {
						for(Sequence seq : wrapper) {
							for(Expression exp : seq.expressions) {
								expressions.remove(exp);
							}
						}
						for(Sequence seq : wrapper) {
							for(Expression exp : seq.expressions) {
								if(exp instanceof WrapperExpression)
									seq.leftRight((WrapperExpression) exp);
							}
						}
						Sequence.this.leftRight(wrapper);
						expressions.add(pointer, wrapper);
					}
				});
			}
			return this;
		}
	}
	
	public void undoDeleteNext() {
		UndoAction undo = undoStack.pop();
		undo.exec();
	}
	
	/**
	 * 
	 * @param s
	 * @return new Sequence of focus
	 */
	public Sequence appendSymbol(String s) {
		insert(new Symbol(s));
		return this;
	}
	
	/**
	 * 
	 * @param s
	 * @return new Sequence of focus
	 */
	public Sequence appendSymbol(short s) {
		insert(new Symbol(s));
		return this;
	}

	
	/**
	 * 
	 * @return new Sequence of focus
	 */
	public Sequence raiseToPower() {
		
		Power power = new Power();
		leftRight(power);
		insert(power); // TODO solve the problem of power elevation
		return power.getLeftmostSequence();
	}
	
	/**
	 * 
	 * @return new Sequence of focus
	 */
	public Sequence appendSqrt() {

		Sqrt sqrt = new Sqrt();
		leftRight(sqrt);
		insert(sqrt);
		
		return sqrt.getLeftmostSequence();
	}
	
	/**
	 * 
	 * @return new Sequence of focus
	 */
	public Sequence appendIntegral() {

		
		Integral i = new Integral();
		leftRight(i);
		insert(i);
		return i.getLeftmostSequence();
	}
	
	/**
	 * 
	 * @return new Sequence of focus
	 */
	public Sequence appendIntegralWithLimits() {

		IntegralWithLimits i = new IntegralWithLimits();
		return append(i);
	}
	
	public Sequence appendSummation() {
		
		Summation s = new Summation();
		return append(s);
	}
	
	public Sequence append(WrapperExpression e) {
		leftRight(e);
		insert(e);
		return e.getLeftmostSequence();
	}
	
//	public Sequence append(Expression e) {
//		insert(e);
//		return this;
//	}
	
	/**
	 * 
	 * @return new Sequence of focus
	 */
	public Sequence appendDifferential() {
		
		Differential diff = new Differential();
		leftRight(diff);
		insert(diff);

		return diff.getLeftmostSequence();
	}
	
	public Sequence appendFraction() {
		Fraction frac = new Fraction();
		leftRight(frac);
		insert(frac);
		return frac.getLeftmostSequence();
	}

	private void leftRight(WrapperExpression e) {
		e.getLeftmostSequence().setLeftSequence(this);
		e.getRightmostSequence().setRightSequence(this);
	}

	public boolean pointerAtRightEnd(){
		return pointer == expressions.size();
	}
	
	public boolean pointerAtLeftEnd(){
		return pointer == 0 && !isParent;
	}

	@Override
	public void setTouchHandler(OnTouchHandler<Object> touchHandler) {
		handler = touchHandler;
		for(Expression exp : this.expressions) {
			exp.setTouchHandler(touchHandler);
		}
		
	}
	OnTouchHandler<Object> handler;
	

	public boolean haveReached(Object arg) {
		return (this == arg) ||(pointer != 0 && expressions.get(pointer-1) == arg);
	}

	public Expression getNext() {
		if(expressions.size() == pointer) return null;
		else return expressions.get(pointer);
	}
	
	protected Expression getExpressionAt(int index) {
		if(index > expressions.size()-1 || index < 0)
			return null;
		else return expressions.get(index);
	}

//	public Sequence shallowCopy() {
//		Sequence seq = new Sequence();
//		seq.andHalf = this.andHalf;
//		seq.pointer = this.pointer;
//		seq.handler = this.handler;
//		seq.hidePointer = this.hidePointer;
//		seq.leftSequence = this.leftSequence;
//		seq.rightSequence = this.rightSequence;
//		return null;
//	}
}
