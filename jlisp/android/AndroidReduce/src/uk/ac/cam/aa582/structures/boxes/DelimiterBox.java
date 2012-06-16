package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;


/**
 * [3], (3), {3}, |3| <br/><br/>
 * 
 * are DelimiterBoxes with delimited expression '3' <br/>
 * This class delimits a box inside a pair of delimiters
 * (brackets or absolute value bars). These delimiters adjust
 * their heights according to the height of the box inside them.
 * For example the parenthesis can grow arbitrarily tall until
 * the box inside fits <i>almost</i> entirely in between.
 * 
 * 
 * @author Ahmad Akra
 *
 */
public class DelimiterBox extends Box {
	
	/**
	 * There is an option to include a single delimiter
	 * on the left or on the right, or two delimiters
	 * on both sides, this information is communicated
	 * through this enumeration
	 * 
	 * @author Ahmad Akra
	 *
	 */
	public enum DelimiterType {
		/**
		 * (foo
		 */
		left, 
		
		/**
		 * foo)
		 */
		right, 
		
		/**
		 * (foo)
		 */
		leftAndRight
	}
	
	/**
	* The type of the delimiters used in this {@link DelimiterBox}
	* is communicated through this enumeration
	* 
	 * @author Ahmad Akra
	 *
	 */
	public enum Delimiters {
		
		/**
		 * (foo)
		 */
		paren, 
		
		/**
		 * [foo]
		 */
		square, 
		
		/**
		 * {foo}
		 */
		curly, 
		
		/**
		 * |foo|
		 */
		abs
	}

	/**
	 * The box representation of the delimited expression
	 */
	Box innerBox;
	
	/**
	 * The type of the delimiters: ( or [ or { or |
	 */
	Delimiters delimiters;
	
	/**
	 * Left delimiter only, right delimiter only, or both
	 * left and right delimiters.
	 */
	DelimiterType type = DelimiterType.leftAndRight;
	
	/**
	 * If this is not null, the {@link Size} of the delimiter
	 * is taken to be its value, and the regular way of calculating
	 * the {@link Size} of the delimiter is ignored.<br/>
	 * This is useful when breaking the {@link DelimiterBox} into many
	 * pieces and you want to make sure that both delimiters have
	 * the same size nevertheless.
	 *  
	 */
	Size delimSizeOverride = null;
	
	/**
	 * If {@link DelimiterBox#delimSizeOverride} is set to
	 * {@link Size#extended} then this field should contain
	 * the number of extension pieces to add
	 */
	int extensionCount = 0;
	
	/**
	 * Determines how much do extensions overlap
	 */
	private float m = 2f; 
	
	/**
	 * All squeezable horizontal margins should be multiplied
	 * by this field
	 */
	private float squeezingFactor = 1.0f;
	

	/**
	 * Constructor
	 * 
	 * @param bracketed the box inside the delimiters
	 * @param brackets the type of the delimiters ( or { or [ or |
	 * @param type delimiters at both left and right, or only on the left or only on the right
	 * @param delimSizeOverride passing anything but null, will override the {@link Size} of the delimiters to its value
	 * @param extensionCount if delimSizeOverride is {@link Size#extended}, this should indicate the number of extensions to use
	 * @param squeezingFactor All squeezable horizontal margins should be multiplied by this value
	 */
	private DelimiterBox(Box bracketed, Delimiters brackets, DelimiterType type, Size delimSizeOverride, int extensionCount, float squeezingFactor) {
		
		if(bracketed != null) this.innerBox = bracketed;
		else this.innerBox = defaultBox();
		
		if(brackets == null) this.delimiters = Delimiters.paren;
		else this.delimiters = brackets;
		
		if(type != null) this.type = type;
		
		this.delimSizeOverride = delimSizeOverride;
		this.extensionCount = extensionCount;
		this.squeezingFactor = squeezingFactor;
		
		this.useFont(Font.cmr);
		setChildrenStyle();
	}
	
