package uk.ac.cam.aa582.structures.reducible;


import uk.ac.cam.aa582.structures.boxes.*;

public class Integral extends WrapperExpression {
	
	private Sequence integrand = sequences[0];
	private Sequence wrt = sequences[1];

	public Integral(){
		super(new Sequence(), new Sequence());
	}
	private Integral(Sequence[] seq) {
		super(seq);
	}
	
	@Override
	protected String toReduce() {
		return String.format("int(%s,%s)", integrand.toReduce(), wrt.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new IntegralBox(integrand.toDrawable(), wrt.toDrawable());
	}
	@Override
	public Integral copy() {
		return new Integral(copyAll(sequences));
	}
}
