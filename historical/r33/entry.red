module entry;   % Table of entry points of self-loading modules.

% Author: Anthony C. Hearn.

% Using a modified version of the defautoload function of Eric Benson
% and Martin L. Griss.

global '(!*msg modules!* systemname!* system!*);

symbolic procedure safe!-putd(name,type,body);
   % So that stubs will not clobber REAL entries preloaded.
   if getd name
     then !*msg
        and printf("%n*** Autoload stub for %p not defined%n",name)
    else putd(name,type,body);

symbolic macro procedure defautoload u;
% (defautoload name), (defautoload name loadname),
% (defautoload name loadname fntype), or
% (defautoload name loadname fntype numargs)
% Default is 1 Arg EXPR in module of same name;
  begin scalar name,numargs,loadname,fntype,x;
    u := cdr u;
    name := car u;
    u := cdr u;
    if u then <<loadname := car u; u :=cdr u>> else loadname := name;
    if eqcar(name, 'quote) then name := cadr name;
    if atom loadname
      then if (x := get(loadname,'loadnames)) then loadname := x
            else loadname := list loadname
     else if car loadname eq 'quote then loadname := cadr loadname;
    if u then <<fntype := car u; u := cdr u>> else fntype := 'expr;
    if u then numargs := car u else numargs := 1;
    numargs := if numargs=0 then nil
                else if numargs=1 then '(x1)
                else if numargs=2 then '(x1 x2)
                else if numargs=3 then '(x1 x2 x3)
                else if numargs=4 then '(x1 x2 x3 x4)
                else error(99,list(numargs,"too large in defautoload"));
    return
       list('safe!-putd,
            mkquote name,
            mkquote fntype,
            list('function,
                 list('lambda, numargs,
                      'progn .
                      aconc(for each j in loadname
                               collect list('load!-module,mkquote j),
                            list('apply,
                                 mkquote name,
                                 'list . numargs)))))
  end;


COMMENT Actual Entry Point Definitions;

% Bigfloat module entry point.

put('bigfloat,'module!-name,'bfloat);


% Compiler and LAP entry points.

% defautoload(compd,compiler,expr,3);

defautoload(compile,compiler);

defautoload(lap,compiler);


% Cross-reference module entry points.

put('cref,'simpfg,'((t (crefon)) (nil (crefoff))));

defautoload(crefon,rcref,expr,0);


% Factorizer module entry points.

remprop('factor,'stat);

defautoload(ezgcdf,ezgcd,expr,2);

defautoload(factorf,'(ezgcd factor));

defautoload(factoreval,'(ezgcd factor));

put('factorize,'psopfn,'factoreval);

defautoload(pfactor,'(ezgcd factor),expr,2);

% defautoload(simpnprimitive,'(ezgcd factor));

% put('nprimitive,'simpfn,'simpnprimitive);

defautoload(simpresultant,rsltnt);

defautoload(resultant,rsltnt,expr,3);

put('resultant,'simpfn,'simpresultant);

put('factor,'stat,'rlis);


% FASL module entry points.

%defautoload(faslout,compiler);

flag('(faslout),'opfn);

put('faslend,'stat,'endstat);


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


% Input editor entry points.

defautoload(cedit,util);

defautoload(display,util);

put('display,'stat,'rlis);

defautoload(editdef,util);

put('editdef,'stat,'rlis);


% Integrator module entry point.

defautoload(simpint,int);

put('int,'simpfn,'simpint);


% Matrix module entry points.

defautoload(detq,matr);

defautoload(generateident,matr);

defautoload(matp,matr);

defautoload(matrix,matr);

put('matrix,'stat,'rlis);

flag('(mat),'struct);

put('mat,'formfn,'formmat);

defautoload(formmat,matr,expr,3);

defautoload(lnrsolve,matr,expr,2);


% Prettyprint module entry point.

defautoload(prettyprint,util);


% Rprint module entry point.

defautoload(rprint,util);


% SOLVE module entry point.

defautoload(solveeval,solve);

defautoload(solve0,solve,expr,2);

put('solve,'psopfn,'solveeval);


% Debug module entry points.

% defautoload(embfn,debug,expr,3);

endmodule;


end;
