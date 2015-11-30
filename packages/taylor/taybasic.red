module taybasic;

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
%      Functions that implement the basic operations
%       on Taylor kernels
%
%*****************************************************************


exports addtaylor, addtaylor1, invtaylor, invtaylor1, makecoeffpairs,
        makecoeffs, makecoeffs0, multtaylor, multtaylor1,
        multtaylorsq, negtaylor, negtaylor1, quottaylor, quottaylor1$

imports

% from the REDUCE kernel:
        addsq, invsq, lastpair, mvar, multsq, negsq, neq, nth, numr,
        over, quotsq, reversip, subtrsq, union,

% from the header module:
        !*tay2q, common!-increment, get!-degree, invert!-powerlist,
        make!-taylor!*, multintocoefflist, prune!-coefflist,
        smallest!-increment, subtr!-degrees, subs2coefflist, taycfpl,
        taycfsq, taycoefflist, tayflags, tayflagscombine, taygetcoeff,
        taylor!-kernel!-sq!-p, taylor!:, taymakecoeff, tayorig,
        taytemplate, taytpelvars, tpdegreelist, tpnextlist,

% from module Tayintro:
        confusion, taylor!-error, taylor!-error!*,

% from module Tayutils:
        add!.comp!.tp!., add!-degrees, enter!-sorted, exceeds!-order,
        inv!.tp!., min2!-order, mult!.comp!.tp!., replace!-next,
        taydegree!-strict!<!=;


fluid '(!*taylorkeeporiginal)$

symbolic procedure multtaylorsq (tay, sq);
  %
  % multiplies the s.q. sq into the Taylor kernel tay.
  % value is a Taylor kernel.
  % no check for variable dependency is done!
  %
  if null tay or null numr sq then nil
   else make!-taylor!* (
              multintocoefflist (taycoefflist tay, sq),
              taytemplate tay,
              if !*taylorkeeporiginal and tayorig tay
                then multsq (sq, tayorig tay)
               else nil,
              tayflags tay)$


symbolic inline procedure degree!-union (u, v);
  union (u, v)$ % works for the moment;

symbolic procedure addtaylor(u,v);
  %
  % u and v are two Taylor kernels
  % value is their sum, as a Taylor kernel
  %
  (if null tp then confusion 'addtaylor
    else addtaylor!*(u,v,car tp))
    where tp := add!.comp!.tp!.(u,v);


symbolic procedure addtaylor!-as!-sq(u,v);
   begin scalar tp;
     return
       if taylor!-kernel!-sq!-p u and taylor!-kernel!-sq!-p v and
          (tp := add!.comp!.tp!.(mvar numr u,mvar numr v))
         then !*tay2q addtaylor!*(mvar numr u,mvar numr v,car tp)
        else addsq(u,v)
   end;

symbolic procedure addtaylor!*(u,v,tp);
   make!-taylor!*
           (cdr z,replace!-next(tp,car z),
            if !*taylorkeeporiginal and tayorig u and tayorig v
              then addsq(tayorig u,tayorig v)
             else nil,
            tayflagscombine(u,v))
       where z := addtaylor1(tp,taycoefflist u,taycoefflist v);

symbolic procedure addtaylor1(tmpl,l1,l2);
  %
  % Returns the coefflist that is the sum of coefflists l1, l2.
  %
  begin scalar cff,clist,tn,tp;
    tp := tpdegreelist tmpl;
    tn := tpnextlist tmpl;
    %
    % The following is necessary to ensure that the rplacd below
    %  doesn't do any harm to the list in l1.
    %
    clist := for each cc in l1 join
               if not null numr taycfsq cc
                 then if not exceeds!-order(tn,taycfpl cc)
                        then {taymakecoeff(taycfpl cc,taycfsq cc)}
                       else <<tn := min2!-order(tn,tp,taycfpl cc);nil>>;
    for each cc in l2 do
      if not null numr taycfsq cc
        then if not exceeds!-order(tn,taycfpl cc)
               then <<cff := assoc(taycfpl cc,clist);
                      if null cff then clist := enter!-sorted(cc,clist)
                       else rplacd(cff,addsq(taycfsq cff,taycfsq cc))>>
              else tn := min2!-order(tn,tp,taycfpl cc);
    return tn . subs2coefflist clist
  end;


