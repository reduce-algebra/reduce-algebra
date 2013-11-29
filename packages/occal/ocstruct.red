module ocstruct;  % Alternate routines for structuring expressions.

% Author: Rainer Schöpf 

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


fluid '(svar svarlis);

global '(varnam!*);

varnam!* := 'temp;

symbolic procedure mystructr u;
   begin scalar scountr,svar,svarlis;
      %SVARLIS is a list of elements of form:
      %(<unreplaced expression> . <newvar> . <replaced exp>);
      scountr :=0;
      svar := varnam!*;
      u := for each el in u collect 
             if eqcar (el, 'setq)
               then list ('setq, cadr el, mystruct!*sq aeval caddr el)
              else mystruct!*sq aeval el;
      svarlis := reversip!* svarlis;
      return append (for each x in svarlis collect
                       list ('setq, cadr x, cddr x),
                     u)
   end;

symbolic procedure mystruct!*sq u;
  if eqcar(u,'!*sq)
    then prepsq(mystructf numr cadr u ./ mystructf denr cadr u)
   else u;


symbolic procedure mystructf u;
   if null u then nil
    else if domainp u
     then 
%       if eqcar (u, '!:rd!:) then if atom cdr u then cdr u else bf2flr u else
           u
    else begin scalar x,y,z;
        x := mvar u;
        if sfp x then if y := assoc(x,svarlis) then x := cadr y
                else x := structk(prepsq!*(mystructf x ./ 1),
                                  structvar(),x)
%         else if not atom x % and not atomlis cdr x
          else if not atom x and not (atom car x and flagp (car x, 'noreplace))
          then if y := assoc(x,svarlis) then x := cadr y
                else x := structk(x,structvar(),x);
        if ldeg u = 1 then return x .** ldeg u .* mystructf lc u .+ mystructf red u;
        z := retimes exchk list (x .** ldeg u);
        if y := assoc(z,svarlis) then x := cadr y
         else x := structk(z, structvar(), z);
        return x .** 1 .* mystructf lc u .+ mystructf red u
     end;

endmodule;

end;

