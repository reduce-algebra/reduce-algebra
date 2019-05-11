module decrep;  % Periodic Decimal Representation.

% Author: Alan Barnes
% symbolic mode version and extension to other bases
% of earlier work by Lisa Temme, 1995

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

% Date:   April 2019.

symbolic; procedure digits2num(x, base);
%% convert an list of digits to a number
begin scalar n;

     if not pairp x then
         rederr "digits2num: arg should be list of non-negative digits";

     n := 0;

     foreach d in x do 
       if fixp d and d >= 0 and d < base then
	  n := n*base + d
       else
	  rederr  "digits2num: arg should be list of non-negative digits";
	  
     return n;
end;

symbolic procedure num2digits(n, base);
%% convert a number to a list of digits in specified base ignoring sign
begin scalar result;

    if not(fixp n) then
       rederr "num2digits: arg must be an integer";

    if n=0 then return list 0;
    if n < 0 then n := -n;

    while n > 0 do <<
        n := divide(n, base);
        result := cdr n . result;
        n := car n;
    >>;

    return result;   
end;

%***********************
operator periodic;
put('rational2periodic, 'psopfn, 'r2p!*!*);

symbolic procedure r2p!*!* u;
begin scalar base, n, d, res, neg_flag;
   base := if cdr u then ieval cadr u else 10;
   if base < 2 or base > 16 then
      rederr "rational2periodic: base must be >=2 and <= 16";
   u := car u;
   if eqcar(u, 'minus) then <<
      u := cadr u, neg_flag := t; >>;
   u := r2p!-num!-den u;
   n := car u;
   d := cdr u;
   if n < 0 then <<
      neg_flag := t; n := -n>>;
   res := rat2fixed_pt(n, d, base);
   if neg_flag then 
      base := -base;
   return list('periodic, 'list . car res, 'list . cadr res,
                'list . caddr res, base);

end;

symbolic procedure r2p!-num!-den(u);     
begin scalar v, w;
   if fixp u then  return u . 1;
   
   if eqcar(u,'quotient) and  fixp cadr u and fixp caddr u then 
            return (cadr u) . caddr u;

   if eqcar(u, '!*sq) then <<
           v := cadr u;  % standard quotient
           if domainp(w := car v) then
             if  fixp w and fixp cdr v then
	        return w . cdr v
             else if eqcar(w, '!:rn!:) and cdr v = 1 then 
                return cdr w;
   >>;
   rederr "rational2periodic: 1st arg must be a rational number";
end;

symbolic procedure rat2fixed_pt(n, d, base);
%% gives periodic fixed point base b representation of rational n/d
begin scalar m, z, intpart, non_periodic, repeating;

 %% calculate integer part
    m := divide(n, d);
    intpart := car m;
    n := base*cdr m;
    m := divide(n, d);

%% calculate digits in fractional part
   while n neq 0 and not member(m, z) do <<
      z := m  . z;
      n := base*cdr m;
      m := divide(n, d);
   >>;  

   z := reversip z;
   if n = 0 then
      non_periodic := foreach pr in z collect car pr
   else <<
       while z do 
          if m neq car z then <<
	      non_periodic := (caar z) . non_periodic;
	      z := cdr z;
           >>
           else <<
	      repeating := foreach pr in z collect  car pr;
	      z := nil;
	   >>; 
        non_periodic := reversip non_periodic;
   >>;
   return list(num2digits(intpart, base), non_periodic, repeating);
end;


%% Procedure to convert a periodic representation to a rational one.
symbolic procedure fixed_pt2rat(ip, npp, pp, b);
begin scalar lnpp, lpp, n, d, pp1, g;
   lnpp := length npp;
   lpp := length pp;

   ip := digits2num(ip, b);
   if lnpp neq 0 then
      npp := digits2num(npp, b)
   else
      npp := 0;

   d := expt(b, lnpp);
   n := ip*d + npp;

   if lpp neq 0 then <<
      pp := digits2num(pp, b);
      pp1 := expt(b, lpp) - 1;
      n := n*pp1 + pp;
      d := d*pp1;
   >>;
   g := gcdn(n, d);
   n := n/g;
   d := d/g;

   if d = 1 then
      return n
   else
     return list('quotient, n , d);

end;

symbolic procedure !*digit_listp(u, b);
begin scalar res;
  if not eqcar(u, 'list) then 
     return nil;

  res := t;
  u := cdr u;
  while res and u do <<
     if car u < 0 or car u > b then
        res := nil;
     u := cdr u;
  >>;
  return res;
end; 
 
put('periodic2rational, 'psopfn, 'p2r!*!*);

symbolic procedure p2r!*!* u;
begin scalar l, ip, npp, pp, base, neg_flag, res;
  l := length u;
  if l = 1 then
     if caar u = 'periodic then <<
        u := cdar u;
	ip := car u;
        npp := cadr u;
        pp := caddr u;
        base := cadddr u;
	if base < 0 then <<
	   neg_flag := t;
	   base := -base
	>>;
	res :=  fixed_pt2rat(cdr ip, cdr npp, cdr pp, base);
	if neg_flag then
	   return list('minus, res)
	else
	   return res;
     >>
     else
        rederr "periodic2rational: single arg must be (periodic, ....)";

  if l = 2 or l > 4 then
     rederr "periodic2rational: too many arguments -- must be 1, 3 or 4"; 

  ip := car u;
  npp := cadr u;
  pp := caddr u;
  if cdddr u then
     base := ieval cadddr u
  else
     base := 10;
  if base < 0 then <<
     neg_flag := t;
     base := -base;
  >>;
  if base < 2 or base > 16 then
     rederr "periodic2rational: base must be >=2 and <= 16";
  if length ip = 1 or not (!*digit_listp(ip, base) and 
                           !*digit_listp(npp, base) and
                           !*digit_listp(pp, base)) then
        rederr "periodic2rational: invalid digit list(s) for this base";
  res :=  fixed_pt2rat(cdr ip, cdr npp, cdr pp, base);
  if neg_flag then
     return list('minus, res)
  else
     return res;
end;

% printers

fluid '(!*digit2ch);
!*digit2ch := mkvect 15$

symbolic procedure print_periodic (u);

   if not(!*nat) or
        (length caddr u + 10) > (linelength nil) then 'failed else

   begin scalar oo, ip, npp, pp, base, neg_flag, l1, l2, l3, l;

    ip := cdr cadr u;
    l1 := length ip;
    
    npp := cdr caddr u;
    l2 := length npp;
    
    pp := cdr cadddr u;
    l3 := length pp;
    
    base := cadr cdddr u;
    if base < 0 then <<
       neg_flag := t;
       base := -base;
    >>;

    if l3 > 0 then <<
       l := l1+l2+1;   % 'decimal' point needed
       if neg_flag then %  and minus sign
          l  := l + 1;
       ycoord!* := ycoord!* +1;
       oo := posn!*;
       ymax!* := max(ymax!*,ycoord!*);
    
       for i := 1 : l do prin2!* " ";
       for i := 1 : l3 do prin2!* "_";
       posn!* := oo;
       ycoord!* := ycoord!* -1;
    >>;

    if neg_flag then prin2!* "-";
    foreach d in ip do prin2!* getv(!*digit2ch, d);
    if l2 > 0 or l3 > 0 then <<
       prin2!* ".";
       foreach d in npp do prin2!* getv(!*digit2ch, d);
       foreach d in pp do prin2!* getv(!*digit2ch, d);
    >>;
    
    if base neq 10 then <<
       prin2!* "  (base ";
       prin2!* base;
       prin2!* ")";
    >>;
    
    return t;
end;

for i:=0:9 do putv(!*digit2ch, i, i)$
putv(!*digit2ch, 10, '!A)$ putv(!*digit2ch, 11, '!B)$
putv(!*digit2ch, 12, '!C)$ putv(!*digit2ch, 13, '!D)$
putv(!*digit2ch, 14, '!E)$ putv(!*digit2ch, 15, '!F)$

put('periodic, 'prifn, 'print_periodic);
put('periodic,'fancy!-prifn,'fancy!-periodic);

symbolic procedure fancy!-periodic(u);
fancy!-level
  begin scalar w0, ip, npp, pp, base, neg_flag, l2, l3;
    ip := cdr cadr u;
    npp := cdr caddr u;
    l2 := length npp;
    pp := cdr cadddr u;
    l3 := length pp;
    
    base := cadr cdddr u;
    if base < 0 then <<
       neg_flag := t;
       base := -base;
    >>;

    if neg_flag then fancy!-prin2!*("-", 0);
    foreach d in ip do fancy!-prin2!*(getv(!*digit2ch, d), 0);
    if l2 > 0 or l3 > 0 then <<
      fancy!-prin2!*(".", 0);
      foreach d in npp do fancy!-prin2!*(getv(!*digit2ch, d), 0);
      if l3 > 0 then <<
      % *************** temporary hack to enclose periodic part in 
      % ********* brackets rather than overlining
	 fancy!-prin2!*('![, 0);
         foreach d in pp do fancy!-prin2!*(getv(!*digit2ch, d), 0);
         fancy!-prin2!*('!], 0);
      >>;
    >>;
    % print number base as a subscript if it is not 10
    if base neq 10 then <<
       fancy!-prin2!*('!_, 0);
       fancy!-prin2!*('!{, 0);
       w0 := fancy!-maprint(base,0) where !*list=nil;
       fancy!-prin2!*('!}, 0);
    >>;
  return w0;
end;

endmodule;

end;
