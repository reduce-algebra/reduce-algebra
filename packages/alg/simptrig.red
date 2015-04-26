module simptrig; % Simplification for trigonometric and hyperbolic functions.

% Author: Alan Barnes, Rainer Schöpf, Eberhard Schruefer and others.

% Copyright (c) 2015 Reduce developers

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

comment First attempt to define simplification functions for trigonometric functions;

comment remove the rules replaced by simpfn ;

algebraic;

clear cos(0),
    sin(pi/12),
    sin(5pi/12),
    sin(pi/6),
    sin(pi/4),
    sin(pi/3),
    cos(pi/2),
    sin(pi/2),
    sin(pi),
    cos(pi)
       ;

clearrules

 sin( (~~w + ~~k*pi)/~~d)
     => (if evenp fix(k/d) then 1 else -1)
          * sin(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and abs(k/d) >= 1,

 sin( ~~k*pi/~~d) => sin((1-k/d)*pi)
      when ratnump(k/d) and k/d > 1/2,

 cos( (~~w + ~~k*pi)/~~d)
     => (if evenp fix(k/d) then 1 else -1)
          * cos(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and abs(k/d) >= 1,

 cos( ~~k*pi/~~d) => -cos((1-k/d)*pi)
      when ratnump(k/d) and k/d > 1/2,

 csc( (~~w + ~~k*pi)/~~d)
     => (if evenp fix(k/d) then 1 else -1)
          * csc(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and fixp k and abs(k/d) >= 1,

 csc( ~~k*pi/~~d) => csc((1-k/d)*pi)
      when ratnump(k/d) and k/d > 1/2,

 sec( (~~w + ~~k*pi)/~~d)
     => (if evenp fix(k/d) then 1 else -1)
          * sec(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and fixp k and abs(k/d) >= 1,

 sec( ~~k*pi/~~d) => -sec((1-k/d)*pi)
      when ratnump(k/d) and k/d > 1/2,

 tan( (~~w + ~~k*pi)/~~d)
     => tan(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and abs(k/d) >= 1,

 cot( (~~w + ~~k*pi)/~~d)
     => cot(w/d + ((k/d)-fix(k/d))*pi)
      when w freeof pi and ratnump(k/d) and abs(k/d) >= 1;

clearrules

    sin((~x + ~~k*pi)/~~d) => sign(k/d)*cos(x/d)
         when x freeof pi and abs(k/d) = 1/2,

    cos((~x + ~~k*pi)/~~d) => -sign(k/d)*sin(x/d)
         when x freeof pi and abs(k/d) = 1/2,

    csc((~x + ~~k*pi)/~~d) => sign(k/d)*sec(x/d)
         when x freeof pi and abs(k/d) = 1/2,

    sec((~x + ~~k*pi)/~~d) => -sign(k/d)*csc(x/d)
         when x freeof pi and abs(k/d) = 1/2,

    tan((~x + ~~k*pi)/~~d) => -cot(x/d)
         when x freeof pi and abs(k/d) = 1/2,

    cot((~x + ~~k*pi)/~~d) => -tan(x/d)
         when x freeof pi and abs(k/d) = 1/2;

symbolic;

comment Implemented are:
   (1) Spltting of terms that are multiples of pi
   (2) Folding of argument to -pi/2 .. +pi/2
   (3) special values
   (4) sin(pi/2+x) => cos(x)  and the like

Not yet implemented:
   (5) sin(asin(x)) => x and sin(acsc(x)) => 1/x, but not sin(acos(x))

;


symbolic procedure simp!-trig!-arg u;
   begin scalar r,okord,!*mcd,!*exp,dmode!*;
     okord := setkorder '(pi);
     !*mcd := !*exp := t;
     r := simp u;
     setkorder okord;
     return r
   end;


symbolic procedure pi_split u;
   begin scalar du,nu,l;
     nu := numr u;
     du := denr u;
     a: if domainp nu or null(mvar nu eq 'pi) then return nil . u;
        if ldeg nu < (if domainp du then 1 else ldeg du + 1)
           then return nil . u;
        if ldeg nu = (if domainp du then 1 else ldeg du + 1)
           then <<if null l
                    then l := quotsq(lc nu ./ 1,
                                     (if domainp du then du else lc du) ./ 1)
                   else if quotsq(lc nu ./ 1,
                                  (if domainp du then du else lc du) ./ 1) neq l
                    then return nil . u;
                  if domainp du or null red du then return l . u;
                  du := red du>>;
        nu := red nu;
        go to a
   end;


symbolic procedure simp!-trig u;
   simp!-trig1(car u,simp!-trig!-arg cadr u);

symbolic procedure simp!-trig1(op,arg);
   begin scalar x,y,w,realpart,fractpart,intpart,nonintpart,s;
      x := pi_split arg;
      % car x is either nil or coeff of term linear in pi, cdr x is arg
      y := car x; 
      %%% note: check kernel order here!!!
      if y then x := y . subtrsq(cdr x,multsq(y,simp 'pi));
      % check that car x is a rational number with a suitable range
      %%% This check is too simple, it assumes that denr y is a number
      if y and numberp denr y then <<
        y := numr y;
        while y and not domainp y do y := red y;
        if null y then nonintpart := car x
         else <<
           realpart := multsq(!*f2q repartf y,1 ./ denr car x);
	   intpart := simp {'fix,prepsq realpart};
           % check that intpart is a (sort of) number
           if not atom denr intpart or not domainp numr intpart then intpart := nil ./ 1;
           fractpart := subtrsq(realpart,intpart);

	   % At this point any integer multiple of pi has been taken care of,
           % now shift by pi into the interval (-pi/2,+pi/2)
	     
	   if atom denr fractpart and domainp (w:=numr fractpart)
             then if null w then nil
                   else if !:minusp w and !:minusp !:plus(w,!:times(denr fractpart,'(!:rn!: 1 . 2)))
                    then intpart:=addsq(intpart,1 ./ 1)
                   else if not !:minusp w and !:minusp !:difference(!:times(denr fractpart,'(!:rn!: 1 . 2)),w)
     	            then intpart:=addsq(intpart,-1 ./ 1);

           nonintpart := subtrsq(car x,intpart);

      	   %
      	   % implement shifts by +/-pi/2
      	   %
      	   if null numr subtrsq(nonintpart, 1 ./ 2) % op(arg+pi/2)
             then << if op eq 'sin then op := 'cos
                      else if op eq 'cos then << op := 'sin; s := not s >>
		      else if op eq 'tan then << op := 'cot; s := not s >>
		      else if op eq 'cot then << op := 'tan; s := not s >>
		      else if op eq 'sec then << op := 'csc; s := not s >>
		      else if op eq 'csc then op := 'sec;
		     nonintpart := nil ./ 1
                  >>
       	    else if null numr addsq (nonintpart, 1 ./ 2) % op(arg-pi/2)
             then << if op eq 'sin then << op := 'cos; s := not s >>
                      else if op eq 'cos then op := 'sin
		      else if op eq 'tan then << op := 'cot; s := not s >>
		      else if op eq 'cot then << op := 'tan; s := not s >>
		      else if op eq 'sec then op := 'csc
		      else if op eq 'csc then <<op := 'sec; s := not s >>;
                     nonintpart := nil ./ 1
	          >>;

           w := numr intpart;
	   arg := if null numr nonintpart then cdr x
	           else addsq(cdr x,multsq(nonintpart,!*k2q 'pi));
	   % int!-equiv!-chk since w might be a domain element representing an integer
	   if w and op memq '(sin cos sec csc) and not evenp int!-equiv!-chk w then s:=not s;
	>>;
      >>;
      if null numr cdr x then <<
        % at this point we have op(nonintpart*pi), check for 0 and rational number
        if null numr nonintpart then << if op memq '(sin tan csc) then return nil ./ 1
                                            else if op memq '(cos sec) then return 1 ./ 1 >>
        % check for zero result first
         else if op memq '(cos cot) and atom denr(w := multsq(nonintpart,2 ./ 1)) and (numr w=1 or numr w=-1)
          then return nil ./ 1
         else if atom denr nonintpart and (atom numr nonintpart or car numr nonintpart memq '(!:rn!: !:crn!:))
          then << if (w := try!-simp!-trig!-ratpi(op,nonintpart)) then return w >>
      >>;
      % special values checked, fall back to simpiden to apply rules
      if op memq '(sin csc tan cot) and minusf numr arg then <<arg := negsq arg; s:=not s>>;
%%%      %
%%%      % Check for inverse function
%%%      %
%%%      if kernp arg and not atom mvar numr arg and 
%%%	 (w := assoc(op,'((sin (asin . nil) (acsc . t))
%%%                          (cos (acos . nil) (asec . t))
%%%       	   	          (tan (atan . nil) (acot . t))
%%%		          (cot (acot . nil) (atan . t))
%%%		          (sec (asec . nil) (acos . t))
%%%		          (csc (acsc . nil) (asin . t)))))
%%%         and (w := assoc(car mvar numr arg, cdr w))
%%%        then << x := simp cadr mvar numr arg; if cdr w then x := invsq x >>
%%%       else
      x := simpiden {op,mk!*sq arg};
      if s then x := negsq x;
      return x;
   end;

symbolic procedure try!-simp!-trig!-ratpi(op,sq);
   % Tries to simplify op(sq*pi), where sq represents a rational number
   begin scalar u,v,w,x,y,z,s,flg;
     x := get(op,'rat!-pi!-alist);
     if null x then return nil;
     if atom numr sq then << u := numr sq; v := denr sq >>
      else if car numr sq eq '!:rn!: then << u := cadr numr sq; v := cddr numr sq >>
      else if car numr sq eq '!:crn!: then << u := car cadr numr sq; v := cdr cadr numr sq >>;
     if u<0 then << u := -u; s := t >>;
     if op eq 'cos and u=1 and v=2 then return nil ./ 1;
     % for cot,sec,csc check 1/tan,1/cos,1/sin instead
     if op eq 'cot then << op := 'tan; flg := t>>
      else if op eq 'sec then << op := 'cos; flg := t>>
      else if op eq 'csc then << op := 'sin; flg := t>>;
     y := assoc(v,x);                   % find denominator in alist
     if null y then return nil;
     z := assoc(u,y);
     if null z then return nil;
     w := simp cdr z;
     if flg then if null numr w then return nil else w := invsq w;
     return if s then negsq w else w
   end;

put('sin,'rat!-pi!-alist,'((2 . ((1 . 1)))
                           (3 . ((1 . (quotient (sqrt 3) 2))))
                           (4 . ((1 . (quotient (sqrt 2) 2))))
                           (6 . ((1 . (quotient 1 2))))
                           (12 . ((1 . (times (quotient (sqrt 2) 4) (difference (sqrt 3) 1)))
                                  (5 . (times (quotient (sqrt 2) 4) (plus (sqrt 3) 1)))))));

put('cos,'rat!-pi!-alist,'((2 . ((1 . 0)))
                           (3 . ((1 . (quotient 1 2))))
                           (4 . ((1 . (quotient (sqrt 2) 2))))
                           (6 . ((1 . (quotient (sqrt 3) 2))))
                           (12 . ((1 . (times (quotient (sqrt 2) 4) (plus (sqrt 3) 1)))
                                  (5 . (times (quotient (sqrt 2) 4) (difference (sqrt 3) 1)))))));

put('tan,'rat!-pi!-alist,'((8 . ((1 . (difference (sqrt 2) 1))
                                 (3 . (plus (sqrt 2) 1))))));


put('sin,'simpfn,'simp!-trig);
put('cos,'simpfn,'simp!-trig);
put('sec,'simpfn,'simp!-trig);
put('csc,'simpfn,'simp!-trig);
put('tan,'simpfn,'simp!-trig);
put('cot,'simpfn,'simp!-trig);


endmodule;

end;
