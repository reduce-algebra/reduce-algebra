%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:LASTKERNEL.SL
% Description:  A function to mark the end of kernel code space
% Author:       Cris Perdue, Hewlett-Packard Laboratories
% Created:      17-Oct-84
% Modified:     17-Oct-84 14:45:24 (Cris Perdue)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions
%  27-Aug-88 (Julian Padget)
%   WLESSP in the first conjunction had an extra x making three arguments
%   and giving rise to the wrong answer.  Removed.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(bpslowerbound nextbps))

% Predicate that takes an address and returns non-NIL iff the
% address points into an area where compiled code is kept.  For
% use by returnaddressp.  Key property is dereferencing the
% pointer will result in addressing nonexistent memory.
(de codeaddressp (x)
  (setq x (inf x))
  (or (and (wleq (inf (getfcodepointer 'firstkernel)) x)
	   (wlessp x (inf (getfcodepointer 'lastkernel))))
      (and (wleq (inf bpslowerbound) x)
	   (wlessp x (inf nextbps)))))


% Dummy for use by codeaddressp
(de lastkernel (x) x)

