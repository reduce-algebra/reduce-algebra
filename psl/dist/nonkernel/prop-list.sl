%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:PROPERTY-LIST.SL
% Title:          Functions dealing with property lists
% Author:         Eric Benson
% Created:        17 August 1981
% Modified:       31-Dec-84 10:54:16 (Cris Perdue)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
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
% 31-Dec-84 10:52:18 (Cris Perdue)
%  Changed remprop to remove the property from the property list
%  unconditionally so storage for properties with values of NIL
%  is released.
% 21-Mar-84 14:45:02 (Jim Ambras)
%  Removed turning on of fast-links flag
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:59:17 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
% Edit by Cris Perdue, 21 Apr 1983 1345-PST
% Flag now gives error if IDList not NIL or list.
%  <PSL.INTERP>PROPERTY-LIST.RED.11,  1-Mar-82 14:09:20, Edit by BENSON
%  Changed "move-to-front" to "exchange-with-previous"
%  <PSL.INTERP>PROPERTY-LIST.RED.7, 27-Feb-82 12:43:27, Edit by BENSON
%  Optimized GET and FLAGP, rearranges property list
% Every ID in the system has a property list.  It is obtained by the function
% PROP(ID) and updated with the function SETPROP(ID, PLIST).  These functions
% are not in the Standard Lisp report, and are not intended for use in user
% programs.  A property list (whose format should also not be known to
% user programs) is a list of IDs and dotted pairs (A-List entries).  The
% pairs are used by PUT and GET, and the IDs are used by FLAG and FLAGP.
% Non-Standard Lisp functions used:
% DELQIP -- EQ, destructive version of Delete	(in EASY-NON-SL.RED)
% ATSOC -- EQ version of ASSOC	(in EASY-NON-SL.RED)
% DELATQIP -- EQ, destructive version of DELASC (in EASY-NON-SL.RED)
% EQCAR(A,B) -- PairP A and car A eq B (in EASY-NON-SL.RED)
% NonIDError -- in TYPE-ERRORS.RED
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de prop (u)
  % Access property list of U
  (if (idp u)
    (symprp (idinf u))
    (noniderror u 'prop)))

(de setprop (u l)
  % Store L as property list of U
  (if (idp u)
    (setf (symprp (idinf u)) l)
    (noniderror u 'setprop)))

(de flagp (u indicator)
  % Is U marked with Indicator?
  (if (or (not (idp u)) (not (idp indicator)))
    nil
    (prog (pl previouspointer)
          (setq pl (symprp (idinf u)))
          (when (null pl)
            (return nil))
          (when (weq (car pl) indicator)
            (return t))
          (setq previouspointer pl)
          (setq pl (cdr pl))
     loop
          (when (null pl)
            (return nil))
          (when (weq (car pl) indicator)
            (return (progn (rplaca pl (car previouspointer))
                           (rplaca previouspointer indicator)
                           t)))
          (setq previouspointer pl)
          (setq pl (cdr pl))
          (go loop))))

%(on fastlinks)

(de getfntype (u)
  (get u 'type))

%(off fastlinks)

(de get (u indicator)
  % Retrieve value stored for U with Ind
  (if (or (not (idp u)) (not (idp indicator)))
    nil
    (prog (pl x previouspointer)
          (setq pl (symprp (idinf u)))
          (when (null pl)
            (return nil))
          (setq x (car pl))
          (when (and (pairp x) (weq (car x) indicator))
            (return (cdr x)))
          (setq previouspointer pl)
          (setq pl (cdr pl))
     loop
          (when (null pl)
            (return nil))
          (setq x (car pl))
          (when (and (pairp x) (weq (car x) indicator))
            (return (progn (rplaca pl (car previouspointer))
                           (rplaca previouspointer x)
                           (cdr x))))
          (setq previouspointer pl)
          (setq pl (cdr pl))
          (go loop))))

(de flag (idlist indicator)
  % Mark all in IDList with Indicator
  (cond ((not (idp indicator)) (noniderror indicator 'flag))
        ((not (or (pairp idlist) (null idlist)))
         (nonlisterror idlist 'flag))
        (t (foreach u in idlist do (flag1 u indicator)))))

(de flag1 (u indicator)
  (if (not (idp u))
    (noniderror u 'flag)
    (prog (pl)
          (setq pl (prop u))
          (unless (memq indicator pl)
            (setprop u (cons indicator pl))))))

(de remflag (idlist indicator)
  % Remove marking of all in IDList
  (if (not (idp indicator))
    (noniderror indicator 'remflag)
    (foreach u in idlist do (remflag1 u indicator))))

(de remflag1 (u indicator)
  (if (not (idp u))
    (noniderror u 'remflag)
    (setprop u (delqip indicator (prop u)))))

(de put (u indicator val)
  % Store Val in U with Indicator
  (cond ((not (idp u)) (noniderror u 'put))
        ((not (idp indicator)) (noniderror indicator 'put))
        (t (prog (pl v)
	     (setq pl (prop u))
	     (if (not (setq v (atsoc indicator pl)))
	       (setprop u (cons (cons indicator val) pl))
	       (rplacd v val))
	     (return val)))))

(de remprop (u indicator)
  % Remove value of U with Indicator
  (if (or (not (idp u)) (not (idp indicator)))
    nil
    (prog (v)
      (setq v (get u indicator))
      (setprop u (delatqip indicator (prop u)))
      (return v))))

(de rempropl (l indicator)
  % RemProp for all IDs in L
  (foreach x in l do (remprop x indicator)))

