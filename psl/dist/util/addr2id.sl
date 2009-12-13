%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:ADDR2ID.SL 
% Description:  Attempt to find out what function an address is in 
% Author:       Eric Benson, Hewlett-Packard CRC 
% Created:      18 May 1982 
% Modified:     19 Jan 1984 1428-PST (Brian Beach) 
% Status:       Experimental (Do Not Distribute) 
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:SYSLISP.B PL:USEFUL.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 19 Jan 1984 1428-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load useful))

(compiletime (fluid '(code-address* closest-address* closest-symbol*)))

(de code-address-to-symbol (code-address*)
  (let ((closest-symbol* ()) (closest-address* 0))
       (mapobl #'(lambda (symbol)
		         (when (fcodep symbol)
			       (let ((address (inf (getfcodepointer symbol))))
				    (when (and (ileq address
						     code-address*)
					       (igreaterp address
							  closest-address*))
					  (setq closest-address*
						address)
					  (setq closest-symbol* symbol))))))
       closest-symbol*))
