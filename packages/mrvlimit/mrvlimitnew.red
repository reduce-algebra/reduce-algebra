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
% all bugs and comments or suggestions please report to Winfried Neun,      |
% ZIB, Takustrasse 7, D-14195, Berlin Dahlem, Germany: e/mail neun@zib.de   |
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

flag('(sqchk),'opfn);

load_package limits;
load_package sets;

symbolic inline procedure mrv_constantp(f,x);
   % This procedure returns true if f does not depend on variable x
   constant_exprp f or f freeof x;


algebraic;
off mcd;

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

algebraic;
procedure mrv_maxi1(f,g);  lisp('list . mrv_maxi(cdr f,cdr g,'x));

algebraic;

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

%procedure comp(f,g); lisp('list.mrv_compare(f,g));

%----------------------------------------------------------------------------
load_package assist;

symbolic procedure mrv!-logsimp exptterm;
   % exptterm is an expt prefix form
   % simplify (log exptterm)
   if cadr exptterm eq 'e then caddr exptterm
    else {'times,caddr exptterm,{'log,cadr exptterm}};

symbolic procedure mrv(u,var);
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
	 rerror(mrvlimit,3,{"Error in Taylor expansion"}) >>
      else if not kernp (s := car s) then <<
	 if !*trlimit then <<
	    terpri!* t;
	    prin2!* "Taylor expansion of";
	    mathprint f;
	    prin2!* "yields unexpected result";
	    printsq s;
	    terpri!* t
	 >>;
	 rerror(mrvlimit,3,{"Error in Taylor expansion"})>>;
