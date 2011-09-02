module TayDiff;

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
        !*tay2q, !*TayExp2q, make!-cst!-coefflis, make!-Taylor!*,
        TayCfPl, TayCfSq, TayCoeffList, TayFlags, Taylor!:,
        TayMakeCoeff, TayOrig, TayTemplate, TayTpElNext, TayTpElOrder,
        TayTpElPoint, TayTpElVars, TayVars,

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
    d := if not ldepends(TayVars u,kernel)
           then make!-Taylor!*(
                  for each cc in TayCoeffList u collect
                    TayMakeCoeff(TayCfPl cc,
                                 diffsq(TayCfSq cc,kernel)),
                    TayTemplate u,
                    if !*taylorkeeporiginal and TayOrig u
                      then diffsq(TayOrig u,kernel)
                     else nil,
                    TayFlags u)
          else difftaylorwrttayvar(u,kernel);
    for each el in TayTemplate u do
      if depends(TayTpElPoint el,kernel)
        then begin scalar f;
               f := negsq diffsq(!*k2q TayTpElPoint el,kernel);
               for each var in TayTpElVars el do
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
  Taylor!:
  begin scalar v,w,w1; integer n,m;
    v := TayTemplate u;
    w := var!-is!-nth(v,kernel);
    n := car w;
    m := cdr w;
    w := for each x in TayCoeffList u join <<
           w := nth(TayCfPl x,n);
           w1 := nth(w,m);
           if w1 = 0 then nil
            else list
              if TayTpElPoint nth(v,n) eq 'infinity
                then TayMakeCoeff(
                        replace!-nth!-nth(TayCfPl x,n,m,w1 + 1),
                        multsq(TayCfSq x,!*TayExp2q (-w1)))
               else TayMakeCoeff(
                        replace!-nth!-nth(TayCfPl x,n,m,w1 - 1),
                        multsq (TayCfSq x,!*TayExp2q w1))>>;
    return
      make!-Taylor!*(
            if null w
              then make!-cst!-coefflis(nil ./ 1,v)
             else w,
            replace!-nth (v,n,
                          ({TayTpElVars w1,
                            TayTpElPoint w1,
                            if TayTpElPoint w1 eq 'infinity
                              then TayTpElOrder w1 + 1
                             else TayTpElOrder w1 - 1,
                            if TayTpElPoint w1 eq 'infinity
                              then TayTpElNext w1 + 1
                             else TayTpElNext w1 - 1}
                              where w1 := nth(v,n))),
            if !*taylorkeeporiginal and TayOrig u
              then diffsq(TayOrig u,kernel)
             else nil,
            TayFlags u)
  end;

endmodule;

end;
