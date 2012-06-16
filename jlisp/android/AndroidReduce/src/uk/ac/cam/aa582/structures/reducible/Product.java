package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox;
import uk.ac.cam.aa582.structures.boxes.LargeOperatorSymbolBox.LargeOp;
import uk.ac.cam.aa582.structures.boxes.S;
import uk.ac.cam.aa582.structures.boxes.ScriptBox;
import uk.ac.cam.aa582.structures.boxes.SequenceBox;
import uk.ac.cam.aa582.structures.boxes.SymbolBox;

public class Product extends WrapperExpression {

	Sequence variable = sequences[0];
	Sequence lowerlimit = sequences[1];
	Sequence upperlimit = sequences[2];
	Sequence body = sequences[3];
	
	public Product() {
		super(new Sequence(), new Sequence(), new Sequence(), new Sequence());
	}
	
	private Product(Sequence[] seq) {
		super(seq);
	}

	@Override
	protected String toReduce() {
		return String.format("prod(%s,%s,%s,%s)", body.toReduce(), variable.toReduce(), lowerlimit.toReduce(), upperlimit.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SequenceBox(
				new ScriptBox(
						new LargeOperatorSymbolBox(LargeOp.prod), 
						upperlimit.toDrawable(), 
						new SequenceBox(variable.toDrawable(), new SymbolBox(S.equals),lowerlimit.toDrawable())), 
				new SymbolBox("("), 
				body.toDrawable(), 
				new SymbolBox(")"));
	}
	
	@Override
	public Product copy() {
		return new Product(copyAll(sequences));
	}
}
