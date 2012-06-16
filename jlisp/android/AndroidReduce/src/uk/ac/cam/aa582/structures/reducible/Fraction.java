package uk.ac.cam.aa582.structures.reducible;


import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.FractionBox;

public class Fraction extends WrapperExpression {
	
	Sequence num = sequences[0];
	Sequence denom = sequences[1];
	
	public Fraction(){
		super(new Sequence(), new Sequence());
	}
	
	private Fraction(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("((%s)/(%s))", num, denom);
	}

	@Override
	public Box toDrawable() {

		return new FractionBox(num.toDrawable(), denom.toDrawable());
	}

	@Override
	public Fraction copy() {
		return new Fraction(copyAll(sequences));
	}

}
