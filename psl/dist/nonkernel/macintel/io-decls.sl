%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:IO-DECLS.SL 
% Description:  Declarations of constants and fluids used by I/O. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      22-Mar-84 
% Modified:     12-Sep-84 11:54:27 (Brian Beach)
% Mode:         Lisp 
% Package:      
% Status:       Experimental (Do Not Distribute) 
% Compile to:   PL:IO-DECLS.B
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 27 Oct 1984 0955-PDT (Brian Beach)
%  Moved to PNK, since this file is machine independant.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(define-constant channelclosed 0)
(define-constant channelopenread 1)
(define-constant channelopenwrite 2)
(define-constant channelopenspecial 3)

(define-constant maxtokensize 5000)

(define-constant maxchannels 31)

(fluid 
 '(
   tokenbuffer
   bufferlength
   nextposition
   channeltable
   maxbuffer
   channelstatus
   maxline
   pageposition
   lineposition
   unreadbuffer
   closefunction
   writefunction
   readfunction
   ))

