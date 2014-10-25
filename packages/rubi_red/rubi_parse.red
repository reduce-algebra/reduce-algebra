%
% A reduce recursive descent parser that will parse Rubi rules
% and test scripts (which start off in Mathematica syntax).
%
%                                                   A C Norman, 2013

module 'rubi_parse;

fluid '(trap!-time!*);

switch trrubi;  % Make a file "testcase.red" of all the examples tried.

fluid '(mmachar);  % variable to hold next character

mmachar := '! ;    % starts off as a space character

#if (memq 'psl lispsystem!*)

fluid '(blank tab);

blank := intern int2id 32;
tab   := intern int2id 9;

symbolic procedure flush u;  % Flush a file...
  nil;

#endif 

fluid '(carriage_return);

carriage_return := intern int2id 13;

symbolic procedure isspace ch;
  ch = blank or ch = tab or ch = !$eol!$ or ch = carriage_return;

fluid '(currexpr prevline currline eofcounter line_number);
prevline := currline := nil;
currexpr := list !$eol!$;
line_number := 1;

% I will arrange to fake several blank lines at the end of any file since
% that will make finshing reading the rule before the end a bit easier for me.

fluid '(outer_level);
outer_level := t;

% This reads the next character - and keeps track of the line number. The
% most recent two lines of input are stored for display in the case of
% a parse error.

symbolic procedure next_mma_char();
  begin
    scalar r;
    r := readch();
    if eofcounter > 0 then <<
      if eofcounter > 5 then return !$eof!$;
      eofcounter := eofcounter + 1;
      return !$eol!$ >>
    else if r = !$eof!$ then <<
      currline := 'eof . currline;
      eofcounter := 1;
      return !$eol!$ >>
    else if r = !$eol!$ then <<
      currexpr := r . currexpr;
      line_number := line_number + 1;
      prevline := currline;
      currline := nil >>
    else <<
      currexpr := r . currexpr;
      currline := r . currline >>;
    return r
  end;

fluid '(mmatok !*trace_token);

!*trace_token := nil;

% Read a token. If !*trace_token is true display it (for debugging and
% tracing). The collection of tokens accepted here are intended to cover
% that subset of Mathematica notation used in Rubi.

