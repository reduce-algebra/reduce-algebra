package uk.ac.cam.aa582.structures.boxes;

/**
 * Every part of a formula is drawn on the screen in a certain font,
 * font size, margins and spaces. All these are determined by the TEX style
 * of that part of the formula. For example if the main formula is in
 * display style then the superscripts are in script style, the numerator
 * in the fraction is in text style and the part under the square root sign
 * is in cramped display style, etc... <br/>
 * There exists four TEX styles (Display, Text, Script, Scriptscript) and for each
 * one of those styles, there is a cramped version (e.g. cramped display style)
 * bringing the total up to 8.<br/>
 * These styles are named TEX styles because they are used in the TEX typesetting
 * system and are taken from it and used in this application.
 * 
 * @author Ahmad Akra
 *
 */
public enum TexStyle {
	/**
	 * Display style
	 */
	D, 
	
	/**
	 * Cramped display style
	 */
	DC,
	
	/**
	 * Text style
	 */
	T,
	
	/**
	 * Cramped text style
	 */
	TC,
	
	/**
	 * Script style
	 */
	S,
	
	/**
	 * Cramped script style
	 */
	SC,
	
	/**
	 * Scriptscript style
	 */
	SS,
	
	/**
	 * Cramped scriptscript style
	 */
	SSC
}
