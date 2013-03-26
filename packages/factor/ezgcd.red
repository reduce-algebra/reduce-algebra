module ezgcd;  % Header module for ezgcd package.

% Authors: A. C. Norman and P. M. A. Moore.

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


create!-package('(ezgcd alphas coeffts ezgcdf facmisc facstr interfac
                  linmodp mhensfns modpoly multihen unihens),
                '(factor));

fluid '(!*trallfac !*trfac factor!-level factor!-trace!-list);

factor!-level:=0;  % start with a numeric value.

symbolic procedure !*d2n a; if null a then 0 else a;

symbolic procedure adjoin!-term (p,c,r);
   if null c then r else (p .* c) .+ r;

symbolic inline procedure ttab n; spaces(n-posn());

symbolic inline procedure polyzerop u; null u;

symbolic inline procedure didntgo q; null q;

symbolic inline procedure depends!-on!-var(a,v);
  (lambda !#!#a; (not domainp !#!#a) and (mvar !#!#a=v)) a;

symbolic procedure errorf u;
   rerror(ezgcd,1,list("Factorizer error:",u));

inline procedure printstr l; << prin2!* l; terpri!*(nil) >>;

inline procedure printvar v; printstr v;

inline procedure prinvar v; prin2!* v;

% This MUST be an SMACRO not an INLINE because "action" is not
% always to be evaluated.

symbolic smacro procedure factor!-trace action;
   begin scalar stream;
      if !*trallfac or (!*trfac and factor!-level = 1)
        then stream := nil . nil
       else stream := assoc(factor!-level,factor!-trace!-list);
      if stream then <<stream := wrs cdr stream; action; wrs stream>>
   end;

symbolic inline procedure getm2(a,i,j);
   % Store by rows, to ease pivoting process.
   getv(getv(a,i),j);

symbolic inline procedure putm2(a,i,j,v);
   putv(getv(a,i),j,v);

symbolic inline procedure !*f2mod u; u;

symbolic inline procedure !*mod2f u; u;

% A load of access inlines for image sets follow:

accessors get!-image!-set . (get!-chosen!-prime . (get!-image!-lc .
  (get!-image!-mod!-p . (get!-image!-content . (get!-image!-poly .
  (get!-f!-numvec . !_))))));


symbolic inline procedure put!-image!-poly!-and!-content
   (s,imcont,impol);
  list(get!-image!-set s,
       get!-chosen!-prime s,
       get!-image!-lc s,
       get!-image!-mod!-p s,
       imcont,
       impol,
       get!-f!-numvec s);

symbolic procedure printvec(str1,n,str2,v);
<< for i:=1:n do <<
    prin2!* str1;
    prin2!* i;
    prin2!* str2;
    printsf getv(v,i) >>;
   terpri!*(nil) >>;

endmodule;

end;
