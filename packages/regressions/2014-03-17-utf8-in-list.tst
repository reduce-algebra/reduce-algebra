% This is for checking how the underlying Lisp copes with
% printing (and exploding) strings and symbols that contain
% multi-byte characters - ie utf-8 sequences for characters with
% code over U+007f.

% The output is a little tedious to decode, but this is intended to
% illustrate a collection of cases both as regards the actual
% output generated and the calculation of "output columns" and hence
% the way in which lines get wrapped.

% At present this is only expected to give even partly sensible
% results with CSL.

lisp;
on echo;

% test line overflow

<<
% This test dispays a sequence of characters in clumps of 7 interleaved
% with numbers showing the output column that has been reached. The
% three instances use a letter "a" which provides a simple reference case.
% then there is a "pi", a "forall" symbol and a double-struck capical B:
% those use two, three and four bytes. Note that the #Bopf; may not be
% available in the font you use unless it is somewhat specialised.
% Note that #Zopf;, #Qopf; and #Ropf; are often used to denote the integers,
% rationals an dreals, and that #Bopf; is a similar font effect.
%
% If things work well then the display should be similar in all cases,
% both in term of the column values printed and the position
% where line-breaks are inserted. If (eg) a sequence of utf-8 bytes ends up
% counted as multiple "columns" that could lead to differences.
%
% First try printing strings.
  linelength 72;
  terpri(); terpri();
  prin2 "Check linelength effect with strings";
  terpri();
  prin2 ".. each of the following 4 blocks should show the sama layout";
  foreach x in list("a", "#pi;", "#ForAll;", "#Bopf;") do <<
     terpri();
     for i := 1:11 do <<
       for j := 1:7 do prin2 x;
       prin2 posn() >> >>;
  terpri(); terpri();
% Now the same but printing symbols (using prin2).
  prin2 "Check linelength effect with symbols";
  terpri();
  prin2 ".. each of the following 4 blocks should show the sama layout";
  foreach x in list('a, '#pi;, '#ForAll;, '#Bopf;) do <<
     terpri();
     for i := 1:11 do <<
       for j := 1:7 do prin2 x;
       prin2 posn() >> >>;

% This section uses prin1 and variations on explode to process first strings
% and then symbols with various contents. For prin1 the requirement is that
% the output be re-inputable.
% The string here is intended to contain a jolly mix of potential issues.
  w1 := "2AbCd #pi; #ForAll; #Bopf; #hash;pi; #quot; #gamma; #Gamma;";
  foreach x in list(w1, intern w1) do <<
     terpri();
     prin2 "Test using ";
     if stringp x then prin2 "strings" else prin2 "symbols";
     terpri();
% prin2 is used just to display the information "naturally" (at least
% if you have an utf-8 capable terminal with enough fonts installed.
     prin2 "Raw: "; prin2 x; print posn();

% prin1 should generate re-inputable material, and to assure that it
% renders extended characters as hex sequence such as "#1234;". Within a
% string if such a sequence literally occured then the initial "#" is expanded
% to be "#hash;". In strings any double quote mark is doubled, while in
% symbols special characters are preceeded by an exclamation mark.
     prin2 "prin1: "; prin1 x; print posn();

% explode2 should be rather like prin2 except that it generates a list of
% characters. Note that this means that multi-byte sequences in the data will
% need to be rendered as single multi-byte character objects. E.g.
% explode2 "#alpha;" => (#alpha;), a list of length 1.
% spaces) it must explode2 as 
     prin2 "explode2: "; prin1 explode2 x; print posn();

% explode is like prin1 except that it can end up with extended characters...
% thus
% explode "#alpha;" => (!" !#alpha; !"), a list of length 3. The only joker
% here is that if the string contains a literal sequence "# w o r d ;" (without
% the spaces) then that has to end up as (!" !# h a s h !; w o r d !; !")
% so it can be re-inputable.
     prin2 "explode: "; prin1 explode x; print posn();
% explodecn is like explodec but returns a list of the numeric codes of
% the characters involved. E.g.
% explodecn "#alpha;" => (945)
     princ "explodecn: "; prin1 explodecn x; print posn();
% exploden is like explode but returns a list of integer codes.
% Note some codes can be bigger than 0xff.
     princ "exploden: "; prin1 exploden x; print posn();
% explode2uc (and explode2lc, explode2ucn, explode2lcn) are like
% explode2 except that they folds characters to upper or lower case.
% There are two issues here. The first is whether #alpha; will change to
% #Alpha; (and similarly for all other non-Latin letters), the second
% is that the names for special characters will need to retain their
% regular case, so for instance #Alpha; must appear not #ALPHA; even
% after conversion to upper case. If in fact extended characters are
% printed in hex not using names much of that worry evaporates.
% In some - perhaps all - locales only a-x and A-Z will be changed
% by case folding...
     princ "explode2uc: "; prin1 explode2uc x; print posn() >>;
     princ "explode2lc: "; prin1 explode2lc x; print posn() >>;
  terpri() >>;

end;
