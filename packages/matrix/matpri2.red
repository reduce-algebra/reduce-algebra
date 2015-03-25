module matpri; % matrix prettyprinter

% Author: Takeyuki Takahashi, Toyohashi University of Technology.

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


global '(!&count!& !&m!-p!-flag!& !&name !&namearray);

% General functions.

symbolic procedure terpri!* u;
   begin integer n;
      if !&m!-p!-flag!& then <<!&count!& := t; go to c>>;
      if !*fort then return fterpri u
       else if not pline!* or not !*nat then go to b;
      n := ymax!*;
      pline!* := reverse pline!*;
    a:
      scprint(pline!*,n);
      terpri();
      if n=ymin!* then go to b;
      n := n - 1;
      go to a;
    b:
      if u then terpri();
    c:
      pline!* := nil;
      posn!* := orig!*;
      ycoord!* := ymax!* := ymin!* := 0
   end;

symbolic procedure plus!-l u; plus!-l1(0,u);

symbolic procedure plus!-l1(n,u);
   if null u then n else <<n := n + car u; plus!-l1(n,cdr u)>>;

symbolic procedure delnth(n,l);
   if n=1 then cdr l else car l . delnth(n - 1,cdr l);


% MATRIX Pretty printer.

symbolic procedure mat!-p!-print u;
   begin integer c!-leng1,icoln,pp,icol,column!-leng,m,n;
         scalar column!-s!-point,maxleng,element!-leng;
      u := cdr u;
      icoln := length car u;
      icol := linelength nil - 8;
      !&m!-p!-flag!& := t;
      element!-leng := !&count u;
      !&m!-p!-flag!& := nil;
    a:
      maxleng := !&max!-row element!-leng;
      c!-leng1 := plus!-l maxleng + 3*(icoln - 1);
      if c!-leng1=column!-leng then go to dump;
      column!-leng := c!-leng1;
      if column!-leng>icol
        then <<element!-leng :=
                subst( - 1,maxl maxleng,element!-leng);
               go to a>>;
      prin2!* !&name;
      prin2!* " := ";
      terpri!* nil;
      n := 0;
      column!-s!-point :=
       for each y in maxleng collect <<n := n + y;
                                       n := n + 3;
                                       n + 3>>;
      column!-s!-point := append(list 3,column!-s!-point);
      terpri();
      prin2 "|-";
      spaces (column!-leng + 4);
      prin2 "-|";
      terpri();
      m := 1;
      for each y in u do
         <<n := 1;
           for each z in y do
              <<posn!* := nth(column!-s!-point,n);
                if nth(nth(element!-leng,m),n)<0
                  then <<prin2!* "*";
                         prin2!* "(";
                         prin2!* m;
                         prin2!* ",";
                         prin2!* n;
                         prin2!* ")">>
                 else maprin z;
                n := n + 1>>;
           pp := column!-leng + 7;
           for i := ymin!*:ymax!* do
              <<pline!* := append(pline!*, list(((0 . 1) . i) . "|"));
                pline!* := append(list(((pp . (pp + 1)) . i) . "|"),
                                  pline!*)>>;
           terpri!* nil;
           m := m + 1;
           prin2 "| ";
           spaces (column!-leng + 4);
           prin2 " |";
           terpri()>>;
      prin2 "|-";
      spaces (column!-leng + 4);
      prin2 "-|";
      terpri();
      terpri();
      m := 1;
      for each y in u do
         <<n := 1;
           for each z in y do
              <<if nth(nth(element!-leng,m),n)<0
                       then <<prin2!* "*";
                              prin2!* "(";
                              prin2!* m;
                              prin2!* ",";
                              prin2!* n;
                              prin2!* ")";
                              prin2!* " ";
                              maprin z;
                              terpri!* t>>;
                n := n + 1>>;
           m := m + 1>>;
      return nil;
    dump:
      prin2t "Column length too long";
      matpri!*('mat . u,list mkquote !&name,'only)
   end;

