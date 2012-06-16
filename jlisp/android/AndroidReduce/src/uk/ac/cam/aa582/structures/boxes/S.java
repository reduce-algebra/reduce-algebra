package uk.ac.cam.aa582.structures.boxes;

/**
 * Many math symbols are stored here in short integer fields<br/>
 * The short integer encodes the character in the first 8 bits 
 * (0x00FF) and the font in the next 4 bits (0x0F00)
 * For example: 0x0DA1 specifies the char A1 in font D (which
 * happens to be cmsy)<br/>
 * This class contains few more utility methods to extract the
 * char and font information from the short integer.<br/>  
 * The field names are chosen to be the TeX name of that symbol 
 * (when applicable), for example pm stands for "plus or minus" 
 * which is the TeX name for the symbol
 * 
 * @author Ahmad Akra
 *
 */
public class S {
	
	
	/**
	 * Extract the font information from the short integer
	 * given how they are encoded in this class
	 * 
	 * @param s the short int to extract the info from
	 * @return the font file encoded in the short int
	 */
	public static Font font(short s) {
		char fontCode = (char) ((s & 0x0F00)/(0x0100));
		
		if(fontCode == 0x0A) return Font.cmr;
		if(fontCode == 0x0B) return Font.cmmi;
		if(fontCode == 0x0C) return Font.cmex;
		if(fontCode == 0x0D) return Font.cmsy;
		
		return Font.cmr;
	}
	
	/**
	 * Extract the character from the short integer
	 * given how it is encoded in the fields of this
	 * class
	 * 
	 * @param s the short int to extract the info from
	 * @return the character encoded in the short int
	 */
	public static char symbol(short s) { 
		//s = (s & 0x00FF);
		return (char)  (s & 0x00FF);
	}
	
	/**
	 * 
	 * @param s the short int to turn into text
	 * @return the Reduce string representation of the
	 * symbol encoded in the parameter, for example
	 * <tt>text(S.times)</tt> returns <tt>"*"</tt> 
	 */
	public static String text(short s) {
		switch(s) {
		case minus : return "-";
		case times : return "*";
		case div : return "/";
		case pi : return "pi";
		case infty : return "infinity";
		default : return symbol(s)+"";
		}
	}
	
	/**
	 * +
	 */
	public static final short plus 			= 0x0A00 + '+';
	
	/**
	 * Minus sign
	 */
	public static final short minus 		= 0x0DA1;
	
	/**
	 * Plus of minus
	 */
	public static final short pm			= 0x0DA7;
	
	/**
	 * Minus of plus
	 */
	public static final short mp			= 0x0DA8;
	
	/**
	 * Multiplication symbol
	 */
	public static final short times 		= 0x0DA3;
	
	/**
	 * Division symbol
	 */
	public static final short div			= 0x0DA5;
	
	/**
	 * *
	 */
	public static final short ast			= 0x0DA4;
	public static final short cdot			= 0x0DA2;
    public static final short ominus 		= 0x0DAA;
    public static final short oplus 		= 0x0DA9;
    public static final short oslash 		= 0x0DAE;
    public static final short otimes 		= 0x0DAD;
    public static final short odot 			= 0x0DAF;
    
    /**
     * =
     */
    public static final short equals		= 0x0A00 + '=';
    
    /**
     * Less then sign
     */
    public static final short lessthen		= 0x0A00 + '<';
    
    /**
     * Greater then sign
     */
    public static final short greaterthen 	= 0x0A00 + '>';
    
    /**
     * Less then or equal sign
     */
    public static final short leq			= 0x0DB7;
    
    /**
     * Greater then or equal sign
     */
    public static final short geq			= 0x0DB8;
    public static final short simeq 		= 0x0D27;
    
    /**
     * Approximately equal sign
     */
    public static final short approx		= 0x0DBC;
    
    /**
     * Infinity
     */
    public static final short infty 		= 0x0D31;
    
	/**
	 * Letter a in Computer Modern Math Italic font (cmmi)
	 */
	public static final short a				= 0x0B00 + 'a';

	/**
	 * Letter b in Computer Modern Math Italic font (cmmi)
	 */
	public static final short b				= 0x0B00 + 'b';

	/**
	 * Letter c in Computer Modern Math Italic font (cmmi)
	 */
	public static final short c				= 0x0B00 + 'c';

	/**
	 * Letter d in Computer Modern Math Italic font (cmmi)
	 */
	public static final short d				= 0x0B00 + 'd';

	/**
	 * Letter e in Computer Modern Math Italic font (cmmi)
	 */
	public static final short e				= 0x0B00 + 'e';

	/**
	 * Letter f in Computer Modern Math Italic font (cmmi)
	 */
	public static final short f				= 0x0B00 + 'f';

