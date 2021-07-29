module tok; % Identifier and reserved character reading.

% Author: Anthony C. Hearn.
% Modifications by: Arthur Norman.

% Copyright (c) 2001 Anthony C. Hearn.  All rights reserved.

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

% $Id: $
% Parts of the coding style here look antique and ugly with lots of
% goto statements. The notations for  "for" and "while" loops are not
% used here.
% This is not because we do not care about style, but because in the
% process of bootstrapping Reduce this file is first read by a somewhat
% minimalist cut-down version of the parser that does not support the
% full language syntax.

% Substantial changes in March 2014 to put in support for wide characters
% generally packed in the underlying Lisp string type using utf-8 encoding.

fluid '(!*adjprec !*comment !*defn !*eoldelimp !*lower !*minusliter
        peekchar!* !*quotenewnam !*raise semic!* !*report!_colons
        ifl!* curline!*);

!*report!_colons := t;

% Note *raise is global in the SL Report, but treated as fluid here.

global '(!$eof!$
         !$eol!$
         !*micro!-version
         !*savecomments!*
         comment!*
         crbuf!*
         crbuf1!*
         crchar!*
         cursym!*
         curescaped!*
         eof!*
         nxtsym!*
         outl!*
% Values in ttype!*:
%     0  symbol                   a,b,c,word,!+
%     1  string                   "something"
%     2  number                   1,2, 1.0, 2.0
%     3  operator-like character  +,-,...
%     4  result of quotation      '(something)
         ttype!*
         escaped!*
         !*csl
         !*psl

         named!-character!*);

flag('(adjprec),'switch);

!*quotenewnam := t;

crchar!* := '! ;
peekchar!* := nil;

curline!* := 1;

% The next few are so I have clear names for functions that will
% support strings that have utf-8 sequences packed within them. They
% just rely on Lisp support for strings made up of 8-bit characters.

% I will want to check that Jlisp and VSL also support the things that
% are essential here... mainly allocate-string, string2list, list2string
% and int2id.

% This takes a list of integers (each in the range 0-255) and make a
% string. BEWARE that although PSL can print such strings at present
% if you try passing one to explode or explode2 that can crash the
% system. It should be consided improper to pass a list of integers
% here if they do not represent a valid encoding in utf-8.
%
symbolic procedure bytelist2string u;
  list2string u;
