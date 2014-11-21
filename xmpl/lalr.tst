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
%     (LHS   ((rhs1.1 rhs1.2 ...) (a1.1 a1.2 ...))
%            ((rhs2.1 rhs2.1 ...) (a2.1 a2.2 ...))
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

load_package lalr;

% Before testing parser generation I will demonstrate the lexer..
%

lex_cleanup();

lex_keywords '("begin" "<=>" "<==");

% The output from this is expected to be

%  Result: (1 symbol)
%  Result: (3 200)
%  Result: (3 3.542)
%  Result: (2 "a string")
%  Result: (1 nil)
%  Result: (4 (quote (quoted lisp)))
%  Result: (4 (backquote (backquoted (!, comma) (!,!@ comma_at))))
%  Result: (1 !+)
%  Result: (1 !<!=!>)
%  Result: (1 !-)
%  Result: (1 !=)
%  Result: (1 !>)
%  Result: (1 !<)
%  Result: (1 !<!=)
%  Result: (5 begin)
%  Result: (1 null)
%  Result: (1 null)
%  Result: (1 null)
%
%  nil
%  null null null null 'x;

% The row of "null null null" at the end provides some protection so that
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
null
null
null null null null null 'x;


% Here I set up a sample grammar
%    S' -> S
%    S  -> C C        { A1 }
%    C  -> "cc" C     { A2 }
%        | "dd"       { A3 }
% Example 4.42 from Aho, Sethi and Ullman's Red Dragon book, with
% some simple semantic actions added. Note that I do not need to insert
% the production S' -> S for myself since the analysis code will
% augment my grammar with it for me anyway.
% Example 4.54 in the more recent Purple book.
% Well I have added a ";" terminator rather than risking running on for too
% long...

% Note that this grammar will introduce "c" and "d" as keywords rather than
% being general symbols. When I construct a subsequent grammar that will
% undo that setting. The semantic actions here illustrate the !$1, !$2 etc
% can be used to access the semantic result from each component in the
% rule that is matched.


% BEWARE. For now the names used for non-termninals must be disjoint from the
% spellings used for terminals. I will fix that bug at some stage!  Also I
% MUST have the "eof" on the end of the input text to allow yyparse to tell
% when to stop.

% Further limitations are
% (1) Semantic actions are not paid attentio to.
% (2) I will need a way to specify precedence if this is to be feasibly
%     useful.
% (3) At present the parser generator will not cope with large grammars
%     because it does not merge rules promptly enough.
% (4) The lexer is hand-written and can not readily be reconfigured for
%     use with languages other than rlisp. For instance it has use of "!"
%     as a character escape built into it.
%
%
% However if even one small grammar can be handled this is a strep forward!


grammar := '((S  ((C C) ((list !$1 !$2))))
             (C  (("cc" C) ((list 'c !$2)))
                 (("dd") ('d)))
            );

lalr_construct_parser grammar;

yyparse();

cc cc cc dd cc dd eof

yyparse();

dd dd eof

#if nil  % Skip the rest of this test file...


% Example 4.46 from the Red Dragon (4.61 in Aho, Lam, Sethi and Ullman,
% "Compilers: principles, techniques and tools", second edition 2007).

g4_46 := '((S   ((L "=" R)   ((print (list !$1 !$2 !$3))
                              (list 'equal !$1 !$3)))
                ((R)         (!$1)))
           (L   (("*" R)     ((print !$2) (list 'star !$2)))
                ((!:symbol)  (!$1)))
           (R   ((L)         (!$1))));

lalr_construct_parser g4_46;

yyparse();

leftsym = rightsym eof


yyparse();

****abc = *def eof


% The next example will not work until I have precedence rules imlemented
% but is expected to be reasonably representative of natural small grammars.

gtest := '((S  ((P) (!$1))
               ((S op P) ((list !$2 !$1 !$3)))
               (("-" P) (list 'minus !$2))
               (("+" P) (!$2)))
           (op (("+") ('plus))
               (("-") ('difference))
               (("*") ('times))
               (("/") ('quotient))
               (("**") ('expt))
               (("^") ('expt)))
           (P  (("(" S ")") (!$2))
               ((!:symbol) (!$1))
               ((!:string) (!$1))
               ((!:number) (!$1))));

lalr_construct_parser gtest;

yyparse();

a * (b/c + d/e) ^ 2 ^ g - "stringdata" eof 


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

(command         ((  cmnd sep ) (dummy_action))
                 ((  end sep ) (dummy_action))
                 ((  command cmnd sep ) (dummy_action))
                 ((  command end sep ) (dummy_action))
)


(sep             ((  ";" ) (dummy_action))
                 ((  "$" ) (dummy_action))
)


(proc_type       ((  "symbolic" ) (dummy_action))
                 ((  "algebraic" ) (dummy_action))
)


(proc_qual       ((  "expr" ) (dummy_action))
                 ((  "macro" ) (dummy_action))
                 ((  "smacro" ) (dummy_action))
)


(sym_list        ((  ")" ) (dummy_action))
                 ((  "," !:symbol sym_list ) (dummy_action))
)


(infix           ((  "setq" ) (dummy_action))
                 ((  "or" ) (dummy_action))
                 ((  "and" ) (dummy_action))
                 ((  "member" ) (dummy_action))
                 ((  "memq" ) (dummy_action))
                 ((  "=" ) (dummy_action))
                 ((  "neq" ) (dummy_action))
                 ((  "eq" ) (dummy_action))
                 ((  ">=" ) (dummy_action))
                 ((  ">" ) (dummy_action))
                 ((  "<=" ) (dummy_action))
                 ((  "<" ) (dummy_action))
                 ((  "freeof" ) (dummy_action))
                 ((  "+" ) (dummy_action))
                 ((  "-" ) (dummy_action))
                 ((  "*" ) (dummy_action))
                 ((  "/" ) (dummy_action))
                 ((  "^" ) (dummy_action))
                 ((  "**" ) (dummy_action))
                 ((  "." ) (dummy_action))
)

(prefix          ((  "not" ) (dummy_action))
                 ((  "+" ) (dummy_action))
                 ((  "-" ) (dummy_action))
)


(proc_head       ((  !:symbol ) (dummy_action))
                 ((  !:symbol !:symbol ) (dummy_action))
                 ((  !:symbol "(" ")" ) (dummy_action))
                 ((  !:symbol "(" !:symbol sym_list ) (dummy_action))
                 ((  prefix !:symbol ) (dummy_action))
                 ((  !:symbol infix !:symbol ) (dummy_action))
)


(proc_def        ((  "procedure" proc_head sep cmnd ) (dummy_action))
                 ((  proc_type "procedure" proc_head sep cmnd ) (dummy_action))
                 ((  proc_qual "procedure" proc_head sep cmnd ) (dummy_action))
                 ((  proc_type proc_qual "procedure" proc_head sep cmnd ) (dummy_action))
)


% The type "!:rlistat" is dodgy here... it doe snot (yet) exist!

(rlistat         ((  !:rlistat ) (dummy_action))
                 ((  "in" ) (dummy_action))
                 ((  "on" ) (dummy_action))
)


(rltail          ((  expr ) (dummy_action))
                 ((  expr "," rltail ) (dummy_action))
)


(cmnd            ((  expr ) (dummy_action))
                 ((  rlistat rltail ) (dummy_action))
)


(if_stmt         ((  "if" expr "then" cmnd "else" cmnd ) (dummy_action))
                 ((  "if" expr "then" cmnd ) (dummy_action))
)


(for_update      ((  ":" expr ) (dummy_action))
                 ((  "step" expr "until" expr ) (dummy_action))
)


(for_action      ((  "do" ) (dummy_action))
                 ((  "sum" ) (dummy_action))
                 ((  "collect" ) (dummy_action))
)


(for_inon        ((  "in" ) (dummy_action))
                 ((  "on" ) (dummy_action))
)


(for_stmt        ((  "for" !:symbol !:setq expr for_update for_action cmnd ) (dummy_action))
                 ((  "for" "each" !:symbol for_inon expr for_action cmnd ) (dummy_action))
                 ((  "foreach" !:symbol for_inon expr for_action cmnd ) (dummy_action))
)


(while_stmt      ((  "while" expr "do" cmnd ) (dummy_action))
)


(repeat_stmt     ((  "repeat" cmnd "until" expr ) (dummy_action))
)


(return_stmt     ((  "return" ) (dummy_action))
                 ((  "return" expr ) (dummy_action))
)


(goto_stmt       ((  "goto" !:symbol ) (dummy_action))
                 ((  "go" !:symbol ) (dummy_action))
                 ((  "go" "to" !:symbol ) (dummy_action))
)


(group_tail      ((  ">>" ) (dummy_action))
                 ((  sep ">>" ) (dummy_action))
                 ((  sep cmnd group_tail ) (dummy_action))
)


(group_expr      ((  "<<" cmnd group_tail ) (dummy_action))
)


(scalar_tail     ((  sep ) (dummy_action))
                 ((  "," !:symbol scalar_tail ) (dummy_action))
                 ((  "," integer scalar_tail ) (dummy_action))
)


(scalar_def      ((  "scalar" !:symbol scalar_tail ) (dummy_action))
                 ((  "integer" !:symbol scalar_tail ) (dummy_action))
)


(scalar_defs     ((  scalar_def ) (dummy_action))
                 ((  scalar_defs scalar_def ) (dummy_action))
)


(block_tail      ((  "end" ) (dummy_action))
                 ((  cmnd "end" ) (dummy_action))
                 ((  !:symbol ":" block_tail ) (dummy_action))
                 ((  cmnd sep block_tail ) (dummy_action))
                 ((  sep block_tail ) (dummy_action))
)

(block_expr      ((  "begin" scalar_defs block_tail ) (dummy_action))
                 ((  "begin" block_tail ) (dummy_action))
)


(lambda_vars     ((  sep ) (dummy_action))
                 ((  "," !:symbol lambda_vars ) (dummy_action))
)


(lambda_expr     ((  "lambda" !:symbol lambda_vars cmnd ) (dummy_action))
                 ((  "lambda" "(" ")" sep cmnd ) (dummy_action))
                 ((  "lambda" "(" !:symbol sym_list sep cmnd ) (dummy_action))
)


(expr            ((  rx0 ) (dummy_action))
                 ((  lx0 ) (dummy_action))
)


(rx0             ((  lx0 "where" !:symbol "=" rx1 ) (dummy_action))
                 ((  rx1 ) (dummy_action))
)


(lx0             ((  lx0 "where" !:symbol "=" lx1 ) (dummy_action))
                 ((  lx1 ) (dummy_action))
)


(rx1             ((  lx2 ":=" rx1 ) (dummy_action))
                 ((  rx2 ) (dummy_action))
)


(lx1             ((  lx2 ":=" lx1 ) (dummy_action))
                 ((  lx2 ) (dummy_action))
)


(rx2tail         ((  rx3 ) (dummy_action))
                 ((  lx3 "or" rx2tail ) (dummy_action))
)

(rx2             ((  lx3 "or" rx2tail ) (dummy_action))
                 ((  rx3 ) (dummy_action))
)


(lx2tail         ((  lx3 ) (dummy_action))
                 ((  lx3 "or" lx2tail ) (dummy_action))
)

(lx2             ((  lx3 "or" lx2tail ) (dummy_action))
                 ((  lx3 ) (dummy_action))
)


(rx3tail         ((  rx4 ) (dummy_action))
                 ((  lx4 "and" rx3tail ) (dummy_action))
)

(rx3             ((  lx4 "and" rx3tail ) (dummy_action))
                 ((  rx4 ) (dummy_action))
)


(lx3tail         ((  lx4 ) (dummy_action))
                 ((  lx4 "and" lx3tail ) (dummy_action))
)

(lx3             ((  lx4 "and" lx3tail ) (dummy_action))
                 ((  lx4 ) (dummy_action))
)


(rx4             ((  "not" rx4 ) (dummy_action))
                 ((  rx5 ) (dummy_action))
)


(lx4             ((  "not" lx4 ) (dummy_action))
                 ((  lx5 ) (dummy_action))
)

% The fact that this lists "member" and "memq" (etc) here makes those names
% keywords, and so possibly disables use as function names as in
%    member(a, b)

(rx5             ((  lx6 "member" ry6 ) (dummy_action))
                 ((  lx6 "memq" ry6 ) (dummy_action))
                 ((  lx6 "=" ry6 ) (dummy_action))
                 ((  lx6 "neq" ry6 ) (dummy_action))
                 ((  lx6 "eq" ry6 ) (dummy_action))
                 ((  lx6 ">=" ry6 ) (dummy_action))
                 ((  lx6 ">" ry6 ) (dummy_action))
                 ((  lx6 "<=" ry6 ) (dummy_action))
                 ((  lx6 "<" ry6 ) (dummy_action))
                 ((  lx6 "freeof" ry6 ) (dummy_action))
                 ((  rx6 ) (dummy_action))
)


(lx5             ((  lx6 "member" ly6 ) (dummy_action))
                 ((  lx6 "memq" ly6 ) (dummy_action))
                 ((  lx6 "=" ly6 ) (dummy_action))
                 ((  lx6 "neq" ly6 ) (dummy_action))
                 ((  lx6 "eq" ly6 ) (dummy_action))
                 ((  lx6 ">=" ly6 ) (dummy_action))
                 ((  lx6 ">" ly6 ) (dummy_action))
                 ((  lx6 "<=" ly6 ) (dummy_action))
                 ((  lx6 "<" ly6 ) (dummy_action))
                 ((  lx6 "freeof" ly6 ) (dummy_action))
                 ((  lx6 ) (dummy_action))
)


(ry6             ((  "not" ry6 ) (dummy_action))
                 ((  rx6 ) (dummy_action))
)


(ly6             ((  "not" ly6 ) (dummy_action))
                 ((  lx6 ) (dummy_action))
)


(rx6tail         ((  ry6a ) (dummy_action))
                 ((  ly6a "+" rx6tail ) (dummy_action))
)

(rx6             ((  lx6a "+" rx6tail ) (dummy_action))
                 ((  rx6a ) (dummy_action))
)


(lx6tail         ((  ly6a ) (dummy_action))
                 ((  ly6a "+" lx6tail ) (dummy_action))
)

(lx6             ((  lx6a "+" lx6tail ) (dummy_action))
                 ((  lx6a ) (dummy_action))
)


(ry6a            ((  not ry6a ) (dummy_action))
                 ((  rx6a ) (dummy_action))
)


(rx6a            ((  lx6a "-" ry7 ) (dummy_action))
                 ((  rx7 ) (dummy_action))
)


(ly6a            ((  not ly6a ) (dummy_action))
                 ((  lx6a ) (dummy_action))
)


(lx6a            ((  lx6a "-" ly7 ) (dummy_action))
                 ((  lx7 ) (dummy_action))
)


(ry7             ((  not ry7 ) (dummy_action))
                 ((  rx7 ) (dummy_action))
)


(rx7             ((  "+" ry7 ) (dummy_action))
                 ((  "-" ry7 ) (dummy_action))
                 ((  rx8 ) (dummy_action))
)


(ly7             ((  not ly7 ) (dummy_action))
                 ((  lx7 ) (dummy_action))
)


(lx7             ((  "+" ly7 ) (dummy_action))
                 ((  "-" ly7 ) (dummy_action))
                 ((  lx8 ) (dummy_action))
)


(rx8tail         ((  ry9 ) (dummy_action))
                 ((  ly9 "*" rx8tail ) (dummy_action))
)

(rx8             ((  lx9 "*" rx8tail ) (dummy_action))
                 ((  rx9 ) (dummy_action))
)


(lx8tail         ((  ly9 ) (dummy_action))
                 ((  ly9 "*" lx8tail ) (dummy_action))
)

(lx8             ((  lx9 "*" lx8tail ) (dummy_action))
                 ((  lx9 ) (dummy_action))
)


(ry9             ((  "not" ry9 ) (dummy_action))
                 ((  "+" ry9 ) (dummy_action))
                 ((  "-" ry9 ) (dummy_action))
                 ((  rx9 ) (dummy_action))
)


(rx9             ((  lx9 "/" ry10 ) (dummy_action))
                 ((  rx10 ) (dummy_action))
)


(ly9             ((  "not" ly9 ) (dummy_action))
                 ((  "+" ly9 ) (dummy_action))
                 ((  "-" ly9 ) (dummy_action))
                 ((  lx9 ) (dummy_action))
)


(lx9             ((  lx9 "/" ly10 ) (dummy_action))
                 ((  lx10 ) (dummy_action))
)


(ly10            ((  "not" ly10 ) (dummy_action))
                 ((  "+" ly10 ) (dummy_action))
                 ((  "-" ly10 ) (dummy_action))
                 ((  lx10 ) (dummy_action))
)


(lx10            ((  lx11 "^" ly10 ) (dummy_action))
                 ((  lx11 ) (dummy_action))
)


(ry10            ((  "not" ry10 ) (dummy_action))
                 ((  "+" ry10 ) (dummy_action))
                 ((  "-" ry10 ) (dummy_action))
                 ((  rx10 ) (dummy_action))
)


(rx10            ((  lx11 "^" ry10 ) (dummy_action))
                 ((  rx11 ) (dummy_action))
)


(ry11            ((  "not" ry11 ) (dummy_action))
                 ((  "+" ry11 ) (dummy_action))
                 ((  "-" ry11 ) (dummy_action))
                 ((  rx11 ) (dummy_action))
)


(rx11            ((  x12 "." ry11 ) (dummy_action))
                 ((  if_stmt ) (dummy_action))
                 ((  for_stmt ) (dummy_action))
                 ((  while_stmt ) (dummy_action))
                 ((  repeat_stmt ) (dummy_action))
                 ((  return_stmt ) (dummy_action))
                 ((  goto_stmt ) (dummy_action))
                 ((  lambda_expr ) (dummy_action))
                 ((  proc_type ) (dummy_action))
                 ((  proc_def ) (dummy_action))
                 ((  endstat ) (dummy_action))
)


(ly11            ((  "not" ly11 ) (dummy_action))
                 ((  "+" ly11 ) (dummy_action))
                 ((  "-" ly11 ) (dummy_action))
                 ((  lx11 ) (dummy_action))
)


(lx11            ((  x12 "." ly11 ) (dummy_action))
                 ((  x12 ) (dummy_action))
)


(arg_list        ((  expr ")" ) (dummy_action))
                 ((  expr "," arg_list ) (dummy_action))
)


(x12             ((  x13 "[" expr "]" ) (dummy_action))
                 ((  x13 "(" ")" ) (dummy_action))
                 ((  x13 "(" expr "," arg_list ) (dummy_action))
                 ((  x13 x12 ) (dummy_action))
                 ((  x13 ) (dummy_action))
)


(x13             ((  !:symbol ) (dummy_action))
                 ((  !:number ) (dummy_action))
                 ((  !:string ) (dummy_action))
                 ((  !:list ) (dummy_action))     % Both 'xxx and `xxx here
                 ((  group_expr ) (dummy_action))
                 ((  block_expr ) (dummy_action))
                 ((  "(" expr ")" ) (dummy_action))
)
)$


% lalr_construct_parser rlisp_grammar;

#endif

end;
