package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.S;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.ScriptBox.ScriptMode;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;

public class Limit extends WrapperExpression {
	
	Sequence variable = sequences[0];
	Sequence limit = sequences[1];
	Sequence body = sequences[2];
	
	public Limit(Sequence... seq) {
		super(seq);
	}
	
	public Limit() {
		super(new Sequence(), new Sequence(), new Sequence());
	}

	@Override
	public Expression copy() {
		return new Limit(copyAll(sequences));
	}

	@Override
	protected String toReduce() {
		return String.format("limit(%s,%s,%s)", body.toReduce(), variable.toReduce(), limit.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SequenceBox(
					new ScriptBox(
						new SymbolBox("lim"), null,
						new SequenceBox(
								variable.toDrawable(), 
								new SymbolBox(S.rightarrow),
								limit.toDrawable()), ScriptMode.overunder),
					new SymbolBox("("), 
					body.toDrawable(), 
					new SymbolBox(")"));
	}

}