	/**
	 * Constructor
	 * 
	 * @param bracketed the box inside the delimiters
	 * @param brackets the type of the delimiters ( or { or [ or |
	 * @param type delimiters at both left and right, or only on the left or only on the right
	 */
	public DelimiterBox(Box bracketed, Delimiters brackets, DelimiterType type) {
		this(bracketed, brackets, type, null, -1, 1.0f);
	}
	
	/**
	 * Constructor
	 * 
	 * @param bracketed the box inside the delimiters
	 * @param brackets the type of the delimiters ( or { or [ or |
	 */	
	public DelimiterBox(Box bracketed, Delimiters brackets) {
		this(bracketed, brackets, null, null, -1, 1.0f);
	}
	
	/**
	 * Constructor
	 * 
	 * @param bracketed the box inside the delimiters
	 */
	public DelimiterBox(Box bracketed) {
		this(bracketed, null, null, null, -1, 1.0f);
	}
	
	/**
	 * @return the width of the delimiter based on the 
	 * delimiter type and size
	 */
	private float delimiterWidth() {
		if(optimize && bracketWidth >= 0) return bracketWidth;

		Size size = determineDelimiterSize();
		float bw = delimiterWidth(size);
		return bracketWidth = bw;
	}

	/**
	 * <u>Contract</u>: result not defined if the delimiters are absolute bars.
	 * absolute bars do not have a size
	 * 
	 * @return the {@link Size} of the delimiters based on the dimensions
	 * of the inner box
	 */
	private Size determineDelimiterSize() {
		if(optimize && determineBracketSize != null) return determineBracketSize;
		
		if(delimSizeIsOverriden()) 
			return delimSizeOverride;
		
		float halfHeight = Math.max(innerBox.axis(), innerBox.depth());
		float minHalfBracketHeight = halfHeight - maximumBracketShortfall();
		Size size = determineBracketSize(minHalfBracketHeight);
		return determineBracketSize = size;
	}

	/** 
	 * @return How much is the box inside the brackets allowed to peak
	 * outside the brackets (above or below) such that brackets
	 * do not completely encompass the inner Box
	 */
	private float maximumBracketShortfall() {
		if(optimize && maximumBracketShortfall >= 0) return maximumBracketShortfall;
			
		return maximumBracketShortfall = (C.maximum_bracket_shortfall_factor * fontSize());
	}
	
	/**
	 * 
	 * @param size the {@link Size} of the delimiter
	 * @return the width of the delimiter in the given size
	 */
	private float delimiterWidth(Size size) {
		
		if(delimiters == Delimiters.abs && size != Size.tiny) {
			return absLineAdvancingWidth();
		} else {
			char bracket = getLeftBracket(); // bracket
			useFontFor(size);
			return graphics.advancingWidth(bracket, font, fontNumber, fontSize()); // bull's eye
		}
	}
	
