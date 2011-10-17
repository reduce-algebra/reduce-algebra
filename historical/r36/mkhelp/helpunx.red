% helpunx.red
%
% interfacing reduce help file to unix GNU texinfo structure
%
%  Author: Herbert Melenk, ZIB Berlin
%
%  November 1992
%
%  PSL dependent

%-------------------- output ------------------------------------


fluid '(outc newl par !*font !*newline nodechain
	 prevnode upnodes !*terpri);


symbolic procedure initoutput();
    <<
     upnodes := {"Top"};
     if null nodechain then
       nodechain:={{"dummy 2",nil,"dummy 1"}};
     prevnode :={nil};
     channellinelength(outfile!*,200);
     myprin2 bldmsg("@setfilename %w.info",package);
     myterpri();
    >>;

symbolic procedure endoutput();
   nil;

symbolic procedure verbatim(u);
   <<myterpri();
     if not u then toggle_line();
     myprin2 if u then "@example" else "@end example";
     myterpri();
     if u then toggle_line();
     if not u then
     <<myprin2t "@*"; myprin2t "@noindent"; >>;
     !*verbatim:=u;
   >>;

symbolic procedure toggle_line();
   <<myterpri!*(); for i:=1:60 do myprin2 "_";  myterpri();>>;

symbolic procedure newfont(f);
    if currentfont neq f then
     <<fontoff(); currentfont:=f; fonton()>>;

symbolic procedure fontoff();
  <<%%% if !*font then channelprin2(outfile!*,"}");
    outc:=nil;
    !*font:=nil>>;

symbolic procedure fonton();
  <<if not !*font then
    <<%%% channelprintf(outfile!*,"{\%w ",currentfont);
      outc := nil>>;
    !*font:=t>>;