put('bytelist2string, 'inline, '(lambda (u) (list2string u)));

% Given a string (that may contain bytes that are over 127) return a list
% of positive small integers out of the raw byte data.
%
symbolic procedure string2bytelist u;
% I do not want to use explode here in case at some stage I want to
% re-work that to behave in character units not in bytes. So here I
% will do things by hand...
  begin
    scalar r, w;
    w := string2list u;
    while w do <<
       if minusp car w then r := (256+car w) . r
       else r := car w . r;
       w := cdr w >>;
    return reversip r;
  end;

% Make a symbol from the given list of bytes that are each on 0-255
%
symbolic procedure bytelist2id u;
  intern list2string u;
put('bytelist2id, 'inline, '(lambda (u) (intern (list2string u))));

% Make a character (ie a symbol whose name is one character long)
% out of the integer in the range 0-127. Note that this function
% might cope also with arguments in the range 129-255 but PSL specifies
% that if it is given 128 it will return nil.
% In CSL this will also do the same job for the range 128-255.
%
% symbolic procedure int2id u; % built in / defined in csl.red

% Here I will want the strings that I work with to be treated as if
% they are sequences of octets forming an UTF-8 encoded string. I update
% these sequences, and if I do so in a non-atomic manner I can have
% intermediate states that are not valid UTF-8 sequences. That does not
% hurt too much on CSL or PSL where the native string representations are
% as sequences of octets. However for any Lisp that stores strings in a way
% that can only support valud Unicode that is an issue. So I have an
% abstraction here that writes the sequences of octets that make up the
% UTF-8 representation of a single codepoint, and in the simple case I
% just write byte at a time but for Jlisp (in particular) I need to
% ensure that these are treated atomically. So Jlisp has functions
% to write 2, 3 and 4 bytes into a string and the intent is that these are
% used when those bytes form part of a single UTF-8 group. For PSL
% I make writing 2, 3 or 4 bytes into procedures. I had wanted to make
% these inline procedures or smacros but it is too early in the bootstrapping
% for that. But the extra procedure call will only happen if an character
% outside the basic Latin set (U+0000 to U+007f) is being processed, so I
% am not too worried.

symbolic procedure string!-store1(s, n, c);
  string!-store(s, n, c);
put('string!-store1, 'inline, '(lambda (s n c) (string!-store s n c)));

symbolic procedure string!-store2(s, n, c1, c2);
  << string!-store(s, n, c1);
     string!-store(s, n+1, c2) >>;

symbolic procedure string!-store3(s, n, c1, c2, c3);
 << string!-store(s, n, c1);
    string!-store(s, n+1, c2);
    string!-store(s, n+2, c3) >>;

symbolic procedure string!-store4(s, n, c1, c2, c3, c4);
 << string!-store(s, n, c1);
    string!-store(s, n+1, c2);
    string!-store(s, n+2, c3);
    string!-store(s, n+3, c4) >>;

% Take a list of integers (now each in the range 0-0x0010ffff) and
% turn it into a string encoding those using utf-8
%
% It will also support use of identifiers or strings as well as integers,
% and will use the first character (n.b. not octet) as the code concerned.
%

% Look at the GOTOs in this...

symbolic procedure list2widestring u;
  begin
    scalar u1, n, s, len;
    len := 0;
    u1 := u;
 a: if null u1 then go to b;
    n := car u1;
    u1 := cdr u1;
    if idp n then n := car widestring2list symbol!-name n
    else if stringp n and n neq "" then n := car widestring2list n
    else if not fixp n then rederr "Invalid item in arg to list2widestring";
    if n < 0 then error(1, "Negative integer in list2widestring")
% I put the constants in decimal because hex reading may not be
% available yet.
    else if n < 128 then len := len + 1
    else if n < 2048 then len := len + 2
    else if n < 65536 then len := len + 3
    else if n < 1114112 then len := len + 4
    else error(1, "Integer too large in list2widestring");
    go to a;
 b: s := allocate!-string len;
    len := 0;
 c: while u do <<
       n := car u;
       if idp n then n := car widestring2list symbol!-name n
       else if stringp n and n neq "" then n := car widestring2list n;
       u := cdr u;
       if n < 128 then <<
% I use string!-store rather than the more proper name string!-store1 here
% since I believe that string!-store will be the version built into the Lisp
% I am using.
         string!-store(s, len, n);
         len := len + 1 >>
       else if n < 2048 then <<
         string!-store2(s, len, 192 + lshift(n, (iminus 6)),
                                128 + land(n, 63));
         len := len + 2 >>
       else if n < 65536 then <<
         string!-store3(s, len, 224 + lshift(n, (iminus 12)),
                                128 + land(lshift(n, (iminus 6)), 63),
                                128 + land(n, 63));
         len := len + 3 >>
       else <<
         string!-store4(s, len, 240 + lshift(n, (iminus 18)),
                                128 + land(lshift(n, (iminus 12)), 63),
                                128 + land(lshift(n, (iminus 6)), 63),
                                128 + land(n, 63));
         len := len + 4 >> >>;
    return s
  end;

% Ditto but make a symbol;
%
symbolic procedure list2wideid u;
  intern list2widestring u;
put('list2wideid, 'inline, '(lambda (u) (intern (list2widestring u))));

% Ditto but starting with a single integer
%
symbolic procedure int2wideid n;
  if n < 128 then int2id n
  else intern list2widestring list n;

% Given a string that may contain bytes that are over 127 return a list
% of positive integers corresponding to the characters in it if it
% is interpreted as being encoded in utf-8. The behaviour if the bytes
% are not valid utf-8 is to be considered undefined.
%
symbolic procedure moan!-if!-not!-follower n;
  if not (land(n, 192) = 128) then
    error(0, "Bad follow-on in utf-8 string")
  else n;

symbolic procedure moan!-if!-truncated u;
  if null u then error(0, "Truncated data in utf-8 string")
  else moan!-if!-not!-follower car u;

symbolic procedure widestring2list u;
  begin
    scalar w, r, n, c;
% The next line turns the string into a list of bytes. On PSL the
% bytes may be extracted as signed values. With CSL they are all
% positive.
    w := string2list u;
% Now I need to decode any utf-8 specials...
    while w do <<
       n := car w;
       w := cdr w;
% I am going to rely on the fact that bytes from the string that were
% at least 0x80 in value come back looking negative here. Thus any values
% that are positive are simple ASCII.
       if not (land(n, 128) = 0) then <<
         if land(n, 224) = 192 then << % Start of 2 byte code
           c := moan!-if!-truncated w;
           w := cdr w;
           n := lshift(land(n, 31), 6) + land(c, 63) >>
         else if land(n, 240) = 224 then << % Start of 3 byte code
           c := moan!-if!-truncated w;
           w := cdr w;
           n := lshift(land(n, 15), 12) + lshift(land(c, 63), 6);
           c := moan!-if!-truncated w;
           w := cdr w;
           n := n + land(c, 63) >>
         else if land(n, 248) = 240 then << % Start of 4 byte code
           c := moan!-if!-truncated w;
           w := cdr w;
           n := lshift(land(n, 7), 18) + lshift(land(c, 63), 12);
           c := moan!-if!-truncated w;
           w := cdr w;
           n := n + lshift(land(c, 63), 6);
           c := moan!-if!-truncated w;
           w := cdr w;
           n := n + land(c, 63) >>
         else error(0, "Improper byte in utf-8 string") >>;
       r := n . r >>;
    return reversip r;
  end;

% Return a list of bytes corresponding to the representation of the
% name of the symbol u. Each byte will be in the range 0 to 255.
%
symbolic procedure id2bytelist u;
  string2bytelist id2string u;
put('id2bytelist, 'inline, '(lambda (u) (string2bytelist (id2string u))));

% Return a list of integers corresponding to the characters that make
% up the name of the symbol u assuming it is encoded using utf-8.
%
symbolic procedure wideid2list u;
  widestring2list id2string u;
put('wideid2list, 'inline, '(lambda (u) (widestring2list (id2string u))));

% The argument should be an identifier denoting a single character. It
% mey neverthless use multiple bytes. Return the integer code for the
% character.
%
symbolic procedure wideid2int u;
  car wideid2list u;
put('wideid2int, 'inline, '(lambda (u) (car (wideint2list u))));


% Find the number of bytes that would be printed if the argument
% was. The argument ought to be an identifier, string or number
%
symbolic procedure lengthc u;
  if idp u then length string2list id2string u
  else if stringp u then length string2list u
  else length explode2 u;

% Find the number of (wide) characters  that would arise from printing
% the atom. This just ignores bytes that are utf-8 follow-on bytes (ie
% those that are 10xxxxxx in binary).
%
symbolic procedure widelengthc u;
   if idp u then length!-without!-followers string2list id2string u
   else if stringp u then length!-without!-followers string2list u
   else length explode2 u;

symbolic procedure length!-without!-followers l;
  begin
    scalar n;
    n := 0;
    while l do <<
       if not (land(car l, 192) = 128) then n := n + 1;
       l := cdr l >>;
    return n
  end;

%==========================================================================

% The function TOKEN defined below is used for reading identifiers
% and reserved characters (such as parentheses and infix operators).
% It is called by the function SCAN, which translates reserved
% characters into their internal name, and sets up the output of the
% input line.  The following definitions of TOKEN and SCAN are quite
% general, but also inefficient.  The reading process can often be
% speeded up considerably if these functions (especially token) are
% written in terms of the explicit LISP used.

symbolic procedure prin2x u;
   outl!* := u . outl!*;

% This character look-ahead is used when parsing names that
% have colons within them, as in abc:def. In particular it is active when
% input text such as "... abc::? ...". If the character written as "?" there
% is a letter, digit or underscore then it continues the symbol that
% started with "abc". Otherwise the symbol will stop as just "abc" with
% the first ":" left in crchar!* and peekchar!* set to '(!: ?).
% I will not preserve peekchar!* across file-selection (I note that
% curchr!* is not preserved either). This is OK provided that the Reduce
% directive to read in a file (ie 'in "filename";') can not properly end in
% a symbol that has colons at the end of it. And also that the "in" command
% can not end with something that messed with backslashes. This is UGLY and
% delicate but probably OK at present.
%
% Furthermore I will cause this to do special things with "#" so that at
% this very low level a sequence
%          #word;
%    or    #number;
% gets treated as if it was a single character. Numbers must be given in
% hexadecimal, and the words will be (by and large) following the usage
% in HTML. Thus "#amp;" and "&" will be equivalent. Many forms of usage
% here will describe characters outside the safe 7-bit ASCII range,
% so "#pound;" will be the Sterling pounds sign that is otherwise "#a3"
% and "#Sigma;" will be the same as "#3a3;". This conversion will take
% place everywhere, even within strings. However if the material after
% a "#" is not a recognised word or a valid hexadecimal number (with a
% maximum of 6 digits and a value at most 0x0010ffff) or the ";" is missing
% then the conversion described here will not be made. It looks as if the
% standard HTML 4 entity names are all at most 8 characters long (eg thetasym
% is maximal). Codes in the range #00; to #ff; may be useful even in the
% short term. Some others are looking forward to a Unicode world. In
% particular the character items created will be made using int2id passing
% arguments in the range 0 to 0x0010ffff not just 0 to 0xff.
%
% Note that an extension to try to use HTML5 entity names would lead to
% ambiguity with #ac;, #ace; and several others. To cope with that the
% symbolic name will take priority over a numeric interpretation, but
% a form #Xddd; or #Uddd; can be available where X introduces hex digits and
% U a decimal version. At present at least there are no name conflicts that
% arise if those versions are used!
%
% I will note (although it is not dealt with here) that later on in
% token I will make "#if", "#else", "#elif", "#endif", "#eval" and
% "#define" special cases of tokens that can be written without needing
% the initial "#" to be escaped. Thus I want the words involved there
% to be disjoint from the ones I use for character entities.
%
% To back this up it will be good if the Lisp system lets prin2 just print
% items (in UTF8 encoding), but print will need altering. Given a symbol
% or a string that contains a non-ASCII character it should display it
% using "#NNN;" (and if it is a symbol that will be preceeded by an
% exclamation mark escape). If the name or string contains a "#" character
% that should be rendered as "#23;" so that e.g. the string that displays
% using prin2 as #amp; will come out via prin1 as "#23;amp;". Note that the
% translation of funny characters is only done once, also that HTML does not
% provide a special name for the character "#". Perhaps I ought to then the
% output could become "#hash;amp;" which may be clearer.
%
% I might note that #apos; is ('), #quot; is ("), #grave is (`),
% #dollar; is ($).  #Tab; and #NewLine ; provide layout. There are
% a couple of very special bits of treatment in these areas implemented
% because I believe that they will help.
% Within a string #quot; expands to a (") but it does not terminate the
% string. Thus a string with an embedded quote mark can be written
% as "This string has an embedded #quot; in it". For now the previous
% notation where the (") needs to be doubled is still available.
% In a similar sort of way the end-of-line denoted by #NewLine ; does not
% terminate a "%" comment, and the dollar that results from #dollar;
% does not end one that is introduced with the word "comment". These
% three cases are handled by having a flag "named!-character!*" that
% can identify when a character has arisen as an expansion of a sequence
% starting with "#". This flag must be cleared before a call to readch1
% if it is to be tested afterwards.
%
% The idiom (string!-length id2string x = 1) tests if x is a symbol whose
% internal representation is just one byte long. This can identify things
% in the range 0 to 127 that may safely be be tested using liter, digit etc.
% In the code here I try to protect calls to liter, digit etc and as
% a result all characters whose code exceeds 127 will be neither letters
% not digits nor whitespace.

% Check GOTO here


symbolic procedure readch1;
  begin
    scalar x, y, w, n, save;
% First cope with anything that had been read ahead...
    if peekchar!* then <<
      x := car peekchar!*;
% In general when I peek ahead I will not do case-folding as I go:
% that has to be done now when I retrieve the character for final use.
% The PSL rule is that if !*raise is set then characters are all converted
% to the standard case (ie lower case). CSL has two variables !*raise and
% !*lower and folds case as directed by them.
      peekchar!* := cdr peekchar!*;
% I had at first tried "memq('psl, lispsystem!*)" here to detect PSL but that
% fails for two reasons in bootstrapping. First MEMQ may only be used as an
% infix, secondly lispsystem!* is not set early enough. So I have a new
% variable !*psl that I use to detect the relevant situation!
      <<
        if x eq !$eof!$ then nil % Do not mess with EOF
        else if !*psl then << if !*raise then x := red!-char!-downcase x >>
        else if !*lower then x := char!-downcase x
        else if !*raise then x := char!-upcase x >>;
      return x >>;
% Now it is necessary to do a "real" read.
a:  if null terminalp() then <<
% In a fully Unicode world readch() might return a symbol whose name
% is several bytes long but that represents a single Unicode character.
% Doing things that way risks repeatedly packing and unpacking utf-8
% and Unicode data but may feel most consistent.
      x := readch();
      if x eq !$eol!$ then curline!* := curline!*+1 >>
% crbuf1!* is a close relative of peekchar!* but is mainly used as
% an interface for "cedit" to use so that it can have an edited
% bit of stuff appear visible as if it was keyboard input.
    else if crbuf1!* then <<
      x := car crbuf1!*;
      crbuf1!* := cdr crbuf1!* >>
    else x := readch();
    crbuf!* := x . crbuf!*;
% One might worry that adding support for "#" escapes has made this code
% a lot longer than before and that this might slow critical things down.
% In fact about the only extra work done here in normal circumstances is
% a fairly cheap test to see if "#" is present.
    if null peekchar!* then <<
      if not (x = '!#) then return x;
      save := (!*raise . !*lower);
% I switch off !*raise and !*lower while reading. That is (for instance)
% so that #Sigma; and #sigma; can yield an upper and a lower case
% Greek sigma character.
      !*raise := (!*lower := nil);
      peekchar!* := x . peekchar!*;
      go to a >>
% Here I am accumulating a bit of stuff where I look ahead following
% a "#" character.
    else if (not (x eq !$eof!$)) and
       (string!-length id2string x = 1) and
       (liter x or digit x) then <<
% I accumulate the initial "#" followed by any number of letters and
% digits. Well I will only consider letters with codes in the range
% U+0000 to u+007f here and that keeps things simpler - eg when it comes
% to case folding things later on.
      peekchar!* := x . peekchar!*;
      go to a >>;
    !*raise := car save;
    !*lower := cdr save;
% If what I find at the end is not a semicolon then I will
% do nothing... ie I will leave the peeked characters to be read one
% by one in the usual way. Note that while the very final peeked character
% could be a second "#" none of the others can be.
    if not (x = '!;) or null cdr peekchar!* then <<
      peekchar!* := cdr reversip (x . peekchar!*);
      return '!# >>;
% Now I have a potential character name object. It could be one of
%        #name;
%        #hexdigits;
%        #Xhexdigits;     (upper or lower case "x")
% (also  #0hexdigits;     will have the same effect)
%        #Udecimaldigits; (upper or lower case "u")
% but if the name is not recognised or the numeric value is out of
% range the sequence will just be treated as raw characters and all
% this special treatment will have been merely a diversion.
    y := intern list2string (x := cdr reverse peekchar!*);
% For bootstrapping there has to be a "!" before the "_" on the next line.
    if (y := get(y, 'unicode!_character)) then <<
       peekchar!* := nil;
       named!-character!* := t;
       return int2wideid y >>;
% Now it was not a known name. Next check if it was #Udddd
    n := 0;
% I uprated the very initial bootstrap version of the parser so that
% letters after "!" were not case folded.
    if eqcar(x, '!u) or eqcar(x, '!U) then go to dec1;
% Check for explicit hex marker, as in #Xdddd
    if eqcar(x, '!x) or eqcar(x, '!X) then x := cdr x;
hex:if null x then go to ok;
    w := get(car x, 'hexdigit);
    if null w then go to fail;
    n := 16*n + w;
    x := cdr x;
    go to hex;
dec1:
    x := cdr x;
dec:if null x then go to ok;
    if null digit car x then go to fail;
    n := 10*n + get(car x, 'hexdigit);
    x := cdr x;
    go to dec;
ok: peekchar!* := nil;
    named!-character!* := t;
    return int2wideid n;
fail:
    peekchar!* := cdr reverse ('!; . peekchar!*);
    return '!#
  end;

symbolic procedure tokquote;
   begin
      crchar!* := readch1();
      nxtsym!* := mkquote rread();
      curescaped!* := nil;
      ttype!* := 4;
      return nxtsym!*
   end;

put('!','tokprop,'tokquote);

% Check GOTO here

if !*csl then <<
% I will accept input such as 1.23S0. I preserve the fact that it named
% a short float by using ":dn!-s!:" to tag it rather than just ":dn:", but
% then in algebraic mode form() will map that back onto just !:dn!: so that
% the short nature of the float is only used in symbolic mode.
  put('!s, 'exponent!-mark, '!:dn!-s!:);
  put('!S, 'exponent!-mark, '!:dn!-s!:);
  put('!f, 'exponent!-mark, '!:dn!-f!:);
  put('!F, 'exponent!-mark, '!:dn!-f!:);
  put('!e, 'exponent!-mark, '!:dn!:);
  put('!E, 'exponent!-mark, '!:dn!:);
  put('!d, 'exponent!-mark, '!:dn!:);
  put('!D, 'exponent!-mark, '!:dn!:);
  put('!l, 'exponent!-mark, '!:dn!-l!:);
  put('!L, 'exponent!-mark, '!:dn!-l!:) >>
else <<
  put('!e, 'exponent!-mark, '!:dn!:);
  put('!E, 'exponent!-mark, '!:dn!:) >>;

symbolic procedure token!-number x;
   % Read and return a valid number from input.
   % Adjusted by A.C. Norman to be less sensitive to input case and to
   % support hex numbers.
   begin scalar dotp,power,sign,y,z,xmark;
      power := 0;
      ttype!* := 2;
    num1:
      if y or null(x = '!)) then y := x . y;
      if dotp then power := power - 1;
    num2:
      x := readch1();
      if (x eq !$eof!$) or
         (not (string!-length id2string x = 1)) then go to ret
% The code here used to generate a diagnostic on input like "1.2.3" but
% now it should accept 1.2 as a number and just stop reading at the second
% dot. That seems more friendly and generally consistent with what lexical
% processing should do.
       else if x = '!. and not dotp then <<
         dotp := t;
         go to num2 >>
       else if digit x then go to num1
       else if y = '(!0) and (x = '!x or x = '!X) then go to hexnum
% The next line is a HACK so that 0zNNNNN will let ACN read in a potentially
% big integer explicitly using an experimental version of the CSL bignum
% arithmetic. The syntax will only be available if a function called "newplus"
% is defined, which I take to be a signature of the testing code. When (and
% I should probably say "if") CSL has fully adopted its new code I can get
% rid of this!
       else if y = '(!0) and
               (x = '!z or x = '!Z) and
               getd 'newplus then go to znum
% For whatever original reason this ignores backslashes within numbers. This
% I guess lets one write 12\34567\89000 and group digits in fives if you like.
% I can not see this mentioned in the manual and wonder if anybody uses it.
       else if x = '!\ then << readch1(); go to num2 >>
       else if null(xmark := get(x, 'exponent!-mark)) then go to ret;
% I want to let exponent markers S, F, E, D and L be available for
% writing floating point literals with some specified width. However there
% is a problem of backwards compatibility. Old-style Reduce lets a number end
% when there is a character other than "E". And it does not require spaces
% between tokens. A concrete example of how this hurts is that there are
% places that read "... 2sqrt x ..." where I might have liked it better if
% the code read "2*sqrt x" or at a minimum "2 sqrt x" with a space. But I
% should not break TOO much existing code. So I will allow letters other than
% "e" to instroduce exponents only when there has been an explicit "." before.
% That means that the input "... 2.0sqrt x ..." will now parse with a short
% float 2.0s0 and then "qrt x" and that is a change. But that case "2sqrt x"
% will behave the way it used to. Similarly for cases with other letters at the
% end of of numbers.
%
% To show part of why I believe that the status quo was wrong, note the
% different behaviour of
%    2sqrt x;       (times 2 (list 'sqrt 'x))
%    2exp x;        (times '(!:rd!: 2 . 0) (list 'xp 'x))
% !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
% I rather view that as broken behaviour.
      if not dotp and (x neq '!e and x neq '!E) then go to ret;
      % Case of number with embedded or trailing E.
      dotp := t;
      if (x := readch1()) = '!- then sign := t
       else if x = '!+ then nil
       else if (x eq !$eof!$) or
               (null (string!-length id2string x = 1)) then go to ret
       else if null digit x then go to ret
       else z := list x;
   nume1:
% Even though characters are now extended I want the digit test to pick out
% just those decimal digits that can be handled by compress. So characters
% such as U+1D7E6 (mathematical sans serif digit four) probably does not want
% to pass the test...
      x := readch1();
      if null (string!-length id2string x = 1) then go to nume2
       else if null digit x then go to nume2;
      z := x . z;
      go to nume1;
   hexnum:
      y := 0;
   hexnum1:
      if not (z := get(x := readch1(), 'hexdigit)) then go to ret1;
      y := 16*y + z;
      go to hexnum1;
   znum:
      y := 0;
   znum1:
      if not digit (x := readch1()) then go to ret1;
% This uses functions newplus and newtimes that are only available in
% non-standard testing builds of the CSL version...
      y := newplus(newtimes(10, y), get(x, 'hexdigit));
      go to znum1;
   nume2:
      if null z then rerror('rlisp,4,
         concat("Syntax error: improper number ",
                list2string (x . append(z, 'e . y))));
% This use of compress is for a number...
      z := compress reversip!* z;
      if sign then power := power - z else power := power + z;
   ret:
% This use of compress is for a number...
      y := compress reversip!* y;
   ret1:
      nxtsym!* := if dotp then (if null xmark then '!:dn!: else xmark) .
                               (y . power)
                   else if !*adjprec then '!:int!: . (y . nil)
                   else y;
      crchar!* := x;
      return nxtsym!*
   end;

% Note that the arrangements here only support numbers written using
% characters from the Basic Latin Block (U+0000 to U+007f).
deflist(
 '((!0 0)  (!1 1)  (!2 2)  (!3 3)  (!4 4)
   (!5 5)  (!6 6)  (!7 7)  (!8 8)  (!9 9)
   (!a 10) (!b 11) (!c 12) (!d 13) (!e 14) (!f 15)
   (!A 10) (!B 11) (!C 12) (!D 13) (!E 14) (!F 15)), 'hexdigit);

% The special marker !_line!_ will be replaced in the input stream of
% tokens by the current line number. Note that if terminalp() returns
% true that input lines are not counted - ie if !*int is on (to signal
% interactive use) and input is direct from whatever is standard when
% reduce starts then !_line!_ will always expand to 1. Go "off int;" or
% put your material in a file that you read using "in" if this matters
% to you. Similarly, the special marker !_file!_ will be replaced by the
% name of the file currently read in, or the string "Terminal" if not
% reading from a file.

fluid '(!*line!-marker !*file!-marker);
% Note I can NOT just go "!*line!-marker := '__line__;" here since that
% would end up mapped to the line number in this file rather than the
% desired literal symbol - hence the use of intern on a string!
!*line!-marker := intern "__line__";
!*file!-marker := intern "__file__";

% This is a big ugly procedure with a lot of GOTO statements. It is overdue
% for re-work.

symbolic procedure token;
%
% The current syntax for an identifier is that it starts with a letter (or
% an escaped character) and can continue with letters, digits or underscores.
% I wish to support identifiers that contain an internal unescaped "::"
% (but just one such).
% When I started considering this I had wondered about also allowing
% an embedded single ":" too. However it became clear that that would cause
% trouble in common occuring cases such in
%         label:x:=y;
% and     for i:=m:n dp ...
%
% I believe that little existing code will be troubled if double colons are
% treated specially. The only use of them that I can see in the current source
% is where gentran enables :: to indicate a range in a declaration. If both
% ends of the range have alpabetic names then extra whitespace would be
% required.
%
% When (and if) this is ever activated the case of a single colon
% will merely be treated as it used to be (so avoiding incompatibility),
% while perhaps the usage
%   package::name
% can be used for something interesting. But initially package::name will
% merely denote a name that has embedded colons.
%
% I suspect that the flag "!*minusliter" (which I hope is not made a flag
% that can be toggled using on/off, since it is a dodgy thing for ordinary
% users to mess with) causes "-" to be accepted as a "letter" within but
% not at the start of a name. Thus "-a-b+c" ends up parsing as
%      (plus (minus a!-b) c)
%
   begin scalar x,y,z;
        x := crchar!*;
    a:  if (x eq !$eof!$) or
           (not (string!-length id2string x = 1)) then go to unicode;
        if seprp x and null(x eq !$eol!$ and !*eoldelimp)
          then << x := readch1(); go to a >>
         else if digit x then return token!-number x
% Letters in the Basic Latin Block can be used without needing an escape
% character. The status of things such as U+00c1 (latin capital A with acute)
% and all the other supplemental characters (to say nothing of Greek letters)
% will be a matter for the underlying Lisp to worry about.
         else if liter x then go to letter
         else if (y := get(x,'tokprop)) then return lispapply(y,nil)
         else if x = '!% and null !*savecomments!* then go to coment
         else if x = '!! and null(!*micro!-version and null !*defn)
          then go to escape
         else if x = '!" then go to string
         else if x = '!\ then go to backslash;
    unicode:
        ttype!* := 3;
        if x eq !$eof!$ then prog2(crchar!* := '! ,filenderr());
        nxtsym!* := x;
        if not (x eq !$eof!$) then <<
           if (string!-length id2string x = 1) and (delcp x) then
             crchar!*:= '!  else crchar!*:= readch1() >>;
        if null(x = '!- and
                (not (crchar!* eq !$eof!$)) and
                (string!-length id2string crchar!*  = 1) and
                digit crchar!* and
                !*minusliter)
          then go to c;
        x := token!-number crchar!*;
        if numberp x then return apply1('minus,x);  % For bootstrapping.
        rplaca(cdr x,apply1('minus,cadr x));        % Also for booting.
        return x;
    escape:
        begin scalar !*raise,!*lower;
           escaped!* := t;
           x := readch1();
% If a token is read such that a letter is preceeded by an exclamation mark
% I will set the variable escaped!*. The purpose of this is to support a
% tool that will report on cases where names are used in Reduce such that they
% are identical other than in case. So if both "symbolic" and "sYmBoLiC" are
% used that is a clash. However I do not want "!Alpha" and "alpha" to count
% as a clash, or "!X" and "!x" and "x". So the presence of a letter whose
% case is explicitly preserved by the escape character will be taken as a mark
% that the word was meant to be just as written. This can leave bad cases
% such as "!Alpha" vs "!AlphA" but it covers enough to be useful for now.
% I do not set escaped!* to nil here - if you wish to inspect it please set
% it to nil before calling token(). The arrangement like that is perhaps
% ugly but minimises overhead in all the common cases where this is not
% actually being used.
           if liter x then escaped!* := t;
        end;
    letter:
        ttype!* := 0;
    let1:
        x := wideid2list x;
    let2:
        if null x then go to let3;
        y := car x . y;
        x := cdr x;
        go to let2;
    let3:
        x := readch1();
        if (x eq !$eof!$) or
            (not (string!-length id2string crchar!*  = 1)) then go to ordinarysym
         else if digit x or liter x then go to let1
         else if x = '!! then go to escape
         else if x = '!- and !*minusliter
          then go to let1
         else if x = '!_ then go to let1     % Allow _ as letter.
%% The following change led to problems with CSL, and perhaps it is not
%% even needed.
%%         else if x = '!% then go to let1     % Allow % as letter.
         else if x = '!: then go to maybepackage;
    ordinarysym:
        y := list2wideid reversip!* y;
% If I implement a package system I might want to check if the name
% y here should map onto ppp:y for some package ppp.
        if y = !*line!-marker then nxtsym!* := curline!*
        else if y = !*file!-marker
          then nxtsym!* := if null ifl!* then "Terminal" else car ifl!*
        else nxtsym!* := y;
        crchar!* := x;
    c:  return nxtsym!*;
    backslash:
        y := '(!\ e n d !{ r e d u c e !});
        z := nil;
    bsloop:
        z := x . z;
        x := readch1();
        y := cdr y;
        if null y then go to bsfound
        else if x eq car y then go to bsloop;
% Here I need to set things back so that all the peeked-ahead stuff is
% put ready for re-scanning and I can merely return the "\".
        peekchar!* := cdr reverse (x . z);
        ttype!* := 3;
        crchar!* := readch1();
        nxtsym!* := '!\;
        return nxtsym!*;
    bsfound:
% At this stage I have just found the text "\end{reduce}" and what I will do
% is to discard all stuff until I find either end of file of "\begin{reduce}".
% However note that at this stage I am expecting to be scanning TeX code and
% so if there are any TeX comments (introduced by "%") I do not want to
% detect the magic within them.
        y := '(!\ b e g i n !{ r e d u c e !});
        ttype!* := 3;
    bssrch:
        if x = '!% then go to bscomm
        else if x eq !$eof!$ then <<
           crchar!* := '! ;
           filenderr();
           nxtsym!* := x;
           return x >>;
% If I have found \begin{reduce} go back to scanning input normally.
        if null y then go to a;
        z := x;
        x := readch1();
        if not (z eq car y) then go to bsfound;
        y := cdr y;
        go to bssrch;
    bscomm:
        x := readch1();
        if x eq !$eof!$ then go to bssrch
        else if x eq !$eol!$ then go to bsfound
        else go to bscomm;
    maybepackage:                               % Seen abc:
        x := readch1();
        if x = '!: then go to maybeextpackage;
        peekchar!* := list x;
        x := '!:;
        go to ordinarysym;
    maybeextpackage:                            % Seen abc::
        x := readch1();
        if (not (x eq !$eof!$)) and
           (string!-length id2string crchar!*  = 1) and
           liter x then go to isextpackage;
        peekchar!* := list('!:, x);
        x := '!:;
        go to ordinarysym;
    isextpackage:
% What follows lexes a name of the form ppp::xxx
        z := list2wideid reverse y;
% In case it is useful I set z to the name of the "package" part ppp
        y := (id2int '!:) . (id2int '!:) .  y;
    extpackmore:
        x := wideid2list x;
    ext1:
        if null x then go to ext2;
        y := car x . y;
        x := cdr x;
        go to ext1;
    ext2:
        x := readch1();
        if (x eq !$eof!$) or
           (not (string!-length id2string crchar!*  = 1)) then go to extdone
         else if digit x or liter x then go to extpackmore
         else if x = '!! then go to extpackescape
         else if x = '!- and !*minusliter
          then go to extpackmore
         else if x = '!_ then go to extpackmore;    % Allow _ as letter.
    extdone:
        y := list2wideid reversip!* y;
% At this stage I will always display a message reporting what I have seen.
        lprim list("Name with double colon in detected:", y);
        nxtsym!* := y;
        crchar!* := x;
% This is where I merely return the symbol with an embedded "::". If I
% ever implement a genuine package system this should be where I put a
% major hook that manages extra symbol tables.
        return nxtsym!*;
    extpackescape:
        begin scalar !*raise,!*lower;
           escaped!* := t;
           x := readch1()
        end;
        go to extpackmore;
    string:
        begin scalar !*raise,!*lower;
       strinx:
           x := wideid2list x; % extract character from the symbol.
       dumpx:
           if null x then go to dumped;
           y := car x . y;
           x := cdr x;
           go to dumpx;
       dumped:
           named!-character!* := nil;
           if (x := readch1()) eq !$eof!$
             then << crchar!* := '! ;
                     lpriw("***** End-of-file in string",nil);
                     filenderr() >>
            else if (null(x = '!")) or named!-character!* then go to strinx;
           % Now check for embedded string character.
           named!-character!* := nil;
           x := readch1();
           if (x = '!") and (null named!-character!*) then go to strinx;
           nxtsym!* := list2widestring cdr reversip!* y
         end;
        ttype!* := 1;
        crchar!* := x;
        go to c;
    coment:
        begin scalar !*raise,!*lower;
    comm1:
        named!-character!* := nil;
        if (null((x := readch1()) eq !$eol!$ or
                  x eq !$eof!$)) or named!-character!* then go to comm1
        end;
        x := readch1();
        go to a
   end;

symbolic procedure tokbquote;
   begin
     crchar!* := readch1();
      nxtsym!* := list('backquote,rread());
      curescaped!* := nil;
      ttype!* := 3;
      return nxtsym!*
   end;

put('!`,'tokprop,'tokbquote);

symbolic procedure filenderr;
   begin
      curescaped!* := nil;
      cursym!* := '!*semicol!*;
      eof!* := eof!*+1;
      if terminalp() then error1()
       else error(99,if ifl!*
                       then list("End-of-file read in file",car ifl!*)
                      else "End-of-file read")
   end;

symbolic procedure ptoken;
   begin scalar x;
        x := token();
        if x = '!) and eqcar(outl!*,'! ) then outl!*:= cdr outl!*;
           %an explicit reference to OUTL!* used here;
        prin2x x;
        if null ((x = '!() or (x = '!))) then prin2x '! ;
        return x
   end;

symbolic procedure rread1;
   % Modified to use QUOTENEWNAM's for ids.
   % Note that handling of reals uses symbolic mode, regardless of
   % actual mode.
   begin scalar x,y;
        x := ptoken();
        if null (ttype!*=3)
          then return if idp x
                        then if !*quotenewnam
                                and (y := get(x,'quotenewnam))
                               then y
                              else x
                       else if eqcar(x,'!:dn!:)
                        then dnform(x,nil,'symbolic)
                       else x
         else if x = '!( then return rrdls()
         else if null (x = '!+ or x = '!-) then return x;
        y := ptoken();
        if eqcar(y,'!:dn!:) then y := dnform(y,nil,'symbolic);
        if null numberp y
          then << nxtsym!* := " ";
                  symerr("Syntax error: improper number",nil) >>
         else if x = '!- then y := apply1('minus,y);
           % We need this construct for bootstrapping purposes.
%@@@@@@@@ Check if this is still the case @@@@@@@@@@@
        return y
   end;

symbolic procedure rrdls;
   begin scalar x,y,z;
    a:  x := rread1();
        if null (ttype!*=3) then go to b
         else if x = '!) then return z
         else if null (x = '!.) then go to b;
        x := rread1();
        y := ptoken();
        if null (ttype!*=3) or null (y = '!))
          then << nxtsym!* := " "; symerr("Invalid S-expression",nil) >>
         else return nconc(z,x);
    b: z := nconc(z,list x);
       go to a
   end;

symbolic procedure rread;
   << prin2x " '"; rread1() >>;

symbolic procedure delcp u;
   % Returns true if U is a semicolon, dollar sign, or other delimiter.
   % This definition replaces the one in the BOOT file.
   flagp(u,'delchar);
put('delcp, 'inline, '(lambda (u) (flagp u 'delchar)));

flag('(!; !$),'delchar);

symbolic procedure toknump x;
   numberp x or eqcar(x,'!:dn!:) or eqcar(x,'!:int!:);

% The following version of SCAN provides RLISP with a facility for
% conditional compilation.  The protocol is that text is included or
% excluded at the level of tokens.  Control by use of new reserved
% tokens #if, #else, #elif and #endif.  These are used in the form:
%    #if (some Lisp expression for use as a condition)
%    ... RLISP input ...
%    #else
%    ... alternative RLISP input ...
%    #endif
%
% The form
%    #if C1 ... #elif C2 ... #elif C3 ... #else ... #endif
% is also supported.
%
% This formation will not be recognised within quoted exressions, so
%       a := '(one
%       #if sometimes
%              two
%       #endif
%              three);
% will not be useful. The tokens "#if" etc do not need an initial (!)
% when they might be directives. Again this means that within quoted
% material they will.
%
% Conditional compilation can be nested.  If the Lisp expression used
% to guard a condition causes an error it is taken to be a FALSE
% condition. It is not necessary to have an #else before #endif if no
% alternative text is needed.  Although the examples here put #if etc
% at the start of lines this is not necessary (though it may count as
% good style?).  Since the condition will be read using RLISPs own
% list-reader there could be conditional compilation guarding parts of
% it - the exploitation of that possibility is to be discouraged!

% Making the condition a raw Lisp expression makes sure that parsing it
% is easy. It makes it possible to express arbitrary conditions, but it
% is hoped that most conditions will not be very elaborate - things like
%    #if (member 'psl lispsystem!*)
%         magic();
%    #else
%         error();
%    #endif
% or
%    #if debugging!-mode  % NB if variable is unset that counts as nil
%    print "message";      % so care should be taken to select the most
%    #endif               % useful default sense for such tests
% should be about as complicated as reasonable people need.
%
% Two further facilities are provided:
%    #eval (any lisp expression)
% causes that expression to be evaluated at parse time.  Apart from any
% side-effects in the evaluation the text involved is all ignored. It is
% expected that this will only be needed in rather curious cases, for
% instance to set system-specific options for a compiler.

%    #define symbol value
% where the value should be another symbol, a string or a number,
% causes the first symbol to be mapped onto the second value wherever
% it occurs in subsequent input.  This uses exactly the same mechanism
% as the existing REDUCE "define" statement and so has the same
% limitations.  The use of a hook in SCAN to support this ensures that
% the #define can be written anywhere in REDUCE source code (eg within
% a procedure definition) and will still apply while the program
% involved is parsed.  No special facility for undoing the effect of a
% #define is provided, but the general-purpose #eval could be used to
% remove the 'newnam property that is involved.

symbolic procedure addcomment u;
 %  if commentlist!*
 %    then cursym!* := 'comment . aconc(reversip commentlist!*,u)
 %   else
     cursym!* := u;
put('addcomment, 'inline, '(lambda (u) (setq cursym!* u)));

symbolic procedure scan;
   begin scalar bool,x,y;
        if null (cursym!* = '!*semicol!*) then go to b;
    a:  escaped!* := nil;
        nxtsym!* := token();
    b:  if null atom nxtsym!* and null toknump nxtsym!*
          then go to q1
         else if nxtsym!* = 'else or cursym!* = '!*semicol!*
         then outl!* := nil;
        prin2x nxtsym!*;
    c:  if null idp nxtsym!* then go to l
         else if (x:=get(nxtsym!*,'newnam)) and
                        (null (x=nxtsym!*)) then go to new
% Here I will allow "comment" to be spent in either upper or lower case
% so that if "off raise;" (or "off lower;") is active things that may be
% intended to be comments remain treated as such. The various capitalisations
% detected here actually arise within the Reduce sources (at least until at
% some stage they are tidied away...)
         else if nxtsym!* = '!c!o!m!m!e!n!t or
                 nxtsym!* = '!C!O!M!M!E!N!T or
                 nxtsym!* = '!C!o!m!m!e!n!t
          then << x := read!-comment1 'comment;
                  if !*comment then return x else go to a >>
         else if nxtsym!* = '!% and ttype!*=3
          then << x := read!-comment1 'percent!_comment;
                  if !*comment then return x else go to a >>
% I might comment that the material within a quoted form is not
% processed by SCAN and so the text "!#if" here both NEED the initial
% escape mark and it will not be treated as introducing a conditional
% section.
         else if nxtsym!* = '!#if then go to conditional
         else if nxtsym!* = '!#else or
                 nxtsym!* = '!#elif then <<
                     nxtsym!* := x := bool := nil;
                     go to skipping >>
         else if nxtsym!* = '!#endif then go to a
         else if nxtsym!* = '!#eval then <<
                     errorset(rread(), !*backtrace, nil);
                     curescaped!* := (escaped!* := nil);
                     go to a >>
         else if nxtsym!* = '!#define then <<
                     x := errorset('(rread), !*backtrace, nil);
                     curescaped!* := (escaped!* := nil);
                     if errorp x then go to a;
                     y := errorset('(rread), !*backtrace, nil);
                     curescaped!* := (escaped!* := nil);
                     if errorp y then go to a;
                     put(car x, 'newnam, car y);
% Print a message to show that the "#define" has been seen.
                     princ "*** "; prin car x; princ " => "; print car y;
                     go to a >>
         else if null(ttype!* = 3) then go to l
         else if nxtsym!* eq !$eof!$ then return filenderr()
         else if nxtsym!* = '!' then rederr "Invalid QUOTE"
         else if !*eoldelimp and nxtsym!* eq !$eol!$ then go to delim
         else if nxtsym!* = '!# and not seprp crchar!* then go to hh
         else if null (x:= get(nxtsym!*,'switch!*)) then go to l
         else if eqcar(cdr x,'!*semicol!*) then go to delim;
        bool := seprp crchar!*;
   sw1: nxtsym!* := token();
        if null(ttype!* = 3) then go to sw2
         else if nxtsym!* eq !$eof!$ then return filenderr()
         else if car x then go to sw3;
   sw2: cursym!*:=cadr x;
        curescaped!*:=nil;
        bool := nil;
        if cursym!* = '!*rpar!* then go to l2
         else return addcomment cursym!*;
   sw3: if bool or null (y:= atsoc(nxtsym!*,car x)) then go to sw2;
        prin2x nxtsym!*;
        x := cdr y;
% The next line is a hook for RLISP88 where input of the form
%    /* .... */ reads in as (!*comment!* "....") so that the comment
% text can be preserved.
        if null car x and cadr x = '!*comment!*
          then << comment!* := read!-comment(); go to a >>;
        go to sw1;
  hh:
% Here I have a "#" not preceeded by an escape marker (!) and followed
% by something that is not a separator. I will handle that at first rather
% as if it was the "switch" case but with extra support for some special
% cases like "#if".
        bool := nil;
        x := get(nxtsym!*,'switch!*);
        nxtsym!* := token();
        if nxtsym!* = 'if or
           nxtsym!* = 'else or
           nxtsym!* = 'elif or
           nxtsym!* = 'endif or
           nxtsym!* = 'eval or
           nxtsym!* = 'define then go to preprocessor;
        if null(ttype!* = 3) then go to sw2
         else if nxtsym!* eq !$eof!$ then return filenderr()
         else if car x then go to sw3;
        go to sw2;
  preprocessor:
        prin2x nxtsym!*;
        nxtsym!* := intern list2string ('!# . explode2 nxtsym!*);
        go to c;
  conditional:
% The conditional expression used here must be written in Lisp form
        x := errorset(rread(), !*backtrace, nil);
        curescaped!* := (escaped!* := nil);
% errors in evaluation count as NIL
        if null errorp x and car x then go to a;
        x := nil;
        bool := t;
  skipping:
% I support nesting of conditional inclusion. However one new joy
% here is that a "#" followed (immediately) by one "if, "else", "elif"
% or "endif" must be noticed here... The way I do that here has the
% effect that (eg) ##endif is treated as ## endif not as # #endif so will
% not terminate a conditional block.
        if nxtsym!* = '!# and ttype!*=3 and not seprp crchar!* then <<
          nxtsym!* := token();
          if ttype!* = 0 then
            nxtsym!* := intern list2string ('!# . explode2 nxtsym!*) >>;
        if nxtsym!* = '!#endif then
           if null x then go to a else x := cdr x
        else if nxtsym!* = '!#if then x := nil . x
        else if (nxtsym!* = '!#else) and null x and bool then go to a
        else if (nxtsym!* = '!#elif) and null x and bool then go to conditional;
        nxtsym!* := token();
        if (ttype!*=3) and (nxtsym!* eq !$eof!$)
          then return filenderr()
         else go to skipping;
  delim:
        semic!*:=nxtsym!*;
        curescaped!* := nil;
        return addcomment '!*semicol!*;
  new:  nxtsym!* := x;
        if stringp x then go to l
        else if atom x then go to c
        else go to l;
  q1:   if null (car nxtsym!* = 'string) then go to l;
        prin2x " ";
        prin2x cadr(nxtsym!* := mkquote cadr nxtsym!*);
  l:    cursym!*:=nxtsym!*;
        curescaped!* := escaped!*;
        escaped!* := nil;
        nxtsym!* := token();
        if (nxtsym!* eq !$eof!$) and (ttype!* = 3) then return filenderr();
  l2:   if numberp nxtsym!*
           or (atom nxtsym!* and null get(nxtsym!*,'switch!*))
          then prin2x " ";
        return addcomment cursym!*
   end;

symbolic procedure read!-comment1 u;
   begin scalar !*lower,!*raise;
      named!-character!* := nil;
 comm1:
      if named!-character!* or
         (null (string!-length id2string crchar!* = 1)) or
         (null (delcp crchar!*)) or
         (crchar!* eq !$eol!$) then <<
             named!-character!* := nil;
             crchar!* := readch1();
             go to comm1 >>;
      crchar!* := '! ;
      condterpri()
   end;

% The next procedure is adapted from code in RLISP88 for a comment
% opened with "/*". These leave material in the source.

symbolic procedure read!-comment;
   begin
      scalar x,y,z;
      begin
         scalar !*raise, !*lower;
         z := list crchar!*;
      a: named!-character!* := nil;
         if (x := readch()) = '!* and not named!-character!* then
            if (y := readch()) = '!/ and not named!-character!* then return nil
            else z := y . x . z
         else if x = !$eof!$ then rederr "EOF encountered in comment"
         else z := x . z;
         go to a;
      end;
      crchar!* := readch();
      return list('!*comment!*, list2string reversip z)
   end;


endmodule;

end;
