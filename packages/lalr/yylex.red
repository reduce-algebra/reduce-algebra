% yylex.red

% Author: Arthur Norman

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

module 'yylex;


%
% This is a lexical anaylser for use with RLISP. Its interface is
% styles after the one needed by yacc, in that it exports a function
% called yylex() that returns as a value a numeric category code, but
% sets a variable yylval
% just parsed. Single character objects are coded as their (ASCII?) code
% [leaving this code non-portable to machines with other encodings?].
% Other things must have been given 'lex_code properties indicate the
% associated category code.  This lexer handles ' and ` as special prefix
% characters that introduce Lisp-stype s-expressions. and it knows about
% RLISP-style comments and a few diphthongs. It also supports some
% simple preprocessor directives.
%


% I keep a circular buffer with the last 64 characters that have been
% read. Initially the buffer contains NILs rather than characters, so I can
% tell when it is only partially filled. I have made yyreadch() a macro
% because it is probably one of the time-critical parts of the entire
% parsing process.

inline procedure yyreadch();
 << lex_char := readch();
    if lex_char = !$eol!$ then which_line := which_line + 1;
    if lex_char neq !$eof!$ then << 
       last64p := last64p + 1;
       if last64p = 64 then last64p := 0;
       putv(last64, last64p, lex_char) >>;
    lex_char >>;

symbolic procedure yyerror msg;
  begin
    scalar c;
    terpri();
    princ "+++++ Parse error at line "; prin which_line; princ ":";
    if atom msg then msg := list msg;
    for each s in msg do << princ " "; princ s >>;
    terpri();
    for i := 1:64 do <<
       last64p := last64p + 1;
       if last64p = 64 then last64p := 0;
       c := getv(last64, last64p);
       if not (c = nil) then princ c >>;
    if not (c = !$eol!$) then terpri();
    if lex_char = !$eof!$ then printc "<EOF>"
  end;

% Before a succession of calls to yylex() it is necessary to
% ensure that lex_char is set suitably and that the circular buffer
% used to store characters for error messages is ready for use.

symbolic procedure start_parser();
 << last64 := mkvect 64;
    last64p := 0;
    which_line := 1;
    if_depth := 0;
    yyreadch() >>;

%
% The following version of YYLEX provides RLISP with a facility for
% conditional compilation.  The protocol is that text is included or
% excluded at the level of tokens.  Control by use of new reserved
% tokens !#if, !#else and !#endif.  These are used in the form:
%    !#if (some Lisp expression for use as a condition)
%    ... RLISP input ...
%    !#else
%    ... alternative RLISP input ...
%    !#endif
%
% The form
%    !#if C1 ... !#elif C2 ... !#elif C3 ... !#else ... !#endif
% is also supported.
%
% Conditional compilation can be nested.  If the Lisp expression used to
% guard a condition causes an error it is taken to be a FALSE condition.
% It is not necessary to have an !#else before !#endif if no alternative
% text is needed. Although the examples here put !#if etc at the start of
% lines this is not necessary (though it may count as good style?). Since
% the condition will be read using RLISPs own list-reader there could be
% condtional compilation guarding parts of it - the exploitation of that
% possibility is to be discouraged!
%
% Making the condition a raw Lisp expression makes sure that parsing it
% is easy. It makes it possible to express arbitrary conditions, but it is
% hoped that most conditions will not be very elaborate - things like
%    !#if (not (member 'csl lispsystem!*))
%         error();
%    !#else
%         magic();
%    !#endif
% or
%    !#if debugging_mode   % NB if variable is unset that counts as nil
%    print "message";      % so care should be taken to select the most
%    !#endif               % useful default sense for such tests
% should be about as complicated as reasonable people need.
% 
% Two further facilities are provided:
%    !#eval (any lisp expression)
% causes that expression to be evaluated at parse time.  Apart from any
% side-effects in the evaluation the text involved is all ignored. It is
% expected that this will only be needed in rather curious cases, for
% instance to set system-specific options for a compiler.
%
%    !#define symbol value
% where the value should be another symbol, a string or a number, causes
% the first symbol to be mapped onto the second value wherever it occurs in
% subsequent input.  No special facility for undoing the effect of a
% !#define is provided, but the general-purpose !#eval could be used to
% remove the '!#define property that is involved.
%
% NOTE: The special symbols !#if etc are NOT recognised within Lisp
%       quoted expressions, so test like the following will be
%       ineffective:
%            a := '(
%                P
%            !#if q_is_wanted
%                Q
%            !#endif
%                R);
%       but on the other hand code like
%            if sym = '!#if then ...
%       behaves the way that had probably been wanted. Unlike the C
%       preprocessor, this system recognizes directives within rather than
%       just at the start of lines.


