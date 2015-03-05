% sml2red.red                                         (C) 2015 A C Norman

%
% This code is to parse SML-97 source code into Lisp parse trees, and
% will at a later stage massage some of what is created into something
% that can be execured within a Lisp world. Its sole initial purpose is
% to parse the SML implementation of the TeX maths layout algorithms that
% were prepared by Heckmann and Wilhelm (kept in a directory near where this
% file should live, I hope) as a route to getting TeX layout available to
% Reduce. Because of this limited aim it will support that subset of SML
% used in the Heckmann and Wilhelm source code and not guarantee anything
% beyond that. Completing it can be a nice project for somebody keen.
%
% Put another way, the implementation follows a varient on YAGNI (You Ain't
% Gonna Need It) except that when I do introduce support for an aspect of
% SML syntax I will try to make what I parse agree properly with the full
% definition of the language... the aim there being that extending this code
% will ideally mainly be extending to fill in visible gaps rather than needing
% to do significant re-work of stuff that is already present.

% The grammar as used here started by being derived from the "railway
% diagrams" in Larry Paulson's "ML for the Working Programmer". Since I am
% implementing it as a recursive descent parser there is no automatic
% guarantee that I will accept exactly the correct language, and there are
% certainly places where I am less restrictive than the specification I start
% from, and there are certainly places where the railway diagrams provide
% an ambiguous explanation of the syntax so I resolve those using other
% resources (eg testing on implementations of SML).
%
% As my work progressed I switched to concentrate on using the official
% SML '97 specification rather than Paulson's convenient book.
% I observe that sml-family.org explains: "With the permission of
% MIT Press, we are able to make The Definition of Standard ML (SML '90)
% and The Definition of Standard ML, Revised (SML '97) available for
% downloading as pdf files" and I would encourage anybody wanting to work on
% this code to either fetch from there or buy hard copy of the formal
% (and not entirely easily readable) specification since that counts as being
% properly authoritative and should resolve any uncertainty! Well actually the
% sections of the Definition that describe concrete syntax are as reasonably
% readable as almost anything else. Something to note is that the ambiguous
% productions such as
%    pat ::= pat infix pat
%        ::= pat : typ
% are to be resolved by precedence. For infix operators that will be the
% declared precedence (including the rules for what happens when precedences
% are equal and whether the operator has been declared left or right
% associative) but in other cases the order in which the clauses are listed
% in the grammar is to be taken to indicate precedence - with the first given
% production having pririty over lower ones. So in this particular case
% a form like "A op B : Ty" must parse as "(A op B) : Ty".
% My initial work aims just to parse SML into some form of parse three that
% Lisp/Reduce can then work with. Later activity will re-form that into a
% more directly Lisp-friendly form.




% Author: Arthur Norman.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%



% To start with this is not a Reduce package and I do not guarantee PSL
% compatibility, although I will try not to wilfully use CSL specific
% facilities.

lisp;
off echo;
on comp;
if member('csl, lispsystem!*) then <<
  enable!-errorset(3,3);
  verbos 7 >>;
on backtrace;

% I note that Reduce is in general not case sensitive, but as a matter of
% style I wish to use mixed case identifiers here. To ensure that
% I used these consistently I will disable Reduce's case folding so that
% if I accidentally got case incorrect I would end up with undefined
% functions or variable names.

off raise, lower;


% When I read characters I will want to keep a circular buffer of
% the last few that have been read so that I can display some context
% as part of any error report.

fluid '(smlChar smlCharsize smlChars smlCharp smlLine smlFile smlFileStack);

smlFile := "-";
smlFileStack := nil;
smlChar := '! ;
smlCharsize := 256;
smlChars := mkvect smlCharsize;
smlCharp := 0;
smlLine := 1;

fluid '(smlEofCount);
smlEofCount := 0;

symbolic procedure smlNextChar();
  begin
    scalar !*echo;
    smlChar := readch();
    if smlChar = !$eol!$ then smlLine := smlLine + 1;
    if smlChar = !$eof!$ then <<
      if (smlEofCount := smlEofCount + 1) > 10 then
        smlError "Too many end-of-file conditions reported";
      if null smlFileStack then return smlChar;
      smlFile := caar smlFileStack;
      smlLine := cadar smlFileStack;
      close rds cddar smlFileStack;
      smlFileStack := cdr smlFileStack;
      return smlNextChar() >>;
    smlEofCount := 0;
    putv(smlChars, smlCharp, smlChar);
    if (smlCharp := smlCharp + 1) = smlCharsize then smlCharp := 0;
    return smlChar
  end;

flag('(smlError), 'variadic);

% smlError takes a format string and some extra arguments and displays
% a message suitable for reporting syntax errors.

symbolic macro procedure smlError u;
  list('smlError1, cadr u, 'list . cddr u);

symbolic procedure smlError1(ff, a);
  begin
    scalar w, n;
    if not zerop posn() then terpri();
    princ "### Error: ";
    w := explodec ff;
    while w do <<
      while w and not eqcar(w, '!%) do <<
        princ car w;
        w := cdr w >>;
% The only escape supported so far is "%s". I think I should maybe invent
% some more!
      if w and eqcar(cdr w, 's) then <<
        princ car a;
        a := cdr a;
        w := cddr w >> >>;
    terpri();
    if smlFile neq "-" then <<
      princ "File ";
      princ smlFile;
      princ " " >>;
    princ "Line ";
    princ smlLine;
    terpri();
    princ "...";
    w := smlCharp;
    n := 0;
% I want to display a context of up to smlCharsize characters but also I want
% to limit myself to 5 lines. That is because if there had been (say) 35 blank
% lines just before the error it seems silly to see them!
    for i := 1:smlCharsize do <<
      if w = 0 then w := smlCharsize;
      w := w - 1;
      if getv(smlChars, w) = !$eol!$ then <<
        n := n + 1;
        if n > 5 then i := smlCharsize >> >>;
    if getv(smlChars, w) = !$eof!$ then princ "...";
    while w neq smlCharp do <<
      if (n := getv(smlChars, w)) then <<
        if n = !$eol!$ then << terpri(); princ "@@ " >>
        else princ n >>;
      if (w := w + 1) = smlCharsize then w := 0 >>;
    if n then terpri();
    error(1, "SML syntax error")
  end;

% When I want to read a sub-file I need to interact with the character
% reading and error reporting mechanisms.

symbolic procedure smlReadFile name;
  begin
    scalar fullname, i;
    fullname := concat("sml/", concat(name, ".sml"));
    i := open(fullname, 'input);
    if null i then smlError("File %s could not be accessed", fullname);
    smlFileStack := (smlFile . smlLine . rds i) . smlFileStack;
    smlFile := fullname;
    smlLine := 1;
    if not zerop posn() then terpri();
    princ "+++ Reading from file ";
    printc fullname
  end;

% Here I try to list all the symbols that SML-97 reserves and that as such
% may not be used as regular identifiers. There is special treatment for
% "=" which both has special syntactic meaning and can be used as an infix
% equality operator. Note that in general being the name of an infix
% operator does not make something reserved in ML.

flag('(
    abstype and andalso as case datatype do else end exception fn
    fun handle if in infix infixr let local nonfix of op open orelse
    raise rec then type val with withtype while !( !) ![ !] !{ !}
    !, !: !; !.!.!. !_ !| != !=!> !-!> !#), 'smlKeyword);

% A test for a simple non-reserved identifier.

symbolic procedure smlId u;
  idp u and not flagp(u, 'smlKeyword) and not flagp(u, '!:tyvar);

symbolic procedure smlShortId u;
  idp u and not flagp(u, 'smlKeyword) and
    not flagp(u, '!:tyvar) and not flagp(u, 'long);

fluid '(smlSym);

% Read a string allowing for the SML-specific rules for character escapes.

symbolic procedure smlString();
  begin
    scalar r;
    while smlNextChar() neq '!" and
          smlChar neq !$eof!$ do <<
      if smlChar = '!\ then smlChar := smlEscapedChar();
      if smlChar neq 'ignore then r := smlChar . r >>;
    smlNextChar();
    return list2string reverse r
  end;

% This should support the full SML-97 set of character escapes.

symbolic procedure smlEscapedChar();
  begin
    scalar w, r;
    smlNextChar();
    if smlChar = 'a then return int2id 7
    else if smlChar = 'b then return int2id 8
    else if smlChar = 't then return int2id 9
    else if smlChar = 'n then return !$eol!$
    else if smlChar = 'v then return int2id 11
    else if smlChar = 'f then return int2id 12
    else if smlChar = 'r then return int2id 13
    else if smlChar = '!" then return smlChar
    else if smlChar = '!\ then return smlChar
    else if seprp smlChar then <<
      while seprp smlChar do smlNextChar();
      if smlChar neq '!\ then
        smlError "Bad syntax with \<whitespace>\ in string";
      return 'ignore >>
    else if smlChar = 'u then <<
      r := 0;
      for i := 1:4 do <<
        smlNextChar();
        w := get(smlChar, 'hexdigit);
        if not w then smlError "Hex digit needed in \u character escape";
        r := 16*r + w >>;
      return intern list2widestring list r >>
    else if digit smlChar then <<
      r := get(smlChar, 'hexdigit);
      for i := 1:2 do <<
        smlNextChar();
        if not digit smlChar then
          smlError "Digit needed in character escape";
        r := 10*r + get(smlChar, 'hexdigit) >>;
      return intern list2widestring list r >>
    else if smlChar = '!^ then <<
      smlNextChar();
      return intern list2string list land(31, id2int smlChar) >>
    else smlError("Bad character escape sequence \%s", smlChar)
  end;

flag ('(!! !% !& !$ !# !+ !- !* !/ !:
        !< != !> !? !@ !\ !~ !` !^ !|), 'smlOpChar);

symbolic procedure smlNumber();
  begin
    scalar w, x, v, s;
    v := 0;
    if smlChar = '!~ then <<
% The negation mark can start a number provided that what follows it is
% a digit.
      smlNextChar();
      if not digit smlChar then <<
        v := '(!~);
        while flagp(smlChar, 'smlOpChar) do <<
          v := smlChar . v;
          smlNextChar() >>;
        return intern list2string reverse v >>;
      s := t >>;                % Record the sign
    if smlChar = '!0 then <<
      smlNextChar();
      if smlChar = 'w then <<
% There is fun with the input "~0w..." because this is not allowed to be
% a negative word (because there are no such things). But you are allowed to
% write (eg) "~ 0w1" with the "~" as an operator acting on the word value.
        if s then smlError "Word literals may not be signed";
        w := t;                 % Must reduce to a word
        smlNextChar() >>;
      if smlChar = 'x then <<
        x := t;                 % Input will be in hexadecimal
        smlNextChar() >> >>;
    if x then while get(smlChar, 'hexdigit) do <<
      v := 16*v + get(smlChar, 'hexdigit);
      smlNextChar() >>
    else while digit smlChar do <<
      v := 10*v + get(smlChar, 'hexdigit);
      smlNextChar() >>;
    if s then v := -v
% On 32-bit Windows and poly-ML it seems that words are 31-bit values,
% while on 64-bit Linux they appear to be 63-bit ones. But smlnj on the same
% 64-bit Linux uses 31-bit words. I am left uncertain both by the odd number
% of bits and the inconsistent width as to just what is expected. But by
% masking to 31 bits here I am at least in line with some implementations.
    else if w then return list('!:word, land(v, 0x7fffffff));
% If something was explicitly a word or in hexadecimal it can not be
% the start of a floating point value.
    if x or (smlChar neq '!. and smlChar neq '!e and smlChar neq '!E) then
      return v;
    v := reverse explode v;
% See a "." for a decimal point
    if smlChar = '!. then <<
      v := smlChar . v;
      while digit smlNextChar() do v := smlChar . v >>;
% See an "E" or an "e" that introduces an exponent
    if smlChar = '!E or smlChar = '!e then <<
      v := '!E . v;
      smlNextChar();
      if smlChar = '!~ then <<
        v := '!- . v;
        smlNextChar() >>;
      while digit smlChar do <<
        v := smlChar . v;
        smlNextChar() >> >>;
    return compress reverse v
  end;

% Read a token. This will be returned as a symbol, number or string.
% I will add characters to symbols so as to allow the various categories
% to avoid clashing. Observe that some characters can not legally occur
% within an SML identifier: ", (, ), {, }, [, ] as well as things whose
% code is over U+007f. Also no valid identifier can contain a mix of
% alphanumeric and punctuation characters.
%
% For a string, I return a Lisp string.
%
% For an integer I return a Lisp integer.
%
% I think that "words" are supposed to be something like e.g. 32-bit
% unsigned values, and must not be introduced by "~". In Reduce I do not
% do a lot to distinguish limited-range and arbitrary integers, but I will
% return a word here as (!:word int). This is NOT an identifier but flagp and
% get can still be called in it (and they will return nil). I will restrict
% words to just 32 bits.
%
% There are then a range of sorts of names:
%  StrId     occurs in OPEN or when followed with "." in a way that
%            will lead to a long name of some sort.
% In "open" I will leave the name as it is, but otherwise I will lex
% and sequence of identifiers joined by dots as a single symbol. If there
% is a "." at all I will flag the name as 'long. If the final component
% is "*" or "=" I will flag it as 'notype.
% This means that "StrId" sort of goes away as a significant context.
%  Lab       use a symbol or a strictly positive integer.
%  TyCon     within a type expression
%  TyVar     something whose name starts with "'". Flag as '!:tyvar
%  Vid       eveything else!
%
% Character literals:
% These are represented in the input as e.g. #"A". I will return them as
% (!:char n) where n is an integer codepoint. See (!:word n) for comparable
% treatment of another data type.
%
% For SML reserved tokens I return the symbol, flagged 'smlKeyword.

symbolic procedure smlToken();
  begin
    scalar r, w, islong, isop;
    r := smlToken1();
    if r = 'op then <<
      isop := t;
      r := smlToken1();
      if not smlId r then
        smlError("Identifier needed after ""op"" but found ""%s""", r) >>;
% Here I will not permit whitespace before the "." that builds a
% long identifier.
    if smlChar neq '!. or not idp r or
       flagp(r, 'smlKeyword) or flagp(r, '!:tyvar) then return r;
% Now accumulate a long identifier...
    while smlChar = '!. do <<
      islong := t;
      smlNextChar();
      w := smlToken1();
      if not idp w or flagp(r, 'smlKeyword) or flagp(r, '!:tyvar) then
        smlError("Invalid item ""%s"" after "".""", w);
      r := intern list2widestring
        append(wideid2list r, id2int '!. . wideid2list w) >>;
    flag(list r, 'long);
    if flagp(w, 'notype) then flag(list r, 'notype);
% If a (possibly long) identifier is preceeded by the word "op" the symbol
% I will return will have a name such as "op:*" and its '!:op property will
% point back to the simple symbol it came from. The new symbol will be tagged
% as 'long if relevant. What this means is that EVERYWHERE in the parser the
% sequence "op long-identifer" will be recognised just as well as the
% long identifier itself, so where this must be invalid I need to check for
% the '!:op property and object. When buildin a parse tree it may make sense
% to follow the !:op reference too. Note that the extended symbol "op:x" first
% can not clash with any genuine identifier even if x is alphanumeric because
% real identifiers can not mix alpha and punctuation character. And that
% provided I filter out and reject attempts such as "infix op foo" that the
% extended name will never have infix status.
    if isop then <<
      w := intern list2widestring append(
        widestring2list "op:",
        widestring2list r);
      put(w, '!:op, r);
      if islong then flag(list w, 'long);
      r := w >>;
    return r
  end;

% The following line is because the tokens "*" and "=" have to be treated
% as valid identifiers in expressions but they are must not be so treated in
% type expressions (where for instance "*" is used to indicate tuple types).

flag('(!* !=), 'notype);

% The main part of token reading is here...

symbolic procedure smlToken1();
  begin
% Note that SML input is case sensitive.
    scalar r, !*raise, !*lower;
% Discard white-space
    while smlChar neq !$eof!$ and seprp smlChar do smlNextChar();
    if smlChar = !$eof!$ then return !$eof!$;
% A simple name
    if liter smlChar or smlChar = '!_ then <<
      r := list smlChar;
      while liter smlNextChar() or
            digit smlChar or
            smlChar = '!_ or
            smlChar = '!' do r := smlChar . r;
      return intern list2string reverse r >>
% I will handle "'" specially since it introduces type valuables.
    else if smlChar = '!' then return begin
      scalar equality;
      r := '(!');
% I will tend to generosity in my parsing of type variables. After an
% initial "'" I will allow any sequenmce of letters, digits, underscores and
% single-quotes. On SML90 notations like '_a and ''_a meant something
% special but they no longer do. I believe that '9 is probably not
% really valid but flagging it up as an error seems unnecessary here!
% If there are two or more quote marks this will be an equality type.
      while liter smlNextChar() or
            digit smlChar or
            smlChar = '!_ or
            (smlChar = '!' and (equality := t)) do r := smlChar . r;
      r := list('!:typeVar, intern list2string reverse r);
      flag(list r, 'typevar);
      if equality then flag(list r, 'equalitytype);
      return r end
% Numbers - integers, words and real numbers are handled here. Also a symbol
% whose name starts with "~" may be spotted.
    else if digit smlChar or smlChar = '!~ then return smlNumber()
% Strings
    else if smlChar = '!" then return smlString()
% SML identifiers using operator-style sequences of characters
    else <<
      while flagp(smlChar, 'smlOpChar) do <<
        r := smlChar . r;
        smlNextChar() >>;
% Any multi-character sequence starting with "#" here stands as it is.
% only the case of a single isolated "#" followed by a double quote mark
% gets intercepted to denote a character literal.
      if r = '(!#) and smlChar = '!" then % #" for character literal
        return list('!:char, smlString())
      else if r then return intern list2string reverse r;
% Here r was empty which means we did not have any smlOpChar characters,
% so we must have a punctuation character like "(", "," or ";"
      r := smlChar;
      smlNextChar();
% Special treatment to notice the start of a comment.
      if r = '!( and smlChar = '!* then <<
        skipToCommentEnd();
        return smlToken1() >>;
      return r >>
  end;

fluid '(smlLookAhead);
smlLookAhead := '!:nothing;

symbolic procedure smlNextSym();
  begin
    if smlLookAhead neq '!:nothing then <<
      smlSym := smlLookAhead;
      smlLookAhead := '!:nothing >>
    else smlSym := smlToken();
    return smlSym
  end;

% I will support a 1-token lookahead - but note that I treat combinations
% such as "op id" and "id.id.id" as single tokens so this can look more
% characters ahead than one might initially imagine. smlPeekSym returns the
% symbol beyond the current one but does not alter the existing value of
% smlSym.

symbolic procedure smlPeekSym();
  begin
    scalar smlSym; % So it is not hurt by this!
    if smlLookAhead = '!:nothing then smlLookAhead := smlToken();
    return smlLookAhead
  end;

% Find the end of a comment, allowing for nested comments.

symbolic procedure skipToCommentEnd();
  begin
    repeat <<
      repeat <<
        smlNextChar();
        while smlChar = '!( do <<
          smlNextChar();
          if smlChar = '!* then skipToCommentEnd() >> 
        >> until smlChar = '!* or smlChar = !$eof!$;
      repeat smlNextChar() until smlChar neq '!*
      >> until smlChar = '!) or smlChar = !$eof!$;
    smlNextChar()
  end;

% Before I look at syntax I will check my lexical analysis so I
% can believe that it is at least roughly working. Here are a bunch of
% examples. I put a number of extra semicolons at the end because they
% allow me to get back in step almost regardless of how my SML lexer
% behaves.

for i := 1:25 do begin
  scalar r;
  terpri(); princ "Next: [";
  prin i;
  princ "] ";
  r := smlNextSym();
  terpri();
  princ " => "; print r
  end;
Arthur
Arthur.C.Norman
1234
~1234
123.45
123.45e6
123.45e~6
~123.45E~6
+
~
~@~
++-->>
(* simple comment *)
Norman''
(* Nested (* Comments (* three *) deep *) testing *)
sml
"String"
(*) less usual cases for a comment to try to trick (**))) ****)
"string\nwith\nnewline"
"embedded \\ and \" characters"
"continue \
   \string over \
   \several lines"
#"A"
#"several letters" (* probably invalid *)
"Upper case A |\065| tab |\^I| lowercase a |\u0061|"
''a
; ; ; ;


% I think that all that makes lexical analysis complete. Now I will
% set up the precedence for those symbols that have predefined infix
% status. This records exactly the numeric values that SML suggests, and
% by default things will be left associative. Note that long-form identifiers
% may not be used as infix operators.

<<put('!/,   'smlInfix, 7);
  put('!*,   'smlInfix, 7);
  put('div,  'smlInfix, 7);
  put('mod,  'smlInfix, 7);
  put('!+,   'smlInfix, 6);
  put('!-,   'smlInfix, 6);
  put('!~,   'smlInfix, 6);
  put('!:!:, 'smlInfix, 5);
  flag('(!:!:), 'smlRight);
% Here I have an unpleasantness, SML-90 specified explicitly that "::" was
% right associative but "@" was left associative, bot having precedence 5.
% However SML-97 seems to have removed explanations and clarification re "@",
% but would lead to "1::[]@[]" being illegal. But I observe both poly-ML and
% SML-NJ accepting the above and so they must be using a different precedence
% setting for "@". I resolve things here by just making it right associative
% which to my mind is reasonable sensible in simple cases anyway! If somebody
% can point me at the place in the official SML-97 specification that
% clarifies this that would make me happy.
% I can detect that SML-NJ does what I do by presenting a test script
% "infix 5 foo; fun a foo b = []; [] foo [] @ foo;"
% where I then get a warning about mixing left and right associative operators
% of the same precedence, so empirically I may be safe here! Note that the
% above test script also falls foul of the SML-97 value restriction rules
% too!
  put('!@,   'smlInfix, 5);
  flag('(!@),   'smlRight);
% Note horribly well that "=" is a keyword as well as an infix operator
% so the code to detect infix expressions etc will need to pay rather
% special attention to it.
  put('!=,   'smlInfix, 4);
  put('!<!>, 'smlInfix, 4);
  put('!<,   'smlInfix, 4);
  put('!>,   'smlInfix, 4);
  put('!<!=, 'smlInfix, 4);
  put('!>!=, 'smlInfix, 4);
  put('!:!=, 'smlInfix, 3);
  put('o,    'smlInfix, 3);
% I have a fake symbol ":infix" that has a lower precedence than anything
% else that I can use when I start the expression-reading code off. Note that
% no valid SML identifier can have a name that contains a mix of punctuation
% and alphabetic characters so this can not lead to a name-clash.
  put('!:infix,  'smlInfix, -1);
  nil >>;

% The user could introduce new infix operators by adding the 'smlInfix
% property to an identifier... but note that at times this can be
% done in a local manner and so reaching the end of a scope may
% need to trigger removal of infix properties. I will cope with that
% by having a fluid variable bound while parsing a local context that
% contains a list of the identifiers made infix there.

% Now I might worry whether a local infix or nonfix declaration might be
% shadowing a more global one. To allow for that the list will need to
% store the infomation that is to be restores, so it could be for instance
% ( ... ... (!* . (7 . nil)) ... ... )

fluid '(smlLocalInfixes);

smlLocalInfixes := nil;

symbolic procedure smlInfixDecl();
  begin
    scalar p, r;
    p := 0;
    while smlChar neq !$eof!$ and seprp smlChar do smlNextChar();
    if digit smlChar then <<
      p := get(smlChar, 'hexdigit);
      smlNextChar();
      if not seprp smlChar then
        smlError "space expected after digit in infix declaration" >>;
    while smlShortId smlNextSym() and
          not get(smlSym, '!:op) do r := smlSym . r;
    for each x in reverse r do <<
      smlLocalInfixes := (x . (get(x, 'smlInfix) . flagp(x, 'smlRight))) .
                         smlLocalInfixes;
      put(x, 'smlInfix, p);
      remflag(list x, 'smlRight) >>
  end;

symbolic procedure smlInfixrDecl();
  begin
    scalar p, r;
    p := 0;
    while smlChar neq !$eof!$ and seprp smlChar do smlNextChar();
    if digit smlChar then <<
      p := get(smlChar, 'hexdigit);
      smlNextChar();
      if not seprp smlChar then
        smlError "space expected after digit in infixr declaration" >>;
    while smlShortId smlNextSym() and
          not get(smlSym, '!:op) do r := smlSym . r;
    for each x in reverse r do <<
      smlLocalInfixes := (x . (get(x, 'smlInfix) . flagp(x, 'smlRight))) .
                         smlLocalInfixes;
      put(x, 'smlInfix, p);
      flag(list x, 'smlRight) >>
  end;

symbolic procedure smlNonfixDecl();
  begin
    scalar p, r;
    p := 0;
    while smlShortId smlNextSym() and
          not get(smlSym, '!:op) do r := smlSym . r;
    for each x in reverse r do <<
      smlLocalInfixes := (x . (get(x, 'smlInfix) . flagp(x, 'smlRight))) .
                         smlLocalInfixes;
      remprop(x, 'smlInfix);
      remflag(list x, 'smlRight) >>
  end;

symbolic procedure endInfixScope();
  for each x in smlLocalInfixes do
    if cadr x then <<
      remprop(car x, 'smlInfix);
      remflag(car x, 'smlRight) >>
    else <<
      put(car x, 'smlInfix, cadr x);
      if cddr x then flag(list car x, 'smlRight)
      else remflag(list cadr x, 'smlRight) >>;



% Top level parser... Note that I let a ";" terminate a TopLevelDeclaration
% but I delay reading past it until I have processed the input so that I try
% to avoid reading ahead more than I need to. In general while I am processing
% something I expect to have checked characters as far as reading just one
% beyond the ";", and very often that will be a newline. I treat either a
% genuine end of file or the special token endOfFile as terminating input
% (but note that genuine file ends in file I am reading recursively do not
% get passed back to the syntax analysis phase - they are detected in the
% lexer and cause a return to the outer file).

% ML for the Working Programmer only shows individual semicolons between
% top-level items, however it also allows an Object Declaration, Signature
% Declaratiuons and Functor Declarations to be merely arbitrary sequences of
% semicolons. I lift that case up a level in the grammar thereby removing
% ambiguity and making life easier for myself. But also hmmm - the diagrams
% in ML for the Working Programmer demand semicolons after each Top Level
% Declaration and that means that one would be required between a signature
% and a following struct (for instance) but current reality (and extant code)
% is not so fussy... Aha the SML-97 definition makes that semicolon optional,
% but the use of an expression at the top level (and perhaps the presence
% of two or more consecutive semicolons) is an extra that is to do with
% an "interactive toplevel".

symbolic procedure smlProgram();
  begin
    scalar w;
    while smlSkipSemicolons() neq !$eof!$ and smlSym neq 'end!Of!File do <<
      w := smlTopLevelDeclaration();
% The following lines seem to clash with current reality!
%     if smlSym neq '!; then
%       smlError """;"" expected at end of top level form";
      if not zerop posn() then terpri();
      if eqcar(w, '!U) then smlReadFile(cadr w)
      else prettyprint w  >>;
    if not zerop posn() then terpri();
    printc "+++ finished reading a segment of SML code";
    smlSym := '!;;
    return "End of SML code detected"
  end;

% I want a few general helper functions for use while building the parser.

symbolic procedure smlSkipSemicolons();
  begin
    while smlSym = '!; do smlNextSym();
    return smlSym
  end;

% There are a number of syntactic forms where a sequence of the
% form
%     A b A b A b A
% will be expected, as in A (b A)* where the occurence of the literal
% input b triggers continuation. In this macro a is a command to be obeyed
% to parse A and b is a literal value to check for. Note that the
% first argument is in general a form that needs to be evaluated
% multiple times so it is essential that this be a macro not an
% ordinary procedure.

%symbolic smacro procedure sequenceOf(!*parse!*, !*b!*);
%  begin
%    scalar !*r!*;
%    !*r!* := list !*parse!*;
%    while smlSym = !*b!* do <<
%      smlNextSym();
%      !*r!* := !*parse!* . !*r!* >>;
%    return reverse !*r!*
%  end$

symbolic macro procedure sequenceOf u;
  begin
    scalar P, sep, lab, r;
    P := cadr u;       % Evaluate this to parse something
    sep := caddr u;    % Evaluate this to get the separator
    lab := gensym();
    r := gensym();
    return sublis(
      list('P . P, 'sep . sep, 'r . r),
      '(prog (r)
         (setq r (list P))
      lab  (cond ((not (equal smlSym sep)) (return (reverse r))))
         (smlNextSym)
         (setq r (cons P r))
         (go lab)))
  end;
        

% Verify that the current token is as expected, and skip past it.

symbolic procedure smlCheckFor tok;
  if smlSym = tok then smlNextSym()
  else smlError("Expected ""%s"" but found ""%s""", tok, smlSym);


% That is the end of my batch of helper definitions. I now need to
% deal with the syntax of the language...


% A Top Level Declaration can be an expression, and Object Declaration,
% a Signature Declaration or a Functor Declaration. All the cases apart from
% expressions can be identified by virtual of an initial keyword, and so
% I check for that. I mark all the words that get special treatment here
% by giving them smlParseDecl property. Anything not so tagged will be looked
% at by the expression parser, and if that finds a reserved word in a way
% that makes it unhappy it should report the pain.

symbolic procedure smlTopLevelDeclaration();
  begin
    scalar w;
    if idp smlSym and
       (w := get(smlSym, 'smlParseDecl)) then return apply(w, nil)
    else return smlExpression()
  end;

% All the words that I know of that can arise here are now listed.
% I may at the start have placeholder helper functions that just
% display error messages reporting that my parser is incomplete. 

put('structure, 'smlParseDecl, 'smlStructureDecl);
put('local,     'smlParseDecl, 'smlLocalDecl);
put('signature, 'smlParseDecl, 'smlSignatureDecl);
put('val,       'smlParseDecl, 'smlValDecl);
put('fun,       'smlParseDecl, 'smlFunDecl);
put('type,      'smlParseDecl, 'smlTypeDecl);
put('datatype,  'smlParseDecl, 'smlDatatypeDecl);
put('abstype,   'smlParseDecl, 'smlAbstypeDecl);
put('exception, 'smlParseDecl, 'smlExceptionDecl);
put('local,     'smlParseDecl, 'smlLocalDecl);
put('open,      'smlParseDecl, 'smlOpenDecl);
put('infix,     'smlParseDecl, 'smlInfixDecl);
put('infixr,    'smlParseDecl, 'smlInfixrDecl);
put('nonfix,    'smlParseDecl, 'smlNonfixDecl);

symbolic procedure smlStructureDecl();
  begin
    scalar name, sig;
    smlNextSym();
    return '!:structure . sequenceOf(<<
% Here and in many places I am insisting that an identifier is not spelt
% the same way as any SML built-in symbol. So for instance I will
% reject thinge like "structure if : ..." and "a.then.op.ref.+". Anything
% else seems to risk confusion!
      if not smlId smlSym then
        smlError("""%s"" not expected in structure declaration", smlSym);
      name := smlSym;
      smlNextSym();
      if smlSym = '!: then <<
        smlNextSym();
        sig := list('!:regular, sequenceOf(smlSignature(), '!:)) >>
      else if smlSym = '!:!> then <<
        smlNextSym();
        sig := list('!:opaque, sequenceOf(smlSignature(), '!:!>)) >>;
      smlCheckFor '!=;
      list(name, sig, smlStructure()) >>, 'and);
  end;

% Here we have the body of a structure.

symbolic procedure smlStructure();
  begin
    scalar r1, r2;
    if smlSym = 'struct then <<
      smlNextSym();
      r1 := smlObjectDeclaration();
      smlCheckFor 'end;
      return list('!:struct, r1) >>
    else if smlSym = 'let then begin
      scalar smlLocalInfixes;
      smlNextSym();
      r1 := smlObjectDeclaration();
      if smlSym neq 'in then smlError """in"" expected after ""let""";
      r2 := smlStructure();
      smlCheckFor 'end;
      endInfixScope();
      return list('!:letstruct, r1, r2) end;
% If a structure does not start with "struct" or "let" then it will be
% either of the form
%    Compound Ident
% or Ident ( ... )
% and the first of these is of the form "Ident . ..." so I need to read
% an Ident then see if I have "." or "(".
    if not smlId smlSym then
      smlError("Symbol ""%s"" unexpected in structure", smlSym);
    r1 := smlSym;
    smlNextSym();
    if smlSym = '!. then <<
      r1 := list r1;
      while smlSym = '!. do <<
        smlNextSym();
        if not smlId smlSym then
          smlError("Symbol %s unexpected after "".""", smlSym);
        r1 := smlSym . r1;
        smlNextSym() >>;
      return '!:compoundName . reverse r1 >>;
    if smlSym neq '!( then
      smlError("Symbol %s unexpected in structure", smlSym);
% After "Ident (" I can have either a Structure or an Object Declaration" and
% I need to decide which...
    while smlSym = '!; do smlNextSym();
    if idp smlSym and flagp(smlSym, 'smlObjectDeclarationStart) then
      return list('!:objstruct, r1, smlObjectDeclaration())
    else return list('!:structure, r1)
  end;

flag('(structure local val fun type datatype abstype exception local
       open infix infixr nonfix), 'smlObjectDeclarationStart);

symbolic procedure smlObjectDeclaration();
  begin
    scalar r, w;
    if smlSym = 'signature or
       smlSym = 'functor then
      smlError("""%s""illegal in Object Declaration", smlSym);
    while smlSym = '!; do smlNextSym();
    while idp smlSym and flagp(smlSym, 'smlObjectDeclarationStart) do <<
      if idp smlSym and
         (w := get(smlSym, 'smlParseDecl)) then r := apply(w, nil) . r
      else smlError("""%s"" unexpected in Object Declaration", smlSym);
      while smlSym = '!; do smlNextSym() >>;
    return '!:objectdeclaration . reverse r
  end;

symbolic procedure smlLocalDecl();
  smlError "local not implemented yet@@@";

symbolic procedure smlSignatureDecl();
  begin
    scalar r, name;
    repeat <<
      smlNextSym();
      name := smlSym;
      if not smlId name then
        smlError("The item %s is not a name in a signature declaration", name);
      smlNextSym();
      smlCheckFor '!=;
      r := list(name, smlSignature()) . r >>
    until smlSym neq 'and;
    return 'signature . reverse r
  end;

symbolic procedure smlSignature();
  begin
    scalar w;
    if smlSym = 'sig then <<
      smlNextSym();
      w := smlSignatureSpecification();
      smlCheckFor 'end;
      return w >>
    else if not idp smlSym then smlError("Expected name in signature");
    w := smlSym;
    smlNextSym();
    return w
  end;

symbolic procedure smlSignatureSpecification();
  begin
    scalar done, w, w1, w2, r;
    repeat <<
      done := nil;
      if smlSym = 'val then <<
        smlNextSym();
        w := '!:val . sequenceOf(<<
          w1 := smlSym;
          smlNextSym();
          smlCheckFor '!:;
          w2 := smlType();
          list(w1, w2) >>, 'and);
        done := t >>
      else if smlSym = 'type or smlSym = 'eqtype then <<
        w1 := smlSym;
        w := smlTypeDesc();
        if w1 = 'eqtype then w := '!:eqtypedecl . cdr w;
        done := t >>
      else if smlSym = 'datatype then <<
        smlNextSym();
        w := smlDatatypeDecl();
        done := t >>
      else if smlSym = 'exception then <<
        w := smlExceptionDecl();
        done := t >>
      else if smlSym = 'structure then <<
        w := smlStructureDecl();
        done := t >>
      else if smlSym = 'sharing then <<
        smlNextSym();
        smlError "sharing not implemented yet@@@";
        done := t >>
      else if smlSym = 'local then begin
        scalar smlLocalInfixes;
        smlNextSym();
        smlError "local not implemented yet@@@";
        done := t;
        endInfixScope() end
      else if smlSym = 'open then <<
        smlNextSym();
        smlError "open not implemented yet@@@";
        done := t >>
      else if smlSym = 'include then <<
        smlNextSym();
        smlError "include not implemented yet@@@";
        done := t >>
      else if smlSym = '!; then <<
        smlNextSym();
        done := t >>;
      r := w . r
      >> until not done;
    return reverse r
  end;

symbolic procedure smlFunctorDecl();
  smlError "functor not implemented yet@@@";

put('functor, 'smlParser, 'smlFunctorDecl);

symbolic procedure smlValDecl();
  begin
    scalar w, ty;
    smlNextSym();
    ty := smlTyVarSeq();
    w := sequenceOf(                 % definitions connected by "and"
      smlSingleVal(), 'and);
    if null cdr w then return car w
    else return '!:valsequence . ty . w
  end;

symbolic procedure smlSingleVal();
  begin
    scalar r, p;
    if smlSym = 'rec then <<
      r := t;
      smlNextSym() >>;
    p := smlPattern();
    smlCheckFor '!=;
    return list('!:val, p, r, smlExpression())
  end;

symbolic procedure smlTypeDecl();
  begin
    smlNextSym();
    return smlTypeBind()
  end;

symbolic procedure smlTypeBind();
  begin
    scalar w;
    w := sequenceOf(                 % definitions connected by "and"
      smlSingleTypeDecl(), 'and);
    if null cdr w then return car w
    else return '!:typesequence . w
  end;

symbolic procedure smlSingleTypeDecl();
  begin
    scalar r, p, ty;
    ty := smlTyVarSeq();
    if not smlId smlSym or smlSym = '!* then
      smlError("Illegal item ""%s"" in type declaration", smlSym);
    p := smlSym;
    smlNextSym();
    smlCheckFor '!=;
    return list('!:typedef, ty, p, smlType())
  end;

symbolic procedure smlTypeDesc();
  begin
    smlNextSym();
    return smlTypeDesc1()
  end;

symbolic procedure smlTypeDesc1();
  begin
    scalar w;
    w := sequenceOf(                 % definitions connected by "and"
      smlSingleTypeDesc(), 'and);
    if null cdr w then return car w
    else return '!:typesequence . w
  end;

symbolic procedure smlSingleTypeDesc();
  begin
    scalar r, p, ty;
    ty := smlTyVarSeq();
    if not smlId smlSym or smlSym = '!* then
      smlError("Illegal item ""%s"" in type declaration", smlSym);
    p := smlSym;
    smlNextSym();
    return list('!:typedesc, ty, p)
  end;

% After the word "fun" you can have a sequence of partial definitions each
% of the form "heading = expression" connected by "|" or "and". I make it
% clear here that the "|" case nests within "and".

symbolic procedure smlClausalFunction();
  begin
    scalar heading, w;
    w := sequenceOf(<<               % Part-definitions connected by "|"
      heading := smlFunctionHeading();
      if smlSym = '!: then <<
        smlNextSym();
        heading := list('!:typed, heading, smlType()) >>;
      smlCheckFor '!=;
      list('!:fun, heading, smlExpression()) >>, '!|);
    if null cdr w then return car w
    else return ('!:clausalfundef . w)
  end;

symbolic procedure smlTyVarSeq();
  begin
    scalar w, ty;
% Here I parse a TyVarSeq - ie either an optional type variable or a
% comma-separated parenthesis-wrapped list of type variables. The
% parenthesized case needs look ahead because one then needs to distinguish
% between such cases as
%       fun ( 'typevar ...
% and   fun ( atomicpat infixop atomicpat ) = ...
    if idp smlSym and flagp(smlSym, '!:tyvar) then <<
      ty := list smlSym;
      smlNextSym() >>
    else if smlSym = '!( then <<
      w := smlPeekSym();      % Perhaps the only place I look-ahead!
      if idp smlSym and flagp(smlSym, '!:tyvar) then <<
        ty := list smlNextSym(); % The type variable
        while smlSym = '!, do <<
          smlNextSym();
          if idp smlSym and flagp(smlSym, '!:tyvar) then <<
            ty := smlSym . ty;
            smlNextSym() >>
          else smlError("Type variable expected but found ""%s""", smlSym) >>;
        if smlSym neq '!) then
          smlError "Close paren needed after type variable list";
        smlNextSym() >> >>;
    return ty
  end;

symbolic procedure smlFunDecl();
  begin
    scalar w, ty;
    smlNextSym();
    ty := smlTyVarSeq();
    w := sequenceOf(                 % definitions connected by "and"
      smlClausalFunction(), 'and);
    if null cdr w then return car w
    else return '!:funsequence . ty . w
  end;

% The complication with function headings is that you may be defining
% something that is an infix operator, and if you are doing that you may
% (or may not) use parantheses. So the normal case is that what I have
% here is a name followed by a sequence of atomic patterms. But I am
% supposed to support binary infix operators too. Yuk.
%
% OK so what I can have is basically
%    Name   AtomicPattern*
% or AtomicPattern infixop AtomicPattern
% or (AtomicPattern infixop AtomicPattern)
% and an AtomicPattern is an underscore, a compound name, a constant or
% something in "()", "[]" or "{}". A compound name could be a simple
% name, or a compound identifier (names held together with dots) or it
% could be "op" followed by an infix operator. A Name could also use "op".
% These days I make the lexer consolidate the word "op" and any sequence
% of dot-connected identifiers into a single token that represents what may
% be a compound name. That really simplifies matters for me here.

symbolic procedure smlFunctionHeading();
  begin
    scalar r;
    if smlSym = '!( or smlSym = '![ or smlSym = '!{ then <<
% Here I have either
%      fun (a infix b) = ...
% or   fun (a, b) infix c = ...
% or   fun [a, b] infix c = ... 
% but in either case I am defining something that is an infix operator.
      smlError "Infix expression in parens or tuple etc to left of infix after fun"
      >>;
    if not idp smlSym or smlSym = '!_ then <<
% Here I have something that must be like
%    fun _ infix b = ...
%    fun 0 infix b = ... where a wildcard or a pattern is to the left of
% an infix operator that I am defining.
      smlError "Infix expression after fun" >>;
    if not smlShortId smlSym then
      smlError("Illegal name ""%s"" for function", smlSym);
    r := list smlSym;
    smlNextSym();
    if idp smlSym and get(smlSym, 'smlInfixLeft) then
      smlError "Infix definition with fun";
% Now I know I have the "simple" case of a function heading.
    r := smlAtomicPattern() . r;
    while smlSym neq '!= and smlSym neq '!: do
      r := smlAtomicPattern() . r;
    return reverse r  
  end;

% I need to know if a symbol could be the start of an atomic pattern...

symbolic procedure smlStartAtomicPattern u;
  u = '!_ or eqcar(u, '!:char) or
  stringp u or numberp u or u = '!( or
  u = '![ or u = '!{ or (smlId u and not get(u, 'smlInfix));


symbolic procedure smlAtomicPattern();
  begin
    scalar r;
    if smlSym = '!_ or eqcar(smlSym, '!:char) or
       stringp smlSym or numberp smlSym then <<
      smlNextSym();
      return '!_ >>
    else if smlSym = '!( then <<
      smlNextSym();
      if smlSym = '!) then <<
        smlNextSym();
        return '(!:tuple) >>;
      r := sequenceOf(smlPattern(), '!,);
      smlCheckFor '!);
      if r and null cdr r then return car r
      else return '!:tuple . r >>
    else if smlSym = '![ then <<
      smlNextSym();
      if smlSym = '!] then <<
        smlNextSym();
        return '(!:list) >>;
      r := sequenceOf(smlPattern(), '!,);
      smlCheckFor '!];
      return '!:list . r >>
    else if smlSym = '!{ then <<
      smlNextSym();
      if smlSym = '!} then <<
        smlNextSym();
        return '(!:record) >>;
      r := sequenceOf(smlRecordPattern(), '!,);
      smlCheckFor '!};
      return '!:record . r >>
    else if not (r := get(smlSym, '!:op)) then r := smlSym;
    smlNextSym();
    return r;
  end;

% Here I wish to recognize
%     ...
%     label = pattern
%     ident [ : type ] [ as pattern ]
% where a label is an identifier or a sequence of digits.

symbolic procedure smlRecordPattern();
  begin
    scalar r, ty;
    if smlSym = '!.!.!. then <<
      smlNextSym();
      return '!.!.!. >>;
    r := smlSym;
    if idp r and get(r, '!:op) then
      smlError """op"" not expected in record pattern";
% Here I can have a label of a "value identifier" but I can not have
% anything with either dots in it or "op" as a prefix.
    if not (smlShortId r or (fixp r and r >= 0)) then
      smlError("Unexpected item ""%s"" in record pattern", r);
    smlNextSym();
    if smlSym = '!= then <<
      smlNextSym();
      return list('!:label, r, smlPattern()) >>;
    if not idp r then
      smlError("Unexpected item ""%s"" in record pattern", r);
    if smlSym = '!: then <<
      smlNextSym();
      ty := smlTYpe() >>;
    if smlSym = 'as then
      return list('!:as, r, ty, smlPattern())
    else return list('!:ident, r, ty)
  end;

% patterns are to my mind almost as much mess as expressions. The cases
% that have to be handled are:
%   atomic pattern  (starts with _, ident, constant, (, [ or { )
%   compound name followed by atomic pattern
%   pattern infix pattern (precedence has to apply here)
%   pattern : type
%   name [ : type ] as pattern
% where name = 'ident' or 'op infix'. Many of these start with an
% identifier and have to be disambiguated using look-ahead.
% I will put type constraints outside anything else, then use precedence
% as for expressions.

symbolic procedure smlPattern();
  begin
    scalar r;
    r := smlPattern1 '!:infix;
    while smlSym = '!: do <<
      smlNextSym();
      r := list('!:types, r, smlType()) >>;
    return r
  end;

symbolic procedure smlPattern1 preced;    
  begin
    scalar w, op, r;
    r := smlPattern2();
    while smlShortId smlSym and
          (w := get(smlSym, 'smlInfix)) and
          smlShift(preced, smlSym) do <<
      op := smlSym;
      smlNextSym();
      r := list(op, r, smlPattern1 op) >>;
   return r
  end;

% This base case for patterns need to discriminate between
%     AtomicPattern
%     CompoundName AtomicPattern
%     Name [ : Type ] as Pattern
% All of these may start with a symbol.

symbolic procedure smlPattern2();
  begin
    scalar r, ty;
% Get as many easy to resolve cases out of the way as I can!
    if smlSym = '!_ or smlSym = '!( or smlSym = '![ or smlSym = '!{ or
       stringp smlSym or numberp smlSym or eqcar(smlSym, '!:char) then
      return smlAtomicPattern();
% If I ignore the word "op" and the issue of dots making up compound
% identifiers the cases that remain are:
%    ident
%    ident AtomicPattern
%    ident : Type
%    ident as Pattern
%    ident : Type as Pattern
    if not smlId smlSym then
      smlError("Illegal item ""%s"" where pattern expected", smlSym);
    r := smlSym;
    smlNextSym();
    if smlSym = '!: then <<
      smlNextSym();
      ty := smlType();
      if smlSym = 'as then <<
        smlNextSym();
        return list('!:as, list('!:typed, r, ty), smlPattern()) >>
      else return list('!:typed, r, ty) >>
    else if smlSym = 'as then <<
      smlNextSym();
      return list('!:as, r, smlPattern()) >>
    else if smlStartAtomicPattern smlSym and
      not (idp smlSym and get(smlSym, 'smlInfix)) then
      return list('!:constructed_value, r, smlAtomicPattern()) 
    else return r
  end;

symbolic procedure smlDatatypeDecl();
  begin
    scalar r;
    smlNextSym();
    r := '!:datatype . sequenceOf(smlDataType1(), 'and);
    if smlSym = 'withtype then <<
      smlNextSym();
      r := list('!:with, r, smlTypeBind()) >>;
    return r;
  end;

symbolic procedure smlDataType1();
  begin
    scalar ty, name;
    ty := smlTyVarSeq();
    if not smlShortId smlSym then
      smlError(
        "Type constructor needed in datatype statement but found ""%s""",
        smlSym);
    name := smlSym;  % The tycon
    smlNextSym();
    smlCheckFor '!=;
    if smlSym = 'datatype then smlError "datatype foo = bar case not done yet";
    return list('!:datatype1, ty, name, sequenceOf(smlConBind(), '!|))
  end;

symbolic procedure smlConBind();
  begin
    scalar name;
    if not smlShortId smlSym then smlError "Short id needed as constructor";
    name := smlSym;
    smlNextSym();
    if smlSym = 'of then <<
      smlNextSym();
      return list('!:of, name, smlType()) >>
    else return name
  end;

symbolic procedure smlAbstypeDecl();
  smlError "abstype not implemented yet@@@";

symbolic procedure smlExceptionDecl();
  begin
    scalar w;
    smlNextSym();
    return '!:exception . sequenceOf(<<
      if not smlShortId smlSym then
        smlError(
          "Short id expected in exception declaration but found ""%s""",
          smlSym);
      w := smlSym;
      smlNextSym();
      if smlSym = 'of then <<
        smlNextSym();
        w := list('!:types, w, smlType()) >>
      else if smlSym = '!= then <<
        smlNextSym();
        if not smlId symSym then
          smlError("unexpected ""%s"" in exception declaration", smlSym);
        w := list('!=, w, smlSym);
        smlNextSym() >>;
      w >>, 'and);
  end;

symbolic procedure smlLocalDecl();
  smlError "local not implemented yet@@@";

symbolic procedure smlOpenDecl();
  begin
    scalar r;
    smlNextSym();
    while smlId smlSym and not get(smlSym, '!:op) do <<
      r := smlSym . r;
      smlNextSym() >>;
    return '!:open . reverse r
  end;


symbolic procedure smlExpression();
  begin
    scalar r;
    if smlSym = 'fn then <<
      smlNextSym();
      return list('!:fn, smlMatch()) >>
    else if smlSym = 'case then <<
      smlNextSym();
      r := smlExpression();
      smlCheckFor 'of;
      return list('!:case, r, smlMatch()) >>
    else if smlSym = 'while then <<
      smlNextSym();
      r := smlExpression();
      smlCheckFor 'do;
      return list('!:while, r, smlExpression()) >>
    else if smlSym = 'if then <<
      smlNextSym();
      r := smlExpression();
      smlCheckFor 'then;
      r := r . smlExpression();
      smlCheckFor 'else;
      return list('!:if, car r, cdr r, smlExpression()) >>
    else if smlSym = 'raise then <<
      smlNextSym();
      return list('!:raise, smlExpression()) >>;
% The above are all the cases that are introduced by high level special
% keywords. So now I have infix like constructions and below those the
% various "application" and "closed" variants on Expressions.
    r := smlExpression1();
    while smlSym = 'handle do <<
      smlNextSym();
      r := list('!:handle, r, smlMatch()) >>;
    return r
  end;

symbolic procedure smlMatch();
  '!:match . sequenceOf(smlMrule(), '!|);

symbolic procedure smlMrule();
  begin
    scalar p;
    p := smlPattern();
    smlCheckFor '!=!>;
    return list('!:mrule, p, smlExpression())
  end;

% The little sequence of procedures here arrange that "handle", "orelse",
% "andalso" and ":" group properly even though SML does not consider them
% to have infix status, but rather views them as reserved words with
% individual parsing rules.

symbolic procedure smlExpression1();
  begin
    scalar r;
    r := smlExpression2();
    while smlSym = 'orelse do <<
      smlNextSym();
      r := list('!:orelse, r, smlExpression2()) >>;
    return r
  end;

symbolic procedure smlExpression2();
  begin
    scalar r;
    r := smlExpression3();
    while smlSym = 'andalso do <<
      smlNextSym();
      r := list('!:andalso, r, smlExpression3()) >>;
    return r
  end;

symbolic procedure smlExpression3();
  begin
    scalar r;
    r := smlInfixExpression '!:infix;
    while smlSym = '!: do <<
      smlNextSym();
      r := list('!:typed, r, smlType()) >>;
    return r
  end;


% Now for infix expressions. This code implements operator precedence.
% The argument to smlInfixExpression is the existing operator that has
% been seen that any new one has to have its precedence (and associativity)
% judged against.

% smlShift compares the operators a and b to see whether in the context
%    ... X a Y b ...
% the code should shift (ie treat the input as ... X a (Y b ...)) or
% reduce (ie treat it as ... (X a Y) b ...). It can also report an error
% if a and b have the same precedence but they wish to associate in opposite
% directions.

symbolic procedure smlShift(a, b);
  begin
    scalar r, p1, p2;
    p1 := get(a, 'smlInfix);
    p2 := get(b, 'smlInfix);
    if (r := flagp(a, 'smlRight)) neq flagp(b, 'smlRight) and
      p1 = p2 then
      smlError("Adjacent operators ""%s"" and ""%s"" not permitted", a, b);
    return (p2 > p1) or ((p2 = p1) and r)
  end;

symbolic procedure smlInfixExpression preced;
  begin
    scalar w, op, r;
    r := smlAppExpression();
% If something has an 'smlInfix property it can not have been written
% using "op" and it can not be a long identifier (written with embedded
% dots). Note also that "=" is accepted here as an operator not a keyword.
    while (smlShortId smlSym or smlSym = '!=) and
          (w := get(smlSym, 'smlInfix)) and
          smlShift(preced, smlSym) do <<
      op := smlSym;
      smlNextSym();
      r := list(op, r, smlInfixExpression op) >>;
    return r
  end;

% This reads a sequence of balanced expresssions, and these are
% associated to the left to denote function applications. E.g.
%   f x y
%   f (a,b)
% and the like. This needs to know the start-set for AtomicExpression,
% which is taken here to be any reserved words except those explicitly
% tagged as valid. Words like "if" are not valid expression-starters
% here because
%    fun I x = x;
%    I if true then 1 else 2;
% is invalid and needs to be written as
%    I (if true then 1 else 2);

symbolic procedure smlAppExpression();
  begin
    scalar r;
    r := smlAtomicExpression();
    while (smlId smlSym and not get(smlSym, 'smlInfix)) or
          numberp smlSym or
          stringp smlSym or
          (idp smlSym and flagp(smlSym, 'smlExpressionStart)) or
          eqcar(smlSym, '!:char) do
      r := list(r, smlAtomicExpression());
    return r
  end;

% These are the "keywords" that are allowed to start an AtomicExpression
% and all other atomic tokens (ie names, numbers and strings) can too. Also
% of the non-atomic values that can be returned as tokens (!:char xx) [for a
% character literal] can start an AtomicExpression but (!:typeVar nn) can not.

flag('(
   !( ![ !{ !# let
   ), 'smlExpressionStart);

% Read a self-contained part of an expression. The cases that have to be
% handled are:
%   name.name.name              compound name
%   11 or 77.5                  number
%   "Ook"                       string
%   #"?"                        character constant
%   () or ( E , E , E )         paranthesised item or tuple
%   [] or [ E , E , E ]         list
%   {} or { lab = val , ... }   record
%   # label
%   ( E ; E ; E )               sequential evaluation block
%   let D in E ; E ; E end      local block

symbolic procedure smlAtomicExpression();
  begin
    scalar v, w;
    w := smlSym;
    smlNextSym();
    if numberp w or stringp w or eqcar(w, '!:char) then return w
    else if (v := get(w, '!:op)) then return v
    else if w = '!( then <<
      if smlSym = '!) then <<
        smlNextSym();
        return '(!:tuple) >>;
      w := list smlExpression();
      if smlSym = '!, then <<
        v := '!:tuple;
        while smlSym = '!, do <<
          smlNextSym();
          w := smlExpression() . w >> >>
      else if smlSym = '!; then <<
        v := '!:sequential;
        while smlSym = '!; do <<
          smlNextSym();
          w := smlExpression() . w >> >>;
      smlCheckFor '!);
      if null cdr w then return car w
      else return v . reverse w >>
    else if w = '![ then <<
      if smlSym = '!] then <<
        smlNextSym();
        return '(!:list) >>;
      w := list smlExpression();
      if smlSym = '!, then <<
        while smlSym = '!, do <<
          smlNextSym();
          w := smlExpression() . w >> >>;
      smlCheckFor '!];
      return '!:list . reverse w >>
    else if w = '!{ then <<
      if smlSym = '!} then <<
        smlNextSym();
        return '(!:record) >>;
      if smlId smlSym or
         fixp smlSym and smlSym >= 0 then <<
        v := smlSym;
        smlNextSym() >>
      else smlError("Invalid label ""%s""", smlSym);
      smlCheckFor '!=;
      w := list (v . smlExpression());
      if smlSym = '!, then <<
        while smlSym = '!, do <<
          smlNextSym();
          if smlId smlSym or
             fixp smlSym and smlSym >= 0 then <<
            v := smlSym;
            smlNextSym() >>
          else smlError("Invalid label ""%s""", smlSym);
          smlCheckFor '!=;
          w := (v . smlExpression()) . w >> >>;
      smlCheckFor '!};
      return '!:record . reverse w >>
    else if w = '!# then <<
      if smlId smlSym or
         fixp smlSym and smlSym >= 0 then <<
        w := smlSym;
        smlNextSym();
        return list('!:label, w) >>
      else smlError("Invalid label ""%s""", smlSym) >>
    else if w = 'let then begin
      scalar smlLocalInfixes;
      v := smlObjectDeclaration();
      smlCheckFor 'in;
      w := list smlExpression();
      while smlSym = '!; do <<
        smlNextSym();
        w := smlExpression() . w >>;
      smlCheckFor 'end;
      endInfixScope();
      return '!:let . v . reverse w end
    else if flagp(w, '!:tyvar) then
      smlError("type variable ""%s"" found in unexpected place", w)
    else return w
  end;

% A type is represented as one of
%    'a or ''a           type var   
%    name or name.name.name
%    TYPE name                  or name.name.name
%    (TYPE , TYPE, ... ) name   or name.name.name
%    TYPE * TYPE * ... * TYPE
%    TYPE -> TYPE               associates to right
%    { #label : TYPE , ... }
%    ( TYPE )

symbolic procedure smlType();
  begin
    scalar r;
    r := smlType1();
    if smlSym = '!-!> then <<
       smlNextSym();
       return list('!:arrow, r, smlType()) >>
    else return r
  end;

symbolic procedure smlType1();
  begin
    scalar r, r1, r2;
    if smlSym = '!* then smlError "Unexpected ""*""";
    repeat <<
      if smlSym = '!* then smlNextSym();
      if eqcar(smlSym, '!:typeVar) then <<
        r1 := smlSym;
        smlNextSym() >>
      else if smlSym = '!( then <<
        smlNextSym();
        r1 := list smlType();
        while smlSym = '!, do <<
          smlNextSym();
          r1 := smlType() . r1 >>;
        smlCheckFor '!);
        if null cdr r1 then r1 := car r1
        else r1 := '!:seq . reverse r1 >>
      else if smlSym = '!{ then <<
        smlNextSym();
        if smlSym = '!} then <<
          smlNextSym();
          r1 := '(!:record) >>
        else <<
          r1 := '!:record . sequenceOf(smlRecordEntry(), '!,);
          smlCheckFor '!} >> >>;
% Now any type can be followed by a compound identifier.... But
% note that I have a special exclusion for "*" here because otherwise
%   ... : 'a * ...
% would (boo hiss) get treated in a way somewhat analagous to
%   ... : 'a list ...
% with the "*" treated as a qualifier for the type variable.
      while smlId smlSym and smlSym neq '!* do <<
        r2 := smlSym;
        smlNextSym();
        if null r1 then r1 := r2
        else r1 := list('!:qualifiedType, r1, r2) >>;
      r := r1 . r;
    >> until smlSym neq '!*;
    if null cdr r then return car r
    else return '!:tuple . reverse r
  end;

symbolic procedure smlRecordEntry();
  begin
    scalar r1;
    if smlId smlSym or
       fixp smlSym and smlSym >= 0 then <<
      r1 := smlSym;
      smlNextSym() >>
    else smlError("Invalid label ""%s""", smlSym);
    smlCheckFor '!:;
    return list('!:labelled, r1, smlType())
  end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Now I will test things a bit.

%tr smlExpression, smlFunctionHeading, smlClausalFunction, smlFunDecl;
%tr smlPattern, smlPattern1, smlPattern2, smlAtomicPattern;
%tr smlAtomicExpression, smlToken;

smlProgram();
(* I put a succession of test cases here... the first are very basic *)
a;
22;
"string";

(* Infix operators and operator precedence *)
1+2;
2*3;
4*5+6;
7+8*9::[];

(* Function definitions with various levels of complication *)
fun f x = x;
fun f x = x : 'a;
fun f x = x : 'a -> 'a;
fun f x = x : 'a * 'b;
fun f x = x : ''a -> (''a * 'b);
fun f (x) = x;

(* Infix constructor *)
fun sum ( h :: t ) = h + sum t;

endOfFile

% After the above small test I will try to read in at least the start of
% the SML code that performs TeX style mathematical layout...

smlProgram();
(* The operator U will read in one of my source files.
*)
U "General";
U "Powers2";
U "BasicTypes";
U "Distance";
U "Size";
U "FontTypes";
U "LoadFont";
U "FontVector";
U "CharInfo";
U "CharFunctions";
U "Const";
U "FontParams";
U "StyleParams";
U "BoxTypes";
U "BasicBox";
U "NodeDim";
U "NodeListDim";
U "GlueCalculation";
U "HListGlue";
U "BoxPack";
U "MakeVBox";
U "AxisCenter";
U "ChangeStyle";
U "Accent";
U "Radical";
U "BasicChar";
U "MakeChar";
U "MakeLine";
U "MakeAtop";
U "MakeFract";
U "Delimiter";
U "GenFraction";
U "MakeLimOp";
U "MakeScripts";
U "MathTypes";
U "Kind";
U "MathSpace";
U "MathGlue";
U "Spacing";
U "IListTypes";
U "IListDim";
U "ChangeKind";
U "MathPenalty";
U "Boundaries";
U "IListTranslate";
U "MathTranslate";
U "Formula";
U "Out";
U "OutHigh";
U "OutDvi";
U "DviState";
U "DviCmd";
U "SetNode";
U "SetBox";
U "ShipOut";
U "Input";
U "test";

;endOfFile
;;

end;

