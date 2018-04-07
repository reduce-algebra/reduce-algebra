%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:FASLOUT.SL 
% SCCS:         %A% %G% %U% 
% Title:        Top level of fasl file writer 
% Author:       Eric Benson 
% Created:      16 February 1982 
% Modified:     23 Jan 1985 0937-PST (Brian Beach)
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Compiletime:  PL:FAST-VECTOR.B PL:FASL-DECLS.B 
% Runtime:      
%
% (c) Copyright 1983, 1984, Hewlett-Packard Company, see the file
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
% 10-Aug-88 (Chris Burdorf)
%  Replaced all the if's located inside "function" so that the compiler can
%  be loaded without having USEFUL loaded.
%
% 15-Aug-87 (Leigh Stoller)
%  Removed all internal functions. No longer considered proper.
% 07-Sep-86 (Leigh Stoller)
%  Changed > to greaterp in fasl-writename because a compiler module should
%  not depend on a utility module.
% 23 Jan 1985 0937-PST (Brian Beach)
%  Changed FASLOUT so that it returns T again.
% 15-Jan-85 15:49:52 (Brian Beach)
%  Added a fluid variable called FASL-IDNUMBER-PROPERTY* which is the name
%  of the property that id numbers are stored under.  This is to fix a problem
%  that occurrs when a compile is abnormally terminated, and another one
%  started where id numbers in the new compile are confused with id numbers
%  in the terminated compile that weren't cleaned up.
% 14-Nov-84 14:20:49 (Brian Beach)
%  Changed FASLABORT accoring to Utah fix so that the output file is closed
%  after the flags are reset, so that the system is left in a reasonable state
%  even if the file cannot be closed.
% 24-Oct-84 15:30:01 (Alan Snyder)
%  Install changes from Bob Morain:
%    Now turns off internalfunction flag at the end of the file to restore
%    compiler to good state.  Added a new internal function
%    DEALLOCATEFASLSPACES.  Flagged FASLABORT 'ignore to make it more useful;
%    made it call DEALLOCATEFASLSPACES.  Flush flagging of STARTUPTIME, which
%    is obsolete.  Changed FASLOUT-MAGIC to (COMPILER-CONSTANT
%    'FASLOUT-MAGIC).  Added FASL-PREEVAL* to parameterize the property looked
%    up by DFPRINTFASL; DFPRINTFASL can now be used (and is used) by ASMOUT.
%    Made FASL-FUNCTION call COMPD, which seems to do pretty much the same
%    things that FASL-FUNCTION did.  Remove redundant binding of
%    *WRITINGFASLFILE by DFPRINTFASL.
%  In addition:
%    Make FASLEND call FASLABORT to reduce duplicated code.
% 19-Oct-84 08:37:49 (Alan Snyder)
%  Fix another bug in 02-Oct-84 change: LOADTIME was calling FASL-FORM, which
%  interprets the IGNORE and EVAL flags (which implement COMPILETIME and
%  BOTHTIMES).  It appears that the behavior desired by PSL programmers is for
%  LOADTIME to force compiler output and prevent compiler execution, as in
%  (LOADTIME (ON FOO)), where ON is implicitly COMPILETIME.  This behavior
%  differs from Common Lisp EVAL-WHEN, where an (EVAL-WHEN (LOAD) ...) is a
%  no-op to the compiler (the body is compiled normally).  My fix is to add a
%  parameter to fasl-from and the faslpreeval functions and and pass this down
%  (to handle macro calls).
% 15-Oct-84 11:15:49 (Alan Snyder)
%  Fix bug in 02-Oct-84 change: Add ERRSET around invocation of TOPLOOPEVAL*.
% 02-Oct-84 09:23:07 (Alan Snyder)
%   Restructured DFPRINTFASL for much improved clarity.  Flushed the redundant
%   checking for COMPILE flag on function type (EXPR, etc.). Changed to use
%   the existing PREFASLEVAL hook for special treatment of PUTD, DE, etc.,
%   instead of special case code.  Added the EVAL and IGNORE flag handling in
%   DFPRINTFASL (instead of DSKIN and TOPLOOP), for proper interaction with
%   macro expansion; macros can now expand into COMPILETIME, etc.  (Note
%   30-Apr-82 change, for amusement.)  Changed to use TOPLOOPEVAL* instead of
%   EVAL, for multiple dialect support.  Added warning message for non-list
%   form given to DFPRINTFASL.  Removed PACKAGE attribute from the file
%   header.
% 04-Jun-84 13:46:13 (Brian Beach)
%  Replaced compiletime dskin of SYSTEM-FASLOUT with compiletime load of
%  FASL-DECLS.  New constant model.  Replaced use of 2048 with constant
%  first-local-id-number.
% 12 Apr 1984 1411-PST (Nancy Kendzierski)
%  Changed if_system unix to if_system vax and relative path load to shell
%  variable $pv.  Added hpux200 compiletime load.
% 28 Mar 1984 1702-PST (Nancy Kendzierski)
%  Changed references to addressingunitsperitem from const to wconst.
%  Changed references to faslout-magic (previously FASL_MAGIC_NUMBER) from
%  const to wconst.
%  Moved (load monsym) to p20:system-faslout.sl where it belonged.
% 11-Jan-84 17:19:45 (Cris Perdue)
%  Modified codefiletrailer to accept a real string with a
%  header tag in its header word.  FASL file will always contain a
%  count for each string with no random extra bits set in that word.
% 06-Dec-83 10:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
 (progn
   (load fast-vector)
   (load fasl-decls)))

