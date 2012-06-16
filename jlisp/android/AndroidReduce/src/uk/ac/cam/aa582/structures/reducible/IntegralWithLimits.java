package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.IntegralBox;

public class IntegralWithLimits extends WrapperExpression {
	
	Sequence integrand = sequences[0];
	Sequence wrt = sequences[1];
	Sequence lowerlimit = sequences[2];
	Sequence upperlimit = sequences[3];
	
	public IntegralWithLimits() {
		super(new Sequence(), new Sequence(), new Sequence(), new Sequence());
	}
	
	private IntegralWithLimits(Sequence[] seq) {
		super(seq);
	}
	
	@Override
	protected String toReduce() {
		// TODO Auto-generated method stub
		return String.format("int(%s,%s,%s,%s)",integrand.toReduce(), wrt.toReduce(), lowerlimit.toReduce(), upperlimit.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new IntegralBox(integrand.toDrawable(), wrt.toDrawable(), upperlimit.toDrawable(), lowerlimit.toDrawable());
	}

	@Override
	public IntegralWithLimits copy() {
		return new IntegralWithLimits(copyAll(sequences));
	}
}
