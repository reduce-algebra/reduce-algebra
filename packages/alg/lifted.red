module lifted;   % Functions previously defined in multiple modules

% Author: Anthony C. Hearn.

% Copyright (c) 1999 Anthony C. Hearn.  All rights reserved.

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

% In earlier versions of Reduce there were various functions where the
% definition were replicated in several places. When these are pure
% duplicates it seems good to lift the definitions to here so that they
% are included just once. So some of the functions defined here may be
% a little specialist and not used in very many places. Others might have
% ended up in the rtools package but are here because they are used by the
% parser (etc) before that module gets built.

symbolic inline procedure revpr u;
   cdr u . car u;

symbolic procedure carx(u,v);
   if not null u and null cdr u then car u
    else rerror(alg,5,list("Wrong number of arguments to",v));

symbolic procedure nlist(u,n);
   if n=0 then nil else u . nlist(u,n-1);

symbolic procedure mapcons(u,v);
   for each j in u collect v . j;

symbolic procedure mappend(u,v);
   for each j in u collect append(v,j);

symbolic procedure smemqlp(u,v);
   %True if any member of id list U is contained at any level
   %in V (exclusive of quoted expressions);
   if null v or numberp v then nil
    else if atom v then v memq u
    else if car v eq 'quote then nil
    else smemqlp(u,car v) or smemqlp(u,cdr v);

symbolic inline procedure !*k2pf u;
   u .* (1 ./ 1) .+ nil;

symbolic inline procedure negpf u;
   multpfsq(u,(-1) ./ 1);

symbolic inline procedure lowerind u;
   list('minus,u);

% The next two are from excalc.

symbolic inline procedure get!*fdeg u;
   (if x then car x else nil) where x = get(u,'fdegree);

symbolic inline procedure get!*ifdeg u;
   (if x then cdr x else nil)
    where x = assoc(length cdr u,get(car u,'ifdegree));

% The next is from fmprint.red/tmprint.red. I rather suspect that fmprint.red
% should be discarded in favour of tmprint.red since they are really the same
% code... but until that happens I will try a little tidy-up job here.

symbolic macro procedure fancy!-level u;
 % unwind-protect for special output functions.
  {'prog,'(pos tpos fl w),
      '(setq pos fancy!-pos!*),
      '(setq tpos fancy!-texpos),
      '(setq fl fancy!-line!*),
      {'setq,'w,cadr u},
      '(cond ((eq w 'failed)
              (setq fancy!-line!* fl)
              (setq fancy!-texpos tpos)
              (setq fancy!-pos!* pos))),
       '(return w)};

symbolic inline procedure add!+vector!+to!+list(vector1, vectorlist);
% returns a list of vectors consisting of vectorlist with vector1
% added at the end. Used in symmetry and linalg packages.
   append(vectorlist, list vector1);

symbolic procedure adomainp u;
 % numberp test in an algebraic form.
   numberp u or (pairp u and idp car u and get(car u,'dname))
             or eqcar(u,'minus) and adomainp cadr u;

symbolic procedure adomainpx(u,num);
  % extended algebraic domainp test:
  % num = t: u is a domain element;
  % num = inf: u is a domain element or inf or (minus inf)
  % num = nil: u is arbitrary.
    null num or adomainp u or num='infinity
                and member(u,'(infinity (minus infinity)));

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if adomainpx(car l,num) and adomainpx(cadr l,num) then return l;
    typerr(u,"numeric interval");
  end;

endmodule;

end;
