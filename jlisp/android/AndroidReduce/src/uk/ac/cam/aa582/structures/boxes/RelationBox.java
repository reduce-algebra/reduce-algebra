package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * <tt> x = 2y </tt> is a RelationBox with left <tt>'x'</tt>,
 * right <tt>'2y'</tt> and relation <tt>'='</tt>
 * 
 * @author Ahmad Akra
 *
 */
public class RelationBox extends SequenceBox {

	public RelationBox(short relation, Box left, Box right) {
		this(relation, left, right, 1f);
	}	
	
	private RelationBox(short relation, Box left, Box right, float squeezingFactor) {
		super( 
				(left == null) ? defaultBox() : left, 
						new SymbolBox(relation),  
				(right == null) ? defaultBox() : right
			);
		
		this.squeezingFactor = squeezingFactor;
		this.relation = relation;
	}	

	private static float relationSpaceFactor() {
		return C.relation_symbol_display_margin_factor;
	}
	
	@Override
	protected float interBoxMargin(){

		if(TexRules.relationMarginsExist(style)) {
			return relationSpaceFactor() * fontSize() * squeezingFactor;
		}
		else return 0f;
	}
	
	float squeezingFactor = 1f;
	short relation;
	
	@Override
	public float getSquashingDistance() {
		return 2 * interBoxMargin() + super.getSquashingDistance();
	}
	
	@Override
	public Box squash(float factor) {
		RelationBox result = new RelationBox(
				relation, 
				boxes[0].squash(factor),
				boxes[2].squash(factor), 
				factor);	
		result.setState(this);
		return result;
	}
	
	@Override
	public Box[] split(Level level) {
		// can split before the relation sign and after the relation sign
		return concat(boxes[0].split(level),
				new Box[] { boxes[1] },
				boxes[2].split(level));
	}
}
