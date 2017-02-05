module hodge;

% Author: Eberhard Schruefer;

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


global '(dimex!* sgn!* detm!* basisforml!*);

fluid '(frlis!*);

symbolic procedure formhodge(u,vars,mode);
   if mode eq 'symbolic then 'hash . formlis(cdr u,vars,mode)
    else 'list . mkquote 'hodge . formlis(cdr u,vars,mode);

%put('hash,'formfn,'formhodge);

put('hodge,'simpfn,'simphodge);

put('hodge,'rtypefn,'getrtypecar);

put('hodge,'partitfn,'partithodge);

put('!#22c6;,'scripted_op,
    '(rsup . hodge) . get('!#22c6;,'scripted_op));

symbolic procedure partithodge u;
   hodgepf partitop car u;

symbolic procedure simphodge u;
   !*pf2sq partithodge u;

symbolic procedure mkhodge u;
   begin scalar x,y;
     return if x := opmtch(y := list('hodge,u))
               then partitop x
             else if deg!*form u = dimex!*
                     then 1 .* mksq(y,1) .+ nil
                   else mkupf y
   end;

inline procedure mkbaseform u;
   mkupf list(caar basisforml!*,u);

symbolic procedure basisformp u;
   null atom u and (u memq basisforml!*);

symbolic procedure hodgepf u;
   if null u then nil
    else addpf(multpfsq(hodgek ldpf u,lc u),hodgepf red u);

symbolic procedure hodgek u;
   if eqcar(u,'hodge)
      then cadr u .* multsq(mksgnsq multf(deg!*form cadr u,
                              addf(dimex!*,negf deg!*form cadr u)),
                                   resimp sgn!*) .+ nil
    else if basisformp u then dual list u
    else if eqcar(u,'wedge) 
            then if boundindp(cdr u,basisforml!*) then dual cdr u
                  else (if x then xpndhodge2(cdr u,x)
                         else mkhodge u) where x = xpndablehodgep cdr u
    else if basisforml!* and null deg!*form u
            then dual0 u
    else mkhodge u;


symbolic procedure all1formsp u;
   if deg!*form car u = 1 
      then if cdr u then all1formsp cdr u
            else t
    else nil;

symbolic procedure xpndablehodgep u;
   xpndablehodge1(u,0,nil);

symbolic procedure xpndablehodge1(u,v,w);
   if null u then if w then v . w else nil
    else if eqcar(car u,'hodge) and eqcar(cadar u,'wedge)
      then if all1formsp(cdadar u) then xpndablehodge1(cdr u,v,u)
            else nil
    else if deg!*form car u = 1 
      then xpndablehodge1(cdr u,if null w then v+1 else v,w)
    else nil;

symbolic procedure xpndhodge2(u,v);
   begin scalar h,rw,x;
     h := cadr v;
     rw := cddr v;
     x := cdadr h .* multsq(mksgnsq multf(car v,deg!*form h),
                            resimp sgn!*) .+ nil;
     a: if h eq car u then go to b;
        x := hodgeinnerprodwedgepf(car u,x);
        u := cdr u;
        go to a;
     b: if null rw then go to c;
        x := hodgeinnerprodwedgepf(car rw,x);
        rw := cdr rw;
        go to b;
     c: return mkuniquewedge x
   end;

symbolic procedure hodgeinnerprodwedgepf(u,v);
   if null v then nil
    else addpf(multpfsq(hodgeinnerprodwedge1(u,caar v,nil),cdar v),
               hodgeinnerprodwedgepf(u,cdr v));

symbolic procedure hodgeinnerprodwedge1(u,v,w);
   if null rwf v 
      then mkunarywedge multpfsq(hodgeinnerprod(u,lwf v),mksgnsq w)
    else addpf(if null rwf rwf v and (deg!*form lwf rwf v = 1)
                  then multpfsq(!*k2pf list lwf v,
                                multsq(mksgnsq addf(deg!*form lwf v,w),
                                       !*pf2sq hodgeinnerprod(u,lwf rwf v)))
                else wedgepf2(!*k2pf lwf v,
                              hodgeinnerprodwedge1(u,rwf v,
                                                   addf(w,deg!*form lwf v))),
               if deg!*form lwf v = 1
                  then multpfsq(!*k2pf rwf v,
                                multsq(!*pf2sq hodgeinnerprod(u,lwf v),
                                       mksgnsq w))
                else wedgepf2(hodgeinnerprod(u,lwf v),
                              rwf v .* mksgnsq w .+ nil));

symbolic procedure hodgeinnerprod(u,v);
   hodgepf mkuniquewedge wedgepf2(!*k2pf u,mkunarywedge mkhodge v);


symbolic procedure dual0 u;
   (multpfsq(mkwedge ('wedge . basisforml!*),
             simpexpt list(mk!*sq(absf!* numr x ./
                                  absf!* denr x),'(quotient 1 2))))
    where x = simp!* detm!*;

symbolic procedure dual u;
   (multpfsq(mkdual xpnddual u,
             simpexpt list(mk!*sq(absf!* numr x ./
                                  absf!* denr x),'(quotient 1 2))))
    where x = simp!* detm!*;

symbolic procedure !*met2pf u;
   metpf1 getupper cadr u;

symbolic procedure xpnddual u;
   if null cdr u
      then mkunarywedge !*met2pf car u
    else wedgepf2(!*met2pf car u,xpnddual cdr u);

symbolic procedure metpf1 u;
   if null u then nil
    else addpf(multpfsq(mkbaseform caar u,simp cdar u),metpf1 cdr u);

symbolic procedure mkdual u;
   if null u then nil
    else addpf(multpfsq(((if null x then nil
                           else if cdr ldpf x
                                   then multpfsq(mkuniquewedge1 ldpf x,
                                                 lc x)
                           else car ldpf x .* lc x .+ nil)
                          where x = dualk ldpf u),
                         lc u),mkdual red u);

symbolic procedure dualk u;
   begin scalar x;
     x := !*k2pf basisforml!*;
     a: x := dualk2(car u,x);
        if null(u := cdr u) then return x;
        go to a
   end;


symbolic procedure dualk2(u,v);
   dualk0(u,v,nil);

symbolic procedure dualk0(u,v,w);
   if u eq car ldpf v
      then if null cdr ldpf v
              then list 1 .* multsq(mksgnsq w,lc v) .+ nil
            else cdr ldpf v .* multsq(mksgnsq w,lc v) .+ nil
    else if null cdr ldpf v then nil
    else wedgepf2(!*k2pf ldpf car v,
                  dualk0(u,cdr ldpf v .* lc v .+ nil,addf(w,1)));

symbolic procedure hodgeprn u;
   <<prin2!* "#"; rembras cadr u>>;

put('hodge,'prifn,'hodgeprn);

symbolic procedure xhodgeprn u;
   begin
     fancy!-prin2!*("\!",1);
     fancy!-print!-indexlist1('(!#22c6;),'!^,nil);
     return fancy!-maprint(cadr u,0)
   end;

put('hodge,'fancy!-prifn,'xhodgeprn);

endmodule;

end;
