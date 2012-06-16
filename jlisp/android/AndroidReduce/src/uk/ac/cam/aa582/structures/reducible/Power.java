package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SpaceBox;

public class Power extends WrapperExpression {

	private Sequence power = sequences[0];
	
	public Power() { super(new Sequence()); }
	
	/**
	 * For making deep copying
	 * 
	 */
	private Power(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("^(%s)",power.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new ScriptBox(new SpaceBox(0.0f,0.0f), power.toDrawable());
	}
	
	
	@Override
	public Power copy() {
		return new Power(copyAll(sequences));
	}
}