symbolic procedure myprin2 u;
  if not(u eq '!\) then
  <<!*newline:=nil; !*terpri :=nil; channelprin2(outfile!*,u)>>;


fluid '(!*verbescape);

symbolic procedure emit_start_verbatim();
   << myprin2 "@example"; myterpri();toggle_line()>>;

symbolic procedure emit_end_verbatim();
   << toggle_line();myterpri();myprin2 "@end example"; myterpri();>>;

symbolic procedure verbprin2 u; (textout u) where !*verbatim=t;

symbolic procedure verbprin2 u;
  if u = '!\ then <<myprin2 '!@ ; !*verbescape :=t>>
    else
  if u=!$eol!$ then <<myprin2 " "; myterpri();!*verbescape := nil>>
      else
  if (u = '!&) then
   <<myprin2 " "; !*verbescape:=par:=newl:=outc:=nil>>
     else
  if u memq '(!{ !}) then
       <<if not !*verbescape then myprin2 "@"; myprin2 u;
	  !*verbescape := nil>>
     else
  <<myprin2 u; !*verbescape := nil>>;

symbolic procedure myprin2t u;
  <<!*newline:=t; channelprin2(outfile!*,u); channelterpri outfile!*;>>;

symbolic procedure myterpri!*();
   !*terpri or myterpri();

symbolic procedure myterpri();
   <<channelterpri outfile!*; !*terpri := t>>;

symbolic procedure textout(u);
  if par and (u=!$eol!$ or u='!  ) then nil else
  if u='!{ or u='!} then nil else
  <<fonton();
   if u=!$eol!$ and (!*verbatim or newl)
      then <<myprin2 u;  %%% print_newline();
	     outc:='!  ;newl:=nil; par:=t>>
     else
   if (u = '!&) then
   <<myprin2 " "; par:=newl:=outc:=nil>>
     else
   if (u = '!$) then
      newfont(if currentfont = helvetica then courier else helvetica)
     else
   if (u neq '! ) or (outc neq '! ) or !*verbatim
   then
   <<myprin2(u); outc := u;
     if u=!$eol!$ then newl:=t else
     if u neq '!  then newl:=nil;
     par:=nil;
   >>;
  >>;

symbolic procedure textoutl(l);
    if null l then nil else
     if atom l then textout l else
	 for each x in l do textout x;

symbolic procedure textout2(l);
     if atom l then myprin2 l else
     for each x in l do myprin2
       if x='!  then '!_ else x;

%  -------- paragraph heading ---------------------------

symbolic procedure par_heading(type);
 <<verbprin2 !$eol!$;
   verbprin2 "@noindent"; verbprin2 !$eol!$;
   for each x in explode type do verbprin2 x;
   verbprin2 ":";
   verbprin2 !$eol!$; verbprin2 !$eol!$;
 >>;
%  --------  directory structure -------------------------

fluid '(!*in!-directory actdir);

symbolic procedure base_new_dir name;
   % initial call for new section
      <<% name := mycompress name;
	prevnode := nil . prevnode;
	upnodes:= name.upnodes;
      >>;

symbolic procedure emit_dir_new();
   % closing a section.
   << if upnodes then
       <<actdir := car upnodes; upnodes:=cdr upnodes>>;
       if prevnode then prevnode:=cdr prevnode;
   >>;

symbolic procedure emit_dir_key u; nil;

symbolic procedure emit_dir_entry(name,lab);
   begin scalar n,alias;
      if not !*in!-directory then
       <<myterpri(); myprin2 "@menu"; myterpri();!*in!-directory:=t;>>;
      myprin2 "* ";
      textoutl if atom lab then name else lab;
      myprin2 "::";
      n:=length (if atom lab then name else lab)+2;
      for i:=n:25 do myprin2 " ";
      if (alias:=assoc(lab,aliases)) then
	 <<myprin2 "  "; textoutl cdr alias; myprin2 "  ";>>;
   %%% Klappaltar   textoutl name;
      if find_type(name) then textoutl find_type(name);
      myterpri();
    end;

fluid '(typen);

typen := for each x in
  '("package" "operator" "type" "variable" "concept"
    "switch" "command" "introduction" "declaration")
   collect explode2 x;

symbolic procedure find_type(name);
   <<while memq('!  ,name) do name:=cdr name;
     if name member typen then name else nil
   >>;

symbolic procedure emit_dir_header(); nil;

symbolic procedure emit_dir_separator();
   <<myprin2 "@end menu";
     myterpri(); myterpri();
     !*in!-directory:=nil;
     prevnode:=actdir . cdr prevnode;
   >>;

symbolic procedure emit_dir_label u; nil;

symbolic procedure emit_dir_title u;
    % emit_node_title (nil,u,'section);
      emit_node_title (u,u,'section);

symbolic procedure emit_dir_browse(u,n); nil;

%  ----  node structure

symbolic procedure emit_node_separator();
  <<
    myterpri(); myterpri();
    outc:='!  ; par:=t;
  >>;

symbolic procedure printem(s);
  begin
    fontoff();
    myprin2 "@titlefont{";
    mapc(s,'myprin2);
    myprin2 "}";
  end;

symbolic procedure printem(s);
   <<mapc(raisestring s,'myprin2);
     myprin2 '!  ;
   >>;

symbolic procedure printref u;
 begin scalar l;
    l := get_label u;
    if l then
    <<myprin2 "[@pxref{";
      mapc(l,'myprin2);
      myprin2 "}] ";
    >>
      else
    <<mapc(u,'myprin2); myprin2 '!   >>;
  end;

symbolic procedure printnameref u;
   <<printref u>>;

symbolic procedure emit_node_keys u; nil;

symbolic procedure emit_node_key u;
  if !*verbatim then textoutl u else
   <<myprin2 "@cindex{";
     textoutl u;
     myprin2t "}";
    %  textoutl u; das ist hier schon ausgegeben
   >>;

symbolic procedure emit_hidden_node_key u;
  if !*verbatim then textoutl u else
   <<myprin2 "@cindex{";
      textoutl u;
     myprin2t "}";
   >>;

symbolic procedure emit_node_label u; nil;

%symbolic procedure emit_node_title (dummy,u,type);
symbolic procedure emit_node_title (u,dummy,type);
  begin scalar slot,prev,next,up,cu,z;
    cu := u; % cu:=mycompress u;
    prev := if prevnode then car prevnode;
    slot := assoc(cu,nodechain);
    if null slot then
    <<slot := {cu,nil,prev};
      nodechain :=slot.nodechain;
    >>;
    if prevnode and car prevnode
      and (z:=assoc(car prevnode,nodechain)) then
    <<z:=cdr z; car z :=cu>>;
    up := if upnodes then car upnodes;
    fonton();
    myterpri();
    myprin2 "@node ";
    textoutl u; myprin2 ", ";
    textoutl cadr slot;myprin2 ", ";
    textoutl caddr slot;myprin2 ", ";
    textoutl (up or "(dir)");
    myterpri();
    if null up then <<myprin2 "@top"; myterpri()>>;
    if null prevnode then prevnode := {cu}
      else car prevnode := cu;
  end;

symbolic procedure emit_node_browse(u,n);
   nil;

symbolic procedure set_tab(); nil;
symbolic procedure release_tab(); nil;

symbolic procedure print_bold u;
  <<fontoff();
    myprin2 "@titlefont{";
    mapc(u,'myprin2);
    myprin2 "}";
  >>;

symbolic procedure print_newline();
   <<if null !*newline then
     <<channelterpri outfile!*>>;
     !*newline:=t
   >>;

symbolic procedure second_newline();
   <<!*newline :=nil; print_newline()>>;

symbolic procedure print_tab (); textout "     ";

%--------------------------------------------------------------
symbolic procedure tue();
  % job "c:\herbert\whelp\redindex.tex"$
    job("redindex.tex","hugo.x");

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


