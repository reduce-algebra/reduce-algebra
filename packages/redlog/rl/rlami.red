% ----------------------------------------------------------------------
% $Id: rlami.red,v 1.47 2007/12/21 22:18:25 zengler Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-2008 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
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

% $Log: rlami.red,v $
% Revision 1.47  2007/12/21 22:18:25  zengler
% Added rl_a2s!-string.
%
% Revision 1.46  2007/12/21 03:58:07  zengler
% Fixed a bug in rl_a2s!-qsatoptions.
%
% Revision 1.45  2007/12/21 00:11:15  zengler
% Added rl_s2a!-qsatoptions and rl_a2s!-qsatoptions for option settings of rlqsat.
%
% Revision 1.44  2007/12/20 15:38:10  sturm
% Moved procedures rl_a2s!-sflist and rl_s2a!-sflistlist from rlsched to rlami.
%
% Revision 1.43  2007/07/10 09:14:35  lasaruk
% Added service pqea for probabilistic quantifier elimination with answers.
%
% Revision 1.42  2007/07/05 06:20:07  lasaruk
% Added a2s!-sf for rational number conversion. Added service pqe.
%
% Revision 1.41  2006/11/25 14:15:32  sturm
% Admit reserved identifiers (pi,i,e) as quantified variables.
%
% Revision 1.40  2006/05/15 21:44:34  sturm
% Some bug fixes for Texmacs printing: Avoid fancy!-prin2 " ".
%
% Revision 1.39  2006/04/09 07:48:36  lasaruk
% Expansion service for answers added
%
% Revision 1.38  2006/03/10 21:57:04  lasaruk
% rlqewa renamed to rlwqea
%
% Revision 1.37  2006/03/07 07:41:02  lasaruk
% weak quantifier elimination with answers service rlqewa added
%
% Revision 1.36  2005/09/26 13:40:54  sturm
% The context tag in Pseudo-Lisp Prefix is a list now (for qqe).
%
% Revision 1.35  2005/04/13 18:11:02  lasaruk
% In the call to bsatp the second variable added
%
% Revision 1.34  2004/08/11 15:18:45  lasaruk
% Test for finite solution set in bounded quantifiers added
%
% Revision 1.33  2003/11/11 15:10:07  sturm
% Modified printing for bounded quantifiers. Do not use various
% symbols for logical and.
%
% Revision 1.32  2003/10/21 15:23:16  gilch
% Added procedure rl_s2a!-ghqe.
%
% Revision 1.31  2003/10/12 19:41:14  sturm
% Introduced rl_texmacs. The test "if get('or,'fancy!-infix!-symbol) = 218"
% does not work in general since Windows does not guarantee to load
% fmprint at startup.
%
% Revision 1.30  2003/10/12 18:26:17  sturm
% Printing for both fmprint and tmprint in pasf now.
% The test is done via "if get('or,'fancy!-infix!-symbol) = 218" for now.
% IBALP printing remains to be adapted.
%
% Revision 1.29  2003/10/12 16:57:04  sturm
% Fixed bug in rl_fancy!-pribq.
%
% Revision 1.28  2003/10/12 16:53:29  sturm
% Texmacs fancy-printing crashed Windows. Substituted fancy procedures
% by less fancy but working ones for now.
%
% Revision 1.27  2003/08/21 14:46:38  seidl
% Fancy printing for bounded quantifiers (for TeXmacs).
%
% Revision 1.26  2003/08/19 09:32:10  seidl
% Added bquap case to rl_lengthfof.
%
% Revision 1.25  2003/04/09 18:25:09  seidl
% Bounded quantifiers now only allowed within PASF context. Augmented
% rl_resimp for bounded quantifiers.
%
% Revision 1.24  2003/03/27 22:55:05  seidl
% Introduced bounded quantifiers. Added rl_simpbq, rl_pribq, modified
% rl_prepfof1.
%
% Revision 1.23  2003/01/29 10:43:43  sturm
% Built clean optional argument interface for rlcad and rlgcad. This was buggy.
%
% Revision 1.22  2003/01/27 11:50:56  sturm
% Fixed a bug in rl_a2s_idlist s.t. it properly handles [nil] now. [nil]
% indicates (in contrast to the empty algebraic list) that there is no
% optional argument present.
%
% Revision 1.21  2003/01/25 11:49:41  sturm
% Changed return value and interface for rlcadporder/ofsf_cadporder and
% rlgcadporder/ofsf_gcadporder. They return a list of variables now.
% s2a conversion is done in the scheduler now. Adapted rlcad/ofsf_cad and
% rlgcad/ofsf_gcad accordingly.
%
% Revision 1.20  2003/01/11 17:58:01  sturm
% Added AM services rlcadporder, rlgcadporder for ofsf.
%
% Revision 1.19  2002/08/23 12:32:01  dolzmann
% Added local quantifier elimination.
%
% Revision 1.18  1999/03/23 09:23:55  dolzmann
% Changed copyright information.
%
% Revision 1.17  1999/03/22 08:07:56  sturm
% Turned error message "select a language" in into "select a context".
%
% Revision 1.16  1999/03/21 13:39:44  dolzmann
% Modified procedure rl_qvarchk: Reserved identifiers are not allowed
% as quantified variables.
%
% Revision 1.15  1997/08/14 10:10:46  sturm
% Renamed rldecdeg to rldecdeg1.
% Added service rldecdeg.
%
% Revision 1.14  1997/08/13 12:45:46  dolzmann
% Added procedure rl_s2a!-decdeg.
%
% Revision 1.13  1997/08/12 17:03:54  sturm
% Fixed fancy printing for Xr and PC versions.
%
% Revision 1.12  1996/10/17 13:52:23  sturm
% Introduced services rlvarl, rlfvarl, and rlbvarl. Renamed cl_varl to
% cl_varl1 for this.
%
% Revision 1.11  1996/10/07 12:03:54  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.10  1996/10/03 16:07:04  sturm
% Modified error message in rl_s2a!-struct.
%
% Revision 1.9  1996/10/01 10:25:18  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.8  1996/09/29 14:21:28  sturm
% Removed switch rlqeans. Introduced service rlqea instead.
% Also introduced corresponding service rlgqea.
%
% Revision 1.7  1996/09/26 11:51:09  dolzmann
% Do not use T as formal parameter.
%
% Revision 1.6  1996/09/05 11:16:48  dolzmann
% Added procedures rl_cleanup, rl_a2s!-id, rl_s2a!-term, and rl_s2a!-struct.
% Renamed procedure rl_a2s!-terml to rl_s2a!-struct.
%
% Revision 1.5  1996/07/02 15:12:28  sturm
% Fixed a bug in length computation.
%
% Revision 1.4  1996/06/05 15:11:25  sturm
% Added procedure rl_sub!*fof.
%
% Revision 1.3  1996/05/21 17:12:34  sturm
% Removed rl_subfof. Substitution code has moved to cl.
%
% Revision 1.2  1996/05/12 08:28:23  sturm
% Added procedures rl_s2a!-gqe and rl_s2a!-atl.
%
% Revision 1.1  1996/03/22 12:18:27  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rl_ami_rcsid!* rl_ami_copyright!*);
   rl_ami_rcsid!* :=
      "$Id: rlami.red,v 1.47 2007/12/21 22:18:25 zengler Exp $";
   rl_ami_copyright!* := "Copyright (c) 1995-2008 by A. Dolzmann and T. Sturm"
