module regex;

% Copyright 1994 by Rainer Schoepf and ZIB.

COMMENT a regular expression matcher;

fluid '(!*trregex !*trregexmatch);

switch trregex,trregexmatch;

global '(!*regex!-groups!*);

fluid '(!*regex!-groupings!*);

!*regex!-groups!* := mkvect 10;

symbolic procedure nth0(l,i); nth(l,i + 1);

symbolic procedure pnth0(l,i); 
   if i<0 then rederr "Index out of range"
    else if i=0 then l
    else if atom l then rederr "Index out of range"
    else pnth0(cdr l,i - 1);

symbolic procedure regex_info msg; if !*trregex then lprim msg;

symbolic procedure regex_match_info msg;
   if !*trregexmatch then lprim msg;

symbolic smacro procedure next_source_char; 
   if atom source then eoserror()
    else <<current := car source; 
           regex_info ({"Grabbing next source character", current}); 
           source := cdr source; 
           current>>;

symbolic smacro procedure add_exp l; 
   <<regex_info ({"Adding to expression list:", l}); 
     expression := l . expression>>;

symbolic procedure form_simple_char_exp char; 
   <<regex_info ({"Building expression for simple character", char}); 
     {'cond, 
      {{'not, 
        {'and,
         '(lessp indx len),
         {'eq, mkquote char, '(nth0 string indx)}}}, 
       if !*trregex
         then {'progn, 
               {'regex_match_info, 
                {'list, 
                 "Check for character", 
                 mkquote char, 
                 "failed at index", 
                 'indx}}, 
               '(return nil)}
        else '(return nil)}, 
      if !*trregex
        then {'t, 
              {'progn, 
               {'regex_match_info, 
                {'list, 
                 "Check for character", 
                 mkquote char, 
                 "succeeded at index", 
                 'indx}}, 
               '(setq indx (add1 indx))}}
       else '(t (setq indx (add1 indx)))}>>;

symbolic smacro procedure add_simple_char_exp char; 
   add_exp form_simple_char_exp char;

symbolic procedure form_vector_exp vect; 
   <<regex_info ({"Building expression for character class vector"}); 
     {'cond, 
      '((not (lessp indx len)) (return nil)), 
      {{'getv, vect, '(char2num (nth0 string indx))}, 
       if !*trregex
         then {'progn, 
               {'regex_match_info, 
                {'list, 
                 "Check for character class vector", 
                 "succeeded at index", 
                 'indx}}, 
               '(setq indx (add1 indx))}
        else '(setq indx (add1 indx))}, 
      {'t, 
       if !*trregex
         then {'progn, 
               {'regex_match_info, 
                {'list, 
                 "Check for character class vector", 
                 "failed at index", 
                 'indx}}, 
               '(return nil)}
        else '(return nil)}}>>;

symbolic smacro procedure add_vector_exp vect; add_exp form_vector_exp vect;

symbolic procedure form_group_ref_exp g; 
   <<regex_info ({"Building expression for", g}); 
     {{'lambda, 
       '(nstring), 
       {'progn, 
        if !*trregex
          then {'regex_match_info, 
                {'list, 
                 "Matching group_ref", 
                 cadr g, 
                 "(", 
                 {'car, g}, 
                 ",", 
                 {'cadr, g}, 
                 ") =", 
                 'nstring, 
                 "at index", 
                 'indx}}, 
        '(cond
          ((compare_string_part string indx nstring)
           (setq indx (plus2 indx (length nstring))))
          (t (return nil)))}}, 
      {'extract_substring, 'string, {'car, g}, {'cadr, g}}}>>;

symbolic smacro procedure add_group_ref_exp g; add_exp form_group_ref_exp g;

symbolic procedure form_variant_simple_exp(ex,min,max,rest); 
   begin scalar body; 
      regex_info ({"Building simple variant expression for", 
                   ex, 
                   "with minimum", 
                   min, 
                   "and maximum", 
                   max}); 
      body := {'(go tag)}; 
      if max
        then body := ({'cond, {{'equal, 'count, max}, '(return t)}}) . body; 
      if !*trregex
        then body := 
              ({'regex_match_info, 
                {'list, 
                 "Variant match succeeded between indices", 
                 'oindx, 
                 'indx}})
                . body; 
      body := '(setq matchindices (cons oindx matchindices)) . body; 
      if max then body := '(setq count (add1 count)) . body; 
      body := 'tag . ('(setq oindx indx) . (ex . body)); 
      if null max then body := '(oindx) . body
       else body := '(count oindx) . ('(setq count 0) . body); 
      return {{'lambda, 
               '(matchindices), 
               {'progn, 
                'prog . body, 
                {'prog, 
                 '(start), 
                 '(setq start indx), 
                 'tag, 
                 if min>0
                   then {'cond, 
                         {{'lessp, '(length matchindices), min}, 
                          '(return nil)}}, 
                 {'cond, 
%                  {'prog . ('(indx) . ('(setq indx start) . rest)), 
                  {'prog . ('nil . ('(setq indx start) . rest)), 
                   '(return t)}}, 
                 '(cond ((null matchindices) (return nil))), 
%                 '(setq matchindices (cdr matchindices)), 
                 '(setq start (car matchindices)), 
                 '(setq matchindices (cdr matchindices)), 
                 if !*trregex
                   then {'regex_match_info, {'list, "Backing up to index", 'start}}, 
                 '(go tag)}}}, 
              nil}
   end;

symbolic procedure form_variant_group_exp(ex,min,max,rest); 
   <<regex_info ({"Building group variant expression for", 
                  ex, 
                  "with minimum", 
                  min, 
                  "and maximum", 
                  max}); 
     {'cond, 
      {form_variant_simple_exp('progn . cdr ex,min,max,rest), t}, 
      {t, {'set_group_end, car ex, 'indx}}}>>;

symbolic procedure form_variant_exp(ex,min,max,rest); 
   {'return, 
    if numberp car ex then form_variant_group_exp(ex,min,max,rest)
     else form_variant_simple_exp(ex,min,max,rest)};

symbolic procedure set_group_end(groupno,indx); 
   <<regex_match_info ({"Setting end of group", groupno, "to index", indx}); 
     car cdr getv(!*regex!-groups!*,groupno) := indx>>;

symbolic procedure group_ref groupno; getv(!*regex!-groups!*,groupno);

symbolic procedure extract_substring(string,start,endd); 
   begin scalar result; integer l; 
      l := endd - start; 
      string := pnth0(string,start); 
      if length string<l then eoserror(); 
      for i := 1:l do <<result := car string . result; string := cdr string>>; 
      return reversip result
   end;

symbolic procedure extract_group(string,groupno);
   extract_substring(string, car gref, cadr gref) where gref := group_ref groupno;

symbolic procedure compare_string_part(string,indx,nstring); 
   begin integer l; 
      l := length nstring; 
      string := pnth0(string,indx); 
      if length string<l then return nil; 
    loop: 
      if null nstring then return t
       else if not(car nstring eq car string) then return nil; 
      string := cdr string; 
      nstring := cdr nstring; 
      go to loop
   end;

symbolic procedure compile_regex_pp l;
   begin scalar result;
     while l do <<
       if stringp car l then result := append(result,explode2 car l)
        else if not atom car l then result := append(result,eval car l)
        else result := append(result,{car l});
       l := cdr l>>;
     return result
   end;

symbolic procedure eoserror; rederr ({"Unexpected end of string"});

symbolic procedure regex_special_char_p char; 
   char memq '(!? !* !+ !. !( !) ![ !] !\ !$ !{ !| !});

symbolic smacro procedure add2result l; 
   <<regex_info ({"Adding to result:", l}); result := l . result>>;

symbolic procedure compile_regex source; 
   begin integer group; scalar fastfirst,result,groupstack,source,
                               expression,current,anchored; 
      regex_info ({"Entering compile_regex with ", source}); 
      expression := 'nil; 
      group := 1; 
      groupstack := nil; 
      result := nil; 
      fastfirst := nil; 
      if stringp source then source := explode2 source
       else if atom source then rederr {"invalid argument to compile_regex:", source}
       else source := compile_regex_pp source;
      if null source then return '(lambda (arg) t); 
      if car source eq '!^ then <<source := cdr source; anchored := t>>; 
      if length source>1 and car source eq '!. and cadr source eq '!*
        then anchored := t;  % optimization
      if anchored then regex_info "Search is anchored"; 
      if not anchored
           and not regex_special_char_p car source
           and not(not null cdr source and regex_special_char_p cadr source)
        then fastfirst := 
              {'cond, {{'not, {'memq, mkquote car source, 'string}}, '(return nil)}}; 
      add_exp '(putv !*regex!-groups!* 0 (list indx nil)); 
      while not null source do 
         begin scalar current; 
            next_source_char(); 
            regex_info ({"Now processing character ", current}); 
            if current eq '!.
              then add_exp '(cond
                             ((lessp indx len) (setq indx (add1 indx)))
                             (t (return nil)))
             else if current eq '!$
              then if not null source then add_simple_char_exp '!$
                    else add_exp '(cond ((not (equal indx len)) (return nil)))
             else if current eq '!* then add_exp 'asterisk
             else if current eq '!+ then add_exp 'plus
             else if current eq '!? then add_exp 'question
             else if current eq '!{
              then begin scalar result; 
                      result := regex_brace source; 
                      source := pnth0(source,car result); 
                      add_exp ('brace . cdr result)
                   end
             else if current eq '!(
              then <<group := group + 1; 
                     groupstack := group . groupstack; 
                     add_exp ({'putv, 
                               '!*regex!-groups!*, 
                               group - 1, 
                               '(list indx nil)}); 
                     add_exp group>>
             else if current eq '!)
              then if null groupstack then rederr "Unmatched Parentheses"
                    else begin scalar group;
                      group := car groupstack; 
                      groupstack := cdr groupstack; 
                      add_exp ({'set_group_end, group - 1, 'indx}); 
                      add_exp ( - group)
                   end
             else if current eq '!| then rederr "variants not yet implemented"
             else if current eq '![
              then begin scalar value; integer leng; 
                      value := regex_charclass source; 
                      leng := car value; 
                      value := cdr value; 
                      source := pnth0(source,leng); 
                      add_vector_exp value
                   end
             else if current eq '!\
              then begin scalar value; integer leng; 
                      value := regex_quoted(source,nil); 
                      leng := car value; 
                      value := cdr value; 
                      source := pnth0(source,leng); 
                      if not atom value
                        then if car value eq 'group_ref
                               then add_group_ref_exp value
                              else if car value eq 'wordboundary
                               then rederr "Word boundaries not yet implemented"
                              else if car value eq 'nonwordboundary
                              
           then rederr "Non word boundaries not yet implemented"
          else nil
                       else if vectorp value then add_vector_exp value
                       else add_simple_char_exp value
                   end
             else add_simple_char_exp current
         end; 
      add_exp '(set_group_end 0 indx); 
      add_exp '(return t); 
      for j := 1:length expression do 
         begin scalar piece; 
            piece := nth(expression,j); 
            if idp piece or eqcar(piece,'brace)
              then <<result := compile_regex_closure(expression,j,result); 
                     j := car result; 
                     result := cdr result>>
             else if not atom piece then add2result piece
             else t
         end;
      if not null groupstack then rederr "Unmatched Parentheses!";
      if anchored
        then result := 
              {'lambda, 
               '(string), 
               {'prog, 
                '(indx len retval), 
                '(cond ((stringp string) (setq string (explode2 string)))), 
                {'setq, '!*regex!-groupings!*, group}, 
                '(setq indx 0), 
                '(setq len (length string)), 
                {'setq, 'retval, 'prog . nil . result},
                '(cond ((null retval) (putv !*regex!-groups!* 0 nil))),
                '(return retval)  
                  }}
       else result := 
             {'lambda, 
              '(string), 
              {'prog, 
               '(start len retval), 
               '(cond ((stringp string) (setq string (explode2 string)))), 
               {'setq, '!*regex!-groupings!*, group}, 
               '(setq start 0), 
               '(setq len (length string)), 
               fastfirst, 
               {'setq,
                'retval,
                {'prog, 
                 '(marker indx), 
                 '(setq marker start), 
                 'tag, 
                 '(cond ((greaterp marker len) (return nil))), 
                 '(setq indx marker), 
                 {'cond, {'prog . ('nil . result), '(return t)}}, 
                 '(setq marker (add1 marker)), 
                   '(go tag)}},
                 '(cond ((null retval) (putv !*regex!-groups!* 0 nil))),
                 '(return retval)
                 }}; 
      return result
   end;

symbolic smacro procedure next_exp; 
   begin scalar nex; 
      nex := nth(expression,j := j + 1); 
      return if not atom nex then nex
              else begin integer groupno; scalar nexl; 
                      groupno :=  - nex; 
                      nexl := {'(return t)}; 
                      nexl := nth(expression,j := j + 1) . nexl;     % skip set_group_ref
                      while (nex := nth(expression,j := j + 1)) neq groupno do 
                         <<if idp nex or eqcar(nex,'brace)
                             then <<nex := 
                                     compile_regex_closure(expression,j,nexl); 
                                    j := car nex; 
                                    nexl := cdr nex>>
                            else nexl := nex . nexl>>; 
                      return 'progn . nexl
                   end
   end;

symbolic procedure compile_regex_closure(expression,j,result); 
   begin scalar piece; 
      piece := nth(expression,j); 
      if piece eq 'question
        then begin scalar nex; 
                nex := next_exp(); 
                if numberp car nex
                  then add2result ({'cond, 
                                    {'prog
                                       . ('nil . (cdr nex . {'(return t)})), 
                                     t}, 
                                    {t, {'set_group_end, car nex, 'indx}}})
                 else add2result ({'prog, 'nil, nex, '(return t)})
             end
       else if piece eq 'asterisk
        then begin scalar nex; 
                nex := next_exp(); 
                result := {form_variant_exp(nex,0,nil,result)}; 
                regex_info ({"Constructed * result:", result})
             end
       else if piece eq 'plus
        then begin scalar nex; 
                nex := next_exp(); 
                result := {form_variant_exp(nex,1,nil,result)}; 
                regex_info ({"Constructed + result:", result})
             end
       else if eqcar(piece,'brace)
        then begin integer max,min; scalar nex; 
                min := cadr piece; 
                max := caddr piece; 
                nex := next_exp(); 
                result := {form_variant_exp(nex,min,max,result)}; 
                regex_info ({"Constructed {...} result:", result})
             end
       else rederr ({"Internal error in compile_regex_closure:", piece}); 
      return j . result
   end;

global '(!*regex!-digits!*
         !*regex!-nodigits!*
         !*regex!-alpha!*
         !*regex!-noalpha!*
         !*regex!-white!*
         !*regex!-nowhite!*);

!*regex!-digits!* := mkvect 256;
!*regex!-nodigits!* := mkvect 256;
!*regex!-alpha!* := mkvect 256;
!*regex!-noalpha!* := mkvect 256;
!*regex!-white!* := mkvect 256;
!*regex!-nowhite!* := mkvect 256;

for i := 48:57 do <<putv(!*regex!-digits!*,i,t); putv(!*regex!-alpha!*,i,t)>>;

for i := 65:90 do putv(!*regex!-alpha!*,i,t);
for i := 97:122 do putv(!*regex!-alpha!*,i,t);
putv(!*regex!-alpha!*,95,t);   % _

putv(!*regex!-white!*,32,t);   % SPACE
putv(!*regex!-white!*,9,t);    % TAB
putv(!*regex!-white!*,10,t);   % NEWLINE
putv(!*regex!-white!*,13,t);   % CR
putv(!*regex!-white!*,15,t);   % FORMFEED

for i := 0:255 do 
   <<putv(!*regex!-nodigits!*,i,not getv(!*regex!-digits!*,i)); 
     putv(!*regex!-noalpha!*,i,not getv(!*regex!-alpha!*,i)); 
     putv(!*regex!-nowhite!*,i,not getv(!*regex!-white!*,i)); 
     nil>>;

symbolic procedure is_digit_char c; 
   char2num c>=char2num '!0 and char2num c<=char2num '!9;

symbolic procedure regex_brace source; 
   begin integer used; scalar endd,start,dlist,current; 
      while is_digit_char (<<used := used + 1; next_source_char()>>) do 
         dlist := current . dlist; 
      if dlist then <<start := compress reversip dlist; dlist := nil>>
       else start := 0; 
      if not(current eq '!,) then rederr "Invalid character in brace"; 
      while is_digit_char (<<used := used + 1; next_source_char()>>) do 
         dlist := current . dlist; 
      if dlist then <<endd := compress reversip dlist>>; 
      return {used, start, endd}
   end;

symbolic procedure set_range(vect,min,max,value); 
   <<if min>max
       then rederr ({"Invalid range", num2char min, "-", num2char max}); 
     for i := min:max do putv(vect,i,value)>>;

symbolic procedure set_from_charclass(vect,cc,value); 
   for i := 0:255 do if getv(cc,i) then putv(vect,i,value);

symbolic smacro procedure end_range c; 
   <<set_range(vect,rangestart,if c then c else 255,setchar); 
     rangestart := nil>>;

symbolic procedure regex_charclass source; 
   begin integer used; scalar rangestart,previous,current,setchar,vect,invert; 
      if null source then eoserror(); 
      vect := mkvect 256; 
      invert := car source eq '!^; 
      if invert
        then <<next_source_char(); used := 1; for i := 0:255 do putv(vect,i,t)>>
       else <<setchar := t; used := 0>>; 
      while not((<<used := used + 1; next_source_char()>>) eq '!]) do 
         <<if current eq '!\
             then begin scalar value; 
                     value := regex_quoted(source,t); 
                     used := used + car value; 
                     source := pnth0(source,car value); 
                     value := cdr value; 
                     if vectorp value
                       then <<set_from_charclass(vect,value,setchar); 
                              previous := nil>>
                      else previous := value; 
                     if rangestart then end_range previous
                  end
            else if current eq '!-
             then <<if rangestart then end_range char2num '!-
                     else rangestart := if previous then previous else 0; 
                    previous := nil>>
            else <<if rangestart
                     then <<end_range char2num current; previous := nil>>
                    else <<if previous then putv(vect,previous,setchar); 
                           previous := char2num current>>>>>>; 
      % finish possible open range
      if rangestart then end_range 255
       else if previous then putv(vect,previous,setchar);
      return used . vect
   end;

symbolic procedure regex_quoted(charlist,flag); 
   % flag is true if inside []
   begin integer used; scalar result,first; 
      result := (first := car charlist); 
      used := 1; 
      if first eq '!d then result := !*regex!-digits!*
       else if first eq '!D then result := !*regex!-nodigits!*
       else if first eq '!w then result := !*regex!-alpha!*
       else if first eq '!W then result := !*regex!-noalpha!*
       else if first eq '!s then result := !*regex!-white!*
       else if first eq '!S then result := !*regex!-nowhite!*
       else if first eq '!n then result := num2char 10 % NEWLINE
       else if first eq '!r then result := num2char 13 % CR
       else if first eq '!t then result := num2char 9  % TAB
       else if first eq '!f then result := num2char 12 % FF
       else if first eq '!b
        then if flag then result := num2char 8         % BACKSPACE
              else result := '(wordboundary)
       else if first eq '!B and null flag then result := '(nonwordboundary)
       else if is_digit_char first
        then if length charlist>2
                  and is_digit_char cadr charlist
                  and is_digit_char caddr charlist
               then <<result := 0; 
                      for i := 1:3 do 
                         result := 8*result + char2num nth(charlist,i); 
                      result := num2char result; 
                      used := 3>>
              else if flag then result := first
              else begin integer group; 
                      group := char2num first - char2num '!0; 
                      result := {'group_ref, group}
                   end
       else result := first; 
      return used . result
   end;

endmodule;

end;
