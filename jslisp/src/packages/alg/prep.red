module prep; % Functions for converting canon. forms into prefix forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

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


fluid '(!*bool !*intstr);

symbolic procedure prepsqxx u;
   % This is a top level conversion function.  It is not clear if we
   % need prepsqxx, prepsqx, prepsq!* and prepsq, but we keep them all
   % for the time being.
   negnumberchk prepsqx u;

symbolic procedure negnumberchk u;
   if eqcar(u,'minus) and numberp cadr u then - cadr u else u;

symbolic procedure prepsqx u;
   if !*intstr then prepsq!* u else prepsq u;

symbolic procedure prepsq u;
   if null numr u then 0 else sqform(u,function prepf);

symbolic procedure sqform(u,v);
   (lambda (x,y); if y=1 then x else list('quotient,x,y))
      (apply1(v,numr u),apply1(v,denr u));

symbolic procedure prepf u;
   (if null x then 0 else replus x) where x=prepf1(u,nil);

symbolic procedure prepf1(u,v);
   if null u then nil
    else if domainp u then list retimes(prepd u . exchk v)
    else nconc!*(prepf1(lc u,if mvar u eq 'k!* then v else lpow u . v),
                 prepf1(red u,v));

symbolic procedure prepd u;
   if atom u then if u<0 then list('minus,-u) else u
    else if apply1(get(car u,'minusp),u)
%    then list('minus,prepd1 !:minus u)
     then (if null x then 0 else list('minus,x))
          where x=prepd1 !:minus u
%   else if !:onep u then 1
    else apply1(get(car u,'prepfn),u);

symbolic procedure prepd1 u;
   if atom u then u else apply1(get(car u,'prepfn),u);

% symbolic procedure exchk u;
%    begin scalar z;
%       for each j in u do
%          if cdr j=1
%            then if eqcar(car j,'expt) and caddar j = '(quotient 1 2)
%                    then z := list('sqrt,cadar j) .z
%                   else z := sqchk car j . z
%            else z := list('expt,sqchk car j,cdr j) . z;
%       return z
%   end;

symbolic procedure exchk u; exchk1(u,nil,nil,nil);

symbolic procedure exchk1(u,v,w,x);
   % checks forms for kernels in EXPT. U is list of powers.  V is used
   % to build up the final answer. W is an association list of
   % previous non-constant (non foldable) EXPT's, X is an association
   % list of constant (foldable) EXPT arguments.
   if null u then exchk2(append(x,w),v)
    else if eqcar(caar u,'expt)
     then begin scalar y,z;
            y := simpexpon list('times,cdar u,caddar car u);
            if numberp cadaar u   % constant argument
              then <<z := assoc2(y,x);
                     if z then rplaca(z,car z*cadaar u)
                      else x := (cadaar u . y) . x>>
             else <<z := assoc(cadaar u,w);
                    if z then rplacd(z,addsq(y,cdr z))
                     else w := (cadaar u . y) . w>>;
            return exchk1(cdr u,v,w,x)
        end
    else if cdar u=1 then exchk1(cdr u,sqchk caar u . v,w,x)
    else exchk1(cdr u,list('expt,sqchk caar u,cdar u) . v,w,x);

symbolic procedure exchk2(u,v);
   if null u then v
    else exchk2(cdr u,
%               ((if eqcar(x,'quotient) and caddr x = 2
%                  then if cadr x = 1 then list('sqrt,caar u)
%                        else list('expt,list('sqrt,caar u),cadr x)
                ((if x=1 then caar u
                   else if !*nosqrts then list('expt,caar u,x)
                   else if x = '(quotient 1 2) then list('sqrt,caar u)
                   else if x=0.5 then list('sqrt,caar u)
                   else list('expt,caar u,x)) where x = prepsqx cdar u)
                . v);

symbolic procedure assoc2(u,v);
   % Finds key U in second position of terms of V, or returns NIL.
   if null v then nil
    else if u = cdar v then car v
    else assoc2(u,cdr v);

symbolic procedure replus u;
   if null u then 0
    else if atom u then u
    else if null cdr u then car u
    else 'plus . unplus u;

symbolic procedure unplus u;
   if atom u then u
   else if car u = 'plus then unplus cdr u
   else if atom car u or not eqcar(car u,'plus)
      then (car u) . unplus cdr u
   else append(cdar u,unplus cdr u);

% symbolic procedure retimes u;
%    % U is a list of prefix expressions. Value is prefix form for the
%    % product of these;
%    begin scalar bool,x;
%       for each j in u do
%         <<if j=1 then nil     % ONEP
%             else if eqcar(j,'minus)
%              then <<bool := not bool;
%                     if cadr j neq 1 then x := cadr j . x>>     % ONEP
%             else if numberp j and minusp j
%              then <<bool := not bool;
%                    if j neq -1 then x := (-j) . x>>
%             else x := j . x>>;
%        x := if null x then 1
%                else if cdr x then 'times . reverse x else car x;
%        return if bool then list('minus,x) else x
%   end;

symbolic procedure retimes u;
   begin scalar !*bool;
      u := retimes1 u;
      u := if null u then 1
            else if cdr u then 'times . u
            else car u;
      return if !*bool then list('minus,u) else u
   end;

symbolic procedure retimes1 u;
   if null u then nil
    else if car u = 1 then retimes1 cdr u
    else if minusp car u
     then <<!*bool := not !*bool; retimes1((-car u) . cdr u)>>
    else if atom car u then car u . retimes1 cdr u
    else if caar u eq 'minus
     then <<!*bool := not !*bool; retimes1(cadar u . cdr u)>>
    else if caar u eq 'times then retimes1 append(cdar u,cdr u)
    else car u . retimes1 cdr u;

symbolic procedure sqchk u;
   if atom u then u
    else (if x then apply1(x,u) else if atom car u then u else prepf u)
          where x=get(car u,'prepfn2);

put('!*sq,'prepfn2,'prepcadr);

put('expt,'prepfn2,'prepexpt);

symbolic procedure prepcadr u; prepsq cadr u;

symbolic procedure prepexpt u; if caddr u=1 then cadr u else u;

endmodule;

end;
