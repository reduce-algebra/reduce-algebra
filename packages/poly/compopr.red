module compopr;   % Operators on Complex Expressions.

% Author: Eberhard Schruefer.
% Modifications by:  Francis Wright, Rainer Schoepf & Alan Barnes.

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


fluid '(!*exp !*factor kord!*);

put('repart,'simpfn,'simprepart);

symbolic procedure simprepart u;
   repartsq simp!* car u where !*factor = nil;

symbolic procedure repartsq u;
   multsq(addsq(multsq(repartnum,repartden),
                multsq(impartnum,impartden)),
          invsq addsq(multsq(repartden,repartden),
                      multsq(impartden,impartden)))
   where repartnum = car reimnum, impartnum = cdr reimnum,
         repartden = car reimden, impartden = cdr reimden
   where reimnum = splitcomplex numr u,
         reimden = splitcomplex denr u;

put('impart,'simpfn,'simpimpart);

symbolic procedure simpimpart u;
   impartsq simp!* car u where !*factor = nil;

symbolic procedure impartsq u;
   multsq(addsq(multsq(impartnum,repartden),
                negsq multsq(repartnum,impartden)),
          invsq addsq(multsq(repartden,repartden),
                      multsq(impartden,impartden)))
   where repartnum = car reimnum, impartnum = cdr reimnum,
         repartden = car reimden, impartden = cdr reimden
   where reimnum = splitcomplex numr u,
         reimden = splitcomplex denr u;

put('conj,'simpfn,'simpconj);

symbolic procedure simpconj u;
   conjsq simp!* car u;

symbolic procedure conjsq u;
  (if null numr w then u else addsq(repartsq u,negsq multsq(simp 'i,w)))
   where w=impartsq u;

inline procedure idomainp; get('i,'idvalfn);
  % Tests if 'i' is transformed to a domain structure.

symbolic procedure splitcomplex u;
   (begin scalar v;
      v := if idomainp() then expand!-imrepart u
            else <<if smemq('i,u) then
                   <<setkorder('i . kord!*); u:=reorder u>>;
                   subs2 expand!-imrepart u>>;
      return take!-realpart v . take!-impart v
    end) where kord!* = kord!*,!*exp = t;

symbolic procedure expand!-imrepart u;
   if domainp u then u ./ 1
    else addsq(multsq(expand!-imrepartpow lpow u,
                      expand!-imrepart lc u),
               expand!-imrepart red u);

symbolic procedure expand!-imrepartpow u;
   % This needs to treat kernels that are standard forms smarter.
   % At the moment, we expand to get the required result.
   begin scalar !*exp,cmpxsplitfn;
     !*exp := t;
     cmpxsplitfn := null idp car u and
                    get(car car u,'cmpxsplitfn);
     return
       exptsq(if null cmpxsplitfn
                 then if car u eq 'i then !*k2q 'i
                       else addsq(mkrepart car u,
                                  multsq(simp 'i,
                                         mkimpart car u))
               else apply1(cmpxsplitfn,car u),cdr u)
    end;

symbolic procedure mkrepart u;
   if realvaluedp u then !*k2q u
    else if sfp u then repartsq(u ./ 1)
    else mksq(list('repart, u),1);

symbolic procedure mkimpart u;
   if realvaluedp u then nil ./ 1
    else if sfp u then impartsq(u ./ 1)
    else mksq(list('impart, u),1);

symbolic procedure take!-realpart u;
% real part of numerator and the denominator may have a common factor 
% so must use multsq here
%   repartf numr u ./ denr u;
   multsq(repartf(numr u) ./ 1, 1 ./ denr u);

symbolic procedure repartf u;
   % We can't check for null dmode!* as there may still be complex
   % domain elements in the expression (e.g., e^repart x).
  (if domainp u
      then if atom u then u
            else if get(car u,'cmpxfn)
            % We now know u is of form (<tag> <re> . <im>).
              then int!-equiv!-chk(car u . cadr u .
                        cadr apply1(get(car u,'i2d),0))
        % Otherwise we assume it is real
       else u
    else if mvar u eq 'i then repartf red u
%    else if null dmode!* then addf(!*t2f lt u,repartf red u)
    else addf(multpf(lpow u,repartf lc u),repartf red u))
       where u = reorder u where kord!* = 'i . kord!*;

symbolic procedure take!-impart u;
% imaginary part of numerator and the denominator may have a common factor 
% so must use multsq here
%   impartf numr u ./ denr u;
   multsq(impartf(numr u) ./ 1, 1 ./ denr u);

symbolic procedure impartf u;
   % We can't check for null dmode!* as there may still be complex
   % domain elements in the expression.
  (if domainp u
     then if atom u then nil
           else if get(car u,'cmpxfn)
            % We now know u is of form (<tag> <re> . <im>).
             then int!-equiv!-chk(car u . cddr u .
                                  cadr apply1(get(car u,'i2d),0))
        % Otherwise we assume it is real
       else nil
    else if mvar u eq 'i then addf(lc u,impartf red u)
%   else if null dmode!* then impartf red u
    else addf(multpf(lpow u,impartf lc u),impartf red u))
       where u = reorder u where kord!* = 'i . kord!*;

% The following code attempts to improve the way that the complex
% operators CONJ, REPART and IMPART handle values that are implicitly
% real, namely composed "reality-preserving" functions of explicitly
% real numbers, implicitly real symbolic constants and variables that
% the user has declared using the REALVALUED command defined below.

% All arithmetic operations, direct trig functions and the exponential
% function are "reality-preserving", but inverse trig functions and the
% logarithm are "reality-preserving" only for real arguments in a
% restricted range.  This relates to piecewise-defined functions!  This
% code is believed to make the right decision about implicit reality in
% straightforward cases, and otherwise errs on the side of caution and
% makes no assumption at all, as does the standard REDUCE 3.4 code.  It
% performs only very limited numerical evaluation, which should be very
% fast.  It never performs any approximate numerical evaluation, or any
% sophisticated analysis, both of which would be much slower and/or
% complicated.  The current strategy is believed to represent a
% reasonable compromise, and will normally give the user what they
% expect without undue overhead.

rlistat '(realvalued notrealvalued);   % Make user operators.

symbolic procedure realvalued u;
   % Command to allow the user to declare functions or variables to be
   % implicitly real valued.
   <<rmsubs();  % So that an expression can be re-evaluated.
     for each v in u do
        if not idp v then typerr(v,"id")
         else flag(list v,'realvalued)>>;

symbolic procedure notrealvalued u;
   % Undo realvalued declaration.
   % Cannot recover "complexity", so no need for rmsubs().
   for each v in u do
      if not idp v then typerr(v,"id")
       else remflag(list v, 'realvalued);

flag('(realvaluedp),'boolean); % Make realvaluedp available in
                               % algebraic mode.

symbolic procedure realvaluedp u;
   % True if the true prefix kernel form u is explicitly or implicitly
   % real-valued.
   if atom u then numberp u or flagp(u, 'realvalued)
   else begin scalar caru; % cnd
     return
      flagp((caru := car u), 'alwaysrealvalued)
         % real-valued for all possible argument values
      or (flagp(caru, 'realvalued) and realvaluedlist cdr u)
         % real-valued function if arguments are real-valued,
         % an important common special case of condrealvalued.
%%      or ((cnd := get(caru, 'condrealvalued)) and apply(cnd, cdr u))
         % real-valued function if arguments satisfy conditions
         % that depend on the function
      or caru eq '!:rd!:;  % rounded number - least likely?
   end;

symbolic procedure realvaluedlist u;
   % True if every element of the list u of true prefix kernel forms
   % is real-valued.
   realvaluedp car u and (null cdr u or realvaluedlist cdr u);

% Define the real valued properties
% ---------------------------------

% Only operators that can remain symbolic need be considered,
% e.g. NOT nextprime, num, den, deg, det.

% A very small number of functions are real-valued for ALL arguments:

flag('(repart impart abs ceiling floor fix round max min),
     'alwaysrealvalued);

% Symbolic constants:

flag('(pi e infinity),'realvalued);

% Some functions are real-valued if all their arguments are
% real-valued, without further constraints:

% Arithmetic operators:

flag('(plus minus times quotient), 'realvalued);

% Elementary transcendental functions, etc:

flag('(exp cbrt hypot sin cos tan csc sec cot sind cosd tand cscd secd
       cotd sinh cosh tanh csch sech coth atan atand atan2 atan2d acot
       acotd asinh acsch factorial),
     'realvalued);

% Additional such variables and functions can be declared by the user
% with the REALVALUED command defined above.


put('sin,'cmpxsplitfn,'reimsin);

symbolic procedure reimsin u;
   addsq(multsq(simp list('sin,rearg),
                simp list('cosh,imarg)),
         multsq(simp 'i,
                multsq(simp list('cos,rearg),
                       simp list('sinh,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

put('sinh,'cmpxsplitfn,'reimsinh);

symbolic procedure reimsinh u;
   addsq(multsq(simp list('sinh,rearg),
                simp list('cos,imarg)),
         multsq(simp 'i,
                multsq(simp list('cosh,rearg),
                       simp list('sin,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

put('cos,'cmpxsplitfn,'reimcos);

symbolic procedure reimcos u;
   addsq(multsq(simp list('cos,rearg),
                simp list('cosh,imarg)),
         multsq(simp 'i,negsq
                multsq(simp list('sin,rearg),
                       simp list('sinh,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

put('cosh,'cmpxsplitfn,'reimcosh);

symbolic procedure reimcosh u;
   addsq(multsq(simp list('cosh,rearg),
                simp list('cos,imarg)),
         multsq(simp 'i,
                multsq(simp list('sinh,rearg),
                       simp list('sin,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

      
put('expt,'cmpxsplitfn,'reimexpt);

% symbolic procedure reimexpt u;
%    if cadr u eq 'e %or numberp cadr u
%      then multsq(simp {'exp,{'times,{'log,cadr u},prepsq simprepart cddr u}},
%                  addsq(reimcos {'cos,imarg},
%                        multsq(simp 'i,reimsin {'sin,imarg})))
%             where imarg = {'times,{'log,cadr u},prepsq simpimpart cddr u}
% %     then addsq(reimcos list('cos,reval list('times,'i,caddr u)),
% %                multsq(simp list('minus,'i),
% %                    reimsin list('sin,reval list('times,'i,caddr u))))
%     else if fixp cadr u and cadr u > 0
%               and eqcar(caddr u,'quotient)
%               and fixp cadr caddr u
%               and fixp caddr caddr u
%      then mksq(u,1)
%     else addsq(mkrepart u,multsq(simp 'i,mkimpart u));

% This normally returns the principal value for complex arguments including
% cases with a rational real exponent. However, for (powers of) the nth root 
% (n odd) of a real negative number, it returns a real value.
% This is due to simplifications performed by simpexpt prior to the call
% of reimexpt.
%
% Thus, for example, 
%     x := repart((-2)^(u+i*v)); x where u => 1/3, v=>0;
% produces the real part of  the (complex) principal value whereas
%     x := repart((-2)^(1/3));
% produces the real negative cube root.
% cf the numerical evaluation od (-2)^(1/3) after on rounded; 
%   compared with the behaviour after on rounded, complex;
symbolic procedure reimexpt u;
  begin scalar x, y, v, w, z1, z2;
    x := reimlog{'log, cadr u};
    y := prepsq take!-impart x;
    x := prepsq take!-realpart x;
    v := prepsq simprepart cddr u;
    w := prepsq simpimpart cddr u;
    z1 := simp {'exp, {'difference, {'times, x, v}, {'times, y, w}}};
    z2 := {'plus, {'times, x, w}, {'times, y, v}};
    return
      multsq(z1, addsq(simp{'cos, z2}, multsq(simp 'i, simp{'sin, z2}))); 
  end;

put('sqrt, 'cmpxsplitfn, 'reimsqrt);

% only called when !*keepsqrts is true
symbolic procedure reimsqrt u;
   reimexpt {'expt, cadr u, {'quotient, 1, 2}};

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The procedures below were added by Alan Barnes to handle tan, tanh, cot,
% coth, sec, csc, sech, csch.
% They all return results in terms of sin, cos, sinh and cosh of 
% the real and imaginary parts of the argument of the function concerned. 
% There are several equivalent ways of expressing the denominators;
% below denominators are always expressed as the sum of 2 squares 

put('tan,'cmpxsplitfn,'reimtan);

symbolic procedure reimtan u;
begin scalar rearg, imarg, sinx, sinhy, cosx, coshy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinx  := simp {'sin, rearg};
   sinhy := simp {'sinh, imarg};
   cosx  := simp {'cos, rearg};
   coshy := simp {'cosh, imarg};

   return quotsq(
      addsq(multsq(sinx, cosx),
            multsq(simp 'i, multsq(sinhy, coshy))),
      addsq(multsq(cosx, cosx), multsq(sinhy, sinhy)));
end;

put('tanh,'cmpxsplitfn,'reimtanh);

symbolic procedure reimtanh u;
begin scalar rearg, imarg, sinhx, siny, coshx, cosy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinhx := simp {'sinh, rearg};
   siny  := simp {'sin, imarg};
   coshx := simp {'cosh, rearg};
   cosy  := simp {'cos, imarg};

   return quotsq(
      addsq(multsq(sinhx, coshx),
            multsq(simp 'i, multsq(siny, cosy))),
      addsq(multsq(cosy, cosy), multsq(sinhx, sinhx)));
end;

put('cot,'cmpxsplitfn,'reimcot);

symbolic procedure reimcot u;
begin scalar rearg, imarg, sinx, sinhy, cosx, coshy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinx  := simp {'sin, rearg};
   sinhy := simp {'sinh, imarg};
   cosx  := simp {'cos, rearg};
   coshy := simp {'cosh, imarg};

   return quotsq(
      addsq(multsq(sinx, cosx),
            multsq(simp 'i, negsq multsq(sinhy, coshy))),
      addsq(multsq(sinhy, sinhy), multsq(sinx, sinx)));
end;

put('coth,'cmpxsplitfn,'reimcoth);

symbolic procedure reimcoth u;
begin scalar rearg, imarg, sinhx, siny, coshx, cosy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinhx := simp {'sinh, rearg};
   siny  := simp {'sin, imarg};
   coshx := simp {'cosh, rearg};
   cosy  := simp {'cos, imarg};

  return quotsq(
      addsq(multsq(sinhx, coshx),
            multsq(simp 'i, negsq multsq(siny, cosy))),
      addsq(multsq(sinhx, sinhx), multsq(siny, siny)));
end;

put('sec,'cmpxsplitfn,'reimsec);

symbolic procedure reimsec u;
begin scalar rearg, imarg, sinx, sinhy, cosx, coshy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinx  := simp {'sin, rearg};
   sinhy := simp {'sinh, imarg};
   cosx  := simp {'cos, rearg};
   coshy := simp {'cosh, imarg};

   return quotsq(
      addsq(multsq(cosx, coshy),
            multsq(simp 'i, multsq(sinx, sinhy))),
      addsq(multsq(cosx, cosx), multsq(sinhy, sinhy)));
end;

put('sech,'cmpxsplitfn,'reimsech);

symbolic procedure reimsech u;
begin scalar rearg, imarg, sinhx, siny, coshx, cosy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinhx := simp {'sinh, rearg};
   siny  := simp {'sin, imarg};
   coshx := simp {'cosh, rearg};
   cosy  := simp {'cos, imarg};

   return quotsq(
      addsq(multsq(coshx, cosy),
            multsq(simp 'i, negsq multsq(sinhx, siny))),
      addsq(multsq(cosy, cosy), multsq(sinhx, sinhx)));
end;

put('csc,'cmpxsplitfn,'reimcsc);

symbolic procedure reimcsc u;
begin scalar rearg, imarg, sinx, sinhy, cosx, coshy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinx  := simp {'sin, rearg};
   sinhy := simp {'sinh, imarg};
   cosx  := simp {'cos, rearg};
   coshy := simp {'cosh, imarg};

   return quotsq(
      addsq(multsq(sinx, coshy),
            multsq(simp 'i, negsq multsq(cosx, sinhy))),
      addsq(multsq(sinhy, sinhy), multsq(sinx, sinx)));
end;

put('csch,'cmpxsplitfn,'reimcsch);

symbolic procedure reimcsch u;
begin scalar rearg, imarg, sinhx, siny, coshx, cosy;
   rearg := prepsq simprepart cdr u;
   imarg := prepsq simpimpart cdr u;
   sinhx := simp {'sinh, rearg};
   siny  := simp {'sin, imarg};
   coshx := simp {'cosh, rearg};
   cosy  := simp {'cos, imarg};

  return quotsq(
      addsq(multsq(sinhx, cosy),
            multsq(simp 'i, negsq multsq(coshx, siny))),
      addsq(multsq(sinhx, sinhx), multsq(siny, siny)));
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Inverse Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

put('log,'cmpxsplitfn,'reimlog);
put('log10,'cmpxsplitfn,'reimlog);

% When Re(x) is a number in log(x), there is no point in computing the squares
% and square roots. Return log(abs(x)) as real part.
% This improves simplification of, e.g., repart(log(5)) and repart(log(-5))
% which both used to return log(25)/2
symbolic procedure reimlog u;
  (addsq(if imarg=0 then simp {op, {'abs, rearg}}
          else if rearg=0 then simp {op, {'abs, imarg}}
          else simp {'quotient, {op, {'plus, {'expt, rearg, 2},
                                               {'expt, imarg , 2}}}, 2},
         multsq(simp if op='log10 then '(quotient i (log 10)) else 'i,
                simp {'atan2, imarg, rearg})))
   where op = car u,
         rearg = prepsq simprepart cdr u,
      	 imarg = prepsq simpimpart cdr u;

% Subsidiary function called from next three split functions
% Returns a dotted pair of the arguments for acos and acosh resp.
% The first value is guaranteed to be in the range [-1, +1] 
% and the second is always >= 1
symbolic procedure invfn!-args(x, y);
  if x=0 then 1 . {'plus, 1, {'times, 2, {'expt, y, 2}}}
  else
    begin scalar ssq, sroot;
       ssq :=  simp {'plus, {'expt, x, 2}, {'expt, y, 2}};
       if y=0 then 
         sroot := simp {'abs, {'plus, prepsq ssq, -1}}
       else
         sroot := simp {'sqrt, {'plus, {'expt, {'plus, prepsq ssq, -1}, 2},
                                       {'times, 4, {'expt, y, 2}}}};
       return
         (prepsqxx addsq(sroot, negsq ssq)) . (prepsqx addsq(ssq, sroot));
end;

% The split functions below for asin, acos, asinh and acosh do not use the 
% split function for log and the identities of these functions 
% in terms of logarithm; this generally leads to expressions involving 
% nested square roots.
% Instead they calculate the real and imaginary parts of the form 
% acos(R1)/2 & acosh(R2)/2 where R1 & R2 are real with |R1| <=1 & |R2|>=1.
% Then they choose the correct branch by examining the signs of the real &
% imaginary parts of the the argument. This avoids nested sqare roots but
% for a non-numeric  argument involes rather messy expressions involving the
% sign operator applied to the real and imaginary parts of the argument. 

put('asin, 'cmpxsplitfn, 'reimasin);
put('acos, 'cmpxsplitfn, 'reimasin);

symbolic procedure reimasin u;
begin scalar rearg, imarg, x, y, sr, si, op;
  rearg := prepsq simprepart cdr u;
  imarg := prepsq simpimpart cdr u;
  op := car u;
  (if rearg=0 then 
     if op='asin then return res
     else if op='acos then
        return addsq(simp {'quotient, 'pi, 2}, negsq res))
   where res= simp {'times, 'i, {'asinh, imarg}};

  y := invfn!-args(rearg, imarg);

% testing car and cdr here improves the handling of purely numerical real args
  if cdr y = 1 then  % |rearg| <= 1 & imarg=0
     return simp {op, rearg}
  else if car y = -1 then <<  % |rearg| > 1 amd imarg=0
     x := simp {'quotient, 'pi, 2};
     y := simp {'acosh, {'abs, rearg}}>>
  else <<
    x := simp {'quotient, {'acos, car y}, 2};
    y := simp {'quotient, {'acosh, cdr y}, 2}>>;  

  sr := simp!-sign1 rearg;
  si := simp!-sign1 imarg;

  % Multiply x by sr if sr neq 0 and by 1 if sr=0
  x := multsq(x, addsq(1 ./ 1, multsq(sr, addsq(1 ./ 1, negsq sr)))); 
  % Multiply y by si if si neq 0 and by -sr if si=0
  y := multsq(y, addsq(si, 
                       multsq(sr, addsq(multsq(si, si), (-1) ./ 1))));

  (if op='asin then return res
   else if op='acos then return addsq(simp {'quotient, 'pi, 2}, negsq res))  
     where res = addsq(x, multsq(simp 'i, y));
end;

put('asinh, 'cmpxsplitfn, 'reimasinh);

symbolic procedure reimasinh u;
begin scalar rearg, imarg, x, y, sr, si;
  rearg := prepsq simprepart cdr u;
  imarg := prepsq simpimpart cdr u;
  if imarg=0 then return simp {'asinh, rearg};
  x := invfn!-args(imarg, rearg);

% testing car and cdr here improves the handling of purely numerical imag args
  if cdr x = 1 then  % |imarg| <= 1 & rearg=0
     return simp {'times, 'i, {'asin, imarg}}
  else if car x = -1 then <<  % |imarg| > 1 amd rearg=0
     x := simp {'acosh, {'abs, imarg}};
     y := simp {'quotient, 'pi, 2}>>
  else <<
     y := simp {'quotient, {'acos, car x}, 2};
     x := simp {'quotient, {'acosh, cdr x}, 2}>>;

  sr := simp!-sign1 rearg;
  si := simp!-sign1 imarg;

  % Multiply y by si if si neq 0 and by 1 if si=0
  y := multsq(y, addsq(1 ./ 1, multsq(si, addsq(simp 1, negsq si))));
  % Multiply x by sr if sr neq 0 and by si if sr=0
  x := multsq(x, addsq(sr, 
                       multsq(si, addsq(negsq multsq(sr, sr), 1 ./ 1))));

  return addsq(x, multsq(simp 'i, y));
end;

put('acosh, 'cmpxsplitfn, 'reimacosh);

symbolic procedure reimacosh u;
begin scalar rearg, imarg, x, y, sr, si;
  rearg := prepsq simprepart cdr u;
  imarg := prepsq simpimpart cdr u;
  x := invfn!-args(rearg, imarg);

% testing car and cdr here improves the handling of purely numerical
% real and args
  if rearg=0  then <<
     x := simp {'asinh, {'abs, imarg}};
     y := simp {'quotient, 'pi, 2} >>
  else if car x = -1 then << % imarg=0 & |rearg| >=1
     y := nil ./ 1;
     x := simp {'acosh, {'abs, rearg}} >>
  else if cdr x = 1 then << % imarg=0 & |rearg| < 1
     y := simp {'acos, {'abs, rearg}};
     x := nil ./ 1 >>
  else <<
     y := simp {'quotient, {'acos, {'minus, car x}}, 2};
     x := simp {'quotient, {'acosh, cdr x}, 2} >>;

  sr := simp!-sign1 rearg;
  si := simp!-sign1 imarg;

  % leave y unchanged when sr=1 or sr=0 else y := pi-y when sr=-1
  y := addsq(y, (multsq(multsq(sr, addsq(sr, (-1) ./ 1)), 
                        addsq(simp {'quotient, 'pi, 2}, negsq y))));
  % Now multiply y by si if si neq 0 and by 1 if si=0 
  y := multsq(y, addsq(1 ./ 1, multsq(si, addsq(1 ./ 1, negsq si))));

  return addsq(x, multsq(simp 'i, y));
end;

put('atanh, 'cmpxsplitfn, 'reimatanh);

symbolic procedure reimatanh u;
begin scalar rearg, imarg, x, y, sr, si, s1;
  rearg := prepsq simprepart cdr u;
  imarg := prepsq simpimpart cdr u;
  if rearg =0 then return simp {'times, 'i, {'atan, imarg}};
  sr := simp!-sign1 rearg;

  % s1 = 1 if |rearg| >1, -1; if |rearg| <1; else 0
  s1 := simp {'sign, {'difference, {'expt, rearg, 2}, 1}}; 
  % s1 = 2 if |rearg| > 1 else if |rearg| <1  s1 = 0 ; else s1 =1 
  s1 := addsq(1 ./ 1, s1);

  if imarg = 0 then <<
    x := {'quotient, {'plus, 1, rearg}, {'difference, 1,  rearg}};
    x := simp {'quotient, {'log, {'abs, x}}, 2};
    % y = -pi/2 if rearg>1, y =pi/2 if rearg<-1 else y=0
    y := multsq(multsq(sr, simp {'quotient, 'pi, -4}), s1)>>
  else <<
    si := prepsq simp!-sign1 imarg;
    % si =-1 if imarg =0 else si = 0
    si := simp {'difference, {'expt, si, 2}, 1}; 

    x := {'plus, {'expt, {'plus, rearg, 1}, 2}, {'expt, imarg, 2}}; 
    y := {'plus, {'expt, {'difference, 1, rearg}, 2}, {'expt, imarg, 2}}; 
    x := simp {'quotient, {'log, {'quotient, x, y}}, 4};

    y := {'difference, 1, {'plus, {'expt, rearg, 2}, {'expt, imarg, 2}}};
    y := simp {'quotient, {'atan2, {'times, 2, imarg}, y}, 2};
    % subtract pi iff imarg=0 and rearg >1
    y := addsq(multsq(multsq(si, multsq(s1, addsq(1 ./ 1, sr))),
               simp {'quotient, 'pi, 4}), y)>>;

  return addsq(x, multsq(simp 'i, y));
end;

% % Produces a simpler imaginary part for non-numerical arguments, 
% % but for numeric arguments the imaginary part is the sum of two atan terms
% % rather than one with the method above.
% symbolic procedure reimatanh1 u;
% begin scalar rearg, imarg, x, y;
%   rearg := prepsq simprepart cdr u;
%   imarg := prepsq simpimpart cdr u;
%   if rearg =0 then return simp {'times, 'i, {'atan, imarg}};
%   if imarg = 0 then <<
%     x:= {'quotient, {'plus, 1, rearg}, {'difference, 1,  rearg}};
%     x := simp {'quotient, {'log, {'abs, x}}, 2}>>
%   else <<
%     x := {'plus, {'expt, {'plus, rearg, 1}, 2}, {'expt, imarg, 2}}; 
%     y := {'plus, {'expt, {'difference, 1, rearg}, 2}, {'expt, imarg, 2}}; 
%     x := simp {'quotient, {'log, {'quotient, x, y}}, 4}>>;
% 
%   y := {'quotient, {'plus, {'atan2, imarg, {'plus, 1, rearg}},
%                            {'atan2, imarg, {'difference, 1, rearg}}},
%                     2};
% 
%   return addsq(x, multsq(simp 'i, simp y));
% end;

put('atan, 'cmpxsplitfn, 'reimatan);
put('acot, 'cmpxsplitfn, 'reimatan);

symbolic procedure reimatan u;
   (if imarg=0 then simp {op, rearg}
    else (if op='atan then negsq res 
          else if op='acot then addsq(simp {'quotient, 'pi, 2}, res))
       where res=multsq(simp 'i, reimatanh({car u, {'times, 'i, cadr u}})))
   where op = car u,
         rearg = prepsq simprepart cdr u, 
         imarg = prepsq simpimpart cdr u;

put('asec, 'cmpxsplitfn, 'reimasec);

symbolic procedure reimasec u;
  reimasin({'acos, {'quotient, 1, cadr u}});

put('acsc, 'cmpxsplitfn, 'reimacsc);

symbolic procedure reimacsc u;
  reimasin({'asin, {'quotient, 1, cadr u}});

put('asech, 'cmpxsplitfn, 'reimasech);

symbolic procedure reimasech u;
  reimacosh({'acosh, {'quotient, 1, cadr u}});

put('acsch, 'cmpxsplitfn, 'reimacsch);

symbolic procedure reimacsch u;
  reimasinh({'asinh, {'quotient, 1, cadr u}});   

put('acoth, 'cmpxsplitfn, 'reimacoth);

symbolic procedure reimacoth u;
begin scalar rearg, imarg, x, y, sr, si, s1;
  rearg := prepsq simprepart cdr u;
  imarg := prepsq simpimpart cdr u;
  
  if rearg=0 then << 
     y := simp {'times, 'i, {'acot, {'abs, imarg}}};
     si := simp!-sign1 imarg;

     % if imarg > 0 x=-1 else x=+1
     x := addsq(simp 1, negsq multsq(si, addsq(1 ./ 1, si)));
     return multsq(x, y)>>;

  % s1 = 1 if |rearg| <1, s1=-1; if |rearg| >1; else s1=0
  s1 := simp {'sign, {'difference, 1, {'expt, rearg, 2}}}; 
  % s1 = 2 if |rearg| < 1 else if |rearg| >1  s1 = 0 ; else s1 =1 
  s1 := addsq(1 ./ 1, s1);

  sr := simp!-sign1 rearg;
  % sr=-1 if rearg > 0, 1 if rearg<=0 
  sr := addsq(1 ./ 1, negsq multsq(sr, addsq(1 ./ 1, sr)));

  if imarg = 0 then <<
    x:= {'quotient, {'plus, 1, rearg}, {'difference, rearg, 1}};
    x := simp {'quotient, {'log, {'abs, x}}, 2};

    y := simp {'quotient, {'atan2, 0, {'difference, {'expt, rearg, 2}, 1}}, 4};
    % y = -pi/2 if 0<rearg<1, y =pi/2 if -1<rearg<=0 else y=0
    y := multsq(multsq(sr, s1), y)>>
  else <<
    si := prepsq simp!-sign1 imarg;
    % si =1 if imarg =0 else si = 0
    si := simp {'difference, 1, {'expt, si, 2}}; 

    x :=  {'plus, {'expt, {'plus, rearg, 1}, 2}, {'expt, imarg, 2}}; 
    y :=  {'plus, {'expt, {'difference, 1, rearg}, 2}, {'expt, imarg, 2}}; 
    x := simp {'quotient, {'log, {'quotient, x, y}}, 4};

    y :=  {'difference, {'plus, {'expt, rearg, 2}, {'expt, imarg, 2}}, 1};
    y := simp {'quotient, {'atan2, {'times, -2, imarg}, y}, 2};
    % subtract pi iff imarg=0 and 0<rearg<1
    y := addsq(multsq(multsq(si, multsq(s1, addsq((-1) ./ 1, sr))),
               simp {'quotient, 'pi, 4}), y)>>;

  return addsq(x, multsq(simp 'i, y));
end;

% % Produces a simpler imaginary part for non-numeric arguments, but for numeric
% % arguments the imaginary part is the sum of two atan terms rather than one.
% % When u=0, an error is raised due to the formation of atan2(0, 0) 
% % rather than returning the correct value i*pi/2.
% symbolic procedure reimacoth1 u;
% begin scalar rearg, imarg, x, y, si;
%   rearg := prepsq simprepart cdr u;
%   imarg := prepsq simpimpart cdr u;
%   
%   if rearg=0 then << 
%      y := simp {'times, 'i, {'acot, {'abs, imarg}}};
%      si := simp!-sign1 imarg;
%      % if imarg > 0 x=-1 else x=+1
%      x := addsq(simp 1, negsq multsq(si, addsq(simp 1, si)));
%      return multsq(x, y)>>;
% 
%   if imarg = 0 then <<
%     x := {'quotient, {'plus, 1, rearg}, {'difference, rearg, 1}};
%     x := simp {'quotient, {'log, {'abs, x}}, 2}>>
%   else <<
%     x :=  {'plus, {'expt, {'plus, rearg, 1}, 2}, {'expt, imarg, 2}}; 
%     y :=  {'plus, {'expt, {'difference, 1, rearg}, 2}, {'expt, imarg, 2}}; 
%     x := simp {'quotient, {'log, {'quotient, x, y}}, 4}>>;
% 
%   y := {'plus, {'expt, rearg, 2}, {'expt, imarg, 2}};
%   y := {'quotient, {'difference, {'atan2, {'minus, imarg}, {'plus, y, rearg}},
%                                  {'atan2, imarg, {'difference, y, rearg}}},
%                     2};
%   return addsq(x, multsq(simp 'i, simp y));
% end;


%%% special cases

put('arbint,'cmpxsplitfn,'simp);


endmodule;

end;