symbolic procedure negtaylor u;
  make!-taylor!* (
         negtaylor1 taycoefflist u,
         taytemplate u,
         if !*taylorkeeporiginal and tayorig u
           then negsq tayorig u else nil,
         tayflags u)$

symbolic procedure negtaylor1 tcl;
  for each cc in tcl collect
    taymakecoeff (taycfpl cc, negsq taycfsq cc)$

symbolic procedure multtaylor(u,v);
  %
  % u and v are two Taylor kernels,
  % result is their product, as a Taylor kernel.
  %
  (if null tps then confusion 'multtaylor
    else multtaylor!*(u,v,tps))
   where tps := mult!.comp!.tp!.(u,v,nil);

symbolic procedure multtaylor!-as!-sq(u,v);
   begin scalar tps;
     return
       if taylor!-kernel!-sq!-p u and taylor!-kernel!-sq!-p v and
          (tps := mult!.comp!.tp!.(mvar numr u,mvar numr v,nil))
         then !*tay2q multtaylor!*(mvar numr u,mvar numr v,tps)
        else multsq(u,v)
   end;

symbolic procedure multtaylor!*(u,v,tps);
   make!-taylor!*
        (cdr z,replace!-next(car tps,car z),
         if !*taylorkeeporiginal and tayorig u and tayorig v
           then multsq (tayorig u, tayorig v)
          else nil,
         tayflagscombine(u,v))
     where z := multtaylor1(car tps,taycoefflist u,taycoefflist v);

symbolic procedure multtaylor1(tmpl,l1,l2);
  %
  % Returns the coefflist that is the product of coefflists l1, l2,
  %  with respect to Taylor template tp.
  %
  begin scalar cff,pl,rlist,sq,tn,tp;
    tp := tpdegreelist tmpl;
    tn := tpnextlist tmpl;
    for each cf1 in l1 do
      for each cf2 in l2 do <<
        pl := add!-degrees(taycfpl cf1,taycfpl cf2);
        if not exceeds!-order(tn,pl) then <<
          sq := multsq(taycfsq cf1,taycfsq cf2);
          if not null numr sq then <<
            cff := assoc(pl,rlist);
            if null cff
              then rlist := enter!-sorted(taymakecoeff(pl,sq),rlist)
             else rplacd(cff,addsq(taycfsq cff,sq))>>>>
         else tn := min2!-order(tn,tp,pl)>>;
    return tn . subs2coefflist rlist
  end;

COMMENT Implementation of Taylor division.
        We use the following algorithm:
        Suppose the numerator and denominator are of the form

                -----                    -----
                \          k             \          l
        f(x) =   >     a  x   ,  g(x) =   >     b  x   ,
                /       k                /       l
                -----                    -----
                k>=k0                    l>=l0

        respectively.  The quotient is supposed to be

                -----
                \          m
        h(x) =   >     c  x   .
                /       m
                -----
                m>=m0

        Clearly: m0 = k0 - l0.  This follows immediately from
        f(x) = g(x) * h(x) by comparing lowest order terms.
        This equation can now be written:

         -----            -----                 -----
         \          k     \             l+m     \              n
          >     a  x   =   >     b  c  x     =   >    b    c  x  .
         /       k        /       l  m          /      n-m  m
         -----            -----                 -----
         k>=k0            l>=l0              m0<=m<=n-l0
                          m>=m0                n>=l0+m0

        Comparison of orders leads immediately to

                  -----
                  \
          a    =   >    b    c   ,  n>=l0+m0 .
           n      /      n-m  m
                  -----
               m0<=m<=n-l0

        We write the last term of the series separately:

                  -----
                  \
          a    =   >    b    c   + b   c     ,  n>=l0+m0 ,
           n      /      n-m  m     l0  n-l0
                  -----
               m0<=m<n-l0

        which leads immediately to the recursion formula

                       /       -----           \
                   1   |       \               |
         c     = ----- | a  -   >     b    c   | .
          n-l0    b    |  n    /       n-m  m  |
                   l0  \       -----           /
                            m0<=m<n-l0

        Finally we shift n by l0 and obtain

                       /          -----              \
                   1   |          \                  |
         c     = ----- | a     -   >     b       c   | .  (*)
          n       b    |  n+l0    /       n-m+l0  m  |
                   l0  \          -----              /
                                 m0<=m<n

        For multidimensional Taylor series we can use the same
        expression if we interpret all indices as appropriate
        multiindices.

        For computing the reciprocal of a Taylor series we use
        the formula (*) above with f(x) = 1, i.e. lowest order
        coefficient = 1, all others = 0;


