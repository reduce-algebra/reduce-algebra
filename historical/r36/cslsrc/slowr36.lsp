%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%           csl -z -o slowr36.img build36.lsp -l build1.log
%
% where this job rebuilds a bootstrap REDUCE etc etc from scratch
%
%
% Build a CSL REDUCE "in core" as first stage of a bootstrap.  To be
% run starting from a cold-start CSL, i.e. with the -z option.
%
% This file first builds REDUCE, it then makes a set of FASL modules
% for auto-loadable parts of the system, compiles a load of Lisp into
% C and processes the Lisp interface code generated in the process.
%
% Here I build modules for all the things that will be included in the
% demonstration version of REDUCE, and all the parts of the code that
% will be subject to compilation into C.
%

% Author: Anthony C. Hearn.
%         Modifications by Stanley L. Kameny and Arthur Norman

(verbos 3)

(rdf "$cslbase/compat.lsp")
(rdf "../cslsrc/fastgets.lsp")
(rdf "$cslbase/extras.lsp")

(fluid '(!*ord))
(setq !*ord t)

(rdf "$cslbase/compiler.lsp")

(compile '(
    s!:improve s!:literal_order s!:comval s!:outopcode0
    s!:plant_basic_block s!:remlose s!:islocal
    s!:is_lose_and_exit s!:comatom s!:destination_label
    s!:record_literal s!:resolve_labels s!:expand_jump
    s!:outopcode1lit stable!-sortip s!:iseasy s!:outjump
    s!:add_pending s!:comcall s!:resolve_literals))

(compile!-all)

% Build fasl files for the compatibility code and the two
% versions of the compiler.