	/**
	 * Letter g in Computer Modern Math Italic font (cmmi)
	 */
	public static final short g				= 0x0B00 + 'g';

	/**
	 * Letter h in Computer Modern Math Italic font (cmmi)
	 */
	public static final short h				= 0x0B00 + 'h';

	/**
	 * Letter i in Computer Modern Math Italic font (cmmi)
	 */
	public static final short i				= 0x0B00 + 'i';

	/**
	 * Letter j in Computer Modern Math Italic font (cmmi)
	 */
	public static final short j				= 0x0B00 + 'j';

	/**
	 * Letter k in Computer Modern Math Italic font (cmmi)
	 */
	public static final short k				= 0x0B00 + 'k';

	/**
	 * Letter l in Computer Modern Math Italic font (cmmi)
	 */
	public static final short l				= 0x0B00 + 'l';

	/**
	 * Letter m in Computer Modern Math Italic font (cmmi)
	 */
	public static final short m				= 0x0B00 + 'm';

	/**
	 * Letter n in Computer Modern Math Italic font (cmmi)
	 */
	public static final short n				= 0x0B00 + 'n';

	/**
	 * Letter o in Computer Modern Math Italic font (cmmi)
	 */
	public static final short o				= 0x0B00 + 'o';

	/**
	 * Letter p in Computer Modern Math Italic font (cmmi)
	 */
	public static final short p				= 0x0B00 + 'p';

	/**
	 * Letter q in Computer Modern Math Italic font (cmmi)
	 */
	public static final short q				= 0x0B00 + 'q';

	/**
	 * Letter r in Computer Modern Math Italic font (cmmi)
	 */
	public static final short r				= 0x0B00 + 'r';

	/**
	 * Letter s in Computer Modern Math Italic font (cmmi)
	 */
	public static final short s				= 0x0B00 + 's';

	/**
	 * Letter t in Computer Modern Math Italic font (cmmi)
	 */
	public static final short t				= 0x0B00 + 't';

	/**
	 * Letter u in Computer Modern Math Italic font (cmmi)
	 */
	public static final short u				= 0x0B00 + 'u';

	/**
	 * Letter v in Computer Modern Math Italic font (cmmi)
	 */
	public static final short v				= 0x0B00 + 'v';

	/**
	 * Letter w in Computer Modern Math Italic font (cmmi)
	 */
	public static final short w				= 0x0B00 + 'w';

	/**
	 * Letter x in Computer Modern Math Italic font (cmmi)
	 */
	public static final short x				= 0x0B00 + 'x';

	/**
	 * Letter y in Computer Modern Math Italic font (cmmi)
	 */
	public static final short y				= 0x0B00 + 'y';

	/**
	 * Letter z in Computer Modern Math Italic font (cmmi)
	 */
	public static final short z				= 0x0B00 + 'z';

	/**
	 * Letter A in Computer Modern Math Italic font (cmmi)
	 */
	public static final short A				= 0x0B00 + 'A';

	/**
	 * Letter B in Computer Modern Math Italic font (cmmi)
	 */
	public static final short B				= 0x0B00 + 'B';

	/**
	 * Letter C in Computer Modern Math Italic font (cmmi)
	 */
	public static final short C				= 0x0B00 + 'C';

	/**
	 * Letter D in Computer Modern Math Italic font (cmmi)
	 */
	public static final short D				= 0x0B00 + 'D';

	/**
	 * Letter E in Computer Modern Math Italic font (cmmi)
	 */
	public static final short E				= 0x0B00 + 'E';

	/**
	 * Letter F in Computer Modern Math Italic font (cmmi)
	 */
	public static final short F				= 0x0B00 + 'F';

	/**
	 * Letter G in Computer Modern Math Italic font (cmmi)
	 */
	public static final short G				= 0x0B00 + 'G';

	/**
	 * Letter H in Computer Modern Math Italic font (cmmi)
	 */
	public static final short H				= 0x0B00 + 'H';

	/**
	 * Letter I in Computer Modern Math Italic font (cmmi)
	 */
	public static final short I				= 0x0B00 + 'I';

	/**
	 * Letter J in Computer Modern Math Italic font (cmmi)
	 */
	public static final short J				= 0x0B00 + 'J';

	/**
	 * Letter K in Computer Modern Math Italic font (cmmi)
	 */
	public static final short K				= 0x0B00 + 'K';

	/**
	 * Letter L in Computer Modern Math Italic font (cmmi)
	 */
	public static final short L				= 0x0B00 + 'L';

	/**
	 * Letter M in Computer Modern Math Italic font (cmmi)
	 */
	public static final short M				= 0x0B00 + 'M';

