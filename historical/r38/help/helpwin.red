% helpwin.red
%
% interfacing reduce help file to Microsoft help compiler rtf structure
%
%  Author: Herbert Melenk, ZIB Berlin
%
%  November 1992
%

fluid '(outc newl par !*font !*newline !*windows);

!*windows:=t;
helvetica:= "f2";
courier:= "f4";

% The original version of this file had initoutput() as an empty
% procedure, but after the run it used shell commands to concatenate
% the following text at the start and end of the generated file. To
% reduce the amount of shell programming needed and keep as much as
% possible in REDUCE code the (fixed) header and trailer text is
% generated explicitly (albeit clumsily) here now.

symbolic procedure initoutput ();
  begin
    scalar o;
    o := wrs outfile!*;
    prin2t "{\rtf1\ansi \deff0{\fonttbl{\f0\froman Tms Rmn;}";
    prin2t "{\f1\fdecor Symbol;}";
    prin2t "{\f2\fswiss Helv;}";
    prin2t "{\f3\fmodern pica;}";
    prin2t "{\f4\fmodern Courier;}";
    prin2t "{\f5\fmodern elite;}";
    prin2t "{\f6\fmodern prestige;}";
    prin2t "{\f7\fmodern lettergothic;}";
    prin2t "{\f8\fmodern gothicPS;}";
    prin2t "{\f9\fmodern cubicPS;}";
    prin2t "{\f10\fmodern lineprinter;}";
    prin2t "{\f11\fswiss Helvetica;}";
    prin2t "{\f12\fmodern avantegarde;}";
    prin2t "{\f13\fmodern spartan;}";
    prin2t "{\f14\fmodern metro;}";
    prin2t "{\f15\fmodern presentation;}";
    prin2t "{\f16\fmodern APL;}";
    prin2t "{\f17\fmodern OCRA;}";
    prin2t "{\f18\fmodern OCRB;}";
    prin2t "{\f19\froman boldPS;}";
    prin2t "{\f20\froman emperorPS;}";
    prin2t "{\f21\froman madaleine;}";
    prin2t "{\f22\froman zapf humanist;}";
    prin2t "{\f23\froman classic;}";
    prin2t "{\f24\froman roman f;}";
    prin2t "{\f25\froman roman g;}";
    prin2t "{\f26\froman roman h;}";
    prin2t "{\f27\froman timesroman;}";
    prin2t "{\f28\froman century;}";
    prin2t "{\f29\froman palantino;}";
    prin2t "{\f30\froman souvenir;}";
    prin2t "{\f31\froman garamond;}";
    prin2t "{\f32\froman caledonia;}";
    prin2t "{\f33\froman bodini;}";
    prin2t "{\f34\froman university;}";
    prin2t "{\f35\fscript Script;}";
    prin2t "{\f36\fscript scriptPS;}";
    prin2t "{\f37\fscript script c;}";
    prin2t "{\f38\fscript script d;}";
    prin2t "{\f39\fscript commercial script;}";
    prin2t "{\f40\fscript park avenue;}";
    prin2t "{\f41\fscript coronet;}";
    prin2t "{\f42\fscript script h;}";
    prin2t "{\f43\fscript greek;}";
    prin2t "{\f44\froman kana;}";
    prin2t "{\f45\froman hebrew;}";
    prin2t "{\f46\froman roman s;}";
    prin2t "{\f47\froman russian;}";
    prin2t "{\f48\froman roman u;}";
    prin2t "{\f49\froman roman v;}";
    prin2t "{\f50\froman roman w;}";
    prin2t "{\f51\fdecor narrator;}";
    prin2t "{\f52\fdecor emphasis;}";
    prin2t "{\f53\fdecor zapf chancery;}";
    prin2t "{\f54\fdecor decor d;}";
    prin2t "{\f55\fdecor old english;}";
    prin2t "{\f56\fdecor decor f;}";
    prin2t "{\f57\fdecor decor g;}";
    prin2t "{\f58\fdecor cooper black;}";
    prin2t "{\f59\fnil linedraw;}";
    prin2t "{\f60\fnil math7;}";
    prin2t "{\f61\fnil math8;}";
    prin2t "{\f62\fnil bar3of9;}";
    prin2t "{\f63\fnil EAN;}";
    prin2t "{\f64\fnil pcline;}";
    prin2t "{\f65\fnil tech h;}";
    prin2t "{\f66\fswiss Helvetica-Narrow;}";
    prin2t "{\f67\fmodern Modern;}";
    prin2t "{\f68\froman Roman;}}";
    terpri();
    princ  "{\colortbl;\red0\green0\blue0;\red0\green0\blue255;";
    prin2t "\red0\green255\blue255;\red0\green255\blue0;";
    princ  "\red255\green0\blue255;\red255\green0\blue0;";
    prin2t "\red255\green255\blue0;\red255\green255\blue255;}";
    princ  "{\stylesheet{\s244 \fs16\up6 \sbasedon0\snext0";
    prin2t " footnote reference;}";
    prin2t "{\s245 \fs20 \sbasedon0\snext245 footnote text;}";
    prin2t "{\s246\li720 \i\fs20 ";
    prin2t "\sbasedon0\snext255 heading 9;}";
    prin2t "{\s247\li720 \i\fs20 \sbasedon0\snext255 heading 8;}";
    prin2t "{\s248\li720 \i\fs20 \sbasedon0\snext255 heading 7;}";
    prin2t "{\s249\li720 \fs20\ul \sbasedon0\snext255 heading 6;}";
    prin2t "{\s250\li720 \b\fs20 \sbasedon0\snext255 heading 5;}";
    prin2t "{\s251\li360 ";
    prin2t "\ul \sbasedon0\snext255 heading 4;}";
    prin2t "{\s252\li360 \b \sbasedon0\snext255 heading 3;}";
    prin2t "{\s253\sb120 \b\f2 \sbasedon0\snext0 heading 2;}";
    prin2t "{\s254\sb240 \b\f2\ul \sbasedon0\snext0 heading 1;}";
    prin2t "{\s255\li720 \fs20 \sbasedon0\snext255 Normal Indent;}";
    prin2t "{\fs20 ";
    prin2t "\snext0 Normal;}";
    prin2t "{\s2\fi-240\li480\sb80\tx480 \f11 \sbasedon0\snext2 nscba;}";
    prin2t "{\s3\fi-240\li240\sa20 \f11 \sbasedon0\snext3 j;}";
    prin2t "{\s4\li480\sa20 \f11 \sbasedon0\snext4 ij;}";
    prin2t "{\s5\sb80\sa20 \f11 \sbasedon0\snext5 btb;}";
    prin2t "{\s6\fi-240\li2400\sb20\sa20 \f11\fs20 ";
    prin2t "\sbasedon0\snext6 ctcb;}";
    prin2t "{\s7\fi-240\li480\sa40\tx480 \f11 \sbasedon0\snext7 ns;}";
    prin2t "{\s8\sa120 \f11\fs28 \sbasedon0\snext8 TT;}";
    prin2t "{\s9\fi-240\li2400\sa20 \f11 \sbasedon0\snext9 crtj;}";
    prin2t "{\s10\fi-240\li480\tx480 \f11 \sbasedon0\snext10 nsca;}";
    prin2t "{\s11\sa20 \f11 ";
    prin2t "\sbasedon0\snext11 bt;}";
    prin2t "{\s12\li240\sb120\sa40 \f11 \sbasedon0\snext12 Hf;}";
    prin2t "{\s13\li240\sb120\sa40 \f11 \sbasedon0\snext13 Hs;}";
    prin2t "{\s14\li480\sb120\sa40 \f11 \sbasedon0\snext14 RT;}";
    princ  "{\s15\fi-2160\li2160\sb240\sa80\tx2160 \f11";
    prin2t " \sbasedon0\snext15 c;}";
    prin2t "{";
    prin2t "\s16\li2160\sa20 \f11 \sbasedon0\snext16 ct;}";
    prin2t "{\s17\li240\sa20 \f11 \sbasedon0\snext17 it;}";
    prin2t "{\s18\li480 \f11\fs20 \sbasedon0\snext18 nsct;}";
    prin2t "{\s19\fi-160\li400\sb80\sa40 \f11 \sbasedon0\snext19 nscb;}";
    prin2t "{\s20\fi-2640\li2880\sb120\sa40\brdrb\brdrs \brdrbtw\brdrs ";
    prin2t "\tx2880 \f11 \sbasedon0\snext20 HC2;}";
    princ  "{\s21\fi-2640\li2880\sb120\sa20\tx2880 \f11";
    prin2t " \sbasedon0\snext21 C2;}";
    prin2t "{\s22\fi-240\li2400\sa20 \f11\fs20 \sbasedon0\snext22 ctc;}";
    prin2t "{\s23\li2160\sb160 \f11 \sbasedon0\snext23 crt;}";
    prin2t "{\s24\li480\sb20\sa40 \f11 ";
    prin2t "\sbasedon0\snext24 or;}}";
    terpri();
    princ  "{\info{\author Dan Davids}{\operator Dan Davids}";
    prin2t "{\creatim\yr2137\mo8\dy7}";
    princ  "{\revtim\yr1990\mo5\dy9\hr16\min54}{\version3}";
    prin2t "{\edmins3134}{\nofpages0}";
    prin2t "{\nofwords65536}{\nofchars69885}{\vern8310}}";
    terpri();
    prin2t "\ftnbj \sectd \linex576\endnhere ";
    prin2t "\pard\plain \sl240 \fs20 ";
    terpri();
    terpri();
    terpri();
    wrs o;
  end;