%      resetklist('taylor!*, oldklist);
      s := mvar numr s;
      s := cadr s;
      while s and null numr cdr car s do s := cdr s;
      if null s then return {0,0}
	 else return {prepsq cdar s,caaaar s};
      s := aeval {'taylor,f,w,0,4};
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
      prin2!* "Entering mrv!-leading!-term(";
      prin2!* !*mrv!-recursion!-level!*; prin2!* ") for ";
      maprin u; terpri!* t;
      prin2!* "w.r.t. var "; maprin var; terpri!* t;
      prin2!* "Omega set = "; maprin ('list . omega); terpri!* t;
   >>;
   result := 
  if mrv_constantp(u,var) then {u,0}
   else begin scalar e0,s,w,f,logw;
      e0 := u;
      omega := for each term in omega conc
	 if mrv!-expt!-smember(term,e0) then {term};
      if null omega then omega := mrv(e0,var);
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
   then car mrv!-leading!-term(u,var,nil)
   else rerror(mrvlimit,2,{"Cannot compute the sign of",u});
	    
	 
algebraic;
expr procedure move_up(exp,x);
%sub({log(x)=x,x=e^x},exp);
sub({x=e^x},exp);
expr procedure move_down(exp,x);
sub({x=log(x)},exp);
%sub({e^x=x,x=log(x)},exp);

%off mcd;
algebraic;
expr procedure mrv_rewrite(m);
begin scalar ans_list,summ,k,g,c,A;

  ans_list:={};
  g:=part(m,1); write length g;
  for k:=1:arglength(m) do
  <<
    summ:=length(den(part(m,k)))+length(num(part(m,k))); write summ;
    if(summ<(length(den(g))+length(num(g)))) then g:=part(m,k);
  >>;
  write "g is ", g;

  for each f in m do
    <<
      c:=limit(log(f)/log(g),x,infinity);
      A:=e^(log(f)-c*log(g));
      f:=A*w^c;
      ans_list:=append({f}, ans_list);
    >>;
  return ans_list;
end;

procedure mrv_smallest(li);
   %% li is a list of expression of the same compatibility class
   %% return the smallest of them
   << while length li > 1 do begin scalar l1,l2,res;
        l1:=mrv_length(part(li,1));
      	l2:=mrv_length(part(li,2));
      	if (l1>l2) then res := part(li,2) else res := part(li,1);
      	li := res . rest rest li
   end;
   first li >>;

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

algebraic;

expr procedure mrv_limit(f,var,val);
   (lambda (result,!*mrv!-recursion!-level!*);
   <<result := 
begin scalar mrv_f,mrv1_f,w, mrv_f2,tt, lead_term, series_exp,f1, small, rule1,
      const, e0,sig,rule2,k, nu,de,h,recurse;
   integer moveup_flag;
  off mcd; off factor; off rational; off exp; off precise;
  %if(val neq infinity) then return sub(var=val,f);

  % trigonometric expressions aren't dealt with by the algorithm

  if(not(freeof(f,sin))) then rederr "input not an exp log function";
  if(not(freeof(f,cos))) then rederr "input not an exp log function";
  if(not(freeof(f,tan))) then rederr "input not an exp log function";

  if lisp !*trlimit then
     write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "Computing limit of ",f," w.r.t. ",var;
  if(freeof(f,var)) then % possible cases: f can be a number, an expression
                         % independent of var, or possibly not an exp log
                         % function. In all cases, return f as the answer
    return f;
  if(val neq infinity) then return sub(var=val,f);

  %on rational;
  %on rounded;
  %this checks for numbers. red doesn't recognise some objects as numbers unless
  % the rounded switch is on

  f1:=f;
  if(numberp(f1)) then return f;
  off rational;
  off rounded;
  if(var neq x) then f:=sub(var=x,f) else nil;
  if numberp f then return f;
  %%%% special case where f=e, or pi. Don't want to use the on rounded switch
  %%%% in these cases
  if (f=e) then return e;
  if(f=pi) then return pi;
  %if(f=x) then return plus_infinity;
  on factor; off mcd;
  mrv_f:=mrv1(f,var);
  %write "*********************************************************************";
  if(lisp !*trlimit) then
     write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "mrv_f is ", mrv_f;
  lisp if null cdr mrv_f then % emergency exit for now
         return ('limit . list(f,var,val));

  %write "*********************************************************************";
  off factor;
  %on mcd;

  if(member(x,mrv_f)) then
    <<
      off exp; off mcd;
      while(member(x,mrv_f)) do
      <<
          f:=move_up(f,x);
	  if (lisp !*trlimit) then
 	     write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
                   "After move_up, f is ",f;
          %mrv_f:=mrv1(f);
          mrv_f:=for k:=1:arglength(mrv_f) collect move_up(part(mrv_f,k),x);
          %write "mrv is ", mrv_f;
        >>;
      % we know that x was a member of mrv(f), so now, the mrv set will contain
      % e^x at least. Hence, write directly in terms of w=e^(-x)

      small:=e^(-x);
      % now have the smallest element, but don't know its limiting behaviour
      % if lim is infinity, need to set w to 1/small
      rule1:={small => ww };
      let rule1;
      f:=f;
      on mcd; nu:=num(f); de:=den(f); f:=nu/de; off mcd;
      f:=f; % write f;
      clearrules rule1;
      % f now rewritten
    >>
   else <<
           %mrv_f2:=mrv_rewrite(mrv_f); % write "f2 is ", mrv_f2;
                  % now need to rewrite f itself
           small:=mrv_smallest(mrv_f);
	   begin scalar !*expandlogs; lisp(!*expandlogs := t);
	     h:=log(small); 
	     if lisp !*trlimit then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ","h is ", h;
	   end;
 	   % Shortcut for case small = e^(+/-x) -> no need to actually compute the limit
           if h neq (-x) and (h=x or mrv_limit(h,x,infinity)=infinity) then
             <<
                small:=small^-1;
                if lisp(!*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ","small has been changed to ", small;
             >>;

         rule1 := { small => ww, 1/small => ww^-1 };
         %let rule1; 
         off mcd;

	 if lisp (!*trlimit) then
	    write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
            "Substituting: ",rule1, " in expression ",f;
         f := (f where rule1);
	 if lisp (!*trlimit) then 
	    write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "After substitution to ww, f is ",f;
         %on mcd;
         %off mcd; %f:=f;
         %clearrules rule1;

         % now rewritten in terms of w, and mrv(f)=w hopefully
        >>;

  % at this point, f has been rewritten. Now check lcof of series expansion

  % lisp !*mcd:=nil; lisp !*factor:=nil; lisp !*exp:=t; lisp !*rational:=nil;

  off mcd; on factor; off exp; off rational;
  series_exp:=taylor(f,ww,0,1);
  if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "Performing taylor on: ", f;

  %off mcd; on exp; on factor; off rational;
  if(not taylorseriesp series_exp and part(series_exp,0)=taylor)
    then rederr "could not compute the Taylor series expansion";

  tt:=log(small);

  series_exp:=sub(log(ww)=tt,series_exp); %off mcd; off factor; off exp;
  series_exp:=taylortostandard series_exp;
  if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "Series expansion is ", series_exp;
  % should now have the lead term of the series expansion in terms of w
  if numberp(series_exp) then return series_exp
   else <<
      if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "Series is ", series_exp;
          off rational;  off mcd;  off exp; off factor;
          series_exp:=series_exp; off factor;
          const:=coeffn(series_exp,ww,0); %write "const is ", const;
          if(const neq 0) then
            <<
              if(numberp(const)) then return const else
                <<
                   if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "performing recursion on ", const;
                  off mcd; on factor; off exp;  on rational; const:=const;
                  return mrv_limit(const,x,infinity);
                >>;
            >>
           else
            <<
              % need to look at exponent of ww. If e0>0 then return 0, if
              % e0<0 return infinity, if e0=0 return mrv_limit(c)
              %write "series_exp is ", series_exp;
              series_exp:=series_exp; off mcd; % try it here!
              %if(lisp !*trlimit) then
              %write "mrv_limit(",!*mrv!-recursion!-level!*,"): ","series exp is  ", series_exp;
              %  series_exp:=lisp reval series_exp;
              %off mcd;
              e0:=mrv_find_least_expt(series_exp);
              if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ",
           "leading exponent e0 is ", e0;
              off mcd; on factor; off exp; off rational;
              %if(part(e0,1)=expt) then
              %<< e0:=part(e0,2);
              %e0:=part(e0,1); if(e0=e) then return e;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% possible cases: e0:={expt_list,num_list,x_list}
% if both num_list and x_list are empty, then e0 takes the value of the
% smallest exponent in expt_list.
% if numbers in expt_list are all positive, then e0 is the value in either
% num_list, or expt_list: if num_list, then this number is returned, if
% expt_list, then we apply algorithm recusively to the value of x_exp
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

              if (part(e0,1)=expt)
                then <<
                       e0:=part(e0,2);
                       %if(not numberp e0) then return part(e0,2);
                       if(e0<0 and ((lisp car series_exp) neq minus))
                         then return infinity
                        else
                            << %*sign(lcof(series_exp,ww))
                               if(e0<0) then return -infinity
                                else if(e0>0) then return 0
                                else <<
                                       off mcd; off factor; off rational; on exp;
                                       recurse:=lcof(series_exp,ww);
                                       return mrv_limit(recurse,x,infinity);
                                     >>;
                            >>;
                     >>
               else if (part(e0,1)=number)
                then return part(e0,2)
               else if sqchk part(e0,1) = 'minus then return -infinity
               else nil;
              e0:=lpower(series_exp,ww); off mcd;
              % expr free of neg powers ? sort of
              if (numberp e0)
                then <<
                       on mcd; on exp;
                       e0:=lpower(num series_exp,ww)/lpower(den series_exp,ww);
                       off mcd;
                       e0:=e0;
                     >>;

              lisp (e0:=lisp prepsq cadr e0);

              if(e0=ww) then return 0
               else if(part(e0,0)=expt) 
                then <<
                       if (part(e0,2)<0)
                         then % have plus /minus infinity
                              << if(sign(lcof(series_exp,ww))=-1)
                                   then return -infinity
                                  else if (sign(lcof(series_exp,ww))=1)
                                   then return infinity
                                  else << rule2:= { sign(log(~x)) => 1 };
                                          %let rule2;
                                          sig := (sign(lcof(series_exp,ww)) where rule2);
                                          %clearrules rule2;
                                          return infinity;
                                       >>;
                              >>
                        else if(part(e0,2)>0)
                         then return 0
                        else
                             % the limiting behaviour of f depends on that of c
                             << on rational; off mcd; 
                                return mrv_limit(lcof(series_exp,ww),x,infinity);
                             >>;
		     >>;
	    >>;
        >>;

  off mcd;
end;
   if(lisp !*trlimit) then write "mrv_limit(",!*mrv!-recursion!-level!*,"): ","Result = ",result;
   result>>
   )
   (0,!*mrv!-recursion!-level!*+1);
%---------------------------------------------------------------------------

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
      then u := subeval({{{'equal,x,{'minus,newvar}}},u})
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