symbolic procedure !&count u;
   begin integer n;
      return foreach y in u collect
                foreach z in y collect
                   <<!&count!& := nil;
                     maprin z;
                     n := posn!*;
                     pline!* := nil;
                     posn!* := orig!*;
                     ycoord!* := ymax!* := ymin!* := 0;
                     if null !&count!& then n else minus n>>;
   end;

global '(!&max!-l);

symbolic procedure !&max!-row u;
   begin scalar v;
    a:
      if null car u then return v;
      u := !&max!-row1 u;
      v := append(v,list !&max!-l);
      go to a
   end;

symbolic procedure !&max!-row1 u;
   begin
      !&max!-l := 1;
      return for each y in u collect
                <<!&max!-l := if car y<0 then 6
                               else max(!&max!-l,car y);
                  cdr y>>
   end;

symbolic procedure maxl u; maxl1(cdr u,car u);

symbolic procedure maxl1(u,v);
   if null u then v
    else if car u>v then maxl1(cdr u,car u)
    else maxl1(cdr u,v);

symbolic procedure mprint u;
   begin scalar v;
    a:
      if null u then return nil
       else if atom car u and (v := get(car u,'matrix))
        then <<!&name := car u;
               mat!-p!-print v;
               !&name := nil>>
       else if stringp car u then varpri(car u,nil,'only)
       else if v := arrayp car u
        then <<!&namearray := car u;
               print!-array2(list v,nil);
               !&namearray := nil;
               nil>>
       else <<!&name := car u;
              rat!-p!-print aeval car u;
              !&name := nil>>;
    b:
      u := cdr u;
      go to a
   end;

rlistat '(mprint);

symbolic procedure print!-array2(u,w);
   begin integer n; scalar v;
      v := car u;
      if car v eq '!&vector
        then begin
                n := cadr v;
                v := cdr v;
                if w then w := car w;
                for i := 0:n do
                   <<v := cdr v;
                     print!-array2(v,list append(w,list i))>>
             end
       else if v neq 0
        then <<!&name := append(list !&namearray,car w);
               rat!-p!-print v;
               !&name := nil>>
   end;


% Rational function Pretty printer.

symbolic procedure rat!-p!-print u;
   begin integer os,ln,orgnum,orgden,ll,lennum,lenden;
         scalar name,uden,unum;
      if null u then return nil;
      if numberp u
        then <<varpri(u,list mkquote !&name,'only);
               terpri();
               !&name := nil;
               return nil>>;
      u := cadr u;
      !&m!-p!-flag!& := t;
      lenden := !&count!-length (uden := cdr u./1);
      lennum := !&count!-length (unum := car u./1);
      !&m!-p!-flag!& := nil;
      ln := (linelength nil - lengthc !&name) - 4;
      os := orig!*;
      if cdr u=1 or lenden>ln or lennum>ln then go to dump;
      if !&name
        then <<inprint('setq,2,list !&name);
               oprin 'setq;
               name := pline!*;
               os := posn!*;
               !&name := nil;
               pline!* := nil>>;
      if lenden>lennum
        then <<orgnum := (lenden - lennum)/2; ll := lenden>>
       else <<orgden := (lennum - lenden)/2; ll := lennum>>;
      posn!* := orgnum + os + 1;
      maprin mk!*sq unum;
      terpri!* nil;
      if name then pline!* := name else pline!* := nil;
      posn!* := os;
      for i := 1:ll + 2 do prin2!* "-";
      terpri!* nil;
      posn!* := orgden + os + 1;
      maprin mk!*sq uden;
      terpri!* t;
      return nil;
    dump:
      varpri(mk!*sq u,list mkquote !&name,'only);
      terpri();
      !&name := nil
   end;

symbolic procedure !&count!-length u;
   begin integer n;
      !&count!& := nil;
      maprin mk!*sq u;
      n := posn!* - orig!*;
      if !&count!& then n := linelength nil + 10;
      pline!* := nil;
      posn!* := orig!*;
      ycoord!* := ymax!* := ymin!* := 0;
      return n
   end;

endmodule;

end;

