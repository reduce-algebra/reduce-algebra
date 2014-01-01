
% Test cases for the parser generator. This all runs in
% symbolic mode...

symbolic;

% Here I set up a sample grammar
%    S' -> S
%    S  -> CC      { A1 }
%    C  -> cC      { A2 }
%        | d       { A3 }
% Example 4.42 from Aho, Sethi and Ullman's Red Dragon book, with
% some dummy semantic actions added. Note that I do not need to insert
% the production S' -> S for myself since the analysis code will
% augment my grammar with it for me anyway.
% Example 4.54 in the more recent Purple book.

grammar := '((S  ((C C) A1))
             (C  ((cc C) A2)
                 ((dd) A3))
            );

lalr_construct_parser grammar;

yyparse();

cc cc cc dd cc dd eof

yyparse();

dd dd eof




% Example 4.46 from the Red Dragon (4.61 in Aho, Lam, Sethi and Ullman,
% "Compilers: principles, techniques and tools", second edition 2007).

g4_46 := '((S   ((L "=" R) a1)
                ((R)       a2))
           (L   (("*" R)   a3)
                ((!:symbol)  a4))
           (R   ((L)       a5)));

lalr_construct_parser g4_46;

yyparse();

leftsym = rightsym eof


yyparse();

****xxx = *x eof

end;  % for now...

% Now a much more complicated grammar - one that recognizes the syntax of
% RLISP. In order to survice this grammar my paser generator will need to
% be extended to deal with ambiguous grammars both to cope with the
% standard problem of "dangling else" clauses and to use precedence
% declarations to disambiguate the uses of infix operators. Well at
% present the grammar is written in a grossly bloated form so that
% operator predcedence is hard wired into it... that too will need changing.

% Note that a naive implementaion of LALR parser table generation via
% initial construction of a full LR(1) table leads to ridiculous expense
% when processing a grammar of this scale.

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

