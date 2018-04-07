%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:VECTOR-FIX.SL 
% Description:  
% Author:       
% Created:      
% Modified:     23-Aug-84 09:30:55 (Brian Beach) 
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
% 23-Aug-84 09:30:25 (Brian Beach)
%  Removed (LOAD SYSLISP) and uses of WCONST.
% 05-Dec-83 18:05:40 (Nancy Kendzierski)
%   Added contents of .BUILD file.
% 02-Dec-83 19:10:58 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 18-Mar-82 13:50:06, Edit by BENSON          
%   Removed patches that were installed in V3 interp                        
% 20-Jan-82 12:15:26, Edit by GRISS           
%   Patch to allow 0 element vectors                                         
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(de mkwords (n)
  %. Allocate vector, init all to #0                                       
  (cond ((intp n) (if (wlessp n -1)
           (stderror '"A WORD vector with fewer than zero elements cannot be allocated")
           (prog (w)
                 (setq w (gtwrds n))
                 (for (from i 0 n 1) (do (setf (wrditm w i) 0)))
                 (return (mkwrds w)))))
        (t % Tag it                                                         
           (nonintegererror n 'mkwords))))

% A special facility to truncate X-vects in place                          
% extract peices                                                           
(de truncatevector (v i)
  (cond ((not (vectorp v)) (nonvectorerror v 'truncatevector))
        ((not (intp i)) (nonintegererror i 'truncatevector))
        (t (prog (len len2 vi)
                 (setq vi (vecinf v))
                 (setq len (veclen vi))
                 (when (weq len i)
                   (return v))
                 % Already the size                                        
                 (when (wlessp len i)
                   (return 
                    (stderror "Cannot Lengthen a Vector in TruncateVector")))
                 (when (wlessp len -1)
                   (return 
                    (stderror "Cant TruncateVector to less then -1")))
                 (setf (getmem vi) (mkitem hvect-tag i))
                 (setf (vecitm vi (wplus2 i 1)) 
                       (mkitem hvect-tag (wdifference (wdifference len i) 2)))
                 (return v)))))

% Missing Words Operations                                                 
(de wordsp (w)
  (weq (tag w) words-tag))

(de truncatewords (v i)
  (cond ((not (wordsp v)) (nonwordserror v 'truncatewords))
        ((not (intp i)) (nonintegererror i 'truncatewords))
        (t (prog (len len2 vi)
                 (setq vi (wrdinf v))
                 (setq len (wrdlen vi))
                 (when (weq len i)
                   (return v))
                 % Already the size                                        
                 (when (wlessp len i)
                   (return 
                    (stderror "Cannot Lengthen a Words in TruncateWords")))
                 (when (wlessp len -1)
                   (return (stderror "Cant TruncateWords to less then -1")))
                 (setf (getmem vi) (mkitem hwords-tag i))
                 (setf (wrditm vi (wplus2 i 1)) 
                       (mkitem hwords-tag (wdifference (wdifference len i) 2)))
                 (return v)))))

(de getwords (wrd i)
  %. Retrieve the I'th entry of WRD                                        
  (let (stripv
        stripi)
       (if (wordsp wrd)
         (cond ((intp i) % can't have Wordss bigger than INUM               
                (progn (setq stripv (wrdinf wrd))
                       (setq stripi (intinf i))
                       (if (and (wgeq stripi 0) 
                            (wleq stripi (wrdlen stripv)))
                         (wrditm stripv stripi)
                         (stderror 
                          (bldmsg 
                           '"Subscript %r in GetWords is out of range" i)))))
               (t (indexerror i 'getwords)))
         (nonwordserror wrd 'getwords))))

(de putwords (wrd i val)
  %. Store Val at I'th position of WRD                                     
  (let (stripv
        stripi)
       (if (wordsp wrd)
         (cond ((intp i) % can't have Wordss bigger than INUM               
                (progn (setq stripv (wrdinf wrd))
                       (setq stripi (intinf i))
                       (if (and (wgeq stripi 0) 
                            (wleq stripi (wrdlen stripv)))
                         (setf (wrditm stripv stripi) val)
                         (stderror 
                          (bldmsg 
                           '"Subscript %r in PutWords is out of range" i)))))
               (t (indexerror i 'putwords)))
         (nonwordserror wrd 'putwords))))

(de upbw (v)
  %. Upper limit of Words V                                                
  (if (wordsp v)
    (mkint (wrdlen (wrdinf v)))
    nil))

(off fast-integers)
