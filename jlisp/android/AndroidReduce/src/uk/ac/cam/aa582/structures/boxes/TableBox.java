package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * A TableBox arranges a collection of boxes into a 
 * matrix like arrangement (rows and columns) such that
 * boxes are vertically centered in their rows and vertically
 * centered in their columns. The number of rows and columns
 * can be specified through the constructor
 * 
 * @author Ahmad Akra
 *
 */
public class TableBox extends Box {
	
	/**
	 * The number of rows in this table box
	 */
	int rowCount = 0;
	
	/**
	 * The number of columns in this table box
	 */
	int colCount = 0;
	
	/**
	 * What fraction of the margins between the columns
	 * is OK to squeeze.
	 */
	float squeezableFraction = 0.5f;
	
	/**
	 * This value is multiplied by the widths of any horizontal margins
	 * that can be squeezed.
	 */
	float squeezingFactor = 1.0f;
	
	/**
	 * The array of boxes as it arrived through the constructor. This
	 * should be interpreted like this: as the index goes from 0 to n.
	 * it sweepts over the first row, and then the second row etc... 
	 */
	Box[] boxes;
	
	/**
	 * table[row][column]
	 */
	private Box[][] table;
	
	/**
	 * invertedTable[column][row]
	 */
	private Box[][] invertedTable;
	
	/**
	 * 
	 * @param rows The number of rows
	 * @param cols The number of columns
	 * @param boxes the boxes to arrange in this TableBox, These
	 * should be interpreted like this: as the index goes from 0 to n.
	 * it sweeps over the first row, and then the second row etc...
	 */
	public TableBox(int rows, int cols, Box... boxes) {
		// assert (boxes.length == rows*cols)
		rowCount = rows;
		colCount = cols;
		
		this.boxes = boxes;
		
		table  = new Box[rowCount][colCount];

		for(int r=0; r<rows; r++) {
			for(int c=0; c<cols; c++) {
				table[r][c] = boxes[(r*cols) + c];
			}
		}
		
		invertedTable = new Box[colCount][rowCount];
		
		for(int c=0; c<cols; c++) {
			for(int r=0; r<rows; r++) {
				invertedTable[c][r] = boxes[(r*cols) + c];
			}
		}
	}
	
	@SuppressWarnings("unused")
	private TableBox(int rows, int cols, float squeezingFactor, Box...boxes) {
		this(rows,cols, boxes);
		this.squeezingFactor = squeezingFactor;
	}

	@Override
	public float axis() {
		if(optimize && axis >= 0f) return axis;
		
		return axis = (height() / 2);
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;

		float sum = 0f;
		for(int r=0; r<rowCount; r++) {
			Box[] row = table[r];
			float maximumBelowAxis = 0f;
			float maximumAboveAxis = 0f;
			for(Box box : row) {
				maximumAboveAxis = Math.max(maximumAboveAxis, box.axis());
				maximumBelowAxis = Math.max(maximumBelowAxis, box.depth());
			}
			sum += maximumAboveAxis;
			sum += maximumBelowAxis;
		}
		sum += (rowCount-1) * interRowMargin();

		return height = sum;
	}

	/**
	 * @return The absolute value of the height of the margin between
	 * the rows.
	 */
	private float interRowMargin() {
		return C.table_box_inter_row_margin_factor * fontSize();
	}
	
	/**
	 * @return The absolute value of the width of the margin between
	 * the columns.
	 */
	private float interColumnMargin() {
		return C.table_box_inter_column_margin_factor * fontSize() * 
				(1-squeezableFraction + (squeezableFraction * squeezingFactor));
	}

	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(boxes);
	}

	@Override
	public Box[] split(Level level) {
		// tables do not split
		return new Box[] { this };
	}

	@Override
	public Box squash(float factor) {
//		Box[] squeezedBoxes = new Box[boxes.length];
//		for(int i=0; i<boxes.length; i++)
//			squeezedBoxes[i] = boxes[i].squeeze(factor);
//		return new TableBox(rowCount, colCount, factor, squeezedBoxes);
		return this;
	}

	@Override
	public float getSquashingDistance() {
//		float maximumEffectiveSqueeze = 0f;
//		for(int r=0; r<rowCount; r++) {
//			float squeeze = 0f;
//			for(Box box : table[r]) {
//				squeeze += box.squeezingDistance();
//			}
//			squeeze += ((colCount-1) * interColumnMargin() * squeezableFraction * squeezingFactor);
//			
//			float originalWidth = 0f;
//			for(Box box : table[r]) {
//				originalWidth += box.width();
//			}
//			originalWidth += 
//			
//			maximumEffectiveSqueeze = Math.max(maximumEffectiveSqueeze, this.width() -(originalWidth-squeeze));
//		}
		// this is very tricky so I'll just say the a table cannot be squeezed or splitted
		return 0;
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;

		float sum = 0f;
		for(int c=0; c<colCount; c++) {
			Box[] col = invertedTable[c];
			float maximumWidth = 0f;
			for(Box box : col) {
				maximumWidth = Math.max(maximumWidth, box.width());
			}
			sum += maximumWidth;
		}
		sum += (colCount-1) * interColumnMargin();

		return width = sum;
	}

	@Override
	protected void eraseMemory() {
		
	}

	@Override
	protected void setChildrenStyle() {
		for(Box b : this)
			b.setStyle(this.style);
	}

	@Override
	public void onDraw() {
		
		// two loops will fill these arrays
		float[] widths = new float[colCount];
		float[] heights = new float[rowCount];
		float[] axises = new float[rowCount];
		
		for(int c=0; c<colCount; c++) {
			Box[] col = invertedTable[c];
			float maximumWidth = 0f;
			for(Box box : col) {
				maximumWidth = Math.max(maximumWidth, box.width());
			}
			widths[c] = maximumWidth;
		}
		
		for(int r=0; r<rowCount; r++) {
			Box[] row = table[r];
			float maximumBelowAxis = 0f;
			float maximumAboveAxis = 0f;
			for(Box box : row) {
				maximumAboveAxis = Math.max(maximumAboveAxis, box.axis());
				maximumBelowAxis = Math.max(maximumBelowAxis, box.depth());
			}
			heights[r] = maximumAboveAxis + maximumBelowAxis;
			axises[r] = maximumAboveAxis;
		}
		
		float x = 0f;
		float y = 0f;

		for(int r=0; r<rowCount; r++) {
			
			float height = heights[r];
			float axis = axises[r];
			
			for(int c=0; c<colCount; c++) {
				Box box = table[r][c];

				float width = widths[c];
				
				this.drawBox(box, x + (width-box.width())/2, y+(axis - box.axis()));
				
				x += width + interColumnMargin();				
			}
			y += height + interRowMargin();
			x = 0f;
		}
	}
}
