module rlprint;  % Reduce logic component printing.

revision('rlprint, "$Id$");

copyright('rlprint, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2017 T. Sturm");

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

asserted procedure rl_texmacsp(): Boolean;
   % Texmacs predicate. Returns [t] iff Texmacs is running.
   if getenv("TEXMACS_REDUCE_PATH") then t;

put('!*fof,'prifn,'rl_print!*fof);
put('!*fof,'fancy!-prifn,'rl_print!*fof);
put('!*fof,'fancy!-setprifn,'rl_setprint!*fof);
%put('!*fof,'prifn,'prin2!*);

put('and,'pprifn,'rl_ppriop);
put('and,'fancy!-pprifn,'rl_fancy!-ppriop);
if rl_texmacsp() then put('and,'fancy!-infix!-symbol,"\,\wedge\, ");

put('or,'pprifn,'rl_ppriop);
put('or,'fancy!-pprifn,'rl_fancy!-ppriop);
if rl_texmacsp() then put('or,'fancy!-infix!-symbol,"\,\vee\, ");

put('impl,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('impl,'fancy!-infix!-symbol,"\,\longrightarrow\, ")
else
   put('impl,'fancy!-infix!-symbol,222);

put('repl,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('repl,'fancy!-infix!-symbol,"\,\longleftarrow\, ")
else
   put('repl,'fancy!-infix!-symbol,220);

put('equiv,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('equiv,'fancy!-infix!-symbol,"\,\longleftrightarrow\, ")
else
   put('equiv,'fancy!-infix!-symbol,219);

put('ex,'prifn,'rl_priq);
put('ex,'fancy!-prifn,'rl_fancy!-priq);
if rl_texmacsp() then
   put('ex,'fancy!-functionsymbol,"\exists ")
else
   put('ex,'fancy!-functionsymbol,36);

put('all,'prifn,'rl_priq);
put('all,'fancy!-prifn,'rl_fancy!-priq);
if rl_texmacsp() then
   put('all,'fancy!-functionsymbol,"\forall ")
else
   put('all,'fancy!-functionsymbol,34);

put('bex,'prifn,'rl_pribq);
put('bex,'rl_prepfn,'rl_prepbq); % semms not to be used!
%put('bex,'fancy!-functionsymbol,36);
put('bex,'fancy!-prifn,'rl_fancy!-pribq);
if rl_texmacsp() then
   put('bex,'fancy!-functionsymbol,"\bigsqcup ")
else
   put('bex,'fancy!-functionsymbol,36); %%% 36 okay?

put('ball,'prifn,'rl_pribq);
%put('ball,'fancy!-functionsymbol,34);
put('ball,'fancy!-prifn,'rl_fancy!-pribq);
if rl_texmacsp() then
   put('ball,'fancy!-functionsymbol,"\bigsqcap ")
else
   put('ball,'fancy!-functionsymbol,34); %%% 34 okay?

procedure rl_print!*fof(u);
   maprin reval u;

procedure rl_setprint!*fof(x,u);
   <<
      fancy!-maprint(x,0);
      fancy!-prin2!*(":=",4);
      rl_print!*fof u
   >>;

procedure rl_priq(qf);
   begin scalar m;
      if null !*nat then return 'failed;
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
      rl_pribound(cadr qf,caddr qf); % print bound
      prin2!* "] ";
      prin2!* "(";
      maprin cadddr qf; % print matrix
      prin2!* ")"
   end;

switch rlsmprint;
on1 'rlsmprint;

procedure rl_pribound(v,f);
   maprin rl_fancybound(v,f);

procedure rl_fancybound(v,f);
   begin scalar w,w1,w2,argl;
      if null !*rlsmprint then
	 return f;
      if eqcar(f,'or) then <<
	 w := 'or . for each x in cdr f collect rl_fancybound(v,x);
	 return rl_fancybound!-try!-abs w
      >>;
      argl := rl_argn f;
      if cddr argl then
	 return f;
      w1 := rl_fancybound1(v,car argl);
      if null w1 then
	 return f;
      w2 := rl_fancybound1(v,cadr argl);
      if null w2 then
	 return f;
      if car w1 eq car w2 then
	 return f;
      if eqcar(w1,'ub) then <<
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
      return nconc(w1,{caddr w2})
   end;

procedure rl_fancybound1(v,a);
   begin scalar w,c;
      if car a memq '(geq greaterp) then
	 a := {pasf_anegrel car a,{'minus,cadr a},0};
      w := sfto_reorder(numr simp cadr a,v);
      if not domainp w and mvar w eq v then
	 c := lc w;
      if car a memq '(leq lessp) and c = 1 then
      	 return 'ub . {car a,v,prepf negf red w};
      if car a memq '(leq lessp) and c = -1 then
      	 return 'lb . {car a,prepf red w,v}
   end;

procedure rl_fancybound!-try!-abs(f);
   begin scalar w,v,r1,r2,l1,l2,u1,u2;
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
	 return {r1,{'minus,{'abs,prepf absf l1}},v,{'abs,prepf absf u1}};
      return f
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
   <<
      if null !*nat or null !*rlbrop or eqn(n,0) then
	 'failed
      else if !*rlbrop then
	 fancy!-in!-brackets(
	    {'fancy!-inprint,mkquote car f,n,mkquote cdr f},'!(,'!))
      else
	 fancy!-inprint(car f,n,cdr f)
   >>;

procedure rl_fancy!-priq(qf);
   begin scalar m,w;
      if null !*nat then
	 return 'failed;
      w := fancy!-prefix!-operator car qf;
      if w eq 'failed then <<
	 fancy!-terpri!* t;
	 fancy!-prefix!-operator car qf
      >>;
      w := fancy!-maprint!-atom(cadr qf,0);
      if w eq 'failed then <<
	 fancy!-terpri!* t;
	 fancy!-maprint!-atom(cadr qf,0)
      >>;
      if pairp(m := caddr qf) and car m memq '(ex all) then
	 return rl_fancy!-priq m;
      w := fancy!-in!-brackets({'fancy!-maprint,mkquote m,0},'!(,'!));
      if w eq 'failed then <<
	 fancy!-terpri!* t;
      	 return fancy!-in!-brackets({'fancy!-maprint,mkquote m,0},'!(,'!))
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

endmodule;

end;
