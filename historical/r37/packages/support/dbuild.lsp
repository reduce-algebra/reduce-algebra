% Build a CSL REDUCE "in core" as first stage of a bootstrap.  To be
% run starting from a cold-start CSL, i.e. with the -z option.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%           smallred -z dbuild.lsp -l dbuild.log
%
% where this job rebuilds a bootstrap REDUCE etc etc from scratch
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

(rdf "$reduce/lisp/csl/cslbase/compat.lsp")
(rdf "$reduce/lisp/csl/cslbase/extras.lsp")
(rdf "$reduce/lisp/csl/cslbase/compiler.lsp")

% Now be brave and compile the compiler - I hand-compile the
% most speed-critical functions first

(compile '(s!:resolve!_labels s!:plant!_basic!_block s!:tidy!_flowgraph
	   s!:endprocedure s!:outopcode1 s!:outjump s!:findliteral
           s!:destination!_label s!:compile1 s!:outoperation
           s!:add!_pending s!:iseasy s!:set!_label s!:outextend
           s!:start!_procedure s!:outexit))

(compile!-all)

% Finally build fasl files for the compatibility code and the two
% versions of the compiler.

(faslout 'compat)
(rdf "$reduce/lisp/csl/cslbase/compat.lsp")
(rdf "$reduce/lisp/csl/cslbase/extras.lsp")
(faslend)

(faslout 'compiler)
(rdf "$reduce/lisp/csl/cslbase/compiler.lsp")
(faslend)

(faslout 'ccomp)
(rdf "$reduce/lisp/csl/cslbase/ccomp.lsp")
(faslend)

(de concat (u v)
    (compress (cons '!" (append (explode2 u)
			 (nconc (explode2 v) (list '!"))))))

(global '(oldchan!*))

(setq prolog_file 'cslprolo)

(setq rend_file 'cslrend)

(setq oldchan2!*
   (rds (setq oldchan!* (open "$reduce/packages/support/dbuild2.sl" 'input))))
				      % CSL independent code.
(close oldchan!*)

(setq !*savedef nil)

(begin)

symbolic;

faslout "remake";
in "$reduce/packages/support/remake.red"$
faslend;

<< initreduce();
   date!* := "Bootstrap version";
% I call mapstore() here to reset all counts to zero,
% thereby making future statistics at least marginally meaningful!
   mapstore 4;
   !*savedef := nil;
   preserve 'begin >>;

% End of dbuild.lsp.
