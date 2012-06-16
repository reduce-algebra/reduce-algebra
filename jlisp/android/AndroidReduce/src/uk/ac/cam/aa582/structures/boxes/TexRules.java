package uk.ac.cam.aa582.structures.boxes;

public class TexRules {
	
	
	public static TexStyle superscriptOf(TexStyle style){
		switch(style){
		case D : 			return TexStyle.S;
		case DC : 			return TexStyle.SC;
		case T : 			return TexStyle.S;
		case TC : 			return TexStyle.SC;
		case S : 			return TexStyle.SS;
		case SC : 			return TexStyle.SSC;
		case SS : 			return TexStyle.SS;
		case SSC : 			return TexStyle.SSC;
		default : 	return TexStyle.D;
		}
	}
	
	public static TexStyle subscriptOf(TexStyle style){
		switch(style){
		case D : 			return TexStyle.SC;
		case DC : 			return TexStyle.SC;
		case T : 			return TexStyle.SC;
		case TC : 			return TexStyle.SC;
		case S : 			return TexStyle.SSC;
		case SC : 			return TexStyle.SSC;
		case SS : 			return TexStyle.SSC;
		case SSC : 			return TexStyle.SSC;
		default : 			return TexStyle.D;
		}
	}
	
	public static TexStyle crampedVersionOf(TexStyle style){
		switch(style){
		case D : 			return TexStyle.DC;
		case DC : 			return TexStyle.DC;
		case T : 			return TexStyle.TC;
		case TC : 			return TexStyle.TC;
		case S : 			return TexStyle.SC;
		case SC : 			return TexStyle.SC;
		case SS : 			return TexStyle.SSC;
		case SSC : 			return TexStyle.SSC;
		default : return TexStyle.D;
		}
	}
	
	public static TexStyle numeratorOf(TexStyle style){
		switch(style){
		case D : 			return TexStyle.T;
		case DC : 			return TexStyle.TC;
		case T : 			return TexStyle.S;
		case TC : 			return TexStyle.SC;
		case S : 			return TexStyle.SS;
		case SC : 			return TexStyle.SSC;
		case SS : 			return TexStyle.SS;
		case SSC : 			return TexStyle.SSC;
		default : return TexStyle.D;
		}
	}
	
	public static TexStyle denominatorOf(TexStyle style){
		switch(style){
		case D : 			return TexStyle.TC;
		case DC : 			return TexStyle.TC;
		case T : 			return TexStyle.SC;
		case TC : 			return TexStyle.SC;
		case S : 			return TexStyle.SSC;
		case SC : 			return TexStyle.SSC;
		case SS : 			return TexStyle.SSC;
		case SSC : 			return TexStyle.SSC;
		default : return TexStyle.D;
		}
	}


	
	
	public static Size opSize(TexStyle style) {
		if(style == TexStyle.D || style == TexStyle.DC)
			return Size.large;
		else return Size.small;
	}
	
	/**
	 * The same computer modern font usually comes in many
	 * different "numbers" that differ slightly in their 
	 * thickness, for example, cmr10 is like cmr5 except that 
	 * chars in the latter are a little "fatter" than in the former.<br/>
	 * TeX uses different font numbers for different styles,
	 * because for example, a style in which characters are
	 * small (like script style) would be associated with a lower
	 * number so that the characters are thicker and easier to see.
	 * 
	 *  
	 * @param font The font for which to calculate the number
	 * @param style The style of the drawn font 
	 * @return The computer modern font number based on the font
	 * and the TeX style
	 */
	public static int selectFontNumber(Font font, TexStyle style) {
		if(font == Font.regular) return 0; // size is not defined for a regular font
		if(font == Font.cmex) return 10; // only one size for cmex
		else {
			switch(style) {
			case D : 
			case DC : 
			case T : 
			case TC : return 10;
			case S :
			case SC : return 7;
			case SS :
			case SSC : return 5;
			default : throw new IllegalStateException("This exception cannot throw"); // should not reach here
		}
			
	}
	}

	public static boolean relationMarginsExist(TexStyle style) {
		return style == TexStyle.D || style == TexStyle.DC || style == TexStyle.T || style == TexStyle.TC;
	}

	public static boolean operationMarginsExist(TexStyle style) {
		return style == TexStyle.D || style == TexStyle.DC || style == TexStyle.T || style == TexStyle.TC;
	}
}
