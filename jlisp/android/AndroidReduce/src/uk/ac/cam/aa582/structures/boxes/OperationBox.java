package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * <tt> x + 2y </tt> is a OperationBox with left <tt>'x'</tt>,
 * right <tt>'2y'</tt> and operation <tt>'+'</tt>
 * 
 * @author Ahmad Akra
 *
 */
public class OperationBox extends SequenceBox {
	
	float squeezingFactor = 1f;
	short op;
	private SymbolBox opBox;

	public OperationBox(short op, Box left, Box right) {
		this(op, left, right, 1f);
	}	
	
	private OperationBox(short op, Box left, Box right, float squeezingFactor) {
		super( 
				(left == null) ? defaultBox() : left, 
						new SymbolBox(op),  
				(right == null) ? defaultBox() : right
			);
		
		this.squeezingFactor = squeezingFactor;
		this.op = op;
	}
	
	public OperationBox(SymbolBox op, Box left, Box right) {
		this(op, left, right, 1f);
	}
	
	private OperationBox(SymbolBox op, Box left, Box right, float squeezingFactor) {
		super( 
				(left == null) ? defaultBox() : left, 
						op,  
				(right == null) ? defaultBox() : right
			);
		
		this.squeezingFactor = squeezingFactor;
		this.opBox = op;
	}
	
	private static float operatorSpaceFactor() {
		return C.operation_symbol_margin_factor;
	}
	
	@Override
	protected float interBoxMargin(){

		if(TexRules.operationMarginsExist(style)) {
			return operatorSpaceFactor() * fontSize() * squeezingFactor;
		}
		else return 0f;
	}
	

	
	@Override
	public float getSquashingDistance() {
		return 2 * interBoxMargin() + super.getSquashingDistance();
	}
	
	@Override
	public Box squash(float factor) {
		OperationBox result;
		if(opBox == null) { 
			result = new OperationBox(
					op, 
					boxes[0].squash(factor),
					boxes[2].squash(factor), 
					factor);
		} else {
			result = new OperationBox(
					opBox, 
					boxes[0].squash(factor),
					boxes[2].squash(factor), 
					factor);
		}
		result.setState(this);
		return result;
	}
	
	@Override
	public Box[] split(Level level) {
		 // can split before the operator and after the operator
		return concat(boxes[0].split(level),
						new Box[] { boxes[1] },
						boxes[2].split(level));
	}
}
