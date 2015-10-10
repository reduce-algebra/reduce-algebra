module tayexpnd;

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
%          The Taylor expansion machinery
%
%*****************************************************************


exports taylorexpand;

imports

% from the REDUCE kernel:
        !*k2q, !*p2q, .*, .+, ./, aeval, addsq, apply1, denr,
        dependsl, dfn_prop, diffsq, domainp, eqcar, error1, errorp,
        errorset!*, exptsq, kernp, lastpair, lc, let, lpow, lprim,
        mk!*sq, mkquote, mksq, multsq, mvar, nconc!*, neq, nlist, nth,
        numr, operator, prepsq, quotsq, red, rederr, setcar, sfp,
        simp!*, subsq, subtrsq,

% from the header module:
        !*tay2q, cst!-taylor!*, has!-taylor!*, make!-cst!-coefficient,
        make!-taylor!*, prune!-coefflist, set!-tayorig, taycfpl,
        taycfsq, taycoefflist, tayflags, taylor!*p,
        taylor!-kernel!-sq!-p, taylor!-trace, taylor!-trace!-mprint,
        taylor!:, taymakecoeff, tayorig, taytemplate, taytpelnext,
        taytpelorder, taytpelpoint, taytpelvars, taytpvars, tayvars,

% from module TayBasic:
        addtaylor!*, multtaylor, multtaylor!*, quottaylor!-as!-sq,

% from module TayConv:
        preptaylor!*,

% from module TayFns:
        inttaylorwrttayvar, taycoefflist!-union,

% from module TayInterf:
        taylor1,

% from module TayIntro:
        nzerolist, replace!-nth, smemberlp, taylor!-error,
        taylor!-error!*, var!-is!-nth,

% from module TaySimp:
        expttayrat, taysimpsq, taysimpsq!*,

% from module TayUtils:
        add!.comp!.tp!., addto!-all!-taytpelorders, enter!-sorted,
        mult!.comp!.tp!., subtr!-tp!-order, tayminpowerlist,
        taytp!-min2, tp!-greaterp, truncate!-taylor!*;


fluid '(!*backtrace
        !*taylor!-assoc!-list!*
        !*tayexpanding!*
        !*taylorkeeporiginal
        !*taylornocache
        !*tayrestart!*
        !*trtaylor);

global '(!*sqvar!* erfg!*);

symbolic smacro procedure !*tay2q!* u;
   ((u . 1) .* 1 .+ nil) ./ 1;


switch taylornocache;

symbolic procedure init!-taylor!-cache;
   !*taylor!-assoc!-list!* := nil . !*sqvar!*;

