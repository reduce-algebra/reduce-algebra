
%
% Create fasl files for compiler, ccomp and extras and build a jlisp
% checkpoint image for a system that includes them.
%
% Run this using
%           jlisp -z build0.lsp -l build0.log
%


(verbos 3)

(rdf "compat.lsp")
(rdf "extras.lsp")
(rdf "compiler.lsp")

% (clear_source_database)

% First I compile those things that appear to be most heavily used in the
% compiler. This should speed up the whole bootstrap compilation process

% (compile '(
%    s!:improve s!:literal_order s!:comval s!:outopcode0
%    s!:plant_basic_block s!:remlose s!:islocal
%    s!:is_lose_and_exit s!:comatom s!:destination_label
%    s!:record_literal s!:resolve_labels s!:expand_jump
%    s!:outopcode1lit stable!-sortip s!:iseasy s!:outjump
%    s!:add_pending s!:comcall s!:resolve_literals))
%
% (compile!-all)

% Build fasl files for the compatibility code and the two
% versions of the compiler.

% (clear_source_database)

%
%(faslout 'compat)
%(rdf "$cslbase/compat.lsp")
%(rdf "$cslbase/extras.lsp")
%(faslend)
%
%(faslout 'compiler)
%(rdf "$cslbase/compiler.lsp")
%(faslend)
%
%(faslout 'ccomp)
%(rdf "$cslbase/ccomp.lsp")
%(faslend)
%
%(bytecounts)
%
%(save_source_database "$cslbase/whereis.lsp")

%
% (restart-csl nil) is a fairly dramatic, and maybe dangerous function.  It
% abandons all existing Lisp data and restarts the system from scratch,
% with only minimal built-in functionality.
%

%(restart!-csl nil)
%
%(load!-module 'compat)
%
%(setq !*comp nil)
%
%(set!-autoload 'compile      'compiler)
%(set!-autoload 'compile!-all 'compiler)
%(set!-autoload 'faslout      'compiler)
%(set!-autoload 'c_out        'compiler)
%

(setq !*comp nil)

(preserve)

