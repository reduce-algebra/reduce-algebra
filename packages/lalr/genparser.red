% genparser.red


%==============================================================================
% This is a LALR(1) parser generator, which takes the specification of an 
% appropriate grammar and outputs a parser for that grammar. The parser 
% consists of a set of tables and other information intended to be used by
% yyparse.red's yyparse() procedure. 
%
% The core algorithm is the "efficient" construction given by the Dragon Book,
% where the LR(0) itemset collection is generated and then transformed into
% the LALR itemset collection by a process of spontaneous generation and
% propagation of lookaheads.
%==============================================================================

% Copyright Zach Hauser and Arthur Norman, 2016

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
% 

% $Id$

%==============================================================================
% Fluid Variables & Symbol Properties (& general notes)
%==============================================================================

% These four structures are created early on by lalr_set_grammar() for later
% reference. The first two are lists of grammar symbols: symbols contains 
% all nonterminals and terminals, while nonterminals contains only those. 
%
% This is a logical place to explain that, after lalr_set_grammar() does its 
% work, nonterminals are represented as Lisp symbols while terminals are 
% represented by their respective lexer category codes (integers), obtained 
% from yylex.red. For this reason, the code occasionally uses numberp and idp 
% to determine whether a particular grammar symbol is a terminal or nonterminal.
%
% lex_context is the data structure representing a particular parser's lexer. 
% It is obtained from lex_save_context() in yylex.red in order to be later
% fed into lex_restore_context() to "switch back" to the appropriate lexer. 
% It is not examined or deconstructed in this file, but merely stored early on
% in order to be included in the final structure representing the parser that
% is constructed.
%
% The precedence_table stores information about the precedence and 
% associativity of terminals (if provided). It is a vector indexed by terminal
% (i.e., by lexer category code), where each entry is a dotted pair of 
% precedence (an integer, with 0 indicating the highest precedence and higher 
% numbers indicating lower precedence) and associativity (!:right, !:left, or
% !:none). lalr_precedence and lalr_associativity are provided as convenience
% functions for reading from the precedence_table. 
fluid '(symbols nonterminals lex_context precedence_table);

symbolic procedure lalr_precedence terminal;
  begin 
    scalar x;
    if (x := getv(precedence_table, terminal)) then
      return car x
  end;

symbolic procedure lalr_associativity terminal;
  begin 
    scalar x;
    if (x := getv(precedence_table, terminal)) then 
      return cdr x
  end;

% The following structure is provided for use by genparserprint.red, in which 
% lives all the code for printing diagnostic information during the parser 
% generation process. It is a simple association list from lexer category code
% to the terminal as a Lisp symbol.
fluid '(terminal_codes nonterminal_codes);

fluid '(reduction_info);

% Together, the following two structures represent the collection of itemsets 
% (first LR(0) and then LALR) used to construct the parsing tables.
%
% The itemset_collection is a list of indexed itemsets (dotted pair of itemset   
% and integer index), where each itemset is a list of items. Initially, when 
% the items are LR(0), the item [A -> ab.cd] would be represented as simply 
%         '(A a b !. c d). 
% When the items are LALR, the item [A -> ab.cd, u/v/x] would be represented as 
%         '((A a b !. c d) u v x). 
%
% The goto_table describes the GOTO transitions between the itemsets. It is 
% implemented as a hashtable of alists, as follows. If B = GOTO(A, X) where 
% A,B are itemsets and X is a grammar symbol (terminal or nonterminal), then 
% gethash(X, goto_table) will return an alist containing the entry (A . B). 
% Note that A,B are the actual indexed itemset objects from itemset_collection.
%
% lalr_add_goto and lalr_goto are provided as convenience functions
% for constructing and reading from the goto_table.
%
% Both itemset_collection (as the LR(0) collection) and goto_table are  
% initially constructed by lalr_generate_lr0_collection(), and 
% lalr_generate_collection() then modifies itemset_collection by adding 
% lookaheads to convert it into the LALR collection.  
fluid '(itemset_collection goto_table);

symbolic procedure lalr_add_goto(src, x, dest);
  puthash(x, goto_table, (src . dest) . gethash(x, goto_table));

symbolic procedure lalr_goto(src, x);
  begin 
    scalar result_i_itemset;
    if result_i_itemset := assoc(src, gethash(x, goto_table)) then
      return cdr result_i_itemset 
    else  
      return nil
  end;

% In addition to the fluid variables described above, we store data relating 
% to each nonterminal in its property list (temporarily lalr_cleanup() clears 
% these properties out at the very end). 
% 
% For some nonterminal X:
% 
% 'lalr_produces holds a list of productions, where each production is a dotted
% pair of right-hand-side and semantic action. For example, if there is a 
% production [X -> a "+" b {plus !$1 !$3}], then the list of productions will
% include '((a "+" b) plus !$1 !$3).
% 
% 'lalr_first holds the list of terminals that make up the FIRST set of X, as
% defined by the Dragon Book.
%
% 'lalr_nonterminal_code holds a unique integer code for X. These are assigned
% by lalr_set_grammar() but not actually used until the construction of the 
% parser tables. (As mentioned, throughout almost all the parser generation, 
% code, nonterminals are stored as Lisp symbols).
%
% lalr_productions is a convenience function for accessing the 'lalr_produces
% property.

