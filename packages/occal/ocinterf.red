module ocinterf;

% Author: Rainer Schöpf 

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


fluid '(!*oc!-dynamic!-variables!*
        !*oc!-control!-variables!*
        !*oc!-abbreviations!*
        !*oc!-adjoint!-variables!*
        !*oc!-adjoint!-equations!*
        !*oc!-hamiltonian!*
        !*oc!-linear!-part!*
        !*oc!-nonlinear!-part!*
        !*oc!-time!-variable!*
        !*oc!-boundaries!*
        !*oc!-boundary!-conditions!*
        !*oc!-dgls!*
        !*oc!-constants!*
        !*oc!-parameters!*
        !*oc!-functional!*
        !*oc!-name!*
        !*oc!-title!*
        !*oc!-is!-free!*
        !*oc!-relations!*
        !*oc!-tempvar!-prefix!*
        !*oc!-target!-lang!*
        !*oc!-mulcon!-param!*
        !*oc!-mulcon!-param!-left!*
        !*oc!-mulcon!-param!-right!*
        !*oc!-mulcon!-param!-start!*
        !*oc!-msh!-pts!*
        !*oc!-msh!-values!*
        !*oc!-no!-left!-bcs!*
        !*oc!-no!-right!-bcs!*
        !*oc!-left!-lms!*
        !*oc!-right!-lms!*
        !*oc!-adjoint!-left!-bcs!*
        !*oc!-adjoint!-right!-bcs!*
        !*oc_trace
       );

global '(gentranlang!*);


