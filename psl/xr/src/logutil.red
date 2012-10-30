module logutil; % utilities for REDUCE log files.

% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

%    log_latex(<infile>,<outfile>);
%
%      Transform a REDUCE log file <infile> from XR or Windows with 
%      output in type setting style to a LATEX source file <outfile>.

fluid '(texstate!* char!-texon!* char!-texoff!* char!-null!*
        old!-line!* );

char!-texon!*  := int2id 16$
char!-texoff!* := int2id 17$
char!-null!*   := int2id 0$

symbolic procedure log_latex(din,dout);
  begin scalar fin,fout,oldfin,oldfout,w;
   fin:=open(din,'input); fout:=open(dout,'output);
   oldfin:=rds fin; oldfout:=wrs fout;
   w:=errorset('(log2latex1),t,t) where !*lower=nil,!*raise=nil;
   wrs oldfout; rds oldfin;
   close fout; close fin;
 end;

symbolic operator log_latex;

fluid '(l2xprologue!* l2xepilogue!*);

l2xprologue!* :='(
"\documentstyle{article}"
"\newcommand{\step}{\hspace*{.5cm}}"
"\setlength{\parindent}{0cm}"
"\sloppy"
"\begin{document}"
);

l2xepilogue!* :='(
"\end{document}"
);

symbolic procedure log2latex1();
  begin scalar texstate!*,l,w,c;
    integer n;
    old!-line!*:=nil;
    for each l in l2xprologue!* do prin2t l;
   a:
    l:=read!-line();
    if car l = !$eof!$ then goto done;
    if car l = 'tex then
    <<
      l:=transform2tex cdr l;
      mathon();
      c:=nil; n:=0;
      for each x in l do
      <<n:=n+1; 
        if n>60 and x='!\ and c neq '!\ then <<terpri(); n:=0>>;
        prin2 x; c:=x;
      >>;
      mathoff();
    >>
    else
    <<texton();
      for each x in cdr l do prin2 x; 
      terpri();
    >>;
    goto a;
  done:
   if texstate!*=0 then textoff() else 
   if texstate!*=1 then mathoff();
   for each l in l2xepilogue!* do prin2t l;
  end;
      
symbolic procedure transform2tex ll;
 begin scalar w,l;  
 % l2xspace!*:=0;
  l := ll;
  while l do
  <<
    if (w:=l2xmatch(l,'(!\ !>))) then l2xsymbtab(l,w) else
    if (w:=l2xmatch(l,'(!\ !s !y !m !b !{))) then l2xsymb(l,w) else
    if (w:=l2xmatch(l,'(!\  s  y  m  b !{))) then l2xsymb(l,w);
    l:=cdr l;
  >>;
  return ll;
 end;

symbolic procedure l2xmatch(s,p);
  if null p then s else
  if null s then nil else
  if car s eq car p then l2xmatch(cdr s,cdr p) else nil;

symbolic procedure l2xsymbtab(l,w);
  <<w:=append(explode2 "\step ",cddr l);
    car l:=car w; cdr l:=cdr w;
    l>>;

fluid '(tex!-symbols!*);

tex!-symbols!* := 
'(( 182 . "\partial")
  ( 198 . "\emptyset")
  ( 216 . "\neg")
  ( 163 . "\leq")
  ( 179 . "\geq")
  ( 185 . "\not=")
  ( 199 . "\bigcap")
  ( 200 . "\bigcup")
  ( 206 . "\in")
  ( 217 . "\bigwedge")
  ( 218 . "\bigvee")
  ( 239 . "\vert")
  ( 124 . "\vert")
  ( 222 . "\Rightarrow")
  (  34 . "\forall")
  (  71 . "\Gamma")
  ( 226 . "\dag")     % shoud have been (R)
  ( 227 . "\copyright")

  (  32 . "\quad")
);


symbolic procedure l2xsymb(l1,l2);
  % convert \symb{nnn} to tex symbol.
 begin scalar w;integer n;
  while digit car l2 do
  <<n:=n*10 + id2int car l2 - id2int '!0;
    l2 := cdr l2
  >>;
  w := assoc(n,tex!-symbols!*);
  if null w then rederr {"symbol not konw:",n};
  l2 := append (explode2 cdr w,'!  .cdr l2);
  car l1 := car l2; cdr l1 := cdr l2;
 end;
 

symbolic procedure read!-line();
  begin scalar w,l;
   l:=read!-line0();
   if car l=!$eof!$ then return l;
   if car l = char!-texon!* then
    return
     begin 
     l:=cdr l;
    a:
      w:=member(char!-texoff!*,l) or member(!$eof!$,l);
      if w then 
       <<old!-line!*:=cdr w; car w:= '!  ; 
         cdr w:=nil; return 'tex . l>>;
      l:=append(l,read!-line0());
      go to a;
     end;
   w:=member(char!-texon!*,l);
   if w then
    <<old!-line!* := car w . cdr w; car w:= '!   >>;
   return nil.l;
  end;

symbolic procedure read!-line0();
  begin scalar w,c;
    if old!-line!* then
     <<w:=old!-line!*; old!-line!*:=nil; return w>>;
    while not ((c:=readch())=!$eol!$) and not(c=!$eof!$) do 
       if id2int c > 3 then w:=c.w;  % for ctrlA, ctrl B
    if c=!$eof!$ then return {c};
    w:=reversip w;
    return w or read!-line0();
  end;   
      
symbolic procedure mathon();
   << textoff(); prin2 "$";  texstate!* :=1; >>;

symbolic procedure mathoff();
   << if texstate!*=1 then prin2t "$\\"; texstate!* :=nil>>;   

symbolic procedure texton();
   if not(texstate!*=0) then
   <<mathoff(); prin2t "\begin{verbatim}"; texstate!* := 0>>;

symbolic procedure textoff();
   if texstate!*=0 then 
   <<prin2t "\end{verbatim}"; texstate!*:=nil>>;

endmodule;

end;


