%
%           smallr35 -I- -Ofullimage build2.red
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

in "../cslsrc/patches.red"$

symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
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
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'cslprolo;
in "../cslsrc/cslprolo.red"$
faslend;

restart!-csl t;
symbolic;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'patches;
in "../cslsrc/patches.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'rlisp;
in "../src/rlisp.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'cslrend;
in "../cslsrc/cslrend.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'poly;
in "../src/poly.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'alg;
in "../src/alg.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'mathpr;
in "../src/mathpr.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'arith;
in "../src/arith.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'cslentry;
in "../cslsrc/cslentry.red"$
faslend;

%
% The ones that follow will be copied are FASL files into the final image
%

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'matrix;
in "../src/matrix.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'hephys;
in "../src/hephys.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(glsolterm mkglsol), 'lose);

faslout 'arnum;
in "../src/arnum.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'cedit;
in "../src/cedit.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'compact;
in "../src/compact.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(clear oddp), 'lose);

faslout 'excalc;
in "../src/excalc.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'ezgcd;
in "../src/ezgcd.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'factor;
in "../src/factor.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'gentran;
in "../src/gentran.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'dipoly;
in "../src/dipoly.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(subsetp), 'lose);

faslout 'groebner;
in "../src/groebner.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'groebnr2;
in "../src/groebnr2.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'int;
in "../src/int.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(subsetp), 'lose);

faslout 'algint;
in "../src/algint.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'pretty;
in "../src/pretty.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'rcref;
in "../src/rcref.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'numeric;
in "../src/numeric.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'roots;
in "../src/roots.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(rprint), 'lose);

faslout 'rprint;
in "../src/rprint.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(getcind), 'lose);

faslout 'scope;
in "../src/scope.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(evalletsub2 glsolterm mkglsol), 'lose);

faslout 'solve;
in "../src/solve.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(degreef ordp), 'lose);

faslout 'spde;
in "../src/spde.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'specfn;
in "../src/specfn.red"$
faslend;
faslout 'specfn2;
in "../src/specfn2.red"$
faslend;
faslout 'specfaux;
in "../src/specfaux.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(simptaylor), 'lose);

faslout 'taylor;
in "../src/taylor.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'tps;
in "../src/tps.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'misc;
in "../src/misc.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'odesolve;
in "../src/odesolve.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(getrtype1 getrtype2 locate rcons rcons varpri), 'lose);

faslout 'avector;
in "../src/avector.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

remflag('(depend maprin nodepend), 'lose);

faslout 'rlisp88;
in "../src/rlisp88.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
symbolic procedure c!:install(name, env);
    flag(list name, 'lose);
load!-module 'user;

faslout 'orthovec;
in "../src/orthovec.red"$
faslend;

restart!-csl t;
symbolic; load!-module 'patches;
remflag('(evenp lengthreval natnumlis oddp
          rappend rcons rfirst rinsert rmember
          rrest rreverse rsecond rthird unitmat), 'lose);

faslout 'assist;
in "../lib/assist.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(flatten subsetp unitmat), 'lose);

faslout 'cali;
in "../lib/cali.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'camal;
in "../lib/camal.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(diffp), 'lose);

faslout 'changevr;
in "../lib/changevr.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(freeof), 'lose);

faslout 'crack2;
in "../lib/crack2.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(freeof), 'lose);

faslout 'crack;
in "../lib/crack.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(isimp1), 'lose);

faslout 'cvit;
in "../lib/cvit.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'desir;
in "../lib/desir.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(maxorder simptaylor), 'lose);

faslout 'fide1;
in "../lib/fide1.red"$
faslend;
load_package fide1,gentran;
faslout 'fide;
in "../lib/fide.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'ideals;
in "../lib/ideals.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'laplace;
in "../lib/laplace.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remprop('help, 'stat);  % Because lie.red uses "help" as a variable name
                        % and I am not allowed to change that in the source.
                        % Anybody who tries to recompile lie.red other than
                        % via this file "watch out".
                        % Actually it is more complicated than that, since I
                        % will usually run this re-build job using "smallr35"
                        % and I do not build the help mechanism into that.

faslout 'lie;
in "../lib/lie.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'linineq;
in "../lib/linineq.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(locate multf ordp ordp reordop subs3f1), 'lose);
remflag('(getrtype maprint multf multf multfnc ordop), 'lose);

faslout 'noncom2;
in "../lib/noncom2.red"$
faslend;
faslout 'physop;
in "../lib/physop.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(equalreval listeval opfneval opmtch rinsert simpiden), 'lose);

faslout 'pm;
in "../lib/pm.red"$
faslend;
faslout 'pmrules;
in "../lib/pmrules.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'reacteqn;
in "../lib/reacteqn.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'reset;
in "../lib/reset.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(get!* texlet varpri), 'lose);
faslout 'rlfi;
in "../lib/rlfi.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'symmetry;
in "../lib/symmetry.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

remflag('(texlet), 'lose);

faslout 'tri;
in "../lib/tri.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'wu;
in "../lib/wu.red"$
faslend;

lisp restart!-csl t;
symbolic; load!-module 'patches;

faslout 'gnuplot;
in "../plot/gnuplot.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

on comp;

% Note: "cslhelp.red" defines some macros that must be present while
% this version of REDUCE is being built, but the macros themselves do not
% want to go in any fasl file - only the result of expanding them.

in "../cslsrc/cslhelp.red"$

faslout 'makehelp;

module helpdata;

global '(!*force);
flag('(force),'switch);
flag('(on),'eval);
on force;

symbolic procedure formhelp(u,vars,mode);
   list('help, 'list . for each x in cdr u collect mkquote x);

make_help "../cslsrc/helpdata";

if member('help, lispsystem!*) then <<
   put('help, 'stat, 'rlis);
   flag('(help), 'go);
   put('help, 'formfn, 'formhelp) >>;

off force;
remflag('(on),'eval);

endmodule;

faslend;

quit;