	/**
	 * Letter N in Computer Modern Math Italic font (cmmi)
	 */
	public static final short N				= 0x0B00 + 'N';

	/**
	 * Letter O in Computer Modern Math Italic font (cmmi)
	 */
	public static final short O				= 0x0B00 + 'O';

	/**
	 * Letter P in Computer Modern Math Italic font (cmmi)
	 */
	public static final short P				= 0x0B00 + 'P';

	/**
	 * Letter Q in Computer Modern Math Italic font (cmmi)
	 */
	public static final short Q				= 0x0B00 + 'Q';

	/**
	 * Letter R in Computer Modern Math Italic font (cmmi)
	 */
	public static final short R				= 0x0B00 + 'R';

	/**
	 * Letter S in Computer Modern Math Italic font (cmmi)
	 */
	public static final short S				= 0x0B00 + 'S';

	/**
	 * Letter T in Computer Modern Math Italic font (cmmi)
	 */
	public static final short T				= 0x0B00 + 'T';

	/**
	 * Letter U in Computer Modern Math Italic font (cmmi)
	 */
	public static final short U				= 0x0B00 + 'U';

	/**
	 * Letter V in Computer Modern Math Italic font (cmmi)
	 */
	public static final short V				= 0x0B00 + 'V';

	/**
	 * Letter W in Computer Modern Math Italic font (cmmi)
	 */
	public static final short W				= 0x0B00 + 'W';

	/**
	 * Letter X in Computer Modern Math Italic font (cmmi)
	 */
	public static final short X				= 0x0B00 + 'X';

	/**
	 * Letter Y in Computer Modern Math Italic font (cmmi)
	 */
	public static final short Y				= 0x0B00 + 'Y';

	/**
	 * Letter Z in Computer Modern Math Italic font (cmmi)
	 */
	public static final short Z				= 0x0B00 + 'Z';

    public static final short alpha 		= 0x0BAE;
    public static final short beta 			= 0x0BAF;
    public static final short gamma 		= 0x0BB0;
    public static final short delta 		= 0x0BB1;
    public static final short epsilon 		= 0x0BB2;
    public static final short zeta 			= 0x0BB3;
    public static final short eta 			= 0x0BB4;
    public static final short theta 		= 0x0BB5;
    public static final short iota 			= 0x0BB6;
    public static final short kappa 		= 0x0BB7;
    public static final short lambda 		= 0x0BB8;
    public static final short mu 			= 0x0BB9;
    public static final short nu 			= 0x0BBA;
    public static final short xi 			= 0x0BBB;
    public static final short pi 			= 0x0BBC;
    public static final short rho 			= 0x0BBD;
    public static final short sigma 		= 0x0BBE;
    public static final short tau 			= 0x0BBF;
    public static final short upsilon 		= 0x0BC0;
    public static final short phi 			= 0x0BC1;
    public static final short chi 			= 0x0BC2;
    public static final short psi 			= 0x0BC3;
    
    public static final short omega 		= 0x0B21;
    public static final short varepsilon 	= 0x0B22;    
    public static final short vartheta 		= 0x0B23;    
    public static final short varpi 		= 0x0B24;	
    public static final short varrho 		= 0x0B25;
    public static final short varphi 		= 0x0B27;
    
    public static final short Gamma 		= 0x0BA1;
    public static final short Delta 		= 0x0BA2;
    public static final short Theta 		= 0x0BA3;
    public static final short Lambda		= 0x0BA4;
    public static final short Xi 			= 0x0BA5;
    public static final short Pi 			= 0x0BA6;
    public static final short Sigma 		= 0x0BA7;
    public static final short Upsilon 		= 0x0BA8;
    public static final short Phi 			= 0x0BA9;
    public static final short Psi 			= 0x0BAA;
    public static final short Omega 		= 0x0BAD;

    public static final short rightarrow	= 0x0D21;
    public static final short leftarrow		= 0x0DC3;
    public static final short uparrow		= 0x0D22;
    public static final short downarrow		= 0x0D23;
    public static final short Rightarrow	= 0x0D27;
    public static final short Leftarrow		= 0x0D28;
    public static final short Uparrow		= 0x0D2A;
    public static final short Downarrow		= 0x0D2B;
    

    /**
     * Small integral sign
     */
	public static final short int_small 	= 0x0C52;
	
	/**
	 * Large integral sign
	 */
	public static final short int_large 	= 0x0C5A;
	
	/**
	 * Small summation sign (Sigma)
	 */
	public static final short sum_small 	= 0x0C50;
	
	/**
	 * Large summation sign (Sigma)
	 */
	public static final short sum_large 	= 0x0C58;
	
