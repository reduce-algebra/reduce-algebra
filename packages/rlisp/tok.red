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

% $Id$

% WARNING:
% This file can be read in the process of bootstrapping Reduce, and in that
% case it may be processed by a limited version of the rlisp parser that
% has been expressed directly in Lisp. That initial parser was only intended
% for use during bootstrapping and so was kept as simple and small as
% possible. During the build process sometimes definitions here overlay
% the bootstrap ones immediately and this can mean that parsing here happens
% using a mix of initial and new code. So this file has to be written in
% a really conservative style! In the past the bootstrap parser did not
% accept either "<<...>>" group statements or "where" loops and as a result
% many constructs needed to be expressed using labels and "go to". These days
% that restriction has been lifted, but historical code here remains expressed
% with very many "go to" statements and looks archaic in style. One limit
% that remains in 2024 is that unary "-" is not supported at the stage that
% this file is processed ("-" is thought of as just an infix operator for
% subtraction) so it is not possible to write a constant "-1" and the
% code instead spells out "minus 1".
% Other perhaps clumsy notation here may either represent historical relics
% or extreme caution.

% Re-work of scan() in April 2024. ACN.

% Substantial changes in March 2014 to put in support for wide characters
% generally packed in the underlying Lisp string type using utf-8 encoding.

fluid '(!*adjprec !*comment !*defn !*eoldelimp !*minusliter
        peekchar!* !*quotenewnam !*raise !*lower semic!*
        !*report!_colons ifl!* curline!* comment!* !*comment!*);

!*report!_colons := t;

% Note *raise is global in the SL Report, but treated as fluid here.

global '(!$eof!$
         !$eol!$
         !*micro!-version
         crbuf!*
         crbuf1!*
         crchar!*
         cursym!*
         curescaped!*
         eof!*
         nxtsym!*
         outl!*
         ttype!*    %  Values in ttype!*:
%                      0  symbol                   a,b,c,word,!+
%                      1  string                   "something"
%                      2  number                   1,2, 1.0, 2.0
%                      3  operator-like character  +,-,...
%                      4  result of quotation      '(something)
         escaped!*
         !*csl
         !*psl
         blank
         tab
         named!-character!*);

blank := '! ;
% Later on I would be able to write "tab := '!#x09;;" for the character U+09
tab := '!	;  % A TAB character.

flag('(adjprec),'switch);

!*quotenewnam := t;
put('quotenewnam,'switchdefault,t);

crchar!* := blank;
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
% During the bootstrap build I can not go "inline procedure" so I put
% data on the property list manually to achieve the same effect.
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
    while u1 do <<
      n := car u1;
      u1 := cdr u1;
      if idp n then n := car widestring2list symbol!-name n
      else if stringp n and n neq "" then n := car widestring2list n
      else if null fixp n then rederr "Invalid item in arg to list2widestring";
      if n < 0 then error(1, "Negative integer in list2widestring")
