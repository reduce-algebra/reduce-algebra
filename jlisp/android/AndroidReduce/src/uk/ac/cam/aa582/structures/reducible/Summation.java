package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;
import uk.ac.cam.aa582.structures.boxes.*;

public class Summation extends WrapperExpression {
	
	Sequence variable = sequences[0];
	Sequence lowerlimit = sequences[1];
	Sequence upperlimit = sequences[2];
	Sequence body = sequences[3];
	
	public Summation() {
		super(new Sequence(), new Sequence(), new Sequence(), new Sequence());
	}
	
	private Summation(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("sum(%s,%s,%s,%s)", body.toReduce(), variable.toReduce(), lowerlimit.toReduce(), upperlimit.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SequenceBox(
				new ScriptBox(
						new LargeOperatorSymbolBox(LargeOp.sum), 
						upperlimit.toDrawable(), 
						new SequenceBox(variable.toDrawable(), new SymbolBox(S.equals),lowerlimit.toDrawable())), 
				new SymbolBox("("), 
				body.toDrawable(), 
				new SymbolBox(")"));
	}
	
	@Override
	public Summation copy() {
		return new Summation(copyAll(sequences));
	}
}
