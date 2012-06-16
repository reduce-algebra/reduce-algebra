package uk.ac.cam.aa582.structures.reducible;

import uk.ac.cam.aa582.structures.boxes.Box;


public abstract class Reducible {
	
	protected abstract String toReduce();
	
	public abstract Box toDrawable();
	
	
	@Override
	public String toString(){
		String result = this.toReduce();
		if(result == null) result = "";
		
		return result;
	}
}
