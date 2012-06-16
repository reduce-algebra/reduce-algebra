package uk.ac.cam.aa582.structures.boxes;

/**
 * The usual way to display symbols is the {@link SymbolBox}
 * however it is inadequate for large operators such as big
 * sum or integral sign, since they define a very peculiar baseline
 * and would like to insert margins to their right. So this 
 * Box is used instead.
 * 
 * @author Ahmad Akra
 *
 */
public class LargeOperatorSymbolBox extends SymbolBox {

	public enum LargeOp {
		integral, ointegral, sum, prod
	}

	private float squeezeFactor = 1.0f;
	private LargeOp op;
	
	public LargeOperatorSymbolBox(LargeOp op) {
		this(op, 1.0f);
	}
	
	private LargeOperatorSymbolBox(LargeOp op, float squeezingFactor) {
		super(symbolOf(op, Size.large));
		
		this.squeezeFactor = squeezingFactor;
		if(op != null) this.op = op;
		else this.op = LargeOp.integral;
	}
	
	private static short symbolOf(LargeOp op, Size s) {
		switch(op) {
		case integral : return s == Size.large ? S.int_large : S.int_small;
		case sum : return s == Size.large ? S.sum_large : S.int_small;
		case prod : return s == Size.large ? S.prod_large : S.prod_small;
		case ointegral : return s == Size.large ? S.oint_large : S.oint_small;
		}
		return S.int_large; // should not reach here
	}

	@Override
	public float axis(){
		return this.height() / 2;
	}
	
	@Override
	public float width(){
		return graphics.boundingWidth(this.getSymbol(), font, fontNumber, fontSize()) + rightMargin();
	}
	
	@Override
	public void setStyle(TexStyle style){
		if(TexRules.opSize(style) == Size.large)
			symbol = largeVersionOf(symbol()) +"";
		else
			symbol = smallVersionOf(symbol()) +"";
		super.setStyle(style);
	}

	private float rightMargin() {
		// TODO needs some reworking
		// this is saying that no right margins should be used
		// if the superscript and subscript are over and under
		// the large operator, because that would make them look skewed.
		if((style == TexStyle.D || style == TexStyle.DC) && 
				(op == LargeOp.sum || op == LargeOp.prod)) return 0f;
		if(TexRules.opSize(style) == Size.large) {
			return C.large_operator_right_margin_factor * fontSize() * squeezeFactor ;
		}
		else return C.small_operator_right_margin_factor * fontSize() * squeezeFactor;
	}	
	
	private char largeVersionOf(char symbol) {
		if(symbol == S.symbol(S.int_small)) return S.symbol(S.int_large);
		if(symbol == S.symbol(S.sum_small)) return S.symbol(S.sum_large);
		if(symbol == S.symbol(S.prod_small)) return S.symbol(S.prod_large);
		if(symbol == S.symbol(S.oint_small)) return S.symbol(S.oint_large);
		return symbol;
	}
	
	private char smallVersionOf(char c) {
		if(c == S.symbol(S.int_large)) return S.symbol(S.int_small);
		if(c == S.symbol(S.sum_large)) return S.symbol(S.sum_small);
		if(c == S.symbol(S.prod_large)) return S.symbol(S.prod_small);
		if(c == S.symbol(S.oint_large)) return S.symbol(S.oint_small);
		return c;
	}

	private char symbol() {
		return symbol.charAt(symbol.length() -1);
	}
	
	@Override
	public float superscriptShift(){
		if(symbol() == S.symbol(S.int_large)) 
			return C.large_integral_superscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.int_small))
			return C.small_integral_superscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.sum_large)) 
			return C.large_sum_and_prod_superscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.sum_small))
			return 0f;
		if(symbol() == S.symbol(S.prod_large)) 
			return C.large_sum_and_prod_superscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.prod_small))
			return 0f;
		if(symbol() == S.symbol(S.oint_large)) 
			return C.large_integral_superscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.oint_small))
			return C.small_integral_superscript_shift_factor * fontSize();
		return 0.0f;
	}
	
	@Override
	public float subscriptShift(){
		if(symbol() == S.symbol(S.int_large)) 
			return C.large_integral_subscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.int_small))
			return C.small_integral_subscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.sum_large)) 
			return C.large_sum_and_prod_subscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.sum_small))
			return 0f;
		if(symbol() == S.symbol(S.prod_large)) 
			return C.large_sum_and_prod_subscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.prod_small))
			return 0f;
		if(symbol() == S.symbol(S.oint_large)) 
			return C.large_integral_subscript_shift_factor * fontSize();
		if(symbol() == S.symbol(S.oint_small))
			return C.small_integral_subscript_shift_factor * fontSize();
		return 0.0f;
	}	
	
	@Override
	public float getSquashingDistance() {
		return rightMargin();
	}
	
	@Override
	public Box squash(float factor) {
		LargeOperatorSymbolBox result = new LargeOperatorSymbolBox(this.op, factor);
		result.setGraphics(graphics);
		return result;
	}
}
