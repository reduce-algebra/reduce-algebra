%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:FLUID-GLOBAL.SL 
% Description:  Fluid, Global binding 
% Author:       Eric Benson 
% Created:      
% Modified:     20-Jun-84 11:25:39 
% Mode:         Lisp 
% Package:      
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 20-Jun-84 11:25:13 (Jim Ambras/CRC)
%  Changed a local from x to y to avoid fluid binding.
% 01-Dec-83 14:47:43 (Brian Beach)                                         
%   Translated from Rlisp to Lisp.                                         
%                                                                          
%  <PSL.INTERP>FLUID-GLOBAL.RED.3, 10-Sep-82 09:18:04, Edit by BENSON      
%  Uses indicator VARTYPE instead of TYPE                                  
%  <PSL.INTERP>FLUID-GLOBAL.RED.3, 22-Jan-82 12:35:25, Edit by BENSON      
%  GlobalP now only checks for variables, not functions                    
% The functions dealing with FLUID and GLOBAL declarations use the property
% list indicator TYPE, which is also used by PUTD and GETD.                
% Not true anymore!                                                        
% Non-Standard Lisp functions used:                                        
% ErrorPrintF -- in IO.RED                                                 
%                                                                          
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
(compiletime
  (flag '(declarefluidorglobal declarefluidorglobal1) 'internalfunction))

(de declarefluidorglobal (idlist fg)
  (foreach u in idlist do (declarefluidorglobal1 u fg)))

(de declarefluidorglobal1 (u fg)
  (when (idp u)
    (let ((y (get u 'vartype)))
      (cond ((null y) (put u 'vartype fg) 
	     (when (unboundp u)
	       (set u nil)))
	    ((eq y fg) nil)
	    (t 
	     (errorprintf "*** %p %r cannot become %p" y u fg))))))

(de fluid (idlist)
  % Declare all in IDList as fluid vars                                   
  (declarefluidorglobal idlist 'fluid))

(de fluid1 (u)
  % Declare U fluid                                                       
  (declarefluidorglobal1 u 'fluid))

(de fluidp (u)
  % Is U a fluid variable?                                                
  (equal (get u 'vartype) 'fluid))

(de global (idlist)
  % Declare all in IDList as global vars                                  
  (declarefluidorglobal idlist 'global))

(de global1 (u)
  % Declare U global                                                      
  (declarefluidorglobal1 u 'global))

(de globalp (u)
  % Is U a global variable                                                
  (equal (get u 'vartype) 'global))

(de unfluid (idlist)
  % Undeclare all in IDList as fluid                                      
  (foreach u in idlist do (unfluid1 u)))

(de unfluid1 (u)
  (when (fluidp u)
    (remprop u 'vartype)))