	/**
	 * Small closed loop integral sign
	 */
	public static final short oint_small 	= 0x0C48;
	
	/**
	 * Large closed loop integral sign
	 */
	public static final short oint_large 	= 0x0C49;
	
	/**
	 * Small product sign (pi)
	 */
	public static final short prod_small 	= 0x0C51;
	
	/**
	 * Large product sign (pi)
	 */
	public static final short prod_large 	= 0x0C59;
	
	/**
	 * Curl symbol (triangle)
	 */
	public static final short curl 			= 0x0D72;
	
	/**
	 * Forward slash /
	 */
	public static final short slash 		= 0x0A00 + '/';
	
	/**
	 * Vertical bar |
	 */
	public static final short abs_bar_tiny							= 0x0D6A;
	
	public static final short bracket_paren_left_tiny				= 0x0A00 + '(';
	public static final short bracket_paren_left_small 				= 0x0CA1;
	public static final short bracket_paren_left_medium 			= 0x0CB3;
	public static final short bracket_paren_left_large 				= 0x0CB5;
	public static final short bracket_paren_left_xlarge 			= 0x0CC3;
	public static final short bracket_paren_left_head 				= 0x0C30;
	public static final short bracket_paren_left_tail 				= 0x0C40;
	public static final short bracket_paren_left_vertical_bar		= 0x0C42;

	public static final short bracket_paren_right_tiny 				= 0x0A00 + ')';
	public static final short bracket_paren_right_small 			= 0x0CA2;
	public static final short bracket_paren_right_medium 			= 0x0CB4;
	public static final short bracket_paren_right_large 			= 0x0CB6;
	public static final short bracket_paren_right_xlarge 			= 0x0C21;
	public static final short bracket_paren_right_head 				= 0x0C31;
	public static final short bracket_paren_right_tail 				= 0x0C41;
	public static final short bracket_paren_right_vertical_bar		= 0x0C43;

	public static final short bracket_square_left_tiny				= 0x0A00 + '[';
	public static final short bracket_square_left_small				= 0x0CA3;
	public static final short bracket_square_left_medium			= 0x0C68;
	public static final short bracket_square_left_large				= 0x0CB7;
	public static final short bracket_square_left_xlarge			= 0x0C22;
	public static final short bracket_square_left_head				= 0x0C32;
	public static final short bracket_square_left_tail				= 0x0C34;
	public static final short bracket_square_left_vertical_bar		= 0x0C36;

	public static final short bracket_square_right_tiny				= 0x0A00 + ']';
	public static final short bracket_square_right_small			= 0x0CA4;
	public static final short bracket_square_right_medium			= 0x0C69;
	public static final short bracket_square_right_large			= 0x0CB8;
	public static final short bracket_square_right_xlarge			= 0x0C23;
	public static final short bracket_square_right_head				= 0x0C33;
	public static final short bracket_square_right_tail				= 0x0C35;
	public static final short bracket_square_right_vertical_bar		= 0x0C37;

	public static final short bracket_curly_left_tiny 				= 0x0D66;
	public static final short bracket_curly_left_small				= 0x0CA9;
	public static final short bracket_curly_left_medium				= 0x0C6E;
	public static final short bracket_curly_left_large				= 0x0CBD;
	public static final short bracket_curly_left_xlarge				= 0x0C28;
	public static final short bracket_curly_left_head				= 0x0C38;
	public static final short bracket_curly_left_tail				= 0x0C3A;
	public static final short bracket_curly_left_vertical_bar		= 0x0C3E;
	public static final short bracket_curly_left_middle				= 0x0C3C;
	
	public static final short bracket_curly_right_tiny 				= 0x0D67;
	public static final short bracket_curly_right_small				= 0x0CAA;
	public static final short bracket_curly_right_medium			= 0x0C6F;
	public static final short bracket_curly_right_large				= 0x0CBE;
	public static final short bracket_curly_right_xlarge			= 0x0C29;
	public static final short bracket_curly_right_head				= 0x0C39;
	public static final short bracket_curly_right_tail				= 0x0C3B;
	public static final short bracket_curly_right_vertical_bar		= 0x0C3E;
	public static final short bracket_curly_right_middle			= 0x0C3D;

	/**
	 * The smallest square root sign
	 */
	public static final short sqrt_tiny 							= 0x0D70;
	public static final short sqrt_small							= 0x0C70;
	public static final short sqrt_medium							= 0x0C71;
	public static final short sqrt_large							= 0x0C72;
	public static final short sqrt_xlarge							= 0x0C73;
	public static final short sqrt_base								= 0x0C74;
	public static final short sqrt_vertical_bar						= 0x0C75;
	public static final short sqrt_corner							= 0x0C76;
	
}
