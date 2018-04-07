%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:ASSOCIATION.SL 
% Description:  Nmode Mutable Association Lists 
% Author:       Alan Snyder, Hewlett-Packard CRC 
% Created:      21 July 1982 
% Modified:     02-Mar-84 16:12:56 (Mike Creech) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  
% Runtime:      
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
% 02-Mar-84 16:12:37 (Mike Creech)
%  Fixed header.
% 11-Jan-84 11:19:52 (Mike Creech)
%  Made assocation-bind append to front of list. Removed assocation-bind
%  and map-over-association.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de association-create ()

  % Create an empty association list (that is mutable!).

  (list (cons '*DUMMY* '*DUMMY*)))

(de association-bind (alist indicator value)

    % Change or extend the ALIST to map INDICATOR to VALUE.
    % Return the modified alist as value.

    (let
        ((pair (atsoc indicator alist)))
	(if
	   pair
	   % THEN Replace the existing value for the pair.
	   (rplacd pair value)
	   % ELSE Add a new item to the front of the list.
	   (if
	      (and (eq (caar alist) '*DUMMY*)
		    (eq (cdar alist) '*DUMMY*))
	      % THEN Replace with the (*DUMMY* . *DUMMY*) item.
	      (rplaca alist (cons indicator value))
	      % ELSE Add to front of list.
	      (let
		  ((new-cell (cons (car alist) (cdr alist))))
		  (rplaca alist (cons indicator value))
		  (rplacd alist new-cell)
		  )
	      )
	   )
	)
    alist
    )

% (de association-lookup (alist indicator)
  % Return the value attached to the given indicator (using EQ for
  % comparing indicators).  If there is no attached value, return NIL.

%  (let ((pair (atsoc indicator alist)))
%    (if pair (cdr pair) NIL)))

% (defmacro map-over-association ((alist indicator-var value-var) . body)

  % Execute the body once for each indicator in the alist, binding
  % the specified indicator-var to the indicator and the specified
  % value-var to the attached value.  Return the result of the body
  % (implicit PROGN).

%  `(for (in ***PAIR*** ,alist)
%	(with ***RESULT***)
%	(do (let ((,indicator-var (car ***PAIR***))
%		  (,value-var (cdr ***PAIR***))
%		  )
%	      (cond ((not (eq ,indicator-var '*DUMMY*))
%		     (setf ***RESULT*** (progn ,@body))
%		       ))))
%	(returns ***RESULT***)
%	))
