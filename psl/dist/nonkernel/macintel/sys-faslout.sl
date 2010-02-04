%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-FASLOUT.SL
% Title:          68000-specific stuff for FASL at compile time
% Author:         Eric Benson
% Created:        20 February 1982
% Modified:       27-Feb-84 17:04:06 (RAM)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1982, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 27-Feb-84 17:03:53 (RAM)
%  Changed File entry in header.
% 02-Dec-83 10:40:13 (Jim Ambras)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          
% Notes by Maguire:                                                        
% FASL_MAGIC_NUMBER is used to check that the file is in the current FASL  
%                   format, it's current value is 99                       
% None of the operations make any sense, there needs to be some explanatory
% information added for these operation. Enough atleast to be able to test 
% them on the Apollo                                                       

% These declarations are now in fasl-decls
