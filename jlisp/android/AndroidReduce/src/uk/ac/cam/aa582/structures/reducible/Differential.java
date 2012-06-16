package uk.ac.cam.aa582.structures.reducible;


import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.FractionBox;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;

public class Differential extends WrapperExpression {

	Sequence body = sequences[1];
	Sequence wrt = sequences[0];
	
	public Differential() {
		super(new Sequence(), new Sequence());
	}
	
	private Differential(Sequence[] seq) {
		super(seq);
	}
	
	@Override
	protected String toReduce() {

		return String.format("df(%s,%s)", body.toReduce(), wrt.toReduce());
	}

	@Override
	public Box toDrawable() {
		Expression e = body.getExpressionAt(0);
		if(e instanceof Differential && this.wrt.isEmpty()) {
			return new SequenceBox(
					new FractionBox( new SymbolBox("d"), new SequenceBox(new SymbolBox("d"), wrt.toDrawable())),
					new SymbolBox("("),
					body.toDrawable(),
					new SymbolBox(")")
				);
		} else { 
			return new SequenceBox(
					new FractionBox( new SymbolBox("d"), new SequenceBox(new SymbolBox("d"), wrt.toDrawable())),
					new SymbolBox("("),
					body.toDrawable(),
					new SymbolBox(")")
				);
		}
	}

	@Override
	public Differential copy() {
		return new Differential(copyAll(sequences));
	}
}
