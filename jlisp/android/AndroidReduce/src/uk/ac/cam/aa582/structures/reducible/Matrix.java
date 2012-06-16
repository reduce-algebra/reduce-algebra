package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;

public class Matrix extends WrapperExpression {
	
	int rowCount = 0;
	int colCount = 0;
	
	/**
	 * matrix[column][row]
	 */
	Expression[][] matrix;
	
	public Matrix(int rows, int cols) {
		this(rows, cols, initializedSequenceArray(rows*cols));
	}
	
	public Matrix(int rows, int cols, Sequence[] seq) {
		super(seq);
		
		rowCount = rows;
		colCount = cols;
		matrix = new Expression[colCount][rowCount];

		for(int c=0; c<colCount; c++) {
			for(int r=0; r<rowCount; r++) {
				matrix[c][r] = sequences[(r*colCount) + c];
			}
		}
	}
	

	@Override
	public Expression copy() {
		return new Matrix(rowCount, colCount, copyAll(sequences));
	}

	@Override
	protected String toReduce() {
		// According to Reduce documentation:
		// result := mat((row1),(row2),..,(rown));
		// rowString := (x1,x2,...,xn)
		
		String result = "mat(";
		for(int r=0; r<rowCount; r++) {
			String rowString = "";
			for(int c=0; c<colCount; c++) {
				Expression exp = matrix[c][r];
				rowString += exp.toReduce();
				rowString += (c==colCount-1) ? "" : ",";
			}
			result += String.format("(%s)" + ((r==rowCount-1) ? "" : ","), rowString);
		}		
		result += ")";
		return result;
	}

	@Override
	public Box toDrawable() {
		Box[] boxes = new Box[sequences.length];
		for(int i=0; i<boxes.length; i++)
			boxes[i] = sequences[i].toDrawable();
		return Box.newMatrix(rowCount, colCount, boxes);
	}

}
