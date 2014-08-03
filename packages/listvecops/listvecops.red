module listvecops;   % Vector operations on lists.

% Author: Eberhard Schruefer

% Copyright (c) 2014, Eberhard Schruefer.  All rights reserved.

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

create!-package('(listvecops),nil);

symbolic procedure listplus(u,v);
  begin scalar r,z;
    z := for each j in u collect reval1(j,v);
    r := cdar z;
    z := cdr z;
    for each j in z do if null eqcar(car z,'list) 
                          then rederr "Only a list can be added to a list."
                        else r := listadd2(r,cdar z);
    return 'list . for each j in r collect mk!*sq j
  end;

symbolic procedure listadd2(u,v);
   if null u then if v then rederr "Unequal length lists in add."
                   else nil
    else if null v then rederr "Unequal length lists in add."
    else addsq(simp car u,simp car v) . listadd2(cdr u,cdr v);

%put('plus,'rtypefn,getrtypeor); %This would allow for stricter type checking.
       
put('plus,'listfn,'listplus);

symbolic procedure listdifference(u,v);
  begin scalar x,y;
    x := reval1(car u,v);
    if null eqcar(x,'list) then rederr "Type error in difference.";
    x := cdr x;
    y := reval1(cadr u,v);
    if null eqcar(y,'list) then rederr "Type error in difference.";
    y := cdr y;
    if length x neq length y 
       then rederr "Not equal length lists found in difference.";
    return 'list . listdifference2(x,y)
  end;

symbolic procedure listdifference2(u,v);
   if null u then nil
    else mk!*sq simpdiff {car u,car v} . listdifference2(cdr u,cdr v);

put('difference,'listfn,'listdifference);

symbolic procedure listminus(u,v);
   begin scalar x;
     x := reval1(car u,v);
     return 'list . for each j in cdr x collect mk!*sq negsq simp j;
   end;

put('minus,'listfn,'listminus);

symbolic procedure listtimes(u,v); 
  begin scalar x,z;
     x := reval1(car u,v);
     if null eqcar(x,'list) then x := simp x;
     for each j in cdr u do
         <<z := reval1(j,v);
           x := if eqcar(z,'list) 
                   then if eqcar(x,'list) then 'list . listtimes2(cdr x,cdr z)
                    else 'list . listtimes1(cdr z,x)
            else if eqcar(x,'list) then 'list . listtimes1(cdr x,simp z)
            else multsq(x,simp z)>>;
     return x 
   end;

symbolic procedure listtimes1(u,v);
   for each j in u collect mk!*sq multsq(simp j,v);

symbolic procedure listtimes2(u,v);
   if null u then if v then rederr "Unequal length lists found in times."
                   else nil
    else if null v then rederr "Unequal length lists found in times."
    else mk!*sq multsq(simp car u,simp car v) . listtimes2(cdr u,cdr v);

put('times,'listfn,'listtimes); 

symbolic procedure listquotient(u,v);
  begin scalar x,y;
    x := reval1(car u,v);
    y := reval1(cadr u,v);
    return 'list . if eqcar(y,'list) then listquotient2(cdr x,cdr y)
                    else for each j in cdr x collect mk!*sq simpquot {j,y};
  end;

symbolic procedure listquotient2(u,v);
    if null u then if v then rederr "Unequal length lists found in quotient."
                   else nil
    else if null v then rederr "Unequal length lists found in quotient."
    else mk!*sq quotsq(simp car u,simp car v) . listquotient2(cdr u, cdr v);

put('quotient,'listfn,'listquotient);

symbolic procedure listexpt(u,v);
   begin scalar x,y;
     x := reval1(car u,v);
     y := reval1(cadr u,v);
     return 'list . for each j in cdr x collect mk!*sq simpexpt {j,y}
   end;

put('expt,'listfn,'listexpt);

symbolic procedure listdotprod(u,v);
   begin scalar x,y;
     x := reval1(car u,v);
     y := reval1(cadr u,v);
     if null(eqcar(x,'list) and eqcar(y,'list)) 
        then rederr "Dot product can only be applied to two lists.";
     return mk!*sq listdotprod2(cdr x,cdr y);
   end;

symbolic procedure listdotprod2(u,v);
   begin scalar x;
     x := nil ./ 1;
     a: if null u then if v 
           then rederr "Unequal length lists found in dot product."
                        else return x
         else if null v 
                 then rederr "Unequal length lists found in dot product.";
        x := addsq(multsq(simp car u,simp car v),x);
        u := cdr u;
        v := cdr v;
        go to a
   end;

put('listdot,'listfn,'listdotprod);

put('listdot,'rtype,'list);

infix listdot;

%newtok '((whatever) listdot);

endmodule;

end;
