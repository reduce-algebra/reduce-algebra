%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-GC.SL                                             
% Title:          System dependent before and after GC hooks               
%                 Based on VAX version.                                    
% Author:         Eric Benson                                              
% Created:        5 March 1982                                             
% Modified:       29-Oct-84 09:08:15 (Vicki O'Day)
% Status:         Experimental                                             
% Mode:           Lisp                                                     
% Package:        Kernel                                                   
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% Copyright (c) 1982 Eric Benson                                           
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          
% Revisions:                                                               
%                                                                          
% 9-Jul-84 (Vicki O'Day)
%  Changed hooks be defined bothtimes instead of compiletime.
% 27-Feb-84 17:29:47 (RAM)                                                 
%  Changed File entry in header.                                           
%  Made the hooks just nil.                                                
% 2-Dec-83  16:00:00 (Brian Beach)                                         
%   Translated from Rlisp to Lisp.                                         
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%                                                                          
(fluid '(safearithargs!*0 safearithargs!*1))

(de internal_beforegcsystemhook nil
      (setq safearithargs!*0 (wgetv arithargloc 0 )
            safearithargs!*1 (wgetv arithargloc 1 ))
      nil)

(de internal_aftergcsystemhook nil
         (wputv arithargloc 0 safearithargs!*0)
         (wputv arithargloc 1 safearithargs!*1)
      (setq safearithargs!*0 NIL safearithargs!*1 nil)
     nil)

(de beforegcsystemhook nil
   (unless (or  (funboundp 'beforegcuserhook)
                (flambdalinkp 'beforegcuserhook))
        (beforegcuserhook))
    nil)

(de aftergcsystemhook nil
    (unless (or (funboundp 'aftergcuserhook)
                (flambdalinkp 'aftergcuserhook))
        (aftergcuserhook))
     nil)


