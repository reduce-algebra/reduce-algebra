% comphelp.red:
%
%  first part of the REDUCE help compiler: syntax analysis
%   and structure generation.
%
%  the second part contains target specific code.
%
%  Author: Herbert Melenk, ZIB Berlin
%
%  November 1992
%

symbolic;

fluid '(char!* infile!* outfile!* !*windows !*test !*myeof);
fluid '(printfunction!* sect_count endchar current_node!*);
fluid '(!*verbatim !*sqbkt !*opennode currentfont topiccount!*);
fluid '(courier helvetica outc beginstack filestack level);
fluid '(nodechain undo match_point_lft match_point_rgt);
fluid '(run!* dir_src);
fluid '(aliases package);
fluid '(section_list regoup_sections);
fluid '(help_gensym_count);


run!* := 0;

% !*test := t;
regoup_sections := nil;

%------------------------------------------------------------
%
%  MAIN PROGRAM
%
%------------------------------------------------------------

symbolic procedure job(infile,outfile);
  begin  scalar !*raise, !*lower;
    help_gensym_count := 1;
    section_list := nil;
    !*myeof := nil;
    if getenv "echo" then !*echo:=t;
    run!* := run!* + 1;
    reset(); terpri();
    if run!* = 2 then update_labels();
    !*opennode := nil;
    sect_count:=1;
    topiccount!* := 0;
    printfunction!*:=nil;
    if infile!* then close infile!*;
    if outfile!* then close outfile!*;
    infile!*:=open(bldmsg("%w%w",dir_src,infile),'input);
    outfile!*:=open(outfile,'output);
    channellinelength(outfile!*,200);
    initoutput();
    newfont helvetica;
    mainloop();
    close_section 'document;
    write_sections();
    fontoff();
    endoutput();
    close infile!*;
    infile!* :=nil;
    if outfile!* then close outfile!*;
    outfile!*:=nil;
  % printstruct();
  end;

%------------------------------------------------------------
%
%  file input
%
%------------------------------------------------------------

fluid '(oldchar !*myecho !*myeof);

!*myecho := nil;
!*myeof := nil;

symbolic procedure rdch(); rdchr0(nil);

symbolic procedure rdch!*(); rdchr0(t);

symbolic procedure rdchr0(q);
 if !*myeof then !$eof!$ else
 if oldchar then <<oldchar := nil; old>> where old = oldchar
   else
 <<char!*:= channelreadch(infile!*);
   if !*myecho then prin2 char!*;
   if inf char!* = 9 then char!* := tab!* else  % tab
   if not q and prevchar neq '!\ and char!*='!% then
     <<while !$eol!$ neq channelreadch(infile!*) do nil;
       rdch()>>
        else char!*
 >> where prevchar = char!*;

symbolic procedure unrdch(); oldchar := char!*;

symbolic procedure myskip c;
     while (c neq rdch()) do nil;

symbolic procedure myskipl l;
   begin scalar c;
       while not memq(c:=rdch(),l) do nil;
       return c;
   end;

symbolic procedure myskipstring(s1,s2);
  begin scalar l,c,r;
    l:=explode2 s2;
    while l do
    <<c:=rdch(); r:=c.r;
      if c neq car l then
       error(99, {"EXPECTED:", {s1,s2},"FOUND:",{s1,reversip r}});
      l:=cdr l;
    >>;
  end;

fluid '(case!*);

case!*:= if '!N!I!L then 'lower else 'upper;

symbolic procedure mytoken(fold);
 begin scalar tok,c,n;
   tok:={'!"};
   while digit(c:=rdch()) or liter c do
      << n:=id2int c;
         if fold then
         if case!* = 'upper and n then
              c:=int2id(n-32)
         else if case!*='lower and 64<n and n<91 then
              c:=int2id(n+32);
        tok:=c.tok;
      >>;
     % if we have found a token, eat up the following blanks.
%  if cdr tok then while c='!  do c:=rdch();  % ACH: loses a char.
   if null cdr tok then return nil;
   tok := compress reverse('!".tok);
   return intern tok;
end;

symbolic procedure mystring();
 begin scalar tok,c;
   while digit(c:=rdch()) or liter c or c='!  or
	(endchar and c neq endchar) do
           tok:=c.tok;
   return reversip(tok);
end;

symbolic procedure mystring2();
  % read string util }, but ignore \}
 begin scalar tok,c;
   while (c:=rdch()) neq '!} do tok:=c.tok;
   return reversip(tok);
end;

symbolic procedure mystring2!]();
  % read string util ], but ignore \}
 begin scalar tok,c;
   while (c:=rdch!*()) neq '!] do tok:=c.tok;
   return reversip(tok);
