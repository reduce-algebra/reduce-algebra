
%
% Create fasl files for compiler, ccomp and extras and build a CSL
% checkpoint image for a system that includes them.
%
% Run this using
%           csl -z build0.lsp -l build0.log
%

%%
%% Copyright (C) 2016, A C Norman, Codemist.                              *
%%                                                                        *
%% Redistribution and use in source and binary forms, with or without     *
%% modification, are permitted provided that the following conditions are *
%% met:                                                                   *
%%                                                                        *
%%     * Redistributions of source code must retain the relevant          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer.                                                      *
%%     * Redistributions in binary form must reproduce the above          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer in the documentation and/or other materials provided  *
%%       with the distribution.                                           *
%%                                                                        *
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
%% DAMAGE.                                                                *
%%




(verbos 3)

(rdf "$cslbase/compat.lsp")
(rdf "$cslbase/extras.lsp")
(rdf (cond
  ((memq 'jlisp lispsystem!*) "$cslbase/compiler-for-jlisp.lsp")
  (t "$cslbase/compiler.lsp")))

(setq !*print!-array!* t)

% First I compile those things that appear to be most heavily used in the
% compiler. This should speed up the whole bootstrap compilation process

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

% I choose to turn the utility functions into native code in
% case performance matters for some of them, but I will leave the
% compiler byte-coded since it generally seems to me to be fast enough
% for most reasonable needs. This is a rather frivolous decision since
% the performance gains are not liable to be huge, but is done mainly
% to illustrate the native compilation scheme and keep some regression
% testing on it.
%
% Well maybe I will not, since that is a way of making things more
% delicate!
%
% (setq !*native_code t)

(faslout 'compat)
(rdf "$cslbase/compat.lsp")
(rdf "$cslbase/extras.lsp")
(faslend)

(setq !*native_code nil)

(faslout 'compiler)
(rdf (cond
  ((memq 'jlisp lispsystem!*) "$cslbase/compiler-for-jlisp.lsp")
  (t "$cslbase/compiler.lsp")))
(faslend)

(bytecounts)

%
% (restart-csl nil) is a fairly dramatic, and maybe dangerous function.  It
% abandons all existing Lisp data and restarts the system from scratch,
% with only minimal built-in functionality.
%

(restart!-csl nil)

(load!-module 'compat)

(fluid '(!*comp !*native_code))

(setq !*comp nil)

(set!-autoload 'compile      'compiler)
(set!-autoload 'compile!-all 'compiler)
(set!-autoload 'faslout      'compiler)
(set!-autoload 'c_out        'compiler)


(when (file!-readablep "stubs.lsp")
   (de c!:install (name env c!-version !&optional c1)
      (cond
        (c1 "unused here")
        (t (progn
              (put name 'c!-version c!-version)
              (cond (env (prog (v n)
                 (setq v (mkvect (sub1 (length env))))
                 (setq n 0)
            top  (cond
                    ((null env) (progn
                     (put name 'funarg v)
                     (return (symbol!-set!-env name v)))))
                 (putv v n (car env))
                 (setq n (add1 n))
                 (setq env (cdr env))
                 (go top))))
              name))))
    (rdf "stubs.lsp"))


% My choice for a Lisp system is to enable full compilation by default.

(setq !*comp t)
(setq !*native_code nil)

% The next line unsets !@cslbase since the gensym will not have a real value.
(setq !@cslbase (setq !@srcdir (symbol!-value (gensym))))

(preserve)

