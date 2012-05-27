module exptsimp;

% Author: Rainer M. Schoepf, Jan 92.

comment basic principle of this module: replace all surds and certain
        exponentials by variables, add the polynomials defining this
        variables in terms of the surds or exponentials, and compute
        the Groebner basis of the resulting polynomial system.
        Resubstitution of the exponentials for the variables gives the
        (hopefully) simplified expression;

load!-package 'groebner;

fluid '(!*trexptsimp);

switch trexptsimp;

comment factorize!-expt tries to factorize the exponential
        u = (expt base exponent) 
        by trying to factorize base.
        It returns nil if unsuccessful;

symbolic procedure factorize!-expt u;
  factorize!-expt1 (cadr u, simp caddr u);  

symbolic procedure factorize!-expt1 (u,n);
  % u is the basis of a expt expression
  % n the exponent
  begin scalar x,y,z,q; integer m;
    x := simp u;
    m := numr n;
    if not (m=1) then return nil; % not a surd
    y := fctrf numr x;
    if not atom denr x then z := fctrf denr x;
    q := car y ./ if null z then 1 else car z;
    y := cdr y;
    if not null z then z := cdr z;
    if length y <= 1 and length z <= 1 then return nil;
    y := for each f in y collect
           prepsq simpexpt1 (prepf car f, cdr f ./ denr n, nil);
    y := retimes (prepsq exptsq (mkrootsq (prepsq q, denr n), m) . y);
    if null z then return y;
    z := retimes for each f in z collect
               prepsq simpexpt1 (prepf car f, cdr f ./ denr n, nil);
    return {'quotient, y, z}
  end;

symbolic procedure expr!-sort u;
  % u is a list of expts, result is sorted list of expts
  sort(u, function expr!-order!-p);

symbolic procedure is!-rational!-exponent u;
  eqcar (u, 'quotient) and fixp cadr u and fixp caddr u
   or eqcar ('!:rn!:, u);

symbolic procedure expr!-order!-p (u, v);
  %
  % order function for exponentials
  %  for different base it just returns the standard REDUCE order,
  %  otherwise it orders according to exponent
  %
  if not (cadr u = cadr v) or
     not is!-rational!-exponent caddr u or
     not is!-rational!-exponent caddr v
    then ordp (u, v)
   else begin integer n1,n2,d1,d2;
     u := caddr u; v := caddr v;
     if eqcar (u, 'quotient)
       then << n1 := cadr u; d1 := caddr u >>
      else << n1 := cadr u; d1 := cddr u >>;
     if eqcar (v, 'quotient)
       then << n2 := cadr v; d2 := caddr v >>
      else << n2 := cadr v; d2 := cddr v >>;
     return if d1 = d2 then n1 < n2 else d1 < d2
     end;

fluid '(!*exptsimp!*sublis!* !*exptsimp!*bcksub!* !*exptsimp!*krnls!*);

symbolic smacro procedure newkernel (k);
  begin scalar g;
    g := gensym ();
    %
    % !*exptsimp!*sublis!* is list of substitutions
    % !*exptsimp!*bcksub!* is list of back subst.
    %
    !*exptsimp!*sublis!* := (k . g) . !*exptsimp!*sublis!*;
    !*exptsimp!*bcksub!* := (g . k) . !*exptsimp!*bcksub!*;
    !*exptsimp!*krnls!* := k . !*exptsimp!*krnls!*;
    if !*trexptsimp then <<
      writepri ("Generated kernel: ", 'first);
      writepri (mkquote {'equal, k, g}, 'last);
      >>;
    return g
  end;

symbolic procedure generate!-root!-rels u;
  %
  % u is a list of expts
  %
  begin scalar l,l1,sl,z1,z2;
    u := expr!-sort u;
    for each x in u do
      if null l1 or cadr x = cadr car l1
        then l1 := x . l1
       else << l := reversip l1 . l; l1 := list x >>;
    if not null l1 then l := reversip l1 . l;
    l := reversip l;
    for each ss in l do
      for each x on ss do
        for each y in cdr x do begin scalar z1,z2,kgv,k,pp;
                                     integer denom1, denom2, dd;
          z1 := caddr car x; z2 := caddr y;
          if is!-rational!-exponent z1
            then if is!-rational!-exponent z2
              then <<
                denom1 := if eqcar (z1, 'quotient) then caddr z1
                           else cddr z1;
                denom2 := if eqcar (z2, 'quotient) then caddr z2
                           else cddr z2;
                dd := gcdn(denom1,denom2);
                kgv := denom1 * denom2 / dd;
                if not (dd = 1) then <<
                  denom1 := denom1 / dd;
                  denom2 := denom2 / dd;
                  >>;
                k := prepsq simp!* {'expt, cadr car x,
                                    prepsq simp!* {'quotient, 1, kgv}};
                pp := assoc (k, !*exptsimp!*sublis!*);
                if null pp then newkernel k
                 else k := cdr pp;
                sl := {'difference, {'expt, k, denom2},
                       car assoc (car x, !*exptsimp!*sublis!*)} .
                      {'difference, {'expt, k, denom1},
                       car assoc (y, !*exptsimp!*sublis!*)}
                      . sl;
                >>
              else nil
           %%
           %% in the following else part we treat the case of
           %% exponentials of the same base whose exponents are
           %% a rational multiple of each other
           %%
           else if not is!-rational!-exponent z2
              then begin scalar q,k,pp; integer com;
                q := prepsq simp!* {'quotient, z1, z2};
                if not is!-rational!-exponent q then return;
                z1 := cadr q;
                z2 := if eqcar (q, 'quotient) then caddr q else cddr q;
                com := z1 * z2;
                k := prepsq simp!* {'expt, cadr car x,
                           prepsq simp!* {'quotient, caddr car x, z1}};
                pp := assoc (k, !*exptsimp!*sublis!*);
                if null pp then newkernel k
                 else k := cdr pp;
                sl := {'difference, {'expt, k, z1},
                       car assoc (car x, !*exptsimp!*sublis!*)} .
                      {'difference, {'expt, k, z2},
                       car assoc (y, !*exptsimp!*sublis!*)}
                      . sl;
                end;
      end;
    return sl
  end;

comment This is like kernels, but it descends possible
        factored expressions to find kernels contained therein;

symbolic procedure my!-kernels sf;
  begin scalar x,bool;
      x := kernels sf;
    while not bool do begin scalar y;
      bool := t;
      x := for each k in x join
             if not sfp k then list k
              else << y := union (y, kernels k); bool := nil >>;
      x := union (x, y);
      end;
    return x
  end;

comment The function that does the work;
        

symbolic procedure try!-expt!-simp sq;
  begin scalar topg,g,glis,p,sl,l,nl,u,w,w2,w3,notfound,f,
               !*exptsimp!*krnls!*,!*exptsimp!*sublis!*,
               !*exptsimp!*bcksub!*;
    topg := gensym ();
    p := addf (multf (denr sq, !*k2f topg), negf numr sq);
    if !*trexptsimp then <<
      writepri ("Start of expt simplification process...", 'only);
      writepri ("Expression to be simplified is: ", 'first);
      writepri (mkquote mk!*sq sq, 'last);
      writepri ("Generated polynomial is: ", 'first);
      writepri (mkquote prepf p, 'last);
      writepri ("with new variable: ", 'first);
      writepri (mkquote topg, 'last);
      >>;
    while null notfound do <<
      !*exptsimp!*krnls!* := my!-kernels p;
      for each k in !*exptsimp!*krnls!* do if eqcar (k, 'expt)
       then begin scalar k1;
        if !*trexptsimp then <<
          writepri ("Factorization attempted for kernel: ", 'first);
          writepri (mkquote k, 'last);
        >>;
        k1 := factorize!-expt k;
        if null k1 then <<
          if !*trexptsimp then writepri ("Not successful.", 'only);
          >>
         else << if not assoc (k, f) then f := (k . k1) . f;
                 if !*trexptsimp then <<
                   writepri ("Result is: ", 'first);
                   writepri (mkquote {'equal, k, k1}, 'last);
                 >>
           >>
        end;
      for each poly in sl do
        !*exptsimp!*krnls!* :=
             union (!*exptsimp!*krnls!*, my!-kernels poly);
      notfound := t;
      for each x in !*exptsimp!*krnls!* do
        if eqcar (x, 'expt) then
          << if not member (x, l) then begin scalar krnl, expo;
                                             integer denom;
                    l := x . l;
                    notfound := nil;
                    g := newkernel x;   % enter x in list 
                    expo := caddr x;
                    if is!-rational!-exponent expo then <<
                      denom := if eqcar (expo, 'quotient)
                                 then caddr expo
                                else cddr expo;
                      krnl := simp!* {'difference, cadr x,
                                      {'expt, g, denom}};
                      >>
                     else krnl := simp!* {'difference, x, g};
                    sl := numr krnl . sl;
                    if !*trexptsimp then <<
                      writepri ("Generating the relation: ", 'first);
                      writepri (mkquote prepf car sl, 'last);
                      >>;
                    end
               else if not member (x, nl) then nl := x . nl;
           >>;
      if f then <<
        p := numr subf1 (p, f);
        sl := for each poly in sl collect numr subf1 (poly, f);
        if !*trexptsimp then <<
          writepri ("Application of factorization results:", 'only);
          writepri (mkquote prepf p, 'only);
          for each poly in sl do writepri (mkquote prepf poly, 'only);
          >>;
        >>;
      p := numr subf1 (p, !*exptsimp!*sublis!*);
      sl := for each poly in sl collect
              numr subf1 (poly, !*exptsimp!*sublis!*);
      if !*trexptsimp then <<
        writepri ("Application of substitution with list: ", 'only);
        for each pp in !*exptsimp!*sublis!* do
          writepri (mkquote {'equal, car pp, cdr pp}, 'only);
        writepri ("Results are:", 'only);
        writepri (mkquote prepf p, 'only);
        for each poly in sl do writepri (mkquote prepf poly, 'only);
        >>;
      >>;
    u := generate!-root!-rels l;
    if !*trexptsimp then <<
      if not null u then writepri ("Generated extra relations:", 'only);
      for each el in u do writepri (mkquote {'equal, el, 0}, 'only) ;
      >>;
    u := for each el in u collect
           prepf numr subsq (simp el, !*exptsimp!*sublis!*);
    if not !*complex and 'i memq !*exptsimp!*krnls!*
      then u := '(plus (expt i 2) 1) . u;
    glis := for each el in !*exptsimp!*bcksub!* collect car el;
    w := prepf p . append (u, for each poly in sl collect prepf poly);
    glis := reversip glis;
    if !*trexptsimp then <<
      writepri ("List of polynomials for Groebner calculation:", 'only);
      for each el in w do writepri (mkquote el, 'only);
      writepri ("with variable list: ", 'first);
      writepri (mkquote ('list . topg . append (glis, nl)), 'last);
      >>;
    w := groebnereval {'list . w,
                       'list . topg . append (glis, nl)};
    w2 := cdr coeff1 (cadr w, topg, nil);
    w3 := negsq quotsq (simp!* car w2, simp!* cadr w2);
    if !*trexptsimp then <<
      writepri ("Final result is: ", 'first);
      writepri (mkquote mk!*sq w3, 'last);
      >>;
    return subsq (w3, !*exptsimp!*bcksub!*)
  end;

comment driver function: simplifies, calls our code and returns;

symbolic procedure exptsimp u;
  mk!*sq try!-expt!-simp simp!* u;

flag ('(exptsimp), 'opfn);

endmodule;

end;