% I put the constants in decimal because hex reading may not be
% available yet.
      else if n < 128 then len := len + 1
      else if n < 2048 then len := len + 2
      else if n < 65536 then len := len + 3
      else if n < 1114112 then len := len + 4
      else error(1, "Integer too large in list2widestring") >>;
    s := allocate!-string len;
    len := 0;
    while u do <<
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
  if null (land(n, 192) = 128) then
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
       if null (land(n, 128) = 0) then <<
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
       if null (land(car l, 192) = 128) then n := n + 1;
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
% in HTML. Thus "#amp;" and "&" will be equivalent, save that when #amp;
% is read the variable named!-character!* will be set by token(). This can
% be used to describe characters outside the safe 7-bit ASCII range,
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
% ambiguity between a name and a hex code with #ac;, #ace; and several
% others. To cope with that the symbolic name will take priority over a
% numeric interpretation, but a form #Xddd; or #Uddd; can be available
% where X introduces hex digits and U a decimal version, so interpretation
% as a numeric code-point can be forced. At present at least there are n
% name conflicts that arise if those versions are used! But if a future
% HTML standard introduced names starting "#x" or "#u" and continuing with
% letters in the range a-f some more thought might be needed!
%
% I will note (although it is not dealt with here) that later on in
% token/scan I will make "#if", "#else", "#elif", "#endif", "#eval" and
% "#define" special cases of tokens that can be written without needing
% the initial "#" to be escaped. Thus I want the words involved there
% to be disjoint from the ones I use for character entities. But supposing
% HTML introduced a notation "#if;" then with the semicolon in place that
% interpretation would be taken in preference to using that as a preprocessor
% directive.
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
% as "This string has an embedded #quot; in it". The previous
% notation where the (") needs to be doubled is still available.
% In a similar sort of way the end-of-line denoted by #NewLine; does not
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

symbolic procedure readch1;
  begin
    scalar x, y, w, n, save;
    named!-character!* := nil;
% First cope with anything that had been read ahead...
    if peekchar!* then <<
% WARNING. The flag "named!-character!*" is not handled with look-ahead.
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
      if null (x eq '!#) then return x;
      save := (!*raise . !*lower);
% I switch off !*raise and !*lower while reading. That is (for instance)
% so that #Sigma; and #sigma; can yield an upper and a lower case
% Greek sigma character.
      !*raise := (!*lower := nil);
      peekchar!* := x . peekchar!*;
      go to a >>
% Here I am accumulating a bit of stuff where I look ahead following
% a "#" character.
    else if (null (x eq !$eof!$)) and
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
    if (null (x eq '!;)) or (null cdr peekchar!*) then <<
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
    if car x neq '!_ then <<
      w := get(car x, 'hexdigit);
      if null w then go to fail;
      n := 16*n + w >>;
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

if !*csl then <<
% I will accept input such as 1.23S0. I preserve the fact that it named
% a short float by using ":dn!-s!:" to tag it rather than just ":dn:", but
% then in algebraic mode form() will map that back onto just !:dn!: so that
% the short nature of the float is only used in symbolic mode.
% put('!p, 'exponent!-mark, '!:dn!-p!:);
% put('!P, 'exponent!-mark, '!:dn!-p!:);
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

% The code in this file (still) has quote a lot of labels and goto statements.
% Some of this is a hang-over or consequence of bootstrapping issues. The
% way Reduce is built is that there is an initial rlisp parser that is
% fairly cut down and so which does not support all the syntax that will
% eventually become available. At least at one stage it did not support
% either blocks (as in <<A;B;C>>) or "while" statements. Behaviour that
% might have been expressed using either of those constructs was coded using
% labels and goto statements. These days the initial parser has been somewhat
% upgraded so nicer code can be used - but working through here improving
% style introduces risks (as does any code change) and so will happen
% rather gradually.

symbolic procedure token!-number x;
   % Read and return a valid number from input.
   % Adjusted by A.C. Norman to be less sensitive to input case and to
   % support hex numbers. And now hex floats in form such as 0x1.ABC5p-7
   % where the exponent is a scale in powers of 2, so for instance
   % 0x1.0P10 == 1024.0
   begin scalar dotp,power,sign,y,z,xmark;
      power := 0;
      ttype!* := 2;
    num1:
      if y or (null (x eq '!))) then y := x . y;
      if dotp then power := power - 1;
    num2:
      x := readch1();
      if (x eq !$eof!$) or
         (null (string!-length id2string x = 1)) then go to ret
% The code here used to generate a diagnostic on input like "1.2.3" but
% now it should accept 1.2 as a number and just stop reading at the second
% dot. That seems more friendly and generally consistent with what lexical
% processing should do.
       else if x eq '!. and null dotp then <<
         dotp := t;
         go to num2 >>
       else if digit x then go to num1
       else if y = '(!0) and ((x eq '!x) or (x eq '!X)) then go to hexnum
% Within a number any "\" together with the following character is ignored.
% I believe this will have been introduced for the case where the backslash
% is the final character on a line, so it provides for continuation of
% huge numbers. I am altering the code so that if the character after the
% "\" is not a newline the number terminates.
       else if x eq '!\ then <<
          if (x := readch1()) = !$eol!$ then go to num2;
          peekchar!* := '!\ . x . peekchar!*;
          go to ret >>
% In a way intended to be consistent with the treatment within hex numbers
% one can embed an underscore followed by any amount of whitespace in
% a number. This allows for continuation over a line with the continuation
% neatly indented, and also for grouping digits as in 12_34567_89012.
       else if x eq '!_ then <<
          while (x eq '!_) or (x eq !$eol!$) or (x eq blank) or (x eq tab) do
             x := readch1();
          peekchar!* := x . peekchar!*;
          go to num2 >>
       else if null(xmark := get(x, 'exponent!-mark)) then go to ret;
% I want to let exponent markers S, F, E, D and L be available for1
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
      if (null dotp) and ((x neq '!e) and (x neq '!E)) then go to ret;
      % Case of number with embedded or trailing E.
      dotp := t;
      if (x := readch1()) eq '!- then sign := t
       else if x eq '!+ then nil
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
% A hexadecimal number start off with "0x". After that there are hex
% digits 0-8a-f. Also a "." can be included to indicate a hexadecimally
% specified floating point number. Within this sequence "_" is special in
% that it together with any following whitespace is ignored. The consequence
% is that huge hex numbers can be input using "_" for line-breaks:  0x1234_
%      5678_9abc_
%      def0
% where obviously the "%" comment markers are not used!
% Negative numbers in hex are a bit of an oddity. I arrange that the
% notation "0x~" will stand for an infinite string of leading 1 bits so
% that 0x~f will be -1 and 0x~1 will be as 0x...ffff1 = -15. 
      x := readch1();
      if (z := get(x, 'hexdigit)) then <<
         y := 16*y + z;
         if dotp then power := power-4;
         while (z := get(x := readch1(), 'hexdigit)) do
         << y := 16*y + z;
            if dotp then power := power-4 >> >>
      else if x eq '!~ and y = 0 then <<
        y := minus 1;   % Can not yet write "-1" because of bootstrapping issues!
        goto hexnum1 >>;
      if x eq '!_ then <<
        while ((x := readch1()) = blank) or (x = tab) or (x = !$eol!$) do nil;
        peekchar!* := x . peekchar!*;
        go to hexnum1 >>;
      if x eq '!. then <<
        dotp := t;
        go to hexnum1 >>;
      if (x neq '!p and x neq '!P) then go to ret1; 
      dotp := t;
      if (x := readch1()) eq '!- then sign := t
      else if x eq '!+ then nil
      else if (x eq !$eof!$) or
              (null (string!-length id2string x = 1)) then go to hexe2
      else if null digit x then go to hexe2
      else z := list x;
   hexe1:
      x := readch1();
      if null (string!-length id2string x = 1) then go to hexe2
       else if null digit x then go to hexe2;
      z := x . z;
      go to hexe1;
   hexe2:
      if null z then z := 0
      else z := compress reversip!* z;
      if sign then power := power - z else power := power + z;
      if power >= 0 then nxtsym!* := y * expt(2, power)
      else nxtsym!* := mkrn(y , expt(2, 0-power));
      crchar!* := x;
      return nxtsym!*;
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

% The special marker !__line__ will be replaced in the input stream of
% tokens by the current line number. Note that if terminalp() returns
% true that input lines are not counted - ie if !*int is on (to signal
% interactive use) and input is direct from whatever is standard when
% reduce starts then !__line__ will always expand to 1. Go "off int;" or
% put your material in a file that you read using "in" if this matters
% to you. Similarly, the special marker !__file__ will be replaced by the
% name of the file currently read in, or the string "Terminal" if not
% reading from a file.

fluid '(!*line!-marker !*file!-marker);
% Note I can NOT just go "!*line!-marker := '__line__;" here since that
% would end up mapped to the line number in this file rather than the
% desired literal symbol - hence the use of intern on a string!
!*line!-marker := intern "__line__";
!*file!-marker := intern "__file__";

% The current syntax for an identifier is that it starts with a letter (or
% an escaped character) and can continue with letters, digits or underscores.
% I wish to support identifiers that contain an internal unescaped "::"
% (but just one such).
% When I started considering this I had wondered about also allowing
% an embedded single ":" too. However it became clear that that would cause
% trouble in common occuring cases such in
%         label:x:=y;
% and     for i:=m:n do ...
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
% merely denote a name that has embedded colons. But I hope to migrate to
% using it for namespace control at some stage.
%
% I suspect that the flag "!*minusliter" (which I hope is not made a flag
% that can be toggled using on/off, since it is a dodgy thing for ordinary
% users to mess with) causes "-" to be accepted as a "letter" within but
% not at the start of a name. Thus "-a-b+c" ends up parsing as
%      (plus (minus a!-b) c)
%
% A change in November 2022 arranges that although normally "_" is
% treated as a letter when within a symbol but needs to be escaped (with
% "!") at the start of a symbol, a double underscore can start a symbol
% without need for escape. This allows the token __line__ and its friends
% to be used more easily.

% This function gets replaces in calrend.red or pslrend.red but is here so
% that during system building there is a version of the function when token()
% gets defined in the following version.

symbolic procedure seprp ch;
   (ch eq blank) or
   (ch eq tab) or
   (ch eq !$eol!$);

symbolic procedure token;
   begin scalar x,y,z;
% This is a big ugly procedure with a lot of GOTO statements. It is overdue
% for re-work.
        x := crchar!*;
    a:  if (x eq !$eof!$) or
           (null (string!-length id2string x = 1)) then go to unicode;
        if seprp x and null(x eq !$eol!$ and !*eoldelimp)
          then << x := readch1(); go to a >>
         else if digit x then return token!-number x
% Letters in the Basic Latin Block can be used without needing an escape
% character. The status of things such as U+00c1 (latin capital A with acute)
% and all the other supplemental characters (to say nothing of Greek letters)
% will be a matter for the underlying Lisp to worry about.
         else if liter x then go to letter
% '(...) and `(...) are handled here. They MIGHT have been left for
% scan to cope with but it ends up tidier to cope at this point.
         else if (y := get(x,'tokprop)) then return lispapply(y,nil)
% Comments introduced by "%" are detected here in token() so that they are
% honoured within quoted expressions. Comments starting with either the
% word "comment" or with "/*" are handled by scan() and will not be
% recognised within quoted expressions.
         else if x eq '!% then <<
            begin
               scalar txt, !*raise,!*lower;
               named!-character!* := nil;
% The comment here continues until end of line or end of file but the
% notation "#NewLine;" is an end of line character that does not end
% the line for these purposes! If !*comment is set the text of the
% comment is appended to the list !*comment!*.
               while (null (((x := readch1()) eq !$eol!$) or
                            (x eq !$eof!$))) or
                     named!-character!* do <<
                  txt := x . txt;
                  named!-character!* = nil >>;
               if !*comment then
                  !*comment!* :=
                     append(!*comment!*, list list!-to!-string reverse txt);
            end;
            x := readch1();
            go to a >>
         else if x eq '!! and null(!*micro!-version and null !*defn)
          then go to escape
         else if x eq '!" then go to string
         else if x eq '!\ then go to backslash
         else if x eq '!_ then go to underscore;
    unicode:
        ttype!* := 3;
        if x eq !$eof!$ then prog2(crchar!* := blank,filenderr());
        nxtsym!* := x;
        if null (x eq !$eof!$) then <<
           if (string!-length id2string x = 1) and (delcp x) then
             crchar!*:= blank else crchar!*:= readch1() >>;
        if null(x eq '!- and
                (null (crchar!* eq !$eof!$)) and
                (string!-length id2string crchar!*  = 1) and
                digit crchar!* and
                !*minusliter)
          then go to c;
        x := token!-number crchar!*;
        if numberp x then return minus x;  % For bootstrapping.
        rplaca(cdr x, minus cadr x);       % Also for booting.
        return x;
    underscore:
        x := readch1();
        if x eq '!_ then go to doubleunderscore;
        peekchar!* := x . peekchar!*;
        x := '!_;
        go to unicode;
    doubleunderscore:
        ttype!* := 0;
        x := wideid2list x;
        y := car x . y;
        go to let2;
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
        while x do <<
          y := car x . y;
          x := cdr x >>;
        x := readch1();
        if (x eq !$eof!$) or
            (null (string!-length id2string crchar!*  = 1)) then go to ordinarysym
         else if (digit x) or (liter x) then go to let1
         else if x eq '!! then go to escape
         else if x eq '!- and !*minusliter
          then go to let1
         else if x eq '!_ then go to let1     % Allow _ as letter.
         else if x eq '!: then go to maybepackage;
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
% Note that the "%" here is a TeX style comment and will not end up
% in !*comment!*.
        if x eq '!% then go to bscomm
        else if x eq !$eof!$ then <<
           crchar!* := blank;
           filenderr();
           nxtsym!* := x;
           return x >>;
% If I have found \begin{reduce} go back to scanning input normally.
        if null y then go to a;
        z := x;
        x := readch1();
        if null (z eq car y) then go to bsfound;
        y := cdr y;
        go to bssrch;
    bscomm:
        x := readch1();
        if x eq !$eof!$ then go to bssrch
        else if x eq !$eol!$ then go to bsfound
        else go to bscomm;
    maybepackage:                               % Seen abc:
        x := readch1();
        if x eq '!: then go to maybeextpackage;
        peekchar!* := list x;
        x := '!:;
        go to ordinarysym;
    maybeextpackage:                            % Seen abc::
        x := readch1();
        if (null (x eq !$eof!$)) and
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
           (null (string!-length id2string crchar!*  = 1)) then go to extdone
         else if (digit x) or (liter x) then go to extpackmore
         else if x eq '!! then go to extpackescape
         else if (x eq '!-) and !*minusliter
          then go to extpackmore
         else if x eq '!_ then go to extpackmore;    % Allow _ as letter.
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
             then << crchar!* := blank;
                     lpriw("***** End-of-file in string",nil);
                     filenderr() >>
            else if (null (x eq '!")) or named!-character!* then go to strinx;
           % Now check for embedded string character.
           named!-character!* := nil;
           x := readch1();
           if (x eq '!") and (null named!-character!*) then go to strinx;
           nxtsym!* := list2widestring cdr reversip!* y
         end;
        ttype!* := 1;
        crchar!* := x;
        go to c;
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
        if x eq '!) and eqcar(outl!*,blank) then outl!*:= cdr outl!*;
        prin2x x;
        if null ((x eq '!() or (x eq '!))) then prin2x blank;
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
         else if x eq '!( then return rrdls()
         else if null (((x eq '!+) or (x eq '!-)) and (digit crchar!*))
           then return x;
        y := ptoken();
        if eqcar(y,'!:dn!:) then y := dnform(y,nil,'symbolic);
        if null numberp y then <<
           nxtsym!* := " ";
           symerr("Syntax error: improper number",nil) >>
        else if x eq '!- then y := minus y;
        return y
   end;

symbolic procedure rrdls;
   begin scalar x,y,z;
    a:  x := rread1();
        if null (ttype!*=3) then go to b
         else if x eq '!) then return z
         else if null (x eq '!.) then go to b;
        x := rread1();
        y := ptoken();
        if (null (ttype!*=3)) or (null (y eq '!)))
          then << nxtsym!* := " "; symerr("Invalid S-expression",nil) >>
         else return nconc(z,x);
    b: z := nconc(z,list x);
       go to a
   end;

symbolic procedure rread;
   << prin2x " '"; rread1() >>;

flag('(!; !$),'delchar);

symbolic procedure delcp u;
   % Returns true if U is a semicolon, dollar sign, or other delimiter.
   % This definition replaces the one in the BOOT file.
   flagp(u,'delchar);
put('delcp, 'inline, '(lambda (u) (flagp u 'delchar)));

symbolic procedure toknump x;
   (numberp x) or eqcar(x,'!:dn!:) or eqcar(x,'!:int!:);

% The following version of SCAN provides RLISP with a facility for
% conditional compilation.  The protocol is that text is included or
% excluded at the level of tokens.  Control by use of reserved
% tokens #if, #else, #elif and #endif.  These are used in the form:
%    #if (some Lisp expression for use as a condition)
%    ... RLISP input ...
%    #else
%    ... alternative RLISP input ...
%    #endif
%
% The form
%    #if C1 ... #elif C2 ... #elif C3 ... #else ... #endif
% is also supported. Note that "#else" is treated exactly as if
% it had been "#elif t" so in fact multiple uses of "#else" will
% be accepted.
%
% This notation will not be recognised within quoted exressions, so
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
% good style?). The predicate that follows the word "#if" or "#elif" is
% read in a way that does not process further conditionals, so anybody
% who tries to be "clever" with
%   #if    #if something test1 #else test2 #endif  guarded material #endif
% is out of luck. The symbol "!#if" will be used as the predicate...

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
%    print "message";     % so care should be taken to select the most
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

<< newtok '((!# i f)         !#if);
   newtok '((!# e l s e)     !#else);
   newtok '((!# e l i f)     !#elif);
   newtok '((!# e n d i f)   !#endif);
   newtok '((!# e v a l)     !#eval);
   newtok '((!# d e f i n e) !#define) >>;

% The simple scheme for multi-character operator would lead to the
% input text (say) "#ifonly" rendering as "#if" followed by "only". I
% view that as dodgy. So for these alpametic extensions I will insist that
% the multi-character operator is only accepted if at the end the following
% character is not a letter, digit, "!" or "_". The consequence is that
% "#ifonly" will be seen as "#" followed by "ifonly". Sensible people
% will put whitespace or some other separator in as in "#if only" and
% "#if(something)".

flag('(!#if !#else !#elif !#endif !#eval !#define), 'need_termination);

symbolic procedure read_long_form_comment();
   << begin
         scalar !*raise,!*lower, x;
         named!-character!* := nil;
         while named!-character!* or
            (null (string!-length id2string crchar!* = 1)) or
            (null (delcp crchar!*)) or
            (crchar!* eq !$eol!$) do <<
                x := crchar!* . x;
                named!-character!* := nil;
                crchar!* := readch1();
                if crchar!* = !$eof!$ then filenderr(); >>;
         crchar!* := blank;
         condterpri();
% Note that the comment text here can include newlines.
         if !*comment then
            !*comment!* := append(!*comment!*, list list2string reverse x);
      end;
      cursym!* := '!*semicol!*;
      scan() >>;

% The next bit is somewhat ridiculous! It will arrange that the word
% "comment" will be recognized with any mix of upper and lower case
% letters. Well on a system that is internally either upper or lower
% case instances of "COMMENT" and "comment" can arise. If either !*raise or
% !*lower is set any input is reduced to one of those. But if Reduce is run
% in case-sensitive mode then other situations may arise, and the Reduce
% source code has used instances of "Comment". Handling all the other
% improbably cases is really just done because it is fairly easy and
% does not cost much!

% "foreach" statements are not yet available
flag('(
   !c!o!m!m!e!n!t !c!o!m!m!e!n!T !c!o!m!m!e!N!t !c!o!m!m!e!N!T !c!o!m!m!E!n!t
   !c!o!m!m!E!n!T !c!o!m!m!E!N!t !c!o!m!m!E!N!T !c!o!m!M!e!n!t !c!o!m!M!e!n!T
   !c!o!m!M!e!N!t !c!o!m!M!e!N!T !c!o!m!M!E!n!t !c!o!m!M!E!n!T !c!o!m!M!E!N!t
   !c!o!m!M!E!N!T !c!o!M!m!e!n!t !c!o!M!m!e!n!T !c!o!M!m!e!N!t !c!o!M!m!e!N!T
   !c!o!M!m!E!n!t !c!o!M!m!E!n!T !c!o!M!m!E!N!t !c!o!M!m!E!N!T !c!o!M!M!e!n!t
   !c!o!M!M!e!n!T !c!o!M!M!e!N!t !c!o!M!M!e!N!T !c!o!M!M!E!n!t !c!o!M!M!E!n!T
   !c!o!M!M!E!N!t !c!o!M!M!E!N!T !c!O!m!m!e!n!t !c!O!m!m!e!n!T !c!O!m!m!e!N!t
   !c!O!m!m!e!N!T !c!O!m!m!E!n!t !c!O!m!m!E!n!T !c!O!m!m!E!N!t !c!O!m!m!E!N!T
   !c!O!m!M!e!n!t !c!O!m!M!e!n!T !c!O!m!M!e!N!t !c!O!m!M!e!N!T !c!O!m!M!E!n!t
   !c!O!m!M!E!n!T !c!O!m!M!E!N!t !c!O!m!M!E!N!T !c!O!M!m!e!n!t !c!O!M!m!e!n!T
   !c!O!M!m!e!N!t !c!O!M!m!e!N!T !c!O!M!m!E!n!t !c!O!M!m!E!n!T !c!O!M!m!E!N!t
   !c!O!M!m!E!N!T !c!O!M!M!e!n!t !c!O!M!M!e!n!T !c!O!M!M!e!N!t !c!O!M!M!e!N!T
   !c!O!M!M!E!n!t !c!O!M!M!E!n!T !c!O!M!M!E!N!t !c!O!M!M!E!N!T !C!o!m!m!e!n!t
   !C!o!m!m!e!n!T !C!o!m!m!e!N!t !C!o!m!m!e!N!T !C!o!m!m!E!n!t !C!o!m!m!E!n!T
   !C!o!m!m!E!N!t !C!o!m!m!E!N!T !C!o!m!M!e!n!t !C!o!m!M!e!n!T !C!o!m!M!e!N!t
   !C!o!m!M!e!N!T !C!o!m!M!E!n!t !C!o!m!M!E!n!T !C!o!m!M!E!N!t !C!o!m!M!E!N!T
   !C!o!M!m!e!n!t !C!o!M!m!e!n!T !C!o!M!m!e!N!t !C!o!M!m!e!N!T !C!o!M!m!E!n!t
   !C!o!M!m!E!n!T !C!o!M!m!E!N!t !C!o!M!m!E!N!T !C!o!M!M!e!n!t !C!o!M!M!e!n!T
   !C!o!M!M!e!N!t !C!o!M!M!e!N!T !C!o!M!M!E!n!t !C!o!M!M!E!n!T !C!o!M!M!E!N!t
   !C!o!M!M!E!N!T !C!O!m!m!e!n!t !C!O!m!m!e!n!T !C!O!m!m!e!N!t !C!O!m!m!e!N!T
   !C!O!m!m!E!n!t !C!O!m!m!E!n!T !C!O!m!m!E!N!t !C!O!m!m!E!N!T !C!O!m!M!e!n!t
   !C!O!m!M!e!n!T !C!O!m!M!e!N!t !C!O!m!M!e!N!T !C!O!m!M!E!n!t !C!O!m!M!E!n!T
   !C!O!m!M!E!N!t !C!O!m!M!E!N!T !C!O!M!m!e!n!t !C!O!M!m!e!n!T !C!O!M!m!e!N!t
   !C!O!M!m!e!N!T !C!O!M!m!E!n!t !C!O!M!m!E!n!T !C!O!M!m!E!N!t !C!O!M!m!E!N!T
   !C!O!M!M!e!n!t !C!O!M!M!e!n!T !C!O!M!M!e!N!t !C!O!M!M!e!N!T !C!O!M!M!E!n!t
   !C!O!M!M!E!n!T !C!O!M!M!E!N!t !C!O!M!M!E!N!T), '!*comment!*);

% The next procedure is for a comment opened with "/*".

symbolic procedure read_slash_star_comment();
   << begin
         scalar x,y,txt,!*raise,!*lower;
         txt := list crchar!*;
      a: named!-character!* := nil;
         if (x := readch()) eq '!* and (null named!-character!*) then
            if (y := readch()) eq '!/ and (null named!-character!*) then <<
               if !*comment then
                  !*comment!* := append(!*comment!*,
                                        list list2string reversip txt);
               return >>
            else if y eq !$eof!$ then fileenderr()
            else txt := y . x . txt
         else if x = !$eof!$ then rederr "EOF encountered in comment"
         else txt := x . txt;
         go to a;
      end;
      crchar!* := readch();
      cursym!* := '!*semicol!*;
      scan() >>;

put('!*comment!*, 'scan_action!*, 'read_slash_star_comment);

% scan() handles a whole range of things:
% (1) Multi-character tokens such as ">=" and "-->".
% (2) Comments introduced with the word "comment".
% (3) Handling of "/*" comments. Note that "%" comments are
%     handled in token() not here.
% (4) Preprocessor conversions using "#define" and the newnam property.
% (5) Conditional source inclusion using "#if" and friends.
% (6) "#eval".
% (7) Some behaviour using outl!* and prin2x which maintains the contextual
%     information to be printed if a syntax error is encountered.

% A stray remark. Comments introduced by "%" are honoured within quoted
% expresisons, but ones with the word "comment" or "/*" are not, so
% '(comment /* not a comment here */;);
% has all those items present in the list and "/" and "*" are handled as
% separate characters. Similarly '(a := 3) is a list of length 4 with ":"
% and "=" as separate atoms within it.

global '(skipping!*);
skipping!* := nil;

symbolic procedure read_define();
   begin
      scalar x, w;
      x := rread();
      if null idp x then symerr("#define can only define a sumbol", nil);
      w := rread();
      if null skipping!* then put(x, 'newnam, w);
      cursym!* := '!*semicol!*;  % Forces reading of the next token.
      return scan()
   end;

put('!#define, 'scan_action!*, 'read_define);

% The way I need to handle "#if" is basically by using a stack automaton
% to parse the context-free grammar that matches "#if" with "#endif".
% One issue that tends to compilicate that automaton is a feeling that
% "#else" should always come at the end. To simplify parsing I will
% implement things so that "#else" is treated in the same way as "#elif t",
% and that means that it becomes legal to have multiple "#else" sections,
% and further "#elif" ones after an "#else". So
%   #if nil; A; #else B; #else C; #elif X D; #endif
% will be accepted (and "B;") would be the part that gets through.
%

global '(if_stack);
if_stack := '(NOT_WITHIN_IF);

symbolic procedure scan_state();
   car if_stack;
put('scan_state, 'inline,
    '(lambda () (car if_stack)));

symbolic procedure push_state new_state;
   if_stack := new_state . if_stack;
put('push_state, 'inline,
    '(lambda (new_state) (setq if_stack (cons new_state if_stack))));

symbolic procedure pop_state();
   if_stack := cdr if_stack;
put('pop_state, 'inline,
    '(lambda () (setq if_stack (cdr if_stack))));

symbolic procedure change_state new_state;
   if_stack := new_state . cdr if_stack;
put('chance_state, 'inline,
    '(lambda (new_state) (setq if_stack (cons new_state (cdr if_stack)))));

% When #if wants to ignore some material it can call this. The requirement
% then if that #if, #else, #elif and #endif clear skipping!*. Also #eval
% and #define do not do anything in skipping mode. This arranges that
% all sorts of comment, strings and quoted expressions are handled in
% ways that do not interect with #if.

symbolic procedure scan_skip();
   begin
% Observe that because I remind !*comment!* and comment!* any comments
% within skipped material are not recorded. I think that makes sense!
      scalar w, !*comment!*, comment!*;
      skipping!* := t;
      while skipping!* do w := scan();
      return w
   end;

% #if X
%       normal: evaluate X
%               non-nil            push "iftrue" and return next token
%               nil                push "iffalse" and skip to next directive
%       iftrue: evaluate X
%               non-nil            push "iftrue" and return next token
%               nil                push "iffalse" and skip to next directive
%       iffalse:do not evaluate X
%                                  push "ifdone" and skip to next directive
%       ifdone: do not evaluate X
%                                  push "ifdone" and skip to next directive

symbolic procedure read_if();
   begin
      scalar x;
      skipping!* := nil;
% Again note that eg "#if #if" will be treated as "#if !#     if"
% rather than as a messed up attempt to nest conditionals.
      x := rread();
      if (scan_state() = 'NOT_WITHIN_IF) or
         (scan_state() = 'IF_TRUE) then <<
         x := errorset(x, !*backtrace, nil);
         if errorp x then x := nil else x := car x;
         if x then <<
            push_state 'IF_TRUE;
            cursym!* := '!*semicol!*;
            return scan() >>
         else <<
            push_state 'IF_FALSE;
            return scan_skip() >> >>
      else <<
         push_state 'IF_DONE;
         return scan_skip() >>
   end;

put('!#if, 'scan_action!*, 'read_if);

% #else
%       normal:                    error
%       iftrue:                    set "ifdone" and skip to next directive
%       iffalse:                   set "iftrue" and return next token
%       ifdone:                    leave as "ifdone", skip to next directive
%

symbolic procedure read_else();
   begin
      skipping!* := nil; 
      if scan_state() = 'IF_TRUE then <<
         change_state 'IF_DONE;
         return scan_skip() >>
      else if scan_state() = 'IF_FALSE then <<
         change_state 'IF_TRUE;
         cursym!* := '!*semicol!*;
         return scan() >>
      else if scan_state() = 'IF_DONE then return scan_skip()
      else symerr("unexpected #else", nil);
   end;

put('!#else, 'scan_action!*, 'read_else);

% #elif X
%       normal:                    error
%       iftrue: do not evaluate X  set "ifdone" and skip to next directive
%       iffalse:evaluate X
%               T                  set "iftrue" and return next token
%               NIL                leave as "iffalse" and skip to next directive
%       ifdone: do not evaluate X  leave as "ifdone", skip to next directive
%

symbolic procedure read_elif();
   begin
      scalar x;
      skipping!* := nil;
      x := rread();
      if scan_state() = 'NOT_WITHIN_IF then
         symerr("unexpected #endif", nil)
      else if (scan_state() = 'IF_TRUE) or
         (scan_state() = 'IF_DONE) then <<
         change_state 'IF_DONE;
         return scan_skip() >>;
% must be 'IF_FALSE here...
      x := errorset(x, !*backtrace, nil);
      if errorp x then x := nil else x := car x;
      if x then <<
         change_state 'IF_TRUE;
         cursym!* := '!*semicol!*;
         return scan() >>
      else return scan_skip()
   end;

put('!#elif, 'scan_action!*, 'read_elif);

% #endif
%       normal:                    error
% otherwise pop and consider the new state:
%          normal:                 return next tokem
%          iftrue:                 return next token
%          iffalse:                skip
%          ifdone:                 skip

symbolic procedure read_endif();
   begin
      skipping!* := nil; 
      if scan_state() = 'NOT_WITHIN_IF then
         symerr("unexpected #endif", nil);
      pop_state();
      cursym!* := '!*semicol!*;
      if scan_state() = 'NOT_WITHIN_IF or
         scan_state() = 'IF_TRUE then return scan()
      else return scan_skip();
   end;

put('!#endif, 'scan_action!*, 'read_endif);

symbolic procedure read_eval();
   begin
% Note that rread() uses token() not scan() to read things, and so
% if some clown writes something like
%     eval #if ...
% the item read by rread will be just !# and there is no risk of
% the sort of confusion that could arise if the string "#if" was
% recognised as a directive!
      scalar x;
      x := rread();
      if null skipping!* then errorset(x, !*backtrace, nil);
      cursym!* := '!*semicol!*;  % Forces reading of the next token.
      return scan()
   end;

put('!#eval, 'scan_action!*, 'read_eval);

% In general scan() will read the token following the one that it returns
% because in previous versions that was how it handled multi-character
% operator names such as ":=". These days it processes those character at
% a time not token at a time. However changing its external interface would
% potentially impact all places where it is called, so this look-ahead
% remains in place. Note that if a semicolon is read the material beyond
% that is not inspected.

symbolic procedure scan();
   begin
      scalar x, w;
% If the most recent symbol is a semicolon then I did not read the
% token beyond it into nxtsym!* - so I must do that now.
      if cursym!* eq '!*semicol!* then <<
         escaped!* := nil;
         nxtsym!* := token() >>;
% outl!* is used to record the current context so that if a syntax error
% arises it can be echoed - potentially with "$$$" inserted to mark the
% place where things were wrong. prin2x adds items to it. So here I
% update it is the most recent token was a string.
      if (null atom nxtsym!*) and (null toknump nxtsym!*) then <<
         if car nxtsym!* eq 'string then <<
            prin2x " ";
            prin2x cadr(nxtsym!* := mkquote cadr nxtsym!*) >>;
            cursym!*:=nxtsym!*;
            curescaped!* := escaped!*;
% Set nxtsym!* to the token beyond this one.
            escaped!* := nil;
            comment!* := !*comment!*; !*comment!* := nil;
            nxtsym!* := token();
% On some platforms the end of file marker is the symbol !$eof!$ itself,
% however when that is read because readch() returns it token() will
% report it with ttype!*=3 while if the text "!$eof!$" appears in a file
% that will be a token of type 0.
            if (nxtsym!* eq !$eof!$) and (ttype!* = 3) then return filenderr();
            if (numberp nxtsym!*)
               or ((atom nxtsym!*) and (null get(nxtsym!*,'switch!*)))
               then prin2x " ";
            if (w := get(cursym!*, 'scan_action!*)) then
               return apply(w, nil);
            return cursym!* >>;
% "else" and ";" lead to outl!* being cleared so that the "context" displayed
% in diagnostics does not get unnecessarily long.
      if (nxtsym!* eq 'else) or (cursym!* eq '!*semicol!*) then outl!* := nil;
      prin2x nxtsym!*;
% Deal with 'newnam. I allow for chains of renaming, but also stop
% on any loop. So if the user goes (say)
%    #define A B
%    #define B A
% then if either A or B is encountered rather than the code just looping
% as earlier versions of Reduce did!) I will stop and return at one of the
% symbols along the way.
      while (idp nxtsym!*) and
            (x := get(nxtsym!*, 'newnam)) and
            (null (x member (w := nxtsym!* . w))) do nxtsym!* := x;
% Now if the item read is anything other than an operator-like character
% I should just return it (but adding info to outl!* and reading the
% following token...). Well I also do this if it is an operator-like
% character but one that can not start a multi-char symbol.
      x := nil;
      if (null (ttype!* = 3)) or
         (null
            ((idp nxtsym!*) and (x := get(nxtsym!*, 'switch!*)))) then <<
% I will make "comment" introduce a comment but eg "!comment" will not.
         if flagp(nxtsym!*, '!*comment!*) and (null escaped!*) then
            return read_long_form_comment();
         cursym!* := nxtsym!*;
         curescaped!* := escaped!*;
         escaped!* := nil;
         comment!* := !*comment!*; !*comment!* := nil;
         nxtsym!* := token();
         if (nxtsym!* eq !$eof!$) and (ttype!* = 3) then return filenderr();
         if (numberp nxtsym!*) or
            ((atom nxtsym!*) and (null get(nxtsym!*,'switch!*)))
            then prin2x " ";
         return cursym!* >>;
% Note that x is now the switch!* property for nxtsym!*.
% Semicolons (and newlines if !*eoldelimp is set) are special - and note that
% "$" decodes as a semicolon! This probably means that one can not introduce
% a multi-char operator that starts with either ";" or "$".
      if eqcar(cdr x, '!*semicol!*) or
         (!*eoldelimp and (nxtsym!* = !$eol!$)) then <<
         semic!* := nxtsym!*;
         curescaped!* := nil;
         return (cursym!* := '!*semicol!*) >>;
% Next I will consolidate multi-character operators.
% It is possible that (say) a 3 character token has been defined but
% not its two-character prefix. Or perhaps not even the one-character lead
% in. In these cases the code as written is not good enough!
      w := list(crchar!* . x);
      while (x := atsoc(crchar!*, car x)) do <<
         x := cdr x;
         crchar!* := readch1();
         w := (crchar!* . x) . w >>;
% Now if the sequence of characters matched was something like "#if" but the
% following character is alphanumeric (or "_" or "!") I will pretend that
% it was not a match by updating my backtrack-list.
      if (null null cddar w) and
         flagp(caddar w, 'need_termination) and
         ((liter crchar!*) or (digit crchar!*) or
            (crchar!* eq '!_) or (crchar!* eq '!!)) then <<
         w := (caar w . '(())) . cdr w >>;
% w is now a list showing the state at each stage in this investigation.
% Each item in it is a character paired with the switch!* record it
% was associated with. In normal circumstances the place where I stop
% will have cdar w of the form (??? token) where token is the result I
% must return. However there are cases such as the one that arises with
% "-->" where if the input is "--x" we end up with cdar w being (???) [ie
% with a nil where there would have been a list showing the token to
% return on "--" input. I must detect that case and backtrack. Note that
% the very first character that starts a sequence MUST have a translation
% and so the loop here will end tidily.
w := w;
      while null cddar w do <<
         peekchar!* := crchar!* . peekchar!*;
         w := cdr w;
         crchar!* := caar w >>;
      cursym!* := caddar w;
% Comments introduced by "/*" can now be handled. Note that the treatment here
% differs from the previous in that with the old scheme even if the switch!*
% data allowed for a longer operator-token starting with "/*" the first two
% characters would trigger comment processing. This difference could only
% be triggered if there was a  "newtok '((!/ !* something-more) ???);"
% so if that is avoided all will be well. However I could at least imagine
% a future change that make "/**" introduce a special sort of comment - maybe
% one related to extractable documentation) so all in all I view this as a
% sane "upgrade".
      if (w := get(cursym!*, 'scan_action!*)) then return apply(w, nil);
      escaped!* := nil;
      comment!* := !*comment!*; !*comment!* := nil;
      nxtsym!* := token();
      return cursym!*;
   end;

endmodule;

end;
