% yyparse.red

module 'yyparse;

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
% This is a general-purpose LR(1) parser skeleton. The entry point is the 
% function yyparse, which receives a parameter "parser" containing all the info 
% necessary to parse a specific grammar. (Note: genparser.red will generate
% LALR parsers in the format yyparse expects.)
%
% This parser skeleton is based on the method given by the Dragon Book. 
% Consequently, the "parser" passed to yyparse consists of the ACTION and GOTO
% tables described in the Dragon Book, along with some other additional info
% required for their operation.
%==============================================================================

% parser_action_table is the ACTION table described in the Dragon Book, with
% some (optional) effort at compaction. The format is a vector of "table rows", 
% indexed by parser state. Each row is a dotted pair (row . default), where 
% "row" is an alist from terminal to action and "default" is an optional default 
% action to take if "row" does not have an entry for the desired terminal. 
% 
% Terminals are represented as the integer category codes returned by yylex().
% 
% Actions are also integers, where positive x indicates "shift to state x" and 
% and negative x indicates "reduce by reduction code (-x-1)". Since state 0 is
% the initial state of an augmented grammar, the ACTION table will never 
% prescribe a shift to state 0, and so we use 0 to indicate "accept".
%
% A blank entry in the ACTION table (i.e., no entry in "row" and no default)
% indicates an error.
%
% parser_goto_table is the GOTO table in a similar format. This time, the 
% vector elements are "table columns" indexed by nonterminal. The column alists
% are from source state to destination state, and the default is not optional. 
%
% Note that nonterminals are represented as integer codes as well.
fluid '(parser_action_table parser_goto_table);

% These three vectors are indexed by reduction code (as found in the ACTION 
% table), and are referred to when executing a reduction. 
% For a given reduction code:
%   - reduction_rhs_n holds the number of symbols on the right-hand-side of the 
%     production, i.e. the number of states to be popped off the state stack
%     and the number of values to be popped off the symbol stack.
%
%   - reduction_fn contains an optional semantic action function, which is 
%     passed the values popped off the symbol stack and returns the value
%     pushed on to the symbol stack. There is default behavior for when no 
%     semantic action is provided, described below in yyparse.
%
%   - reduction_lhs contains the nonterminal on the left-hand-side of the 
%     production, as its integer nonterminal code. This is then used to lookup
%     the destination state from the GOTO table, to push onto the state stack.
% 
% Note that reduction_lhs and reduction_rhs_n are CSL fixnum vectors. For PSL
% I have a compatibility fragment that uses simple Lisp vectors to store
% the same information, but less compactly.

global '(lex_initial_next_code);

fluid '(reduction_fn reduction_lhs reduction_rhs_n next_input);

% This is an alist from nonterminal category code to nonterminal symbol, 
% provided strictly for verbose printing purposes. Note that genparserprint.red
% provides a lalr_prin_nonterminal function that expects a global/fluid called
% nonterminal_codes to be initialized in this format -- convenient!

fluid '(nonterminal_codes);

% Ditto for terminal symbols.

fluid '(terminal_codes);

% This function deconstructs the parser structure passed to yyparse() and 
% initialized all the necessary fluid variables. 
%
% The final element of the parser structure not yet mentioned (because it's not
% stored as a fluid variable above) is the lex_context structure that needs
% to be passed to lex_restore_context (in yylex.red) so that the lexer will 
% provide the correct tokens for this grammar.

symbolic procedure set_parser parser;
  begin
    scalar w;
    lex_restore_context    car parser;
    parser_action_table := car (parser := cdr parser);
    w              :=      car (parser := cdr parser);
    reduction_fn :=          car w;
    reduction_rhs_n :=       car (w := cdr w);
    reduction_lhs :=         car (w := cdr w);
    parser_goto_table :=   car (parser := cdr parser);
    nonterminal_codes :=   car (parser := cdr parser);
    terminal_codes :=      car (parser := cdr parser);
    return nil
  end;

symbolic procedure get_goto(src_state, nonterminal);
  begin
    scalar table_column_and_default, table_column, result;
    table_column_and_default := getv(parser_goto_table, nonterminal); 
    table_column := car table_column_and_default;
    result := cdr table_column_and_default;
    while table_column do 
      if caar table_column = src_state then <<
        result := cdar table_column;
        table_column := nil >>
      else
        table_column := cdr table_column;
    return result
  end;