put('taylornocache,'simpfg,'((t (init!-taylor!-cache))));

symbolic init!-taylor!-cache();

symbolic procedure taylor!-add!-to!-cache(krnl,tp,result);
   if null !*taylornocache
     then car !*taylor!-assoc!-list!* :=
                        ({krnl,sublis({nil . nil},tp)} . result) .
                           car !*taylor!-assoc!-list!*;

fluid '(!*taylor!-expansion!-level!* !*taylor!-max!-precision!-cycles!*);

symbolic(!*taylor!-expansion!-level!* := 0);

symbolic(!*taylor!-max!-precision!-cycles!* := 6);

symbolic procedure taylorexpand(sq,tp);
   (begin scalar result,oldklist,!*tayexpanding!*,!*tayrestart!*,ll;
         integer cycles;
      ll := tp;
      oldklist := get('taylor!*,'klist);
      !*tayexpanding!* := t;
    restart:
      !*tayrestart!* := nil;
      result := errorset!*({'taylorexpand1,mkquote sq,mkquote ll,'t},
                           !*trtaylor);
      put('taylor!*,'klist,oldklist);
      if null errorp result
        then <<result := car result;
               if cycles>0 and taylor!-kernel!-sq!-p result
                 then result := !*tay2q
                                  truncate!-taylor!*(
                                   mvar numr result,tp);
               return result>>;
      if null !*tayrestart!* then error1();
      erfg!* := nil;
      taylor!-trace {"Failed with template",ll};
      cycles := cycles + 1;
      if cycles > !*taylor!-max!-precision!-cycles!*
         then taylor!-error('max_cycles,cycles - 1);
      ll := addto!-all!-taytpelorders(ll,nlist(2,length ll));
      taylor!-trace {"Restarting with template",ll};
      goto restart
   end)
     where !*taylor!-expansion!-level!* := !*taylor!-expansion!-level!*+1;


symbolic procedure taylorexpand1(sq,ll,flg);
   %
   % sq is a s.q. that is expanded according to the list ll
   %  which has the form
   %  ((var_1 var0_1 deg_1 next_1) (var_2 var0_2 deg_2 next_2) ...)
   % flg if true indicates that the expansion order should be
   %  automatically increased if the result has insufficient order.
   %
   begin scalar oldresult,result,lll,lmin,dorestart,nl; integer count;
     lll := ll;
     if null cadr !*taylor!-assoc!-list!*
       then !*taylor!-assoc!-list!* := nil . !*sqvar!*;
    restart:
     count := count + 1;
     if count > !*taylor!-max!-precision!-cycles!*
        or oldresult and taytemplate oldresult = taytemplate result
       then taylor!-error('max_cycles,count - 1);
     oldresult := result;
     taylor!-trace {"expanding s.q. (level", !*taylor!-expansion!-level!*, 
                    ") with template", 
                    for each el in ll collect 
                      {taytpelvars el,
		       taytpelpoint el,
		       preptayexp taytpelorder el,
		       preptayexp taytpelnext el}};
     taylor!-trace!-mprint mk!*sq sq;
     if denr sq = 1
       then result := taysimpsq!* taylorexpand!-sf(numr sq,lll,t)
%      else if not dependsl(denr sq,TayTpVars lll) then begin scalar nn;
%         nn := taylorexpand!-sf(numr sq,lll,t);
%         if Taylor!-kernel!-sq!-p nn
%           then result := !*tay2q multtaylorsq(
%                             truncate!-Taylor!*(mvar numr nn,lll),
%                             1 ./ denr sq)
%          else result := taysimpsq!* quotsq(nn,1 ./ denr sq)
%        end
%      else if numr sq = 1 then begin scalar dd;
%         dd := taylorexpand!-sf(denr sq,lll,nil);
%         if null numr dd
%           then Taylor!-error!*('zero!-denom,'taylorexpand)
%          else if Taylor!-kernel!-sq!-p dd
%           then if Taylor!*!-zerop mvar numr dd
%                  then <<!*tayrestart!* := t;
%                         Taylor!-error('zero!-denom,
%                                       'taylorexpand)>>
%                 else result := !*tay2q invtaylor mvar numr dd
%          else result := taysimpsq!* invsq dd
%        end
%      else if not dependsl(numr sq,TayTpVars lll) then begin scalar dd;
%         dd := taylorexpand!-sf(denr sq,lll,nil);
%         if null numr dd
%           then Taylor!-error!*('zero!-denom,'taylorexpand)
%          else if Taylor!-kernel!-sq!-p dd
%           then if Taylor!*!-zerop mvar numr dd
%                  then <<!*tayrestart!* := t;
%                         Taylor!-error('zero!-denom,
%                                       'taylorexpand)>>
%          else result := !*tay2q multtaylorsq(
%                                     truncate!-Taylor!*(
%                                       invtaylor mvar numr dd,
%                                       lll),
%                                   numr sq ./ 1)
%          else result := taysimpsq!* quotsq(numr sq ./ 1,dd)
%        end
      else begin scalar nn,dd;
         dd := taylorexpand!-sf(denr sq,lll,nil);
         if null numr dd
           then taylor!-error!*('zero!-denom,'taylorexpand)
          else if not taylor!-kernel!-sq!-p dd
           then return
              result := taysimpsq!*
                          quotsq(taylorexpand!-sf(numr sq,lll,t),dd);
         lmin := prune!-coefflist taycoefflist mvar numr dd;
         if null lmin then taylor!-error!*('zero!-denom,'taylorexpand);
         lmin := tayminpowerlist lmin;
         nn := taylorexpand!-sf(
                 numr sq,
                 addto!-all!-taytpelorders(lll,lmin),t);
         if not (taylor!-kernel!-sq!-p nn and taylor!-kernel!-sq!-p dd)
           then result := taysimpsq!* quotsq(nn,dd)
          else result := quottaylor!-as!-sq(nn,dd);
       end;
     if not taylor!-kernel!-sq!-p result
       then return if not smemberlp(taytpvars ll,result)
                     then !*tay2q cst!-taylor!*(result,ll)
                    else result;
     result := mvar numr result;
     dorestart := nil;
      taylor!:
        begin scalar ll1;
          ll1 := taytemplate result;
          for i := (length ll1 - length ll) step -1 until 1 do
            ll := nth(ll1,i) . ll;
          if flg then <<nl := subtr!-tp!-order(ll,ll1);
                        for each o in nl do if o>0 then dorestart := t>>
         end;
     if dorestart
%     if tp!-greaterp(ll,TayTemplate result)
       then <<lll := addto!-all!-taytpelorders(lll,nl);
              taylor!-trace {"restarting (loss of precision):",
                             "old =",ll,
                             "result =",result,
                             "new =",lll};
              goto restart>>;
     result := truncate!-taylor!*(result,ll);
     if !*taylorkeeporiginal then set!-tayorig(result,sq);
     result := !*tay2q result;
     taylor!-trace {"result of expanding s.q. (level", !*taylor!-expansion!-level!*, ") is"};
     taylor!-trace!-mprint mk!*sq result;
     return result
  end;

symbolic procedure taylorexpand!-sf(sf,ll,flg);
   begin scalar lcof,lp,next,rest,x,dorestart,lll,xcl,nl,tps;
         integer l,count;
     lll := ll;
    restart:
     count := count + 1;
     if count > !*taylor!-max!-precision!-cycles!*
       then taylor!-error('max_cycles,count - 1);
     taylor!-trace {"expanding s.f. (level", !*taylor!-expansion!-level!*,
                    ") with template", 
                    for each el in ll collect 
                      {taytpelvars el,
		       taytpelpoint el,
		       preptayexp taytpelorder el,
		       preptayexp taytpelnext el}};
     taylor!-trace!-mprint mk!*sq !*f2q sf;
     x := nil ./ 1;
     rest := sf;
     while not null rest do <<
       if domainp rest
         then <<next := !*tay2q!* cst!-taylor!*(rest ./ 1,lll);
                rest := nil>>
        else <<
          lp := taylorexpand!-sp(lpow rest,lll,flg);
          if lc rest=1 then next := lp
           else <<
          lcof := taylorexpand!-sf(lc rest,lll,flg);
          if taylor!-kernel!-sq!-p lcof and taylor!-kernel!-sq!-p lp
            and (tps :=
                   mult!.comp!.tp!.(mvar numr lcof,mvar numr lp,nil))
            then next := !*tay2q!*
                           multtaylor!*(mvar numr lcof,mvar numr lp,tps)
           else next := taysimpsq!* multsq(lcof,lp);
         >>;
          rest := red rest>>;
       if null numr x then x := next
        else if taylor!-kernel!-sq!-p x and taylor!-kernel!-sq!-p next
               and (tps := add!.comp!.tp!.(mvar numr x,mvar numr next))
         then x := !*tay2q!*
                     addtaylor!*(mvar numr x,mvar numr next,car tps)
        else x := taysimpsq!* addsq(x,next)>>;
     if not taylor!-kernel!-sq!-p x then return x;
     if null flg then <<
       xcl := prune!-coefflist taycoefflist mvar numr x;
       if null xcl then <<
         lll := addto!-all!-taytpelorders(lll,nlist(2,length lll));
         taylor!-trace {"restarting (no coeffs)...(",count,")"};
         goto restart >>
        else taylor!:
             <<l := tayminpowerlist xcl;
               dorestart := nil;
               nl := for i := 1:length lll collect
                       if nth(l,i)>0
                         then <<dorestart := t;
                                2*nth(l,i)>>
                        else 0;
               if dorestart
                 then <<flg :=t;
                        lll := addto!-all!-taytpelorders(lll,nl);
                        taylor!-trace
                          {"restarting (no cst trm)...(",count,"):",
                           "result =",mvar numr x,
                           "new =",lll};
                        goto restart>>>>>>;
     taylor!-trace {"result of expanding s.f. (level", !*taylor!-expansion!-level!*, ") is"};
     taylor!-trace!-mprint mk!*sq x;
     return x
  end;


symbolic procedure taylorexpand!-sp(sp,ll,flg);
  taylor!:
   begin scalar fn,krnl,pow,sk,vars;
%    if (sk := assoc({sp,ll},car !*taylor!-assoc!-list!*))
%      then return cdr sk;
    taylor!-trace {"expanding s.p. (level", !*taylor!-expansion!-level!*,
                   ") with template", 
                   for each el in ll collect 
                      {taytpelvars el,
		       taytpelpoint el,
		       preptayexp taytpelorder el,
		       preptayexp taytpelnext el}};
    taylor!-trace!-mprint mk!*sq !*p2q sp;
    vars := taytpvars ll;
    krnl := car sp;
    pow := cdr sp;
    if idp krnl and krnl memq vars
      then <<pow := 1;
             sk := !*tay2q!* make!-pow!-taylor!*(krnl,cdr sp,ll);
%             taylor!-add!-to!-cache(sp,TayTemplate mvar numr sk,sk)
             >>
      % optimization for (expt var (quotient fixnum fixnum))
     else if eqcar(krnl,'expt) and cadr krnl memq vars and
              eqcar(caddr krnl,'quotient) and fixp cadr caddr krnl and fixp caddr caddr krnl
      then <<pow := mkrn(cdr sp * cadr caddr krnl,caddr caddr krnl);
	     sk := !*tay2q!* make!-pow!-taylor!*(cadr krnl, pow,ll);
             pow := 1>>
     else if sfp krnl then sk := taylorexpand!-sf(krnl,ll,flg)
     else if (sk := assoc({sp,ll},car !*taylor!-assoc!-list!*))
      then <<pow := 1;
             sk := cdr sk>>
     else if not(pow=1) and
             (sk := assoc({krnl . 1,ll},car !*taylor!-assoc!-list!*))
      then sk := cdr sk
     else <<sk := if idp krnl
              then if dependsl(krnl,vars)
                     then taylorexpand!-diff(krnl,ll,flg)
                    else !*tay2q!* cst!-taylor!*(simp!* krnl,ll)
             else if taylor!*p krnl
                    then if smemberlp(vars,tayvars krnl)
                           then taylorexpand!-samevar(krnl,ll,flg)
                   else taylorexpand!-taylor(krnl,ll,flg)
             else if not idp car krnl
              then taylorexpand!-diff(krnl,ll,flg)
%             else if (fn := get(car krnl,'taylordef))
%              then
             else if null(fn := get(car krnl,'taylorsimpfn))
              then taylorexpand!-diff(krnl,ll,flg)
             else begin scalar res,args,flg,!*taylorautoexpand;
                    args := for each el in cdr krnl collect
                              if not dependsl(el,vars) then el
                               else <<flg := t;
                                      prepsq
                                        taylorexpand(simp!* el,ll)>>;
                    if has!-taylor!* args
                      then res := apply1(fn,car krnl . args)
                     else if null flg
                      then res :=
                             !*tay2q!* cst!-taylor!*(mksq(krnl,1),ll)
                     else res := mksq(krnl,1);
                    return res
                  end;
            if taylor!-kernel!-sq!-p sk
              then taylor!-add!-to!-cache(
                     krnl . 1,taytemplate mvar numr sk,sk)>>;
    if not(pow = 1)
      then <<if not taylor!-kernel!-sq!-p sk
               then sk := taysimpsq exptsq(sk,pow)
              else <<sk := mvar numr sk;
                     sk := !*tay2q!* if pow=2 then multtaylor(sk,sk)
                                      else expttayrat(sk,pow ./ 1)>>;
             if taylor!-kernel!-sq!-p sk
               then taylor!-add!-to!-cache(
                      sp,taytemplate mvar numr sk,sk)>>;
    taylor!-trace {"result of expanding s.p. (level", !*taylor!-expansion!-level!*, ") is"};
    taylor!-trace!-mprint mk!*sq sk;
    return sk
  end;

symbolic procedure make!-pow!-taylor!*(krnl,pow,ll);
  taylor!:
   begin scalar pos,var0,nxt,ordr,x,torig; integer pos1;
     pos := var!-is!-nth(ll,krnl);
     pos1 := cdr pos;
     pos := car pos;
     var0 := taytpelpoint nth(ll,pos);
     ordr := taytpelorder nth(ll,pos);
     nxt := taytpelnext nth(ll,pos);
     if !*taylorkeeporiginal
       then torig := if eqcar(pow,'!:rn!:)
                       then simpexpt1(krnl,cdr pow,t)
		      else mksq(krnl,pow);
%     if ordr < pow
%       then
             ll := replace!-nth(ll,pos,
                               ({taytpelvars tpel,
                                 taytpelpoint tpel,
                                 max2(pow,ordr),max2(pow,ordr)+nxt-ordr}
                                 where tpel := nth(ll,pos)));
%     if ordr < 1 then return
%        make!-Taylor!*(nil,replace!-nth(ll,pos,
%                                        ({TayTpElVars tpel,
%                                         TayTpElPoint tpel,
%                                         TayTpElOrder tpel,
%                                         1}
%                                         where tpel := nth(ll,pos))),
%                       nil,nil)
%     else
      if var0 = 0 or var0 eq 'infinity
        then return make!-taylor!*(
               {make!-var!-coefflist(ll,pos,pos1,pow,
                                     var0 eq 'infinity)},
               ll,
               torig,
               nil);
      x := make!-taylor!*(
               {make!-cst!-coefficient(simp!* var0,ll),
                make!-var!-coefflist(ll,pos,pos1,1,nil)},
               ll,
               nil,
               nil);
      if not (pow=1) then x := expttayrat(x,
                                          if eqcar(pow,'!:rn!:) then cdr pow 
                                           else pow ./ 1);
      if !*taylorkeeporiginal then set!-tayorig(x,torig);
      return x
   end;

symbolic procedure make!-var!-coefflist(tp,pos,pos1,pow,infflg);
   taymakecoeff(make!-var!-powerlist(tp,pos,pos1,pow,infflg),1 ./ 1);

symbolic procedure make!-var!-powerlist(tp,pos,pos1,pow,infflg);
   if null tp then nil
    else ((if pos=1
             then for j := 1:l collect
                    if j neq pos1 then 0
                     else if infflg then -pow
                     else pow
            else nzerolist l)
          where l := length taytpelvars car tp)
          . make!-var!-powerlist(cdr tp,pos - 1,pos1,pow,infflg);


symbolic procedure taylorexpand!-taylor(tkrnl,ll,flg);
   begin scalar tay,notay,x;
     notay := nil ./ 1;
     for each cc in taycoefflist tkrnl do <<
%       x := taylorexpand1(TayCfSq cc,ll,t);
       x := taylorexpand1(taycfsq cc,ll,flg);
       if taylor!-kernel!-sq!-p x
         then tay := nconc(tay,
                           for each cc2 in taycoefflist mvar numr x
                             collect taymakecoeff(
                                       append(taycfpl cc,taycfpl cc2),
                                       taycfsq cc2))
        else taylor!-error('expansion,"(possbile singularity)")>>;
              %notay := aconc!*(notay,cc)>>;
     return
       if null tay then nil ./ 1
        else !*tay2q!* make!-taylor!*(tay,
                                      append(taytemplate tkrnl,ll),
                                      nil,nil);
  end;


COMMENT The cache maintained in !*!*taylorexpand!-diff!-cache!*!* is
        the key to handle the case of a kernel whose derivative
        involves the kernel itself. It is guaranteed that in every
        recursive step the expansion order is smaller than in the
        previous one;

fluid '(!*!*taylorexpand!-diff!-cache!*!*);

symbolic procedure taylorexpand!-diff(krnl,ll,flg);
  begin scalar result;
    %
    % We use a very simple strategy: if we know a partial derivative
    %  of the kernel, we pass the problem to taylorexpand!-diff1 which
    %  will try to differentiate the kernel, expand the result and
    %  integrate again.
    %
    % NOTE: THE FOLLOWING test can be removed, but needs more checking
    %        removing it seems to slow down processing
    %
    if null atom krnl and get(car krnl,dfn_prop krnl)
      then
        (result := errorset!*({'taylorexpand!-diff1,
                                 mkquote krnl,mkquote ll,mkquote flg},
                                !*backtrace)
           where !*!*taylorexpand!-diff!-cache!*!* :=
                   !*!*taylorexpand!-diff!-cache!*!*);
    %
    % If this fails we fall back to simple differentiation and
    %  substitution at the expansion point.
    %
    if result and not errorp result
      then result := car result
     else if !*tayrestart!* then error1() % propagate
     else <<result := !*k2q krnl;
            for each el in ll do
              %
              % taylor1 is the function that does the real work
              %
              result := !*tay2q!* taylor1(result,
                                          taytpelvars el,
                                          taytpelpoint el,
                                          taytpelorder el)>>;
    if !*taylorkeeporiginal and taylor!-kernel!-sq!-p result
      then set!-tayorig(mvar numr result,!*k2q krnl);
    return result
  end;

symbolic procedure taylorexpand!-diff1(krnl,ll,flg);
   <<if y and taytpvars ll = taytpvars(y := cdr y)
          and not tp!-greaterp(y,ll)
       then ll := for each el in y collect
                    {taytpelvars el,taytpelpoint el,
                     taytpelorder el - 1,taytpelnext el - 1};
     !*!*taylorexpand!-diff!-cache!*!* :=
                (krnl . ll) . !*!*taylorexpand!-diff!-cache!*!*;
     for each el in ll do result := taylorexpand!-diff2(result,el,nil);
     result>>
       where result := !*k2q krnl,
             y := assoc(krnl,!*!*taylorexpand!-diff!-cache!*!*);

symbolic procedure taylorexpand!-diff2(sq,el,flg);
   begin scalar l,singlist,c0,tay,l0,tp,tcl,sterm;
     singlist := nil ./ 1;
     tp := {el};
     %
     % We check whether there is a rule for taylorsingularity.
     %
     sterm := simp!* {'taylorsingularity,mvar numr sq,
                      'list . taytpelvars el,taytpelpoint el};
     if kernp sterm and eqcar(mvar numr sterm,'taylorsingularity)
       then sterm := nil % failed
      else sq := subtrsq(sq,sterm);
     if taytpelorder el > 0 then <<
       l := for each var in taytpelvars el collect begin scalar r;
            r := taylorexpand1(diffsq(sq,var),
                               {{taytpelvars el,
                                 taytpelpoint el,
                                 taytpelorder el - 1,
                                 taytpelnext el - 1}},flg);
            if taylor!-kernel!-sq!-p r
              then return inttaylorwrttayvar(mvar numr r,var)
             else taylor!-error('expansion,"(possible singularity)");
          end;
       tcl := taycoefflist!-union
                for each pp in l collect taycoefflist cdr pp;
       for each pp in l do
         if car pp then singlist := addsq(singlist,car pp);
       if not null numr singlist
         then taylor!-error('expansion,"(possible singularity)")>>;
     %
     % If we have a special singularity, then set c0 to zero.
     %
     if not null sterm then c0 := nil ./ 1
      else c0 := subsq(sq,for each var in taytpelvars el collect
                            (var . taytpelpoint el));
     l0 := {nzerolist length taytpelvars el};

     if null numr c0 then nil
      else if not taylor!-kernel!-sq!-p c0
       then tcl := taymakecoeff(l0,c0) . tcl
      else <<c0 := mvar numr c0;
             tp := nconc!*(taytemplate c0,tp);
             for each pp in taycoefflist c0 do
               tcl := enter!-sorted(taymakecoeff(append(taycfpl pp,l0),
                                                 taycfsq pp),
                                    tcl)>>;

     if not null l
       then for each pp in l do
              tp := taytp!-min2(tp,taytemplate cdr pp);

     tay := !*tay2q!* make!-taylor!*(tcl,tp,
                         if !*taylorkeeporiginal then sq else nil,nil);

     if not null numr singlist then tay := addsq(singlist,tay);

     if null sterm then return tay
      else return taysimpsq!* addsq(taylorexpand(sterm,tp),tay)
  end;

algebraic operator taylorsingularity;

if null get('psi,'simpfn) then algebraic operator psi;

algebraic let {
  taylorsingularity(dilog(~x),~y,~y0) => pi^2/6 - log(x)*log(1-x) when sub(foreach y1 in y collect y1=y0,x)=0,
  taylorsingularity(Ei(~x),~y,~y0) => (log(x)-log(1/x))/2 - psi(1) when sub(foreach y1 in y collect y1=y0,x)=0
};

%% The following do not really work
%%
%%  taylorsingularity(gamma(~x),~y,~y0) => 1/x + psi(1) when sub(foreach y1 in y collect y1=y0,x)=0
%%  taylorsingularity(psi(~x),~y,~y0) => -1/x + psi(1) when sub(foreach y1 in y collect y1=y0,x)=0,
%%  taylorsingularity(polygamma(~n,~x),~y,~y0) => (if evenp n then -1 else 1)*factorial(n)/x^(n+1) + polygamma(n,1) 
%%     	      	       	     	      	       	  when fixp n and n>0 and sub(foreach y1 in y collect y1=y0,x)=0


symbolic procedure taylorexpand!-samevar(u,ll,flg);
  taylor!:
  begin scalar tpl;
    tpl := taytemplate u;
    for each tpel in ll do begin scalar tp,varlis,mdeg,n; integer pos;
      varlis := taytpelvars tpel;
      pos := car var!-is!-nth(tpl,car varlis);
      tp := nth(tpl,pos);
      if length varlis > 1 and not (varlis = taytpelvars tp)
        then taylor!-error('not!-implemented,
                            "(homogeneous expansion in TAYLORSAMEVAR)");
      n := taytpelorder tpel;
      if taytpelpoint tp neq taytpelpoint tpel
        then u := taylor1(if not null tayorig u then tayorig u
                           else simp!* preptaylor!* u,
                          varlis,taytpelpoint tpel,n);
      mdeg := taytpelorder tp;
      if n=mdeg then nil
       else if n > mdeg
        %
        % further expansion required
        %
        then if null flg then nil
              else taylor!-error('expansion,
                                 "Cannot expand further... truncated.")
       else u := make!-taylor!*(
          for each cc in taycoefflist u join
            if nth(nth(taycfpl cc,pos),1) > n
              then nil
             else list cc,
          replace!-nth(tpl,pos,{varlis,taytpelpoint tpel,n,n+1}),
          tayorig u,tayflags u)
     end;
    return !*tay2q!* u
  end;

endmodule;

end;
