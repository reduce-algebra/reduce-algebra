module tayutils;

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

% $Id$

%*****************************************************************
%
%       Utility functions that operate on Taylor kernels
%
%*****************************************************************


exports add!-degrees, add!.comp!.tp!., check!-for!-cst!-taylor,
        comp!.tp!.!-p, delete!-superfluous!-coeffs, enter!-sorted,
        exceeds!-order, exceeds!-order!-variant, find!-non!-zero,
        get!-cst!-coeff, inv!.tp!., is!-neg!-pl, min2!-order,
        mult!.comp!.tp!., rat!-kern!-pow, replace!-next,
        subtr!-degrees, subtr!-tp!-order, taydegree!<,
        taydegree!-strict!<!=, taymincoeff, tayminpowerlist,
        taylor!*!-constantp, taylor!*!-nzconstantp, taylor!*!-onep,
        taylor!*!-zerop, taytpmin2, tp!-greaterp, truncate!-coefflist,
        truncate!-taylor!*;

imports

% from the REDUCE kernel:
        ./, domainp, eqcar, gcdn, geq, lastpair, lc, ldeg, mkrn, mvar,
	neq, nth, numr, red, reversip, simprn,

% from the header module:
        !*tay2q, get!-degree, get!-degreelist, make!-cst!-powerlist,
        make!-taylor!*, nzerolist, prune!-coefflist, taycfpl, taycfsq,
        taycoefflist, taygetcoeff, tayflags, taylor!:, tayorig,
        taytemplate, taytpelnext, taytpelorder, taytpelpoint,
        taytpelvars, tpdegreelist, tpnextlist,

% from module Tayintro:
        confusion,

% from module TayUtils:
        taycoefflist!-zerop;



symbolic procedure add!-degrees (dl1, dl2);
  %
  % calculates the element-wise sum of two degree lists dl1, dl2.
  %
  taylor!:
    begin scalar dl,u,v,w;
      while dl1 do <<
        u := car dl1;
        v := car dl2;
        w := nil;
        while u do <<
          w := (car u + car v) . w;
          u := cdr u;
          v := cdr v>>;
        dl := reversip w . dl;
        dl1 := cdr dl1;
        dl2 := cdr dl2>>;
      return reversip dl
    end;

symbolic procedure subtr!-degrees(dl1,dl2);
  %
  % calculates the element-wise difference of two degree lists dl1, dl2.
  %
  taylor!:
    begin scalar dl,u,v,w;
      while dl1 do <<
        u := car dl1;
        v := car dl2;
        w := nil;
        while u do <<
          w := (car u - car v) . w;
          u := cdr u;
          v := cdr v>>;
      dl := reversip w . dl;
      dl1 := cdr dl1;
      dl2 := cdr dl2>>;
    return reversip dl
  end;

symbolic procedure find!-non!-zero pl;
  %
  % pl is a power list.  Returns pair (n . m) of position of first
  % non zero degree.
  %
  begin scalar u; integer n, m;
    n := 1;
   loop:
    m := 1;
    u := car pl;
   loop2:
    if not (car u = 0) then return (n . m);
    u := cdr u;
    m := m + 1;
    if not null u then goto loop2;
    pl := cdr pl;
    n := n + 1;
    if null pl then confusion 'find!-non!-zero;
    goto loop
  end$


symbolic procedure lcmn(n,m);
   %
   % returns the least common multiple of two integers m,n.
   %
   n*(m/gcdn(n,m));

symbolic inline procedure get!-denom expo;
   if atom expo then 1 else cddr expo;

symbolic procedure get!-denom!-l expol;
   <<for each el in cdr expol do
       result := lcmn(result,get!-denom el);
     result>>
      where result := get!-denom car expol;

symbolic procedure get!-denom!-ll(dl,pl);
   if null dl then nil
    else lcmn(car dl,get!-denom!-l car pl)
           . get!-denom!-ll(cdr dl, cdr pl);

symbolic procedure smallest!-increment cfl;
   if null cfl then confusion 'smallest!-increment
    else begin scalar result;
     result := for each l in taycfpl car cfl collect get!-denom!-l l;
     for each el in cdr cfl do
       result := get!-denom!-ll(result,taycfpl el);
     return for each n in result collect if n=1 then n else mkrn(1,n);
   end;


