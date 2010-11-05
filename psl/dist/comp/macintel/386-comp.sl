%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PVC:386-COMP.SL
% Title:          Compiler patterns for VAX PSL, plus a few cmacro expanders
% Author:         Eric Benson
% Created:        11 January 1982                                              
% Modified:       5 June 1984 (Vicki O'Day)
% Status:         Experimental
% Mode:           Lisp
% Package:        Compiler
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
% 17-Aug 1993 (Herbert Melenk)
%   Introduced TVPAT-eq and TVPAT-tag for simple comparisons returning
%   NIL/T.  
% 10-Aug 1993 (Herbert Melenk)
%   Modified MODMEMPAT: update register database when aux register 
%   needed.
% 22 April 1987 (Harold Carr)
%   Moved *lambind, *jumpon, and *foreignlink cmacros (and support) from
%   this file to vax-cmac.sl, where they belong.
% 5 June 1984 (Vicki O'Day)
%   Incorporated Utah change to make foreign functions be linked
%   through SYMFNC.
% 18-Jan-84 (Sam Sands)
%   Hacked up so that FIELD will find what constant value it is getting
%   if it is given a register.
% 12-Jan-84 (Sam Sands)
%   Added patterns 'CARCDRPAT and 'MEMORYPAT;  modified MODMEMPAT
% 06-Dec-83 10:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(PUT 'CARCDRPAT 'PATTERN 
  '(NIL NIL
    ( ANY ('*RETURN (FN A1)))))
    
(PUT 'MEMORYPAT 'PATTERN 
  '(NIL NIL
    ((ANY CONST) ('*RETURN (FN A1 A2)))
    ((REGNP ANY) ('*WPLUS2 A1 A2) ('*SET A1 ('*WPLUS2 A1 A2))
                                  ('*RETURN (FN A1 ('WCONST '0))))
    ((ANY REGNP) ('*WPLUS2 A2 A1) ('*SET A2 ('*WPLUS2 A2 A1))
                                  ('*RETURN (FN A2 ('WCONST '0))))
    ( ANY        ('*LOAD   T1 A1) ('*WPLUS2 T1 A2) 
                 ('*SET T1 ('*WPLUS2 T1 A2))
                                  ('*RETURN (FN T1 ('WCONST '0))))
    ))
    

(commentoutcode

(put 'tvpat 'pattern 
     '(!&regmem ('!*destroy dest) 
                ((dest any) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((any dest) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((usesdest any) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((any usesdest) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                (any ('!*load dest ''t) (mac l1 a1 a2) 
                     ('!*load dest ''nil) ('!*lbl l1))))
)

(compiletime (remprop 'nil-t-diff* 'constant!?))
(fluid '(nil-t-diff*))
(setq nil-t-diff* (difference (id2int nil)(id2int t)))
(put 'nil-t-diff* 'constant!? t)

(put 'tvpat 'pattern 
     '(!&regmem ('!*destroy dest) 
                ((dest any) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((any dest) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((usesdest any) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((any usesdest) (mac l1 a1 a2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                (any ('!*load dest ''t) (mac l1 a1 a2)
                     ('!*wplus2 dest '(wconst nil-t-diff*)) ('!*lbl l1))))


(put 'tvpat1 'pattern 
     '(!&regmem ('!*destroy dest) 
                ((dest) (mac l1 a1 p2) ('!*load dest ''nil) ('!*jump l2) 
                 ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                ((usesdest) (mac l1 a1 p2) ('!*load dest ''nil) 
                 ('!*jump l2) ('!*lbl l1) ('!*load dest ''t) ('!*lbl l2))
                (any ('!*load dest ''t) (mac l1 a1 p2) 
                     ('!*load dest ''nil) ('!*lbl l1))))

% similar to tvpat for eq/neq tests

(put 'tvpat-eq 'pattern
     '(!&regmem ('!*destroy dest)
               (any ('*Wcmp a1 a2) 
                    ('!*load dest ''t) 
                    (&convert-mac l1)
                    ('!*wplus2 dest '(wconst nil-t-diff*)) 
                    ('!*lbl l1))))

% similar to tvpat1 for tag tests

(put 'tvpat-tag 'pattern
     '(!&regmem ('!*destroy dest)
                (any   
                       ('!*load dest a1)
                       ('*wshift dest '-27)
                       ('*wcmp dest p2)
                       ('!*load dest ''t)
                       (&convert-mac l1)
                       ('!*wplus2 dest '(wconst nil-t-diff*))
                       ('!*lbl l1))))


% transform *JUMPTYPE/*JUMPEQ to JE, *JUMPNOTTYPE/*JUMPNOTEQ to JNE

(put '&convert-mac 'substfn '&convert-mac)

(de &convert-mac(arg args params)
     (if (or (eq (cadr params) '*JUMPTYPE) 
             (eq (cadr params) '*JUMPEQ))
         'je 'jne))

(put 'tstpat 'pattern 
     '(nil !&fixregtest ((regn any) (mac dest a1 a2)) 
           (any (mac dest a2 a1))))

(put 'tstpatc 'pattern 
     '(nil !&setregs1 ((regn any) (mac dest a1 a2)) (any (p2 dest a2 a1))))

(put 'tstpat2 'pattern '(nil !&setregs1 (any (mac dest a1 p2))))

(put 'setqpat 'pattern 
     '(nil nil ((noval any notanyreg) ('!*store a2 a1)) 
           ((noval dest any) ('!*store a2 dest)) 
           ((noval usesdest any) ('!*load t1 a2) ('!*store t1 a1)) 
           ((noval any any) ('!*load dest a2) ('!*store dest a1)) 
           ((any dest) ('!*store dest a1)) ((dest any) ('!*store a2 dest)) 
           ((usesdest any) ('!*store a2 a1) ('!*store a2 dest)) 
           (any ('!*load dest a2) ('!*store dest a1))))

(put 'rplacpat 'pattern 
     '(nil nil ((noval any any) ('!*store a2 (mac a1))) 
           ((dest any) ('!*store a2 (mac a1))) 
           ((usesdest any) ('!*store a2 (mac a1)) ('!*load dest a1)) 
           ((any dest) ('!*store a2 (mac a1)) ('!*load dest a1)) 
           ((any usesdest) ('!*store a2 (mac a1)) ('!*load dest a1)) 
           (any ('!*load dest a1) ('!*store a2 (mac dest)))))

(put 'assocpat 'pattern 
     '(nil ('!*set dest (fn a1 a2)) ((dest any) (mac a1 a2)) 
           ((any dest) (mac a2 a1)) 
           ((usesdest usesdest) ('!*load t1 a1) ('!*load dest a2) 
            (mac dest t1))
           ((any usesdest) ('!*load dest a2) (mac dest a1)) 
           (any ('!*load dest a1) (mac dest a2))))

(put 'subpat 'pattern 
     '(nil ('!*set dest (fn a1 a2)) ((dest any) (mac a1 a2)) 
           ((any dest) ('!*wminus dest dest) ('!*wplus2 a2 a1)) 
           ((any usesdest) ('!*load t1 a2) ('!*load dest a1) (mac dest t1)) 
           (any ('!*load dest a1) (mac dest a2))))

(put 'nonassocpat 'pattern 
     '(nil ('!*set dest (fn a1 a2)) ((dest any) (mac a1 a2)) 
           ((any usesdest) ('!*load t1 a2) ('!*load dest a1) (mac dest t1)) 
           (any ('!*load dest a1) (mac dest a2))))

(put 'fieldpat 'pattern 
     '(&constfieldargs  ('!*set dest (fn a1 a2 a3)) (any (mac dest a1 a2 a3))))

(de &constfieldargs(args) 
  (cond ((registerp (second args)) 
	 (&constfieldargs
	  (list (first args) (&constregval (second args)) (third args))))
        ((registerp (third args))
	 (list (first args) (second args) (&constregval (third args))))
	(t args)))

(de &constregval (reg)
  % Return a constant value known to be in the register, if any, otherwise
  % just return the register.
  (for (in value (&regval reg))
       (do (when (&constp value)
		 (return value)))
       (returns reg)
       ))

(put 'putfieldpat 'pattern 
     '(nil nil ((noval any any any any) (mac a1 a2 a3 a4)) 
           (any (mac a1 a2 a3 a4) ('!*store a1 dest))))

(put 'unarypat 'pattern 
     '(!&noanyreg ('!*set dest (fn a1)) (any (mac dest a1))))

(put 'modmempat 'pattern '(nil nil 
     ((NOVAL ANY ANY)      (mac a1 a2))
     ((      ANY REGNP)    (P2  A2 LA1) 
                           ('*STORE A2 A1) 
                           ('*RETURN A2))
     ( ANY                 ('*LOAD T2 A2) 
                           (P2  T2 LA1) 
                           ('!*set t2 (fn a1 a2)) % HM
                           ('*STORE T2 A1) 
                           ('*RETURN T2))
     ))

(put 'modmempat1 'pattern '(nil nil (any (mac a1 a1))))

% End of file.

