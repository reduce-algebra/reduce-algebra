%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:IO-DECLS.SL
% Description:  Declarations of constants and fluids used by I/O.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Mar-84
% Modified:     22-Mar-84 10:48:25 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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