	/**
	 * Given the minimum length for half of the delimiter, this method
	 * calculated the minimum {@link Size} of the delimiter that would
	 * satisfy this constraint, this also depends on the type of
	 * the delimiter
	 * 
	 * @param minHalfBracketHeight the minimum allowed half height of this delimiter
	 * @return the {@link Size} of the delimiters based on the given
	 * minimum half height
	 */
	private Size determineBracketSize(float minHalfBracketHeight) {
		float minHeight = minHalfBracketHeight * 2;
		useFontFor(Size.tiny); // for the tiny size
		switch(this.delimiters) {
		case paren : {
			if(graphics.boundingHeight('(', font, fontNumber, fontSize()) > minHeight) return Size.tiny;
			else {
				useFont(Font.cmex);
				if(graphics.boundingHeight(Cmex.bracket_paren_left_small, font, fontNumber, fontSize()) > minHeight) return Size.small;
				else if(graphics.boundingHeight(Cmex.bracket_paren_left_medium, font, fontNumber, fontSize()) > minHeight) return Size.medium;
				else if(graphics.boundingHeight(Cmex.bracket_paren_left_large, font, fontNumber, fontSize()) > minHeight) return Size.large;
				else if(graphics.boundingHeight(Cmex.bracket_paren_left_xlarge, font, fontNumber, fontSize()) > minHeight) return Size.xlarge;
				else return Size.extended;
			}
		}
		case curly : {
			if(graphics.boundingHeight(S.symbol(S.bracket_curly_left_tiny), font, fontNumber, fontSize()) > minHeight) return Size.tiny;
			else {
				useFont(Font.cmex);
				if(graphics.boundingHeight(Cmex.bracket_curly_left_small, font, fontNumber, fontSize()) > minHeight) return Size.small;
				else if(graphics.boundingHeight(Cmex.bracket_curly_left_medium, font, fontNumber, fontSize()) > minHeight) return Size.medium;
				else if(graphics.boundingHeight(Cmex.bracket_curly_left_large, font, fontNumber, fontSize()) > minHeight) return Size.large;
				else if(graphics.boundingHeight(Cmex.bracket_curly_left_xlarge, font, fontNumber, fontSize()) > minHeight) return Size.xlarge;
				else return Size.extended;
			}
		}
		case square: {
			if(graphics.boundingHeight('[', font, fontNumber, fontSize()) > minHeight) return Size.tiny;
			else {
				useFont(Font.cmex);
				if(graphics.boundingHeight(Cmex.bracket_square_left_small, font, fontNumber, fontSize()) > minHeight) return Size.small;
				else if(graphics.boundingHeight(Cmex.bracket_square_left_medium, font, fontNumber, fontSize()) > minHeight) return Size.medium;
				else if(graphics.boundingHeight(Cmex.bracket_square_left_large, font, fontNumber, fontSize()) > minHeight) return Size.large;
				else if(graphics.boundingHeight(Cmex.bracket_square_left_xlarge, font, fontNumber, fontSize()) > minHeight) return Size.xlarge;
				else return Size.extended;
			}
		}
		case abs: {
			if(graphics.boundingHeight(S.symbol(S.abs_bar_tiny), font, fontNumber, fontSize()) > minHeight) return Size.tiny;
			else return Size.extended;
		}
		}
		return null;
	}

	/**
	 * 
	 * @return the height of the delimiters based on their type, size
	 * and the dimensions of the inner {@link Box}
	 */
	private float delimiterHeight() {
		if(optimize && delimiterHeight >= 0) return delimiterHeight;
		
		char bracket = 0; // bracket
		Size size = determineDelimiterSize();
		
		useFontFor(size);
		if(size != Size.extended) {
			bracket = getLeftBracket();
			return this.delimiterHeight = graphics.boundingHeight(bracket, font, fontNumber, fontSize());
		} else {
				switch(this.delimiters) {
				case paren : {
					// the bracket head, tail and the extension piece
					char head = Cmex.bracket_paren_left_head;
					char tail = Cmex.bracket_paren_left_tail;
					char extension = Cmex.bracket_paren_left_vertical_bar;
					
					//calculate the height of each
					float headHeight = graphics.boundingHeight(head, font, fontNumber, fontSize())-m;
					float tailHeight = graphics.boundingHeight(tail, font, fontNumber, fontSize())-m;
					float extHeight = graphics.boundingHeight(extension, font, fontNumber, fontSize())-m;
					
					 // this is only the number of extensions in one direction, so have to multiply by 2
					int extensionCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
							headHeight, 
							extHeight, 
							maximumBracketShortfall(), 
							Math.max(innerBox.axis(), innerBox.depth()));
					
					return this.delimiterHeight =
							(headHeight + 
							(2 * extensionCount * extHeight) + 
							tailHeight);
				}
				case curly : {
					// the bracket head, tail middle section, and the extension piece
					char head = Cmex.bracket_curly_left_head;
					char tail = Cmex.bracket_curly_left_tail;
					char middle = Cmex.bracket_curly_left_middle;
					char extension = Cmex.bracket_curly_left_vertical_bar;

					//calculate the height of each				
					float headHeight = graphics.boundingHeight(head, font, fontNumber, fontSize())-m;
					float tailHeight = graphics.boundingHeight(tail, font, fontNumber, fontSize())-m;
					float middleHeight = graphics.boundingHeight(middle, font, fontNumber, fontSize())-m;
					float extHeight = graphics.boundingHeight(extension, font, fontNumber, fontSize())-m;

					 // this is only the number of extensions in one direction, so have to multiply by 2
					int extensionCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
							headHeight + (middleHeight/2), 
							extHeight, 
							maximumBracketShortfall(), 
							Math.max(innerBox.axis(), innerBox.depth()));
					
					return this.delimiterHeight =
							(headHeight + 
							(2 * extensionCount * extHeight) + 
							middleHeight +
							tailHeight);
				}
				case square : {
					char head = Cmex.bracket_square_left_head;
					char tail = Cmex.bracket_square_left_tail;
					char extension = Cmex.bracket_square_left_vertical_bar;
					
					float headHeight = graphics.boundingHeight(head, font, fontNumber, fontSize())-m;
					float tailHeight = graphics.boundingHeight(tail, font, fontNumber, fontSize())-m;
					float extHeight = graphics.boundingHeight(extension, font, fontNumber, fontSize())-m;
					
					int extensionCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
							headHeight, 
							extHeight, 
							maximumBracketShortfall(), 
							Math.max(innerBox.axis(), innerBox.depth()));
					
					return this.delimiterHeight = 
							(headHeight + 
							(2 * extensionCount * extHeight) + 
							tailHeight);
				}
				case abs : {
					float pieceHeight = C.abs_bar_piece_height_factor * fontSize();
					
					int pieceCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
								0f,
								pieceHeight,
								maximumBracketShortfall(),
								Math.max(innerBox.axis(), innerBox.depth()));
					
