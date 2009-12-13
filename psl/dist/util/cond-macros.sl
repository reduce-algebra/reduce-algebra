%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:COND-MACROS.SL 
% Description:  convenient macros for conditional expressions 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2055-PDT (Nancy Kendzierski) 
% Status:       Experimental (Do Not Distribute) 
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B 
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
% 6 May 1984 1636-PDT (Nancy Kendzierski)
%  Changed compiletime loads requirements to allow separate compilation of
%  USEFUL modules.
% 8 Mar 1984 1542-PST (Nancy Kendzierski)
%  Added XOR back in -- nmode uses it.
% 19 Jan 1984 1431-PST (Brian Beach)
%  Added standard header.
% 08 Feb 1984 (Cris Perdue)
%  Commented out defn. of XOR (I hope it's not used), added compiletime
%  load useful to make this stand on its own.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro))

(defmacro if (predicate then . else)
  (cond ((null else) `(cond (,predicate ,then)))
	(t `(cond (,predicate ,then) (t . ,else)))))

(defmacro xor (u v) 
  % done this way to both "semi-open-code" but not repeat the code for either
  % arg; also evaluates args in the correct (left to right) order.
  `((lambda (***XOR-ARG***) (if ,v (not ***XOR-ARG***) ***XOR-ARG***)) ,u))

(defmacro when (p . c) `(cond (,p . ,c)))

(defmacro unless (p . c) `(cond ((not ,p) . ,c)))
