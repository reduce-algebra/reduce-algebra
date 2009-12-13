%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:ASSOCIATION.SL 
% Description:  Nmode Mutable Association Lists 
% Author:       Alan Snyder, Hewlett-Packard CRC 
% Created:      21 July 1982 
% Modified:     02-Mar-84 16:12:56 (Mike Creech) 
% Status:       Experimental (Do Not Distribute) 
% Mode:         Lisp 
% Package:      Utilities 
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
