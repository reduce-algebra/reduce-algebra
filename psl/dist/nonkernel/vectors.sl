%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:VECTORS.SL 
% Title:        Standard Lisp Vector functions 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     05-Sep-84 09:10:02 (Brian Beach)
% Status:       Open Source: BSD License
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
% 10-May-84 14:25:16 (Brian Beach)
%   12-Mar-84 13:17:04 (Mike Creech)
%     Fixed bug I introduced in UPBV.
%   26-Jan-84 13:56:29 (Mike Creech)
%     Fixed bugs with vector functions used where evector functions should be used
%     (i.e., veclen, vecitm, and vecinf).
%     Removed EVECTORP.
%  
% 26-Apr-84 07:50:39 (Brian Beach)
%  Removed EVECTORP.  Moved it to KNOWN-TO-COMP-SL.
% 01-Dec-83 15:05:03 (Brian Beach)
%   Translated from Rlisp to Lisp.
% 14 Jun 1983 1103-PDT, Cris Perdue
%   Added assign-op property and setf-safe flag to egetv.
%  <PSL.KERNEL>VECTORS.RED.2, 10-Jan-83 15:54:19, Edit by PERDUE
%  Added EGetV etc. for EVectors, paralleling Vectors
% MkVect and MkEVector are found in PK:CONS-MKVECT.RED
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de getv (vec i)
  % Retrieve the I'th entry of Vec
  (let (stripv
        stripi)
       (if (vectorp vec)
         (cond ((intp i) % can't have vectors bigger than INUM

                (progn (setq stripv (vecinf vec))
                       (setq stripi (intinf i))
                       (if (and (wgeq stripi 0)
                            (wleq stripi (veclen stripv)))
                         (vecitm stripv stripi)
                         (stderror
                          (bldmsg '"Subscript %r in GetV is out of range"
                           i)))))
               (t (indexerror i 'getv)))
         (nonvectorerror vec 'getv))))

(de putv (vec i val)
  % Store Val at I'th position of Vec
  (let (stripv
        stripi)
       (if (vectorp vec)
         (cond ((intp i) % can't have vectors bigger than INUM

                (progn (setq stripv (vecinf vec))
                       (setq stripi (intinf i))
                       (if (and (wgeq stripi 0)
                            (wleq stripi (veclen stripv)))
                         (setf (vecitm stripv stripi) val)
                         (stderror
                          (bldmsg '"Subscript %r in PutV is out of range"
                           i)))))
               (t (indexerror i 'putv)))
         (nonvectorerror vec 'putv))))

(de upbv (v)
  % Upper limit of vector V
  (if (vectorp v)
    (mkint (veclen (vecinf v)))
    nil))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% EVectors
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de egetv (vec i)

    %  Retrieve the I'th element of Vec.
    %  Can't have vectors bigger than INUM.
    %  Check that i falls in the bounds of the evector.

    (if
       (and (evectorp vec)
	    (intp i))
       % THEN
       (let
	   ((stripv (evecinf vec))
	    (stripi (intinf i)))
	   (if
	      (and (wgeq stripi 0) 
		   (wleq stripi (eveclen stripv)))
	      % THEN i falls within the evector.
	      (evecitm stripv stripi)
	      % ELSE We have an error.
	      (stderror 
	               (bldmsg  '"Subscript %r in EGETV is out of range" i)))
	   )
       % ELSE We have some type of error.
       (if
	  (evectorp vec)
	  % THEN 
	  (indexerror i 'egetv)
	  % ELSE
	  (nonvectorerror vec 'egetv)
	  )
       ))

(de eputv (vec i val)

    % Store Val at I'th element of Vec.
    % Can't have vectors bigger than INUM.
    % Check that i falls within the bounds of the evector.

    (if
       (and (evectorp vec)
	    (intp i))
       % THEN
       (let
	   ((stripv (evecinf vec))
	    (stripi (intinf i)))
	   (if
	      (and (wgeq stripi 0) 
		   (wleq stripi (eveclen stripv)))
	      % THEN The index is ok, so do the put.
	      (setf (evecitm stripv stripi) val)
	      % ELSE We have an error.
	      (stderror 
	               (bldmsg  '"Subscript %r in EPUTV is out of range" i)))
	   )
       % ELSE We have some type of error.
       (if
	  (evectorp vec)
	  % THEN 
	  (indexerror i 'eputv)
	  % ELSE
	  (nonvectorerror vec 'eputv)
	  )
       ))

(de eupbv (v)

    %-  Upper limit of evector V
    %   If not an evector, return NIL.

    (when
       (evectorp v)
       % THEN Ok to change the upper bound.
       (mkint (eveclen (evecinf v)))
       ))

(put 'egetv 'assign-op 'eputv)

(flag1 'egetv 'setf-safe)