>>;


module rlami;
% Reduce logic component algebraic mode interface. Submodule of [redlog].

procedure rl_mk!*fof(u);
   % Reduce logic make tagged form of first-order formula. [u] is a
   % first-order formula. Returns pseudo Lisp prefix of [u]. This is
   % analogous to [mk!*sq] in [alg.red].
   rl_mk!*fof1 rl_csimpl u;

procedure rl_mk!*fof1(u);
   % Reduce logic make tagged form of first-order formula subroutine.
   % [u] is a first-order formula. Returns pseudo Lisp prefix of [u].
   % This is analogous to [mk!*sq] in [alg.red].
   if u eq 'true or u eq 'false then
      mk!*sq simp u
   else if eqcar(u,'equal) then
      rl_prepfof1 u
   else
      '!*fof . rl_cid!* . u . if !*resubs then !*sqvar!* else {nil};

procedure rl_reval(u,v);
   % Reduce logic [reval]. [u] is a formula in some mixed pseudo Lisp
   % prefix form where [car u] is either ['!*fof] or a first-order
   % operator; [v] is bool. Returns Lisp prefix of [u] in case [v] is
   % non-[nil], and pseudo Lisp prefix of [u] else.
   if v then rl_prepfof rl_simp1 u else rl_mk!*fof rl_simp1 u;

procedure rl_csimpl(u);
   % Conditional simplify.
   if !*rlsimpl and getd 'rl_simpl then %???
      rl_simpl(u,{},-1)
   else
      u;

procedure rl_prepfof(f);
   % [prep] first-order with bounded quantifers formula.
   rl_prepfof1 rl_csimpl f;

procedure rl_prepfof1(f);
   % [prep] first-order formula with bounded quantifers subroutine.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
 	 return op;
      if rl_quap op then
	 return {op,rl_var f,rl_prepfof1 rl_mat f};
      if rl_bquap op then
	 return {op,rl_var f,rl_prepfof1 rl_b f,rl_prepfof1 rl_mat f};
      if rl_cxp op then
	 return op . for each x in rl_argn f collect rl_prepfof1 x;
      % [f] is atomic.
      return apply(get(car rl_cid!*,'rl_prepat),{f})
   end;

procedure rl_cleanup(u,v);
   reval1(u,v);

procedure rl_simpa(u);
   % simp an answer structure
   for each a in cdr reval u collect
      {rl_simp cadr a, 
	 for each b in cdaddr a collect
	    rl_simp b, cdr cadddr a};

procedure rl_simp(u);
   % [simp] first-order formula.
   rl_csimpl rl_simp1 u;

procedure rl_simp1(u);
   % Reduce logic [simp]. [u] is (pseudo) Lisp prefix of a formula.
   % Returns the formula encoded by [u].
   begin scalar w;
      if null rl_cid!* then rederr {"select a context"};
      if atom u then
 	 return rl_simpatom u;
      argnochk u;
      if (w := get(car u,'rl_simpfn)) then
 	 return if flagp(w,'full) then apply(w,{u}) else apply(w,{cdr u});
      if (w := get(car u,get(car rl_cid!*,'simpfnname))) then
	 return if flagp(w,'full) then apply(w,{u}) else apply(w,{cdr u});
      if (w := get(car u,'psopfn)) then
 	 return rl_simp1 apply1(w,cdr u);
      if flagp(car u,'opfn) then
	 return rl_simp1 apply(car u,for each x in cdr u collect reval x);
      if (w := get(car u,'prepfn2)) then
 	 return rl_simp1 apply(w,{u});
      rl_redmsg(car u,"predicate");
      put(car u,get(car rl_cid!*,'simpfnname),get(car rl_cid!*,'simpdefault));
      return rl_simp1(u)
   end;

procedure rl_simpatom(u);
   % Reduce logic simp atom. [u] is an atom.
   begin scalar w;
      if null u then typerr("nil","logical");
      if numberp u then typerr({"number",u},"logical");
      if stringp u then typerr({"string",u},"logical");
      if (w := rl_gettype(u)) then <<
	 if w eq 'logical or w eq 'equation or w eq 'scalar then
	    return rl_simp1 cadr get(u,'avalue);
	 typerr({w,u},"logical")
      >>;
      % [u] algebraically unbound.
      if rl_tvalp u then return u;
      if boundp u then return rl_simp1 eval u;
      typerr({"unbound id",u},"logical")
   end;

procedure rl_simpbop(f);
   % Reduce logic simp boolean operator.
   rl_mkn(car f,for each x in cdr f collect rl_simp1 x);

procedure rl_simpq(f);
   % Reduce logic simp quantifier.
   begin scalar vl,w;
      vl := reval cadr f;
      if eqcar(vl,'list) then
	 vl := cdr vl
      else
	 vl := {vl};
      w := rl_simp1 caddr f;
      for each x in reverse vl do <<
      	 rl_qvarchk x;
	 w := rl_mkq(car f,x,w)
      >>;
      flag(vl,'used!*);
      return w
   end;

procedure rl_simpbq(f);
   % Reduce logic simp bounded quantifier. [f] is a list [(Q,x,b,f)]
   % where [Q] is a quantifier, [x] is an id, and [b] and [f] are
   % lisp-prefix. Returns a bounded quantifier headed formula.
   begin scalar x,wb,wf;
      if car rl_cid!* neq 'pasf then
	 rederr "boundend quantifiers only allowed within PASF context";
      x := reval cadr f;
      if not idp x then typerr("not identifer","bounded quantified variable");
      wb := rl_simp1 caddr f;
      %%% test, wether x is the only free variable in [wb].
      wf := rl_simp1 cadddr f;
      % Test, wether the bounded quantifier has a finite solution set.
      % rl_bsatp fails per definition if that is not the case.
      rl_bsatp(wb,x);      
      flag({x},'used!*);
      return rl_mkbq(car f,x,wb,wf)
   end;
      
procedure rl_qvarchk(v);
   % Syntax-check quantified variable.
   if null v then
      typerr("nil","quantified variable")
   else if numberp v then
      typerr({"number",v},"quantified variable")
   else if stringp v then
      typerr({"string",v},"quantified variable")
   else if pairp v then
      typerr({"complex expression",v},"quantified variable");

procedure rl_simp!*fof(u);
   % Reduce logic simp [!*fof] operator. [u] is of the form
   % $([tag],f,[!*sqvar!*])$ where [tag] is a context tag and $f$ is a
   % formula.
   begin scalar tag,f,w;
      if caddr u then return cadr u;  % [!*sqvar!*=T]
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

procedure rl_resimp(u);
   % Reduce logic resimp. [u] is a formula.
   begin scalar op,w;
      op := rl_op u;
      if rl_tvalp op then
	 return u;
      if rl_quap op then <<
      	 if (w := rl_gettype(rl_var u)) then
 	    typerr({w,rl_var u},"quantified variable");
      	 return rl_mkq(op,rl_var u,rl_resimp rl_mat u)
      >>;
      if rl_bquap op then <<
      	 if (w := rl_gettype(rl_var u)) then
 	    typerr({w,rl_var u},"quantified variable");
      	 return rl_mkbq(op,rl_var u,rl_resimp rl_b u,rl_resimp rl_mat u)
      >>;
      if rl_cxp op then
	 return rl_mkn(op,for each x in rl_argn u collect rl_resimp x);
      return apply(get(car rl_cid!*,'rl_resimpat),{u})
   end;

procedure rl_gettype(v);
   % Get type. Return type information if present. Handle scalars
   % properly.
   (if w then car w else get(v,'rtype)) where w = get(v,'avalue);

procedure rl_redmsg(u,v);
   % Reduce msg. [u] is an identifier, [v] is a category which must be
   % "predicate". Ask for declaring [u] predicate.
   if null !*msg or v neq "predicate" then
      nil  % :-)
   else if terminalp() then
      yesp list("Declare",u,v,"?") or error1()
   else
      lprim list(u,"declared",v);

procedure rl_lengthlogical(u);
   rl_lengthfof rl_simp u;

procedure rl_lengthfof(f);
   % First order formula length. [u] is a formula. Returns the number
   % of top-level constituents of [u].
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
      % [f] is atomic.
      return apply(get(car rl_cid!*,'rl_lengthat),{f})
   end;

procedure rl_sub!*fof(al,f);
   rl_mk!*fof rl_subfof(al,rl_simp f);

procedure rl_print!*fof(u);
   maprin reval u;

procedure rl_priq(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      maprin car qf;
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

% procedure rl_pribq(qf);
%    % Print bounded quantifer.
%    begin
%       if null !*nat then return 'failed;
%       maprin car qf; % print quantifier
%       prin2!* " ";
%       maprin cadr qf; % print variable
%       prin2!* " ";
%       prin2!* "(";
%       maprin caddr qf; % print bound
%       if car qf eq 'ball then prin2!* " ==> " else prin2!* " /\ ";
%       maprin cadddr qf; % print matrix
%       prin2!* ")"
%    end;

procedure rl_pribq(qf);
   % Print bounded quantifer.
   begin
      if null !*nat then return
 	 'failed;
      maprin car qf; % print quantifier
      prin2!* " ";
      maprin cadr qf; % print variable
      prin2!* " ";
      prin2!* "[";
      maprin caddr qf; % print bound
      prin2!* "] ";
      prin2!* "(";
      maprin cadddr qf; % print matrix
      prin2!* ")"
   end;

procedure rl_ppriop(f,n);
   if null !*nat or null !*rlbrop or eqn(n,0) then
      'failed
   else <<
      prin2!* "(";
      inprint(car f,get(car f,'infix),cdr f);
      prin2!* ")"
   >>;

procedure rl_fancy!-ppriop(f,n);
   if null !*nat or null !*rlbrop or eqn(n,0) then
      'failed
   else <<
      fancy!-prin2 "(";
      fancy!-inprint(car f,get(car f,'infix),cdr f);
      fancy!-prin2 ")"
   >>;

procedure rl_fancy!-priq(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      fancy!-prefix!-operator car qf;
      if not rl_texmacsp() then fancy!-prin2 " ";
      maprin cadr qf;
      if not rl_texmacsp() then fancy!-prin2 " ";
      if pairp(m := caddr qf) and car m memq '(ex all) then
	 maprin m
      else <<
	 fancy!-prin2 "(";
 	 maprin m;
 	 fancy!-prin2 ")"
      >>
   end;

symbolic procedure fancy!-prin2!-underscore(); % --> fmprint
   <<
      fancy!-line!* := '_ . fancy!-line!*;
      fancy!-pos!* := fancy!-pos!* #+ 1;
      if fancy!-pos!* #> 2 #* (linelength nil #+1 ) then overflowed!*:=t;
   >>;

symbolic procedure rl_fancy!-prib(v,f);
   %   if car f eq 'and then <<
   %      fancy!-prin2 "{";
   %      rl_fancy!-prib1 cdr f;
   %      fancy!-prin2 "}";
   %   >> else
   <<
      fancy!-prin2 v;
      fancy!-prin2 ":";
      maprin f
   >>;

symbolic procedure rl_fancy!-prib1(fl);  
   if cdr fl then <<
      fancy!-prin2 "\stackrel";
      fancy!-prin2 "{";
      fancy!-prin2 "\large{}";
      maprin car fl;
      fancy!-prin2 "}";
      fancy!-prin2 "{";
      rl_fancy!-prib1 cdr fl;
      fancy!-prin2 "}";      
   >> else <<
      fancy!-prin2 "\stackrel";
      fancy!-prin2 "{";
      fancy!-prin2 "\large{}";
      maprin car fl;
      fancy!-prin2 "}";
      fancy!-prin2 "{";
      fancy!-prin2 "}";      
%      fancy!-prin2 "\normalsize{}";
%      maprin car fl
   >>;

switch rlbqlimits;

procedure rl_fancy!-pribq(qf);
   if rl_texmacsp() then
      if !*rlbqlimits then
      	 rl_fancy!-pribq!-texmacs qf
      else
	 rl_fancy!-pribq!-texmacs2 qf
   else
      rl_fancy!-pribq!-fm qf;


procedure rl_fancy!-pribq!-texmacs(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      fancy!-prefix!-operator car qf;
      fancy!-prin2!-underscore();
      fancy!-prin2 "{";
      %maprin caddr qf;
      rl_fancy!-prib(cadr qf,caddr qf);
      fancy!-prin2 "}";
      if pairp(m := cadddr qf) and car m memq '(ex all bex ball) then
	 maprin m
      else <<
	 fancy!-prin2 "(";
 	 maprin m;
 	 fancy!-prin2 ")"
      >>
   end;

procedure rl_fancy!-pribq!-texmacs2(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      fancy!-prefix!-operator car qf;
      fancy!-prin2 cadr qf;
      fancy!-prin2 "[";
      maprin caddr qf;
      fancy!-prin2 "]";
      if pairp(m := cadddr qf) and car m memq '(ex all bex ball) then
	 maprin m
      else <<
	 fancy!-prin2 "(";
 	 maprin m;
 	 fancy!-prin2 ")"
      >>
   end;

procedure rl_fancy!-pribq!-fm(qf);
   if null !*nat then
      'failed
   else
   <<
      fancy!-prefix!-operator car qf;
      fancy!-prin2 " ";
      maprin cadr qf;
      fancy!-prin2 " ";
      fancy!-prin2 "[";
      maprin caddr qf; % print bound
      fancy!-prin2 "]";
      fancy!-prin2 " (";
      maprin cadddr qf; % print matrix
      fancy!-prin2 ")"
   >>;

procedure rl_interf1(fname,evalfnl,oevalfnl,odefl,resconv,argl);
   begin integer l1,l2,l3; scalar w;
      if null eval intern compress nconc(explode fname,'(!! !*)) then
	 rederr {"service",fname,"not implemented in context",rl_cid!*};
      l1 := length argl;
      l2 := length evalfnl;
      l3 := length oevalfnl;
      if l1 < l2 or l1 > l2 + l3 then
      	 rederr {fname,"called with",l1,"arguments instead of",l2,"-",l2+l3};
      argl := for each x in append(evalfnl,oevalfnl) collect <<
	 if argl then <<
	    w := car argl;
	    argl := cdr argl
	 >> else
	    w := car odefl;
	 if l2 = 0 then  % evaluation of optional parameters
	    odefl := cdr odefl
	 else
	    l2 := l2 - 1;
	 apply(x,{w})
      >>;
      if !*rlrealtime then ioto_realtime();
      w := apply(resconv,{apply(fname,argl)});
      if !*rlrealtime then ioto_tprin2t {"Realtime: ",ioto_realtime()," s"};
      return w
   end;

procedure rl_a2s!-decdeg1(u);
   if u eq 'fvarl then 'fvarl else rl_a2s!-varl u;

procedure rl_a2s!-varl(l);
   begin scalar w;
      w := reval l;
      if not eqcar(w,'list) then typerr(w,"list");
      w := cdr w;
      for each x in w do
	 if not idp x then typerr(x,"variable");
      return w
   end;

procedure rl_a2s!-number(n);
   % Algebraic to symbolic number.
   begin
      n := reval n;
      if not numberp n then typerr(n,"number");
      return n
   end;

procedure rl_a2s!-sf(n);
   % Algebraic to symbolic standard form.
   begin
      n := simp reval n;
      % if not numberp n then typerr(n,"number");
      return n
   end;

procedure rl_a2s!-id(k);
   % Algebraic to symbolic identifier
   begin
      k := reval k;
      if not idp k then typerr(k,"identifier");
      return k
   end;

procedure rl_a2s!-atl(l);
   % Algebraic to symbolic atomic formula list.
   begin scalar w,!*rlsimpl;
      l := reval l;
      if not eqcar(l,'list) then
 	 typerr(l,"list");
      return for each x in cdr l collect <<
	 if rl_cxp rl_op (w := rl_simp x) then
	    typerr(x,"atomic formula");
      	 w
      >>
   end;

procedure rl_a2s!-posf(f);
   % Algebraic to symbolic positive formula.
   rl_nnf rl_simp f;

procedure rl_s2a!-simpl(f);
   if f eq 'inctheo then rederr "inconsistent theory" else rl_mk!*fof f;

procedure rl_s2a!-gqe(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      {'list,rl_s2a!-atl car res,rl_mk!*fof cdr res};

procedure rl_s2a!-gqea(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      {'list,rl_s2a!-atl car res,rl_s2a!-qea cdr res};

procedure rl_s2a!-qea(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      'list . for each x in res collect
 	 {'list,rl_mk!*fof car x,'list . cadr x};

procedure rl_s2a!-wqea(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      'list . for each x in res collect
 	 {'list,rl_mk!*fof car x,'list . 
	    for each f in cadr x collect
	       rl_mk!*fof f,'list . caddr x};

procedure rl_s2a!-opt(res);
   if res eq 'infeasible then
      'infeasible
   else
      {'list,mk!*sq car res,'list . for each x in cadr res collect 'list . x};

procedure rl_s2a!-atl(l);
   'list . for each x in l collect rl_mk!*fof x;

procedure rl_s2a!-ml(ml,s2acar);
   'list . for each p in ml collect {'list,apply(s2acar,{car p}),cdr p};

procedure rl_s2a!-term(u);
   apply(get(car rl_cid!*,'rl_prepterm),{u});

procedure rl_s2a!-decdeg1(p);
   begin scalar w;
      w := if cdr p then
	 for each x in cdr p collect {'list,car x,cdr x}
      else
	 nil;
      return {'list,rl_mk!*fof car p,'list . w}
   end;

procedure rl_a2s!-targfn(x);
   begin scalar w;
      w := simp x;
      if not domainp denr w then
      	 rederr {"variable in target function denominator"};
      return w
   end;

procedure rl_a2s!-terml(l);
   begin scalar w;
      w := reval l;
      if not eqcar(w,'list) then
         typerr(l,"list");
      return for each x in cdr w collect
         apply(get(car rl_cid!*,'rl_simpterm),{x})
   end;

procedure rl_s2a!-terml(l);
   'list . for each u in l collect apply(get(car rl_cid!*,'rl_prepterm),{u});

procedure rl_a2s!-term(l);
   apply(get(car rl_cid!*,'rl_simpterm),{l});

procedure rl_s2a!-varl(pr);
   {'list,'list . car pr,'list . cdr pr};

procedure rl_s2a!-fbvarl(l);
   'list . l;

procedure rl_s2a!-struct(l);
   <<
      for each x in cdr l do
	 if get(cdr x,'avalue) then
	    rederr {"identifier",cdr x,"has an avalue"};
      {'list, rl_mk!*fof car l,
      	 'list . for each x in cdr l collect
      	    {'equal,cdr x,prepf car x}}
   >>;

procedure rl_a2s!-pt(u);
   for each x in cdr reval u collect
      cadr x . caddr x;

procedure rl_s2a!-idlist(l);
   'list . l;

procedure rl_a2s!-idlist(u);
   begin scalar w;
      w := reval u;
      if not eqcar(w,'list) then
         typerr(w,"list");
      w := cdr w;
      for each x in w do
	 if not idp x then
	    typerr(x,"identifier");
      return w
   end;

procedure rl_s2a!-qsatoptions(l);
   'list . l;

procedure rl_a2s!-qsatoptions(u);
   begin scalar w,temp;
      w := reval u;
      if not eqcar(w,'list) then
         typerr(w,"list");
      w := cdr w;
      if w then <<
      	 temp := car w;
      	 if not (temp = 'zmom or temp = 'activity or temp = 'dlcs) then
 	    typerr(temp,"allowed heuristics (zmom, activity, dlcs)");
      	 temp := cadr w;
      	 if not numberp temp then
	    typerr(temp,"number");
      	 temp := caddr w;
      	 if not (eqn(temp,0) or eqn(temp,1)) then
	    typerr(temp,"0 or 1");
      	 temp := cadddr w;
      	 if not numberp temp then
	    typerr(temp,"number");
      	 temp := car cddddr w;
      	 if not numberp temp then
	    typerr(temp,"number");
      >>;
      return w
   end;

procedure rl_a2s!-string(s);
   if not stringp s then
      typerr(s,"string")
   else
      s;
      
procedure rl_s2a!-ghqe(l);
   % Generic elimination result for algebraic mode. [l] is a lis of
   % the form $(theo res)$. Returns a list of the form $(theo res)$,
   % where $theo$ is a theory and $res$ a quantifier-free formula.
   'list . {rl_mk!*fof car l, rl_mk!*fof cadr l};

procedure rl_a2s!-sflist(pl);
   for each p in cdr pl collect numr simp p;

procedure rl_s2a!-sflistlist(sfll);
   % . [sfll] is a list of list of SF.
   begin scalar fl,f;
      return 'list . for each fl in sfll collect
	 'list . for each f in fl collect prepf f
   end;

foractions!* := 'mkand . 'mkor . foractions!*;
deflist('((mkand rlmkand) (mkor rlmkor)),'bin);
deflist('((mkand (quote true)) (mkor (quote false))),'initval);

symbolic operator rlmkor,rlmkand;

procedure rlmkor(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkor' invalid in symbolic mode"
   else <<
      if null a then a := 'false;
      if null b then b := 'false;
      a := if eqcar(a,'or) then cdr a else {a};
      b := if eqcar(b,'or) then cdr b else {b};
      'or . nconc(b,a)
   >>;

procedure rlmkand(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkand' invalid in symbolic mode"
   else <<
      if null a then a := 'true;
      if null b then b := 'true;
      a := if eqcar(a,'and) then cdr a else {a};
      b := if eqcar(b,'and) then cdr b else {b};
      'and . nconc(b,a)
   >>;

endmodule;  % [rlami]

end;  % of file
