package uk.ac.cam.aa582.structures.tex;

import uk.ac.cam.aa582.structures.tex.TexLexer.Do;
import uk.ac.cam.aa582.structures.tex.TexLexer.TokenType;
import uk.ac.cam.aa582.structures.tex.TexLexer.LexFont;
import uk.ac.cam.aa582.structures.tex.TexParser.Function;

public class Token {
	
	public Token(String name, TokenType type, LexFont font, char c, Do d, Function f) {
		this.name = name;
		this.type = type;
		this.font = font;
		this.charCode = c;
		this.ptr = f;
		this.d = d;
	}
	
	public String name;
	public TokenType type;
	public LexFont font;
	public char charCode;
	public Function ptr;
	public Do d;
	
	@Override
	public String toString() {
		return name;
	}
}
