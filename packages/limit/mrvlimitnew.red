%----------------------------------------------------------------------------
%                                                                           |
% A new Exp-Log limits package in REDUCE                                    |
%                                                                           |
% Author: Neil Langmead                                                     |
% Place:  ZIB, Berlin                                                       |
% Date:   April 1997                                                        |
% e/mail: langmead@zib.de                                                   |
%                                                                           |
% some cleanup and a minor fix by WN 14 Dec 2005                            |
% major rewrite by RMS in 2022/2023                                         |
%----------------------------------------------------------------------------

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

% $Id: mrvlimit.red 5874 2021-07-30 21:08:56Z arthurcnorman $

module mrvlimit;
create!-package ('(mrvlimit expon),nil);

fluid '(!*trlimit); % for the tracing facility)

fluid '(!*mrv!-recursion!-level!*);

global '(erfg!*);

share !*mrv!-recursion!-level!*;

!*mrv!-recursion!-level!* := 0;

switch trlimit=off;			% off by default

load_package limits;
load_package sets;

symbolic inline procedure mrv_constantp(f,x);
   % This procedure returns true if f does not depend on variable x
   constant_exprp f or f freeof x;


symbolic procedure mrv_maxi(f,g,var);
   if mrv_constantp(f,var) then g
   else if mrv_constantp(g,var) then f
   else if f=g then f
      %% if the following condition is true, there is at least one
      %% common element in f and g, ie. they are in the same
      %% compatibility class
   else if not null intersection(f,g) then union(f,g)
      %% At this point f and g are non-empty and have no common element
   else mrv_compare(f,g,var);

 %max
%-------------------------------------------------------------------------

algebraic
procedure mrv_maxi1(f,g);  lisp('list . mrv_maxi(cdr f,cdr g,'x));

