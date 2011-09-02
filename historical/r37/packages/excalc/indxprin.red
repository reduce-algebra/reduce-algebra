module indxprin; % Functions for special print.

% Author: Eberhard Schruefer;

fluid '(!*nat !*nero !*revpri obrkp!* orig!* pline!* posn!* ycoord!*
	ymax!* ymin!* fancy!-pos!* fancy!-line!*);

global '(!*eraise spare!*);

symbolic procedure indvarprt u;
    if null !*nat then <<prin2!* car u;
                         prin2!* "(";
                         if cddr u then inprint('!*comma!*,0,cdr u)
                          else maprin cadr u;
                         prin2!* ")" >>
     else begin scalar y; integer l;
            l := flatsizec flatindxl u+length cdr u-1;
            if l>(linelength nil-spare!*)-posn!* then terpri!* t;
            %avoid breaking of an indexed variable over a line;
            y := ycoord!*;
            prin2!* car u;
            for each j on cdr u do
              <<ycoord!* :=  y + if atom car j then 1 else -1;
                if ycoord!*>ymax!* then ymax!* := ycoord!*;
                if ycoord!*<ymin!* then ymin!* := ycoord!*;
                prin2!* if atom car j then car j else cadar j;
                if cdr j then prin2!* " ">>;
            ycoord!* := y
          end;

symbolic procedure rembras u;
   if !*nat and (atom u or null get(car u,'infix))
       then <<prin2!* " ";
              maprin u>>
    else <<prin2!* "(";
           maprin u;
           prin2!* ")">>;

put('form!-with!-free!-indices,'tag,'form!-with!-free!-indices);

put('form!-with!-free!-indices,'prifn,'indxpri1);

put('form!-with!-free!-indices,'fancy!-setprifn,'indxpri);

flag('(form!-with!-free!-indices),'sprifn);

put('indvarprt,'expt,'inbrackets);

symbolic procedure xindvarprt(l,p);
  % Thanks to Herbert Melenk.
  fancy!-level
  ( if not(get('expt,'infix)>p) then
    fancy!-in!-brackets(
       {'xindvarprt,mkquote l,0}, '!(,'!))
    else
   begin scalar w,x,b,s;
     w:=fancy!-prefix!-operator car l;
     if w eq 'failed then return w;
     l := xindxlfix cdr l;
     while l and w neq 'failed do
     <<if b then fancy!-prin2!*("{}",0);
       b := t;
       if atom car l
          then (if s eq '!^
                  then x := car l . x
                else <<if s then
                   <<w := fancy!-print!-indexlist1(reversip x,s,nil);
                     fancy!-prin2!*("{}",0)>>;
                   x := {car l};
                   s := '!^>>)
        else (if s eq '!_
                  then x := cadar l . x
                else <<if s then
                   <<w := fancy!-print!-indexlist1(reversip x,s,nil);
                     fancy!-prin2!*("{}",0)>>;
                   x := {cadar l};
                   s := '!_>>);
       l := cdr l>>;
       w := fancy!-print!-indexlist1(reversip x,s,nil);
     return w
   end);

symbolic procedure xindxlfix u;
   if null u then nil
   else if atom car u then xindxfix car u . xindxlfix cdr u
   else {'minus,xindxfix cadar u} . xindxlfix cdr u;

symbolic procedure xindxfix x;
   % x: atom -> xindxfix:atom
   begin scalar xx;
   xx := explode x;
   while xx and car xx = '!! do xx := cdr xx;
   return if xx and numberp(xx := compress xx) then xx
          else x;
   end;

endmodule;

end;