symbolic procedure common!-increment(dl1,dl2);
   begin scalar result,l;
     loop:
       l := lcmn(get!-denom car dl1,get!-denom car dl2);
       result := (if l=1 then l else mkrn(1,l)) . result;
       dl1 := cdr dl1;
       dl2 := cdr dl2;
       if not null dl1 then goto loop
        else if not null dl2 then confusion 'common!-increment
        else return reversip result
   end;

symbolic procedure min2!-order(nextlis,ordlis,dl);
  %
  % (List of Integers, List of Integers, TayPowerList) -> Boolean
  %
  % nextlis is the list of TayTpElNext numbers,
  % ordlis the list of TayTpElOrder numbers,
  % dl the degreelist of a coefficient.
  % Dcecrease the TayTpElNext number if the degree is greater than
  % the order, but smaller than the next.
  % Returns the corrected nextlis.
  %
  if null nextlis then nil
   else (taylor!: (if dg > car ordlis then min2(dg,car nextlis)
                   else car nextlis) where dg := get!-degree car dl)
          . min2!-order(cdr nextlis,cdr ordlis,cdr dl);

symbolic procedure replace!-next(tp,nl);
   %
   % Given a template and a list of exponents, returns a template
   %  with the next part replaced.
   %
   if null tp then nil
    else {taytpelvars car tp,
          taytpelpoint car tp,
          taytpelorder car tp,
          car nl}
           . replace!-next(cdr tp,cdr nl);

symbolic procedure comp!.tp!.!-p (u, v);
  %
  % Checks templates of Taylor kernels u and v for compatibility,
  % i.e. whether variables and expansion points match.
  % Returns t if possible.
  %
  begin;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil;
    u := cdr u; v := cdr v;
    if null u then return t;
    goto loop
  end$

symbolic procedure add!.comp!.tp!.(u,v);
  %
  % Checks templates of Taylor kernels u and v for compatibility
  % when adding them, i.e. whether variables and expansion points
  % match.
  % Returns either a list containing a new Taylor template whose
  % degrees are the minimum of the corresponding degrees of u and v,
  % or nil if variables or expansion point(s) do not match.
  %
  taylor!:
  begin scalar w;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
    if null u then return {nil};
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil
     else w := {taytpelvars car u,
                taytpelpoint car u,
                min2(taytpelorder car u,taytpelorder car v),
                min2(taytpelnext car u,taytpelnext car v)}
                . w;
    u := cdr u; v := cdr v;
    if null u then return {reversip w};
    goto loop
  end;

symbolic procedure taymindegreel(pl,dl);
   taylor!:
     if null pl then nil
      else min2(get!-degree car pl,car dl)
             . taymindegreel(cdr pl,cdr dl);

symbolic procedure get!-min!-degreelist cfl;
  taylor!:
    if null cfl then confusion 'get!-min!-degreelist
     else if null cdr cfl then get!-degreelist taycfpl car cfl
     else taymindegreel(taycfpl car cfl,
                        get!-min!-degreelist cdr cfl);

