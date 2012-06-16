package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;

public class Logarithm extends WrapperExpression {
	
	Sequence base = sequences[0];
	Sequence body = sequences[1];
	
	public Logarithm() {
		super(new Sequence(), new Sequence());
	}
	
	private Logarithm(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("logb(%s,%s)",body.toReduce(), base.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SequenceBox(
				new ScriptBox( new SymbolBox("log"), null, base.toDrawable()),
				new SymbolBox("("),
				body.toDrawable(),
				new SymbolBox(")")
			);
	}

	@Override
	public Logarithm copy() {
		return new Logarithm(copyAll(sequences));
	}

	
}
