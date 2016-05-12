% genparserprint.red

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

module 'genparserprint;

symbolic procedure lalr_print_compressed_action_table action_table;
  begin
    scalar n_itemsets, row, default;
    n_itemsets := length itemset_collection;
    princ "=== ACTION TABLE ==="; terpri();
    princ "STATE"; ttab 6; princ "TERMINAL"; ttab 20; princ "ACTION"; terpri();
    for state:=0 : (sub1 n_itemsets) do << 
      row := car getv(action_table, state);
      default := cdr getv(action_table, state);
      prin state; 
      for each entry in row do <<
        ttab 6; lalr_prin_symbol car entry; ttab 20;
        lalr_prin_action cdr entry; terpri() >>;  
      if default then <<
        ttab 6; princ "<any>"; ttab 20;   
        lalr_prin_action default; terpri() >> >>;
    terpri();
  end;

symbolic procedure lalr_print_compressed_goto_table goto_table;
  begin 
    scalar code, row, default;
    princ "=== GOTO TABLE ==="; terpri();
    princ "NONTERMINAL"; ttab 20; princ "SRC"; ttab 28; princ "DEST"; terpri();
    for each nonterminal in delete('!S!', nonterminals) do <<
      code := get(nonterminal, 'lalr_nonterminal_code);
      row := car getv(goto_table, code);
      default := cdr getv(goto_table, code);
      lalr_prin_nonterminal code;
      for each entry in row do <<
        ttab 20; prin car entry; ttab 28; print cdr entry >>;
      if default then <<
        ttab 20; princ "<any>"; ttab 28; print default >> >>;
    terpri();
  end;

symbolic procedure lalr_prin_action action;
  if action = nil then 
    princ " "
  else if action > 0 then << 
    princ "shift to state "; 
    prin action >>
  else if action = 0 then 
    princ "accept"
  else 
    lalr_prin_reduction (-action);

symbolic procedure lalr_prin_reduction code;
  begin
    scalar reduction_fn, reduction_rhs_length, reduction_lhs, fn;
    reduction_fn := first reduction_info; 
    reduction_rhs_length := second reduction_info;
    reduction_lhs := third reduction_info;
    princ "reduce by #"; prin code; princ ": ";
    lalr_prin_nonterminal getv16(reduction_lhs, code); 
    princ " -> ["; prin getv8(reduction_rhs_length, code); princ " symbols] ";
% He ha - if !*comp is set then the reduction function gets compiled and
% its source is not readily visible for display here.
    if (fn := getv(reduction_fn, code)) then prin cdr getd fn;
  end;

symbolic procedure lalr_print_lr0_collection; 
  begin
    scalar i_goto;
    princ "=== LR(0) ITEMSET COLLECTION ==="; terpri();
    for each i_itemset in reverse itemset_collection do <<
      princ "Itemset "; prin cdr i_itemset; terpri();
      for each item in sort(car i_itemset, function ordp) do <<
        princ " "; lalr_prin_symbol car item; princ " ->"; 
        for each x in cdr item do << princ " "; lalr_prin_symbol x >>;
        terpri() >>;
      for each x in symbols do 
        if i_goto := lalr_goto(i_itemset, x) then <<
          princ "GOTO("; lalr_prin_symbol x; 
          princ ") = state "; prin cdr i_goto;
          terpri() >>;
      terpri() >>
  end;

symbolic procedure lalr_print_collection; 
  begin
    scalar i_goto;
    princ "=== LALR ITEMSET COLLECTION ==="; terpri();
    for each i_itemset in reverse itemset_collection do <<
      princ "Itemset "; prin cdr i_itemset; terpri();
      for each item in sort(car i_itemset, function ordp) do <<
        princ " "; lalr_prin_symbol caar item; princ " ->"; 
        for each x in cdar item do << princ " "; lalr_prin_symbol x >>;
        princ " [";
        for each remaining_lookaheads on cdr item do <<
          lalr_prin_symbol car remaining_lookaheads;
          if length remaining_lookaheads = 1 then 
            princ "]"
          else 
            princ "/" >>; 
        terpri() >>;
      for each x in symbols do 
        if i_goto := lalr_goto(i_itemset, x) then <<
          princ "GOTO("; lalr_prin_symbol x; princ ") = "; prin cdr i_goto;
          terpri() >>;
      terpri() >>
  end;

symbolic procedure lalr_print_first_information;
  <<
    princ "=== FIRST sets for each nonterminal ==="; terpri();
    for each nt in nonterminals do <<
      lalr_prin_symbol nt; princ ":"; ttab 20;
      for each terminal in get(nt, 'lalr_first) do <<
        lalr_prin_symbol terminal; princ " " >>; 
      terpri() >>;
    terpri()
  >>;

symbolic procedure lalr_print_terminals_and_codes terminals;
  << 
    princ "=== Terminal symbols ==="; terpri();
    for each terminal in terminals do <<
      princ "   "; lalr_prin_symbol terminal; 
      princ " ["; prin terminal; princ "]";
      if (lalr_precedence terminal) or (lalr_associativity terminal) then <<
        princ " (precedence "; prin lalr_precedence terminal; princ ", ";
        for each c in cdr explode2 lalr_associativity terminal do princ c; 
        princ " associativity)" >>;
      terpri() >>;
    terpri()
  >>;

symbolic procedure lalr_print_nonterminals_and_productions;
  <<  
    princ "=== Nonterminal symbols ==="; terpri();
    for each nt in nonterminals do <<
      princ "["; prin get(nt, 'lalr_nonterminal_code); princ "] ";
      lalr_prin_symbol nt;
      begin 
        scalar separator;
        separator := ":";
        for each production in lalr_productions nt do <<
          ttab 20; princ separator; princ " ";
          separator := "|";
          lalr_prin_rhs car production;
          if posn() > 48 then terpri(); ttab 48;
          princ "{ "; lalr_prin_semantic_action cdr production; princ " }";
          terpri() >>
      end;
      terpri() >>;
    terpri()
  >>;

symbolic procedure lalr_prin_semantic_action semantic_action;
  prin semantic_action;

symbolic procedure lalr_prin_rhs rhs;
  if rhs = nil then 
    princ "<empty>"
  else 
    for each sym in rhs do <<
      lalr_prin_symbol sym;
      princ " " >>;

symbolic procedure lalr_prin_symbol sym;
  if sym = 0 then 
    princ "$"
  else if numberp sym then
    for each c in explode2 cdrassoc(sym, terminal_codes) do princ c
  else 
    for each c in explode2uc sym do princ c;

symbolic procedure lalr_prin_nonterminal code;
  for each c in explode2uc cdrassoc(code, nonterminal_codes) do princ c;


symbolic procedure lalr_warn_reduce_reduce_conflict(reduce1, reduce2, state);
  <<
    if not zerop posn() then terpri();
    princ "+++++ Reduce/reduce conflict in itemset #"; prin state;
    princ " on lookahead "; lalr_prin_symbol car reduce1; terpri();
    princ "Reduction #1: "; lalr_prin_production cadr cadr reduce1; terpri();
    princ "Reduction #2: "; lalr_prin_production cadr cadr reduce2; terpri();
    printc "Resolved in favour of reduction #1";
    terpri()
  >>;

symbolic procedure lalr_prin_production production;
  <<
    lalr_prin_symbol car production;
    princ " -> ";
    lalr_prin_rhs cdr production
  >>;


symbolic procedure lalr_warn_shift_reduce_conflict(shift, reduce, state);
  <<
    if not zerop posn() then terpri();
    princ "+++ Shift/reduce conflict in itemset #"; prin state; 
    princ " on lookahead "; lalr_prin_symbol car shift; terpri();
    princ "Reduce: "; lalr_prin_production cadr cadr reduce; terpri();
    princ "Shift: to state #"; prin cadr cadr shift; terpri(); 
    printc "Resolved in favour of the shift operation";
    terpri()
  >>;

endmodule;

end;