symbolic procedure get_action_without_lookahead state;
  begin
    scalar table_row_and_default;
    table_row_and_default := getv(parser_action_table, state);
    if car table_row_and_default = nil then
      return cdr table_row_and_default
    else
      return nil
  end;

symbolic procedure get_action(state, terminal);
  begin
    scalar table_row_and_default, table_row, result;
    table_row_and_default := getv(parser_action_table, state);
    table_row := car table_row_and_default;
    result := cdr table_row_and_default;
    while table_row do 
      if caar table_row = terminal then <<
        result := cdar table_row;
        table_row := nil >>
      else
        table_row := cdr table_row;
    return result
  end;

symbolic procedure yyparse parser;
  begin
    % state_stack is a stack of parser-machine states and sym_stack runs
    % in step with it and holds the corresponding symbols. Terminals are 
    % shifted directly onto sym_stack, but when a nonterminal is generated
    % through a reduction, the sym_stack receives the result of the semantic 
    % action.
    scalar parser_action_table, parser_goto_table, 
           reduction_fn, reduction_lhs, reduction_rhs_n, 
           terminal_codes, nonterminal_codes,
           sym_stack, state_stack, next_input, w;


    % Note that state 0 must be the initial state, and that we initialize
    % next_input to an invalid code -1 which is used to avoid unnecessary 
    % reading ahead.
    set_parser parser;
    state_stack := list 0;
    lex_init();
    next_input := -1; 

    % Each iteration of the loop begins by fetching the next action. The loop
    % ends when the input is accepted (action 0) or on error (action nil).
    while <<
      w := get_action_without_lookahead(car state_stack);
      if null w then <<
        if next_input < 0 then next_input := yylex();
        w := get_action(car state_stack, next_input) >>;
      (w neq 0) and (w neq nil) >> 
    do <<

      % SHIFT
      if w > 0 then <<                            
        if next_input < 0 then next_input := yylex();
%       if next_input = lex_eof_code then
%         error(0, "End of file detected");
        if next_input < lex_initial_next_code then
          sym_stack := yylval . sym_stack
        else sym_stack := cdrassoc(next_input, terminal_codes) . sym_stack;    
        state_stack := w . state_stack;                 
        next_input := -1;                               
        if !*lalr_verbose then << %% should we decode the terminal code here?
          princ "Shift token "; prin car sym_stack; princ " onto stack, ";
          princ "and shift to state "; print car state_stack >> >>

      % REDUCE
      else begin                                   
        scalar lhs, rhs_n, fn;
        w := -w;
        fn := getv(reduction_fn, w);
        rhs_n := getv8(reduction_rhs_n, w);             
        lhs := getv16(reduction_lhs, w);            
        w := nil;
        for i := 1:rhs_n do <<
          w := car sym_stack . w;
          sym_stack := cdr sym_stack;
          state_stack := cdr state_stack >>;

        % By default, if no semantic action is provided, we either:
        %   - build the list (r1 r2 r3) for a production of multiple symbols
        %     L -> r1 r2 r3
        %   - simply leave r unchanged for a production of one symbol L -> r
        if fn then w := apply(fn, w)
        else if rhs_n = 1 then w := car w;
        sym_stack := w . sym_stack;

        state_stack := get_goto(car state_stack, lhs) . state_stack;

        if !*lalr_verbose then <<
          princ "On lookahead "; prin next_input; princ ", reduce "; prin rhs_n; 
          princ " symbols to nonterminal "; lalr_prin_nonterminal lhs; 
          princ ", and goto state "; print car state_stack >>
      end >>;

    if w = nil then <<
      terpri();
      w := append(explodec "Item ",
             append(explode next_input,
               append(explodec " ('",
                 append(explodec yylval,
                   explodec "') unexpected."))));
      yyerror list2string w;
      princ "states: "; print state_stack;       % Probably not useful.
      princ "symbols: "; print sym_stack;        % Probably not useful.
      princ "next token: "; print next_input >>; % Probably redundant.

    if !*lalr_verbose then <<
      if not zerop posn() then terpri();
      princ "Seems to have finished... " >>;

    return car sym_stack
  end;

endmodule;

end;
