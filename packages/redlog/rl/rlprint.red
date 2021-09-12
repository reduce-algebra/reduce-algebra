module rlprint;
% Reduce logic package printing of algebraic mode output.

revision('rlprint, "$Id$");

copyright('rlprint, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2017-2021 T. Sturm");

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

struct MixedPrefixForm asserted by mixedPrefixFormP;
struct PseudoPrefixForm asserted by pairp;

put('!*fof, 'prifn, 'rl_print!*fof);

asserted procedure rl_print!*fof(u: PseudoPrefixForm);
   maprin reval u;

put('and, 'pprifn, 'rl_ppriop);
put('or, 'pprifn, 'rl_ppriop);
put('impl, 'pprifn, 'rl_ppriop);
put('repl, 'pprifn, 'rl_ppriop);
put('equiv, 'pprifn, 'rl_ppriop);

asserted procedure rl_ppriop(f: LispPrefixForm, n: Integer);
   % Infix Precedence print for operators and, or, impl, repl, equiv.
   if null !*nat or null !*rlbrop or eqn(n, 0) then
      'failed
   else <<
      prin2!* "(";
      inprint(car f, get(car f, 'infix), cdr f);
      prin2!* ")"
   >>;

put('ex, 'prifn, 'rl_priq);
put('all, 'prifn, 'rl_priq);

asserted procedure rl_priq(qf: LispPrefixForm): Void;
   % Print formula starting with quantifier ex, all.
   begin scalar m;
      if null !*nat then
        return 'failed;
      maprin car qf;
      if not !*utf8 then
         prin2!* " ";
      maprin cadr qf;
      prin2!* " ";
      if pairp(m := caddr qf) and car m memq '(ex all) then
         maprin m
      else <<
         prin2!* "(";
         maprin m;
         prin2!* ")"
      >>
   end;

put('bex, 'prifn, 'rl_pribq);
put('ball, 'prifn, 'rl_pribq);

asserted procedure rl_pribq(qf: LispPrefixForm): Void;
   % Print formula starting with bounded quantifer bex, ball.
   begin scalar w;
      if null (w := get(car rl_cid!*, 'rl_pribq)) then
         rederr {"current context", rl_usedcname!*, "does not support bounded quantifiers"};
      apply(w, {qf})
   end;

% Here starts support for Texmacs, the CSL GUI, and for an old PSL GUI once
% used on Windows.

asserted procedure rl_texmacsp(): Boolean;
   % Texmacs predicate. Returns t iff Texmacs is running.
   if getenv("TEXMACS_REDUCE_PATH") then t;

if rl_texmacsp() or 'csl memq lispsystem!* then <<
   put('and, 'fancy!-infix!-symbol, "\,\wedge\, ");
   put('or, 'fancy!-infix!-symbol, "\,\vee\, ");
   put('impl, 'fancy!-infix!-symbol, "\,\longrightarrow\, ");
   put('repl, 'fancy!-infix!-symbol, "\,\longleftarrow\, ");
   put('equiv, 'fancy!-infix!-symbol, "\,\longleftrightarrow\, ");
   put('ex, 'fancy!-functionsymbol, "\exists ");
   put('all, 'fancy!-functionsymbol, "\forall ")
>> else <<
   put('impl, 'fancy!-infix!-symbol, 222);
   put('repl, 'fancy!-infix!-symbol, 220);
   put('equiv, 'fancy!-infix!-symbol, 219);
   put('ex, 'fancy!-functionsymbol, 36);
   put('all, 'fancy!-functionsymbol, 34)
>>;

put('!*fof, 'fancy!-setprifn, 'rl_setprint!*fof);

asserted procedure rl_setprint!*fof(x: Kernel, u: LispPrefixForm);
   % Print assignment of a formula to a variable.
   <<
      fancy!-maprint(x, 0);
      fancy!-prin2!*(":=", 4);
      rl_print!*fof u
   >>;

put('!*fof, 'fancy!-prifn, 'rl_print!*fof);

% procedure rl_print!*fof is defined above.

put('and, 'fancy!-pprifn, 'rl_fancy!-ppriop);
put('or, 'fancy!-pprifn, 'rl_fancy!-ppriop);

asserted procedure rl_fancy!-ppriop(f: LispPrefixForm, n: Integer);
   <<
      if null !*nat or null !*rlbrop or eqn(n, 0) then
         'failed
      else if !*rlbrop then
         fancy!-in!-brackets(
            {'fancy!-inprint, mkquote car f, n, mkquote cdr f}, '!(, '!))
      else
         fancy!-inprint(car f, n, cdr f)
   >>;

put('ex, 'fancy!-prifn, 'rl_fancy!-priq);
put('all, 'fancy!-prifn, 'rl_fancy!-priq);

asserted procedure rl_fancy!-priq(qf: LispPrefixForm);
   begin scalar m, w;
      if null !*nat then
         return 'failed;
      w := fancy!-prefix!-operator car qf;
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-prefix!-operator car qf
      >>;
      w := fancy!-maprint!-atom(cadr qf, 0);
      if w eq 'failed then <<
         fancy!-terpri!* t;
         fancy!-maprint!-atom(cadr qf, 0)
      >>;
      if pairp(m := caddr qf) and car m memq '(ex all) then
         return rl_fancy!-priq m;
      w := fancy!-in!-brackets({'fancy!-maprint, mkquote m, 0}, '!(, '!));
      if w eq 'failed then <<
         fancy!-terpri!* t;
         return fancy!-in!-brackets({'fancy!-maprint, mkquote m, 0}, '!(, '!))
      >>
   end;

put('bex, 'fancy!-prifn, 'rl_fancy!-pribq);
put('ball, 'fancy!-prifn, 'rl_fancy!-pribq);

asserted procedure rl_fancy!-pribq(qf: LispPrefixForm);
   % Fancy-print formula starting with bounded quantifer bex, ball.
   begin scalar w;
      if null (w := get(car rl_cid!*, 'rl_fancy!-pribq)) then
         rederr {"current context", rl_usedcname!*, "does not support bounded quantifiers"};
      apply(w, {qf})
   end;

endmodule;

end;
