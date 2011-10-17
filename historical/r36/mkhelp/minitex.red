module minitex;   % support of minimal tex syntax for
                  % reduce help file compilation.

 % author:  Herbert Melenk, ZIB Berlin

% input:    list of single characters in Latex subset syntax
%
% output:   list of rows, tagged by line number and max column 
%           length.
%
%           supported syntax elements:
%
%                ^  exponent
%                _  index
%                \frac{ ... }{ ... }
%
%                escape sequences \{ \} \_ \^ \\

fluid '(ESCAPE RAISE LOWER X0 Y0 CON);

fluid '(xlo xhi yhi ylo minitex_input minitex_page);

ESCAPE := '!\;
RAISE  := '!^;
LOWER  := '!_;

X0     := 2;
Y0     := 3;
CON    := 4;

symbolic procedure mintex_convert0 s;
   if null s then s else
   if null cdr s then s else
   if car s ='!\ and cadr s = '!\ then !$eol!$ . mintex_convert0 cddr s 
     else car s . mintex_convert0 cdr s;

symbolic procedure mintex_convert s; mintex_convert0 s;

symbolic procedure minitex(string);
  begin scalar q,w; integer r,c;
     minitex_page := for i:=-20:20 collect {i};
     minitex_input := mintex_convert string;
     q := make_chain(0,'hugo);
     if null q then return nil;
     minitex_collect q;
     for each l in minitex_page do
      if (l:=cdr l) then
      <<r:=r+1; if length(l)>c then c:=length(l);
        w:=l.w;
      >>;
     return r.c. reverse w;
  end;
     
symbolic procedure minitex_pop_char();
 if minitex_input then 
  begin scalar c;
      c := car minitex_input;
      minitex_input := cdr minitex_input;
      return c;
  end;

symbolic procedure minitex_skip(cc);
  begin scalar c;
    c := nil;
    while c neq cc do c:=minitex_pop_char();
  end;

symbolic procedure minitex_next_char();
  if minitex_input then car minitex_input;

symbolic procedure struct(type);
    {type,0,0,0};


symbolic procedure make_chain(font,term);
  begin integer indpos,xact,d,fh,
     lxlo, lxhi, lylo,lyhi,
     yindhi,yindlo;
     scalar c,cc,cell,new,end_code;
     
     fh:=1;  % font height

     end_code := 0;
     cell := struct('chain);
     
  loop:
     c := minitex_pop_char();
     cc := minitex_next_char();
     if(c = '!{ and null term) then
        <<term := '!}; goto loop>>;

     if (c = term or c = nil) then goto finish;
%    if (c = '!  ) then goto loop;
     if (c =  !$eol!$) then goto loop;

     
          % handle escaped single characters
     if(c = ESCAPE and
        (cc = '!  or cc = '!_ or cc = '!{ or cc = '!} or cc = '!$))
          then 
       <<
         indpos := -1;
          new := make_char(font,0,minitex_pop_char());
         goto after_syntax;
       >>;

     if(c = ESCAPE) then
       <<
         indpos := -1; 
         new := make_escape(font,term);
         if(new = -999) then goto loop; % /* ignore? */
       >>
       else
     if(c = LOWER or c = RAISE) then
       <<
         if(indpos > -1) then
         << xact:=indpos; yhi := yindhi; ylo = yindlo;>>
           else
         << indpos:=xact; yindhi:= yhi; yindlo := ylo;>>;

         new := make_chain(1,nil);
         if(c = RAISE) then
            d := - 1
            else
            d := + 1; 

         nth(new,Y0) := d;
         ylo := ylo+d; yhi := yhi+d;
       >>
      else
    if(c = '!{) then new := make_chain(font,'!})
      else
       << indpos := -1;
          new := make_char(font,0,c);
       >>;
  
   after_syntax:
     if not pairp new then <<end_code := new; goto finish>>;

     nth(cell,CON):=append(nth(cell,CON),{new});
     nth(new,X0) := xact;
     xact := xact + xhi;
     if(xact>lxhi) then lxhi := xact else xact:=lxhi;
     if(ylo<lylo) then lylo:=ylo;
     if(yhi>lyhi) then lyhi:=yhi;

     if(term) then goto loop;

 finish:
     ylo := lylo; yhi := lyhi;
     xlo := lxlo; xhi := lxhi;
     if pairp nth(cell,CON) then return(cell);
    end;

symbolic procedure make_char(font,cs,c);
  begin scalar cell;
    cell := struct('char);
    nth(cell,CON) := c;
    ylo := 0; yhi:=1; 
    xlo := 0; xhi:=1;
    return(cell);
  end;
 
symbolic procedure make_frac(font);
  begin scalar cell;
     scalar numr,denr,line;
     integer nxhi,dxhi,nyhi,dyhi,nylo,dylo;
     integer lxhi;
     integer yline,ydist;
     ydist := 1;

     cell := struct('chain);
     while minitex_input and car minitex_input neq '!{ do
           minitex_input:=cdr minitex_input;
     yline := 0;
     numr := make_chain(font,nil);
     nxhi := xhi; nyhi := yhi; nylo := ylo; 

      while minitex_input and car minitex_input neq '!{ do
           minitex_input:=cdr minitex_input;
     xhi := 0; xlo := 0; yhi := 0; ylo := 0;
     denr := make_chain(font,nil);
     dxhi := xhi; dyhi := yhi; dylo := ylo;

       % /* move the shorter one to the middle */
     if(dxhi > nxhi) then
     <<
        lxhi := dxhi;
        nth(numr,X0) := (dxhi - nxhi)/2;
     >>
       else
     <<
        lxhi := nxhi;
        nth(denr,X0) := (nxhi - dxhi)/2;
     >>;

     % /* make line */
     line := make_line(0,yline,lxhi,yline);

     % /* put num on top */
     nth(numr,Y0) := yline - ydist - (nyhi-1);

     % /* put denr below */
     nth(denr,Y0) := yline + ydist - dylo;

     % /* total frame */
     xlo := 0; xhi := lxhi;
     ylo := yline - ydist -(nyhi-nylo);
     yhi := yline + ydist +(dyhi-dylo);

     % /* make chain */
     nth(cell,CON) := {line,numr,denr};
     return cell;
  end;

symbolic procedure make_line(x,y,x1,y1);
 <<nth(cell,X0):=x;
   nth(cell,Y0):=y;
   nth(cell,CON):=x1;
   cell>> where cell=struct('line);

symbolic procedure make_multi(font);
  begin scalar cell,new; integer base;
    minitex_skip('!}); 
    minitex_skip('!});
    cell := struct('chain); nth(cell,CON) :=nil;
    while pairp (new :=make_chain(font,!$eol!$)) do
    << nth(cell,CON) := append(nth(cell,CON),{new});
       nth(new,Y0) := base;
       base:=base + (yhi-ylo) + 1;
    >>;
    yhi := base;
    return cell;
  end;
      
   
symbolic procedure make_end(font);
  <<minitex_skip('!}); -1>>;

%---------------------- dispatch -----------------------------------

fluid '(nullum);
nullum := struct('chain);
nth(nullum,CON):= nil;

symbolic procedure make_escape(font,term);
  if my_compare('(!f !r !a !c)) then make_frac(font)
    else 
  if my_compare('(!r !f !r !a !c)) then make_frac(font)
    else
  if my_compare('(!b !e !g !i !n { !m !u !l !t !i )) then make_multi(font)
    else
  if my_compare('(!e !n !d)) then make_end(font)
    else
  if my_compare('(!e !m)) then nullum
    else
  if my_compare('(!n !a !m !e)) then nullum
    else
  if my_compare('(!i !t)) then nullum
    else
     <<prin2 "######## \";
       for each c in minitex_input do prin2 c;
       rederr "Mini-TEX: function not implemented";
     >>;

symbolic procedure my_compare s;
  begin scalar i,c;
    i := minitex_input;
    while s and (c := minitex_pop_char()) and
      c=car s do s:= cdr s;
    if null s then return t;
    minitex_input := i;
    return nil;
  end;
     
%-------------- interprete structure: fill into page ---------------

symbolic procedure minitex_collect u;
        minitex_do(0,0,0,u);

symbolic procedure minitex_do(x,y,font,box);
   <<if null get(car box,'minitex) then
       <<print box; rederr "minitex: cannot expand object">>;
   apply(get(car box,'minitex),list(x,y,font,box));
   >>;

put('chain,'minitex,'minitex_chain);
 
symbolic procedure minitex_chain(x,y,font,box);
 << x:=x+nth(box,X0); y := y+nth(box,Y0);
   for each u in nth(box,CON) do minitex_do(x,y,font,u)
 >>;
  
put('char,'minitex,'minitex_char);

symbolic procedure minitex_char(x,y,font,box);
  begin 
    x:=x+nth(box,X0); y := y+nth(box,Y0);
    minitex_putchar(x,y,nth(box,CON));
  end;

put('line,'minitex,'minitex_line);

symbolic procedure minitex_line(x,y,font,box);
  begin
    x:=x+nth(box,X0); y := y+nth(box,Y0);
    for i:=x:x+nth(box,CON) do
       minitex_putchar(i,y,'!-);
  end;

symbolic procedure minitex_putchar(x,y,c);
  begin scalar r;
    x:=x+2;
    r:=assoc(y,minitex_page);
    while length r<x do r:=nconc(r,{'! });
    nth(r,x):=c;
  end;

end;

minitex '(a b c ^ { d e f } g);

minitex
  append(explode2 "\begin{multilineoutput}{1cm}" ,
        append({!$eol!$, 1, !$eol!$,2, !$eol!$ , 3, !$eol!$},
                 explode2 "\end{multilineoutput}"));
