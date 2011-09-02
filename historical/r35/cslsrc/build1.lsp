%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%           smallr35 -z build1.lsp -l build1.log
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
(rdf "$cslbase/extras.lsp")
(rdf "$cslbase/compiler.lsp")

% Now be brave and compile the compiler - I hand-compile the
% most speed-critical functions first

(compile '(s!:resolve!_labels s!:plant!_basic!_block s!:tidy!_flowgraph
           s!:endprocedure s!:outopcode1 s!:outjump
           s!:destination!_label s!:compile1 s!:outoperation
           s!:add!_pending s!:iseasy s!:set!_label s!:outextend
           s!:start!_procedure s!:outexit))

(compile!-all)

% Build fasl files for the compatibility code and the two
% versions of the compiler.

(faslout 'compat)
(rdf "$cslbase/compat.lsp")
(rdf "$cslbase/extras.lsp")
(faslend)

(faslout 'compiler)
(rdf "$cslbase/compiler.lsp")
(faslend)

(faslout 'ccomp)
(rdf "$cslbase/ccomp.lsp")
(faslend)

(setq !*comp t)

% The curious arrangement of rds and oldchan!* is because the
% source file ../src/boot.sl ends by doing an (rds oldchan!*), which
% avoids it hitting the end of file, and probably fits PSL very well.
% If that line were not there I could just go (rdf "$cslbase/../src/boot.sl")
% and that would cope with the file closing as well.

(rds (setq oldchan!* (rds nil)))

(rds (setq xxx (open "../src/boot.sl" 'input)))

(close xxx)

(begin2)

% "cslprolo.red" can contain things that are system dependent
% but which HAVE to be loaded before "rlisp.red" is.

rds(xxx := open("../cslsrc/cslprolo.red",'input));

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

rds(xxx := open("../cslsrc/cslrend.red",'input));

(close xxx)

(begin)

% Now I have RLISP built I can dispense with all the fooling about with
% rds and open, and just read files in using the regular (in "xxx.red")
% syntax.  I build all the parts of REDUCE that are expected to be
% resident.

on backtrace;

in "../src/poly.red"$

in "../src/alg.red"$

in "../src/arith.red"$

in "../src/mathpr.red"$

on savedef;  % Now I start on the FASL files - I want saved defs in them all
             % since the saved definitions will be used when speed-critical
             % parts of the system are to be compiled into C.

faslout 'cslprolo;
in "../cslsrc/cslprolo.red"$
faslend;

faslout 'module;
in "../src/module.red"$

module 'cslpatch;

% Support for patching REDUCE 3.5 sources.....
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

faslout 'rlisp;
in "../src/rlisp.red"$
faslend;

faslout 'cslrend;
in "../cslsrc/cslrend.red"$
faslend;

faslout 'poly;
in "../src/poly.red"$
faslend;

faslout 'mathpr;
in "../src/mathpr.red"$
faslend;

faslout 'alg;
in "../src/alg.red"$
faslend;

faslout 'arith;
in "../src/arith.red"$
faslend;

faslout 'cslentry;
in "../cslsrc/cslentry.red"$
faslend;

faslout 'loadr35;
rdf "$cslbase/loadr35.lsp"$
faslend;

faslout 'patches;
% I make a dummy version of the patches module here as part of the
% rather delicate bootstrapping procedure.
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'patches;
in "../cslsrc/patches.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'matrix;
in "../src/matrix.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'hephys;
in "../src/hephys.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'arnum;
in "../src/arnum.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'cedit;
in "../src/cedit.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'compact;
in "../src/compact.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'excalc;
in "../src/excalc.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'ezgcd;
in "../src/ezgcd.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'factor;
in "../src/factor.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'gentran;
in "../src/gentran.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'dipoly;
in "../src/dipoly.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'groebner;
in "../src/groebner.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'groebnr2;
in "../src/groebnr2.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'int;
in "../src/int.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'algint;
in "../src/algint.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'pretty;
in "../src/pretty.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'rcref;
in "../src/rcref.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'numeric;
in "../src/numeric.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'roots;
in "../src/roots.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'rprint;
in "../src/rprint.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'scope;
in "../src/scope.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'solve;
in "../src/solve.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'spde;
in "../src/spde.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'specfn;
in "../src/specfn.red"$
faslend;
faslout 'specfn2;
in "../src/specfn2.red"$
faslend;
faslout 'specfaux;
in "../src/specfaux.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'taylor;
in "../src/taylor.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'tps;
in "../src/tps.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'misc;
in "../src/misc.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'odesolve;
in "../src/odesolve.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'avector;
in "../src/avector.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'rlisp88;
in "../src/rlisp88.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

faslout 'orthovec;
in "../src/orthovec.red"$
faslend;

lisp restart!-csl nil;
(setq !*savedef nil) (load!-module 'loadr35) (begin)
symbolic;

<< initreduce();
   date!* := "Bootstrap version";
   % I call mapstore() here to reset all counts to zero,
   % thereby making future statistics at least marginally meaningful!
   mapstore 4;
   !*savedef := nil;

   preserve('begin, "Bootstrap REDUCE 3.5...") >>;

% end of build1.lsp
