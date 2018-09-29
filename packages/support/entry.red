module entry;   % Entry points for self-loading modules.

% Author: Anthony C. Hearn.

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


% Using a modified version of the defautoload function of Eric Benson
% and Martin L. Griss.

% Extended for algebraic operators and values by Herbert Melenk.

fluid '(varstack!*);

if getd 'create!-package then create!-package('(entry),'(build));

symbolic procedure safe!-putd(name,type,body);
   % So that stubs will not clobber REAL entries preloaded.
   if getd name then lprim list("Autoload stub for",name,"not defined")
    else putd(name,type,body);

inline procedure mkfunction u; list('function,u);

symbolic procedure do!-autoload(name, u, loadname);
  begin
    scalar w;
    for each j in loadname do load!-package j;
    w := getd name;
    if not atom w and
       not atom (w := cdr w) and
       eqcar(w, 'lambda) and
       not atom (w := cddr w) and
       eqcar(car w, 'do!-autoload) then <<
       lprim list("Autoloading for", name, "did not defined it"); 
       error(99, list("Presumed build failure:", name, loadname)) >>;
    return lispapply(name, u)
  end;

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
    u := if numargs=0 then nil
          else if numargs=1 then '(x1)
          else if numargs=2 then '(x1 x2)
          else if numargs=3 then '(x1 x2 x3)
          else if numargs=4 then '(x1 x2 x3 x4)
          else if numargs=5 then '(x1 x2 x3 x4 x5)
          else if numargs=6 then '(x1 x2 x3 x4 x5 x6)
          else error(99,list(numargs,"too large in DEFAUTOLOAD"));
    name := mkquote name;
    return
       list('progn,
            list('put,name,mkquote 'number!-of!-args,numargs),
            list('safe!-putd,
                 name,
                 mkquote fntype,
                 mkfunction
                    list('lambda, u,
                       list('do!-autoload,
                            name,
                            'list . u,
                            mkquote loadname))))
  end;

% Autoload support for algebraic operators and values.
%
%    defautoload_operator(opname,package);
%    defautoload_value(varname,package);
%

symbolic macro procedure defautoload_operator u;
  begin scalar name,package;
    name := cadr u; package := caddr u;
    return subla(list('name.name,'package.package),
     '(progn
        (flag '(name) 'full)
        (put 'name 'simpfn
          '(lambda(x)(autoload_operator!* 'name 'package x)))))
  end;

symbolic procedure autoload_operator!*(o,p,x);
   begin scalar varstack!*;
     remflag(list o,'full);
     remprop(o,'simpfn);
     if pairp p then for each pp in p do load!-package pp
        else load!-package p;
     return simp x;
   end;

symbolic macro procedure defautoload_value u;
  begin scalar name,package;
    u:=cdr u; name := car u; u:=cdr u; package := car u;
    return subla(list('name.name,'package.package),
     '(progn
        (put 'name 'avalue
          '(autoload_value!* name package))))
  end;

symbolic procedure autoload_value!*(u,v);
   begin scalar name,p,x,varstack!*;
     x:=get(u,'avalue);
     name := cadr x; p := caddr x;
     remprop(name,'avalue);
     load!-package p;
     return reval1(name,v);
   end;

put('autoload_value!*,'evfn,'autoload_value!*);

COMMENT Actual Entry Point Definitions;

% Compiler and LAP entry points.

defautoload(compile,compiler);

if 'psl memq lispsystem!* then defautoload(lap,compiler)
 else defautoload(faslout,compiler);


% Cross-reference module entry points.

remd 'crefon;  % don't use PSL version

% Protect against "off cref;" calling crefoff before the rcref module 
% is loaded.
put('cref,'simpfg,'((t (crefon))
                    (nil (and (getd (quote crefoff)) (crefoff)))));

defautoload(crefon,rcref,expr,0);


% Input editor entry points.

defautoload cedit;

defautoload(display,cedit);

put('display,'stat,'rlis);

defautoload(editdef,cedit);

put('editdef,'stat,'rlis);

% Functions for rebuilding parts of Reduce

defautoload(package!-remake, remake);

% Factorizer module entry points.

switch trfac, trallfac;

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


% Integrator module entry points.

fluid '(!*trint !*trintsubst !*trdint);

switch trint,trintsubst,trdint;

defautoload(simpint,int);

put('int,'simpfn,'simpint);

fluid '(!*tra);

switch tra;

put('algint,'simpfg,'((t (load!-package 'algint))));

fluid '(!*trdefint);

switch trdefint;

defautoload(new_defint,defint);

defautoload(new_indefint,defint);

defautoload(defint0,defint);


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

defautoload(matstat,'(matrix),expr,0);

put('mat,'stat,'matstat);

defautoload(generateident,'(matrix));

defautoload(lnrsolve,'(matrix),expr,2);

defautoload(simpresultant,'(matrix));

defautoload(resultant,'(matrix),expr,3);

put('resultant,'simpfn,'simpresultant);

defautoload(nullspace!-eval,matrix);

put('nullspace,'psopfn,'nullspace!-eval);

defautoload(readmatproc,'(matrix),expr,0);

put('matrixproc,'stat,'readmatproc);

% ODESolve entry point.

put('odesolve,'psopfn,'odesolve!-eval);

defautoload(odesolve!-eval,odesolve);

% Plot entry point.

put('plot,'psopfn,'(lambda(u) (prog (!*msg) (load!-package 'gnuplot) (ploteval u))));

%% define .. operator so that you don't get an error when used before autoloaded
put('!*interval!*,'simpfn,'simpiden);

newtok '((!. !.) !*interval!*);

put('!*interval!*,'prtch,'! !.!.! );

precedence .., or;

fluid '(!*trplot !*plotkeep);

switch force_gnuplot_term=on, trplot, plotkeep;


% Prettyprint module entry point (built into CSL).

if 'psl memq lispsystem!* then defautoload(prettyprint,pretty);

% Print module entry point.

% defautoload(horner,scope);

% global '(!*horner);

% switch horner;


% Rprint module entry point.

defautoload rprint;


% SOLVE module entry points.

defautoload(solveeval,solve);

defautoload(solve0,solve,expr,2);

% defautoload(solvelnrsys,solve,expr,2);      % Used by matrix routines.

% defautoload(!*sf2ex,solve,expr,2);   % Used by matrix routines.

put('solve,'psopfn,'solveeval);

switch allbranch,arbvars,fullroots,multiplicities,nonlnr,solvesingular;
%      varopt;

% Default values.

!*allbranch     := t;
!*arbvars       := t;
!*solvesingular := t;

put('arbint,'simpfn,'simpiden);

% Since the following three switches are set on in the solve module,
% they must first load that module if they are initially turned off.

put('nonlnr,'simpfg,'((nil (load!-package 'solve))));

put('allbranch,'simpfg,'((nil (load!-package 'solve))));

put('solvesingular,'simpfg,'((nil (load!-package 'solve))));


% Root finding package entry points.

defautoload roots;

defautoload(gfnewt,roots);

defautoload(gfroot,roots);

defautoload(root_val,roots);

defautoload(firstroot,roots);

defautoload(rlrootno,roots2);

defautoload(realroots,roots2);

defautoload(isolater,roots2);

defautoload(nearestroot,roots2);

defautoload(sturm0,roots2);

defautoload(multroot1,roots2);

for each n in '(roots rlrootno realroots isolater firstroot
                nearestroot gfnewt gfroot root_val)
   do put(n,'psopfn,n);

put('sturm,'psopfn,'sturm0);

switch trroot,rootmsg;

put('multroot,'psopfn,'multroot1);

switch fullprecision,compxroots;

% Limits entry points.

for each c in '(limit limit!+ limit!-) do
   <<put(c,'simpfn,'simplimit);
     put(c,'number!-of!-args,3);
     flag({c},'full)>>;

defautoload(simplimit,limits);

% Partial fractions entry point.

flag('(pf),'opfn);

flag('(pf),'noval);

defautoload(pf,pf,expr,2);

% Compact entry point.

defautoload(simpcompact,compact);

put('compact,'simpfn,'simpcompact);

% Changevar entry point

defautoload(simpchangevar,changevr);

put('changevar,'simpfn,'simpchangevar);

% Sum entry points.

defautoload(simp!-sum,sum);
defautoload(simp!-sum0,sum,expr,2);

put('sum,'simpfn,'simp!-sum);

defautoload(simp!-prod,sum);

put('prod,'simpfn,'simp!-prod);

switch zeilberg;

% Taylor entry points

put('taylor,'simpfn,'simptaylor);

defautoload(simptaylor,taylor);

% Trigsimp  entry points

put('trigsimp,'psopfn,'trigsimp!*);

defautoload(trigsimp!*,trigsimp);

% Specfn entry points

flag('(compute!:dilog compute!:lerch_phi),'opfn);
defautoload(compute!:dilog,specfn);
defautoload(compute!:lerch_phi,specfn,expr,3);

flag('(compute!:khinchin1 bernoulli!*calc euler!:aux),'opfn);
defautoload(compute!:khinchin1,specfn,expr,0);
defautoload(bernoulli!*calc,specfn,expr,1);
defautoload(euler!:aux,specfn,expr,1);
defautoload(rd_euler!*,(specfn sfgamma),expr,0);
defautoload(cr_euler!*,(specfn sfgamma),expr,0);
defautoload(rd_catalan!*,specfn,expr,0);
defautoload(cr_catalan!*,specfn,expr,0);

defautoload_operator(BesselJ,(specfn specbess));
defautoload_operator(BesselY,(specfn specbess));
defautoload_operator(BesselI,(specfn specbess));
defautoload_operator(BesselK,(specfn specbess));
defautoload_operator(hankel1,(specfn specbess));
defautoload_operator(hankel2,specbess);
defautoload_operator(KummerM,specbess);
defautoload_operator(KummerU,specbess);
defautoload_operator(StruveH,specbess);
defautoload_operator(StruveL,specbess);
defautoload_operator(lommel1,specbess);
defautoload_operator(lommel2,specbess);
defautoload_operator(WhittakerM,specbess);
defautoload_operator(WhittakerW,specbess);
defautoload_operator(Airy_Ai,specbess);
defautoload_operator(Airy_Bi,specbess);
defautoload_operator(Airy_Aiprime,specbess);
defautoload_operator(Airy_Biprime,specbess);

%defautoload_operator(gamma,(specfn sfgamma));
defautoload_operator(binomial,specfn);

flag('(compute!:int!:functions),'opfn);

defautoload(compute!:int!:functions,specfn,expr,2);

defautoload(sf!*eval,specfn,expr,2);

flag('(do!*gamma do!*pochhammer do!*polygamma polygamma_aux do!*trigamma!*halves
       do!*zeta do!*zeta!*pos!*intcalc ibeta!:eval igamma!:eval),'opfn);
defautoload(do!*gamma,(specfn sfgamma));
defautoload(do!*pochhammer,(specfn sfgamma),expr,2);
defautoload(polygamma_aux,(specfn sfgamma),expr,2);
defautoload(rdpsi!*,(specfn sfgamma));
defautoload(crpsi!*,(specfn sfgamma));
defautoload(do!*polygamma,(specfn sfgamma),expr,2);
defautoload(do!*trigamma!*halves,(specfn sfgamma));
defautoload(do!*zeta,(specfn sfgamma));
defautoload(do!*zeta!*pos!*intcalc,(specfn sfgamma));
defautoload(igamma!:eval,(specfn sfgamma),expr,2);
defautoload(ibeta!:eval,(specfn sfgamma),expr,3);

flag('(solidharmonicy sphericalharmonicy),'opfn);
defautoload(solidharmonicy,specfn,expr,6);
defautoload(sphericalharmonicy,specfn,expr,4);

flag('(fibonacci fibonaccip),'opfn);
flag('(fibonacci),'integer);
defautoload(fibonacci,specfn);
defautoload(fibonaccip,specfn,expr,2);

flag('(motzkin),'opfn);
defautoload(motzkin,specfn);

% specfn2 module entry points

defautoload_operator(hypergeometric,(specfn specfn2));
defautoload_operator(MeijerG,(specfn specfn2));

% Debug module entry points.

% if not(systemname!* eq 'ibm) then defautoload(embfn,debug,expr,3);


% Specfn entry points.

defautoload_operator(lambert_w,(specfn specbess));

% Pgauss entry points

defautoload(pg_gauss!-sym, pgauss, expr, 2);

% Rltools entry points

symbolic operator meminfo;
defautoload(meminfo, rltools, expr, 0);

defautoload(systo_datestamp, rltools, expr, 0);
defautoload(systo_get!-resource!-directory, rltools, expr, 0);
defautoload(systo_trunk, rltools, expr, 0);

defautoload(ioto_cplu, rltools, expr, 2);
defautoload(ioto_cterpri, rltools, expr, 0);
defautoload(ioto_form2str, rltools, expr, 1);
defautoload(ioto_prin2, rltools, expr, 1);
defautoload(ioto_prin2t, rltools, expr, 1);
defautoload(ioto_realtime, rltools, expr, 0);
defautoload(ioto_smaprin, rltools, expr, 1);
defautoload(ioto_sxread, rltools, expr, 1);
defautoload(ioto_tprin2, rltools, expr, 1);
defautoload(ioto_tprin2t, rltools, expr, 1);

defautoload(lto_0listp, rltools, expr, 1);
defautoload(lto_upcase, rltools, expr, 1);
defautoload(lto_alinsert, rltools, expr, 3);
defautoload(lto_almerge, rltools, expr, 2);
defautoload(lto_alphap, rltools, expr, 1);
defautoload(lto_alunion, rltools, expr, 1);
defautoload(lto_appendn, rltools, expr, 1);
defautoload(lto_apply2nthip, rltools, expr, 4);
defautoload(lto_at2str, rltools, expr, 1);
defautoload(lto_cartprod, rltools, expr, 1);
defautoload(lto_cassoc, rltools, expr, 2);
defautoload(lto_catsoc, rltools, expr, 2);
defautoload(lto_delnthip, rltools, expr, 2);
defautoload(lto_delq, rltools, expr, 2);
defautoload(lto_delqip, rltools, expr, 2);
defautoload(lto_downcase, rltools, expr, 1);
defautoload(lto_drop, rltools, expr, 2);
defautoload(lto_eatsoc, rltools, expr, 3);
defautoload(lto_fastgensym, rltools, expr, 0);
defautoload(lto_hinsert, rltools, expr, 3);
defautoload(lto_hmember, rltools, expr, 3);
defautoload(lto_idconcat, rltools, expr, 1);
defautoload(lto_idconcat2, rltools, expr, 2);
defautoload(lto_init, rltools, expr, 1);
defautoload(lto_insert, rltools, expr, 2);
defautoload(lto_insertq, rltools, expr, 2);
defautoload(lto_last, rltools, expr, 1);
defautoload(lto_lengthp, rltools, expr, 3);
defautoload(lto_list2set, rltools, expr, 1);
defautoload(lto_list2vector, rltools, expr, 1);
defautoload(lto_lpvarl, rltools, expr, 1);
defautoload(lto_max, rltools, expr, 1);
defautoload(lto_maxkl, rltools, expr, 1);
defautoload(lto_mergesort, rltools, expr, 2);
defautoload(lto_min, rltools, expr, 1);
defautoload(lto_nconcn, rltools, expr, 1);
defautoload(lto_partition, rltools, expr, 2);
defautoload(lto_powerset, rltools, expr, 1);
defautoload(lto_remove, rltools, expr, 2);
defautoload(lto_rmpos, rltools, expr, 2);
defautoload(lto_sconcat, rltools, expr, 1);
defautoload(lto_sconcat2, rltools, expr, 2);
defautoload(lto_setequalq, rltools, expr, 2);
defautoload(lto_setminus, rltools, expr, 2);
defautoload(lto_sgnchg, rltools, expr, 1);
defautoload(lto_string2id, rltools, expr, 1);
defautoload(lto_stringdescriptionlist, rltools, expr, 5);
defautoload(lto_stringparagraph, rltools, expr, 3);
defautoload(lto_sublistp, rltools, expr, 2);
defautoload(lto_subset, rltools, expr, 2);
defautoload(lto_subsetq, rltools, expr, 2);
defautoload(lto_unionn, rltools, expr, 1);
defautoload(lto_zip, rltools, expr, 3);

defautoload(sfto_allcoeffs, rltools, expr, 2);
defautoload(sfto_avgq, rltools, expr, 2);
defautoload(sfto_dcontentf, rltools, expr, 1);
defautoload(sfto_decdegf, rltools, expr, 3);
defautoload(sfto_dgcdf, rltools, expr, 2);
defautoload(sfto_dprpartf, rltools, expr, 1);
defautoload(sfto_dprpartksf, rltools, expr, 1);
defautoload(sfto_exteucd, rltools, expr, 2);
defautoload(sfto_fctrf, rltools, expr, 1);
defautoload(sfto_floatsub, rltools, expr, 2);
defautoload(sfto_fsub, rltools, expr, 2);
defautoload(sfto_fsub1, rltools, expr, 2);
defautoload(sfto_gcdf!*, rltools, expr, 2);
defautoload(sfto_greaterq, rltools, expr, 2);
defautoload(sfto_idvarf, rltools, expr, 1);
defautoload(sfto_int2sf, rltools, expr, 1);
defautoload(sfto_kernelp, rltools, expr, 1);
defautoload(sfto_kmemberf, rltools, expr, 2);
defautoload(sfto_lcmn, rltools, expr, 2);
defautoload(sfto_lcx, rltools, expr, 1);
defautoload(sfto_lessq, rltools, expr, 2);
defautoload(sfto_linwpp, rltools, expr, 2);
defautoload(sfto_lmq, rltools, expr, 1);
defautoload(sfto_lmultf, rltools, expr, 1);
defautoload(sfto_lreorder, rltools, expr, 2);
defautoload(sfto_mkpowq, rltools, expr, 2);
defautoload(sfto_monfp, rltools, expr, 1);
defautoload(sfto_mvartest, rltools, expr, 2);
defautoload(sfto_mvarx, rltools, expr, 1);
defautoload(sfto_pdecf, rltools, expr, 1);
defautoload(sfto_qsub, rltools, expr, 2);
defautoload(sfto_qsub1, rltools, expr, 2);
defautoload(sfto_qsubhor, rltools, expr, 3);
defautoload(sfto_qsubhor1, rltools, expr, 3);
defautoload(sfto_redx, rltools, expr, 1);
defautoload(sfto_renamealf, rltools, expr, 2);
defautoload(sfto_renamef, rltools, expr, 3);
defautoload(sfto_reorder, rltools, expr, 2);
defautoload(sfto_resf, rltools, expr, 3);
defautoload(sfto_sf2int, rltools, expr, 1);
defautoload(sfto_sf2monl, rltools, expr, 1);
defautoload(sfto_sf2monlip, rltools, expr, 1);
defautoload(sfto_sqfdecf, rltools, expr, 1);
defautoload(sfto_sqfpartf, rltools, expr, 1);
defautoload(sfto_sqfpartz, rltools, expr, 1);
defautoload(sfto_sqrtf, rltools, expr, 1);
defautoload(sfto_truncq, rltools, expr, 2);
defautoload(sfto_tsqsumf, rltools, expr, 1);
defautoload(sfto_ucontentf, rltools, expr, 1);
defautoload(sfto_varisnump, rltools, expr, 1);
defautoload(sfto_vardeg, rltools, expr, 2);
defautoload(sfto_varf, rltools, expr, 1);
defautoload(sfto_varp, rltools, expr, 1);
defautoload(sfto_zdeqn, rltools, expr, 2);

symbolic operator fastresultant;
defautoload(fastresultant, rltools, expr, 3);

% Rlsupport entry points

defautoload(revision, rlsupport, expr, 2);

defautoload(copyright, rlsupport, expr, 2);

defautoload(rl_provideService, rlsupport, expr, 2);

put('rl_type, 'stat, 'rl_typeStat);
defautoload(rl_typeStat, rlsupport, expr, 0);

put('rl_service, 'stat, 'rl_serviceStat);
defautoload(rl_serviceStat, rlsupport, expr, 0);

put('rl_blackBox, 'formfn, 'rl_formBlackBox);
defautoload(rl_formBlackBox, rlsupport, expr, 3);

defautoload(rl_servicewrapper, rlsupport, expr, 6);

defautoload(rl_exception, rlsupport, expr, 1);

defautoload(rl_exceptionp, rlsupport, expr, 1);

defautoload(rl_exc, rlsupport, expr, 1);

defautoload(rl_excp, rlsupport, expr, 1);

% Redlog entry points

put('rlset, 'psopfn, 'rl_set!$);
defautoload(rl_set!$, redlog, expr, 1);

defautoload(rl_set, redlog, expr, 1);

defautoload(rl_copyc, redlog, expr, 2);

% Qhull entry point

symbolic operator qhull;
defautoload(qhull, qhull, expr, 1);

defautoload(qhull_qhull, qhull, expr, 1);

% Gurobi entry points

defautoload(gurobi_newmodel, gurobi, expr, 2);

% Crack, Applysym & Liepde

defautoload(backup_reduce_flags, crack, expr, 0);
symbolic operator setcrackflags;
defautoload(setcrackflags, crack, expr, 0);
defautoload(liepde, liepde, expr, 4);
defautoload(einfachst, applysym, expr, 2);

% Assert

fluid '(!*assert assert_functionl!*);

switch assert;

put('assert, 'simpfg, '((t (assert_onoff)) (nil (assert_onoff))));
defautoload(assert_onoff, assert, expr, 0);

defautoload(assert_declarestat, assert, expr, 0);
put('declare, 'stat, 'assert_declarestat);

defautoload(assert_structstat, assert, expr, 0);
put('struct,'stat,'assert_structstat);

defautoload(assert_procstat, assert, expr, 0);
put('asserted, 'stat, 'assert_procstat);

defautoload(assert_install, assert, expr, 1);
put('assert_install, 'stat, 'rlis);

defautoload(assert_uninstall, assert, expr, 1);
put('assert_uninstall, 'stat, 'rlis);

operator assert_install_all;
defautoload(assert_install_all, assert, expr, 0);

operator assert_uninstall_all;
defautoload(assert_uninstall_all, assert, expr, 0);

% LALR

defautoload(lex_cleanup, lalr, expr, 0);
defautoload(lalr_construct_parser, lalr, expr, 2);
defautoload(yyparse, lalr, expr, 1);

% Ranum

switch ranum;
put('ranum,'simpfg,'((t (load!-package 'ranum) (setdmode (quote ranum) t))));

defautoload(ra_x, ranum, expr, 0);
defautoload(ra_y, ranum, expr, 0);

% Smt
operator smt;
defautoload(smt, smt, expr, 0);

operator smt_mainloop;
defautoload(smt_mainloop, smt, expr, 0);

% mrvlimit
symbolic operator mrv_limit;
defautoload(mrv_limit, mrvlimit, expr, 3);

endmodule;

end;
