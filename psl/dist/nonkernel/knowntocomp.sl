%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:KNOWNTOCOMP.SL
% Title:        Standard Lisp functions which are handled entirely by the 
%               compiler 
% Author:       Eric Benson 
% Created:      17 August 1981 
% Modified:     26-Apr-84 07:49:49 (Brian Beach) 
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
% 10-Sep-93 (Herbert Melenk)
%   (car nil) and (cdr nil) -> error unless *fastcar = NIL
% 19 Mar 1988 (Julian Padget)
%  Added interpreter definition for sgdp.
% 02 Sep 1986 (Julian Padget)
%  Added interpreter definitions of predicates for new types.
% 26-Apr-84 07:49:40 (Brian Beach)
%  Added EVECTORP.
% 26 Jan 1984 1000-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:49:17 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(off r2i)

(compiletime (fluid '(*fastcar)))

(setq *fastcar t)

% can't do recursion removal, will get infinite recursion
% Section 3.1 -- Elementary predicates

(de codep (u)
  % Is U a code pointer?
  (codep u))

(de eq (u v)
  % Are U and V identical?
  (eq u v))

(de floatp (u)
  % Is U a floating point number?
  (floatp u))

(de bigp (u)
  % Is U a bignum?
  (bigp u))

(de idp (u)
  % Is U an ID?
  (idp u))

(de pairp (u)
  % Is U a pair?
  (pairp u))

(de stringp (u)
  % Is U a string?
  (stringp u))

(de vectorp (u)
  % Is U a vector?
  (vectorp u))

(de evectorp (u)
  % Is U an evector?
  (evectorp u))

%JAP: new predicates

(de contextp (x) (contextp x))

(de bstructp (x) (bstructp x))

(de bvectorp (x) (bvectorp x))

(de funargp (x) (funargp x))

%JAP: and another one

(de sgdp (x) (sgdp x))

% Section 3.2 -- Functions on Dotted-Pairs
% NonPairError found in TYPE-ERRORS.RED
(de car (u)
  % left subtree of pair
  (cond ((pairp u) (car u))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'car))))

(de cdr (u)
  % right subtree of pair
  (cond ((pairp u) (cdr u))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdr))))

(de rplaca (u v)
  % RePLAce CAr of pair
  (if (pairp u)
    (rplaca u v)
    (nonpairerror u 'rplaca)))

(de rplacd (u v)
  % RePLACe CDr of pair
  (if (pairp u)
    (rplacd u v)
    (nonpairerror u 'rplacd)))

(on r2i)

% Turn recursion removal back on
