package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.Delimiters;

public class AbsoluteValue extends WrapperExpression {
	
	Sequence innerExpression = sequences[0];
	
	public AbsoluteValue() {
		super(new Sequence());
	}
	private AbsoluteValue(Sequence s) {
		super(s);
	}

	@Override
	protected String toReduce() {
		return String.format("abs(%s)",innerExpression.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new DelimiterBox(innerExpression.toDrawable(), Delimiters.abs);
	}

	@Override
	public AbsoluteValue copy() {
		return new AbsoluteValue(innerExpression.copy());
	}
}
