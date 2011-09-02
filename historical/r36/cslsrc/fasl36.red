%
%           csl -i slowr36.img -o fasl36.img fasl36.red
%
% Make some modules in a file called "fullimage" so that REDUCE can be
% built from them.  These are things that will be pre-loaded into the
% main image and so their FASL modules will not be needed once the
% proper image has been built, plus things where the modules will be
% copied into the final production image.  In this build job I restart
% CSL/REDUCE after I compile each module - this guarantees that inter-
% module conflicts can not hurt the compilation.  It is unfortunate that
% at present many modules instate definitions or properties that are
% incompatible with building others.
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% You may wonder what all the "remflag('(xxx), 'lose)" statements
% here are.  Well, they are used when some optionally loaded module
% redefines functions that are part of the base system.  In CSL (at least)
% if those functions were important they were migrated into the CSL kernel
% and flagged LOSE.  So without the explicit REMFLAGs here the new
% definitions required would not get instantiated.
%
% NOTE VERY WELL
%   If any of the source files are changed here so that they re-define
%   other functions then the code here MUST be changed to reflect that
%   fact.   I hope very much that changes will in fact go in the other
%   direction so that eventually NO functions in REDUCE are given
%   multiple definitions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic;

!*savedef := nil;

copy!-module 'compat;
copy!-module 'compiler;
copy!-module 'ccomp;

faslout 'user;
rdf "u01.lsp"$
rdf "u02.lsp"$
rdf "u03.lsp"$
rdf "u04.lsp"$
rdf "u05.lsp"$
rdf "u06.lsp"$
rdf "u07.lsp"$
rdf "u08.lsp"$
rdf "u09.lsp"$
rdf "u10.lsp"$
rdf "u11.lsp"$
rdf "u12.lsp"$
faslend;

symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'module;
in "../src/module.red"$

module 'cslpatch;

% Support for patching REDUCE 3.5 sources.
% This adjusted version is needed if patching is to work properly with
% CSL.  The only changes are two replacements for calls to gensym().

