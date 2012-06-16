package uk.ac.cam.aa582.structures.boxes;

import java.util.Iterator;

import uk.ac.cam.aa582.structures.boxes.BoxUtil.Level;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.DelimiterType;
import uk.ac.cam.aa582.structures.boxes.DelimiterBox.Delimiters;

public class SqrtBox extends Box {


	Box innerBox;
	private float m = 2f;
	
	public SqrtBox(Box rooted) {
		if(rooted != null) innerBox = rooted;
		else innerBox = defaultBox();
		
		useFont(Font.cmsy);
		setChildrenStyle();
	}

	@Override
	protected float lineThickness() {
		float thinningFactor = 
				style != TexStyle.D && 
				style != TexStyle.DC && 
				style != TexStyle.T && 
				style != TexStyle.TC ? 
				C.sqrt_bar_nondisplay_thinning_factor : 
				1f;
				
		return super.lineThickness() * thinningFactor;
				
	}

	private float sqrtSymbolWidth() {
		if(optimize && sqrtSymbolWidth >= 0) return sqrtSymbolWidth;
		
		char sqrt = getSqrtSymbol();
		return sqrtSymbolWidth = graphics.advancingWidth(sqrt, font, fontNumber, fontSize());
	}
	
	private float sqrtSymbolHeight() {
		if(optimize && sqrtSymbolHeight >= 0) return sqrtSymbolHeight;
		
		Size size = determineSqrtSymbolSize();
		if(size != Size.extended) {
			
			char sqrt = getSqrtSymbol();
			return sqrtSymbolHeight = graphics.boundingHeight(sqrt, font, fontNumber, fontSize());
			
		} else {
			
			char base = Cmex.sqrt_base;
			char ext = Cmex.sqrt_vertical_bar;
			char corner = Cmex.sqrt_corner;
			
			float baseHeight = graphics.boundingHeight(base, font, fontNumber, fontSize())-m ;
			float extHeight = graphics.boundingHeight(ext, font, fontNumber, fontSize())-m;
			float cornerHeight = graphics.boundingHeight(corner, font, fontNumber, fontSize());
			
			int extCount = minimumN(
					baseHeight+cornerHeight, 
					extHeight, 
					0f, 
					minimumInnerHeight());
			
			return sqrtSymbolHeight = cornerHeight + (extCount * extHeight) + baseHeight;
		}
	}
	
	private char getSqrtSymbol() {
		if(optimize && getSqrtSymbol != 0x00) return getSqrtSymbol;
		
		Size size = determineSqrtSymbolSize();
		switch(size) {
		case tiny : return getSqrtSymbol = S.symbol(S.sqrt_tiny);
		case small : return getSqrtSymbol = Cmex.sqrt_small;
		case medium : return getSqrtSymbol = Cmex.sqrt_medium;
		case large : return getSqrtSymbol  = Cmex.sqrt_large;
		case xlarge : return getSqrtSymbol = Cmex.sqrt_xlarge;
		case extended : return getSqrtSymbol = Cmex.sqrt_base;
		default : return 0x00; // never reaches here
		}
		
	}

	private Size determineSqrtSymbolSize() {
		if(optimize && determineSqrtSymbolSize != null) return determineSqrtSymbolSize;
		
		float minHeight = minimumInnerHeight() - lineThickness();
		
		useFont(Font.cmsy);
		if(graphics.boundingHeight((char)0x70, font, fontNumber, fontSize()) > minHeight) return determineSqrtSymbolSize = Size.tiny;
		else {
			useFont(Font.cmex);
			if(graphics.boundingHeight(Cmex.sqrt_small, font, fontNumber, fontSize()) > minHeight) return determineSqrtSymbolSize = Size.small;	
			else if(graphics.boundingHeight(Cmex.sqrt_medium, font, fontNumber, fontSize()) > minHeight) return determineSqrtSymbolSize = Size.medium;
			else if(graphics.boundingHeight(Cmex.sqrt_large, font, fontNumber, fontSize()) > minHeight) return determineSqrtSymbolSize = Size.large;
			else if(graphics.boundingHeight(Cmex.sqrt_xlarge, font, fontNumber, fontSize()) > minHeight) return determineSqrtSymbolSize = Size.xlarge;
			else return determineSqrtSymbolSize = Size.extended;
		}
	}

	private float minimumInnerHeight() {
		if(optimize && minimumInnerHeight >= 0) return minimumInnerHeight;
		
		return minimumInnerHeight =
				innerBox.height() 
				+ minimumBottomMargin() 
				+ minimumTopMargin(); 
	}
	
	private float minimumTopMargin() {
		if(optimize && minimumTopMargin >= 0) return minimumTopMargin;
		
		return minimumTopMargin =
				Math.max((style == TexStyle.D ? C.minimum_display_sqrt_top_margin_factor 
						: C.minimum_nondisplay_sqrt_top_margin_factor) * fontSize(), 1f);
	}
	
	private float minimumBottomMargin() {
		if(optimize && minimumBottomMargin >= 0) return minimumBottomMargin;
		
		return minimumBottomMargin =
				(style == TexStyle.D ? C.minimum_display_sqrt_bottom_margin_factor 
						: C.minimum_nondisplay_sqrt_bottom_margin_factor) * fontSize();
	}
	
	
	@Override
	public Iterator<Box> iterator() {
		return iteratorOver(innerBox);
	}

