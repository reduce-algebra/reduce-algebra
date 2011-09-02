module entry;   % Entry points for self-loading modules.

% Author: Anthony C. Hearn.

% Using a modified version of the defautoload function of Eric Benson
% and Martin L. Griss.

if getd 'create!-package then create!-package('(entry),'(build));

symbolic procedure safe!-putd(name,type,body);
   % So that stubs will not clobber REAL entries preloaded.
   if getd name then lprim list("Autoload stub for",name,"not defined")
    else putd(name,type,body);

smacro procedure mkfunction u; list('function,u);

symbolic macro procedure defautoload u;
% (defautoload name), (defautoload name loadname),
% (defautoload name loadname fntype), or
% (defautoload name loadname fntype numargs)
% Default is 1 Arg EXPR in module of same name.
  begin scalar name,numargs,loadname,fntype;
    u := cdr u;
    name := car u;
    u := cdr u;
    if u then <<loadname := car u; u :=cdr u>> else loadname := name;
    if eqcar(name, 'quote) then name := cadr name;
    if atom loadname then loadname := list loadname
     else if car loadname eq 'quote then loadname := cadr loadname;
    if u then <<fntype := car u; u := cdr u>> else fntype := 'expr;
    if u then numargs := car u else numargs := 1;
    numargs := if numargs=0 then nil
                else if numargs=1 then '(x1)
                else if numargs=2 then '(x1 x2)
                else if numargs=3 then '(x1 x2 x3)
                else if numargs=4 then '(x1 x2 x3 x4)
                else error(99,list(numargs,"too large in DEFAUTOLOAD"));
    return
       list('safe!-putd,
            mkquote name,
            mkquote fntype,
            mkfunction
               list('lambda, numargs,
                    'progn .
                    aconc(for each j in loadname
                             collect list('load!-package,mkquote j),
                          list('lispapply,
                               mkquote name,
                               'list . numargs))))
  end;


comment Actual Entry Point Definitions;

% Compiler and LAP entry points.

defautoload(compile,compiler);

defautoload(faslout,compiler);


% Cross-reference module entry points.

remd 'crefon;  % don't use PSL version

put('cref,'simpfg,'((t (crefon)) (nil (crefoff))));

defautoload(crefon,rcref,expr,0);


% Input editor entry points.

defautoload cedit;

defautoload(display,cedit);

put('display,'stat,'rlis);

defautoload(editdef,cedit);

put('editdef,'stat,'rlis);


% Factorizer module entry points.

switch trfac;

remprop('factor,'stat);

defautoload(ezgcdf,ezgcd,expr,2);

defautoload(factorize!-primitive!-polynomial,factor);

defautoload(pfactor,factor,expr,2);

defautoload(simpnprimitive,factor);

put('nprimitive,'simpfn,'simpnprimitive);

put('factor,'stat,'rlis);


% FASL module entry points.

flag('(faslout),'opfn);

flag('(faslout),'noval);


% High energy physics module entry points.

remprop('index,'stat); remprop('mass,'stat);

remprop('mshell,'stat); remprop('vecdim,'stat);

remprop('vector,'stat);

defautoload(index,hephys);

defautoload(mass,hephys);

defautoload(mshell,hephys);

defautoload(vecdim,hephys);

defautoload(vector,hephys);

put('index,'stat,'rlis);

put('mshell,'stat,'rlis);

put('mass,'stat,'rlis);

put('vecdim,'stat,'rlis);

put('vector,'stat,'rlis);

flagop nospur;


% Integrator module entry points.

fluid '(!*trint);

switch trint;

defautoload(simpint,int);

put('int,'simpfn,'simpint);

put('algint,'simpfg,'((t (load!-package 'algint))));


% Matrix module entry points.

switch cramer;

put('cramer,'simpfg,
    '((t (put 'mat 'lnrsolvefn 'clnrsolve)
     (put 'mat 'inversefn 'matinv))
      (nil (put 'mat 'lnrsolvefn 'lnrsolve)
       (put 'mat 'inversefn 'matinverse))));
 
defautoload(detq,'(matrix)); % Used by high energy physics package.

defautoload(matp,'(matrix));

defautoload(matrix,'(matrix));

put('matrix,'stat,'rlis);

flag('(mat),'struct);

put('mat,'formfn,'formmat);

defautoload(formmat,'(matrix),expr,3);

defautoload(generateident,'(matrix));

defautoload(lnrsolve,'(matrix),expr,2);

defautoload(simpresultant,'(matrix));

defautoload(resultant,'(matrix),expr,3);

put('resultant,'simpfn,'simpresultant);

defautoload(nullspace!-eval,matrix);

put('nullspace,'psopfn,'nullspace!-eval);


% Prettyprint module entry point.

% defautoload(prettyprint,pretty);      % Built into CSL.


% Rprint module entry point.

defautoload rprint;


% SOLVE module entry points.

defautoload(solveeval,solve);

defautoload(solve0,solve,expr,2);

put('solve,'psopfn,'solveeval);

switch allbranch,fullroots,multiplicities,nonlnr,solvesingular;

% Since the following three switches are set on in the solve module,
% they must first load that module if they are initially turned off.

put('nonlnr,'simpfg,'((nil (load!-package 'solve))));

put('allbranch,'simpfg,'((nil (load!-package 'solve))));

put('solvesingular,'simpfg,'((nil (load!-package 'solve))));


% Root finding package entry points.

defautoload roots;

defautoload(rlrootno,roots);

defautoload(realroots,roots);

defautoload(isolater,roots);

defautoload(firstroot,roots);

defautoload(nearestroot,roots);

defautoload(gfnewt,roots);

defautoload(gfroot,roots);

defautoload(sturm0,roots);

defautoload(root_val,roots);

defautoload(roots_at_prec,roots);

symbolic for each n in '(roots rlrootno realroots isolater firstroot
 nearestroot gfnewt gfroot root_val roots_at_prec)
   do put(n,'psopfn,n);

put('sturm,'psopfn,'sturm0);

switch trroot,rootmsg;


% Limits entry points.

for each c in '(limit,limit!+,limit!-) do
  <<put(c,'simpfn,'simplimit); flag({c},'full)>>;

defautoload(simplimit,misc);

% Partial fractions entry point.

defautoload(pf,misc,expr,2);

symbolic operator pf;


% Sum entry points.

defautoload(simp!-sum,misc);

put('sum,'simpfn,'simp!-sum);

defautoload(simp!-prod,misc);

put('prod,'simpfn,'simp!-prod);


% Debug module entry points.

% if not(systemname!* eq 'ibm) then defautoload(embfn,debug,expr,3);


endmodule;

end;
