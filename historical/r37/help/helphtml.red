% helphtml.red
%
% interfacing reduce help file to HTML (world wide web)
%
%  Author: Herbert Melenk, ZIB Berlin
%
%  November 1992
%
%  PSL dependent

fluid '(outc newl par !*font !*newline !*html html_specials!* !*windows !*secondrun);

fluid '(node_file_name!* current_base_dir !*directory_open CURRENT_NODE_NUMBER!*);

!*HTML := t;
!*windows := t;
helvetica:= "R";
courier:= "TT";

!#if (member 'csl lispsystem!*)

fluid '(root dest);

symbolic procedure rootname();
   if boundp 'root and root then
      list!-to!-string explodec root
   else "r37";

symbolic procedure dest_directory();
   if boundp 'dest and dest then
      list!-to!-string explodec dest
   else "html";

!#else

symbolic procedure rootname();
    getenv "package";

symbolic procedure dest_directory();
   getenv "tdir";

!#endif

fluid '(node_file_labels filenumber indexfilename labels2nodes);

filenumber:=0;

symbolic procedure reset_html();
  <<
     indexfilename := make_html_file_name "index";
     filenumber := 0;
  >>;


symbolic procedure html_open(u);
    myprin2(compress ('!" . ( '!< . append(explode2 u, '(!> !")) )) );

symbolic procedure html_close(u);
  myprin2(compress ('!" . ( '!< . ( '!/ . append(explode2 u, '(!> !")) )) ));


symbolic procedure open_current_base_dir u;
 % myprin2 " open_current_base_dir "; myprin2 u;
 nil;

symbolic procedure close_current_base_dir ();
 % myprin2 " close_current_base_dir ";
 nil;

symbolic procedure make_html_file_name u;
  begin scalar base,num;
    base := reversip explode2 rootname();
    while length base > 4 do base :=  cdr base;
    base := compress ('!" . reversip ('!" . base));
!#if (member 'csl lispsystem!*)
    if u="main_index" then return bldmsg("%w.html",base)
    else if u="index" then num:="idx"
    else <<filenumber:=filenumber+1;
	 num := compress('!" . append(cdr explode2
			(10000+filenumber),'(!")));
	 >>;
    return bldmsg("%w_%w.html",base,num);
!#else
    if u="main_index" then num:="_dir"
    else if u="index" then num:="_idx"
    else <<filenumber:=filenumber+1;
	 num := compress('!" . append(cdr explode2
			(10000+filenumber),'(!")));
	 >>;
    return bldmsg("%w%w.html",base,num);
!#endif
  end;



symbolic procedure open_node_file u;
  begin scalar dir,name;
   dir:=if (dir:=dest_directory()) then bldmsg("%w/",dir) else "";
   name := node_file_name!* := make_html_file_name u;
   labels2nodes := (name . u) . labels2nodes;
   % non-unix and PSL: open with suffix "htm".
   if not member('unix,lispsystem!*) and member('psl, lispsystem!*) then
    name:= compress ('!" . reversip('!" . cdr reversip explode2 name));
   if outfile!* then close outfile!*;
   outfile!* := open(bldmsg("%w%w",dir,name), 'output);
   return outfile!*;
  end;

symbolic procedure close_node_file ();
if outfile!* then << close outfile!*; outfile!* := nil;
			  node_file_name!* := nil;
  >>;

symbolic procedure node_file_name();  node_file_name!*;

symbolic procedure initoutput (); nil;

symbolic procedure endoutput(); nil;

symbolic procedure verbatim u;
 !*verbatim := u;

symbolic procedure newfont(f);
    if currentfont neq f then
     <<fontoff(); currentfont:=f; fonton()>>;

symbolic procedure fontoff();
  <<% if !*font then channelprin2(outfile!*,"}");
    outc:=nil;
    !*font:=nil>>;

symbolic procedure fonton();
  <<if not !*font then
    <<% channelprintf(outfile!*,"{\%w ",currentfont); outc := nil
     >>;
    !*font:=t>>;

symbolic procedure myprin2 u;
  <<!*newline:=nil; channelprin2(outfile!*,u)>>;

deflist( '((!<  "&lt;")
	   (!>  "&gt;")
	   (!"   "&quot;")
	   (!&   "&amp;")),
	 'HTML_Symbol_Name);

html_specials!* := '(!< !> !" !&);

symbolic procedure myprin2_protected u;
  <<if u memq html_specials!* then myprin2 get(u, 'HTML_Symbol_Name)
      else myprin2 u;
    u
  >>;

fluid '(!*verbescape);

symbolic procedure emit_start_verbatim();
   <<html_open "P"; html_open "PRE"; html_open "TT">>;

symbolic procedure emit_end_verbatim();
    <<html_close "TT"; html_close "PRE"; html_open "P">> ;

symbolic procedure verbprin2 u;
  if u = '!\ then << !*verbescape :=t>>
    else
  if u=!$eol!$ then << myterpri();!*verbescape := nil>>
      else
  if (u = '!&) then
   <<myprin2 " _ _ _ "; !*verbescape:=par:=newl:=outc:=nil>>
     else
  if u memq html_specials!* then
       <<if not !*verbescape then myprin2_protected u else myprin2 u;
	  !*verbescape := nil>>
     else
  <<myprin2 u; !*verbescape := nil>>;

symbolic procedure myterpri();
   channelterpri outfile!*;

symbolic procedure number4out n;
  % print number with 4 digits.
   << if n<10 then textout "0";
      if n<100 then textout "0";
      if n<1000 then textout "0";
      textout n>>;

% par = t:   paragraph has been terminated - no new data so far
% newl = t:  last character has been an EOL

symbolic procedure textout(u);
  if par and (u=!$eol!$ or u='!  ) then nil else
  if stringp u then mapc(explode2 u, 'textout) else
  <<fonton();
   if u=!$eol!$ and (!*verbatim or newl)
      then <<print_newline();
	     outc:='!  ;
	     if not !*verbatim then second_newline();
	     newl:=nil;
	     par:=t
	   >>
     else
   if (u = '!&) then
   <<myprin2 " _ _ _ "; par:=newl:=outc:=nil>>
     else
   if (u = '!$) then
      newfont(if currentfont = helvetica then courier else helvetica)
     else
   if (u memq html_specials!*) then <<myprin2_protected u>> else
   if (u neq '! ) or (outc neq '! ) or !*verbatim
   then
   <<if u=!$eol!$  and outc neq '!   then myprin2 '!   ;
     myprin2(u); outc := u;
     if u=!$eol!$ then newl:=t else
     if u neq '!  then newl:=nil;
     par:=nil;
   >>;
  >>;

%  -------- paragraph heading ---------------------------

symbolic procedure par_heading(type);
 <<myprin2 " <P> <H3> ";
   verbprin2 !$eol!$;
   for each x in explode type do verbprin2 x;
   verbprin2 ": </H3>";
   verbprin2 !$eol!$;
 >>;

%  --------  directory structure -------------------------

symbolic procedure base_new_dir(name);
  <<%myprin2 "base_new_dir name="; myprin2 name;
    close_current_base_dir();
    open_current_base_dir name;
    current_base_dir := name>>;

symbolic procedure emit_dir_new();
  <<%print current_base_dir;
    %open_node_file current_base_dir
  nil>>;

symbolic procedure emit_dir_key u;
      emit_node_key u;

symbolic procedure emit_dir_separator();
      emit_node_separator();

symbolic procedure emit_dir_label u;
      emit_node_label u;

symbolic procedure emit_dir_title u;
      emit_node_title(u,nil,'section);

symbolic procedure emit_dir_browse(u,n);
      emit_node_browse(u,n);

%  ----  node structure

symbolic procedure emit_node_separator();
  <<fonton();
    if !*directory_open then <<html_close "MENU" ;
			       !*directory_open := nil>>;
    %myterpri(); myterpri();
    %channelprin2(outfile!*,"emit_node_separator");
    %myterpri(); myterpri();
    outc:='!  ; par:=t;

    close_node_file();
  >>;

symbolic procedure set_tab();  nil;
%    myprin2 "set_tab ";

symbolic procedure release_tab();  nil;
%   myprin2 "release_tab ";

symbolic procedure textout_name(l);
 % l is a list of characters to be printed.
 % special action for names: \ in front of _ suppressed because
 % of Microsoft HC logic (don't know why).
     if atom l then textout l else
      while l do
       <<if not(car l = '!\) or null cdr l or not(cadr l = '!_)
	    then textout car l;
	 l := cdr l>>;


symbolic procedure textout2(l);
     if l then
     if atom l then myprin2 l else
     for each x in l do myprin2
       if x='!  then '!_ else x;

symbolic procedure printem(s);
  % print italic
  begin
    html_open "em";
    mapc(s,'myprin2);
    html_close "em";
  end;

symbolic procedure printem(s);
  begin
    fontoff();
    html_open "em";
    mapc(s,'myprin2_protected);
    html_close "em";
  end;

symbolic procedure printref u;
  begin scalar r,s;
   % print ( ">>>" . u);
    r:= get_label u;
%    s := assoc (u,node_file_labels);
    s := assoc (r,node_file_labels);
    if null s then s := assoc(append(r, '(!_ !s !w !i !t !c !h)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !c !o !m !m !a !n !d)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !v !a !r !i !a !b !l !e)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !o !p !e !r !a !t !o !r)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !d !e !c !l !a !r !a !t !i !o !n)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !c !o !n !s !t !a !n !t)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !t !y !p !e)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !c !o !n !c !e !p !t)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !p !a !c !k !a !g !e)), node_file_labels);
    if null s then s := assoc(append(r, '(!_ !i !n !t !r !o !d !u !c !t !i !o !n)), node_file_labels);
    if s then s := cdr s;
    if null r then return printem u;
    fontoff();
    myterpri();
if null s then <<
   wrs nil;
   printc "*** missing cross-reference ***";
   princ "u = "; print u;
   princ "r = "; print r;
   princ "s = "; print s;
   princ "assoc(u,..) = ", print assoc(u, node_file_labels);
   printc "node_file_labels = ";
   for each w in node_file_labels do <<
      princ "  "; prin car w; ttab 30; print cdr w >>;
   printc "*** stopping ***";
   stop 0 >>;
    myprin2 "<A HREF="; myprin2 s;
    %myprin2 "#"; mapc(r, 'myprin2);
    myprin2 ">";
    mapc(u,'myprin2); html_close "A";
  end;

symbolic procedure printnameref u;
   printref u;

fluid '(key_database);

symbolic procedure emit_node_keys u;
  begin scalar keys;
    keys := assoc(u,key_database);
    if null keys then return;
    keys := cdr keys;
    fonton();
    myterpri();
    while keys do
    << %myprin2 "<A NAME="; textout_name car keys;
      % number4out    current_node_number!* ; myprin2 ">";
      % textout_name car keys;
      % myprin2 " . </A>";
       node_file_labels := ( car keys . node_file_name!*) . node_file_labels;
      % print ( "<=>" . car keys);
       keys:= cdr keys;
      %if keys then myprin2";"
    >>;
    myterpri();
  end;

symbolic procedure emit_node_key u;
       emit_hidden_node_key u;

symbolic procedure emit_hidden_node_key u;
  if current_node!* then
  begin scalar q;
   q:= assoc(current_node!*,key_database);
   if null q then
      key_database := (current_node!* . {u}).key_database
   else
      if not member(u,cdr q) then cdr q:=u.cdr q;
  end;

symbolic procedure emit_node_label u;
  <<open_node_file u;
    fonton();
    myterpri();
    myprin2 "<A NAME=";
    textout_name u;
    myprin2 ">";
    myterpri();
    node_file_labels := ( u . node_file_name!* ) . node_file_labels;
  >>;

symbolic procedure emit_node_title(u,dummy,type);
  <<fonton();
    myterpri();
    html_open "TITLE";
    textout_name u;
    html_close "TITLE";
    html_close "A";    % from emit_node_label
    myterpri();
    channelprintf(outfile!*,"<b><a href=%w>INDEX</a></b><p><p>%n",indexfilename);
  >>;

symbolic procedure emit_node_browse(u,n);
  <<fonton();
  %  myterpri();
  %  myprin2 "<A NAME=";
  %  textout2 u;
  %  number4out n;
    current_node_number!* := n;
  %  myprin2 "> . </A>";
  %  myterpri();
    node_file_labels := ( u . node_file_name!* ) . node_file_labels;

  >>;


symbolic procedure print_bold u;
  <<fontoff();
    html_open "B";
    mapc(u,'myprin2);
    html_close "B";
  >>;

symbolic procedure emit_dir_header();
   <<
     fontoff();
     html_open "MENU";
    !*directory_open := t;
     myterpri();
   >>;

symbolic procedure emit_dir_entry(name,lab);
  begin scalar alias, s;
     s:= assoc(lab,node_file_labels); if s then s := cdr s;
     fontoff();
if null s then error(0, "emit_dir_entry" . name . lab);
     html_open "LI"; myprin2 "<A HREF=";
     textout2 s; % myprin2 ".html";
     %     myprin2 "#";     textout2 lab;
     myprin2 ">";
     mapc(name,'myprin2);
     html_close "A";
%     myterpri();
%     myprin2 "{\v\f2 ";
     if (alias:=assoc(lab,aliases)) then
      <<myprin2 "alias=  "; myprin2 cdr alias>>;
%     myprin2 " ENDemit_dir_entry";
     print_newline();
  end;

symbolic procedure print_newline();
   <<if null !*newline then
     <<fonton(); channelprin2(outfile!*,"<P>"); channelterpri outfile!*>>;
     !*newline:=t
   >>;


symbolic procedure second_newline();
   <<!*newline :=nil; print_newline()>>;

symbolic procedure print_tab ();
   <<fonton();  myprin2 " _ _ _ ">>;

%------------------- HTML index file --------------------------------


symbolic procedure html_indexfile();
  begin scalar u,v,q,r,s,rr,!*lower;
   prin2t "..... compiling html index file";
   s := for each q in node_file_labels join
     if pairp car q then  {sort_term car q . q};
   s := sort(s,'html_indexfile_sort);
    % remove trivial entries
   r:=s;
  while r do
  <<u:=car r; r:=cdr r;
    if car u member
   '((c o m m a n d)
     (c o n c e p t)
     (c o n s t a n t)
     (d e c l a r a t i o n)
     (i n t r o d u c t i o n)
     (o p e r a t o r)
     (p a c k a g e)
     (s w i t c h)
     (v a r i a b l e)
    )
      then s:=deletip(u,s);
  >>;
    % remove duplicates
  r:=s;
  while r and cdr r do
  <<u:=car r; rr:=r:=cdr r;
    while rr and html_indexfile_subsetp(car u,car (v:=car rr)) do
    <<if cddr u = cddr v then s:=deletip(u,s); rr:=cdr rr>>;
  >>;

  open_node_file "index";
  channelprintf(outfile!*, "<title>%w search index</title>%n",rootname());
% channelprintf(outfile!*, "<dl compact><isindex>%n");
  channelprintf(outfile!*, "<dl compact>%n");
  channelprintf(outfile!*, "<menu>%n");
  for each x in s do
  <<channelprin2(outfile!*, "<dt>");
    for each c in cadr x do
      if c='!_ then  channelprin2(outfile!*," ") else
      if not(c='!\) then channelprin2(outfile!*,c);
    channelprintf(outfile!*, ": <a href=%w>",cddr x);
    q := cdr assoc(cddr x,labels2nodes);
    for each c in q do
      if c='!_ then  channelprin2(outfile!*," ") else
      if not(c='!\) then channelprin2(outfile!*,c);
    channelprin2t(outfile!*, "</a>");
  >>;
  channelprintf(outfile!*, "</menu>%n");
  close outfile!*;
  outfile!*:=nil;
  end;

symbolic procedure sort_term u;
  for each c in raisestring u join
    if liter c or digit c then {c};

symbolic procedure html_indexfile_sort(u,v);
   html_indexfile_sort1(car u,car v);

symbolic procedure html_indexfile_sort1(u,v);
  if null u then t else
  if null v then nil else
  if car u = car v then html_indexfile_sort1(cdr u,cdr v) else
  id2int car u < id2int car v;

symbolic procedure html_indexfile_subsetp(a,b);
  null a or
   b and car a = car b and html_indexfile_subsetp(cdr a,cdr b);

%------------------- LISP index file --------------------------------


symbolic procedure LISP_indexfile();
  begin scalar u,v,q,r,s,rr,!*lower,pack;
   prin2t "..... compiling independent index file";
   pack := rootname();
   s := for each q in node_file_labels join
     if pairp car q then  {sort_term car q . q};
   s := sort(s,'html_indexfile_sort);
    % remove trivial entries
   r:=s;
  while r do
  <<u:=car r; r:=cdr r;
    if car u member
   '((c o m m a n d)
     (c o n c e p t)
     (c o n s t a n t)
     (d e c l a r a t i o n)
     (i n t r o d u c t i o n)
     (o p e r a t o r)
     (p a c k a g e)
     (s w i t c h)
     (v a r i a b l e)
    )
      then s:=deletip(u,s);
  >>;
    % remove duplicates
  r:=s;
  while r and cdr r do
  <<u:=car r; rr:=r:=cdr r;
    while rr and html_indexfile_subsetp(car u,car (v:=car rr)) do
    <<if cddr u = cddr v then s:=deletip(u,s); rr:=cdr rr>>;
  >>;

  outfile!*:= open(bldmsg("%w.hdx",pack),'output);
  channelprintf(outfile!*, "%w generated from reference manual >%w< %n",'!%,pack);
  channelprintf(outfile!*, "%w (node text description status details) %n",'!%,pack);
  for each x in s do
  <<channelprin2(outfile!*, "(");
    q := cdr assoc(cddr x,labels2nodes);
    for each c in q do
	   if not(c='!\) then
	     <<c:=id2int c;
	       if c> 64 and c<91 then c:=c+32;
	       channelprin2(outfile!*,int2id c)>>;
    channelprin2(outfile!*,'! );
    channelprin2(outfile!*,'!");
    for each c in cadr x do
      if not(c='!\) then channelprin2(outfile!*,c);
    channelprin2(outfile!*,'!");
    channelprin2(outfile!*,'! );
    channelprintf(outfile!*," %w help nil)%n", pack);
  >>;
  close outfile!*;
  outfile!*:=nil;
  end;

%------------------- printstruct -------------------------------

symbolic procedure printstruct();
   <<terpri(); printstruct1(car record,1)>>;

symbolic procedure printstruct1(r,n);
  <<for i:=1:n do prin2 "  ";
    mapc(name r,'prin2);
    terpri();
    for each x in reverse seq r do
	printstruct1(nil . x,n+1);
  >>;

end;