symbolic procedure patchstat;
   % Read a patch for a given package.
   begin scalar !*mode,u,v,x,y,z,z2;
      x := scan();   % Package name.
      scan();        % Remove semicolon.
 a:   !*mode := 'symbolic;
      y := xread nil;
      if eqcar(y,'symbolic) then y := cadr y
       else if flagpcar(y,'modefn)
        then progn(!*mode := car y, y := cadr y);
      if eq(y,'endpatch)
       then progn(u := dated!-name x,
                  z2 :=  list('de,u,nil,'progn . reversip z) . z2,
                  z2 := list('put,mkquote x,mkquote 'patchfn,mkquote u)
                           . z2,
                  return ('patch . reversip z2))
       else if eqcar(y,'procedure)
        then progn(v := cadr y,
               u := hashtagged!-name(v, y),
               z := list('copyd,mkquote v,mkquote u) . z,
               z2  := convertmode(('procedure . u . cddr y),nil,
                                  'symbolic,!*mode)
                     . z2)
       else z := convertmode(y,nil,'symbolic,!*mode) . z;
      go to a;
   end;

put('patch,'stat,'patchstat);

endmodule;

faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'cslprolo;
in "../src/cslprolo.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'patches;
in "../src/patches.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'rlisp;
in "../src/rlisp.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'cslrend;
in "../src/cslrend.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'poly;
in "../src/poly.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'alg;
in "../src/alg.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'mathpr;
in "../src/mathpr.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'fmprint;
in "../cslsrc/fmprint.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'arith;
in "../src/arith.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'entry;
in "../src/entry.red"$
faslend;

%
% The ones that follow will be copied are FASL files into the final image
%

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'matrix;
in "../src/matrix.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'hephys;
in "../src/hephys.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(glsolterm mkglsol), 'lose);

faslout 'arnum;
in "../src/arnum.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'cedit;
in "../src/cedit.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'compact;
in "../src/compact.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(clear oddp), 'lose);

faslout 'excalc;
in "../src/excalc.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'ezgcd;
in "../src/ezgcd.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'factor;
in "../src/factor.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'gentran;
in "../src/gentran.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'dipoly;
in "../src/dipoly.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(subsetp), 'lose);

faslout 'groebner;
in "../src/groebner.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'groebnr2;
in "../src/groebnr2.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'int;
in "../src/int.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(subsetp), 'lose);

faslout 'algint;
in "../src/algint.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'pretty;
in "../src/pretty.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'rcref;
in "../src/rcref.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'numeric;
in "../src/numeric.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'roots;
in "../src/roots.red"$
faslend;
faslout 'roots2;
in "../src/roots2.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(rprint), 'lose);

faslout 'rprint;
in "../src/rprint.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(getcind), 'lose);

faslout 'scope;
in "../src/scope.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(evalletsub2 glsolterm mkglsol), 'lose);

faslout 'solve;
in "../src/solve.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(degreef ordp), 'lose);

faslout 'spde;
in "../src/spde.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(simptaylor), 'lose);

faslout 'taylor;
in "../src/taylor.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'tps;
in "../src/tps.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'misc;
in "../src/misc.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'odesolve;
in "../src/odesolve.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(getrtype1 getrtype2 locate rcons rcons varpri), 'lose);

faslout 'avector;
in "../src/avector.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(depend maprin nodepend), 'lose);

faslout 'rlisp88;
in "../src/rlisp88.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'orthovec;
in "../src/orthovec.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'ineq;
in "../src/ineq.red"$
faslend;
faslout 'specfn;
in "../src/specfn.red"$
faslend;
faslout 'specfn2;
in "../src/specfn2.red"$
faslend;
faslout 'specfaux;
in "../src/specfaux.red"$
faslend;
faslout 'specbess;
in "../src/specbess.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;
remflag('(evenp lengthreval natnumlis oddp
          rappend rcons rfirst rinsert rmember
          rrest rreverse rsecond rthird unitmat), 'lose);

faslout 'assist;
in "../src/assist.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'boolean;
in "../src/boolean.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(flatten subsetp unitmat), 'lose);

faslout 'cali;
in "../src/cali.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'camal;
in "../src/camal.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(diffp), 'lose);

faslout 'changevr;
in "../src/changevr.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(freeof), 'lose);

faslout 'crackapp;
in "../src/crackapp.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(freeof), 'lose);

faslout 'crack;
in "../src/crack.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'applysym;
in "../src/applysym.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(isimp1), 'lose);

faslout 'cvit;
in "../src/cvit.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'defint;
in "../src/defint.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'desir;
in "../src/desir.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'dfpart;
in "../src/dfpart.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'dummy;
in "../src/dummy.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(maxorder simptaylor), 'lose);

faslout 'fide1;
in "../src/fide1.red"$
faslend;
load_package fide1,gentran;
faslout 'fide;
in "../src/fide.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'fps;
in "../src/fps.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'ideals;
in "../src/ideals.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'invbase;
in "../src/invbase.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'laplace;
in "../src/laplace.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remprop('help, 'stat);  % Because lie.red uses "help" as a variable name
                        % and I am not allowed to change that in the source.
                        % Anybody who tries to recompile lie.red other than
                        % via this file "watch out".
                        % Actually it is more complicated than that, since I
                        % will usually run this re-build job using "slowr36"
                        % and I do not build the help mechanism into that.

faslout 'lie;
in "../src/lie.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'linalg;
in "../src/linalg.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'modsr;
in "../src/modsr.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'ncpoly;
in "../src/ncpoly.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'normform;
in "../src/normform.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(locate multf ordp ordp reordop subs3f1), 'lose);
remflag('(getrtype maprint multf multf multfnc ordop), 'lose);

faslout 'noncom2;
in "../src/noncom2.red"$
faslend;
faslout 'physop;
in "../src/physop.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(equalreval listeval opfneval opmtch rinsert simpiden), 'lose);

faslout 'pm;
in "../src/pm.red"$
faslend;
faslout 'pmrules;
in "../src/pmrules.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'randpoly;
in "../src/randpoly.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'reacteqn;
in "../src/reacteqn.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'reset;
in "../src/reset.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(get!* texlet varpri), 'lose);
faslout 'rlfi;
in "../src/rlfi.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'residue;
in "../src/residue.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'rsolve;
in "../src/rsolve.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'sets;
in "../src/sets.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'symaux;
in "../src/symaux.red"$
faslend;
faslout 'symmetry;
in "../src/symmetry.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

remflag('(texlet), 'lose);

faslout 'tri;
in "../src/tri.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'trigsimp;
in "../src/trigsimp.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'wu;
in "../src/wu.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'xcolor;
in "../src/xcolor.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'xideal;
in "../src/xideal.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'zeilberg;
in "../src/zeilberg.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'ztrans;
in "../src/ztrans.red"$
faslend;

lisp restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env, !&optional, checksum, !&rest, r);
    if null r then flag(list name, 'lose);
load!-module 'user;

faslout 'gnuplot;
in "../cslsrc/gnuplot.red"$
faslend;

lisp restart!-csl t;
symbolic;

on comp;

faslout 'makehelp;

module helpdata;

global '(!*force);
flag('(force),'switch);
flag('(on),'eval);
on force;

symbolic procedure formhelp(u,vars,mode);
   list('help, 'list . for each x in cdr u collect mkquote x);

if member('help, lispsystem!*) then <<
   put('help, 'stat, 'rlis);
   flag('(help), 'go);
   put('help, 'formfn, 'formhelp) >>;

off force;
remflag('(on),'eval);

endmodule;

faslend;

quit;

