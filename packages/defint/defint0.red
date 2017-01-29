module defint0;  % Rules for definite integration.

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


global '(unknown_tst product_tst transform_tst transform_lst);

transform_lst := '();

fluid '(!*precise !*trdefint);

global '(spec_cond);

switch trdefint;

%% RmS: Commented out since unused
%%symbolic procedure mynumberp(n);
%%  if numberp n then t
%%  else if listp n and car n = 'quotient and
%%          (numberp cadr n or mynumberp cadr n) and
%%          (numberp caddr n or mynumberp caddr n) then t
%%  else if listp n and car n = 'sqrt and (numberp cadr n or cadr n = 'pi)
%%         then t
%%  else nil;
%%
%%symbolic operator mynumberp;


put('intgggg,'simpfn,'simpintgggg);

% put('defint,'psopfn,'new_defint);

%%%
%%% new_defint is the entry point for the Mellin transform method for evaluating
%%%  integrals with limits 0 ... infinity.
%%%
%%% The steps performed are these:
%%%  1. Separate the integrand into independent factors
%%%       c (constant w.r.t. integration variable
%%%       x^alpha (a power of the integration variable)
%%%       all other factors f1,f2,...
%%%  
%%%  2. Since the Mellin transform algorithm can handle onyl up to two factors f1,f2,
%%%     rewrite the integralinto one of these forms:
%%%       c*defint(x^alpha,f1,x)
%%%       c*defint(x^alpha,f1,f2,x)
%%%       c*defint(x^alpha,f1*f2*...,x)
%%%     with the new operator defint2
%%%
%%%  3. Use the pattern matcher to transform these into either
%%%       x^alpha*f1    or x^alpha*f1*f2
%%%     where f1 and f2 (if present) can be expressed in terms of a MeijerG function.
%%%     The result is written as either
%%%      intgggg(defint_choose(f1),0,alpha,x)
%%%     or
%%%      intgggg(defint_choose(f1),defint_choose(f2),alpha,x)
%%%
%%%  4. intgggg is the workhorse: it performs some processing on its first two
%%%     arguments and uses a table lookup to find the correct MeijerG function for
%%%     f1 and f2.
%%%
%%%  5. If these are found, the integral can be written as the (known) Mellin transform
%%%     of either one MeijerG function or a product of two of them.
%%%
%%%  6. If not, unknown is returned.
%%%     

symbolic procedure new_defint(lst);
   begin scalar nn,dd,x,y,ncoef,dcoef,coeff,var,varpow,varexp,
	 matchform,result,n1,n2,n3,!*precise;
      x := simp!* car lst;
      var := cadr lst;
      if !*trdefint then <<
      	 prin2t "Entering new_defint with integrand";
	 printsq x;
	 prin2!* "w.r.t. variable >"; maprin var; prin2!* "<"; terpri!* t;
	 >>;
      nn := fctrf numr x;
      dd := fctrf denr x;
      ncoef := car nn;
      dcoef := car dd;
      if !*trdefint then <<
      	 prin2t "After factorization, the numerator has factors";
	 terpri!* t;
	 if ncoef neq 1 then <<printsf ncoef; terpri!* t;>>;
	 for each fctr in cdr nn do << printsf mksp!*(car fctr,cdr fctr); terpri!* t >>;
	 prin2t "and the denominator has factors";
	 terpri!* t;
	 if dcoef neq 1 then <<printsf dcoef; terpri!* t;>>;
	 for each fctr in cdr dd do << printsf mksp!*(car fctr,cdr fctr); terpri!* t >>;
	 >>;
      varpow := 1 ./ 1;
      varexp := nil ./ 1;
      for each fff in cdr nn do <<
        if not depends(car fff,var)
	  then ncoef := multf(ncoef,
	     if cdr fff=1 then car fff else mksp!*(car fff,cdr fff))
	else if null red car fff and lc car fff =1 and ldeg car fff = 1 and 
	     (mvar car fff=var or mvar car fff={'sqrt,var}
	     	or eqcar(mvar car fff,'expt) and cadr mvar car fff = var
		   and not depends(caddr mvar car fff,var))
	  then <<varpow := multsq(varpow,mksq(car fff,cdr fff));
	         if mvar car fff=var then varexp := addsq(varexp,cdr fff ./ 1)
		  else if car fff={'sqrt,var}
		   then varexp := addsq(varexp,if evenp cdr fff then (cdr fff/2 ./ 1) else (cdr fff ./ 2))
		  else varexp :=  addsq(varexp,simp!* {'times,caddr mvar car fff,cdr fff})>>
	else y :=
	   (if cdr fff=1 then prepf car fff else prepf mksp!*(car fff,cdr fff))
      	       . y>>;

      for each fff in cdr dd do
        if not depends(car fff,var)
	  then dcoef := multf(dcoef,
	     if cdr fff=1 then car fff else mksp!*(car fff,cdr fff))
	 else if null red car fff and lc car fff =1 and ldeg car fff = 1 and 
	     (mvar car fff=var or mvar car fff={'sqrt,var}
	     	or eqcar(mvar car fff,'expt) and cadr mvar car fff = var
		   and not depends(caddr mvar car fff,var))
	  then <<varpow := multsq(varpow,mksq(car fff,-cdr fff));
	         if mvar car fff=var then varexp := subtrsq(varexp,cdr fff ./ 1)
		  else if mvar car fff={'sqrt,var}
		   then varexp := subtrsq(varexp,if evenp cdr fff then (cdr fff/2 ./ 1) else (cdr fff ./ 2))
		  else varexp :=  subtrsq(varexp,simp!* {'times,caddr mvar car fff,cdr fff})>>
         else y := prepsq (1 ./ mksp!*(car fff,cdr fff)) . y;

      coeff := mk!*sq quotsq(!*f2q ncoef,!*f2q dcoef);

      %
      % At this point, we have the following factors of the integrand
      %
      %  coeff  - intedependent of the integration variable
      %  varpow - a power of the intergration variable
      %  y      - a list of the remaining factors.
      %  

      y := reversip y;

      if !*trdefint then <<
      	 prin2t "After separating the factors into classes, we have the following factors:";
	 if coeff neq '(1 . 1) then <<
	    terpri!* t;
	    prin2t "Constant w.r.t. integration variable:";
	    mathprint coeff;
	    >>;
	 if varpow neq '(1 . 1) then <<
	    prin2t "Powers of integration variable:";
	    printsq varpow;
	    >>;
	 for each fctr in y do mathprint fctr;
	 >>;


      %
      % Now we distinguish:
      %  (a) y is empty. The integrand is a power of x, hence the integral diverges. We return 'unkwnon
      %  (b) y more than two elements, soe we multipyl them and let the pattern matcher try to handle them
      %  (c) we have one or two elements, pass the result ot the pattern matcher
      %

      if null y then <<
      	if !*trdefint then <<
	  prin2t "The integrand is constant or a power of the integration variable:";
	  prin2t "Integral is divergent!";
	>>;
	return 'unknown;
      >>;

      if length y > 2 then y := {reval retimes y};
      
      if varpow neq '(1 . 1) then y := prepsq varpow . y;

      lst := nconc(y,cdr lst);

      unknown_tst := nil;

%%      if length lst = 2 and listp car lst then
%%              lst := test_prod(lst,var);
      transform_tst := reval algebraic(transform_tst);
%      if transform_tst neq t then lst := hyperbolic_test(lst);
      for each i in lst do specfn_test(i);

      if length lst = 4 then
         <<n1 := car lst;
           n2 := cadr lst;
           n3 := caddr lst;
	   matchform := {'defint2,n1,n2,n3,var};
%%	   assgnpri("Calling defint2 with 3 factors and varexp (",nil,'first);
%%	   assgnpri(prepsq varexp,nil,nil);
%%	   assgnpri("): ",nil,nil);
%%	   assgnpri(matchform,nil,'last)
         >>
      else if length lst = 3 then
         <<n1 := car lst;
           n2 := cadr lst;
	   matchform := {'defint2,n1,n2,var}>>
      else if length lst = 2 then
         <<n1 := car lst;
	   matchform := {'defint2,n1,var}>>
      else if length lst = 1 then
	 matchform := {'defint2,1,var}
      else return 'unknown;
      if !*trdefint then <<
      	 prin2t "Expression to pass to algebraic simplifier is:";
	 mathprint matchform;
	 >>;
      result := reval matchform;
      if !*trdefint then <<
      	 prin2t "Expression returned is:";
	 mathprint result;
	 >>;
      algebraic(transform_tst := nil);
      if smemq('defint2,result) then <<
      	 if !*trdefint then <<prin2!* "Pattern match failed!"; terpri!* t;>>;
	 return 'unknown;
	 >>
       else if smemq('unknown,result) then <<
         if !*trdefint then <<prin2!* "Method failed"; terpri!* t;>>;
	 return 'unknown;
	 >>;
      result := reval {'times,coeff,result};
      if !*trdefint then <<
      	 prin2t "After multiplying with the coefficient we return:";
	 mathprint result;
	 >>;
      return result
   end;


symbolic procedure specfn_test(n);

begin;
if listp n and car n = 'times then
<< if listp caddr n and (car caddr n = 'm_gegenbauerp or
                                             car caddr n = 'm_jacobip)
    then off exp; >>;
end;

symbolic procedure test_prod(lst,var);

begin scalar temp,ls;

temp := caar lst;

if temp = 'times then
   << if listp caddar lst then

% test for special cases of Meijer G-functions of compound functions

      << if car caddar lst neq 'm_chebyshevt and
                  car caddar lst neq 'm_chebyshevu and
            car caddar lst neq 'm_gegenbauerp and
            car caddar lst neq 'm_jacobip then
            ls := append(cdar lst,{var})

%else returned without change
         else ls := lst;>>
      else ls := append(cdar lst,{var});
   >>

else if temp = 'minus and caadar lst = 'times then
<< if length cadar lst = 3 then
      ls := {{'minus,car cdadar lst},cadr cdadar lst,var}
   else if length cadar lst = 4 then
      ls := {{'minus,car cdadar lst},cadr cdadar lst,
	 caddr cdadar lst,var}>>
else ls := lst;
return ls;
end;

%%symbolic procedure test_unknown(n);
%%
%%% A procedure to test for unknown as the result of the integration
%%% process
%%
%%if pairp n then << for each i in n do test_unknown(i)>>
%%else if n = 'unknown then unknown_tst := 't;

algebraic<<
heaviside_rules :=

{ Heaviside(~x) => 1 when numberp x and x >= 0,
  Heaviside(~x) => 0 when numberp x and x < 0 };

let heaviside_rules;

operator defint2,defint_choose;

share mellincoef$

%%
%% These rules for defint2 preprocess the integrand for the real Mellin transform
%% machinery.  intgggg is the workhorse: it has 4 parameters f1,f2,alpha,x. They
%% correspond to an integrand of the form x^a*f1*f2.
%%
%% If there is only one factor f2 is passed as zero;
%%
   
defint2_rules:=

{

%%
%% Rules for defint2 with 2 arguments
%%

  defint2(cos((~x*~~a)/~~c)-cos((~x*~~b)/~~d),~x) =>
                -2*defint2(sin((a/c+b/d)*x/2),sin((a/c-b/d)*x/2),x),

  defint2(~b/~f1,~x) => b*defint2(1/f1,x)
        when freeof (b,x) and not(b = 1),

  defint2(~~b*~f1,~x) => b*defint2(f1,x)
        when freeof (b,x) and not(b = 1),

  defint2(~f1/~~b,~x) => 1/b*defint2(f1,x)
        when freeof (b,x) and not(b = 1),

  defint2((~f2+ ~~f1)/~~f3,~x) =>
      defint!:addx(defint2(f2/f3,x),defint2(f1/f3,x)) when not(f1=0),

  defint2(-~f1,~x) =>  - defint2(f1,x),

  defint2(~f1,~x) => intgggg(defint_choose(f1,x),0,0,x),

%%
%% Rules for defint2 with 3 arguments
%%

  defint2(~n,cos((~x*~~a)/~~c)-cos((~x*~~b)/~~d),~x) =>
                -2*defint2(n,sin((a/c+b/d)*x/2),sin((a/c-b/d)*x/2),x),

  defint2(~~b*~f1,~~c*~f2,~x) => b*c*defint2(f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~b/~f1,~c/~f2,~x) => c*b*defint2(1/f1,1/f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~~b*~f1,~c/~f2,~x) => c*b*defint2(f1,1/f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~b/~f1,~~c*~f2,~x) => c*b*defint2(1/f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~f1/~~b,~~c*~f2,~x) => c/b*defint2(f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2((~f2+ ~f1)/~~f3,~n,~x) =>
     defint!:addx(defint2(f2/f3,n,x),defint2(f1/f3,n,x)),

  defint2(-~f1,~n,~x) =>  - defint2(f1,n,x),

  defint2(~n,(~f2+ ~f1)/~~f3,~x) =>
     defint!:addx(defint2(n,f2/f3,x),defint2(n,f1/f3,x)),

  defint2(~n,-~f1,~x) =>  - defint2(n,f1,x),

  defint2(1/~x^(~~a),~f1,~x) => intgggg(defint_choose(f1,x),0,-a,x)
      when a freeof x,

  defint2(1/sqrt(~x),~f1,~x) => intgggg(defint_choose(f1,x),0,-1/2,x),

  defint2(1/(sqrt(~x)*~x^~~a),~f1,~x) =>
                             intgggg(defint_choose(f1,x),0,-1/2-a,x) when a freeof x,

  defint2(~x**(~~a),~f1,~x) => intgggg(defint_choose(f1,x),0,a,x)
      when a freeof x,

  defint2(sqrt(~x),~f1,~x) => intgggg(defint_choose(f1,x),0,1/2,x),

  defint2(sqrt(~x)*~x^~~a,~f1,~x) =>
              intgggg(defint_choose(f1,x),0,1/2+a,x) when a freeof x,

  defint2(~b,~f1,~x) => b*defint2(f1,x) when freeof(b,x),

  defint2(~f1,~f2,~x) =>
        intgggg(defint_choose(f1,x),defint_choose(f2,x),0,x),

  defint2(~n,~f1,~x) => n*intgggg(defint_choose(f1,x),0,0,x) when numberp n,

  defint2((~f1-~f2)/~f3,~f4,~x) =>
     defint!:subtract(defint2(f1/f3,f4,x),defint2(f2/f3,f4,x)),

%%
%% Rules for defint2 with 4 arguments
%%

  defint2(~b,~f1,~f2,~x) => b*defint2(f1,f2,x) when freeof (b,x),

  defint2(~n,(~f2+ ~f1)/~~f3,~nn,~x) =>
     defint!:addx(defint2(n,f2/f3,nn,x),defint2(n,f1/f3,nn,x)),

  defint2(~n,-~f1,~nn,~x) =>  - defint2(n,f1,nn,x),

  defint2(~n,~nn,(~f2+ ~f1)/~~f3,~x) =>
     defint!:addx(defint2(n,nn,f2/f3,x),defint2(n,nn,f1/f3,x)),

  defint2(~n,~nn,-~f1,~x) =>  - defint2(n,nn,f1,x),

  defint2(~n,1/~x,~f1,~x) => n*intgggg(defint_choose(f1,x),0,-1,x)
   when n freeof x,

  defint2(~n,1/~x^(~a),~f1,~x) => n*intgggg(defint_choose(f1,x),0,-a,x)
   when n freeof x,

  defint2(~n,1/sqrt(~x),~f1,~x) =>
                 n*intgggg(defint_choose(f1,x),0,-1/2,x) when n freeof x,

  defint2(~n,1/(sqrt(~x)*~x),~f1,~x) =>
                            n*intgggg(defint_choose(f1,x),0,-3/2,x) when n freeof x ,

  defint2(~n,1/(sqrt(~x)*~x^~a),~f1,~x) =>
                            n*intgggg(defint_choose(f1,x),0,-1/2-a,x) when n freeof x,

  defint2(~n,~x**(~a),~f1,~x) => n*intgggg(defint_choose(f1,x),0,a,x)
   when n freeof x,

  defint2(~n,~x,~f1,~x) => n*intgggg(defint_choose(f1,x),0,1,x)
   when n freeof x,

  defint2(~n,sqrt(~x),~f1,~x) => n*intgggg(defint_choose(f1,x),0,1/2,x)
    when n freeof x,

  defint2(~n,sqrt(~x)*~x,~f1,~x) =>
    n*intgggg(defint_choose(f1,x),0,3/2,x) when n freeof x,

  defint2(~n,sqrt(~x)*~x^~a,~f1,~x) =>
     n*intgggg(defint_choose(f1,x),0,1/2+a,x) when n freeof x,

  defint2(~~b*~x^~~a/~~c,~f1,~f2,~x) =>
        b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),a,x)
                        when freeof(b,x) and freeof (c,x),

  defint2(~b/(~~c*~x^~~a),~f1,~f2,~x) =>
        b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),-a,x)
                        when freeof(b,x) and freeof(c,x),

  defint2(sqrt(~x),~f1,~f2,~x) =>
                     intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2,x),

  defint2(sqrt(~x)*~x^~~a,~f1,~f2,~x) =>
               intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2+a,x) when a freeof x,

  defint2(~b/(~~c*sqrt(~x)),~f1,~f2,~x) =>
     b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2,x)
	when b freeof x and c freeof x,

  defint2(1/(sqrt(~x)*~x^~~a),~f1,~f2,~x) =>
    intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2-a,x) when a freeof x,

  defint2(-~b,~f1,~f2,~x) => -b*defint2(f1,f2,x) when freeof(b,x)

%%
%% Rules for defint2 with 5 arguments
%%
%%% No longer needed, better preprocessing
%%%
%%%  defint2(~n,~x^~a,~f1,~f2,~x) =>
%%%     n*intgggg(defint_choose(f1,x),defint_choose(f2,x),a,x)
%%%        when n freeof x and a freeof x,
%%%
%%%
%%%  defint2(~n,~x,~f1,~f2,~x) =>
%%%                 n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,1/~x^~~a,~f1,~f2,~x) =>
%%%     n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-a,x)
%%%        when n freeof x and a freeof x,
%%%
%%%  defint2(~n,1/~x,~f1,~f2,~x) =>
%%%                           n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,sqrt(~x),~f1,~f2,~x) =>
%%%                           n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,sqrt(~x)*~x,~f1,~f2,~x) =>
%%%                           n*intgggg(defint_choose(f1,x),defint_choose(f2,x),3/2,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,sqrt(~x)*~x^~a,~f1,~f2,~x) =>
%%%              n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2+a,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,1/sqrt(~x),~f1,~f2,~x) =>
%%%               n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,1/(sqrt(~x)*~x),~f1,~f2,~x) =>
%%%               n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-3/2,x)
%%%   when n freeof x,
%%%
%%%  defint2(~n,1/(sqrt(~x)*~x^~a),~f1,~f2,~x) =>
%%%             n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2-a,x)
%%%   when n freeof x

};

let defint2_rules;
>>;
endmodule;
end;


