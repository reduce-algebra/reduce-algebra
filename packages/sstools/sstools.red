module sstools;

create!-package('(sstools),nil);

%********************************************************************
%                                                                   *
%  The package SSTOOLS for the study of integrability of            *
%                    super-symmetric PDEs                           *
%                                                                   *
%  Author: Thomas Wolf and Eberhard Schruefer with contributions    *
%          of Winfried Neun                                         *
%                                                                   *
%********************************************************************

global '(!*sstools!-loaded);

!*sstools!-loaded := t;

%----------------------- 
% The following module for non-commutative differentiation and 
% multiplication of fermionic forms is written by Eberhard Schruefer 2007.

module dop$

fluid '(t_changes_parity s_changes_parity asymplis!* ncmp!*)$

switch t_changes_parity,s_changes_parity$

put('t_changes_parity,'simpfg,
    '((t (rmsubs) (setq t_changes_parity t) (clear_t_changes_parity))
         (nil (rmsubs) (setq t_changes_parity nil) (clear_t_changes_parity))))$

put('s_changes_parity,'simpfg,
    '((t (rmsubs) (setq s_changes_parity t) (clear_s_changes_parity))
         (nil (rmsubs) (setq s_changes_parity nil) (clear_s_changes_parity))))$

symbolic procedure clear_t_changes_parity()$
   begin
     asymplis!* := clear_t_changes_power_rules asymplis!*; 
   end$

symbolic procedure clear_s_changes_parity()$
   begin
     asymplis!* := clear_s_changes_power_rules asymplis!*;
   end$

