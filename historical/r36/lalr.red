
symbolic;
spool "lalr.log";
on comp, backtrace;
unglobal '(!*raise);
fluid '(!*raise);

%=============================================================================
% The file provides parser support for Lisp. The file contains three
% major sections.  The first is a lexical analyser, which has been
% coded to support RLISP and Standard Lisp. Its interface is modelled after
% the one used with the lex/yacc combination commonly used with Unix.
%
% The second section is the generic part of an LR parser. It requires
% tables to tell it what actions to take, and calls the lexical analyser to
% obtain tokens.
%
% The final part is an LALR(1) parser generator, which can take the
% specification of a grammar and construct tables that direct the
% generic parser skeleton.
%
%=============================================================================

%
% This is a lexical anaylser for use with RLISP. Its interface is
% styles after the one needed by yacc, in that it exports a function
% called yylex() that returns as a value a numeric category code, but
% sets a variable yylval to hold further information about the token
% just parsed. Single character objects are coded as their (ASCII?) code
% [leaving this code non-portable to machines with other encodings?].
% Other things must have been given 'lex_code properties indicate the
% associated category code.  This lexer handles ' and ` as special prefix
% characters that introduce Lisp-stype s-expressions. and it knows about
% RLISP-style comments and a few diphthongs. It also supports some
% simple preprocessor directives.
%
%                                              Arthur Norman.  April 1995


fluid '(!*raise !*lower !*echo);
global '(lex_char yylval last64 last64p which_line);

% I keep a circular buffer with the last 64 characters that have been
% read. Initially the buffer contains NILs rather than characters, so I can
% tell when it is only partially filled. 

smacro procedure yyreadch();
 << last64p := last64p + 1;
    if last64p = 64 then last64p := 0;
    lex_char := readch();
    if lex_char = !$eol!$ then which_line := which_line + 1;
    putv(last64, last64p, lex_char);
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
       if c = !$eof!$ then princ "<EOF>"
       else if not (c = nil) then princ c >>;
    if not (c = !$eol!$) then terpri()
  end;

% Before a succession of calls to yylex() it is necessary to
% ensure that lex_char is set suitably and that the circular buffer
% used to store characters for error messages is ready for use.

symbolic procedure start_parser();
 << last64 := mkvect 64;
    last64p := 0;
    which_line := 1;
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
% the condtion will be read using RLISPs own list-reader there could be
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
% expected that this will only be needed in rather curious cases, for instance
% to set system-specific options for a compiler.
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
%                Q);
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
                yylval := nil;
                w := lex_skipping(w, nil) >>
            else if yylval eq '!#endif then w := lex_basic_token()
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
% the next "!#else", "!#elif t" or "!endif").

symbolic procedure lex_conditional x;
  begin
    scalar w;
    w := lex_basic_token();
    x := errorset(x, nil, nil);
    if errorp x or null car x then return lex_skipping(w, nil)
    else return w
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


% lex_basic_token() will read the next token from the current input stream and
% leave a value in yylval to show what was found. It does not handle the
% word "comment", nor does it consolidate things like ':' followed by '=' into
% ':='. Those steps are left to yylex(). But lex_basic_token() does recognize 
% the quote prefix, as in '(lisp expression).  The return value is numeric
% for single-character tokens, but otherwise a descriptive symbol.

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
          scalar !*raise, !*lower;  % Rebind !*raise & !*lower to avoid..
          r := lex_char . r;      % case folding when the next character..
          yyreadch();   % is read.
          return (w := t) end) then <<
      r := lex_char. r;
      while liter(yyreadch()) or
            digit lex_char or
            lex_char = '!_ or
            (lex_char = '!! and begin
               scalar !*raise, !*lower;
               r := lex_char . r;
               yyreadch();
               return (w := t) end) do
        r := lex_char . r;
