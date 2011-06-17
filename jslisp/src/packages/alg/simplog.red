xmodule simplog;  % Simplify logarithms.

% Authors: Mary Ann Moore and Arthur C. Norman.

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


fluid '(!*intflag!* !*noneglogs !*expandlogs);

global '(domainlist!*);

exports simplog,simplogi,simplogsq;

imports addf,addsq,comfac,quotf,prepf,mksp,simp!*,!*multsq,simptimes,
        minusf,negf,negsq,mk!*sq,carx,multsq,resimp,simpiden,simpplus,
        prepd,mksq,rerror,zfactor,sfchk;

symbolic procedure simplog u;
   (if !*expandlogs then
     (resimp simplogi x where !*expandlogs=nil)
    else if eqcar(x,'quotient) and cadr x=1
      and (null !*precise or realvaluedp caddr x)
     then negsq simpiden('log . cddr x)
    else simpiden u)
    where x=carx(cdr u,'simplog);

put('log,'simpfn,'simplog);

flag('(log),'full);

put('expandlogs,'simpfg,'((nil (rmsubs)) (t (rmsubs))));

put('combinelogs,'simpfg,'((nil (rmsubs)) (t (rmsubs))));

symbolic procedure simplogi(sq);
   % This version will only expand a log if at most one of the
   % arguments is complex.  Otherwise you can finish up on the wrong
   % sheet.
   if atom sq then simplogsq simp!* sq
    else if car sq memq domainlist!* then simpiden list('log,sq)
    else if car sq eq 'times
          then if null !*precise or one_complexlist cdr sq
           then simpplus(for each u in cdr sq collect mk!*sq simplogi u)
          else !*kk2q {'log,sq}
    else if car sq eq 'quotient
       and (null !*precise or one_complexlist cdr sq)
     then addsq(simplogi cadr sq,negsq simplogi caddr sq)
    else if car sq eq 'expt
     then simptimes list(caddr sq,mk!*sq simplogi cadr sq)
    else if car sq eq 'nthroot
     then multsq!*(1 ./ caddr sq,simplogi cadr sq)
    % we had (nthroot of n).
    else if car sq eq 'sqrt then multsq!*(1 ./ 2,simplogi cadr sq)
    else if car sq = '!*sq then simplogsq cadr sq
    else simplogsq simp!* sq;

symbolic procedure one_complexlist u;
   % True if at most one member of list u is complex.
   if null u then t
    else if realvaluedp car u then one_complexlist cdr u
    else null cdr u or realvaluedlist cdr u;

symbolic procedure multsq!*(u,v);
   if !*intflag!* then !*multsq(u,v) else multsq(u,v);

symbolic procedure simplogsq sq;
   % This procedure needs to be reworked to provide for proper sheet
   % handling.
   if null numr sq then rerror(alg,210,"Log 0 formed")
    else if denr sq=1 and domainp numr sq and !:onep numr sq
     then nil ./ 1
    else if !*precise then !*kk2q {'log,prepsq sq}
    else addsq(simplog2 numr sq,negsq simplog2 denr sq);

symbolic procedure simplog2(sf);
 if atom sf
   then if null sf then rerror(alg,21,"Log 0 formed")
      else if numberp sf
       then if sf iequal 1 then nil ./ 1
             else if sf iequal 0 then rerror(alg,22,"Log 0 formed")
             else simplogn sf
      else formlog(sf)
   else if domainp sf then mksq({'log,prepd sf},1)
     else begin scalar form;
        form := comfac sf;
        if not null car form
          then return addsq(formlog(form .+ nil),
                            simplog2 quotf(sf,form .+ nil));
        % We have killed common powers.
        form := cdr form;
        if form neq 1
          then return addsq(simplog2 form,simplog2 quotf(sf,form));
        % Remove a common factor from the sf.
        return formlog sf
     end;

symbolic procedure simplogn u;
   % See comments in formlog for an explanation of the code.
   begin scalar y,z;
      y := zfactor u;
      if car y= '(-1 . 1) and null(y := mergeminus cdr y)
       then return !*kk2q {'log,u};
      for each x in y do
          z := addf(((mksp({'log,car x},1) .* cdr x) .+ nil),z);
      return z ./ 1
   end;

symbolic procedure mergeminus u;
   begin scalar x;
   a: if null u then return nil
       else if remainder(cdar u,2)=1
        then return nconc(reversip x,((-caar u) . cdar u) . cdr u)
       else <<x := car u . x; u := cdr u; go to a>>
   end;

symbolic procedure formlog sf;
   % Minus test commented out. Otherwise, we can get:
   % log(a) + log(-1) => log(a*(-1)) => log(-a).
   % log(a) - log(-1) => log(a/(-1)) => log(-a).
   % I.e., log(-a) can be log(a) + log(-1) or log(a) - log(-1).
   if null red sf then formlogterm sf
%   else if minusf sf and null !*noneglogs
%    then addf((mksp(list('log,-1),1) .* 1) .+ nil,
%              formlog2 negf sf) ./ 1
    else (formlog2 sf) ./ 1;

symbolic procedure formlogterm(sf);
   begin scalar u;
      u := mvar sf;
      if not atom u and (car u member '(times sqrt expt nthroot))
         then u := addsq(simplog2 lc sf,
                         multsq!*(simplogi u,simp!* ldeg sf))
        else if (lc sf iequal 1) and (ldeg sf iequal 1)
         then u := ((mksp(list('log,sfchk u),1) .* 1) .+ nil) ./ 1
        else u := addsq(simptimes list(list('log,sfchk u),ldeg sf),
                        simplog2 lc sf);
      return u
   end;

symbolic procedure formlog2 sf;
   ((mksp(list('log,prepf sf),1) .* 1) .+ nil);

endmodule;

end;
