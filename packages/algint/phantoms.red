module phantoms;

% Author: James H. Davenport.

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


fluid '(!*trint cancellationlist inequalitystack lhs magiclist nindex
        termsused);

exports phantomterms;

imports getv,!*multf,addf;

% See if an exponent set agrees with a set of linear constraints.


symbolic procedure matchp(pow,equalities,inequalities);
%True if the equalities and inequalities given are consistent with
%the given power
 begin scalar fg;
top:
    if null equalities then go to ineq;
    fg:=matcheqnp(pow,car equalities);
    if null fg then return nil; %Clash with an equality
    equalities:=cdr equalities;
    go to top;
ineq:
    if null inequalities then return t; %OK - consistent
    fg:=matcheqnp(pow,car inequalitystack);
    if fg then return nil; %Clash with an inequality
    inequalities:=cdr inequalities;
    go to ineq end;


symbolic procedure matcheqnp(pow,eqqn);
% Substitute integers given by pow into linear
% form eqqn and return t if result is zero
 begin scalar i,res;
    res:=getv(eqqn,1); %Constant term from the equation
    for i:=2:nindex do <<
      res:=addf(res,!*multf(!*n2f car pow,getv(eqqn,i)));
      pow:=cdr pow >>;
    if null res then return t
                else return nil
 end;

%symbolic procedure !*n2f n;
%% Convert number into standard form
%    if n=0 then nil
%    else n;

symbolic procedure phantomterms(lhs);
% Put extra term on the front of lhs to allow for malice i;
% cancelling terms. give it a zero weight.
 begin scalar r,s;
    if !*trint then printc "phantomterms called on";
    if !*trint then superprint lhs;
    r:=findphantoms(lpow lhs); %Things that may be needed
    if !*trint then printc "findphantoms returned";
    if !*trint then printc r;
    while r do <<
       if not member(car r,termsused) then s:=(car r) . s;
       r:=cdr r >>;
    if !*trint then printc "unused phantoms=";
    s:=reversewoc s; %Back in right order again
    if !*trint then printc s;
    if not null s then <<
    if !*trint then   printc "phantom term generated in integrand";
    if !*trint then   printc "exponent set is";
    if !*trint then   printc car s >>;
    if null s then r:=lhs
    else r := ((car s) . (nil . 1)) . lhs;
    return r end;


symbolic procedure findphantoms(pow);
 begin scalar l,w;
    l:=cancellationlist;
top:
    if null l then return cdrxx assoc(pow,magiclist);
%seek user help on magiclist
    w:=phantommatch(pow,car l);
    if not null w then return w;
    l:=cdr l;
    go to top end;


symbolic procedure cdrxx a;
    if atom a then nil
    else cdr a;


symbolic procedure phantommatch(pow,pattern);
% Items on cancellationlist are (case . effect) where
% case = (equalities . inequalities) - a set of constraints
% on the power that must be satisfied before it is special,
% and effect is a list of offsets that have to be subtracted
% to pow to get the powers representing generated phantoms
 begin scalar r;
    r:=matchp(pow,caar pattern,cdar pattern);
    if null r then return nil; %Template does not fit
    return offsetlist(pow,cdr pattern)
 end;

symbolic procedure offsetlist(pow,l);
    if null l then nil
    else begin
        scalar w;
        w:=offset1(pow,car l);
        l:=offsetlist(pow,cdr l);
        if w then l:=w . l;
        return l end;

symbolic procedure offset1(pow,delta);
% Compute offset version of exponent set - return nil if this
% would involve negative powers
  begin
    scalar w;
top:
    if null pow then return reversewoc w;
    w:=(car pow - car delta) . w;
    if minusp car w then return nil;
    pow:=cdr pow; delta:=cdr delta;
    goto top
   end;

endmodule;

end;