symbolic procedure do!-oc!-cnst (name, value);
   if evalgreaterp (value,0) then reval {'sign_assert, name, +1}
    else if evallessp (value, 0) then reval {'sign_assert, name, -1}
    else if not (value=0)
     then rederr {"cannot determine sign of", value};


symbolic procedure compute!-hamiltonian ();
  begin scalar u,v,w;
    w := simp!* !*oc!-functional!*;
    u := !*oc!-adjoint!-variables!*;
    v := !*oc!-dgls!*;
   loop:
    w := addsq (w, multsq (simp!* car u, simp!* cdr car v));
    u := cdr u;
    v := cdr v;
    if null u then return w else goto loop
  end;



symbolic procedure separate!-linear!-part ();
  begin scalar lin, nonlin, r;
    for each el in !*oc!-control!-variables!* do <<
      r := cdr coeff1 (mk!*sq !*oc!-hamiltonian!*, el, nil);
      if length r <= 2 and r freeof el
        then lin := el . lin
       else nonlin := el . nonlin >>;
    !*oc!-linear!-part!* := lin;
    !*oc!-nonlinear!-part!* := nonlin;
    return
  end;

algebraic operator oclm;

symbolic procedure assert!-param!-sign;
   if evalgreaterp (!*oc!-mulcon!-param!-left!*, 0) and
      evalgreaterp (!*oc!-mulcon!-param!-right!*, 0) and
      evalgreaterp (!*oc!-mulcon!-param!-start!*, 0)
     then reval {'sign_assert, !*oc!-mulcon!-param!*, +1}
    else if evallessp (!*oc!-mulcon!-param!-left!*, 0) and
            evallessp (!*oc!-mulcon!-param!-right!*, 0) and
            evallessp (!*oc!-mulcon!-param!-start!*, 0)
     then reval {'sign_assert, !*oc!-mulcon!-param!*, -1};

fluid '(varnum);

symbolic procedure number!-variable v;
   <<put(v, 'varnum, varnum); varnum := varnum + 1>>;

symbolic procedure number!-dvars;
   for each el in !*oc!-dynamic!-variables!* do number!-variable el;

symbolic procedure generate!-adjoint!-variables;
   !*oc!-adjoint!-variables!* :=
     for each el in !*oc!-dynamic!-variables!* collect <<
       el := mkid ('lamb_, el);
       mkop el;
       number!-variable el;
       el>>;

COMMENT Depending on its argument, register!-dependencies establishes
        or removes dependency of the dynamic, control and adjoint
        variables on the time variable;

symbolic procedure register!-dependencies flg;
   <<for each el in !*oc!-dynamic!-variables!* do
       depend1 (el, !*oc!-time!-variable!*, flg);
     for each el in !*oc!-control!-variables!* do
       depend1 (el, !*oc!-time!-variable!*, flg);
     for each el in !*oc!-adjoint!-variables!* do
       depend1 (el, !*oc!-time!-variable!*, flg)>>;

symbolic procedure generate!-adjoint!-equations;
   !*oc!-adjoint!-equations!* :=
     for each el in !*oc!-dynamic!-variables!* collect
       negsq diffsq(!*oc!-hamiltonian!*,el);


symbolic smacro procedure print!-eqn(l,r);
   writepri(mkquote {'equal,l,r},'only);

symbolic smacro procedure print!-dgl(dvar,tvar,fn);
   writepri(mkquote {'equal,{'df,dvar,tvar},fn}, 'only);


symbolic procedure print!-adjoint!-equations;
   for i := 1 : length !*oc!-adjoint!-equations!* do
     print!-dgl(nth(!*oc!-adjoint!-variables!*, i),
                !*oc!-time!-variable!*,
                prepsq!* nth(!*oc!-adjoint!-equations!*, i));

symbolic procedure make!-df(var);
   !*a2k {'df,var,!*oc!-time!-variable!*};

symbolic procedure substitute!-in!-dgls l;
   append(for each dgl in !*oc!-dgls!* collect
            make!-df car dgl . subsq (simp!* cdr dgl,l),
          for i := 1 : length !*oc!-adjoint!-equations!* collect
            make!-df nth(!*oc!-adjoint!-variables!*,i)
            . subsq(nth(!*oc!-adjoint!-equations!*,i),l));

symbolic procedure do_calculation();
  begin scalar x, dm, sx, dm1, ss, h1, fns, bc, swfs, !*int;
        integer varnum, count;
%    on rounded,double;
    rmsubs();    %% clear all internal information!
    varnum := 1;
    gentranlang!* := !*oc!-target!-lang!* or 'c;

    (let ('list . !*oc!-abbreviations!*)) where !*int := nil;

    for each el in !*oc!-constants!* do
      do!-oc!-cnst (car el, reval cdr el);

    assert!-param!-sign();

    number!-dvars();

    generate!-adjoint!-variables();

    register!-dependencies(t);
      
    !*oc!-hamiltonian!* := compute!-hamiltonian ();
    tracewritenl "Computed Hamiltonian is:";
    tracewritenl "========================";
    tracemathpri prepsq!* !*oc!-hamiltonian!*;

    generate!-adjoint!-equations();

    if !*oc_trace then << write "Adjoint equations:";
                          print!-adjoint!-equations()>>;

    separate!-linear!-part ();

    if !*oc_trace then <<
      if null !*oc!-linear!-part!* then writepri("No linear part.", 'only)
       else <<writepri ("Linear part: ", 'first);
              for each k in !*oc!-linear!-part!* do <<
                writepri (mkquote k, nil);
                writepri (" ", nil)>>;
              writepri ("", 'last)>>;
      if null !*oc!-nonlinear!-part!* then writepri("No nonlinear part.", 'only)
       else <<writepri ("Nonlinear part: ", 'first);
              for each k in !*oc!-nonlinear!-part!* do <<
                writepri (mkquote k, nil);
                writepri (" ", nil)>>;
              writepri ("", 'last)>>>>;

    (if not null !*oc!-nonlinear!-part!* then <<
      x := for each el in !*oc!-nonlinear!-part!* collect
             numr diffsq (!*oc!-hamiltonian!*, el);
      dm := detq for each el1 in !*oc!-nonlinear!-part!* collect
                    for each el2 in x collect difff (el2, el1);
      if !*oc_trace then <<
        writepri ("Equations for nonlinear part:", 'only);
        for each el in x do print!-eqn(prepf el,0)>>;
      sx := my!-solve!-nn x;
      for each el in sx do begin scalar x,!*intstr; integer multipl;
        !*intstr := t;
        multipl := caddr el;
        x := pair (cadr el, for each el2 in car el collect mk!*sq el2);
        dm1 := mk!*sq subsq (dm, x);
        if !*oc_trace then <<
          writepri ("Solution #", 'first);
          writepri (mkquote count, nil);
          writepri (":", 'last);
          for each el2 in x do
            print!-eqn(car el2,cdr el2);
            writepri ("Determinant: ", 'first);
            writepri (mkquote dm1, 'last)
            >>;
        begin scalar !*factor,!*exp,!*gcd;
          !*factor := t; !*gcd := t;
          ss := sign_eval1 (prepsq!* simp!* dm1, !*int);
        end;
        if ss eq 'unknown then rederr "Unable to determine sign!"
         else if ss = +1 then <<
          count := count + 1;
           h1 := subsq (!*oc!-hamiltonian!*, x);
           fns := substitute!-in!-dgls x;
           bc := for each el in !*oc!-boundary!-conditions!* collect
                   subsq (simp!* el, x);
           
           if !*oc_trace then <<
             writepri ("Hamiltonian after substitution: ", 'first);
             writepri (mkquote mk!*sq h1, 'last);
             writepri ("DGLs after substitution: ", 'first);
             for each el in fns do
               writepri (mkquote {'setq,
                                  {'df, car el, !*oc!-time!-variable!*},
                                  mk!*sq cdr el}, 'only);
             writepri ("BCs after substitution: ", 'first);
             for each el in bc do print!-eqn(mk!*sq el,0)>>;
           analyze!-boundary!-conditions (bc);
           generate!-program (count, bc, h1, fns, nil);
           >>
      end  >>
    else if not null !*oc!-linear!-part!* then begin integer ndgls,nadj;
        ndgls := length !*oc!-dgls!*;
        nadj := length !*oc!-adjoint!-equations!*;
        bc := for each el in !*oc!-boundary!-conditions!* collect
                simp!* el;
        analyze!-boundary!-conditions (bc);
        swfs := handle!-linear!-part ();
        generate!-program (1,
                           for each el in !*oc!-boundary!-conditions!*
                             collect simp!* el,
                           !*oc!-hamiltonian!*,
                           append (for each dgl in !*oc!-dgls!* collect
                              make!-df car dgl . simp!* cdr dgl,
                           for i := 1 : nadj collect
                              make!-df nth (!*oc!-adjoint!-variables!*, i) .
                                   nth (!*oc!-adjoint!-equations!*, i)),
                           swfs)
       end ) where sign!-db!* := sign!-db!*;

    register!-dependencies(nil);

    clear ('list . !*oc!-abbreviations!*);

    terpri ();
    prin2t "==========================================================";
    prin2t " That's all, folks!";
    prin2t "==========================================================";
    terpri ()
  end;

flag ('(do_calculation), 'opfn);


symbolic procedure my!-solve!-nn gls;
  begin scalar u, v, w, y, z, nns;
    nns := !*oc!-nonlinear!-part!*;
    for each gl in gls do
      for each k in kernels gl do
        if not(k member y) then y := k . y;
    % y is now list of all kernels in all equ. gls
    for each k in y do
      if dependsl (k, nns) then u := k . u;
    % u is now list of all kernels in gls that contain a variable
    for each el in nns do
      if el member u then <<
        for each k in u do if not (k freeof el) then z := k . z;
        for each k in z do u := delete (k, u)
      >>;
    for each el in u do if not atom el then <<
      y := cdr el;
      w := nil;
      for each k in y do
        for each k1 in kernels !*a2f k do
          if not(k1 member w) then w := k1 . w;
      if length w > 1 then v := el . v
      >>;
    for each el in v do u := delete (el, u);
    w := nil;
    for each el in nns do
      for each k in u do
        if not(k freeof el) then
          if not(el member w) then w := el . w;
    for each k in w do nns := delete (k, nns);
    nns := append (nns, u);
    if !*oc_trace then <<
      prin2t "Variables after change of variables:";
      for each el in nns do <<
        writepri (mkquote el, nil); writepri (" ", nil);
        >>;
      writepri ("", 'last);
      terpri ()
      >>;
    return solve0 ('list . for each el in gls collect prepf el,
                   'list . nns)
  end;

symbolic procedure analyze!-boundary!-conditions (bc);
  begin scalar x;
     !*oc!-left!-bcs!* := nil;
     !*oc!-right!-bcs!* := nil;
     tracepri ("Analyzing boundary conditions...", 'only);
     for each el in bc do
       if dependsl (el, for each x in !*oc!-dynamic!-variables!* collect
                          {x, car !*oc!-boundaries!*}) or
          dependsl (el, for each x in !*oc!-adjoint!-variables!* collect
                          {x, car !*oc!-boundaries!*})
         then !*oc!-left!-bcs!* := el . !*oc!-left!-bcs!*
        else if dependsl (el, for each x in !*oc!-dynamic!-variables!*
                                collect {x, cadr !*oc!-boundaries!*}) or
                dependsl (el, for each x in !*oc!-adjoint!-variables!*
                                collect {x, cadr !*oc!-boundaries!*})
         then !*oc!-right!-bcs!* := el . !*oc!-right!-bcs!*
        else rederr {"invalid boundary condition", prepsq el};

     !*oc!-no!-left!-bcs!* := length !*oc!-left!-bcs!*;
     !*oc!-no!-right!-bcs!* := length !*oc!-right!-bcs!*;

     !*oc!-left!-lms!* := for i := 1 : !*oc!-no!-left!-bcs!* collect
                            !*a2k {'oclm, 1, i};
     !*oc!-right!-lms!* := for i := 1 : !*oc!-no!-right!-bcs!* collect
                             !*a2k {'oclm, 2, i};

     x := nil ./ 1;
     for i := 1 : !*oc!-no!-left!-bcs!* do
       x := addsq (x, multsq (nth (!*oc!-left!-bcs!*, i),
                              simp!* nth (!*oc!-left!-lms!*, i)));

     !*oc!-adjoint!-left!-bcs!* := 
       for each el2 in !*oc!-dynamic!-variables!* collect
         addsq (simp!* {mkid ('lamb_, el2), car !*oc!-boundaries!*},
                diffsq (x, !*a2k {el2, car !*oc!-boundaries!*}));

     x := simp!* !*oc!-functional!*;
       for i := 1 : !*oc!-no!-right!-bcs!* do
     x := addsq (x, multsq (nth (!*oc!-right!-bcs!*, i),
                            simp!* nth (!*oc!-right!-lms!*, i)));

     !*oc!-adjoint!-right!-bcs!* := 
       for each el2 in !*oc!-dynamic!-variables!* collect
         addsq (simp!* {mkid ('lamb_, el2), cadr !*oc!-boundaries!*},
                negsq diffsq (x, !*a2k {el2, cadr !*oc!-boundaries!*}));

     if !*oc_trace then <<
       writepri ("Generated boundary conditions for adjoint variables:",
                 'only);
       for each el in !*oc!-adjoint!-left!-bcs!* do
         print!-eqn(mk!*sq el,0);
       for each el in !*oc!-adjoint!-right!-bcs!* do
         print!-eqn(mk!*sq el,0);
       >>;
%
%     if !*oc_trace
%       then writepri ("Reducing boundary conditions...", 'only);
%     x := for each var in append (!*oc!-dynamic!-variables!*,
%                                  !*oc!-adjoint!-variables!*) collect
%            for each el in append (!*oc!-left!-bcs!*,
%                                   !*oc!-adjoint!-left!-bcs!*) collect
%              mk!*sq diffsq (el, var);
%     x := nullspace!-alg x;
%     if !*oc_trace then for each el in x do
%       writepri (mkquote ('list . el), 'only);
%     x := groebnereval {'list . for each el in
%              append (!*oc!-left!-bcs!*, !*oc!-adjoint!-left!-bcs!*)
%                  collect mk!*sq el};
%     if !*oc_trace
%       then for each el in cdr x do writepri (mkquote el , 'only);
%     x := for each var in append (!*oc!-dynamic!-variables!*,
%                                  !*oc!-adjoint!-variables!*) collect
%            for each el in append (!*oc!-right!-bcs!*,
%                                   !*oc!-adjoint!-right!-bcs!*) collect
%              mk!*sq diffsq (el, var);
%     x := nullspace!-alg x;
%     if !*oc_trace then for each el in x do
%                          writepri (mkquote ('list . el), 'only);
%     x := groebnereval {'list . for each el in
%              append (!*oc!-right!-bcs!*, !*oc!-adjoint!-right!-bcs!*)
%                  collect mk!*sq el};
%     if !*oc_trace
%       then for each el in cdr x do writepri (mkquote el, 'only);
     end;	


symbolic procedure handle!-linear!-part;
  begin scalar hlin, r, ll, result, swfs; integer ordr;
    hlin := nil ./ 1;
    ll := for each var in !*oc!-linear!-part!* collect <<
      r := cdr coeff1 (mk!*sq !*oc!-hamiltonian!*, var, nil);
      if null cdr r then <<
         writepri("Hamiltonian does NOT depend on control variable ",'first);
         writepri(mkquote var,'last); nil>>
       else << hlin := addsq (hlin, multsq (simp!* cadr r, simp!* var));
               (var . cadr r) >> >>;
    for each pp in ll do if not null pp then <<
      if !*oc_trace then <<
        terpri();
        prin2 "Switch function for variable ";
        prin1 car pp;
        prin2 " : ";
        writepri (mkquote cdr pp, 'only)
        >>;
      tracewritenl
          "Trying to remove irrelevant factors from switch function...";
      tracenewline();
      begin scalar dmode!*, !*factor, bool, w, x,y,z;
      
        w := simp!* cdr pp;
        x := fctrf denr w;
        x := cdr x;   % remove numeric factor
        y := 1 ./ 1;

      loop:
        if null x then goto endloop;
        z := sign_eval1 (prepsq!* car x, !*int);
        if z eq 'unknown
          then y := multsq (y, car x)
         else if z = -1 then bool := not bool;
        x := cdr x;
        goto loop;

      endloop:

        y := invsq y;

        x := fctrf numr w;

        x := cdr x;   % remove numeric factor

      loop2:
        if null x then goto endloop2;
        z := sign_eval1 (prepsq!* car x, !*int);
        if z eq 'unknown
          then y := multsq (y, car x)
         else if z = -1 then bool := not bool;
        x := cdr x;
        goto loop2;

      endloop2:

        if bool then y := negsq y;

        if null numr resimp addsq(y,negsq w)
          then tracewritenl "No irrelevant factors found."
         else <<
	  tracewritenl
        "Removal of irrelevant factors from switch function succeeded!";
          tracewritenl "Simplified switch function is:";
          tracewritenl "==============================";
          tracemathpri prepsq y;
          >>;
        swfs := (car pp . y) . swfs;
      end;

      result := calculate!-order (!*oc!-hamiltonian!*, car pp,
                                  simp!* cdr pp);

      if null result then <<
        writepri("Bang bang control for variable ",'first);
        writepri(mkquote car pp,'last)>>
       else <<

         ordr := car result;
         result := cdr result;

%         check!-legendre!-clebsch (car pp, result)
         >>>>;

      return reversip swfs;
  end;

fluid '(svarlis scountr svar);

symbolic procedure calculate!-order (hlin, var, sch);
  begin scalar x,y,z, a, b, subs; integer ordr;
    subs := for each pp in !*oc!-dgls!* collect
              ({'df, car pp, !*oc!-time!-variable!*} . cdr pp);
    for i := 1 : length !*oc!-adjoint!-variables!* do
      subs := ({'df, nth (!*oc!-adjoint!-variables!*, i),
                !*oc!-time!-variable!*} .
               mk!*sq nth (!*oc!-adjoint!-equations!*, i)) . subs;
    x := {sch};
    while (numr car x and car x freeof var) do <<
      x := subsq (diffsq (car x, !*oc!-time!-variable!*), subs) . x;
      ordr := ordr + 1 >>;
    if null numr car x then <<
      x := cdr x;
      writepri ("Switching function for variable ",'first);
      writepri (mkquote var,nil);
      if ordr = 1 then writepri (" constant",'last)
       else <<writepri ("polynomial of order ",nil);
              writepri (mkquote ordr,nil);
              writepri (" in time",'last)>>;

      return>>
     else x := car x;
    while (x freeof var) do <<
      x := subsq (diffsq (x, !*oc!-time!-variable!*), subs);
      ordr := ordr + 1 >>;
    if not evenp ordr then rederr "This can't happen: odd order!?"
     else ordr := ordr / 2;
    y := cdr coeff1 (mk!*sq x, var, nil);
    if cddr y
      then rederr "This can't happen: nonlinear appearance of control!";
    a := simp!* car y;
    b := simp!* cadr y;
    z := quotsq (negsq a, b);
      writepri ("Singular control of order ", 'first);
      writepri (mkquote ordr, 'nil);
      writepri (" for variable ", nil);
      writepri (mkquote var, nil);
      writepri (": ", 'last);
%      writepri (mkquote mk!*sq z, 'only);
%      structr symbolic mk!*sq z;
      begin scalar svarlis, svar; integer scountr;
%        svar := varnam!*;
        svar := 'temp;
        z := mystruct!*sq mk!*sq z;
        assgnpri(z,nil,'only);
        if scountr=0 then return nil
                else <<if null !*nat then terpri();
		       prin2t "   where">>;
        for each x in svarlis do
	     <<terpri!* t;
	       prin2!* "      ";
	       assgnpri(cddr x,list cadr x,t)>>
       end;
    return (ordr . if evenp ordr then b else negsq b)
  end;


symbolic procedure check!-legendre!-clebsch (var, x);
  begin scalar s,!*factor,!*exp,!*gcd;
    !*factor := t;
    !*gcd := t;
    s := sign_eval1 (prepsq!* x, !*int);
%    if !*oc_trace then <<
      writepri ("Sign in Legendre Clebsch condition for variable ",
                'first);
      writepri (mkquote var, nil);
      writepri (" is ", nil);
      writepri (mkquote s, 'last);
%      >>;
  end;


endmodule;

end;
