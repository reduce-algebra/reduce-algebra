% This is a grammar file that has NOT been tested and will almost
% certainly (a) not work at all and (b) to the extent that it will
% the parser generator will use ridiculous levels of resource trying
% to process it. I leave it here in case anybody want to build from
% it (eg altering it to use precedence rules rather than the extremely
% heavily written oput sets of productions given here.
% But if you really want an rlisp parser you should probably start afresh
% rather than with this! Also this has no semantic actions and so is
% somewhat useless in its current form.!
%
%                                             A C Norman. December 2014


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


lalr_construct_parser rlisp_grammar;

