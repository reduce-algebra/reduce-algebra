module pasfprint;

revision('pasfprint, "$Id$");

copyright('pasfprint, "(c) 2021 T. Sturm");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

put('pasf, 'rl_pribq, 'pasf_pribq);

switch rlpribqsm;
on1 'rlpribqsm;

asserted procedure pasf_pribq(f: LispPrefixForm): Void;
   % Print bound. We are called from rlprint/rl_pribq(). The variable v has
   % been printed already, and we are currently inside square brackets, where
   % we must print the bound b.
   begin
      if null !*nat then
        return 'failed;
      maprin car f;
      prin2!* " ";
      maprin cadr f;
      prin2!* " ";
      prin2!* "[";
      if !*rlpribqsm then
         maprin pasf_boundsm(caddr f, cadr f)
      else
         maprin caddr f;
      prin2!* "] ";
      prin2!* "(";
      maprin cadddr f;
      prin2!* ")"
   end;

asserted procedure pasf_boundsm(f: LispPrefixForm, v: Kernel): LispPrefixForm;
   begin scalar w, w1, w2, argl;
      if eqcar(f, 'or) then <<
         w := 'or . for each x in cdr f collect pasf_boundsm(x, v);
         return pasf_boundsmTryAbs w
      >>;
      argl := rl_argn f;
      if cddr argl then
         return f;
      w1 := pasf_boundsm1(car argl, v);
      if null w1 then
         return f;
      w2 := pasf_boundsm1(cadr argl, v);
      if null w2 then
         return f;
      if car w1 eq car w2 then
         return f;
      if eqcar(w1, 'ub) then <<
         w := w1;
         w1 := w2;
         w2 := w
      >>;
      w1 := cdr w1;
      w2 := cdr w2;
      if car(w1) neq car(w2) then
         if car(w1) eq 'leq then << % <= v <
            caddr w2 := reval {'plus, caddr w2, {'minus, 1}};
            car w2 := 'leq
         >>
         else << % < v <=
            cadr w1 := reval {'plus, cadr w1, 1};
            car w1 := 'leq
         >>;
      return nconc(w1, {caddr w2})
   end;

asserted procedure pasf_boundsm1(a: LispPrefixForm, v: Kernel): DottedPair;
   begin scalar w, c;
      if car a memq '(geq greaterp) then
         a := {pasf_anegrel car a, {'minus, cadr a}, 0};
      w := sfto_reorder(numr simp cadr a, v);
      if not domainp w and mvar w eq v then
         c := lc w;
      if car a memq '(leq lessp) and c = 1 then
         return 'ub . {car a, v, prepf negf red w};
      if car a memq '(leq lessp) and c = -1 then
         return 'lb . {car a, prepf red w, v}
   end;

asserted procedure pasf_boundsmTryAbs(f: LispPrefixForm): LispPrefixForm;
   begin scalar w, v, r1, r2, l1, l2, u1, u2;
      w := cdr f;
      if cddr w then
         return f;
      if length car w neq 4 or length cadr w neq 4 then
         return f;
      r1 := car car w;
      r2 := car cadr w;
      if r1 neq r2 or r1 eq 'cong then
         return f;
      l1 := numr simp cadr car w;
      v := caddr car w;
      u1 := numr simp cadddr car w;
      l2 := numr simp cadr cadr w;
      u2 := numr simp cadddr cadr w;
      if l1 = u2 and l2 = u1 and l1 = negf u1 and l2 = negf u2 then
         return {r1, {'minus, {'abs, prepf absf l1}}, v, {'abs, prepf absf u1}};
      return f
   end;

put('cong,'prifn,'pasf_pricong);

asserted procedure pasf_pricong(l: LispPrefixForm);
   % Presburger arithmetic standard form print a congruence.
   if null !*nat then
      'failed
   else if !*utf8 then
      pasf_pricongUtf8 l
   else <<
      maprin cadr l;
      prin2!* " ~";
      maprin cadddr l;
      prin2!* "~ ";
      maprin caddr l
   >>;

asserted procedure pasf_pricongUtf8(l: LispPrefixForm);
   if numberp cadddr l then <<
      maprin cadr l;
      prin2!* " ";
      prin2!* intern compress nconc(explode car l,explode cadddr l);
      prin2!* " ";
      maprin caddr l
   >> else <<
      maprin cadr l;
      prin2!* " ";
      prin2!* car l;
      prin2!* " ";
      maprin caddr l;
      prin2!* " mod ";
      maprin cadddr l
   >>;

put('ncong,'prifn,'pasf_princong);

asserted procedure pasf_princong(l: LispPrefixForm);
   % Presburger arithmetic standard form print an incongruence.
   if null !*nat then
      'failed
   else if !*utf8 then
      pasf_pricongUtf8 l
   else <<
      maprin cadr l;
      prin2!* " #";
      maprin cadddr l;
      prin2!* "# ";
      maprin caddr l
   >>;

% Here starts support for Texmacs, the CSL GUI, and for an old PSL GUI once
% used on Windows.

if rl_texmacsp() or 'csl memq lispsystem!* then <<
   put('bex, 'fancy!-functionsymbol, "\bigsqcup ");
   put('ball, 'fancy!-functionsymbol, "\bigsqcap ")
>>;

put('pasf, 'rl_fancy!-pribq, 'pasf_fancy!-pribq);

switch rlpribqlimits;
off1 'rlpribqlimits;

asserted procedure pasf_fancy!-pribq(qf: LispPrefixForm);
   if rl_texmacsp() then
      if !*rlpribqlimits then
         pasf_fancy!-pribq!-texmacs!-limits qf
      else
         pasf_fancy!-pribq!-texmacs!-classic qf
   else
      pasf_fancy!-pribq!-fm qf;

asserted procedure pasf_fancy!-pribq!-fm(qf: LispPrefixForm);
   % Used by the CSL GUI.
   begin scalar v, w;
      v := mkvect 0;
      if null !*nat then
         return 'failed;
      w := fancy!-prefix!-operator car qf;
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-prefix!-operator car qf
      >>;
      fancy!-prin2 " ";
      w := fancy!-maprint!-atom(cadr qf, 0);
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-maprint!-atom(cadr qf, 0)
      >>;
      fancy!-prin2 " ";
      % We abuse vectors, where it would be more appropriate to use
      % fancy!-in!-brackets with square brackets ![, !], but this produced
      % strange results in the CSL GUI.
      if !*rlpribqsm then
         putv(v, 0, pasf_boundsm(caddr qf, cadr qf))
      else
         putv(v, 0, caddr qf);
      w := fancy!-maprint!-atom(v, 0);
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-maprint!-atom(v, 0)
      >>;
      fancy!-prin2 " ";
      w := fancy!-in!-brackets({'fancy!-maprint, mkquote cadddr qf, 0}, '!(, '!));
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-in!-brackets({'fancy!-maprint, mkquote cadddr qf, 0}, '!(, '!))
      >>
   end;

% From here on, everything is for Texmacs.

asserted procedure pasf_fancy!-pribq!-texmacs!-classic(qf: LispPrefixForm);
   begin
      if null !*nat then
         return 'failed;
      fancy!-prefix!-operator car qf;
      fancy!-prin2 " ";
      fancy!-prin2 cadr qf;
      fancy!-prin2 " [";
      if !*rlpribqsm then
         fancy!-maprint(pasf_boundsm(caddr qf, cadr qf), 0)
      else
         fancy!-maprint(caddr qf, 0);
      fancy!-prin2 "] ";
      fancy!-prin2 "(";
      fancy!-maprint(cadddr qf, 0);
      fancy!-prin2 ")"
   end;

asserted procedure pasf_fancy!-pribq!-texmacs!-limits(qf: LispPrefixForm);
   begin
      if null !*nat then return 'failed;
      fancy!-prefix!-operator car qf;
      fancy!-prin2!-underscore();
      fancy!-prin2 "{";
      pasf_fancy!-prib(caddr qf, cadr qf);
      fancy!-prin2 "}";
      fancy!-prin2 "(";
      fancy!-maprint(cadddr qf, 0);
      fancy!-prin2 ")"
   end;

asserted procedure fancy!-prin2!-underscore();
   <<
      fancy!-line!* := '_ . fancy!-line!*;
      fancy!-pos!* := fancy!-pos!* #+ 1;
      if fancy!-pos!* #> 2 #* (linelength nil #+1 ) then overflowed!*:=t;
   >>;

asserted procedure pasf_fancy!-prib(f: LispPrefixForm, v: Kernel);
   <<
      fancy!-prin2 v;
      fancy!-prin2 ":";
      fancy!-prin2 " ";
      if !*rlpribqsm then
         fancy!-maprint(pasf_boundsm(f, v), 0)
      else
         fancy!-maprint(caddr f, 0);
   >>;

if rl_texmacsp() or 'csl memq lispsystem!* then <<
   put('neq,'fancy!-infix!-symbol,"\,\neq\, ");
   put('leq,'fancy!-infix!-symbol,"\,\leq\, ");
   put('geq,'fancy!-infix!-symbol,"\,\geq\, ");
   put('lessp,'fancy!-infix!-symbol,"\,<\, ");
   put('greaterp,'fancy!-infix!-symbol,"\,>\, ")
>>;

put('cong,'fancy!-prifn,'pasf_fancy!-pricong);
put('ncong,'fancy!-prifn,'pasf_fancy!-pricong);

asserted procedure pasf_fancy!-pricong(l: LispPrefixForm);
   % Presburger arithmetic standard form texmacs print a congruence.
   if rl_texmacsp() or 'csl memq lispsystem!* then
      pasf_fancy!-pricong!-texmacs l
   else
      pasf_fancy!-pricong!-fm l;

asserted procedure pasf_fancy!-pricong!-texmacs(l: LispPrefixForm);
   % Presburger arithmetic standard form texmacs print a congruence.
   if null !*nat then
      'failed
   else <<
      maprin cadr l; % lhs
      if car l eq 'cong then
         fancy!-prin2 "\,\equiv"
      else
         fancy!-prin2 "\,\not\equiv";
      fancy!-prin2!-underscore();
      fancy!-prin2 "{";
      maprin cadddr l; % modulus
      fancy!-prin2 "}\,";
      maprin caddr l; % rhs
   >>;

asserted procedure pasf_fancy!-pricong!-fm(l: LispPrefixForm);
   % Presburger arithmetic standard form texmacs print a congruence.
   if null !*nat then
      'failed
   else <<
      maprin cadr l;
      if car l eq 'cong then
         fancy!-special!-symbol(186, 2)
      else
         fancy!-special!-symbol(187, 2);
      maprin caddr l;
      fancy!-prin2 " (";
      maprin cadddr l;
      fancy!-prin2 ")"
   >>;

endmodule;

end;
