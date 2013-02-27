%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:SYMBOL-VALUES.SL
% Title:          ValueCell, UnboundP, MakeUnbound and Set
% Author:         Eric Benson
% Created:        20 August 1981
% Modified:       29-Aug-84 11:02:05 (Brian Beach)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:02:42 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(kernel-maxsymbols old_symval))

(de unboundp (u)
  % Does U not have a value?
  (if (idp u)
    (if (wgreaterp (idinf u) kernel-maxsymbols)
        (weq (tag (symval (idinf u))) unbound-tag)
        (weq (tag (wgetv old_symval (idinf u))) unbound-tag))
    (noniderror u 'unboundp)))

(de makeunbound (u)
  % Make U an unbound ID
  (if (idp u)
    (if (wgreaterp (idinf u) kernel-maxsymbols)
                 (setf (symval (idinf u)) (mkitem unbound-tag (idinf u)))
                 (setf (wgetv old_symval (idinf u))
				 (mkitem unbound-tag (idinf u))))
    (noniderror u 'makeunbound)))

(de valuecell (u)
  % Safe access to SymVal entry
  (prog (v)
        % This guy is called from Eval
        (return (if (idp u)
                  (progn (setq v (if (wgreaterp (idinf u) kernel-maxsymbols)
       				 (symval (idinf u))
	                         (wgetv old_symval (idinf u))))
                         (if (weq (tag v) unbound-tag)
                           (continuableerror '99
                            (bldmsg '"%r is an unbound ID" u) u)
                           v))
                  (noniderror u 'valuecell)))))

% This version of SET differs from the Standard Lisp report in that Exp is
% not declared fluid, in order to maintain compatibility between compiled
% and interpreted code.
(de set (exp val)
  % Assign Val to ID Exp
  (if (idp exp)
    (if (not (or (null exp) (weq exp 't)))
      (progn (if (wgreaterp (idinf exp) kernel-maxsymbols)
                         (setf (symval (idinf exp)) val)
                         (setf (wgetv old_symval (idinf exp)) val))
             val)
      (stderror '"T and NIL cannot be SET"))
    (noniderror exp 'set)))