symbolic procedure endoutput ();
  begin
    scalar o;
    o := wrs outfile!*;
    prin2t "}";
    wrs o
  end;

symbolic procedure verbatim u; !*verbatim := u;

symbolic procedure newfont(f);
    if currentfont neq f then
     <<fontoff(); currentfont:=f; fonton()>>;

symbolic procedure fontoff();
  <<if !*font then channelprin2(outfile!*,"}"); 
    outc:=nil;
    !*font:=nil>>;

symbolic procedure fonton();
  <<if not !*font then 
    <<channelprintf(outfile!*,"{\%w ",currentfont); outc := nil>>;
    !*font:=t>>;

symbolic procedure myprin2 u;
  <<!*newline:=nil; channelprin2(outfile!*,u)>>;

symbolic procedure myprin2_protected u;
  <<if u memq '(!{ !}) then myprin2 "\";
    myprin2 u;
  >>;

fluid '(!*verbescape);

symbolic procedure emit_start_verbatim(); nil;
symbolic procedure emit_end_verbatim(); nil;
symbolic procedure verbprin2 u;
  if u = '!\ then <<myprin2 u ; !*verbescape :=t>>
    else
  if u=!$eol!$ then <<myprin2 " \par"; myterpri();!*verbescape := nil>>
      else
  if (u = '!&) then
   <<myprin2 "\tab "; !*verbescape:=par:=newl:=outc:=nil>>
     else
  if u memq '(!{ !}) then 
       <<if not !*verbescape then myprin2 "\"; myprin2 u;
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
  <<fonton();  
   if u=!$eol!$ and (!*verbatim or newl)
      then <<print_newline(); 
             outc:='!  ;
             if not !*verbatim then second_newline();
             newl:=nil; 
	     par:=t>>
     else 
   if (u = '!&) then
   <<myprin2 "\tab "; par:=newl:=outc:=nil>>
     else
   if (u = '!$) then
      newfont(if currentfont = helvetica then courier else helvetica)
     else
   if (u memq '(!{ !})) then <<myprin2 '!\; myprin2 u>> else
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
 <<verbprin2 !$eol!$;
   for each x in explode type do verbprin2 x;
   verbprin2 ":";
   verbprin2 !$eol!$; 
 >>;

%  --------  directory structure -------------------------

symbolic procedure base_new_dir(name); nil;

symbolic procedure emit_dir_new(); nil;

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
    myterpri(); myterpri();
    channelprin2(outfile!*,"\page");
    myterpri(); myterpri();
    outc:='!  ; par:=t;
  >>;

symbolic procedure set_tab();
    myprin2 "\pard \tx3420 ";

symbolic procedure release_tab();
   myprin2 "\pard \sl240 ";

symbolic procedure textoutl(l);
 % l is a list of characters to be printed.
 % special action for names: \ in front of _ suppressed because
 % of Microsoft HC logic (don't know why).
     if atom l then textout l else
      while l do
       <<if not(car l = '!\) or null cdr l or not(cadr l = '!_)
            then textout car l;
         l := cdr l>>;


symbolic procedure textout2(l);
     if atom l then myprin2 l else
     for each x in l do myprin2 
       if x='!  then '!_ else x;

symbolic procedure printem(s);
  % print italic
  begin
    myprin2 "{\i ";
    mapc(s,'myprin2);
    myprin2 "} ";
  end;

symbolic procedure printem(s);
  begin 
    fontoff(); 
    myprin2 "{\f3 ";
    mapc(s,'myprin2_protected);  
    myprin2 "} ";
  end;

symbolic procedure printref u;
  begin scalar r;
    r:= get_label u;
    if null r then return printem u;  
    fontoff();
    myterpri();
    myprin2 "{\f2\uldb ";
    mapc(u,'myprin2);
    myprin2  "}{\v\f2 ";
    mapc(r,'myprin2);
    myprin2  "}"; myprin2 " ";
    myterpri();
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
    myprin2 " K{\footnote \pard\plain \sl240 \fs20 K ";
    while keys do
    <<textoutl car keys; keys:= cdr keys;
      if keys then myprin2";">>;
    myprin2 "}";
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
  <<fonton();
    myterpri();
    myprin2 "#{\footnote \pard\plain \sl240 \fs20 # ";
    textout2 u;
    myprin2 "}";
    myterpri();
  >>;

symbolic procedure emit_node_title(u,dummy,type);
  <<fonton();
    myterpri();
    myprin2 "${\footnote \pard\plain \sl240 \fs20 $ ";
    textoutl u;
    myprin2 "}";
    myterpri();
  >>;

symbolic procedure emit_node_browse(u,n);
  <<fonton();
    myterpri();
    myprin2 "+{\footnote \pard\plain \sl240 \fs20 + ";
    textout u;
    textout ":";
    number4out n;
    myprin2 "}";
    myterpri();
  >>;
  

symbolic procedure print_bold u;
  <<fontoff();
    myprin2 "{\b\f2 ";
    mapc(u,'myprin2);
    myprin2 "}";
  >>;

symbolic procedure emit_dir_header();
   <<fontoff();
     myprin2 "{\f2 \par }\pard \sl240 {\f2 \par }";
     myterpri();
   >>;

symbolic procedure emit_dir_entry(name,lab);
  begin scalar alias;
     fontoff();
     myprin2 "{\f2 \tab}{\f2\uldb ";
     mapc(name,'myprin2);
     myprin2 "}";
     myterpri(); 
     myprin2 "{\v\f2 ";
     textout2 lab;
     myprin2 "}";
     if (alias:=assoc(lab,aliases)) then 
      <<myprin2 "  "; myprin2 cdr alias>>;
     print_newline();
  end;

symbolic procedure print_newline();
   <<if null !*newline then 
     <<fonton(); channelprin2(outfile!*,"\par "); channelterpri outfile!*>>;
     !*newline:=t
   >>;

symbolic procedure second_newline();
   <<!*newline :=nil; print_newline()>>;

symbolic procedure print_tab ();
   <<fonton();  myprin2 "\tab ">>;

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


