package uk.ac.cam.aa582.structures.boxes;

import java.util.LinkedList;

import uk.ac.cam.aa582.structures.boxes.MultilineBox.Alignment;
import android.util.Log;

/**
 * Contains methods that handle squashing and breaking formulae into 
 * multiple lines when they don't fit between horizontal boundaries
 * 
 * @author Ahmad Akra
 *
 */
public class BoxUtil {
	
	/**
	 * easy: break at operators and relations <br/>
	 * medium: break inside brackets and large operators <br/>
	 * hard: break change fractions and sqrt <br/>
	 * nightmare: break every symbol, and flatten superscripts and subscripts too <br/>
	 * 
	 * @author Ahmad Akra
	 *
	 */
	public enum Level {
		easy, 
		medium, 
		hard, 
		nightmare
	}
	
	/**
	 * O(n^2) where n = possible break points
	 * 
	 * @param box
	 * @param maxWidth
	 */
	public static Box fitWithin(Box box, float maxWidth){
		
		if(box.width() < maxWidth) return box;
		else { // step 1: remove unnecessary margins e.g. (a = b + c) => (a=b+c)

			Log.d("measure old box", box.toString());
			
			float d = box.getSquashingDistance();
			float w = box.width();
			float squashingingFactor = Math.max(0f, 1-((w - maxWidth) / d));
			box = box.squash(squashingingFactor);

			Log.d("measure d", d+"");
			Log.d("measure w", w+"");
			Log.d("measure squashingingFactor", (squashingingFactor)+"");
			Log.d("measure w-d", (w-d)+"");
			Log.d("measure maxWidth", maxWidth+"");
			Log.d("measure new box", box.toString());
			
			if(w - d < maxWidth) {
				
				return box;
			}else { // step 2: split the box into multiple lines
				
				Box[] easyParts = box.split(Level.easy);
				if(maxWidth(easyParts) < maxWidth) 
					return knuthPlass(easyParts, maxWidth);
				else {
					Box[] mediumParts = box.split(Level.medium);
					if(maxWidth(mediumParts) < maxWidth) 
						return knuthPlass(mediumParts, maxWidth);
					else {
						Box[] hardParts = box.split(Level.hard);
						if(maxWidth(hardParts) < maxWidth) 
							return knuthPlass(hardParts, maxWidth);
						else {
							Box[] nightmareParts = box.split(Level.nightmare);
							if(maxWidth(nightmareParts) < maxWidth)
								return knuthPlass(nightmareParts, maxWidth);
							
							else { // step 3: reduce the font size
								float newSize = box.fontSize() * (maxWidth / maxWidth(nightmareParts)); 
								for(int i=0; i< nightmareParts.length; i++)
									nightmareParts[i].setFontSize(newSize);
								
								box = knuthPlass(nightmareParts, maxWidth(nightmareParts));
								return box;
							}
						}
					}
				}
			}
		}
	}
	
	private static Box knuthPlass(Box[] pieces, float maxWidth) {
		int pieceCount = pieces.length;
		if(pieceCount == 1) return pieces[0];
		
		// calculate 'sum' in O(n^2)
		float[][] sum = new float[pieceCount][pieceCount];
		for(int i=0; i<pieceCount; i++) {
			sum[i][i] = pieces[i].width(); 
			for(int j=i+1; j<pieceCount; j++) {
				sum[i][j] = sum[i][j-1] + pieces[j].width(); 
			}
		}
		
		// calculate 'cost' in O(n^2) using 'sum'
		float[][] cost = new float[pieceCount][pieceCount];
		for(int i=0; i<pieceCount; i++) {
			for(int j=i; j<pieceCount; j++) {
				float diff = maxWidth - sum[i][j];
				if(diff < 0) // if words don't fit on the line
					cost[i][j] = Float.POSITIVE_INFINITY;
				// else the cost is the square of the difference between 
				// the width of the words and the width of the line
				else cost[i][j] = diff * diff; 
			}
		}
		
		// calculate 'minCost' and 'pointer' in O(n^2) using 'cost'
		float[] minCost = new float[pieceCount];
		int[] pointer = new int[pieceCount];
		minCost[0] = cost[0][0];
		pointer[0] = 0;
		for(int j=1; j<minCost.length; j++) {
			if(cost[0][j] < Float.POSITIVE_INFINITY) {
				minCost[j] = cost[0][j];
				pointer[j] = 0;
			} else {
				float minJcost = Float.POSITIVE_INFINITY;
				int minK = -1;
				for(int k=j-1; k>=0; k--) {
					float kCost = minCost[k] + cost[k+1][j];
					if(kCost < minJcost) {
						minJcost = kCost;
						minK = k;
					}
				}
				minCost[j] = minJcost;
				pointer[j] = minK+1;
			}
		}
		
		// extract the lines using 'pointer'
		LinkedList<Box> lines = new LinkedList<Box>();
		int index = pieceCount-1;
		while(index>=0) {
			Box[] lineParts = subArray(pieces, pointer[index], index);
			SequenceBox line = new SequenceBox(lineParts);
			lines.addFirst(line);
			index = pointer[index]-1;
		}
		
		// finally: arrange the lines nicely inside a MultilineBox object.
		//Box firstLine = lines.poll();
		Box[] remainingLinesArray = lines.toArray(new Box[0]);
		
		float displayFontSize = remainingLinesArray[0].displayFontSize(); //firstLine.displayFontSize();
		float margins = 5f / displayFontSize;
		float lineHeight = 2;
		maxWidth = maxWidth / displayFontSize;
		
//		MultilineBox remainingLines = new MultilineBox(margins, lineHeight, maxWidth(remainingLinesArray), Alignment.left, remainingLinesArray);
//		MultilineBox remainingLines2 = new MultilineBox(margins, lineHeight, maxWidth, Alignment.right, remainingLines);
//		MultilineBox wholeThing = new MultilineBox(margins, lineHeight, maxWidth, Alignment.left, firstLine, remainingLines2);
		
		MultilineBox wholeThing = new MultilineBox(margins, lineHeight, maxWidth, Alignment.centre, remainingLinesArray);
		
		return wholeThing;
	}

	private static Box[] subArray(Box[] array, int i, int j) {

		Box[] subarray = new Box[j-i+1];
		for(int k=0; k<subarray.length; k++)
			subarray[k] = array[i+k];
		return subarray;
	}

	private static float maxWidth(Box[] parts) {
		float max = 0;
		for(Box part : parts)
			max = Math.max(max, part.width());
		return max;
	}

	/**
	 * O(n), where n = possible breakpoints
	 * @param box
	 * @param maxWidth
	 */
	public static Box wrap(Box box, float maxWidth) {
		if(box.width() < maxWidth) 
			return box;
		
		Box[] parts = box.split(Level.nightmare);
		LinkedList<SequenceBox> lines = new LinkedList<SequenceBox>();
		LinkedList<Box> line = new LinkedList<Box>();
		float totalWidth = 0f;
		for(int i=0; i<parts.length; i++){
			Box part = parts[i];
			if(line.size() != 0 && totalWidth + part.width() > maxWidth) {
				SequenceBox seq = new SequenceBox(line.toArray(new Box[0]));
				lines.add(seq);
				line = new LinkedList<Box>();
				totalWidth = 0f;
			}
			
			totalWidth += parts[i].width();
			line.add(part);
			
		}
		
		if(line.size() != 0) {
			SequenceBox seq = new SequenceBox(line.toArray(new Box[0]));
			lines.add(seq);
		}
		
		return new MultilineBox(-1,-1,-1, 
				Alignment.left, 
				lines.toArray(new SequenceBox[0]));
	}
}
