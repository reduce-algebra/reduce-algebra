package uk.ac.cam.aa582.structures.boxes;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * This Box represents a matrix, the dimensions of the matrix
 * can be specified through the constructor along with the boxes
 * to arrange in the matrix.<br/>
 * The matrix has a pair of large parenthesis surrounding it by
 * default, but this can be overridden and curly brackets can be
 * used instead or square brackets or absolute value bars. (e.g.
 * matrix determinant) <br/>
 * The matrix is implemented as a {@link DelimiterBox} wrapping
 * a {@link TableBox}
 * 
 * @author Ahmad Akra
 *
 */
public class MatrixBox extends DelimiterBox {

	/**
	 * Constructor <br/>
	 * <u>Contract</u>: The number of boxes should be equal
	 * to rows x cols
	 * 
	 * @param rows The number of rows
	 * @param cols The number of columns
	 * @param boxes the boxes to arrange in the matrix
	 */
	public MatrixBox(int rows, int cols, Box... boxes) {
		this(Delimiters.paren, rows, cols, boxes);
	}
	

	/**
	 * Constructor <br/>
	 * <u>Contract</u>: The number of boxes should be equal
	 * to rows x cols
	 * 
	 * @param brackets the type of brackets to surround the matrix with
	 * @param rows The number of rows
	 * @param cols The number of columns
	 * @param boxes the boxes to arrange in the matrix
	 */
	public MatrixBox(Delimiters brackets, int rows, int cols, Box... boxes) {
		super(new TableBox(rows, cols, boxes), brackets);
	}

	@Override
	public Box[] split(Level level) {
		// should not split a matrix
		return new Box[] { this };
	}
}