symbolic procedure quottaylor(u,v);
  %
  % Divides Taylor series u by Taylor series v.
  % Like invtaylor, it depends on ordering of the coefficients
  %  according to the degree of the expansion variables (lowest first).
  %
  (if null tps then confusion 'quottaylor
    else quottaylor!*(u,v,tps))
   where tps := mult!.comp!.tp!.(u,v,t);

symbolic procedure quottaylor!-as!-sq(u,v);
   begin scalar tps;
     return
       if taylor!-kernel!-sq!-p u and taylor!-kernel!-sq!-p v and
          (tps := mult!.comp!.tp!.(mvar numr u,mvar numr v,t))
         then !*tay2q quottaylor!*(mvar numr u,mvar numr v,tps)
        else quotsq(u,v)
   end;

symbolic procedure quottaylor!*(u,v,tps);
   make!-taylor!*(
      cdr z,replace!-next(car tps,car z),
      if !*taylorkeeporiginal and tayorig u and tayorig v
        then quotsq (tayorig u, tayorig v)
       else nil,
      tayflagscombine(u,v))
    where z := quottaylor1(car tps,taycoefflist u,taycoefflist v);

symbolic procedure quottaylor1(tay,lu,lv);
  %
  % Does the real work, called also by the expansion procedures.
  % Returns the coefflist.
  %
  taylor!:
  begin scalar clist,il,lminu,lminv,aminu,aminv,ccmin,coefflis,tp,tn;
    tp := tpdegreelist tay;
    tn := tpnextlist tay;
    lu := prune!-coefflist lu;
    if null lu then return tn . nil;
    lminu := taycfpl car lu;
    for each el in cdr lu do
      if not null numr taycfsq el then
        lminu := taydegree!-min2(lminu,taycfpl el);
    aminu := if lminu neq taycfpl car lu then taygetcoeff(lminu,lu)
              else taycfsq car lu;
    lv := prune!-coefflist lv;
    if null lv then taylor!-error!*('not!-a!-unit,'quottaylor);
    il := common!-increment(smallest!-increment lu,
                            smallest!-increment lv);
    aminv := taycfsq car lv;   % first element is that of lowest degree
    lminv := taycfpl car lv;
    for each cf in cdr lv do
      if not taydegree!-strict!<!=(lminv,taycfpl cf)
        then taylor!-error('not!-a!-unit,'quottaylor);
    ccmin := subtr!-degrees(lminu,lminv);
    clist := {taymakecoeff(ccmin,quotsq(aminu,aminv))};
    coefflis := makecoeffs(ccmin,tn,il);
    if null coefflis then return tn . clist;
    for each cc in cdr coefflis do begin scalar sq;
      sq := subtrsq(taygetcoeff(add!-degrees(cc,lminv),lu),
                    addcoeffs(clist,lv,ccmin,cc));
      if exceeds!-order(tn,cc)
        then tn := min2!-order(tn,tp,cc)
       else if not null numr sq
        then clist := taymakecoeff(cc,quotsq(sq,aminv)) . clist;
     end;
    return tn . subs2coefflist reversip clist
  end;

symbolic procedure taydegree!-min2(u,v);
  %
  % (TayPowerList, TayPowerList) -> TayPowerList
  %
  % returns minimum of both powerlists
  %
  for i := 1 : length u collect begin scalar l1,l2;
    l1 := nth(u,i);
    l2 := nth(v,i);
    return
      for j := 1 : length l1 collect
        taylor!: min2(nth(l1,j),nth(l2,j))
  end;

symbolic procedure makecoeffshom(cmin,lastterm,incr);
  if null cmin then '(nil)
   else taylor!:
     for i := 0 step incr until lastterm join
       for each l in makecoeffshom(cdr cmin,lastterm - i,incr) collect
              (car cmin + i) . l;

symbolic procedure makecoeffshom0(nvars,lastterm,incr);
  if nvars=0 then '(nil)
   else taylor!:
     for i := 0 step incr until lastterm join
       for each l in makecoeffshom0(nvars - 1,lastterm - i,incr) collect
             i . l;

