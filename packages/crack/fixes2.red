%********************************************************************
module reduce_patches$
%********************************************************************
%  Routines for finding leading derivatives and others
%  Author: Tony Hearn, Winfried Neun, Arthur Norman, since 2003

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

symbolic fluid '(!*fjwflag)$ % for diffp() below

%>>>>>>>>>>  the next fixes some noncom bug

symbolic procedure diffp(u,v)$
   begin scalar n,w,x,y,z; integer m;
	n := cdr u;
	u := car u;
	if n>1 and noncomp u
	  then return addsq(multsq(simpdf {u,v},simpexpt {u,n - 1}),
			    multpq(u .** 1,diffp(u . (n - 1),v)))
	 else if u eq v and (w := 1 ./ 1) then go to e
	 else if atom u then go to f
	 else if (not atom car u and (w:= difff(u,v)))
		  or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
	  then go to c
	 else if x := get(car u,'dfform) then return apply3(x,u,v,n)
	 else if x:= get(car u,dfn_prop u) then nil
	 else if car u eq 'plus and (w := diffsq(simp u,v))
	  then go to c
	 else go to h;
	y := x;
	z := cdr u;
    a:  w := diffsq(simp car z,v) . w;
	if caar w and null car y then go to h;
	y := cdr y;
	z := cdr z;
	if z and y then go to a
	 else if z or y then go to h;
	y := reverse w;
	z := cdr u;
	w := nil ./ 1;
    b:  if caar y
	  then w := addsq(multsq(car y,simp subla(pair(caar x,z),
						   cdar x)),
			  w);
	x := cdr x;
	y := cdr y;
	if y then go to b;
    c:
    e: if (x := atsoc(u,wtl!*))
	  then w := multpq('k!* .** (-cdr x),w);
	m := n-1;
	return rationalizesq if n=1 then w
		else if flagp(dmode!*,'convert)
		     and null(n := int!-equiv!-chk
					   apply1(get(dmode!*,'i2d),n))
		 then nil ./ 1
		else multsq(!*t2q((u .** m) .* n),w);
    f:  if not depends(u,v)
	   and (not (x:= atsoc(u,powlis!*))
		 or not depends(cadddr x,v))
	   and null !*depend
	  then return nil ./ 1;
	w := list('df,u,v);
	w := if x := opmtch w then simp x else mksq(w,1);
	go to e;
    h:  if car u eq 'df
	  then if depends(cadr u,v)
			and not(cadr u eq v)
		 then
	  <<if !*fjwflag and eqcar(cadr u, 'int) then
	      if caddr cadr u eq v then
		 << w := 'df . cadr cadr u . cddr u;  go to j >>
	      else if !*allowdfint and
		 not_df_p(w := diffsq(simp!* cadr cadr u, v))
	      then <<
		 w := 'df . reval{'int, mk!*sq w, caddr cadr u} . cddr u;
		 go to j >>;
	   if (x := find_sub_df(w:= cadr u . derad(v,cddr u),
					   get('df,'kvalue)))
			  then <<w := simp car x;
				 for each el in cdr x do
				    for i := 1:cdr el do
					w := diffsq(w,car el);
				 go to e>>
		       else w := 'df . w
		>>
		else if null !*depend then return nil ./ 1
		else w := {'df,u,v}
	 else w := {'df,u,v};
   j:   if (x := opmtch w) then w := simp x
	 else if not depends(u,v) and null !*depend then return nil ./ 1
	 else w := mksq(w,1);
      go to e
   end$

%>>>>>>>> A gcd catastrophic error fix by Winfried Neun, 13. Sep 2006
% symbolic procedure gcdf(u,v)$
% now in the reduce source

%>>>>>>>> A fix by Winfried Neun, 20. Sep 2006 
%>>>>>>>> to simplify df(int(f,y),x,y) --> df(f,x)
%>>>>>>>> An alternative is
%>>>>>>>> on allowdfint$
%>>>>>>>> on dfint$

copyd('oldsimpdf,'simpdf)$

symbolic procedure simpdf (li)$
begin scalar intvar,intvar2,vars,restvars;

 if (pairp car li) and (caar li = 'int)
   then << intvar := caddar li;
           vars := append(li,nil)>> % will be destroyed
   else return oldsimpdf(li);

 if idp intvar and ( restvars := mymemq(intvar,vars,nil) )
   then
     if (pairp cdr restvars) and numberp (intvar2 := cadr restvars)
      then  << vars := car vars .
                 (intvar . ( intvar2 . append( cdr vars, cddr
   restvars)));
               return oldsimpdf (vars) >>
     else  <<  vars := car vars . (intvar . append( cdr vars, cdr
   restvars));
               return oldsimpdf (vars) >>;

 return oldsimpdf(li);
end$


%>>>>>>>>>> To avoid printing warnings of the compiler that
% PSL constants are non-local variables uncomment the following
% procedure. This is only necessary when runing the 
% crossreferencing programme cref because it would generate too
% many warnings.

%symbolic procedure symbid(u,vars)$
%   <<if fname!* and null(ftype!* memq '(macro smacro))
%       and not(atsoc(u,vars) or fluidp u or globalp u
%        or null u or u eq t or flagp(u,'share) or !*comp 
%        % or !*cref % <-- This line is the only difference
%        or get(u,'constant!?))
%       then lprim list("nonlocal use of undeclared variable",u,
%                       "in procedure",fname!*);
%     u>>$

%>>>>>>>>>> To avoid "***** READ Buffer overflow, Truncating"
% when reading from a file too long numbers or strings
% One needs an extra modified REDUCE and then also

% If the corresponding patch has not yet been used and REDUCE been
% re-compiled then uncomment the following:

%load token!-decls$

%fluid '(bigtokenbuffersize)$
%lisp <<tokenbuffer := gtwarray(25000)$
%       bigtokenbuffersize := 200000; >>$

%symbolic procedure readinbuf ()$
%<<tokch:= channelreadchar tokchannel;
%  putstrbyt(inf tokenbuffer, currentchar, tokch);
%  chtokentype := tokentypeofchar tokch;
%  if wlessp(currentchar,bigtokenbuffersize) then
%  currentchar := currentchar #+ 1           else
%  if currentchar #= bigtokenbuffersize then <<
%    errorprintf( "***** READ Buffer overflow, Truncating");
%    currentchar:=bigtokenbuffersize #+ 1
%  >>                                   else
%  currentchar :=  bigtokenbuffersize #+ 1
%>>$

%>>>>>>>>>> To avoid a crash of gcdlist involving rational numbers
% 4 Oct 2007 by Winfried Neun

symbolic procedure gcdlist_aux(l)$
if null dmode!* then gcdlist l
else if length l = 1 then car l
else if car l = 1 then 1
else if length l = 2 then  gcdf(car l, cadr l)
else gcdlist_aux (gcdf(car l, cadr l) . cddr l)$

%>>>>>>>>>> To speed up substitutions
% by Tony Hearn

symbolic procedure subeval0 u$
   % This is the general evaluator for SUB forms.  All but the last
   % argument are assumed to be substitutions.  These can either be
   % an explicit rule with a lhs and rhs separated by an equal sign,
   % a list of such rules, or something that evaluates to this.
   begin scalar x,y,z,ns,caddrx;                                  % <-- caddrx added
   % Check for spurious substitutions.
   while cdr u do <<if not eqcar(car u,'equal) then x := car u . x
                     else if not(cadar u = (y := aeval caddar u)) % <-- was reval istead of aeval
                      then x := {caar u,cadar u,y} . x;
                    u := cdr u>>;
   if null x then return car u else u := nconc(reversip x,u);
   % Separate assignments from expression.
      if u member sublist!* then return mk!*sq !*p2q mksp('sub . u,1)
       else sublist!* := u . sublist!*;
      if null(u and cdr u)
       then rederr "SUB requires at least 2 arguments"; % F.J. Wright.
      (while cdr u do
          <<x := reval car u;
            if getrtype x eq 'list then u := append(cdr x,cdr u)
             else <<if not eqexpr x then errpri2(car u,t);
                    y := cadr x;
                    if null getrtype y then y := !*a2kwoweight y;
                    caddrx:=reval caddr x;                          % <-- inserted
                    if getrtype caddrx then ns := (y . caddrx) . ns % <-- now 2x with caddrx
                     else z := (y . caddrx) . z;                    % <-- now with caddrx
                    u := cdr u>>>>) where !*evallhseqp=nil;
      x := aeval car u;
      return subeval1(append(ns,z),x)
end$

%>>>>>>>> Fix of an infinite substitution loop generated in odesolve()
%         when sin^2 => 1-cos^2 or cos^2=>1-sin^2 was issued.

load_package trigsimp$ % load_package instead of load to load recursively all

%>>>>>>>> Fix of error message ".. invalid as distributive polynomial exponent"
% 3 June 2008 by Eberhard Schruefer 

% The extension of a2dip allows exponentials in *non*-distributive variables.
% Remaining problem: if a variable is u^p then in the expression
% a3*u^(3*p)+ a1*u^p the power u^(3*p) is not represented as (u^p)^3 .
% So exponents are still to be avoided in crineq.red .

%>>>>>>>> The next fix  corrects printing of Gaussian integers 
%         (integer complex numbers under ON NAT and ON COMPLEX 
%         to avoid printing of (:gi: 0 . 1) for i
% Author: Winfried Neun Nov 2009

% 14 Sep 2010, it seems the current REDUCE does all correctly now
% so the procedure is commented out for now.

%symbolic procedure add_prin_char(u,n)$
%if null !*nat then if get(u, 'dname) then prin1 u  % <-- This line is extra.
%                                     else 
%if stringp u or get(u,'switch!*) or digit u
%   or get(car explode2 u,'switch!*) then prin2 u
%                                    else prin1 u
%              else <<
% pline!* := (((posn!* . n) . ycoord!*) . u) .  pline!*;
% posn!* := n
%>>$

endmodule$


%>>>>>>>> Fix of error message "***** CATASTROPHIC ERROR *****
%                               ("gcdf failed" (plus 
% when sqrt(3) and i are involved and ON COMBINEEXPT

%>>>>>>>> Additional fix of a crash when noncom variables are involved
%         and:  on  combineexpt$


end$
