module compact;  % Header module for compact code.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

create!-package('(compact mv mvmatch reddom compactf comfac),
                '(contrib compact));

% These smacros are used in more than one module.

symbolic smacro procedure mv!-!.!+(u,v); u . v;

symbolic smacro procedure mv!-!.!*(u,v); u . v;

symbolic smacro procedure mv!-lc u; cdar u;

symbolic smacro procedure mv!-lpow u; caar u;

symbolic smacro procedure mv!-lt u; car u;

symbolic smacro procedure mv!-red u; cdr u;

endmodule;


module mv; % Operations on multivariate forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

% These smacros are local to this module.

symbolic smacro procedure mv!-term!-coeff u; cdr u;

symbolic smacro procedure mv!-term!-pow u; car u;

symbolic smacro procedure mv!-tpow u; car u;

symbolic smacro procedure mv!-tc u; cdr u;

symbolic procedure mv!-!+(u,v);
   if null u then v
    else if null v then u
    else if mv!-lpow u= mv!-lpow v
     then (lambda x;
            if x=0 then mv!-!+(mv!-red u,mv!-red v)
             else mv!-!.!+(mv!-!.!*(mv!-lpow u,x),
                           mv!-!+(mv!-red u,mv!-red v)))
          (mv!-lc u + mv!-lc v)
    else if mv!-pow!-!>(mv!-lpow u,mv!-lpow v)
     then mv!-!.!+(mv!-lt u,mv!-!+(mv!-red u,v))
    else mv!-!.!+(mv!-lt v,mv!-!+(u,mv!-red v));

symbolic smacro procedure domain!-!*(u,v); u*v;

symbolic smacro procedure domain!-!/(u,v); u/v;

symbolic procedure mv!-term!-!*(u,v);
   % U is a (non-zero) term and v a multivariate form. Result is
   % product of u and v.
   if null v then nil
    else mv!-!.!+(mv!-!.!*(mv!-pow!-!+(mv!-tpow u,mv!-lpow v),
                           domain!-!*(mv!-tc u,mv!-lc v)),
                  mv!-term!-!*(u,mv!-red v));

symbolic procedure mv!-term!-!/(u,v);
   % Returns the result of the (exact) division of u by term v.
   if null u then nil
    else mv!-!.!+(mv!-!.!*(mv!-pow!-!-(mv!-lpow u,mv!-tpow v),
                           domain!-!/(mv!-lc u,mv!-tc v)),
                  mv!-term!-!/(mv!-red u,v));

symbolic procedure mv!-domainlist u;
   if null u then nil
    else mv!-lc u . mv!-domainlist mv!-red u;

symbolic procedure mv!-pow!-mv!-!+(u,v);
   if null v then nil
    else mv!-!.!+(mv!-pow!-mv!-term!-!+(u,mv!-lt v),
                  mv!-pow!-mv!-!+(u,mv!-red v));

symbolic procedure mv!-pow!-mv!-term!-!+(u,v);
   mv!-!.!*(mv!-pow!-!+(u,mv!-term!-pow v), mv!-term!-coeff v);

symbolic procedure mv!-pow!-!+(u,v);
   if null u then nil
    else (car u+car v) . mv!-pow!-!+(cdr u,cdr v);

symbolic procedure mv!-pow!-!-(u,v);
   if null u then nil
    else (car u-car v) . mv!-pow!-!-(cdr u,cdr v);

symbolic procedure mv!-pow!-!*(u,v);
   if null v then nil
    else (u*car v) . mv!-pow!-!*(u,cdr v);

symbolic procedure mv!-pow!-minusp u;
   if null u then nil
    else car u<0 or mv!-pow!-minusp cdr u;

symbolic procedure mv!-pow!-!>(u,v);
   if null u then nil
    else if car u=car v then mv!-pow!-!>(cdr u,cdr v)
    else car u>car v;

symbolic procedure mv!-reduced!-coeffs u;
   % reduce coefficients of u to lowest terms.
   begin scalar x,y;
      x := mv!-lc u;
      y := mv!-red u;
      while y and x neq 1 do <<x := gcdn(x,mv!-lc y); y := mv!-red y>>;
      return if x=1 then u else mv!-!/(u,x)
   end;

symbolic procedure mv!-!/(u,v);
   if null u then nil
    else mv!-!.!+(mv!-!.!*(mv!-lpow u,mv!-lc u/v),mv!-!/(mv!-red u,v));


% Functions that convert between standard forms and multivariate forms.

symbolic procedure sf2mv(u,varlist);
   % Converts the standard form u to a multivariate form wrt varlist.
   sf2mv1(u,nil,varlist);

symbolic procedure sf2mv1(u,powers,varlist);
   if null u then nil
    else if domainp u
     then list(append(powers,nzeros length varlist) . u)
    else if mvar u = car varlist     % This should be eq, but seems to
                                     % need equal.
     then append(sf2mv1(lc u,append(powers,list ldeg u),cdr varlist),
                 sf2mv1(red u,powers,varlist))
    else sf2mv1(u,append(powers,list 0),cdr varlist);

symbolic procedure nzeros n; if n=0 then nil else 0 . nzeros(n-1);

symbolic procedure mv2sf(u,varlist);
   % converts the multivariate form u to a standard form wrt varlist.
   % This version uses addf to fold terms - there is probably a more
   % direct method.
   if null u then nil
    else addf(mv2sf1(mv!-lpow u,cdar u,varlist),mv2sf(cdr u,varlist));

symbolic procedure mv2sf1(powers,cf,varlist);
   if null powers then cf
    else if car powers=0 then mv2sf1(cdr powers,cf,cdr varlist)
    else !*t2f((car varlist .** car powers)
                 .* mv2sf1(cdr powers,cf,cdr varlist));

endmodule;


module mvmatch;  % Side relation matching against expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All Rights Reserved.

symbolic procedure mv!-compact(u,v,w);
   % Compares a multivariate form u with a multivariate form template v
   % and reduces u appropriately.
   % Previously, the content was removed from u.  However, this does
   % not work well if the same content is in v.
   begin scalar x,y;   % z;
      if null u then return mv!-reverse w;
%     if null w then <<z := mv!-content u; u := mv!-term!-!/(u,z)>>
%      else z := nzeros length mv!-lpow u . 1;
        % check first terms.
      if (x := mv!-pow!-chk(u,v))
          and (y := mv!-compact2(u,mv!-pow!-mv!-!+(x,v)))
%       then return mv!-term!-!*(z,mv!-compact(y,v,w))
        then return mv!-compact(y,v,w)
        % check second terms.
       else if (x := mv!-pow!-chk(u,mv!-red v))
          and not mv!-pow!-assoc(y := mv!-pow!-!+(x,mv!-lpow v),w)
          and (y := mv!-compact2(mv!-!.!+(mv!-!.!*(y,0),u),
                                 mv!-pow!-mv!-!+(x,v)))
%       then return mv!-term!-!*(z,mv!-compact(y,v,w))
%      else return mv!-term!-!*(z,mv!-compact(mv!-red u,v,mv!-lt u . w))
        then return mv!-compact(y,v,w)
       else return mv!-compact(mv!-red u,v,mv!-lt u . w)
   end;

symbolic procedure mv!-pow!-assoc(u,v); assoc(u,v);

symbolic procedure mv!-reverse u; reversip u;

symbolic procedure mv!-pow!-chk(u,v);
%  (u := mv!-pow!-!-(caar u,caar v)) and not mv!-pow!-minusp u and u;
   if v and (u := mv!-pow!-!-(caar u,caar v)) and not mv!-pow!-minusp u
     then u
    else nil;

symbolic procedure mv!-compact2(u,v);
   % U and v are multivariate forms whose first powlists are equal.
   % Value is a suitable multiplier of v which when subtracted from u
   % results in a more compact expression.
   begin scalar x,y,z;
      x := equiv!-coeffs(u,v);
      z := mv!-domainlist v;
      y := reduce(x,z);
      return if y=x then nil
           else mv!-!+(mv!-coeff!-replace(v,mv!-domainlist!-!-(y,x)),u)
   end;

symbolic procedure mv!-coeff!-replace(u,v);
   % Replaces coefficients of multivariate form u by those in domain
   % list v.
   if null u then nil
    else if car v=0 then mv!-coeff!-replace(mv!-red u,cdr v)
    else mv!-!.!+(mv!-!.!*(mv!-lpow u,car v),
                mv!-coeff!-replace(mv!-red u,cdr v));

symbolic procedure equiv!-coeffs(u,v);
   if null u then nzeros length v
    else if null v then nil
    else if mv!-lpow u = mv!-lpow v
     then cdar u . equiv!-coeffs(cdr u,cdr v)
    else if mv!-pow!-!>(mv!-lpow u,mv!-lpow v)
     then equiv!-coeffs(cdr u,v)
    else 0 . equiv!-coeffs(u,cdr v);

endmodule;


module reddom;   % Reduction of domain elements.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

fluid '(mv!-vars!*);

global '(!*xxx !*yyy);

switch xxx,yyy;

!*xxx := !*yyy := t;


% Operations on domain elements.

symbolic smacro procedure domain!-!+(u,v); u+v;

symbolic smacro procedure domain!-!-(u,v); u-v;

symbolic smacro procedure domain!-!*(u,v); u*v;

symbolic smacro procedure domain!-divide(u,v); divide(u,v);


% Operations on domain element lists.

symbolic procedure mv!-domainlist!-!+(u,v);
   if null u then nil
    else domain!-!+(car u,car v) . mv!-domainlist!-!+(cdr u,cdr v);

symbolic procedure mv!-domainlist!-!-(u,v);
   if null u then nil
    else domain!-!-(car u,car v) . mv!-domainlist!-!-(cdr u,cdr v);

symbolic procedure mv!-domainlist!-!*(u,v);
   if null v then nil
    else domain!-!*(u,car v) . mv!-domainlist!-!*(u,cdr v);

% Procedures for actually reducing domain elements.

symbolic procedure reduce(u,v);
   % Reduce domain element list u with respect to an equal length domain
   % element list v.  We assume that v has been reduced to lowest terms.
   begin scalar weightlist,x;
      % Look for equal ratios of elements.
      x := u;
      if !*yyy then
      x := reduce!-ratios(x,v);
      % Define weighting list.
      weightlist := set!-weights v;
      % Choose column elimination with lowest weight.
      if !*xxx then
      x := reduce!-columns(x,v,weightlist);
      % Look for a reduction in weight of the expression.
      if !*xxx then
      x := reduce!-weights(x,v,weightlist);
      return x
   end;

   symbolic procedure set!-weights v;
      % Define weights to be associated with the reduction test.
      % The current definition is pretty naive.
      begin integer n;
%         return reversip for each j in v collect (n := n+1)
          return reversip (0 . for each j in cdr v collect 1)
      end;

   symbolic procedure reduce!-ratios(u,v);
      begin scalar x;
         if null(x := red!-ratios1(u,v)) then return u;
         x := mv!-domainlist!-!-(mv!-domainlist!-!*(car x,u),
                                      mv!-domainlist!-!*(cdr x,v));
         return if zeros u >= zeros x then u
                 else reduce!-ratios(x,v)
      end;

      symbolic procedure zeros u;
         if null u then 0
          else if car u = 0 then 1+zeros cdr u
          else zeros cdr u;

      symbolic procedure red!-ratios1(u,v);
         u and (red!-ratios2(cdr u,cdr v,car u,car v)
                   or red!-ratios1(cdr u,cdr v));

         symbolic procedure red!-ratios2(u,v,u1,v1);
            % The remainder check is needed for the example
            % reduce('(3 0 -3 0 0 0 0),(2 -1 -2 -1 3 -1 1));
            begin integer n;
               return if null u then nil
                       else if (n := u1*car v) = v1*car u and n neq 0
                         and remainder(gcdn(v1,u1),v1)=0
                        then red!-lowest!-terms(v1,u1)
                       else red!-ratios2(cdr u,cdr v,u1,v1)
            end;

            symbolic procedure red!-lowest!-terms(u,v);
               begin scalar x;
                  if u<0 then <<u := -u; v := -v>>;
                  x := gcdn(u,v);
                  % We must have x = u from call in red-ratios2.  If
                  % not, something is awfully wrong.
                  if x neq u then errach list("red-lowest-terms",u,v);
                  return 1 . (v/x)
               end;

symbolic procedure reduce!-columns(u,v,weightlist);
   begin scalar w,x,y,z,z1;
      x := u;
      y := v;
      w := (u . red!-weight(u,weightlist));
   a: if null x then return car w
       else if car x=0 or car y=0 then nil
       else if cdr(z := domain!-divide(car x,car y))=0
        then <<z := mv!-domainlist!-!-(u,mv!-domainlist!-!*(car z,v));
               z1 := red!-weight(z,weightlist);
               if red!-weight!-less!-p(z1,cdr w)
                  and not more!-apartp(z . z1,w)
                 then w := (z . z1)>>;
      x := cdr x;
      y := cdr y;
      go to a
   end;

   symbolic procedure more!-apartp(u,v);
      cadr u=2 and cadr u=cadr v and cadar u=0 and cadar v neq 0;

   symbolic procedure reduce!-weights(u,v,weightlist);
      begin scalar success,x,y,z;
         x := red!-weight(u,weightlist);
      a: y := mv!-domainlist!-!+(u,v);
         z := red!-weight(y,weightlist);
         if red!-weight!-less!-p(z,x)
           then <<success := t; u := y; x := z; go to a>>;
         if success then return u;
      b: y := mv!-domainlist!-!-(u,v);
         z := red!-weight(y,weightlist);
         if red!-weight!-less!-p(z,x) then <<u := y; x := z; go to b>>;
         return u
      end;

      symbolic procedure red!-weight(u,weightlist);
         nonzero!-length u . red!-weight1(u,weightlist);

         symbolic procedure red!-weight1(u,weightlist);
            if null u then 0
             else abs car u*car weightlist
                     + red!-weight1(cdr u,cdr weightlist);

         symbolic procedure nonzero!-length u;
            if null u then 0
             else if car u=0 then nonzero!-length cdr u
             else add1 nonzero!-length cdr u;

      symbolic procedure red!-weight!-less!-p(u,v);
         if car u=car v then cdr u<cdr v else car u<car v;

endmodule;


module compactf; % Algorithms for compacting algebraic expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All Rights Reserved.

fluid '(mv!-vars!*);

global '(!*trcompact);

switch trcompact;

% Interface to REDUCE simplifier.

put('compact,'simpfn,'simpcompact);

symbolic procedure simpcompact u;
   begin scalar bool;
      if null u or null cdr u
       then rerror(compact,1,
                   list("Wrong number of arguments to compact"));
      if null !*exp then <<rmsubs(); bool := !*exp := t>>;
      u := errorset!*(list('simpcompact1,mkquote u),nil);
      if bool then !*exp := nil;
      if errorp u then rerror(compact,2,"Compact error");
      return car u
   end;

symbolic procedure simpcompact1 u;
   begin scalar v,x;
      v := simp!* car u;
      u := cadr u;
      if idp u
        then if eqcar(x := get(u,'avalue),'list)
               then u := cadr x
              else typerr(u,"list")
       else if getrtype u eq 'list then u := cdr u
       else typerr(u,"list");
      u := for each j in u collect if not eqcar(j,'equal) then j
                                    else !*eqn2a j;
      for each j in u do v := compactsq(v,simp!* j);
      return v
   end;

% True beginning of compacting routines.

symbolic procedure compactsq(u,v);
   % U is a standard quotient, v a standard quotient for equation v=0.
   % Result is a standard quotient for u reduced wrt v=0.
   begin
      if denr v neq 1
        then msgpri("Relation denominator",prepf denr v,"discarded",
                    nil,nil);
      v := numr v;
      return multsq(compactf(numr u,v) ./ 1,
                    1 ./ compactf(denr u,v))
   end;

symbolic procedure compactf(u,v);
   % U is a standard form, v a standard form for an equation v=0.
   % Result is a standard form for u reduced wrt v=0.
   begin scalar x; integer n;
      if !*trcompact
       then <<prin2t "*** Arguments on entering compactf:";
              mathprint mk!*sq !*f2q u;
              mathprint mk!*sq !*f2q v>>;
      while x neq u do <<x := u; u := compactf1(u,v); n := n+1>>;
      if !*trcompact and n>2
        then <<prin2 " *** Compactf looped ";prin2 n; prin2t " times">>;
      return u
   end;

symbolic procedure compactf1(u,v);
   begin scalar x,y,z;
      x := kernels u;
      y := kernels v;
      z := intersection(x,y);                 % find common vars.
      if null z then return u;
%  Unfortunately, it's too expensive in space to generate all perms.
%  as in this example:
%       l:={-c31*c21+c32*c22+c33*c23+c34*c24=t1};
%       x:= -c31*c21+c32*c22+c33*c23+c34*c24;
%       compact(x,l);     % out of heap space
%     for each j in permutations z do u := compactf11(u,v,x,y,j);
      return compactf11(u,v,x,y,z)
%     return u
   end;

symbolic procedure compactf11(u,v,x,y,z);
   begin scalar w;
      if domainp u then return u;
      y := append(z,setdiff(y,z));            % vars in eqn.
      x := append(setdiff(x,z),y);            % all vars.
      x := setkorder x;
      u := reorder u;                         % reorder expressions.
      v := reorder v;
      z := comfac!-to!-poly comfac u;
      u := quotf(u,z);
      u := remchkf(u,v,y);
      w := compactf2(u,mv!-reduced!-coeffs sf2mv(v,y),y);
      if termsf w < termsf u then u := w;
      % Should we also reduce z at this point?
      u := multf(z,u);
      % It is possible that if z is not a kernel product, that including
      % z in the reduction can lead to a more compact form, but we
      % exclude that case for the time being.
      setkorder x;
      u := reorder u;
      if !*trcompact
       then <<prin2t "*** Value on leaving compactf11:";
              mathprint mk!*sq !*f2q u>>;
      return u
   end;

symbolic procedure remchkf(u,v,vars);
   % This procedure returns u after checking if a smaller remainder
   % results after division by v.  It is potentially inefficient, since
   % we check all the way down the list, term by term.  However, the
   % process terminates when we no longer have any relevant kernels.
   (if domainp x or null intersection(kernels u,vars) then x
     else lt x .+ remchkf(red x,v,vars))
   where x=remchkf1(u,v);

symbolic procedure remchkf1(u,v);
   begin integer n;
      n := termsf u;
      v := xremf(u,v,n);
      if null v or termsf(v := car v)>=n then return u
       else if !*trcompact then prin2t "*** Remainder smaller";
      return v
   end;

symbolic procedure xremf(u,v,m);
   % Returns the quotient and remainder of U divided by V, or NIL if
   % the number of terms in the remainder exceeds M.
   % The goal is to keep terms u+terms z<=m.
   % There is some slop in the count, so one must check sizes on
   % leaving.
   begin integer m1,m2,n; scalar x,y,z;
        if domainp v then return list cdr qremd(u,v);
        m2 := termsf u;
    a:  if m<= 0 then return nil
         else if domainp u then return list addf(z,u)
         else if mvar u eq mvar v
          then if (n := ldeg u-ldeg v)<0 then return list addf(z,u)
                else <<x := qremf(lc u,lc v);
                y := multpf(lpow u,cdr x);
                m := m+m1;
                z := addf(z,y);
                m1 := termsf z;
                m := m-m1+m2;
                u := if null car x then red u
                        else addf(addf(u,multf(if n=0 then v
                                        else multpf(mvar u .** n,v),
                                        negf car x)), negf y);
                m2 := termsf u;
                m := m-m2;
                go to a>>
         else if not ordop(mvar u,mvar v) then return list addf(z,u);
        m := m+m1;
        x := xremf(lc u,v,m);
        if null x then return nil;
        z := addf(z,multpf(lpow u,car x));
        m1 := termsf z;
        m := m-m1;
        u := red u;
        go to a
   end;

symbolic procedure compactf2(u,v,vars);
  % U is standard form for expression, v for equation. W is ordered
  % list of variables in v. Result is a compacted form for u.
    if domainp u then u
     else if mvar u memq vars then compactf3(u,v,vars)
     else lpow u .* compactf2(lc u,v,vars) .+ compactf2(red u,v,vars);

symbolic procedure compactf3(u,v,vars);
   begin scalar mv!-vars!*;
      mv!-vars!* := vars;
      return mv2sf(mv!-compact(sf2mv(u,vars),v,nil),vars)
   end;

endmodule;


module comfac;   % Multivariate common factor/content routines.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

symbolic smacro procedure domain!-gcd(u,v); gcdn(u,v);

symbolic smacro procedure domain!-onep u; onep u;

symbolic procedure mv!-pow!-zerop u;
   null u or zerop car u and mv!-pow!-zerop cdr u;

symbolic procedure mv!-pow!-gcd(u,v);
   if null u then nil
    else min(car u,car v) . mv!-pow!-gcd(cdr u,cdr v);

symbolic procedure mv!-content u;
   % Finds the term that is the content of u.
      if null u then nil
       else begin scalar x,y;
         x := mv!-lc u;
         y := mv!-lpow u;
      a: u := mv!-red u;
         if null u or domain!-onep x and mv!-pow!-zerop y
           then return mv!-!.!*(y,x);
         x := domain!-gcd(x,mv!-lc u);
         y := mv!-pow!-gcd(y,mv!-lpow u);
         go to a
       end;

endmodule;


end;