end;

symbolic procedure mystring_nodename();
  % read node name, eventually updating the name translation table
  % for entries like "\begin{Command}[percent]{%}"
  % read string util }, but ignore \}
 begin scalar tok,c,alt;
   c:=myskipl '(!{ ![);
   if c='![ then
   << alt := mystring2!]();  myskip '!{ >>;
   while (c:=rdch!*()) neq '!} do tok:=c.tok;
   tok := reversip tok;
   if alt then aliases := (alt . tok) . aliases;
   return alt or tok;
end;

symbolic procedure mystring3();
 begin scalar tok,c;
  loop:
   c:=rdch();
   if c='!\ then <<tok := rdch().tok; goto loop>>;
   if c= '!}  then return reversip(tok);
   tok := c.tok; goto loop;
end;

symbolic procedure raisestring(s);
 begin scalar n;
  return for each c in s collect
   if (n:=id2int c)>95 then
        int2id(n-32) else c;
 end;

symbolic procedure lowerstring(s);
 begin scalar n;
  return for each c in s collect
   if liter c and (n:=id2int c)<95 then
        int2id(n+32) else c;
 end;

symbolic procedure mycompress u;
     compress reversip('!" . reverse('!" . u));

%---------------------- main loop ----------------------------

symbolic procedure mainloop();
  begin scalar u,c,tok,f,undo;
  loop:
    c:=rdch();
    if c=!$eof!$ then goto finis;
    if endchar and c=endchar then
    <<endchar:=nil; goto finis>>;
    if c='!{ then
     <<
      begin scalar endchar;
        endchar := '!};
        mainloop();
      end;
      goto loop;
     >>;
    if c='!\ then
    <<tok:=mytoken(t);
      if tok='ENDINPUT then <<!*myeof := t; goto finis>>;
      if null tok then
        <<c:=if char!*='!\ then !$eol!$ else c:=char!*;
          goto char>>;
      if tok='documentstyle then
         <<myskip('!}); goto loop>>
         else
      if tok='end then
         <<u:=mytoken(t);
           if !*test then <<prin2 " \end{"; prin2 u; prin2 "} ">>;
           if u neq car beginstack then
           <<prin2t {"****** begin(",car beginstack,
                     ") ended with end (",u,")"};
             exitlisp(1);
           >>;
           if !*test then printf(" (main pop %w)",beginstack);
           beginstack := cdr beginstack;
           goto finis>>
         else
      if(f:=get(tok,'act)) then
        <<
          if !*test then <<prin2 " \"; prin2 tok; prin2 " ">>;
          apply1(f,tok);
          if flagp(f,'simple) then oldchar := char!*;
          goto loop;
        >>
         else
         printf("**** unknown token: %w %n",tok);
    >>;
  char:
    if printfunction!* then apply1(printfunction!*,c);
    goto loop;
  finis:
    for each u in undo do eval(u);
  end;

%-----------------\input{...} \include{ ...}-----------------

symbolic procedure include(u);
  begin scalar file,fname,fname1,endchar;
    endchar := '!};
    fname:=mycompress mystring();
    if fname = "intro" then return;
    fname:=bldmsg("%w%w",dir_src,fname);
    endchar := nil;
    file:=errorset({'open,mkquote fname,mkquote 'input},nil,nil);
    if not errorp file then goto found;
    fname1:=bldmsg("%w.tex",fname);
    file:=errorset({'open,mkquote fname1,mkquote 'input},nil,nil);
    if not errorp file then goto found;
    printf("***** cannot open file >%w< resp. >%w< %n",fname,fname1);
    return nil;
  found:
    if fname1 then fname := fname1;
    filestack:=infile!*.filestack;
    infile!* :=car file;
    terpri(); prin2 "--- input file "; prin2t fname;
    mainloop();
    terpri(); prin2 "--- return from file "; prin2t fname;
    close infile!*;
    !*myeof := nil;
    infile!*:=car filestack;
    filestack := cdr filestack;
  end;

put('input,'act,'include);
put('include,'act,'include);

put('makeindex,'act,'null);
put('tt,'act,'null);

%-------------------section hierarchy -----------------------

symbolic procedure print_indent();
   if numberp level then for i:=1:level do prin2 "   ";

fluid '(record act_rec node_count);

node_count := 0;

smacro procedure type(u); car u;
smacro procedure seq(u); cadr u;
smacro procedure lab(u); caddr u;
smacro procedure count(u); cadddr u;
smacro procedure name(u);car cddddr u;

symbolic procedure reset();
  <<
   record :=
   {
    %  type        seq   lab  nr     name
      {'document,  nil,  "main_index",
                              1,     '(!T !o !p)},
%                             1,     "Top"},
      {'section,   nil,  nil, 1,     nil},
      {'subsection,nil,  nil, 1,     nil},
   {'subsubsection,nil,  nil, 1,     nil}};
   act_rec:= car record;
  >>;

symbolic procedure sectappend r;
    % link tail from next record to cont of first one
  car cdar r :=(cdr cadr r) . seq car r;

%-------------------- section -------------------------------


symbolic procedure section(s);
  begin scalar name;
    current_node!* := nil;
    name:=mystring2();
    close_section(s);
    open_section(s,name);
  end;

symbolic procedure close_section(s);
 begin scalar r;
   r:=record;
   while r and caar r neq s do r:= cdr r;
   if null r then  error({"record empty",s},99);
   for each u in reverse r do close_section1 u;
 end;

symbolic procedure close_section1(rec);
  if name rec then
  begin
     if !*windows then
     << print_indent(); reporttopic("               section end: ");
        terpri();
     >>;
     if regoup_sections then
          section_list := append(rec,nil) . section_list
       else
          write_section(rec);
     cdr rec:={nil,nil,0,nil};
  end;

symbolic procedure write_sections();
  for each s in section_list do write_section s;

symbolic procedure write_section(rec);
  if name rec then
  begin
     if !*opennode then emit_node_separator();
     !*opennode:=nil;
     emit_dir_new();
     emit_dir_label(lab rec);
     emit_dir_title name rec;
     emit_dir_browse('index,count rec);
     emit_dir_key(name rec);
     print_bold name rec;
     emit_dir_header();
     for each x in reverse seq rec do
       make_dir_entry (nil.x);
     emit_dir_separator();
  end;

symbolic procedure make_dir_entry rec;
    emit_dir_entry(name rec,lab rec);

symbolic procedure help_gensym();
  compress ('!g . explode2 (help_gensym_count := help_gensym_count+1));

symbolic procedure open_section(s,n);
   begin scalar r;
     sect_count:=sect_count+1;
     r:= record;
     while r and cdr r and caadr r neq s do r:=cdr r;
     if null r then  error({"record empty",s},99);
         % initialize new section and link to parent
     if not !*windows then n:=append(n, '(!  !s !e !c !t !i !o !n));
     cdr cadr r:={nil,help_gensym(),sect_count,n};
     sectappend r;
     r:= cadr r;
     level := if s='section then 0 else
              if s='subsection then 1 else
              if s='subsubsection then 2 else 3;
     print_indent();
     for each c in lowerstring explode2 s do prin2 c;
     prin2 " ";
     prin2 count r; prin2 " ";
     prin2 lab r; prin2 " ";
     mapc(name r,'prin2); terpri();
     act_rec := r;
     base_new_dir name r;
     level := if s='section then 1 else
              if s='subsection then 2 else
              if s='subsubsection then 3 else 4;
  end;

put('section,'act,'section);
put('subsection,'act,'section);
put('subsubsection,'act,'section);


%------------------- begin-end contexts ---------------------------

symbolic procedure beg(u);
  begin scalar tok,f,w;
    tok:=mytoken(t);
    for each c in beginstack do w:=w or (get(c,'context)='node);
    if w and 'node=get(tok,'context) then
     <<printf("===== missing end of node; hierarchy: %w",beginstack);
        exitlisp()>>;
    if !*test then <<terpri(); prin2 "\begin{"; prin2 tok;prin2 "}">>;
    if !*test then printf(" (push %w)",tok);
    beginstack := tok.beginstack;
    f:=get(tok,'context);
    if f then apply1(f,tok) else
    <<prin2t {"******* unknown begin-context:",tok};
      mainloop()>>;
  end;

put('begin,'act,'beg);

symbolic procedure mmain(u); mainloop();

put('document,'context,'mmain);

%------------------- generate unique labels  ----------------------

fluid '(labels!* l_list name_trans);

symbolic procedure clean_name u;
    if null u then nil else
    if car u memq '(!- !, !? !* !> !< !. ! )
      then '!_ . clean_name cdr u else
       car u . clean_name cdr u;


name_trans :='(
    ((!,) . COMMA_sign)
    ((!.) . DOT_sign)
    ((!;) . SEMICOLON_sign)
    ((!%) . PERCENT_sign)
    ((!$) . DOLLAR_sign)
    ((!: !=) . ASSIGN_sign)
    ((!=) . EQUAL_sign)
    ((!+) . PLUS_sign)
    ((!-) . MINUS_sign)
    ((!*) . TIMES_sign)
    ((!/) . SLASH_sign)
    ((!* !*) . POWER_sign)
    ((!$ !> != !$) . GEQ_sign)
    ((!> !=) . GEQ_sign)
    ((!>) . GREATER_sign)
    ((!$ !< != !$) . LEQ_sign)
    ((!< != ) . LEQ_sign)
    ((!<) . LESS_sign)
    ((!< !<) . BLOCK));


symbolic procedure make_label(name, type, alias);
   begin scalar u,s,w,uname;
    uname := raisestring name;
    if !*windows then
     << alias := clean_name alias;
        name := clean_name name>>;
    s := uname . type;
    u := assoc (s,labels!*);
    if u and run!* = 1 then
   <<prin2 " ######## duplicate node ";
     prin2 name;
     terpri();
   >>;
    if u then return cadr u;
    labels!* := (s.(w:=alias.name.type)). labels!*;
    if not member(uname,l_list) then
            l_list := uname . l_list;
    return car w;
  end;

symbolic procedure get_label name;
  (if l then car l) where l=get_label1 name;

symbolic procedure patch_ u;
  if null u then nil else
  if car u = '!_ then '!\ . '!_ . patch_ cdr u
   else car u . patch_ cdr u;

symbolic procedure get_label1 name;
  begin scalar u,uname;
   uname := raisestring name;
   u := get_label2 uname or get_label2 patch_ uname;
   if null u and (run!* > 1) then
   <<prin2 " ######## reference to ";
     prin2 name;
     prin2t "  not found,";
   >>;
   return if u then cdr u else nil;
  end;

symbolic procedure get_label2 uname;
  begin scalar u,uname;
   u := assoc((uname . 'operator),labels!*)
     or assoc((uname . 'function),labels!*)
     or assoc((uname . 'switch),labels!*)
     or assoc((uname . 'statement),labels!*)
     or assoc((uname . 'command),labels!*)
     or assoc((uname . 'declaration),labels!*)
     or assoc((uname . 'variable),labels!*)
     or assoc((uname . 'type),labels!*)
     or assoc((uname . 'constant),labels!*)
     or assoc((uname . 'concept),labels!*)
     or assoc((uname . 'package),labels!*)
     or assoc((uname . 'introduction),labels!*);
   return u;
  end;

symbolic procedure update_labels();
  % for unique names use the name as label.
  begin scalar new,old;
   terpri();
   prin2t "------ updating node labels -----";
   for each p in l_list do
    if (p:=get_label1 p) then
    <<old := car p; new := cadr p;
      car p := new;
      if nodechain then
        nodechain := substipq(new,old,nodechain);
    >>;
   prin2t "------ updating done ------------";
  end;

%------------------- nodes ------------------------------------

symbolic procedure node(type);
  begin scalar name,name2,rname,type2,name3,rec,type3,name4,label;
     scalar altname,alias;
     printfunction!* := 'textout;
     if !*opennode then emit_node_separator();
     !*opennode:=t;
     % myskip '!{;
     name:=mystring_nodename();
     if altname:=assoc(name,name_trans) then
       name := explode2 cdr altname;
%    alias := if !*windows and assoc(name,aliases) then
%         cdr assoc(name,aliases);
     alias := if assoc(name,aliases) then
          cdr assoc(name,aliases);
     type3 := lowerstring (type2:=explode2 type);
     name2 :=type . '!  . (rname:=raisestring name);
     name3 := append(type3,'!  . name);
     name4 := append(name, '!  . type3);
     label := make_label(name,type,name4);
     rec := {'node,
              nil,
              label,
              node_count:=add1 node_count,
              name4};
     car cdr act_rec:= cdr rec . seq act_rec;
     fonton();
     print_indent();
     mapc(name3,'prin2); reporttopic(" "); terpri();
     emit_node_label(lab  rec);
     emit_node_title(lab rec,name,type);
     emit_node_browse(lab act_rec,count rec);
     emit_node_keys(name4);
     current_node!* := name4;
     emit_hidden_node_key(type3);
     emit_hidden_node_key(name rec);
       % header line;
     myterpri();
     if alias  then <<print_bold alias; print_tab();>>;
     print_bold rname;
     if type2 neq '(C O N C E P T) then
     << print_tab(); print_tab(); print_tab(); print_tab();
        print_bold type2;
     >>;
     print_newline();  second_newline();
     mainloop ();
  end;

put('switch,'context,'node);
put('variable,'context,'node);
put('operator,'context,'node);
put('function,'context,'node);
put('command,'context,'node);
put('statement,'context,'node);
put('declaration,'context,'node);
put('concept,'context,'node);
put('introduction,'context,'node);
put('package,'context,'node);
put('type,'context,'node);
put('constant,'context,'node);


symbolic procedure part(type);
   begin
     outc:='! ;
     if type='examples or type='syntax or type='related
            then par_heading(type) else
     if type='bigexample then par_heading('example);

     if type='bigexample or type='verbatim then return vpart(type) else
     if type='examples then return examples_part(type);
     if type='syntax or type='examples then newfont courier;
     mainloop();
     second_newline(); second_newline();
     newfont helvetica;
    end;

symbolic procedure par_heading(type);
 <<verbprin2 !$eol!$;
   for each x in explode type do verbprin2 x;
   verbprin2 ":";
   verbprin2 !$eol!$; verbprin2 !$eol!$;
 >>;

symbolic procedure vpart(type);
  % formatted / verbatim part.
  begin
     emit_start_verbatim();
     set_tab();
     newfont courier;

     vpart0();

     emit_end_verbatim();
     newfont helvetica;
   end;

symbolic procedure vpart0();
  begin scalar c,c1,c2,c3;
  loop:
    c:=rdch();
    if c=!$eof!$ then rederr "#### EOF in verbatim part";
    if c='!\ then
    <<c2:=c3:=nil;
      if (c1:=rdch()) = '!\ then <<verbprin2 !$eol!$; goto loop>>;
      if c1 = '!e and (c2:=rdch()) = '!n and (c3:=rdch()) = '!d
         then goto done;
      verbprin2 '!\; verbprin2 c1;
      if c2 then verbprin2 c2;
      if c3 then verbprin2 c3;
      goto loop>>;
    verbprin2 c;
    goto loop;
done:
     rdch();
     mytoken(t);
     if !*test then printf(" (vpart pop %w)",beginstack);
     beginstack := cdr beginstack;
     release_tab();
   end;

symbolic procedure compareahead(seq,l); compareahead1(seq,cdr seq,l);

symbolic procedure compareahead1(base,seq,l);
   if null l then t else
   if null seq then compareahead1(nconc(base,c),c,l) where c={rdch()}
    else
   if not(car seq = car l) then nil else
        compareahead1(base,cdr seq,cdr l);

macro procedure  look_ahead(m);
    {'compareahead,'inlist,mkquote explode2 cadr m};

symbolic procedure examples_part(type);
  % formatted / verbatim part.
  begin scalar c,pg,state,tab_flag,pg,ll,l,endflag,eolflag,inlist;
     emit_start_verbatim();
     set_tab();
     newfont courier;
     state := 'lhs;
  read_next:
    eolflag := nil;
    ll := nil;
  read_loop:
    c:=rdch();
    if c=!$eof!$ then rederr "#### EOF in examples part";
    if c='!\ then
    <<inlist :={nil};
      if look_ahead "\" then
           <<eolflag := t;
             if state = 'rhs then goto rhs_line
                 else goto tab_label>>;
      if look_ahead "end{Examples}"
         then <<endflag := t;
                if !*test then prin2t "\end{Examples}";
                if state = 'rhs then goto rhs_line else goto done;
              >>
        else
      if look_ahead "explanation"
         then << myskip '!{;
                 non_verb_block() where endchar='!};
                 goto read_next;
              >>        else
      if look_ahead "begin{multilineinput}"
         then <<
                 beginstack := 'multilineinput.beginstack;
                 vpart0();
                 goto read_next;
              >>;
      if state neq 'rhs and look_ahead "begin{multilineoutput}"
         then <<
                 beginstack := 'multilineoutput.beginstack;
                 vpart0();
                 goto read_next;
              >>;
      ll := '!\ . ll;
      for each q in cdr inlist do if q then ll := q . ll;
      goto read_loop
    >>
    else if c='!& then
     <<if state = 'lhs then goto tab_label else
       <<mapc(reverse ll,'prin2); rederr "#### second & in example">>
     >>
    else ll := c . ll;
    goto read_loop;
tab_label:
    while ll and cdr ll and car ll = '!  and cadr ll = '!  do
      ll := cdr ll;  % remove trailing blanks.
    l := reversip ll;
    for each c in l do
    %  if not c=!$eol!$ then
         verbprin2 c;
    if eolflag then
    <<verbprin2 !$eol!$; goto read_next>>;
    if length l > 35 then verbprin2 !$eol!$;
 %% verbprin2 '!&;
 %% verbprin2 "=>";
    state := 'rhs;
    goto read_next;

 rhs_line:
    verbprin2 !$eol!$;
    ll:=reversip ll;
       % remove leading blanks
    ll := delete(!$eol!$,ll);
    while ll and car ll = '!  do ll:= cdr ll;

   goto no_expla;
    if matchleft(ll,'(!\ !e !x !p !l !a !n !a))
     then
     <<while ll and not (car ll = '!{) do ll := cdr ll;
       ll:= cdr ll;
       newfont helvetica;
       while ll and not(car ll = '!}) do
        <<textout car ll;ll:= cdr ll>>;
       ll := cdr ll;
     >>;

   no_expla:
     % provide for multiline
    if matchleft(ll,'(!\ !b !e !g !i !n
                    !{ !m !u !l !t !i !l !i !n !e !o !u !t !p !u !t !}))
    then pg:=make_multi_out() ELSE pg:=minitex ll;

    if null pg then goto nix;
    tab_flag :=  t;
 %% if cadr pg > 35 then
    <<verbprin2 !$eol!$; verbprin2 "  "; tab_flag := nil>>;
    pg := cddr pg;
    while pg do
    <<l := car pg; pg := cdr pg;
      for each c in l do verbprin2 c;
      if pg then
      <<verbprin2 !$eol!$;
        if tab_flag then verbprin2 '!&;
        verbprin2 "  ";
      >>;
    >>;
    verbprin2 !$eol!$;
  nix:
    verbprin2 !$eol!$;
    state := 'lhs;
    if endflag then goto done;
    goto read_next;

done:
    emit_end_verbatim();
     if !*test then printf(" (examples pop %w)",beginstack);
     beginstack := cdr beginstack;
     release_tab();
     newfont helvetica;
   end;

symbolic procedure non_verb_block();
  begin
   emit_end_verbatim();
   release_tab();
   newfont helvetica;
   mainloop ();
   newfont courier;
   set_tab();
   emit_start_verbatim();
  end;

symbolic procedure make_multi_out();
 begin scalar con,w,pg,m,q;
       con:=t;
       w := cdr match_point_rgt;
         % get rid of "{6cm}"
       while w and car w neq '!} do w:=cdr w;
       if w then w:=cdr w;
       if member(!$eol!$,w) then
       <<q:=cut_lines(w,nil); w:= car q; q:=cdr q>>;
       pg:=nil;
       m:=0;
   mult_loop:
       match_point_lft:=nil;
       if matcharb(w, '(!\ !e !n !d !{ !m !u !l !t !i !l !i !n !e ))
       then<< con:=nil;
              if match_point_lft then cdr match_point_lft:=nil else w:=nil;
           >>;
       if w then
          <<if length w>m then m:=length w;
              if memq('!^,w) or memq('!{,w) then
                pg := append(pg,cddr minitex w)
                  else
                pg:=append(pg,{w})
          >>;
       if con then
       <<
         if q then <<w:=car q;q:=cdr q>> else w:=read_one_line();
         goto mult_loop
       >>;
       pg := length pg . m . pg;
       return pg;
    end;

symbolic procedure cut_lines(l,q);
    if null l then {reversip q} else
    if car l = !$eol!$ then reversip q . cut_lines(cdr l,nil)
    else cut_lines(cdr l,car l . q);

%   match_point_lft:  pair before match position
%   match_point_rgt:  last pair of matched string

symbolic procedure matchleft(a,pat);
  if null pat then t else
  if null a then nil else
  if car a neq car pat then
       <<match_point_lft:=a; nil>>
   else <<match_point_rgt:=a;
          matchleft(cdr a,cdr pat)>>;

symbolic procedure matcharb(a,pat);
  if null a then nil else
  matchleft(a,pat) or matcharb(cdr a,pat);

symbolic procedure read_one_line();
  begin scalar l,c;
 loop:
   c := rdch();
   if c=!$eol!$ then return reversip l;
   l := c.l;
   goto loop;
  end;

put('comments,'context,'part);
put('examples,'context,'part);
put('bigexample,'context,'part);
put('syntax,'context,'part);
put('related,'context,'part);
put('text,'context,'part);
put('verbatim,'context,'part);
put('quote,'context,'part); % QUOTE -> VERBATIM (temporal)

symbolic procedure do!-itemize(type);
   begin
     outc:='! ;
     mainloop();
     second_newline();
    end;

put('itemize,'context,'do!-itemize);

symbolic procedure context_error(p,q);
  <<
    terpri();
    prin2 "######### error in context ";
    prin2 p;
    prin2 " ### : ";
    prin2t q;
  >>;

%-------------------- special item routines ----------------------

symbolic procedure verb(u);
  begin scalar endchar,!*verbose;
     endchar := char!*; !*verbose:=t;
     mainloop();
  end;
put('verb,'act,'verb);

symbolic procedure ldots(u); textout "...";
put('ldots,'act,'ldots);
flag('(ldots),'simple);

symbolic procedure cdots(u); textout "...";
put('cdots,'act,'cdots);
flag('(cdots),'simple);

symbolic procedure cdot(u); textout ". ";
put('cdot,'act,'cdot);
flag('(cdot),'simple);


symbolic procedure write_pi(u); textout "pi";
put('pi,'act,'write_pi);
flag('(write_pi),'simple);

symbolic procedure emphase(u); printem mystring3();
put('key,'act,'emphase);

symbolic procedure meta(u);
    <<textout "<"; mapc(mystring2(),'textout); textout ">">>;

put('meta,'act,'meta);

symbolic procedure italic(u);
   <<switchitalic(t);
     unrdch();
     undo := '(switchitalic nil).undo>>;
symbolic procedure switchitalic u; nil;
put('bf,'act,'italic);
put('em,'act,'italic);
put('it,'act,'italic);

symbolic procedure nameref(u); printnameref mystring3();
put('nameref,'act,'nameref);

symbolic procedure ref(u); printref mystring2();
put('ref,'act,'ref);

symbolic procedure see(u);
     begin
       u:=mystring2();
    %  textout2 u; textout '! ;
       emit_node_key u;
     end;

put ('see,'act,'see);

symbolic procedure myname(u);
    printem mystring3();
put ('name,'act,'myname);

symbolic procedure myindex(u);
     <<textout '! ;emit_node_key mystring2()>>;
put('index,'act,'myindex);

symbolic procedure nameindex(u);
    begin scalar s;
      s:= mystring2();
      textout '! ;
      emit_hidden_node_key s;
      printem s;
    end;
put('nameindex,'act,'nameindex);

symbolic procedure reduce(u); textout "REDUCE";
put('reduce,'act,'reduce);
flag('(reduce),'simple);

symbolic procedure rept(u); textout "+";
put('repeated,'act,'rept);
flag('(rept),'simple);

symbolic procedure optional(u); textout "*";
put('optional,'act,'optional);
flag('(optional),'simple);

symbolic procedure myexp(u); <<textout"(";textout "exp">>;
put('exp,'act,'myexp);

symbolic procedure formula(u); textoutl mystring2();
put('variable,'act,'formula);
put('arg,'act,'formula);

symbolic procedure rfrac(u);
   <<textoutl mystring2();
     rdch();
     textout "/";
     textoutl mystring2();
   >>;
put('rfrac,'act,'rfrac);

symbolic procedure item(u);
   begin scalar endchar;
     endchar := '!];
     print_newline();
     if !*windows then print_tab();
     mainloop();
  end;

put('item,'act,'item);

%-------------------- support for iftex etc. ---------------------

symbolic procedure texonly1(u);
   begin scalar endchar,c;
    integer count;
    count:=1;
  loop:
    c:= rdch();
    if c='!\ then c:= rdch() else
    if c='!{ then count:=count+1 else
    if c='!} then count:=count-1;
    if count>0 then goto loop;
    myskip('!{);
    endchar:='!};
    mainloop();
  end;

put('iftex,'act,'texonly1);

symbolic procedure texonly2(u);
   begin scalar endchar,c,tok;
    integer count;
    count:=1;
  loop:
    c:= rdch();
    if c='!\ then
    <<tok:=mytoken(t);
      if tok='begin then count:=count+1 else
      if tok='end then count:=count-1;
    >>;
    if count>0 then goto loop;
    tok:=mytoken(t);
    if tok neq 'tex then
    <<printf("****** \begin{tex} ends with \end{%w}%n",tok);
      exitlisp();
    >>;
    if !*test then printf(" (texonly pop %w)",beginstack);
    beginstack := cdr beginstack;
  end;

put('tex,'context,'texonly2);

symbolic procedure infoonly(u);
   begin scalar endchar;
     mainloop();
   end;

put('info,'context,'infoonly);

symbolic procedure reporttopic u;
   if !*windows then
    <<prin2 u; prin2(topiccount!* := topiccount!*+1); prin2 " ">>;

%----------------- untilities ------------------------------

symbolic procedure substipq(new,old,l);
  % destructive substip based on eq test.
   if not pairp l then l else
   <<
     if car l eq old then car l := new;
     if cdr l eq old then cdr l := new;
     substipq(new,old,car l);
     substipq(new,old,cdr l);
     l>>;

end;


