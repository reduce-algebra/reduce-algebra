package uk.ac.cam.aa582.structures.reducible;

import java.util.Iterator;
import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.OnTouchHandler;

/**
 * Base class for any expression that contains sub-expressions
 * 
 * @author Ahmad Akra
 *
 */
public abstract class WrapperExpression extends Expression implements Iterable<Sequence> {
	
	public Sequence getLeftmostSequence() {
		return sequences[0];
	}
	public Sequence getRightmostSequence() {
		return sequences[sequences.length-1];
	}
	
	Sequence[] sequences;
	
	public WrapperExpression(Sequence... sequences) {
		this.sequences = sequences;
		
		for(int i=0; i<sequences.length-1;i++){
			sequences[i].setRightSequence(sequences[i+1]);
			sequences[i+1].setLeftSequence(sequences[i]);
		}
	}
	
	@Override
	public void setTouchHandler(OnTouchHandler<Object> touchHandler) {
		for(Sequence seq : this) {
			seq.setTouchHandler(touchHandler);
		}
	}
	
	@Override
	public Iterator<Sequence> iterator() {
		LinkedList<Sequence> ll = new LinkedList<Sequence>();
		if(sequences == null) return ll.iterator();
		for(int i=0; i<sequences.length; i++){
			ll.add(sequences[i]);
		}
		return ll.iterator();
	}
	
	protected Sequence[] copyAll(Sequence[] sequences) {
		Sequence[] result = new Sequence[sequences.length];
		for(int i=0; i<result.length; i++) {
			result[i] = sequences[i].copy();
		}
		return result;
	}
	
	protected static Sequence[] initializedSequenceArray(int arraySize) {
		Sequence[] result = new Sequence[arraySize];
		for(int i=0; i<arraySize; i++)
			result[i] = new Sequence();
		
		return result;
	}
}
