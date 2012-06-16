package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.*;

public class SolveCommand extends WrapperExpression {
	
	Sequence equations = sequences[0];
	Sequence variables = sequences[1];
	
	public SolveCommand(Sequence[] seq) {
		super(seq);
	}
	
	public SolveCommand() {
		super(new Sequence(), new Sequence());
	}

	@Override
	public Expression copy() {
		return new SolveCommand(copyAll(sequences));
	}

	@Override
	protected String toReduce() {
		return String.format("solve({%s},{%s})",equations.toReduce(), variables.toReduce());
	}

	@Override
	public Box toDrawable() {
		return new SequenceBox(
				new SymbolBox("solve"), 
				new SpaceBox(),
				new SymbolBox(S.bracket_curly_left_tiny),
				equations.toDrawable(), 
				new SymbolBox(S.bracket_curly_right_tiny),
				new SpaceBox(),
				new SymbolBox("for"),
				new SpaceBox(),
				new SymbolBox(S.bracket_curly_left_tiny),
				variables.toDrawable(),
				new SymbolBox(S.bracket_curly_right_tiny));
	}

}
