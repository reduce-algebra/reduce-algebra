module tayfns;

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

% $Id$

%*****************************************************************
%
%       Simplification functions for special functions
%
%*****************************************************************


exports taysimpexpt, taysimpatan, taysimplog, taysimpexp,
        taysimptan, taysimpsin, taysimpsinh, taysimpasin;

imports

% from the REDUCE kernel:
        !*f2q, !:minusp, addsq, aeval, denr, domainp, eqcar, evenp,
        freeof, invsq, kernp, lastpair, let, lprim, lnc, mk!*sq, mksq,
        multsq, mvar, negsq, neq, nlist, nth, numr, over, prepd,
        prepsq, quotsq, retimes, reval, reversip, simp, simp!*,
        simplogi, simplogsq, subs2!*, subsq, subtrsq,

% from the header module:
        !*tay2q, !*TayExp2q, constant!-sq!-p, cst!-taylor!*,
        find!-non!-zero, get!-degree, has!-tayvars, make!-cst!-coefflis,
        make!-cst!-powerlist, make!-taylor!*, prune!-coefflist,
        set!-taycoefflist, set!-taycfsq, set!-tayflags, set!-tayorig, taycfpl,
        taycfsq, taycoefflist, tayflags, taygetcoeff, taylor!*p,
        taylor!-kernel!-sq!-p, taylor!:, taymakecoeff, tayorig,
        taytemplate, taytpelnext, taytpelorder, taytpelpoint,
        taytpelvars, taytpvars, tayvars, tpnextlist,

% from the module Tayintro:
        confusion, delete!-nth, delete!-nth!-nth, replace!-nth,
        replace!-nth!-nth, taylor!-error, taylor!-error!*,
        var!-is!-nth,

% from the module Tayutils:
        addto!-all!-taytpelorders, get!-cst!-coeff, is!-neg!-pl,
        smallest!-increment, subtr!-degrees, taylor!*!-constantp,
        taylor!*!-zerop,

% from the module Taybasic:
        addtaylor, addtaylor!-as!-sq, invtaylor, makecoeffs0,
        makecoeffpairs, makecoeffpairs1, multtaylor,
        multtaylor!-as!-sq, multtaylorsq, negtaylor, negtaylor1,
        quottaylor,

% from the module TayExpnd:
        taylorexpand,

% from the module Taysimp:
        expttayrat, taysimpsq, taysimpsq!*,

% from the module Taydiff:
        difftaylorwrttayvar,

% from the module TayConv:
        preptaycoeff, preptaylor!*,

% from the module Tayfrontend:
        taylorcombine, taylortostandard;


fluid '(!*taylorkeeporiginal !*!*taylor!-epsilon!*!* frlis!*);


