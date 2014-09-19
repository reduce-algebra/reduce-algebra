%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PVU:GET-OPTIONS.SL
% Description:  Get command line arguments (VAX UNIX version)
% Author:       Cris Perdue
% Created:      April 5, 1983
% Modified:     13-Jan-84 10:09:43 (Brian Beach)
%
% (c) Copyright 1987, University of Utah, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 13-Jan-84 10:08:44 (Brian Beach)
%  Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de get-command-args ()
  (for (from i 1 (size Unixargs*))	% Don't return the zeroeth /csp
       (collect (indx UnixArgs* i))))
