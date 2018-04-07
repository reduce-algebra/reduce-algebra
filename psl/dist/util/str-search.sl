%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:STR-SEARCH.SL 
% Description:  String searching functions 
% Author:       Cris Perdue 
% Created:      23-Nov-82 
% Modified:     12 Apr 1984 1423-PST (Nancy Kendzierski) 
% Status:       Experimental (Do Not Distribute) 
% Status:       Open Source: BSD License
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
% 03-Sep-86 (Leigh Stoller)
%  Commented out 68000 version of char-search2. 
% 12 Apr 1984 1423-PST (Nancy Kendzierski)
%  Changed if_system HP9836 to MC6800, since we believe it should work on all
%  68000 -- at least HP9836 and HPUX200.
% 02-Mar-84 09:36:22 (Jim Ambras/CRC)
%  Corrected file header.
% 09-Jan-84 15:01:26 (Tim Tillson)
%   Modified LAP for D-register version
% 03-Aug-83 17:16:52, Cris Perdue
%   Changed names from upper to fast-char-upcase and lower to
%   fast-char-downcase.
% 01-Aug-83 17:53:20, Cris Perdue
%   Added definition of fast-char-lessp.
% 28-Jul-83 Nancy Kendzierski
%   Changed use of autoincrement to postincrement to conform to new
%   code generation.
% 26 Jul 1983 1532-PDT, Cris Perdue
%   Corrected bugs in string-search-from-equal, improved
%   performance a little.
% 19-Jul-83 15:05:43, Cris Perdue
%   Corrected name from substring-= to substring=.
%   Changed args to substring-equal and substring=.
% 02-Jun-83 18:11:27, Cris Perdue
%   Added string-search-equal, string-search-from-equal, substring-=,
%   and substring-equal.