(fluid '(*writingfaslfile
	 *lower
	 *quiet_faslout
	 dfprint*
         uncompiledexpressions*
	 modulename*
	 codeout*
	 initoffset*
         currentoffset*
	 faslblockend*
	 maxfasloffset*
	 bittableoffset*
         faslfilenameformat*
         fasl-idnumber-property*
	 ))

(setq faslfilenameformat* "%w.b")

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DFPRINTFASL - the external entry point to compile each form
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(toploopeval* fasl-preeval*))

(de dfprintfasl (u)
  % Called by top-loop, dskin, dfprint to compile a single form.
  (fasl-form u NIL))

(de fasl-form (u loadtime?)
  % Compile a simple S-EXPRESSION, maybe EVAL it.
  % If LOADTIME? is true, then do not obey the IGNORE and EVAL flags.

  (if (not (pairp u))
    (when u (errorprintf "*** Warning: non-list form ignored: %p" u))
    % Otherwise:
    (let ((fn (car u)) fcn)
      % Evaluate the expression if FN is flagged IGNORE or EVAL.
      (when (and (not loadtime?)
		 (idp fn)
		 (or (flagp fn 'ignore) (flagp fn 'eval)))
	(errset (funcall toploopeval* u) t))
      (cond
       % Do not compile if FN is flagged IGNORE.
       ((and (not loadtime?) (idp fn) (flagp fn 'ignore)) NIL)
       % Check for calls of special flagged function:
       ((and (idp fn) (setq fcn (get fn fasl-preeval*)))
	(funcall fcn u loadtime?))
       % Check for macro call:
       ((and (idp fn) (setq fcn (getd fn)) (equal (car fcn) 'macro))
	(fasl-form (funcall (cdr fcn) u) loadtime?))
       (t
	(saveuncompiledexpression u)
	NIL
	)))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Special cases for FASL:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(put 'de 'faslpreeval
     (function (lambda (u loadtime?) (fasl-define u 'expr))))
(put 'df 'faslpreeval
     (function (lambda (u loadtime?) (fasl-define u 'fexpr))))
(put 'dm 'faslpreeval
     (function (lambda (u loadtime?) (fasl-define u 'macro))))
(put 'dn 'faslpreeval
     (function (lambda (u loadtime?) (fasl-define u 'nexpr))))
(put 'putd 'faslpreeval
     (function (lambda (u loadtime?) (fasl-putd u))))

(de fasl-define (u ty)
  % Compile a DE/DF/DM/DN.
  (fasl-function (cadr u) (cons 'lambda (cddr u)) ty))

(de fasl-function (nam u ty)
  % Compile a named function definition.
  (when (equal ty 'macro) % Macros get defined now (interpretively)
    (let ((*comp NIL))
      (putd nam ty u)))
  (compd nam ty u)
  (fasl-writename nam)
  )

(de fasl-writename (nam)
  % Write function name after compiling it.
  (when (greaterp (posn) 0)
    (writechar (char blank)))
  (prin1 nam)
  )

(de fasl-putd (u)
  % Compile a PUTD
  (let ((nam (cadr u))
	(ty (caddr u))
	(fn (cadddr u))
	)
    (cond ((and (eqcar nam 'quote)
		(eqcar ty 'quote)
		(memq (cadr ty) '(expr fexpr macro nexpr))
		(or (eqcar fn 'function)
		    (eqcar fn 'quote)))
	   (fasl-function (cadr nam) (cadr fn) (cadr ty)))
	  (t
	   (saveuncompiledexpression u)
	   ))))

% Seems the wrong place for this:
(flag '(deflist flag fluid global remflag remprop unfluid) 'eval)

(de faslpreevalloadtime (u loadtime?)
  (fasl-form (cadr u) T))

% remove LOADTIME                                                          
(put 'loadtime 'faslpreeval 'faslpreevalloadtime)

(put 'bothtimes 'faslpreeval 'faslpreevalloadtime)

% used in kernel                                                           
% A few things to save space when loading                                  
(put 'flag 'faslpreeval 
     (function (lambda (u loadtime?)
                       (cond ((eqcar (second u) 'quote)
			      (fasl-form 
			       (cons 'progn 
				     (foreach x in (second (second u)) collect 
					      (list 'flag1 (mkquote x)
						    (third u)))) loadtime?))
			     (t (saveuncompiledexpression u))))))

(put 'fluid 'faslpreeval 
     (function (lambda (u loadtime?)
                       (cond ((eqcar (second u) 'quote)
			      (fasl-form 
			       (cons 'progn 
				     (foreach x in (second (second u)) collect 
					      (list 'fluid1 (mkquote x))))
			       loadtime?))
			     (t (saveuncompiledexpression u))))))

(put 'global 'faslpreeval 
     (function (lambda (u loadtime?)
                       (cond ((eqcar (second u) 'quote)
			      (fasl-form 
			       (cons 'progn 
				     (foreach x in (second (second u)) collect 
					      (list 'global1 (mkquote x))))
			       loadtime?))
			     (t (saveuncompiledexpression u))))))

(put 'deflist 'faslpreeval 
     (function (lambda (u loadtime?)
                       (cond ((eqcar (second u) 'quote)
			      (fasl-form 
			       (cons 'progn 
				     (foreach x in (second (second u)) collect 
					      (list 'put (mkquote (first x))
						    (third u) 
						    (mkquote (second x)))))
			       loadtime?))
			     (t (saveuncompiledexpression u))))))

(put 'progn 'faslpreeval 
     (function (lambda (u loadtime?)
                       (foreach x in (cdr u) do (fasl-form x loadtime?)))))

(put 'lap 'faslpreeval 
     (function (lambda (u loadtime?)
                       (cond ((eqcar (cadr u) 'quote)
			      (lap (cadr (cadr u))))
                         (t (saveuncompiledexpression u))))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FASLOUT and friends:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq uncompiledexpressions* (cons nil nil))

(de saveuncompiledexpression (u)
  (if (atom u)
    nil
    (tconc uncompiledexpressions* u))
  nil)

(de faslout (fil)
  (when (idp fil)(let((*lower t)) (setq fil (bldmsg "%w" fil))))
  (setq modulename* fil)
  (unless *quiet_faslout
    (if (not (funboundp 'begin1))
      (progn (prin2t "FASLOUT: IN files; or type in expressions")
             (prin2t "When all done execute FASLEND;"))
      (progn (prin2t "FASLOUT: (DSKIN files) or type in expressions")
             (prin2t "When all done execute (FASLEND)"))))
  (setq codeout*
        (binaryopenwrite (bldmsg faslfilenameformat* modulename*)))
  (codefileheader)
  (setq dfprint* 'dfprintfasl)
  (setq fasl-preeval* 'faslpreeval)
  (setq *writingfaslfile t)
  (setq *defn t)
  (setf fasl-idnumber-property* (intern (concat "FASL-IDNUMBER-" (stringgensym))))
  t
  )
    
(de faslend ()
  (if (not *writingfaslfile)
    (stderror "FASLEND not within FASLOUT")
    (progn (compileuncompiledexpressions)
           (codefiletrailer)
	   (faslabort)
	   )))

(flag '(faslend) 'ignore)

% FaslAbort.  Abort the Fasl process cleanly.  The code file will be closed
% and the various flags will be reset.

% FaslAbort.  Abort the Fasl process cleanly.  The code file will be closed
% and the various flags will be reset.
(de faslabort ()
  (if (not *writingfaslfile)
    (stderror "FASLAbort not within FASLOUT")
    (progn (setq uncompiledexpressions* (cons nil nil))
	   (deallocatefaslspaces)
           (setq *writingfaslfile nil)
	   (setq fasl-preeval* nil)
           (setq dfprint* nil)
           (setq *defn nil)
           (binaryclose codeout*)
	   )))

(flag '(faslabort) 'ignore)

(de compileuncompiledexpressions ()
  (errorprintf "*** Init code length is %w"
               (length (car uncompiledexpressions*)))
  (dfprintfasl (list 'de '**fasl**initcode** 'nil
                     (cons 'progn (car uncompiledexpressions*)))))

(de codefileheader ()
  (binarywrite codeout* (compiler-constant 'faslout-magic))
  (allocatefaslspaces))

(fluid '(codebase* bittablebase* orderedidlist* nextidnumber*))

(de findidnumber (u)
  (prog (i)
        (return (cond ((ileq (setq i (idinf u)) 128) i)
                      ((setq i (get u fasl-idnumber-property*)) i)
                      (t (put u fasl-idnumber-property* (setq i nextidnumber*))
                         (setq orderedidlist* (tconc orderedidlist* u))
                         (setq nextidnumber* (iadd1 nextidnumber*)) i)))))

(de faslid2string (x)
  % Stub to permit redefinition for "limited" package system
  (id2string x))

(de codefiletrailer ()
  (prog (s)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*) 
					   first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (setq x (strinf (faslid2string x)))
                        (setq s (strlen x))
			(binarywrite codeout* s)
                        (binarywriteblock codeout* (strbase x)
					  (strpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 addressingunitsperitem))
		       addressingunitsperitem)))
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
        (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
        (binarywriteblock codeout* bittablebase* s)
	(deallocatefaslspaces)))

(de updatebittable (numberofentries firstentry)
  (when *writingfaslfile
    (putbittable bittablebase* bittableoffset* firstentry)
    (setq bittableoffset* (iadd1 bittableoffset*))
    (for (from i 2 numberofentries 1)
         (do (progn (putbittable bittablebase* bittableoffset* 0)
                    (setq bittableoffset* (iadd1 bittableoffset*)))))
    (when (igreaterp bittableoffset* maxfasloffset*)
      (fatalerror "BPS exhausted during FaslOut; output file too large"))))

(de allocatefaslspaces ()
  (prog (b)
    (setq b (gtwarray nil))
    % how much is left?
    (setq b (idifference b (iquotient b 3)))
    (setq faslblockend* (gtwarray 0))
    % pointer to top of space
    (setq bittablebase* (gtwarray b))
    % take 2/3 of whatever's left
    (setq currentoffset* 0)
    (setq bittableoffset* 0)
    (setq codebase*
      (loc (wgetv bittablebase* % split the space between
		  (iquotient b % bit table and code
			     (iquotient bittable-entries-per-word
					addressingunitsperitem)))))
    (setq maxfasloffset* (idifference faslblockend* codebase*))
    (setq orderedidlist* (cons nil nil))
    (setq nextidnumber* first-local-id-number)))

(de deallocatefaslspaces ()
  (delwarray bittablebase* faslblockend*)
  )
