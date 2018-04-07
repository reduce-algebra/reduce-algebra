%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:AUTOLOAD.SL 
% Title:        Autoloading entry stubs 
% Author:       Eric Benson 
% Created:      25 March 1982 
% Modified:     22-Mar-84 09:12:15 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:IF-SYSTEM.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22-Mar-84 09:12:03 (Brian Beach)
%  Added compiletime load of if-system.
% 01-Dec-83 14:11:24 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(compiletime
  (progn (dm defautoload (u)
           %
           % (DefAutoload name), (DefAutoload name loadname),
           % (DefAutoload name loadname fntype), or
           % (DefAutoload name loadname fntype numargs)
           %
           % Default is 1 Arg EXPR in module of same name
           %
           (prog (name numargs loadname fntype)
                 (setq u (rest u))
                 (setq name (first u))
                 (setq u (rest u))
                 (if (not (null u))
                   (progn (setq loadname (first u))
                          (setq u (rest u)))
                   (setq loadname name))
                 (when (eqcar name 'quote)
                   (setq name (second name)))
                 (when (eqcar loadname 'quote)
                   (setq loadname (second loadname)))
                 (if (not (null u))
                   (progn (setq fntype (first u))
                          (setq u (rest u)))
                   (setq fntype 'expr))
                 (if (not (null u))
                   (setq numargs (first u))
                   (setq numargs 1))
                 (setq numargs (makearglist numargs))
                 (return (list 'progn
                          (list 'put (mkquote name)
                           (mkquote 'auto-load-form)
                           (list 'list (length numargs) (mkquote fntype)
                            (mkquote loadname)))
                          (list 'putd (mkquote name) (mkquote fntype)
                           (list 'function
                            (list 'lambda numargs (list 'load loadname)
                             (list 'apply (mkquote name)
                              (cons 'list numargs)))))))))
         (de print-autoloads ()
           (mapobl (function print-autoloads-aux)))
         (de print-autoloads-aux (name)
           (prog (f)
                 (when (setq f (get name 'auto-load-form))
                   (errorprintf
                    "Function %p, a %p argument %p, autoloads from module %p%n"
                    name (first f) (second f) (third f)))))
         (de makearglist (n)
           (getv '[nil (x1) (x1 x2) (x1 x2 x3) (x1 x2 x3 x4)
                   (x1 x2 x3 x4 x5)]
                 n))
         nil))

(defautoload prettyprint pp)

(defautoload pp pp macro)

(defautoload step)

(put 'syslisp 'simpfg '((t (load syslisp))))

(defautoload compd compiler expr 3)

(defautoload faslout compiler)

%% End of File.