symbolic procedure next_mma_tok();
  begin
    scalar r;
    r := next_mma_tok1();
    if !*trace_token then <<
      princ "Token: ";
      if r = !$eof!$ then printc "EOF"
      else if r = !$eol!$ then printc "EOL"
      else if r = blank then printc "BLANK"
      else if r = tab then printc "TAB"
      else if idp r and flagp(r, 'operator_like) then <<
         princ "operator """;
         princ r;
         printc """" >>
      else print r >>;
    return r;
  end;

symbolic procedure next_mma_tok1();  % read next token
  begin
    scalar w, buff, save!*raise, save!*lower;
    if mmachar = !$eof!$ then return mmatok := mmachar;
    save!*raise := !*raise;
    save!*lower := !*lower;
    !*raise := !*lower := nil; % I want case sensitive reading
    w := 0;
    while isspace mmachar do <<
      if mmachar = !$eol!$ then w := w + 1;
      mmachar := next_mma_char() >>; % skip white-space.
    if outer_level and ((w > 0 and mmachar = !$eof!$) or w > 1) then <<
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok := !$eol!$ >>;
      % fully blank line treated as significant, or newline at end of file.
    if digit mmachar then <<         % Digit, so read a number.
      while digit mmachar do <<    % Keep accepting digits.
        buff := mmachar . buff;  % push onto front of buffer.
        mmachar := next_mma_char() >>;
      if mmachar = '!. then <<  % Allow for simple floating point syntax
        buff := mmachar . buff;
        mmachar := next_mma_char();
        while digit mmachar do <<    % Keep accepting digits.
          buff := mmachar . buff;  % push onto front of buffer.
          mmachar := next_mma_char() >> >>;
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok := compress reverse buff >> % convert to a number.
    else if liter mmachar or mmachar = '!$ then <<
      % a letter, so start of a name. Well '$' starts a name too!
      if mmachar = '!$ then <<
        buff := '(!$ !!);
        mmachar := next_mma_char() >>;
      while liter mmachar or
            digit mmachar do <<    % Keep accepting letters/digits.
        buff := mmachar . buff;  % push onto front of buffer.
        mmachar := next_mma_char() >>;
      mmatok := intern compress reverse buff; % convert to a name.
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok >>
    else if mmachar = '!" then <<
      buff := nil;
      mmachar := next_mma_char();
      while not (mmachar = '!") do <<
        buff := mmachar . buff;
        if mmachar = !$eof!$ then
          syntax_error "unterminated string";
        mmachar := next_mma_char() >>;
      mmachar := next_mma_char();
      buff := reverse buff;
      mmatok := list2string buff;    % A string
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok >>
% In mathematica tokens #, ## and either of those followed by a sequence
% of digits are used with anonymous functions.
    else if mmachar = '!# then <<
      buff := list(mmachar, '!!);
      mmachar := next_mma_char();
      if mmachar = '!# then <<
        buff := mmachar . '!! . buff;
        mmachar := next_mma_char() >>;
      while digit mmachar do <<
        buff := mmachar . buff;
        mmachar := next_mma_char() >>;
      mmatok := intern compress reverse buff;
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok >>;
% Here anything that does not start with a letter or digit is treated as
% an operator. There are a rather small number of cases of two-character
% symbols that need to be allowed for. Specifically ":=", "/;", "(*", "*)"
% "&&", "||", "<=" and ">=".
    buff := mmachar;
    mmachar := next_mma_char();
    if null memq(mmachar, get(buff, 'follow_on_char)) then <<
      flag(list buff, 'operator_like);   % Ie not alphanumeric.
      !*raise := save!*raise;
      !*lower := save!*lower;
      return mmatok := buff >>;
    buff := intern compress list('!!, buff, '!!, mmachar);
    mmachar := next_mma_char();
    if (buff = '!=!= or buff = '!=!!) and mmachar = '!= then <<
% Special cases on === and =!= as 3-character operators.
      mmachar := next_mma_char();
      if buff = '!=!= then buff := '!=!=!=
      else buff := '!=!!!= >>;
% Now I will discard comments. As implemented here (* ... (* .. *) .. *)
% style comments may be nested.
    if buff = '!(!* then <<
      next_mma_tok1();
      while mmatok neq '!*!) do <<
        if mmatok = !$eof!$ then syntax_error "end of file within comment";
        next_mma_tok1() >>;
      !*raise := save!*raise;
      !*lower := save!*lower;
      return next_mma_tok1() >>;
    flag(list buff, 'operator_like);   % Ie not alphanumeric.
    !*raise := save!*raise;
    !*lower := save!*lower;
    return mmatok := buff;
  end;

flag(list(!$eol!$, !$eof!$), 'operator_like);

put('!:, 'follow_on_char, '(!=));
put('!/, 'follow_on_char, '(!;));
put('!(, 'follow_on_char, '(!*));
put('!*, 'follow_on_char, '(!)));
put('!&, 'follow_on_char, '(!&));
put('!|, 'follow_on_char, '(!|));
put('!>, 'follow_on_char, '(!=));
put('!<, 'follow_on_char, '(!=));
put('!!, 'follow_on_char, '(!=));
put('!=, 'follow_on_char, '(!= !!));
put('!_, 'follow_on_char, '(!. !'));


mmatok := nil;

% I now show the context free grammar that is used to parse everything.
% There us a slight extra complication because blank lines (shown here
% as 'eol') are treated as significant at the top level but will be ignored
% when they occur (for instance) within brackets. The grammar presented
% here has been reverse engineered so that it covers the Rubi source
% files. Hence it will not provide support for full Mathematica.

% Rules ::= 'eof'
%       |   'eol' Rules
%       |   Rule 'eol' Rules
%       |   Rule 'eof'
%
% Rule  ::= Expression
%
% Expression := E0 | Expression ';' E0
%
% E0        ::= E1 | E0 '/;' E1
%
% E1        ::= E2 | E2 ':=' E2;

% E2        ::= E3 | E2 '||' E3
%
% E3        ::= E4 | E3 '&&' E4
%
% E4        ::= E5
%           | E5 '>=' E5
%           | E5 '>=' E5 '>=' E5  (and in fact I allow longer chains)
%           | E5 '>=' E5 '>' E5
%           | E5 '>' E5
%           | E5 '>' E5 '>=' E5
%           | E5 '>' E5 '>' E5
%           | E5 '<=' E5
%           | E5 '<=' E5 '<=' E5
%           | E5 '<=' E5 '<' E5
%           | E5 '<' E5
%           | E5 '<' E5 '<=' E5
%           | E5 '<' E5 '<' E5
%           | E5 == E5
%           | E5 != E5
%
% E5    ::= E6 | E5 '+' E6 | E5 '-' E6
%
% E6    ::= E7 | E6 '*' E7 | E6 '/' E7 | E6 E7
% The final case is an implicit "*" when the following E7 starts
% with something suitable
%
% E7    ::= '-' E7 | E8 | E8 '^' E7
%
% E8    ::= E9 | E8 '!'
%
% E9    ::= Number
%       |   String
%       |   Name
%       |   Name '_'
%       |   Name '_' Name
%       |   Name '_' '''
%       |   Name '_' '.'
%       |   Name '=' Expression
%       |   Name ('[' Expression ArgTail)+
%       |   '[' Expression ArgTail
%       |   '{' Expression BraceTail
%       |   '(' Expression ')'
%
% ArgTail ::= ']' | ',' Expression ArgTail
%
% BraceTail ::= '}' | ',' Expression BraceTail
%

% Now the recursive descent parser has a procedure that mechanises
% each clause in the grammar. In general these are all very
% straight-forward!

% Rules ::= 'eof'
%       |   Rule 'eol' Rules
%       |   Rule 'eof'
%

symbolic procedure parseRules();
  begin
    scalar r;
    while mmatok = !$eol!$ do next_mma_tok();
    while not (mmatok = !$eof!$) do <<
       r := parseRule() . r;
       while mmatok = !$eol!$ do next_mma_tok() >>;
    return reverse r
  end;

% Rule  ::= Expression
%

symbolic procedure parseRule();
  parseExpression();

% Expression := E0 | Expression ';' E0
%

symbolic procedure parseExpression();
  begin
    scalar r;
    r := parseE0();
    while mmatok = '!; do <<
      next_mma_tok();
      r := list('!;, r, parseE0()) >>;
    return r;
  end;

% E0 := E1 | E0 '/;' E1
%

symbolic procedure parseE0();
  begin
    scalar r;
    r := parseE1();
    while mmatok = '!/!; do <<
      next_mma_tok();
      r := list('!/!;, r, parseE1()) >>;
    return r;
  end;

% E1        ::= E2 | E2 ':=' E2;

symbolic procedure parseE1();
  begin
    scalar r;
    r := parseE2();
    if mmatok = '!:!= then <<
      next_mma_tok();
      r := list('!:!=, r, parseE2()) >>;
    return r;
  end;

%
% E2 ::= E3 | E2 '||' E3
%

symbolic procedure parseE2();
  begin
    scalar r;
    r := parseE3();
    while mmatok = '!|!| do <<
      next_mma_tok();
      r := list('or, r, parseE3()) >>;
    return r;
  end;

% E3        ::= E4 | E3 '&&' E4
%

symbolic procedure parseE3();
  begin
    scalar r;
    r := parseE4();
    while mmatok = '!&!& do <<
      next_mma_tok();
      r := list('and, r, parseE4()) >>;
    return r;
  end;

% The intent here is to be able to have chains of comparisons provided
% they are all "in the same direction" so that A < B <= C < D < E <= F
% would be allowed, but s mix or < and > would not. When I had first
% looked through the Rubi sources I observed A < B <= C case and had
% written out the grammar for just up to three values being compared. But
% now my parsing code will (despite the grammar as written here) allow for
% any number.

% E4        ::= E5
%           | E5 '>=' E5
%           | E5 '>=' E5 '>=' E5    and longer chains
%           | E5 '>=' E5 '>' E5
%           | E5 '>' E5
%           | E5 '>' E5 '>=' E5
%           | E5 '>' E5 '>' E5
%           | E5 '<=' E5
%           | E5 '<=' E5 '<=' E5
%           | E5 '<=' E5 '<' E5
%           | E5 '<' E5
%           | E5 '<' E5 '<=' E5
%           | E5 '<' E5 '<' E5
%           | E5 '==' E5
%           | E5 '!=' E5
%           | E5 '===' E5
%           | E5 '=!=' E5

symbolic procedure parseE4chain(r, a, tok, allowed);
  begin
    scalar b;
    next_mma_tok();
    b := parseE5();
    r := list(get(tok, 'reduce_form), a, b) . r;
    if member(mmatok, allowed) then
      return parseE4chain(r, b, mmatok, allowed);
    if null cdr r then return car r
    else return 'and . reverse r
  end;

symbolic procedure parseE4();
  begin
    scalar a;
    a := parseE5();
    if mmatok = '!< or mmatok = '!<!= then
      return parseE4chain(nil, a, mmatok, '(!< !<!=))
    else if mmatok = '!> or mmatok = '!>!= then
      return parseE4chain(nil, a, mmatok, '(!> !>!=))
    else if mmatok = '!=!= or mmatok = '!!!= then
      return parseE4chain(nil, a, mmatok, '(!=!= !!!=))
    else if mmatok = '!=!=!= or mmatok = '!=!!!= then
      return parseE4chain(nil, a, mmatok, '(!=!=!= !=!!!=))
    else return a
  end;

put('!>,   'reduce_form, 'greaterp);
put('!<,   'reduce_form, 'lessp);
put('!>!=, 'reduce_form, 'geq);
put('!<!=, 'reduce_form, 'leq);
put('!=!=, 'reduce_form, 'equal);
put('!!!=, 'reduce_form, 'neq);

% The use of === and =!= is something I have not yet wrapped my mind around.

% E5 ::= E6 | E5 '+' E6 | E5 '-' E6
%
symbolic procedure parseE5();
  begin
    scalar r, op;
    r := parseE6();
    while mmatok = '!+ or mmatok = '!- do <<
       op := mmatok;
       next_mma_tok();
       r := list(get(op, 'reduce_form), r, parseE6()) >>;
    return r
  end;

put('!+, 'reduce_form, 'plus);
put('!-, 'reduce_form, 'difference);

% E6    ::= E7 | E6 '*' E7 | E6 '/' E7 | E6 E7
% The final case is an implicit "*" when the following E7 starts
% with something suitable. This involves a little bit of look-ahead
% that is not very cleary expressed in the formal grammar.

symbolic procedure parseE6();
  begin
    scalar r, op;
    r := parseE7();
    while mmatok = '!* or mmatok = '!/ or
      (idp mmatok and not flagp(mmatok, 'operator_like)
       and mmatok neq !$eol!$ and mmatok neq !$eof!$) or
      numberp mmatok or mmatok = '!( do <<
       if mmatok = '!* or mmatok = '!/ then <<
         op := mmatok;
         next_mma_tok() >>
       else op := '!*;
       r := list(get(op, 'reduce_form), r, parseE7()) >>;
    return r
  end;

put('!*, 'reduce_form, 'times);
put('!/, 'reduce_form, 'quotient);

% E7    ::= '-' E7 | E8 | E8 '^' E7
%

symbolic procedure parseE7();
  begin
    scalar r;
    if mmatok = '!- then <<
       next_mma_tok();
       r := list('minus, parseE7()) >>
    else r := parseE8();
    if mmatok = '!^ then <<
      next_mma_tok();
      return list('expt, r, parseE7()) >>
    else return r
  end;

% E8   := E9 | E8 '!'

% Factorials may be written as "E!".

symbolic procedure parseE8();
  begin
    scalar r;
    r := parseE9();
    while mmatok = '!! do <<
      next_mma_tok();
      r := list('factorial, r) >>;
    return r
  end;

% E9    ::= Number
%       |   String
%       |   Name
%       |   Name '_'
%       |   Name '_' Name
%       |   Name '_' '''
%       |   Name '_' '.'
%       |   Name '=' Expression
%       |   Name ('[' Expression ArgTail)+
%       |   Name '_' '[' Expression ArgTail
%       |   Name '_' ''' '[' Expression ArgTail
%       |   '[' Expression ArgTail
%       |   '{' Expression BraceTail
%       |   '(' Expression ')'

% The range of syntax here is a bit of a mess, and certainly I am worried
% about my marsing for assignments performed with "=". But if this suffices
% for Rubi I will be content for the moment. Somebody may like to come back
% and revisit this later to make it more complete and to bring it more
% carefully into agreement with Mathematica as a whole.

symbolic procedure parseE9();
  begin
    scalar r, w;
    if mmatok = !$eof!$ then return mmatok
    else if mmatok = '!( then <<
      << next_mma_tok();
         r := parseExpression() >> where outer_level = nil;
      checkfor '!);
      return r >>
    else if mmatok = '!{ then <<
      << next_mma_tok();
         r := parseExpression();
         r := 'bracelist . r . parseBraceTail() >> where outer_level = nil;
      next_mma_tok();
      return r >>
    else if mmatok = '![ then <<
      << next_mma_tok();
         r := parseExpression();
         r := 'bracketlist . r . parseArgTail() >> where outer_level = nil;
      next_mma_tok();
      return r >>
    else if numberp mmatok or stringp mmatok then <<
      r := mmatok;
      next_mma_tok();
      return r >>
    else if mmatok = !$eof!$ then syntax_error "unexpected end of file"
    else if flagp(mmatok, 'operator_like) then
      syntax_error list("unexpected operator", mmatok);
    r := mmatok;
    next_mma_tok();
    if mmatok = '!= then <<
      next_mma_tok();
      return list('setq, r, parseExpression()) >>
    else if mmatok = '![ then <<
      while mmatok = '![ do <<
        << next_mma_tok();
           w := parseExpression();
           r := r . w . parseArgTail() >> where outer_level = nil;
        next_mma_tok() >>;
      return r >>
    else if mmatok = '!_ then <<
      r := list('!_, r);
      next_mma_tok();
      if mmatok = '![ then <<
        << next_mma_tok();
           w := parseExpression();
           r := r . w . parseArgTail() >> where outer_level = nil;
        next_mma_tok();
        return r >>
      else if idp mmatok and not flagp(mmatok, 'operator_like) then <<
        r := list('!_, cadr r, mmatok);
        next_mma_tok();
        return r >>
      else return r >>
    else if mmatok = '!_!. then <<
      next_mma_tok();
      return list('!_!., r) >>
    else if mmatok = '!_!' then <<
      r := list('deriv, list('!_, r));
      next_mma_tok();
      if mmatok = '![ then <<
        while mmatok = '![ do <<
          << next_mma_tok();
             w := parseExpression();
             r := r . w . parseArgTail() >> where outer_level = nil;
          next_mma_tok() >>;
        return r >>
      else return r >>
    else return r
  end;


% ArgTail ::= ']' | ',' Expression ArgTail
%

% These next two behave oddly in that they leave the terminating close
% bracket as current so that thei caller must read beyond it. That is
% a policy applied so I can ignore blank lines within "[]" and "{}".

symbolic procedure parseArgTail();
  begin
    scalar r;
    if mmatok = '!] then return nil;
    checkfor '!,;
    r := parseExpression();
    return r . parseArgTail()
  end;

symbolic procedure parseBraceTail();
  begin
    scalar r;
    if mmatok = '!} then return nil;
    checkfor '!,;
    r := parseExpression();
    return r . parseBraceTail()
  end;


symbolic procedure checkfor x;
  if mmatok = x then next_mma_tok()
  else syntax_error list(x, "expected");

fluid '(filename);

% Display a message and show the most recent two lines of input. The
% message passed can either be a string or a list of items to be
% printed.

symbolic procedure syntax_error message;
  begin
    terpri();
    princ "+++ Syntax error in rules file ";
    print filename;
    if atom message then princ message
    else for each x in message do <<
      princ x; princ " " >>;
    terpri();
    princ "Line "; princ line_number; printc "...";
    for each x in reverse prevline do princ x;
    terpri();
    for each x in reverse currline do princ x;
    terpri();
    terpri();
    error(0, "parsing failed");
  end;

% The simplification that Reduce does is sometimes unable to verify
% the results of integration. This can happen for instance if there are
% trig functions and identities such as (sin(x)^2 + cos(x)^2 - 1) = 0 hide
% within the result. It can also happen when radical substitutions (eg
% between csc(x) and 1/sin(x), or involving tan(x/2)) have been applied.
% To get a better evaluation of the INTEGRATION capabilities of Reduce
% and not merely its simplification power I back up its respectable
% simplifier with tests for expression equality based on substituting
% numeric values for all the variables in an expression. This could
% fail in either direction! Coincidence could lead to my evaluation
% sample point causing a generally non-zero expression to yield a zero
% result. Numeric inaccuracy could cause trouble. And there are some messy
% issues with branch cuts and principle values if the evaluation leads to
% complex-valued results. It still seems to me that what I have here
% is better than nothing.

symbolic procedure findvars(u, l);
  if atom u or get(car u, 'dname) or eqcar(u, '!*sq) then <<
    if memq(u, '(e i pi)) then l      % e, i and pi are special!
    else if not idp u then l      % not a name
    else if memq(u, l) then l         % seen already
    else u . l >>                     % a new name
  else findvarslist(cdr u, l);        % (OP a1 a2 ...) case

symbolic procedure findvarslist(u, l);
  if atom u then l
  else findvarslist(cdr u, findvars(car u, l));

% The "probably_zero" test could potentially "get stuck" if it
% found itself evaluating deeply nested exponentials - or something.
% I will reduce overall risk by limiting the resources it can use.

% A concrete example of something that bit me on one occasion was that
% the code here found itself trying to find a numerical value for
% sech(e^42163.0) and that is of course a ridiculously large value!

% This tests if v is probably zero, using u to give normalising values.

symbolic procedure probably_zero(u, v);
  begin
    scalar r;
    r := with!-timeout(10000, % Allow ten seconds
       errorset(list('probably_zero1, mkquote u, mkquote v), t, t));
    if atom r then <<
      printc "Resource limit exceeded checking equality";
      return nil >>;
    r := car r;
    if atom r then <<
      printc "Error while checking equality";
      return nil >>
    else return car r
  end;

symbolic procedure probably_zero1(u, v);
  begin
% I re-bind !*msg to nil so I do not see comments every time I switch to
% complex mode and back.
    scalar vars, subs, u1, v1, scale, trials, !*msg;
% Identify all the variable in the expressions.
    vars := findvars(v, findvars(u, nil));
% Set up random substututions for each variable. Ensure that the values
% I select cause the first expression to evaluate to something in the
% range 10^(-5) to 10^5. Hmmm if the first expression was in fact identically
% zero this would not be possible and the code here would loop, so
% I put a trap that limits the number of samples I am willing to
% try.
    u1 := 0.0;
    scale := 0.002;
    trials := 0;
    while (u1 < 1.0e-5 or u1 > 1.0e5) and trials < 100 do <<
      trials := trials + 1;
      subs := for each v in vars collect
         (v . ((random(scale*2000000) - scale*1000000.0)/1000003.0));
      on rounded, complex, numval;
      u1 := prepsq simp!* subla(subs, list('abs, u));
      off numval, complex, rounded;
      scale := 2.0*scale;
      if eqcar(u1, '!:rd!:) then u1 := cdr u1;
      if not floatp u1 then u1 := 0.0 >>;
% If I failed to find a suitable evaluation point I will just report
% that I can not show that the expressions match.
    if trials >= 100 then return nil;
% Evaluate the result - which should yield a number! Set myself into
% a Reduce mode that does numeric evaluation.
    on rounded, complex, numval;
    v1 := prepsq simp!* subla(subs, v);
    off numval, complex, rounded;
    if eqcar(v1, '!:rd!:) then v1 := cdr v1
    else if fixp v1 then v1 := float v1;
    if not floatp v1 then v1 := 10000.0*u1;
% Now just return the result... I set a tolerance here, and so the overall
% test I am applying can lead to a result that says "yes they seem equal"
% when really they are not.
    return (10000.0*v1 < u1);
  end;

% I want the random trials used to vary on each run... so seed the random
% number source based on the date and time of day.

random_new_seed begin scalar w;
  w := 1;
  for each c in explode date!-and!-time() do
     w := remainder((169*w + id2int c), 100000000);
  return w end;

fluid '(testdirectory);
fluid '(testcount optimal messy unable invalid);
fluid '(t_testcount t_optimal t_messy t_unable t_invalid);
fluid '(section_name);

testcount := optimal := messy := unable := invalid := 0;
t_testcount := t_optimal := t_messy := t_unable := t_invalid := 0;

% When the tests are run I prefix each line of report with a "@" so that
% it is easy to extract information from a log file even if there is a great
% deal of other trace output.

symbolic procedure start_whole_test();
  begin
    t_testcount := t_optimal := t_messy := t_unable := t_invalid := 0;
    terpri();
    princ "@Integrand types";
    ttab 30;
    princ "Problems";
    ttab 40;
    princ "Optimal";
    ttab 50;
    princ "Messy";
    ttab 60;
    princ "Unable";
    ttab 70;
    printc "Invalid"
  end;

symbolic procedure start_test_section name;
  begin
    section_name := name;
    testcount := optimal := messy := unable := invalid := 0;
  end;


symbolic procedure report_section();
  begin
    princ "@";
    princ section_name;
    ttab 30;
    prin (optimal+messy+unable+invalid);
    ttab 40;
    prin optimal;
    ttab 50;
    prin messy;
    ttab 60;
    prin unable;
    ttab 70;
    print invalid;
    t_optimal := t_optimal + optimal;
    t_messy := t_messy + messy;
    t_unable := t_unable + unable;
    t_invalid := t_invalid + invalid;
  end;

symbolic procedure final_report();
  begin
    scalar tot;
    tot := t_optimal+t_messy+t_unable+t_invalid;
    princ "@Totals";
    ttab 30;
    prin tot;
    ttab 40;
    prin t_optimal;
    ttab 50;
    prin t_messy;
    ttab 60;
    prin t_unable;
    ttab 70;
    print t_invalid;
    tot := float tot;
    setprintprecision 3;
    princ "@Percentages";
    ttab 40;
    prin (100.0*float t_optimal/tot);
    ttab 50;
    prin (100.0*float t_messy/tot);
    ttab 60;
    prin (100.0*float t_unable/tot);
    ttab 70;
    print (100.0*float t_invalid/tot);
  end;

symbolic procedure xsize u;
  if null u then 0
  else if atom u then 1
  else 1 + xsize car u + xsize cdr u;

symbolic procedure convert_to_reduce u;
  if idp u and get(u, 'reduceversion) then get(u, 'reduceversion)
  else if atom u then u
  else for each v in u collect convert_to_reduce v;

put('!E,               'reduceversion, 'e);
put('!Pi,              'reduceversion, 'pi);
put('!I,               'reduceversion, 'i);
put('e,                'reduceversion, 'lower_case_e);
put('i,                'reduceversion, 'lower_case_i);

put('!Int,             'reduceversion, 'int);
put('!D,               'reduceversion, 'df);
put('!Simplify,        'reduceversion, 'mma_simplify);

put('!Abs,             'reduceversion, 'abs);
put('!Exp,             'reduceversion, 'exp);
put('!Log,             'reduceversion, 'log);
put('!Sqrt,            'reduceversion, 'sqrt);
put('!Sin,             'reduceversion, 'sin);
put('!Cos,             'reduceversion, 'cos);
put('!Sec,             'reduceversion, 'sec);
put('!Csc,             'reduceversion, 'csc);
put('!Tan,             'reduceversion, 'tan);
put('!Cot,             'reduceversion, 'cot);
put('!Sinh,            'reduceversion, 'sinh);
put('!Cosh,            'reduceversion, 'cosh);
put('!Sech,            'reduceversion, 'sech);
put('!Csch,            'reduceversion, 'csch);
put('!Tanh,            'reduceversion, 'tanh);
put('!Coth,            'reduceversion, 'coth);
put('!Arc!Sin,         'reduceversion, 'asin);
put('!Arc!Cos,         'reduceversion, 'acos);
put('!Arc!Sec,         'reduceversion, 'asec);
put('!Arc!Csc,         'reduceversion, 'acsc);
put('!Arc!Tan,         'reduceversion, 'atan);
put('!Arc!Cot,         'reduceversion, 'acot);
put('!Arc!Sinh,        'reduceversion, 'asinh);
put('!Arc!Cosh,        'reduceversion, 'acosh);
put('!Arc!Sech,        'reduceversion, 'asech);
put('!Arc!Csch,        'reduceversion, 'acsch);
put('!Arc!Tanh,        'reduceversion, 'atanh);
put('!Arc!Coth,        'reduceversion, 'acoth);

put('!Erf,             'reduceversion, 'erf);
put('!Elliptic!E,      'reduceversion, 'elliptice);
put('!Elliptic!F,      'reduceversion, 'ellipticf);
put('!Elliptic!Pi,     'reduceversion, 'ellipticpi);
put('!Exp!Integral!Ei, 'reduceversion, 'ei);
put('!Log!Integral,    'reduceversion, 'li);
put('!Poly!Log,        'reduceversion, 'polylog);
put('!Product!Log,     'reduceversion, 'productlog);
put('!Erfc,            'reduceversion, 'erfc);
put('!Erfi,            'reduceversion, 'erfi);
put('!Fresnel!S,       'reduceversion, 'fresnel_s);
put('!Fresnel!C,       'reduceversion, 'fresnel_c);
put('!Sin!Integral,    'reduceversion, 'si);
put('!Cos!Integral,    'reduceversion, 'ci);
put('!Gamma,           'reduceversion, 'gamma);
put('!Poly!Gamma,      'reduceversion, 'polygamma);
put('!Log!Gamma,       'reduceversion, 'loggamma);
put('!Sinh!Integral,   'reduceversion, 'shi);
put('!Cosh!Integral,   'reduceversion, 'chi);
put('!Zeta,            'reduceversion, 'zeta);

% Make things operators if that are not already so...

for each x in '(elliptice ellipticf ellipticpi li
    polylog productlog erfc erfi fresnel_s fresnel_c
    polygamma loggamma shi chi zeta mma_simplify) do
  if not get(x, 'simpfn) then apply1('operator, list x);

algebraic operator f, !Complex!Expand;

algebraic for all x let mma_simplify(x) = x;

fluid '(testcases);

testcases := nil; % Used for a file to save a transcript of cases tried.

algebraic <<

trig_normalisations := {
  asin(~z) => -i*log(i*z+sqrt(1-z^2)),
  acos(~z) => pi/2 - asin(z),
  atan(~z) => (i/2)*(log(1-z) - log(1+i*z)),
  acot(~z) => atan(1/z),
  acsc(~z) => asin(1/z),
  asec(~z) => acos(1/z),
  asinh(~z) => log(z+sqrt(1+z^2)),
  acosh(~z) => log(z + sqrt(z+1)*sqrt(z-1)),
  atanh(~z) => log((1+z)/(1-z))/2,
  acoth(~z) => log((z+1)/(z-1))/2,
  acsch(~z) => log(1/z + sqrt(1/z^2+1)),
  asech(~z) => log(1/z + sqrt(1/z+1)*sqrt(1/z-1)),
  e^((~a*log(~b))/~c) => b^(a/c) 
  } >>;
  

fluid '(time_limit!*);
time_limit!* := 20000; % Allow 20 seconds per integral ...
                       % ... and 40 second per complete test case.

symbolic procedure safe_evaluate a;
  begin
    scalar w;
    w := with!-timeout(time_limit!*,
      errorset(a, nil, nil));
    if atom w then return 'timeout;
    return car w
  end;

symbolic procedure try_rubi_example(r, integrand);
  begin
    scalar rr, e, x, steps, res, w1, w2, ff;
    rr := r;
    if not eqcar(r, 'bracelist) or
       (length r neq 5 and length r neq 6)then <<
      terpri();
      princ "+++ Malformed test case: ";
      prettyprint r;
      return nil >>;
    if !*trrubi and null testcases then
      testcases := open("testcases.red", 'output);
    r := cdr r;
    princ "%%%%:::: ";
    for each x in integrand do princ x;
    terpri();
%   princ "%%%%::: "; princ list time(); princ " "; print car r;
    e := convert_to_reduce car r; r := cdr r;
    x := car r; r := cdr r;
    steps := car r; r := cdr r;
% Sometimes the Rubi files seem to have a second (alternative?) "right answer"
% but I will ignore that here.
    res := convert_to_reduce car r; r := cdr r;
    w1 := list('prepsq, list('simp!*, mkquote list('int, e, x)));
% The next line is painful. It is here because the old Reduce integrator
% can "get stuck" on rather a lot of the Rubi examples. Eg
%   int(1/(x*(a+b*x)^(3/2)*(c + d*x)^(5/2)), x);
% provides a particular example where the only sane behaviours here would
% be either to disable trying the case or to arrange to give up trying to
% solve it after a suitable amount of time. However note that erroring out
% from the integration code can leave Reduce in an inconsistent state - so
% I will need to work out just what status needs restoring.
% I try to encapsulate it can not do too much damage.
%
    w1 := safe_evaluate(w1);
    printc "Integration complete"; flush nil;
    if atom w1 then <<
      if !*trrubi then <<
        ff := wrs testcases;
        if w1 = 'timeout then printc "% Timeout"
        else printc "% Errorset trap";
        << prin2!* "COMMENT "; maprin convert_to_reduce cadr rr;
           prin2!* ";"; terpri!* t >> where !*nat = nil;
        princ "try_rubi_example '"; prin rr; printc ";";
        terpri();
        wrs ff;
        flush testcases >>;
      if w1 = 'timeout then printc "Timeout" else printc "Errorset trap" >>;
    if atom w1 or smemq('int, w1) then <<
      mathprint list('int, e, x);
      printc "Unable to integrate";
      mathprint res;                 % Show the answer that Rubi suggests
      unable := unable + 1;
      return nil >>;
    w1 := car w1;                    % Value if errorset succeeded
    printc "Integration done";
    w2 := prepsq simp!* list('difference, e, list('df, w1, x));
% I first tried to check the answer with Reduce's standard settings, and that
% includes "on precise;" which represents a simplification regime that is
% somewhat cautious about multiple-valued functions. If that confirmed a
% correct answer I am very happy. If it does not then I will try to check
% the result in "off precise" mode, and if that looks good I will accept it
% (but printing a message to explain that there is a risk).
    if w2 neq 0 then begin
      scalar !*precise;
      printc "About to normalise trig fns";
%     w2 := normalise_trigs w2; % Converts all trigs to tan half angle form
      printc "Resimplify";
      w2 := prepsq simp!* list('trigsimp, w2, 'expon);
      if w2 neq 0 then printc "normalise inverse trigs to logarithms";
      if w2 neq 0 then
        w2 := prepsq simp!* aeval
          list('whereexp, '(list trig_normalisations), w2);
      if w2 = 0 then
        printc "Result seems OK at least in ""off precise"" mode";
    end;
% If the reliable algebraic check on the answer fails then I will
% try a probablistic one based on numerical evaluation.
    if w2 neq 0 then <<
% If I was more cautious I should perhaps run probably_equal several times.
      princ "Running probabilistic check on "; print w2;
      if probably_zero(e, w2) then w2 := 0 >>;
    if w2 neq 0 then <<
      mathprint list('int, e, x);
      printc "Invalid result, or checking failed";
      invalid := invalid + 1;
      if !*trrubi then <<
        e := wrs testcases;
        printc "% Result may be incorrect";
        << prin2!* "COMMENT "; maprin convert_to_reduce cadr rr;
           prin2!* ";"; terpri!* t >> where !*nat = nil;
        princ "try_rubi_example '"; prin rr; printc ";";
        terpri();
        wrs e;
        flush testcases >>;
% Some - perhaps many - of these will in fact be OK!
      return nil >>;
    if xsize w1 > 2*xsize res then <<
      mathprint list('int, e, x);
      printc "Result is correct but messy"; 
      messy := messy + 1 >>
    else <<
%     printc "Result satisfactory";
      optimal := optimal + 1 >>;
  end;

% This reads a single Rubi test file. When running tests it is
% important that that variable "testdirectory" holds a string that is
% the directory that the Rubi test files can be found from. The main
% Reduce testing scripts in the full source tree arrange for that to
% be the case.

symbolic procedure read_one_rubi_test(filename, version4);
  begin
    scalar integrand, r, ff, save, !*echo;
    if not boundp 'testdirectory or not stringp testdirectory then <<
      if (r := getenv("reduce")) then
        testdirectory := concat(r, "/packages/rubi_red")
      else if (r := getenv("O")) then
        testdirectory := concat(r, "/packages/rubi_red")
      else testdirectory := "." >>;
% Now for the benefit of PSL when running under Windows I will allow for
% circumstances that arise when I have been building for CSL under cygwin,
% in which case the directory information I obtained might start off
% with "/cygdrive/X/..." for some letter "X". I need to map that to
% "X:/..." to survive under native windows. CSL actually makes this
% conversion internally! This sort of assumes that no sensible Unix-like
% system would have a top-level directory names "/cygdrive", which is
% probably OK in practise but is a bit ugly!
    r := explode2 testdirectory;
    save := '(!/ c y g d r i v e !/);
    while save and eqcar(r, car save) do << r := cdr r; save := cdr save >>;
    if null save and r and eqcar(cdr r, '!/) then <<
       r := car r . '!: . cdr r;
       testdirectory := list2string r >>;
    if version4 then
       filename := concat(testdirectory, concat("/tests4/", filename))
    else filename := concat(testdirectory, concat("/tests/", filename));
    ff := open(filename, 'input);
    save := rds ff;
%   princ "Reading file "; print filename;
    prevline := currline := nil;
    mmachar := !$eol!$;
    line_number := 1;
    eofcounter := 0;
    outer_level := nil;
    next_mma_tok();
    while mmatok neq !$eof!$ do <<
% Each input is expected to be a list of the form "{A, B, C, D}" and I will
% parse this very much by hand so that I can grab the text from A.
       if mmatok neq '!{ then syntax_error "'{' expected";
       currexpr := list car currexpr;
       next_mma_tok();
       r := parseExpression();
       integrand := reverse cddr currexpr;
       while eqcar(integrand, !$eol!$) do integrand := cdr integrand;
       r := 'bracelist . r . parseBraceTail();
       next_mma_tok();
%      r := errorset('(parseE9), t, t);
%      if atom r then syntax_error "parsing failed"
%      else try_rubi_example car r >>;
       with!-timeout(2*time_limit!*, try_rubi_example(r, integrand)) >>;
    rds save;
    close ff;
    return nil
  end;

% The above procedure read just one test file - this one reads all of them.
% Note it is keyed to a particular release of Rubi because it has an
% explicit list of the test files provided.

symbolic procedure read_rubi_rationals();
 << start_test_section "Rational functions";
    read_one_rubi_test("RationalFunctions/RationalFunctionsOfBinomials.m", nil);
    read_one_rubi_test("RationalFunctions/RationalFunctionsOfLinears.m", nil);
    read_one_rubi_test("RationalFunctions/RationalFunctionsOfTrinomials.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_algebraics();
 << start_test_section "Algebraic functions";
    read_one_rubi_test("AlgebraicFunctions/AlgebraicFunctionsOfBinomials.m", nil);
    read_one_rubi_test("AlgebraicFunctions/AlgebraicFunctionsOfLinears.m", nil);
    read_one_rubi_test("AlgebraicFunctions/AlgebraicFunctionsOfTrinomials.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_exponentials();
 << start_test_section "Exponential functions";
    algebraic operator f;
    read_one_rubi_test("ExponentialFunctions/ExponentialFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_logarithms();
 << start_test_section "Logarithmic functions";
    algebraic operator !Complex!Expand;
    read_one_rubi_test("ExponentialFunctions/LogarithmFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_trig();
 << start_test_section "Trig functions";
    read_one_rubi_test("TrigFunctions/cos(x)^m (a+a cos(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/cos(x)^m (a+b cos(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/cos(x)^m (b cos(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/CosecantFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/CosineFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/CotangentFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/csc(x)^m (a+a csc(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/csc(x)^m (a+b csc(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/sec(x)^m (a+a sec(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/sec(x)^m (a+b sec(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/sec(x)^m (b sec(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/SecantFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/sin(x)^m (a+a sin(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/sin(x)^m (a+b sin(x))^n.m", nil);
    read_one_rubi_test("TrigFunctions/SineFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/TangentFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/TrigFunctions.m", nil);
    read_one_rubi_test("TrigFunctions/TwoTrigFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_inverse_trig();
 << start_test_section "Inverse trig functions";
    read_one_rubi_test("InverseTrigFunctions/InverseCosecantFunctions.m", nil);
    read_one_rubi_test("InverseTrigFunctions/InverseCosineFunctions.m", nil);
    read_one_rubi_test("InverseTrigFunctions/InverseCotangentFunctions.m", nil);
    read_one_rubi_test("InverseTrigFunctions/InverseSecantFunctions.m", nil);
    read_one_rubi_test("InverseTrigFunctions/InverseSineFunctions.m", nil);
    read_one_rubi_test("InverseTrigFunctions/InverseTangentFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_hyperbolic();
 << start_test_section "Hyperbolic functions";
    algebraic operator f;
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCosecantFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCosineFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCotangentFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicSecantFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicSineFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicTangentFunctions.m", nil);
    read_one_rubi_test("HyperbolicFunctions/TwoHyperbolicFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_inverse_hyperbolic();
 << start_test_section "Inverse hyperbolic functions";
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCosecantFunctions.m", nil);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCosineFunctions.m", nil);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCotangentFunctions.m", nil);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicSecantFunctions.m", nil);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicSineFunctions.m", nil);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicTangentFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_error_fresnel();
 << start_test_section "Error and Fresnel functions";
    read_one_rubi_test("SpecialFunctions/ErrorFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/FresnelIntegralFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_integral();
 << start_test_section "Integral functions";
    read_one_rubi_test("SpecialFunctions/ExponentialIntegralFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/HyperbolicIntegralFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/LogarithmIntegralFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/TrigIntegralFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_rubi_special();
 << start_test_section "Special functions";
    read_one_rubi_test("SpecialFunctions/GammaFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/PolylogarithmFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/ProductLogarithmFunctions.m", nil);
    read_one_rubi_test("SpecialFunctions/ZetaFunctions.m", nil);
    report_section();
 >>;

symbolic procedure read_all_rubi_tests();
  begin
    scalar section_name, testcount, optimal, messy, unable, invalid,
      t_testcount, t_optimal, t_messy, t_unable, t_invalid;
%=============================================================================
    start_whole_test();
    read_rubi_rationals();
%-----------------------------------------------------------------------------
    read_rubi_algebraics();
%=============================================================================
    read_rubi_exponentials();
%-----------------------------------------------------------------------------
    read_rubi_logarithms();
%=============================================================================
    read_rubi_trig();
%-----------------------------------------------------------------------------
    read_rubi_inverse_trig();
%=============================================================================
    read_rubi_hyperbolic();
%-----------------------------------------------------------------------------
    read_rubi_inverse_hyperbolic();
%=============================================================================
    read_rubi_error_fresnel();
%-----------------------------------------------------------------------------
    read_rubi_integral();
%-----------------------------------------------------------------------------
    read_rubi_special();
    final_report();
%=============================================================================
  end;

symbolic procedure read_all_rubi_tests_version4();
  begin
    scalar section_name, testcount, optimal, messy, unable, invalid,
      t_testcount, t_optimal, t_messy, t_unable, t_invalid;
%=============================================================================
    start_whole_test();

    start_test_section "Exponential Functions";
    read_one_rubi_test("ExponentialFunctions/ExponentialFunctions.m", t);
    read_one_rubi_test("ExponentialFunctions/LogarithmFunctions.m", t);
    report_section();

    start_test_section "Inverse Trig Functions";
    read_one_rubi_test("InverseTrigFunctions/InverseCotangentFunctions.m", t);
    read_one_rubi_test("InverseTrigFunctions/InverseCosineFunctions.m", t);
    read_one_rubi_test("InverseTrigFunctions/InverseSineFunctions.m", t);
    read_one_rubi_test("InverseTrigFunctions/InverseCosecantFunctions.m", t);
    read_one_rubi_test("InverseTrigFunctions/InverseTangentFunctions.m", t);
    read_one_rubi_test("InverseTrigFunctions/InverseSecantFunctions.m", t);
    report_section();

    start_test_section "Hyperbolic Functions";
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCotangentFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCosecantFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicTangentFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/cosh(c+d x)^m (a+b cosh(c+d x))^n.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/tanh^3.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicSecantFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicSineFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/TwoHyperbolicFunctions.m", t);
    read_one_rubi_test("HyperbolicFunctions/HyperbolicCosineFunctions.m", t);
    report_section();

    start_test_section "Special Functions";
    read_one_rubi_test("SpecialFunctions/TrigIntegralFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/GammaFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/PolylogarithmFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/HyperbolicIntegralFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/ProductLogarithmFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/ExponentialIntegralFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/ZetaFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/FresnelIntegralFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/LogarithmIntegralFunctions.m", t);
    read_one_rubi_test("SpecialFunctions/ErrorFunctions.m", t);
    report_section();

    start_test_section "P3 Trinomial Functions";
    read_one_rubi_test("P3 Trinomial Functions/P3.1.5 u (a+b x+c x^2)^n (d+e x+f x^2)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.3.2 x^m (d+e x^n)^q (a+b x^n+c x^(2n))^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.3.1 x^m (a+b x^n+c x^(2n))^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.1.1 x^m (a+b x+c x^2)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.2.1 x^m (a+b x^2+c x^4)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.3.3 x^m (a x^q+b x^n+c x^(2 n-q))^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.1.3 x^m (d+e x)^n (a+b x+c x^2)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.1.2 (d+e x)^m (a+b x+c x^2)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.2.2 x^m (d+e x^2)^n (a+b x^2+c x^4)^p.m", t);
    read_one_rubi_test("P3 Trinomial Functions/P3.1.4 (d+e x)^m (f+g x)^n (a+b x+c x^2)^p.m", t);
    report_section();

    start_test_section "Inverse Hyperbolic Functions";
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicTangentFunctions.m", t);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCosineFunctions.m", t);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicSineFunctions.m", t);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCosecantFunctions.m", t);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicSecantFunctions.m", t);
    read_one_rubi_test("InverseHyperbolicFunctions/InverseHyperbolicCotangentFunctions.m", t);
    report_section();

    start_test_section "P1 Monomial Functions";
    read_one_rubi_test("P1 Monomial Functions/P1.7 Miscellaneous problems.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.1 x^m (a x^r+b x^s+...)^n.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.5 Piecewise constant extraction problems.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.6 Expansion problems.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.3 Normalization problems.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.2 x^m P[x] Q[x]^p.m", t);
    read_one_rubi_test("P1 Monomial Functions/P1.4 Substitution problems.m", t);
    report_section();

    start_test_section "Trig Functions";
    read_one_rubi_test("TrigFunctions/8.1 trig(c+d x)^m (a cos(c+d x)+b sin(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/3.2 trig(a+b x)^m trig(c+d x)^n.m", t);
    read_one_rubi_test("TrigFunctions/7.5.2 sec(c+d x)^m (a+b sec(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.2.3 trig(c+d x)^m (a+b cos(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/8.4 trig(c+d x)^m (a+b trig(c+d x)^n)^p.m", t);
    read_one_rubi_test("TrigFunctions/7.1.1 sin(c+d x)^m (a+a sin(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/4.2 cos(a+b x)^m (c cos(a+b x))^n.m", t);
    read_one_rubi_test("TrigFunctions/8.2 (c trig(a+b x)^m)^n.m", t);
    read_one_rubi_test("TrigFunctions/7.5.3 trig(c+d x)^m (a+b sec(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.2.2 cos(c+d x)^m (a+b cos(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.1.2 sin(c+d x)^m (a+b sin(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.1.3 trig(c+d x)^m (a+b sin(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.5.1 sec(c+d x)^m (a+a sec(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.3.3 trig(c+d x)^m (a+b tan(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.6.2 csc(c+d x)^m (a+b csc(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.6.3 trig(c+d x)^m (a+b csc(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/8.3 (a+b trig(c+d x)^m)^n.m", t);
    read_one_rubi_test("TrigFunctions/7.1.4 (A+B trig(c+d x)) (a+b sin(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/1. trig(a+b x)^n.m", t);
    read_one_rubi_test("TrigFunctions/7.6.1 csc(c+d x)^m (a+a csc(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.3.1 tan(c+d x)^m (a+i a tan(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/TrigFunctions.m", t);
    read_one_rubi_test("TrigFunctions/9.3 (d+e x)^m trig(a+b x+c x^2)^n.m", t);
    read_one_rubi_test("TrigFunctions/9.2 x^m (a+b trig(c+d x)^n)^p.m", t);
    read_one_rubi_test("TrigFunctions/9.4 x^m trig(a+b log(c x^n))^p.m", t);
    read_one_rubi_test("TrigFunctions/7.4.2 cot(c+d x)^m (a+b cot(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/9.1 x^m trig(a+b x^n)^p.m", t);
    read_one_rubi_test("TrigFunctions/7.2.1 cos(c+d x)^m (a+a cos(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.3.2 tan(c+d x)^m (a+b tan(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.2.4 (A+B trig(c+d x)) (a+b cos(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/7.4.3 trig(c+d x)^m (a+b cot(c+d x))^n.m", t);
    read_one_rubi_test("TrigFunctions/3.1 trig(a+b x)^m trig(a+b x)^n.m", t);
    read_one_rubi_test("TrigFunctions/4.5 sec(a+b x)^m (c sec(a+b x))^n.m", t);
    report_section();

    start_test_section "Miscellaneous Functions";
    read_one_rubi_test("MiscellaneousFunctions/SymmetricModFunctions.m", t);
    read_one_rubi_test("MiscellaneousFunctions/SchaumsIntegrationProblems.m", t);
    read_one_rubi_test("MiscellaneousFunctions/zTrigProblems.m", t);
    read_one_rubi_test("MiscellaneousFunctions/PiecewiseContinuouss.m", t);
    read_one_rubi_test("MiscellaneousFunctions/TestGradnew.m", t);
    read_one_rubi_test("MiscellaneousFunctions/newproblems.m", t);
    read_one_rubi_test("MiscellaneousFunctions/DifferentiationFunctions.m", t);
    read_one_rubi_test("MiscellaneousFunctions/SimpProblems.m", t);
    report_section();

    start_test_section "P2 Binomial Functions";
    read_one_rubi_test("P2 Binomial Functions/P2.1.3 (a+b x)^m (c+d x)^n (e+f x)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.3.1 x^m (a x^q+b x^n)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.2.2 (a+b x^n)^m (c+d x^n)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.1.2 (a+b x)^m (A+B x) (d+e x)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.2.5 x^m P[x] (a+b x^n)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.2.3 x^m (a+b x^n)^p (c+d x^n)^q.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.2.1 x^m (a+b x^n)^p.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.1.1 (a+b x)^m (c+d x)^n.m", t);
    read_one_rubi_test("P2 Binomial Functions/P2.2.4 (a+b x^n)^m (c+d x^n)^p (e+f x^n)^q.m", t);
    report_section();

    start_test_section "Contributed Problems";
    read_one_rubi_test("ContributedProblems.m", t);
    report_section();

    final_report();
%=============================================================================
  end;

fluid '(rubi_rules);

% Now I have a function that reads a single file of Rubi rules. The
% path used is relative to $reduce, and that will make it valid while
% Reduce is being built, but not necessarily if a version of Reduce has
% then been installed without associated source code.

symbolic procedure read_rubi_rule_file filename;
  begin
    scalar r, ff, save, !*echo;
    filename := concat("$reduce/packages/rubi_red/rubi-rules/", filename);
    ff := open(filename, 'input);
    save := rds ff;
    princ "Reading file "; print filename;
    prevline := currline := nil;
    mmachar := !$eol!$;
    line_number := 1;
    eofcounter := 0;
    outer_level := t;
    next_mma_tok();
    r := errorset('(parseRules), t, t);
    rds save;
    close ff;
    if atom r then return error(0, "parsing failed");
    r := car r;
    princ "File processed giving ";
    princ length r;
    printc " rules";
    rubi_rules := append(rubi_rules, r);
    return nil
  end;

% Read all of the rule files. Again this is keyed to a particular version
% of Rubi and will need updating if rule-files are added or deleted.

symbolic procedure read_rubi_rules();
  begin
    scalar rubi_rules;
    read_rubi_rule_file "AlgebraicFunctions/AlgebraicFunctionsOfBinomials.m";
    read_rubi_rule_file "AlgebraicFunctions/AlgebraicFunctionsOfLinears.m";
    read_rubi_rule_file "AlgebraicFunctions/AlgebraicFunctionsOfTrinomials.m";
    read_rubi_rule_file "ExponentialFunctions/ExponentialFunctions.m";
    read_rubi_rule_file "ExponentialFunctions/LogarithmFunctions.m";
    read_rubi_rule_file "ExponentialFunctions/ProductsOfExponentialAndHyperbolicFunctions.m";
    read_rubi_rule_file "ExponentialFunctions/ProductsOfExponentialAndTrigFunctions.m";
    read_rubi_rule_file "HyperbolicFunctions/HyperbolicSecantFunctions.m";
    read_rubi_rule_file "HyperbolicFunctions/HyperbolicSineFunctions.m";
    read_rubi_rule_file "HyperbolicFunctions/HyperbolicSubstitution.m";
    read_rubi_rule_file "HyperbolicFunctions/HyperbolicTangentFunctions.m";
    read_rubi_rule_file "HyperbolicFunctions/RationalFunctionsOfHyperbolicSinesAndCosines.m";
    read_rubi_rule_file "HyperbolicFunctions/TwoHyperbolicFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicCosecantFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicCosineFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicCotangentFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicSecantFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicSineFunctions.m";
    read_rubi_rule_file "InverseHyperbolicFunctions/InverseHyperbolicTangentFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseCosecantFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseCosineFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseCotangentFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseSecantFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseSineFunctions.m";
    read_rubi_rule_file "InverseTrigFunctions/InverseTangentFunctions.m";
    read_rubi_rule_file "RationalFunctions/RationalFunctionsOfBinomials.m";
    read_rubi_rule_file "RationalFunctions/RationalFunctionsOfLinears.m";
    read_rubi_rule_file "RationalFunctions/RationalFunctionsOfTrinomials.m";
    read_rubi_rule_file "SpecialFunctions/ErrorFunctions.m";
    read_rubi_rule_file "SpecialFunctions/ExponentialIntegralFunctions.m";
    read_rubi_rule_file "SpecialFunctions/FresnelIntegralFunctions.m";
    read_rubi_rule_file "SpecialFunctions/GammaFunctions.m";
    read_rubi_rule_file "SpecialFunctions/HyperbolicIntegralFunctions.m";
    read_rubi_rule_file "SpecialFunctions/LogarithmIntegralFunctions.m";
    read_rubi_rule_file "SpecialFunctions/PolylogarithmFunctions.m";
    read_rubi_rule_file "SpecialFunctions/ProductLogarithmFunctions.m";
    read_rubi_rule_file "SpecialFunctions/TrigIntegralFunctions.m";
    read_rubi_rule_file "SpecialFunctions/ZetaFunctions.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (a+a sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (A+B sin^k) (a+a sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (A+B sin^k) (a+b sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (a+b sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (A+B sin^k+C sin^(2k)) (a+a sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/(sin^j)^m (A+B sin^k+C sin^(2k)) (a+b sin^k)^n.m";
    read_rubi_rule_file "TrigFunctions/RationalFunctionsOfSinesAndCosines.m";
    read_rubi_rule_file "TrigFunctions/RecurrenceEquations.m";
    read_rubi_rule_file "TrigFunctions/SecantFunctions.m";
    read_rubi_rule_file "TrigFunctions/SineFunctions.m";
    read_rubi_rule_file "TrigFunctions/TangentFunctions.m";
    read_rubi_rule_file "TrigFunctions/TrigNormalization.m";
    read_rubi_rule_file "TrigFunctions/TrigSubstitution.m";
    read_rubi_rule_file "TrigFunctions/TwoTrigFunctions.m";
    printc list("there are", length rubi_rules, "rules");
    return rubi_rules
  end;

endmodule;

end;