symbolic procedure mrv!-compute!-loglim(f,g,var);
   %% compute limit(log(f)/log(g),var,infinity);
   begin scalar !*expandlogs;
      !*expandlogs := t;
      if eqcar(f,'expt) and cadr f = 'e then f := caddr f else f := {'log,f};
      if eqcar(g,'expt) and cadr g = 'e then g := caddr g else g := {'log,g};
      return mrv!-limit1(reval {'quotient,f,g},var);
   end;
      
symbolic procedure mrv_compare(f,g,var);
   (if s = 0 then g
   else if s member '(infinity (minus infinity)) then f
   else union(f,g)) where s := mrv!-compute!-loglim(car f,car g,var);

symbolic operator mrv_compare;


symbolic procedure mrv!-logsimp exptterm;
   % exptterm is an expt prefix form
   % simplify (log exptterm)
   if cadr exptterm eq 'e then caddr exptterm
    else {'times,caddr exptterm,{'log,cadr exptterm}};

symbolic procedure mrv!-set(u,var);
   begin scalar li2,op,argl;

   if mrv_constantp(u,var) then return nil
    else if u='(list) then return nil
    else if u=var then return {u};
   if eqcar(u,'!*sq) then u := prepsq cadr u;
   if pairp u then << op := car u; argl := cdr u >>;
   %% These operators of one argument that do not change the compatibility class:
   %% drop the operator
   if op memq '(minus log sqrt)
     then return
       %% Shortcut for common cases of log(x), -x, sqrt(x)
       if first argl = var then {var}
        else if not mrv_constantp(first argl,var) then mrv(first argl,var);
   %% Nary operators times and plus: iterate comparison
   if op memq '(plus times)
     then << %% Drop subexpressions not depending on var
      	     while argl and mrv_constantp(first argl,var) do argl := rest argl;
	     if null argl then return nil;
	     %% Compute compatibility class of 1st subexpression
	     li2 := mrv(first argl,var); argl := rest argl;
	     %% Compute compatibility class of next subexpression and compare
	     while argl do <<
		%% skip constant subexpressions
		if not mrv_constantp(first argl,var)
 		  then li2 :=  mrv_maxi(mrv(first argl,var),li2,var);
		argl := rest argl >>;
	     return li2;
          >>
    else if op eq 'expt
    then return
       %% short cut for the case:    mrv(expt(u,cst)) => mrv(u)
       if mrv_constantp(second argl,var) then mrv(first argl,var)
        else if mrv!-limit1(mrv!-logsimp u,var) member '(infinity (minus infinity))
	 then mrv_maxi({u},mrv(second argl,var),var)
	else mrv_maxi(mrv(first argl,var),mrv(second argl,var),var)
    else if null rest argl		% length argl = 1
    then return mrv(first argl,var)
    else if null cddr argl		% length argl = 2, includes difference and quotient
    then return mrv_maxi(mrv(first argl,var),mrv(second argl,var),var)
    else rerror(mrvlimit,1,"mrv not implemented");
end; % of mrv

symbolic procedure mrv(u,var);
   begin scalar v;
      if !*trlimit then <<
	 prin2!* "Entering mrv("; prin2!* !*mrv!-recursion!-level!*; prin2!* "): ";
	 maprin u; terpri!* t;
      >>;
      v := mrv!-set(u,var);
      if !*trlimit then <<
      	 prin2!* "Mrv set of ";
      	 maprin u; terpri!* t;
      	 prin2!* " is ";
      	 maprin ('list . v); terpri!* t;
      >>;
      return v
   end;

algebraic;

symbolic procedure mrv1(li,var);  'list . mrv(li,var);
flag('(mrv1),'opfn);

fluid '(mrv!-curvar!*);

symbolic procedure mrv!-ordp(a,b);
   length(mrv(a,mrv!-curvar!*)) > length(mrv(b,mrv!-curvar!*));

symbolic inline procedure mrv!-smallest u;
  if atom u then u
   else begin scalar v,lng1,lng2;
      v := car u; lng1 := mrv!-length v;
      for each el in cdr u do
 	 if lng1 > (lng2 := mrv!-length el) then << v := el; lng1 := lng2 >>;
      return v;
   end;
   
symbolic procedure mrv!-rewrite(u,var,omega,w);
   begin scalar mrv!-curvar!*,rlist,g,logg,logw,s;
      mrv!-curvar!* := var;
      omega := sort(omega, function mrv!-ordp);
      %% find the smallest subexpression
      g := mrv!-smallest omega;
      if !*trlimit then <<
      	 prin2!* "In mrv!-rewrite(";
      	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): Rewriting ";
	 maprin u; terpri!* t;
	 prin2!* " omega is "; maprin ('list . omega); terpri!* t;
	 prin2!* "Smallest subexpression is "; maprin g; terpri!* t;
      >>;
      logw := logg := mrv!-logsimp g;
      s := mrv!-sign(logg,var);
      if s=1 then << w := {'expt,w,-1}; logw := {'minus,logw} >>;
      if !*trlimit then <<
      	 prin2!* "In mrv!-rewrite(";
      	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): Sign of ";
	 maprin g; prin2!* " is "; prin2!* s; terpri!* t;
      >>;
      rlist := for each f in omega conc
      	 begin scalar logf,c,wexpt,expt2,repl;
	    logf := mrv!-logsimp f;
	    c := mrv!-leading!-term(reval {'quotient,logf,logg},var,nil);
	    if cadr c neq 0 then rerror(mrvlimit,1,
       	      {"mrv-rewrite: elements must be in the same compatibility class",
		 logf,logg});
	    c := car c; 			% coefficient
	    %% maybe apply reval to the difference as this my be simplified
 	    %% without consequences (Gruntz, section 3.3.2, last sentence)
	    wexpt := if c=1 then w else {'expt,w,c};
	    expt2 := reval {'difference,logf,{'times,c,logg}};
	    repl := f . if expt2=0 then wexpt
 	    else {'times,wexpt,{'expt,'e,expt2}};
	    wexpt := if c=-1 then w else reval {'expt,w,{'minus,c}};
	    expt2 := reval {'difference,{'times,c,logg},logf};
	    return {repl,reval {'expt,f,-1} . if expt2=0 then wexpt
 	    else {'times,wexpt,{'expt,'e,expt2}}}
      	 end;
      if !*trlimit then <<
      	 prin2!* "In mrv!-rewrite(";
      	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): rewriting: ";
	 maprin u; terpri!* t;
	 prin2!* "Replacement list is";
      	 terpri!* t;
      	 for each pp in rlist do
	    << maprin {'replaceby,car pp,cdr pp}; terpri!* t >>;
      >>;
      for each pp in rlist do u := subst(cdr pp,car pp,u);
      if !*trlimit then <<
	 prin2!* "After rewriting: ";
	 maprin u; terpri!* t >>;
      u := subst(logw,{'log,w},u);
      return (u . logw);
   end;
	 

%----------------------------------------------------------------------------
% procedure to determine the leading term of an expression w.r.t. var
% returns a triple (c0, w, e0) for c0*w^e0

symbolic procedure mrv!-expt!-smember(u,v);
   %% checks for u = (expt a b) whether u or u1 = (expt a (minus b))
   %% is a subexpression of v
   smember(u,v) or eqcar(u,'expt) and
      (smember(u1,v) where u1 := {'expt,cadr u,
	 if eqcar(caddr u,'minus) then cadr caddr u else {'minus,caddr u}});

symbolic procedure mrv!-expand!-series(f,w);
   begin scalar s,coeffs;
      if !*trlimit then <<
	 prin2!* "In mrv!-leading!-term(";
 	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): series expansion of ";
      	 maprin f;
      	 terpri!* t;            
      >>;
      s := errorset!*({'simptaylor,mkquote {f,w,0,2}},!*backtrace);
      if atom s then <<
	 if !*trlimit then <<
	    terpri!* t;
	    prin2!* "Error "; prin2!* s; prin2!* " during Taylor expansion of";
	    mathprint f;
	 >>;
	 rerror(mrvlimit,3,{"Error in Taylor expansion"});
	 return list 
      >>
      else if not kernp (s := car s) then <<
	 if !*trlimit then <<
	    terpri!* t;
	    prin2!* "Taylor expansion of";
	    mathprint f;
	    prin2!* "yields unexpected result";
	    printsq s;
	    terpri!* t
	 >>;
	 rerror(mrvlimit,3,{"mrv_limit: Error in Taylor expansion"})>>
      else if !*trlimit then <<
	 prin2!* "In mrv!-leading!-term(";
 	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): series expansion is ";
      	 printsq s;
      	 terpri!* t;
         >>;
%      resetklist('taylor!*, oldklist);
      s := mvar numr s;
      s := cadr s;
      while s and null numr cdr car s do s := cdr s;
      if null s then return {0,0}
	 else return {prepsq cdar s,caaaar s};
      s := aeval {'taylor,f,w,0,4};
      if !*trlimit then <<
	 prin2!* "In mrv!-leading!-term(";
 	 prin2!* !*mrv!-recursion!-level!*; prin2!* "): series expansion is ";
      	 maprin s;
      	 terpri!* t;            
      >>;
      s := taylortostandard s;
%      if eqcar(logw,'minus)
%      then s := subeval({{'equal,cadr logw,{'minus,{'log,w}}},s})
%      	 else s := subeval({{'equal,logw,{'log,w}},s});
      coeffs := coeffeval {s,w};
      return {nth(cdr coeffs,lowpow!*+1),lowpow!*};
   end;

symbolic procedure mrv!-leading!-term(u,var,omega);
   (lambda (result,!*mrv!-recursion!-level!*);
   <<if !*trlimit then <<
      terpri!* t;
      prin2!* "Entering mrv!-leading!-term(";
      prin2!* !*mrv!-recursion!-level!*; prin2!* ") for ";
      maprin u; terpri!* t;
      prin2!* "w.r.t. var "; maprin var; terpri!* t;
      prin2!* "omega = "; maprin ('list . omega); terpri!* t;
   >>;
   result := 
  if mrv_constantp(u,var) then {u,0}
   else begin scalar e0,s,w,f,logw;
      e0 := u;
      omega := for each term in omega conc
	 if mrv!-expt!-smember(term,e0) then {term};
      if null omega then omega := mrv(e0,var);
      if !*trlimit then <<
      	 prin2!* "Omega set of ";
      	 maprin e0;
      	 prin2!* " is ";
	 maprin ('list . omega);
	 terpri!* t;
      >>;
      if var member omega
      then return mrv!-movedown(mrv!-leading!-term(mrv!-moveup(e0,var),var,
	 for each term in omega collect mrv!-moveup(term,var)),var);
      w := gensym();
      f . logw := mrv!-rewrite(e0,var,omega,w);
      return evalletsub({{{'replaceby,{'log,w},logw}},{'mrv!-expand!-series,mkquote f,mkquote w}},nil);
%      if eqcar(logw,'minus)
%      then s := subeval({{'equal,cadr logw,{'minus,{'log,w}}},s})
%      	 else s := subeval({{'equal,logw,{'log,w}},s});
%      coeffs := coeffeval {s,w};
%      return {nth(cdr coeffs,lowpow!*+1),lowpow!*};
   end;
   if !*trlimit then <<
      prin2!* "Exiting mrv!-leading!-term(";
      prin2!* !*mrv!-recursion!-level!*; prin2!* ") with {coeff,exponent}=";
      maprin ('list . result);
      terpri!* t;
   >>;
   result >>
      )
   (0,!*mrv!-recursion!-level!*+1);

symbolic procedure mrv!-simp!-logexp u;
   %% replaces (log (expt e u)) by u
   if atom u then u
   else if car u eq 'log and eqcar(cadr u,'expt) and cadadr u eq 'e
   then caddr cadr u
   else car u . for each arg in cdr u collect mrv!-simp!-logexp arg;

symbolic procedure mrv!-moveup(u,var);
   %   sqchk reval {'sub,{'equal,var,{'expt,'e,var}},u};
   mrv!-simp!-logexp subst({'expt,'e,var},var,u);
   
symbolic procedure mrv!-movedown(u,var);
   for each v in u collect
      sqchk reval {'sub,{'equal,var,{'log,var}},v};
   
symbolic procedure mrv!-sign(u,var);
   if mrv_constantp(u,var) then (sign!-of u or 0)
   else if u=var then 1
   else if eqcar(u,'minus) then (-mrv!-sign(cadr u,var))
   else if eqcar(u,'times) then begin integer p:=1;
      for each fct in cdr u do p := p*mrv!-sign(fct,var);
      return p;
   end
   else if eqcar(u,'expt) then
      if cadr u='e or cadr u=var or sign!-of cadr u = 1 then 1
      else car mrv!-leading!-term(u,var,nil)
   else if eqcar(u,'log) then
      %% For x>0, sign(log(x)) = sign(1+x)
      if sign!-of cadr u = -1 then rerror(mrvlimit,2,"Complex limit")
      else mrv!-sign({'plus,-1,cadr u},var)
   else if eqcar(u,'quotient) then
      (if denom!-sign = 0 then rerror(mrvlimit,2,{"Cannot compute the sign of",u})
        else mrv!-sign(cadr u,var)*denom!-sign)
      	 where denom!-sign := mrv!-sign(caddr u,var)
   else if eqcar(u,'plus) or eqcar(u,'difference)
   then mrv!-sign(car mrv!-leading!-term(u,var,nil),var)
   else rerror(mrvlimit,2,{"Cannot compute the sign of",u});
	    
	 
algebraic;
expr procedure move_up(exp,x);
%sub({log(x)=x,x=e^x},exp);
sub({x=e^x},exp);
expr procedure move_down(exp,x);
sub({x=log(x)},exp);
%sub({e^x=x,x=log(x)},exp);


symbolic procedure mrv!-length u;
   if (u='list) then nil
     else if atom u then 1
     else if atom car u then (1+ mrv!-length cdr u)
     else mrv!-length car u +  mrv!-length cdr u;

algebraic procedure mrv_length u; symbolic(mrv!-length u);

%-------------------------------------------------------------------------

% main routine to compute limits of exp-log functions as the variable tends
% to infinity.

symbolic procedure mrv!-limit1a(u,var);
   %% computes the limit of u as var --> infinity
   if mrv_constantp(u,var) then u
   else begin scalar c0,e0,s,s1;
      {c0,e0} := mrv!-leading!-term(u,var,nil);
      s := mrv!-sign(e0,var);
      if s=0 then return mrv!-limit1(c0,var)
      else if s=1 then return 0
      else if s=-1 then <<
	 s1 := mrv!-sign(c0,var);
	 if s1=1 then return 'infinity
	 else if s1=-1 then return '(minus infinity)
	 else  write "mrv!_limit1a: sign is ", s1;
      >>;
   end;

symbolic procedure mrv!-limit1(u,var);
   << if !*trlimit then <<
      prin2!* "Result of mrv!-limit1 of "; maprin u;
      prin2!* " w.r.t. "; maprin var;
      prin2!* " is "; terpri!* t;
      if null r then prin2!* "nil" else
      maprin r; terpri!* t >>;
   r  >>
      where r := mrv!-limit1a(u,var); 


symbolic procedure mrv_limit(argl);
   if length argl neq 3
      then rederr{"mrv_limit called with wrong number of arguments",argl}
   else begin scalar u,x,x0,r,newvar:= gensym(),
	 !*protfg := not !*backtrace,!*expandlogs := t,!*precise;
      u := reval car argl;
      x := cadr argl;
      x0 := caddr argl;
      if x0='infinity then newvar := x
      else if x0='(minus infinity)
      then u := subeval({{'equal,x,{'minus,newvar}},u})
      else rederr{"mrv_limit: Invalid 3rd argument",x0};
      r := errorset!*({'mrv!-limit1,mkquote u,mkquote newvar},!*backtrace);
      return if errorp r then <<erfg!*:=nil; {'mrv_limit,u,x,x0}>>
      else car r;
   end;

put('mrv_limit,'psopfn,'mrv_limit);
remflag('(mrv_limit),'opfn);


%-----------------------------------------------------------------------------
% for examples, please see the test file included with the documentation. The
% examples labelled from ex1 to ex12 are all taken from Dominik Gruntz' Thesis
% paper. Most are complicated examples, as he himself admits. This package
% does not use the standard limits operator in REDUCE: it has been written to
% COMMENT by WN: only as emergency exit!!
% be independent, and can be presented as a separted facility in REDUCE.

%-----------------------------------------------------------------------------
endmodule;

end;
