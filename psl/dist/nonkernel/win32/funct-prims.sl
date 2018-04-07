%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:FUNCTION-PRIMITIVES.SL
% Title:          Primitives used by PUTD/GETD and EVAL/APPLY              
% Author:         Eric Benson, Steve Lowder                                
% Created:        23 August 1981                                           
% Modified:       11-May-84 07:39:28 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp                                                     
% Package:        Kernel                                                   
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
% 27-Mar-84 13:56:06 (Jim Ambras/CRC)
%  Changed use of idloc to id2int.  Added compiletime load of sys-consts.
% 02-Mar-84 09:19:52 (Jim Ambras/CRC)                                      
%  Corrected file header.                                                  
% 13-Dec-83 12:27:47 (Tim Tillson)                                         
%  Modified for the D-register model; plant routines moved to LAP.SL       
% 02-Dec-83 10:14:03 (Jim Ambras)                                          
%   Translated from Rlisp to Lisp.                                         
% 15-Jul-83 Steve Lowder                                                   
%  Changed three *WTimes2 expressions for (WConst 6) to adds because *WTimes2
%  is no longer a cmacro.                                                  
% 1-Jul-83 Steve Lowder                                                    
%  Changed expressions (displacement (reg 1) 0) to (indirect (reg 1)) to   
%  improve code generation.                                                
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%                                                                          
%                                                                          
% Every ID has a "function cell".  It does not necessarily contain a legal 
% Lisp item, and therefore should not be accessed directly by Lisp functions.
                                                                           
% In this implementation the function cell contains an instruction to be   
% executed.  There are 3 possibilites for this instruction, for which the  
% following predicates and updating functions exist:                       
%                                                                          
%FUnBoundP(ID) -- the function is not defined                              
%FLambdaLinkP(ID) -- the function is interpreted                           
%FCodeP(ID) -- the function is compiled                                    
%                                                                          
%MakeFUnBound(ID) -- undefine the function                                 
%MakeFLambdaLink(ID) -- specify that the function is interpreted           
%MakeFCode(ID, CodePtr) -- specify that the function is compiled,          
%   and that the code resides at the address                               
%   associated with CodePtr                                                
%                                                                          
%GetFCodePointer(ID) -- returns the contents of the function cell as a     
%code pointer                                                              
% These functions currently check that they have proper arguments, but this may
                                                                           
% change since they are only used by functions that have checked them already.
                                                                           
(compiletime (load sys-consts))

(fluid '(lamlnk undefn))

(setq lamlnk 
  (getmem (wplus2 symfnc (wtimes2 (id2int 'compiledcallinginterpreted) 
		                       addressingunitsperfunctioncell))))

(setq undefn 
      (getmem (wplus2 symfnc (wtimes2 (id2int 'undefinedfunction) 
                                        addressingunitsperfunctioncell))))

(de funboundp (u)
  % does U not have a function defn?                                      
  (if (idp u)
    (weq (symfnc (idinf u)) undefn)
    (noniderror u 'funboundp)))

(de flambdalinkp (u)
  % is U an interpreted function?                                         
  (if (idp u)
    (weq (symfnc (idinf u)) lamlnk)
    (noniderror u 'flambdalinkp)))

(de fcodep (u)
  % is U a compiled function?                                             
  (if (idp u)
    (and (wneq (symfnc (idinf u)) undefn) (wneq (symfnc (idinf u)) lamlnk))
    (noniderror u 'fcodep)))

(de makefunbound (u)
  % Make U an undefined function                                          
  (if (idp u)
    (progn (plantunbound (idinf u))
           nil)
    (noniderror u 'makefunbound)))

(de makeflambdalink (u)
  % Make U an interpreted function                                        
  (if (idp u)
    (progn (plantlambdalink (idinf u))
           nil)
    (noniderror u 'makeflambdalink)))

(de makefcode (u codeptr)
  % Make U a compiled function                                            
  (when (idp u)
    (if (codep codeptr)
      (progn (plantcodepointer (idinf u) (inf codeptr))
             nil)
      (noniderror u 'makefcode))))

(de getfcodepointer (u)
  % Get code pointer for U                                                
  (if (idp u)
    (mkcode (symfnc (idinf u)))
    (noniderror u 'getfcodepointer)))

