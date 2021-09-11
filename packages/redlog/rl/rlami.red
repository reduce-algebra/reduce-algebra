module rlami;
% Reduce logic component algebraic mode interface. Submodule of [redlog].

revision('rlami, "$Id$");

copyright('rlami, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2017 T. Sturm");

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

% LispPrefixForm is specified in assert/assertchkfn.red. A PseudoPrefixForm
% has as its car a tag, which carries relevant information on processing such
% a form. A classical example is the !*sq tag for standard quotients. We use
% here !*fof for first-orderformulas. A MixedPrefixForm is a LispPrefixForm
% possibly containing PseudoPrefixForms as subexpressions.

struct MixedPrefixForm asserted by mixedPrefixFormP;
struct PseudoPrefixForm asserted by pairp;

procedure mixedPrefixFormP(x);
   atom x or pairp x;

asserted procedure rl_mk!*fof(u: Formula): PseudoPrefixForm;
   % Reduce logic make tagged form of first-order formula. Convert u to pseudo
   % Lisp prefix after optional simplification.
   rl_mk!*fof1 rl_csimpl u;

asserted procedure rl_mk!*fof1(u: Formula): PseudoPrefixForm;
   % Reduce logic make tagged form of first-order formula subroutine. Convert
   % u to pseudo Lisp prefix. This is analogous to mk!*sq in alg.red.
   if rl_tvalp u then
      u
   else if eqcar(u, 'equal) then
      rl_prepfof1 u
   else
      '!*fof . rl_cid!* . u . if !*resubs then !*sqvar!* else {nil};

asserted procedure rl_reval(u: MixedPrefixForm, v: ExtraBoolean);
   % Reduce logic reval. Convert u to Lisp prefix if v is non-nil, and to
   % pseudo prefix else.
   if v then rl_prepfof rl_simp1 u else rl_mk!*fof rl_simp1 u;

asserted procedure rl_csimpl(u: Formula): Formula;
   % Conditional simplify.
   if !*rlsimpl and getd 'rl_simpl then
      rl_simpl(u, {}, -1)
   else
      u;

asserted procedure rl_prepfof(f: Formula): LispPrefixForm;
   % prep f (in the sense of prepf, prepsq), after optional simplification.
   rl_prepfof1 rl_csimpl f;

asserted procedure rl_prepfof1(f: Formula): LispPrefixForm;
   % prep f (in the sense of prepf, prepsq).
   begin scalar op, w;
      op := rl_op f;
      if rl_tvalp op then
         return op;
      if rl_quap op then
         return {op, rl_var f, rl_prepfof1 rl_mat f};
      if rl_bquap op then <<
         if null (w := get(car rl_cid!*, 'rl_prepb)) then
            rederr {"current context", rl_usedcname!*, "does not support bounded quantifiers"};
         return {op, rl_var f, apply(w, {rl_b f}), rl_prepfof1 rl_mat f}
      >>;
      if rl_boolp op then
         return op . for each x in rl_argn f collect rl_prepfof1 x;
      % f is an atomic formula
      return apply(get(car rl_cid!*, 'rl_prepat), {f})
   end;

asserted procedure rl_cleanup(u, v: ExtraBoolean);
   % This is bound to the property 'cleanupfn of the rl_service!$ functions
   % that are in turn the psopfn of the corresponding rlservice AM
   % entrypoints. The cleanupfn is used with the evaluation of psopfn in
   % reval1 in alg/reval.red, where it converts - in the right moment - the
   % result of of rl_service!$ to Lisp prefix so that part(rlservice(...), 
   % ...) works properly. However, the final evaluation result is generally
   % pseudo prefix.
   reval1(u, v);

asserted procedure rl_simp(u: MixedPrefixForm): Formula;
   % simp to formula (in the sense of simp to standard quotient), after
   % conditional simplification.
   rl_csimpl rl_simp1 u;

asserted procedure rl_simp1(u: MixedPrefixForm): Formula;
   % simp to formula (in the sense of simp to standard quotient).
   begin scalar w, h;
      if null rl_cid!* then rederr {"select a context"};
      if atom u then
         return rl_simpatom u;
      argnochk u where !*strict_argcount = t;
      if (w := get(car u, 'rl_simpfn)) then
         return if flagp(w, 'full) then apply(w, {u}) else apply(w, {cdr u});
      if (w := get(car u, get(car rl_cid!*, 'simpfnname))) then
         return if flagp(w, 'full) then apply(w, {u}) else apply(w, {cdr u});
      if (w := get(car u, 'psopfn)) then <<
         % u = (replaceby x 1) will return itself via a psopfn equalreplaceby.
         h := apply1(w, cdr u);
         if h neq u then
            return rl_simp1 h
      >>;
      if flagp(car u, 'opfn) then
         return rl_simp1 apply(car u, for each x in cdr u collect reval x);
      if (w := get(car u, 'prepfn2)) then
         return rl_simp1 apply(w, {u});
      h := ioto_form2str car u;
      if (w := get(car u, 'prtch)) then
         h := lto_sconcat {ioto_form2str w, " (", h, ")"};
      redmsg(h, "predicate");
      put(car u, get(car rl_cid!*, 'simpfnname), get(car rl_cid!*, 'simpdefault));
      return rl_simp1(u)
   end;

asserted procedure rl_simpatom(u: Atom): Formula;
   % simp atom to formula.
   begin scalar w;
      if null u then typerr("nil", "logical");
      if numberp u then typerr({"number", u}, "logical");
      if stringp u then typerr({"string", u}, "logical");
      if rl_tvalp u then return u;
      if (w := rl_gettype(u)) then <<
         if w eq 'logical or w eq 'equation or w eq 'scalar then
            return rl_simp1 cadr get(u, 'avalue);
         typerr({w, u}, "logical")
      >>;
      % u is algebraically unbound.
      if boundp u then return rl_simp1 eval u;
      typerr({"unbound id", u}, "logical")
   end;

asserted procedure rl_simpbop(f: MixedPrefixForm): Formula;
   % simp form that starts with a boolean operator.
   rl_mkn(car f, for each x in cdr f collect rl_simp1 x);

asserted procedure rl_simpq(f: MixedPrefixForm): Formula;
   % simp form that starts with a quantifier.
   begin scalar vl, w;
      vl := reval cadr f;
      if eqcar(vl, 'list) then
         vl := cdr vl
      else
         vl := {vl};
      w := rl_simp1 caddr f;
      for each x in reverse vl do <<
         rl_qvarchk x;
         w := rl_mkq(car f, x, w)
      >>;
      flag(vl, 'used!*);
      return w
   end;

asserted procedure rl_simpbq(f: MixedPrefixForm): Formula;
   % simp form that starts with a bounded quantifier.
   begin scalar simpb, x;
      if null (simpb := get(car rl_cid!*, 'rl_simpb)) then
         rederr {"current context", rl_usedcname!*, "does not support bounded quantifiers"};
      x := reval cadr f;
      if not idp x then
         typerr(x, "bounded quantified variable");
      flag({x}, 'used!*);
      return rl_mkbq(car f, x, apply(simpb, {caddr f, x}), rl_simp1 cadddr f)
   end;

asserted procedure rl_qvarchk(v: Any): Void;
   % Syntax-check quantified variable.
   if not sfto_kernelp v or (!*rlbrkcxk and pairp v) then
      typerr(v, "quantified variable");

asserted procedure rl_simp!*fof(u: List): Formula;
   % simp form that starts with !*fof. The leading !*fof has already gone, and
   % u is its argument list of the form (tag, f, !*sqvar!*) where tag is a
   % context tag and f is an already simped formula.
   begin scalar tag, f, w;
      if caddr u then return cadr u;  % !*sqvar!* = T
      tag := car u;
      f := cadr u;
      if tag neq rl_cid!* then <<
         w := rl_set tag where !*msg=nil;
         f := rl_prepfof f;
         rl_set w where !*msg=nil;
         return rl_simp f
      >>;
      return rl_resimp f
   end;

asserted procedure rl_resimp(u: Formula): Formula;
   % Reduce logic resimp.
   begin scalar op, w;
      op := rl_op u;
      if rl_tvalp op then
         return u;
      if rl_quap op then <<
         if (w := rl_gettype(rl_var u)) then
            typerr({w, rl_var u}, "quantified variable");
         rl_qvarchk rl_var u;
         return rl_mkq(op, rl_var u, rl_resimp rl_mat u)
      >>;
      if rl_bquap op then <<
         if (w := rl_gettype(rl_var u)) then
            typerr({w, rl_var u}, "quantified variable");
         rl_qvarchk rl_var u;
         if null (w := get(car rl_cid!*, 'rl_resimpb)) then
            rederr {"current context", rl_usedcname!*, "does not support bounded quantifiers"};
         return rl_mkbq(rl_op u, rl_var u, apply(w, {rl_b u}), rl_resimp rl_mat u)
      >>;
      if rl_boolp op then
         return rl_mkn(op, for each x in rl_argn u collect rl_resimp x);
      return apply(get(car rl_cid!*, 'rl_resimpat), {u})
   end;

asserted procedure rl_gettype(v: Id): Id;
   % Get type. Return type information if present. Handle scalars properly.
   (if w then car w else get(v, 'rtype)) where w = get(v, 'avalue);

asserted procedure rl_lengthlogical(u: MixedPrefixForm): Integer;
   rl_lengthfof rl_simp u;

procedure rl_lengthfof(f: Formula): Integer;
   % First order formula length. Returns the number of top-level constituents
   % of f.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return 1;
      if rl_quap op then
         return 2;
      if rl_bquap op then
         return 3;
      if rl_cxp op then
         return length rl_argn f;
      % f is atomic
      return apply(get(car rl_cid!*, 'rl_lengthat), {f})
   end;

asserted procedure rl_sub!*fof(al: Alist, f: MixedPrefixForm): MixedPrefixForm;
   rl_mk!*fof rl_subfof(al, rl_simp f);


rl_builtin {
   name = mkor, 
   doc = {
      synopsis = {pos = 1, text = "for R mkor E"}, 
      description = "for-loop action for constructing disjunctions", 
      returns = "Any", 
      arg = {pos = 1, name = "R", text = "range specification as documented in Sect.5.4 of the REDUCE manual "}, 
      arg = {pos = 2, name = "E", text = "RLISP expression"}
   }
};

foractions!* := lto_insertq('mkor, foractions!*);

put('mkor, 'initval, '(quote false));

put('mkor, 'bin, 'rl_mkor);

flag('(rl_mkor), 'opfn);

asserted procedure rl_mkor(a: LispPrefixForm, b: LispPrefixForm): LispPrefixForm;
   if !*mode eq 'symbolic then
      rederr "`for ... mkor' invalid in symbolic mode"
   else if null a then
      rederr "empty body in `for ... mkor'"
   else if b eq 'false then
      a
   else <<
      a := if eqcar(a, 'or) then cdr a else {a};
      b := if eqcar(b, 'or) then cdr b else {b};
      'or . nconc(b, a)
   >>;

rl_builtin {
   name = mkand, 
   doc = {
      synopsis = {pos = 1, text = "for R mkand E"}, 
      description = "for-loop action for constructing conjunctions", 
      returns = "Any", 
      arg = {pos = 1, name = "R", text = "range specification as documented in Sect.5.4 of the REDUCE manual "}, 
      arg = {pos = 2, name = "E", text = "RLISP expression"}
   }
};

foractions!* := lto_insertq('mkand, foractions!*);

put('mkand, 'initval, '(quote true));

put('mkand, 'bin, 'rl_mkand);

flag('(rl_mkand), 'opfn);

asserted procedure rl_mkand(a: LispPrefixForm, b: LispPrefixForm): LispPrefixForm;
   if !*mode eq 'symbolic then
      rederr "`for ... mkand' invalid in symbolic mode"
   else if null a then
      rederr "empty body in `for ... mkand'"
   else if b eq 'true then
      a
   else <<
      a := if eqcar(a, 'and) then cdr a else {a};
      b := if eqcar(b, 'and) then cdr b else {b};
      'and . nconc(b, a)
   >>;

endmodule;

end;
