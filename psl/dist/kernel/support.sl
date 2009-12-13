%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:SUPPORT.SL 
% Description:  Assorted support functions for the kernel. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      22-Feb-84 
% Modified:     13-Nov-84 14:06:44 (Brian Beach) 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22-Feb-90 (DJCH)
%  Fixed copystringtofrom not to copy one word too many
% 05-Apr-88 (Julian Padget)
%  (Re)Incorporated simple definitions of INTERROGATE and MODIFY for
%  use in booting - will be redefined by symbol-values.  Changed 
%  *DEFINE-CONSTANT to (wgetv symval <expr>)
% 13-Nov-84 14:05:14 (Brian Beach)
%  Added changes for PKG-FASL hack:  SUBSEQ function for strings, and 
%  SEARCH-STRING-FOR-CHARACTER.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load f-strings))

(on fast-integers fast-strings)

(de subseq (string lower-bound upper-bound)    % To be redefined
  
  % This function is does not check bounds.  The parameters must satisfy the
  % following conditions:
  %
  %    STRING must be a string
  %    LOWER-BOUND and UPPER-BOUND must be integers:
  %        0 <= LOWER-BOUND < UPPER-BOUND <= (string-length STRING)

  (unless (stringp string)
    (kernel-fatal-error "SUBSEQ called with a non-string")
    )
  
  (let* ((new-size (- (- upper-bound lower-bound) 1))
	 (old-pointer  (strinf string))
	 (new-pointer  (gtstr new-size)))
    (for (from i 0 new-size 1)
	 (do (setf (strbyt new-pointer i) (strbyt old-pointer (+ lower-bound i))))
	 )
    (mkstr new-pointer)
    ))
  
(de search-string-for-character (char string)
  
  (for (from i 0 (string-upper-bound string))
       (do (when (eq char (string-fetch string i))
	     (return i)))
       (returns nil)   % when none found
       ))

(de unchecked-string-equal (u v)
  % EqStr without typechecking or eq                                       
  (prog (len i)
        (setq u (strinf u))
        (setq v (strinf v))
        (setq len (strlen u))
        (when (wneq len (strlen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i len)
          (return t))
        (when (wneq (strbyt u i) (strbyt v i))
          (return nil))
        (setq i (wplus2 i 1))
        (go loop)))


(de copystringtofrom (new old)
  % Copy all chars in Old to New                                          
  (prog (slen stripnew stripold)
        (setq stripnew (strinf new))
        (setq stripold (strinf old))
        (setq slen (strlen stripold))
        (when (wlessp (strlen stripnew) slen)
          (setq slen (strlen stripnew)))
        (setq slen (wdifference (strpack slen) 1))
        (for (from i 0 slen 1) 
	     (do (setf (vecitm stripnew i) (vecitm stripold i))))
        (return new)))

(de cons (a b)
  (let ((ptr (gtheap (pairpack))))
    (setf (wgetv ptr 0) a)
    (setf (wgetv ptr 1) b)
    (mkpair ptr)
    ))

(de interrogate (index) (wgetv symval index))

(de modify (index val) (setf (wgetv symval index) val))

(de put (u indicator val)   % To be redefined.
  (unchecked-put u indicator val)
  )

(de unchecked-put (id indicator value)
  % Put a property on the property list of ID.
  (let* ((property-list   (unchecked-prop id))
	 (old-element     (atsoc indicator property-list)))
    (if old-element
      (rplacd old-element value)
      (unchecked-setprop id (cons (cons indicator value) property-list))
      )
    value
    ))

(de atsoc (u v)
  % EQ version of ASSOC                                                   
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (eq u (caar v))) (car v))
        (t (atsoc u (cdr v)))))

(de unchecked-setprop (u l)
  % Store L as property list of U                                         
  (setf (symprp (idinf u)) l)
  )


(de unchecked-prop (u)
  % Access property list of U                                             
  (symprp (idinf u))
  )

(de putd (fnname fntype fnexp)    % To be redefined
  (code-putd fnname fntype fnexp)
  )

(de code-putd (fnname fntype fnexp)
  % A simplified version of PUTD for the small FASLIN.
  % It is assumed that all functions defined will be already compiled.

  (unless (and (idp fnname)
	       (idp fntype)
	       (codep fnexp))
    (kernel-fatal-error "Bad parameters to CODE-PUTD")
    )
  
  (plantcodepointer (idinf fnname) (codeinf fnexp))
  (unless (eq fntype 'expr)
    (put fnname 'type fntype)
    ))

(de fluid (list)
  (for (in id list)
       (do (fluid1 id))
       ))

(de fluid1 (id)
  (put id 'vartype 'fluid)
  )

(de stderror (x)   % To be redefined
  (kernel-fatal-error x)
  )

(de *define-constant (name value)    % to be redefined
  (setf (wgetv symval (idinf name)) value)
  (put name 'constant? t)
  )

(off fast-integers)

% End of file.