	@Override
	public float width() {
		if(optimize && width >= 0) return width;
		
		return width = 
				sqrtSymbolWidth() + innerBox.width();
	}

	@Override
	public float height() {
		if(optimize && height >= 0) return height;
		
		return height = sqrtSymbolHeight();
	}

	@Override
	public float axis() {
		if(optimize && axis >= 0) return axis;
		
		return axis = 
				((sqrtSymbolHeight() - lineThickness() - minimumInnerHeight()) /2) 
				+ minimumTopMargin() + innerBox.axis();
	}
	
	@Override
	public void onDraw() {
		
		graphics.setOrigin(xOrigin(),yOrigin());
		
		// draw inner box
		float x1 = sqrtSymbolWidth();
		float y1 = this.axis() - innerBox.axis();
		
		drawBox(innerBox, x1, y1);
		
		Size size = determineSqrtSymbolSize();
		// draw sqrt symbol
		if(size == Size.tiny) {
			useFont(Font.cmsy);
			char sqrt = getSqrtSymbol();
			graphics.drawChar(sqrt, font, fontNumber, fontSize(), 0, 0);
		}
		else {

			useFont(Font.cmex);
			if(size != Size.extended) {
			
				useFont(Font.cmex);
				char sqrt = getSqrtSymbol();
				graphics.drawChar(sqrt, font, fontNumber, fontSize(), 0, 0);
			} else {
				char base = Cmex.sqrt_base;
				char ext = Cmex.sqrt_vertical_bar;
				char corner = Cmex.sqrt_corner;
				
				float baseHeight = graphics.boundingHeight(base, font, fontNumber, fontSize())-m;
				float extHeight = graphics.boundingHeight(ext, font, fontNumber, fontSize())-m;
				float cornerHeight = graphics.boundingHeight(corner, font, fontNumber, fontSize());
				
				int extCount = minimumN(
						baseHeight+cornerHeight, 
						extHeight, 
						0f, 
						minimumInnerHeight());
				
				float x2 = 0f;
				float y2 = 0f;
				
				graphics.drawChar(corner, font, fontNumber, fontSize(),x2,y2);
				y2 += cornerHeight;
				
				for(int i=0; i<extCount; i++) {
					graphics.drawChar(ext, font, fontNumber, fontSize(),x2,y2);
					y2 += extHeight;
			}
			
			graphics.drawChar(base, font, fontNumber, fontSize(),x2,y2);
			}
		}
		// draw horizontal line
		float startX = sqrtSymbolWidth();
		float startY = lineThickness()/2;
		float stopX = width();
		float stopY = startY;
		
		graphics.drawLine(lineThickness(), startX, startY, stopX, stopY);

	}

	@Override
	protected void eraseMemory() {
		lineThickness = Float.NEGATIVE_INFINITY;
		sqrtSymbolWidth = Float.NEGATIVE_INFINITY;
		sqrtSymbolHeight = Float.NEGATIVE_INFINITY;
		getSqrtSymbol = 0x00;
		determineSqrtSymbolSize = null;
		minimumInnerHeight = Float.NEGATIVE_INFINITY;
		minimumTopMargin = Float.NEGATIVE_INFINITY;
		minimumBottomMargin = Float.NEGATIVE_INFINITY;
	}

	float lineThickness = Float.NEGATIVE_INFINITY;
	float sqrtSymbolWidth = Float.NEGATIVE_INFINITY;
	float sqrtSymbolHeight = Float.NEGATIVE_INFINITY;
	char getSqrtSymbol = 0x00;
	Size determineSqrtSymbolSize = null;
	float minimumInnerHeight = Float.NEGATIVE_INFINITY;
	float minimumTopMargin = Float.NEGATIVE_INFINITY;
	float minimumBottomMargin = Float.NEGATIVE_INFINITY;

	
	@Override
	public void setChildrenStyle() {
		innerBox.setStyle(TexRules.crampedVersionOf(style));
	}


	@Override
	public float getSquashingDistance() {
		return innerBox.getSquashingDistance();
	}


	@Override
	public Box squash(float factor) {
		Box result = new SqrtBox(innerBox.squash(factor));
		result.setState(this);
		return result;
	}

	@Override
	public Box[] split(Level level) {
		if(level == Level.hard || level == Level.nightmare) {
			Box innerBoxWithBrackets;
			if(innerBox instanceof DelimiterBox) { // already has brackets
				innerBoxWithBrackets = innerBox;
			}
			else {
				innerBoxWithBrackets = new DelimiterBox(innerBox, Delimiters.paren, DelimiterType.leftAndRight)
						.setGraphics(graphics.sameGraphics());
			}
			Box[] split = innerBoxWithBrackets.split(level);
			split[0] = new SequenceBox( new SqrtBox(new SpaceBox(0f,0.1f)), split[0])//new SymbolBox(S.sqrt_tiny), split[0])
						.setGraphics(graphics.sameGraphics());
			return split;
		} else {
			return new Box[] { this };
		}
	}
}