symbolic procedure yylex();
  begin
    scalar w, done;
% I take a rather robust view here - words that are intended to be used as
% keywords may not be written with included escape characters. Thus for
% instance this lexer will view "be!gin" or "!begin" as being a simple
% symbol and NOT being the keyword "begin".
    w := lex_basic_token();
% The "while not done" loop is so that I can restart the scan after seeing
% a pre-processor directive such as !#if.
    while not done do <<
% The word "COMMENT" introduces a comment that terminates at the next ";"
% or "$".
        while yylval = 'comment and
              w = '!:symbol_or_keyword do <<
            while not (lex_char = '!; or lex_char = '!$) do
                yyreadch();
            yyreadch();
            w := lex_basic_token() >>;
% If a word was spelt out directly (without any escape characters in it) it
% may be a keyword - if it is, then convert it here.
        if w = '!:symbol_or_keyword then <<
            if w := get(yylval, '!#define) then <<
                yylval := cdr w; 
                w := car w >>
            else <<
                if done := get(yylval, 'lex_code) then w := done
                else if flagp(yylval, 'rlis) then
                    w := get('rlistat, 'lex_code)
                else if flagp(yylval, 'endstat) then
                    w := get('endstat, 'lex_code)
                else w := get('!:symbol, 'lex_code);
                done := t >> >>
% A word with escapes in might be a pre-processor directive.
        else if w = '!:symbol then <<
            if yylval eq '!#if then <<
                read_s_expression();
                w := lex_conditional yylval >>
            else if yylval eq '!#else or
                    yylval eq '!#elif then <<
                if if_depth = 0 then yyerror "Unexpected #else of #elif"
                else if_depth := if_depth-1;
                yylval := nil;
                w := lex_skipping(w, nil) >>
            else if yylval eq '!#endif then <<
                if if_depth = 0 then yyerror "Unexpected #endif"
                else if_depth := if_depth-1;
                w := lex_basic_token() >>
            else if yylval eq '!#eval then << 
                read_s_expression();
                errorset(yylval, nil, nil);
                w := lex_basic_token() >>
            else if yylval eq '!#define then <<
                read_s_expression();
                w := yylval;    % Ought to be a symbol
                done := read_s_expression();
                if idp w then put(w, '!#define, done . yylval);
                w := lex_basic_token();
                done := nil >>
            else <<
                w := get('!:symbol, 'lex_code);
                done := t >> >>
        else if numberp w then <<
% Now gobble up extra characters for multi-character operators (eg ">=").
% Note that I only look one character ahead here.
            while done := atsoc(lex_char, get(yylval, 'lex_dipthong)) do <<
                w := cdr done;
                yylval := cdr w;
                w := get(car w, 'lex_code);
                yyreadch() >>;
            if done := get(yylval, '!#define) then <<
                yylval := cdr done;
                w := car done;
                done := nil >>
            else done := t >>
        else <<
            done := t;
            w := get(w, 'lex_code) >> >>;
    return w
  end;



% If, when reading ordinary text, I come across the token !#if I read
% the expression following. If that evaluates to TRUE I just keep on
% on reading. So the sequence "!#if t" is in effect ignored. Then
% if later on I just ignore an "!#endif" all will be well.  If on the other
% hand the expression evaluates to NIL (or if evaluation fails), I will
% call lex_skipping() to discard more tokens (up to and including
% the next "!#else", "!#elif t" or "!#endif"). I keep a count of how many
% "!#if t" equivalents I have passed so that I can match them with their
% corresponding "!#endif" statements and moan if an "!#else" or "!#endif"
% occurs out of place.

symbolic procedure lex_conditional x;
  begin
    scalar w;
    w := lex_basic_token();
    x := errorset(x, nil, nil);
    if errorp x or null car x then return lex_skipping(w, nil);
    if_depth := if_depth+1;
    return w
  end;

% I call lex_skipping when I find "!#if nil" or "!#else" or "!#elif"
% that is processed. When a top-level "!#else" or "!#elif" is found it
% is discarded before calling lex_skipping, since it must follow a
% successful "!#if" and hence introduce material to be thrown away.

symbolic procedure lex_skipping(w, x);
  begin
    scalar done;
% In this code x keep track of the depth of testing of "!#if" constructions
    while not done do <<
        if w = 0 then done := t   % End of file
        else <<
            if w = '!:symbol then <<
                if yylval = '!#endif then <<
                    if null x then done := t
                    else x := cdr x >>
                else if yylval = '!#if then x := nil . x
                else if yylval = '!#else and null x then done := t
                else if yylval = '!#elif and null x then <<
                    read_s_expression();
                    done := errorset(yylval, nil, nil);
                    if errorp done or null car done then done := nil >> >>;
            w := lex_basic_token() >> >>;
    return w
  end;



% In some cases RLISP operators are made up out of two (or more) characters.
% I map '**' onto '^', and >=, <= onto GEQ and LEQ.
% ":=" becomes SETQ.   I turn << and >> onto symbols that can not be
% read directly (!:lsect and !:rsect).
% This means that the system that sets up lex_code properties had really
% better make sure that it gives setq, geq, leq, !:rsect and !:lsect values.

put('!*, 'lex_dipthong, '((!* !^ . !^)));
put('!:, 'lex_dipthong, '((!= setq . setq)));
put('!>, 'lex_dipthong, '((!= geq . geq),
                          (!> !:rsect . !:rsect)));
put('!<, 'lex_dipthong, '((!= leq . leq),
                          (!< !:lsect . !:lsect)));

put('!^, 'lex_code, char!-code '!^);

put('!:symbol, 'lex_code, 256);
put('!:lsect,  'lex_code, 257);
put('!:rsect,  'lex_code, 258);
put('geq,      'lex_code, 259);
put('leq,      'lex_code, 260);
put('setq,     'lex_code, 261);
put('rlistat,  'lex_code, 262);
put('endstat,  'lex_code, 263);
put('!:number, 'lex_code, 264);
put('!:string, 'lex_code, 265);
put('!:list,   'lex_code, 266);

next_lex_code := 267;


% lex_basic_token() will read the next token from the current input stream
% and leave a value in yylval to show what was found. It does not handle
% the word "comment", nor does it consolidate things like ':' followed by
% '=' into ':='. Those steps are left to yylex(). But lex_basic_token()
% does recognize the quote prefix, as in '(lisp expression).  The return
% value is numeric for single-character tokens, but otherwise a descriptive
% symbol.

% Some people would consider the Lisp dialect that I am using here to be
% significantly flawed, in that I need to build symbols, numbers and
% strings up as lists, and then use COMPRESS to make the real objects. The
% CONS operations involved can be seen as an overhead, and going back to
% something like the VERY old-fashioned clearbuff/pack/boffo world might
% avoid that.

symbolic procedure lex_basic_token();
  begin
    scalar r, w;
% First skip over whitespace. Note that at some stage in the future RLISP
% may want to make newlines significant and partially equivalent to
% semicolons, but that is not supported at present.
    while lex_char = '!  or lex_char = !$eol!$ or
          (lex_char = '!% and <<
             while not (lex_char = !$eol!$ or lex_char = !$eof!$) do
                yyreadch();
             t >>) do yyreadch();
% Symbols start with a letter or an escaped character and continue with
% letters, digits, underscores and escapes.
    if liter lex_char or
       (lex_char = '!! and begin
% If both !*raise and !*lower were FLUID rather than GLOBAL I could
% just rebind them here, and that would have the extra benefit that if
% some exception led to an error exit from within yyreadch they would
% end up restored. However the Standard Lisp Report says that !*raise must
% be global, and PSL follows that.
          scalar raise, lower;      % Save !*raise & !*lower to avoid ..
          raise := !*raise;
          lower := !*lower;
          !*raise := !*lower := nil;
          r := lex_char . r;        % .. case folding when the next ..
          yyreadch();               % character is read.
          !*raise := raise;
          !*lower := lower;
          return (w := t) end) then <<
      r := lex_char. r;
      while liter(yyreadch()) or
            digit lex_char or
            lex_char = '!_ or
            (lex_char = '!! and begin
               scalar raise, lower;      % Save !*raise & !*lower.
               raise := !*raise;
               lower := !*lower;
               !*raise := !*lower := nil;
               r := lex_char . r;
               yyreadch();
               !*raise := raise;
               !*lower := lower;
               return (w := t) end) do
        r := lex_char . r;
% If there was a '!' in the word I will never treat it as a keyword.
% The intern here is for the benefit of PSL.
      yylval := intern compress reversip r;
      if not w and yylval = 'eof then return 0; % Special fudge for now
      return if w then '!:symbol else '!:symbol_or_keyword >>
% Numbers are either integers or floats. A floating point number is
% indicated by either a point "." or an exponent marker "e". In the code
% here I keep a flag (in w) to indicate if I had a floating or integer
% value, but in the end I ignore this and hand back the lexical category
% :number in both cases.
    else if digit lex_char then <<
      r := list lex_char;
      while digit (yyreadch()) do r := lex_char . r;
      if lex_char = '!. then <<
        w := t;       % Flag to indicate floating point
        r := lex_char . r;
        while digit (yyreadch()) do r := lex_char . r >>;
% I permit the user to write the exponent marker in either case.
      if lex_char = '!e or lex_char = '!E then <<
% If the input as 1234E56 I expand it as 1234.0E56
        if not w then r := '!0 . '!. . r;
        w := t;
        r := '!e . r;
        yyreadch();
        if lex_char = '!+ or lex_char = '!- then <<
          r := lex_char . r;
          yyreadch() >>;
% If there is no digit written after "E" I insert a zero. Thus overall the
% input 17E gets treated as 17.0E0
        if not digit lex_char then r := '!0 . r
        else <<
          r := lex_char . r;
          while digit (yyreadch()) do r := lex_char . r >> >>;
      yylval := compress reversip r;
      return '!:number >>
% Strings are enclosed in double-quotes, and "abc""def" is a string with
% a double-quote mark within it. Note no case folding on characters in a
% string.
    else if lex_char = '!" then <<
      begin
        scalar raise, lower;      % Save !*raise & !*lower.
        raise := !*raise;
        lower := !*lower;
        !*raise := !*lower := nil;
        repeat <<
          r := lex_char . r;
          while not ((yyreadch()) = '!") do r := lex_char . r;
          r := lex_char . r;
          yyreadch() >> until not (lex_char = '!");
        !*raise := raise;
        !*lower := lower;
      end;
      yylval := compress reversip r;
      return '!:string >>
% "'" and "`"(backquote) introduce Lisp syntax S-expressions
    else if lex_char = '!' then <<
      yyreadch();
      read_s_expression();
      yylval := list('quote, yylval);
      return '!:list >>
    else if lex_char = '!` then <<
      yyreadch();
      read_s_expression();
      yylval := list('backquote, yylval);
      return '!:list >>
    else <<
      yylval := lex_char;
% I take special notice of end of file, since it is fairly drastic.
% In particular I do not attempt to advance lex_char beyond it. So I do
% TWO things here: I avoid advancing the input, and I return the code 0
% as an end-of-file indication.
      if yylval = !$eof!$ then return 0
      else <<
        yyreadch();
        return char!-code yylval >> >>
  end;

%
% I use a hand-written recursive descent parser for Lisp S-expressions
% mainly because the syntax involved is so VERY simple. A rough sketch of
% the syntax required is given here, but in reality (in part because I do
% not want to have to report syntax errors) I implement a more liberal
% syntax, especially as it relates to dotted-pair notation. This of course
% is one of the natural dangers in using recursive descent... the syntax
% actually parsed is only properly defined by direct reference to the code.
%

% s_tail      =   ")" |
%                 "." s_expr ")" |
%                 s_expr s_tail;
% 
% s_vectail   =   "]" |
%                 s_expr s_vectail;
% 
% s_expr      =   symbol |
%                 number |
%                 string |
%                 "(" s_tail |
%                 "[" s_vectail |
%                 "'" s_expr |
%                 "`" s_expr |
%                 "," s_expr |
%                 ",@" s_expr;

dot_char     := char!-code '!.;
rpar_char    := char!-code '!);
rsquare_char := char!-code '!];

symbolic procedure read_s_expression();
 <<
% At the start of an S-expression I want to check for the characters
% "(", "[" and ",". Thus I need to skip whitespace.
    while lex_char = '!  or lex_char = '!$eol!$ do yyreadch();
    if lex_char = '!( then begin
      scalar r, w, w1;
      yyreadch();
      w := read_s_expression();
      while not (w = rpar_char or w = dot_char or w = 0) do <<
        r := yylval . r;
% Note that at the end of the list read_s_expression() will read the ")"
% as a token.
        w := read_s_expression() >>;
      if not (w = dot_char) then yylval := reversip r
      else <<
        read_s_expression();  % Thing after the "."
        w := yylval;
% Reverse the list putting a dotted item on the end.
        while r do <<
          w1 := cdr r;
          rplacd(r, w);
          w := r;
          r := w1 >>;
        yylval := w;
        while lex_char = '!  or lex_char = '!$eol!$ do
            yyreadch();
% When I find a ")" I do not read beyond it immediately, but reset lex_char
% to whitespace. This may help prevent unwanted hangups in interactive use.
        if lex_char = '!) then lex_char := '!   % turn ')' into a blank.
        else yyerror "Syntax error with '.' notation in a list" >>;
      return '!:list end
% "[" introduces a simple vector.
    else if lex_char = '![ then begin
      scalar r, w, w1;
      yyreadch();
      w := read_s_expression();
      w1 := -1;
      while not (w = rsquare_char or w = 0) do <<
        r := yylval . r;
        w1 := w1 + 1;
        w := read_s_expression() >>;
% Create a vector of the correct size and copy information into it.
      w := mkvect w1;
      r := reversip r;
      w1 := 0;
      while r do <<
        putv(w, w1, car r);
        w1 := w1 + 1;
        r := cdr r >>;
      yylval := w;
      return '!:list end
% I spot "," and ",@" here, and should wonder if I should (a) police that
% they are only expected to make sense within the scope of a "`" and (b)
% whether I ought to expand them in terms of LIST, CONS, APPEND etc here.
% For now I just hand back markers that show where they occured.
    else if lex_char = '!, then <<
      yyreadch();
      if lex_char = '!@ then <<
        yyreadch();
        read_s_expression();
        yylval := list('!,!@, yylval) >>
      else <<
        read_s_expresssion();
        yylval := list('!,, yylval) >>;
      'list >>
% Care with ")" and "]" not to read ahead further than is essential.
    else if lex_char = '!) or lex_char = '!] or lex_char = '!. then <<
      yylval := lex_char;
      lex_char := '! ;
      char!-code yylval >>      
% In most cases (including "'" and "`") I just hand down to read a token.
% This covers the cases of symbols, numbers and strings.
    else lex_basic_token() >>;


endmodule;

end;
