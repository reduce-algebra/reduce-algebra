package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;

public class IntegralBox extends SequenceBox {
	public IntegralBox(Box integrand, Box wrt, Box upperLimit, Box lowerLimit) {
		super(
				new ScriptBox(
						new LargeOperatorSymbolBox(LargeOp.integral),
						upperLimit,
						lowerLimit),
				new SpaceBox(C.integral_with_limits_right_margin_factor,0.05f),
				integrand,
				new SymbolBox(".d"),
				wrt);
	}
	
	public IntegralBox(Box integrand, Box wrt) {
		super(
				new LargeOperatorSymbolBox(LargeOp.integral),
				integrand,
				new SymbolBox(".d"),
				wrt);
	}
}