(faslout 'compat)
(rdf "$cslbase/compat.lsp")
(rdf "../cslsrc/fastgets.lsp")
(rdf "$cslbase/extras.lsp")
(faslend)

(faslout 'compiler)
(rdf "$cslbase/compiler.lsp")
(faslend)

(faslout 'ccomp)
(rdf "$cslbase/ccomp.lsp")
(faslend)

(setq !*nocompile nil)
(cond ((not !*nocompile) (setq !*comp t)))

% The curious arrangement of rds and oldchan!* is because the
% source file ../src/boot.sl ends by doing an (rds oldchan!*), which
% avoids it hitting the end of file, and probably fits PSL very well.
% If that line were not there I could just go (rdf "../src/boot.sl")
% and that would cope with the file closing as well.

(rds (setq oldchan!* (rds nil)))

(rds (setq xxx (open "../src/boot.sl" 'input)))

(close xxx)

(begin2)

% "cslprolo.red" can contain things that are system dependent
% but which HAVE to be loaded before "rlisp.red" is.

rds(xxx := open("../src/cslprolo.red",'input));

(close xxx)

(begin2)

rds(xxx := open("../src/module.red",'input));

(close xxx)

(begin2)

rds(xxx := open("../src/rlisp.red",'input));

(close xxx)

(begin2)

% "cslrend.red" contains CSL specific definitions of a few functions
% required by Reduce, and can flag things as 'lose where that will help
% performance by allowing versions of functions built into the CSL kernel
% to remain active.

rds(xxx := open("../src/cslrend.red",'input));

(close xxx)

(begin)

% Now I have RLISP built I can dispense with all the fooling about with
% rds and open, and just read files in using the regular (in "xxx.red")
% syntax.  I build all the parts of REDUCE that are expected to be
% resident.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% HORRIBLE WARNING:
%     The system build in-store here will NOT have patches applied to it.
%     The fasl files written out WILL be subject to patching, but
%     if building the first few modules correctly depends on running
%     with a patched version then you are in trouble.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

on backtrace;

% The bad news is that module "poly.red" uses some of these, but they
% are defined in "alg.red". But if I try to load "alg.red" first I run
% into trouble with the operators ".+" etc...

symbolic smacro procedure iequal(u,v); eqn(u,v);

newtok '((!#) hash);
newtok '((!# !+) iplus2);
newtok '((!# !-) idifference);
newtok '((!# !*) itimes2);
newtok '((!# !/) iquotient);
newtok '((!# !>) igreaterp);
newtok '((!# !<) ilessp);
newtok '((!# !=) iequal);

infix #+,#-,#*,#/,#>,#<,#=;

precedence #+,+;
precedence #-,-;
precedence #*,*;
precedence #/,/;
precedence #>,>;
precedence #<,<;
precedence #=,=;

deflist('((idifference iminus)),'unary);

deflist('((iminus iminus)),'unary);

deflist('((iminus iplus2)), 'alt);

in "../src/poly.red"$

in "../src/alg.red"$

in "../src/arith.red"$

in "../src/mathpr.red"$

on savedef;  % Now I start on the FASL files - I want saved defs in them all
             % since the saved definitions will be used when speed-critical
             % parts of the system are to be compiled into C.

faslout 'cslprolo;
in "../src/cslprolo.red"$
faslend;

faslout 'module;
in "../src/module.red"$

module 'cslpatch;

% Support for patching REDUCE 3.6 sources.....
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

load!-module 'module;   % Patched version MUST be loaded before patches.red

faslout 'patches;
in "../src/patches.red"$
faslend;

% Note that even though I have now read in the patches, they do not get
% applied unless a module is loaded using "load_package".  Thus the
% patches are not yet in effect.

faslout 'rlisp;
in "../src/rlisp.red"$
faslend;

faslout 'cslrend;
in "../src/cslrend.red"$
faslend;

faslout 'alg;
in "../src/alg.red"$
faslend;

faslout 'poly;
in "../src/poly.red"$
faslend;

faslout 'mathpr;
in "../src/mathpr.red"$
faslend;

faslout 'arith;
in "../src/arith.red"$
faslend;

faslout 'entry;
in "../src/entry.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil)

(load!-module 'compat)
(load!-module 'cslprolo)
(load!-module 'module)
(load!-module 'patches)
(setq loaded!-packages!* '(compat cslprolo module patches))
(load!-package 'rlisp)
(load!-package 'cslrend)
(load!-package 'poly)
(load!-package 'alg)
(load!-package 'arith)
(load!-package 'mathpr)
(setq !*comp nil)
(load!-package 'entry)
(setq !*nocompile nil)
(setq !*comp (not !*nocompile))

(begin)
symbolic;

<< initreduce();
   date!* := "Bootstrap version";
   % I call mapstore() here to reset all counts to zero,
   % thereby making future statistics at least marginally meaningful!
   mapstore 4;
   !*savedef := nil;

   checkpoint('begin, "Bootstrap REDUCE 3.6...") >>;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% I build each module (from now on) with a cleanly-restarted version of
% REDUCE so that if the module sets flags or changes syntax etc etc that
% can not cause trouble for further system-building.  This seems an ugly
% state of affairs but is essential at present.  An effect will be that
% patches get applied when the modules are loaded, so from now on the
% modules built should be safe.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic; on savedef;

faslout 'fmprint;
in "../cslsrc/fmprint.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'matrix;
in "../src/matrix.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'hephys;
in "../src/hephys.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'arnum;
in "../src/arnum.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'cedit;
in "../src/cedit.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'compact;
in "../src/compact.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'excalc;
in "../src/excalc.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'ezgcd;
in "../src/ezgcd.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'factor;
in "../src/factor.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'gentran;
in "../src/gentran.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'dipoly;
in "../src/dipoly.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'groebner;
in "../src/groebner.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'groebnr2;
in "../src/groebnr2.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'int;
in "../src/int.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'algint;
in "../src/algint.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'pretty;
in "../src/pretty.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'rcref;
in "../src/rcref.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'numeric;
in "../src/numeric.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'roots;
in "../src/roots.red"$
faslend;
faslout 'roots2;
in "../src/roots2.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'rprint;
in "../src/rprint.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'scope;
in "../src/scope.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'solve;
in "../src/solve.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'spde;
in "../src/spde.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'taylor;
in "../src/taylor.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'tps;
in "../src/tps.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'misc;
in "../src/misc.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'odesolve;
in "../src/odesolve.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'avector;
in "../src/avector.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'rlisp88;
in "../src/rlisp88.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

faslout 'orthovec;
in "../src/orthovec.red"$
faslend;

lisp restart!-csl t;
symbolic; on savedef;

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

quit;

% end of slowr36.lsp
