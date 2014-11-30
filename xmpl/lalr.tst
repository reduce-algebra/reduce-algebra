% Test cases for the parser generator. This all runs in
% symbolic mode...


%
% This is where (for now) I will put documentation of the syntax I
% will use when creating a grammer. There is a main function called
% lalr_construct_parser and that is passed a list that describes
% a grammar. It is in the form of a sequence of productions, and the first
% one given is taken to be the top-level target.
%
% Each production is in the form
%     (LHS   ((rhs1.1 rhs1.2 ...) a1.1 a1.2 ...)
%            ((rhs2.1 rhs2.1 ...) a2.1 a2.2 ...)
%            ...)
% which in regular publication style for grammars might be interpreted
% as meaning
%      LHS ::= rhs1.1 rhs1.2 ... { a1.1 a1.2 ... }
%          |   rhs2.1 rhs2.2 ... { a2.1 a2.2 ... }
%          ...
%          ;
%
% Each LHS is treated as a non-terminal symbol and is specified as a simple
% name. Note that by default the Reduce parser will be folding characters
% within names to lower case and so it will be best to choose names for
% non-terminals that are unambiguous even when case-folded, but I would like
% to establish a convention that in source code they are written in capitals.
%
% The rhs items may be either non-terminals (identified because they are
% present in the left hand side of some production) or terminals. Terminal
% symbols can be specified in two different ways.
% The lexer has built-in recipies that decode certain sequences of characters
% and return the special markers for !:symbol, !:number, !:string, !:list for
% commonly used cases. In these cases the variable yylval gets left set
% to associated data, so for instance in the case of !:symbol it gets set
% to the particular symbol concerned.
% The token type :list is used for Lisp or rlisp-like notation where the
% input contains
%     'expression
% or  `expression
% so for instance the input `(a b c) leads to the lexer returning !:list and
% yylvel being set to (backquote (a b c)). This treatment is specialised for
% handling rlisp-like syntax.
%
% Other terminals are indicated by writing a string. That may either
% consist of characters that would otherwise form a symbol (ie a letter
% followed by letters, digits and underscores) or a sequence of
% non-alphanumeric characters. In the latter case if a sequence of three or
% more punctuation marks make up a terminal then all the shorter prefixes
% of it will also be grouped to form single entities. So if "<-->" is a
% terminal then '<', '<-' and '<--' will each by parsed as single tokens, and
% any of them that are not used as terminals will be classified as !:symbol.
%
% When the lexer processes input it will return a numeric code that identifies
% the type of the item seen, so in a production one might write
%     (!:symbol ":=" EXPRESSION)
% and as it recognises the first two tokens the lexer will return a numeric
% code for !:symbol (and set yylval to the actual symbol as seen) and then
% a numeric code that it allocates for ":=". In the latter case it will
% also set yylval to the symbol !:!= in case that is useful.


symbolic;

% Before testing parser generation I will demonstrate the lexer..
% If I was julpy about the exact behaviour of the lexer I could go
%               on tracelex;
% to get some more tracing.

lex_cleanup();

lex_keywords '("begin" "<=>" "<==");

% The output from this is expected to be

%  Result: (2 symbol)
%  Result: (4 200)
%  Result: (4 3.542)
%  Result: (3 "a string")
%  Result: (2 nil)
%  Result: (5 (quote (quoted lisp)))
%  Result: (5 (backquote (backquoted (!, comma) (!,!@ comma_at))))
%  Result: (2 !+)
%  Result: (7 !<!=!>)
%  Result: (2 !-)
%  Result: (2 !=)
%  Result: (2 !>)
%  Result: (9 !<)
%  Result: (8 !<!=)
%  Result: (5 begin)
%  Result: (2 !;)
%  Result: (2 !;)
%  Result: (2 !;)
%
%  nil

% The row of "; ; ;" at the end provides some protection so that
% if faults in the lexer were to cause it to read more or less than it ought
% to then what is left over is reasonably likely to remain as valid rlisp
% syntax and so the rest of this test file will be able to continue happily.


<< off echo;
   lex_init();
   for i := 1:18 do <<
     tt := yylex();
     if not zerop posn() then terpri();
     princ "Result: ";
     print list(tt, yylval) >>;
   on echo >>;