% If there was a '!' in the word I will never treat it as a keyword.
      yylval := compress reversip r;
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
        scalar !*raise, !*lower;
        repeat <<
          r := lex_char . r;
          while not ((yyreadch()) = '!") do r := lex_char . r;
          r := lex_char . r;
          yyreadch() >> until not (lex_char = '!");
      end;
      yylval := compress reversip r;
      return '!:string >>
% "'" and "`" introduce Lisp syntax S-expressions
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

global '(dot_char rpar_char rsquare_char);

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
      if not w = dot_char then yylval := reversip r
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
% I will be somewhat liberal about syntactic problems with dotted pair
% notation, since it is unclear how I can usefully report or repair errors.
        while lex_char = '!  or lex_char = '!$eol!$ do
            yyreadch();
% When I find a ")" I do not read beyond it immediately, but reset lex_char
% to whitespace. This may help prevent unwanted hangups in interactive use.
        if lex_char = '!) then lex_char := '!  >>;
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



%=============================================================================

% Here I have a general-purpose LR(1) parser skeleton.  This needs to
% have a source of tokens, and some tables that will direct its actions.

% The format of the tables required by this code will be a little curious,
% mainly because they represent some attempt to compact the information that
% is needed. Note that the CSL functions mkvect16, putv16, getv16 are
% somewhat similar to the regular mkvect, putv and getv, but may be used
% if the vector contents will always be 16-bit fixnums.

global '(!*verbose);

!*verbose := t;      % How much will the parset-generator print?

global '(goto_index goto_old_state goto_new_state);

% For each terminal I have a pointer (stored in goto_index) into
% a pair of vectors, goto_old_state and goto_new_state. The first of these
% holds states that I might be in, and the second holds the ones I must
% move into after a reduction has been performed. In the goto_old_state
% table the value "-1" is taken to match any state that I am attempting
% to look up. Thus it can be used to terminate a segment of the table. I am
% entitled to let undefined locations in the goto table respond with
% any value that just happens.

smacro procedure get_goto(state, non_terminal);
 << w1 := getv16(goto_index, non_terminal);
    while not (((w2 := getv16(goto_old_state, w1)) = -1) or
               w2 = state) do w1 := w1 + 1;
    getv16(goto_new_state, w1) >>;

global '(action_index, action_terminal action_result);

% In a rather similar way, actions are found via an association-list
% like look-up in a table. In this table a strictly positive number n stands
% for (SHIFT n) [observe that if I reserve zero as the number of the
% initial state of my augmented grammar I can never need to shift into
% state 0].  The value 0 in the table represents ACCEPT. This leaves
% nagative values to cover reductions and error cases.

smacro procedure get_action(state, terminal);
 << w1 := getv16(action_index, state);
    while not (((w2 := getv16(action_terminal, w1)) = -1) or
               w2 = terminal) do w1 := w1 + 1;
    getv(action_result, w1) >>;

global '(action_first_error action_error_messages);

global '(action_fn action_A action_n);

symbolic procedure yyparse();
  begin
    scalar sym_stack, state_stack, next_input, w, w1, w2;
    state_stack := list 0;  % Note that state 0 must be the initial one.
    start_parser();
    next_input := yylex();
    while not (w := get_action(car state_stack, next_input)) = 0 do
        if w > 0 then <<
            sym_stack := next_input . sym_stack;
            state_stack := cadr w . state_stack;
            next_input := yylex() >>
        else begin   
            scalar A, n, action;
            w := - (w + 1);
            if w < action_first_error then <<
                action := getv(action_fn, w);
                n := getv8(action_n, w);
                A := getv16(action_A, w);
% I am now reducing by "A -> beta { action() }" where beta has n items
                w := nil;
                for i := 1:n do <<
                    w := car sym_stack . w;
                    sym_stack := cdr sym_stack;
                    state_stack := cdr state_stack >>;
                w := reversip w;
                if action then w := apply1(action, w)
                else w := A . w;
                sym_stack := w . sym_stack;
                state_stack := get_goto(car state_stack, A) >>
            else <<
                w := w - action_first_error;
                yyerror getv(action_error_messages, w);
% The next activity must result in the loop ending...
                state_stack := list 0;
                sym_stack := '(error);
                next_input := 0 >>
        end;
    return car sym_stack
  end;

%=============================================================================
%
% A grammar is represented as a list of rules. A rule
%      sym : x y z { p q r }
%          | x y z { p q r }
%          ;
% maps onto the list
%      (sym   ((x y z) p q r)
%             ((x y z) p q r))
% and items on the right hand side can be symbols or strings. Strings
% stand for terminals. Symbols that are mentioned on a left hand side of
% a production are non-terminals, others are considered to be terminals
% supported by the lexer.
%
% ***** I am still working out what to do with the "semantic actions".

global '(terminals non_terminals symbols goto_cache action_map);

smacro procedure lalr_productions x;
    get(x, 'produces);

smacro procedure lalr_set_productions(x, y);
    put(x, 'produces, y);

symbolic procedure lalr_prin_symbol x;
    if x = 0 then princ "$"
    else if x = nil then princ "<empty>"
    else if x = '!. then princ "."
    else if numberp x and rassoc(x, terminals) then
        prin car rassoc(x, terminals)
    else if stringp x then prin x
    else for each c in explode2uc x do princ c;

symbolic procedure lalr_display_symbols();
  begin
    princ "Terminal symbols are:"; terpri();
    for each x in terminals do <<
        princ " "; prin car x;
        princ ":"; prin cdr x >>;
    terpri();
    princ "Non-terminal symbols are:"; terpri();
    for each x in non_terminals do begin
       scalar w;
       princ "["; prin get(x, 'non_terminal_code); princ "]";
       lalr_prin_symbol x;
       w := ":";
       for each y in lalr_productions x do <<
           ttab 20; princ w; w := "|";
           for each z in car y do << princ " "; lalr_prin_symbol z >>;
           if posn() > 48 then terpri();
           ttab 48;
           princ "{";
           for each z in cdr y do << princ " "; prin z >>;
           princ " }";
           terpri() >>;
       ttab 20;
       princ ";";
       terpri() end;
    terpri();
  end;

symbolic procedure lalr_print_action_map();
  begin
    princ "Action map:"; terpri();
    for each x in action_map do <<
        prin cdr x; princ ":"; ttab 12; prin car x; terpri() >>
  end;

symbolic procedure lalr_set_grammar g;
  begin
    scalar name, vals, tnum, w;
    terminals := non_terminals := symbols := nil;
    tnum := 0;
% I will start by augmenting the grammar with an initial production...
    g := list('s!', list list caar g) . g;
    for each x in g do <<
        name := car x; vals := cdr x;
        if name member non_terminals then
            vals := append(vals, lalr_productions name)
        else non_terminals := name . non_terminals;
        for each vv in cdr x do
          for each v in car vv do <<
            if stringp v or numberp v then <<
                if not assoc(v, terminals) then
                    terminals := (v . (tnum := tnum+1)) . terminals >>
            else if not (v member symbols) then symbols := v . symbols >>;
        lalr_set_productions(name, vals) >>;
    for each name in non_terminals do symbols := delete(name, symbols);
    for each v in symbols do terminals := (v . (tnum := tnum+1)) . terminals;
% I reverse the list of non-terminals here so that the starting symbol
% remains as the first item.
    non_terminals := reversip non_terminals;
    tnum := -1;
    for each v in non_terminals do
        put(v, 'non_terminal_code, tnum := tnum+1);
    symbols := append(non_terminals, for each x in terminals collect cdr x);
    goto_cache := mkhash(length non_terminals, 1, 1.5);
    if !*verbose then lalr_display_symbols();
% Map all terminals onto numeric codes.
    for each x in non_terminals do
       lalr_set_productions(x, 
           for each y in lalr_productions x collect
               sublis(terminals, car y) . cdr y);
% Map all actions onto numeric codes, such that identical actions all have the
% same code
    action_map := nil;
    tnum := -1;
    for each x in non_terminals do
        for each a in lalr_productions x do <<
            w := assoc(cdr a, action_map);
            if null w then <<
                w := cdr a . (tnum := tnum + 1);
                action_map := w . action_map >>;
            rplacd(a, list cdr w) >>;
    action_map := reversip action_map;
    if !*verbose then lalr_print_action_map();
    lalr_calculate_first non_terminals;
  end;

symbolic procedure lalr_clean_up();
  begin
    for each x in terminals do <<
        remprop(x, 'produces);
        remprop(x, 'lalr_first);
        remprop(x, 'non_terminal_code) >>;
    terminals := non_terminals := symbols := nil;
    goto_cache := action_map := nil
  end;

symbolic procedure lalr_action(lhs, rhs);
    cdr assoc(rhs, lalr_productions lhs);

symbolic procedure lalr_print_firsts g;
  begin
    princ "FIRST sets for each non-terminal:"; terpri();
    for each x in g do <<
        lalr_prin_symbol x;
        princ ": ";
        ttab 15;
        for each y in get(x, 'lalr_first) do <<
            princ " "; lalr_prin_symbol y >>;
        terpri() >>
  end;

symbolic procedure lalr_calculate_first g;
  begin
    scalar w, y, z, done;
    for each x in g do
        if assoc(nil, lalr_productions x) then put(x, 'lalr_first, '(nil));
    repeat <<
        done := nil;
        for each x in g do <<
            z := get(x, 'lalr_first);
            for each y1 in lalr_productions x do <<
                y := car y1;
                while y and
                      not numberp y
                      and (nil member (w := get(car y, 'lalr_first))) do <<
                    z := union(w, z);
                    y := cdr y >>;
                if null y then nil
                else if numberp car y then z := union(list car y, z)
                else z := union(get(car y, 'lalr_first), z) >>;
            if not (z = get(x, 'lalr_first)) then done := t;
            put(x, 'lalr_first, z) >>
    >> until not done;
    if !*verbose then lalr_print_firsts g;
    return nil
  end;

symbolic procedure lalr_first l;
  begin
    scalar r, w;
    while l and
          not numberp car l and
          (nil member (w := get(car l, 'lalr_first))) do <<
        r := union(delete(nil, w), r);
        l := cdr l >>;
    if null l then r := nil . r
    else if numberp car l then r := union(list car l, r)
    else r := union(w, r);
    return r
  end;


% The next few procedures are as documented in Figure 4.38 of Red Dragon

symbolic procedure lalr_print_items(heading, cc);
  begin
    princ heading;
    terpri();
    for each y in cc do <<
        princ "Item number "; prin cdr y; terpri();
        for each x in sort(car y, function orderp) do <<
            lalr_prin_symbol caar x; princ " ->";
            for each y in cdar x do << princ " "; lalr_prin_symbol y >>;
            princ "  :  ";
            lalr_prin_symbol cadr x;
            terpri() >>;
        for each x in hashcontents goto_cache do
          for each xx in cdr x do
            if car xx = cdr y then <<
                ttab 10; lalr_prin_symbol car x;
                princ " GOTO state "; prin cdr xx; terpri() >> >>
  end;

symbolic procedure lalr_items g;
  begin
    scalar c, val, done, w, w1, w2, n;
    val := lalr_productions 's!';
    if cdr val then error(0, "Starting state must only reduce to one thing")
    else val := caar val;
    n := 0;
    c := list (lalr_closure list list(('s!' . '!. . val), 0) . n);
    repeat <<
        done := nil;
        for each i in c do
            for each x in symbols do
                if w := lalr_goto(car i, x) then <<
                     w1 := assoc(w, c);
                     if w1 then <<
                         w2 := gethash(x, goto_cache);
                         if not assoc(cdr i, w2) then
                             puthash(x, goto_cache, (cdr i . cdr w1) . w2) >>
                     else <<
                         c := (w . (n := n + 1)) . c;
                         puthash(x, goto_cache,
                                    (cdr i . n) . gethash(x, goto_cache));
                         done := t >> >>
    >> until not done;
    c := reversip c;   % So that item numbers come out in nicer order.
    if !*verbose then lalr_print_items("LR(1) Items:", c);
    return c
  end;

symbolic procedure lalr_closure i;
  begin
    scalar pending, a, rule, tail, done, ff, w;
    pending := i;
    while pending do <<
        ff := car pending;  % [(A -> alpha . B beta), a]
        pending := cdr pending;
        rule := car ff; a := cadr ff; tail := cdr ('!. member rule);
        if tail and not numberp car tail then <<
            ff := lalr_first append(cdr tail, list a);
            for each p in lalr_productions car tail do
                for each b in ff do <<
                    w := list(car tail . '!. . car p, b);
% It might be better to store items as hash tables, since then the
% member-check here would be much faster.
                    if not (w member i) then <<
                        i := w . i;
                        pending := w . pending >> >> >> >>;
    return i
  end;

symbolic procedure lalr_move_dot(z, x);
  begin
    scalar r;
    while not (car z = '!.) do <<
        r := car z . r;
        z := cdr z >>;
    z := cdr z;
    if not (z and car z = x) then return nil;
    z := car z . '!. . cdr z;
    while r do <<
        z := car r . z;
        r := cdr r >>;
    return z
  end;

symbolic procedure lalr_goto(i, x);
  begin
    scalar j, w;
    for each z in i do <<
        w := lalr_move_dot(car z, x);
        if w then j := list(w, cadr z) . j >>;
    return lalr_closure j
  end;

symbolic procedure lalr_cached_goto(i, x);
    cdr assoc(i, gethash(x, goto_cache));

% Next part of Algorithm 4.11 from the Red Dragon

symbolic procedure lalr_remove_duplicates x;
  begin
    scalar r;
    if null x then return nil;
    x := sort(x, function orderp);
    r := list car x;
    x := cdr x;
    while x do <<
        if not (car x = car r) then r := car x . r;
        x := cdr x >>;
    return r
  end;

symbolic procedure lalr_core i;
    lalr_remove_duplicates for each x in car i collect car x;

symbolic procedure lalr_same_core(i1, i2);
    lalr_core i1 = lalr_core i2;

% cc is a list of items, while i is a single item. If cc already contains
% an item with the same core as I then merge i into that, and adjust any
% goto records either out of or into i to refer now to the thing merged
% with.

fluid '(renamings);

symbolic procedure lalr_insert_core(i, cc);
   if null cc then list i
   else if lalr_same_core(i, car cc) then <<
       renamings := (i . cdar cc) . renamings;
       (union(car i, caar cc) . cdar cc) . cdr cc >>
   else car cc . lalr_insert_core(i, cdr cc);

symbolic procedure lalr_rename_gotos();
  begin
    scalar w;
    for each x in non_terminals do <<
        w := sublis(renamings, gethash(x, goto_cache));
        puthash(x, goto_cache, lalr_remove_duplicates w) >>
  end;

% Part of Algorithm 4.10 of the Red Dragon

symbolic procedure lalr_print_actions action_table;
  begin
    scalar w;
    princ "Actions:"; terpri();
    for each x in action_table do
      for each xx in cdr x do <<
        prin car x;  ttab 20;
        lalr_prin_symbol car xx; ttab 40;
        w := cadr xx;
        if eqcar(w, 'reduce) then <<
            princ "reduce ";
            lalr_prin_symbol caadr w;
            princ " ->";
            for each v in cdadr w do << princ " "; lalr_prin_symbol v >>;
            princ " {";
            for each v in caddr w do << princ " "; prin v >>;
            princ " }";
            terpri() >>
        else << prin w; terpri() >> >>
  end;

symbolic procedure lalr_make_actions c;
  begin
    scalar action_table, aa, j, w;
    for each i in c do <<
        aa := nil;
        for each r in car i do <<
            w := cdr ('!. member cdar r);
            if w and numberp car w then <<
                j := lalr_cached_goto(cdr i, car w);
                aa := list(car w, list('shift, j)) . aa >>
            else if null w and not (caar r = 's!') then <<
                w := reverse cdr reverse car r;
                aa :=
                    list(cadr r, list('reduce, w, lalr_action(car w, cdr w))) .
                    aa >>
            else if null w and caar r = 's!' then
                aa := list(0, 'accept) . aa >>;
        action_table := (cdr i . lalr_remove_duplicates aa) . action_table >>;
    action_index := mkvect16 caar action_table;
    action_table := reversip action_table;
    if !*verbose then lalr_print_actions action_table;
    j := 0; w := nil;
    for each x in action_table do <<
        putv16(action_index, car x, j);
        aa := lalr_lay_out_actions cdr x;
        while aa do <<
            w := (0 . 0) . w;
            j := j + 1 >> >>;
    action_terminal := mkvect16 j;
    action_result := mkvect16 j;
    while j > 0 do <<
        j := j - 1;
        putv16(action_terminal, j, caar w);
        putv16(action_result, j, cdar w);
        w := cdr w >>
  end;

symbolic procedure lalr_most_common_dest p;
  begin
    scalar r, w;
    for each x in p do
        if (w := assoc(cdr x, r)) then rplacd(w, cdr w + 1)
        else r := (cdr x . 1) . r;
    w := car r;
    for each x in cdr r do if cdr x > cdr w then w := x;
    return car w
  end;

symbolic procedure lalr_make_gotos();
  begin
    scalar p, r1, w, r;
    p := 0;
    for each x in hashcontents goto_cache do
        if not numberp car x then <<
            if !*verbose then
                for each xx in cdr x do <<
                    prin car xx; ttab 10; lalr_prin_symbol car x;
                    princ " GOTO state "; prin cdr xx; terpri() >>;
            r1 := (get(car x, 'non_terminal_code) . p) . r1;
            if cdr x then <<
                w := lalr_most_common_dest cdr x;
                for each xx in cdr x do if not (cdr xx = w) then <<
                    r := xx . r;
                    p := p + 1 >>;
                r := ((-1) . w) . r;
                p := p + 1 >> >>;
    goto_index := mkvect16 length non_terminals;
    goto_old_state := mkvect16 p;
    goto_new_state := mkvect16 p;
    for each x in r1 do putv16(goto_index, car x, cdr x);
    while p > 0 do <<
        p := p - 1;
        putv16(goto_old_state, p, caar r);
        putv16(goto_new_state, p, cdar r);
        r := cdr r >>;
    princ "goto_index: ";     print goto_index;
    princ "goto_old_state: "; print goto_old_state;
    princ "goto_new_state: "; print goto_new_state
  end;

% A main driver function that performs all the steps involved
% in building parse tables for a given grammar.

symbolic procedure lalr_construct_parser g;
  begin
    scalar c, cc, renamings;
    lalr_set_grammar g;
    c := lalr_items non_terminals;
    renamings := nil;
    for each i in c do cc := lalr_insert_core(i, cc);
    lalr_rename_gotos();
    if !*verbose then lalr_print_items("Merged Items:", cc);
    lalr_make_actions cc;
    lalr_make_gotos();
    lalr_clean_up()
  end;

%=============================================================================

% Now some test cases

on time;

% Here I set up a sample grammar
%    S' -> S
%    S  -> CC      { A1 }
%    C  -> cC      { A2 }
%        | d       { A3 }
% (example 4.42 from Aho, Sethi and Ullman's Red Dragon book, with
%  some dummy semantic actions added. Note that I do not need to insert
% the production S' -> S for myself since the analysis code will
% augment my grammar with it for me anyway.

grammar := '((S  ((C C) A1))
             (C  (("c" C) A2)
                 (("d") A3))
            );

lalr_construct_parser grammar;

% Example 4.46 from the Red Dragon

g4_46 := '((S   ((L "=" R) a1)
                ((R)       a2))
           (L   (("*" R)   a3)
                ((id)      a4))
           (R   ((L)       a5)));

lalr_construct_parser g4_46;


% Now a much more complicated grammar - one that recognizes the syntax of
% RLISP.

rlisp_grammar := '(

(command         ((  cmnd sep ) action)
                 ((  end sep ) action)
                 ((  command cmnd sep ) action)
                 ((  command end sep ) action)
)


(sep             ((  ";" ) action)
                 ((  "$" ) action)
)


(proc_type       ((  symbolic ) action)
                 ((  algebraic ) action)
)


(proc_qual       ((  expr ) action)
                 ((  macro ) action)
                 ((  smacro ) action)
)


(sym_list        ((  ")" ) action)
                 ((  "," symbol sym_list ) action)
)


(infix           ((  setq ) action)
                 ((  or ) action)
                 ((  and ) action)
                 ((  member ) action)
                 ((  memq ) action)
                 ((  "=" ) action)
                 ((  neq ) action)
                 ((  eq ) action)
                 ((  geq ) action)
                 ((  ">" ) action)
                 ((  leq ) action)
                 ((  "<" ) action)
                 ((  freeof ) action)
                 ((  "+" ) action)
                 ((  "-" ) action)
                 ((  "*" ) action)
                 ((  "/" ) action)
                 ((  "^" ) action)
                 ((  "." ) action)
)

(prefix          ((  not ) action)
                 ((  "+" ) action)
                 ((  "-" ) action)
)


(proc_head       ((  symbol ) action)
                 ((  symbol symbol ) action)
                 ((  symbol "(" ")" ) action)
                 ((  symbol "(" symbol sym_list ) action)
                 ((  prefix symbol ) action)
                 ((  symbol infix symbol ) action)
)


(proc_def        ((  procedure proc_head sep cmnd ) action)
                 ((  proc_type procedure proc_head sep cmnd ) action)
                 ((  proc_qual procedure proc_head sep cmnd ) action)
                 ((  proc_type proc_qual procedure proc_head sep cmnd ) action)
)


(rlistat         ((  rlistat ) action)
                 ((  in ) action)
                 ((  on ) action)
)


(rltail          ((  expr ) action)
                 ((  expr "," rltail ) action)
)


(cmnd            ((  expr ) action)
                 ((  rlistat rltail ) action)
)


(if_stmt         ((  if expr then cmnd else cmnd ) action)
                 ((  if expr then cmnd ) action)
)


(for_update      ((  ":" expr ) action)
                 ((  step expr until expr ) action)
)


(for_action      ((  do ) action)
                 ((  sum ) action)
                 ((  collect ) action)
)


(for_inon        ((  in ) action)
                 ((  on ) action)
)


(for_stmt        ((  for symbol setq expr for_update for_action cmnd ) action)
                 ((  for each symbol for_inon expr for_action cmnd ) action)
                 ((  foreach symbol for_inon expr for_action cmnd ) action)
)


(while_stmt      ((  while expr do cmnd ) action)
)


(repeat_stmt     ((  repeat cmnd until expr ) action)
)


(return_stmt     ((  return ) action)
                 ((  return expr ) action)
)


(goto_stmt       ((  goto symbol ) action)
                 ((  go symbol ) action)
                 ((  go to symbol ) action)
)


(group_tail      ((  rsect ) action)
                 ((  sep rsect ) action)
                 ((  sep cmnd group_tail ) action)
)


(group_expr      ((  lsect cmnd group_tail ) action)
)


(scalar_tail     ((  sep ) action)
                 ((  "," symbol scalar_tail ) action)
                 ((  "," integer scalar_tail ) action)
)


(scalar_def      ((  scalar symbol scalar_tail ) action)
                 ((  integer symbol scalar_tail ) action)
)


(scalar_defs     ((  scalar_def ) action)
                 ((  scalar_defs scalar_def ) action)
)


(block_tail      ((  end ) action)
                 ((  cmnd end ) action)
                 ((  symbol ":" block_tail ) action)
                 ((  cmnd sep block_tail ) action)
                 ((  sep block_tail ) action)
)

(block_expr      ((  begin scalar_defs block_tail ) action)
                 ((  begin block_tail ) action)
)


(lambda_vars     ((  sep ) action)
                 ((  "," symbol lambda_vars ) action)
)


(lambda_expr     ((  lambda symbol lambda_vars cmnd ) action)
                 ((  lambda "(" ")" sep cmnd ) action)
                 ((  lambda "(" symbol sym_list sep cmnd ) action)
)


(expr            ((  rx0 ) action)
                 ((  lx0 ) action)
)


(rx0             ((  lx0 where symbol "=" rx1 ) action)
                 ((  rx1 ) action)
)


(lx0             ((  lx0 where symbol "=" lx1 ) action)
                 ((  lx1 ) action)
)


(rx1             ((  lx2 setq rx1 ) action)
                 ((  rx2 ) action)
)


(lx1             ((  lx2 setq lx1 ) action)
                 ((  lx2 ) action)
)


(rx2tail         ((  rx3 ) action)
                 ((  lx3 or rx2tail ) action)
)

(rx2             ((  lx3 or rx2tail ) action)
                 ((  rx3 ) action)
)


(lx2tail         ((  lx3 ) action)
                 ((  lx3 or lx2tail ) action)
)

(lx2             ((  lx3 or lx2tail ) action)
                 ((  lx3 ) action)
)


(rx3tail         ((  rx4 ) action)
                 ((  lx4 and rx3tail ) action)
)

(rx3             ((  lx4 and rx3tail ) action)
                 ((  rx4 ) action)
)


(lx3tail         ((  lx4 ) action)
                 ((  lx4 and lx3tail ) action)
)

(lx3             ((  lx4 and lx3tail ) action)
                 ((  lx4 ) action)
)


(rx4             ((  not rx4 ) action)
                 ((  rx5 ) action)
)


(lx4             ((  not lx4 ) action)
                 ((  lx5 ) action)
)


(rx5             ((  lx6 member ry6 ) action)
                 ((  lx6 memq ry6 ) action)
                 ((  lx6 "=" ry6 ) action)
                 ((  lx6 neq ry6 ) action)
                 ((  lx6 eq ry6 ) action)
                 ((  lx6 geq ry6 ) action)
                 ((  lx6 ">" ry6 ) action)
                 ((  lx6 leq ry6 ) action)
                 ((  lx6 "<" ry6 ) action)
                 ((  lx6 freeof ry6 ) action)
                 ((  rx6 ) action)
)


(lx5             ((  lx6 member ly6 ) action)
                 ((  lx6 memq ly6 ) action)
                 ((  lx6 "=" ly6 ) action)
                 ((  lx6 neq ly6 ) action)
                 ((  lx6 eq ly6 ) action)
                 ((  lx6 geq ly6 ) action)
                 ((  lx6 ">" ly6 ) action)
                 ((  lx6 leq ly6 ) action)
                 ((  lx6 "<" ly6 ) action)
                 ((  lx6 freeof ly6 ) action)
                 ((  lx6 ) action)
)


(ry6             ((  not ry6 ) action)
                 ((  rx6 ) action)
)


(ly6             ((  not ly6 ) action)
                 ((  lx6 ) action)
)


(rx6tail         ((  ry6a ) action)
                 ((  ly6a "+" rx6tail ) action)
)

(rx6             ((  lx6a "+" rx6tail ) action)
                 ((  rx6a ) action)
)


(lx6tail         ((  ly6a ) action)
                 ((  ly6a "+" lx6tail ) action)
)

(lx6             ((  lx6a "+" lx6tail ) action)
                 ((  lx6a ) action)
)


(ry6a            ((  not ry6a ) action)
                 ((  rx6a ) action)
)


(rx6a            ((  lx6a "-" ry7 ) action)
                 ((  rx7 ) action)
)


(ly6a            ((  not ly6a ) action)
                 ((  lx6a ) action)
)


(lx6a            ((  lx6a "-" ly7 ) action)
                 ((  lx7 ) action)
)


(ry7             ((  not ry7 ) action)
                 ((  rx7 ) action)
)


(rx7             ((  "+" ry7 ) action)
                 ((  "-" ry7 ) action)
                 ((  rx8 ) action)
)


(ly7             ((  not ly7 ) action)
                 ((  lx7 ) action)
)


(lx7             ((  "+" ly7 ) action)
                 ((  "-" ly7 ) action)
                 ((  lx8 ) action)
)


(rx8tail         ((  ry9 ) action)
                 ((  ly9 "*" rx8tail ) action)
)

(rx8             ((  lx9 "*" rx8tail ) action)
                 ((  rx9 ) action)
)


(lx8tail         ((  ly9 ) action)
                 ((  ly9 "*" lx8tail ) action)
)

(lx8             ((  lx9 "*" lx8tail ) action)
                 ((  lx9 ) action)
)


(ry9             ((  not ry9 ) action)
                 ((  "+" ry9 ) action)
                 ((  "-" ry9 ) action)
                 ((  rx9 ) action)
)


(rx9             ((  lx9 "/" ry10 ) action)
                 ((  rx10 ) action)
)


(ly9             ((  not ly9 ) action)
                 ((  "+" ly9 ) action)
                 ((  "-" ly9 ) action)
                 ((  lx9 ) action)
)


(lx9             ((  lx9 "/" ly10 ) action)
                 ((  lx10 ) action)
)


(ly10            ((  not ly10 ) action)
                 ((  "+" ly10 ) action)
                 ((  "-" ly10 ) action)
                 ((  lx10 ) action)
)


(lx10            ((  lx11 "^" ly10 ) action)
                 ((  lx11 ) action)
)


(ry10            ((  not ry10 ) action)
                 ((  "+" ry10 ) action)
                 ((  "-" ry10 ) action)
                 ((  rx10 ) action)
)


(rx10            ((  lx11 "^" ry10 ) action)
                 ((  rx11 ) action)
)


(ry11            ((  not ry11 ) action)
                 ((  "+" ry11 ) action)
                 ((  "-" ry11 ) action)
                 ((  rx11 ) action)
)


(rx11            ((  x12 "." ry11 ) action)
                 ((  if_stmt ) action)
                 ((  for_stmt ) action)
                 ((  while_stmt ) action)
                 ((  repeat_stmt ) action)
                 ((  return_stmt ) action)
                 ((  goto_stmt ) action)
                 ((  lambda_expr ) action)
                 ((  proc_type ) action)
                 ((  proc_def ) action)
                 ((  endstat ) action)
)


(ly11            ((  not ly11 ) action)
                 ((  "+" ly11 ) action)
                 ((  "-" ly11 ) action)
                 ((  lx11 ) action)
)


(lx11            ((  x12 "." ly11 ) action)
                 ((  x12 ) action)
)


(arg_list        ((  expr ")" ) action)
                 ((  expr "," arg_list ) action)
)


(x12             ((  x13 "[" expr "]" ) action)
                 ((  x13 "(" ")" ) action)
                 ((  x13 "(" expr "," arg_list ) action)
                 ((  x13 x12 ) action)
                 ((  x13 ) action)
)


(x13             ((  symbol ) action)
                 ((  number ) action)
                 ((  string ) action)
                 ((  quoted ) action)
                 ((  backquoted ) action)
                 ((  group_expr ) action)
                 ((  block_expr ) action)
                 ((  "(" expr ")" ) action)
)
)$


% lalr_construct_parser rlisp_grammar;


end;

