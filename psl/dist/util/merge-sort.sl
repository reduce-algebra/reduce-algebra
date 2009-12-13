%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:MERGE-SORT.SL 
% Description:  Very efficient merge and mergesort 
% Author:       Cris Perdue, Hewlett-Packard CRC 
% Created:      26 Jul 83 
% Modified:     19 Jan 1984 1443-PST (Brian Beach) 
% Package:      Utilities 
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
% 19 Jan 1984 1443-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Copyright (c) 1983, Hewlett-Packard Company
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% (natural-merge-sort list compare-fn)
%%% Returns the elements of the list, destructively sorted.
%%% The value, not the input, must be used.
%%% This function uses "natural merging" rather than merging of
%%% fixed-size groups.  If there are runs of elements already in
%%% order, the runs will be merged as units.
%%% 
%%% (natural-merge list1 list2 compare-fn)
%%% Returns the elements of the two lists, destructively merged.
%%% 
%%% Both of these functions are carefully written to run fast.
%%% The sort runs particularly fast if the list to be sorted has
%%% runs of elements already in order.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if numeric-ops useful))

(fluid '($$cfn $$l))

(de natural-merge1 (a b)
  (if (null a) then b
    elseif (null b) then a
    else
    (prog (val end)
      %% Val will be returned.  End will point to the last cell
      %% of val.
      (setq val
	(setq end
	  (if (funcall $$cfn (car a) (car b)) then
	    (prog1 a (setq a (cdr a)))
	    else
	    (prog1 b (setq b (cdr b))))))
      loop
      (if (null a)
	%% Reached end of A.
	then (rplacd end b) (return val)
	elseif (null b)
	%% Reached end of B.
	then (rplacd end a) (return val)
	elseif (funcall $$cfn (car a) (car b))
	%% Include the first cell of A if it is next.
	%% Optimization: don't change the cdr of that cell.
	then (rplacd end a) (setq a (cdr a))
	%% Otherwise include the first cell of B.
	else (rplacd end b) (setq b (cdr b)))
      (setq end (cdr end))
      (go loop))))

(de natural-merge (a b $$cfn)
  (natural-merge1 a b))

(on fast-integers)

(de natural-merge-sort1 (n)
%%% Sort the first 2 to the nth runs from $$l.  $$l is set to
%%% any part of its initial value that is not sorted by this
%%% procedure.  The value returned is the natural-merge of all the
%%% elements of the sorted runs.
%%% This procedure is destructive: it does no storage allocation.
  (if (null $$l) then nil
    elseif (= n 0)
    then (for (with end (run $$l))
	      (do (setq end $$l)
		  (setq $$l (cdr $$l))
		  (if (or (null $$l)
			  (not (funcall $$cfn (car end) (car $$l))))
		    then
		    (rplacd end nil)
		    (return run))))
    else (natural-merge1 (natural-merge-sort1 (- n 1))
			 (natural-merge-sort1 (- n 1)))))

(de natural-merge-sort ($$l $$cfn)
%%% First let val be the first in-order run of elements of $$l.
%%% Then let it be merged with successively larger sorted pieces
%%% of $$l.
  (for (while $$l)
       (from n 0)
       (with (val (natural-merge-sort1 0)))
       (do (setq val (natural-merge1 val (natural-merge-sort1 n))))
       (finally (return val))))

(off fast-integers)

% End of file.