symbol
200
3.542
"a string"
'(quoted lisp)
`(backquoted ,comma ,@comma_at)
+
<=>
-
=>
<
<=
begin
; ; ; ;


on lalr_verbose;

% Here I set up a sample grammar
%    S' -> S
%    S  -> C C        { }
%    C  -> "c" C      { }
%        | "d"        { }
% Example 4.42 from Aho, Sethi and Ullman's Red Dragon book, with
% some simple semantic actions added. Note that I do not need to insert
% the production S' -> S for myself since the analysis code will
% augment my grammar with it for me anyway.
% Example 4.54 in the more recent Purple book.

% Note that this grammar will introduce "c" and "d" as keywords rather than
% being general symbols. When I construct a subsequent grammar that will
% undo that setting. I will omit semantic actions here so that the default
% action of building a form of tree is used.

% Limitations are
% (1) I will need a way to specify precedence if this is to be feasibly
%     useful. I have some planning for this but have not implemented it yet.
% (2) At present the parser generator will not cope with large grammars
%     because it does not merge rules promptly enough.
% (3) The lexer is hand-written and can not readily be reconfigured for
%     use with languages other than rlisp. For instance it has use of "!"
%     as a character escape built into it.
%
%


grammar := '(
  (S  ((C C)    )   % One production for S, no semantic actions
  )
  (C  (("c" C)  )   % First production for C
      (("d")    )   % Second production for C
  ));

lalr_construct_parser grammar;

printc yyparse()$

c c c d c d ;

printc yyparse()$

d d ;


% Example 4.46 from the Red Dragon (4.61 in Aho, Lam, Sethi and Ullman,
% "Compilers: principles, techniques and tools", second edition 2007).

% The semantic actions here contain print statements that will
% print some sort of trace as the parsing progresses.

symbolic procedure neatprintc x;
 << if not zerop posn() then terpri();
    printc x >>;

g4_46 := '((S   ((L "=" R)   (neatprintc "## S => L = R")
                             (list 'equal !$1 !$3))
                ((R)         (neatprintc "## S => R")
                             !$1))
           (L   (("*" R)     (neatprintc "## L => * R")
                             (list 'star !$2))
                ((!:symbol)  (neatprintc "## L => symbol")
                             !$1))
           (R   ((L)         (neatprintc "## R => L")
                             !$1)));

lalr_construct_parser g4_46;

printc yyparse()$

leftsym = rightsym ;


printc yyparse()$

****abc = *def ;

#if nil  % Skip the rest of this test file...


% The next example will not work until I have precedence rules imlemented
% but is expected to be reasonably representative of natural small grammars.

gtest := '((S  ((P) !$1)
               ((S op P) (list !$2 !$1 !$3))
               (("-" P) (list 'minus !$2))
               (("+" P) !$2))
           (op (("+") 'plus)
               (("-") 'difference)
               (("*") 'times)
               (("/") 'quotient)
               (("**") 'expt)
               (("^") 'expt))
           (P  (("(" S ")") !$2)
               ((!:symbol) !$1)
               ((!:string) !$1)
               ((!:number) !$1)));

lalr_construct_parser gtest;

printc yyparse()$

a * (b/c + d/e) ^ 2 ^ g - "stringdata" ;


% Now a much more complicated grammar - one that recognizes the syntax of
% RLISP. In order to survive this grammar my paser generator will need to
% be extended to deal with ambiguous grammars both to cope with the
% standard problem of "dangling else" clauses and to use precedence
% declarations to disambiguate the uses of infix operators. Well at
% present the grammar is written in a grossly bloated form so that
% operator predcedence is hard wired into it... that too will need changing.

% Note that a naive implementaion of LALR parser table generation via
% initial construction of a full LR(1) table leads to ridiculous expense
% when processing a grammar of this scale.

rlisp_grammar := '(

(command         ((  cmnd sep ))
                 ((  end sep ))
                 ((  command cmnd sep ))
                 ((  command end sep ))
)


(sep             ((  ";" ))
                 ((  "$" ))
)


(proc_type       ((  "symbolic" ))
                 ((  "algebraic" ))
)


(proc_qual       ((  "expr" ))
                 ((  "macro" ))
                 ((  "smacro" ))
)


(sym_list        ((  ")" ))
                 ((  "," !:symbol sym_list ))
)


(infix           ((  "setq" ))
                 ((  "or" ))
                 ((  "and" ))
                 ((  "member" ))
                 ((  "memq" ))
                 ((  "=" ))
                 ((  "neq" ))
                 ((  "eq" ))
                 ((  ">=" ))
                 ((  ">" ))
                 ((  "<=" ))
                 ((  "<" ))
                 ((  "freeof" ))
                 ((  "+" ))
                 ((  "-" ))
                 ((  "*" ))
                 ((  "/" ))
                 ((  "^" ))
                 ((  "**" ))
                 ((  "." ))
)

(prefix          ((  "not" ))
                 ((  "+" ))
                 ((  "-" ))
)


(proc_head       ((  !:symbol ))
                 ((  !:symbol !:symbol ))
                 ((  !:symbol "(" ")" ))
                 ((  !:symbol "(" !:symbol sym_list ))
                 ((  prefix !:symbol ))
                 ((  !:symbol infix !:symbol ))
)


(proc_def        ((  "procedure" proc_head sep cmnd ))
                 ((  proc_type "procedure" proc_head sep cmnd ))
                 ((  proc_qual "procedure" proc_head sep cmnd ))
                 ((  proc_type proc_qual "procedure" proc_head sep cmnd ))
)


% The type "!:rlistat" is dodgy here... it doe snot (yet) exist!

(rlistat         ((  !:rlistat ))
                 ((  "in" ))
                 ((  "on" ))
)


(rltail          ((  expr ))
                 ((  expr "," rltail ))
)


(cmnd            ((  expr ))
                 ((  rlistat rltail ))
)


(if_stmt         ((  "if" expr "then" cmnd "else" cmnd ))
                 ((  "if" expr "then" cmnd ))
)


(for_update      ((  ":" expr ))
                 ((  "step" expr "until" expr ))
)


(for_action      ((  "do" ))
                 ((  "sum" ))
                 ((  "collect" ))
)


(for_inon        ((  "in" ))
                 ((  "on" ))
)


(for_stmt        ((  "for" !:symbol !:setq expr for_update for_action cmnd ))
                 ((  "for" "each" !:symbol for_inon expr for_action cmnd ))
                 ((  "foreach" !:symbol for_inon expr for_action cmnd ))
)


(while_stmt      ((  "while" expr "do" cmnd ))
)


(repeat_stmt     ((  "repeat" cmnd "until" expr ))
)


(return_stmt     ((  "return" ))
                 ((  "return" expr ))
)


(goto_stmt       ((  "goto" !:symbol ))
                 ((  "go" !:symbol ))
                 ((  "go" "to" !:symbol ))
)


(group_tail      ((  ">>" ))
                 ((  sep ">>" ))
                 ((  sep cmnd group_tail ))
)


(group_expr      ((  "<<" cmnd group_tail ))
)


(scalar_tail     ((  sep ))
                 ((  "," !:symbol scalar_tail ))
                 ((  "," integer scalar_tail ))
)


(scalar_def      ((  "scalar" !:symbol scalar_tail ))
                 ((  "integer" !:symbol scalar_tail ))
)


(scalar_defs     ((  scalar_def ))
                 ((  scalar_defs scalar_def ))
)


(block_tail      ((  "end" ))
                 ((  cmnd "end" ))
                 ((  !:symbol ":" block_tail ))
                 ((  cmnd sep block_tail ))
                 ((  sep block_tail ))
)

(block_expr      ((  "begin" scalar_defs block_tail ))
                 ((  "begin" block_tail ))
)


(lambda_vars     ((  sep ))
                 ((  "," !:symbol lambda_vars ))
)


(lambda_expr     ((  "lambda" !:symbol lambda_vars cmnd ))
                 ((  "lambda" "(" ")" sep cmnd ))
                 ((  "lambda" "(" !:symbol sym_list sep cmnd ))
)


(expr            ((  rx0 ))
                 ((  lx0 ))
)


(rx0             ((  lx0 "where" !:symbol "=" rx1 ))
                 ((  rx1 ))
)


(lx0             ((  lx0 "where" !:symbol "=" lx1 ))
                 ((  lx1 ))
)


(rx1             ((  lx2 ":=" rx1 ))
                 ((  rx2 ))
)


(lx1             ((  lx2 ":=" lx1 ))
                 ((  lx2 ))
)


(rx2tail         ((  rx3 ))
                 ((  lx3 "or" rx2tail ))
)

(rx2             ((  lx3 "or" rx2tail ))
                 ((  rx3 ))
)


(lx2tail         ((  lx3 ))
                 ((  lx3 "or" lx2tail ))
)

(lx2             ((  lx3 "or" lx2tail ))
                 ((  lx3 ))
)


(rx3tail         ((  rx4 ))
                 ((  lx4 "and" rx3tail ))
)

(rx3             ((  lx4 "and" rx3tail ))
                 ((  rx4 ))
)


(lx3tail         ((  lx4 ))
                 ((  lx4 "and" lx3tail ))
)

(lx3             ((  lx4 "and" lx3tail ))
                 ((  lx4 ))
)


(rx4             ((  "not" rx4 ))
                 ((  rx5 ))
)


(lx4             ((  "not" lx4 ))
                 ((  lx5 ))
)

% The fact that this lists "member" and "memq" (etc) here makes those names
% keywords, and so possibly disables use as function names as in
%    member(a, b)

(rx5             ((  lx6 "member" ry6 ))
                 ((  lx6 "memq" ry6 ))
                 ((  lx6 "=" ry6 ))
                 ((  lx6 "neq" ry6 ))
                 ((  lx6 "eq" ry6 ))
                 ((  lx6 ">=" ry6 ))
                 ((  lx6 ">" ry6 ))
                 ((  lx6 "<=" ry6 ))
                 ((  lx6 "<" ry6 ))
                 ((  lx6 "freeof" ry6 ))
                 ((  rx6 ))
)


(lx5             ((  lx6 "member" ly6 ))
                 ((  lx6 "memq" ly6 ))
                 ((  lx6 "=" ly6 ))
                 ((  lx6 "neq" ly6 ))
                 ((  lx6 "eq" ly6 ))
                 ((  lx6 ">=" ly6 ))
                 ((  lx6 ">" ly6 ))
                 ((  lx6 "<=" ly6 ))
                 ((  lx6 "<" ly6 ))
                 ((  lx6 "freeof" ly6 ))
                 ((  lx6 ))
)


(ry6             ((  "not" ry6 ))
                 ((  rx6 ))
)


(ly6             ((  "not" ly6 ))
                 ((  lx6 ))
)


(rx6tail         ((  ry6a ))
                 ((  ly6a "+" rx6tail ))
)

(rx6             ((  lx6a "+" rx6tail ))
                 ((  rx6a ))
)


(lx6tail         ((  ly6a ))
                 ((  ly6a "+" lx6tail ))
)

(lx6             ((  lx6a "+" lx6tail ))
                 ((  lx6a ))
)


(ry6a            ((  not ry6a ))
                 ((  rx6a ))
)


(rx6a            ((  lx6a "-" ry7 ))
                 ((  rx7 ))
)


(ly6a            ((  not ly6a ))
                 ((  lx6a ))
)


(lx6a            ((  lx6a "-" ly7 ))
                 ((  lx7 ))
)


(ry7             ((  not ry7 ))
                 ((  rx7 ))
)


(rx7             ((  "+" ry7 ))
                 ((  "-" ry7 ))
                 ((  rx8 ))
)


(ly7             ((  not ly7 ))
                 ((  lx7 ))
)


(lx7             ((  "+" ly7 ))
                 ((  "-" ly7 ))
                 ((  lx8 ))
)


(rx8tail         ((  ry9 ))
                 ((  ly9 "*" rx8tail ))
)

(rx8             ((  lx9 "*" rx8tail ))
                 ((  rx9 ))
)


(lx8tail         ((  ly9 ))
                 ((  ly9 "*" lx8tail ))
)

(lx8             ((  lx9 "*" lx8tail ))
                 ((  lx9 ))
)


(ry9             ((  "not" ry9 ))
                 ((  "+" ry9 ))
                 ((  "-" ry9 ))
                 ((  rx9 ))
)


(rx9             ((  lx9 "/" ry10 ))
                 ((  rx10 ))
)


(ly9             ((  "not" ly9 ))
                 ((  "+" ly9 ))
                 ((  "-" ly9 ))
                 ((  lx9 ))
)


(lx9             ((  lx9 "/" ly10 ))
                 ((  lx10 ))
)


(ly10            ((  "not" ly10 ))
                 ((  "+" ly10 ))
                 ((  "-" ly10 ))
                 ((  lx10 ))
)


(lx10            ((  lx11 "^" ly10 ))
                 ((  lx11 ))
)


(ry10            ((  "not" ry10 ))
                 ((  "+" ry10 ))
                 ((  "-" ry10 ))
                 ((  rx10 ))
)


(rx10            ((  lx11 "^" ry10 ))
                 ((  rx11 ))
)


(ry11            ((  "not" ry11 ))
                 ((  "+" ry11 ))
                 ((  "-" ry11 ))
                 ((  rx11 ))
)


(rx11            ((  x12 "." ry11 ))
                 ((  if_stmt ))
                 ((  for_stmt ))
                 ((  while_stmt ))
                 ((  repeat_stmt ))
                 ((  return_stmt ))
                 ((  goto_stmt ))
                 ((  lambda_expr ))
                 ((  proc_type ))
                 ((  proc_def ))
                 ((  endstat ))
)


(ly11            ((  "not" ly11 ))
                 ((  "+" ly11 ))
                 ((  "-" ly11 ))
                 ((  lx11 ))
)


(lx11            ((  x12 "." ly11 ))
                 ((  x12 ))
)


(arg_list        ((  expr ")" ))
                 ((  expr "," arg_list ))
)


(x12             ((  x13 "[" expr "]" ))
                 ((  x13 "(" ")" ))
                 ((  x13 "(" expr "," arg_list ))
                 ((  x13 x12 ))
                 ((  x13 ))
)


(x13             ((  !:symbol ))
                 ((  !:number ))
                 ((  !:string ))
                 ((  !:list ))     % Both 'xxx and `xxx here
                 ((  group_expr ))
                 ((  block_expr ))
                 ((  "(" expr ")" ))
)
)$


% lalr_construct_parser rlisp_grammar;

#endif

end;