symbolic procedure lalr_productions x;
  get(x, 'lalr_produces);

%==============================================================================



%==============================================================================
% lalr_create_parser() main driver function and entry point for genparser.red,
%                        and its cleanup function lalr_cleanup().
%==============================================================================

% This function is the entry point for genparser.red -- ideally the only 
% function that users of this code need to worry about. It receives the 
% complete description of a grammar, and returns a LALR parser for that grammar.
%
% precedence_list: an optional (can be nil) list of operator precedence
%                  declarations, ordered by decreasing precedence. Each element
%                  of the list is either 
%                     - a single terminal symbol
%                     - a list of terminal symbols (which indicates that they 
%                       all share the same precedence level)
%                     - an associativity directive (!:right, !:left, or !:none),
%                       which applies until the next associativity directive in
%                       the list (note: the default associativity is !:left)
%                  For example:
%                     '(!:right "^" !:left ("*" "/") ("+" "-") !:none "=")
% 
% grammar: the grammar is passed as a list of rules. Each rule is a dotted pair
%          of nonterminal and a list of productions, where each production is a
%          dotted pair of right-hand-side and semantic action. For example, the
%          toy expression grammar
%             expr   -> expr "+" expr { plus !$1 !$3 } | 
%                       expr "*" expr { times !$1 !$3 } | 
%                       number 
%             number -> "~" <number> { minus !$1} |
%                       <number>
%          would be represented by the structure
%             '((expr   ((expr "+" expr) plus !$1 !$3)
%                       ((expr "*" expr) times !$1 $3)
%                       ((number)))
%               (number (("~" !:number) minus !$1)
%                       ((!:number))))
%          Note that terminals are represented by strings or one of the special
%          tokens recognized by the core lexer: !:symbol, !:string, or !:number.  %% test and add the others
%          Nonterminals are represented by symbols. 
%
% In addition it will be possible to write shorthand items on the right
% hand side of a production:
%        (opt X Y Z)
%        (star X Y Z)
%        (plus X Y Z)
%        (list S X Y Z)
%        (listplus S X Y Z)
%        (or A B C)
% where each are replaced by a new non-terminal G and a further rule(s)
% are then added:
%
% (opt X Y Z) is either X Y Z or nothing
%   (G (())              % value will be either nil or (list X Y Z)
%      ((X Y Z)))        % or if only one item X then X.
%
% (star X Y Z) is zero or more repetitions of X Y Z, and the
% value it returns is a list of whatever each X Y Z generated
%   (G (())              % value is a list of items in the sequence
%      ((G1 G) (cons !$1 !$2)))
%   (G1 ((X Y Z))
%
% (plus X Y Z) is like (star X Y Z) except that it demands at least
% one instance of X Y Z is present.
%   (G  ((G1) (list !$1))
%       ((G1 G) (cons !$1 !$2))) 
%   (G1 ((X Y Z)))
%
% (list del X Y Z) gives a sequence of X Y Z entities with del as a
% separator. A typical use might be in
%   (funcall ((!:symbol "("
%                       (list "," expression)
%                       ")")) (cons !$1 !$3))
% to recognise function calls such as "f(A,B,C)" in a typical language.  
%   (G  (())
%       ((G2 G1) (cons !$1 !$2))
%   (G1 (())
%       ((del G2 G1) (cons !$2 !$3)))
%   (G2 ((X Y Z)))
%
% (listplus del X Y Z) is just like (list del X Y Z) except that it demands
% at least one item.
%   (G  ((G2 G1) (cons !$1 !$2))
%   (G1 (())
%       ((del G2 G1) (cons !$2 !$3)))
%   (G2 ((X Y Z)))
%
% (or A B C) is for one of the given symbols
%   (G ((A))
%      ((B))
%      ((C)))
%
%
%
% returns: a structure representing a complete LALR parser (and associated 
%          lexer) for the given grammar. The structure is intended to be passed
%          as the argument to yyparse() in yyparse.red. 
symbolic procedure lalr_create_parser (precedence_list, grammar);
  begin

    % These are the fluid variables described above and used by the rest of the 
    % code, plus the parser tables themselves.
    scalar symbols, nonterminals, lex_context, precedence_table, 
           terminal_codes, itemset_collection, goto_table, 
           reduction_info, compressed_action_table, compressed_goto_table;

    % Analyze the grammar, setting fluid variables and symbol properties
    % for further reference and modification. After this, we don't need to 
    % look at the arguments (precedence_list and grammar) again.
    lalr_set_grammar(precedence_list, lalr_expand_grammar grammar);

    % Generate the LR(0) itemset collection and then convert it to the final 
    % LALR(1) itemset collection. After this, all the fluid variables are in
    % their final state.
    goto_table := mkhash(length symbols, 1, 1.5);
    lalr_generate_lr0_collection();
    lalr_generate_collection();

    % Assign each unique "reduction" a numerical code and store the relevant
    % information for each reduction in a single structure. The parser's action
    % table will refer to each reduction by its code.
    reduction_info := lalr_process_reductions();

    % Analyze the LALR(1) itemset collection to create the parser's action
    % and goto tables (as described by the Dragon Book).  
    compressed_action_table := lalr_make_compressed_action_table();
    compressed_goto_table := lalr_make_compressed_goto_table();

    % The only global state we've polluted is the nonterminal symbols' 
    % property lists, so we clean that up here. 
    lalr_cleanup();

    return list(lex_context, compressed_action_table, reduction_info, 
                compressed_goto_table, nonterminal_codes, terminal_codes)
  end; 

symbolic procedure lalr_cleanup();
  for each symbol in symbols do if idp symbol then <<
    put(symbol, 'lalr_produces, nil);
    put(symbol, 'lalr_first, nil);
    put(symbol, 'lalr_nonterminal_code, nil) >>;

%==============================================================================

%
% Deal with the grammar features that can be covered by a form of macro
% expansion. So for instance (star XXX) will expand into rules that
% accept zero or more instances of whatever XXX would match.

fluid '(pending_rules!*);

symbolic procedure lalr_expand_grammar g;
  begin
    scalar pending_rules!*, w, r;
    pending_rules!* := g;
% The use of the fluid variable pending_rules!* here is because when I
% expand one rule that may generate othersd which willl themselves in turn
% need to be scanned.
    while pending_rules!* do <<
      w := car pending_rules!*;
      pending_rules!* := cdr pending_rules!*;
      r := (expand_rule w) . r >>;
    return reverse r
  end;

symbolic procedure expand_rule u;
  car u .
    for each x in cdr u collect
      ((for each y in car x collect expand_terminal y) . cdr x);

global '(expansion_count);
expansion_count := 0;

symbolic procedure expansion_name();
  compress append(explode 'lalr_internal_,
      explode (expansion_count := expansion_count + 1));

symbolic procedure expand_terminal z;
  begin
    scalar g1, g2, g3;
    if atom z then return z
    else if eqcar(z, 'opt) then <<
      g1 := expansion_name();
      pending_rules!* :=
        list(g1,
             '(()),
             list cdr z) . pending_rules!*;
      return g1 >>
    else if eqcar(z, 'star) then <<
      g1 := expansion_name();
      g2 := expansion_name();
      if cdr z and null cddr z and atom cadr z then g2 := cadr z
      else pending_rules!* := list(g2, list cdr z) . pending_rules!*;
      pending_rules!* :=
        list(g1,
             '(()),
             list(list(g2, g1), '(cons !$1 !$2))) . pending_rules!*;
      return g1 >>
    else if eqcar(z, 'plus) then <<
      g1 := expansion_name();
      g2 := expansion_name();
      if cdr z and null cddr z and atom cadr z then g2 := cadr z
      else pending_rules!* := list(g2, list cdr z) . pending_rules!*;
      pending_rules!* :=
        list(g1,
             list(list g2, '(list !$1)),
             list(list(g2, g1), '(cons !$1 !$2))) . pending_rules!*;
      return g1 >>
    else if eqcar(z, 'list) and cdr z then <<
      g1 := expansion_name();
      g2 := expansion_name();
      g3 := expansion_name();
      if cddr z and null cdddr z and atom caddr z then g2 := caddr z
      else pending_rules!* := list(g2, list cddr z) . pending_rules!*;
      pending_rules!* :=
        list(g3,
             '(()),
             list(list(cadr z, g2, g3), '(cons !$2 !$3))) . pending_rules!*;
      pending_rules!* :=
        list(g1,
             '(()),
             list(list(g2, g3), '(cons !$1 !$2))) . pending_rules!*;
      return g1 >>
    else if eqcar(z, 'listplus) and cdr z then <<
      g1 := expansion_name();
      g2 := expansion_name();
      g3 := expansion_name();
      if cddr z and null cdddr z and atom caddr z then g2 := caddr z
      else pending_rules!* := list(g2, list cddr z) . pending_rules!*;
      pending_rules!* :=
        list(g3,
             '(()),
             list(list(cadr z, g2, g3), '(cons !$2 !$3))) . pending_rules!*;
      pending_rules!* :=
        list(g1,
             list(list(g2, g3), '(cons !$1 !$2))) . pending_rules!*;
      return g1 >>
    else if eqcar(z, 'or) then <<
      g1 := expansion_name();
      pending_rules!* :=
        (g1 . for each q in cdr z collect list list q) . pending_rules!*;
      return g1 >>
    else error(0, "Invalid item in a rule")
  end;



%==============================================================================



%==============================================================================
% lalr_set_grammar()   this section analyzes the precedence_list and grammar
%                      structure, stashing all the information the rest of the
%                      code will need in fluid variables and symbol property
%                      lists. 
%==============================================================================

symbolic procedure carrassoc(key, alist);
  begin
    scalar w;
    if not atom (w := rassoc(key, alist)) then return car w;
    terpri();
    princ "RASSOC trouble: "; prin key; princ " "; print alist;
    rederr "rassoc trouble"
  end;

symbolic procedure lalr_set_grammar(precedence_list, grammar);
  begin
    scalar terminals; 
    grammar := lalr_augment_grammar grammar;

    nonterminals := lalr_collect_nonterminals grammar;
    terminals := lalr_collect_terminals grammar;
    terminal_codes := lalr_get_lex_codes terminals;
    lalr_set_nonterminal_codes();

    precedence_table := lalr_create_precedence_table (precedence_list, 
                                                      terminal_codes);

    lalr_process_productions(grammar, terminal_codes);

    lalr_precalculate_first_sets();

    terminals := for each terminal in terminals collect  
                    carrassoc(intern terminal, terminal_codes);
    symbols := append(nonterminals, terminals);

    if !*lalr_verbose then <<
      lalr_print_terminals_and_codes terminals;
      lalr_print_nonterminals_and_productions();
      lalr_print_first_information() >>
  end;

symbolic procedure lalr_augment_grammar grammar;
  begin
    if assoc('!S!', grammar) then
      return grammar
    else 
      return list('!S!', list list caar grammar) . grammar
  end;

symbolic procedure lalr_create_precedence_table (precedence_list, lex_codes);
  begin
    scalar table, associativity, next_precedence, terminal_code, w;
    table := mkvect caar lex_codes;
    next_precedence := 0;
    associativity := '!:left;
    for each x in precedence_list do <<
      if x member '(!:left !:none !:right) then 
        associativity := x
      else <<
        for each xx in (if atom x then list x else x) do <<
          w := rassoc(intern xx, lex_codes);
% The precedence information could perhaps try to specify a precedence for
% some symbol not used in the grammar, and then rassoc here would have
% returned nil. Ignore settings on such symbols.
          if w then <<
            terminal_code := car w;
            putv(table, terminal_code, next_precedence . associativity) >> >>;
        next_precedence := next_precedence + 1 >> >>;
    return table
  end;

symbolic procedure lalr_set_nonterminal_codes;
  begin
    scalar code;
    code := 0;
    for each x in nonterminals do <<
      if x = '!S!' then 
        put(x, 'lalr_nonterminal_code, -1)
      else <<
        put(x, 'lalr_nonterminal_code, code);
        if !*lalr_verbose then 
          nonterminal_codes := (code . x) . nonterminal_codes;
        code := code + 1 >> >>;
      if !*lalr_verbose then 
        nonterminal_codes := ((-1) . '!S!') . nonterminal_codes;
  end;

symbolic procedure lalr_process_productions(grammar, lex_codes);
  begin
    scalar x, productions, productions_processed, w, rule, semantic_action;
    for each productions in grammar do <<
      x := car productions;
      productions_processed := nil;
      for each production in cdr productions do <<
        rule := car production;
        semantic_action := cdr production;
        rule := for each symbol in rule collect
                  (if (intern symbol) member nonterminals then 
                     intern symbol
                   else
                     carrassoc(intern symbol, lex_codes));
        production := rule . semantic_action;
        productions_processed := production . productions_processed >>;
      if (w := get(intern x, 'lalr_produces)) then
        productions_processed := append(w, productions_processed);
      put(intern x, 'lalr_produces, productions_processed) >>
  end;

symbolic procedure lalr_precalculate_first_sets;
  begin
    scalar more_added, x_first_set, rhs, w;
    repeat << 
      more_added := nil;
      for each x in nonterminals do <<
        x_first_set := get(x, 'lalr_first);
        for each production in lalr_productions x do <<
          rhs := car production;
          while rhs and 
                not numberp car rhs and 
                member(nil, (w := get(car rhs, 'lalr_first))) do <<
            x_first_set := union(delete(nil, w), x_first_set);
            rhs := cdr rhs >>;
          if null rhs then 
            x_first_set := union('(nil), x_first_set)
          else if numberp car rhs then 
            x_first_set := union(list car rhs, x_first_set)
          else
            x_first_set := union(get(car rhs, 'lalr_first), x_first_set) >>;
        if x_first_set neq get(x, 'lalr_first) then <<
          more_added := t;
          put(x, 'lalr_first, x_first_set) >> >>
    >> until not more_added
  end;

symbolic procedure lalr_collect_nonterminals grammar;
  lalr_remove_duplicates 
    (for each productions in grammar collect intern car productions);

symbolic procedure lalr_collect_terminals grammar; 
  begin
    scalar rhs_symbols;
    for each productions in grammar do 
      for each production in cdr productions do 
        for each symbol in car production do 
          if not (symbol member rhs_symbols) then
            rhs_symbols := symbol . rhs_symbols;
    return setdiff(rhs_symbols, nonterminals)
  end;

symbolic procedure lalr_get_lex_codes terminals;
  begin
    scalar nonstandard_terminals, prev_lex_context, lex_codes;
    for each terminal in terminals do
      if stringp terminal then 
        nonstandard_terminals := terminal . nonstandard_terminals;
    prev_lex_context := lex_save_context();
    lex_cleanup();
    lex_keywords nonstandard_terminals;
    lex_context := lex_save_context();
    lex_codes := lex_export_codes();
    lex_restore_context(prev_lex_context);
    return lex_codes
  end;







%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This section generates the LR0 item collection.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Generates the collection of LR(0) itemsets for the grammar (which must have
% already been analyzed by lalr_set_grammar, so that lalr_productions works
% and the symbols list exists).
%
% Effects: initializes itemset_collection and goto_table
%
% The algorithm is taken from the Dragon Book (Figure 4.33), but arranges to 
% process each itemset only once.
symbolic procedure lalr_generate_lr0_collection;
  begin
    scalar pending, previous_i, i_itemset, itemset, 
           goto_itemset, goto_itemset1, i_goto_itemset;
    itemset_collection := list (lalr_lr0_initial_itemset() . 0);
    pending := list car itemset_collection;    
    previous_i := 0;

    while pending do <<
      i_itemset := car pending;
      pending := cdr pending;
      itemset := car i_itemset;

      % For each grammar symbol, compute the goto itemset. If we've already
      % discovered this itemset, simply update the goto_table. If it's new, 
      % allocate it an index and add it to itemset_collection first. 
      for each x in symbols do <<
        if goto_itemset := lalr_compute_lr0_goto(itemset, x) then <<
          if goto_itemset1 := assoc(goto_itemset, itemset_collection) then
            i_goto_itemset := goto_itemset1  
          else <<
            i_goto_itemset := goto_itemset . (previous_i := previous_i + 1);
            itemset_collection := i_goto_itemset . itemset_collection;
            pending := i_goto_itemset . pending >>;
          lalr_add_goto(i_itemset, x, i_goto_itemset) >> >> >>;

    %% if !*lalr_verbose then 
    %%  lalr_print_lr0_collection()
  end;

% Simply constructs the initial itemset, which is the closure of
% the itemset comprising only the initial production [S' -> .S].
symbolic procedure lalr_lr0_initial_itemset;
  begin
    scalar start_symbol, initial_item;
    start_symbol := caaar lalr_productions '!S!';
    initial_item := list('!S!', '!., start_symbol);
    return lalr_lr0_closure list initial_item
  end;



% Implements the function GOTO (for LR(0) itemsets) described in the Dragon 
% Book. 
%
% Note: this procedure is not aware of itemset_collection or 
% goto_table, and returns brand new objects. The itemset parameter is a list 
% of LR(0) items (the index from itemset_collection is not included).  
symbolic procedure lalr_compute_lr0_goto(itemset, x);
  begin
    scalar result_kernel, result_item;
    for each item in itemset do 
      if (result_item := lalr_lr0_move_dot(item, x)) then
        result_kernel := result_item . result_kernel;
    return lalr_lr0_closure result_kernel
  end;



% This procedure attempts to "move the dot" in an LR(0) item. Specifically, if
% for the LR(0) item [A -> bc.de], if d=x (the parameter x), then it returns
% [A -> bcd.e] and otherwise nil. 
symbolic procedure lalr_lr0_move_dot(item, x);
  begin
    scalar r;
    while not (car item = '!.) do <<
      r := car item . r;
      item := cdr item >>;
    item := cdr item;
    if not (item and car item = x) then return nil;
    item := car item . '!. . cdr item;
    while r do <<
      item := car r . item;
      r := cdr r >>;
    return item
  end;



% Implements the function CLOSURE (for LR(0) items) described in the Dragon 
% Book. 
%
% Note: this procedure is not aware of itemset_collection or 
% goto_table, and returns brand new objects (though original items are 
% retained). The itemset parameter is a list of LR(0) items (the index from 
% itemset_collection is not included).
%
% Implementation is based on Figure 4.32 in the Dragon Book, although some 
% effort is made to avoid duplicate work.
symbolic procedure lalr_lr0_closure itemset;
  begin
    scalar added, pending, tail, x, rule, new_items, y;
    for each item in itemset do <<
      tail := cdr ('!. member item);
      if tail and (x := car tail) and idp x and not (x member pending) then 
        pending := x . pending >>;

    while pending do <<
      x := car pending;
      pending := cdr pending;
      added := x . added;

      for each production in lalr_productions x do << % [x -> abc] as (a b c)
        rule := car production;
        new_items := (x . '!. . rule) . new_items;
        if rule and (y := car rule) and idp y 
                           and not (y member added or y member pending) then 
          pending := y . pending >> >>;

    % new_items has no duplicates because we made sure to check the added list
    % but there may be overlap with the initial items in the itemset.
    return union(itemset, new_items) 
  end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% This section converts the LR(0) itemset collection into the LALR collection.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Converts the collection of LR(0) itemsets for the grammar (which must have
% already been generated by lalr_generate_lr0_collection) to the LALR 
% collection.
%
% Effects: modifies itemset_collection
%
% The algorithm is adapted from the Dragon Book (Algorithm 4.63). 
symbolic procedure lalr_generate_collection;
  begin
    scalar itemset0, propagation_list;

    % First we must convert the items from their LR(0) format to a format that
    % can have lookaheads. We also take the opportunity to strip each itemset
    % down to its kernel. Note that we preserve the identity of the i_itemsets, 
    % because the goto_table links between them. 
    for each i_itemset in itemset_collection do 
      rplaca(i_itemset, lalr_lr0_itemset_to_lalr_kernel car i_itemset);

    % Hereafter all operations on the individual LALR items (adding lookaheads)
    % preserve their identity, because the propagation_list links between them.

    % Determine all spontaneously generated lookaheads and all item -> item
    % lookahead propagation pairs. 
    propagation_list := lalr_analyze_lookaheads();

    % Add the special lookahead 0 (end-of-input character $) to the initial
    % item [S' -> S]. 
    itemset0 := carrassoc(0, itemset_collection);
    lalr_add_lookahead(car itemset0, 0);

    % Propagate all lookaheads until the LALR collection is complete.
    lalr_propagate_lookaheads(propagation_list);

    % Expand out the kernels to the full itemsets.
    for each i_itemset in itemset_collection do 
      rplaca(i_itemset, lalr_closure car i_itemset);

    if !*lalr_verbose then 
      lalr_print_collection()
  end;



% This procedure converts an LR0 itemset to its LALR kernel. This is really
% two separate jobs and perhaps I shouldn't have combined them. First, we 
% examine each item and only retain it if it is a kernel item. Second, we wrap
% each item (already a list, e.g. 
%     '(A a !. b c) corresponding to LR(0) item [A -> a.bc]
% in another list, which leaves room to stash lookahead symbols. 
symbolic procedure lalr_lr0_itemset_to_lalr_kernel itemset;
  begin
    scalar kernel;
    for each item in itemset do 
      if (car item = '!S!') or (cadr item neq '!.) then 
        kernel := (list item) . kernel;
    return kernel
  end;



% This procedure destructively adds a lookahead symbol to a LALR item.
symbolic procedure lalr_add_lookahead(item, lookahead);
  if item then 
    rplacd(item, lookahead . cdr item)
  else 
    rplacd(item, list lookahead);



% Repeatedly passes over a provided propagation_list, which links item pairs
% (src . dest), until all lookaheads from src are propagated to dest.
symbolic procedure lalr_propagate_lookaheads propagation_list;
  begin
    scalar more_propagated, src, dest;
    repeat <<
      more_propagated := nil;
      for each item_pair in propagation_list do <<
        src := car item_pair; dest := cdr item_pair;
        for each lookahead in cdr src do 
          if not (lookahead member (cdr dest)) then <<
            lalr_add_lookahead(dest, lookahead);
            more_propagated := t >> >> 
    >> until not more_propagated
  end;



% This is the core of the LR(0)-to-LALR conversion algorithm, and is just a 
% wrapper (to iterate through all itemsets) around Algorithm 4.62 in the Dragon 
% Book. 
%
% Effects: adds all spontaneously generated lookaheads to the items in
%          itemset_collection (note: item identity is preserved)
%
% Returns: a list  of item pairs (src . dest), such that all lookaheads from
%          item src should propagate to item dest
symbolic procedure lalr_analyze_lookaheads;
  begin
    scalar propagation_list, lookaheads, dest_i_itemset, dest_item, dummy_item,
           byxd, xd, x, d;
    for each src_i_itemset in itemset_collection do 
      for each src_item in car src_i_itemset do << % Algorithm 4.62
        dummy_item := (car src_item) . '(-1); % -1 is the dummy lookahead #
        for each dummy_closure_item in lalr_closure list dummy_item do <<

          % dummy_closure_item: [B -> y.xd, u/v] where y,d are 0+ grammar 
          % symbols, x is 0-1 grammar symbols
          byxd := car dummy_closure_item; % [B - y.xd]
          lookaheads := cdr dummy_closure_item; % [u/v]

          if xd := cdr ('!. member byxd) then <<
            x := car xd; d := cdr xd;
            dest_i_itemset := lalr_goto(src_i_itemset, x);
            dest_item := lalr_item_with_rule(
                        lalr_lr0_move_dot(byxd,x), car dest_i_itemset);

            for each a in lookaheads do % now considering item [B -> y.xd, a]
              if a = -1 then % lookaheads propagate
                propagation_list := (src_item . dest_item) . propagation_list
              else % lookahead a is spontaneously generated
                lalr_add_lookahead(dest_item, a) >> >> >>;

    return propagation_list
  end;



% Searches the given itemset for the LALR item with the given production rule.
% (Or in other words, with the given "LR(0) core".)
symbolic procedure lalr_item_with_rule(rule, itemset);
  begin
    scalar result;
    while itemset do <<
      if caar itemset = rule then <<
        result := car itemset;
        itemset := nil >>
      else 
        itemset := cdr itemset >>;
    return result
  end;  



% Computes the LALR closure of an itemset. Note: this procedure is not aware of 
% itemset_collection or goto_table, and returns brand new objects (though 
% original items are retained). The itemset parameter is a list of LALR items 
% (the index from itemset_collection is not included). 
%
% The implementation is essentially the algorithm from Figure 4.40 in the 
% Dragon Book, though some care is taken not to do duplicate work. 
%
% The added complexity over lalr_lr0_closure essentially comes from this: 
% suppose that at one iteration of the loop, the closure operation generates  
% the item [B -> y, a/b/c/d], but a previous iteration generated [B -> y, b/d].
% Then we need to add the lookaheads a/c to the existing [B -> y, b/d] object 
% (to create [B -> y, a/b/c/d], represented as '((B y) a/b/c/d)), but we only 
% want to add [B -> y, a/c] to the pending list.
symbolic procedure lalr_closure itemset;
  begin
    scalar pending, item, tail, x, gen_lookaheads, gen_rule, gen_item; 
    pending := itemset;
    while pending do <<
      item := car pending;
      pending := cdr pending;

      for each lookahead in cdr item do <<
        tail := cdr ('!. member car item);
        if tail and (x := car tail) and idp x then
          for each production in lalr_productions x do << % [B -> y]
            gen_lookaheads := lalr_first append(cdr tail, list lookahead);

            gen_rule := x . '!. . car production;
            gen_item := lalr_item_with_rule(gen_rule, itemset);
            if gen_item then 
              gen_lookaheads := setdiff(gen_lookaheads, cdr gen_item) 
            else <<
              gen_item := gen_rule . nil;
              itemset := gen_item . itemset >>;

            if gen_lookaheads then <<
              pending := (gen_rule . gen_lookaheads) . pending;
              for each gen_lookahead in gen_lookaheads do
                lalr_add_lookahead(gen_item, gen_lookahead) >> >> >> >>;
    return itemset
  end;



symbolic procedure lalr_first string;
  begin
    scalar results, w;
    while string and
          not numberp car string and
          (nil member (w := get(car string, 'lalr_first))) do <<
      results := union(delete(nil, w), results);
      string := cdr string >>;
    if null string then results := nil . results
    else if numberp car string then results := union(list car string, results)
    else results := union(w, results);
    return results
  end;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% In this section, make_compressed_action_table examines the itemset_collection
%% and goto_table in order to make the ACTION portion of the ACTION/GOTO 
%% parser table described by the Dragon Book.
%%
%% The compression method is based off the discussion of compressed LALR 
%% parsing tables in the Dragon Book. 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% reqs ordered itemset collection %% wait... does it? why?
symbolic procedure lalr_make_compressed_action_table;
  begin
    scalar table;
    table := mkvect sub1 length itemset_collection;
    for each i_itemset in itemset_collection do 
      putv(table, cdr i_itemset, lalr_make_compressed_action_row i_itemset);
    if !*lalr_verbose then
      lalr_print_compressed_action_table table;
    return table;
  end;

symbolic procedure lalr_make_compressed_action_row i_itemset;
  begin
    scalar action_list;
    action_list := lalr_list_of_actions i_itemset;
    action_list := lalr_resolve_conflicts(action_list, cdr i_itemset);
    return lalr_make_compressed_action_row1 action_list;
  end;

% I sort the actions by number first, but when numbers match I put
% SHIFT ahead of REDUCE

symbolic procedure orderactions(a, b);
  if car a < car b then t
  else if car a > car b then nil
  else if caadr a = caadr b then ordp(cdr a, cdr b)
  else if caadr a = 'shift then t
  else nil; 

symbolic procedure lalr_resolve_conflicts(action_list, itemset_i); 
  begin
    scalar conflicting_actions, results, shift, reduce, chosen_action,
           shift_op, reduce_op, associativity, 
           shift_precedence, reduce_precedence;
    action_list := sort(action_list, function orderactions);
    while action_list do <<
      conflicting_actions := list car action_list;
      action_list := cdr action_list;
      while action_list and caar action_list = caar conflicting_actions do <<
        conflicting_actions := car action_list . conflicting_actions;
        action_list := cdr action_list >>;

      shift := reduce := chosen_action := nil;
      if null cdr conflicting_actions then
        chosen_action := car conflicting_actions
      else
        for each action in conflicting_actions do <<
          if caadr action = 'shift then 
            shift := action
          else if null reduce then % handles accept as well?
            reduce := action
          else % reduce-reduce conflict - keep first reduction seen
            lalr_warn_reduce_reduce_conflict(reduce, action, itemset_i);

          if shift and reduce then << % shift-reduce conflict
            shift_op := car shift; % terminal after dot
            for each symbol in cadr cadr reduce do % the rule
              if numberp symbol then
                reduce_op := symbol;

            if shift_op and reduce_op then <<
              shift_precedence := lalr_precedence shift_op;
              reduce_precedence := lalr_precedence reduce_op;
              if shift_precedence and reduce_precedence then 
                if shift_precedence = reduce_precedence then <<
                  associativity := lalr_associativity shift_op;
                  if associativity = '!:left then
                    shift := nil
                  else if associativity = '!:right then 
                    reduce := nil
                  else
                    shift := reduce := nil >>
                else if shift_precedence < reduce_precedence then
                  reduce := nil
                else 
                  shift := nil >> >> >>;

      if shift and reduce then 
        lalr_warn_shift_reduce_conflict(shift, reduce, itemset_i);
      chosen_action := chosen_action or shift or reduce;
      if chosen_action then
        results := chosen_action . results >>;
    return results
  end;

symbolic procedure lalr_list_of_actions i_itemset;
  begin
    scalar actions, lhs, terminal, tail, rule, reduction_i, goto_i;
    for each item in car i_itemset do <<
      lhs := caar item;
      tail := cdr ('!. member car item);
      if tail and numberp car tail then <<
        terminal := car tail;
        goto_i := cdr lalr_goto(i_itemset, terminal);
        actions := list(terminal, list('shift, goto_i)) . actions >>
      else if null tail and lhs neq '!S!' then <<
        rule := delete('!., car item);
        reduction_i := lalr_reduction_index rule;
        for each lookahead in cdr item do 
          actions := list(lookahead, 
                          list('reduce, rule, reduction_i)) . actions >>
      else if null tail and lhs = '!S!' then 
        actions := list(0, '(accept)) . actions >>;
    return lalr_remove_duplicates actions;
  end;

symbolic procedure lalr_remove_duplicates x;
  begin
    scalar r;
    for each a in x do
      if not member(a, r) then r := a . r;
    return reversip r
  end;

symbolic procedure lalr_make_compressed_action_row1 action_list;
  begin
    scalar most_common_reduction, row, terminal, action_type;
    most_common_reduction := lalr_most_common_reduction action_list;
    for each action in action_list do 
      if cadr action neq most_common_reduction then <<
        terminal := car action;
        action_type := caadr action;
        if action_type = 'shift then 
          row := (terminal . cadadr action) . row
        else if action_type = 'accept then
          row := (terminal . 0) . row
        else if action_type = 'reduce then 
          row := (terminal . -(car cddadr action)) . row >>;
    if most_common_reduction then
      most_common_reduction := 
        if car most_common_reduction = 'accept then 0
        else -(caddr most_common_reduction);
    return row . most_common_reduction
  end;

symbolic procedure lalr_most_common_reduction action_list;
  begin
    scalar reduction_count, reduction, w;
    for each action in action_list do
      if caadr action = 'reduce or caadr action = 'accept then <<
        reduction := cadr action;
        if (w := assoc(action, reduction)) then rplacd(w, cdr w + 1)
        else reduction_count := (reduction . 1) . reduction_count >>;
    if reduction_count then <<
      w := car reduction_count;
      for each entry in cdr reduction_count do 
        if cdr entry > cdr w then 
          w := entry;
      return car w >>
    else
      return nil
  end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% In this section, make_ examines the itemset_collection
%% and goto_table in order to make the GOTO portion of the ACTION/GOTO 
%% parser table described by the Dragon Book.
%%
%% The compression method is based off the discussion of compressed LALR 
%% parsing tables in the Dragon Book. 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure lalr_make_compressed_goto_table;
  begin
    scalar table, column;
    table := mkvect sub1 length nonterminals;
    for each x in nonterminals do % ordered by nonterminal code
      if x neq '!S!' then <<
        column := lalr_make_compressed_goto_column x;
        putv(table, get(x, 'lalr_nonterminal_code), column) >>;
    if !*lalr_verbose then 
      lalr_print_compressed_goto_table table;
    return table
  end;

symbolic procedure lalr_make_compressed_goto_column x;
  begin
    scalar goto_list, column, most_common_dest;
    goto_list := for each entry in gethash(x, goto_table) collect
                (cdar entry . cddr entry);
    most_common_dest := lalr_most_common_dest goto_list;
    for each entry in goto_list do 
      if cdr entry neq most_common_dest then
        column := entry . column;
    return column . most_common_dest
  end;

symbolic procedure lalr_most_common_dest goto_list;
  begin
    scalar dest_count, w;
    for each entry in goto_list do
      if (w := assoc(cdr entry, dest_count)) then rplacd(w, cdr w + 1)
      else dest_count := (cdr entry . 1) . dest_count;
    w := car dest_count;
    for each entry in cdr dest_count do if cdr entry > cdr w then w := entry;
    return car w
  end;


%%%
%
%
% includes a useless reduction for S' -> S
symbolic procedure lalr_process_reductions;
  begin
    scalar reduction_codes, code, n_reductions, canonical_reduction, 
           coded_canonical_reduction, rhs_length, lhs, fn, 
           reduction_fn, reduction_lhs, reduction_rhs_length;

    code := -1;
    % print nonterminals; print lalr_productions car nonterminals; error(1,"");
    for each x in nonterminals do 
      for each production in lalr_productions x do <<
        canonical_reduction := (x . length car production) . cdr production;
        coded_canonical_reduction := assoc(canonical_reduction,reduction_codes);
        if null coded_canonical_reduction then <<
          coded_canonical_reduction := canonical_reduction . (code := code + 1);
          reduction_codes := coded_canonical_reduction . reduction_codes >>;
        rplacd(production, cdr coded_canonical_reduction) >>;

    n_reductions := code + 1;
    reduction_fn := mkvect sub1 n_reductions;
    reduction_lhs := mkvect16 sub1 n_reductions;
    reduction_rhs_length := mkvect8 sub1 n_reductions;
    for each coded_canonical_reduction in reduction_codes do <<
      code := cdr coded_canonical_reduction;
      rhs_length := cdaar coded_canonical_reduction;
      lhs := get(caaar coded_canonical_reduction, 'lalr_nonterminal_code);
      putv16(reduction_lhs, code, lhs);
      putv8(reduction_rhs_length, code, rhs_length);

      if (cdar coded_canonical_reduction) then <<
        fn := cdar coded_canonical_reduction;
        fn := lalr_construct_fn(fn, rhs_length) >>
      else
        fn := nil;
      putv(reduction_fn, code, fn) >>;

    return list(reduction_fn, reduction_rhs_length, reduction_lhs);
  end;

symbolic procedure cdrassoc(key, alist);
  begin
    scalar w;
    if not atom (w := assoc(key, alist)) then return cdr w;
    terpri();
    princ "ASSOC trouble: "; prin key; princ " "; print alist;
    rederr "assoc trouble"
  end;



symbolic procedure lalr_reduction_index rule;
  begin
    scalar x, rhs;
    x := car rule; rhs := cdr rule;
    return cdrassoc(rhs, lalr_productions x)
  end;


symbolic procedure lalr_construct_fn(lambda_expr, args_n);
  begin
    scalar fn;
    fn := gensym();
    lambda_expr := 'lambda  . lalr_make_arglist args_n . lambda_expr;
    putd(fn, 'expr, lambda_expr) where !*pwrds = nil;
    return fn
  end;

symbolic procedure lalr_make_arglist n;
  for i := 1:n collect
    intern list2string ('!$ . explode2 i);


end;