symbolic procedure taysimpexpt u;
  %
  % Argument is of the form ('expt base exponent)
  % where both base and exponent (but a least one of them)
  % may contain Taylor kernels given as prefix forms.
  % Value is the equivalent Taylor kernel.
  %
  if not (car u eq 'expt) or cdddr u then confusion 'taysimpexpt
   else if cadr u eq 'e then taysimpexp {'exp, caddr u}
   else begin scalar bas, expn;
     bas := taysimpsq simp!* cadr u;
     expn := taysimpsq simp!* caddr u;
     if constant!-sq!-p bas then return taysimpexp
         {'exp,mk!*sq multsq(simp!*{'log,mk!*sq bas},expn)};
     if null kernp bas
       then if not(denr bas = 1)
              then return mksq({'expt,prepsq bas,prepsq expn},1)
             else if domainp numr bas
              then return taysimpexp {'exp,
                  prepsq multsq(simp!* {'log,prepd numr bas},expn)}
             else return mksq({'expt,prepsq bas,prepsq expn},1);
     if fixp numr expn and fixp denr expn
       then return !*tay2q expttayrat(mvar numr bas,expn);
     if denr expn = 1 and eqcar(numr expn,'!:rn!:)
       then return !*tay2q expttayrat(mvar numr bas,cdr numr expn);
     bas := mvar numr bas;
     return
       if taylor!*p bas
         then if taylor!-kernel!-sq!-p expn
                then if taytemplate bas = taytemplate mvar numr expn
                       then taysimpexp {'exp,
                                        mk!*sq taysimpsq
                                          multtaylor!-as!-sq(
                                              expn,
                                              taysimplog {'log,bas})}
                      else mksq({'expt,bas,mvar numr expn},1)
               else if not has!-tayvars(bas,expn)
                then begin scalar logterm;
                  logterm := taysimplog{'log,bas};
                  return
                    if taylor!-kernel!-sq!-p logterm
                      then taysimpexp{'exp,
                                      multtaylorsq(mvar numr logterm,
                                                   expn)}
                     else taysimpsq
                            simp!* {'exp,mk!*sq multsq(logterm,expn)}
                 end
               else mksq({'expt,bas,mk!*sq expn},1)
        else if taylor!-kernel!-sq!-p expn
               then if not has!-tayvars(mvar numr expn,bas)
                      then taysimpexp{'exp,
                                      multtaylorsq(mvar numr expn,
                                                   simp!*{'log,bas})}
                     else if taylor!*!-constantp mvar numr expn
                      then taylorexpand(
                             simp!* {'expt,bas,
                                     preptaylor!* mvar numr expn},
                             taytemplate mvar numr expn)
                     else mksq({'expt,bas,mk!*sq expn},1)
        else mksq({'expt,bas,mk!*sq expn},1);
  end;

put('expt,'taylorsimpfn,'taysimpexpt);


symbolic procedure taycoefflist!-union u;
  if null cdr u then car u
   else taycoefflist!-union2 (car u, taycoefflist!-union cdr u)$

symbolic procedure taycoefflist!-union2 (x, y);
  %
  % returns union of TayCoeffLists x and y
  %
  << for each w in y do
       if null (assoc (car w, x)) then x := w . x;
     x >>$

symbolic procedure inttaylorwrttayvar(tay,var);
  %
  % integrates Taylor kernel tay wrt variable var
  %
  inttaylorwrttayvar1(taycoefflist tay,taytemplate tay,var)$

symbolic procedure inttaylorwrttayvar1(tcl,tp,var);
  %
  % integrates Taylor kernel with TayCoeffList tcl and template tp
  %  wrt variable var
  %
  taylor!:
  begin scalar tt,u,w,singlist,csing; integer n,n1,m;
    u := var!-is!-nth(tp,var);
    n := car u;
    n1 := cdr u;
    tt := nth(tp,n);
    u := for each cc in tcl join <<
           m := nth(nth(taycfpl cc,n),n1);
           if taytpelpoint nth(tp,n) eq 'infinity
             then <<
               if m=1 then <<singlist :=
                               taymakecoeff(
                                 delete!-nth!-nth(taycfpl cc,n,n1),
                                 taycfsq cc) . singlist;nil>>
                else {taymakecoeff(
                        replace!-nth!-nth(taycfpl cc,n,n1,m-1),
                        multsq(taycfsq cc,invsq !*TayExp2q(-m + 1)))}>>
            else <<
               if m=-1 then <<singlist :=
                                taymakecoeff(
                                  delete!-nth!-nth(taycfpl cc,n,n1),
                                  taycfsq cc) . singlist;nil>>
               else {taymakecoeff(
                       replace!-nth!-nth(taycfpl cc,n,n1,m+1),
                       multsq(taycfsq cc,invsq !*TayExp2q(m + 1)))}>>>>;
    w := {taytpelvars tt,taytpelpoint tt,
          if var member taytpelvars tt
            then if taytpelpoint tt eq 'infinity
                   then taytpelorder tt - 1
                  else taytpelorder tt + 1
           else taytpelorder tt,
          if var member taytpelvars tt
            then if taytpelpoint tt eq 'infinity
                   then taytpelnext tt - 1
                  else taytpelnext tt + 1
           else taytpelorder tt};
    if singlist then begin scalar tpel;
        tpel := nth(tp,n);
        singlist := reversip singlist;
        if taycfpl car singlist = '(nil) % no Taylor left
          then csing := taycfsq car singlist
         else csing := !*tay2q
                         make!-taylor!*(
                           singlist,
                           replace!-nth(
                             tp,n,
                             {delete!-nth(taytpelvars tpel,n1),
                              taytpelpoint tpel,
                              taytpelorder tpel,
                              taytpelnext tpel}),
                           nil,nil);
        csing := multsq(csing,simp!* {'log,nth(taytpelvars tpel,n1)})
       end;

    return (csing . make!-taylor!*(u,replace!-nth(tp,n,w),nil,nil))
%
% The following is not needed yet
%
%     return make!-Taylor!*(
%              u,
%              replace!-nth(TayTemplate tay,n,w),
%              if !*taylorkeeporiginal and TayOrig tay
%                then simp {'int,mk!*sq TayOrig tay,var}
%               else nil,
%              TayFlags u)
  end;


COMMENT The inverse trigonometric and inverse hyperbolic functions
        of a Taylor kernel are calculated by first computing the
        derivative(s) with respect to the Taylor variable(s) and
        integrating the result.  The derivatives can easily be
        calculated by the manipulation functions defined above.

        The method is best illustrated with an example.  Let T(x)
        be a Taylor kernel depending on one variable x.  To compute
        the inverse tangent T1(x) = atan(T(x)) we calculate the
        derivative

                                T'(x)
                    T1'(x) = ----------- .
                                      2
                              1 + T(x)

        (If T and T1 depend on more than one variable replace
        the derivatives by gradients.)
        This is integrated again with the integration constant
        T1(x0) = atan(T(x0)) yielding the desired result.
        If there is more than variable we have to find the
        potential function T1(x1,...,xn) corresponding to
        the vector grad T1(x1,...,xn) which is always possible
        by construction.

        The prescriptions for the eight functions asin, acos, asec,
        acsc, asinh, acosh, asech, and acsch can be put together
        in one procedure since the expressions for their derivatives
        differ only in certain signs.  The same remark applies to
        the four functions atan, acot, atanh, and acoth.

        These expressions are:

         d                 1
         -- asin x = ------------- ,
         dx           sqrt(1-x^2)

         d                -1
         -- acos x = ------------- ,
         dx           sqrt(1-x^2)

         d                 1
         -- asinh x = ------------- ,
         dx            sqrt(1+x^2)

         d                 1
         -- acosh x = ------------- ,
         dx            sqrt(x^2-1)

         d               1
         -- atan x = --------- ,
         dx           1 + x^2

         d               -1
         -- acot x = --------- ,
         dx           1 + x^2

         d                1
         -- atanh x = --------- ,
         dx            1 - x^2

         d                1
         -- acoth x = --------- ,
         dx            1 - x^2

        together with the relations

                       1
         asec x = acos - ,
                       x

                       1
         acsc x = asin - ,
                       x

                         1
         asech x = acosh - ,
                         x

                         1
         acsch x = asinh -
                         x .


        This method has one drawback: it is applicable only when T(x0)
        is a regular point of the function in question. E.g., if T(x0)
        = 0, then asech(T(x)) cannot be calculated by this method, as
        asech has a logarithmic singularity at 0. This means that the
        constant term of the series cannot be determined by computing
        asech(T(x0)).  In that case, we use the following relations
        instead:


         asin z = -i log(i z + sqrt(1 - z^2)),


         acos z = -i log(z + sqrt(z^2 - 1)),

                    1        1 + i z
         atan z = ----- log ---------,
                   2 i       1 - i z

                   -1        i z + 1
         acot z = ----- log ---------,
                   2 i       i z - 1


         asinh z = log(z + sqrt(1 + z^2)),


         acosh z = log(z + sqrt(z^2 - 1)),

                    1       1 + z
         atanh z = --- log -------,
                    2       1 - z

                    1       z + 1
         acoth z = --- log -------.
                    2       z - 1


         These formulas are applied at the following points:

           infinity for all functions,

           +i/-i for atan and acot,

           +1/-1 for atanh and acoth.


         There are still some branch points, where the calculation is
         not always possible:

           +1/-1 for asin and acos, and consequently for asec and acsc,

           +i/-i for asinh, acosh, asech and acsch.

         In these cases, the above formulas are applied as well, but
         simplification of the square roots and the logarithm may lead
         to a rather complicated result;



symbolic procedure taysimpasin u;
  if not (car u memq '(asin acos acsc asec asinh acosh acsch asech))
     or cddr u
    then confusion 'taysimpasin
   else taylor!:
     begin scalar l,l0,c0,v,tay0,tay,tay2,tp,singlist;
     tay0 := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay0
       then return mksq({car u,mk!*sq tay0},1);
     tay0 := mvar numr tay0; % asin's argument
     l0 := make!-cst!-powerlist taytemplate tay0;
     c0 := taygetcoeff(l0,taycoefflist tay0);
     if car u memq '(asec acsc asech acsch)
       then if null numr c0 then return taysimpasec!*(car u,tay0)
             else tay := invtaylor tay0
      else tay := tay0;
     tp := taytemplate tay;
     l := prune!-coefflist taycoefflist tay;
     if null l then return !*tay2q make!-taylor!* (
                 make!-cst!-coefflis (simp!* {car u,0}, tp),
                 tp, 
                 if null tayorig tay then nil else simp!* {car u,prepsq tayorig tay},
                 nil);
     if is!-neg!-pl taycfpl car l then return taysimpasin!*(car u,tay);
     tay2 := multtaylor(tay,tay);
     if car u memq '(asin acos acsc asec)
       then tay2 := negtaylor tay2;
     tay2 := addtaylor(
               cst!-taylor!*(
                 !*f2q(if car u memq '(acosh asech) then -1 else 1),
                 tp),
               tay2);
     if taylor!*!-zerop tay2
       then taylor!-error!*('branch!-point,car u)
      else if null numr taygetcoeff(l0,taycoefflist tay2)
       then return taysimpasin!*(car u,tay);

     tay2 := invtaylor expttayrat(tay2,1 ./ 2);
     if car u memq '(acos asec) then tay2 := negtaylor tay2;
     l := for each krnl in tayvars tay collect
            inttaylorwrttayvar(
              multtaylor(difftaylorwrttayvar(tay,krnl),tay2),
              krnl);
     v := taycoefflist!-union
            for each pp in l collect taycoefflist cdr pp;
     singlist := nil ./ 1;
     for each pp in l do
       if car pp then singlist := addsq(singlist,car pp);
     %
     % special treatment for zeroth coefficient
     %
     c0 := simp {car u,mk!*sq c0};
     v := taymakecoeff(l0,c0) . v;
     tay := make!-taylor!*(
              v,
              tp,
              if !*taylorkeeporiginal and tayorig tay
                then simp {car u,mk!*sq tayorig tay}
               else nil,
              tayflags tay);
     if null numr singlist then return !*tay2q tay;
     if !*taylorkeeporiginal and tayorig tay
       then set!-tayorig(tay,subtrsq(tayorig tay,singlist));
     return addsq(singlist,!*tay2q tay)
  end;

symbolic procedure taysimpasec!*(fn,tay);
   begin scalar result,tay1,tay2,i1;
     i1 := simp 'i;
     if fn memq '(asin acsc) then tay := multtaylorsq(tay,i1);
     tay1 := cst!-taylor!*(1 ./ 1,taytemplate tay);
     tay2 := multtaylor(tay,tay);
     if fn memq '(asec asech) then tay2 := negtaylor tay2;
     result := taysimplog {'log,
                           addtaylor(
                             expttayrat(addtaylor(tay2,tay1),1 ./ 2),
                             tay1)};
     tay1 := taysimplog {'log,tay};
     if fn memq '(asin acos asec acsc)
       then <<result := taysimpsq negsq multsq(result,i1);
              result := addtaylor!-as!-sq(result,multsq(i1,tay1))>>
      else result := addtaylor!-as!-sq(result,
                                       negsq taysimplog {'log,tay});
     return taysimpsq!* result
   end;

symbolic procedure taysimpasin!*(fn,tay);
   begin scalar result,tay1;
     if fn memq '(asin acsc)
       then tay := multtaylorsq(tay,simp 'i);
     tay1 := cst!-taylor!*(
               (if fn memq '(asin asinh acsc acsch)
                  then 1
                 else -1) ./ 1,
                taytemplate tay);
     result := taysimplog {'log,
                           addtaylor(
                             expttayrat(addtaylor(multtaylor(tay,tay),
                                                  tay1),
                                        1 ./ 2),
                             tay)};
     if fn memq '(asin acos asec acsc)
       then result := quotsq(result,simp 'i);
     return taysimpsq!* result
   end;


put('asin,'taylorsimpfn,'taysimpasin);
put('acos,'taylorsimpfn,'taysimpasin);
put('asec,'taylorsimpfn,'taysimpasin);
put('acsc,'taylorsimpfn,'taysimpasin);
put('asinh,'taylorsimpfn,'taysimpasin);
put('acosh,'taylorsimpfn,'taysimpasin);
put('asech,'taylorsimpfn,'taysimpasin);
put('acsch,'taylorsimpfn,'taysimpasin);


symbolic procedure taysimpatan u;
  if not (car u memq '(atan acot atanh acoth)) or cddr u
    then confusion 'taysimpatan
   else begin scalar l,l0,c0,v,tay,tay2,tp,singlist;
     tay := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay
       then return mksq({car u,mk!*sq tay},1);
     tay := mvar numr tay; % atan's argument
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     l := prune!-coefflist taycoefflist tay;
     if null l then return !*tay2q make!-taylor!* (
                 make!-cst!-coefflis (simp!* {car u,0}, tp),
                 tp, 
                 if null tayorig tay then nil else simp!* {car u,prepsq tayorig tay},
                 nil);
     if is!-neg!-pl taycfpl car l then return taysimpatan!*(car u,tay);
     c0 := get!-cst!-coeff tay;
     if car u memq '(atan acot)
       then c0 := subs2!* multsq(c0,simp 'i);
     if c0 = (1 ./ 1) or c0 = (-1 ./ 1)
       then return taysimpatan!*(car u,tay);
     tay2 := multtaylor(tay,tay);
     if car u memq '(atanh acoth) then tay2 := negtaylor tay2;
     tay2 := invtaylor addtaylor(cst!-taylor!*(1 ./ 1,tp),tay2);
     if car u eq 'acot then tay2 := negtaylor tay2;
     l := for each krnl in tayvars tay collect
            inttaylorwrttayvar(
              multtaylor(difftaylorwrttayvar(tay,krnl),tay2),
              krnl);
     v := taycoefflist!-union
            for each pp in l collect taycoefflist cdr pp;
     singlist := nil ./ 1;
     for each pp in l do
       if car pp then singlist := addsq(singlist,car pp);
     %
     % special treatment for zeroth coefficient
     %
     c0 := simp {car u,
                 mk!*sq taygetcoeff(l0,taycoefflist tay)};
     v := taymakecoeff (l0,c0) . v;
     tay := make!-taylor!*(
              v,
              tp,
              if !*taylorkeeporiginal and tayorig tay
                then simp {car u,mk!*sq tayorig tay}
               else nil,
              tayflags tay);
     if null numr singlist then return !*tay2q tay;
     if !*taylorkeeporiginal and tayorig tay
       then set!-tayorig(tay,subtrsq(tayorig tay,singlist));
     return addsq(singlist,!*tay2q tay)
  end;

symbolic procedure taysimpatan!*(fn,tay);
   begin scalar result,tay1,flg;
     if fn memq '(atan acot)
       then tay := multtaylorsq(tay,simp 'i);
     tay1 := cst!-taylor!*(1 ./ 1,taytemplate tay);
     tay := quottaylor(addtaylor(tay1,tay),
                       addtaylor(tay1,negtaylor tay));
     %
     % if the constant term is -1, take care to replace log(-1) by i*pi
     %
     if get!-cst!-coeff tay = '(-1 . 1) then flg := t;
     result := taysimplog {'log,tay};
     if flg and Taylor!-kernel!-sq!-p result
       then set!-taycfsq(assoc(make!-cst!-powerlist taytemplate tay,taycoefflist tay),
                         simp '(times i pi))
	 where tay := mvar numr result;
     result := multsq(result,1 ./ 2);
     if fn eq 'atan then result := quotsq(result,simp 'i)
      else if fn eq 'acot then result := multsq(result,simp 'i);
     return taysimpsq!* result
   end;



put('atan,'taylorsimpfn,'taysimpatan);
put('acot,'taylorsimpfn,'taysimpatan);
put('atanh,'taylorsimpfn,'taysimpatan);
put('acoth,'taylorsimpfn,'taysimpatan);


COMMENT For the logarithm and exponential we use the extension of
        an algorithm quoted by Knuth who shows how to do this for
        series in one expansion variable.

        We extended this to the case of several variables which is
        straightforward except for one point, see below.
        Knuth's algorithm works as follows: Assume you want to compute
        the series W(x) where

            W(x) = log V(x)

        Differentiation of this equation gives

                    V'(x)
            W'(x) = ----- ,   or V'(x) = W'(x)V(x) .
                     V(x)

        You make now the ansatz

                    -----
                    \           n
            W(x) =   >      W  x  ,
                    /        n
                    -----

        substitute this into the above equation and compare
        powers of x.  This yields the recursion formula

                               n-1
                 V            -----
                  n       1   \
           W  = ---- - ------  >    m W  V     .
            n    V      n V   /        m  n-m
                  0        0  -----
                               m=0

        The first coefficient must be calculated directly, it is

           W   = log V  .
            0         0

        To use this for series in more than one variable you have to
        calculate all partial derivatives: n and m refer then to the
        corresponding component of the multi index.  Looking closely
        one finds that there is an ambiguity: the same coefficient
        can be calculated using any of the partial derivatives.  The
        only restriction is that the corresponding component of the
        multi index must not be zero, since we have to divide by it.

        We resolve this ambiguity by simply taking the first nonzero
        component.

        The case of the exponential is nearly the same: differentiation
        gives

            W'(x) = V'(x) W(x) ,

        from which we derive the recursion formula

                   n-1
                  -----
                  \     n-m
            W  =   >    --- W  V     , W  = exp V  .
             n    /      m   m  n-m     0        0
                  -----
                   m=0

        ;


symbolic procedure taysimplog u;
  %
  % Special Taylor expansion function for logarithms
  %
  if not (car u eq 'log) or cddr u then confusion 'taysimplog
   else taylor!:
    begin scalar a0,clist,coefflis,il,l0,l,tay,tp,csing,singterm,result;
    taylor!-trace!-with!-level(!*taylor!-expansion!-level!*,{"computing log of"});
    taylor!-trace!-mprint u;
    u := simplogi cadr u;
    if not kernp u then return taysimpsq u;
    u := mvar numr u;
    if not (car u eq 'log) then confusion 'taysimplog;
    u := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p u then return mksq({'log,mk!*sq u},1);
    tay := mvar numr u;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    l := prune!-coefflist taycoefflist tay;
    if null l then taylor!-error!*('not!-a!-unit,'taysimplog);
    %
    % The assumption at this point is that the first term is the one
    % with lowest degree, i.e. dividing by this term yields a series
    % which starts with a constant term.
    %
    if taycfpl car l neq l0 then
      <<csing := taycfpl car l;
        l := for each pp in l collect begin scalar newpl;
                 newpl := subtr!-degrees(taycfpl pp,csing);
                 if is!-neg!-pl newpl
                   then taylor!-error('not!-a!-unit,'taysimplog)
                  else return taymakecoeff(newpl,taycfsq pp);
               end;
        tp := addto!-all!-taytpelorders(
                tp,
                for each nl in csing collect
                  - get!-degree nl);
        singterm := simp!* retimes preptaycoeff(csing,tp);
        if !:minusp lnc numr taycfsq car l
          then <<singterm := negsq singterm;
                 l := negtaylor1 l>>>>;
    a0 := taygetcoeff(l0,l);
    clist := {taymakecoeff(l0,simplogi mk!*sq a0)};
    il := if null l then nlist(1,length tp)
           else smallest!-increment l;
    coefflis := makecoeffs0(tp,tpnextlist tp,il);
    if not null coefflis
      then for each cc in cdr coefflis do
             begin scalar s,pos,pp,n,n1;
               s := nil ./ 1;
               pos := find!-non!-zero cc;
               n := nth(nth(cc,car pos),cdr pos);
               pp := makecoeffpairs(l0,cc,taycfpl car l,il);
               for each p in pp do <<
                 n1 := nth(nth(car p,car pos),cdr pos);
                 s := addsq(s,
                            multsq(!*TayExp2q n1,
                                   multsq(taygetcoeff(car p,clist),
                                          taygetcoeff(cdr p,l))))>>;
%               for each p in pp addsq
%                 multsq(!*TayExp2q nth(nth(car p,car pos),cdr pos),
%                        multsq(TayGetCoeff(car p,clist),
%                               TayGetCoeff(cdr p,l)));
               s := subtrsq(taygetcoeff(cc,l),quotsq(s,!*TayExp2q n));
               if not null numr s
                 then clist := taymakecoeff(cc,quotsq(s,a0)) . clist;
             end;
    tay := make!-taylor!*(
             reversip clist,
             tp,
             if !*taylorkeeporiginal and tayorig tay
               then simplogi mk!*sq tayorig tay
              else nil,
             tayflags tay);
    if null csing then return !*tay2q tay;
    singterm := simplogsq singterm;
    if taylor!*!-zerop tay then return singterm;
    if !*taylorkeeporiginal and tayorig tay
      then set!-tayorig(tay,subtrsq(tayorig tay,singterm));
    %% Add the singular term back to the result. Pass the result through
    %% taysimpsq as the simplification of log(singterm) above may return
    %% a result that is free of the expansion variables (this occurs in,
    %% e.g., the mrvlimit package).
    result := taysimpsq addsq(singterm,!*tay2q tay);
    taylor!-trace!-with!-level(!*taylor!-expansion!-level!*,{"result of computing log is"});
    taylor!-trace!-mprint mk!*sq result;
    return result;
  end;

put('log,'taylorsimpfn,'taysimplog);


symbolic procedure taysimpexp u;
  %
  % Special Taylor expansion function for exponentials
  %
  if not (car u eq 'exp) or cddr u then confusion 'taysimpexp
   else taylor!:
    begin scalar a0,clist,coefflis,il,l0,l,lm,lp,tay,tp;
    u := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p u
      then return mksq ({'exp,mk!*sq u},1);
    tay := mvar numr u;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    l := prune!-coefflist taycoefflist tay;
    if null l then return !*tay2q cst!-taylor!*(1 ./ 1,tp);
    for each pp in l do
      if is!-neg!-pl taycfpl pp then lm := pp . lm
       else if not null numr taycfsq pp then lp := pp . lp;
    lm := reversip lm;
    l := reversip lp;

    if lm
      then lm := simp!* {'exp,
                         preptaylor!* make!-taylor!*(lm,tp,nil,nil)};

    if null l then return lm;

    a0 := taygetcoeff(l0,l);
    clist := {taymakecoeff(l0,simp!* {'exp,mk!*sq a0})};
    il := smallest!-increment l;
    coefflis := makecoeffs0(tp,tpnextlist tp,il);

    if not null coefflis
      then for each cc in cdr coefflis do
             begin scalar s,pos,pp,n,n1;
               s := nil ./ 1;
               pos := find!-non!-zero cc;
               n := nth(nth(cc,car pos),cdr pos);
               pp := makecoeffpairs(l0,cc,l0,il);
               for each p in pp do <<
                 n1 := nth(nth(car p,car pos),cdr pos);
                 s := addsq(s,
                            multsq(!*TayExp2q(n - n1),
                                   multsq(taygetcoeff(car p,clist),
                                          taygetcoeff(cdr p,l))))>>;
               s := subs2!* quotsq(s,!*TayExp2q n);
               if not null numr s
                 then clist := taymakecoeff(cc,s) . clist
             end;

    clist := reversip clist;

    u := !*tay2q
           make!-taylor!*(
             clist,
             tp,
             if !*taylorkeeporiginal and tayorig tay
               then simp {'exp,mk!*sq tayorig tay}
              else nil,
             tayflags tay);
    return if null lm then u else multsq(u,lm)
  end;

put('exp,'taylorsimpfn,'taysimpexp);


COMMENT The algorithm for the trigonometric functions is also
        derived from their differential equation.
        The simplest case is that of tangent whose equation is

                            2
           tan'(x) = 1 + tan (x) .          (*)

        For the others we have

                               2
           cot'(x) = - (1 + cot (x)),

                              2
           tanh'(x) = 1 - tanh (x),

                              2
           coth'(x) = 1 - coth (x) .



        Let T(x) be a Taylor series,

                  -----
                  \         N
           T(x) =  >    a  x
                  /      N
                  -----
                   N=0

        Now, let

                              -----
                              \         N
           T1(x) = tan T(x) =  >    b  x
                              /      N
                              -----
                               N=0

        from which we immediately deduce that b  = tan a .
                                               0        0

        From (*) we get
                              2
           T1'(x) = (1 + T1(x) ) T'(x) ,

        or, written in terms of the series:

        Inserting this into (*) we get

          -----              /     /  -----       \ 2 \  -----
          \           N-1    |     |  \         N |   |  \           L
           >    N b  x    =  | 1 + |   >    b  x  |   |   >    L a  x
          /        N         |     |  /      N    |   |  /        L
          -----              \     \  -----       /   /  -----
           N=1                         N=0                L=1

        We perform the square on the r.h.s. using Cauchy's rule
        and obtain:


           -----
           \           N-1
            >    N b  x    =
           /        N
           -----
            N=1

                              N
               /     -----  -----            \  -----
               |     \      \              N |  \           L
               | 1 +  >      >    b    b  x  |   >    L a  x  .
               |     /      /      N-M  M    |  /        L
               \     -----  -----            /  -----
                      N=0    M=0                 L=1

        Expanding this once again with Cauchy's product rule we get

           -----
           \           N-1
            >    N b  x    =
           /        N
           -----
            N=1

                                L-1     N
           -----      /        -----  -----                    \
           \      L-1 |        \      \                        |
            >    x    | L a  +  >      >    b    b  (L-N) a    | .
           /          |    L   /      /      N-M  M        L-N |
           -----      \        -----  -----                    /
            L=1                 N=0    M=0

        From this we immediately deduce the recursion relation

                      L-1                 N
                     -----              -----
                     \       L-N        \
           b  = a  +  >     ----- a      >    b    b  .  (**)
            L    L   /        L    L-N  /      N-M  M
                     -----              -----
                      N=0                M=0

        This relation is easily generalized to the case of a
        series in more than one variable, where the same comments
        apply as in the case of log and exp above.

        For the hyperbolic tangent the relation is nearly the same.
        Since its differential equation has a `-' where that of
        tangent has a `+' we simply have to do the same substitution
        in the relation (**).  For the cotangent we get an additional
        overall minus sign.

        There is one additional problem to be handled: if the constant
        term of T(x), i.e. T(x0) is a pole of tangent. This can be
        solved quite easily: for a small quantity TAYEPS we calculate

             Te(x) = T(x) + TAYEPS .

        and perform the above calculation for Te(x). Then we recover
        the desired result via the relation

            tan T(x)  = tan (Te(x) - TAYEPS)

                           tan Te(x) - tan TAYEPS
                      = ---------------------------- .
                         1 + tan Te(x) * tan TAYEPS

        For the other functions we have similar relations:

            tanh T(x) = tanh (Te(x) - TAYEPS)

                           tanh Te(x) - tanh TAYEPS
                      = ------------------------------ ,
                         1 - tanh Te(x) * tanh TAYEPS

            cot T(x)  = cot (Te(x) - TAYEPS)

                         1 + cot Te(x) * cot TAYEPS
                      = ---------------------------- ,
                           cot TAYEPS - cot Te(x)

            coth T(x) = coth (Te(x) - TAYEPS)

                         1 - coth Te(x) * coth TAYEPS
                      = ------------------------------ .
                           coth Te(x) - coth TAYEPS

        We know that this result is independent of TAYEPS, and we can
        thus evaluate it for any value of TAYEPS.

        Since we further know that T(x0) is a pole of the function in
        question, we can express tan (T(x0) + TAYEPS) as

                                1
                        - ------------ ,
                           tan TAYEPS

        and similarly all the other possible expressions involving
        TAYEPS can be written in terms of tan TAYEPS and tanh TAYEPS,
        respectively. This makes it possible to just substitute any
        occurrence of tan TAYEPS or tanh TAYEPS by zero, which greatly
        simplifies the final calculation

        ;

% I rather suspect that the idea here is to create a symbol whose name is
% tayexp but that is not interned and hence could not clash with any user
% symbol that happened to have that name. Rather than relying on an
% uninterned symbol I will just use one with an unusual name.

!*!*taylor!-epsilon!*!* := '!~tayeps!~;

symbolic procedure taysimptan u;
  %
  % Special Taylor expansion function for circular and hyperbolic
  %  tangent and cotangent
  %
  if not (car u memq '(tan cot tanh coth)) or cddr u
    then confusion 'taysimptan
   else taylor!:
    begin scalar a,a0,clist,coefflis,il,l0,l,poleflag,tay,tp;
    tay := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p tay
      then return mksq({car u,mk!*sq tay},1);
    tay := mvar numr tay;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % First we get rid of possible zero coefficients.
    %
    l := prune!-coefflist taycoefflist tay;
%    if null l then return !*tay2q cst!-Taylor!*(simp!* {car u,0},tp);
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    if not null l and is!-neg!-pl taycfpl car l
      then taylor!-error('essential!-singularity,car u);
    a0 := taygetcoeff(l0,l);
    il := if null l then nlist(1,length tp)
           else smallest!-increment l;
    %
    %%% handle poles of function
    %
    a := quotsq(a0,simp 'pi);
    if car u memq '(tanh coth) then a := subs2!* multsq(a,simp 'i);
    if car u memq '(tan tanh) and
       denr(a := multsq(a,simp '2)) = 1 and
       fixp (a := numr a) and not evenp a
       or car u memq '(cot coth) and denr a = 1 and
          (null (a := numr a) or fixp a)
      then <<
        %
        % OK, now we are at a pole, so we add a small quantity, compute
        %  the series and use the addition formulas to get the real
        %  result.
        %
        poleflag := t;
        a0 := if car u eq 'tan
                then negsq invsq simp!* {'tan,!*!*taylor!-epsilon!*!*}
               else if car u eq 'tanh
                then invsq simp!* {'tanh,!*!*taylor!-epsilon!*!*}
               else if car u eq 'cot
                then invsq simp!* {'tan,!*!*taylor!-epsilon!*!*}
               else invsq simp!* {'tanh,!*!*taylor!-epsilon!*!*};
        clist := {taymakecoeff(l0,a0)};
        >>
     else clist := {taymakecoeff(l0,simp!* {car u,mk!*sq a0})};
    %
    coefflis := makecoeffs0(tp,tpnextlist tp,il);

    if not null coefflis
      then for each cc in cdr coefflis do
             begin scalar cf,s,pos,x,y,n,n1;
               s := nil ./ 1;
               pos := find!-non!-zero cc;
               n := nth(nth(cc,car pos),cdr pos);
               for each p in makecoeffpairs(l0,cc,l0,il) do <<
                 x := reversip makecoeffpairs1(l0,car p,l0,il);
                 y := nil ./ 1;
                 for each z in x do
                   y := addsq(y,multsq(taygetcoeff(car z,clist),
                                       taygetcoeff(cdr z,clist)));
                 n1 := nth(nth(car p,car pos),cdr pos);
                 s := addsq(s,
                            multsq(!*TayExp2q(n - n1),
                                   multsq(y,taygetcoeff(cdr p,l))))>>;
               cf := quotsq(s,!*TayExp2q n);
               if car u memq '(tanh coth) then cf := negsq cf;
               cf := addsq(taygetcoeff(cc,l),cf);
               if null numr cf then return;  % short cut for efficiency
               if car u eq 'cot then cf := negsq cf;
               clist := taymakecoeff(cc,cf) . clist
             end;
    a := make!-taylor!*(reversip clist,tp,nil,nil);
    %
    % Construct ``real'' series in case of pole
    %
    if poleflag then begin scalar x;
       x := if car u eq 'cot
              then cst!-taylor!*(
                     invsq simp {'tan,!*!*taylor!-epsilon!*!*},tp)
             else if car u eq 'coth
              then cst!-taylor!*(
                     invsq simp {'tanh,!*!*taylor!-epsilon!*!*},tp)
             else cst!-taylor!*(
                     simp {car u,!*!*taylor!-epsilon!*!*},tp);

       if car u eq 'tan then
         a := quottaylor(addtaylor(a,negtaylor x),
                         addtaylor(cst!-taylor!*(1 ./ 1,tp),
                                   multtaylor(a,x)))
        else if car u eq 'cot then
         a := quottaylor(addtaylor(multtaylor(a,x),
                                   cst!-taylor!*(1 ./ 1,tp)),
                         addtaylor(x,negtaylor a))
        else if car u eq 'tanh then
         a := quottaylor(addtaylor(a,negtaylor x),
                         addtaylor(cst!-taylor!*(1 ./ 1,tp),
                                   negtaylor multtaylor(a,x)))
        else if car u eq 'coth then
         a := quottaylor(addtaylor(multtaylor(a,x),
                                   cst!-taylor!*(-1 ./ 1,tp)),
                         addtaylor(x,negtaylor a));

        if not (a freeof !*!*taylor!-epsilon!*!*)
          then set!-taycoefflist(a,
                  for each pp in taycoefflist a collect
                    taymakecoeff(taycfpl pp,
                                 subsq(taycfsq pp,
                                       {!*!*taylor!-epsilon!*!* . 0})));
      end;
    %
    if !*taylorkeeporiginal and tayorig tay
      then set!-tayorig(a,simp {car u,mk!*sq tayorig tay});
    set!-tayflags(a,tayflags tay);
    return !*tay2q a
  end;

put('tan,'taylorsimpfn,'taysimptan);
put('cot,'taylorsimpfn,'taysimptan);
put('tanh,'taylorsimpfn,'taysimptan);
put('coth,'taylorsimpfn,'taysimptan);



COMMENT For the circular sine and cosine and their reciprocals
        we calculate the exponential and use it via the formulas


                     exp(+I*x) - exp(-I*x)
            sin x = ----------------------- ,
                               2

                     exp(+I*x) + exp(-I*x)
            cos x = ----------------------- ,
                               2

        etc. To avoid clumsy expressions we separate the constant term
        of the argument,

               T(x) = a0 + T1(x),

        and use the addition theorems which give

                       1
            sin T(x) = - exp(+I*T1(x)) * (sin a0 - I*cos a0) +
                       2

                       1
                       - exp(-I*T1(x)) * (sin a0 + I*cos a0) ,
                       2

                       1
            cos T(x) = - exp(+I*T1(x)) * (cos a0 + I*sin a0) +
                       2

                       1
                       - exp(-I*T1(x)) * (cos a0 - I*sin a0) .
                       2

        ;


symbolic procedure taysimpsin u;
  %
  % Special Taylor expansion function for circular sine, cosine,
  %  and their reciprocals
  %
  if not (car u memq '(sin cos sec csc)) or cddr u
    then confusion 'taysimpsin
   else taylor!:
    begin scalar l,tay,result,result2,tp,i1,l0,a0,a1,a2;
    tay := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p tay
      then return mksq({car u,mk!*sq tay},1);
    tay := mvar numr tay;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    l := prune!-coefflist taycoefflist tay;
%    if null l then return !*tay2q cst!-Taylor!*(simp!* {car u,0},tp);
%    if is!-neg!-pl TayCfPl car l
%      then Taylor!-error('essential!-singularity,car u);
    a0 := taygetcoeff(l0,l);
    %
    % make constant term to 0
    %
    i1 := simp 'i;
    if not null numr a0
      then tay := addtaylor(tay,cst!-taylor!*(negsq a0,tp));
    result := taysimpexp{'exp,multtaylor(tay,cst!-taylor!*(i1,tp))};
    result2 := taysimpexp{'exp,multtaylor(tay,cst!-taylor!*(negsq i1,tp))};
    a1 := simp!* {'sin,mk!*sq a0} . simp!* {'cos,mk!*sq a0};
    if car u memq '(sin csc) then <<
      a2 := addsq(car a1,multsq(i1,cdr a1));
      a1 := addsq(car a1,negsq multsq(i1,cdr a1));
      >>
     else <<
      a2 := addsq(cdr a1,negsq multsq(i1,car a1));
      a1 := addsq(cdr a1,multsq(i1,car a1));
     >>;
    result := multsq(addsq(multsq(result,a1),
                           multsq(result2,a2)),
                     1 ./ 2);
    if car u memq '(sec csc) then <<
       if null numr result then taylor!-error!*('not!-a!-unit,u)
        else result := invsq result;
    >>
     else if null numr result then return !*tay2q cst!-taylor!*(result,tp);
    return taysimpsq!* result
  end;


put('sin,'taylorsimpfn,'taysimpsin);
put('cos,'taylorsimpfn,'taysimpsin);
put('sec,'taylorsimpfn,'taysimpsin);
put('csc,'taylorsimpfn,'taysimpsin);



COMMENT For the hyperbolic sine and cosine and their reciprocals
        we calculate the exponential and use it via the formulas


                     exp(+x) - exp(-x)
           sinh x = ------------------- ,
                             2

                     exp(+x) + exp(-x)
           cosh x = ------------------- ,
                             2

        etc. To avoid clumsy expressions we separate the constant term
        of the argument,

               T(x) = a0 + T1(x),

        and use the addition theorems which give

                        1
            sinh T(x) = - exp(+T1(x)) * (sinh a0 + cosh a0) +
                        2

                        1
                        - exp(-T1(x)) * (sinh a0 - cosh a0) ,
                        2

                        1
            cosh T(x) = - exp(+T1(x)) * (cosh a0 + sinh a0) +
                        2

                        1
                        - exp(-T1(x)) * (cosh a0 - sinh a0) .
                        2
        ;


symbolic procedure taysimpsinh u;
  %
  % Special Taylor expansion function for circular sine, cosine,
  %  and their reciprocals
  %
  if not (car u memq '(sinh cosh sech csch)) or cddr u
    then confusion 'taysimpsin
   else taylor!:
    begin scalar l,tay,result,result2,tp,l0,a0,a1,a2;
    tay := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p tay
      then return mksq({car u,mk!*sq tay},1);
    tay := mvar numr tay;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    l := prune!-coefflist taycoefflist tay;
%    if null l then return !*tay2q cst!-Taylor!*(simp!* {car u,0},tp);
%    if is!-neg!-pl TayCfPl car l
%      then Taylor!-error('essential!-singularity,car u);
    a0 := taygetcoeff(l0,l);
    %
    % make constant term to 0
    %
    if not null numr a0
      then tay := addtaylor(tay,cst!-taylor!*(negsq a0,tp));
    result := taysimpexp{'exp,tay};
    result2 := taysimpexp{'exp,negtaylor tay};
    a1 := simp!* {'sinh,mk!*sq a0} . simp!* {'cosh,mk!*sq a0};
    if car u memq '(sinh csch) then <<
      a2 := addsq(car a1,cdr a1);
      a1 := subtrsq(car a1,cdr a1);
      >>
     else <<
      a2 := addsq(cdr a1,car a1);
      a1 := subtrsq(cdr a1,car a1);
     >>;
    result := multsq(addsq(multsq(result,a2),
                           multsq(result2,a1)),
                     1 ./ 2);
    if car u memq '(sech csch) then <<
       if null numr result then taylor!-error!*('not!-a!-unit,u)
        else result := invsq result;
    >>
     else if null numr result then return !*tay2q cst!-taylor!*(result,tp);
    return taysimpsq!* result
  end;


put('sinh, 'taylorsimpfn, 'taysimpsinh);
put('cosh, 'taylorsimpfn, 'taysimpsinh);
put('sech, 'taylorsimpfn, 'taysimpsinh);
put('csch, 'taylorsimpfn, 'taysimpsinh);


COMMENT Support for the integration of Taylor kernels.
        Unfortunately, with the current interface, only Taylor kernels
        on toplevel can be treated successfully.

        The way it is down means stretching certain interfaces beyond
        what they were designed for...but it works!

        First we add a rule that replaces a call to INT with a Taylor
        kernel as argument by a call to TAYLORINT, then we define
        REVALTAYLORINT as simplification function for that;


algebraic let {

  int(symbolic algebraic(taylor!*(~x,~y,~z,~w)),~u)
      => taylorint(~x,~y,~z,~w,~u),

  int(log(~u)^~~n * symbolic algebraic(taylor!*(~x,~y,~z,~w)),~u)
      => log(u)^n * int(symbolic('(taylor!* x y z w)),u)
          - int(log(u)^(n-1)
             * taylorcombine(int(symbolic('(taylor!* x y z w)),u)/u),u),

  int(~x,~y) => taylorint1(~x,~y)
                  when not symbolic algebraic(~x freeof 'taylor!*)
};


put('taylorint1, 'psopfn, 'revaltaylorint1);

symbolic procedure revaltaylorint1 x;
  begin scalar u,v;
    u := car x;
    v := cadr x;
    if taylor!*p u then return revaltaylorint append(cdr u,{v});
    u := reval taylorcombine u;
    if taylor!*p u then return revaltaylorint append(cdr u,{v});
    if not atom u
      then if car u memq '(plus minus difference)
             then return
                    reval (car u . for each term in cdr u collect
                                     {'int,term,v});
    lprim "Converting Taylor kernels to standard representation";
    return aeval {'int,taylortostandard car x,v}
  end;

put('taylorint, 'psopfn, 'revaltaylorint);

symbolic procedure revaltaylorint u;
  begin scalar taycfl, taytp, tayorg, tayflgs, var;
    taycfl := car u;
    taytp := cadr u;
    tayorg := caddr u;
    tayflgs := cadddr u;
    var := car cddddr u;
    if null (var member taytpvars taytp)
      then return mk!*sq !*tay2q
            make!-taylor!*(
              for each pp in taycfl collect
                taycfpl pp . simp!* {'int,mk!*sq taycfsq pp,var},
              taytp,
              if not null tayorg
                then simp!* {'int,mk!*sq tayorg,var}
               else nil,
            nil)
     else return mk!*sq
            ((if null car result then !*tay2q cdr result
               else addsq(car result,!*tay2q cdr result))
             where result := inttaylorwrttayvar1(taycfl,taytp,var))
   end;

endmodule;

end;
