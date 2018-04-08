%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:FIXUP.SL
% Description:  
% Author:       Jim Ambras/CRC
% Created:      27-Mar-84
% Modified:     11-May-84 07:38:38 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 27-Mar-84 13:51:45 (Jim Ambras/CRC)
%  Added compiletime load of sys-consts.
% 02-Mar-84 09:19:47 (Jim Ambras/CRC)                                      
%  Corrected file header.                                                  
% 13-Dec-83 09:31:39 (Tim Tillson)                                         
%  D-register model version. Added header.                                 
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
(compiletime (load sys-consts))

(off r2i) %avoid infinite recursion


(de getbyte (m o)
  (getbyte m o))

(de byte (m o)
  (getbyte m o))

(de putbyte (m o v)
  (putbyte m o v))

(de gethalfword (m o)
  (gethalfword m o))

(de halfword (m o)
  (gethalfword m o))

(de puthalfword (m o v)
  (puthalfword m o v))

)
(on r2i)

(de bittable (a b)
  (getbittable a b)
  )

% Fixups for the HP-Lap.red relocation                                     

(de makerelocword (reloctag relocinf)
  (iplus2 (ilsh reloctag 30) (ilsh (ilsh relocinf 2) -2)))

(de makerelocinf (reloctag relocinf)
  (iplus2 (ilsh reloctag 22) (field relocinf 10 22)))

(de makerelochalfword (reloctag relocinf)
  (iplus2 (ilsh reloctag 14) (field relocinf 18 14)))

(de getbittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2)) 
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(de putbittable (baseaddress bitoffset value2)
  (prog (m b c)
        (setq b 
              (iland (byte baseaddress (setq m (ilsh bitoffset -2))) 
                     (ilsh (idifference -1 (itimes2 3 256)) 
                      (idifference -2 
                       (setq c (itimes2 (field bitoffset 30 2) 2))))))
        (putbyte baseaddress m (if (eq value2 0)
                   b
                   (ilor b (ilsh value2 (idifference 6 c)))))))

