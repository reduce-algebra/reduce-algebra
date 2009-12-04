%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:COPIERS.SL 
% Title:        Functions for copying various data types 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     19 Oct 1984 0617-PDT (Mark R. Swanson)
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
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
% 29-Feb-96 Winfried Neun (for the sake of this special leapyear day).
%  Invented copyfltn in Totalcopy such that alignment of floats is not lost
% 4-Jul-85 Edited by Connie O'Dell to install fix for uninitialized vectors
%  in totalCopy proposed by Will Galway, to prevent unpleasant consequences
%  of garbage collecting while part of copy structure is uninitialized.
% 19 Oct 1984 0616-PDT (Mark R. Swanson)
%  Modified length calculation in COPYSTRINGTOFROM to take count word out of 
%   consideration
% 18-Jul-84 08:08:34 (Brian Beach)
%  Minor cleanup of TOTALCOPY
% 01-Dec-83 14:26:58 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(de copystringtofrom (new old)
  % Copy all chars in Old to New
  (prog (slen stripnew stripold)
        (setq stripnew (strinf new))
        (setq stripold (strinf old))
        (setq slen (strlen stripold))
        (when (wlessp (strlen stripnew) slen)
          (setq slen (strlen stripnew)))
        (setq slen (- (strpack slen) 1))
        (for (from i 0 slen 1)
              (do (setf (vecitm stripnew i) (vecitm stripold i))))
        (return new)))

(de copystring (s)
  % copy to new heap string
  (prog (s1)
        (setq s1 (gtstr (strlen (strinf s))))
        (copystringtofrom s1 (strinf s))
        (return (mkstr s1))))

(de copybytes (s)
  % copy to new heap string
  (prog (s1)
        (setq s1 (gtstr (strlen (strinf s))))
        (copystringtofrom s1 (strinf s))
        (return (mkbytes s1))))

(de copywarray (new old uplim)
  % copy UpLim + 1 words
  (progn (for (from i 0 uplim 1) (do (setf (wgetv new i) (wgetv old i))))
         new))

(de copyvectortofrom (new old)
  % Move elements, don't recurse
  (prog (slen stripnew stripold)
        (setq stripnew (vecinf new))
        (setq stripold (vecinf old))
        (setq slen (veclen stripold))
        (for % assumes VecLen New has been set

              (from i 0 slen 1)
              (do (setf (vecitm stripnew i) (vecitm stripold i))))
        (return new)))

(de copyvector (s)
  % Copy to new vector in heap
  (prog (s1)
        (setq s1 (gtvect (veclen (vecinf s))))
        (copyvectortofrom s1 (vecinf s))
        (return (mkvec s1))))

(de copyevectortofrom (new old)
  % Move elements, don't recurse
  (prog (slen stripnew stripold)
        (setq stripnew (evecinf new))
        (setq stripold (evecinf old))
        (setq slen (eveclen stripold))
        (for % assumes EVecLen New has been set

              (from i 0 slen 1)
              (do (setf (evecitm stripnew i) (evecitm stripold i))))
        (return new)))

(de copyevector (s)
  % Copy to new EVector in heap
  (prog (s1)
        (setq s1 (gtevect (eveclen (evecinf s))))
        (copyevectortofrom s1 (evecinf s))
        (return (mkevect s1))))

(de copywrdstofrom (new old)
  % Like CopyWArray in heap
  (prog (slen stripnew stripold)
        (setq stripnew (wrdinf new))
        (setq stripold (wrdinf old))
        (setq slen (wrdlen stripold))
        (for % assumes WrdLen New has been set

              (from i 0 slen 1)
              (do (setf (wrditm stripnew i) (wrditm stripold i))))
        (return new)))

(de copyhalfwordstofrom (new old)
  % Like CopyWArray in heap
  (prog (slen stripnew stripold)
        (setq stripnew (halfwordinf new))
        (setq stripold (halfwordinf old))
        (setq slen (halfwordlen stripold))
        (for % assumes WrdLen New has been set

              (from i 0 slen 1)
              (do (setf (halfworditm stripnew i) (halfworditm stripold i))))
        (return new)))

(de copywrds (s)
  % Allocate new WRDS array in heap
  (prog (s1)
        (setq s1 (gtwrds (wrdlen (wrdinf s))))
        (copywrdstofrom s1 (wrdinf s))
        (return (mkwrds s1))))

(de copyhalfwords (s)
  % Allocate new HALFWORDS array in heap
  (prog (s1)
        (setq s1 (gthalfwords (halfwordlen (halfwordinf s))))
        (copyhalfwordstofrom s1 (halfwordinf s))
        (return (mkhalfwords s1))))

% CopyPairToFrom is RplacW, found in EASY-NON-SL.RED
% CopyPair is: car S . cdr S;
% Usual Lisp definition of Copy only copies pairs, is found in EASY-NON-SL.RED

(de totalcopy (s)
  % Unique copy of entire structure blows up on circular structures
  (case (tag s)
    ((pair-tag)      (cons (totalcopy (car s)) (totalcopy (cdr s))))
    ((string-tag)    (copystring s))
    ((vector-tag)    (let* ((strips (vecinf s))
			    (len (veclen strips))
			    (ptr (mkvect len)))
		       (for (from i 0 len 1)
			    (do
			     (setf (vecitm (vecinf ptr) i)
			       (totalcopy (vecitm (vecinf s) i)))))
		       ptr))
    ((words-tag)     (copywrds s))
    ((bytes-tag)     (copybytes s))
    ((halfwords-tag) (copyhalfwords s))
    ((fixnum-tag)    (mkfixn (inf (copywrds s))))
    ((floatnum-tag)  (copyfltn s))
    (nil             s)
    ))

(de copyfltn (s)
  % Allocate new Floatnum in heap 
  % May have special alignment needs
  (prog (s1)
        (setq s1 (gtfltn (wrdlen (wrdinf s))))
        (copywrdstofrom s1 (wrdinf s))
        (return (mkfltn s1))))

(off fast-integers)
