module ocpriprg;

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


fluid '(!*optdecs !*gentranopt);

fluid '(!*oc!-dynamic!-variables!*
        !*oc!-control!-variables!*
        !*oc!-adjoint!-variables!*
        !*oc!-adjoint!-equations!*
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
        !*oc_trace
       );


put ('fortran, 'file!-extension, '!f);

put ('pascal, 'file!-extension, '!p);

put ('c,  'file!-extension, '!c);

symbolic smacro procedure kernels!-sq u;
  union (kernels numr u, kernels denr u);

symbolic smacro procedure make!-assign(left,right);
   {'setq,left,right};

symbolic procedure make!-indexed!-kernel(op,ovar);
   !*a2k {op, get(ovar,'varnum)};

symbolic procedure make!-subs!-pair(krnl,op,n);
   krnl . !*a2k {op, n};

symbolic procedure diff!-kernel(k,var);
   mk!*sq diffsq(simp!* k,var);


symbolic procedure make!-ptr!-param x;
   if !*oc!-target!-lang!* eq 'c then {x, '(range 0 0)} else x;

symbolic procedure make!-array!-decl(aname,len);
   {aname,{'range,'0,len - 1}};

symbolic procedure make!-ptr!-ref x;
   if !*oc!-target!-lang!* eq 'c then !*a2k {x, '0} else x;

symbolic procedure make!-filename(base,count,ext);
   compress append('!" . explode2 base,
                   append(explode count,
                          '!. . ext . '(!")));

symbolic procedure make!-swf!-name name;
   mkid('swf_,name);

symbolic procedure subsql(exprl,pl);
   for each el in exprl collect subsq(el,pl);



symbolic procedure generate!-procedure(name,params,decls,forms);
   <<sym!-gentran '(literal cr!*);
     sym!-gentran
       {'procedure,name,'nil,'expr,params,
        'rblock . nil . {'declare,decls} . forms}>>;


algebraic operator ya,yb,x,dx,w,a,b,dfdx,dfdtau,tau;

flag ('(ya yb x dx w a b tau), 'noreplace);

global '(clinelen!*);

symbolic procedure generate!-program (count, bcs, h, forms, swfs);
  begin scalar x, dx, r, l, el, kl, filename, bcname, fname,
               dforms, dtforms, dfname, locals, timelen,
               vars, bcdecls,fdecls, dfdecls, olddb, oldrd;
        integer i,j, lng, nvars;

    filename := make!-filename(!*oc!-name!*,
                               count,
           get (!*oc!-target!-lang!*, 'file!-extension) or '!c);
    if !*oc!-target!-lang!* eq 'c then clinelen!* := 60;
    bcname := intern compress ('!r . explode count);
    fname := intern compress append ('(!f !c !n), explode count);
    dfname := intern compress append ('(!d !f !c !n), explode count);

    vars := append(!*oc!-dynamic!-variables!*,
                   !*oc!-adjoint!-variables!*);
    nvars := length vars;

    if not (!*oc!-target!-lang!* eq 'c) then begin scalar cl;
      cl := for each x in !*oc!-constants!* collect
              (car x . reval cdr x);
      bcs := subsql(bcs,cl);
      h := subsq(h,cl);
      forms := subsql(forms,cl);
    end;

    lng := length vars;
    timelen := reval {'difference, cadr !*oc!-boundaries!*,
                      car !*oc!-boundaries!*};
      
    if !*oc!-is!-free!* then <<
      timelen := !*a2k timelen;
      l := for each el in vars collect (el . !*a2k {el, cadr !*oc!-boundaries!*});
      h := sublis (l, h);
      bcs := h . bcs
      >>;

    l := for each el in vars conc
           {{el,car !*oc!-boundaries!*} . make!-indexed!-kernel('ya,el),
            {el,cadr !*oc!-boundaries!*} . make!-indexed!-kernel('yb,el)};

    bcs := for each el in bcs collect sublis (l, el);

    i := 0;
    for each el in bcs do <<
      kl := union (kl, kernels!-sq el);
      r := make!-assign(!*a2k {'w, i}, mk!*sq el) . r;
      i := i + 1 >>;
        
    l := for each el in vars collect
           (make!-df el . make!-indexed!-kernel('dx,el));

    forms := for each el in forms collect begin scalar xx;
                xx := sublis (l, cdr el);
                kl := union (kl, kernels!-sq xx);
                if !*oc!-is!-free!*
                  then xx := quotsq (xx, simp!* timelen);
                return make!-assign(sublis (l, car el), mk!*sq xx)
              end;

    if !*oc!-is!-free!* then <<
      forms := aconc!*(forms, make!-assign(!*a2k {'dx, lng}, '0));
      dtforms := for each el in forms collect
                   make!-assign(!*a2k {'dfdtau, cadr cadr el},
                                diff!-kernel(caddr el, timelen));
      put(timelen,'varnum,lng);
      lng := lng + 1;
      vars := append(vars,{timelen});
      >>
     else if !*oc!-mulcon!-param!*
      then dtforms := for i := 1 : lng collect
                        make!-assign(!*a2k {'dfdtau, i - 1},
                        diff!-kernel(cadr caddr nth (forms, i),
                                     !*oc!-mulcon!-param!*))
     else
      dtforms := for i := 1 : lng collect
                   make!-assign(!*a2k {'dfdtau, i - 1}, 0);

    j := -1;
    dforms := for i := 1 : lng conc
                for each elf in forms collect
                  make!-assign(!*a2k {'dfdx, j := j + 1},
                   diff!-kernel(caddr elf,nth(vars,i)));

    for each krnl in kl do check!-kernel krnl;

    j := length r;

    r := mystructr r;

    locals := for i := 1 : (length r - j) collect cadr nth (r, i);

    if !*oc!-mulcon!-param!* then <<
      r := make!-assign(!*oc!-mulcon!-param!*,make!-ptr!-ref 'tau) . r;
      locals := !*oc!-mulcon!-param!* . locals >>
     else if !*oc!-is!-free!* then <<
      r := make!-assign(timelen,make!-ptr!-ref 'tau) . r;
      locals := timelen . locals >>;

    bcdecls := append({'real,
		       make!-array!-decl('ya,lng),
		       make!-array!-decl('yb,lng),
                       make!-ptr!-param 'tau,
		       make!-array!-decl('w,lng)},
                       locals);

    j := length forms;

    forms := mystructr forms;

    l := for each el in vars collect
           make!-assign(el, make!-indexed!-kernel('x,el));

    forms := append (l, forms);

    locals := for i := 1 : (length forms - j) collect
                cadr nth (forms, i);
    if !*oc!-mulcon!-param!*
      then locals := !*oc!-mulcon!-param!* . locals
     else if !*oc!-is!-free!* then locals := timelen . locals;

    fdecls := append({'real,make!-array!-decl('x,lng),
		            make!-array!-decl('dx,lng),
                            make!-ptr!-param !*oc!-time!-variable!*,
                            make!-ptr!-param 'tau},
                     append (locals, vars));

    if !*oc!-mulcon!-param!*
      then x := make!-assign(!*oc!-mulcon!-param!*, make!-ptr!-ref 'tau) . x
     else if !*oc!-is!-free!* then x := make!-assign(timelen, {'x, lng}) . x;

    dx := append(dx, dforms);

    dx := append(dtforms, dx);

    j := length dx;

    dx := mystructr dx;

    dx := append (l, dx);

    locals := for i := 1 : (length dx - j) collect cadr nth (dx, i);
    if !*oc!-mulcon!-param!*
      then locals := !*oc!-mulcon!-param!* . locals
     else if !*oc!-is!-free!* then locals := timelen . locals;

    if !*oc!-mulcon!-param!*
      then dx := make!-assign(!*oc!-mulcon!-param!*,make!-ptr!-ref 'tau) . dx
     else if !*oc!-is!-free!*
      then dx := make!-assign(timelen,{'x, lng}) . dx;


    dfdecls := append({'real,
                       make!-array!-decl('x,lng),
                       make!-array!-decl('dfdx,lng*lng),
                       make!-ptr!-param !*oc!-time!-variable!*,
                       make!-array!-decl('dfdtau,lng),
                       make!-ptr!-param 'tau},
                       append(locals,vars));


    % switching functions

    swfs := for each pp in swfs collect begin scalar name;
              name := make!-swf!-name car pp;
              return {car pp,name,
                      append({'real,
                              name,
                              make!-array!-decl('x,lng),
                              make!-ptr!-param 'tau},
                             vars),
                      append(l,{{'return, prepsq cdr pp}})};
             end;

    rmsubs();  % clear all internal information!

    oldrd := !*rounded;
    olddb := !*double;

    on rounded,double;

    system bldmsg ("rm -f %w", filename);
    sym!-gentranout filename;
    sym!-gentran '(literal cr!*);
    if !*oc!-target!-lang!* eq 'c then <<
      sym!-gentran '(literal "#include <math.h>" cr!*);
      sym!-gentran '(literal cr!*);
      for each x in !*oc!-constants!* do
        sym!-gentran {'literal, "#define ", car x, " ", get!-number cdr x, 'cr!*};
      sym!-gentran '(literal cr!*);
      for each x in !*oc!-parameters!* do
        sym!-gentran {'literal, "extern double ", car x, ";", 'cr!*};
      >>;
    generate!-procedure(bcname,'(ya yb tau w),bcdecls,r);

    generate!-procedure(fname,!*oc!-time!-variable!* . '(x tau dx),fdecls,forms);

    generate!-procedure(dfname,!*oc!-time!-variable!* . '(x tau dfdx dfdtau),dfdecls,dx);

    for each ll in swfs do
      generate!-procedure(cadr ll,'(x tau),caddr ll,cadddr ll);

    sym!-gentranshut filename;

    if null olddb then off double;
    if null oldrd then off rounded;

%    system bldmsg ("cc -c %w", filename)


  end;



symbolic procedure get!-number x;
  <<x := reval x;
    if numberp x then x
     else if car x eq 'minus then - get!-number cadr x
     else cdr x>>;

symbolic procedure check!-kernel knl;
  if atom knl or domainp knl then nil
   else if car knl memq '(ya yb w x dx) then nil
   else if get (car knl, 'simpfn)
    then for each x in cdr knl do check!-kernel x
   else  lprim list ("Warning: Undefined variable ", knl);

endmodule;
   
end;
