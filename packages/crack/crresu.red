%********************************************************************
module resultante$
%********************************************************************
%  Routines for computing the resultant as a list of factors
%  Author: Eberhard Schruefer March 2008 (computing routines)
%          Thomas Wolf 2014 (embedding in crack)

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

% Whenever a row of the Bezout matrix is calculated a common
% factor of the head polynomials is calculated and divided out.
% Then a common factor of each Bezout polynomial and their
% successive exterior product is determined and taken out.
% Before calculating a common factor, a trial divison of previously
% found factors is performed (suggested by Thomas).
% A list of factors of the Resultant with their multiplicities is
% returned. 
% Note that it is not attempted to calculate a factorization
% of the last factor.
% For non square matrices the code still could be improved.

% Author: Eberhard Schruefer, June 2008

% Code status: experimental.

% bresultant returns a list of lists. (The first element is a
% numerical factor). I.e. 
% {{num factor},{factor_1,multiplicity_1},....,{factor_n,multiplicity_n}}


flag('(bresultant),'opfn)$
%-------------------------------

symbolic procedure err_catch_resul(l1,l2,v)$
% currently not used
begin scalar h,bak,bakup_bak$
 bak:=max_gc_counter;max_gc_counter:=my_gc_counter+max_gc_elimin;
 bakup_bak:=backup_;backup_:='max_gc_elimin$
 h:=errorset({'bresultant,mkquote l1,mkquote l2,mkquote v},nil,nil)
    where !*protfg=t;
 erfg!*:=nil; 
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h  
end$
%-------------------------------

symbolic procedure degfl(l,f)$
begin scalar del$
 del:=get(l,'derivs);
 while del and f neq caaar del do del:=cdr del; 
 return cdar del
end$

symbolic procedure add_res_with(f,de1,de2)$
begin scalar a,b$
  a:=get(de2,'res_with)$
  b:=assoc(f,a)$
  if b then <<a:=delete(b,a)$ b:=cons(f,cons(de1,cdr b))>>
       else b:=list(f,de1)$
  put(de2,'res_with,cons(b,a))$
end$

symbolic procedure add_both_res_with(f,de1,de2)$
% add de2 to resultant computation of de1 wrt f to get de1 property
% ((f de2 de6 de4 ..) (...)) and the same for de2
begin
  add_res_with(f,de1,de2)$
  add_res_with(f,de2,de1)$
end$

symbolic procedure do_one_resultant(arglist)$  
% compute one resultant from two equations
% - One could have a flag whether 2 equations have already been used to
%   compute a resultant from but resultants either
%   - result in an equation for fewer variables, or
%   - result in two factorized equations.
%   So if resultants are usually computed only when no more factors are known
%   that can be set to zero in case distinctions and only for a pair of
%   equations with the lowest number of unknowns then the same equations
%   should not be paired again and therefore one does not need to record
%   whether two equations have been paired for a resultant.

begin scalar pdes,cpu,gc,p,avf,del,l,l1,l2,with1,fcts1,nvars1,terms1,
      allvarfcts1,h,foundbetterpair,best1,best2,bestf,bestnfcts,bestsize,
      d1,d2,ltd$

 cpu:=time()$ gc:=gctime()$
 pdes:=car arglist$

 if expert_mode then l:=selectpdes(pdes,2)
                else l:=pdes;

 % find a pair of equations algebraic and polynomial in one function of all
 % variables, with as few as possible functions+unknowns in both equations,
 % both equations with a few as possible terms, with the sum of
 % degrees of that function in both equations as low as possible,

 % ----- Start:

 % From all equations in l collect those which are purely algebraic in the
 % functions of all variables (any other pairings could still be done
 % interactively).

 for each p in l do 
 if not pairp get(p,'fac) then << % Factorizable equations should first be
                                  % case checked because a lower degree reduces
                                  % the computational complexity of resultant 
                                  % computations.
  avf:=get(p,'allvarfcts);
  if avf then <<
   del:=get(p,'derivs);
   while del and (null cdaar del            % algebraic
                  or freeof(avf,caaar del)  % not of all variables
                 ) do del:=cdr del;
   if null del then l1:=cons(p,l1);
  >>
 >>$
 if null l1 then return nil;
 l:=l1;

 % Now determination of the best pairing, i.e. of 
 % two equations and the function to be eliminated

 bestnfcts:=10000; % 1st criterion
 l1:=car l; l:=cdr l;
 while l do << % l is the list of potential partners of l1

  % assign often to be compared properties of l1 to some variables
  with1:=get(l1,'res_with);
  fcts1:=get(l1,'fcts);
  nvars1:=get(l1,'nvars);
  terms1:=get(l1,'terms);
  allvarfcts1:=get(l1,'allvarfcts);
  
  for each l2 in l do % find a partner equation
  if null member(l2,with1) and % they must not have been paired yet
     nvars1=get(l2,'nvars) and % although this check is contained in the 
                               % following check, but this is quick
     (allvarfcts1=get(l2,'allvarfcts)) % they need to depend on the same
                                       % allvarfcts as otherwise other 
                                       % modules like 27,30 should be used 
                                       % first which replace equations by 
                                       % simplified equations
  then << % the pair (l1,l2) is possible and is to be considered

   % 1st criterion: minimal total number of fcts
   % 2nd criterion: munimal total number of terms
   if (h:=(length union(fcts1,get(l2,'fcts)))) < bestnfcts then <<
    bestnfcts:=h;
    bestsize:=terms1+get(l2,'terms);
    foundbetterpair:=t
   >>                                                      else 
   if h=bestnfcts then <<
    h:=terms1+get(l2,'terms);
    if h<bestsize then <<bestsize:=h;foundbetterpair:=t>> 
                  else foundbetterpair:=nil;
   >>             else foundbetterpair:=nil;

   if foundbetterpair then << % find a function bf to be eliminated
    % the best pair of equations
    best1:=l1;
    best2:=l2;

    % simple version which guarantees that different resultant-computations
    % eliminate the same functions first, i.e. follow the same strategy
    bestf:=car allvarfcts1;

    % other possible option:
    % find a function bf with the minimum total degree ltd 
    % to be eliminated (l1,l2 have the same allvarfcts)
    if nil then <<
     ltd:=10000; % lowest total degree 
     for each f in allvarfcts1 do <<
      d1:=degfl(l1,f); % degree of f in l1
      d2:=degfl(l2,f); % degree of f in l2

      %% the dimension of the Sylvester matrix is d1+d2
      %if (d1+d2)<ltd then <<ltd:=d1+d2; bestf:=f>>

      % in the Bezout construction of the resultant the matrix 
      % has the dimension max(d1,d2)
      if d2>d1 then d1:=d2;
      if d1<ltd then <<ltd:=d1; bestf:=f>> 

     >>
    >>;

    % third option: eliminate a function f if there is at least one equation
    % without f and with allvarfcts that is a subset of allvarfcts1
    % ...

   >>
  >>$
  l1:=car l; l:=cdr l
 >>$

 if bestnfcts<10000 then << % at lest one good pair of equations has been found
  % compute the resultant
  pdes:=one_resultant(pdes,best1,best2,bestf)$

  % record the pairing
  add_both_res_with(bestf,best1,best2)

 >>                 else pdes:=nil$

 if print_ and !*time then <<
  write " time : ", time() - cpu,
        " ms    GC time : ", gctime() - gc," ms.      "
 >>$

 return if null pdes then nil
                     else list(pdes,cadr arglist)

end$
%-------------------------------

symbolic procedure comp_resultant(pdes)$
% This procedure is called interactively.
begin scalar s,l;
 l:=selectpdes(pdes,2)$

 if length(s:=get(car  l,'derivs))=1 then <<
  s:=caar s;
  s:=if null cdr s then car s else cons('df,s);
  if freeof(get(cadr l,'kern),s) then <<
   write"No common kernel in both equations."$terpri()
  >>
 >>                                  else
 if length(s:=get(cadr l,'derivs))=1 then <<
  s:=caar s;
  s:=if null cdr s then car s else cons('df,s);
  if freeof(get(car l,'kern),s) then <<
   write"No common kernel in both equations."$terpri()
  >>
 >>                                 else <<
  change_prompt_to "Which function/derivative shall be eliminated? "$ 
  s:=termread()$
  restore_interactive_prompt()$
  if freeof(get(car  l,'kern),s) or
     freeof(get(cadr l,'kern),s) then <<
   write"This is not a kernel in both equations."$terpri()
  >>
 >>$

 l:=one_resultant(pdes,car l,cadr l,s)$
 return if l then l else pdes

end$
%-------------------------------

symbolic procedure one_resultant(pdes,e1,e2,s)$
begin scalar rational_bak,ezgcd_bak,gcd_bak,h,res$
 on bezout$
 if !*rational then <<algebraic off rational;rational_bak:=t>>$
 if !*ezgcd  then  ezgcd_bak:=t else algebraic on  ezgcd$
 if !*gcd    then    gcd_bak:=t else algebraic on    gcd$
% if !*bezout then bezout_bak:=t else algebraic on bezout$
% !*b!:headpolys_red:=t$
%     res:=bresultant({'!*sq,get(e1,'sqval),nil},
%                     {'!*sq,get(e2,'sqval),nil},s)$
 res:=err_catch_resul({'!*sq,get(e1,'sqval),nil},
                      {'!*sq,get(e2,'sqval),nil},s)$
 % err_catch_resul is necessary due to stack_overflow for large problems
 if null  ezgcd_bak then algebraic off  ezgcd$
 if null    gcd_bak then algebraic off    gcd$
% if null bezout_bak then algebraic off bezout$
 if rational_bak then algebraic on rational$

 if null res then return nil$
 if res='(list 0) then <<
  if print_ then << 
   write "Polynomials ",e1,",",e2," have a common factor and have now"$terpri()$ 
   write "at least each 2 factors recorded in their properties."$terpri()$
  >>$
  res:=err_catch_gcd({'!*sq,get(e1,'sqval),nil},
                     {'!*sq,get(e2,'sqval),nil});
  res:=simp res$
  % possible improvement: factorize the gcd and multipliers with symbolic 
  % procedure err_catch_fac2(a)$
  h:=get(e1,'fac)$ 
  if ((h=nil) or (fixp h)) and (res neq get(e1,'sqval))
  then put(e1,'fac,{res,quotsq(get(e1,'sqval),res)})$

  h:=get(e2,'fac)$ 
  if ((h=nil) or (fixp h)) and (res neq get(e2,'sqval))
  then put(e2,'fac,{res,quotsq(get(e2,'sqval),res)})$
 >>             else <<
  res:=for each h in cdr res collect simp!* cadr h;
  res:=mkeqSQ(nil,res,nil,union(get(e1,'fcts),get(e2,'fcts)),
              union(get(e1,'vars),get(e2,'vars)),allflags_,
              t,list(0),nil,pdes)$
  if print_ then << 
   write "Computing the resultant for ",e1,", ",e2," wrt. ",s,
         " gives the new equation ",res,"."$terpri()$
  >>$
  pdes:=eqinsert(res,pdes)
 >>$
 return pdes
end$

symbolic procedure bresultant(u,v,var)$
   begin scalar x,!*exp;
     !*exp := t;
     u := numr simp!* u;
     v := numr simp!* v;
     var := !*a2k var;
     if domainp u and domainp v
      then return {'list,1};
       kord!* := var . kord!*; 
       if null domainp u and null(mvar u eq var)
	 then u := reorder u;
       if null domainp v and null(mvar v eq var)
	 then v := reorder v;
       x := bezout_resultant_fac(u,v,var);
       setkorder cdr kord!*;
       return x
   end$

symbolic procedure bezout_resultant_fac(u,v,w)$
   % U and v are standard forms. Result is resultant of u and v
   % w.r.t. kernel w. Method is Bezout's determinant using exterior
   % multiplication for its calculation.
   begin integer n,nm; scalar ap,ep,uh,ut,vh,vt,x,cx,cxf,cep,cuh,cvh,res_verbose;
     res_verbose:=nil$
     if res_verbose then <<write "entering bezout."; terpri()>>;
     !*exp := t;
     if domainp u or null(mvar u eq w)
        then return if not domainp v and mvar v eq w
                       then {'list,mk!*sq(exptf(u,ldeg v) ./ 1)}
                     else {'list,1}
      else if domainp v or null(mvar v eq w)
        then return if mvar u eq w then {'list,mk!*sq(exptf(v,ldeg u) ./ 1)} 
                     else {'list,1};
     n := ldeg v - ldeg u;
     cxf := '(1);
     if n < 0 then <<x := u; u := v; v := x; cxf := '(-1); n := -n>>;
     ep := 1;
     nm := ldeg v;
     uh := lc u;
     vh := lc v;
     ut := if n neq 0 then multpf(w to n,red u) else red u;
     vt := red v;
     cx := 1;
     cuh := uh;
     cvh := vh;
     cx := gcdf!*(uh,vh);
     if cx = 1 then if res_verbose then 
     <<write "Found trivial factor from headpolys only. "; terpri()>>
                                   else
      else <<if res_verbose then <<write "Found factor from headpolys with ",
                                         termsf cx," terms."; terpri()>>;
             cxf := fctrf cx>>;
     ap := addf(multf(quotf1(uh,cx),vt),negf multf(quotf1(vh,cx),ut));
     x := !*sf2exb(ap,w);
     if cdr cxf then x := b!:try_previous_factors(x,cdr cxf);
     cx := b!:comfac x;
     if cx neq 1 then <<cxf := bfac!-merge(fctrf cx,cxf);
                        if res_verbose then <<
                         write "commom factor cx found. ",tmsf cx," terms.";
			 terpri()
                        >>
                      >>;
     x := b!:cquot(x,cx);
     ep := b!:extmult(x,ep);
     if cdr cxf then ep := b!:try_previous_factors(ep,cdr cxf);
     for j := (nm - 1) step -1 until (n + 1) do
        <<if degr(ut,w) = j then
             <<uh := addf(lc ut,multf(!*k2f w,uh));
               if null(cuh = 1 or cvh = 1) then cuh := gcdf!*(lc ut,cuh);
               ut := red ut>>
           else uh := multf(!*k2f w,uh);
          if degr(vt,w) = j then
             <<vh := addf(lc vt,multf(!*k2f w,vh));
               if null(cuh = 1 or cvh = 1) then cvh := gcdf!*(lc vt,cvh);
               vt := red vt>>
           else vh := multf(!*k2f w,vh);
          cx := 1;
          cx := gcdf!*(cuh,cvh); 
          if cx = 1 then if res_verbose then 
          <<write "Found trivial factor from headpolys only. "; terpri()>>
                                        else
           else <<if res_verbose then <<write "Found factor from headpolys with ",
                                              termsf cx," terms."; terpri()>>;
                  cxf := bfac!-merge(fctrf cx,cxf)>>;
          x := !*sf2exb(addf(multf(quotf1(uh,cx),vt),
                             negf multf(quotf1(vh,cx),ut)),w);
          if cdr cxf then x := b!:try_previous_factors(x,cdr cxf);
          cx := b!:comfac x;
          if cx neq 1 then 
             <<if res_verbose then <<write "commom factor cx found. ",
                                           tmsf cx," terms."$terpri()>>;
               cxf := bfac!-merge(fctrf cx,cxf);
             >>;
          x := b!:cquot(x,cx);
          ep := b!:extmult(x,ep);
          if cdr cxf then ep := b!:try_previous_factors(ep,cdr cxf);
          if j neq 1 then
             <<cep := b!:comfac ep;
               if cep neq 1 then 
                  <<cxf := bfac!-merge(fctrf cep,cxf);
                    if res_verbose then <<write "commom factor cep found. ",
                                          tmsf cep," terms."; terpri()>> >>;
                ep := b!:cquot(ep,cep)>>
                                       >>;
      if n neq 0
         then <<x := !*sf2exb(u,w);
                cx := b!:comfac x;
                if cx neq 1 then 
                   <<if res_verbose then <<write "commom factor cx found.",
                                                 tmsf cx," terms"; terpri()>>;
                     cxf := bfac!-merge(fctrf cx,cxf)>>;
                x := b!:cquot(x,cx);
                ep := b!:extmult(x,ep);
          cep := b!:comfac ep;
          if cep neq 1 then 
             <<if res_verbose then <<write "commom factor cep found. ",
                                           tmsf cep," terms."; terpri()>>;
               cxf := bfac!-merge(fctrf cep,cxf)>>;
          ep := b!:cquot(ep,cep);
                for j := 1:(n-1) do
                  <<x := !*sf2exb(multpf(w to j,u),w);
                    cx := b!:comfac x;
                    if cx neq 1 then 
                       <<if res_verbose then <<write "commom factor cx found. ",
                                                     tmsf cx," terms."; terpri()>>;
                         cxf := bfac!-merge(fctrf cx,cxf)>>;
                    x := b!:cquot(x,cx);
                    ep := b!:extmult(x,ep);
                    cep := b!:comfac ep;
                    if cep neq 1 then 
                       <<cxf := bfac!-merge(fctrf cep,cxf);
                         if res_verbose then <<write "commom factor cep found. ",
                                               tmsf cep," terms."; terpri()>> >>;
                    ep := b!:cquot(ep,cep);
                    >> >>; 
      return if null ep then {'list,0} 
              else if domainp lc ep
                then 'list . {'list,multf(car cxf,lc ep)} .
                               for each j in cdr cxf 
                                   collect {'list,mk!*sq(car j ./ 1),cdr j}
              else 'list . {'list,car cxf} . {'list,mk!*sq(lc ep ./ 1),1} . 
                    for each j in cdr cxf collect {'list,mk!*sq(car j ./ 1),cdr j}
   end$

symbolic procedure b!:comfac u$
   begin scalar !*ezgcd,x;
     %write "entered comfac."; terpri();
     !*ezgcd := t;
     if null u then return 1;
     x := lc u;
     a: u := red u;
        if null u then <<%write "left comfac."; terpri(); 
                         return x>>;
        x := gcdf!*(lc u,x);
        go to a
   end$

symbolic procedure b!:cquot(u,v)$
   if null u then nil
    else lpow u .* quotf1(lc u,v) .+ b!:cquot(red u,v)$

symbolic procedure b!:try_previous_factors(u,v)$
   begin scalar x;
     b: x := b!:ctrialdiv(u,caar v);
        if null x then go to a;
        % write "successful trial div. "; terpri();
        u := x;
        rplacd(car v,cdar v + 1);
        go to b;
     a: v := cdr v;
        if null v then return u;
        go to b
   end$

symbolic procedure b!:ctrialdiv(u,v)$
   begin scalar res,w,x;
     if domainp u then return quotf1(u,v);
     if x := quotf1(lc u,v) then res := w := lpow u .* x .+ nil
      else return nil;
     a: u := red u;
        if null u then return res;
        if domainp u then if x := quotf1(u,v) then <<rplacd(w,x); return res>>
                           else return nil;
        if x := quotf1(lc u,v) then rplacd(w,lpow u .* x .+ nil)
         else return nil;
        w := red w;
       go to a;
   end$

symbolic procedure bfac!-merge(u,v)$
   if null cdr v then multf(car u,car v) . cdr u 
    else multf(car u,car v) . bfac!-merge2(cdr u,cdr v)$

symbolic procedure bfac!-merge2(u,v)$
   begin scalar x,y,r;
     if null u then return v;
     c: x := car u;
        y := v;
     b: if car x = caar y 
           then <<rplacd(car y,cdar y + cdr x);
                  go to a>>;
        y := cdr y;
        if y then go to b;
        r := x . r;
     a: u := cdr u;
        if null u then return append(v,r);
        go to c;
   end$

endmodule$

end$

do_one_resultant
 one_resultant

comp_resultant
 one_resultant

one_resultant
 bresultant
 err_catch_gcd
 mkeqSQ
 eqinsert

bresultant
 bezout_resultant_fac

bezout_resultant_fac
 b!:try_previous_factors
 bfac!-merge

tr err_catch_resul % not used
tr degfl
tr do_one_resultant
tr one_resultant
tr comp_resultant
tr bresultant
tr bezout_resultant_fac
tr b!:comfac
tr b!:cquot
tr b!:try_previous_factors
tr b!:ctrialdiv
tr bfac!-merge
tr bfac!-merge2