symbolic procedure clear_t_changes_power_rules u$
   if null u then u
    else if smember('t,car u) then clear_t_changes_power_rules cdr u
    else car u . clear_t_changes_power_rules cdr u$

symbolic procedure clear_s_changes_power_rules u$
   if null u then u
    else if smember('s,car u) then clear_s_changes_power_rules cdr u
    else car u . clear_s_changes_power_rules cdr u$

ncmp!* := t$

rlistat('(fermion))$

symbolic procedure fermion u$ fermion1 u$

symbolic procedure fermion1 u$
   <<flag(u,'fermionic);
     for each j in u 
       do <<flag({j},'full); put(j,'simpfn,'simpfermion)>>; 
     for each j in u do noncom1 j>>$

symbolic procedure simpfermion u$
   begin scalar x,y,z;
     if x := opmtch u then return simp x;
     u := car u . for each j in cdr u collect aeval j;
     y := mksq(u,1);
     if domainp numr y then return y;
     z := mvar numr y;
     if atom z or null(car z eq car u) then return y; 
     if null atsoc(z,asymplis!*) 
        then asymplis!* := (z . 2) . asymplis!*;
     return y
   end$

rlistat('(boson))$

symbolic procedure boson u$ boson1 u$

symbolic procedure boson1 u$
   for each j in u do
     <<flag({j},'bosonic); mkop j>>$

put('d,'simpfn,'simpdop)$

noncom1 'd$

symbolic procedure simpdop u$
   begin scalar x;
     u := aeval car u . cdr u;
     if x := opmtch ('d . u) then return simp x;
%     if x := opmtch u then return simp u;
     x := simp cadr u;
     if null numr x then return x;
     if domainp denr x or null fermionicp mvar denr x
        then return multsq(dopf(car u, numr x), 1 ./ denr x);
     rederr "encountered non constant den in simpdop ...";
   end$

symbolic procedure dopf(n,u)$
   if domainp u then nil ./ 1
    else addsq(addsq(multpq(lpow u,dopf(n,if fermionicp mvar u 
                                             then negf lc u
                                           else lc u)),
                     multsq(dopp(n, lpow u),lc u ./ 1)),dopf(n, red u))$

symbolic procedure dopp(n, u)$
   % the following test that car u is a constant wrt d should be checked if 
   % it is complete.
   if atom car u or null(flagp(caar u,'fermionic) or flagp(caar u,'bosonic) or
                         (caar u eq 'd) or (caar u eq 'df))
      then nil ./ 1
    else if cdr u > 1 
            then multsq(cdr u ./ 1,multsq(simpexpt {car u,cdr u-1},
                                          simpdop {n,car u}))
    else if caar u eq 'd
            then if n = cadr car u 
                    then simpdf {caddr car u,'x}
                  else if n > cadr car u 
                    then negsq simpdop({cadr car u,{'d,n,caddr car u}})
         else mkdsq({'d,n,car u},1)
    else mkdsq({'d,n,car u},1)$

symbolic procedure mkdsq(u,n)$
   begin scalar x,z;
    if x := opmtch u then return simp x;
     x := mksq(u,n);
     if null numr x then return x;
     z := mvar numr x;
     if fermionicp z and null atsoc(z,asymplis!*)
        then asymplis!* := (z . 2) . asymplis!*;
     return x 
   end$
 
symbolic procedure dfdp(u,v,n)$
   begin scalar x;
     x := simpdf {caddr u,v,n};
     if null numr x then return x;
     if ((v eq 't) and t_changes_parity) or
        ((v eq 's) and s_changes_parity)
        then x := negsq x;
     if domainp denr x or
                null fermionicp mvar denr x
        then return multsq(dopf(cadr u, numr x), 1 ./ denr x)
      else rederr "fermioic den encountered in dfdp"
   end$

put('d,'dfform,'dfdp)$

symbolic procedure fermionicp u$
   null atom u and (flagp(car u,'fermionic) or
                    (car u eq 'd and null fermionicp caddr u) or
                    (car u eq 'df and fermionicp caddr u) or
                    (car u eq 'df and 
                     if fermionicp cadr u
                        then if memq('s,cddr u) then not s_changes_parity
                              else if memq('t,cddr u) then not t_changes_parity
                              else t 
                      else if memq('s,cddr u) then s_changes_parity
                            else if memq('t,cddr u) then t_changes_parity
                            else nil))$


symbolic procedure sstools!-multfnc(u,v)$
   % Returns canonical product of U and V, with both main vars non-
   % commutative.
   begin scalar x,y;
      x := multf(lc u,!*t2f lt v);
      if null x then nil
       else if not domainp x and mvar x eq mvar u
        then x := addf(if null (y := mkspm(mvar u,ldeg u+ldeg x))
                         then nil
                        else if y = 1 then lc x
                        else !*t2f(y .* lc x),
                       multf(!*p2f lpow u,red x))
       else if noncomp mvar u 
               then if ordop(mvar u,mvar x)
                       then x := !*t2f(lpow u .* x)
                     else if null(y := multf(!*p2f lpow u,lc x))
                             then x := multf(!*p2f lpow u,red x)
                     else x := addf(!*t2f(lpow x .* 
                                    if fermionicp mvar u and 
                                       fermionicp mvar x then negf y 
                                                         else y),
                                    multf(!*p2f lpow u,red x))
       else x := multf(!*p2f lpow u,x) where !*!*processed=t;
      return addf(x,addf(multf(red u,v),multf(!*t2f lt u,red v)))
   end$

symbolic procedure difff(u,v)$
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   % Allow for differentiable domains.
   if atom u then nil ./ 1
    else if atom car u
     then (if diff!-fn then apply2(diff!-fn,u,v) else nil ./ 1)
        where (diff!-fn =  get(car u,'domain!-diff!-fn))
    else addsq(addsq(multpq(lpow u,difff(if (fermionicp mvar u and
                                             (((v eq 's) and s_changes_parity) or
                                              ((v eq 't) and t_changes_parity) or
                                              fermionicp v 
                                             )
                                            ) 
                                            then negf lc u 
                                            else      lc u,v)),
                        multsq(if cdr lpow u = 1 and (((v eq 's) and s_changes_parity) or
                                                      ((v eq 't) and t_changes_parity) or
                                  fermionicp car lpow u) then diffdp(lpow u,v)
                                else diffp(lpow u,v),lc u ./ 1)),
               difff(red u,v))$

symbolic procedure diffdp(u,v)$
  begin scalar x,y,z,w;
    u := car u;
    if null atom u and (x := get(car u,'dfform)) then return apply3(x,u,v,1);
    if null depends(u,v) then return nil ./ 1;
    if u eq v then return 1 ./ 1;
    if eqcar(u,'df) and v eq 's 
       and t_changes_parity and s_changes_parity 
       and uneven_t_p cddr u
       then z := -1 ./ 1 else z := 1 ./ 1;
    if car u eq 'df
      then if (x := find_sub_df(w := cadr u . merge!-ind!-vars(u,v),
                    get('df,'kvalue)))
           then <<w := simp car x;
                  for each el in cdr x do
                  for i := 1:cdr el do
                  w := diffsq(w,car el);
                  return w>>
           else u := 'df . w
      else u := {'df,u,v};
      w := 1 ./ 1;
      if x := opmtch u then return multsq(z,simp x);
      x := mksq(u,1);
      if null numr x then return x;
      y := mvar numr x;
    if fermionicp y and null atsoc(y,asymplis!*)
    then asymplis!* := (y . 2) . asymplis!*;
 return multsq(z,x)
end$

symbolic procedure uneven_t_p u$
   if car u eq 't
      then if cdr u then null(fixp cadr u and evenp cadr u)
            else t
    else cdr u and uneven_t_p cdr u$

bothtimes put('is_fermionic,'boolfn,'evalfermionicp)$

symbolic procedure evalfermionicp u$
fermionicfp numr simp u$
% begin scalar x;
%  x := numr simp u;
%  return fermionicfp x
% end;

symbolic procedure fermionicfp u$
if domainp u then nil
%else (fermionicp mvar u and fermionicfp lc u) or fermionicfp red u;
             else 
if fermionicp mvar u then not fermionicfp lc u
                     else     fermionicfp lc u$

% The following function makes reording of sstools expresion possible
% (as needed by coeffn for example). Unfortunately some redefinitions
% of standard REDUCE functions are necessary.

symbolic procedure reordablep(u,v)$
   atom u or atom v or reordablekp(u,v)$

symbolic procedure reordablekp(u,v)$
   sstools_kernelp u or sstools_kernelp v$

symbolic procedure sstools_kernelp u$
   car u eq 'd or flagp(car u,'fermionic) or flagp(car u,'bosonic)$

symbolic procedure reordop(u,v)$
   if reordablep(u,v) then ordop(u,v)
      else (!*ncmp and noncomp1 u and noncomp1 v) or ordop(u,v)$

symbolic procedure rmultpf(u,v); !*q2f simp!* prepf (u .* v .+ nil)$


endmodule$

%----------------------- further declarations and initializations

%algebraic$

fermion1 '(f th)$
boson1 '(b)$  

algebraic$
depend  {f,b},t,x$

!#if (memq 'psl lispsystem!*)
set_bndstk_size 50000$
!#endif

lisp <<simplimit!* := 100000$ 
       !*noarg := nil  % not done as 'off noarg$' to prevent compiler message
     >>$
on dfprint$

lisp(!*allfac := nil)$ % instead of OFF ALLFAC in order to avoid difference
                       % between compiled and uncompiled version

symbolic fluid '(x flist blist fblist sysfbl N_ fname_ fname_list nfct_ 
                 use_new_crackout print_ print_more collect_sol sol_list
                 proc_list_ max_factor flin_ subst_1 pdelimit_1 old_history
                 homogen_ max_gc_short max_gc_red_len record_hist
                 !*time lin_test_const lines_written ineq_ html_out
                 !*t_changes_parity !*s_changes_parity)$

lrule1:={D(~n,df(~h,x   )) => lin_test_const**3,
         D(~n,df(~h,x,~m)) => lin_test_const**(2*m+1)}$
lrule2:={D(~n,~h)          => lin_test_const,
         df(~h,x)          => lin_test_const**2,
         df(~h,x,~n)       => lin_test_const**(2*n)}$

subli:={}$       % the list of substitutions coming with the call of ssym
symansatz:={}$   % the ansatz for equations and symmetry

%----------------------- procedures

if lisp(null(getd 'redfront_color) ) then
symbolic procedure redfront_color(a)$ a$

%-------

symbolic operator is_const$
symbolic procedure is_const(a)$
freeof(a,'f) and freeof(a,'b)$

%-------

symbolic operator is_fermion$
symbolic procedure is_fermion(a)$
if pairp a then 
if car a = 'D  then is_boson caddr a
               else
if car a = 'DF then if is_fermion cadr a then 
   if caddr a ='s then not !*s_changes_parity else
   if caddr a ='t then not !*t_changes_parity else t
                                         else 
   if caddr a ='s then !*s_changes_parity else
   if caddr a ='t then !*t_changes_parity else nil
               else 
if car a = 'EXPT then 
   if is_boson cadr a then nil else 
   if (caddr a = 1) then t else 
   if fixp caddr a then nil else 
   write"###### ERROR: UNDEFINED PARITY!! ######"
                 else
if car a = 'TIMES then begin scalar n,h;
                        n:=0;
                        for each h in cdr a do 
                        if is_fermion h then n:=add1 n;
                        return not evenp n
                       end 
                  else
if (car a = 'MINUS) or
   (car a = 'QUOTIENT) then is_fermion cadr a else
   % we assume, the denominator can not be fermionic
if (car a = 'PLUS) then begin scalar h;
                         h:=cdr a;
                         while h and zerop car h do h:=cdr h;
                         return if h then is_fermion car h
                                     else nil
                        end
                   else
if not freeof(a,'f) then t else nil
           else if not freeof(a,'f) then t else nil$

symbolic operator is_boson$
symbolic procedure is_boson(a)$
if pairp a then 
if car a = 'D  then is_fermion caddr a 
               else
if car a = 'DF then if is_boson cadr a then 
   if caddr a ='s then not !*s_changes_parity else
   if caddr a ='t then not !*t_changes_parity else t
                                       else 
   if caddr a ='s then !*s_changes_parity else
   if caddr a ='t then !*t_changes_parity else nil
               else 
if car a = 'EXPT then 
   if is_boson cadr a then t else 
   if (caddr a = 1) then nil else 
   if fixp caddr a then t else 
   write"###### ERROR: UNDEFINED PARITY!! ######"
                 else
if (car a = 'MINUS) or
   (car a = 'QUOTIENT) then is_boson(cadr a) else
if car a = 'TIMES then begin scalar n,h;
                        n:=0;
                        for each h in cdr a do 
                        if is_fermion h then n:=add1 n;
                        return evenp n
                       end 
                  else
if (car a = 'PLUS) then begin scalar h;
                         h:=cdr a;
                         while h and zerop car h do h:=cdr h;
                         return if h then is_boson car h
                                     else t
                        end
                   else
if not freeof(a,'b) then t else nil
           else if not freeof(a,'b) then t else nil$

%-------

symbolic operator ssini$
symbolic procedure ssini(N,nf,nb)$
% initializes N_, fblist and selects printing routines for f(i) and b(j)
begin scalar j;
 N_:=N;   % assignung the global number of super symm generators N_
          % For customized printing:"$  
 if nf=1 then put('f,'prifn,'myfpri)  % to suppress (1) when printing f(1)
         else put('f,'prifn,nil)$     % to print index of all f(i)
 if nb=1 then put('b,'prifn,'myfpri)  % to suppress (1) when printing b(1)
         else put('b,'prifn,nil)$     % to print index of all b(i)
 fblist:=append(for j:=1:nf collect {'f,j},
                for j:=1:nb collect {'b,j} )$
end$

%-------

symbolic procedure presimplify(es,fl)$ 
% es,fl are algebraic lists of equations and functions
begin scalar w,ineq_bak,nopowersbak,eqns,m,k,cpu,p,len_es$
 % Simplifying equations and dropping multiple ones
 len_es:=sub1 length es$
 write len_es," equations result"$terpri()$
 cpu:=time();
 % write((k:=time())-cpu)/1000,
 %      " s: Now simplifying equations and dropping multiple ones"$terpri()$
 w:=nil;   % list of equations consisting of only a coefficient
 ineq_bak:=ineq_$
 ineq_:=nil$ % for simplifyterm
 nopowersbak:=!*nopowers;
 algebraic(off nopowers);
 eqns:=nil$
 fl:=cdr reval fl;
 m:=nil; % list of new equations consisting of only a coefficient
 repeat <<
  if m then <<
   es:=algebraic(sub(lisp cons('LIST,for each k in m collect {'EQUAL,k,0}),lisp es))$
   % w:=append(m,w)$
   w:=nconc(m,w)$
   m:=nil; 
  >>$
  es:=cdr es$         % to get rid of the leading 'LIST
  while es do 
  if zerop car es then es:=cdr es else <<
   k:=algebraic(factorize lisp car es); es:=cdr es$
   k:=cdr k;
   p:=nil; 
   while k do <<
    if not freeoflist(cadr car k,fl) then p:=cons(cadr car k,p);
    k:=cdr k;
   >>$
   if null p then eqns:=cons(1,eqns) else <<
    if cdr p then p:=cons('TIMES,p)
             else p:=simplifyterm(reval car p,fl);
    if atom p then m   :=union({p},   m)
              else eqns:=union({p},eqns)
   >>
  >>$
  es:=cons('LIST,eqns); eqns:=nil
 >> until null m;   

 write length w," coefficients found to be zero: "$listprint w$ terpri()$
 eqns:=nconc(es,w)$
 write reval (len_es+1-length eqns)," redundant equations have been droped."$
 terpri()$

 ineq_:=ineq_bak$
 if nopowersbak then algebraic(on nopowers)$
 write(time()-cpu)/1000," s for pre-simplification"$terpri()$
  
 return eqns
end$

%-------

symbolic procedure input_consistency_test(afwlist,abwlist)$
begin 
 if (length afwlist < 2) and
    (length abwlist < 2) then 
    rederr "flist AND blist are both not assigned."$ 

 afwlist:=cdr afwlist;
 while afwlist and fixp car afwlist and car afwlist>=0 do afwlist:=cdr afwlist;
 if afwlist then if not fixp car afwlist then 
 rederr "The fermionic weight list contains not only numbers!" else % <0
 if not fixp reval algebraic max_deg then
 rederr "If a fermionic weight is < 0 then max_deg must be set!"$

 abwlist:=cdr abwlist;
 while abwlist and fixp car abwlist and car abwlist>0 do abwlist:=cdr abwlist;
 if abwlist then if not fixp car abwlist then 
 rederr "The bosonic weight list contains not only numbers!" else % <=0
 if not fixp reval algebraic max_deg then
 rederr "If a bosonic weight is < 1 then max_deg must be set!"
end$

%-------

symbolic procedure crossprodu(seta,setb,wgt,endprod)$
begin scalar g,k,setbcp;
 if setb then 
 for each g in seta do <<
  setbcp:=setb;
  k:=car g + caar setbcp;
  while k<=wgt do <<
   if k=wgt then endprod:=cons(cons(k,append(cdr g,cdar setbcp)),endprod);
   setbcp:=cdr setbcp;
   if setbcp then k:=car g + caar setbcp 
             else k:=10000000
  >>
 >>$
 return endprod
end$

%-------

symbolic procedure rhs_term_list(N,allf,allb,maxwgt,linsub,forbid,verbose)$
% generation of a list of all fermionic terms and a list of all
% bosonic terms, all of weight maxwgt
begin scalar g,h,j,k,minwgt,maxdeg,maxtermwgt,allv,newv,maxpow,maxwgtm2,
             fprod,bprod,allprod,newprod,linonly,p,q,r,s$

 % As weights can be negative, at first we compute the most negative weight 
 % of a partial product. For that we do not need to consider derivatives as 
 % these have all higher weights than the undifferentiated variables.

 minwgt:=0;  maxdeg:=algebraic max_deg;  allv:=append(allf,allb);
 for each g in allv do
 if car g<0 then minwgt:=minwgt+maxdeg*car g;
 maxtermwgt:=maxwgt-minwgt; % >=maxwgt as minwgt<=0

 % Add to allv for every field its x-derivatives as high as possible
 % and sort the entries by their weight

 maxwgtm2:=maxtermwgt-2;
 % newv:=nil; through initialization
 for each g in allv do <<
  while (car g <= maxwgtm2) and not member(reval {'DF,cadr g,'x},forbid) do <<
   h:=2 + car g;
   g:={h,{'DF,cadr g,'x}};    % not:  reval {'DF,cadr g,'x}
   newv:=cons(g,newv)
  >>
 >>$
 % allv:=idx_sort append(allv,newv);
 allv:=append(allv,newv);

 % Add to allv for each of its elements all possible combinations 
 % of d(i,..) derivatives
 for j:=1:N do <<
  newv:=nil;
  for each g in allv do 
  if car g < maxtermwgt then 
  newv:=cons({add1 car g,{'D,j,cadr g}},newv);
  % allv:=idx_sort append(allv,newv);
  allv:=append(allv,newv);
 >>$

 % generation of all possible products of elements of allv
 allprod:={{0,nil}};
 if verbose then <<
  write"maxwgt=",maxwgt$terpri()$ 
  q:=length allv;                 
  p:=0;                           
  s:=0;                           
 >>$
 for each g in allv do <<
  if verbose then <<
   p:=add1 p;                    
   write p,"(",q,"): ",g$terpri()
  >>$

  if null linsub then linonly:=nil else 
  if smemberl(linsub,cadr g) then linonly:=t
                             else linonly:=nil;
  maxpow:=if linonly or is_fermion cadr g then 1 else
          if car g < 1 then maxdeg else 10000000;
  newprod:=nil;
  if verbose then r:=0; 
  for each h in allprod do 
  if null linonly or null cadr h then <<
   % i.e. either the new factor cadr g is not linonly and
   % can occur arbitrarily often in arbitrary products, or
   % the factors do not contain a linonly factor yet
   k:=car h + car g;
   j:=1$
   while (j <= maxpow) and (k <= maxtermwgt) do <<
    h:=cons(k,cons(linonly or cadr h,cons(cadr g,cddr h)));
    newprod:=cons(h,newprod);
    k:=car h + car g; j:=add1 j
   >>;
   if verbose then r:=r+j-1
  >>$
  if verbose then  s:=s+r;  
  allprod:=nconc(allprod,newprod)
 >>$
  
 % sorting of the products into fermionic and bosonic products
 allprod:=cdr allprod;  % drop of {{0,nil}}
 while allprod do << 
  g:=car allprod; allprod:=cdr allprod;
  if (car g = maxwgt) and (null linsub or cadr g) then 
  if is_fermion cons('TIMES,cdr g) then 
  fprod:=cons(if null cdddr g then caddr g
                              else cons('TIMES,cddr g),fprod)
                                   else 
  bprod:=cons(if null cdddr g then caddr g
                              else cons('TIMES,cddr g),bprod)
 >>$ 

 if verbose then <<write length fprod," fermionic and ",
                         length bprod," bosonic monomials"$terpri()>>$ 
 return {fprod,bprod}

end$

%-------

symbolic procedure gen_eqn(awlist,rhslist,eqn_list,fl,fermionic,tname)$
begin scalar h,w,rlcp,rhs,nf,print_bak,svar$
 svar:=reval tname$
 while awlist do <<
  % an equation df(h,t)=... is generated for each car of element h of awlist
  h:=car awlist; awlist:=cdr awlist;

  % w is the weight of h
  w:=car h; h:=cadr h;

  % find the proper rhs for the weight w of h
  rlcp:=rhslist;
  while caar rlcp neq w do rlcp:=cdr rlcp;
  rhs:=if fermionic then cadar  rlcp
                    else caddar rlcp;
  % add a constant factor to each term in rhs
  print_bak:=print_; print_:=nil; % to avoid printing the new constants
  rhs:=for each r in rhs collect <<nf   :=newfct(fname_,nil,nfct_)$ 
                                   fl   :=cons(nf,fl);
                                   nfct_:=add1 nfct_$
                                   {'TIMES,nf,r}>>$
  print_:=print_bak;
  rhs:=if null rhs then 0 
                   else if cdr rhs then cons('PLUS,rhs)
                                   else car rhs;   
  eqn_list:=cons({'EQUAL,{'DF,h,svar},rhs},eqn_list)
 >>$ 

 return {eqn_list,fl}
end$

%-------

symbolic procedure sspol(N,sysfbl,afwlist,abwlist,difforder,tname,
                         linsub,forbid,flip_par,verbose)$
% returns {eqn_list,fl} where 
% eqn_list is the algebraic list of equations/symmetries and 
% fl is the algebraic list of undetermined constants
% tname is the lhs differentiation variable
begin scalar g,h,i,fwlist,bwlist,allf,allb,w_list,rhs_list,eqn_list,fl,awlist$
 
 fwlist:=cdr reval afwlist$
 bwlist:=cdr reval abwlist$

 % Add to each field its weight as a prefix to create allf and allb
 for i:=1:(length flist) do allf:=cons({nth(fwlist,i),nth(flist,i)},allf);
 for i:=1:(length blist) do allb:=cons({nth(bwlist,i),nth(blist,i)},allb);

 % Generation of the final form of the equations

 % only those weights for which there is an eqn to generate
 % making a list of all different weights 
 w_list:=union(fwlist,union(bwlist,nil))$

 % generating the right-hand-side term-list for the different weights
 % Because expressions are generated according to their weight and are
 % partitioned only afterwards into fermionic and bosonic, we would not save
 % computation when generating only fermionic expressions of specific weight
 % and afterwards the bosonic expressions with specific weight
 rhs_list:=for each w in w_list collect 
           cons(w,rhs_term_list(N,allf,allb,w+difforder,linsub,forbid,verbose))$   
                                   % new weight(t) based on weight(x)=2

 % generating all bosonic equations
 for each h in sysfbl do 
 if car h = 'b then << g:=allb; while g and cadar g neq h do g:=cdr g$
  awlist:=cons(car g,awlist)
 >>$  
 nfct_:=1$   
 % whether difforder is odd or even has no influence on parity (ferm/bos)
 h:=gen_eqn(awlist,rhs_list,eqn_list,fl,flip_par,tname);

 % generating all fermionic equations
 awlist:=nil$
 for each h in sysfbl do 
 if car h = 'f then << g:=allf; while g and cadar g neq h do g:=cdr g$
  awlist:=cons(car g,awlist)
 >>$  
 % whether difforder is odd or even has no influence on parity (ferm/bos)
 h:=gen_eqn(awlist,rhs_list,car h,cadr h,not flip_par,tname);

 return {cons('LIST,car h),cadr h}
end$

%-------

symbolic procedure print_list_of_lists(li)$
begin scalar k$
 for each k in li do <<
  write"{"$
  while k do <<write car k$k:=cdr k$if k then write",">>$
  write"}"$terpri()$
 >>$ 
end$

%-------

symbolic operator listine$
symbolic procedure listine(N,sys,sym,fl,ineql,non_lin_test,save_lists)$
% generation of conditions for the unknown coefficients
begin scalar eqn,ineql,cnd,h,k,fb,flcp,nfl,evolist,rs$
 fl:=cdr fl$ 
 ineql:=for each h in cdr ineql collect cdr h$

 evolist:=for each h in append(cdr sys,cdr sym) collect caddr h$
 k:=gensym()$

 % The online data base was computed with:
 % % none of the equations and symmetries should vanish identically
 % for each eqn in evolist do <<
 %  if null (h:=smemberl(fl,eqn)) then h:={0};
 %  ineql:=cons(h,ineql)
 % >>$
 % %write"ineql1=",ineql$terpri()$

 % none of the equations should vanish identically
 for each eqn in cdr sys do <<
  if null (h:=smemberl(fl,caddr eqn)) then h:={0};
  ineql:=cons(h,ineql)
 >>$

 % at least one of the symmetries must not vanish identically
 h:=for each h in cdr sym collect caddr h$
 if null (h:=smemberl(fl,h)) then h:={0};
 ineql:=cons(h,ineql)$

 % None of the evolution equations should involve only one field,
 % the system should not be triangular.
 if cdr fblist then  % if more than one field
 for each eqn in cdr sys do <<
  rs:=caddr eqn; % rhs of eqn
  fb:=delete(cadr cadr eqn,fblist); % one of the functions fb must occur in rs
  if pairp rs and (car rs = '!*SQ) 
  then rs:={'!*SQ, subsq(cadr rs, for each h in fb collect (h . 0)), t}
  else for each h in fb do rs:=subst(0,h,rs);
  h:=setdiff(smemberl(fl,caddr eqn),smemberl(fl,reval rs));
  if null h then ineql:=cons({0},ineql)
            else ineql:=cons(h,ineql)
 >>$

 % At least one evolutionary equation should be non-linear.
 if non_lin_test then <<
  nfl:=nil;   % we drop all constants from fl which are coefficient to
              % a linear term
  for each eqn in evolist do <<
   flcp:=smemberl(fl,eqn);
   for each h in fblist do eqn:=subst({'TIMES,k,h},h,eqn);
   h:=smemberl(flcp,coeffn(reval eqn,k,1));
   flcp:=setdiff(flcp,h); 
   nfl:=append(nfl,flcp)
  >>$
  if null nfl then nfl:={0};    % contradiction issued
  ineql:=cons(nfl,ineql);
 >>$

 % at least one equation should contain a fermion field or a D_i derivative 
 if null flist then << % otherwise no chance to get a purely classical equation
  flcp:=fl;   % we drop all constants from fl which are coefficient to
              % a term without D(i,..) and without fermion
  algebraic <<
   drop_fd_rules:={d(~i,~j) => 0, f(~i) => 0};
   let drop_fd_rules;
  >>$
  for each eqn in evolist do <<
   h:=smemberl(fl,reval eqn);
   flcp:=setdiff(flcp,h)
  >>$
  algebraic ( clearrules drop_fd_rules )$
  if null flcp then flcp:={0};    % contradiction issued
  ineql:=cons(flcp,ineql);
  %write"ineql5=",ineql$terpri()$
 >>$

 %  N>1 makes only sense if all D_1,..,D_N occur which is required next
 if N>1 then for h:=1:N do <<
  flcp:=fl;   % we drop all constants from fl which are coefficient to
              % a term without D(h,..) 
  algebraic <<k:=lisp h;drop_fd_rules:={d(k,~j) => 0}; let drop_fd_rules>>;
  for each eqn in evolist do <<
   k:=smemberl(fl,reval eqn);
   flcp:=setdiff(flcp,k)
  >>$
  algebraic ( clearrules drop_fd_rules )$
  if null flcp then flcp:={0};    % contradiction issued
  ineql:=cons(flcp,ineql);
 >>$

 % dropping redundand conditions
 repeat <<
  rs:=ineql;
  while rs do <<
    k:=delete(car rs,ineql);
    while k and not_included(car rs,car k) do k:=cdr k;
    if k then << % i.e. cnd is fully included in car k
     ineql:=delete(car k,ineql);
     rs:=ineql
    >>   else rs:=cdr rs
  >>
 >> until null rs$

 if ineql then <<
  terpri()$
  write"From each of the following lists at least one element must be non-zero:"$
  terpri()$terpri()$
  print_list_of_lists(ineql)$
  terpri()$
 >>$
 if save_lists then <<
  out  "inelist"$
  print_list_of_lists(ineql)$
  shut "inelist"$
 >>$

 ineql:=for each cnd in ineql collect 
 if null cdr cnd then car cnd
                else cons('PLUS,for each h in cnd collect {'TIMES,h,gensym()})$

 return cons('LIST,ineql)

end$

%-------

algebraic procedure power_parti(eqns)$
begin scalar w,afblist,equa,ff,ex,a,p,parti,maxpow,h$
 afblist:=lisp(cons('LIST,fblist))$
 w:=lisp lin_test_const$
 maxpow:=0$
 h:=for each equa in eqns collect <<
  ff:=part(equa,1);ex:=part(equa,2);  
  for each a in afblist do ex:=sub(a=a*w,ex)$
  parti:=rest coeff(ex,w);
  if hipow!*>maxpow then maxpow:=hipow!*;
  ff=parti
 >>; 

 % Filling up each element of h with zero's so that all have same length
 if length h > 1 then
 h:=for each equa in h collect part(equa,1)=<<
  le:=length part(equa,2);
  if le=maxpow then part(equa,2)
               else <<ex:={};for g:=1:(maxpow-le) do ex:=cons(0,ex)$
                      append(part(equa,2),ex)>>
 >>$
 return {maxpow,h}
end$

%-------

symbolic procedure add_df_rules_to_D_rule(subl)$
% subl is an algebraic list of rules
% adds to each substitution rule D(i,A)=>.. all differential consequences
if null cdr subl then subl else
begin scalar g,h$
 g:=cdr subl;
 for each h in g do
 if pairp h and car h='REPLACEBY and pairp cadr h and caadr h='D and
    pairp caddr cadr h and ((caaddr cadr h='f) or (caaddr cadr h='b)) then <<
  % In algebraic mode rules are not properly printed, i.e. without brackets
  % around sums to be differentiated, so they may look wrong when being right
  subl:=cons('LIST,union(
      {{'REPLACEBY,{'DF,caddr cadr h,'x},reval {'D,cadr cadr h,caddr h}},
       {'REPLACEBY,{'DF,caddr cadr h,'x,{'~,'n}},
                   {'D,cadr cadr h,{'DF,caddr h,'x,{'DIFFERENCE,'n,1}}}},
       {'REPLACEBY,{'D,cadr cadr h,{'DF,caddr cadr h,{'~,'x}}},
                   reval {'DF,caddr h,'x}},
       {'REPLACEBY,{'D,cadr cadr h,{'DF,caddr cadr h,{'~,'x},{'~,'n}}},
                   {'DF,caddr h,'x,'n}},
       {'REPLACEBY,{'D,cadr cadr h,{'DF,caddr cadr h,{'~,'t},{'~,'x},{'~,'n}}},
                   {'DF,caddr h,'t,'x,'n}}},
      cdr subl))
 >>$
 return subl
end$

%-------

algebraic procedure sieve(inpu,wgl)$
% inpu={sym,cl}
% sym is an algebraic list of equations df(f(i),s)=.., df(b(j),s=..,
% cl is an algebraic list of coefficients in sym
% wgl is a list  {sw,afwlist,abwlist}
% It returns a list (new symmetry, list of coefficients}
begin scalar sym,cl,sw,fli,bli,su,n,h,newsy,to_drop,sy$
 cl:=second inpu;
 sw:=first wgl;
 fli:=second wgl;
 bli:=third wgl;

 % creating a substitution rule
 su:={};
 n:=0$for each h in fli do <<n:=n+1;su:=cons(f(n)=f(n)*lin_test_const**h,su)>>$
 n:=0$for each h in bli do <<n:=n+1;su:=cons(b(n)=b(n)*lin_test_const**h,su)>>$
 sym:=sub(su,first inpu);
 let lrule1; sym:=sym; clearrules lrule1;
 let lrule2; sym:=sym; clearrules lrule2;

 newsy:={};
 to_drop:={}$
 for each sy in sym do <<
  coeff(lhs sy,lin_test_const);
  n:=hipow!*+sw;
  if n<0 then <<h:=lin_test_const**(-n)*rhs sy; 
                newsy:=cons(coeffn(h,lin_test_const,n),newsy)>>
         else newsy:=cons(coeffn(rhs sy,lin_test_const,n),newsy);
 >>;
 su:={};
 for each h in cl do if freeof(newsy,h) then <<
  su:=cons(h=0,su);
  to_drop:=cons(h,to_drop)
 >>$

 return {sub(su,first inpu),lisp cons('LIST,setdiff(cdr cl,cdr to_drop))}
end$

%-------

symbolic procedure non_t_lhs_dvs(pdes)$
% listing lhs's of equations and substitutions which are no t-derivatives
begin scalar h,forbid$
 for each h in pdes do
 if pairp h and
    ((car h = 'EQUAL) or (car h = 'REPLACE)) and 
    (pairp cadr h) and
    ((caadr h = 'DF) or (caadr h = 'D) or (caadr h = 'F) or (caadr h = 'B)) and
    freeof(cadr h,t) then <<
  forbid:=cons(cadr h,forbid);
  if caadr h = 'D  then forbid:=cons({'DF,caddr cadr h,'x},forbid) else
  if caadr h = 'df then for g:=1:N_ do forbid:=cons({'D,g,cadr h},forbid)
 >>$
 return forbid
end$

%-------

algebraic procedure ssym(N,tw,sw,afwlist,abwlist,eqnlist,fl,inelist,mode)$
% uses the global algebraic variable x

% N       .. the number of superfields theta_i
% tw      .. 2 times the differential order of the equation = weight(t)
% sw      .. 2 times the differential order of the symmetry = weight(s)
% afwlist .. (algebraic) list of weights of the fermion fields
%            f(1), f(2), ... 
% abwlist .. (algebraic) list of weights of the boson fields
%            b(1), b(2), ...
% The number of elements in the last two lists determines the
% number of fermion and boson fields.
% eqnlist .. in the nonlinear case a list of extra conditions on the 
%            undetermined coefficients where conditions a3=.. are executed 
%            instantly, these and any, expressions are added to equations 
%            when calling crack
%            in the linear case the system in form of replacements and the 
%            linearized system in form of equations
% fl      .. extra unknowns in eqnlist to be determined
% inelist .. a list, each element of it is a list with at least one of
%            its elements being non-zero
% mode    .. list of flags: 
%            init : only initialization of global data
%            plain_com : direct computation of the commutator (for tests)
%            power_split_com : alternative power splitting of commutator, 
%                              (not if substitutions '='> are present)
%            % const_coeff_in_eqn : have only constant coefficients in eqn.
%            % const_coeff_in_sym : have only constant coefficients in sym.
%            zerocoeff : all coefficients = 0 which are not listed in ine
%            % verbose : extra output for tracing and debugging
%            interactive : whether the solution process is interactive
%            % no_t_in_eqn : no explicit t-derivatives occur in equations
%            % no_t_in_sym : no explicit t-derivatives occur in symmetries
%            filter: extra homogeneity weights as given in the list"$
%                    hom_wei have to be satisfied by the symmetry"$
%            lin: find symmetry for all linear fields, 
%                 if null spar (bosonic s) then 
%                    bosonic   lin fields are b(nb+1)..b(2*nb)
%                    fermionic lin fields are f(nf+1)..b(2*nf)
%                                          else
%                    bosonic   lin fields are b(nb+1)..b(nf+nb)
%                    fermionic lin fields are f(nf+1)..b(nf+nb)
%            tpar: t/nil, whether time variable t changes parity"$        
%            spar: t/nil, whether symmetry variable s changes parity"$
%            log : t/nil, whether files drvlist, evolist, unolist, inelist
%                         are generated to hold data, for example, for 
%                         automatic web page generation
%
begin scalar g,h,k,cpu,gti,fbno,psys,psym,msysp,msymp,totpow,syspow,sympow,
             newcd,afblist,sublist,zerocoeff,fl_e,non_lin_test,do_ine_test,
             init,subl,subl2,sys,sym,ls,rs,linsub,filter,forbid,rhssyl,sycon,
             nw,w,np,p,nq,q,psycon,cn,lp,verbose,plain_com,power_split_com,
             msgbak,interactive,nfr,nfe,nbr,nbe,nf,nb,lhslist,save_lists$
 backup_reduce_flags()$
 lisp <<
  record_hist:=nil;
  if !*time then <<cpu:=time()$ gti:=gctime()>>$

  eqnlist:=cdr eqnlist;
  fl     :=cdr fl;       if fl then homogen_:=nil else homogen_:=t;
  mode   :=cdr mode;

  if member('init,mode) then init:=t else init:=nil;
  % if member('const_coeff_in_eqn,mode) then cc_eqn:=t else cc_eqn:=nil;
  % if member('const_coeff_in_sym,mode) then cc_sym:=t else cc_sym:=nil;
  if member('zerocoeff,mode) then zerocoeff:=t else zerocoeff:=nil;
  if member('plain_com,mode) then plain_com:=t else plain_com:=nil;
  if member('power_split_com,mode) then power_split_com:=t 
                                   else power_split_com:=nil;
  % if member('term_split_com,mode) then term_split_com:=t 
  %                                 else term_split_com:=nil;
  if member('verbose,mode) then verbose:=t else verbose:=nil;
  if member('interactive,mode) then interactive:=t else interactive:=nil;
  % if member('no_t_in_eqn,mode) then no_t_in_eqn:=t else no_t_in_eqn:=nil;
  % if member('no_t_in_sym,mode) then no_t_in_sym:=t else no_t_in_sym:=nil;
  if member('filter,mode) then filter:=t else filter:=nil;
  if member('tpar,mode) then algebraic(on  t_changes_parity)
                        else algebraic(off t_changes_parity);
  if member('spar,mode) then algebraic(on  s_changes_parity)
                        else algebraic(off s_changes_parity);
  if member('log,mode) then save_lists:=t$

  if member('lin,mode) then << % @#@#
   nf:=length afwlist - 1;
   nb:=length abwlist - 1;
   if member('spar,mode) then 
   if nf neq nb then <<write"In the case of spar #(boson fields)=#(fermion fields)",
                             " which is not the case."; forbid:=t>> 
                else % to do more tests one would have to know/find the numbers
                     % of b/f fields before linearization
                         else << % null member('spar,mode) 
    if null evenp nf then <<write"If no spar then #(fermion fields) needs to be even"$
                      forbid:=t>>;
    if null evenp nb then <<write"If no spar then #(boson fields) needs to be even"$
                      forbid:=t>>;
    for each g in eqnlist do if pairp g then lhslist:=cons(cadr g,lhslist);
    nf:=nf/2; nb:=nb/2;
    for each g in lhslist do 

if car g = 'df then
if caadr g = 'f then if ((cadadr g <= nf) and not member({'df,{'f,cadadr g + nf},caddr g},lhslist)) or
                        ((cadadr g  > nf) and not member({'df,{'f,cadadr g - nf},caddr g},lhslist)) then <<
                       write"The counterpart of ",g," is missing on a left hand side."$ forbid:=t>> else
                else
if caadr g = 'b then if ((cadadr g <= nb) and not member({'df,{'b,cadadr g + nb},caddr g},lhslist)) or
                        ((cadadr g  > nb) and not member({'df,{'b,cadadr g - nb},caddr g},lhslist)) then <<
                       write"The counterpart of ",g," is missing on a left hand side."$ forbid:=t>> else
                else
               else
if car g = 'd  then
if caaddr g = 'f then if ((car cdaddr g <= nf) and not member({'d,cadr g,{'f,car cdaddr g + nf}},lhslist)) or
                         ((car cdaddr g  > nf) and not member({'d,cadr g,{'f,car cdaddr g - nf}},lhslist)) then <<
                        write"The counterpart of ",g," is missing on a left hand side."$ forbid:=t>> else
                 else
if caaddr g = 'b then if ((car cdaddr g <= nb) and not member({'d,cadr g,{'b,car cdaddr g + nb}},lhslist)) or
                         ((car cdaddr g  > nb) and not member({'d,cadr g,{'b,car cdaddr g - nb}},lhslist)) then <<
                        write"The counterpart of ",g," is missing on a left hand side."$ forbid:=t>> else
                 else
               else
   >>; % of null member('spar,mode)    
   if forbid then <<forbid:=nil;rederr "">>$
  >>$

  % In the linearized system not half of the equations need to 
  % be = and half => because there may be nonlocal potential variables 
  % introduced through a => relation
  if nil then
  if member('lin,mode) then << % @#@#
   % determine nf and nb
   nfr:=0;  nbr:=0;  % number of f(i) and b(i) in replaceby
   nfe:=0;  nbe:=0;  % number of f(i) and b(i) in equal

   for each g in eqnlist do 
   if pairp g then
   if (car g='equal) then
   if not freeof(cadr g,'f) then nfe:=nfe+1 else
   if not freeof(cadr g,'b) then nbe:=nbe+1 else
                     else
   if (car g='replaceby) then
   if not freeof(cadr g,'f) then nfr:=nfr+1 else
   if not freeof(cadr g,'b) then nbr:=nbr+1 else
                         else $

%check nfr+nfe = length afwlist - 1
%check nbr+nbe = length abwlist - 1

write"nfr= ",nfr," nfe=",nfe,
     "nbr= ",nbr," nbe=",nbe$

   if (    member('spar,mode) and (nfr=nbe) and (nbr=nfe)) or
      (not member('spar,mode) and (nfr=nfe) and (nbr=nbe)) then 
                                                           else <<
    if member('spar,mode) then <<
     if nfr neq nbe then <<write "For spar 
      the number of '=>' relations with a fermion on the lhs should be equal 
      the number of '='  relations with a boson   on the lhs."$ terpri()
     >>$
     if nbr neq nfe then <<write "For spar 
      the number of '=>' relations with a boson   on the lhs should be equal 
      the number of '='  relations with a fermion on the lhs."$ terpri()
     >>
    >>                    else 

    if not member('spar,mode) then <<
     if nfr neq nfe then <<write "For missing spar 
      the number of '=>' relations with a fermion on the lhs should be equal 
      the number of '='  relations with a fermion on the lhs."$ terpri()
     >>$
     if nbr neq nbe then <<write "For missing spar 
      the number of '=>' relations with a boson   on the lhs should be equal 
      the number of '='  relations with a boson   on the lhs."$ terpri()
     >>
    >>$
    rederr ""
   >>
  >>;

  % Initialization of fermionic and bosonic fields + their printing
  input_consistency_test(afwlist,abwlist)$
  N_:=N;  % to avoid printing the index of D in crack_out for N=1
  flist := for g:=1:(length afwlist-1) collect {'f,g};
  if flist and length flist=1 then put('f,'prifn,'myfpri)
                              else put('f,'prifn,nil);
  blist := for g:=1:(length abwlist-1) collect {'b,g};
  if blist and length blist=1 then put('b,'prifn,'myfpri)
                              else put('b,'prifn,nil);
  fblist:=append(flist,blist)
 >>$

 afblist:=lisp(cons('LIST,fblist))$
 for each g in afblist do depend g,x,t$

 lisp <<

  % listing lhs's of equations and substitutions which are no t-derivatives
  forbid:=non_t_lhs_dvs(eqnlist)$

  terpri()$
  write"#######  This is the case N",N,"f",length flist,"b",
       length blist,"t",tw,"s",sw,"w"$
  for each g in append(cdr afwlist,cdr abwlist) do write g;
  write".  #######"$terpri()$
  % specifying the names of constants in the equations
  if fname_list then <<fname_:=car fname_list;
                       fname_list:=cdr fname_list>>
                else   fname_:='p$ 

  % generating the equations
  % Has an ansatz for the system been made?  
  if eqnlist                                    and 
     (pairp car eqnlist                       ) and 
     (((caar eqnlist='EQUAL       ) and 
       (pairp cadar eqnlist       ) and
       (caadar eqnlist = 'DF      )      ) or 
      ((caar eqnlist='REPLACEBY   ) and
       (pairp cadar eqnlist       ) and
       ((caadar eqnlist = 'DF) or 
        (caadar eqnlist = 'D )    )      )    ) then << 
   g:=nil;
   for each h in eqnlist do if pairp h then
   if pairp h and 
      car h='EQUAL and 
      pairp cadr h and 
      caadr h='DF and
      reval caddr cadr h ='t then <<
    sys:=cons(h,sys);
    subl2:=cons({'REPLACEBY,cadr h,caddr h},subl2) % substitutions based on sys
   >>                        else
   if car h='REPLACEBY and 
      pairp cadr h and 
      ((caadr h='DF) or
       (caadr h='D)     ) then subl:=cons(h,subl)
                          else g:=cons(h,g)$                
   eqnlist:=g$

   sysfbl:=reverse for each h in sys collect cadadr h;

   % simplifying the rhs of substitutions
   if verbose then <<write"Simplifying the substitutions."$terpri()>>$
   subl2:=cons('LIST,append(subl,subl2));
   algebraic(let subl2);
   subl:=for each h in subl collect {'REPLACEBY,cadr h,algebraic(lisp(caddr h))}}$
   subl:=cons('LIST,reverse subl);
   algebraic(clearrules subl2);
   subl2:=nil;

   sys:=cons('LIST,reverse sys);
   fl_e:=fl$
   fl:=nil
  >>                                     else <<
   do_ine_test:=t$
   if null eqnlist then non_lin_test:=t$
   sysfbl:=append(flist,blist);
   subl2:=cons('LIST,append(subl,subl2));
   if verbose then <<write"Formulating rhs's of the system"$terpri()>>$
   h:=sspol(N,sysfbl,afwlist,abwlist,tw,algebraic t,linsub,
            forbid,!*t_changes_parity,verbose)$
   sys:=car h; 
   fl_e:=cadr h;
   subl:={'LIST}
  >>$
  
  algebraic<<nodepend f,s; nodepend b,s>>$
  for each h in fblist do algebraic(nodepend h,s); 
  for each h in sysfbl do algebraic(  depend h,s);

  % add to each substitution rule D(i,A)=>.. all differential consequences
  subl:=add_df_rules_to_D_rule subl$

  % specifying the names of constants in the symmetries
  if fname_list then <<fname_:=car fname_list;
                       fname_list:=cdr fname_list>>
                else   fname_:='q$ 
  % generating the symmetry
  if verbose then <<write"Formulating rhs's of the symmetry"$terpri()>>$
  h:=sspol(N,sysfbl,afwlist,abwlist,sw,algebraic s,linsub,
           forbid,!*s_changes_parity,verbose)$

  % applying a homogeneity filter
  if filter and pairp algebraic hom_wei
            and car (algebraic hom_wei) = 'LIST then <<
   if verbose then <<write"Applying an extra homogeneity filter"$terpri()>>$
   h:={'LIST,car h,cons('LIST,cadr h)};
   algebraic(for each g in hom_wei do h:=sieve(h,g))$
   h:={cadr h,cdaddr h} % converting to lisp list of two lisp lists
  >>$
  sym:=car h$ 
  flin_:=cadr h$  h:=nil;

  % Extracting substitutions from eqnlist to be done instantly
  g:=eqnlist; eqnlist:=nil;
  for each h in g do 
  if pairp h and car h = 'EQUAL then <<
   sublist:=cons(h,sublist)$ 
   eqnlist:=cons({'DIFFERENCE,cadr h,caddr h},eqnlist)
  >>                            else eqnlist:=cons(h,eqnlist)$

  if zerocoeff then 
  for each h in append(fl_e,flin_) do 
  if freeof(inelist,h) then sublist:=cons({'EQUAL,h,0},sublist) 
                       else fl:=cons(h,fl)
               else fl:=append(fl_e,flin_);
  fl_e:=nil$
  fl:=cons('LIST,fl)$
  sublist:=cons('LIST,sublist)$
  eqnlist:=cons('LIST,eqnlist)$
 >>$

 if sublist then <<
  sys:=sub(sublist,sys)$
  sym:=sub(sublist,sym)
 >>$
 if lisp(save_lists) then <<
  off nat$
  out  "drvlist"$
  for each g in sys do write lhs g," := ",rhs g$ 
  for each g in sym do write lhs g," := ",rhs g$ 
  write"end$"$
  shut "drvlist"$
 >>$
 on nat$
 on dfprint$
 off noarg$
 if lisp(save_lists) then <<
  out  "evolist"$
  for each g in sys do write lhs g," := ",rhs g$ 
  lisp <<terpri()$
         write"</pre> with symmetries"$ terpri()$
         write"<pre>">>$
  for each g in sym do write lhs g," := ",rhs g$ 
  shut "evolist"$
  out  "unolist"$
  lisp <<listprint(reverse cdr fl)$terpri()>>$
  shut "unolist"$
 >>$

 if interactive then <<off batch_mode$ lisp(print_:= 6 )>>
                else <<on  batch_mode$ lisp(print_:=nil)>>$
 lisp <<
  use_new_crackout:=t;
  %confirm_subst:=t;
  collect_sol:=nil;  % no collection of solutions, i.e. use of crackout()
  subst_1:=11;
  pdelimit_1:=400;
  max_gc_short:=4;
  max_gc_red_len:=4;

  % instead of assigning proc_list here in the form
  %  proc_list_:='(
  %   to_do
  %   separation
  %   subst_level_0
  %   subst_level_04 
  %   alg_length_reduction 
  %   find_and_use_sub_systems22
  %   diff_length_reduction 
  %   factorize_to_substitute
  %   subst_level_35 
  %   decoupling 
  %   factorize_any 
  %   subst_level_4 
  %   alg_solve_single           
  %   stop_batch
  %  ) 
  % it is done in the assignment of old_history before the call of
  % CRACK, in order to drop the separation step after its initial
  % execution

 >>$
 
 if length sys=1 then write"The equation:" else write"The system:"$
 for each g in sys do write g$
 if subl neq {} then <<
  if length subl=1 then write"Extra condition:" else write"Extra conditions:"$
  off nat;
  for each g in subl do write g;
  on nat
 >>$
 if verbose then <<
  write"The symmetry:"$
  for each g in sym do write g$
 >>$

 if do_ine_test then <<
  inelist:=listine(N,sys,sym,fl,inelist,non_lin_test,save_lists);
  g:=inelist$ 
  while g neq {} and first g neq 0 do g:=rest g$ 
  if g neq {} then return <<
   out "invalid"$  
   write"SYSTEM & SYMMETRY DO NOT SATISFY MINIMAL REQUIREMENTS!"$
   shut "invalid"$ 
   write"SYSTEM & SYMMETRY DO NOT SATISFY MINIMAL REQUIREMENTS!"$
  >>
 >>$

 % Formulating all conditions in stages

 if subl neq {} then let subl$% this activates the extra conditions
 fbno:=lisp length sysfbl$
 if subl neq {} then power_split_com:=nil$ % because automatic substitutions from 
                      % subs most likely change powers by introducing new factors
 if power_split_com then <<
  lisp (lin_test_const:=gensym())$
  psys:=power_parti(sys)$ msysp:=first psys; psys:=second psys;
  psym:=power_parti(sym)$ msymp:=first psym; psym:=second psym;
  for totpow:=2:(msysp+msymp) do << % generating all terms with total 
                                    % power totpow of all elements of fblist
   lisp<<write"Generating all terms of total degree ",totpow$terpri()>>$
   % initialize all partial commutators to zero
   newcd:={}$ for g:=1:fbno do newcd:=cons(0,newcd)$
   % generate all pairings giving totpow
   for syspow:=1:msysp do 
   for sympow:=1:msymp do
   if (syspow+sympow)=totpow then <<
    lisp <<
     write"  Pairing now degree ",syspow," terms from the system"$terpri()$
     write"         with degree ",sympow," terms from the symmetry"$terpri()>>$

    subl2:=append(
     for each g in psys collect <<ls:=lhs g;rs:=part(rhs g,syspow);ls => rs>>,
     for each g in psym collect <<ls:=lhs g;rs:=part(rhs g,sympow);ls => rs>>)$
    let subl2;

    % generation of partial commutators and adding them to newcd
    for g:=1:fbno do % for the g'th evol. equation + related symmetry equation
    newcd:=(part(newcd,g):=part(newcd,g)    + df(part(rhs part(psys,g),syspow),s) +
            (if (lisp t_changes_parity) and
                (lisp s_changes_parity) then   df(part(rhs part(psym,g),sympow),t)
                                        else (-df(part(rhs part(psym,g),sympow),t))));
    % clearing the t- and s-derivatives of all field variables
    clearrules subl2

   >>$
   eqnlist:=append(newcd,eqnlist)
  >>$
  psys:=psym:=0
 >>$

 % Assign t- and s-derivatives for all members of fblist for use in crack_out.
 subl2:=append(for each g in sys collect <<ls:=lhs g;rs:=rhs g; ls => rs>>,
               for each g in sym collect <<ls:=lhs g;rs:=rhs g; ls => rs>> )$
 let subl2; % This is the ansatz for the system and symmetry to be used 
            % for the commutator.
 if verbose then <<
  write"sys = ",sys$
  write"sym = ",sym$
  write"df(rhs part(sys,1),s) = ",df(rhs part(sys,1),s)$
  write"df(rhs part(sym,1),t) = ",df(rhs part(sym,1),t)$
 >>$

 if not power_split_com and plain_com then
 for g:=1:fbno do 
 eqnlist:=cons(df(rhs part(sys,g),s) + 
               (if (lisp t_changes_parity) and
                   (lisp s_changes_parity) then   df(rhs part(sym,g),t)
                                           else (-df(rhs part(sym,g),t))),
               eqnlist)
                                      else 
 if not power_split_com then lisp <<

  sym:=reval sym;
  eqnlist:=cdr eqnlist;   % to get rid of 'LIST

  % for each symmetry h collect the list of terms of the rhs caddr h
  rhssyl:= for each h in cdr sym collect   
           if pairp caddr h and caaddr h='PLUS then cdaddr h 
                                               else {caddr h};
  nw:=0$
  for each w in sysfbl do << 
   if verbose then write"Integrability conditions are computed for ",w," :"$ terpri()$
   % For each function w of sysfbl generate the full condition
   nw:=add1 nw$ % the index of the function w in sysfbl
   sycon:=0$    % the condition for this function
   np:=0$       % the index of the symmetry of which one term is kept non-zero

   % Initialize the s-derivative of all functions to zero
   msgbak:=!*msg; !*msg:=nil;
   for each h in sysfbl do algebraic <<clear df(lisp h,s);df(lisp h,s):=0>>$
   !*msg:=msgbak;
   cn:=0$                                 % counter of computed partial commutators
   lp:=for each p in rhssyl sum length p$ % counter of all partial commutators 

   psycon:=nil$   % a partial condition for this function
   for each p in rhssyl do << % for each rhs of a symmetry

    % at first set previous s-deriv again to zero.
    msgbak:=!*msg; !*msg:=nil;
    if np>0 then <<h:=nth(sysfbl,np)$
                   algebraic <<clear df(h,s);df(h,s):=0>> >>$
    !*msg:=msgbak;

    % Now we take the next rhs of which one term is not vanishing
    np:=add1 np;
    h:=nth(sysfbl,np)$
    nq:=0;      % the index of the term in p which is kept non-zero
    for each q in p do <<    % compute partial condition and add to psycon
     nq:=add1 nq$
     cn:=add1 cn$
     if verbose then algebraic write "   ",cn,"(",lp,")/",nw,"(",fbno,
                                     "). Currently non-vanishing: ",q$
     msgbak:=!*msg; !*msg:=nil;
     algebraic <<clear df(lisp h,s);
                 df(lisp h,s):=lisp nth(p,nq)>>$
     !*msg:=msgbak;
     psycon:=cons(algebraic <<
                   k:=df(w,t);g:=df(w,s);
                   df(k,s) + (if (lisp t_changes_parity) and
                                 (lisp s_changes_parity) then    df(g,t)
                                                         else (- df(g,t)))
                  >>,psycon)
    >>
   >>;
   algebraic <<
    sycon:=num lisp cons('PLUS,psycon);
    h:=length sycon;
    if verbose then
    if h=1 then write"The symmetry condition for ",w," has ",h," term." 
           else write"The symmetry condition for ",w," has ",h," terms." 
   >>$
   eqnlist:=cons(sycon,eqnlist)
  >>$
  eqnlist:=cons('LIST,eqnlist)$

  % cleaning up assignments for s-derivatives
  msgbak:=!*msg; !*msg:=nil;
  for each h in sysfbl do algebraic clear df(lisp h,s);
  !*msg:=msgbak;

 >>;

 lisp<<msgbak:=!*msg; !*msg:=nil>>;
 clearrules subl2$
 clearrules subl$
 lisp (!*msg:=msgbak)$

 subli:=subl$
 symansatz:=subl2$

 sys:=sym:=0$

 if not init then <<
  lisp(if !*time then <<terpri()$
   write "CPU time so far: ",   time() - cpu," ms  ",
         " GC time so far: ", gctime() - gti," ms"$
   terpri()
  >>);

  lisp <<

   % Listing the splitting `variables' 
   h:='(t s x)$
   eqnlist:=split_simplify({eqnlist,{'LIST},fl,cons('LIST,h),t})$ 
   if print_ then <<write"Now crack is called."$terpri()>>$
   old_history:='(

    cp (!*comma!* 1 3 45 11 8 20 27 30 47 21 38) 
           % to specify an automatic solving strategy with priorities:
           %
           %  1 : Hot list of urgent steps
           %  3 : Substitution of <=2 terms, only fcts. of less vars., no cases
           % 45 : Substitution of <=8 terms in <=1000 terms, 
           %      alg. expressions, no cases
           % 11 : Algebraic length reduction of equations
           % 53 : Find sub-systems with 2 flin_ functions % taken out, 
           %                                % may generate too many equations 
           % 27 : Length reducing decoupling steps
           %  8 : Factorization to subcases leading to substitutions
           % 20 : Substitution of <=1000 terms, no cases
           % 30 : Do one decoupling step
           % 47 : Any factorization
           % 21 : Substitution of <=1000 terms
           % 34 : Solving an algebraic equation. % taken out as too risky
           % 38 : Stop batch mode
    s      % to display a statistics for the original overdetermined system
    % w nil n "w"   % to store the system in ASCII for later web-page generation
    %               This has been disabled for the online demo.
    dp     % to disable parallellism
    % sb "0" % to backup the original system
    %               This has been disabled for the online demo.
   );
  >>;
  % on time$
  %  eqnlist:=lisp presimplify(eqnlist,fl)$   ############
  crack(eqnlist,inelist,fl,{})$ % ============= CRACK ==============
  lisp <<terpri()$
         write if null sol_list then "No" else length sol_list,
               if length sol_list=1 then " solution was" else " solutions were",
               " found."$ terpri();
       >>$
 >>
end$ % of ssym

%-------

algebraic procedure samelists(a,b)$
if a={} then if b={} then true
                     else nil
        else if b={} then nil
                     else 
if first a neq first b then nil
                       else samelists(rest a,rest b)$

%-------

algebraic procedure crack_out(eqns,assigns,freef,ineq,sol_count)$
% to be used by crack called in ssym()
% lines marked with %#### have to be commented when ssym is called from script
% uses global variablse fblist,t,s,html_out
% assumes that t- and s-derivatives for all members of fblist are assigned
if lisp use_new_crackout then
begin scalar g,h,tm,ratbak,allbak,eqlist,eqcp1,eqcp2,afblist,ff,symlist,frsym,
             all,msgbak,sol_count2; 
             %,natbak
 allbak:=lisp !*allfac$    on allfac$
 ratbak:=lisp !*rational$  on rational$
 afblist:=lisp(cons('LIST,sysfbl))$
 let symansatz$
% let ssrules;
 html_out:=nil$ % could be made a flag in ssym()

 % At first printing the particular solutions correspponding to each
 % individual free parameter

 eqlist:=for each h in afblist collect sub(assigns,df(h,t))$
 eqlist:=append(eqlist,for each h in afblist collect sub(assigns,df(h,s)));
 symlist:=for each h in afblist collect df(h,s);
 frsym:={}$
 for each ff in freef do if not freeof(symlist,ff) then frsym:=cons(ff,frsym);
 all:={}$
 sol_count2:=0;

 write "All symmetries of solution ",sol_count," printed separately:"$ 
 for each ff in frsym do 
 if not freeof(eqlist,ff) then <<   % which really appear             %####

  eqcp1:=eqlist;
  for each h in frsym do if h neq ff then eqcp1:=sub(h=0,eqcp1);

  % For the remaining constant ff we take a value that normalizes the numerical
  % coefficient of the first term of the first non-vanishing rhs of this 
  % symmetry to one.
  g:=eqcp1;
  while (g neq {}) and freeof(first g,ff) do g:=rest g;
  if g neq {} then <<
   if my_freeof(den first g,x) then h:=den first g else h:=1$
   tm:=first g$
   h:=h/(numcoeff tm)$
   eqcp1:=sub(ff=h,eqcp1)
  >>$

  % Has this solution already been found from other constants?
  g:=all$
  while (g neq {}) and not samelists(eqcp1,first g) do g:=rest g;
  if g={} then << % a new solution
   g:={};
   all:=cons(eqcp1,all);
   sol_count2:=sol_count2+1;
   eqcp2:=eqcp1$

   lisp <<                                                             %####
    terpri()$
    if html_out then write"</pre>"$
    write "Solution ",sol_count,", symmetry ",sol_count2,". :"$ terpri()$terpri()$
    if length afblist=2 then write"The equation: "
                        else write"The system: "$  terpri()$
    if html_out then <<write"<pre>"$terpri()>>
 
   >>$
   for each h in afblist do <<
    g:=df(h,t);
    msgbak:=!*msg; !*msg:=nil;
    clear df(h,t);
    !*msg:=msgbak;
    write df(h,t),"=",first eqcp1;  
    df(h,t):=g;
    eqcp1:=rest eqcp1
   >>$
 
   % if (lisp print_more) then 
   <<
    lisp <<
     if html_out then write"</pre>"$
     terpri()$
     write"The symmetry: "$ terpri()$
     if html_out then write"<pre>"$
    >>$
    for each h in afblist do <<
     g:=df(h,s);
     msgbak:=!*msg; !*msg:=nil;
     clear df(h,s);
     !*msg:=msgbak;
     write df(h,s),"=",first eqcp1;  
     df(h,s):=g;
     eqcp1:=rest eqcp1
    >>
   >>$
   lisp << 
    if html_out then write"</pre>"$ 
    terpri()$
    write"And now in machine readable form: "$ terpri()$
    if html_out then write"<p>"$
    if length afblist=2 then write"The equation: "
                        else write"The system: "$  terpri()$
    if html_out then write"<pre>"
   >>$
   off nat$
   for each h in afblist do <<
    write"df(",h,",t)=",first eqcp2;  
    eqcp2:=rest eqcp2
   >>$
   on nat$
   % if (lisp print_more) then 
   <<
    lisp <<
     if html_out then write"</pre>"$ 
     terpri()$ 
     write"The symmetry: "$terpri()$ 
     if html_out then write"<pre>"
    >>$
    off nat$
    for each h in afblist do <<
     write"df(",h,",s)=",first eqcp2;  
     eqcp2:=rest eqcp2
    >>$
    on nat$
   >>                                      
  >>   % of `g neq {}'
 >>$  % of `for each ff'

 % If there are 2 or more symmetries then printing again the solution 
 % with a linear combination of its symmetries:

 if length(sfrsym) > 1 then <<

  lisp <<                                                             %####
   terpri()$
   if html_out then write"</pre>"$
   terpri()$
   write "Again solution ",sol_count,", now with ALL its parameters (symmetries):"$ terpri()$
   if length afblist=2 then write"The equation: "
                       else write"The system: "$  terpri()$
   if html_out then <<write"<pre>"$terpri()>>
  >>$
  for each h in afblist do <<
   g:=df(h,t);
   msgbak:=!*msg; !*msg:=nil;
   clear df(h,t);
   !*msg:=msgbak;
   write df(h,t),"=",sub(assigns,g)$
   df(h,t):=g
  >>$

  % if (lisp print_more) then 
  <<
   lisp <<
    if html_out then write"</pre>"$
    terpri()$
    write"The symmetry: "$ terpri()$
    if html_out then write"<pre>"$
   >>$
   for each h in afblist do <<
    g:=df(h,s);
    msgbak:=!*msg; !*msg:=nil;
    clear df(h,s);
    !*msg:=msgbak;
    write df(h,s),"=",sub(assigns,g)$
    df(h,s):=g;
   >>
  >>$

  % And now in machine readable form:

  lisp << 
   if html_out then write"</pre>"$ 
   terpri()$
   write"And now in machine readable form: "$ terpri()$
   if html_out then write"<p>"$
   if length afblist=2 then write"The equation: "
                       else write"The system: "$  terpri()$
   if html_out then write"<pre>"
  >>$
  off nat$
  for each h in afblist do 
  write"df(",h,",t)=",sub(assigns,df(h,t));
  on nat$
 
  % if (lisp print_more) then 
  <<
   lisp <<
    if html_out then write"</pre>"$ 
    terpri()$ 
    write"The symmetry: "$terpri()$ 
    if html_out then write"<pre>"
   >>$
   off nat$
   for each h in afblist do 
   write"df(",h,",s)=",sub(assigns,df(h,s));
   on nat$
  >>$
 >>$  % if more than 1 symmetry

 lisp <<write"-----------------------------------"$ terpri()>>$  %####
 clearrules symansatz$
 % ssrules should stay on
 if allbak=nil then off allfac$
 if ratbak=nil then off rational$

end$ % of crack_out

%-------

symbolic procedure bigdpri l$
begin scalar dd,f;
 if not !*nat or !*fort then return 'failed;
 f:=cadr l; dd:=caddr l;
 prin2!* '!D;
 ycoord!* := ycoord!*-1;
 if ycoord!* < ymin!* then ymin!*:=ycoord!*;
 if N_ neq 1 then prin2!* f;
 ycoord!* := ycoord!*+1;
 if ycoord!* < ymin!* then ymin!*:=ycoord!*;
 if dd then
 << % prin2!* "(";    % to print brackets
    maprin dd;
    % prin2!* ")";
 >>;
 return l;
end$

%-------

put('!d,'prifn,'bigdpri)$

put('bigdpri,'expt,'inbrackets)$

% put('f,'prifn,'myfpri);  % done in ssym() if only one fermion field
% put('b,'prifn,'myfpri);  % done in ssym() if only one boson   field

symbolic procedure myfpri(x)$
%  if not !*nat or !*fort or null !*no_index then  'failed
if not !*nat or !*fort then 'failed
                       else << prin2!* car x;x>>$

%-------
%>>>>>>> The 2001 patch, now in the Reduce development version and in Reduce 3.8

%    symbolic procedure noncomp u$
%       !*ncmp and noncomp1 u$
 
%-------

%   symbolic procedure noncomp1 u$
%      if null pairp u then nil
%       else if pairp car u then noncomfp u
%       else flagp(car u,'noncom) or noncomlistp cdr u$
 
%-------

%    symbolic procedure noncomlistp u$
%       pairp u and (noncomp1 car u or noncomlistp cdr u)$
 
%-------

%    symbolic procedure mchcomb(u,v,op)$
%       begin integer n;
%	  n := length u - length v +1;
%	  if n<1 then return nil
%	   else if n=1 then return mchsarg(u,v,op)
%	   else if not smemqlp(frlis!*,v) then return nil;
%	  return for each x in comb(u,n) join
%	       if null ncmp!* then mchsarg((op . x) . setdiff(u,x),v,op)
%		else (if null y then nil
%		       else mchsarg((op . x) . car y,
%				    if cdr y then reverse v else v,op))
%		where y = mchcomb2(x,u,nil,nil,nil)
%       end$

%-------

%    symbolic procedure mchcomb2(u,v,w,bool1,bool2)$
%       if null u then nconc(reversip w,v) . bool2
%	else if car u = car v
%	       then if noncomp car u then mchcomb2(cdr u,cdr v,w,t,bool2)
%		     else mchcomb2(cdr u,cdr v,w,bool1,bool2)
%	else if noncomp car u
%	 then if bool1 then nil
%	       else mchcomb2(u,cdr v,car v . w,t,if bool2 then bool2 else t)
%	else mchcomb2(u,cdr v,car v . w,bool1,bool2)$

%-------

symbolic procedure search_li3(l,carli)$
% Find all sublists of l which start with an element of carli (no nesting)
begin scalar b,res$

 if pairp l then <<
  b:=carli;
  while b and null res do if car l = car b then res:=list l
                                           else b:=cdr b
 >>         else if l and member(l,carli) then res:=list l;
 if null res then 
 while pairp l do <<
  if b:=search_li3(car l,carli) then res:=union(b,res);
  l:=cdr l
 >>$
 return res
end$

%-------

%symbolic procedure itercoeff(sf,splitvar)$                 %#################
%if not pairp sf then {!*f2a sf} else                       %#################
%if not memq(mvar sf,splitvar) then {!*f2a sf} else         %#################
%nconc(itercoeff(lc sf,splitvar),itercoeff(red sf,splitvar))$   %#################

%-------

symbolic procedure add_terms(h)$
% h is a lisp list of terms that each has to get a constant coefficient 
% and the terms have to be added and returned
begin scalar fl,nf$
 h:=for each r in h collect <<nf   :=newfct(fname_,nil,nfct_)$ 
                              fl   :=cons(nf,fl);
                              nfct_:=add1 nfct_$
                              {'TIMES,nf,r}>>$
 return {if null h then 0 else
         if null cdr h then reval car h else reval cons('PLUS,h),
         fl}
end$

%-------

algebraic procedure ssconlaw(N,tw,cw,afwlist,abwlist,pdes,fermi)$
 % N       .. the number of superfields theta_i
 % tw      .. 2 times the differential order of the equation = weight(t)
 % cw      .. 2 times the differential order of the conservation law 
 % afwlist .. (algebraic) list of weights of the fermion fields
 %            f(1), f(2), ... 
 % abwlist .. (algebraic) list of weights of the boson fields
 %            b(1), b(2), ...
 % The number of elements in the last two lists determines the
 % number of fermion and boson fields.
 % pdes    .. an algebraic list of the pde(s) for which a conservation
 %            law is to be found, for example
 %            {df(f(1),t)=df(f(1),x)*b(1)*p9,
 %             df(b(1),t)=b(1)**3*p3 + d(1,f(1))**2*p2 + 
 %                        df(b(1),x)*b(1)*p9 + df(f(1),x)*f(1)*p4}$
 % fermi   .. if =t then conserved flow is fermionic, if =nil then bosonic
begin
 scalar cpu,gti,sw,fwlist,bwlist,allf,allb,g,h,k,l,m,Pt,Px,Pdl,fl,nf,fbno,eqn,
        Ptcp,Pxcp,Pdlcp,sol,spezsol,Ql,terms,te,minu,factors,prefac,fa,dli,
        dfli,inte,delta,dlirevcp,tr_cl,pdes2,pdes3,fno,bno,syli,deno,allcl,
        nontriv,forbid,Pt1,Px1,Pdl1,verbose$

% tr_cl:=t$ 

 backup_reduce_flags()$

 lisp <<
  record_hist:=nil;homogen_:=t;
  if !*time then <<cpu:=time()$ gti:=gctime()>>$
  input_consistency_test(afwlist,abwlist)$
  N_:=N;  % to avoid printing the index of D in crack_out for N=1
  fno:=length afwlist-1;
  bno:=length abwlist-1;
  flist := for g:=1:fno collect {'f,g};
  if flist and length flist=1 and tr_cl=nil then put('f,'prifn,'myfpri)
                                            else put('f,'prifn,nil);
  blist := for g:=1:bno collect {'b,g};
  if blist and length blist=1 and tr_cl=nil then put('b,'prifn,'myfpri)
                                            else put('b,'prifn,nil);
  fblist:=append(flist,blist)
 >>$
 afblist:=lisp(cons('LIST,fblist))$
 for each g in afblist do depend g,x,t$ 

 lisp <<

  % creating more substitutions based on pdes
  for each g in cdr pdes do <<
   if is_fermion cadr g then <<fno:=add1 fno; h:={'f,fno}>>
                        else <<bno:=add1 bno; h:={'b,bno}>>;
   algebraic(depend lisp(h),x,t);
   pdes2:=cons({'REPLACEBY,cadr g,{'PLUS,caddr g,h}},pdes2);
   pdes3:=cons({h,0,{'DIFFERENCE,cadr g,caddr g}},pdes3);
   syli:=cons(h,syli)
  >>$
  % pde2 is a substitution list introducing a symbol for each equation
  % pde3 is an assoc list with an entry for each equation, eg.
  % { {symbol_for_eqn, Q(1), df(f(1),t)-...}, 
  %   {symbol_for_eqn, Q(2), df(b(1),t)-...}, ... }   

  % listing lhs's of equations and substitutions which are no t-derivatives
  forbid:=non_t_lhs_dvs(cdr pdes)$

  pdes2:=cons('LIST,pdes2);
  if tr_cl then <<
   algebraic(write"pdes2=",lisp pdes2)$
   write"pdes3="$prettyprint pdes3$ terpri()$
   write"syli=",syli$terpri()
  >>$

  % specifying the names of constants in the equations
  if fname_list then <<fname_:=car fname_list;
                       fname_list:=cdr fname_list>>
                else   fname_:='r$ 

  fwlist:=cdr reval afwlist$
  bwlist:=cdr reval abwlist$

  % Add to each field its weight as a prefix to create allf and allb
  for i:=1:(length flist) do allf:=cons({nth(fwlist,i),nth(flist,i)},allf);
  for i:=1:(length blist) do allb:=cons({nth(bwlist,i),nth(blist,i)},allb);

  nfct_:=1$ print_:=nil$

  h:=rhs_term_list(N,allf,allb,cw-tw,nil,forbid,verbose);
  if fermi then h:= car h else h:=cadr h;
  h:=add_terms(h)$ Pt:=car h$ fl:=append(cadr h,fl)$
  eqn:={{'DF,Pt,'t}}$

  if N=0 then <<
   h:=rhs_term_list(N,allf,allb,cw-2,nil,forbid,verbose);
   if fermi then h:=car h else h:=cadr h;
   h:=add_terms(h)$ Px:=car h$ fl:=append(cadr h,fl)$
   eqn:=cons({'DF,Px,'x},eqn)$
   Pdl:=nil$
  >>     else <<
   Px:=0;    % which is no loss of generality

   h:=rhs_term_list(N,allf,allb,cw-1,nil,forbid,verbose);
   if !*t_changes_parity                  then
   if fermi then h:= car h else h:=cadr h else
   if fermi then h:=cadr h else h:= car h;
   Pdl:=nil$
   for g:=N step -1 until 1 do << % step -1 is crucial for backintegration
    k:=add_terms(h)$ 
    Pdl:=cons({'LIST,g,car k},Pdl)$ 
    fl:=append(cadr k,fl)$ 
    eqn:=cons({'D,g,car k},eqn)$
   >>
  >>$

  eqn:=cons('PLUS,eqn)$
  Pdl:=cons('LIST,Pdl)$
  fl:=cons('LIST,fl)

 >>$

 if tr_cl then <<
  write"Ansatz for Pt: ",Pt$
  write"Ansatz for Px: ",Px$ 
  write"Ansatz for Pdl: ",Pdl$
  write"list of unknown coefficients: ",fl$
 >>$

 if fl={} then return <<
  write "No valid ansatz in this case."$
  nil
 >>$ 

 let pdes; % initializing all substitutions based on equations to generate eqn.
 eqn:=eqn; % only now after `let pdes'
 clearrules pdes;

 lisp << % Formulating the conservation law conditions

  % Listing the splitting `variables' 
  h:=search_li3(reval eqn,{'DF,'F,'B,'D,'X,'T});
  if !*time then <<terpri()$
   write "CPU time so far: ",   time() - cpu," ms  ",
         " GC time so far: ", gctime() - gti," ms"$
   terpri()$
  >>$

  % Splitting
  k:=setkorder h$
  eqn:=cons('LIST,             
            for each g in itercoeff(if not pairp eqn then eqn else 
                                    if car eqn = '!*sq then reorder numr cadr eqn
                                                       else numr simp eqn,h)
            collect {'!*SQ,(g . 1),t})$
  setkorder k$

  !!arbint:=0$
  terpri()$
  write length cdr eqn," conditions for ",length cdr fl," unknowns"$
  terpri()

 >>$
 
 % Solving the conservation law conditions
 sol:=first solve(eqn,fl)$

 lisp <<
  % terpri()$
  write if 0=!!arbint then "No" else !!arbint,
        if 0 neq !!arbint then " (possibly trivial) " else " ",
        if fermi then "fermionic" else "bosonic"," conservation ",
        if 1=!!arbint then "law" else "laws"," of weight ",cw,
        if 0=!!arbint then "." else ":"$
  terpri()$

 >>$

 nontriv:=0$
 for g:=1:lisp !!arbint do <<
  spezsol:=sub(arbcomplex(g)=1,sol);
  for h:=1:lisp !!arbint do 
  if h neq g then spezsol:=sub(arbcomplex(h)=0,spezsol);

  Ptcp :=sub(spezsol,Pt)$
  Pxcp :=sub(spezsol,Px)$
  Pdlcp:=sub(spezsol,Pdl)$

  % Counting how many P's are nonzero
  if Ptcp=0 then k:=0 else k:=1;
  if Pxcp neq 0 then k:=k+1;
  h:=Pdlcp$
  while h neq {} do << if second first h neq 0 then k:=k+1;
                       h:=rest h >>$
  
  % Drop conservation laws with only one non-vanishing component
  if k=0 then write "We drop a conservation law with Pt, Px, Pd[i] ",
                     "all being zero"
         else 
  if k=1 then write "We drop a conservation law with only ",
                     if Ptcp neq 0 then "Pt" else "one Pd[i]"," nonzero."
         else <<

   Pt1:=Ptcp$
   Px1:=Pxcp$
   Pdl1:=Pdlcp$

   if tr_cl then <<
    write ">>>>> ",g,". Conservation law: "$
    write"Pt = ",Ptcp$
    write"Px = ",Pxcp$
    h:=Pdlcp$
    while h neq {} do << write"Pd[",first first h,"] = ",second first h;
                         h:=rest h >>
   >>$

   % Determination of the characteristic functions
   eqn:=df(Ptcp,t)+df(Pxcp,x)+
        for l:=1:N sum <<m:=first part(Pdlcp,l);D(m,second part(Pdlcp,l))>>$
   if tr_cl then write"rhs = ",eqn$

   if eqn=0 then % write "This conservation law is trivial!"
            else lisp <<

    Ql:=pdes3$

    pdes2:=add_df_rules_to_D_rule pdes2$   
    algebraic(let pdes2);
    eqn:=reval eqn;
    algebraic(clearrules pdes2);

    if tr_cl then <<write"rhs in terms of equations = "$
     % by now eqn should not involve any lhs or derivative 
     % of any lhs of any equation in pdes.
     prettyprint eqn;
     terpri()
    >>$   

    % taking care of quotients
    deno:=nil; 
    if pairp eqn and car eqn = 'QUOTIENT then
    if is_const caddr eqn then <<deno:=caddr eqn; eqn:=cadr eqn>>
                          else rederr" Something is wrong!! (0) *****"$
    % converting to a list of terms
    if not pairp eqn or car eqn neq 'PLUS then terms:={eqn} else terms:=cdr eqn;
    for each te in terms do <<

     % taking care of the minus sign
     minu:=nil; if pairp te and car te = 'MINUS then <<minu:=t; te:=cadr te>>$
     % checking each factor of which only one should have a t-derivative
     if not pairp te or car te neq 'TIMES then factors:={te} 
                                          else factors:=cdr te;
     prefac:=nil; 
     while factors do << % search until the first factor including an
                         % element of syli is found
      fa:=car factors;  factors:=cdr factors;
      if freeoflist(fa,syli) then prefac:=cons(fa,prefac)
                             else <<
       if tr_cl then <<
        write" Next term to be partially integrated:";terpri()$
        prettyprint prefac$ terpri()$ write" times "$terpri()$
        prettyprint fa$     terpri()$ write" times "$terpri()$
        prettyprint factors$terpri()$
        write"minu=",minu$  terpri()
       >>$

       % In the case of an exponent, a single factor is good enough for us
       if pairp fa and car fa='EXPT then <<
        factors:=cons(if caddr fa=2 then cadr fa
                                    else {'EXPT,cadr fa,sub1 caddr fa},factors);
        fa:=cadr fa
       >>$

       if null factors then factors:=1 else 
       if null cdr factors then factors:=car factors 
                           else factors:=cons('TIMES,factors);

       if null prefac then prefac:=1 else 
       if null cdr prefac then prefac:=car prefac 
                          else prefac:=cons('TIMES,reverse prefac);

       % Merging prefac and factors, i.e. moving fa to be last factor      
       if is_fermion fa and is_fermion factors then minu:=not minu;
       prefac:={'TIMES,prefac,factors}; 
       factors:=nil; % i.e. stop of while loop
       if minu then prefac:={'MINUS,prefac}; minu:=nil;

       dli:=nil;  
       while pairp fa and car fa='D do <<dli:=cons(cadr fa,dli);fa:=caddr fa>>$
       dli:=reverse dli;

       if pairp fa and car fa = 'DF then <<
        delta:=cadr fa;
        dfli:=cddr fa;
        h:=nil;
        while dfli do <<
         if fixp car dfli then for k:=2:(car dfli) do h:=cons(car h,h)
                          else h:=cons(car dfli,h);
         dfli:=cdr dfli
        >>$      
        dfli:=reverse h
       >>          else <<delta:=fa;dfli:=nil>>;
       k:=assoc(delta,Ql);  % k has form: {symb for eqn, Q_f(i), df(f(i),t)-rhs}
       Ql:=delete(k,Ql);
       delta:=caddr k;
       if deno then delta:={'QUOTIENT,delta,deno};

       if tr_cl then <<write"delta=",delta,"  dfli=",dfli$ terpri()>>$

       % At first partial integration of the D-derivatives      
       while dli do <<
        h:=car dli; dli:=cdr dli; % h in index of supersym. generator
        if is_fermion prefac then prefac:={'MINUS,prefac};
        inte:=delta;
        if dfli then inte:=cons('DF,cons(inte,dfli));

        dlirevcp:=reverse dli;
        while dlirevcp do << 
         inte:={'D,car dlirevcp,inte};
         dlirevcp:=cdr dlirevcp
        >>$
        algebraic(if tr_cl then write"Pdlcp before = ",Pdlcp)$
        algebraic(Pdlcp:=(part(Pdlcp,h):={first part(Pdlcp,h),
                                          second part(Pdlcp,h) - 
                                          lisp({'TIMES,prefac,inte})}))$
        algebraic(if tr_cl then write"Pdlcp after = ",Pdlcp)$
        prefac:=reval {'MINUS,{'D,h,prefac}}
       >>$
       % Then partial integration of the x,t-derivatives
       while dfli and not zerop prefac do <<
        if tr_cl then <<write"Partial ",car dfli,"-integration:"$ terpri()>>$
        inte:=delta;
        if cdr dfli then inte:=cons('DF,cons(inte,cdr dfli));
        if car dfli='x then <<
         algebraic(if tr_cl then write"Pxcp before = ",Pxcp)$
         Pxcp:={'DIFFERENCE,Pxcp,{'TIMES,prefac,inte}};
         algebraic(if tr_cl then write"Pxcp after = ",Pxcp)$
        >>             else <<
         algebraic(if tr_cl then write"Ptcp before = ",Ptcp)$
         Ptcp:={'DIFFERENCE,Ptcp,{'TIMES,prefac,inte}};
         algebraic(if tr_cl then write"Ptcp after = ",Ptcp)$
        >>$

        prefac:=reval {'MINUS,{'DF,prefac,car dfli}};
        dfli:=cdr dfli
       >>$

       if deno then prefac:={'QUOTIENT,prefac,deno};
       Ql:=cons({car k,{'PLUS,prefac,cadr k},caddr k},Ql);
      >>  % of not freeoflist(fa,syli)
     >>  % while factors do
    >>; % for each te in terms do

    % The integrating factors as well as the conserved densities may now
    % involve the symbols, like f(4), b(3) introduced for the equations.
    % These symbols have to be replaced by the equations now.
    nf:=cons('LIST,for each g in pdes3 collect {'EQUAL,car g,caddr g}) ;
    Ql:=for each h in Ql collect {car h,algebraic(sub(nf,lisp cadr h)),caddr h};

    % Is the conservation law trivial?
    h:=Ql$
    while h and zerop cadar h do h:=cdr h;
    if tr_cl then <<
     if null h then write"CL is TRIVIAL!"
               else write"CL is GENUINE!"$ 
     terpri()$
    >>$

    if h then algebraic << % CL is not trivial

     Ptcp :=sub(nf,Ptcp)$
     Pxcp :=sub(nf,Pxcp)$
     if N>0 then <<
      % We use D_x(Pxcp) = D(m,D(m,Pxcp)), set Pxcp=0 and add D(m,Pxcp) to
      % Pd(m) where m is one index in 1..N (probably 1).
      m:=first first Pdlcp;
      if tr_cl then write"We add Pxcp=",Pxcp," to Pd[",m,"]."$
      Pdlcp:=cons({m, D(m,Pxcp)+second first Pdlcp},
                  rest Pdlcp);
      Pxcp:=0$
      Pdlcp:=sub(nf,Pdlcp)$
     >>$

     % Test of correctness
     lisp(h:=if length Ql=1 then {'TIMES,cadar Ql,caddar Ql}
                            else cons('PLUS,for each h in Ql collect 
                                            {'TIMES,cadr h,caddr h}));

     k:=df(Ptcp,t)+df(Pxcp,x) - (lisp h) + 
        for g:=1:N sum <<m:=first part(Pdlcp,g);D(m,second part(Pdlcp,g))>>$

     % Making Ql an algebraic list
     lisp (Ql:=cons('LIST,for each h in Ql collect {'LIST,caddr h,cadr h}));

     % Is conservation law new? --> compare with CL in allcl.
     % structure of allcl: {cl1,cl2,...} where each cli is a conservation law 
     % and has the form {Ql,Pdlcp,Pxcp,Ptcp,no_of_terms_in_all_P}
     %    h:=allcl$
     %    while h neq {} do <<
     %     
     %    >>$
     %. . . . . . .

     if t then << % Print new conservation law
      lisp <<
       nontriv:=add1 nontriv;
       terpri()$
       write ">>>>> ",nontriv,". Non-trivial conservation law: "$
       terpri()$terpri()$
       write"At first in the form of a conserved current vanishing mod eqn.s:"$
       terpri()$terpri()$
      >>$
      write"Pt = ",Pt1$
      write"Px = ",Px1$
      % Printing of Pdl1
      h:=Pdl1$
      while h neq {} do <<write"Pd[",first first h,"] = ",second first h;
                          h:=rest h >>$

      write"----- and in machine readable form:"$
      off nat$
      write"Pt = ",Pt1$
      write"Px = ",Px1$
      h:=Pdl1$
      while h neq {} do << write"Pd[",first first h,"] = ",second first h;
                           h:=rest h >>$
      on nat;
      write"Now as conserved current with characteristic functions:"$

      write"Pt = ",Ptcp$
      write"Px = ",Pxcp$
      % Printing of Pdlcp
      h:=Pdlcp$
      while h neq {} do <<write"Pd[",first first h,"] = ",second first h;
                          h:=rest h >>$
      for each h in Ql do write"Q[",first h,"] = ",second h;
      write"----- and in machine readable form:"$
      off nat$
      write"Pt = ",Ptcp$
      write"Px = ",Pxcp$
      h:=Pdlcp$
      while h neq {} do << write"Pd[",first first h,"] = ",second first h;
                           h:=rest h >>$
      for each h in Ql do write"Q[",first h,"] = ",second h;
      on nat;
     >>;

     % We print contradiction message after the values to be able to check
     if k neq 0 then <<
      write"***** ERROR: "$
      write" 0 <> ",k$
      rederr" A test shows a contradiction! *****"$    
%      write" A test shows a contradiction! *****"$    %@@@@@@@@@@@@@@@@
     >>

    >>   %  there is a non-zero Q after substitution of equations
   >>   %  divergence does not vanish identically 
  >>   %  if k>1 then <<  (more than one non-vanishing component)
 >>$  %  for g:=1:lisp !!arbint do <<
 %#1#
end$

%-------

algebraic procedure ssconl(N,tw,mincw,maxcw,afwlist,abwlist,pdes)$
<<lisp <<
  terpri()$
  write"##### ssconl: This is the case N",N,"f",length cdr afwlist,"b",
       length cdr abwlist,"t",tw,"w"$
  for each g in append(cdr afwlist,cdr abwlist) do write g;
  write". #####"$terpri()$
 >>$
 write"The ",if length pdes=1 then "equation" else "system",
      " to be investigated:"$
 for each h in pdes do write h$
 pdes:= for each h in pdes collect 
        lisp {'REPLACEBY,cadr algebraic h,caddr algebraic h}$
 lisp <<
  terpri()$
  write"Each CL has the form:  "$terpri()$
  if N=0 then write"    Dt(Pt) + Dx(Px) = Q1*PDE1 + .."
         else write"    Dt(Pt) + sum_i Di(Pd(i)) = Q1*PDE1 + .."$ 
  terpri()$
  write"where, e.g. PDE1 is (left hand side) - (right hand side) of PDE 1."$
  terpri()
 >>$
 for h:=mincw:maxcw do <<
  write"NEXT: FERMIONIC CONSERVATION LAWS OF WEIGHT ",h$
  ssconlaw(N,tw,h,afwlist,abwlist,pdes,t)$
  write"NEXT: BOSONIC CONSERVATION LAWS OF WEIGHT ",h$
  ssconlaw(N,tw,h,afwlist,abwlist,pdes,nil)
 >>
>>$

%-------

symbolic procedure lofl(n,mwt)$
% produces lists with n elements, each having a value 0...mwt
if n=1 then for i:=0:mwt collect {i,{i}} else 
for each l in lofl(n-1,mwt) join 
for j:=0:(mwt-car l) collect {j+car l,cons(j,cadr l)}$

%-------

symbolic procedure wgtof(h,ali,wl)$
% subroutine for FindSSWeights below, determines weight of a kernel
begin scalar w,wt,m$
 return
 if w:=assoc(h,ali) then {cdr w,ali,wl} else
 if pairp h and car h='D then <<
  w:=wgtof(caddr h,ali,wl);
  cons({'PLUS,car w,1},cdr w)
 >>                      else
 if pairp h and car h='DF then <<
  w:=wgtof(cadr h,ali,wl);
  wt:=car w;
  ali:=cadr w;
  wl:=caddr w;
  h:=cddr h; % h is now a list of differentiations
  while h do <<
   w:=wgtof(car h,ali,wl);
   h:=cdr h;
   ali:=cadr w;
   wl:=caddr w;
   if null h or not fixp car h then m:=1
                               else <<m:=car h; h:=cdr h>>;
   wt:={'DIFFERENCE,wt,{'TIMES,car w,m}}
  >>$
  {wt,ali,wl}
 >>                       else <<
  wt:=mkid('w_,if pairp h then gensym() 
                          else h       );
  ali:=cons((h . wt), ali);
  wl:=cons(wt,wl);
  {wt,ali,wl}
 >>
end$

%-------

symbolic operator FindSSWeights$
symbolic procedure FindSSWeights(N,nf,nb,exli,zerowei,verbose)$
% This procedure computes all homogeneities of a list of
% expressios exli which can but need not be equations.
% zerowei is a list of identifiers which should get zero weight.
begin
 scalar j,k,s,bsn,w,jmax,h,ex,fwli,bwli,sc,fh,bh,eh,posi,zrop,posh,negh,
        bs,    % list of all 2^N sequences of 0's and 1's
        ali,   % association list of (kernel . weight_name)
        allali,% list of association lists for all homogeneities
        wl,    % list of all weight names (needed for solveeval)
        sf,    % numerator of an equation (minus first terms..)
        tf,    % (first) term of sf
        wtli,  % list of conditions resulting from one equation
        wt,    % weight of one term in one equation
        eli,   % list of all conditions on weights
        ewli,  % list of weights of expressions/equations in exli
        hlist  % list of all homogeneities
$

 % Consistency of input:
 if not pairp exli or car exli neq 'LIST then return <<
  write"The input expression is not a list  {  } ."$terpri()$
  write"Try again."$terpri()
 >>$  

 % Generation of bs
 bs:={nil};
 for j:=1:N do <<
  for each s in bs do <<
   bsn:=cons(cons(0,s),bsn);
   bsn:=cons(cons(1,s),bsn)
  >>;
  bs:=bsn; bsn:=nil
 >>$
 bs:=for each s in bs collect cons(for each j in s sum j,s)$

 % initialization of ali
 ali:={('x . -2)}$

 % identifiers with zero weight
 for each h in cdr reval zerowei do
 ali:=cons((h . 0), ali); 

 % the weights of further differentiation variables will be 
 % added dynamically as they occur 

 % the weights of all th-variables
 for j:=1:N do ali:=cons(({'th,j} . -1), ali);

 % the weights of all fermionic fields
 for j:=1:nf do <<

  % adding f(j):
  w:=mkid('w_,mkid('f,j));
  wl:=cons(w,wl);
  ali:=cons(({'f,j} . w), ali);

  % now all coefficients f(j,..), b(j,..) of all terms in the
  % th(k) power expansion of f(j):
  for each s in bs do 
  ali:=cons(((if evenp car s then append({'f,j},cdr s)
                             else append({'b,j},cdr s)) . 
             (if zerop car s then w
                             else {'PLUS,w,car s})        ), ali)
 >>$

 % the weights of all bosonic fields
 for j:=1:nb do <<

  % adding b(j):
  w:=mkid('w_,mkid('b,j));
  wl:=cons(w,wl);
  ali:=cons(({'b,j} . w), ali);

  % now all coefficients f(j,..), b(j,..) of all terms in the
  % th(k) power expansion of b(j):
  for each s in bs do 
  ali:=cons(((if evenp car s then append({'b,j},cdr s)
                             else append({'f,j},cdr s)) . 
             (if zerop car s then w
                             else {'PLUS,w,car s})        ), ali)
 >>$

 for each ex in cdr exli do <<

  sf:=numr (if pairp ex and (car ex = 'EQUAL) then 
  subtrsq(simp cadr ex,simp caddr ex)         else simp ex);
  % sf is the numerator of the expression

  wtli:=nil;
  while sf do <<
   tf:=first_term_SF sf; sf:=subtrf(sf,tf); % tf is the first term
   wt:=nil;
   while tf and not domainp tf do <<

    w:=wgtof(mvar tf,ali,wl);
    wt:=cons({'TIMES,ldeg tf,car w},wt);
    ali:=cadr w;
    wl:=caddr w;
    tf:=lc tf
   >>;
   wt:=if null wt then 0              else
       if cdr  wt then cons('PLUS,wt) else 
		       car wt$
   wtli:=cons(reval wt,wtli)
  >>;

  if wtli and cdr wtli then % ie. if there are at least 2 terms
  % then formulate a weight condition for each term to have
  % the same weight as the first term, eli is the resulting
  % list of conditions
  for each w in cdr wtli do
  eli:=cons(reval {'DIFFERENCE,car wtli,w}, eli)$
  ewli:=cons(car wtli,ewli)
 >>;

 % solving the system of conditions
 !!arbint:=0;
 if null eli then 
 if null wl then s:=nil
            else <<
  s:=nil;
  for each w in wl do <<
   !!arbint:=add1 !!arbint;
   s:=cons({'EQUAL,w,{'ARBCOMPLEX,!!arbint}},s)
  >>$
  s:=cons('LIST,s)
 >>          else <<
  s:=solveeval {cons('LIST,eli),cons('LIST,wl)};
  if s then s:=cdr s;  % to get rid of 'LIST
  if s then s:=car s;  % This was a linear homogeneous problem with 
  % only one solution which we take (possibly with free parameters).

  % If there is just a single unknown then the solution will consist
  % only on one {'EQUAL,w_..,..} and not a list --> we make it a list
  if pairp s and car s = 'EQUAL then s:={'LIST,s}

 >>;

 if s then <<

  fwli:=cons('LIST,for j:=1:nf collect cdr assoc({'f,j},ali));
  bwli:=cons('LIST,for j:=1:nb collect cdr assoc({'b,j},ali));
  ewli:=cons('LIST,ewli);


  jmax:=if !!arbint=0 then 1 else !!arbint$
  for j:=1:jmax do <<
   sc:=s;
   for k:=1:!!arbint do 
   if k neq j then sc:=algebraic(sub(arbcomplex(lisp k)=0,sc));

   % storing all homogeneities 
   k:=ali;
   for each h in cdr sc do
   k:=subst(caddr h,reval cadr h,k);
   allali:=cons(k,allali);

   if j neq 0 then 
   sc:=algebraic(sub(arbcomplex(lisp j)=1,sc));

   % storing the homogeneity weights of f(1),f(2),.. b(1),b(2),..
   % in sorted lists:
   fh:=algebraic(sub(lisp sc,lisp fwli));
   bh:=algebraic(sub(lisp sc,lisp bwli));
   eh:=algebraic(sub(lisp sc,lisp ewli));

   % All homogeneities with strictly positive weights will be
   % collected in posh and all others in negh. Then they are
   % appended with posh coming first.
   posi:=t; zrop:=t;
   for each k in cdr fh do <<
    if k<=0 then posi:=nil;
    if k neq 0 then zrop:=nil
   >>;
   for each k in cdr bh do <<
    if k<=0 then posi:=nil;
    if k neq 0 then zrop:=nil
   >>$
   if null zrop then <<
    if posi then posh:=cons({'LIST,fh,bh,eh},posh)
	    else negh:=cons({'LIST,fh,bh,eh},negh);
   >>
  >>
 >>;
 hlist:=cons('LIST,append(posh,negh));

 % Printing all homogeneities
 if verbose then <<
  if hlist={'LIST} then write"This system is not homogeneous." 
		   else <<
   if !!arbint=0 then 
   write"This system has the following homogeneity:" else
   write"This system has the following homogeneities:"$
   terpri()$
   for each ali in allali do <<
    for each w in ali do 
    algebraic(write"W[",lisp car w,"] = ",lisp reval cdr w)$
    write"================================="$terpri()$
   >>$

   write"The program returns a list of "$
   h:=length hlist - 1; 
   if h=1 then <<write"one homogeneity"$terpri()$
    write"which is a list of"
   >>     else <<write h," homogeneities,"$ terpri()$
    write"each homogeneity being a list of"$
   >>$
   terpri()$
   write"a list of all f(1),b(2),.. weights and"$terpri()$
   write"a list of all b(1),b(2),.. weights and"$terpri()$
   write"a list of the weights of equations/expressions"$terpri()$
   write"in the input. "$
   if !!arbint neq 0 then <<
    write"In this output free parameters"$terpri()$
    write"arbcomplex(i) are replaced by 1:"$
   >>$
   terpri()$
   mathprint hlist$
  >>
 >>$

 return hlist

end$

%-------

algebraic procedure linearize(pdes,nf,nb,tpar,spar)$
% pdes   .. a list of equations with a t-derivative on the left hand side
% nf     .. number of fermion fields f(1) .. f(nf)
% nb     .. number of boson   fields b(1) .. b(nb)
% tpar   .. whether the variable t is parity changing
% spar   .. whether the symmetry parameter s of the symmetry that corresponds 
%           to this linearization is parity changing (t) or not (nil)
% linearize returns
% {list of relations that define the introduced fields like df(f(3),s)=f(6),
%  list of linearized equations}
% Newly introduced fields depend on x,t,s. 
begin scalar spar_bak,tpar_bak,n,m,p,npdes,rel$

 spar_bak:=lisp s_changes_parity$
 tpar_bak:=lisp t_changes_parity$
 if tpar then on  t_changes_parity
         else off t_changes_parity$

 % generation of a substitution list f --> F, b --> B for spar=nil
 %                                or f --> B, f --> F got spar=t
 n:=length pdes$
 lisp << terpri()$
  write"The following linearization generates ",
       if n = 1 then "a condition" else "conditions",
       " for the right hand side",
       if n = 1 then " " else "s "$terpri()$
  write"of the symmetry: "$
  terpri()$terpri()
 >>$
 rel:={}$
 if spar then <<
  on  s_changes_parity$
  for n:=1:nf do <<m:=nb+n;depend b(m),x,t;depend f(n),s;
                   rel:=cons(df(f(n),s)=b(m),rel);df(f(n),s):=b(m);
                   lisp write "   D_s f(",n,") = b(",m,")">>$
  for n:=1:nb do <<m:=nf+n;depend f(m),x,t;depend b(n),s;
                   rel:=cons(df(b(n),s)=f(m),rel);df(b(n),s):=f(m);
                   lisp write "   D_s b(",n,") = f(",m,")">>
 >>      else <<
  off s_changes_parity$
  for n:=1:nf do <<m:=nf+n;depend b(m),x,t;depend f(n),s;
                   rel:=cons(df(f(n),s)=f(m),rel);df(f(n),s):=f(m);
                   lisp write "   D_s f(",n,") = f(",m,")">>$
  for n:=1:nb do <<m:=nb+n;depend f(m),x,t;depend b(n),s;
                   rel:=cons(df(b(n),s)=b(m),rel);df(b(n),s):=b(m);
                   lisp write "   D_s b(",n,") = b(",m,")">>
 >>$
 lisp terpri()$

 write"The original system:"$
 for each p in pdes do write p$

 npdes:={};
 for each p in pdes do <<
  m:=df(lhs p,s)$
  if part(m,0)=minus then n:=t else n:=nil$
  npdes:=sqcons(if tpar and spar then if n then (-m =  df(rhs p,s))
                                           else ( m = -df(rhs p,s))
                                 else if n then (-m = -df(rhs p,s))
                                           else ( m =  df(rhs p,s)), npdes)
 >>$

 npdes:=reverse npdes;
 write"The linearized system: "$
 for each p in npdes do write p$
 write"and in machine readable form: "$ off nat$
 for each p in npdes do write p$
 on  nat$

 if lisp(spar_bak neq s_changes_parity) then 
 if spar_bak then on  s_changes_parity
             else off s_changes_parity$

 if lisp(tpar_bak neq t_changes_parity) then 
 if tpar_bak then on  t_changes_parity
             else off t_changes_parity$

 % for n:=1:nf do clear df(f(n),s)$
 % for n:=1:nb do clear df(b(n),s)$

 return {rel,npdes}
end$

%-------

symbolic operator  GenSSPoly$
symbolic procedure GenSSPoly(N,wgtlist,cname,mode)$
begin 
 scalar linsub,g,h,N,flist,blist,afblist,forbid,non0coeff,fname_bak,
        fl,allf,allb,fwlist,bwlist,nf,nb,verbose,afwlist,abwlist,pol,
        fonly,bonly,wgt,newf,newb,print_bak$

 wgtlist:=cdr wgtlist; % to drop 'LIST
 afwlist:=cadr   car wgtlist;
 abwlist:=caddr  car wgtlist;
 wgt    :=cadddr car wgtlist;
 wgtlist:=cdr wgtlist;

 nf:=length afwlist - 1; fwlist:=cdr reval afwlist$
 nb:=length abwlist - 1; bwlist:=cdr reval abwlist$

 % Initialization of flags
 mode:=cdr mode;       % to drop 'LIST
 while mode do <<
  if car mode = 'lin then <<
   if not evenp nf then 
   rederr"The flag `lin' can not be run with odd many fermions"$
   linsub:=for h:=(nf/2+1):nf collect {'f,h}$
   if not evenp nb then 
   rederr"The flag `lin' can not be run with odd many bosons"$
   linsub:=cons('LIST,append(linsub,for h:=(nb/2+1):nb collect {'b,h}))
  >>                 else
  if car mode = 'verbose then verbose:=t else 
  if car mode = 'fonly then fonly:=t else 
  if car mode = 'bonly then bonly:=t else 
  if pairp car mode and cadar mode = 'forbid    then forbid   :=cddar mode else
  if pairp car mode and cadar mode = 'non0coeff then non0coeff:=cddar mode$
  mode:=cdr mode
 >>$
 
 % Initialization of fermionic and bosonic fields + their printing
 input_consistency_test(afwlist,abwlist)$
 N_:=N;  % to avoid printing the index of D in crack_out for N=1

 flist := for g:=1:nf collect {'f,g};
 % if nf=1 then put('f,'prifn,'myfpri) else
 % if nf>1 then put('f,'prifn,nil);
 % This was commented out to avoid confusion when nf=1 and using th(i)
 % expansions and coefficients f(1,1,0,0,1,..).

 blist := for g:=1:nb collect {'b,g};
 % if nb=1 then put('b,'prifn,'myfpri) else
 % if nb>1 then put('b,'prifn,nil);

 % Making f(i) and b(i) x,t-dependent
 algebraic <<
  afblist:=lisp(cons('LIST,append(flist,blist)))$
  for each g in afblist do depend g,x,t$  %<############## t-dependence?
 >>$

 % specifying the names of constants in the symmetries
 fname_bak:=fname_; fname_:=reval cname;

 % Add to each field its weight as a prefix to create allf and allb
 for i:=1:nf do allf:=cons({nth(fwlist,i),nth(flist,i)},allf);
 for i:=1:nb do allb:=cons({nth(bwlist,i),nth(blist,i)},allb);

 % generation of a list of all terms
 pol:=rhs_term_list(N,allf,allb,wgt,linsub,forbid,verbose)$ % returns {fprod,bprod}
 pol:={'LIST,cons('LIST,car pol),cons('LIST,cadr pol)}$

 %>>>>>> add to avoid all forbid factors also if they are f(i) or b(i) or d(i,..)

 % applying the remaining homogeneities
 while wgtlist do <<
  afwlist:=cadr   car wgtlist;
  abwlist:=caddr  car wgtlist;
  wgt    :=cadddr car wgtlist;
  wgtlist:=cdr wgtlist;

  algebraic <<
   % creating a substitution rule
   su:={};
   g:=0$for each h in afwlist do <<g:=g+1;su:=cons(f(g)=f(g)*lin_test_const**h,su)>>$
   g:=0$for each h in abwlist do <<g:=g+1;su:=cons(b(g)=b(g)*lin_test_const**h,su)>>$
   pol:=sub(su,pol);
   let lrule1; pol:=pol; clearrules lrule1;
   let lrule2; pol:=pol; clearrules lrule2;

   newf:={}$  
   for each h in first pol do <<
    h:=h/lin_test_const**wgt; 
    if freeof(h,lin_test_const) then newf:=cons(h,newf)
   >>$

   newb:={}$
   for each h in second pol do <<
    h:=h/lin_test_const**wgt; 
    if freeof(h,lin_test_const) then newb:=cons(h,newb)
   >>$

   pol:={newf,newb}
  >>
 >>$

 print_bak:=print_; print_:=nil;
 newf:=if bonly then 0
                else <<
  h:=for each g in cdadr pol collect <<h    :=newfct(fname_,nil,nfct_)$ 
	 			       fl   :=cons(h,fl);
				       nfct_:=add1 nfct_$
				       {'TIMES,h,g}>>$
  if h then if cdr h then cons('PLUS,h)
                     else car h
       else 0
 >>$
 newb:=if fonly then 0 
                else <<
  h:=for each g in cdaddr pol collect <<h    :=newfct(fname_,nil,nfct_)$ 
	 		   	        fl   :=cons(h,fl);
				        nfct_:=add1 nfct_$
				        {'TIMES,h,g}>>$
  if h then if cdr h then cons('PLUS,h)
                     else car h
       else 0
 >>$
 print_:=print_bak;
 fname_:=fname_bak;
 flin_:=fl$

 return {'LIST,newf,newb,cons('LIST,fl)}
end$

%-------

algebraic procedure thgen(k)$
% generates a list with 2^N elements, each element generating
% a term in the th-power series and has the form:
% {product_of_th(i), 
%  number_of_factors_th(i), 
%  {0's and 1's, i.e. a 1 for each th() otherwise zeros} } 
if k=0 then {{1,0,{}}} 
       else begin 
 scalar a,b$
 a:= thgen(k-1)$
 return for each b in a 
        join {{first b,       second b,   append (third b,{0})},
              {th(k)*first(b),second(b)+1,append (third b,{1})} }
end$

Drule:={D(~i,~a)=>df(a,th(i))+th(i)*df(a,x)}$ % can not be defined within tocoo

algebraic procedure tocoo(N,nf,nb,ex)$
% nf: number of fermion fields
% nb: number of boson fields
% ex: polynomial expression in field form to be transformed into coordinate form
begin
 scalar thli,subfnb,i,h$ 
 lisp(N_:=N);
 put('f,'prifn,nil);
 put('b,'prifn,nil);
 thli:=thgen(N)$

 % Generate the coordinate form of f(i)
 subfnb:={};
 for i:=1:nf do 
 subfnb:=cons(f(i)=for each h in thli sum 
   if evenp second h then lisp(cons('f,cdr algebraic cons(i,third h)))*first h
	             else lisp(cons('b,cdr algebraic cons(i,third h)))*first h, 
              subfnb);

 % Generate the coordinate form of b(i)
 for i:=1:nb do
 subfnb:=cons(b(i)=for each h in thli sum 
   if evenp second h then lisp(cons('b,cdr algebraic cons(i,third h)))*first h
                     else lisp(cons('f,cdr algebraic cons(i,third h)))*first h, 
              subfnb);
 
 % Do the substitution
 ex:=sub(subfnb,ex)$
 % Replace D(i,..) which has to be done AFTER the above substitution
 let Drule;
 ex:=ex;
 clearrules Drule;

 return ex

end$

%-------

algebraic procedure tofield(N,nf,nb,ex,zerowei)$
% tw the total weight of the input expression ex which is
% expected to be either purely fermionic or purely bosonic.

% In a call to GenSSPoly() an ansatz (ssp) in field form with the proper
% homogeneity weights is generated, then converted to coordinate form (ans)
% in a call to tocoo() and compared to the input in coordinate form (ex).
% The difference is splitted through a call to split_simp() and the
% resulting system of conditions for the undetermined coefficients of
% the ansatz has to vanish.

if lisp (pairp algebraic ex and car ex = 'LIST)            then
write"The input should be a polynomial, not an equations!" else
begin scalar ssp,ans,fieldans,rlist,indepv,h,eqnli,solu,wflist,wblist,tw,
 gs,k,ft,sb,notnum,notpos$

 w:=FindSSWeights(N,nf,nb,{ex},zerowei,t)$ % e.g.  w={{{1,3},{},{5}}}
 if w={} then return lisp <<
  write"The input expression does not have a homogeneity"$ terpri()$
  write"which could be used to compute a field form."$     terpri()
 >>$

 w:=first w$ % We just use the fist homogeneity because if there are
             % several and there is one with strictly positive weights
             % then this comes first.
 
 wflist:=first w;
 wblist:=second w;
 tw:=first third w;
 
 for each h in append(wflist,wblist) do 
 if not fixp h then notnum:=t else
 if h <= 0 then notpos:=t$

 if notnum then lisp <<
  write"#####   Strange error: returned weights returned"$terpri()$
  write"        from FindSSWeights() are not integers!   #####"$terpri()
 >>        else
 if notpos then lisp <<
  gs:=gensym()$
  k:=setkorder list gs$
  ft:=append(search_li2(algebraic ex,'f),
             search_li2(algebraic ex,'b) )$   % all f(..), b(..) functions
  for each h in ft do sb:=cons((h . {'TIMES,h,gs}), sb)$
  h:=numr simp {'!*sq,subsq(simp algebraic ex,sb),nil}$
  algebraic(max_deg):=if mvar h neq gs then 0 else
                      ldeg numr simp {'!*sq,subsq(simp algebraic ex,sb),nil}$
  setkorder k
 >>$

 % generating an ansatz in field form (ssp)
 % and convert it back to coordinate form (ans) 
 % Next line works so far only if not compilied.
 if is_fermionic(lisp{'!*SQ,((first_term_SF numr simp algebraic ex) . 1),t}) then <<
 % if (lisp{'!*SQ,((first_term_SF numr simp algebraic ex) . 1),t})**2=0 then <<
  ssp:=gensspoly(N,{{wflist,wblist,tw}},r,{fonly});
  fieldans:=first(ssp);
 >>                                                                          else <<
  ssp:=gensspoly(N,{{wflist,wblist,tw}},r,{bonly});
  fieldans:=second(ssp);
 >>;

 ans:=tocoo(N,nf,nb,fieldans)$

 %spliting the equation
 rlist:=third(ssp); % a list of undetermined coefficients r1,r2, ... 
 indepv:=append({x,t},for h:=1:N collect th(h))$ % all independent variables
 lisp(print_:=nil)$ % to suppress printing about the splitting
 eqnli:=split_simp({ans-ex},{},rlist,indepv,t)$

 %applying crack to find solutions
 solu:=crack(eqnli,{},rlist,{})$

 return if solu={} then lisp <<
  write"The expression to be transformed has a homogeneity"$terpri()$
  write"but a field form does not exist."$terpri()
 >>                else <<solu:=second first (solu);
                          sub(solu,fieldans)>>

end$

%-------

symbolic procedure restore_interactive_prompt$
  begin scalar !*redefmsg,!*usermode$
    copyd('update_prompt,'restore_update_prompt)
  end$

%-------

symbolic procedure change_prompt$
  begin scalar !*usermode$
    if null promptstring!* then promptstring!* := "";
    setpchar promptstring!*;
    promptexp!* := promptstring!*
  end$

%-------

symbolic procedure change_prompt_to u$
   begin scalar oldprompt,!*redefmsg,!*usermode$
     oldprompt := promptstring!*;
     promptstring!* := u;
     copyd('restore_update_prompt,'update_prompt);
     copyd('update_prompt,'change_prompt);
     update_prompt();
     restore_interactive_prompt()$
     return oldprompt
   end$

%-------

symbolic procedure cnt_l_$
if lines_written geq 10 then <<
  change_prompt_to ""$ 
  write"                                   Press Enter to continue "$
  restore_interactive_prompt()$
  rds nil; wrs nil$         % Switch I/O to terminal
  readch()$
  if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
  if ofl!* then wrs cdr ofl!*$
  lines_written:=0
>>$

%-------

symbolic procedure wl1(l)$ 
<<write l$ terpri()$ cnt_l_()$ lines_written:=lines_written+1>>$
symbolic procedure wl2(l)$ 
<<write l$ terpri()$ terpri()$ cnt_l_()$ lines_written:=lines_written+2>>$

%-------

symbolic procedure sshelp1$
<<wl2"Purpose: "$                                                    

 wl1"to determine evolutionary supersymmetric PDEs with higher"$    
 wl1"symmetries, to compute symmetries and conservation laws for"$  
 wl1"given supersymmetric PDEs, or to do any other algebra or"$
 wl2"differentiations of polynomial supersymmetric expressions."$  
>>$

%-------

symbolic procedure sshelp2$
<<wl2"Notation: "$                                                   

 wl1"Fields f(1),f(2),.. are treated as fermionic, and b(1),.. are"$   
 wl1"treated as bosonic. The independent variables are t, x and in"$
 wl1"symmetry computations the symmetry `time' variable is s. "$  
 wl2"Further femionic variables can be defined, for example, theta."$

 wl1"The super derivatives D_i which satisfy (D_i)**2 = d/dx "$    
 wl2"are implemented as d(i, .. ) .  "$                              

 wl1"When refering to homogeneity weights, all weights are scaled"$ 
 wl1"such that the weight of d(i, .. ) is 1 and thus the weight"$   
 wl2"of df( .. , x) is two, i.e. twice the usual value. "$
>>$

%-------

symbolic procedure sshelp3$
<<wl2"Initializations: "$                                            

 wl1"Before starting super-computations the number N of superfields theta_i"$
 wl1"needs to be known. Also the number nb of boson fields and the nf of"$
 wl1"fermion fields is needed to have compact printing on the screen (to"$
 wl1"avoid printing the index 1 if nf=1 or nb=1). The input of N,nf,nb is"$
 wl1"done either through a call of the procedure ssym (to compute"$
 wl1"symmetries) or of the procedure ssconl (to compute conservation laws)"$
 wl1"or with a call of procedure ssini. This help item describes ssini."$
 wl2"It's format is:"$

 wl2"  ssini(N,nf,nb)$"$          

 wl2"where"$
 
 wl1" N      .. the number of superfields theta_i"$
 wl1" nf     .. number of fermion fields f(1) .. f(nf)"$
 wl2" nb     .. number of boson   fields b(1) .. b(nb)"$

 wl2"-----------------"$

 wl2"Example: For N=1 and 2 fermion and 2 boson fields we do"$

 wl2"ssini(1,2,2)$ "$

 wl2"and verify easily that fermions anticommute: "$

 wl1"f(1)**2; "$
 wl2"f(1)*f(2)+f(2)*f(1);"$

 wl2"that bosons commute:"$

 wl1"b(1)**3;"$
 wl2"b(1)*b(2)-b(2)*b(1);"$

 wl2"that x,t-differentiations by default do not change parity"$

 wl1"df(b(1),t)**2;"$
 wl2"df(b(1),x)**2;"$

 wl2"unless one explicitly defines d/dt to be parity changing through"$

 wl2"on t_changes_parity$"$

 wl2"demonstrated by"$

 wl2"df(b(1),t)**2;"$

 wl1"which is also possible to define for the symmetry variable s "$
 wl1"(through       on s_changes_parity$             , see below)"$
 wl2"but not for x. For the remainder of this demo we change back"$

 wl1"off t_changes_parity$"$
 wl2"df(b(1),t)**2;"$

 wl1"Differentiations d/dt, d/dx, D_i follow the supersymmetric"$
 wl2"product rule:"$

 wl1"df(b(1)*f(2),x);"$
 wl1"d(1,b(1)*f(2));"$
 wl1"df(f(1)*f(2),x);"$
 wl2"d(1,f(1)*f(2));"$

 wl2"furthermore D_i changes parity:"$

 wl1"d(1,f(1))**2;"$
 wl2"d(1,b(1))**2;"$

 wl2"and satisfies  D^2 = d/dx:"$

 wl2"d(1,d(1,b(1)));"$

 wl1"To compactify output, in the special case N=1 the index of D_i"$
 wl1"is not printed as seen above. Similarly, indices of f(1), b(1)"$
 wl2"are not printed if we have only one fermion and/or one boson field:"$

 wl1"ssini(2,1,2)$"$
 wl2"f(1)*b(1)*d(1,b(2));"$

 wl1"Any initializations made by ssini are overwritten by a call to the"$
 wl2"procedures ssym or ssconl."$  

>>$

%-------

symbolic procedure sshelp4$
<<wl2"Coefficients: "$                                                    

 wl1"coeffn is a standard REDUCE command although its implementation"$
 wl1"(at least in REDUCE distributions up to version 3.8) does not work"$
 wl1"with non-commuting variables. By loading SsTools some of the REDUCE"$
 wl1"routines are re-defined so that coeffn can be used for supersymmetric"$
 wl2"expressions. The call is unchanged from the standard REDUCE command:"$

 wl2"coeffn(ex,h,n)$"$

 wl1"which computes the coefficient of h**n in the expression ex which"$
 wl1"is supposed to be polynomial in h. The returned result is the"$
 wl1"coefficient AFTER h**n has been moved to be the first factor in"$
 wl2"each term of ex. This matters if h is fermionic and thus n=1."$

 wl2"Example:"$

 wl1"SSIni(2,0,2)$"$
 wl1"ex:=D(2,b(1))*D(1,df(b(2),x,2));"$
 wl2"coeffn(ex,D(1,df(b(2),x,2)),1);"$

 wl1"Because D_2 b(1) and D_1 D_x D_x b(2) are fermionic a minus sign is"$
 wl1"introduced when making D_1 D_x D_x b(2) the first factor in the"$
 wl2"product. This explains the minus in the result of the coeffn call."$

 wl1"NOTE: When using SsTools the REDUCE command noncom has no effect,"$
 wl1"i.e. it is not possible to define additional noncommuting quantities"$
 wl2"besides fermionic ones which are introduced by the command fermionic."$

>>$

%-------

symbolic procedure sshelp5$
<<% special use comments: 
 % in drvlist$ % loads the ansatz of the previous ssym run
 % use_new_crackout:=t$ % needed to use the ssym specific crack_out()

 wl2"Computing symmetries:"$

 wl1"To compute PDEs together with higher symmetries, or to"$ 
 wl2"compute higher symmetries for a given PDE(-system) the call is:"$   

 wl2"  ssym(N,tw,sw,afwlist,abwlist,eqnlist,fl,inelist,mode)$"$          

 wl2"where"$

 wl1" N       .. the number of superfields theta_i"$
 wl1" tw      .. 2 times the differential order of the equation = weight(t)"$ 
 wl1" sw      .. 2 times the differential order of the symmetry = weight(s)"$ 
 wl1" afwlist .. (algebraic mode) list of weights of the fermion fields"$     
 wl1"            f(1), f(2), ... . The number of elements of this list"$
 wl1"            determines the number of fermion fields. "$
 wl1" abwlist .. (algebraic mode) list of weights of the boson fields"$       
 wl1"            b(1), b(2), ... . The number of elements of this list"$
 wl1"            determines the number of boson fields. "$
 wl1" eqnlist .. - in the nonlinear case a list of extra conditions on the"$
 wl1"              undetermined coefficients where conditions a3=.. are executed"$
 wl1"              instantly. These and any expressions are added to equations"$
 wl1"              when calling crack"$
 wl1"            - in the linear case the system in form of replacements => and"$
 wl1"              the linearized system in form of equations = ."$
 wl1" fl      .. extra unknowns in eqnlist to be determined"$                 
 wl1" inelist .. a list, each element of it is a list with at least one of"$  
 wl1"            its elements being non-zero"$                                
 wl1" mode    .. list of flags: "$                                            
 wl1"            init: only initialization of global data"$                   
 wl1"            plain_com : direct computation of the commutator (for tests)"$ 
 wl1"            power_split_com : alternatice power splitting of commutator,"$ 
 wl1"                             (not if substitutions '=>' are present,"$ 
 wl1"                              see below)"$   
 wl1"            zerocoeff: all coefficients = 0 which do not appear in inelist"$ 
 wl1"            filter: extra homogeneity weights as given in the list"$
 wl1"                    hom_wei have to be satisfied by the symmetry"$
 wl1"            lin: find symmetry that is linear homogeneous in all fields "$
 wl1"                 with (index)>(maxindex/2), i.e. if lin then the"$
 wl1"                 number of fermions and boson fields must both be even"$  
 wl1"            tpar: t/nil, whether time variable t changes parity"$        
 wl2"            spar: t/nil, whether symmetry variable s changes parity"$    

 wl2"-----------------"$

 wl1"The question whether ssym is to be used to compute a PDE(-system) with"$ 
 wl1"symmetries, or to compute symmetries for a `given' PDE(-system) is"$
 wl1"decided based on the form of the input eqnlist. "$
 wl1"If symmetries of a specific weight for a given PDE(-system) are to"$
 wl1"be computed then eqnlist has to have the form"$
 wl1"{df(f(1),t)=..., df(b(1),t)=...} with as many t-derivatives"$
 wl1"of fermion fields as there are elements in afwlist and as many"$
 wl2"t-derivatives of boson fields as there are elements in abwlist."$
 
 wl1"If the right hand sides of the PDE(s) in eqnlist involve any "$
 wl1"constants which are to be computed then these constants have to "$
 wl1"be listed in the input list fl, like {p1,p2,...}. If these constant "$
 wl1"coefficients are not given in the list fl then they are treated as "$
 wl1"independent parameters and symmetries are determined which are "$
 wl1"symmetries for generic values of these constant coefficients."$
 wl1"Also, when computing symmetries for a given PDE(-system) then "$
 wl1"dependencies of all the fields on t,x has to be declared"$
 wl1"beforehand in order to be able to input derivatives, like df(f(1),t) "$
 wl2"which otherwise would be automatically evaluated to zero."$

 wl1"If the input list eqnlist does not start with {df(..)=..} then"$
 wl1"an ansatz for the PDE(-system) is generated and this system and"$
 wl1"its symmetries are computed. In this case eqnlist can contain"$
 wl1"substitutions, like p2=0, or expressions which are to be set to"$
 wl1"zero, like p3*r4+p2*r3. Typically one would run the program first "$
 wl1"to see which ansatz for the PDE(-system) and the symmetry is "$
 wl1"generated and then start ssym again with the intended extra"$
 wl2"conditions."$

 wl1"If a boson weight is non-positive or a fermion weight is negative"$
 wl1"then the global (algebraic mode) variable max_deg must have a positive"$
 wl2"integer value which is the highest degree of such a field in any ansatz."$

 wl1"When determining symmetries (either for a given system of equations,"$
 wl1"or when determining equations and symmetries in one run) one has two"$
 wl1"cases: whether the symmetry variable s flips parity, or not, in other"$
 wl1"words, whether s itself is fermionic or bosonic. This has nothing to do"$
 wl1"with the question whether s has an odd or even weight."$
 wl1"Similarly, when determining equations and symmetries in one computation"$
 wl1"one can consider the two cases whether the `time' derivative changes"$
 wl1"parity or not. A parity changing t is specified through the flag `tpar'"$
 wl2"and a parity changing s through the flag `spar'."$

 wl2"-----------------"$

 wl2"Example for determining PDEs + symmetries:"$

 wl2"ssym(1,4,5,{2},{2},{},{},{},{})$ "$

 wl2"Example for determining the symmetries of a given PDE-system:"$
 
 wl1"ssym(1,4,5,{2},{2},"$
 wl1"     {df(f(1),t)=df(f(1),x)*b(1)*p9,"$
 wl1"      df(b(1),t)=df(b(1),x)*b(1)*p9 + df(f(1),x)*f(1)*p4},"$
 wl2"     {},{},{})$ "$

 wl2"-----------------"$

 wl1"Example for determining symmetries of given PDEs in the"$
 wl1"presence of extra substitution rules which are given"$
 wl1"using `=>' instead of `=' for the equations for which"$
 wl1"matching symmetries are to be found:"$

 wl1"lisp put('f,'prifn,nil)$  % from now on more than one fermion "$
 wl1"lisp put('b,'prifn,nil)$  % from now on more than one boson "$             
 wl1"ssym(1,1,4,{1,1},{1,3,1,3}, "$
 wl1"     {df(f(1),t)=>-2*f(1)*b(1)*p1,  "$
 wl1"      df(b(1),t)=>b(1)**2*p1+d(1,f(1))*p2,  "$
 wl1"      d(1,b(2)) =>-df(b(1),x)*f(1),  "$
 wl1"      df(b(2),t)=>-2*d(1,b(1))*f(1)*b(1)*p1+d(1,df(b(1),t))*f(1)"$
 wl1"                  -d(1,f(1))**2*p2/2-d(1,f(1))*b(1)**2*p1"$
 wl1"                  +d(1,f(1))*df(b(1),t),"$
 wl1"      df(f(2),t)=-2*f(2)*b(1)*p1-2*f(1)*b(3)*p1,  "$
 wl1"      df(b(3),t)=2*b(1)*b(3)*p1+d(1,f(2))*p2,  "$
 wl1"      d(1,b(4))=>-df(b(3),x)*f(1)-df(b(1),x)*f(2),  "$
 wl1"      df(b(4),t)=>-2*d(1,b(3))*f(1)*b(1)*p1-2*d(1,b(1))*f(2)*b(1)*p1"$
 wl1"                  -2*d(1,b(1))*f(1)*b(3)*p1+d(1,df(b(3),t))*f(1) "$
 wl1"                  +d(1,df(b(1),t))*f(2)-d(1,f(1))*d(1,f(2))*p2 "$
 wl1"                  -d(1,f(2))*b(1)**2*p1-2*d(1,f(1))*b(3)*b(1)*p1"$
 wl1"                  +d(1,f(2))*df(b(1),t)+d(1,f(1))*df(b(3),t)},"$
 wl2"     {},{},{});  "$

 wl2"-----------------"$

 wl1"The same example again but now with the flag `lin' to generate a"$
 wl1"symmetry that is linear homogeneous in all fields with an index"$
 wl1"greater than half the maximum index for that type of field. When "$
 wl1"setting the flag 'lin' the number of fermions and boson fields must"$
 wl1"both be even. In the following example that means, the symmetry will"$
 wl2"be linear and homogeneous in f(2),b(3),b(4)."$

 wl1"ssym(1,1,4,{1,1},{1,3,1,3},  "$
 wl1"     {df(f(1),t)=>-2*f(1)*b(1)*p1,  "$
 wl1"      df(b(1),t)=>b(1)**2*p1+d(1,f(1))*p2,  "$
 wl1"      d(1,b(2)) =>-df(b(1),x)*f(1),  "$
 wl1"      df(b(2),t)=>-2*d(1,b(1))*f(1)*b(1)*p1+d(1,df(b(1),t))*f(1)"$
 wl1"                  -d(1,f(1))**2*p2/2-d(1,f(1))*b(1)**2*p1"$
 wl1"                  +d(1,f(1))*df(b(1),t),"$
 wl1"      df(f(2),t)=-2*f(2)*b(1)*p1-2*f(1)*b(3)*p1,  "$
 wl1"      df(b(3),t)=2*b(1)*b(3)*p1+d(1,f(2))*p2,  "$
 wl1"      d(1,b(4)) =>-df(b(3),x)*f(1)-df(b(1),x)*f(2),  "$
 wl1"      df(b(4),t)=>-2*d(1,b(3))*f(1)*b(1)*p1-2*d(1,b(1))*f(2)*b(1)*p1"$
 wl1"                  -2*d(1,b(1))*f(1)*b(3)*p1+d(1,df(b(3),t))*f(1) "$
 wl1"                  +d(1,df(b(1),t))*f(2)-d(1,f(1))*d(1,f(2))*p2"$
 wl1"                  -d(1,f(2))*b(1)**2*p1-2*d(1,f(1))*b(3)*b(1)*p1"$
 wl1"                  +d(1,f(2))*df(b(1),t)+d(1,f(1))*df(b(3),t)},"$
 wl2"     {},{},{lin});  "$

 wl2"-----------------"$

 wl1"If one wants to find for a given system of equations df(..,t)=.. a "$
 wl1"symmetry which satisfies in addition to a symmetry weight sw, a list "$
 wl1"of fermion weights afwlist and list of boson weights abwlist other "$
 wl1"homogeneities, then in the last parameter of the ssym call one adds the "$
 wl1"flag `filter' and has a global variable hom_wei which is a list of "$
 wl1"lists {sw,afwlist,abwlist} each being an additional set of homogeneity"$
 wl2"weights."$
 
 wl2"Example: "$

 wl2"hom_wei:={{10,{3,3},{2,2}}}$"$

 wl1"ssym(1,1,6,{1,1},{1,1},"$
 wl1"     {df(f(1),t)=>-2*f(1)*b(1)*p1,"$
 wl1"      df(b(1),t)=>b(1)*b(1)*p1+d(1,f(1))*p2,"$
 wl1"      df(f(2),t)= - 2*f(2)*b(1)*p1 - 2*f(1)*b(2)*p1,"$
 wl1"      df(b(2),t)=2*b(2)*b(1)*p1 + d(1,f(2))*p2},"$
 wl2"     {},{},{lin,filter});"$

 wl2"-----------------"$

 wl1"After a run of ssym() the substitution rules, like df(f(1),t)=> ..  "$
 wl1"are not active. If one wanted to check symmetries interactively  "$
 wl1"one would have to activate these rules which are stored under the"$
 wl1"name `subli' by:                                    let subli$"$
 wl1"and if one would want to de-activate them then do:  clearrules subli$ "$
 wl2"For example, to check symmetries after the above run one could do  "$

 wl2" let subli$  "$

 wl1" df(b(3),t):=2*b(3)*b(1)*p1 + d(1,f(2))*p2$  "$
 wl2" df(f(2),t):=- 2*f(2)*b(1)*p1 - 2*f(1)*b(3)*p1$  "$

 wl1" b3t:=df(b(3),t)$  "$
 wl2" f2t:=df(f(2),t)$  "$

 wl1" df(b(3),s):=(1/2*d(1,b(3))*f(1)*b(1)**2*p1*p2 + 4/11*d(1,b(1))*f(2)  "$
 wl1"  *b(1)**2*p1*p2 + d(1,b(1))*f(1)*b(3)*b(1)*p1*p2 + 7/22*d(1,f(1))**2 "$
 wl1"  *b(3)*p2**2 + 7/11*d(1,f(1))*b(3)*b(1)**2*p1*p2 + 1/4*d(1,f(1))*  "$
 wl1"  d(1,b(3))*f(1)*p2**2 + 5/44*d(1,f(1))*d(1,b(1))*f(2)*p2**2 + 1/44*  "$
 wl1"  df(b(1),x)*f(2)*f(1)*p2**2 + 1/22*df(f(1),x)*f(2)*b(1)*p2**2  "$
 wl1"  + 5/22*df(f(1),x)*f(1)*b(3)*p2**2)/(p1*p2)$  "$
 wl1" df(f(2),s):=(1/4*d(1,f(2))*d(1,f(1))*f(1)*p2**2 + 1/2*d(1,f(2))  "$
 wl1"  *f(1)*b(1)**2*p1*p2 + 3/44*d(1,f(1))**2*f(2)*p2**2 + 3/22*d(1,f(1)) "$
 wl2"  *f(2)*b(1)**2*p1*p2 + 1/44*df(f(1),x)*f(2)*f(1)*p2**2)/(p1*p2)$  "$ 

 wl1" b3s:=df(b(3),s)$  "$
 wl2" f2s:=df(f(2),s)$  "$

 wl1" write ""ZERO = "",df(b3t,s)-df(b3s,t)$  "$
 wl2" write ""ZERO = "",df(f2t,s)-df(f2s,t)$  "$

 wl2" clearrules subli$ "$
>>$

%-------

symbolic procedure sshelp6$
<<wl2"To compute conservation laws the call is:"$
 
 wl2"  ssconl(N,tw,mincw,maxcw,afwlist,abwlist,pdes)$"$
 
 wl2"where"$
 
 wl1" N       .. the number of superfields theta_i"$
 wl1" tw      .. weight(d_t) = 2 times the differential order of the equation"$
 wl1" mincw   .. min weight of the conservation law"$
 wl1" maxcw   .. max weight of the conservation law"$
 wl1" afwlist .. (algebraic) list of weights of the fermion fields"$
 wl1"            f(1), f(2), ... "$
 wl1" abwlist .. (algebraic) list of weights of the boson fields"$
 wl1"            b(1), b(2), ..."$
 wl1" pdes    .. an algebraic list of the pde(s) for which a conservation"$ 
 wl1"            law is to be found, for example"$
 wl1"            {df(f(1),t)=df(f(1),x)*b(1)*p9,"$
 wl1"             df(b(1),t)=b(1)**3*p3 + d(1,f(1))**2*p2 + "$
 wl2"                        df(b(1),x)*b(1)*p9 + df(f(1),x)*f(1)*p4}$"$

 wl1"The number of elements in afwlist and abwlist "$
 wl1"determines the number of fermion and boson fields. All weights are "$
 wl1"based on weight(x)=2."$
 wl1"Important: All fields must be made dependent on x and t before."$
 wl2"Fermion fields are called f(1),f(2),.. and boson fields b(1),.. ."$

 wl1"If a boson weight is non-positive or a fermion weight is negative"$
 wl1"then the global (algebraic mode) variable max_deg must have a positive"$
 wl1"integer value which is the highest degree of such a field or any of"$
 wl2"its derivatives in any ansatz."$

 wl2"-----------------"$

 wl2"Example for determining conservation laws for a given PDE-system:"$
 
 wl1"ssconl(1,4,10,15,{2},{2},"$
 wl1"       {df(f(1),t)=df(f(1),x)*b(1)*p9,"$
 wl1"        df(b(1),t)=b(1)**3*p3 + d(1,f(1))**2*p2 + df(b(1),x)*b(1)*p9 "$
 wl1"                   + df(f(1),x)*f(1)*p4}"$
 wl2"      );"$
>>$

%-------

symbolic procedure sshelp7$
<<wl1"To compute all possible homogeneities of a list of expressions"$
 wl1"or equations, i.e. to determine for each homogeneity the weight"$
 wl2"of d_t, of fields f(i),b(j) and other constants, the call is:"$

 wl2"  FindSSWeights(N,nf,nb,exli,zerowei,verbose)$"$

 wl2"where"$
 
 wl1" N       .. the number of superfields theta_i"$
 wl1" nf      .. number of fermion fields f(1) .. f(nf)"$
 wl1" nb      .. number of boson   fields b(1) .. b(nb)"$
 wl1" exli    .. list of equations or expressions"$
 wl1" zerowei .. list of constants or other kernels that"$
 wl1"            should have zero weight"$
 wl2" verbose .. =t/nil whether detailed comments shall be made"$

 wl1"Weights are scaled such that weight of d_x is 2, i.e. the weight of"$
 wl2"any D is 1. Input expressions can be in field form or coordinate form."$

 wl1"The program returns a list of homogeneities,"$
 wl1"each homogeneity being a list of"$
 wl1"a list of the weights of f(1),b(2),.. and"$
 wl1"a list of the weights of b(1),b(2),.. and"$
 wl2"a list of the weights of equations/expressions in the input. "$


 wl2"-----------------"$

 wl1"Example for determining all possible weights for a given"$
 wl2"(artificial) system of equations: "$

 wl1"- th(i) denotes superfields theta_i,"$
 wl1"- b's and f's with 3 indices are the coefficients in the"$
 wl1"  Taylor expansions"$
 wl1"  f(i)=f(i,0,0)+b(i,1,0)*th(1)+b(i,0,1)*th(2)+f(i,1,1)*th(1)*th(2)"$
 wl1"- x,t,th(i) may occur not only as differentiation variables"$
 wl1"  but also explicitly polynomially,"$
 wl2"- p3,p5 are supposed to have zero weight."$

 wl1"FindSSWeights(2,2,0,"$
 wl1"              {x*df(b(1,1,0),th(1),t)= d(1,d(2,f(2,0,0)))*p5 - "$
 wl1"                                       df(f(1,1,1)*th(1)*th(2),x,2)*p3,"$
 wl1"               df(f(2),t)=(df(f(2),x,2)*p3*p5 - df(f(1),x,3)*p3**2)/p5},"$
 wl1"              {p3,p5},"$
 wl2"              t)$"$
>>$

%-------

symbolic procedure sshelp8$
<<wl1"To compute a linearization of a system of evolution equations,"$
 wl2"the call is:"$
 
 wl2"  linearize(pdes,nf,nb,tpar,spar)$"$
 
 wl2"where"$
 
 wl1" pdes   .. list of equations with a t-derivative on left hand side"$
 wl1" nf     .. number of fermion fields f(1) .. f(nf)"$
 wl1" nb     .. number of boson   fields b(1) .. b(nb)"$
 wl1" tpar   .. t/nil, whether time variable t changes parity"$
 wl2" spar   .. t/nil, whether symmetry variable s changes parity"$

 wl1" linearize returns {list of relations like df(f(3),s) = f(6),"$
 wl1"                    list of linearized equations}"$
 wl2"Newly introduced fields depend on x,t,s."$

 wl1"A linearization is associated with a symmetry D_s. The linearized"$
 wl1"equation depends on whether s is parity changing or not and furthermore"$
 wl1"if s is parity changing then the sign of the lhs of the equation (or,"$
 wl2"equally of the rhs) depends on whether t is parity changing or not."$

 wl2"-----------------"$

 wl2"An (artificial) example for a linearization:"$
 
 wl1"linearize({df(f(1),t)=df(f(2),x)*b(1)**3*p1 "$
 wl1"                      + d(1,f(2))**5*df(f(1),x,2)*p2,"$
 wl1"           df(f(2),t)=2*d(1,df(b(1),x))*df(f(2),x,2)*df(f(1),x)*p3 "$
 wl1"                      + df(f(1),x,3)*p3**2,"$
 wl2"           d(1,d(2,b(1)))=b(1)*d(1,d(2,f(1)))*f(1) },2,1,nil,nil)$"$
>>$

%-------

symbolic procedure sshelp9$
<<wl1"To make an ansatz for a polynom in a number of fermionic and/or"$
 wl1"bosonic variables, and their x-derivatives and D(i,..) derivatives"$
 wl2"The call is:"$

 wl2"  GenSSPoly(N,wgtlist,cname,mode)$"$

 wl2"where"$

 wl1" N       .. the number of superfields theta_i"$
 wl1" wgtlist .. an algebraic mode list of at least one alg. mode list"$
 wl1"            {afwlist,abwlist,wgt} where"$
 wl1"            afwlist .. (algebraic mode) list of weights of the"$
 wl1"                       fermion fields f(1), f(2), ..."$
 wl1"            abwlist .. (algebraic mode) list of weights of the"$
 wl1"                       boson   fields b(1), b(2), ..."$
 wl1"            wgt     .. the weight of each term in the generated"$
 wl1"                       polynomial according to afwlist and abwlist"$
 wl1"            The number of elements in afwlist, abwlist determines"$    
 wl1"            the number of fermion and boson fields."$
 wl1"            If the generated polynomial should have more than one"$
 wl1"            homogeneity symmetry then each extra one is specified"$
 wl1"            by another element {afwlist,abwlist,wgt} in wgtlist."$
 wl1" cname   .. name of the coefficients which gets added an index"$
 wl1" mode    .. list of flags: "$                                            
 wl1"            lin: the generated polynomial has to be linear homogeneous"$
 wl1"                 in all fields with (index)>(maxindex/2), i.e."$
 wl1"                 if lin then the number of fermions and boson fields"$
 wl1"                 must both be even"$  
 wl1"            fonly: only fermionic terms are generated"$
 wl1"            bonly: only bosonic   terms are generated"$
 wl1"            {forbid,d(1,f(1)),..}: a list of fermionic and bosonic"$
 wl1"                 variables and their derivatives that may not occur"$
% wl1"            {non0coeff,p7,p18,..}: an exclusive list of coefficients"$
% wl2"                 that may occur"$

 wl2"The result is a list"$
 
 wl2"{fermonic_polynomial, bosonic_polynomial, {coefficients}}."$

 wl2"Comments:"$

 wl1"- The weight of d/dx is 2, the weight of d(i,..) is 1, no other"$
 wl2"  derivatives occur."$

 wl1"- If in the first homogeneity, i.e. in the first element of wgtlist"$
 wl1"  a boson weight is non-positive or a fermion weight is negative"$
 wl1"  then the global (algebraic mode) variable max_deg must have a"$
 wl1"  positive integer value which is the highest degree of such a"$
 wl1"  field in any ansatz. Therefore if there is a set of strictly"$
 wl1"  positive homogeneity weights, then they should come first, needing"$
 wl2"  no extra restriction through max_deg which might restrict generality."$
>>$

%-------

symbolic procedure sshelp10$
<<wl1"The N symmetry generators theta_1,..,theta_N are called th(1),..,th(N)"$
 wl1"in SSTools. As they are of odd parity only 2^N many products of their"$
 wl1"powers exist. The name convention used in SSTools for coefficients"$
 wl1"in the Taylor expansion wrt. theta_i becomes apparent in the following"$ 
 wl2"two expansions (here for N=2):"$

 wl1"f(i)=f(i,0,0)+b(i,1,0)*th(1)+b(i,0,1)*th(2)+f(i,1,1)*th(1)*th(2)"$
 wl2"b(i)=b(i,0,0)+f(i,1,0)*th(1)+f(i,0,1)*th(2)+b(i,1,1)*th(1)*th(2)."$

 wl2"The theta expansion of derivatives D(i,P) is"$

 wl2"D(i,P) = df(P,th(i))+th(i)*df(P,x)} ."$

 wl1"These expansions can be used to convert a polynomial expression in"$
 wl1"terms of f(i), b(j), D(k,..) (what we call `field form') into what"$
 wl2"we call `coordinate form'. The call is:"$

 wl2"  tocoo(N,nf,nb,ex)$"$
 
 wl2"where"$
 
 wl1" N      .. the number of superfields th(1) .. th(N)"$
 wl1" nf     .. number of fermion fields f(1) .. f(nf)"$
 wl1" nb     .. number of boson   fields b(1) .. b(nb)"$
 wl2" ex     .. the expression to be converted"$

 wl2"-----------------"$

 wl2"Example: For N=2 and 2 fermion fields the call is"$

 wl1"    hh := tocoo(2,2,0,"$
 wl1"                f(1)*d(1,f(2))+d(2,d(1,DF(f(2),x)))+"$
 wl2"                df(f(2),x,2)*p3*p5 - df(f(1),x,3)*p3**2);"$
>>$

%-------

symbolic procedure sshelp11$
<<wl1"The conversion back from coordinate form to field form is done"$
 wl1"by the function tofield. For this function to be applicable "$
 wl1"the expression in coordinate form has to be homogeneous with "$
 wl1"suitable weights and in the current form only involve x- and "$
 wl2"th(i)-derivatives. The call is:"$

 wl2"  tofield(N,nf,nb,ex,zerowei)$"$

 wl2"where"$
 
 wl1" N       .. the number of superfields theta_i"$
 wl1" nf      .. number of fermion fields f(1) .. f(nf)"$
 wl1" nb      .. number of boson   fields b(1) .. b(nb)"$
 wl1" ex      .. the expression to be converted"$
 wl1" zerowei .. list of constants or other kernels that"$
 wl2"            should have zero weight"$

 wl2"-----------------"$

 wl1"Examples:"$
 wl2"The following call inverts the above computation:"$

 wl2"    tofield(2,2,0,hh,{p3,p5});"$

 wl1"The next call shows what happens when the input does"$
 wl2"not have a homogeneity:"$

 wl2"    tofield(1,1,0,f(1,0)+df(f(1,0),x)+f(1,0)*th(1)*df(f(1,0),x),{});"$

 wl1"In the next call the input has a homogeneity but the resulting"$
 wl1"homogeneity weight for f(1) is negative which does not prevent"$
 wl1"the computation but makes it more expensive but that does not"$
 wl2"matter in the following short example:"$

 wl1"    tofield(1,2,0,f(2,0)*b(1,1) + f(2,0)*th(1)*df(f(1,0),x) + "$
 wl2"                  f(1,0) + th(1)*b(2,1)*b(1,1) + th(1)*b(1,1),{}); "$

 wl1"In the next call the input does have a homogeneity, the resulting"$
 wl2"weight for f(1) is positive but still a field form does not exist:"$

 wl2"    tofield(1,1,0,df(f(1,0),x)+f(1,0)*th(1)*df(f(1,0),x),{});"$
>>$

%-------

symbolic operator sshelp$
symbolic procedure sshelp$
begin scalar ps,s$
 lines_written:=0$
 rds nil; wrs nil$              % Switch I/O to terminal
 ps:=promptstring!*$  promptstring!*:=redfront_color ""$
 repeat <<
  write"To read about the following topics input the corresponding number:"$
  terpri()$ terpri()$
  write"  Purpose                        (1)"$ terpri()$
  write"  Notation                       (2)"$ terpri()$
  write"  Initializations                (3)"$ terpri()$
  write"  Coefficients                   (4)"$ terpri()$
  write"  Symmetries                     (5)"$ terpri()$
  write"  Conservation laws              (6)"$ terpri()$
  write"  Homogeneities                  (7)"$ terpri()$
  write"  Linearizations                 (8)"$ terpri()$
  write"  Generating polynomials         (9)"$ terpri()$
  write"  Taylor expansions             (10)"$ terpri()$
  write"  Inverting Taylor expansions   (11)"$ terpri()$
  write"  Exit help                     (12)"$ terpri()$
  terpri()$
  write"Choice: "$
  s:=read()$
  if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
  if ofl!* then wrs cdr ofl!*$
  wl2"=========================================================="$   
  if s= 1 then sshelp1() else
  if s= 2 then sshelp2() else
  if s= 3 then sshelp3() else
  if s= 4 then sshelp4() else
  if s= 5 then sshelp5() else
  if s= 6 then sshelp6() else
  if s= 7 then sshelp7() else
  if s= 8 then sshelp8() else
  if s= 9 then sshelp9() else
  if s=10 then sshelp10() else
  if s=11 then sshelp11() else
  if s neq 12 then write"Wrong input, try again."$
 >> until s=12$
 promptstring!*:=ps
end$

%-------

lisp <<write"For help type:  sshelp()$  "$terpri()>>$ 

endmodule;

end$


