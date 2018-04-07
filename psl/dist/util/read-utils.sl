%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: READ-UTILS.SL 
% Description:  Read Table Utils 
% Author:       M. L. Griss 
% Created:      28 August 1981 
% Modified:     02-Dec-83 19:03:14 (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
% Notes:        
% Compiletime:  
% Runtime:      
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
% 02-Dec-83 19:03:14 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 7 Jul 1983 1349-PDT, Cris Perdue                                        
%   CopyScanTable fixed to use CopyVector, not Copy.                       
% 20 Apr 1983 1330-PST  Cris Perdue
%   Patched up a bit to work with current scan table format,                 
%   commented out functions that can't possibly work right now.              
% 28 Jan 1983 2040-PST  Cris Perdue
%   Occurrences of dipthong changed to diphthong                             
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(characterclass!*))

(de printscantable (table)
  (prog (i)
        (setq i 0)
        (for (from i 0 127 1) 
             (do (progn (prin1 i)
                        (tab 5)
                        (prin2 (int2id i))
                        (tab 15)
                        (print (indx characterclass!* (indx table i))))))
        (printf " Diphthong    name: %r%n" (indx table 128))))

%/       PrintF(" ReadMacro   name: %r%n",Table[129]);                     
%/       PrintF(" SpliceMacro name: %r%n",Table[130]);                     
%%% Some id names for the classes                                          
(de copyscantable (oldtable)
  (prog nil
        (when (null oldtable)
          (setq oldtable currentscantable!*))
        (cond ((not (and (vectorp oldtable) (equal (upbv oldtable) 128))) %/ 130 ...
                                                                            
               (return (stderror "CopyScanTable expects a valid Readtable"))))
        (setq oldtable (copyvector oldtable))
        (setf (indx oldtable 128) (gensym))
        %/     OldTable[129]:=Gensym();                                    
        %/     OldTable[130]:=Gensym();                                    
        (return oldtable)))

(loadtime
  (progn (setq characterclass!* 
               '[digit digit digit digit digit digit digit digit digit 
                 digit letter delimiter comment diphthong idescape 
                 stringquote package ignore minus plus decimal])
         (put 'letter 'characterclass!* 10)
         (put 'delimiter 'characterclass!* 11)
         (put 'comment 'characterclass!* 12)
         (put 'diphthong 'characterclass!* 13)
         (put 'idescape 'characterclass!* 14)
         (put 'stringquote 'characterclass!* 15)
         (put 'package 'characterclass!* 16)
         (put 'ignore 'characterclass!* 17)
         (put 'minus 'characterclass!* 18)
         (put 'plus 'characterclass!* 19)
         (put 'decimal 'characterclass!* 20)))

(de putcharacterclass (table ch val)
  (changechartype table ch val))

(de changechartype (tbl ch ty)
  %. Set Character type                                                    
  (prog (idnum)
        (when (idp ty)
          (setq ty (get ty 'characterclass!*)))
        (if (and (idp ch) (lessp (setq idnum (id2int ch)) 128) 
                 (numberp ty) (geq ty 0) (leq ty 20))
          (putv tbl idnum ty)
          (error 99 "Cant Set ReadTable"))))

(de putdiphthong (tbl startch followch diphthong)
  (if (and (idp startch) (idp followch) (idp diphthong))
    (progn (changechartype tbl startch 13)
           (put startch (indx tbl 128) 
                (cons (cons followch diphthong) 
                      (get startch (indx tbl 128)))))
    (error 99 "Cant Declare Diphthong")))

(de makediphthong (tbl dipindicator startch followch diphthong)
  (if (and (idp startch) (idp followch) (idp diphthong))
    (progn (changechartype tbl startch 13)
           (put startch dipindicator 
                (cons (cons followch diphthong) (get startch dipindicator))))
    (error 99 "Cant Declare Diphthong")))

% Tables don't currently work this way. /csp                               
% Check Delimiter Class as 11 or 23                                        
%/ Splice macros currently "frowned" upon                                  
% Check Delimiter Class as 11 or 13                                        
