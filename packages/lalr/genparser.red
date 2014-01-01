% genparser.red

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

module 'genparser;

unglobal '(!*raise);
fluid '(!*raise);

%=============================================================================
%
% This is an LALR(1) parser generator, which can take the
% specification of a grammar and construct tables that direct the
% generic parser skeleton.
%
%=============================================================================


fluid '(!*raise !*lower !*echo);
global '(lex_char yylval last64 last64p which_line if_depth);

global '(action_first_error action_error_messages);

global '(action_fn action_A action_n);

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

global '(terminals non_terminals symbols goto_cache action_map);

inline procedure lalr_productions x;
    get(x, 'produces);

inline procedure lalr_set_productions(x, y);
    put(x, 'produces, y);

symbolic procedure lalr_prin_symbol x;
  begin
    scalar w;
    if x = 0 then princ "$"
    else if x = nil then princ "<empty>"
    else if x = '!. then princ "."
    else if numberp x and (w := rassoc(x, terminals)) then
       prin car w
    else if stringp x then prin x
    else for each c in explode2uc x do princ c
  end;

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

%
% lalr_set_grammar G expects that G will be a list of productions
% in the format described earlier. The symbol mentioned on the left of the
% first production will be taken as the starting symbol.
%

symbolic procedure lalr_set_grammar g;
  begin
    scalar name, vals, tnum, w;
    terminals := non_terminals := symbols := nil;
% I will start by augmenting the grammar with an initial production...
    g := list('s!', list list caar g) . g;
    for each x in g do <<
        name := car x; vals := cdr x;
% I build an alist of the names that appear on the left of productions, and
% account these as my non-terminals.
        if name member non_terminals then
            vals := append(vals, lalr_productions name)
        else non_terminals := name . non_terminals;
% Items on the right of a production can be strings or numbers, and in that
% case I will allocate them a numeric code that stands for them when used as
% a terminal symbol. The association list 'terminals' will have an entry
% for each. Otherwise I collect a list 'symbols' of all names mentioned
% on the right of a production.
        for each vv in cdr x do
          for each v in car vv do <<
            if stringp v then <<
               if null cdr (tnum := explodecn v) then <<
                  v := compress ('!! . '!: . tnum);
                  put(v, 'lex_code, car tnum) >>
               else v := intern v >>;
            if not (v member symbols) then symbols := v . symbols >>;
        lalr_set_productions(name, vals) >>;
% symbols that were non-terminals can be removed, and then all remaining
% symbols must be terminal, so I allocate numeric codes for them.
    for each name in non_terminals do symbols := delete(name, symbols);
    for each v in symbols do <<
       if not get(v, 'lex_code) then <<
          terminals := (v . next_lex_code) . terminals;
          put(v, 'lex_code, next_lex_code);
          next_lex_code := next_lex_code + 1 >> >>;
% I reverse the list of non-terminals here so that the starting symbol
% will be the first item.
    non_terminals := reversip non_terminals;
% Now I allocate numeric codes for all non-terminals, with 0 for the
% start symbol.
    tnum := -1;
    for each v in non_terminals do
        put(v, 'non_terminal_code, tnum := tnum+1);
% symbols is a list of all symbols, with terminals represented as integers
% that are index values.
    symbols := append(non_terminals, for each x in terminals collect cdr x);
% It could well be that I ought to use hash tables more extensively in
% this code...
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
    action_fn := mkvect tnum;
    action_n := mkvect8 tnum;
    action_A := mkvect16 tnum;
    action_first_error := tnum;
    if !*verbose then lalr_print_action_map();
% Now whenever I start to set up a new grammar I need the FIRST information
% so I may as well compute it here.
    lalr_calculate_first non_terminals;
  end;

% The intent is that lalr_clean_up() should tidy up ALL global state used
% while parse tables are being constructed. But it leaves the parse
% tables that are needed in use.

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
    princ "lalr_calculate_first "; print g;
    for each x in g do
        if assoc(nil, lalr_productions x) then put(x, 'lalr_first, '(nil));
    repeat <<
        done := nil;
        for each x in g do <<
            z := get(x, 'lalr_first);
            princ "Scan "; prin x; princ " : "; prin z;
            princ " / "; print lalr_productions x;
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
    action_index := mkvect16 (caar action_table + 1);
    action_table := reversip action_table;
    if !*verbose then lalr_print_actions action_table;
    printc "ACTION_TABLE = ";
    for each x in action_table do print x;
    j := 0; w := nil;
    for each x in action_table do <<
        putv16(action_index, car x, j);
        for each y on cdr x do begin
           scalar tt, rr, rx, rn, rA;
% The final terminal in each search-chunk will be stored as
% "-1" which is a wild-card. This will then be the action that is
% carried out if a syntax error is present.
           if null cdr y then tt := -1 else tt := caar y;
           rr := cadar y;
           if rr = 'accept then rr := 0
           else if car rr = 'shift then rr := cadr rr
           else <<  % (reduce (A b c d) (rule#))
              rr := cdr rr;
              princ "REDUCE "; prin car rr; princ " : "; print cadr rr;
              rx := caadr rr;       % index of semantic action
              ra := caar rr;        % non-terminal to reduce to
              rn := length cdar rr; % number of items to pop
              putv(action_fn, rx-1, nil); % for the moment
% function should be (lambda (v<1> .. v<rn>)
%                       car rassoc(rx, action_map));
              princ "Semantic Action "; prin list rn;
              princ "  "; print rassoc(rx, action_map);
              putv8(action_n, rx-1, rn);
              putv16(action_A, rx-1, get(rA, 'non_terminal_code));
              rr := -rx >>;
princ "Posn "; prin j; princ " "; prin tt; princ " / "; print rr;
           w := (tt . rr) . w;
           j := j + 1 end >>;
    action_terminal := mkvect16 j;
    action_result := mkvect16 j;
printc "Now fill in the table";
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
    princ "action_index "; print action_index;
    princ "action_terminal "; print action_terminal;
    princ "action_result "; print action_result;
    princ "action_fn "; print action_fn;
    princ "action_n "; print action_n;
    princ "action_A "; print action_A;
    lalr_make_gotos();
    lalr_clean_up()
  end;

endmodule;

end;