symbolic procedure makecoeffs(plmin,dgl,il);
  %
  % plmin the list of the smallest terms, dgl the degreelist
  % of the largest term, il the list of increments.
  % It returns an ordered list of all index lists matching this
  % requirement.
  %
  taylor!:
  if null plmin then '(nil)
   else for each l1 in makecoeffs(cdr plmin,cdr dgl,cdr il) join
        for each l2 in makecoeffshom(
                         car plmin,
                         car dgl - get!-degree car plmin - car il,
                         car il)
                 collect (l2 . l1);

symbolic procedure makecoeffs0(tp,dgl,il);
  %
  % tp is a Taylor template,
  % dgl a next list (m1 ... ),
  % il the list of increments (i1 ... ).
  % It returns an ordered list of all index lists matching the
  % requirement that for every element ni: 0 <= ni < mi and ni is
  % a multiple of i1
  %
  taylor!:
  if null tp then '(nil)
   else for each l1 in makecoeffs0(cdr tp,cdr dgl,cdr il) join
        for each l2 in makecoeffshom0(length taytpelvars car tp,
                                      car dgl - car il,
                                      car il)
                 collect (l2 . l1);

symbolic procedure makecoeffpairs1(plmin,pl,lmin,il);
  taylor!:
  if null pl then '((nil))
   else for each l1 in makecoeffpairs1(
                         cdr plmin,
                         cdr pl,cdr lmin,cdr il) join
     for each l2 in makecoeffpairshom(car plmin,
                                      car pl,car lmin,- car il)
           collect (car l2 . car l1) . (cdr l2 . cdr l1)$

symbolic procedure makecoeffpairs(plmin,pl,lmin,il);
  reversip cdr makecoeffpairs1(plmin,pl,lmin,il);

symbolic procedure makecoeffpairshom(clow,chigh,clmin,inc);
  if null clmin then '((nil))
   else taylor!:
    for i := car chigh step inc until car clow join
      for each l in makecoeffpairshom(cdr clow,cdr chigh,cdr clmin,inc)
          collect (i . car l) . ((car chigh + car clmin - i) . cdr l);

symbolic procedure addcoeffs(cl1,cl2,pllow,plhigh);
  begin scalar s,il;
    s := nil ./ 1;
    il := common!-increment(smallest!-increment cl1,
                            smallest!-increment cl2);
    for each p in makecoeffpairs(pllow,plhigh,caar cl2,il) do
        s := addsq(s,multsq(taygetcoeff(car p,cl1),
                            taygetcoeff(cdr p,cl2)));
    return s
%    return for each p in makecoeffpairs(ccmin,cc,caar cl2,dl) addsq
%             multsq(TayGetCoeff(car p,cl1),TayGetCoeff(cdr p,cl2));
  end;

symbolic procedure invtaylor u;
  %
  % Inverts a Taylor series expansion,
  % depends on ordering of the coefficients according to the
  %  degree of the expansion variables (lowest first)
  %
  if null u then confusion 'invtaylor
   else begin scalar tps;
     tps := inv!.tp!. u;
     return make!-taylor!*(
               invtaylor1(car tps,taycoefflist u),
               car tps,
               if !*taylorkeeporiginal and tayorig u
                then invsq tayorig u
                 else nil,
               tayflags u);
   end;

symbolic procedure invtaylor1(tay,l);
  %
  % Does the real work, called also by the expansion procedures.
  % Returns the coefflist.
  %
  taylor!:
  begin scalar clist,amin,ccmin,coefflis,il;
    l := prune!-coefflist l;
    if null l then taylor!-error!*('not!-a!-unit,'invtaylor);
    amin := taycfsq car l;  % first element must have lowest degree
    ccmin := taycfpl car l;
    for each cf in cdr l do
      if not taydegree!-strict!<!=(ccmin,taycfpl cf)
        then taylor!-error('not!-a!-unit,'invtaylor);
    il := smallest!-increment l;
    ccmin := invert!-powerlist ccmin;
    clist := {taymakecoeff(ccmin,invsq amin)};
    coefflis := makecoeffs(ccmin,tpnextlist tay,il);
    if not null coefflis
      then for each cc in cdr coefflis do begin scalar sq;
             sq := addcoeffs(clist,l,ccmin,cc);
             if not null numr sq
               then clist := taymakecoeff(cc,negsq quotsq(sq,amin))
                               . clist;
     end;
    return subs2coefflist reversip clist
  end;

endmodule;

end;