					return this.delimiterHeight = 
							(2 * pieceCount * pieceHeight);
				}
			}
		}
		return 0f; // this is unreachable, but the compiler insisted that I put it here
	}

	/**
	 * Determines whether or not the normal calculations
	 * of the bracket {@link Size} should be ignored
	 * and hence the value of {@link DelimiterBox#delimSizeOverride}
	 * should be used instead 
	 * 
	 * @return
	 */
	private boolean delimSizeIsOverriden() {
		return delimSizeOverride != null;
	}

	/**
	 * 
	 * If the given size is tiny, sets the font to cmr or cmsy 
	 * depending on the delimiters,
	 * because the small delimiters in cmr or cmsy will be used.<br/>
	 * Else uses the cmex font, which contains the larger
	 * versions of the delimiters.
	 * 
	 * 
	 * @param size 
	 */
	private void useFontFor(Size size) {
		if (size == Size.tiny){
			if(delimiters == Delimiters.paren || delimiters == Delimiters.square)
				useFont(Font.cmr);
			else useFont(Font.cmsy);
		}
		else useFont(Font.cmex);
	}
	
	/**
	 * <u>Contract</u>: result undefined if the delimiters
	 * value is {@link Delimiters#abs}, Those are drawn
	 * as vertical lines.
	 * 
	 * @return the character that represents the left bracket
	 * for the BracketsBox, if the largest available size does
	 * not fit, return the head of the extendible bracket
	 * 
	 */
	private char getLeftBracket(){
		if(optimize && getLeftBracket != 0x00) return getLeftBracket;
		
		Size size = this.determineDelimiterSize();
		// assert size != extended
		char bracket = 0;
		switch(size){
		case tiny : 
			switch(this.delimiters) {
			case abs   : bracket = S.symbol(S.abs_bar_tiny); break;
			case paren : bracket = S.symbol(S.bracket_paren_left_tiny); break;
			case curly : bracket = S.symbol(S.bracket_curly_left_tiny); break;
			case square: bracket = S.symbol(S.bracket_square_left_tiny); break;
			} break;
		case small : 
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_left_small; break;
			case curly : bracket = Cmex.bracket_curly_left_small; break;
			case square: bracket = Cmex.bracket_square_left_small; break;
			} break;
		case medium : 
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_left_medium; break;
			case curly : bracket = Cmex.bracket_curly_left_medium; break;
			case square: bracket = Cmex.bracket_square_left_medium; break;
			} break;
		case large :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_left_large; break;
			case curly : bracket = Cmex.bracket_curly_left_large; break;
			case square: bracket = Cmex.bracket_square_left_large; break;
			} break;
		case xlarge :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_left_xlarge; break;
			case curly : bracket = Cmex.bracket_curly_left_xlarge; break;
			case square: bracket = Cmex.bracket_square_left_xlarge; break;
			} break;
		case extended :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_left_head; break;
			case curly : bracket = Cmex.bracket_curly_left_head; break;
			case square: bracket = Cmex.bracket_square_left_head; break;
			} break;
		}
		return getLeftBracket = bracket;
	}
	
	/**
	 * <u>Contract</u>: result undefined if the delimiters
	 * value is {@link Delimiters#abs}, Those are drawn
	 * as vertical lines.
	 * 
	 * @return the character that represents the right bracket
	 * for the BracketsBox, if the largest available size does
	 * not fit, return the head of the extendible bracket
	 */
	private char getRightBracket(){
		if(optimize && getRightBracket != 0x00) return getRightBracket;
		
		Size size = this.determineDelimiterSize();
		char bracket = 0;
		switch(size){
		case tiny : 
			switch(this.delimiters) {
			case abs   : bracket = S.symbol(S.abs_bar_tiny); break;
			case paren : bracket = S.symbol(S.bracket_paren_right_tiny); break;
			case curly : bracket = S.symbol(S.bracket_curly_right_tiny); break;
			case square: bracket = S.symbol(S.bracket_square_right_tiny); break;
			} break;
		case small : 
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_right_small; break;
			case curly : bracket = Cmex.bracket_curly_right_small; break;
			case square: bracket = Cmex.bracket_square_right_small; break;
			} break;
		case medium : 
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_right_medium; break;
			case curly : bracket = Cmex.bracket_curly_right_medium; break;
			case square: bracket = Cmex.bracket_square_right_medium; break;
			} break;
		case large :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_right_large; break;
			case curly : bracket = Cmex.bracket_curly_right_large; break;
			case square: bracket = Cmex.bracket_square_right_large; break;
			} break;
		case xlarge :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_right_xlarge; break;
			case curly : bracket = Cmex.bracket_curly_right_xlarge; break;
			case square: bracket = Cmex.bracket_square_right_xlarge; break;
			} break;
		case extended :
			switch(this.delimiters) {
			case paren : bracket = Cmex.bracket_paren_right_head; break;
			case curly : bracket = Cmex.bracket_curly_right_head; break;
			case square: bracket = Cmex.bracket_square_right_head; break;
			} break;
		}
		return getRightBracket = bracket;
	}
	
	/**
	 * 
	 * @return The margin between the brackets and the inner expression
	 */
	private float innerBoxMargin(){
		if(optimize && innerBoxMargin >= 0) return innerBoxMargin;
		
		return innerBoxMargin = (C.bracket_inner_box_margin_factor * fontSize() * squeezingFactor);
	}

	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(innerBox);
	}

	@Override
	public float width() { 
		if(optimize && width >= 0) return width;
		int delimCount = 2;
		if(type != DelimiterType.leftAndRight) delimCount = 1;
		return width = innerBox.width() + delimCount * delimiterWidth() + delimCount * innerBoxMargin();
	}
	
	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		
		return height = this.axis() + //height up to axis
				Math.max(innerBox.depth(), delimiterHeight() / 2); // height below axis
	}

	@Override
	public float axis() {
		if(optimize && axis >= 0) return axis;
		return axis = Math.max(innerBox.axis(), delimiterHeight() / 2);
	}
	
	@Override
	public void onDraw(){
		graphics.setOrigin(xOrigin(), yOrigin());
		
		// inner box
		float x1 = (type == DelimiterType.right) ? 0f : delimiterWidth() + innerBoxMargin();
		float y1 = Math.max(0f, (delimiterHeight() / 2) - innerBox.axis());
		this.drawBox(innerBox, x1, y1);
		
			
			Size size = this.determineDelimiterSize();
			if(size != Size.extended) {
				if(type != DelimiterType.right) {
					char leftBracket = getLeftBracket();
					float x2 = 0f;
					float y2 = Math.max(0f, innerBox.axis() - (delimiterHeight() / 2));
					graphics.drawChar(leftBracket, font, fontNumber, fontSize(), x2, y2);
				}
				
				if(type != DelimiterType.left) {
					char rightBracket = getRightBracket();
					float x3 = x1 + innerBox.width() + innerBoxMargin();
					float y3 = Math.max(0f, innerBox.axis() - (delimiterHeight() / 2));
					graphics.drawChar(rightBracket, font, fontNumber, fontSize(), x3, y3);
				}
			} else {
				
				if(delimiters == Delimiters.abs) {
					// absolute bars are handled quite differently
					float pieceHeight = C.abs_bar_piece_height_factor * fontSize();
					
					int pieceCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
								0f,
								pieceHeight,
								maximumBracketShortfall(),
								Math.max(innerBox.axis(), innerBox.depth()));
					
					// left absolute value bar
					float startX1 = delimiterWidth()/2;
					float startY1 = axis() - (delimiterHeight()/2);
					float stopX1 = startX1;
					float stopY1 = startY1 + 2 * pieceCount * pieceHeight;
					
					if(type != DelimiterType.right)
						graphics.drawLine(absLineThickness(), startX1, startY1, stopX1, stopY1);
					
					// right absolute value bar
					float startX2 = x1 + innerBox.width() + innerBoxMargin() + delimiterWidth()/2;
					float startY2 = startY1;
					float stopX2 = startX2;
					float stopY2 = stopY1;			
					
					if(type != DelimiterType.right)
						graphics.drawLine(absLineThickness(), startX2, startY2, stopX2, stopY2);
					
				} else {
				
					float x4 = 0f;
					float y4 = axis() - (delimiterHeight()/2);
					
					// --------- Left bracket ----------
					// the bracket head, tail and the extension piece
					char head;
					char tail;
					char middle = Cmex.bracket_curly_left_middle;
					char extension;
					
					if(delimiters == Delimiters.curly) {
						head = Cmex.bracket_curly_left_head;
						tail = Cmex.bracket_curly_left_tail;
						extension = Cmex.bracket_curly_left_vertical_bar;
					} else if(delimiters == Delimiters.square) {
						head = Cmex.bracket_square_left_head;
						tail = Cmex.bracket_square_left_tail;
						extension = Cmex.bracket_square_left_vertical_bar;
					} else {
						head = Cmex.bracket_paren_left_head;
						tail = Cmex.bracket_paren_left_tail;
						extension = Cmex.bracket_paren_left_vertical_bar;
					}
					
					//calculate the height of each
					float headHeight = graphics.boundingHeight(head, font, fontNumber, fontSize())-m;
					float middleHeight = (delimiters == Delimiters.curly ? graphics.boundingHeight(middle, font, fontNumber, fontSize()) : 0f)-m;
					float extHeight = graphics.boundingHeight(extension, font, fontNumber, fontSize())-m;
					
					 // this is only the number of extensions in one direction, so have to multiply by 2
					int extensionCount = (delimSizeIsOverriden()) ? this.extensionCount : 
						minimumN(
							headHeight + (middleHeight/2), 
							extHeight, 
							maximumBracketShortfall(), 
							Math.max(innerBox.axis(), innerBox.depth()));
					
					if(type != DelimiterType.right) {
						// draw head
						graphics.drawChar(head, font, fontNumber, fontSize(), x4, y4);
						y4 += headHeight;
						
						// draw head-to-middle extensions
						for(int i=0; i<extensionCount; i++){
							graphics.drawChar(extension, font, fontNumber, fontSize(), x4, y4);
							y4 += extHeight;
							//c.drawLine(x4,y4,x4+30,y4,paint());
						}
						
						// draw middle
						if(delimiters == Delimiters.curly) graphics.drawChar(middle, font, fontNumber, fontSize(),x4,y4);
						y4 += middleHeight;
						
						// draw middle-to-tail extensions
						for(int i=0; i<extensionCount; i++){
							graphics.drawChar(extension, font, fontNumber, fontSize(), x4, y4);
							y4 += extHeight;
						}
						
						// draw tail
						graphics.drawChar(tail, font, fontNumber, fontSize(), x4, y4);
					}
					
					// --------- Right bracket ---------
					// the bracket head, tail and the extension piece
					
					if(type != DelimiterType.left) {
						
						x4 = x1 + innerBoxMargin() + innerBox.width();
						y4 = axis() - (delimiterHeight()/2);
						middle = Cmex.bracket_curly_right_middle;
						
						if(delimiters == Delimiters.curly) {
							head = Cmex.bracket_curly_right_head;
							tail = Cmex.bracket_curly_right_tail;
							extension = Cmex.bracket_curly_right_vertical_bar;
						} else if(delimiters == Delimiters.square) {
							head = Cmex.bracket_square_right_head;
							tail = Cmex.bracket_square_right_tail;
							extension = Cmex.bracket_square_right_vertical_bar;
						} else {
							head = Cmex.bracket_paren_right_head;
							tail = Cmex.bracket_paren_right_tail;
							extension = Cmex.bracket_paren_right_vertical_bar;
						}
		
						// draw head
						graphics.drawChar(head, font, fontNumber, fontSize(), x4, y4);
						y4 += headHeight;
						
						// draw head-to-middle extensions
						for(int i=0; i<extensionCount; i++){
							graphics.drawChar(extension, font, fontNumber, fontSize(), x4, y4);
							y4 += extHeight;
						}
						
						// draw middle
						if(delimiters == Delimiters.curly) graphics.drawChar(middle, font, fontNumber, fontSize(),x4,y4);
						y4 += middleHeight;
						
						// draw middle-to-tail extensions
						for(int i=0; i<extensionCount; i++){
							graphics.drawChar(extension, font, fontNumber, fontSize(), x4, y4);
							y4 += extHeight;
						}
						
						// draw tail
						graphics.drawChar(tail, font, fontNumber, fontSize(), x4, y4);
					}
			}
		}
	}
	
	/**
	 * 
	 * @return the thickness of the absolute-value bars: |foo|
	 */
	private float absLineThickness() {
		return lineThickness();
//		if(style == TexStyle.D || style == TexStyle.DC) return lineThickness();
//		else return Math.max(1f,lineThickness() * C.sqrt_bar_nondisplay_thinning_factor);
	}
	
	private float absLineAdvancingWidth() {
		return C.abs_bar_advancing_width_factor * fontSize();
//		if(style == TexStyle.D || style == TexStyle.DC) return lineThickness();
//		else return Math.max(1f,lineThickness() * C.sqrt_bar_nondisplay_thinning_factor);
	}


	@Override
	protected void setChildrenStyle() {
		innerBox.setStyle(style);		
	}

	@Override
	protected void eraseMemory() {
		bracketWidth = Float.NEGATIVE_INFINITY;
		determineBracketSize = null;
		maximumBracketShortfall = Float.NEGATIVE_INFINITY;
		delimiterHeight = Float.NEGATIVE_INFINITY;
		getLeftBracket = 0x00;
		getRightBracket = 0x00;
		innerBoxMargin = Float.NEGATIVE_INFINITY;
	}
	
	// For optimizations these fields store the return
	// results of expensive methods, so that the expensive
	// methods only need to execute once
	
	/**
	 * Optimization field
	 */
	float bracketWidth = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	Size determineBracketSize = null;
	
	/**
	 * Optimization field
	 */
	float maximumBracketShortfall = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	float delimiterHeight = Float.NEGATIVE_INFINITY;
	
	/**
	 * Optimization field
	 */
	char getLeftBracket = 0x00;
	
	/**
	 * Optimization field
	 */
	char getRightBracket = 0x00;
	
	/**
	 * Optimization field
	 */
	float innerBoxMargin = Float.NEGATIVE_INFINITY;

	
	@Override
	public float getSquashingDistance() {
		return 2 * this.innerBoxMargin() + innerBox.getSquashingDistance(); // left and right
	}

	@Override
	public Box squash(float factor) {
		DelimiterBox result = new DelimiterBox(
				this.innerBox.squash(factor), 
				this.delimiters, 
				this.type, 
				this.delimSizeOverride, 
				this.extensionCount, 
				factor);
		
		result.setState(this);
		return result;
	}

	@Override
	public Box[] split(Level level) {
		if(level == Level.easy) {
			return new Box[] { this }; // don't break inside brackets in easy
		} else {
			Box[] brokenInnerBox = innerBox.split(level);
			
			Size size = level == Level.medium ? determineDelimiterSize() : Size.tiny;
			int extensionCount;
			if(size != Size.extended) {
				extensionCount = -1;
			}else {	// calculate the extension count
				if(delimiters == Delimiters.abs) {
					// absolute bars are handled quite differently
					float pieceHeight = C.abs_bar_piece_height_factor * fontSize();
					
					extensionCount = delimSizeIsOverriden() ? this.extensionCount : 
						minimumN(
								0f,
								pieceHeight,
								maximumBracketShortfall(),
								Math.max(innerBox.axis(), innerBox.depth()));
					
					
				} else {
					// --------- Left bracket ----------
					// the bracket head, tail and the extension piece
					char head;
					char middle = Cmex.bracket_curly_left_middle;
					char extension;
					
					if(delimiters == Delimiters.curly) {
						head = Cmex.bracket_curly_left_head;
						extension = Cmex.bracket_curly_left_vertical_bar;
					} else if(delimiters == Delimiters.square) {
						head = Cmex.bracket_square_left_head;
						extension = Cmex.bracket_square_left_vertical_bar;
					} else {
						head = Cmex.bracket_paren_left_head;
						extension = Cmex.bracket_paren_left_vertical_bar;
					}
					
					//calculate the height of each
					float headHeight = graphics.boundingHeight(head, font, fontNumber, fontSize())-m;
					float middleHeight = (delimiters == Delimiters.curly ? graphics.boundingHeight(middle, font, fontNumber, fontSize()) : 0f)-m;
					float extHeight = graphics.boundingHeight(extension, font, fontNumber, fontSize())-m;
					
					 // this is only the number of extensions in one direction, so have to multiply by 2
					extensionCount = (delimSizeIsOverriden()) ? this.extensionCount : 
						minimumN(
							headHeight + (middleHeight/2), 
							extHeight, 
							maximumBracketShortfall(), 
							Math.max(innerBox.axis(), innerBox.depth()));				
				}
			}
			
			if(level != Level.nightmare) { // medium or hard
				if(brokenInnerBox.length == 1)
					return new Box[] { this };
				else {
					Box[] left = new Box[] {new DelimiterBox(
							brokenInnerBox[0], 
							this.delimiters, 
							DelimiterType.left, 
							size, 
							extensionCount, 
							squeezingFactor).setGraphics(graphics.sameGraphics())};
					
					Box[] right = new Box[] {new DelimiterBox(
							brokenInnerBox[brokenInnerBox.length-1],
							this.delimiters, 
							DelimiterType.right, 
							size, 
							extensionCount, 
							squeezingFactor).setGraphics(graphics.sameGraphics())};
					Box[] middle = new Box[brokenInnerBox.length-2];
					for(int i=1; i< brokenInnerBox.length-1; i++) {
						middle[i-1] = brokenInnerBox[i]; 
					}
					return concat(left,middle,right);
				}
			} else {
				return concat(
						new Box[] {new DelimiterBox(
								new SpaceBox(0.0f,0.0f), 
								this.delimiters, 
								DelimiterType.left, 
								size, 
								extensionCount, 
								squeezingFactor).setGraphics(graphics.sameGraphics())},
						brokenInnerBox,	
						new Box[] {new DelimiterBox(
								new SpaceBox(0.0f,0.0f), 
								this.delimiters, 
								DelimiterType.right, 
								size, 
								extensionCount, 
								squeezingFactor).setGraphics(graphics.sameGraphics())});
			}
		}
	}
}