symbolic procedure mult!.comp!.tp!.(u,v,div!?);
  %
  % Checks templates of Taylor kernels u and v for compatibility
  % when multiplying or dividing them, i.e., whether variables and
  % expansion points match.  The difference to addition is that
  % in addition to the new template it returns two degreelists
  % and two nextlists to be used by truncate!-coefflist which
  % are made up so that the kernels have the same number of terms.
  %
  taylor!:
  begin scalar cf1,cf2,next1,next2,ord1,ord2,w,
        !#terms!-1,!#terms!-next,dl1,dl2,mindg;
    cf1 := prune!-coefflist taycoefflist u;
    if null cf1 then dl1 := nzerolist length taytemplate u
     else dl1 := get!-min!-degreelist cf1;
    cf2 := prune!-coefflist taycoefflist v;
    if null cf2 then dl2 := nzerolist length taytemplate v
     else dl2 := get!-min!-degreelist cf2;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
    if null u then return {nil,nil,nil,nil,nil};
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil;
    mindg := if div!? then car dl1 - car dl2 else car dl1 + car dl2;
    !#terms!-1 := min2(taytpelorder car u - car dl1,
                       taytpelorder car v - car dl2);
    !#terms!-next := min2(taytpelnext car u - car dl1,
                          taytpelnext car v - car dl2);
    ord1 := (!#terms!-1 + car dl1) . ord1;
    ord2 := (!#terms!-1 + car dl2) . ord2;
    next1 := (!#terms!-next + car dl1) . next1;
    next2 := (!#terms!-next + car dl2) . next2;
    w := {taytpelvars car u,taytpelpoint car u,
          mindg + !#terms!-1,mindg + !#terms!-next}
          . w;
    u := cdr u; v := cdr v; dl1 := cdr dl1; dl2 := cdr dl2;
    if null u then return {reversip w,
                           reversip ord1,
                           reversip ord2,
                           reversip next1,
                           reversip next2};
    goto loop
  end;

symbolic procedure inv!.tp!. u;
  %
  % Checks template of Taylor kernel u for inversion. It returns a
  % template (to be used by truncate!-coefflist)
  % which is made up so that the resulting kernel has the correct
  % number of terms.
  %
  taylor!:
  begin scalar w,cf,!#terms!-1,!#terms!-next,dl,mindg;
    cf := prune!-coefflist taycoefflist u;
    if null cf then dl := nzerolist length taytemplate u
     else dl := get!-degreelist taycfpl car cf;
    u := taytemplate u;
    if null u then return {nil,nil};
   loop:
    mindg := - car dl;
    !#terms!-1 := taytpelorder car u - car dl;
    !#terms!-next := taytpelnext car u - car dl;
    w := {taytpelvars car u,taytpelpoint car u,mindg + !#terms!-1,
          mindg + !#terms!-next}
          . w;
    u := cdr u; dl := cdr dl;
    if null u then return {reversip w};
    goto loop
  end;

symbolic inline procedure taycoeff!-before(cc1,cc2);
  %
  % (TayCoeff, TayCoeff) -> Boolean
  %
  % returns t if coeff cc1 is ordered before cc2
  % both are of the form (degreelist . sq)
  %
  taydegree!<(taycfpl cc1,taycfpl cc2);

symbolic procedure taydegree!<(u,v);
  %
  % (TayPowerList, TayPowerList) -> Boolean
  %
  % returns t if coefflist u is ordered before v
  %
  taylor!:
  begin scalar u1,v1;
   loop:
    u1 := car u;
    v1 := car v;
   loop2:
     if car u1 > car v1 then return nil
      else if car u1 < car v1 then return t;
     u1 := cdr u1;
     v1 := cdr v1;
     if not null u1 then go to loop2;
    u := cdr u;
    v := cdr v;
    if not null u then go to loop
  end;

symbolic procedure taydegree!-strict!<!=(u,v);
  %
  % (TayPowerList, TayPowerList) -> Boolean
  %
  % returns t if every component coefflist u is less or equal than
  %  respective component of v
  %
  taylor!:
  begin scalar u1,v1;
   loop:
    u1 := car u;
    v1 := car v;
   loop2:
     if car u1 > car v1 then return nil;
     u1 := cdr u1;
     v1 := cdr v1;
     if not null u1 then go to loop2;
    u := cdr u;
    v := cdr v;
    if not null u then go to loop;
    return t
  end;

symbolic procedure exceeds!-order(ordlis,cf);
  %
  % (List of Integers, TayPowerlist) -> Boolean
  %
  % Returns t if the degrees in coefficient cf are greater or
  % equal than those in the degreelist ordlis
  %
  if null ordlis then nil
   else taylor!:(get!-degree car cf >= car ordlis)
          or exceeds!-order(cdr ordlis,cdr cf);

symbolic procedure exceeds!-order!-variant(ordlis,cf);
  %
  % (List of Integers, TayPowerlist) -> Boolean
  %
  % Returns t if the degrees in coefficient cf are greater or
  % equal than those in the degreelist ordlis
  %
  if null ordlis then nil
   else taylor!:(get!-degree car cf > car ordlis)
          or exceeds!-order!-variant(cdr ordlis,cdr cf);

symbolic procedure enter!-sorted (u, alist);
  %
  % (TayCoeff, TayCoeffList) -> TayCoeffList
  %
  % enters u into the alist alist according to the standard
  % ordering for the car part
  %
  if null alist then {u}
   else if taycoeff!-before (u, car alist) then u . alist
   else car alist . enter!-sorted (u, cdr alist)$

symbolic procedure delete!-superfluous!-coeffs(cflis,pos,n);
  %
  % (TayCoeffList, Integer, Integer) -> TayCoeffList
  %
  % This procedure deletes all coefficients of a TayCoeffList cflis
  % whose degree in position pos exceeds n.
  %
  taylor!:
  for each cc in cflis join
     (if get!-degree nth(taycfpl cc,pos) > n then nil else {cc});

symbolic procedure truncate!-coefflist (cflis, dl);
  %
  % (TayCoeffList, List of Integers) -> TayCoeffList
  %
  % Deletes all coeffs from coefflist cflis that are equal or greater
  %  in degree than the corresponding degree in the degreelist dl.
  %
  begin scalar l;
    for each cf in cflis do
      if not exceeds!-order (dl, taycfpl cf) then l := cf . l;
    return reversip l
  end;

symbolic procedure taytp!-min2(tp1,tp2);
  %
  % finds minimum (w.r.t. Order and Next parts) of compatible
  %  templates tp1 and tp2
  %
  taylor!:
    if null tp1 then nil
     else if not (taytpelvars car tp1 = taytpelvars car tp2 and
                  taytpelpoint car tp1 = taytpelpoint car tp2)
      then confusion 'taytpmin2
     else {taytpelvars car tp1,taytpelpoint car tp2,
           min2(taytpelorder car tp1,taytpelorder car tp2),
           min2(taytpelnext car tp1,taytpelnext car tp2)}
          . taytp!-min2(cdr tp1,cdr tp2);


symbolic procedure truncate!-taylor!*(tay,ntp);
  %
  % tcl is a coefflist for template otp
  % truncate it to coefflist for template ntp
  %
  taylor!:
   begin scalar nl,ol,l,tp,tcl,otp;
     tcl := taycoefflist tay;
     otp := taytemplate tay;
     tp := for each pp in pair(ntp,otp) collect
           {taytpelvars car pp,
            taytpelpoint car pp,
            min2(taytpelorder car pp,taytpelorder cdr pp),
            min2(taytpelnext car pp,taytpelnext cdr pp)};
     nl := tpnextlist tp;
     ol := tpdegreelist tp;
     for each cf in tcl do
       if not null numr taycfsq cf
%         then ((if not exceeds!-order(nl,pl) then l := cf . l
%                 else nl := min2!-order(nl,ol,pl))
         then ((if not exceeds!-order!-variant(ol,pl) then l := cf . l
                 else nl := min2!-order(nl,ol,pl))
                where pl := taycfpl cf);
     return make!-taylor!*(reversip l,replace!-next(tp,nl),
                           tayorig tay,tayflags tay)
   end;

symbolic procedure tp!-greaterp(tp1,tp2);
   %
   % Given two templates tp1 and tp2 with matching variables and
   %  expansion points this function returns t if the expansion
   %  order wrt at least one variable is greater in tp1 than in tp2.
   %
   if null tp1 then nil
    else taylor!: (taytpelorder car tp1 > taytpelorder car tp2)
           or tp!-greaterp(cdr tp1,cdr tp2);

symbolic procedure subtr!-tp!-order(tp1,tp2);
   %
   % Given two templates tp1 and tp2 with matching variables and
   %  expansion points this function returns the difference in their
   %  orders.
   %
   taylor!:
    if null tp1 then nil
     else (taytpelorder car tp1 - taytpelorder car tp2)
            . subtr!-tp!-order(cdr tp1,cdr tp2);


COMMENT Procedures to non-destructively modify Taylor templates;

symbolic procedure addto!-all!-taytpelorders(tp,nl);
  taylor!:
   if null tp then nil
    else {taytpelvars car tp,
          taytpelpoint car tp,
          taytpelorder car tp + car nl,
          taytpelnext car tp + car nl} .
         addto!-all!-taytpelorders(cdr tp,cdr nl);

symbolic procedure taymincoeff cflis;
  %
  % Returns degree of first non-zero coefficient
  % or 0 if there isn't any.
  %
  if null cflis then 0
   else if not null numr taycfsq car cflis
    then get!-degree car taycfpl car cflis
   else taymincoeff cdr cflis;

symbolic procedure tayminpowerlist cflis;
  %
  % Returns degreelist of first non-zero coefficient of TayCoeffList
  % cflis or a list of zeroes if there isn't any.
  %
  if null cflis then confusion 'tayminpowerlist
   else tayminpowerlist1(cflis,length taycfpl car cflis);

symbolic procedure tayminpowerlist1(cflis,l);
   if null cflis then nzerolist l
    else if null numr taycfsq car cflis
     then tayminpowerlist1(cdr cflis,l)
    else get!-degreelist taycfpl car cflis;

symbolic procedure get!-cst!-coeff tay;
   taygetcoeff(make!-cst!-powerlist taytemplate tay,taycoefflist tay);

symbolic procedure taylor!*!-constantp tay;
   taylor!*!-constantp1(make!-cst!-powerlist taytemplate tay,
                        taycoefflist tay);

symbolic procedure taylor!*!-constantp1(pl,tcf);
   if null tcf then t
    else if taycfpl car tcf = pl
     then taycoefflist!-zerop cdr tcf
    else if not null numr taycfsq car tcf then nil
    else taylor!*!-constantp1(pl,cdr tcf);

symbolic procedure check!-for!-cst!-taylor tay;
   begin scalar pl,tc;
      pl := make!-cst!-powerlist taytemplate tay;
      tc := taycoefflist tay;
      return if taylor!*!-constantp1(pl,tc) then taygetcoeff(pl,tc)
              else !*tay2q tay
   end;

symbolic procedure taylor!*!-nzconstantp tay;
   taylor!*!-nzconstantp1(make!-cst!-powerlist taytemplate tay,
                          taycoefflist tay);

symbolic procedure taylor!*!-nzconstantp1(pl,tcf);
   if null tcf then nil
    else if taycfpl car tcf = pl
     then if null numr taycfsq car tcf then nil
           else taycoefflist!-zerop cdr tcf
    else if taycfpl car tcf neq pl and
            not null numr taycfsq car tcf
     then nil
    else taylor!*!-nzconstantp1(pl,cdr tcf);

symbolic procedure taylor!*!-onep tay;
   taylor!-onep1(make!-cst!-powerlist taytemplate tay,taycoefflist tay);

symbolic procedure taylor!-onep1(pl,tcf);
   if null tcf then nil
    else if taycfpl car tcf = pl
     then if taycfsq car tcf = (1 ./ 1)
            then taycoefflist!-zerop cdr tcf
           else nil
    else if null numr taycfsq car tcf
     then taylor!*!-nzconstantp1(pl,cdr tcf)
    else nil;

symbolic procedure is!-neg!-pl pl;
  %
  % Returns t if any of the exponents in pl is negative.
  %
  taylor!:
    if null pl then nil
     else if get!-degree car pl < 0 then t
     else is!-neg!-pl cdr pl;

symbolic procedure rat!-kern!-pow(x,pos);
   %
   % check that s.f. x is a kernel to a rational power.
   %  if pos is t allow only positive exponents.
   %  returns pair (kernel . power)
   %
   begin scalar y; integer n;
     if domainp x or not null red x or not (lc x=1) then return nil;
     n := ldeg x;
     x := mvar x;
     taylor!:
       if eqcar(x,'sqrt) then return (cadr x . mkrn(1,2)*n)
        else if eqcar(x,'expt) and (y := simprn{caddr x})
               then if null pos or (y := car y)>0
                      then return (cadr x . (y*n))
                     else return nil
        else return (x . n)
   end;

endmodule;

end;
