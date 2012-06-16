package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;

/**
 * This is basically a {@link ScriptBox} that knows where
 * to position the superscript and subscript for large
 * operators (for big sum and big product, the superscript
 * and subscript should be above and below the symbol if the
 * symbol is in display style).
 * 
 * 
 * @author Ahmad Akra
 *
 */
public class LargeOperatorBox extends ScriptBox {
	
	/**
	 * I use this to remember which large operator we're dealing with,
	 * this is useful in the {@link LargeOperatorBox#setStyle(TexStyle)
	 * method to determine where to put the superscript and the subscript
	 */
	private LargeOp op;

	/**
	 * Constructor
	 * 
	 * @param op Which large operator to use (integral, sum, etc..)
	 * @param subscript The box to use as a subscript for the large operator
	 * @param superscript The box to use as a superscript for the large operator
	 */
	public LargeOperatorBox(LargeOp op, Box subscript, Box superscript) {
		super(new LargeOperatorSymbolBox(op), superscript, subscript);
		this.op = op == null ? LargeOp.integral : op;
	}
	
	/**
	 * Constructor
	 * 
	 * @param op Which large operator to use (integral, sum, etc..)
	 * @param subscript The box to use as a subscript for the large operator
	 */
	public LargeOperatorBox(LargeOp op, Box subscript) {
		this(op, null, subscript);
	}
	
	/**
	 * If you want to use this constructor, you are better off
	 * using the {@link LargeOperatorSymbolBox} directly and don't bother
	 * with this class.
	 * 
	 * @param op Which large operator to use (integral, sum, etc..)
	 */
	public LargeOperatorBox(LargeOp op) {
		this(op, null, null);
	}

	@Override
	public void setStyle(TexStyle style) {
		
		// According to TeX rules, if we're in display style 
		// (or cramped display style) the superscript and subscript 
		// of the large sum and large product should appear over
		// and under the symbol, otherwise they appear to the
		// right of it as normal.
	
		if(op == LargeOp.sum || op == LargeOp.prod) {
			if(style == TexStyle.D || style == TexStyle.DC) {
				this.scriptMode = ScriptMode.overunder;
			} else {
				this.scriptMode = ScriptMode.side;
			}
		}
		super.setStyle(style);
	}

}
