package uk.ac.cam.aa582.structures.boxes;

/**
 * The application talks about which font to use when drawing on the screen
 * through this enumeration. It is up to the implementer of {@link Graphics#setFont(Font, int)}
 * to make sure that calling that method on e.g. {@link Font#cmr} and 10 will set the drawing
 * font to cmr10.ttf <br/>
 * The fonts in this enumeration correspond to some of the Computer 
 * Modern fonts used by default in the LaTeX typesetting system
 * 
 * @author Ahmad Akra
 *
 */
public enum Font { 
	
	/**
	 * Any normal text font (e.g. Times New Roman or Sans Serif)
	 */
	regular,
	
	/**
	 * Computer Modern Roman
	 */
	cmr, 
	
	/**
	 * Computer Modern Math Italic
	 */
	cmmi, 
	
	/**
	 * Computer Modern Math Symbols
	 */
	cmsy, 
	
	/**
	 * Computer Modern Math Extensions
	 */
	cmex 
	
}