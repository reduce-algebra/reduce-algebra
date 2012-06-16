package uk.ac.cam.aa582.structures.reducible;


import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.SqrtBox;

public class Sqrt extends WrapperExpression {

	// The body of the square root
	private Sequence body = sequences[0];
	
	public Sqrt() {
		super(new Sequence());
	}
	
	private Sqrt(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("sqrt(%s)", body.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SqrtBox(body.toDrawable());
	}
	
	@Override
	public Sqrt copy() {
		return new Sqrt(copyAll(sequences));
	}
}