%%% General-purpose searches for substring.  Case is important.
%%% If the target is found, the index in the domain of the
%%% leftmost character of the leftmost match is returned,
%%% otherwise NIL.
%%%
%%% (STRING-SEARCH TARGET DOMAIN).
%%% If passed two strings, Common LISP "search" will give the
%%% same results.
%%%
%%% (STRING-SEARCH-FROM TARGET DOMAIN START)
%%% Like string-search, but the search effectively starts at index
%%% START in the domain.
%%% 
%%% (STRING-SEARCH-EQUAL TARGET DOMAIN)
%%% Like string-search except that the comparisons are case-insensitive.
%%% string-search-equal and string-search-from-equal have been implemented
%%% with special attention to efficiency on MC68000 systems.
%%% 
%%% (STRING-SEARCH-FROM-EQUAL TARGET DOMAIN START)
%%% Like string-search-from except that the comparisons are case-insensitive.
%%% 
%%% (SUBSTRING= STRING1 STRING2 START LIMIT)
%%% Equivalent to (string= string1 (substring string2 start limit)), but
%%% more efficient.
%%% 
%%% (SUBSTRING-EQUAL STRING1 STRING2 START LIMIT)
%%% Equivalent to (string-equal string1 (substring string2 start limit),
%%% but more efficient.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% Implementation note: In both of these, the value of the first
%%% character of the target is precomputed and it is tested against
%%% characters of the domain separately from the other characters of
%%% the target.

(compiletime (load numeric-ops if if-system f-strings))

(on fast-integers fast-strings)

%%% ASCII-specific.  May evaluate its argument multiple times.  Not to
%%% be exported.  (Actually defined at load time in spite of "compiletime".)
(compiletime
(defmacro fast-char-upcase (x)
  `(if (and (<= (char !a) ,x) (<= ,x (char !z))) then
     (- ,x 32)
    else ,x))
)

%%% ASCII-specific.  May evaluate its argument multiple times.  Not to
%%% be exported.
(compiletime
(defmacro fast-char-downcase (x)
  `(if (and (<= (char A) ,x) (<= ,x (char Z))) then
     (+ ,x 32)
    else ,x))
)

(defun string-search (target domain)
  (if (not (and (stringp target) (stringp domain))) then
      (error 0 "Arg to string-search not a string"))
  (let* ((s (string-upper-bound target))
	 (m (- (string-upper-bound domain) s)))
    (if (= s -1) then 0
	else
	(let ((c (string-fetch target 0)))
	  (for (from i 0 m)
	       (do (if (eq (string-fetch domain i) c) then
		       (if
			(for (from u 1 s)
			     (from v (+ i 1))
			     (do (if (neq (string-fetch target u)
					  (string-fetch domain v)) then
				     (return nil)))
			     (finally (return t))) then
			(return i)))))))))

%%% Like string-search, but takes an explicit starting index
%%% in the domain string.

(defun string-search-from (target domain start)
  (if (not (and (stringp target) (stringp domain))) then
      (error 0 "Arg to substring-search not a string"))
  (let* ((s (string-upper-bound target))
	 (m (- (string-upper-bound domain) s)))
    (if (= s -1) then start
	else
	(let ((c (string-fetch target 0)))
	  (for (from i start m)
	       (do (if (eq (string-fetch domain i) c) then
		       (if
			(for (from u 1 s)
			     (from v (+ i 1))
			     (do (if (neq (string-fetch target u)
					  (string-fetch domain v)) then
				     (return nil)))
			     (finally (return t))) then
			(return i)))))))))

%%% Is target a substring of domain, ignoring differences in case?
%%% ASCII - specific.  See above.
(defun string-search-equal (target domain)
  (string-search-from-equal target domain 0))

(defun string-search-from-equal (target domain start)
  (if (not (and (stringp target) (stringp domain))) then
      (error 0 "Arg to string-search not a string"))
  (let* ((s (string-upper-bound target))
	 (m (+ (- (string-upper-bound domain) s) 1)))	% m is limit index of search
    (if (= s -1) then 0
      else
      (let* ((c (string-fetch target 0))
	     (c1 (fast-char-downcase c))
	     (c2 (fast-char-upcase c))
	     (trypos start)
	     foundpos)
	(while (< trypos m)
	  (setf foundpos (char-search2 c1 c2 domain trypos m))
	  (if (not foundpos) then (return nil))
	  (if (for (from u 1 s)
		   (from v (+ foundpos 1))
		   (always (fast-char-equal (string-fetch target u)
					    (string-fetch domain v))))
	    then (return foundpos)
	    else
	    (setq trypos (+ foundpos 1))))))))

(commentoutcode
(if_system MC68000
(lap '(
(*ENTRY CHAR-SEARCH2 EXPR 5)
	(MOVE!.L (reg D4) (REG D7))
	(SUB!.L (reg D3) (reg D7))      %	D2 is max repetition counter
	(MOVE!.L (REG D2) (REG D6))
	(ANDI!.L 16#00FFFFFF (REG D6))
	(MOVEA!.L (REG D6) (REG A0))    	% Mask off tag to help GC
	(ADDA!.L (reg D3) (reg A0))
	(ADDQ!.L 4 (reg A0))            % A0 points to first ch of search
	(CLR!.W (reg D6))               		% Clear low order D6 for word compares
	(DBF (reg D7) (LABEL G0030))
	(BRA (LABEL G0029))
(*LBL (LABEL G0030))
	(MOVE!.B (POSTINCREMENT (REG A0)) (REG D6))	% Get byte
	(CMP!.W (REG D0) (REG D6))	% Compare with c1 (word compare)
	(BEQ (LABEL G0036))
	(CMP!.W (REG D1) (REG D6))      	% ... c2
	(DBEQ (reg D7) (LABEL G0030))	% Test and decr counter and test ...
	(BEQ (LABEL G0036))		% Branch if fell thru due to match
(*LBL (LABEL G0029))
	(MOVE!.L (REG NIL) (REG D0))	% NIL if count ran out
	(RTS)
(*LBL (LABEL G0036))
	(MOVE!.L (reg D4) (REG D0))    	% Match found; R1 := limit index
	(SUB!.L (REG D7) (REG D0))     	% Subtract 1+remaining count
	(SUBQ!.L 1 (REG D0))            		% Gives index at which match found
	(RTS)
)))
)

% else
(defun char-search2 (c1 c2 domain startpos limitpos)
  (for (from i startpos (- limitpos 1))
       (do (let ((c (string-fetch domain i)))
	     (if (or (= c c1) (= c c2))
	       (return i))))
       (finally (return nil))))


(de substring-equal (x y start)
  (let ((limit (+ start (string-upper-bound x))))
    (if (< (string-upper-bound y) limit) then nil
      else
      (for (from i 0)
	   (from j start limit)
	   (always (fast-char-equal (string-fetch x i) (string-fetch y j)))))))

(de substring= (x y start)
  (let ((limit (+ start (string-upper-bound x))))
    (if (< (string-upper-bound y) limit) then nil
      else
      (for (from i 0)
	   (from j start limit)
	   (always (= (string-fetch x i) (string-fetch y j)))))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Not for general export!  The standard definitions will be made
%%% faster and these will be eliminated.  (used by code-browser and idx-browser)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defun fast-char-lessp (x y)
  (< (fast-char-upcase x) (fast-char-upcase y)))

(defun fast-char-equal (x y)
  (= (fast-char-upcase x) (fast-char-upcase y)))

(off fast-integers fast-strings)

% End of file.

