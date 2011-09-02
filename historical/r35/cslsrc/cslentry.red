module entry;   % Entry points for self-loading modules.

% Author: Anthony C. Hearn.
%         Arthur C Norman


if getd 'create!-package then create!-package('(entry),'(build));


comment Actual Entry Point Definitions;

% Cross-reference module entry points.

remd 'crefon;

put('cref,'simpfg,'((t (crefon)) (nil (crefoff))));

set!-autoload('crefon,'rcref);


% Input editor entry points.

set!-autoload('cedit, 'cedit);

set!-autoload('display,'cedit);

put('display,'stat,'rlis);

set!-autoload('editdef,'cedit);

put('editdef,'stat,'rlis);


% Factorizer module entry points.

switch trfac, trallfac;

remprop('factor,'stat);

set!-autoload('ezgcdf,'ezgcd);

set!-autoload('factorize!-primitive!-polynomial,'factor);

set!-autoload('pfactor,'factor);

set!-autoload('simpnprimitive,'factor);

put('nprimitive,'simpfn,'simpnprimitive);

put('factor,'stat,'rlis);


% FASL module entry points.

set!-autoload('compile, 'compiler);

set!-autoload('faslout, 'compiler);

set!-autoload('compile!-all, 'compiler);

flag('(faslout),'opfn);

flag('(faslout),'noval);


% High energy physics module entry points.

remprop('index,'stat); remprop('mass,'stat);

remprop('mshell,'stat); remprop('vecdim,'stat);

remprop('vector,'stat);

set!-autoload('index,'hephys);

set!-autoload('mass,'hephys);

set!-autoload('mshell,'hephys);

set!-autoload('vecdim,'hephys);

set!-autoload('vector,'hephys);

put('index,'stat,'rlis);

put('mshell,'stat,'rlis);

put('mass,'stat,'rlis);

put('vecdim,'stat,'rlis);

put('vector,'stat,'rlis);

flagop nospur;


% Integrator module entry points.

fluid '(!*trint);

switch trint;

set!-autoload('simpint,'int);

put('int,'simpfn,'simpint);

put('algint,'simpfg,'((t (load!-package 'algint))));


% Matrix module entry points.

switch cramer;

put('cramer,'simpfg,
    '((t (put 'mat 'lnrsolvefn 'clnrsolve)
     (put 'mat 'inversefn 'matinv))
      (nil (put 'mat 'lnrsolvefn 'lnrsolve)
       (put 'mat 'inversefn 'matinverse))));

set!-autoload('detq,'matrix); % Used by high energy physics package.

set!-autoload('matp,'matrix);

set!-autoload('matrix,'matrix);

put('matrix,'stat,'rlis);

flag('(mat),'struct);

put('mat,'formfn,'formmat);

set!-autoload('formmat,'matrix);

set!-autoload('generateident,'matrix);

set!-autoload('lnrsolve,'matrix);

set!-autoload('simpresultant,'matrix);

set!-autoload('resultant,'matrix);

put('resultant,'simpfn,'simpresultant);

set!-autoload('nullspace!-eval,'matrix);

put('nullspace,'psopfn,'nullspace!-eval);


% Print module entry point.

set!-autoload('horner,'scope);

global '(!*horner);

switch horner;


% Rprint module entry point.

set!-autoload('rprint, 'rprint);


% SOLVE module entry points.

set!-autoload('solveeval,'solve);

set!-autoload('solve0,'solve);

put('solve,'psopfn,'solveeval);

switch allbranch,fullroots,multiplicities,nonlnr,solvesingular;

put('arbint,'simpfn,'simpiden);

% Since the following three switches are set on in the solve module,
% they must first load that module if they are initially turned off.

put('nonlnr,'simpfg,'((nil (load!-package 'solve))));

put('allbranch,'simpfg,'((nil (load!-package 'solve))));

put('solvesingular,'simpfg,'((nil (load!-package 'solve))));


% Root finding package entry points.

set!-autoload('roots, 'roots);

set!-autoload('rlrootno, 'roots);

set!-autoload('realroots, 'roots);

set!-autoload('isolater, 'roots);

set!-autoload('firstroot, 'roots);

set!-autoload('nearestroot, 'roots);

set!-autoload('gfnewt, 'roots);

set!-autoload('gfroot, 'roots);

set!-autoload('sturm0, 'roots);

set!-autoload('root_val, 'roots);

set!-autoload('roots_at_prec, 'roots);

symbolic for each n in '(roots rlrootno realroots isolater firstroot
                         nearestroot gfnewt gfroot root_val roots_at_prec)
   do put(n,'psopfn,n);

put('sturm,'psopfn,'sturm0);

switch trroot,rootmsg;


% Limits entry points.

for each c in '(limit limit!+ limit!-) do
  <<put(c,'simpfn,'simplimit); flag({c},'full)>>;

set!-autoload('simplimit,'misc);

% Partial fractions entry point.

set!-autoload('pf,'misc);

symbolic operator pf;


% Sum entry points.

set!-autoload('simp!-sum,'misc);

put('sum,'simpfn,'simp!-sum);

set!-autoload('simp!-prod,'misc);

put('prod,'simpfn,'simp!-prod);

endmodule;

end;
