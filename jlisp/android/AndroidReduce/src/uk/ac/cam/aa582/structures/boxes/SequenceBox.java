package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;
import java.util.Stack;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;

/**
 * A SequenceBox is a collection of boxes packed
 * together side by side such that their axis lines are aligned.<br/><br/>
 * 
 * <tt> sin(x)</tt>
 * is a SequenceBox with two sub-boxes <tt>'sin'</tt> and <tt>'(x)'</tt>
 * 
 * @author Ahmad Akra
 *
 */
public class SequenceBox extends Box {

	int visualPointer = -1;
	Box[] boxes = new Box[0];
	
	public SequenceBox(Box... boxes) {
		if(boxes != null) this.boxes = boxes;
		setChildrenStyle();
	}
	
	public SequenceBox setVisualPointer(int index){
		visualPointer = index;
		return this;
	}
	
	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(boxes);
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;
		// the sum of all the widths in the sequence
		float width = 0f;
		for(Box box : this) {
			width += box.width();
		}
		return this.width = width + ((boxes.length == 0 ? 0f : boxes.length -1)*interBoxMargin());
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		/*
		 *  to find the height of the sequence box
		 *  fix the axis line, and calculate separately the
		 *  maximum offset of any box above and below the 
		 *  axis (remember the axis is aligned for all sub-
		 *  boxes), the height of the whole sequence is the
		 *  sum of the two maximums.
		 */
		float maximumDepth = 0;
		for(Box box : this) {
			maximumDepth = Math.max(maximumDepth, box.depth());
		}
		return height = (maximumDepth + maximumAxis());
	}

	@Override
	public float axis() { // fixed
		if(optimize && axis >= 0) return axis;
		
		return axis = maximumAxis();
	}


	@Override
	public void onDraw() {
		
		graphics.setOrigin(xOrigin(), yOrigin());
		
		float x = 0;
		float y;
		float thisAxis = this.axis();
		float margin = interBoxMargin();
		
		for(int i=0; i<boxes.length; i++){
			y = thisAxis - boxes[i].axis();
			drawBox(boxes[i], x, y);
			if(i == visualPointer) graphics.drawVisualPointer(x, thisAxis, fontSize());
			x += boxes[i].width() + margin;
		}
		if(boxes.length == visualPointer) graphics.drawVisualPointer(x, thisAxis, fontSize());
		
	}
	
	private float maximumAxis() {
		if(optimize && maximumAxis >= 0) return maximumAxis;
		
		float maxAxis = 0f;
		for(Box box : this) {
			maxAxis = Math.max(maxAxis, box.axis());
		}
		return maximumAxis = maxAxis;
	}

	@Override
	public void setChildrenStyle() {
		for(Box box : this)
			box.setStyle(style);
	}

	@Override
	protected void eraseMemory() {
		maximumAxis = Float.NEGATIVE_INFINITY;
	}

	private float maximumAxis = Float.NEGATIVE_INFINITY;
	
	@Override
	public float superscriptShift() {
		if(boxes[boxes.length - 1] == null) return super.superscriptShift();
		return boxes[boxes.length - 1].superscriptShift();
	}
	
	@Override
	public float subscriptShift() {
		if(boxes[boxes.length - 1] == null) return super.subscriptShift();
		return boxes[boxes.length - 1].subscriptShift();
	}
	
	/**
	 * Provides the margin between each two adjacent boxes.
	 * This method is useful when overriding this class
	 * 
	 * @return the margin between each two adjacent boxes
	 */
	protected float interBoxMargin() {
		return 0f;
	}

	@Override
	public float getSquashingDistance() {
		float distance = 0f;
		for(Box box : boxes)
			distance += box.getSquashingDistance();
		return distance;
	}

	@Override
	public Box squash(float factor) {
		Box[] squeezedBoxes = new Box[boxes.length];
		for(int i=0; i<boxes.length; i++)
			squeezedBoxes[i] = boxes[i].squash(factor);
		SequenceBox result = new SequenceBox(squeezedBoxes);
		result.setState(this);
		return result;
	}

	@Override
	public Box[] split(Level level) {
		if(boxes.length == 0)
			return new Box[] { this };
		
		if(level == Level.nightmare) {
			Box[][] result = new Box[boxes.length][];
			for(int i=0; i< boxes.length; i++) {
				result[i] = boxes[i].split(level); // TODO: Fix pointer problem (Edit: I think this is fixed)
			}
			
			// the following code makes sure the visual pointer is set 
			// correctly in the resulting broken SequenceBox
			if(visualPointer == result.length){
				SequenceBox sb;
				if(result[visualPointer-1].length == 0) {
					// empty sequence
					sb = new SequenceBox(new SpaceBox(0.0f,0.8f));
					result[visualPointer-1] = new Box[] { sb };
				} else {
					sb = new SequenceBox(result[visualPointer-1][result[visualPointer-1].length-1]);
					result[visualPointer-1][result[visualPointer-1].length-1] = sb ;
				}
				sb.setVisualPointer(sb.boxes.length);
				
			} else if (visualPointer >= 0) {
				
				SequenceBox sb;
				if(result[visualPointer].length == 0) {
					// empty sequence
					sb = new SequenceBox(new SpaceBox(0.0f,0.8f));
					result[visualPointer] = new Box[] { sb };
				} else {
					sb = new SequenceBox(result[visualPointer][0]);
					result[visualPointer][0] = sb;
				}
				sb.setVisualPointer(0);
			}
			
			// return one array containing all the bits
			return concat(result);
		} else {
			// break each part of the sequence and push the broken bits in a stack
			Stack<Box> stack = new Stack<Box>();
			for(int i=0; i<boxes.length; i++) {
				Box[] current = boxes[i].split(level);
				Box toPush;
				if(stack.size() > 0) {
					Box lastPushed = stack.pop();
					if(lastPushed instanceof SequenceBox) {
						// optimize here to make one sequence rather then many nested sequences
						SequenceBox lastPushedSeq = (SequenceBox) lastPushed;
						toPush = new SequenceBox(concat(lastPushedSeq.boxes, new Box[] {current[0]})).setGraphics(graphics.sameGraphics());
					} else {
						toPush = new SequenceBox(lastPushed, current[0]).setGraphics(graphics.sameGraphics());
					}
				} else {
					toPush = current[0];
				}
				stack.push(toPush);
				for(int j=1; j<current.length; j++) {
					stack.push(current[j]);
				}
			}
			return stack.toArray(new Box[0]);
		}
	}

	public SequenceBox append(Box n) {
		Box[] result = new Box[boxes.length + 1];
		for(int i=0; i<boxes.length; i++)
			result[i] = boxes[i];
		
		result[result.length-1] = n;
		return new SequenceBox(result);
	}
}
