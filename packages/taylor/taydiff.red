module taydiff;

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


%*****************************************************************
%
%        Differentiation of Taylor kernels
%
%*****************************************************************


exports difftaylorwrttayvar;

imports

% from the REDUCE kernel:
        !*k2q, !*n2f, depends, diffsq, lastpair, ldepends, multsq, negsq,
        nth, over,

% from the header module:
        !*tay2q, !*TayExp2q, make!-cst!-coefflis, make!-taylor!*,
        taycfpl, taycfsq, taycoefflist, tayflags, taylor!:,
        taymakecoeff, tayorig, taytemplate, taytpelnext, taytpelorder,
        taytpelpoint, taytpelvars, tayvars,

% from module Tayintro:
        replace!-nth, replace!-nth!-nth, var!-is!-nth,

% from module Taybasic:
        addtaylor, multtaylor, multtaylorsq,

% from module Taysimp:
        expttayi;


fluid '(!*taylorkeeporiginal);

put ('taylor!*, 'dfform, 'taydiffp);

symbolic procedure taydiffp(u,v,n);
  %
  % differentiates u**n w.r.t. v, u is a Taylor kernel
  % value is a standard quotient
  %
  !*tay2q
    ((if n=1 then uv
       else multtaylor(multtaylorsq(expttayi(u,n - 1),!*n2f n ./ 1),uv))
      where uv := difftaylor(u,v));

symbolic procedure difftaylor (u,kernel);
  begin scalar d;
    d := if not ldepends(tayvars u,kernel)
           then make!-taylor!*(
                  for each cc in taycoefflist u collect
                    taymakecoeff(taycfpl cc,
                                 diffsq(taycfsq cc,kernel)),
                    taytemplate u,
                    if !*taylorkeeporiginal and tayorig u
                      then diffsq(tayorig u,kernel)
                     else nil,
                    tayflags u)
          else difftaylorwrttayvar(u,kernel);
    for each el in taytemplate u do
      if depends(taytpelpoint el,kernel)
        then begin scalar f;
               f := negsq diffsq(!*k2q taytpelpoint el,kernel);
               for each var in taytpelvars el do
                 d := addtaylor(d,
                        multtaylorsq(difftaylorwrttayvar(u,var),f));
             end;
    return d;
  end;

symbolic procedure difftaylorwrttayvar(u,kernel);
  %
  % kernel is one of the Taylor variables
  % differentiates Taylor kernel u wrt kernel
  %
  taylor!:
  begin scalar v,w,w1; integer n,m;
    v := taytemplate u;
    w := var!-is!-nth(v,kernel);
    n := car w;
    m := cdr w;
    w := for each x in taycoefflist u join <<
           w := nth(taycfpl x,n);
           w1 := nth(w,m);
           if w1 = 0 then nil
            else list
              if taytpelpoint nth(v,n) eq 'infinity
                then taymakecoeff(
                        replace!-nth!-nth(taycfpl x,n,m,w1 + 1),
                        multsq(taycfsq x,!*TayExp2q (-w1)))
               else taymakecoeff(
                        replace!-nth!-nth(taycfpl x,n,m,w1 - 1),
                        multsq (taycfsq x,!*TayExp2q w1))>>;
    return
      make!-taylor!*(
            if null w
              then make!-cst!-coefflis(nil ./ 1,v)
             else w,
            replace!-nth (v,n,
                          ({taytpelvars w1,
                            taytpelpoint w1,
                            if taytpelpoint w1 eq 'infinity
                              then taytpelorder w1 + 1
                             else taytpelorder w1 - 1,
                            if taytpelpoint w1 eq 'infinity
                              then taytpelnext w1 + 1
                             else taytpelnext w1 - 1}
                              where w1 := nth(v,n))),
            if !*taylorkeeporiginal and tayorig u
              then diffsq(tayorig u,kernel)
             else nil,
            tayflags u)
  end;

endmodule;

end;
